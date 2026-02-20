#include "libc/stdbool.h"
#include "modding.h"
#include "recomputils.h"
#include "types.h"

// External function declarations
extern s32 func_800240DC_24CDC(s32 id);                                             // Check flag/state function
extern void func_80216DF8_5D22C8(void *entity, s32 value);                          // Entity state setup
extern void func_80218DA8_5D4278(void *entity, s32 param1, s32 param2, s32 param3); // Entity parameter setup
extern void func_8003521C_35E1C(void (*callback)(void));                            // Set callback function
extern void func_08001874_6C0FC4(void);                                             // Forward declaration for callback

// External data declarations
extern f32 D_080089CC_6C811C; // Float constant 0.200000003

/**
 * Function: func_0800178C_6C0EDC
 * Purpose: Entity initialization with conditional behavior based on flag check
 *
 * This function checks a flag (0x1A3) and performs different initialization:
 * - If flag is set: Sets bit 0x2 in entity flags at offset 0x68
 * - If flag is not set:
 *   - Sets up entity state with values 0x3D3, 0x2006E1, 0x8 at specific offsets
 *   - Calls entity parameter setup function
 *   - Sets up float values in the data structure
 *   - Registers a callback function
 *
 * @param entity - Primary entity pointer for manipulation
 * @param data - Secondary data structure pointer for float value setup
 */
RECOMP_PATCH void func_0800178C_6C0EDC(void *entity, void *data) {
    s32 flag_result;
    u32 current_flags;

    // Check flag 0x1A3 (419 decimal)
    flag_result = func_800240DC_24CDC(0x1A3);

    if (flag_result != 0) {
        // Flag is set - just set bit 0x2 in entity flags
        current_flags = *(u32 *)((u8 *)entity + 0x68);
        current_flags |= 0x2;
        *(u32 *)((u8 *)entity + 0x68) = current_flags;
    } else {
        // Flag is not set - perform full initialization
        // PATCH IS UPDATING THE ENITY ID
        // Set up entity state values
        *(s16 *)((u8 *)entity + 0x5E) = 0x091;    // Set field at 0x5E to 0x3D3 (979)
        *(u32 *)((u8 *)entity + 0x60) = 0x2006E1; // Set field at 0x60 to 0x2006E1
        *(u8 *)((u8 *)entity + 0x4C) = 0x8;       // Set field at 0x4C to 0x8

        // Call entity state setup function
        func_80216DF8_5D22C8(entity, 0);

        // Call entity parameter setup function with specific values
        func_80218DA8_5D4278(entity, 0x1F4, 0x19, 0); // 0x1F4 = 500, 0x19 = 25

        // PATCH IS UPDATING THESE VALUES TO A SMALLER VALUE
        // Set up float values in data structure
        // All using the same constant 0.200000003
        *(f32 *)((u8 *)data + 0x1C) = 0.025f; // 0.200000003f
        *(f32 *)((u8 *)data + 0x20) = 0.025f; // 0.200000003f
        *(f32 *)((u8 *)data + 0x24) = 0.025f; // 0.200000003f

        // Set up specific float values
        *(f32 *)((u8 *)data + 0x8) = -99.0f;  // 0xC2C60000
        *(f32 *)((u8 *)data + 0xC) = -59.0f;  // 0xC26C0000
        *(f32 *)((u8 *)data + 0x10) = -38.0f; // 0xC2180000

        // Register callback function
        func_8003521C_35E1C(func_08001874_6C0FC4);
    }
}
