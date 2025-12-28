#include "types.h"
#include "modding.h"
#include "recomputils.h"
#include "libc/stdbool.h"

// External data declarations
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
