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

void process_flag_actors(struct ActorInstance *actor_instance, struct ActorDefinition *resolved_actor_def, unsigned short actor_id, unsigned short actor_data_file_id, int overall_index)
{

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