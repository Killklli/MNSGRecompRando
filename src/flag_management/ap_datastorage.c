#include "ap_datastorage.h"

#include "Archipelago.h"
#include "extended_save.h"
#include "libc/stdio.h"
#include "modding.h"
#include "recomputils.h"
#include "save_data_tool.h"

// External data declaration
extern u8 D_8015C608_15D208[];

// Create comma-delimited string of all bytes in D_8015C608_15D208 and store it
void update_full_save_data(void) {
    if (!rando_is_connected()) {
        return;
    }

    // Calculate required buffer size: (0x304 + EXTENDED_SAVE_SIZE) bytes * 3 chars per byte ("255") + commas + 1 null terminator
    // = (0x304 + 0x200) * 3 + (0x304 + 0x200 - 1) + 1 = 3843 + 1283 + 1 = 5127 bytes
    static char full_save_string[5200]; // Round up for safety
    int pos = 0;

    // First, save the main D_8015C608_15D208 array
    for (int i = 0; i < 0x304; i++) {
        if (i > 0) {
            full_save_string[pos++] = ',';
        }
        pos += sprintf(&full_save_string[pos], "%u", (unsigned int)D_8015C608_15D208[i]);
    }

    // Then, save the extended_save array
    init_extended_save();
    int extended_save_size = get_extended_save_size();
    for (int i = 0; i < extended_save_size; i++) {
        full_save_string[pos++] = ',';
        pos += sprintf(&full_save_string[pos], "%u", (unsigned int)get_extended_save_byte(i));
    }
    full_save_string[pos] = '\0';

    // Read the current values and store them
    s32 current_health = READ_SAVE_DATA(SAVE_CURRENT_HEALTH);
    s32 total_health = READ_SAVE_DATA(SAVE_TOTAL_HEALTH);

    // Only store if total_health is not 0 (indicating valid game state)
    if (total_health != 0 && current_health != 0) {
        // Store the full save string in the datastore
        rando_set_datastorage_string_async("full_save", full_save_string);
        DEBUG_PRINTF("FULL SAVE: Updated full_save data string\n");
        DEBUG_PRINTF("FULL SAVE STRING: %s\n", full_save_string);
        DEBUG_PRINTF("FULL SAVE: String length=%d\n", pos);
    }
}

// Load comma-delimited string from data storage back into D_8015C608_15D208 array
// Returns true if data was successfully loaded, false otherwise
bool load_full_save_data_from_storage(void) {
    if (!rando_is_connected()) {
        DEBUG_PRINTF("LOAD FULL SAVE: Not connected, cannot load data\n");
        return false;
    }

    // Allocate buffer for the full save string (same size as in update_full_save_data)
    static char full_save_string[5200];

    // Initialize extended save array
    init_extended_save();

    // Get the full save string from data storage
    rando_get_datastorage_string_sync("full_save", full_save_string);

    // Check if we got any data
    if (full_save_string[0] == '\0') {
        DEBUG_PRINTF("LOAD FULL SAVE: No full_save data found in storage\n");
        return false;
    }

    DEBUG_PRINTF("LOAD FULL SAVE: Retrieved string from storage\n");
    DEBUG_PRINTF("LOAD FULL SAVE STRING: %s\n", full_save_string);

    // Parse the comma-delimited string and load into arrays
    char *token = full_save_string;
    char *next_token;
    int byte_index = 0;
    int extended_save_size = get_extended_save_size();
    int total_expected = 0x304 + extended_save_size;

    while (token != NULL && byte_index < total_expected) {
        // Find the next comma or end of string
        next_token = token;
        while (*next_token != ',' && *next_token != '\0') {
            next_token++;
        }

        // Temporarily null-terminate this token
        char saved_char = *next_token;
        *next_token = '\0';

        // Convert string to unsigned integer manually
        unsigned int byte_value = 0;
        char *digit_ptr = token;
        while (*digit_ptr >= '0' && *digit_ptr <= '9') {
            byte_value = byte_value * 10 + (*digit_ptr - '0');
            digit_ptr++;
        }

        // Store in the appropriate array (with bounds checking)
        if (byte_value <= 255) {
            if (byte_index < 0x304) {
                D_8015C608_15D208[byte_index] = (u8)byte_value;
            } else if (byte_index < 0x304 + extended_save_size) {
                set_extended_save_byte(byte_index - 0x304, (u8)byte_value);
            }
        } else {
            DEBUG_PRINTF("LOAD FULL SAVE: Warning - byte value %u out of range at index %d\n", byte_value, byte_index);
            if (byte_index < 0x304) {
                D_8015C608_15D208[byte_index] = 255; // Clamp to max value
            } else if (byte_index < 0x304 + extended_save_size) {
                set_extended_save_byte(byte_index - 0x304, 255);
            }
        }

        byte_index++;

        // Restore the character and move to next token
        *next_token = saved_char;
        if (saved_char == ',') {
            token = next_token + 1;
        } else {
            token = NULL; // End of string
        }
    }

    int main_bytes = (byte_index > 0x304) ? 0x304 : byte_index;
    int extended_bytes = (byte_index > 0x304) ? (byte_index - 0x304) : 0;

    DEBUG_PRINTF("LOAD FULL SAVE: Loaded %d bytes into D_8015C608_15D208 array\n", main_bytes);
    DEBUG_PRINTF("LOAD FULL SAVE: Loaded %d bytes into extended_save array\n", extended_bytes);

    if (byte_index != total_expected) {
        DEBUG_PRINTF("LOAD FULL SAVE: Warning - Expected %d bytes, got %d bytes\n", total_expected, byte_index);
    }

    return true;
}

