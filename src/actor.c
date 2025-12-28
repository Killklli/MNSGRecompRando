#include "modding.h"
#include "common.h"
#include "recomputils.h"
#include "recompconfig.h"
#include "libc/stdbool.h"
#include "save_data_tool.h"

// Forward declarations from surprise_pack.c

struct Position
{
    short x;
    short y;
    short z;
}; // Size: 6

struct Rotation
{
    short pitch;
    short yaw;
    short roll;
}; // Size: 6

struct ActorDefinition
{
    int data[4];
}; // Size: 16

struct LockedDoorActor
{
    unsigned short actor_id;   // 0x23E
    unsigned short padding1;   // 0x0000
    unsigned char door_design; // 0x01 = Oedo Castle, 0x02 = other designs
    unsigned char key_type;    // 0x02 = Silver, etc.
    unsigned short padding2;   // 0x0000
    unsigned short lock_index; // 0x010F
    unsigned short accept_key; // 0x0110
    unsigned short exit_id;    // 0x02
    unsigned short padding3;   // 0x0000
}; // Size: 16

struct KeyActor
{
    unsigned short actor_id;  // 0x193
    unsigned short padding1;  // 0x0000
    unsigned short enemies;   // 0x0000 = No enemies required
    unsigned short padding2;  // 0x0000
    unsigned short key_index; // 0x0110
    unsigned short padding3;  // 0x0000
    unsigned int padding4;    // 0x00000000
}; // Size: 16

struct FlagActor
{
    unsigned short actor_id; // 0x086, 0x087, 0x088, 0x089, 0x091, 0x226, 0x326, 0x345
    unsigned short padding1; // 0x0000
    unsigned short flag;     // Flag identifier (e.g., 0x00DA, 0x00F7)
    unsigned short padding2; // 0x0000
    unsigned int padding3;   // 0x00000000
    unsigned int padding4;   // 0x00000000
}; // Size: 16

struct SignActor
{
    unsigned short actor_id; // 0x08B
    unsigned short padding1; // 0x0000
    unsigned int padding2;   // 0x00000000
    unsigned short padding3; // 0x0000
    unsigned short message;  // Message ID (e.g., 0x013A)
    unsigned int padding4;   // 0x00000000
}; // Size: 16

struct ExitActor
{
    unsigned short actor_id;    // 0x08C
    unsigned short padding1;    // 0x0000
    unsigned short dest_room;   // Destination room ID (e.g., 0x01C5)
    unsigned short dest_x;      // Destination X coordinate (e.g., 0x0057)
    unsigned short dest_z;      // Destination Z coordinate (e.g., -0x0032 = 0xFFCE)
    unsigned short dest_y;      // Destination Y coordinate (e.g., 0x006E)
    unsigned short direction;   // Exit direction (e.g., 0x0300 = South)
    unsigned char misc_exit_id; // Misc exit ID (e.g., 0x28)
    unsigned char misc_unknown; // Unknown value (e.g., 0x13)
}; // Size: 16

struct SlidingDoorActor
{
    unsigned short actor_id; // 0x24D
    unsigned short padding1; // 0x0000
    unsigned char graphic;   // Graphic/appearance type (e.g., 0x01)
    unsigned char padding2;  // 0x00
    unsigned short padding3; // 0x0000
    unsigned int padding4;   // 0x00000000
    unsigned char padding5;  // 0x00
    unsigned char exit_id;   // Exit ID (e.g., 0x03)
    unsigned short padding6; // 0x0000
}; // Size: 16

struct RyoActor
{
    unsigned short actor_id; // 0x082
    unsigned short padding1; // 0x0000
    unsigned char size;      // Size type (e.g., 0x01 = Normal)
    unsigned char padding2;  // 0x00
    unsigned short padding3; // 0x0000
    unsigned int padding4;   // 0x00000000
    unsigned int padding5;   // 0x00000000
}; // Size: 16

struct ActorInstance
{
    struct Position position;
    struct Rotation rotation;
    struct ActorDefinition *actor_definition;
    unsigned char is_spawned;
    unsigned char unk_11;
    unsigned char unk_12;
    unsigned char unk_13;
}; // Size: 20

struct StageActorMetadata
{
    struct ActorInstance *persistent_actor_instances;
    const char **actor_definition_names;
    struct ActorInstance *actor_instances;
    void *actor_partitions;              // Keep as void* since not used
    void *actor_partition_configuration; // Keep as void* since not used
    short actor_data_file_id;
    short unk_16;
    void (*load_stage_data_files)(void);
}; // Size: 28

