#include "scenario_replacer.h"

#include "Archipelago.h"
#include "file_state.h"
#include "libc/stdio.h"
#include "libc/string.h"
#include "modding.h"
#include "recomputils.h"
#include "save_data_tool.h"
#include "scenario.h"
#include "types.h"

// External scenario_text_005F that we can modify directly
extern s16 scenario_text_005F[];

// External scenario references
extern s32 scenario_code_message_0ca_4b70[];
extern s32 scenario_code_message_1ea_63fc[];
extern s32 scenario_code_impact_departure[];
extern s32 scenario_code_poron_encounter[];
extern s32 scenario_code_message_30e_251c[];
extern s32 scenario_code_message_30c_1cd8[];
extern s32 scenario_code_message_162_d63c[];
extern s32 scenario_code_message_1ef_72b4[];
extern s32 scenario_code_message_082_36e0[];
extern s32 scenario_code_message_176_2ad4[];
extern s32 scenario_code_message_288_2f98[];
extern s32 scenario_code_message_1f1_797c[];
extern s32 scenario_code_message_14c_9904[];
extern s32 scenario_code_message_174_28bc[];
extern s32 scenario_code_message_17a_3650[];
extern s32 scenario_code_message_160_c028[];
extern s32 scenario_code_message_1cd_185c[];
extern s32 scenario_code_message_227_3a14[];
extern s32 scenario_code_message_157_a930[];
extern s32 scenario_code_message_15e_b798[];
extern s32 scenario_code_message_110_8420[];
extern s32 scenario_code_message_083_3834[];
extern s32 scenario_code_message_1ed_6bd4[];
extern s32 scenario_code_2410[];
extern s32 scenario_code_31f0[];
extern s32 scenario_code_3260[];

// Storage for dynamic text generation
static s16 dynamic_text_buffer[256];

// Generic function to update any text buffer with AP location data
void update_text_buffer_with_ap_location(s16 *text_buffer, s32 flag_id, const char *prefix, const char *suffix) {
    if (!rando_is_connected()) {
        recomp_printf("Rando not connected, keeping original text\n");
        return;
    }

    // Convert flag_id to string key
    char flag_str[16];
    sprintf(flag_str, "%d", flag_id);

    // Get the flag_id_to_ap_location_id dictionary from slot data
    u32 flag_to_location_handle[2];
    rando_get_slotdata_raw_o32("flag_id_to_ap_location_id", flag_to_location_handle);

    // Try to get the location_id value for this flag directly
    u32 location_id_handle[2];
    rando_access_slotdata_raw_dict_o32(flag_to_location_handle, flag_str, location_id_handle);

    // Check if we got a valid handle (non-zero indicates success)
    if (location_id_handle[0] == 0 && location_id_handle[1] == 0) {
        recomp_printf("Flag %d not found in flag_id_to_ap_location_id mapping\n", flag_id);
        return;
    }

    // Extract the integer value
    u32 ap_location_id = rando_access_slotdata_raw_u32_o32(location_id_handle);
    recomp_printf("Flag %d maps to location_id: %d\n", flag_id, ap_location_id);

    // Get the player
    char player[17];
    rando_get_location_item_player(ap_location_id, player);
    recomp_printf("got player %s\n", player);

    // Get the item at the location
    u32 item_id = rando_get_item_at_location(ap_location_id);

    // Get the item name
    char item_name[33];
    rando_get_item_name_from_id(item_id, item_name);

    recomp_printf("Item at location %d: 0x%08X (%s)\n", ap_location_id, item_id, item_name);

    // Create formatted message: "Player's Item_name"
    char surprise_message[64];
    sprintf(surprise_message, "%s's %s", player, item_name);

    // Split message into lines of max 32 characters
    char formatted_message[128];
    int src_idx = 0;
    int dst_idx = 0;
    int line_length = 0;

    // Add "Got " prefix if no prefix is provided
    if (prefix == NULL || prefix[0] == '\0') {
        formatted_message[dst_idx++] = 'G';
        formatted_message[dst_idx++] = 'o';
        formatted_message[dst_idx++] = 't';
        formatted_message[dst_idx++] = ' ';
        line_length = 4;
    }

    while (surprise_message[src_idx] != '\0' && dst_idx < 120) {
        char c = surprise_message[src_idx];

        // If adding this character would exceed 32 chars, add newline first
        if (line_length >= 32 && c != ' ') {
            // Look back for a space to break at
            int break_pos = dst_idx - 1;
            while (break_pos > 0 && formatted_message[break_pos] != ' ') {
                break_pos--;
            }

            if (formatted_message[break_pos] == ' ') {
                // Replace the space with newline
                formatted_message[break_pos] = '\n';
                line_length = dst_idx - break_pos - 1;
            } else {
                // No space found, force break
                formatted_message[dst_idx++] = '\n';
                line_length = 0;
            }
        }

        // Add the character
        formatted_message[dst_idx++] = c;
        if (c == '\n') {
            line_length = 0;
        } else {
            line_length++;
        }

        src_idx++;
    }

    formatted_message[dst_idx] = '\0';

    // If no suffix provided, ensure we end with a newline for proper formatting
    if (suffix == NULL && dst_idx > 0 && formatted_message[dst_idx - 1] != '\n') {
        formatted_message[dst_idx++] = '\n';
        formatted_message[dst_idx] = '\0';
    }

    // Use existing function to create the text
    s16 *new_text = create_persistent_text_with_newlines(formatted_message);
    if (new_text != NULL) {
        // Replace the content of the text buffer
        int i = 0;
        while (i < 255 && (u16)new_text[i] != 0xFFFF) // Cast to unsigned to handle CTR_ENDLINE properly
        {
            text_buffer[i] = new_text[i];
            i++;
        }
        // Add the endline terminator
        if (i < 255) {
            text_buffer[i] = (s16)0xFFFF; // CTR_ENDLINE
        }

        recomp_printf("Successfully updated text buffer with dynamic AP text\n");
    }
}

