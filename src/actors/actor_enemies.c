#include "actor_common.h"
#include "entities.h"

void process_enemy_actors(struct ActorInstance *actor_instances, int regular_instance_count, int total_instances,
                          unsigned char *grouped_data_start, int max_grouped_data_size, unsigned short actor_data_file_id)
{
    // Counter for tracking replacements
    int robot_replacements_made = 0;
    unsigned short restricted_rooms[] = {0x0000, 0x87};
    unsigned short restricted_enemies[] = {ENTITY_SPINNING_KITE, ENTITY_SWORD_ROBOT, ENTITY_PAPER_GHOST, ENTITY_TANK, ENTITY_GIANT_ENEMY_CRAB, ENTITY_SAMURAI, ENTITY_ROSE_ROBOT, ENTITY_BURROWING_ROBOT};
    // Robot IDs that can be replaced or used as replacements
    unsigned short robot_ids[] = {
        ENTITY_ROBOT_BEE, ENTITY_PINK_ROBOT_FB, ENTITY_PINK_ROBOT_FC, ENTITY_GREEN_ROBOT_FD, 
        ENTITY_GREEN_ROBOT_FE, ENTITY_BLUE_ROBOT, ENTITY_SCARECROW_BOT, ENTITY_PINK_ROBOT_110_FESTIVAL_TEMPLE_AND_HAGI,
        ENTITY_SMALL_CANNON, ENTITY_FLYING_DRAGON_HEAD, ENTITY_DRUM_ROBOT, ENTITY_BIG_SWATTING_ROBOT,
        ENTITY_CAN_CAN_LEGS, ENTITY_SPINNING_KITE, ENTITY_BOUNCING_DARUMANYO, ENTITY_PAPER_GHOST,
        ENTITY_KITE, ENTITY_WATER_SNAKE, ENTITY_FLOATING_INGREDIENTS_GOURMET_SUB, ENTITY_FLATFISH_TOSA_BRIDGE,
        ENTITY_SWORD_ROBOT, ENTITY_TRIANGLE_ROBOT, ENTITY_GIANT_ENEMY_CRAB, ENTITY_SAMURAI,
        ENTITY_HAMMER_THROWER, ENTITY_BOMBER_BIRD, ENTITY_BAMBOO_SHOOTER, ENTITY_RED_EYE_FISH,
        ENTITY_ROSE_ROBOT, ENTITY_FIRE_STALKER, ENTITY_NINJA, ENTITY_FLYING_TILE,
        ENTITY_FOX_MASK, ENTITY_JET_ROBOT, ENTITY_YELLOW_ROBOT, ENTITY_BIG_SWATTING_ROBOT_RED,
        ENTITY_SHRINKING_ROBOT, ENTITY_SEAHORSE, ENTITY_SPINY_SEA_URCHIN, ENTITY_BURROWING_ROBOT,
        ENTITY_FLOOR_FLAMETHROWER
    };
    int num_robots = sizeof(robot_ids) / sizeof(robot_ids[0]);

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

            // Check if this actor ID is in our robot list
            bool is_target_robot = false;
            for (int i = 0; i < num_robots; i++)
            {
                if (actor_id == robot_ids[i])
                {
                    is_target_robot = true;
                    break;
                }
            }

            if (is_target_robot)
            {
                // Check if current room is in restricted rooms list
                bool is_restricted_room = false;
                int num_restricted_rooms = sizeof(restricted_rooms) / sizeof(restricted_rooms[0]);
                for (int i = 0; i < num_restricted_rooms; i++)
                {
                    if (D_800C7AB2 == restricted_rooms[i])
                    {
                        is_restricted_room = true;
                        break;
                    }
                }

                unsigned short new_robot_id;
                int attempts = 0;
                int max_attempts = num_robots * 2; // Prevent infinite loop

                do {
                    // Generate random index for replacement robot
                    random_seed = random_seed * 1103515245 + 12345;
                    int random_index = (random_seed >> 16) % num_robots;
                    new_robot_id = robot_ids[random_index];
                    attempts++;

                    // If not in a restricted room, any robot is fine
                    if (!is_restricted_room) break;

                    // If in a restricted room, check if this robot is in the restricted list
                    bool is_restricted_enemy = false;
                    int num_restricted_enemies = sizeof(restricted_enemies) / sizeof(restricted_enemies[0]);
                    for (int j = 0; j < num_restricted_enemies; j++)
                    {
                        if (new_robot_id == restricted_enemies[j])
                        {
                            is_restricted_enemy = true;
                            break;
                        }
                    }

                    // If it's not a restricted enemy, we can use it
                    if (!is_restricted_enemy) break;

                } while (attempts < max_attempts);

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

                    recomp_printf("Enemy placed in room 0x%03X: 0x%03X -> 0x%03X (instance %d)%s\n", 
                                  D_800C7AB2, actor_id, new_robot_id, robot_replacements_made,
                                  is_restricted_room ? " [RESTRICTED ROOM]" : "");
                    robot_replacements_made++;
                }
            }
        }
    }
}