#include "common.h"
#include "Archipelago.h"
// External function declarations  
extern s32 func_800240DC_24CDC(s32);  // Check if flag is set
extern void func_80218D7C_5D424C(void*, s32, s32, s32);  // Set entity properties
extern void func_8021664C_5D1B1C(void*, s32, s32, s32);  // Set entity animation/state
extern void func_80218DCC_5D429C(void*, s32);  // Set entity state
extern void func_80219E08_5D52D8(void*, f32);  // Set entity float property
extern f32 func_80003E10_4A10(u16);  // Returns float calculation
extern void* func_8021DF60_5D9430(void*, s32, s32, s32, s32);  // Create/configure object
extern void* func_802171A8_5D2678(void*, void*, s32);  // Create child object
extern void* func_800141C4_14DC4(s32);  // Allocate memory
extern void func_8003521C_35E1C(void*);  // Set callback function

// Forward declarations
void func_08002DBC_6FDFBC(void*, void*);
void func_08003074_6FE274(void*, void*);

// Global constants
extern f64 D_08003828_6FEA28;  // 130.0

/**
 * Function: func_08002E28_6FE028
 * Main entity initialization function
 */
RECOMP_PATCH void func_08002E28_6FE028(void* arg0, void* arg1) {
    u32* entity = (u32*)arg0;
    f32* data = (f32*)arg1;
    u32 temp_flags;
    void* child_obj;
    void* allocated_obj;
    f32 calc_result;
    f64 double_calc;
    s32 int_result;
    
    // Check if bit 2 is set in offset 0xD8
    temp_flags = entity[0xD8 / 4];
    if (temp_flags & 0x2) {
        // Check if flag 0x1A4 is set
        // if (func_800240DC_24CDC(0x1A4) == 0) {
        //     return;  // Early exit if flag not set
        // }
    }
    
    // Set up entity properties
    entity[0x60 / 4] = 0x80000260;  // Set address/pointer
    *(u8*)((u8*)entity + 0x8D) = 0x32;  // Set byte value
    *(u16*)((u8*)entity + 0x5E) = 0x1F9;  // Set short value
    
    // Modify flags - set bit 0x4000
    temp_flags = entity[0x64 / 4];
    entity[0x64 / 4] = temp_flags | 0x4000;
    
    *(u8*)((u8*)entity + 0x6C) = 0;  // Clear byte
    
    // Call entity setup function
    func_80218D7C_5D424C(entity, 0x14, 0xA, -5);
    
    // Set entity animation/state
    func_8021664C_5D1B1C(entity, 2, 0, 2);
    
    // Set entity state
    func_80218DCC_5D429C(entity, 3);
    
    // Set entity float property (10.0f = 0x41200000)
    func_80219E08_5D52D8(entity, 10.0f);
    
    // Set flag
    *(u8*)((u8*)entity + 0x4C) = 1;
    
    // Convert float coordinates to short values and store them
    *(s16*)((u8*)entity + 0xC8) = (s16)data[2];  // Convert data[2] to short
    *(s16*)((u8*)entity + 0xCA) = (s16)data[3];  // Convert data[3] to short  
    *(s16*)((u8*)entity + 0xCC) = (s16)data[4];  // Convert data[4] to short
    
    // Modify coordinate values by subtracting 0x8000
    *(u16*)((u8*)entity + 0xD0) = *(u16*)((u8*)entity + 0xD0) - 0x8000;
    *(u16*)((u8*)entity + 0xD2) = *(u16*)((u8*)entity + 0xD2) - 0x8000;
    *(u16*)((u8*)entity + 0xD4) = *(u16*)((u8*)entity + 0xD4) - 0x8000;
    *(u16*)((u8*)entity + 0xD6) = *(u16*)((u8*)entity + 0xD6) - 0x8000;
    
    // Call calculation function
    calc_result = func_80003E10_4A10(*(u16*)((u8*)entity + 0xE0));
    
    // Perform double precision calculation: calc_result * 0.0 + 130.0
    // The assembly multiplies by f6 (which is 0), not f7 (which is PI)
    double_calc = (f64)calc_result * 0.0 + D_08003828_6FEA28;
    
    // Create/configure object with calculated value
    int_result = (s32)double_calc;
    *(void**)((u8*)data + 0x30) = func_8021DF60_5D9430(entity, 0x80, 0xFF, int_result, 0);
    
    // Create child object
    child_obj = func_802171A8_5D2678(entity, func_08002DBC_6FDFBC, 2);
    
    if (child_obj != NULL) {
        // Set child object properties
        *(u16*)((u8*)child_obj + 0x28) = 0x2C;  // Set short value
        
        // Allocate memory
        allocated_obj = func_800141C4_14DC4(0x2C);
        *(void**)((u8*)child_obj + 0x2C) = allocated_obj;  // Store pointer
        
        *(u16*)((u8*)child_obj + 0x5E) = 0x1F9;  // Set short value
        
        // Copy float value from data[7] to multiple locations in allocated object
        f32 scale_val = data[7];  // data[7] is at offset 0x1C
        void* obj_data = *(void**)((u8*)child_obj + 0x18);
        *(f32*)((u8*)obj_data + 0x24) = scale_val;
        *(f32*)((u8*)obj_data + 0x20) = scale_val;
        *(f32*)((u8*)obj_data + 0x1C) = scale_val;
        
        // Copy coordinates from data to child object
        *(f32*)((u8*)child_obj + 0xD0) = data[2];  // X coordinate
        *(f32*)((u8*)child_obj + 0xD4) = data[3];  // Y coordinate
        *(f32*)((u8*)child_obj + 0xD8) = data[4];  // Z coordinate
        
        // Store child object pointer in entity
        entity[0x9C / 4] = (u32)child_obj;
    }
    
    // Check if bit 1 is set in entity flags
    temp_flags = entity[0xD8 / 4];
    if (temp_flags & 0x1) {
        // Set value at offset 0xE2
        *(u16*)((u8*)entity + 0xE2) = 5;
    }
    
    // Set callback function
    func_8003521C_35E1C(func_08003074_6FE274);
}