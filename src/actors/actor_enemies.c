#include "actor_common.h"
#include "entities.h"
#include "libc/stdbool.h"

// Structure to hold enemy replacement data
struct EnemyReplacement {
    unsigned short room_id;
    int index;
    unsigned short new_enemy_id;
};

// Global list of enemy replacements - populate this with your desired replacements
static struct EnemyReplacement global_enemy_replacements[] = {
    // Example entries - replace these with your actual data
    // {0x001, 0, ENTITY_BLUE_ROBOT},
    // {0x001, 1, ENTITY_PINK_ROBOT_FB},
    // {0x002, 0, ENTITY_GREEN_ROBOT_FD},
};

static int num_global_replacements = sizeof(global_enemy_replacements) / sizeof(global_enemy_replacements[0]);

void process_enemy_actors(struct ActorInstance *actor_instance, struct ActorDefinition *resolved_actor_def, unsigned short actor_id, unsigned short actor_data_file_id, int overall_index)
{
    // Look for a replacement in the global list
    unsigned short new_robot_id = 0;
    bool found_replacement = false;
    
    for (int i = 0; i < num_global_replacements; i++)
    {
        if (global_enemy_replacements[i].room_id == D_800C7AB2 && 
            global_enemy_replacements[i].index == overall_index)
        {
            new_robot_id = global_enemy_replacements[i].new_enemy_id;
            found_replacement = true;
            break;
        }
    }

    if (found_replacement)
    {
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

            recomp_printf("Enemy replaced in room 0x%03X: 0x%03X -> 0x%03X (index %d)\n", 
                          D_800C7AB2, actor_id, new_robot_id, overall_index);
        }
    }
}