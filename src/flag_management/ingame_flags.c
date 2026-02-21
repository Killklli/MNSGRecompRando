#include "ingame_flags.h"

#include "Archipelago.h"
#include "ap_datastorage.h"
#include "extended_save.h"
#include "libc/stdio.h"
#include "modding.h"
#include "recomputils.h"
#include "save_data_tool.h"

// External data declaration
extern u8 D_8015C608_15D208[];

RECOMP_PATCH s32 func_800240DC_24CDC(s32 flag_id) {
    // Read from local game data if within bounds
    s32 result = 0;

    if (flag_id >= 0 && flag_id <= 6143) {
        s32 byte_index;
        s32 bit_index;
        u8 byte_value;
        s32 bit_mask;

        // These two flags PURELY exist because the cutscenes check the actual item value, but its only a cutscene that checks it, so this should be fine
        if (flag_id == 0)
        {
            s32 super_pass_value = READ_SAVE_DATA(SAVE_SUPER_PASS);
            s32 result = (super_pass_value != 0) ? 1 : 0;
            return result;
        }
        if (flag_id == 0x29)
        {
            s32 have_achilles_heel = READ_SAVE_DATA(SAVE_ACHILLES_HEEL);
            s32 result = (have_achilles_heel != 0) ? 1 : 0;
            return result;
        }

        // Calculate byte index - divide by 8 with sign-aware right shift
        if (flag_id < 0) {
            byte_index = (flag_id + 7) >> 3; // Add 7 before shifting for negative numbers
        } else {
            byte_index = flag_id >> 3; // Simple right shift for positive numbers
        }

        // Mask to ensure byte_index is within u8 range
        byte_index &= 0xFF;

        // Load the byte from the data array
        byte_value = D_8015C608_15D208[byte_index];

        // Calculate bit position within the byte
        if (flag_id < 0) {
            bit_index = flag_id & 7;
            if (bit_index != 0) {
                bit_index -= 8; // Adjust for negative numbers
            }
        } else {
            bit_index = flag_id & 7;
        }

        // Mask to ensure bit_index is within u8 range
        bit_index &= 0xFF;

        // Create bit mask by shifting 1 left by bit_index positions
        bit_mask = 1 << bit_index;

        // Check if the bit is set
        result = (byte_value & bit_mask) ? 1 : 0;
        DEBUG_PRINTF("FLAG READ: flag_id=%ld, local value=%ld\n", flag_id, result);
    } else if (flag_id >= 6144 && flag_id <= ((0x304 + get_extended_save_size()) * 8 - 1)) {
        // Handle extended save area
        init_extended_save();
        s32 extended_flag_id = flag_id - 6144;
        s32 byte_index = extended_flag_id >> 3;
        s32 bit_index = extended_flag_id & 7;

        if (byte_index >= 0 && byte_index < get_extended_save_size()) {
            u8 byte_value = get_extended_save_byte(byte_index);
            s32 bit_mask = 1 << bit_index;
            result = (byte_value & bit_mask) ? 1 : 0;
            DEBUG_PRINTF("FLAG READ: flag_id=%ld, extended save value=%ld\n", flag_id, result);
        } else {
            DEBUG_PRINTF("FLAG READ: flag_id=%ld is OUTSIDE extended bounds, returning 0\n", flag_id);
            result = 0;
        }
    } else {
        DEBUG_PRINTF("FLAG READ: flag_id=%ld is OUTSIDE all bounds, returning 0\n", flag_id);
        result = 0;
    }

    return result;
}

