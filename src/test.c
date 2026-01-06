#include "types.h"
#include "modding.h"
#include "apconnect_ui.h"
#include "recomputils.h"
#include "save_data_tool.h"
#include "entities.h"


// void func_80216E1C_5D22EC(void* entity, s32 param) {
//     void* object;
    
//     // Get object from entity at offset 0x18
//     object = *(void**)((u8*)entity + 0x18);
    
//     // Set three float values to 0.1
//     *(f32*)((u8*)object + 0x1C) = D_8023A510_5F59E0; // 0.1f
//     *(f32*)((u8*)object + 0x20) = D_8023A510_5F59E0; // 0.1f
//     *(f32*)((u8*)object + 0x24) = D_8023A510_5F59E0; // 0.1f
    
//     // Call another function with original parameters
//     func_80216CE0_5D21B0(entity, param);
// }
// extern float D_8023A510_5F59E0;
// RECOMP_HOOK("func_80216E1C_5D22EC") void func_80216E1C_5D22EC_hook(void* entity, s32 param) {
//     u8* entity_bytes = (u8*)entity;
//     // If the entity id is 0x0088, change it to 0x0193
//     recomp_printf("Checking entity type at +0x5E: 0x%04X\n", *(u16*)(entity_bytes + 0x5E));
//     if (*(u16*)(entity_bytes + 0x5E) == 0x01F4) {
//         recomp_printf("Changing entity type from 0x0088 to 0x0193\n");
//         *(u16*)(entity_bytes + 0x5E) = 0x079;
//     }
// }
RECOMP_HOOK("func_80024038_24C38") void func_80024038_24C38_hook(s32 flag){
    recomp_printf("func_80024038_24C38_hook called with flag value: 0x%08X\n", flag);
}
// D_800C7AB2
extern u16 D_800C7AB2;
static u16 prev_D_800C7AB2 = 0;
static bool first_call = true;

RECOMP_HOOK("func_80002040_2C40") void func_80002040_2C40_hook() {
    u16 current_value = D_800C7AB2;
    
    if (first_call) {
        prev_D_800C7AB2 = current_value;
        first_call = false;
        recomp_printf("D_800C7AB2 initial value: 0x%04X\n", current_value);
    } else if (current_value != prev_D_800C7AB2) {
        recomp_printf("D_800C7AB2 changed from 0x%04X to 0x%04X\n", prev_D_800C7AB2, current_value);
        prev_D_800C7AB2 = current_value;
    }
}

// extern void func_80216CE0_5D21B0(void* entity, s32 param);
// RECOMP_PATCH void func_80216E1C_5D22EC(void* entity, s32 param) {
//     void* object;
//     u8* entity_bytes = (u8*)entity;
    
//     // CHANGE ENTITY TYPE FROM 0x0079 TO 0x0193
//     recomp_printf("CHANGING ENTITY: Original entity at +0x5E: 0x%04X, at +0x5C: 0x%08X\n", 
//                   *(u16*)(entity_bytes + 0x5E), *(u32*)(entity_bytes + 0x5C));
    
//     // Set entity type to 0x0193 at both locations
//     *(u16*)(entity_bytes + 0x5E) = 0x0193;
//     *(u32*)(entity_bytes + 0x5C) = 0x0193; // This might also need to be set
    
//     recomp_printf("CHANGED ENTITY: New entity at +0x5E: 0x%04X, at +0x5C: 0x%08X\n", 
//                   *(u16*)(entity_bytes + 0x5E), *(u32*)(entity_bytes + 0x5C));
    
//     // COMPREHENSIVE ENTITY DEBUGGING AFTER CHANGE
//     debug_entity_extensive(entity, "func_80216E1C_5D22EC_AFTER_CHANGE");
    
//     // Get object from entity at offset 0x18
//     object = *(void**)((u8*)entity + 0x18);
    
//     if (object != NULL) {
//         u8* obj_bytes = (u8*)object;
        
//         // SIZE CONTROL EXPERIMENTS
//         recomp_printf("\n========== SIZE CONTROL EXPERIMENTS ==========\n");
        
