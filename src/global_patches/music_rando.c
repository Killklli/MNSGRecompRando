// Enables music rando in game, we clear a value that lets you persist audio if you per room music enabled.
#include "Archipelago.h"
#include "libc/stdbool.h"
#include "libc/stdio.h"
#include "modding.h"
#include "recomputils.h"
#include "types.h"

// External variables
extern u16 D_800C7AB2; // Current room ID
extern u8 D_8015C54D_15D14D;
extern u16 D_800C7AC6;
extern u16 D_800C7ACA;
extern u32 D_8015C5C8_15D1C8; // Game data base pointer
extern void *D_801FC604_5B8514;
extern u8 D_801C09C9_1C15C9;
extern u8 D_801C09FD_1C15FD;
extern u32 D_801C0A00_1C1600[8];

// External functions
extern void func_80038D14_39914(void);
extern void func_80038D3C_3993C(void);
extern void func_80038BC8_397C8(int);

/**
 * Function: get_music_rando_mode
 * Purpose: Get the music randomization mode
 * Parameters: None
 * Returns: u32 - 0 = off, 1 = on (per song), 2 = on with area rando (per room)
 */
u32 get_music_rando_mode(void) {
    // Check if we're connected to archipelago
    if (!rando_is_connected()) {
        return 0; // Default to disabled if not connected
    }

    u32 music_rando_handle[2];

    // Get the music_rando setting from slot data
    rando_get_slotdata_raw_o32("music_rando", music_rando_handle);

    // Get the value (0 = off, 1 = on, 2 = on with area rando)
    u32 music_rando_value = rando_access_slotdata_raw_u32_o32(music_rando_handle);

    return music_rando_value;
}

// List of valid BGM values to randomly choose from
static const u16 bgm_list[] = {0x0012, 0x0016, 0x0017, 0x001a, 0x001b, 0x001e, 0x0023, 0x0024, 0x0026, 0x0029, 0x002a, 0x002b, 0x0030, 0x0031, 0x0032, 0x003b,
                               0x003c, 0x003f, 0x0040, 0x0041, 0x0042, 0x0048, 0x0049, 0x004f, 0x0051, 0x0053, 0x0054, 0x0055, 0x0056, 0x0059, 0x005a, 0x005b,
                               0x005d, 0x005e, 0x005f, 0x0061, 0x0062, 0x0063, 0x0064, 0x0067, 0x0068, 0x006b, 0x4000, 0x4025, 0x8000, 0x8019, 0x806e};

static const u32 bgm_count = sizeof(bgm_list) / sizeof(bgm_list[0]);

/**
 * Function: get_seed_value
 * Purpose: Get the seed value from slotdata
 * Parameters: None
 * Returns: u32 - The seed hash value
 */
u32 get_seed_value(void) {
    static u32 cached_seed = 0;
    static bool seed_initialized = false;

    if (!seed_initialized && rando_is_connected()) {
        u32 seed_handle[2];
        rando_get_slotdata_raw_o32("seed", seed_handle);

        // Get seed as string since it's too large for u32
        char seed_str[64];
        rando_access_slotdata_raw_string_o32(seed_handle, seed_str);

        // Simple hash function to convert large seed string to u32
        u32 hash = 0;
        for (int i = 0; seed_str[i] != '\0'; i++) {
            hash = hash * 31 + seed_str[i];
        }
        cached_seed = hash;
        seed_initialized = true;
    }

    return cached_seed;
}

/**
 * Function: is_bgm_in_list
 * Purpose: Check if a sound ID is in the BGM list
 * Parameters: soundId - The sound ID to check
 * Returns: bool - true if the sound ID is in the list, false otherwise
 */
bool is_bgm_in_list(u16 soundId) {
    for (u32 i = 0; i < bgm_count; i++) {
        if (bgm_list[i] == soundId) {
            return true;
        }
    }
    return false;
}

/**
 * Function: get_randomized_bgm
 * Purpose: Returns a consistently randomized BGM value based on the original sound ID
 * Parameters: original_id - The original sound ID, use_room_id - Whether to include room ID in calculation
 * Returns: u16 - Selected BGM value from predefined list
 */
u16 get_randomized_bgm(u16 original_id, bool use_room_id) {
    // Generate pseudo-random number based on seed and original ID
    u32 seed = get_seed_value() + original_id;

    // If area rando mode is enabled, add current room ID to the seed
    if (use_room_id) {
        seed += D_800C7AB2;
    }

    u32 random_index = seed % bgm_count;

    return bgm_list[random_index];
}

RECOMP_PATCH void func_80038C30_39830(s32 soundId, s32 param2, s32 param3) {
    u16 id = soundId & 0xFFFF;
    u8 p2 = param2 & 0xFF;
    u8 p3 = param3 & 0xFF;

    // Apply music randomization if enabled
    if (rando_is_connected()) {
        u32 music_mode = get_music_rando_mode();

        if (music_mode > 0 && is_bgm_in_list(id)) {
            recomp_printf("Original BGM ID: 0x%04X\n", id);
            // music_mode == 2 means area rando (per room), otherwise per song
            id = get_randomized_bgm(id, music_mode == 2);
            recomp_printf("Randomized BGM ID: 0x%04X\n", id);
        }
    }

    if (id == 0) {
        D_801C09C9_1C15C9 = 0;
        return;
    }

    // Set some kind of flag
    D_801C09C9_1C15C9 = 0xFF;

    // Build combined value
    u32 combined = id;

    if (p2 != 0) {
        if (p2 < 0x80) {
            combined = id + (p2 << 16);
        } else {
            combined = id;
        }
    }

    if (p3 != 0) {
        combined |= (p3 << 24);
    }

    // Get current queue count
    u8 queueCount = D_801C09FD_1C15FD;

    if (queueCount >= 8) {
        D_801C09C9_1C15C9 = 0;
        return;
    }

    // Check if sound ID already exists in queue
    if (queueCount > 0) {
        for (s32 i = 0; i < queueCount; i++) {
            u32 existing = D_801C0A00_1C1600[i];
            if (id == (existing & 0xFFFF)) {
                D_801C09C9_1C15C9 = 0;
                return;
            }
        }
    }

    // Add to queue
    D_801C0A00_1C1600[queueCount] = combined;
    D_801C09FD_1C15FD = queueCount + 1;
    D_801C09C9_1C15C9 = 0;
}

RECOMP_HOOK("func_801F82FC_5B420C")
void func_801F82FC_5B420C() {
    // This function makes it so we always clear the persist values so we don't have music persist.
    u32 music_mode = get_music_rando_mode();
    // Only run this block if music rando is set to "on" (1), not "on with area music" (2)
    if (music_mode == 1) {
        s32 *data_ptr = (s32 *)(D_8015C5C8_15D1C8 + 0x38000);
        *(data_ptr + 0x2E04 / 4) = 0; // Set word at offset 0x2E04 to 0
        *(data_ptr + 0x2E08 / 4) = 1; // Set word at offset 0x2E08 to 1
    }
}