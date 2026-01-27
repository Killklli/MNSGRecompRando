#ifndef SCENARIO_REPLACER_H
#define SCENARIO_REPLACER_H

#include "types.h"

// Generic scenario replacement function
// - scenario_id: The ID of the scenario to replace
// - scenario_code: Pointer to the original scenario code array
// - scenario_file_id: The file ID for the scenario
// - item_name: Name of the item to display (can be NULL to skip text replacement)
// - flag_id: Pointer to flag ID to set (NULL to skip flag setting)
// - sfg_index: Pointer to which SFG command to replace (NULL to use default index 0)
void replace_scenario_with_flag(s32 scenario_id, s32 *scenario_code, s16 scenario_file_id, const char *item_name, s32 *flag_id, s32 *sfg_index);

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
