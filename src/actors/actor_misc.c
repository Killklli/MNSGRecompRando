#include "actor_common.h"

struct RyoActor
{
    unsigned short actor_id; // 0x082
    unsigned short padding1; // 0x0000
    unsigned char size;      // Size type (e.g., 0x01 = Normal)
    unsigned char padding2;  // 0x00
    unsigned short padding3; // 0x0000
    unsigned int padding4;   // 0x00000000
    unsigned int padding5;   // 0x00000000
}; // Size: 16

void process_misc_actors(struct ActorInstance *actor_instances, int regular_instance_count, int total_instances, 
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

            // Check for ryo actor (0x082) and handle it with struct
            if (actor_id == 0x082)
            {
                // Cast the actor definition to our ryo struct
                struct RyoActor *ryo = (struct RyoActor *)resolved_actor_def;
                // Ryo processing logic can be added here
            }

            // // Debug logging for new actor types to help format them
            // if (actor_id == 0x339)
            // {
            //     recomp_printf("=== NEW ACTOR 0x%03X FOUND ===\n", actor_id);
            //     recomp_printf("Instance %d (overall index %d)\n", overall_index < regular_instance_count ? overall_index : grouped_index - 1, overall_index);
            //     recomp_printf("Position: (%d, %d, %d)\n", actor_instance->position.x, actor_instance->position.y, actor_instance->position.z);
            //     recomp_printf("Rotation: (%d, %d, %d)\n", actor_instance->rotation.pitch, actor_instance->rotation.yaw, actor_instance->rotation.roll);
            //     recomp_printf("Actor Definition Pointer: %p\n", actor_instance->actor_definition);
            //     recomp_printf("Resolved Actor Definition Pointer: %p\n", resolved_actor_def);
            //     recomp_printf("Is Spawned: 0x%02X\n", actor_instance->is_spawned);
            //     recomp_printf("Unk fields: 0x%02X, 0x%02X, 0x%02X\n", actor_instance->unk_11, actor_instance->unk_12, actor_instance->unk_13);
            //     recomp_printf("Actor Definition Data:\n");
            //     recomp_printf("  data[0]: 0x%08X (Actor ID: 0x%03X, Lower: 0x%04X)\n", resolved_actor_def->data[0], actor_id, resolved_actor_def->data[0] & 0xFFFF);
            //     recomp_printf("  data[1]: 0x%08X\n", resolved_actor_def->data[1]);
            //     recomp_printf("  data[2]: 0x%08X\n", resolved_actor_def->data[2]);
            //     recomp_printf("  data[3]: 0x%08X\n", resolved_actor_def->data[3]);

            //     // Print raw bytes around the actor instance for additional context
            //     unsigned char *raw_instance = (unsigned char *)actor_instance;
            //     recomp_printf("Raw instance bytes (20 bytes):\n");
            //     recomp_printf("  ");
            //     for (int byte_i = 0; byte_i < 20; byte_i++)
            //     {
            //         recomp_printf("%02X ", raw_instance[byte_i]);
            //         if ((byte_i + 1) % 8 == 0)
            //             recomp_printf("\n  ");
            //     }
            //     recomp_printf("\n");

            //     // Print raw bytes of the actor definition
            //     unsigned char *raw_def = (unsigned char *)resolved_actor_def;
            //     recomp_printf("Raw definition bytes (16 bytes):\n");
            //     recomp_printf("  ");
            //     for (int byte_i = 0; byte_i < 16; byte_i++)
            //     {
            //         recomp_printf("%02X ", raw_def[byte_i]);
            //         if ((byte_i + 1) % 8 == 0)
            //             recomp_printf("\n  ");
            //     }
            //     recomp_printf("\n===============================\n");
            // }
        }
    }
}