// Generic scenario replacement function - handles its own scenario replacement
// - scenario_id: The ID of the scenario to replace
// - scenario_code: Pointer to the original scenario code array
// - scenario_file_id: The file ID for the scenario
void replace_scenario_with_flag(s32 scenario_id, s32 *scenario_code, s16 scenario_file_id) {
    // Replace the scenario code
    D_800779A0_785A0[scenario_id] = scenario_code;
    D_80078608_79208[scenario_id] = scenario_file_id;
}

extern s32 scenario_code_message_162_cd8c[];

// External data declarations
extern u16 D_800C7AB2;
static u16 prev_D_800C7AB2 = 0;
static bool first_call = true;

RECOMP_HOOK("func_80002040_2C40")
void consolidated_scenario_hook() {
    u16 current_value = D_800C7AB2;

    if (first_call) {
        prev_D_800C7AB2 = current_value;
        first_call = false;
        recomp_printf("D_800C7AB2 initial value: 0x%04X\n", current_value);
    } else if (current_value != prev_D_800C7AB2) {
        recomp_printf("D_800C7AB2 changed from 0x%04X to 0x%04X\n", prev_D_800C7AB2, current_value);
        prev_D_800C7AB2 = current_value;
        recomp_printf("Consolidated scenario replacement hook called\n");
        if (!rando_is_connected()) {
            recomp_printf("Rando not connected, skipping scenario replacements\n");
            return;
        }
        // Replace all scenario dialogs
        replace_scenario_with_flag(0x0ca, scenario_code_message_0ca_4b70, 0); // Oedo Castle Superpass
        replace_scenario_with_flag(0x1ea, scenario_code_message_1ea_63fc, 0); // Mokubei Upgrades
        replace_scenario_with_flag(0x160, scenario_code_message_160_c028, 0); // Ushiwaka

        replace_scenario_with_flag(0x083, scenario_code_message_083_3834, 0); // Wind-Up Camera Reward
        replace_scenario_with_flag(0x1ef, scenario_code_message_1ef_72b4, 0); // Koryuta Flute
        replace_scenario_with_flag(0x082, scenario_code_message_082_36e0, 0); // Medal of Flames
        replace_scenario_with_flag(0x176, scenario_code_message_176_2ad4, 0); // Mermaid Complete
        replace_scenario_with_flag(0x1f1, scenario_code_message_1f1_797c, 0); // Recruit Sasuke
        replace_scenario_with_flag(0x14c, scenario_code_message_14c_9904, 0); // Recruit Yae
        replace_scenario_with_flag(0x172, scenario_code_2410, 0); // Sudden Impact Complete
        replace_scenario_with_flag(0x178, scenario_code_3260, 0); // Super Jump Complete
        replace_scenario_with_flag(0x157, scenario_code_message_157_a930, 0); // Zazen Priest
        replace_scenario_with_flag(0x15e, scenario_code_message_15e_b798, 0); // Zazen Priest Son

        replace_scenario_with_flag(0x162, scenario_code_message_162_cd8c, 0); // Kihachi Quest Complete
        replace_scenario_with_flag(0x288, scenario_code_message_288_2f98, 0); // Plasma
        replace_scenario_with_flag(0x1cd, scenario_code_message_1cd_185c, 0); // Wise Man House Explosion
        replace_scenario_with_flag(0x226, scenario_code_31f0, 0); // Wise Man Sogen
        replace_scenario_with_flag(0x110, scenario_code_message_110_8420, 0); // Bridge Guard 1 (Super Pass Check)

        replace_scenario_with_flag(0x1f4, scenario_code_impact_departure, 0); // Impact Defeated Thaisamba
        replace_scenario_with_flag(0x0fa, scenario_code_poron_encounter, 0);  // Poron Miracle Item
        replace_scenario_with_flag(0x30e, scenario_code_message_30e_251c, 0); // Beat Benkei
        replace_scenario_with_flag(0x30c, scenario_code_message_30c_1cd8, 0); // Benkei Collector
    }
}