extern struct StageActorMetadata *D_80231300_5EC7D0[];

extern void *func_800141C4_14DC4(unsigned int file_id);                // overlay_get_data_pointer
extern void *func_80014840_15440(void *pointer, unsigned int file_id); // overlay_resolve_pointer
extern unsigned int func_80013B14_14714(unsigned short file_id);       // individual file loader
extern short *get_stage_file_list(unsigned short stage_id);            // lookup function from room_files.c

// Missing function declarations for door/exit handling
extern void func_80215330_5D0800(void *task);
extern void func_8003521C_35E1C(void *func_ptr);
extern void func_802154F0_5D09C0(void);
extern int func_802154FC_5D09CC(unsigned int player_ptr, void *object, int radius);
extern void func_801FB270_5B7180(void);

// Original function declaration for manual calling
extern void func_80013AC4_146C4(short *file_list);

extern unsigned short D_800C7AB2; // Part of the huge "SYS_W" structure, ID of the current stage
extern void func_80038B98_39798(unsigned short stage_id);
extern void func_80023DF0_249F0(int param);
extern void func_8003D310_3DF10(int param);
// Hook to modify file list before calling original function
RECOMP_HOOK("func_80013AC4_146C4")
void func_80013AC4_146C4_hook(short *file_list)
{
    // Safety check for null pointer
    if (file_list == NULL)
    {
        return;
    }
    // Count existing files
    int file_count = 0;
    for (int i = 0; i < 32 && file_list[i] != 0; i++)
    {
        file_count++;
    }

    // Files to add: 026, 025, 024, 021, 023, 027
    // short files_to_add[] = {0x026, 0x025, 0x024, 0x021, 0x023, 0x027, 0x01a};
    short files_to_add[] = {};
    int num_files_to_add = sizeof(files_to_add) / sizeof(files_to_add[0]);

    // Room-specific file additions
    if (D_800C7AB2 == 0x009)
    {
        // Add file 01a for room 009
        if (file_count < 31)
        {
            file_list[file_count] = 0x01a;
            file_count++;
            recomp_printf("Added file 0x01a for room 009\n");
        }
    }

    // Add files if there's space
    for (int i = 0; i < num_files_to_add && file_count < 31; i++)
    {
        file_list[file_count] = files_to_add[i];
        file_count++;
    }

    // Null terminate
    if (file_count < 32)
    {
        file_list[file_count] = 0;
    }
}

struct OverlayEntry
{
    unsigned short file_id;
    unsigned short unk_2;
    void *data;
};

extern struct OverlayEntry D_80167FC0_168BC0[40];

static unsigned char *buffer;

void validate_flags_updated()
{
    recomp_printf("Validating flags updated function called\n");
    // if we have 0x11 bit 7 set, then the Super Pass has been obtained
    // Then make sure we set SET_FLAG_BIT(0x00, 1, 1);  // Bridge Guards Opened Gate Already
    if (READ_FLAG_BIT(0x11, 7))
    {
        recomp_printf("Super Pass obtained, setting Bridge Guards Opened Gate Already flag\n");
        SET_FLAG_BIT(0x00, 1, 1); // Bridge Guards Opened Gate Already
    }
}

