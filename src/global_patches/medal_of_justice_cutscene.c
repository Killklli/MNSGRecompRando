// Patches the cutscene so we check for the flag instead of the item
#include "types.h"
#include "common_structs.h"
#include "Archipelago.h"
typedef struct Obj Obj;

// Unknown "actor" layout; only offsets used here are modeled.
typedef struct Actor {
    u8  pad_00[0x8A];
    u16 timer_8A;     // +0x8A
    u8  pad_8C[0xD0 - 0x8C];
    u8  state_D0;     // +0xD0
    u8  pad_D1[0x04 - 0x01];
    Obj*     obj_D4;       // +0xD4 (because code uses *(D0+4))
} Actor;

extern void  func_800124A0_130A0(Obj* obj, float v);
extern void  func_800124AC_130AC(Obj* obj, float v);
extern void  func_80012518_13118(Obj* obj, float a1, float a2, float a3);
extern void  func_80012628_13228(Obj* obj, float a1, float a2, float a3);
extern int   func_80012380_12F80(Obj* obj);

extern int   func_800240DC_24CDC(int id);
extern void  func_8003D388_3DF88(int id, int a1);

extern int   func_8003F1D8_3FDD8(void);

extern void  func_8022026C_5DB73C(Actor* self, int r, int g, int b);
extern int   func_802201F0_5DB6C0(Actor* self);
extern int   func_80220148_5DB618(Actor* self);

extern void  func_80038BC8_397C8(int id);

extern void  func_8003521C_35E1C(void (*fn)(void));
extern void  func_08000448_724948(void);

extern s32 D_8015C6DC;

RECOMP_PATCH void func_0800017C_72467C(Actor* self, void* unused_a1) {
    (void)unused_a1;

    Obj* obj = self->obj_D4;

    switch (self->state_D0) {
        case 0: {
            // If timer == 0x14, kick off a sequence of parameter sets.
            if (self->timer_8A == 0x14) {
                func_800124A0_130A0(obj, 25.0f);
                func_800124AC_130AC(obj, 5120.0f);
                func_80012518_13118(obj, 5.0f, -6.0f, -59.0f);
                func_80012628_13228(obj, 1.0f, 16.0f, -190.0f);
            }

            // Once timer >= 0x14, wait for func_80012380 to become 0, then advance state.
            if (self->timer_8A >= 0x14) {
                if (func_80012380_12F80(obj) == 0) {
                    self->timer_8A = 0;
                    self->state_D0 = 1;
                }
            }
        } break;

        case 1: {
            // On first tick of this state, configure & maybe play a sound.
            if (self->timer_8A == 1) {
                func_800124A0_130A0(obj, 150.0f);
                func_80012518_13118(obj, 5.0f, 18.0f, -55.0f);
                func_80012628_13228(obj, 1.0f, 41.0f, -186.0f);

                // If check(0x13) fails, play sound/effect 0x1ED.
                if (func_800240DC_24CDC(0x13) == 0) {
                    func_8003D388_3DF88(0x1ED, 1);
                }
            }

            // Gate: if global condition is true AND obj still “busy”, stay in state 1.
            if (func_8003F1D8_3FDD8() != 0) {
                if (func_80012380_12F80(obj) != 0) {
                    break; // just fall through to timer increment
                }
            }

            // Otherwise advance to state 2.
            self->timer_8A = 0;
            self->state_D0 = 2;
        } break;

        case 2: {
            // On first tick: set color-ish params and trigger something (0x108).
            if (self->timer_8A == 1) {
                func_8022026C_5DB73C(self, 0xFF, 0xFF, 0xFF);
                func_80038BC8_397C8(0x108);
            }

            // Wait until func_802201F0 returns 0, then advance.
            if (func_802201F0_5DB6C0(self) == 0) {
                self->timer_8A = 0;
                self->state_D0 = 3;
            }
        } break;

        case 3: {
            // Don’t do anything until timer >= 0x32.
            if (self->timer_8A < 0x32) {
                break;
            }

            // Then wait for func_80220148 to return 0; when it does, play one of two ids and advance.
            if (func_80220148_5DB618(self) == 0) {
                // PATCHED HERE so we check the flag instead of the item
                if (func_800240DC_24CDC(0x13) == 1) {
                    func_8003D388_3DF88(0x1ED, 1);
                } else {
                    func_8003D388_3DF88(0x82, 1);
                }
                self->timer_8A = 0;
                self->state_D0 = 4;
            }
        } break;

        case 4: {
            // If global condition is nonzero, do nothing this tick.
            if (func_8003F1D8_3FDD8() != 0) {
                break;
            }

            // Otherwise, after 0x1E ticks, enqueue/call a function pointer and reset timer.
            if (self->timer_8A >= 0x1E) {
                func_8003521C_35E1C(func_08000448_724948);
                self->timer_8A = 0;
            }
        } break;

        default:
            break;
    }

    // Always increment timer at end of function (matches tail block).
    self->timer_8A = (u16)(self->timer_8A + 1);
}