// Save additional player data to datastore
void save_player_data() {
    // Save additional game state values to their own datastore keys
    if (rando_is_connected()) {
        // Read the current values and store them
        s32 current_lives = READ_SAVE_DATA(SAVE_CURRENT_LIFE_TOTAL);
        s32 current_ryo = READ_SAVE_DATA(SAVE_RYO);
        s32 current_health = READ_SAVE_DATA(SAVE_CURRENT_HEALTH);
        s32 total_health = READ_SAVE_DATA(SAVE_TOTAL_HEALTH);

        // Read inventory data
        s32 slot1_item = READ_SAVE_DATA(SAVE_SLOT_1_ITEM);
        s32 slot2_item = READ_SAVE_DATA(SAVE_SLOT_2_ITEM);
        s32 slot2_count = READ_SAVE_DATA(SAVE_SLOT_2_COUNT);
        s32 slot3_item = READ_SAVE_DATA(SAVE_SLOT_3_ITEM);
        s32 slot3_count = READ_SAVE_DATA(SAVE_SLOT_3_COUNT);

        // Only store if total_health is not 0 (indicating valid game state)
        if (total_health != 0 && current_health != 0) {
            // Store each value with its own key
            rando_set_datastorage_u32_async("save_current_lives", (u32)current_lives);
            rando_set_datastorage_u32_async("save_current_ryo", (u32)current_ryo);
            rando_set_datastorage_u32_async("save_current_health", (u32)current_health);
            rando_set_datastorage_u32_async("save_total_health", (u32)total_health);

            // Store inventory data
            rando_set_datastorage_u32_async("save_slot1_item", (u32)slot1_item);
            rando_set_datastorage_u32_async("save_slot2_item", (u32)slot2_item);
            rando_set_datastorage_u32_async("save_slot2_count", (u32)slot2_count);
            rando_set_datastorage_u32_async("save_slot3_item", (u32)slot3_item);
            rando_set_datastorage_u32_async("save_slot3_count", (u32)slot3_count);

            DEBUG_PRINTF("EXTRA SAVE: Stored current_lives=%ld, ryo=%ld, current_health=%ld, total_health=%ld\n", current_lives, current_ryo, current_health, total_health);
            DEBUG_PRINTF("EXTRA SAVE: Stored inventory - slot1_item=%ld, slot2_item=%ld, slot2_count=%ld, slot3_item=%ld, slot3_count=%ld\n", slot1_item, slot2_item, slot2_count, slot3_item, slot3_count);
        } else {
            DEBUG_PRINTF("EXTRA SAVE: Skipping save - total_health is 0 (invalid game state)\n");
        }
    }
}
