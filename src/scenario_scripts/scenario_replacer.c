#include "scenario_replacer.h"
#include "scenario.h"
#include "common.h"
#include "modding.h"
#include "recomputils.h"
#include "text_utils.h"

// External reference to space_newline_text from surprise_pack.c
static s16 space_newline_text[] = {
    PCT_SPACE,
    PCT_SPACE,
    CTR_NEWLINE,
    CTR_ENDLINE,
};

// External scenario references
extern s32 scenario_code_message_0ca_4b70[];
extern s32 scenario_code_message_1ea_63fc[];
extern s32 scenario_code_impact_departure[];
extern s32 scenario_code_poron_encounter[];

// Generic scenario replacement function - handles its own scenario replacement
void replace_scenario_with_flag(s32 scenario_id, s32 *scenario_code, s16 scenario_file_id, const char *item_name, s32 *flag_id, s32 *sfg_index)
{
    // Use the original scenario as base, but modify the text reference dynamically
    static s32 dynamic_scenario[128]; // Increased size to accommodate SFG command
    
    // Default sfg_index to 0 if not found
    s32 actual_sfg_index = 0;
    if (sfg_index != NULL && *sfg_index >= 0) {
        actual_sfg_index = *sfg_index;
    }
    
    s32 actual_flag_id = 0;
    if (flag_id != NULL) {
        actual_flag_id = *flag_id;
    }
    
    recomp_printf("Replacing scenario (ID: %d) with item: %s, flag ID: %d, SFG index: %d\n", scenario_id, item_name, actual_flag_id, actual_sfg_index);

    // Create the dynamic text
    s16 *received_text = NULL;
    if (item_name != NULL && item_name[0] != '\0') {
        received_text = create_received_text(item_name);
    }

    // First pass: count existing SFG commands and find their positions
    s32 sfg_count = 0;
    s32 sfg_positions[16]; // Support up to 16 SFG commands
    for (int i = 0; scenario_code[i] != END; i++)
    {
        if (scenario_code[i] == SFG && sfg_count < 16)
        {
            sfg_positions[sfg_count] = i;
            sfg_count++;
        }
    }

    // Copy the original scenario and replace text references
    int j = 0;
    
    // If no SFG commands exist and we want to add one, add it at the start
    if (actual_flag_id > 0 && sfg_count == 0)
    {
        dynamic_scenario[j++] = SFG;
        dynamic_scenario[j++] = actual_flag_id;
    }
    
    s32 current_sfg_index = 0;
    for (int i = 0; scenario_code[i] != END; i++, j++)
    {
        // Check if this is an SFG command we need to replace
        if (scenario_code[i] == SFG && actual_flag_id > 0 && current_sfg_index == actual_sfg_index)
        {
            // Replace this SFG command with our flag_id
            dynamic_scenario[j] = SFG;
            j++;
            dynamic_scenario[j] = actual_flag_id;
            i++; // Skip the original flag value
            current_sfg_index++;
            continue;
        }
        else if (scenario_code[i] == SFG)
        {
            // This is an SFG command but not the one we're replacing, copy as-is
            dynamic_scenario[j] = scenario_code[i];
            j++;
            dynamic_scenario[j] = scenario_code[i + 1]; // Copy the flag value
            i++; // Skip the flag value in source
            current_sfg_index++;
            continue;
        }

        dynamic_scenario[j] = scenario_code[i];

        // Find TXT commands that might be the received text (look for pattern after space_newline_text)
        if (received_text != NULL && scenario_code[i] == TXT && i > 0 &&
            scenario_code[i - 2] == TXT && scenario_code[i - 1] == (s32)space_newline_text)
        {
            // This should be the received text, replace it
            j++;
            dynamic_scenario[j] = (s32)received_text;
            i++; // Skip the next element since we just processed it
        }
    }

    // Add the END command
    dynamic_scenario[j] = END;

    // Replace the scenario
    D_800779A0_785A0[scenario_id] = dynamic_scenario;
    D_80078608_79208[scenario_id] = scenario_file_id;
}

// Consolidated hook to automatically replace all scenarios
RECOMP_HOOK("func_80000450_1050")
void consolidated_scenario_hook()
{
    // Replace all scenario dialogs
    replace_scenario_with_flag(0x0ca, scenario_code_message_0ca_4b70, 0, NULL, NULL, NULL);      // Oedo Castle Superpass
    replace_scenario_with_flag(0x1ea, scenario_code_message_1ea_63fc, 0, NULL, NULL, NULL);      // Mokubei Upgrades
    replace_scenario_with_flag(0x1f4, scenario_code_impact_departure, 0, NULL, NULL, NULL);     // Impact Defeated Thaisamba
    replace_scenario_with_flag(0x0fa, scenario_code_poron_encounter, 0, NULL, NULL, NULL);      // Poron Miracle Item
}