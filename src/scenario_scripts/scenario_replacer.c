#include "types.h"
#include "scenario_replacer.h"

#include "Archipelago.h"
#include "file_state.h"
#include "libc/stdio.h"
#include "libc/string.h"
#include "modding.h"
#include "recomputils.h"
#include "save_data_tool.h"
#include "scenario.h"

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

// Storage for persistent scenario buffers and text
static struct
{
  s32 scenario_buffer[128];
  s16 text_buffer[256];
  bool initialized;
} scenario_storage[32]; // Support up to 32 scenarios with dynamic text

// Get a storage slot for a scenario ID (simple hash)
static int get_storage_slot(s32 scenario_id)
{
  return (scenario_id & 0xFF) % 32; // Simple modulo hash
}

// Create persistent text that won't be overwritten
static s16 *create_persistent_text(const char *message, int slot)
{
  if (slot < 0 || slot >= 32)
    return NULL;

  s16 *buffer = scenario_storage[slot].text_buffer;
  int idx = 0;

  // Build " Got [message]!" manually
  buffer[idx++] = PCT_SPACE;
  buffer[idx++] = CHR_G;
  buffer[idx++] = CHR_o;
  buffer[idx++] = CHR_t;
  buffer[idx++] = PCT_SPACE;

  // Add the message
  for (int i = 0; message[i] != '\0' && idx < 250; i++)
  {
    if (message[i] >= 'A' && message[i] <= 'Z')
    {
      buffer[idx++] = CHR_A + (message[i] - 'A');
    }
    else if (message[i] >= 'a' && message[i] <= 'z')
    {
      buffer[idx++] = CHR_a + (message[i] - 'a');
    }
    else if (message[i] >= '0' && message[i] <= '9')
    {
      buffer[idx++] = NUM_0 + (message[i] - '0');
    }
    else if (message[i] == ' ')
    {
      buffer[idx++] = PCT_SPACE;
    }
    else if (message[i] == '!')
    {
      buffer[idx++] = PCT_EXCLAMATION;
    }
    else if (message[i] == '\'')
    {
      buffer[idx++] = PCT_APOSTROPHE;
    }
    else if (message[i] == '-')
    {
      buffer[idx++] = PCT_DASH;
    }
    else
    {
      buffer[idx++] = PCT_SPACE; // Default to space
    }
  }

  buffer[idx++] = PCT_EXCLAMATION;
  buffer[idx++] = CTR_NEWLINE;
  buffer[idx++] = CTR_ENDLINE;

  return buffer;
}

// Generic scenario replacement function - handles its own scenario replacement
// - scenario_id: The ID of the scenario to replace
// - scenario_code: Pointer to the original scenario code array
// - scenario_file_id: The file ID for the scenario
// - original_text_ref: Pointer to the original text array to replace (NULL to skip text replacement)
// - ap_location_id: Archipelago location ID to get item name from (0 to skip text replacement)
void replace_scenario_with_flag(s32 scenario_id, s32 *scenario_code,
                                s16 scenario_file_id,
                                s32 *original_text_ref, s32 ap_location_id)
{
  // If we have text replacement parameters, do dynamic replacement
  if (original_text_ref != NULL && ap_location_id != 0)
  {
    int storage_slot = get_storage_slot(scenario_id);
    s32 *dynamic_scenario = scenario_storage[storage_slot].scenario_buffer;

    recomp_printf("Replacing scenario (ID: 0x%x) with AP location ID: %d (slot %d)\n", scenario_id, ap_location_id, storage_slot);

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

    // Create persistent text for this scenario
    s16 *replacement_text = create_persistent_text(surprise_message, storage_slot);
    if (replacement_text == NULL)
    {
      recomp_printf("Error: Failed to create persistent text for scenario 0x%x\n", scenario_id);
      // Fall back to original scenario
      D_800779A0_785A0[scenario_id] = scenario_code;
      D_80078608_79208[scenario_id] = scenario_file_id;
      return;
    }

    // Find scenario length first
    int scenario_length = 0;
    while (scenario_code[scenario_length] != END && scenario_length < 120)
    {
      scenario_length++;
    }
    scenario_length++; // Include the END marker

    // Copy the entire scenario at once
    memcpy(dynamic_scenario, scenario_code, scenario_length * sizeof(s32));

    // Now find and replace the specific text reference
    bool found_replacement = false;
    for (int i = 0; i < scenario_length - 1; i++)
    {
      if (dynamic_scenario[i] == TXT && dynamic_scenario[i + 1] == (s32)original_text_ref)
      {
        dynamic_scenario[i + 1] = (s32)replacement_text;
        recomp_printf("Replaced text reference at position %d: 0x%08X -> 0x%08X\n",
                      i, (s32)original_text_ref, (s32)replacement_text);
        found_replacement = true;
        break; // Assuming only one replacement needed
      }
    }

    if (!found_replacement)
    {
      recomp_printf("Warning: Could not find text reference 0x%08X in scenario 0x%x\n",
                    (s32)original_text_ref, scenario_id);
    }

    // Mark as initialized and replace the scenario
    scenario_storage[storage_slot].initialized = true;
    D_800779A0_785A0[scenario_id] = dynamic_scenario;
    D_80078608_79208[scenario_id] = scenario_file_id;
  }
  else
  {
    // No text replacement, just replace the scenario normally
    D_800779A0_785A0[scenario_id] = scenario_code;
    D_80078608_79208[scenario_id] = scenario_file_id;
  }
}

