#include "Archipelago.h"
#include "apconnect_ui.h"
#include "entities.h"
#include "file_state.h"
#include "libc/stdio.h"
#include "modding.h"
#include "recompconfig.h"
#include "recomputils.h"
#include "save_data_tool.h"
#include "types.h"

extern void increase_silver_fortune_doll();
extern void increase_gold_fortune_doll();
extern void progressive_weapon_handler();
extern void calculate_key_on_pause();
extern void invalidate_key_cache_entry(u32 item_id);
extern void func_80038B98_39798(u32 sound_id);
extern void sasuke_batteries();
extern void normal_health();
extern void fill_health();
extern void increase_lives();

// text_labels_add_ascii_entry
void func_800042AC_4EAC(s16 entry, const char *string, s16 x, s16 y);

u32 initItems = 0;
u32 old_items_size;

// Variables for item display timer (assuming 60 FPS)
u32 item_display_timer = 0;
const u32 ITEM_DISPLAY_DURATION = 180; // 3 seconds at 60 FPS
bool displaying_item = false;
// Common function to handle item processing based on item ID
void handle_item_by_id(u32 item_id)
{
  switch (item_id)
  {
  case 6464022: // Silver Fortune Doll
    increase_silver_fortune_doll();
    break;
  case 6464023: // Gold Fortune Doll
    increase_gold_fortune_doll();
    break;
  case 6464032: // Strength Upgrade 1
    progressive_weapon_handler();
    break;
  case 6464033: // Strength Upgrade 2
    progressive_weapon_handler();
    break;
  case 6464004:
    // Wind Up Camera
    WRITE_SAVE_DATA(SAVE_WINDUP_CAMERA, 1);
    break;
  case 6464005:
    // Chain Pipe
    WRITE_SAVE_DATA(SAVE_CHAIN_PIPE, 1);
    break;
  case 6464006:
    // Ice Kunai
    WRITE_SAVE_DATA(SAVE_ICE_KUNAI, 1);
    break;
  case 6464007:
    // Medal of Flames
    WRITE_SAVE_DATA(SAVE_FIRE_RYO, 1);
    break;
  case 6464008:
    // Bazooka
    WRITE_SAVE_DATA(SAVE_BAZOOKA, 1);
    break;
  case 6464009:
    // Meat Hammer
    WRITE_SAVE_DATA(SAVE_MEATSAW_HAMMER, 1);
    break;
  case 6464010:
    // Flute
    WRITE_SAVE_DATA(SAVE_FLUTE, 1);
    break;
  case 6464011:
    // Mermaid
    WRITE_SAVE_DATA(SAVE_MERMAID_MAGIC, 1);
    break;
  case 6464012:
    // Mini Ebisu
    WRITE_SAVE_DATA(SAVE_MINI_EBISU_MAGIC, 1);
    break;
  case 6464013:
    // Sudden Impact
    WRITE_SAVE_DATA(SAVE_SUDDEN_IMPACT_MAGIC, 1);
    break;
  case 6464014:
    // Jetpack
    WRITE_SAVE_DATA(SAVE_SUPER_JUMP_MAGIC, 1);
    break;
  case 6464015:
    // Goemon
    WRITE_SAVE_DATA(SAVE_GOEMON_RECRUITED, 1);
    break;
  case 6464016:
    // Yae
    WRITE_SAVE_DATA(SAVE_YAE_RECRUITED, 1);
    break;
  case 6464017:
    // Ebisumaru
    WRITE_SAVE_DATA(SAVE_EBISUMARU_RECRUITED, 1);
    break;
  case 6464018:
    // Sasuke
    WRITE_SAVE_DATA(SAVE_SASUKE_RECRUITED, 1);
    WRITE_SAVE_DATA(SAVE_FIRECRACKER_BOMB, 1);
    break;
  case 6464026:
    // Super Pass
    WRITE_SAVE_DATA(SAVE_SUPER_PASS, 1);
    break;
  case 6464027:
    // Triton Horn
    WRITE_SAVE_DATA(SAVE_TRITON_SHELL, 1);
    break;
  case 6464028:
    // Cucumber
    WRITE_SAVE_DATA(SAVE_QUALITY_CUCUMBER, 1);
    break;
  case 6464034:
    // Surprise Pack
    increase_lives();
    break;
  case 6464037:
    // Achilles Heel
    WRITE_SAVE_DATA(SAVE_ACHILLES_HEEL, 1);
    break;
  case 6464048:
    // Miracle Star
    WRITE_SAVE_DATA(SAVE_MIRACLE_STAR, 1);
    break;
  case 6464049:
    // Miracle Snow
    WRITE_SAVE_DATA(SAVE_MIRACLE_SNOW, 1);
    break;
  case 6464050:
    // Miracle Moon
    WRITE_SAVE_DATA(SAVE_MIRACLE_MOON, 1);
    break;
  case 6464051:
    // Miracle Flower
    WRITE_SAVE_DATA(SAVE_MIRACLE_FLOWER, 1);
    break;
  case 6464024:
    // Fill Health
    fill_health();
    break;
  case 6464025:
    // Normal Health
    normal_health();
    break;
  case 6464020:
    // sasuke Battery 1
    sasuke_batteries();
    break;
  case 6464021:
    // sasuke Battery 2
    sasuke_batteries();
    break;
  // Disabled this because we're using this value to display if we have a key on
  // the pause screen
  case 6464003:
    // Jump Gym Key
    // WRITE_SAVE_DATA(SAVE_KEY_TO_TRAINING, 1);
    invalidate_key_cache_entry(6464003);
    calculate_key_on_pause();
    break;
  case 6464035:
    // Mr Elly Fant Oedo Castle
    WRITE_SAVE_DATA(SAVE_MR_ELLY_OEDO_CASTLE, 1);
    break;
  case 6464038:
    // Mr Elly Fant Ghost Toys Castle
    WRITE_SAVE_DATA(SAVE_MR_ELLY_GHOST_TOYS, 1);
    break;
  case 6464039:
    // Mr Elly Fant Festival Temple
    WRITE_SAVE_DATA(SAVE_MR_ELLY_FESTIVAL_TEMPLE, 1);
    break;
  case 6464040:
    // Mr Elly Fant Gourmet Submarine
    WRITE_SAVE_DATA(SAVE_MR_ELLY_SUBMARINE, 1);
    break;
  case 6464045:
    // Mr Elly Fant Gorgeous Music Castle
    WRITE_SAVE_DATA(SAVE_MR_ELLY_MUSICAL, 1);
    break;
  case 6464036:
    // Mr Arrow Oedo Castle
    WRITE_SAVE_DATA(SAVE_MR_ARROW_OEDO_CASTLE, 1);
    break;
  case 6464041:
    // Mr Arrow Ghost Toys Castle
    WRITE_SAVE_DATA(SAVE_MR_ARROW_GHOST_TOYS, 1);
    break;
  case 6464042:
    // Mr Arrow Festival Temple
    WRITE_SAVE_DATA(SAVE_MR_ARROW_FESTIVAL_TEMPLE, 1);
    break;
  case 6464043:
    // Mr Arrow Gorgeous Music Castle
    WRITE_SAVE_DATA(SAVE_MR_ARROW_MUSICAL, 1);
    break;
  case 6464044:
    // Mr Arrow Gourmet Submarine
    WRITE_SAVE_DATA(SAVE_MR_ARROW_SUBMARINE, 1);
    break;
  case 6464000:
    // Silver key
    // We don't actually give the player an item, we just display it on the
    // pause screen
    invalidate_key_cache_entry(6464000);
    calculate_key_on_pause();
    break;
  case 6464001:
    // Gold Key
    // We don't actually give the player an item, we just display it on the
    // pause screen
    invalidate_key_cache_entry(6464001);
    calculate_key_on_pause();
    break;
  case 6464002:
    // Diamond Key
    // We don't actually give the player an item, we just display it on the
    // pause screen
    invalidate_key_cache_entry(6464002);
    calculate_key_on_pause();
    break;
  case 6464058:
  {
    // Ryo
    s32 current_ryo = READ_SAVE_DATA(SAVE_RYO);
    current_ryo += 5;
    WRITE_SAVE_DATA(SAVE_RYO, current_ryo);
    break;
  }
  case 6464059:
  {
    // Pot
    // For this we just give the player 30 ryo since pots don't have an "item" per say currently
    s32 pot_ryo = READ_SAVE_DATA(SAVE_RYO);
    pot_ryo += 50;
    WRITE_SAVE_DATA(SAVE_RYO, pot_ryo);
    break;
  }
  default:
    // Item doesn't need special handling
    break;
  }
}

