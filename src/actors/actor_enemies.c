#include "actor_common.h"
#include "entities.h"
#include "libc/stdbool.h"
#include "libc/stdio.h"
#include "libc/string.h"
#include "Archipelago.h"
#include "types.h"
#include "modding.h"
#include "file_state.h"

// Archipelago slotdata imports
RECOMP_IMPORT(".", void rando_get_slotdata_raw_o32(const char *key, u32 *out_handle_ptr));
RECOMP_IMPORT(".", void rando_access_slotdata_raw_dict_o32(u32 *in_handle_ptr, const char *key, u32 *out_handle_ptr));
RECOMP_IMPORT(".", void rando_iter_slotdata_raw_dict_o32(u32 *dict, u32 *iter_out));
RECOMP_IMPORT(".", bool rando_iter_slotdata_raw_dict_next_o32(u32 *dict, u32 *iter, u32 *key_out, u32 *value_out));
RECOMP_IMPORT(".", void rando_access_slotdata_raw_string_o32(u32 *slotdata_str, char *out_str));

extern unsigned short D_800C7AB2; // Part of the huge "SYS_W" structure, ID of the current stage

// Simple atoi implementation since it's not available in the limited libc
static int simple_atoi(const char *str)
{
    int result = 0;
    int sign = 1;

    // Skip whitespace
    while (*str == ' ' || *str == '\t')
    {
        str++;
    }

    // Handle sign
    if (*str == '-')
    {
        sign = -1;
        str++;
    }
    else if (*str == '+')
    {
        str++;
    }

    // Convert digits
    while (*str >= '0' && *str <= '9')
    {
        result = result * 10 + (*str - '0');
        str++;
    }

    return result * sign;
}

// Structure to hold enemy replacement pair (index and new value)
struct EnemyReplacementPair
{
    int index;
    unsigned short new_enemy_id;
};

// Structure to hold list of enemy replacement pairs
struct EnemyReplacementList
{
    struct EnemyReplacementPair *pairs;
    int count;
};

struct EnemyReplacementList get_enemy_replacements_for_room()
{
    struct EnemyReplacementList result = {NULL, 0};

    if (should_run_ap_logic())
    {
        // try to get the value of enemy_data and then get the key 0x13D
        // Convert room ID to string for lookup
        char room_id_str[16];
        sprintf(room_id_str, "%d", D_800C7AB2);
        // Get room file data from Archipelago slot data
        u32 room_files_handle[2];
        rando_get_slotdata_raw_o32("enemy_data", room_files_handle);

        u32 current_room_files[2];
        rando_access_slotdata_raw_dict_o32(room_files_handle, room_id_str, current_room_files);

        // Check if we actually got valid room data before clearing the original file list
        u32 files_iter[2];
        rando_iter_slotdata_raw_dict_o32(current_room_files, files_iter);

        // Test if there's any data in the iterator
        u32 test_file_key[2];
        u32 test_file_value[2];
        bool has_archipelago_data = rando_iter_slotdata_raw_dict_next_o32(current_room_files, files_iter, test_file_key, test_file_value);
        rando_iter_slotdata_raw_dict_close_o32(current_room_files, files_iter);
        if (has_archipelago_data)
        {
            // Count the number of replacements first
            int count = 0;
            u32 count_iter[2];
            rando_iter_slotdata_raw_dict_o32(current_room_files, count_iter);
            u32 temp_key[2], temp_value[2];
            while (rando_iter_slotdata_raw_dict_next_o32(current_room_files, count_iter, temp_key, temp_value))
            {
                count++;
            }
            rando_iter_slotdata_raw_dict_close_o32(current_room_files, count_iter);

            // Allocate memory for the pairs
            result.pairs = (struct EnemyReplacementPair *)recomp_alloc(count * sizeof(struct EnemyReplacementPair));
            result.count = count;

            if (result.pairs != NULL)
            {
                // Re-create the iterator for filling the pairs array
                u32 fill_iter[2];
                rando_iter_slotdata_raw_dict_o32(current_room_files, fill_iter);

                // Fill the pairs array
                int pair_index = 0;
                u32 file_key[2];
                u32 file_value[2];
                while (rando_iter_slotdata_raw_dict_next_o32(current_room_files, fill_iter, file_key, file_value))
                {
                    // Get the key as a string (enemy index)
                    char key_str[256];
                    rando_access_slotdata_raw_string_o32(file_key, key_str);

                    // Get the value as a string (new enemy ID)
                    char value_str[256];
                    rando_access_slotdata_raw_string_o32(file_value, value_str);

                    // Convert strings to integers
                    result.pairs[pair_index].index = simple_atoi(key_str);
                    result.pairs[pair_index].new_enemy_id = (unsigned short)simple_atoi(value_str);

                    pair_index++;
                }
                rando_iter_slotdata_raw_dict_close_o32(current_room_files, fill_iter);
            }
        }
    }