//         // Original values for comparison
//         recomp_printf("ORIGINAL OBJECT VALUES:\n");
//         recomp_printf("obj+0x08 (float): %f (hex: 0x%08X)\n", *(f32*)(obj_bytes + 0x08), *(u32*)(obj_bytes + 0x08));
//         recomp_printf("obj+0x0C (float): %f (hex: 0x%08X)\n", *(f32*)(obj_bytes + 0x0C), *(u32*)(obj_bytes + 0x0C));
//         recomp_printf("obj+0x10 (float): %f (hex: 0x%08X)\n", *(f32*)(obj_bytes + 0x10), *(u32*)(obj_bytes + 0x10));
//         recomp_printf("obj+0x1C (float): %f (hex: 0x%08X)\n", *(f32*)(obj_bytes + 0x1C), *(u32*)(obj_bytes + 0x1C));
//         recomp_printf("obj+0x20 (float): %f (hex: 0x%08X)\n", *(f32*)(obj_bytes + 0x20), *(u32*)(obj_bytes + 0x20));
//         recomp_printf("obj+0x24 (float): %f (hex: 0x%08X)\n", *(f32*)(obj_bytes + 0x24), *(u32*)(obj_bytes + 0x24));
        
//         // Test different size values - these might be scale factors
//         // obj+0x08 was 0x42CA0000 (101.0f) - might be X position or scale
//         // obj+0x0C was 0xC2800000 (-64.0f) - might be Y position or scale  
//         // obj+0x10 was 0x41A00000 (20.0f) - might be Z position or scale
        
//         // Try setting different scale values to see what affects size
//         *(f32*)(obj_bytes + 0x1C) = 0.1f;  // Try 2x scale
//         *(f32*)(obj_bytes + 0x20) = 0.1f;  // Try 2x scale
//         *(f32*)(obj_bytes + 0x24) = 0.1f;  // Try 2x scale
        
//         // COORDINATE MODIFICATION: Change X coordinate from 101.0f to 80.0f
//         *(f32*)(obj_bytes + 0x08) = 40.0f;  // Change X coordinate
        
//         // Also try modifying the other float values that might control size
//         // Test if obj+0x08, 0x0C, 0x10 affect scale instead of position
//         // *(f32*)(obj_bytes + 0x08) = 202.0f;  // Double the original 101.0f
//         // *(f32*)(obj_bytes + 0x0C) = -128.0f; // Double the original -64.0f
//         // *(f32*)(obj_bytes + 0x10) = 40.0f;   // Double the original 20.0f
        
//         recomp_printf("MODIFIED OBJECT VALUES:\n");
//         recomp_printf("obj+0x08 (X coord): %f\n", *(f32*)(obj_bytes + 0x08));
//         recomp_printf("obj+0x1C (scale?): %f\n", *(f32*)(obj_bytes + 0x1C));
//         recomp_printf("obj+0x20 (scale?): %f\n", *(f32*)(obj_bytes + 0x20));
//         recomp_printf("obj+0x24 (scale?): %f\n", *(f32*)(obj_bytes + 0x24));
        
//         recomp_printf("========== END SIZE CONTROL EXPERIMENTS ==========\n\n");
//     }
    
//     // Call another function with original parameters
//     func_80216CE0_5D21B0(entity, param);
// }


// External data declaration
extern u8 D_8015C608_15D208[];

RECOMP_PATCH s32 func_800240DC_24CDC(s32 flag_id) {
    s32 byte_index;
    s32 bit_index;
    u8 byte_value;
    s32 bit_mask;
    s32 result;
    // if the flag_id is 0x0 AND we have the save item for super pass return 1
    if (flag_id == 0) {
        s32 super_pass_value = READ_SAVE_DATA(SAVE_SUPER_PASS);
        if (super_pass_value != 0) {
            return 1;
        }
    }


    // Calculate byte index - divide by 8 with sign-aware right shift
    if (flag_id < 0) {
        byte_index = (flag_id + 7) >> 3;  // Add 7 before shifting for negative numbers
    } else {
        byte_index = flag_id >> 3;  // Simple right shift for positive numbers
    }
    
    // Mask to ensure byte_index is within u8 range
    byte_index &= 0xFF;
    
    // Load the byte from the data array
    byte_value = D_8015C608_15D208[byte_index];
    
    // Calculate bit position within the byte
    if (flag_id < 0) {
        bit_index = flag_id & 7;
        if (bit_index != 0) {
            bit_index -= 8;  // Adjust for negative numbers
        }
    } else {
        bit_index = flag_id & 7;
    }
    
    // Mask to ensure bit_index is within u8 range
    bit_index &= 0xFF;
    
    // Create bit mask by shifting 1 left by bit_index positions
    bit_mask = 1 << bit_index;
    
    // Check if the bit is set
    result = byte_value & bit_mask;
    
    // Mask result to u8 and return
    return result & 0xFF;
}