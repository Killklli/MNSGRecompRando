#include "actor_common.h"
#include "common_structs.h"
#include "save_data_tool.h"

void adjust_pot_contents(ActorInstance *actor_instance,
                          ActorDefinition *resolved_actor_def,
                          unsigned short actor_id,
                          unsigned short actor_data_file_id,
                          int overall_index)
{
  // Check if this is a pot entity (0x192)
  if (actor_id == 0x192) {
    // Extract the current spawn count from data[1] upper 16 bits
    unsigned int current_spawn_count = (resolved_actor_def->data[1] >> 16) & 0xFFFF;
    
    // If current spawn count is 4, change it to 15
    if (current_spawn_count == 4) {
      // Preserve the lower 16 bits and set upper 16 bits to 15
      resolved_actor_def->data[1] = (resolved_actor_def->data[1] & 0x0000FFFF) | (15 << 16);
    }
  }
}
