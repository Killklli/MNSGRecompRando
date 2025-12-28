#include "actor_common.h"

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

void process_key_actors(struct ActorInstance *actor_instance, struct ActorDefinition *resolved_actor_def, unsigned short actor_id, unsigned short actor_data_file_id, int overall_index)
{
    // Check for key actor (0x193) and handle it with struct
    if (actor_id == 0x193)
    {
        // Cast the actor definition to our key struct
        struct KeyActor *key = (struct KeyActor *)resolved_actor_def;
        // Key processing logic can be added here
    }
}