#include "Archipelago.h"
#include "common.h"
#include "recomputils.h"

extern void func_8003521C_35E1C(void *func_ptr);

extern void func_801CD768_660618(void);

RECOMP_HOOK("func_801CE1F0_6610A0")
void file_selector_watcher(void *entity, s32 param2)
{
  bool connected = rando_is_connected();
  bool scouted = rando_is_scouted();

  if (connected && scouted)
  {
    // recomp_printf("file_selector_watcher: Connected to Archipelago and
    // scouted.\n");
  }
  else
  {
    recomp_printf("file_selector_watcher: Not connected or not scouted. "
                  "Connected: %s, Scouted: %s\n",
                  connected ? "YES" : "NO", scouted ? "YES" : "NO");
    func_8003521C_35E1C(func_801CD768_660618);
  }
}