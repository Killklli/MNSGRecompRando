// Patches the warp to Oedo Town so it does not put you above the map
#include "common.h"
#include "modding.h"
#include "recomputils.h"

// External data references - using original symbol names
extern u16 D_8006D410_6E010[]; // Warp location data array
extern u32 D_8015C5C8_15D1C8;  // Game heap pointer address

// External function declarations
extern void func_80003728_4328(u32 mode);

RECOMP_HOOK("func_8003731C_37F1C")
void func_8003731C_37F1C(u32 arg0)
{

    // Update the first warp entry (index 0) to warp to room 0x1D1 with position data
    D_8006D410_6E010[0] = 0x1D1;  // Room ID
    D_8006D410_6E010[1] = 0x0000; // X position
    D_8006D410_6E010[2] = 0x0000; // Y position
    D_8006D410_6E010[3] = 0x0000; // Z position
    D_8006D410_6E010[4] = 0x0000; // Camera rotation
    D_8006D410_6E010[5] = 0x0000; // Player rotation
}