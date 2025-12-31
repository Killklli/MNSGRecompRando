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
extern s32 scenario_code_message_30e_251c[];
extern s32 scenario_code_message_30c_1cd8[];
extern s32 scenario_code_message_163_d320[];
extern s32 scenario_code_message_162_d63c[];
extern s32 scenario_code_message_1ef_72b4[];
extern s32 scenario_code_message_1ed_6b44[];
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

// Generic scenario replacement function - handles its own scenario replacement
void replace_scenario_with_flag(s32 scenario_id, s32 *scenario_code, s16 scenario_file_id, const char *item_name, s32 *flag_id, s32 *sfg_index)
{

    // Replace the scenario
    D_800779A0_785A0[scenario_id] = scenario_code;
    D_80078608_79208[scenario_id] = scenario_file_id;
}

// Consolidated hook to automatically replace all scenarios
RECOMP_HOOK("func_80000450_1050")
void consolidated_scenario_hook()
{
    recomp_printf("Consolidated scenario replacement hook called\n");
    // Replace all scenario dialogs
    replace_scenario_with_flag(0x0ca, scenario_code_message_0ca_4b70, 0, NULL, NULL, NULL);      // Oedo Castle Superpass
    replace_scenario_with_flag(0x1ea, scenario_code_message_1ea_63fc, 0, NULL, NULL, NULL);      // Mokubei Upgrades
    replace_scenario_with_flag(0x1f4, scenario_code_impact_departure, 0, NULL, NULL, NULL);     // Impact Defeated Thaisamba
    replace_scenario_with_flag(0x0fa, scenario_code_poron_encounter, 0, NULL, NULL, NULL);      // Poron Miracle Item
    replace_scenario_with_flag(0x30e, scenario_code_message_30e_251c, 0, NULL, NULL, NULL);     // Beat Benkei
    replace_scenario_with_flag(0x30c, scenario_code_message_30c_1cd8, 0, NULL, NULL, NULL);     // Benkei Collector
    replace_scenario_with_flag(0x163, scenario_code_message_163_d320, 0, NULL, NULL, NULL);     // Kihachi Early Cucumber
    replace_scenario_with_flag(0x162, scenario_code_message_162_d63c, 0, NULL, NULL, NULL);     // Kihachi Quest Complete
    replace_scenario_with_flag(0x1ef, scenario_code_message_1ef_72b4, 0, NULL, NULL, NULL);     // Koryuta Flute
    replace_scenario_with_flag(0x1ed, scenario_code_message_1ed_6b44, 0, NULL, NULL, NULL);     // Medal of Justice
    replace_scenario_with_flag(0x176, scenario_code_message_176_2ad4, 0, NULL, NULL, NULL);     // Mermaid Complete
    replace_scenario_with_flag(0x288, scenario_code_message_288_2f98, 0, NULL, NULL, NULL);     // Plasma
    replace_scenario_with_flag(0x1f1, scenario_code_message_1f1_797c, 0, NULL, NULL, NULL);     // Recruit Sasuke
    replace_scenario_with_flag(0x14c, scenario_code_message_14c_9904, 0, NULL, NULL, NULL);     // Recruit Yae
    replace_scenario_with_flag(0x174, scenario_code_message_174_28bc, 0, NULL, NULL, NULL);     // Sudden Impact Complete
    replace_scenario_with_flag(0x17a, scenario_code_message_17a_3650, 0, NULL, NULL, NULL);     // Super Jump Complete
    replace_scenario_with_flag(0x160, scenario_code_message_160_c028, 0, NULL, NULL, NULL);     // Ushiwaka
    replace_scenario_with_flag(0x1cd, scenario_code_message_1cd_185c, 0, NULL, NULL, NULL);     // Wise Man House Explosion
    replace_scenario_with_flag(0x227, scenario_code_message_227_3a14, 0, NULL, NULL, NULL);     // Wise Man Sogen
    replace_scenario_with_flag(0x157, scenario_code_message_157_a930, 0, NULL, NULL, NULL);     // Zazen Priest
    replace_scenario_with_flag(0x15e, scenario_code_message_15e_b798, 0, NULL, NULL, NULL);     // Zazen Priest Son
}