RECOMP_HOOK("func_80024038_24C38")
void func_80024038_24C38_hook(s32 flag)
{
  DEBUG_PRINTF("func_80024038_24C38_hook called with flag value: 0x%08X\n",
                flag);

  // Only proceed with AP logic if we're in a file and connected
  if (should_run_ap_logic())
  {
    // Convert flag to string key
    char flag_str[16];
    sprintf(flag_str, "%ld", flag);

    // Get the flag_id_to_ap_location_id dictionary from slot data
    u32 flag_to_location_handle[2];
    rando_get_slotdata_raw_o32("flag_id_to_ap_location_id",
                               flag_to_location_handle);

    // Check if this flag exists in the dictionary
    bool flag_exists = rando_access_slotdata_raw_dict_has_member_o32(
        flag_to_location_handle, flag_str);

    if (flag_exists)
    {
      // Get the location_id value for this flag
      u32 location_id_handle[2];
      rando_access_slotdata_raw_dict_o32(flag_to_location_handle, flag_str,
                                         location_id_handle);

      // Extract the integer value
      u32 location_id = rando_access_slotdata_raw_u32_o32(location_id_handle);

      recomp_printf("Flag %d maps to location_id: %d\n", flag, location_id);

      // Send the location to Archipelago
      bool sent_successfully = rando_send_location(location_id);

      // Check if this location has a local item (is in our world)
      bool has_local_item = rando_get_location_has_local_item(location_id);

      if (has_local_item)
      {
        // List of flags that should grant items immediately when collected in
        // our world
        u32 immediate_item_flags[] = {
            FLAG_RECEIVED_CHAIN_PIPE,      // Mokubei Chain Pipe
            FLAG_OBTAINED_ACHILLES_HEEL,   // Achilles Heel from Ushiwaka fishing
            FLAG_RECEIVED_FIRE_RYO,        // Fire Ryo event
            FLAG_FREED_KORYUTA_DRAGON,     // Got flute cutscene
            FLAG_RECEIVED_SUPER_PASS,      // Oedo Lord gives Superpass
            FLAG_OBTAINED_MERMAID_MAGIC,   // Mermaid Training
            FLAG_OBTAINED_SUDDEN_IMPACT,   // Strength Gym
            FLAG_OBTAINED_KEY_TO_TRAINING, // Jump Gym
            FLAG_RECRUITED_YAE,            // Getting Yae Cutscene
            FLAG_RECRUITED_SASUKE,         // Getting Sasuke Cutscene
            FLAG_UPGRADED_SILVER_WEAPONS,  // Mokubei Weapon Upgrade
            FLAG_UPGRADED_GOLD_WEAPONS,    // Wise Man Weapon Upgrade
            FLAG_OBTAINED_MINI_EBISU,      // Mini Ebisumaru Training
            FLAG_DEFEATED_BENKEI,          // Benkei gives you sasuke dead
            FLAG_RECEIVED_CUCUMBER,        // Zazen Son Cucumber
            FLAG_OBTAINED_KEY_TO_TRAINING, // Zazen Priest Key
        };
        u32 num_flags =
            sizeof(immediate_item_flags) / sizeof(immediate_item_flags[0]);

        // Check if this flag is in our list of immediate item flags
        // for (u32 i = 0; i < num_flags; i++) {
        //     if ((u32)flag == immediate_item_flags[i]) {
        // Grant the item to the player that is at this location
        u32 item_id = rando_get_item_at_location(location_id);
        handle_item_by_id(item_id);
        // break;
        //     }
        // }
      }

      recomp_printf("Sent location %d to Archipelago: %s\n", location_id,
                    sent_successfully ? "SUCCESS" : "FAILED");
    }
    else
    {
      DEBUG_PRINTF("Flag %d not found in flag_id_to_ap_location_id mapping\n",
                    flag);
    }
  }
  else
  {
    DEBUG_PRINTF(
        "Not in a file, connected to Archipelago, or not scouted yet\n");
  }
}

