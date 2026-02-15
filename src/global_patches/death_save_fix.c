// Disables copying the default save data to the player save when we start a file.
#include "modding.h"
#include "Archipelago.h"

extern void func_8000B5D0_C1D0(void);
RECOMP_PATCH void func_8000B6E0_C2E0(void){
    func_8000B5D0_C1D0();
}