#include "actor_common.h"
#include "actor_management.h"
#include "common_structs.h"
#include "libc/stdbool.h"
#include "libc/stdio.h"
#include "libc/string.h"
#include "modding.h"
#include "types.h"

// ==============================================================================
// External Function Declarations
// ==============================================================================

extern unsigned int func_80013B14_14714(unsigned short file_id); // individual file loader
extern short *get_stage_file_list(unsigned short stage_id);      // lookup function from room_files.c

// Missing function declarations for door/exit handling
extern void func_80215330_5D0800(void *task);
extern void func_8003521C_35E1C(void *func_ptr);
extern void func_802154F0_5D09C0(void);
extern int func_802154FC_5D09CC(unsigned int player_ptr, void *object, int radius);
extern void func_801FB270_5B7180(void);

extern unsigned short D_800C7AB2; // Part of the huge "SYS_W" structure, ID of the current stage
extern void func_80038B98_39798(unsigned short stage_id);
extern void func_80023DF0_249F0(int param);
extern void func_8003D310_3DF10(int param);

// Function from other actor modules
extern void adjust_logical_doors(ActorInstance *actor_instance, ActorDefinition *resolved_actor_def, unsigned short actor_id, unsigned short actor_data_file_id, int overall_index);

// ==============================================================================
// Constants and Macros
// ==============================================================================

#define WAVE_MAX 48
#define FILE_NONE 0

// ==============================================================================
// Type Definitions
// ==============================================================================

// Use WAVE_W from common_structs.h instead of OverlayEntry
// (they are identical: file_id == wave_no, data is the same)
typedef WAVE_W OverlayEntry;

// Room-specific configurations for extra instances
static const RoomInstanceConfig room_configs[] = {
    // This is specifically here so we can add an extra exit door to room 0x0A8
    {0x0A8, 2, 0xFFFFFFFF}, // Room 0x0A8: 2 instances with marker 0xFFFFFFFF
};
static const int num_room_configs = sizeof(room_configs) / sizeof(room_configs[0]);

// ==============================================================================
// External Variables
// ==============================================================================

extern OverlayEntry D_80167FC0_168BC0[WAVE_MAX];

// ==============================================================================
// Global Variables
// ==============================================================================

static OverlayRedirection overlay_redirections[WAVE_MAX];

// ==============================================================================
// Private Helper Functions
// ==============================================================================

/**
 * Clear all overlay redirections and free associated memory
 */

static void overlay_redirections_clear(void) {
    int i;

    for (i = 0; i < WAVE_MAX; i++) {
        if (overlay_redirections[i].file_id != FILE_NONE) {
            overlay_redirections[i].file_id = 0;
        }

        if (overlay_redirections[i].redirected_data != NULL) {
            recomp_free(overlay_redirections[i].redirected_data);
            overlay_redirections[i].redirected_data = NULL;
        }
    }
}

/**
 * Add a new overlay redirection with allocated memory
 * @param file_id The file ID to redirect
 * @param data_size Size of memory to allocate
 * @return Pointer to allocated memory, or NULL on failure
 */
static void *overlay_redirections_add(unsigned short file_id, size_t data_size) {
    int i;

    if (file_id == FILE_NONE) {
        DEBUG_PRINTF("Error: Cannot add overlay redirection for FILE_NONE");
        return NULL;
    }

    if (data_size == 0) {
        DEBUG_PRINTF("Error: Cannot add overlay redirection with zero size");
        return NULL;
    }

    // Look for the next open spot
    for (i = 0; i < WAVE_MAX; i++) {
        if (overlay_redirections[i].file_id == FILE_NONE) {
            overlay_redirections[i].file_id = file_id;
            overlay_redirections[i].redirected_data = recomp_alloc(data_size);
            return overlay_redirections[i].redirected_data;
        }
    }

    DEBUG_PRINTF("Error: No available slots to add overlay redirection for file_id=0x%X", file_id);
    return NULL;
}

/**
 * Remove an overlay redirection and free its memory
 * @param file_id The file ID to remove
 */
static void overlay_redirections_remove(unsigned short file_id) {
    int i;

    if (file_id == FILE_NONE) {
        DEBUG_PRINTF("Error: Cannot remove overlay redirection for FILE_NONE");
        return;
    }

    // Look an entry with the file id we are trying to remove
    for (i = 0; i < WAVE_MAX; i++) {
        if (overlay_redirections[i].file_id == file_id) {
            overlay_redirections[i].file_id = FILE_NONE;

            recomp_free(overlay_redirections[i].redirected_data);
            overlay_redirections[i].redirected_data = NULL;
        }
    }
}

/**
 * Get the redirected data pointer for a file ID
 * @param file_id The file ID to look up
 * @return Pointer to redirected data, or NULL if not found
 */
static void *overlay_redirections_get(unsigned short file_id) {
    int i;

    if (file_id == FILE_NONE) {
        DEBUG_PRINTF("Error: Cannot get overlay redirection for FILE_NONE");
        return NULL;
    }

    // Look an entry with the file id we are trying to get
    for (i = 0; i < WAVE_MAX; i++) {
        if (overlay_redirections[i].file_id == file_id) {
            return overlay_redirections[i].redirected_data;
        }
    }

    return NULL;
}

