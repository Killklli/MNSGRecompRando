// Clears the demo cutscenes out that play at the start of the game in the main menu
// This prevents some weird things that can happen when you're editing enemies and entities.
#include "modding.h"

// Function pointer table at D_80058908_59508
extern void *D_80058908_59508[];

RECOMP_HOOK("func_80002040_2C40")
void intro_animation_patch() {
    static bool table_patched = false;
    if (!table_patched) {
        extern void func_80002938_3538(void);
        D_80058908_59508[7] = (void *)func_80002938_3538; // Replace func_80002A98_3698 with func_80002938_3538
        table_patched = true;
    }
}