void check_for_new_items()
{
  // Check if we should run AP logic (in file, connected, and scouted)
  if (!should_run_ap_logic())
  {
    return;
  }

  // If we're currently displaying an item, don't check for new items yet
  if (displaying_item)
  {
    return;
  }

  u32 new_items_size = rando_get_items_size();

  if (!initItems)
  {
    // Load items_received from datastore, default to 0 if not found
    old_items_size = rando_get_datastorage_u32_sync("items_received");
    if (old_items_size == 0) {
      old_items_size = new_items_size;
      // write it back to datastore
      rando_set_datastorage_u32_async("items_received", old_items_size);
    }
    initItems = 1;
  }

  if (new_items_size > old_items_size)
  {
    u32 item_id = rando_get_item(old_items_size);

    if (rando_get_sending_player(old_items_size) != rando_get_own_slot_id())
    {
      char item_name[33];
      char player_name[17];
      rando_get_item_name_from_id(item_id, item_name);
      rando_get_sending_player_name(old_items_size, player_name);
      // Play the sound effect for receiving an item, we're using the coin
      // collect sound
      func_80038B98_39798(0x23C);
      recomp_printf("Received item: %s from player: %s\n", item_name,
                    player_name);
      // print the item_id
      recomp_printf("Item ID: 0x%08X\n", item_id);

      // Create display messages for item and sender (two lines)
      static char item_line[64]; // Make it static so the pointer remains valid
      static char sender_line[64];
      sprintf(item_line, "Got %s", item_name);
      sprintf(sender_line, "from %s", player_name);
      // Display both lines using different indices
      func_800042AC_4EAC(15, item_line, 0, 16);   // First line
      func_800042AC_4EAC(14, sender_line, 0, 28); // Second line (try index 14)

      // Start the display timer
      displaying_item = true;
      item_display_timer = ITEM_DISPLAY_DURATION;

      // Handle the item using the common function
      handle_item_by_id(item_id);
    }

    old_items_size += 1;
    // Write the updated items_received count to datastore asynchronously
    rando_set_datastorage_u32_async("items_received", old_items_size);
  }
}

// Hooks the game's mode handler function to display a string on the screen.
RECOMP_HOOK_RETURN("func_80002040_2C40")
void main_handler()
{

  if (displaying_item && item_display_timer > 0)
  {
    item_display_timer--;
    if (item_display_timer == 0)
    {
      // Timer expired, clear the display and allow new item checks
      recomp_printf("Timer expired, clearing display\n");
      displaying_item = false;
      static char empty_string[] = "";             // Static empty string
      func_800042AC_4EAC(15, empty_string, 0, 16); // Clear first line
      func_800042AC_4EAC(14, empty_string, 0, 28); // Clear second line
    }
  }

  // Only check for new items if we're not currently displaying one
  if (!displaying_item)
  {
    check_for_new_items();
  }
}
