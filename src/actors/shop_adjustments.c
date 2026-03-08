#include "actor_common.h"
#include "common_structs.h"
#include "entities.h"

void adjust_shops(ActorInstance *actor_instance, ActorDefinition *resolved_actor_def, unsigned short actor_id, unsigned short actor_data_file_id, int overall_index) {
    // Check if this is a shop wares entity (ENTITY_SHOP_WARES = 0x08a)
    if (actor_id == ENTITY_SHOP_WARES) {
        // Test in room 0x191
        extern unsigned short D_800C7AB2; // Current stage ID
        
        if (D_800C7AB2 == 0x191) {
            // Print all data to understand the structure
            recomp_printf("Shop Wares in room 0x191, instance %d:\n", overall_index);
            recomp_printf("  actor_id: 0x%04x\n", actor_id);
            recomp_printf("  data[0]: 0x%08x\n", resolved_actor_def->data[0]);
            recomp_printf("  data[1]: 0x%08x\n", resolved_actor_def->data[1]);
            recomp_printf("  data[2]: 0x%08x\n", resolved_actor_def->data[2]);
            recomp_printf("  data[3]: 0x%08x\n", resolved_actor_def->data[3]);
            recomp_printf("  position: (%d, %d, %d)\n", actor_instance->position.x, actor_instance->position.y, actor_instance->position.z);
            
            // Change all shop items to the same item (item_type 0x06 - Rice Ball / Rice Crackers)
            // The item_type is in the lower 16 bits of data[2]
            // Keep data[3] unchanged as it contains the selection/menu index
            // resolved_actor_def->data[2] = (resolved_actor_def->data[2] & 0xFFFF0000) | 0x0006;
            
            // recomp_printf("  Modified data[2]: 0x%08x\n", resolved_actor_def->data[2]);
        }
    }
}
