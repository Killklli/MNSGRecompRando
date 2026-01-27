// Adjusts the surprise pack entity event to use our custom scenario script PER
// surprise pack collection. We can't just set a scenario script because it
// needs to be triggered only when the surprise pack is collected.
#include "Archipelago.h"

#include "file_state.h"
#include "game_entities.h"
#include "libc/stdio.h"
#include "modding.h"
#include "recomputils.h"
#include "types.h"

// External function declarations
extern void func_80221F70_5DD440(void);
extern void func_8003D310_3DF10(s32 param);
extern void func_80218DA8_5D4278(void *entity, s32 param2, s32 param3,
                                 s32 param4);
extern void func_8021A22C_5D56FC(void *entity);
extern void func_80024038_24C38(u16 param);
extern void func_8003521C_35E1C(void *callback);
extern void func_080004AC_6AEC8C(void);
extern void replace_surprise_pack_scenario(s32 scenario_id, s32 *scenario_code,
                                           s16 scenario_file_id,
                                           const char *item_name);
extern s32 scenario_code_surprise_pack[];

RECOMP_PATCH void func_080009F4_6AF1D4(Entity *entity, ParameterStruct *param)
{
  u16 temp;
  void *entityData;

  // Increment the field at offset 0x16 by 4 and mask to 0x3FF
  temp = param->field_0x16 + 4;
  param->field_0x16 = temp & 0x3FF;

  // Check if bit 0x200 is set in entity flags
  if (entity->flags & 0x200)
  {
    // Call various functions to handle the entity state
    func_80221F70_5DD440();
    
    // Read the flag ID from the entity (original location)
    u16 flag_id = entity->field_0xD0;
    
    DEBUG_PRINTF("Surprise Pack flag ID from field_0xD0: %d (0x%04X)\n", flag_id, flag_id);

    // Check AP logic for this surprise pack
    if (should_run_ap_logic())
    {
      // Convert flag to string key
      char flag_str[16];
      sprintf(flag_str, "%d", flag_id);
      DEBUG_PRINTF("Surprise Pack flag ID: %d\n", flag_id);
      // Get the flag_id_to_ap_location_id dictionary from slot data
      u32 flag_to_location_handle[2];
      rando_get_slotdata_raw_o32("flag_id_to_ap_location_id",
                                 flag_to_location_handle);

      // Try to get the location_id value for this flag directly
      u32 location_id_handle[2];
      rando_access_slotdata_raw_dict_o32(flag_to_location_handle, flag_str,
                                         location_id_handle);

      // Check if we got a valid handle (non-zero indicates success)
      if (location_id_handle[0] != 0 || location_id_handle[1] != 0)
      {
        // Extract the integer value
        u32 location_id = rando_access_slotdata_raw_u32_o32(location_id_handle);

        DEBUG_PRINTF("Surprise Pack flag %d maps to location_id: %d\n", flag_id,
                     location_id);

        // Check if it's not our local item
        bool has_local_item = rando_get_location_has_local_item(location_id);

        // if (!has_local_item) {
        // Get the player
        char player[17];
        rando_get_location_item_player(location_id, player);
        DEBUG_PRINTF("got player %s\n", player);

        // Get the item at the location
        u32 item_id = rando_get_item_at_location(location_id);

        // Get the item name
        char item_name[33];
        rando_get_item_name_from_id(item_id, item_name);

        DEBUG_PRINTF("Item at location %d: 0x%08X (%s)\n", location_id, item_id,
                     item_name);

        // Create formatted message: "Player's Item_name"
        char surprise_message[64];
        sprintf(surprise_message, "%s's %s", player, item_name);

        replace_surprise_pack_scenario(0x064, scenario_code_surprise_pack,
                                       0x05d, surprise_message);
        // } else {
        //     recomp_printf("Location %d has local item\n", location_id);
        // }
      }
      else
      {
        DEBUG_PRINTF("Flag %d not found in flag_id_to_ap_location_id mapping\n",
                     flag_id);
        replace_surprise_pack_scenario(0x064, scenario_code_surprise_pack,
                                       0x05d, "a Surprise Pack");
      }
    }
    else
    {
      replace_surprise_pack_scenario(0x064, scenario_code_surprise_pack, 0x05d,
                                     "a Surprise Pack");
    }

    func_8003D310_3DF10(0x64);
    func_80218DA8_5D4278(entity, 0, 0, 0);
    func_8021A22C_5D56FC(entity);

    // Clear the field at offset 0x60
    entity->field_0x60 = 0;

    func_80024038_24C38(entity->field_0xD0);

    // Check if there's data at offset 0xE4
    entityData = entity->field_0xE4;
    if (entityData != NULL)
    {
      // Set a byte at offset 0xD0 of the entity data to 1
      *(u8 *)((u8 *)entityData + 0xD0) = 1;
    }

    // Schedule a callback function
    func_8003521C_35E1C(func_080004AC_6AEC8C);
  }
}
