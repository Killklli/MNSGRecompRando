#ifndef INGAME_FLAGS_H
#define INGAME_FLAGS_H

#include "modding.h"
#include "types.h"

// Function declarations for flag operations
RECOMP_PATCH s32 func_800240DC_24CDC(s32 flag_id);
RECOMP_PATCH void func_80024038_24C38(s32 flag_id);
RECOMP_PATCH void func_80024088_24C88(int bit_index);

#endif // INGAME_FLAGS_H