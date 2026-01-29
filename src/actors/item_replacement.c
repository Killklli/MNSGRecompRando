#include "Archipelago.h"
#include "actor_common.h"
#include "common_structs.h"
#include "entities.h"
#include "file_state.h"
#include "libc/stdbool.h"
#include "libc/stdio.h"
#include "libc/string.h"
#include "modding.h"
#include "types.h"

extern unsigned short
    D_800C7AB2; // Part of the huge "SYS_W" structure, ID of the current stage

// Simple atoi implementation since it's not available in the limited libc
static int simple_atoi(const char *str)
{
  int result = 0;
  int sign = 1;

  // Skip whitespace
  while (*str == ' ' || *str == '\t')
  {
    str++;
  }

  // Handle sign
  if (*str == '-')
  {
    sign = -1;
    str++;
  }
  else if (*str == '+')
  {
    str++;
  }

  // Convert digits
  while (*str >= '0' && *str <= '9')
  {
    result = result * 10 + (*str - '0');
    str++;
  }

  return result * sign;
}

// Structure to hold item data from Archipelago item metadata
typedef struct ItemData {
    unsigned short entity_id;
    unsigned short flag_id;
} ItemData;

// Function to check if health randomization is enabled in slot data
static bool is_health_randomization_enabled()
{
  // Check if we're connected to archipelago
  if (!rando_is_connected())
  {
    // If not connected, default to enabled
    DEBUG_PRINTF("[DEBUG] Not connected to Archipelago, defaulting to health randomization enabled\n");
    return true;
  }
  
  u32 randomize_health_handle[2];
  
  // Get the randomize_health setting from slot data
  rando_get_slotdata_raw_o32("randomize_health", randomize_health_handle);
  
  // Get the boolean value as u32 (0 = false, 1 = true)
  u32 randomize_health_value = rando_access_slotdata_raw_u32_o32(randomize_health_handle);
  
  DEBUG_PRINTF("[DEBUG] Health randomization setting: %u\n", randomize_health_value);
  
  return randomize_health_value != 0;
}

// Function to extract item data from Archipelago item metadata
// This pulls both entity_id and flag_id from item_metadata for the given AP item ID
static ItemData get_item_data_from_ap_id(u32 ap_id, u32 *item_metadata_handle)
{
  ItemData result = {0, 0};
  
  // Convert AP ID to string for lookup
  char ap_id_str[16];
  sprintf(ap_id_str, "%lu", (unsigned long)ap_id);

  // Check if the AP ID exists in item_metadata before accessing
  bool has_ap_id = rando_access_slotdata_raw_dict_has_member_o32(
      item_metadata_handle, ap_id_str);

  if (has_ap_id)
  {
    // Try to access the specific item data
    u32 item_data_handle[2];
    rando_access_slotdata_raw_dict_o32(item_metadata_handle, ap_id_str,
                                       item_data_handle);

    // Check if entity_id exists before accessing
    bool has_entity_id = rando_access_slotdata_raw_dict_has_member_o32(
        item_data_handle, "entity_id");

    if (has_entity_id)
    {
      // Try to get the entity_id from the item data
      u32 entity_id_handle[2];
      rando_access_slotdata_raw_dict_o32(item_data_handle, "entity_id",
                                         entity_id_handle);

      // Get the entity_id as a string and convert to int
      char entity_id_str[256];
      rando_access_slotdata_raw_string_o32(entity_id_handle, entity_id_str);

      int entity_id_val = simple_atoi(entity_id_str);

      if (entity_id_val != 0)
      {
        result.entity_id = (unsigned short)entity_id_val;
      }
    }
    
    // Check if flag_id exists before accessing
    bool has_flag_id = rando_access_slotdata_raw_dict_has_member_o32(
        item_data_handle, "flag_id");

    if (has_flag_id)
    {
      // Try to get the flag_id from the item data
      u32 flag_id_handle[2];
      rando_access_slotdata_raw_dict_o32(item_data_handle, "flag_id",
                                         flag_id_handle);

      // Get the flag_id as a string and convert to int
      char flag_id_str[256];
      rando_access_slotdata_raw_string_o32(flag_id_handle, flag_id_str);

      int flag_id_val = simple_atoi(flag_id_str);

      if (flag_id_val != 0)
      {
        result.flag_id = (unsigned short)flag_id_val;
      }
    }
  }

  return result;
}

