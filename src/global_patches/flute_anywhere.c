#include "recomputils.h"
#include "types.h"

// External data references
extern u32 D_8015C5C8_15D1C8; // Pointer/base address value

RECOMP_PATCH s32 func_80037284_37E84(void) {
    u32 base_addr = D_8015C5C8_15D1C8;

    // Read byte value at base + 0x3ADE4 offset
    u8 state_value = *(u8 *)(base_addr + 0x3ADE4);

    // Normal Behavior, this is what checks what room you're in, by disabling it
    // you can warp from anywhere Check if state value is 1 or 2 if (state_value
    // != 1 && state_value != 2) {
    //     return 0;
    // }

    // Set flag to 0x80 at base + 0x3AE29 offset
    *(u8 *)(base_addr + 0x3AE29) = 0x80;
    // Set value to 0x226 at base + 0x3AFE0 offset
    *(u16 *)(base_addr + 0x3AFE0) = 0x226;
    return 1;
}
