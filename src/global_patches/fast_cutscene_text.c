// Alows for an option to make cutscene text appear instantly instead of being typed out at normal speed.
#include "Archipelago.h"
#include "file_state.h"
#include "modding.h"

RECOMP_HOOK("func_80002040_2C40")
void frame_watcher()
{
    // Only check fast text option if we're connected and in a file
    if (should_run_ap_logic()) {
        // Check if fast text option is enabled
        u32 fast_text_enabled = rando_get_slotdata_u32("fast_text");
        if (fast_text_enabled) {
            // Set text speed to instant (100) instead of normal speed (1)
            *(u8*)0x801c77d8 = 0x64;
        }
    }
}