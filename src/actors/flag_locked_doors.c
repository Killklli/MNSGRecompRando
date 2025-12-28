#include "actor_common.h"
#include "save_data_tool.h"
struct LockedDoorActor
{
    unsigned short actor_id;   // 0x23E
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

void flag_locked_doors(struct ActorInstance *actor_instance, struct ActorDefinition *resolved_actor_def, unsigned short actor_id, unsigned short actor_data_file_id, int overall_index)
{
    if (actor_id != 0x241 && actor_id != 0x242)
        return;

    if (D_800C7AB2 == 0x130)
    {
        if (overall_index == 4 && !IS_FLAG_SET(FLAG_RECEIVED_SUPER_PASS) && actor_id == 0x241)
        {
            // Create a new locked door actor definition
            struct LockedDoorActor *new_door = (struct LockedDoorActor *)recomp_alloc(sizeof(struct LockedDoorActor));
            if (new_door != NULL)
            {
                // Set up the locked door parameters as specified
                new_door->actor_id = 0x023e;   // Locked door actor ID
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
                new_door->actor_id = 0x023e;   // Locked door actor ID
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