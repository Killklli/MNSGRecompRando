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

void process_door_actors(struct ActorInstance *actor_instances, int regular_instance_count, int total_instances, 
                        unsigned char *grouped_data_start, int max_grouped_data_size, unsigned short actor_data_file_id)
{
    // Process all instances in a unified manner
    int grouped_index = 0;
    for (int overall_index = 0; overall_index < total_instances; overall_index++)
    {
        struct ActorInstance *actor_instance = NULL;

        if (overall_index < regular_instance_count)
        {
            // Regular instance
            actor_instance = &actor_instances[overall_index];
        }
        else
        {
            // Grouped instance - find the next valid grouped instance
            while ((int)(grouped_index * sizeof(struct ActorInstance)) < max_grouped_data_size)
            {
                struct ActorInstance *potential_instance = (struct ActorInstance *)(grouped_data_start + grouped_index * sizeof(struct ActorInstance));
                unsigned char *raw_bytes = (unsigned char *)potential_instance;

                bool has_0800_pattern = ((int)(grouped_index * sizeof(struct ActorInstance)) + 12 < max_grouped_data_size &&
                                         raw_bytes[12] == 0x08 && raw_bytes[13] == 0x00);
                bool reasonable_position = (potential_instance->position.x > -10000 && potential_instance->position.x < 10000 &&
                                            potential_instance->position.y > -10000 && potential_instance->position.y < 10000 &&
                                            potential_instance->position.z > -10000 && potential_instance->position.z < 10000);

                if (has_0800_pattern && reasonable_position)
                {
                    actor_instance = potential_instance;
                    grouped_index++;
                    break;
                }
                grouped_index++;
            }
        }

        if (actor_instance == NULL)
            break;

        // Resolve the actor definition pointer to the new buffer
        struct ActorDefinition *resolved_actor_def = func_80014840_15440(actor_instance->actor_definition, actor_data_file_id);

        if (resolved_actor_def != NULL)
        {
            // Extract actor ID from the first data field (shift right by 16 to get the upper 16 bits)
            unsigned short actor_id = (resolved_actor_def->data[0] >> 16) & 0xFFFF;

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

            // Check for actor 0x241 and handle door conversion
            if (actor_id == 0x241)
            {
                // Check for specific actor in room 0x130 and instance id 4, and flag bit is UNSET (value = 0)
                // 0x11 is Super Pass
                if (D_800C7AB2 == 0x130 && overall_index == 4 && !IS_FLAG_SET(FLAG_RECEIVED_SUPER_PASS))
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

                        recomp_printf("Door conversion: Room 0x130 Actor 0x241 Instance %d -> Locked Door 0x23E (Bridge Guards flag NOT set)\n", overall_index);
                    }
                }
            }
        }
    }
}