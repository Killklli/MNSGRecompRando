#include "libc/stdbool.h"
#include "libc/stdio.h"
#include "modding.h"
#include "recomputils.h"
#include "types.h"
#include "ultra64.h"
#include "common_structs.h"
#include "save_data_tool.h"

// Function to print text on screen
void func_800042AC_4EAC(s16 entry, const char *string, s16 x, s16 y);

// External data declarations
extern u16 D_800C7AB2;
static u16 prev_D_800C7AB2 = 0;
static bool first_call = true;

extern u8 D_8015C608_15D208[0x304];
static u8 prev_D_8015C608_15D208[0x304];
static bool first_call_memory = true;

// Position monitoring for CLS_BG_W (0x801fc60c)
CLS_BG_W** CLS_BG_W_ADDR = (CLS_BG_W**)0x801fc60c;
static float prev_x_pos = 0.0f;
static float prev_y_pos = 0.0f;
static float prev_z_pos = 0.0f;
static bool first_call_position = true;

// Screen display positioning
static s16 screen_y = 50;  // Starting Y position for on-screen display

RECOMP_HOOK("func_80002040_2C40")
void func_80002040_2C40_hook()
{
  if (!debug_display_enabled) return;

  // Static buffers for X Y Z display only
  static char buffer_x[32];
  static char buffer_y[32];
  static char buffer_z[32];

  // Static buffers for player stats
  static char buffer_lives[32];
  static char buffer_ryo[32];
  static char buffer_health[32];

  u16 current_value = D_800C7AB2;
  // Monitor D_800C7AB2 for changes and log them
  if (first_call)
  {
    prev_D_800C7AB2 = current_value;
    first_call = false;
  }
  else if (current_value != prev_D_800C7AB2)
  {
    recomp_printf("D_800C7AB2 changed: 0x%04X -> 0x%04X\n", prev_D_800C7AB2, current_value);
    prev_D_800C7AB2 = current_value;
  }

    // Monitor position changes when CLS_BG_W is loaded with 0x801fc60c
  // Check if the memory location contains valid data (basic sanity check)
  if (CLS_BG_W_ADDR != NULL && *CLS_BG_W_ADDR != NULL)
  {
    float current_x = (*CLS_BG_W_ADDR)->position.x;
    float current_y = (*CLS_BG_W_ADDR)->position.y;
    float current_z = (*CLS_BG_W_ADDR)->position.z;

    // Always display current position at top of screen
    int x_val = (int)current_x;
    int y_val = (int)current_y;
    int z_val = (int)current_z;

    sprintf(buffer_x, "X: %s%d", (x_val < 0) ? "NEG" : "", (x_val < 0) ? -x_val : x_val);
    sprintf(buffer_y, "Y: %s%d", (y_val < 0) ? "NEG" : "", (y_val < 0) ? -y_val : y_val);
    sprintf(buffer_z, "Z: %s%d", (z_val < 0) ? "NEG" : "", (z_val < 0) ? -z_val : z_val);

    func_800042AC_4EAC(1, buffer_x, 10, 10);
    func_800042AC_4EAC(2, buffer_y, 10, 30);
    func_800042AC_4EAC(3, buffer_z, 10, 50);

    // Read and display player stats
    s32 current_lives = READ_SAVE_DATA(SAVE_CURRENT_LIFE_TOTAL);
    s32 current_ryo = READ_SAVE_DATA(SAVE_RYO);
    s32 current_health = READ_SAVE_DATA(SAVE_CURRENT_HEALTH);
    s32 total_health = READ_SAVE_DATA(SAVE_TOTAL_HEALTH);

    sprintf(buffer_lives, "Lives: %ld", current_lives);
    sprintf(buffer_ryo, "Ryo: %ld", current_ryo);
    sprintf(buffer_health, "Health: %ld/%ld", current_health, total_health);

    func_800042AC_4EAC(4, buffer_lives, 10, 70);
    func_800042AC_4EAC(5, buffer_ryo, 10, 90);
    func_800042AC_4EAC(6, buffer_health, 10, 110);
  }

  // Monitor D_8015C608_15D208 memory array
  if (first_call_memory)
  {
    // Initialize previous values on first call
    for (int i = 0; i < 0x304; i++)
    {
      prev_D_8015C608_15D208[i] = D_8015C608_15D208[i];
    }
    first_call_memory = false;
  }
  else
  {
    // Check for changes in any byte
    for (int i = 0; i < 0x304; i++)
    {
      if (D_8015C608_15D208[i] != prev_D_8015C608_15D208[i])
      {
        if (i != 0x267)
        {
          // recomp_printf("Position 0x%03X: 0x%02X\n", i, D_8015C608_15D208[i]);
        }
        prev_D_8015C608_15D208[i] = D_8015C608_15D208[i];
      }
    }
  }
}
