#include "actor_common.h"
#include "common_structs.h"
#include "save_data_tool.h"
#include "Archipelago.h"

void adjust_logical_doors(ActorInstance *actor_instance,
                          ActorDefinition *resolved_actor_def,
                          unsigned short actor_id,
                          unsigned short actor_data_file_id,
                          int overall_index)
{
  // Check if prevent_oneway_softlocks is disabled in slot data
  if (rando_is_connected())
  {
    u32 prevent_oneway_handle[2];
    rando_get_slotdata_raw_o32("prevent_oneway_softlocks", prevent_oneway_handle);
    u32 prevent_oneway_value = rando_access_slotdata_raw_u32_o32(prevent_oneway_handle);
    
    if (!prevent_oneway_value)
    {
      return; // Exit early if prevent_oneway_softlocks is False
    }
  }

  // Static variable to store the exit data for reuse
  static ExitActor stashed_exit_data = {0};
  static int stash_initialized = 0;
  // Handle room 0x0A8 - convert marker instances to proper locked doors
  if (D_800C7AB2 == 0x0A8)
  {
    if (overall_index == 1 && !stash_initialized &&
        resolved_actor_def != NULL)
    {
      // Stash the exit data from instance 1 for later use
      ExitActor *exit = (ExitActor *)resolved_actor_def;
      stashed_exit_data = *exit;
      stash_initialized = 1;
    }
    // Check if this is one of our marker instances
    unsigned int marker_value = (unsigned int)actor_instance->actor_definition;
    if (marker_value >= 0xFFFFFFF0)
    {
      // Calculate instance index based on marker value (0xFFFFFFFF = 0,
      // 0xFFFFFFFE = 1, etc.)
      int instance_index = 0xFFFFFFFF - marker_value;

      // Set different actors and positions for each instance
      switch (instance_index)
      {
      case 0: // First instance - Normal Door
      {
        ExitActor *new_exit = (ExitActor *)recomp_alloc(sizeof(ExitActor));
        if (new_exit != NULL)
        {
          // Use stashed exit data
          *new_exit = stashed_exit_data;
          // Override the exit ID to 4 as requested
          new_exit->dest_room = 0x14C;
          new_exit->misc_exit_id = 4;
          new_exit->misc_unknown = 0x10;
          new_exit->direction = 0x0200; // North
          // Print the dest cords
          // Setting ExitActor dest coords to (41, -105, -70) for instance 0
          new_exit->dest_x = 0;
          new_exit->dest_y = -50;
          new_exit->dest_z = -50;

          actor_instance->actor_definition = (ActorDefinition *)new_exit;
          actor_instance->position.x = 0;
          actor_instance->position.y = -75;
          actor_instance->position.z = 485;
        }
      }
      break;
      case 1: // Second instance - Exit Actor
      {
        LockedDoorActor *new_door =
            (LockedDoorActor *)recomp_alloc(sizeof(LockedDoorActor));
        if (new_door != NULL)
        {
          new_door->actor_id = 0x023F;   // Normal Door actor ID
          new_door->door_design = 0x01;  // Door design 03
          new_door->key_type = 0x00;     // No key required
          new_door->exit_id = 0x04;      // Exit ID 01
          new_door->lock_index = 0xFFFF; // Default lock values
          new_door->accept_key = 0xFFFF;
          new_door->padding1 = 0x0000;
          new_door->padding2 = 0x0000;
          new_door->padding3 = 0x0000;

          actor_instance->actor_definition = (ActorDefinition *)new_door;
          actor_instance->position.x = 0;
          actor_instance->position.y = -75;
          actor_instance->position.z = 485;
        }
      }
      break;
      default: // Out of bounds - log error and skip
        DEBUG_PRINTF("Error: Instance index %d is out of bounds for room "
                     "0x0A8. Skipping instance.\n",
                     instance_index);
        return;
      }

      // Set common rotation for all instances
      actor_instance->rotation.pitch = 0; // Pitch rotation
      actor_instance->rotation.yaw = 512; // Yaw rotation
      actor_instance->rotation.roll = 0;  // Roll rotation

      // Reset other fields from marker values to normal values
      actor_instance->is_spawned = 0;
      actor_instance->unk_11 = 0;
      actor_instance->unk_12 = 0;
      actor_instance->unk_13 = 0;

      // Determine actor type for logging
      const char *actor_type;
      unsigned short actor_id_for_log;
      if (instance_index == 0)
      {
        ExitActor *exit_actor = (ExitActor *)actor_instance->actor_definition;
        actor_type = "ExitActor";
        actor_id_for_log = exit_actor->actor_id;
      }
      else
      {
        LockedDoorActor *locked =
            (LockedDoorActor *)actor_instance->actor_definition;
        actor_type = "LockedDoor";
        actor_id_for_log = locked->actor_id;
      }

      DEBUG_PRINTF("Converted marker instance %d to %s actor 0x%03X in room "
                   "0x0A8 with position (%d, %d, %d)\n",
                   instance_index, actor_type, actor_id_for_log,
                   actor_instance->position.x, actor_instance->position.y,
                   actor_instance->position.z);
    }
  }
  else if (D_800C7AB2 == 0x130)
  {
    if (overall_index == 4 && !READ_SAVE_DATA(SAVE_SUPER_PASS) &&
        actor_id == 0x241)
    {
      // Create a new locked door actor definition
      LockedDoorActor *new_door =
          (LockedDoorActor *)recomp_alloc(sizeof(LockedDoorActor));
      if (new_door != NULL)
      {
        // Set up the locked door parameters as specified
        new_door->actor_id = 0x023E;   // Locked door actor ID
        new_door->padding1 = 0x0000;   // Padding
        new_door->door_design = 0x05;  // Door design 05
        new_door->key_type = 0x03;     // Key type 03
        new_door->padding2 = 0x0000;   // Padding
        new_door->lock_index = 0xFFFF; // Lock index 0011
        new_door->accept_key = 0xFFFF; // Accept key FFFF
        new_door->exit_id = 0x01;      // Exit ID 01
        new_door->padding3 = 0x0000;   // Padding

        // Update this instance to point to the new definition
        actor_instance->actor_definition = (ActorDefinition *)new_door;
      }
    }
  }
  else if (D_800C7AB2 == 0x143 && actor_id == 0x242)
  {
    DEBUG_PRINTF("Flagging locked door in room 0x143 at instance %d\n",
                 overall_index);
    if (overall_index == 3 && !IS_FLAG_SET(FLAG_DEFEATED_DHARMANYO))
    {
      DEBUG_PRINTF("Modifying locked door in room 0x143 at instance %d\n",
                   overall_index);
      // Create a new locked door actor definition
      LockedDoorActor *new_door =
          (LockedDoorActor *)recomp_alloc(sizeof(LockedDoorActor));
      if (new_door != NULL)
      {
        // Set up the locked door parameters as specified
        new_door->actor_id = 0x023E;   // Locked door actor ID
        new_door->padding1 = 0x0000;   // Padding
        new_door->door_design = 0x05;  // Door design 05
        new_door->key_type = 0x03;     // Key type 03
        new_door->padding2 = 0x0000;   // Padding
        new_door->lock_index = 0xFFFF; // Lock index 0011
        new_door->accept_key = 0xFFFF; // Accept key FFFF
        new_door->exit_id = 0x01;      // Exit ID 01
        new_door->padding3 = 0x0000;   // Padding

        // Update this instance to point to the new definition
        actor_instance->actor_definition = (ActorDefinition *)new_door;
      }
    }
  }
  else if (D_800C7AB2 == 0x133)
  {
    if (overall_index == 3 && !READ_SAVE_DATA(SAVE_ACHILLES_HEEL) &&
        actor_id == 0x242)
    {
      // Create a new locked door actor definition
      LockedDoorActor *new_door =
          (LockedDoorActor *)recomp_alloc(sizeof(LockedDoorActor));
      if (new_door != NULL)
      {
        // Set up the locked door parameters as specified
        new_door->actor_id = 0x023E;   // Locked door actor ID
        new_door->padding1 = 0x0000;   // Padding
        new_door->door_design = 0x05;  // Door design 05
        new_door->key_type = 0x03;     // Key type 03
        new_door->padding2 = 0x0000;   // Padding
        new_door->lock_index = 0xFFFF; // Lock index 0011
        new_door->accept_key = 0xFFFF; // Accept key FFFF
        new_door->exit_id = 0x01;      // Exit ID 01
        new_door->padding3 = 0x0000;   // Padding

        // Update this instance to point to the new definition
        actor_instance->actor_definition = (ActorDefinition *)new_door;
      }
    }
  }
  else if (D_800C7AB2 == 0x14F)
  {
    if (overall_index == 3 && !READ_SAVE_DATA(SAVE_SUDDEN_IMPACT_MAGIC) && !READ_SAVE_DATA(SAVE_GOEMON_RECRUITED) &&
        actor_id == 0x242)
    {
      // Create a new locked door actor definition
      LockedDoorActor *new_door =
          (LockedDoorActor *)recomp_alloc(sizeof(LockedDoorActor));
      if (new_door != NULL)
      {
        // Set up the locked door parameters as specified
        new_door->actor_id = 0x023E;   // Locked door actor ID
        new_door->padding1 = 0x0000;   // Padding
        new_door->door_design = 0x05;  // Door design 05
        new_door->key_type = 0x03;     // Key type 03
        new_door->padding2 = 0x0000;   // Padding
        new_door->lock_index = 0xFFFF; // Lock index 0011
        new_door->accept_key = 0xFFFF; // Accept key FFFF
        new_door->exit_id = 0x01;      // Exit ID 01
        new_door->padding3 = 0x0000;   // Padding

        // Update this instance to point to the new definition
        actor_instance->actor_definition = (ActorDefinition *)new_door;
      }
    }
  }
}
