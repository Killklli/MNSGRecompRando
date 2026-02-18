
#include "modding.h"
#include "types.h"
#include "recomputils.h"
#include "libc/stdbool.h"
#include "libc/stdio.h"
#include "Archipelago.h"

// External variables
extern u16 D_800C7AB2; // Current room ID
extern u8 D_8015C54D_15D14D;
extern u16 D_800C7AC6;
extern u16 D_800C7ACA;
extern u32 D_8015C5C8_15D1C8; // Game data base pointer
extern void *D_801FC604_5B8514;

// External functions
extern void func_80038D14_39914(void);
extern void func_80038D3C_3993C(void);
extern void func_80038BC8_397C8(int);

/**
 * Function: is_music_rando_enabled
 * Purpose: Check if music randomization is enabled in slotdata
 * Parameters: None
 * Returns: bool - true if music rando is enabled, false otherwise
 */
bool is_music_rando_enabled(void)
{
    // Check if we're connected to archipelago
    if (!rando_is_connected())
    {
        return false; // Default to disabled if not connected
    }

    u32 music_rando_handle[2];

    // Get the music_rando setting from slot data
    rando_get_slotdata_raw_o32("music_rando", music_rando_handle);

    // Get the boolean value as u32 (0 = false, 1 = true)
    u32 music_rando_value = rando_access_slotdata_raw_u32_o32(music_rando_handle);

    return music_rando_value != 0;
}

/**
 * Function: get_random_bgm
 * Purpose: Returns a randomly selected BGM value based on current room ID
 * Parameters: None
 * Returns: u16 - Selected BGM value from predefined list
 */
u16 get_random_bgm(void)
{
    // List of valid BGM values to randomly choose from
    static const u16 bgm_list[] = {
        0x0000, 0x0012, 0x0016, 0x0017, 0x001a, 0x001b, 0x001e, 0x0023,
        0x0024, 0x0026, 0x0029, 0x002a, 0x002b, 0x0030, 0x0031, 0x0032,
        0x003b, 0x003c, 0x003f, 0x0040, 0x0041, 0x0042, 0x0048, 0x0049,
        0x004f, 0x0051, 0x0053, 0x0054, 0x0055, 0x0056, 0x0059, 0x005a,
        0x005b, 0x005d, 0x005e, 0x005f, 0x0061, 0x0062, 0x0063, 0x0064,
        0x0067, 0x0068, 0x006b, 0x4000, 0x4025, 0x8000, 0x8019, 0x806e};

    // Calculate number of BGM options
    static const u32 bgm_count = sizeof(bgm_list) / sizeof(bgm_list[0]);

    // Get the seed value from slotdata
    u32 seed_value = 0;
    if (rando_is_connected())
    {
        u32 seed_handle[2];
        rando_get_slotdata_raw_o32("seed", seed_handle);

        // Get seed as string since it's too large for u32
        char seed_str[64];
        rando_access_slotdata_raw_string_o32(seed_handle, seed_str);

        // Simple hash function to convert large seed string to u32
        u32 hash = 0;
        for (int i = 0; seed_str[i] != '\0'; i++)
        {
            hash = hash * 31 + seed_str[i];
        }
        seed_value = hash;
    }
    // Generate pseudo-random number based on seed and room ID
    u32 seed = seed_value + D_800C7AB2;
    u32 random_index = seed % bgm_count;

    u16 selected_bgm = bgm_list[random_index];
    return selected_bgm;
}

RECOMP_PATCH void func_801F9E18_5B5D28(u16 arg0, u16 arg1)
{
    u16 selected_bgm = arg0; // Default to original BGM value
    if (is_music_rando_enabled())
    {
        selected_bgm = get_random_bgm();
    }

    // Check if high bit (0x8000) is set in selected BGM
    if (selected_bgm & 0x8000)
    {
        func_80038D14_39914();
    }
    else
    {
        // Check if high bit (0x8000) is set in arg1
        if (arg1 & 0x8000)
        {
            func_80038D3C_3993C();
        }
    }

    // Extract low byte and call function if non-zero
    u8 low_byte = selected_bgm & 0xFF;
    if (low_byte != 0)
    {
        func_80038BC8_397C8(low_byte);
    }
}
RECOMP_HOOK("func_801F82FC_5B420C")
void func_801F82FC_5B420C()
{
    if (is_music_rando_enabled())
    {
        s32 *data_ptr = (s32 *)(D_8015C5C8_15D1C8 + 0x38000);
        *(data_ptr + 0x2E04 / 4) = 0; // Set word at offset 0x2E04 to 0
        *(data_ptr + 0x2E08 / 4) = 1; // Set word at offset 0x2E08 to 1
    }
}
