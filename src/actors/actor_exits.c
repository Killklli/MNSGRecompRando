#include "actor_common.h"

struct SignActor
{
    unsigned short actor_id; // 0x08B
    unsigned short padding1; // 0x0000
    unsigned int padding2;   // 0x00000000
    unsigned short padding3; // 0x0000
    unsigned short message;  // Message ID (e.g., 0x013A)
    unsigned int padding4;   // 0x00000000
}; // Size: 16

struct ExitActor
{
    unsigned short actor_id;    // 0x08C
    unsigned short padding1;    // 0x0000
    unsigned short dest_room;   // Destination room ID (e.g., 0x01C5)
    unsigned short dest_x;      // Destination X coordinate (e.g., 0x0057)
    unsigned short dest_z;      // Destination Z coordinate (e.g., -0x0032 = 0xFFCE)
    unsigned short dest_y;      // Destination Y coordinate (e.g., 0x006E)
    unsigned short direction;   // Exit direction (e.g., 0x0300 = South)
    unsigned char misc_exit_id; // Misc exit ID (e.g., 0x28)
    unsigned char misc_unknown; // Unknown value (e.g., 0x13)
}; // Size: 16

void process_exit_actors(struct ActorInstance *actor_instances, int regular_instance_count, int total_instances, 
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

            // Check for sign actor (0x08B) and handle it with struct
            if (actor_id == 0x08b)
            {
                // Cast the actor definition to our sign struct
                struct SignActor *sign = (struct SignActor *)resolved_actor_def;
                // Sign processing logic can be added here
            }

            // Check for exit actor (0x08C) and handle it with struct
            if (actor_id == 0x08c)
            {
                // Cast the actor definition to our exit struct
                struct ExitActor *exit = (struct ExitActor *)resolved_actor_def;

                // // Check for specific exit in room 0x002, instance index 3
                // if (D_800C7AB2 == 0x002 && overall_index == 3 && exit->dest_room == 0x0007 && true == false) {
                //     // Create a new actor definition for this specific instance
                //     struct ExitActor *new_exit = (struct ExitActor *)recomp_alloc(sizeof(struct ExitActor));
                //     if (new_exit != NULL) {
                //         // Copy the original exit data
                //         *new_exit = *exit;

                //         // Update the exit destination to Kai Highway
                //         new_exit->dest_room = 0x012c;
                //         new_exit->dest_x = 0xa94;       // -0x056c in two's complement = 0xa94
                //         new_exit->dest_z = 0x0108;
                //         new_exit->dest_y = 0x0264;
                //         new_exit->direction = 0x0100;   // North
                //         new_exit->misc_exit_id = 02;
                //         new_exit->misc_unknown = 10;

                //         // Update this instance to point to the new definition
                //         actor_instance->actor_definition = (struct ActorDefinition *)new_exit;

                //         recomp_printf("Exit modification: Room 002 Instance 3 -> Kai Highway (012c)\n");
                //     }
                // }
            }
        }
    }
}