ItemReplacementList get_item_replacements_for_room()
{
  ItemReplacementList result = {NULL, 0};

  if (should_run_ap_logic())
  {
    // Get item replacement data from Archipelago slot data
    char room_id_str[16];
    sprintf(room_id_str, "%d", D_800C7AB2);

    // Get both location metadata and item metadata from Archipelago slot data
    u32 location_metadata_handle[2];
    rando_get_slotdata_raw_o32("location_metadata", location_metadata_handle);

    u32 item_metadata_handle[2];
    rando_get_slotdata_raw_o32("item_metadata", item_metadata_handle);

    // Check if the room exists in location_metadata before accessing
    bool room_exists = rando_access_slotdata_raw_dict_has_member_o32(
        location_metadata_handle, room_id_str);

    if (!room_exists)
    {
      return result;
    }

    u32 current_room_dict[2];
    rando_access_slotdata_raw_dict_o32(location_metadata_handle, room_id_str,
                                       current_room_dict);

    // Check if the dict handle looks valid (non-zero)
    if (current_room_dict[0] == 0 && current_room_dict[1] == 0)
    {
      return result;
    }

    // Use dictionary iteration approach like actor_enemies.c
    u32 items_iter[2];
    rando_iter_slotdata_raw_dict_o32(current_room_dict, items_iter);

    // Test if there's any data in the iterator
    u32 test_key[2];
    u32 test_value[2];
    bool has_data = rando_iter_slotdata_raw_dict_next_o32(
        current_room_dict, items_iter, test_key, test_value);
    rando_iter_slotdata_raw_dict_close_o32(current_room_dict, items_iter);
    if (has_data)
    {
      // Count the number of items first (similar to actor_enemies.c)
      int count = 0;
      u32 count_iter[2];
      rando_iter_slotdata_raw_dict_o32(current_room_dict, count_iter);
      u32 temp_key[2], temp_value[2];
      while (rando_iter_slotdata_raw_dict_next_o32(
          current_room_dict, count_iter, temp_key, temp_value))
      {
        count++;
      }
      rando_iter_slotdata_raw_dict_close_o32(current_room_dict, count_iter);

      // Allocate memory for the replacement pairs
      result.pairs = (ItemReplacementPair *)recomp_alloc(
          count * sizeof(ItemReplacementPair));
      result.count = count;

      if (result.pairs != NULL)
      {
        DEBUG_PRINTF("Room 0x%03X: Found %d item replacements\n", D_800C7AB2,
                     count);

        // Re-create the iterator for filling the pairs array
        u32 fill_iter[2];
        rando_iter_slotdata_raw_dict_o32(current_room_dict, fill_iter);

        // Fill the pairs array
        int pair_index = 0;
        u32 item_key[2];
        u32 item_value[2];
        while (rando_iter_slotdata_raw_dict_next_o32(
            current_room_dict, fill_iter, item_key, item_value))
        {
          // item_value should be the object containing instance_id and
          // new_item_ap_id Check if this item has instance_id and
          // new_item_ap_id fields
          if (rando_access_slotdata_raw_dict_has_member_o32(item_value,
                                                            "instance_id") &&
              rando_access_slotdata_raw_dict_has_member_o32(item_value,
                                                            "new_item_ap_id"))
          {

            // Get instance_id
            u32 instance_id_handle[2];
            rando_access_slotdata_raw_dict_o32(item_value, "instance_id",
                                               instance_id_handle);
            char instance_id_str[256];
            rando_access_slotdata_raw_string_o32(instance_id_handle,
                                                 instance_id_str);

            // Get new_item_ap_id
            u32 new_item_ap_id_handle[2];
            rando_access_slotdata_raw_dict_o32(item_value, "new_item_ap_id",
                                               new_item_ap_id_handle);
            char new_item_ap_id_str[256];
            rando_access_slotdata_raw_string_o32(new_item_ap_id_handle,
                                                 new_item_ap_id_str);

            // Get flag_id if it exists
            unsigned short flag_id_to_use = 0;
            if (rando_access_slotdata_raw_dict_has_member_o32(item_value, "flag_id"))
            {
              u32 flag_id_handle[2];
              rando_access_slotdata_raw_dict_o32(item_value, "flag_id",
                                                 flag_id_handle);
              char flag_id_str[256];
              rando_access_slotdata_raw_string_o32(flag_id_handle, flag_id_str);
              int flag_id_val = simple_atoi(flag_id_str);
              if (flag_id_val > 0) {
                flag_id_to_use = (unsigned short)flag_id_val;
              }
            }

            // Convert strings to integers
            int instance_id_val = simple_atoi(instance_id_str);
            int new_item_ap_id_val = simple_atoi(new_item_ap_id_str);

            // Store the replacement data
            result.pairs[pair_index].instance_id = instance_id_val;
            result.pairs[pair_index].new_item_ap_id = new_item_ap_id_val;

            // Check if location_id exists and if the location has a local item
            // unsigned short item_id_to_use;
            // if (rando_access_slotdata_raw_dict_has_member_o32(item_value,
            // "location_id")) {
            //     // Get location_id
            //     u32 location_id_handle[2];
            //     rando_access_slotdata_raw_dict_o32(item_value, "location_id",
            //     location_id_handle); char location_id_str[256];
            //     rando_access_slotdata_raw_string_o32(location_id_handle,
            //     location_id_str); u32 location_id_val =
            //     simple_atoi(location_id_str);

            //     // If we have the local item, use the mapped item ID,
            //     otherwise use 0x091 if
            //     (rando_get_location_has_local_item(location_id_val)) {
            //         item_id_to_use =
            //         map_ap_id_to_actor_id(new_item_ap_id_val,
            //         item_metadata_handle);
            //     } else {
            //         item_id_to_use = 0x091;
            //     }
            // } else {
            //     // Fallback: if no location_id, use the mapped item ID (old
            //     behavior) item_id_to_use =
            //     map_ap_id_to_actor_id(new_item_ap_id_val,
            //     item_metadata_handle);
            // }
            // TODO: Update item spawn types, we're pinned to surprise packs
            // right now for safety
            unsigned short item_id_to_use = 0x091; // Always use surprise pack for now

            result.pairs[pair_index].new_item_id = item_id_to_use;
            result.pairs[pair_index].flag_id = flag_id_to_use;
            DEBUG_PRINTF("[DEBUG] Room 0x%03X Item Replacement %d: "
                         "Instance %d, AP ID %d -> Actor 0x%03X, Flag ID %d\n",
                         D_800C7AB2, pair_index, instance_id_val, new_item_ap_id_val,
                         item_id_to_use, flag_id_to_use);

            DEBUG_PRINTF("  Item instance %d: AP ID %d -> Actor 0x%03X\n",
                         instance_id_val, new_item_ap_id_val,
                         result.pairs[pair_index].new_item_id);

            pair_index++;
          }
        }
        rando_iter_slotdata_raw_dict_close_o32(current_room_dict, fill_iter);
      }
    }
  }

  return result;
}