// Hardcoded function to check super pass and set flag 0x501
void check_super_pass_and_set_flag(void) {
    s32 save_value = READ_SAVE_DATA(SAVE_SUPER_PASS);
    if (save_value != 0) {
        ENABLE_FLAG(0x501); // Set flag 0x501 if super pass is obtained
    } else {
        DISABLE_FLAG(0x501); // Clear flag 0x501 if super pass is not obtained
    }
}

// Hardcoded function to check Achilles' Heel and set flag 0x501
void check_achilles_heel_and_set_flag(void) {
    s32 save_value = READ_SAVE_DATA(SAVE_ACHILLES_HEEL);
    if (save_value != 0) {
        ENABLE_FLAG(0x501); // Set flag 0x501 if Achilles' Heel is obtained
    } else {
        DISABLE_FLAG(0x501); // Clear flag 0x501 if Achilles' Heel is not obtained
    }
}

// Hardcoded function to check Cucumber and set flag 0x501
void check_cucumber_and_set_flag(void) {
    s32 save_value = READ_SAVE_DATA(SAVE_QUALITY_CUCUMBER);
    // Also check if 0x37 is set
    s32 flag_22_set = IS_FLAG_SET(0x37);
    recomp_printf("check_cucumber_and_set_flag: save_value=%d, flag_22_set=%d\n", save_value, flag_22_set);
    if (save_value != 0 && flag_22_set != 0) {
        ENABLE_FLAG(0x501); // Set flag 0x501 if Cucumber is obtained
    } else {
        DISABLE_FLAG(0x501); // Clear flag 0x501 if Cucumber is not obtained
    }
}

// Storage for dynamically generated hint text
static s16 dynamic_hint_buffer[256];

// Counters to track which hint we're on (persists between calls)
static int current_major_hint_index = 0;
static int current_location_hint_index = 0;

