#include "actor_common.h"
#include "save_data_tool.h"
struct LockedDoorActor
{
    unsigned short actor_id;   // 0x23F
    unsigned short padding1;   // 0x0000
    unsigned char door_design; // 0x01 = Oedo Castle, 0x02 = other designs
    unsigned char key_type;    // 0x02 = Silver, etc.
    unsigned short padding2;   // 0x0000
    unsigned short lock_index; // 0x010F
    unsigned short accept_key; // 0x0110
    unsigned short exit_id;    // 0x02
    unsigned short padding3;   // 0x0000
}; // Size: 16

struct SlidingDoorActor
{
    unsigned short actor_id; // 0x24D
    unsigned short padding1; // 0x0000
    unsigned char graphic;   // Graphic/appearance type (e.g., 0x01)
    unsigned char padding2;  // 0x00
    unsigned short padding3; // 0x0000
    unsigned int padding4;   // 0x00000000
    unsigned char padding5;  // 0x00
    unsigned char exit_id;   // Exit ID (e.g., 0x03)
    unsigned short padding6; // 0x0000
}; // Size: 16

struct ExitActor
{
    unsigned short actor_id;     // 0x008C
    unsigned short padding1;     // 0x0000
    unsigned short dest_room;    // Destination room
    short dest_x;                // Destination X coordinate
    short dest_z;                // Destination Z coordinate  
    short dest_y;                // Destination Y coordinate
    unsigned short direction;    // Direction (0300 = South, etc.)
    unsigned char misc_exit_id;  // Misc exit ID
    unsigned char misc_unknown;  // Misc unknown value
}; // Size: 16

void flag_locked_doors(struct ActorInstance *actor_instance, struct ActorDefinition *resolved_actor_def, unsigned short actor_id, unsigned short actor_data_file_id, int overall_index)
{
    // Static variable to store the exit data for reuse
    static struct ExitActor stashed_exit_data = {0};
    static int stash_initialized = 0;
    // Handle room 0x0A8 - convert marker instances to proper locked doors
    if (D_800C7AB2 == 0x0A8)
    {
        if (overall_index == 1 && !stash_initialized && resolved_actor_def != NULL)
        {
            // Stash the exit data from instance 1 for later use
            struct ExitActor *exit = (struct ExitActor *)resolved_actor_def;
            stashed_exit_data = *exit;
            stash_initialized = 1;
        }
        // Check if this is one of our marker instances
        unsigned int marker_value = (unsigned int)actor_instance->actor_definition;
        if (marker_value >= 0xFFFFFFF0)
        {
            // Calculate instance index based on marker value (0xFFFFFFFF = 0, 0xFFFFFFFE = 1, etc.)
            int instance_index = 0xFFFFFFFF - marker_value;
            
            // Set different actors and positions for each instance
            switch (instance_index)
            {
                case 0: // First instance - Normal Door
                    {
                         struct ExitActor *new_exit = (struct ExitActor *)recomp_alloc(sizeof(struct ExitActor));
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

                            
                            actor_instance->actor_definition = (struct ActorDefinition *)new_exit;
                            actor_instance->position.x = 0;
                            actor_instance->position.y = -75;
                            actor_instance->position.z = 485;
                        }
                       
                    }
                    break;
                case 1: // Second instance - Exit Actor
                    {
                        struct LockedDoorActor *new_door = (struct LockedDoorActor *)recomp_alloc(sizeof(struct LockedDoorActor));
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
                            
                            actor_instance->actor_definition = (struct ActorDefinition *)new_door;
                            actor_instance->position.x = 0;
                            actor_instance->position.y = -75;
                            actor_instance->position.z = 485;
                        }
                    }
                    break;
                default: // Out of bounds - log error and skip
                    recomp_printf("Error: Instance index %d is out of bounds for room 0x0A8. Skipping instance.\n", instance_index);
                    return;
            }
            
            // Set common rotation for all instances
            actor_instance->rotation.pitch = 0; // Pitch rotation
            actor_instance->rotation.yaw = 512;   // Yaw rotation
            actor_instance->rotation.roll = 0;  // Roll rotation
            
            // Reset other fields from marker values to normal values
            actor_instance->is_spawned = 0;
            actor_instance->unk_11 = 0;
            actor_instance->unk_12 = 0;
            actor_instance->unk_13 = 0;
            
            // Determine actor type for logging
            const char* actor_type;
            unsigned short actor_id_for_log;
            if (instance_index == 0) {
                struct ExitActor *exit_actor = (struct ExitActor *)actor_instance->actor_definition;
                actor_type = "ExitActor";
                actor_id_for_log = exit_actor->actor_id;
            } else {
                struct LockedDoorActor *locked = (struct LockedDoorActor *)actor_instance->actor_definition;
                actor_type = "LockedDoor";
                actor_id_for_log = locked->actor_id;
            }
            
            recomp_printf("Converted marker instance %d to %s actor 0x%03X in room 0x0A8 with position (%d, %d, %d)\n", 
                          instance_index, actor_type, actor_id_for_log,
                          actor_instance->position.x, actor_instance->position.y, actor_instance->position.z);
        }
    }
    else if (D_800C7AB2 == 0x130)
    {
        if (overall_index == 4 && !IS_FLAG_SET(FLAG_RECEIVED_SUPER_PASS) && actor_id == 0x241)
        {
            // Create a new locked door actor definition
            struct LockedDoorActor *new_door = (struct LockedDoorActor *)recomp_alloc(sizeof(struct LockedDoorActor));
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
                actor_instance->actor_definition = (struct ActorDefinition *)new_door;
            }
        }
    }
    else if (D_800C7AB2 == 0x143 && actor_id == 0x242)
    {
        recomp_printf("Flagging locked door in room 0x143 at instance %d\n", overall_index);
        if (overall_index == 3 && !IS_FLAG_SET(FLAG_DEFEATED_DHARMANYO))
        {
            recomp_printf("Modifying locked door in room 0x143 at instance %d\n", overall_index);
            // Create a new locked door actor definition
            struct LockedDoorActor *new_door = (struct LockedDoorActor *)recomp_alloc(sizeof(struct LockedDoorActor));
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
                actor_instance->actor_definition = (struct ActorDefinition *)new_door;
            }
        }
    }
}