extern s32 scenario_code_message_162_cd8c[];
// External text references that need dynamic replacement
extern s16 scenario_text_005F[]; // Oedo Castle Superpass reward text

// External data declarations
extern u16 D_800C7AB2;
static u16 prev_D_800C7AB2 = 0;
static bool first_call = true;

RECOMP_HOOK("func_80002040_2C40")
void consolidated_scenario_hook()
{  
  u16 current_value = D_800C7AB2;

  if (first_call)
  {
    prev_D_800C7AB2 = current_value;
    first_call = false;
    recomp_printf("D_800C7AB2 initial value: 0x%04X\n", current_value);
  }
  else if (current_value != prev_D_800C7AB2)
  {
    recomp_printf("D_800C7AB2 changed from 0x%04X to 0x%04X\n", prev_D_800C7AB2,
                  current_value);
    prev_D_800C7AB2 = current_value;
    recomp_printf("Consolidated scenario replacement hook called\n");
    if (!rando_is_connected())
    {
      recomp_printf("Rando not connected, skipping scenario replacements\n");
      return;
    }
    // Replace all scenario dialogs
    // Example: Dynamic text replacement for Oedo Castle Superpass
    // replace_scenario_with_flag(0x0ca, scenario_code_message_0ca_4b70, 0,
    //                            (s32 *)&scenario_text_005F, AP_LOCATION_OEDO_SUPERPASS); // Oedo Castle Superpass with dynamic text

    // For scenarios without dynamic text replacement, use 0 for AP location ID
    replace_scenario_with_flag(0x0ca, scenario_code_message_0ca_4b70, 0,
                              (s32 *)scenario_text_005F, 6474106); // Oedo Castle Superpass
    // TODO: Mokubei has two items, we need to account for that
    replace_scenario_with_flag(0x1ea, scenario_code_message_1ea_63fc, 0,
                              NULL, 0); // Mokubei Upgrades
    // TODO: This has two items
    replace_scenario_with_flag(0x160, scenario_code_message_160_c028, 0,
                              NULL, 0); // Ushiwaka

    replace_scenario_with_flag(0x083, scenario_code_message_083_3834, 0,
                              NULL, 0); // Wind-Up Camera Reward
    replace_scenario_with_flag(0x1ef, scenario_code_message_1ef_72b4, 0,
                              NULL, 0); // Koryuta Flute
    replace_scenario_with_flag(0x082, scenario_code_message_082_36e0, 0,
                              NULL, 0); // Medal of Flames
    replace_scenario_with_flag(0x176, scenario_code_message_176_2ad4, 0,
                              NULL, 0); // Mermaid Complete
    replace_scenario_with_flag(0x1f1, scenario_code_message_1f1_797c, 0,
                              NULL, 0); // Recruit Sasuke
    replace_scenario_with_flag(0x14c, scenario_code_message_14c_9904, 0,
                              NULL, 0); // Recruit Yae
    replace_scenario_with_flag(0x174, scenario_code_message_174_28bc, 0,
                              NULL, 0); // Sudden Impact Complete
    replace_scenario_with_flag(0x17a, scenario_code_message_17a_3650, 0,
                              NULL, 0); // Super Jump Complete
    replace_scenario_with_flag(0x157, scenario_code_message_157_a930, 0,
                              NULL, 0); // Zazen Priest
    replace_scenario_with_flag(0x15e, scenario_code_message_15e_b798, 0,
                              NULL, 0); // Zazen Priest Son

    replace_scenario_with_flag(0x162, scenario_code_message_162_cd8c, 0,
                              NULL, 0); // Kihachi Quest Complete
    replace_scenario_with_flag(0x288, scenario_code_message_288_2f98, 0,
                              NULL, 0); // Plasma
    replace_scenario_with_flag(0x1cd, scenario_code_message_1cd_185c, 0,
                              NULL, 0); // Wise Man House Explosion
    replace_scenario_with_flag(0x227, scenario_code_message_227_3a14, 0,
                              NULL, 0); // Wise Man Sogen
    replace_scenario_with_flag(0x110, scenario_code_message_110_8420, 0,
                              NULL, 0); // Bridge Guard 1 (Super Pass Check)

    replace_scenario_with_flag(0x1f4, scenario_code_impact_departure, 0,
                              NULL, 0); // Impact Defeated Thaisamba
    replace_scenario_with_flag(0x0fa, scenario_code_poron_encounter, 0,
                              NULL, 0); // Poron Miracle Item
    replace_scenario_with_flag(0x30e, scenario_code_message_30e_251c, 0,
                              NULL, 0); // Beat Benkei
    replace_scenario_with_flag(0x30c, scenario_code_message_30c_1cd8, 0,
                              NULL, 0); // Benkei Collector
    }
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