// Convert AP ID to actor ID using item_metadata
void process_items(ActorInstance *actor_instance,
                   ActorDefinition *resolved_actor_def, unsigned short actor_id,
                   unsigned short actor_data_file_id, int overall_index)
{
  // Get the replacement data for the current room
  ItemReplacementList replacements = get_item_replacements_for_room();

  // Print all replacements for this room
  if (replacements.count > 0)
  {
    DEBUG_PRINTF("[DEBUG] Room 0x%03X has %d replacements:\n", D_800C7AB2,
                 replacements.count);
    for (int j = 0; j < replacements.count; j++)
    {
      DEBUG_PRINTF("  [%d] Instance %d: AP ID %lu -> Actor 0x%03X\n", j,
                   replacements.pairs[j].instance_id,
                   (unsigned long)replacements.pairs[j].new_item_ap_id,
                   replacements.pairs[j].new_item_id);
    }
  }

  // Look for a replacement in the returned list
  unsigned short new_item_id = 0;
  unsigned short replacement_flag_id = 0;
  bool found_replacement = false;

  // Check the dynamic replacements from Archipelago
  for (int i = 0; i < replacements.count; i++)
  {
    DEBUG_PRINTF("[DEBUG] process_items: Checking replacement %d: "
                 "instance_id=%d, looking for %d\n",
                 i, replacements.pairs[i].instance_id, overall_index);

    if (replacements.pairs[i].instance_id == overall_index)
    {
      DEBUG_PRINTF("[DEBUG] process_items: Found matching instance ID %d\n",
                   overall_index);

      // Skip if the AP ID is 0 (no replacement needed)
      if (replacements.pairs[i].new_item_ap_id == 0)
      {
        DEBUG_PRINTF("Skipping item replacement for index %d: AP ID is 0 (no "
                     "replacement)\n",
                     overall_index);
        break;
      }

      // Skip if the new item ID is 0 (likely invalid)
      if (replacements.pairs[i].new_item_id == 0)
      {
        DEBUG_PRINTF("Skipping item replacement for index %d: new item ID is 0 "
                     "(AP ID: %lu)\n",
                     overall_index,
                     (unsigned long)replacements.pairs[i].new_item_ap_id);
        break;
      }

      // Check if this is a health item and if health randomization is disabled
      if ((actor_id == 0x84 || actor_id == 0x85) && !is_health_randomization_enabled())
      {
        DEBUG_PRINTF("Skipping health item replacement for index %d: health randomization is disabled (actor_id: 0x%03X)\n",
                     overall_index, actor_id);
        break;
      }

      new_item_id = replacements.pairs[i].new_item_id;
      replacement_flag_id = replacements.pairs[i].flag_id;
      found_replacement = true;
      DEBUG_PRINTF("Found item replacement: instance %d, AP ID %lu -> actor "
                   "0x%03X (was 0x%03X), flag_id=%d\n",
                   overall_index,
                   (unsigned long)replacements.pairs[i].new_item_ap_id,
                   new_item_id, actor_id, replacement_flag_id);

      break;
    }
  }

  DEBUG_PRINTF("[DEBUG] process_items: Found replacement: %s\n",
               found_replacement ? "YES" : "NO");

  if (found_replacement)
  {
    DEBUG_PRINTF("[DEBUG] process_items: Replacing original item ID 0x%03X in "
                 "room 0x%03X at instance %d\n",
                 actor_id, D_800C7AB2, overall_index);
  }

  if (found_replacement && actor_id != 0x3d3)
  {
    // Create a new actor definition for this specific instance
    ActorDefinition *new_actor_def =
        (ActorDefinition *)recomp_alloc(sizeof(ActorDefinition));
    if (new_actor_def != NULL)
    {
      // Copy the original definition data
      new_actor_def->data[0] = resolved_actor_def->data[0];
      new_actor_def->data[1] = resolved_actor_def->data[1];
      new_actor_def->data[2] = resolved_actor_def->data[2];
      new_actor_def->data[3] = resolved_actor_def->data[3];

      // Change the actor ID in the new definition
      new_actor_def->data[0] =
          (new_actor_def->data[0] & 0x0000FFFF) | (new_item_id << 16);

      // Special handling for different item types
      if (actor_id == 0x193) // KEY items
      {
        DEBUG_PRINTF("Processing key item replacement for instance %d\n",
                      overall_index);
        // For keys, the flag ID is in data[2] of the original item
        // We need to move it to data[1] for the new item
        unsigned int original_flag_id = (resolved_actor_def->data[2] >> 16) & 0xFFFF;
        new_actor_def->data[1] = (new_actor_def->data[1] & 0x0000FFFF) | (original_flag_id << 16);
        // and then set data[2] to 0
        new_actor_def->data[2] = new_actor_def->data[2] & 0x0000FFFF;
      }

      // Special handling for dango items (0x84 or 0x85)
      if (actor_id == 0x84 || actor_id == 0x85) 
      {
        DEBUG_PRINTF("Processing Dango item replacement for instance %d\n",
                      overall_index);
        // Use the flag_id from the replacement data we already found
        unsigned short flag_id_to_use = replacement_flag_id;
        if (flag_id_to_use == 0) {
          flag_id_to_use = 0x1804; // Default fallback only if no flag_id was provided
        }
        DEBUG_PRINTF("Setting Dango item flag ID to %d for instance %d\n",
                      flag_id_to_use, overall_index);
        // Set flag ID in data[1] upper 16 bits
        new_actor_def->data[1] = (new_actor_def->data[1] & 0x0000FFFF) | (flag_id_to_use << 16);
      }

      // Update this instance to point to the new definition
      actor_instance->actor_definition = new_actor_def;
    }
  }

  // Clean up allocated memory
  if (replacements.pairs != NULL)
  {
    recomp_free(replacements.pairs);
  }
}
