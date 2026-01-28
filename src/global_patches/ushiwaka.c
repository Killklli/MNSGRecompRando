#include "libc/stdbool.h"
#include "libc/stdint.h"
#include "modding.h"
#include "recomputils.h"
#include "types.h"

extern s32 func_800240DC_24CDC(s32 id);

extern void func_08001B44_7189E4(void* obj, int mode);
extern s32 D_8015C718;

// Walking away animation patch to prevent ushiwaka from fleeing
RECOMP_PATCH void func_080001DC_71707C(void* obj /* a0 */, void* a1_unused /* a1 */)
{
    (void)a1_unused;

    // We commented out this block in what disables ushiwaka from running away
    // if (check(0x0A) && !check(0x31)) { func_08001B44(obj, 1); return; }
    // if (func_800240DC_24CDC(0x0A) != 0) {
    //     if (func_800240DC_24CDC(0x31) == 0) {
    //         func_08001B44_7189E4(obj, 1);
    //         return;
    //     }
    // }

    // if (check(0x2A)) {
    //     if (D_8015C718 >= 8) { func_08001B44(obj, 0); return; }
    //     else                 { func_08001B44(obj, 2); return; }
    // } else {
    //     func_08001B44(obj, 2); return;
    // }
    if (func_800240DC_24CDC(0x2A) != 0) {
        if (D_8015C718 >= 8) {
            func_08001B44_7189E4(obj, 0);
            return;
        }
        // falls through to mode 2
    }

    func_08001B44_7189E4(obj, 2);
}


extern void* D_8015C5C8_15D1C8;

extern void* func_800148F0_154F0(void* src, int len);
extern void  func_80034ED4_35AD4(void);

extern void  func_08002604_7194A4(void* obj);
extern void  func_080028B4_719754(void* obj);

extern void  func_80221C0C_5DD0DC(void* obj, int a1, float a2, int a3);
extern void  func_80221A90_5DCF60(void* obj);
extern void  func_80218DA8_5D4278(void* obj, int a1, int a2, int a3);
extern void func_8003521C_35E1C(void *callback);
extern const float D_08003634_71A4D4;


static inline void  store_u32(void* base, u32 off, u32 v)   { *(u32*)((u8*)base + off) = v; }
static inline void  store_u16(void* base, u32 off, u16 v)   { *(u16*)((u8*)base + off) = v; }
static inline void  store_u8 (void* base, u32 off, u8  v)   { *(u8 *)((u8*)base + off) = v; }
static inline void  store_f32(void* base, u32 off, float v) { *(float*)((u8*)base + off) = v; }




// Patch to disable ushiwaka from despawning in the fishing room
RECOMP_PATCH void func_08000000_716EA0(void* obj /* a0 */, void* cfg /* a1 */)
{
    // Early gate:
    // if (check(0x28) != 0 && check(0x31) == 0) { func_80034ED4(); return; }
    // if (func_800240DC_24CDC(0x28) != 0) {
    //     if (func_800240DC_24CDC(0x31) == 0) {
    //         func_80034ED4_35AD4();
    //         return;
    //     }
    // }

    // Read global base pointer, add 0x000C7FA4, copy/alloc 0x14 bytes.
    // v0 stored at obj+0xD0; if null => fallback and return.
    {
        // asm does: a0 = *(u32*)&D_8015C5C8_15D1C8; a0 += 0xC7FA4;
        // (treating global as a raw pointer value)
        u8* base = (u8*)(uintptr_t)(*(u32*)(void*)&D_8015C5C8_15D1C8);
        void* p = func_800148F0_154F0(base + 0x000C7FA4, 0x14);
        store_u32(obj, 0xD0, (u32)(uintptr_t)p);
        if (p == 0) {
            func_80034ED4_35AD4();
            return;
        }
    }

    // If check(0x0A) OR check(0x28), write a bunch of floats into cfg (a1).
    if (func_800240DC_24CDC(0x0A) != 0 || func_800240DC_24CDC(0x28) != 0) {
        const float f0 = D_08003634_71A4D4;

        store_f32(cfg, 0x24, f0);
        store_f32(cfg, 0x20, f0);
        store_f32(cfg, 0x1C, f0);

        store_f32(cfg, 0x08, -6.0f);
        store_f32(cfg, 0x0C, 21.0f);
        store_f32(cfg, 0x10, -107.0f);
    }

    // If any of {0x2A, 0x2B, 0x2C} is set, call func_08002604(obj).
    if (func_800240DC_24CDC(0x2A) != 0 ||
        func_800240DC_24CDC(0x2B) != 0 ||
        func_800240DC_24CDC(0x2C) != 0)
    {
        func_08002604_7194A4(obj);
    }

    // Always call this after:
    func_080028B4_719754(obj);

    // obj->(u16 at +0x5E) = 0x028F
    store_u16(obj, 0x5E, 0x028F);

    // func_80221C0C(obj, 0, 0.25f, 1)
    func_80221C0C_5DD0DC(obj, 0, 0.25f, 1);

    // func_80221A90(obj)
    func_80221A90_5DCF60(obj);

    // obj->(u8 at +0x99) = 8
    store_u8(obj, 0x99, 8);

    // If check(0x0A) OR check(0x28):
    //   func_80218DA8(obj, 0x1388, 0x64, 0);
    //   obj->(u8 at +0x6E) = 2;
    if (func_800240DC_24CDC(0x0A) != 0 || func_800240DC_24CDC(0x28) != 0) {
        func_80218DA8_5D4278(obj, 0x1388, 0x64, 0);
        store_u8(obj, 0x6E, 2);
    }

    // Register callback / something similar
    func_8003521C_35E1C(func_080001DC_71707C);
}
