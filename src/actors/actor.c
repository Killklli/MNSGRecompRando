#include "actor_common.h"

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

struct OverlayEntry
{
    unsigned short file_id;
    unsigned short unk_2;
    void *data;
};

extern struct OverlayEntry D_80167FC0_168BC0[40];

static unsigned char *buffer;

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
    short files_to_add[] = {0x026, 0x025, 0x024, 0x021, 0x023, 0x027};
    //short files_to_add[] = {};
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


RECOMP_HOOK("func_8020D724_5C8BF4")
void func_8020D724_5C8BF4_hook()
{
    recomp_printf("func_8020D724_5C8BF4 called\n");
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

    // Process different actor types using separate modules
    process_enemy_actors(actor_instances, regular_instance_count, total_instances, grouped_data_start, max_grouped_data_size, actor_data_file_id);
    process_door_actors(actor_instances, regular_instance_count, total_instances, grouped_data_start, max_grouped_data_size, actor_data_file_id);
    process_key_actors(actor_instances, regular_instance_count, total_instances, grouped_data_start, max_grouped_data_size, actor_data_file_id);
    process_flag_actors(actor_instances, regular_instance_count, total_instances, grouped_data_start, max_grouped_data_size, actor_data_file_id);
    process_exit_actors(actor_instances, regular_instance_count, total_instances, grouped_data_start, max_grouped_data_size, actor_data_file_id);
    process_misc_actors(actor_instances, regular_instance_count, total_instances, grouped_data_start, max_grouped_data_size, actor_data_file_id);
}