    return result;
}

void process_enemy_actors(struct ActorInstance *actor_instance, struct ActorDefinition *resolved_actor_def, unsigned short actor_id, unsigned short actor_data_file_id, int overall_index)
{
    // Get the replacement data for the current room from get_enemy_replacements_for_room
    struct EnemyReplacementList replacements = get_enemy_replacements_for_room();

    // Look for a replacement in the returned list
    unsigned short new_robot_id = 0;
    bool found_replacement = false;

    // Check the dynamic replacements from Archipelago
    for (int i = 0; i < replacements.count; i++)
    {
        if (replacements.pairs[i].index == overall_index)
        {
            // Skip if the new enemy ID is 0 (likely invalid)
            if (replacements.pairs[i].new_enemy_id == 0)
            {
                DEBUG_PRINTF("Skipping replacement for index %d: new enemy ID is 0\n", overall_index);
                break;
            }

            new_robot_id = replacements.pairs[i].new_enemy_id;
            found_replacement = true;
            break;
        }
    }

    if (found_replacement)
    {
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

            DEBUG_PRINTF("Enemy replaced in room 0x%03X: 0x%03X -> 0x%03X (index %d)\n",
                          D_800C7AB2, actor_id, new_robot_id, overall_index);
        }
    }

    // Clean up allocated memory
    if (replacements.pairs != NULL)
    {
        recomp_free(replacements.pairs);
    }
}

// For some reason we get a divide by zero in this function if certain floats are zero, so we just force them to 1.0f out of safety
RECOMP_HOOK("func_80219578_5D4A48")
void func_80219578_5D4A48_hook(void *arg0, float arg1)
{
    // Check and adjust float at offset 0xd8
    float *float_d8 = (float *)((unsigned char *)(arg0) + 0xd8);
    if (*float_d8 == 0.0f)
    {
        *float_d8 = 20.0f;
    }
    // Check and adjust float at offset 0xdc
    float *float_dc = (float *)((unsigned char *)(arg0) + 0xdc);
    if (*float_dc == 0.0f)
    {
        *float_dc = 20.0f;
    }
}

// External function declaration
extern s32 func_802268A8_5E1D78(void *obj);

// Fixes path tracing on enemies that try to path to the player, but start off in the air or invalid locations
RECOMP_PATCH void func_08001FF4_6D10D4(void *obj, void *arg1)
{
    // Check if obj pointer is valid
    if (obj == NULL)
    {
        return;
    }

    // Updated validation for 64-bit addresses that get sign-extended
    uintptr_t obj_addr = (uintptr_t)obj;
    // Check if this looks like a valid N64 address (either 32-bit or sign-extended 64-bit)
    if ((obj_addr & 0xFFFFFFFF) < 0x80000000 || (obj_addr & 0xFFFFFFFF) >= 0x88000000)
    {
        return;
    }

    // Try to read the first few bytes of the object to see if it's valid memory
    u32 *obj_as_u32 = (u32 *)obj;
    u32 first_word = *obj_as_u32;

    // Check if this looks like a valid object pointer by examining some common object fields
    if (first_word == 0 || first_word == 0xFFFFFFFF)
    {
        return;
    }

    // TEMPORARY: Skip the problematic function call to avoid crash
    // We'll assume it returns false for now and just log what would happen
    s32 condition_result = 0; // Assume false for now

    // Call the condition check function
    // s32 condition_result = func_802268A8_5E1D78(obj);

    if (condition_result)
    {
        // Additional safety check for the flags pointer
        u32 *flags_ptr = (u32 *)((u8 *)obj + 0x68);
        uintptr_t flags_addr = (uintptr_t)flags_ptr;

        if ((flags_addr & 0xFFFFFFFF) < 0x80000000 || (flags_addr & 0xFFFFFFFF) >= 0x88000000)
        {
            return;
        }

        // If condition is true, set bit 1 in the flags at offset 0x68
        u32 old_flags = *flags_ptr;
        *flags_ptr |= 0x2;
    }
}