// ==============================================================================
// Patched Functions (RECOMP_PATCH/RECOMP_HOOK)
// ==============================================================================

/**
 * Patched overlay_get_data_pointer function that checks redirections first
 */
RECOMP_PATCH s32 func_800141C4_14DC4(unsigned int file_id) {
    OverlayEntry *entry = (OverlayEntry *)&D_80167FC0_168BC0;
    int i; // @patch

    if (file_id == FILE_NONE) {
        return 0;
    }

    // @patch: Redirect any file ids that have an entry in overlay_redirections
    for (i = 0; i < WAVE_MAX; i++) {
        if (overlay_redirections[i].file_id == file_id) {
            return (s32)overlay_redirections[i].redirected_data;
        }
    }

    // The loop iterates until it hits an entry with file_id == 0 (Terminator)
    while (entry->file_id != 0) {
        if (entry->file_id == file_id) {
            return entry->data;
        }

        entry++;
    }

    return -1;
}

/**
 * Main hook function for actor management
 * This function handles actor data modification, room-specific instance
 * creation, and actor processing for the randomizer
 */
RECOMP_HOOK("func_8020D724_5C8BF4")
void func_8020D724_5C8BF4_hook() {
    unsigned char *buffer;

    DEBUG_PRINTF("func_8020D724_5C8BF4 called\n");

    // This guarantees that buffer will be freed
    overlay_redirections_clear();

    // Get the actor data file ID for the current stage
    // print D_80231300_5EC7D0 and then D_800C7AB2 to verify
    DEBUG_PRINTF("D_800C7AB2 (current room): 0x%03X\n", D_800C7AB2);
    DEBUG_PRINTF("D_80231300_5EC7D0[D_800C7AB2]: %p\n", D_80231300_5EC7D0[D_800C7AB2]->actor_data_file_id);
    unsigned short actor_data_file_id = D_80231300_5EC7D0[D_800C7AB2]->actor_data_file_id;

    // Get the memory address of the actor data file in memory
    void *actor_data_file_buffer = (void *)func_800141C4_14DC4(actor_data_file_id);

    // Copy actor data file into a new buffer and udate the overlay entry to point
    // to the new buffer
    buffer = overlay_redirections_add(actor_data_file_id, 0x10000);
    DEBUG_PRINTF("Updating overlay entry for file 0x%X to %p\n", actor_data_file_id, buffer);

    for (int i = 0; i < 0x10000; i++) {
        buffer[i] = ((unsigned char *)actor_data_file_buffer)[i];
    }

    // Edit the actor data in the new buffer as needed
    ActorInstance *actor_instances = (ActorInstance *)func_80014840_15440((s32)D_80231300_5EC7D0[D_800C7AB2]->actor_instances, actor_data_file_id);

    // List all actor instances until terminator
    for (int i = 0;; i++) {
        ActorInstance *actor_instance = &actor_instances[i];
        if (actor_instance->actor_definition == NULL) {
            break; // Terminator reached
        }
    }

    // Check if current room needs extra instances
    for (int config_idx = 0; config_idx < num_room_configs; config_idx++) {
        if (D_800C7AB2 == room_configs[config_idx].room_id) {
            // First, count regular instances to find where to insert
            int regular_instance_count = 0;
            for (int i = 0;; i++) {
                ActorInstance *actor_instance = &actor_instances[i];
                if (actor_instance->actor_definition == NULL) {
                    regular_instance_count = i;
                    break;
                }
            }

            // Create the specified number of extra instances
            int instances_to_create = room_configs[config_idx].instance_count;
            for (int instance_idx = 0; instance_idx < instances_to_create; instance_idx++) {
                ActorInstance *extra_instance = &actor_instances[regular_instance_count + instance_idx];

                // Set all values to marker value (with slight variation for multiple
                // instances)
                unsigned int marker = room_configs[config_idx].marker_value - instance_idx;
                extra_instance->position.x = 0xFFFF;
                extra_instance->position.y = 0xFFFF;
                extra_instance->position.z = 0xFFFF;
                extra_instance->rotation.pitch = 0xFFFF;
                extra_instance->rotation.yaw = 0xFFFF;
                extra_instance->rotation.roll = 0xFFFF;
                extra_instance->actor_definition = (ActorDefinition *)marker;
                extra_instance->is_spawned = 0xFF;
                extra_instance->unk_11 = 0xFF;
                extra_instance->unk_12 = 0xFF;
                extra_instance->unk_13 = 0xFF;
            }

            // Re-insert the null terminator after all new instances
            ActorInstance *null_terminator = &actor_instances[regular_instance_count + instances_to_create];
            null_terminator->position.x = 0;
            null_terminator->position.y = 0;
            null_terminator->position.z = 0;
            null_terminator->rotation.pitch = 0;
            null_terminator->rotation.yaw = 0;
            null_terminator->rotation.roll = 0;
            null_terminator->actor_definition = NULL;
            null_terminator->is_spawned = 0;
            null_terminator->unk_11 = 0;
            null_terminator->unk_12 = 0;
            null_terminator->unk_13 = 0;

            // recomp_printf("Added %d extra instances for room 0x%03X\n",
            // instances_to_create, room_configs[config_idx].room_id);
            break; // Only process one room config per call
        }
    }

    // First, count regular instances to find where grouped instances start
    int regular_instance_count = 0;
    for (int i = 0;; i++) {
        ActorInstance *actor_instance = &actor_instances[i];
        if (actor_instance->actor_definition == NULL) {
            regular_instance_count = i;
            break;
        }
    }

    // Calculate grouped data location
    size_t grouped_data_offset = regular_instance_count * sizeof(ActorInstance) + sizeof(ActorInstance);
    unsigned char *raw_buffer = (unsigned char *)actor_instances;
    unsigned char *grouped_data_start = raw_buffer + grouped_data_offset;

    // Count total instances (regular + grouped)
    int total_instances = regular_instance_count;
    int max_grouped_data_size = 2048;

    for (int offset = 0; offset < max_grouped_data_size; offset += sizeof(ActorInstance)) {
        ActorInstance *potential_instance = (ActorInstance *)(grouped_data_start + offset);
        unsigned char *raw_bytes = (unsigned char *)potential_instance;

        // Check for valid grouped instance
        bool has_0800_pattern = (offset + 12 < max_grouped_data_size && raw_bytes[12] == 0x08 && raw_bytes[13] == 0x00);
        bool reasonable_position = (potential_instance->position.x > -10000 && potential_instance->position.x < 10000 && potential_instance->position.y > -10000 &&
                                    potential_instance->position.y < 10000 && potential_instance->position.z > -10000 && potential_instance->position.z < 10000);

        if (has_0800_pattern && reasonable_position) {
            total_instances++;
        } else if (offset > 100) {
            // Check for end of data
            bool all_zero = true;
            for (int check = 0; check < 60; check++) {
                if (offset + check < max_grouped_data_size && grouped_data_start[offset + check] != 0) {
                    all_zero = false;
                    break;
                }
            }
            if (all_zero)
                break;
        }
    }

    // Process all instances in a unified manner
    int grouped_index = 0;
    for (int overall_index = 0; overall_index < total_instances; overall_index++) {
        ActorInstance *actor_instance = NULL;

        if (overall_index < regular_instance_count) {
            // Regular instance
            actor_instance = &actor_instances[overall_index];
        } else {
            // Grouped instance - find the next valid grouped instance
            while ((int)(grouped_index * sizeof(ActorInstance)) < max_grouped_data_size) {
                ActorInstance *potential_instance = (ActorInstance *)(grouped_data_start + grouped_index * sizeof(ActorInstance));
                unsigned char *raw_bytes = (unsigned char *)potential_instance;

                bool has_0800_pattern = ((int)(grouped_index * sizeof(ActorInstance)) + 12 < max_grouped_data_size && raw_bytes[12] == 0x08 && raw_bytes[13] == 0x00);
                bool reasonable_position = (potential_instance->position.x > -10000 && potential_instance->position.x < 10000 && potential_instance->position.y > -10000 &&
                                            potential_instance->position.y < 10000 && potential_instance->position.z > -10000 && potential_instance->position.z < 10000);

                if (has_0800_pattern && reasonable_position) {
                    actor_instance = potential_instance;
                    grouped_index++;
                    break;
                }
                grouped_index++;
            }
        }

        if (actor_instance == NULL)
            break;

        // Special handler to determine if its a NEW instance being edited vs
        // something already in the room
        if ((unsigned int)actor_instance->actor_definition >= 0xFFFFFFF0) {
            adjust_logical_doors(actor_instance, NULL, 0, actor_data_file_id, overall_index);
            continue;
        }

        // Resolve the actor definition pointer to the new buffer
        ActorDefinition *resolved_actor_def = (ActorDefinition *)func_80014840_15440((s32)actor_instance->actor_definition, actor_data_file_id);

        if (resolved_actor_def != NULL) {
            // Extract actor ID from the first data field (shift right by 16 to get
            // the upper 16 bits)
            unsigned short actor_id = (resolved_actor_def->data[0] >> 16) & 0xFFFF;

            // Process different actor types using separate modules
            process_enemy_actors(actor_instance, resolved_actor_def, actor_id, actor_data_file_id, overall_index);

            // Update doors that need logic adjustment to prevent softlocks
            adjust_logical_doors(actor_instance, resolved_actor_def, actor_id, actor_data_file_id, overall_index);

            // Adjust actual items in the room
            process_items(actor_instance, resolved_actor_def, actor_id, actor_data_file_id, overall_index);

            // Adjust pot spawn contents
            adjust_pot_contents(actor_instance, resolved_actor_def, actor_id, actor_data_file_id, overall_index);
        }
    }
}
