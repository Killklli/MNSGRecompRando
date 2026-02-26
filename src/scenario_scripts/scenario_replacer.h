#ifndef SCENARIO_REPLACER_H
#define SCENARIO_REPLACER_H

#include "types.h"

// Generic scenario replacement function
// - scenario_id: The ID of the scenario to replace
// - scenario_code: Pointer to the original scenario code array
// - scenario_file_id: The file ID for the scenario
// - original_text_ref: Pointer to the original text array to replace (NULL to skip text replacement)
// - ap_location_id: Archipelago location ID to get item name from (0 to skip text replacement)
void replace_scenario_with_flag(s32 scenario_id, s32 *scenario_code, s16 scenario_file_id);

// Generic function to update any text buffer with AP location data (buffer must be at least 256 elements)
void update_text_buffer_with_ap_location(s16 *text_buffer, s32 flag_id, const char *prefix, const char *suffix);

// Hint system functions
s16 *create_persistent_text_with_newlines(const char *message);
s16 *get_next_location_hint();
s16 *get_next_major_hint();

// Hardcoded function to check super pass and set flag 0x501
void check_super_pass_and_set_flag(void);

// Hardcoded function to check Achilles' Heel and set flag 0x501
void check_achilles_heel_and_set_flag(void);

// Hardcoded function to check Fire Ryo and set flag 0x501
void check_fire_ryo_and_set_flag(void);

// Hardcoded function to check Mermaid Magic and set flag 0x501
void check_mermaid_magic_and_set_flag(void);

// Hardcoded function to check Chain Pipe and set flag 0x501
void check_chain_pipe_and_set_flag(void);

// Hardcoded function to check Silver Weapons (Goemon weapon level >= 1) and set flag 0x501
void check_silver_weapons_and_set_flag(void);

// Hardcoded function to check Cucumber and set flag 0x501
void check_cucumber_and_set_flag(void);

#endif // SCENARIO_REPLACER_H