RECOMP_PATCH void func_80024038_24C38(s32 flag_id) {
    // Create key string for this flag
    char key[16];
    sprintf(key, "flag_%ld", flag_id);

    // Write to data storage only if connected
    if (rando_is_connected()) {
        rando_set_datastorage_u32_async(key, 1);
    } // If flag is within bounds of D_8015C608_15D208 (0x304 bytes = 6144 flags
      // max, so flags 0-6143)
    if (flag_id >= 0 && flag_id <= 6143) {
        s32 byte_index;
        s32 bit_index;
        u8 current_byte;
        u8 bit_mask;

        // Calculate byte index - divide by 8 with sign-aware right shift
        if (flag_id < 0) {
            byte_index = (flag_id + 7) >> 3; // Add 7 before shifting for negative numbers
        } else {
            byte_index = flag_id >> 3; // Simple right shift for positive numbers
        }

        // Mask to ensure byte_index is within u8 range
        byte_index &= 0xFF;

        // Load the current byte from the bitfield array
        current_byte = D_8015C608_15D208[byte_index];

        // Calculate bit position within the byte
        if (flag_id < 0) {
            bit_index = flag_id & 7;
            if (bit_index != 0) {
                bit_index -= 8; // Adjust for negative numbers
            }
        } else {
            bit_index = flag_id & 7;
        }

        // Mask to ensure bit_index is within u8 range
        bit_index &= 0xFF;

        // Create bit mask by shifting 1 left by bit_index positions
        bit_mask = 1 << bit_index;

        // Set the bit using OR operation
        current_byte |= bit_mask;

        // Store the modified byte back to the array
        D_8015C608_15D208[byte_index] = current_byte;

        DEBUG_PRINTF("FLAG SET: flag_id=%ld written to BOTH local array and datastore\n", flag_id);
    } else if (flag_id >= 6144 && flag_id <= ((0x304 + get_extended_save_size()) * 8 - 1)) {
        // Handle extended save area
        init_extended_save();
        s32 extended_flag_id = flag_id - 6144;
        s32 byte_index = extended_flag_id >> 3;
        s32 bit_index = extended_flag_id & 7;

        if (byte_index >= 0 && byte_index < get_extended_save_size()) {
            u8 current_byte = get_extended_save_byte(byte_index);
            u8 bit_mask = 1 << bit_index;
            set_extended_save_byte(byte_index, current_byte | bit_mask);

            DEBUG_PRINTF("FLAG SET: flag_id=%ld written to extended save array and datastore\n", flag_id);
        } else {
            DEBUG_PRINTF("FLAG SET: flag_id=%ld is OUTSIDE extended bounds, written to datastore only\n", flag_id);
        }
    } else {
        DEBUG_PRINTF("FLAG SET: flag_id=%ld is OUTSIDE all bounds, written to datastore only\n", flag_id);
    }
    save_player_data();
    // Update the full save data string
    update_full_save_data();
}

RECOMP_PATCH void func_80024088_24C88(int bit_index) {
    // Create key string for this flag
    char key[16];
    sprintf(key, "flag_%d", bit_index);

    // Clear in data storage only if connected
    if (rando_is_connected()) {
        rando_set_datastorage_u32_async(key, 0);
    } // If flag is within bounds of D_8015C608_15D208 (0x304 bytes = 6144 flags
      // max)
    if (bit_index >= 0 && bit_index <= ((0x304 * 8) - 1)) {
        int byte_index;
        int bit_offset;
        unsigned char current_byte;
        unsigned char bit_mask;

        // Calculate byte index (bit_index / 8)
        if (bit_index < 0) {
            byte_index = (bit_index + 7) >> 3;
        } else {
            byte_index = bit_index >> 3;
        }

        // Get the current byte from the array
        current_byte = D_8015C608_15D208[byte_index & 0xFF];

        // Calculate bit offset within the byte
        bit_offset = bit_index & 7;
        if (bit_index < 0 && bit_offset != 0) {
            bit_offset = bit_offset - 8;
        }
        bit_offset &= 0xFF;

        // Create bit mask and clear the bit
        bit_mask = ~(1 << bit_offset);
        D_8015C608_15D208[byte_index & 0xFF] = current_byte & bit_mask;

        DEBUG_PRINTF("FLAG CLEAR: flag_id=%d cleared from BOTH local array and datastore\n", bit_index);
    } else if (bit_index >= (0x304 * 8) && bit_index <= ((0x304 + get_extended_save_size()) * 8 - 1)) {
        // Handle extended save area
        init_extended_save();
        int extended_bit_index = bit_index - (0x304 * 8);
        int byte_index = extended_bit_index >> 3;
        int bit_offset = extended_bit_index & 7;

        if (byte_index >= 0 && byte_index < get_extended_save_size()) {
            unsigned char current_byte = get_extended_save_byte(byte_index);
            unsigned char bit_mask = ~(1 << bit_offset);
            set_extended_save_byte(byte_index, current_byte & bit_mask);

            DEBUG_PRINTF("FLAG CLEAR: flag_id=%d cleared from extended save array and datastore\n", bit_index);
        } else {
            DEBUG_PRINTF("FLAG CLEAR: flag_id=%d is OUTSIDE extended bounds, cleared from "
                         "datastore only\n",
                         bit_index);
        }
    } else {
        DEBUG_PRINTF("FLAG CLEAR: flag_id=%d is OUTSIDE all bounds, cleared from "
                     "datastore only\n",
                     bit_index);
    }

    // Save additional game state values to their own datastore keys
    save_player_data();

    // Update the full save data string
    update_full_save_data();
}