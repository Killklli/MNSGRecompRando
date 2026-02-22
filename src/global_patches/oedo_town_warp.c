// Patches the warp to Oedo Town so it does not put you above the map, (and puts you in goemons house instead)
#include "Archipelago.h"
#include "libc/string.h"
#include "modding.h"
#include "recomputils.h"
#include "save_data_tool.h"
#include "types.h"
// External data symbol containing the spawn location text
extern char D_8021750C_6764BC[];

// External data references - using original symbol names
extern u16 D_8006D410_6E010[]; // Warp location data array
extern u32 D_8015C5C8_15D1C8;  // Game heap pointer address

// External function declarations
extern void func_80003728_4328(u32 mode);

RECOMP_HOOK("func_8003731C_37F1C")
void func_8003731C_37F1C(u32 arg0) {
    // Get starting room from slotdata
    u32 starting_room_handle[2];
    rando_get_slotdata_raw_o32("starting_room", starting_room_handle);
    u32 starting_room = rando_access_slotdata_raw_u32_o32(starting_room_handle);

    // Default values (Oedo Town)
    u16 roomID = 0x1D1;
    s16 spawnX = 0;
    s16 spawnY = -80;
    s16 spawnZ = 0;

    // If starting room is NOT 0x1D1, get spawn position from starting_spawn_data
    if (rando_is_connected() && starting_room != 0x1D1) {
        roomID = (u16)starting_room;

        u32 spawn_data_handle[2];
        rando_get_slotdata_raw_o32("starting_spawn_data", spawn_data_handle);

        u32 x_handle[2], y_handle[2], z_handle[2];
        rando_access_slotdata_raw_dict_o32(spawn_data_handle, "x", x_handle);
        rando_access_slotdata_raw_dict_o32(spawn_data_handle, "y", y_handle);
        rando_access_slotdata_raw_dict_o32(spawn_data_handle, "z", z_handle);

        char x_str[32], y_str[32], z_str[32];
        rando_access_slotdata_raw_string_o32(x_handle, x_str);
        rando_access_slotdata_raw_string_o32(y_handle, y_str);
        rando_access_slotdata_raw_string_o32(z_handle, z_str);

        spawnX = (s16)simple_atoi(x_str);
        spawnZ = (s16)simple_atoi(z_str);
        spawnY = (s16)simple_atoi(y_str);
        spawnZ = spawnZ - 28; // Adjust Z to solve our weird spawn issue
    }

    // Update the first warp entry (index 0) with warp data
    D_8006D410_6E010[0] = roomID; // Room ID
    D_8006D410_6E010[1] = spawnX; // X position
    D_8006D410_6E010[2] = spawnY; // Y position
    D_8006D410_6E010[3] = spawnZ; // Z position
    D_8006D410_6E010[4] = 0x0000; // Camera rotation
    D_8006D410_6E010[5] = 0x03;   // Player rotation
}

RECOMP_HOOK("func_80002040_2C40")
void flute_fix() {
    // Only patch the text if connected and starting room is not Oedo Town (0x1D1)
    if (rando_is_connected()) {
        u32 starting_room_handle[2];
        rando_get_slotdata_raw_o32("starting_room", starting_room_handle);
        u32 starting_room = rando_access_slotdata_raw_u32_o32(starting_room_handle);

        // Only replace text if starting room is NOT 0x1D1 (Oedo Town)
        if (starting_room != 0x1D1) {
            // Replace "         Oedo Town" with "       Starting Spawn"
            // Original: "         Oedo Town" (9 spaces + "Oedo Town")
            // New: "       Starting Spawn" (7 spaces + "Starting Spawn")
            strcpy(D_8021750C_6764BC, "       Starting Spawn");
            WRITE_SAVE_DATA(SAVE_WARP_GOEMON_HOUSE, 1);
        }
    }
}