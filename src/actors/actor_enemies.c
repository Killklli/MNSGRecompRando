#include "actor_common.h"

void process_enemy_actors(struct ActorInstance *actor_instances, int regular_instance_count, int total_instances, 
                         unsigned char *grouped_data_start, int max_grouped_data_size, unsigned short actor_data_file_id)
{
    // Counter for tracking replacements
    int robot_replacements_made = 0;

    // Robot IDs that can be replaced
    unsigned short source_robot_ids[] = {0x0fb, 0x0fc, 0x0fd, 0x0fe, 0x12d};
    int num_source_robots = sizeof(source_robot_ids) / sizeof(source_robot_ids[0]);

    // Robot IDs to replace with (including originals for possible no-change)
    unsigned short target_robot_ids[] = {0x0fb, 0x0fc, 0x0fd, 0x0fe, 0x12d, 0x100, 0x103, 0x130, 0x0ff, 0x132, 0x133, 0x145, 0x10c, 0x13d};
    int num_target_robots = sizeof(target_robot_ids) / sizeof(target_robot_ids[0]);

    // Simple random seed based on stage ID for deterministic randomness per stage
    unsigned int random_seed = D_800C7AB2 * 1103515245 + 12345;

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

            // Check if current stage is 0x12C and if this actor is one of our target robot IDs
            if (D_800C7AB2 == 0x012C)
            {
                // Check if this actor ID is in our source robot list
                bool is_target_robot = false;
                for (int i = 0; i < num_source_robots; i++)
                {
                    if (actor_id == source_robot_ids[i])
                    {
                        is_target_robot = true;
                        break;
                    }
                }

                if (is_target_robot)
                {
                    // Generate random index for replacement robot
                    random_seed = random_seed * 1103515245 + 12345;
                    int random_index = (random_seed >> 16) % num_target_robots;
                    unsigned short new_robot_id = target_robot_ids[random_index];

                    // Create a new actor definition for this specific instance
                    struct ActorDefinition *new_actor_def = (struct ActorDefinition *)recomp_alloc(sizeof(struct ActorDefinition));
                    if (new_actor_def != NULL)
                    {
                        // Copy the original definition data
                        new_actor_def->data[0] = resolved_actor_def->data[0];
                        new_actor_def->data[1] = resolved_actor_def->data[1];
                        new_actor_def->data[2] = resolved_actor_def->data[2];
                        new_actor_def->data[3] = resolved_actor_def->data[3];

                        // Change the actor ID in the new definition
                        new_actor_def->data[0] = (new_actor_def->data[0] & 0x0000FFFF) | (new_robot_id << 16);

                        // Update this instance to point to the new definition
                        actor_instance->actor_definition = new_actor_def;

                        // recomp_printf("Robot randomization: 0x%03X -> 0x%03X (instance %d)\n", actor_id, new_robot_id, robot_replacements_made);
                        robot_replacements_made++;
                    }
                }
            }
        }
    }
}