// Function to convert string to game text format with newline support
s16 *create_persistent_text_with_newlines(const char *message) {
    int idx = 0;

    // Parse the message character by character
    for (int i = 0; message[i] != '\0' && idx < 250; i++) {
        // Handle \n as newline
        if (message[i] == '\\' && message[i + 1] == 'n') {
            dynamic_hint_buffer[idx++] = CTR_NEWLINE;
            i++; // Skip the 'n'
            continue;
        }

        if (message[i] >= 'A' && message[i] <= 'Z') {
            dynamic_hint_buffer[idx++] = CHR_A + (message[i] - 'A');
        } else if (message[i] >= 'a' && message[i] <= 'z') {
            dynamic_hint_buffer[idx++] = CHR_a + (message[i] - 'a');
        } else if (message[i] >= '0' && message[i] <= '9') {
            dynamic_hint_buffer[idx++] = NUM_0 + (message[i] - '0');
        } else if (message[i] == ' ') {
            dynamic_hint_buffer[idx++] = PCT_SPACE;
        } else if (message[i] == '!') {
            dynamic_hint_buffer[idx++] = PCT_EXCLAMATION;
        } else if (message[i] == '\'') {
            dynamic_hint_buffer[idx++] = PCT_APOSTROPHE;
        } else if (message[i] == '-') {
            dynamic_hint_buffer[idx++] = PCT_DASH;
        } else if (message[i] == ',') {
            dynamic_hint_buffer[idx++] = PCT_COMMA;
        } else if (message[i] == '.') {
            dynamic_hint_buffer[idx++] = PCT_PERIOD;
        } else if (message[i] == ':') {
            dynamic_hint_buffer[idx++] = PCT_COLON;
        } else if (message[i] == '\n') {
            dynamic_hint_buffer[idx++] = CTR_NEWLINE;
        } else {
            // For any unsupported character, use space instead of skipping
            dynamic_hint_buffer[idx++] = PCT_SPACE;
        }
    }

    dynamic_hint_buffer[idx++] = CTR_ENDLINE;

    return dynamic_hint_buffer;
}

// Function to get the next location hint from slot data (cycling through them)
s16 *get_next_location_hint() {
    if (!rando_is_connected()) {
        // Fallback text when not connected
        return create_persistent_text_with_newlines("No connection to Archipelago.");
    }

    // Get the location_hints array from slot data
    u32 location_hints_handle[2];
    rando_get_slotdata_raw_o32("location_hints", location_hints_handle);

    // Count the number of hints available by trying to access elements
    int hint_count = 0;
    u32 temp_hint[2];

    // Try to access up to 100 hints to find the actual count
    for (int i = 0; i < 100; i++) {
        rando_access_slotdata_raw_array_o32(location_hints_handle, i, temp_hint);

        // Try to read the string to see if it's valid
        char test_str[16];
        rando_access_slotdata_raw_string_o32(temp_hint, test_str);

        // If we get an empty string or null, we've reached the end
        if (test_str[0] == '\0' || test_str[0] == 0) {
            break;
        }
        hint_count++;
    }

    if (hint_count == 0) {
        return create_persistent_text_with_newlines("No location hints available.");
    }

    // Use the current location hint index and wrap around using modulo
    int selected_index = current_location_hint_index % hint_count;

    // Get the selected hint
    u32 selected_hint[2];
    rando_access_slotdata_raw_array_o32(location_hints_handle, selected_index, selected_hint);

    // Extract the hint string
    char hint_text[256];
    rando_access_slotdata_raw_string_o32(selected_hint, hint_text);

    // Increment the counter for next time (this persists between calls)
    current_location_hint_index++;

    return create_persistent_text_with_newlines(hint_text);
}

// Function to get the next major hint from slot data (cycling through them)
s16 *get_next_major_hint() {
    if (!rando_is_connected()) {
        // Fallback text when not connected
        return create_persistent_text_with_newlines("No connection to Archipelago.");
    }

    // Get the major_hints array from slot data
    u32 major_hints_handle[2];
    rando_get_slotdata_raw_o32("major_hints", major_hints_handle);

    // Count the number of hints available by trying to access elements
    int hint_count = 0;
    u32 temp_hint[2];

    // Try to access up to 100 hints to find the actual count
    for (int i = 0; i < 100; i++) {
        rando_access_slotdata_raw_array_o32(major_hints_handle, i, temp_hint);

        // Try to read the string to see if it's valid
        char test_str[16];
        rando_access_slotdata_raw_string_o32(temp_hint, test_str);

        // If we get an empty string or null, we've reached the end
        if (test_str[0] == '\0' || test_str[0] == 0) {
            break;
        }
        hint_count++;
    }

    if (hint_count == 0) {
        return create_persistent_text_with_newlines("No major hints available.");
    }

    // Use the current major hint index and wrap around using modulo
    int selected_index = current_major_hint_index % hint_count;

    // Get the selected hint
    u32 selected_hint[2];
    rando_access_slotdata_raw_array_o32(major_hints_handle, selected_index, selected_hint);

    // Extract the hint string
    char hint_text[256];
    rando_access_slotdata_raw_string_o32(selected_hint, hint_text);

    // Increment the counter for next time (this persists between calls)
    current_major_hint_index++;

    return create_persistent_text_with_newlines(hint_text);
}
