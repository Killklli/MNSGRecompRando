#include "types.h"
#include "scenario_replacer.h"

#include "modding.h"
#include "recomputils.h"
#include "save_data_tool.h"
#include "scenario.h"
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

// Generic scenario replacement function - handles its own scenario replacement
void replace_scenario_with_flag(s32 scenario_id, s32 *scenario_code,
                                s16 scenario_file_id, const char *item_name,
                                s32 *flag_id, s32 *sfg_index)
{

  // Replace the scenario
  D_800779A0_785A0[scenario_id] = scenario_code;
  D_80078608_79208[scenario_id] = scenario_file_id;
}
extern s32 scenario_code_message_162_cd8c[];
// Consolidated hook to automatically replace all scenarios
RECOMP_HOOK("func_80000450_1050")
void consolidated_scenario_hook()
{
  DEBUG_PRINTF("Consolidated scenario replacement hook called\n");
  // Replace all scenario dialogs
  replace_scenario_with_flag(0x0ca, scenario_code_message_0ca_4b70, 0, NULL,
                             NULL, NULL); // Oedo Castle Superpass
  replace_scenario_with_flag(0x1ea, scenario_code_message_1ea_63fc, 0, NULL,
                             NULL, NULL); // Mokubei Upgrades
  replace_scenario_with_flag(0x1f4, scenario_code_impact_departure, 0, NULL,
                             NULL, NULL); // Impact Defeated Thaisamba
  replace_scenario_with_flag(0x0fa, scenario_code_poron_encounter, 0, NULL,
                             NULL, NULL); // Poron Miracle Item
  replace_scenario_with_flag(0x30e, scenario_code_message_30e_251c, 0, NULL,
                             NULL, NULL); // Beat Benkei
  replace_scenario_with_flag(0x30c, scenario_code_message_30c_1cd8, 0, NULL,
                             NULL, NULL); // Benkei Collector
  replace_scenario_with_flag(0x162, scenario_code_message_162_cd8c, 0, NULL,
                             NULL, NULL); // Kihachi Quest Complete
  replace_scenario_with_flag(0x1ef, scenario_code_message_1ef_72b4, 0, NULL,
                             NULL, NULL); // Koryuta Flute
  replace_scenario_with_flag(0x082, scenario_code_message_082_36e0, 0, NULL,
                             NULL, NULL); // Medal of Justice
  replace_scenario_with_flag(0x176, scenario_code_message_176_2ad4, 0, NULL,
                             NULL, NULL); // Mermaid Complete
  replace_scenario_with_flag(0x288, scenario_code_message_288_2f98, 0, NULL,
                             NULL, NULL); // Plasma
  replace_scenario_with_flag(0x1f1, scenario_code_message_1f1_797c, 0, NULL,
                             NULL, NULL); // Recruit Sasuke
  replace_scenario_with_flag(0x14c, scenario_code_message_14c_9904, 0, NULL,
                             NULL, NULL); // Recruit Yae
  replace_scenario_with_flag(0x174, scenario_code_message_174_28bc, 0, NULL,
                             NULL, NULL); // Sudden Impact Complete
  replace_scenario_with_flag(0x17a, scenario_code_message_17a_3650, 0, NULL,
                             NULL, NULL); // Super Jump Complete
  replace_scenario_with_flag(0x160, scenario_code_message_160_c028, 0, NULL,
                             NULL, NULL); // Ushiwaka
  replace_scenario_with_flag(0x1cd, scenario_code_message_1cd_185c, 0, NULL,
                             NULL, NULL); // Wise Man House Explosion
  replace_scenario_with_flag(0x227, scenario_code_message_227_3a14, 0, NULL,
                             NULL, NULL); // Wise Man Sogen
  replace_scenario_with_flag(0x157, scenario_code_message_157_a930, 0, NULL,
                             NULL, NULL); // Zazen Priest
  replace_scenario_with_flag(0x15e, scenario_code_message_15e_b798, 0, NULL,
                             NULL, NULL); // Zazen Priest Son
  replace_scenario_with_flag(0x110, scenario_code_message_110_8420, 0, NULL,
                             NULL, NULL); // Bridge Guard 1 (Super Pass Check)
  replace_scenario_with_flag(0x083, scenario_code_message_083_3834, 0, NULL,
                             NULL, NULL); // Wind-Up Camera Reward
}

// Hardcoded function to check super pass and set flag 0x501
void check_super_pass_and_set_flag(void)
{
  s32 save_value = READ_SAVE_DATA(SAVE_SUPER_PASS);
  if (save_value != 0)
  {
    ENABLE_FLAG(0x501); // Set flag 0x501 if super pass is obtained
  }
  else
  {
    DISABLE_FLAG(0x501); // Clear flag 0x501 if super pass is not obtained
  }
}

// Hardcoded function to check Achilles' Heel and set flag 0x501
void check_achilles_heel_and_set_flag(void)
{
  s32 save_value = READ_SAVE_DATA(SAVE_ACHILLES_HEEL);
  if (save_value != 0)
  {
    ENABLE_FLAG(0x501); // Set flag 0x501 if Achilles' Heel is obtained
  }
  else
  {
    DISABLE_FLAG(0x501); // Clear flag 0x501 if Achilles' Heel is not obtained
  }
}

// Hardcoded function to check Cucumber and set flag 0x501
void check_cucumber_and_set_flag(void)
{
  s32 save_value = READ_SAVE_DATA(SAVE_QUALITY_CUCUMBER);
  // Also check if 0x37 is set
  s32 flag_22_set = IS_FLAG_SET(0x37);
  recomp_printf("check_cucumber_and_set_flag: save_value=%d, flag_22_set=%d\n",
                save_value, flag_22_set);
  if (save_value != 0 && flag_22_set != 0)
  {
    ENABLE_FLAG(0x501); // Set flag 0x501 if Cucumber is obtained
  }
  else
  {
    DISABLE_FLAG(0x501); // Clear flag 0x501 if Cucumber is not obtained
  }
}
