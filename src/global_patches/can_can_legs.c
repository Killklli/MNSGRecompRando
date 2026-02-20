// Patches the Can Can Legs so if we end up outside of the valid memory range we just exit early.
#include "Archipelago.h"
#include "common.h"

// External function declarations
extern void func_8003521C_35E1C(void *func_ptr);                                   // Register function pointer
extern void func_8021664C_5D1B1C(void *entity, s32 param1, f32 scale, s32 param2); // Entity animation function
extern s32 func_802197D8_5D4CA8(void *entity, s32 param);                          // Entity check function
extern void func_8021C194_5D7664(void *entity, f32 param);                         // Entity scale function
extern f32 func_80003E10_4A10(u16 angle);                                          // Sine calculation
extern f32 func_80003EA0_4AA0(u16 angle);                                          // Cosine calculation
extern void func_8021ADD0_5D62A0(f32 param1, f32 param2, f32 param3);              // Position function
extern void func_8021BB04_5D6FD4(void *entity, f32 x, f32 z, f32 scale);           // Entity positioning function

// Forward declarations
void func_08003720_6D9670(void *entity, void *param2);

// Global constants
extern f64 D_08003F48_6D9E98; // 16.6
extern f64 D_08003F50_6D9EA0; // 16.6
extern f64 D_08003F58_6D9EA8; // 16.6
extern f64 D_08003F60_6D9EB0; // 16.6

/**
 * Function: func_080033BC_6D930C
 * Entity update function with state-based behavior
 */
RECOMP_PATCH void func_080033BC_6D930C(void *entity, void *param2) {
    u32 *entity_ptr = (u32 *)entity;
    void *linked_obj;
    void *data_obj;
    u8 state;
    u32 flags;
    f32 temp_f;
    f64 temp_d;
    s32 calc_result;
    u16 angle;
    f32 x_pos, z_pos;

    // Get linked object at offset 0xD0
    linked_obj = (void *)entity_ptr[0xD0 / 4];

    // Check if linked object exists and is a valid pointer
    if (linked_obj == NULL) {
        func_8003521C_35E1C(func_08003720_6D9670);
        return;
    }

    // Check if pointer looks valid (basic sanity check for N64 address space)
    u32 addr = (u32)linked_obj;
    if (addr < 0x80000000 || addr > 0x807FFFFF) {
        func_8003521C_35E1C(func_08003720_6D9670);
        return;
    }

    // Check if linked object has correct ID (0x104)
    u16 obj_id = *(u16 *)((u8 *)linked_obj + 0x5C);

    if (obj_id != 0x104) {
        // Register callback and exit
        func_8003521C_35E1C(func_08003720_6D9670);
        return;
    }

    // Get data object and state
    data_obj = *(void **)((u8 *)linked_obj + 0x18);
    state = *(u8 *)((u8 *)linked_obj + 0xDC);

    // Switch based on state (jump table cases 0-5)
    switch (state) {
    case 0:
        // Register callback and exit
        func_8003521C_35E1C(func_08003720_6D9670);
        return;

    case 1:
        // Set entity animation with scale 0x3F2AAAAB (~0.666667)
        func_8021664C_5D1B1C(entity, 0, *(f32 *)&(u32){0x3F2AAAAB}, 1);
        break;

    case 2:
        // Set entity animation with scale 0x3EAAAAAB (~0.333333)
        func_8021664C_5D1B1C(entity, 1, *(f32 *)&(u32){0x3EAAAAAB}, 1);
        break;

    case 3:
        // Set entity animation with scale 0x3EAAAAAB (~0.333333)
        func_8021664C_5D1B1C(entity, 1, *(f32 *)&(u32){0x3EAAAAAB}, 1);
        break;

    case 4:
        // Check entity state
        if (func_802197D8_5D4CA8(entity, 8) != 0) {
            return;
        }

        // Check entity flags at offset 0x68
        flags = entity_ptr[0x68 / 4];
        if (flags & 0x20) {
            return;
        }

        // Set entity scale based on D4 flag
        state = *(u8 *)((u8 *)entity + 0xD4);
        if (state != 0) {
            func_8021C194_5D7664(entity, 1.0f); // 0x3F800000
        } else {
            func_8021C194_5D7664(entity, 1.5f); // 0x3FC00000
        }

        // Update Y position
        temp_f = *(f32 *)((u8 *)entity + 0x7C);
        temp_d = (f64)temp_f + 3.0; // 0x40080000
        *(f32 *)((u8 *)entity + 0x7C) = (f32)temp_d;

        // Call positioning function
        func_8021ADD0_5D62A0(*(f32 *)((u8 *)entity + 0x78), *(f32 *)((u8 *)entity + 0x80), *(f32 *)((u8 *)entity + 0x7C));

        // Store result in param2
        *(u16 *)((u8 *)param2 + 0x16) = *(u16 *)((u8 *)data_obj + 0x16);
        return;

    case 5:
    default:
        break;
    }

    // Common processing for states 1, 2, 3, and 5
    state = *(u8 *)((u8 *)entity + 0xD4);

    if (state != 0) {
        // Calculate sine and cosine for movement
        angle = *(u16 *)((u8 *)data_obj + 0x16) + 0x100;

        // Calculate X movement using sine
        temp_f = func_80003E10_4A10(angle);
        temp_d = (f64)temp_f * D_08003F48_6D9E98; // * 16.6
        calc_result = (s32)temp_d;

        // Calculate Z movement using cosine
        temp_f = func_80003EA0_4AA0(angle);
        temp_d = (f64)temp_f * D_08003F50_6D9EA0; // * 16.6

        // Update position
        x_pos = *(f32 *)((u8 *)data_obj + 0x8) + (f32)calc_result;
        z_pos = *(f32 *)((u8 *)data_obj + 0x10) + (f32)((s32)temp_d);

        // Call positioning function with scale 2.0
        func_8021BB04_5D6FD4(entity, x_pos, z_pos, 2.0f); // 0x40000000

        // Copy angle back to param2
        *(u16 *)((u8 *)param2 + 0x16) = *(u16 *)((u8 *)data_obj + 0x16);
    } else {
        // Calculate sine and cosine for different movement pattern
        angle = *(u16 *)((u8 *)data_obj + 0x16) + 0x300;

        // Calculate X movement using sine
        temp_f = func_80003E10_4A10(angle);
        temp_d = (f64)temp_f * D_08003F58_6D9EA8; // * 16.6
        calc_result = (s32)temp_d;

        // Calculate Z movement using cosine
        temp_f = func_80003EA0_4AA0(angle);
        temp_d = (f64)temp_f * D_08003F60_6D9EB0; // * 16.6

        // Update position
        x_pos = *(f32 *)((u8 *)data_obj + 0x8) + (f32)calc_result;
        z_pos = *(f32 *)((u8 *)data_obj + 0x10) + (f32)((s32)temp_d);

        // Call positioning function with scale 5.0
        func_8021BB04_5D6FD4(entity, x_pos, z_pos, 5.0f); // 0x40A00000

        // Copy angle back to param2
        *(u16 *)((u8 *)param2 + 0x16) = *(u16 *)((u8 *)data_obj + 0x16);
    }
}