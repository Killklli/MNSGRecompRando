#include "actor_common.h"

struct FlagActor
{
    unsigned short actor_id; // 0x086, 0x087, 0x088, 0x089, 0x091, 0x226, 0x326, 0x345
    unsigned short padding1; // 0x0000
    unsigned short flag;     // Flag identifier (e.g., 0x00DA, 0x00F7)
    unsigned short padding2; // 0x0000
    unsigned int padding3;   // 0x00000000
    unsigned int padding4;   // 0x00000000
}; // Size: 16

struct KeyActor
{
    unsigned short actor_id;  // 0x193
    unsigned short padding1;  // 0x0000
    unsigned short enemies;   // 0x0000 = No enemies required
    unsigned short padding2;  // 0x0000
    unsigned short key_index; // 0x0110
    unsigned short padding3;  // 0x0000
    unsigned int padding4;    // 0x00000000
}; // Size: 16

void process_flag_actors(struct ActorInstance *actor_instances, int regular_instance_count, int total_instances, 
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

            // Check for flag actors and handle them with struct
            if (actor_id == 0x086 || actor_id == 0x087 || actor_id == 0x088 || actor_id == 0x089 ||
                actor_id == 0x091 || actor_id == 0x226 || actor_id == 0x326 || actor_id == 0x345)
            {
                // Cast the actor definition to our flag struct
                struct FlagActor *flag = (struct FlagActor *)resolved_actor_def;

                // Check for specific actor conversion in room 009: actor 086 -> key 193
                // if (D_800C7AB2 == 0x009 && actor_id == 0x086) {
                //     // Create a new key actor definition for this specific instance
                //     struct KeyActor *new_key = (struct KeyActor *)recomp_alloc(sizeof(struct KeyActor));
                //     if (new_key != NULL) {
                //         // Set up the key actor parameters as specified
                //         new_key->actor_id = 0x0193;        // Key actor ID
                //         new_key->padding1 = 0x0000;        // Padding
                //         new_key->enemies = 0x0000;         // No enemies required
                //         new_key->padding2 = 0x0000;        // Padding
                //         new_key->key_index = 0x0110;       // Key index 0110
                //         new_key->padding3 = 0x0000;        // Padding
                //         new_key->padding4 = 0x00000000;    // Padding

                //         // Update this instance to point to the new definition
                //         actor_instance->actor_definition = (struct ActorDefinition *)new_key;

                //         recomp_printf("Actor conversion in room 009: 0x086 -> 0x193 Key (instance %d)\n", overall_index);
                //     }
                // }

                // Check for specific actor conversion in room 164: actor 088 -> key 193
                if (D_800C7AB2 == 0x164 && actor_id == 0x088)
                {
                    // Create a new key actor definition for this specific instance
                    struct KeyActor *new_key = (struct KeyActor *)recomp_alloc(sizeof(struct KeyActor));
                    if (new_key != NULL)
                    {
                        // Set up the key actor parameters as specified
                        new_key->actor_id = 0x0193;     // Key actor ID
                        new_key->padding1 = 0x0000;     // Padding
                        new_key->enemies = 0x0000;      // No enemies required
                        new_key->padding2 = 0x0000;     // Padding
                        new_key->key_index = 0x01b5;    // Key index 01b5
                        new_key->padding3 = 0x0000;     // Padding
                        new_key->padding4 = 0x00000000; // Padding

                        // Update this instance to point to the new definition
                        actor_instance->actor_definition = (struct ActorDefinition *)new_key;

                        recomp_printf("Actor conversion in room 164: 0x088 -> 0x193 Key (instance %d)\n", overall_index);
                    }
                }
                // Flag processing logic can be added here
            }
        }
    }
}