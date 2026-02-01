#include "libc/stdbool.h"
#include "modding.h"
#include "recomputils.h"
#include "types.h"
#include "ultra64.h"

// External data declarations
extern u16 D_800C7AB2;
static u16 prev_D_800C7AB2 = 0;
static bool first_call = true;

extern u8 D_8015C608_15D208[0x304];
static u8 prev_D_8015C608_15D208[0x304];
static bool first_call_memory = true;

RECOMP_HOOK("func_80002040_2C40")
void func_80002040_2C40_hook()
{
  u16 current_value = D_800C7AB2;

  if (first_call)
  {
    prev_D_800C7AB2 = current_value;
    first_call = false;
    recomp_printf("D_800C7AB2 initial value: 0x%04X\n", current_value);
  }
  else if (current_value != prev_D_800C7AB2)
  {
    recomp_printf("D_800C7AB2 changed from 0x%04X to 0x%04X\n", prev_D_800C7AB2,
                  current_value);
    prev_D_800C7AB2 = current_value;
  }
  
  // // Monitor D_8015C608_15D208 memory array
  // if (first_call_memory)
  // {
  //   // Initialize previous values on first call
  //   for (int i = 0; i < 0x304; i++)
  //   {
  //     prev_D_8015C608_15D208[i] = D_8015C608_15D208[i];
  //   }
  //   first_call_memory = false;
  // }
  // else
  // {
  //   // Check for changes in any byte
  //   for (int i = 0; i < 0x304; i++)
  //   {
  //     if (D_8015C608_15D208[i] != prev_D_8015C608_15D208[i])
  //     {
  //       if (i != 0x267)
  //       {
  //         recomp_printf("Position 0x%03X: 0x%02X\n", i, D_8015C608_15D208[i]);
  //       }
  //       prev_D_8015C608_15D208[i] = D_8015C608_15D208[i];
  //     }
  //   }
  // }
}
