// Lowers the enemy kill count in ghost toys to prevent softlocking out of safety.
#include "libc/stdbool.h"
#include "modding.h"
#include "recomputils.h"
#include "types.h"

extern u8 D_8015CD68[];
extern void func_80038B98_39798(s32 sound_id);
extern void func_8003521C_35E1C(void (*callback)(void));
extern void func_080042F4_6F77D4(void);
RECOMP_PATCH void func_08004280_6F7760(s32 arg0, s32 arg1) {
    u8 cd_value;

    cd_value = *(u8 *)D_8015CD68;

    if (cd_value >= 2) {
        func_80038B98_39798(0x15E);

        // Set some values on the object
        *(s16 *)(arg0 + 0x8A) = 0x78;
        *(f32 *)(arg0 + 0x7C) = -0.5f;

        func_8003521C_35E1C(func_080042F4_6F77D4);
    }
}
