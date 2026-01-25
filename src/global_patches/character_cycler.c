// This file handles a patch to the character cycler to skip Goemon if you don't
// have him
#include "common.h"
#include "recomputils.h"

// External function declaration
extern void func_801DD5C0_5994D0(void *arg0, u8 value);

// Data structure pointers
extern u32 D_8015C608_15D208[];
extern u32 D_8015C5D8_15D1D8[];

RECOMP_PATCH int func_801DD50C_59941C(void *arg0)
{
  u8 value = *(u8 *)(arg0 + 0x60);   // lbu $a3, 0x60($a0)
  u32 *data_ptr = (u32 *)0x8015C608; // D_8015C608_15D208
  int i = 1;                         // $a1 = 1
  int max_count = 4;                 // $a2 = 4
  int index = -1;                    // $t0 = -1 (default)

  // Main loop starting at 801DD538
  do
  {
    // This here patches the character cycler to skip if we're missing Goemon
    int test_value = value + i;          // $v1 = $a3 + $a1
    int selected_index = test_value & 3; // Force wrap to 0-3 range

    // Check if data at this index is non-zero
    if (data_ptr[0x94 / 4 + selected_index] != 0)
    { // lw $t8, 0x94($t7)
      index = selected_index;
      break;
    }

    i++; // addiu $a1, $a1, 0x1
  } while (i != max_count); // bnel $a1, $a2, loop

  if (index >= 0)
  {
    *(u8 *)(arg0 + 0x60) = index; // sb $t0, 0x60($s0)

    u32 *other_ptr = (u32 *)0x8015C5D8; // D_8015C5D8_15D1D8
    other_ptr[1] = index & 0xFF;        // sw $t9, 0x4($v0)
    other_ptr[0x2C / 4] = 1;            // sw $t1, 0x2C($v0)

    func_801DD5C0_5994D0(arg0, *(u8 *)(arg0 + 0x60));
    return 0;
  }

  return 1;
}