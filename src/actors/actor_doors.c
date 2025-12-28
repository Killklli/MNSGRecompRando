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

void process_door_actors(struct ActorInstance *actor_instance, struct ActorDefinition *resolved_actor_def, unsigned short actor_id, unsigned short actor_data_file_id, int overall_index)
{
    // Check for locked door actor (0x23E) and handle it with struct
    if (actor_id == 0x23e)
    {
        // Cast the actor definition to our locked door struct
        struct LockedDoorActor *locked_door = (struct LockedDoorActor *)resolved_actor_def;

        // // Check for specific locked door modification in room 009
        // if (D_800C7AB2 == 0x009 && locked_door->lock_index == 0x010b && locked_door->accept_key == 0x010c) {
        //     // Create a new locked door actor definition for this specific instance
        //     struct LockedDoorActor *new_door = (struct LockedDoorActor *)recomp_alloc(sizeof(struct LockedDoorActor));
        //     if (new_door != NULL) {
        //         // Copy the original door data
        //         *new_door = *locked_door;

        //         // Update the lock index and accept key
        //         new_door->lock_index = 0x010b;     // Change from 010b to 010f
        //         new_door->accept_key = 0x0110;     // Change from 010c to 0110

        //         // Update this instance to point to the new definition
        //         actor_instance->actor_definition = (struct ActorDefinition *)new_door;

        //         recomp_printf("Locked door modification in room 009: lock_index 0x010b->0x010f, accept_key 0x010c->0x0110 (instance %d)\n", overall_index);
        //     }
        // }
        // Locked door processing logic can be added here
    }

    // Check for sliding door actor (0x24D) and handle it with struct
    if (actor_id == 0x24d)
    {
        // Cast the actor definition to our sliding door struct
        struct SlidingDoorActor *sliding_door = (struct SlidingDoorActor *)resolved_actor_def;
        // Sliding door processing logic can be added here
    }

}