RECOMP_HOOK("func_8020D724_5C8BF4")
void func_8020D724_5C8BF4_hook()
{
    recomp_printf("func_8020D724_5C8BF4 called\n");
    validate_flags_updated();
    // Get the actor data file ID for the current stage
    unsigned short actor_data_file_id = D_80231300_5EC7D0[D_800C7AB2]->actor_data_file_id;

    // Get the memory address of the actor data file in memory
    void *actor_data_file_buffer = func_800141C4_14DC4(actor_data_file_id);

    // Copy actor data file into a new buffer
    if (buffer != NULL)
    {
        recomp_free(buffer);
    }

    buffer = recomp_alloc(0x10000);

    for (int i = 0; i < 0x10000; i++)
    {
        buffer[i] = ((unsigned char *)actor_data_file_buffer)[i];
    }

    // Update the overlay entry to point to the new buffer
    for (int i = 0; i < 40; i++)
    {
        if (D_80167FC0_168BC0[i].file_id == actor_data_file_id)
        {
            recomp_printf("Updating overlay entry for file %d from %p to %p\n", actor_data_file_id, D_80167FC0_168BC0[i].data, buffer);
            D_80167FC0_168BC0[i].data = buffer;
            break;
        }
    }

    // Edit the actor data in the new buffer as needed
    struct ActorInstance *actor_instances = func_80014840_15440(D_80231300_5EC7D0[D_800C7AB2]->actor_instances, actor_data_file_id);

    // First, count regular instances to find where grouped instances start
    int regular_instance_count = 0;
    for (int i = 0;; i++)
    {
        struct ActorInstance *actor_instance = &actor_instances[i];
        if (actor_instance->actor_definition == NULL)
        {
            regular_instance_count = i;
            break;
        }
    }

    // Calculate grouped data location
    size_t grouped_data_offset = regular_instance_count * sizeof(struct ActorInstance) + sizeof(struct ActorInstance);
    unsigned char *raw_buffer = (unsigned char *)actor_instances;
    unsigned char *grouped_data_start = raw_buffer + grouped_data_offset;

    // Count total instances (regular + grouped)
    int total_instances = regular_instance_count;
    int max_grouped_data_size = 2048;

    for (int offset = 0; offset < max_grouped_data_size; offset += sizeof(struct ActorInstance))
    {
        struct ActorInstance *potential_instance = (struct ActorInstance *)(grouped_data_start + offset);
        unsigned char *raw_bytes = (unsigned char *)potential_instance;

        // Check for valid grouped instance
        bool has_0800_pattern = (offset + 12 < max_grouped_data_size &&
                                 raw_bytes[12] == 0x08 && raw_bytes[13] == 0x00);
        bool reasonable_position = (potential_instance->position.x > -10000 && potential_instance->position.x < 10000 &&
                                    potential_instance->position.y > -10000 && potential_instance->position.y < 10000 &&
                                    potential_instance->position.z > -10000 && potential_instance->position.z < 10000);

        if (has_0800_pattern && reasonable_position)
        {
            total_instances++;
        }
        else if (offset > 100)
        {
            // Check for end of data
            bool all_zero = true;
            for (int check = 0; check < 60; check++)
            {
                if (offset + check < max_grouped_data_size && grouped_data_start[offset + check] != 0)
                {
                    all_zero = false;
                    break;
                }
            }
            if (all_zero)
                break;
        }
    }

    // Counter for tracking replacements
    int robot_replacements_made = 0;

    // Robot IDs that can be replaced
    unsigned short source_robot_ids[] = {0x0fb, 0x0fc, 0x0fd, 0x0fe, 0x12d};
    int num_source_robots = sizeof(source_robot_ids) / sizeof(source_robot_ids[0]);

    // Robot IDs to replace with (including originals for possible no-change)
    unsigned short target_robot_ids[] = {0x0fb, 0x0fc, 0x0fd, 0x0fe, 0x12d, 0x100, 0x103, 0x130, 0x0ff, 0x132, 0x133, 0x145, 0x10c, 0x13d};
    int num_target_robots = sizeof(target_robot_ids) / sizeof(target_robot_ids[0]);

    // Simple random seed based on stage ID for deterministic randomness per stage
    unsigned int random_seed = D_800C7AB2 * 1103515245 + 12345;

    // Process all instances in a unified manner
    int grouped_index = 0;
    for (int overall_index = 0; overall_index < total_instances; overall_index++)
    {
        struct ActorInstance *actor_instance = NULL;

        if (overall_index < regular_instance_count)
        {
            // Regular instance
            actor_instance = &actor_instances[overall_index];
        }
        else
        {
            // Grouped instance - find the next valid grouped instance
            while ((int)(grouped_index * sizeof(struct ActorInstance)) < max_grouped_data_size)
            {
                struct ActorInstance *potential_instance = (struct ActorInstance *)(grouped_data_start + grouped_index * sizeof(struct ActorInstance));
                unsigned char *raw_bytes = (unsigned char *)potential_instance;

                bool has_0800_pattern = ((int)(grouped_index * sizeof(struct ActorInstance)) + 12 < max_grouped_data_size &&
                                         raw_bytes[12] == 0x08 && raw_bytes[13] == 0x00);
                bool reasonable_position = (potential_instance->position.x > -10000 && potential_instance->position.x < 10000 &&
                                            potential_instance->position.y > -10000 && potential_instance->position.y < 10000 &&
                                            potential_instance->position.z > -10000 && potential_instance->position.z < 10000);

                if (has_0800_pattern && reasonable_position)
                {
                    actor_instance = potential_instance;
                    grouped_index++;
                    break;
                }
                grouped_index++;
            }
        }

        if (actor_instance == NULL)
            break;

        // Resolve the actor definition pointer to the new buffer
        struct ActorDefinition *resolved_actor_def = func_80014840_15440(actor_instance->actor_definition, actor_data_file_id);

        if (resolved_actor_def != NULL)
        {
            // Extract actor ID from the first data field (shift right by 16 to get the upper 16 bits)
            unsigned short actor_id = (resolved_actor_def->data[0] >> 16) & 0xFFFF;

            // Check if current stage is 0x12C and if this actor is one of our target robot IDs
            if (D_800C7AB2 == 0x012C)
            {
                // Check if this actor ID is in our source robot list
                bool is_target_robot = false;
                for (int i = 0; i < num_source_robots; i++)
                {
                    if (actor_id == source_robot_ids[i])
                    {
                        is_target_robot = true;
                        break;
                    }
                }

                if (is_target_robot)
                {
                    // Generate random index for replacement robot
                    random_seed = random_seed * 1103515245 + 12345;
                    int random_index = (random_seed >> 16) % num_target_robots;
                    unsigned short new_robot_id = target_robot_ids[random_index];

                    // Create a new actor definition for this specific instance
                    struct ActorDefinition *new_actor_def = (struct ActorDefinition *)recomp_alloc(sizeof(struct ActorDefinition));
                    if (new_actor_def != NULL)
                    {
                        // Copy the original definition data
                        new_actor_def->data[0] = resolved_actor_def->data[0];
                        new_actor_def->data[1] = resolved_actor_def->data[1];
                        new_actor_def->data[2] = resolved_actor_def->data[2];
                        new_actor_def->data[3] = resolved_actor_def->data[3];

                        // Change the actor ID in the new definition
                        new_actor_def->data[0] = (new_actor_def->data[0] & 0x0000FFFF) | (new_robot_id << 16);

                        // Update this instance to point to the new definition
                        actor_instance->actor_definition = new_actor_def;

                        recomp_printf("Robot randomization: 0x%03X -> 0x%03X (instance %d)\n", actor_id, new_robot_id, robot_replacements_made);
                        robot_replacements_made++;
                    }
                }
            }

            // Check for locked door actor (0x23E) and handle it with struct
            if (actor_id == 0x23e)
            {
                // Cast the actor definition to our locked door struct
                struct LockedDoorActor *locked_door = (struct LockedDoorActor *)resolved_actor_def;

                // // Check for specific locked door modification in room 009
                // if (D_800C7AB2 == 0x009 && locked_door->lock_index == 0x010b && locked_door->accept_key == 0x010c) {
                //     // Create a new locked door actor definition for this specific instance
                //     struct LockedDoorActor *new_door = (struct LockedDoorActor *)recomp_alloc(sizeof(struct LockedDoorActor));
                //     if (new_door != NULL) {
                //         // Copy the original door data
                //         *new_door = *locked_door;

                //         // Update the lock index and accept key
                //         new_door->lock_index = 0x010b;     // Change from 010b to 010f
                //         new_door->accept_key = 0x0110;     // Change from 010c to 0110

                //         // Update this instance to point to the new definition
                //         actor_instance->actor_definition = (struct ActorDefinition *)new_door;

                //         recomp_printf("Locked door modification in room 009: lock_index 0x010b->0x010f, accept_key 0x010c->0x0110 (instance %d)\n", overall_index);
                //     }
                // }
                // Locked door processing logic can be added here
            }

            // Check for key actor (0x193) and handle it with struct
            if (actor_id == 0x193)
            {
                // Cast the actor definition to our key struct
                struct KeyActor *key = (struct KeyActor *)resolved_actor_def;
                // Key processing logic can be added here
            }

            // Check for flag actors and handle them with struct
            if (actor_id == 0x086 || actor_id == 0x087 || actor_id == 0x088 || actor_id == 0x089 ||
                actor_id == 0x091 || actor_id == 0x226 || actor_id == 0x326 || actor_id == 0x345)
            {
                // Cast the actor definition to our flag struct
                struct FlagActor *flag = (struct FlagActor *)resolved_actor_def;

                // Check for specific actor conversion in room 009: actor 086 -> key 193
                // if (D_800C7AB2 == 0x009 && actor_id == 0x086) {
                //     // Create a new key actor definition for this specific instance
                //     struct KeyActor *new_key = (struct KeyActor *)recomp_alloc(sizeof(struct KeyActor));
                //     if (new_key != NULL) {
                //         // Set up the key actor parameters as specified
                //         new_key->actor_id = 0x0193;        // Key actor ID
                //         new_key->padding1 = 0x0000;        // Padding
                //         new_key->enemies = 0x0000;         // No enemies required
                //         new_key->padding2 = 0x0000;        // Padding
                //         new_key->key_index = 0x0110;       // Key index 0110
                //         new_key->padding3 = 0x0000;        // Padding
                //         new_key->padding4 = 0x00000000;    // Padding

                //         // Update this instance to point to the new definition
                //         actor_instance->actor_definition = (struct ActorDefinition *)new_key;

                //         recomp_printf("Actor conversion in room 009: 0x086 -> 0x193 Key (instance %d)\n", overall_index);
                //     }
                // }

                // Check for specific actor conversion in room 164: actor 088 -> key 193
                if (D_800C7AB2 == 0x164 && actor_id == 0x088)
                {
                    // Create a new key actor definition for this specific instance
                    struct KeyActor *new_key = (struct KeyActor *)recomp_alloc(sizeof(struct KeyActor));
                    if (new_key != NULL)
                    {
                        // Set up the key actor parameters as specified
                        new_key->actor_id = 0x0193;     // Key actor ID
                        new_key->padding1 = 0x0000;     // Padding
                        new_key->enemies = 0x0000;      // No enemies required
                        new_key->padding2 = 0x0000;     // Padding
                        new_key->key_index = 0x01b5;    // Key index 0110
                        new_key->padding3 = 0x0000;     // Padding
                        new_key->padding4 = 0x00000000; // Padding

                        // Update this instance to point to the new definition
                        actor_instance->actor_definition = (struct ActorDefinition *)new_key;

                        recomp_printf("Actor conversion in room 164: 0x088 -> 0x193 Key (instance %d)\n", overall_index);
                    }
                }
                // Flag processing logic can be added here
            }

            // Check for sign actor (0x08B) and handle it with struct
            if (actor_id == 0x08b)
            {
                // Cast the actor definition to our sign struct
                struct SignActor *sign = (struct SignActor *)resolved_actor_def;
                // Sign processing logic can be added here
            }

            // Check for exit actor (0x08C) and handle it with struct
            if (actor_id == 0x08c)
            {
                // Cast the actor definition to our exit struct
                struct ExitActor *exit = (struct ExitActor *)resolved_actor_def;

                // // Check for specific exit in room 0x002, instance index 3
                // if (D_800C7AB2 == 0x002 && overall_index == 3 && exit->dest_room == 0x0007 && true == false) {
                //     // Create a new actor definition for this specific instance
                //     struct ExitActor *new_exit = (struct ExitActor *)recomp_alloc(sizeof(struct ExitActor));
                //     if (new_exit != NULL) {
                //         // Copy the original exit data
                //         *new_exit = *exit;

                //         // Update the exit destination to Kai Highway
                //         new_exit->dest_room = 0x012c;
                //         new_exit->dest_x = 0xa94;       // -0x056c in two's complement = 0xa94
                //         new_exit->dest_z = 0x0108;
                //         new_exit->dest_y = 0x0264;
                //         new_exit->direction = 0x0100;   // North
                //         new_exit->misc_exit_id = 02;
                //         new_exit->misc_unknown = 10;

                //         // Update this instance to point to the new definition
                //         actor_instance->actor_definition = (struct ActorDefinition *)new_exit;

                //         recomp_printf("Exit modification: Room 002 Instance 3 -> Kai Highway (012c)\n");
                //     }
                // }
            }

            // Check for sliding door actor (0x24D) and handle it with struct
            if (actor_id == 0x24d)
            {
                // Cast the actor definition to our sliding door struct
                struct SlidingDoorActor *sliding_door = (struct SlidingDoorActor *)resolved_actor_def;
                // Sliding door processing logic can be added here
            }

            // Check for actor 0x241 and handle door conversion
            if (actor_id == 0x241)
            {
                // Check for specific actor in room 0x130 and instance id 4, and flag bit is UNSET (value = 0)
                // 0x11 is Super Pass
                if (D_800C7AB2 == 0x130 && overall_index == 4 && !READ_FLAG_BIT(0x11, 7))
                {
                    // Create a new locked door actor definition
                    struct LockedDoorActor *new_door = (struct LockedDoorActor *)recomp_alloc(sizeof(struct LockedDoorActor));
                    if (new_door != NULL)
                    {
                        // Set up the locked door parameters as specified
                        new_door->actor_id = 0x023e;   // Locked door actor ID
                        new_door->padding1 = 0x0000;   // Padding
                        new_door->door_design = 0x05;  // Door design 05
                        new_door->key_type = 0x03;     // Key type 03
                        new_door->padding2 = 0x0000;   // Padding
                        new_door->lock_index = 0xFFFF; // Lock index 0011
                        new_door->accept_key = 0xFFFF; // Accept key FFFF
                        new_door->exit_id = 0x01;      // Exit ID 01
                        new_door->padding3 = 0x0000;   // Padding

                        // Update this instance to point to the new definition
                        actor_instance->actor_definition = (struct ActorDefinition *)new_door;

                        recomp_printf("Door conversion: Room 0x130 Actor 0x241 Instance %d -> Locked Door 0x23E (Bridge Guards flag NOT set)\n", overall_index);
                    }
                }
            }

            // Check for ryo actor (0x082) and handle it with struct
            if (actor_id == 0x082)
            {
                // Cast the actor definition to our ryo struct
                struct RyoActor *ryo = (struct RyoActor *)resolved_actor_def;
                // Ryo processing logic can be added here
            }

            // // Debug logging for new actor types to help format them
            // if (actor_id == 0x339)
            // {
            //     recomp_printf("=== NEW ACTOR 0x%03X FOUND ===\n", actor_id);
            //     recomp_printf("Instance %d (overall index %d)\n", overall_index < regular_instance_count ? overall_index : grouped_index - 1, overall_index);
            //     recomp_printf("Position: (%d, %d, %d)\n", actor_instance->position.x, actor_instance->position.y, actor_instance->position.z);
            //     recomp_printf("Rotation: (%d, %d, %d)\n", actor_instance->rotation.pitch, actor_instance->rotation.yaw, actor_instance->rotation.roll);
            //     recomp_printf("Actor Definition Pointer: %p\n", actor_instance->actor_definition);
            //     recomp_printf("Resolved Actor Definition Pointer: %p\n", resolved_actor_def);
            //     recomp_printf("Is Spawned: 0x%02X\n", actor_instance->is_spawned);
            //     recomp_printf("Unk fields: 0x%02X, 0x%02X, 0x%02X\n", actor_instance->unk_11, actor_instance->unk_12, actor_instance->unk_13);
            //     recomp_printf("Actor Definition Data:\n");
            //     recomp_printf("  data[0]: 0x%08X (Actor ID: 0x%03X, Lower: 0x%04X)\n", resolved_actor_def->data[0], actor_id, resolved_actor_def->data[0] & 0xFFFF);
            //     recomp_printf("  data[1]: 0x%08X\n", resolved_actor_def->data[1]);
            //     recomp_printf("  data[2]: 0x%08X\n", resolved_actor_def->data[2]);
            //     recomp_printf("  data[3]: 0x%08X\n", resolved_actor_def->data[3]);

            //     // Print raw bytes around the actor instance for additional context
            //     unsigned char *raw_instance = (unsigned char *)actor_instance;
            //     recomp_printf("Raw instance bytes (20 bytes):\n");
            //     recomp_printf("  ");
            //     for (int byte_i = 0; byte_i < 20; byte_i++)
            //     {
            //         recomp_printf("%02X ", raw_instance[byte_i]);
            //         if ((byte_i + 1) % 8 == 0)
            //             recomp_printf("\n  ");
            //     }
            //     recomp_printf("\n");

            //     // Print raw bytes of the actor definition
            //     unsigned char *raw_def = (unsigned char *)resolved_actor_def;
            //     recomp_printf("Raw definition bytes (16 bytes):\n");
            //     recomp_printf("  ");
            //     for (int byte_i = 0; byte_i < 16; byte_i++)
            //     {
            //         recomp_printf("%02X ", raw_def[byte_i]);
            //         if ((byte_i + 1) % 8 == 0)
            //             recomp_printf("\n  ");
            //     }
            //     recomp_printf("\n===============================\n");
            // }
        }
    }
}
