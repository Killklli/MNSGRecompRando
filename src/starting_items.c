#include "Archipelago.h"
#include "apconnect_ui.h"
#include "file_state.h"
#include "modding.h"
#include "recomputils.h"
#include "save_data_tool.h"
#include "types.h"

// Forward declarations
extern void set_starting_characters();
extern void handle_item_by_id(u32 item_id);
void grant_starting_items();

// Simple atoi implementation since it's not available in the limited libc
static int simple_atoi(const char *str)
{
    int result = 0;
    int sign = 1;

    // Skip whitespace
    while (*str == ' ' || *str == '\t')
    {
        str++;
    }

    // Handle sign
    if (*str == '-')
    {
        sign = -1;
        str++;
    }
    else if (*str == '+')
    {
        str++;
    }

    // Convert digits
    while (*str >= '0' && *str <= '9')
    {
        result = result * 10 + (*str - '0');
        str++;
    }

    return result * sign;
}

void grant_starting_items();

// Implementation of sync function declared in save_data_tool.h
void sync_all_save_data_from_datastore(void)
{
    // Sync all the main save data offsets from the datastore
    // Character availability
    SYNC_SAVE_DATA_FROM_DATASTORE(SAVE_GOEMON_RECRUITED);
    SYNC_SAVE_DATA_FROM_DATASTORE(SAVE_EBISUMARU_RECRUITED);
    SYNC_SAVE_DATA_FROM_DATASTORE(SAVE_SASUKE_RECRUITED);
    SYNC_SAVE_DATA_FROM_DATASTORE(SAVE_YAE_RECRUITED);

    // Weapon levels
    SYNC_SAVE_DATA_FROM_DATASTORE(SAVE_GOEMON_WEAPON_LEVEL);
    SYNC_SAVE_DATA_FROM_DATASTORE(SAVE_EBISUMARU_WEAPON_LEVEL);
    SYNC_SAVE_DATA_FROM_DATASTORE(SAVE_SASUKE_WEAPON_LEVEL);
    SYNC_SAVE_DATA_FROM_DATASTORE(SAVE_YAE_WEAPON_LEVEL);

    // Special weapons/items
    SYNC_SAVE_DATA_FROM_DATASTORE(SAVE_CHAIN_PIPE);
    SYNC_SAVE_DATA_FROM_DATASTORE(SAVE_MEATSAW_HAMMER);
    SYNC_SAVE_DATA_FROM_DATASTORE(SAVE_FIRECRACKER_BOMB);
    SYNC_SAVE_DATA_FROM_DATASTORE(SAVE_FLUTE);
    SYNC_SAVE_DATA_FROM_DATASTORE(SAVE_GOEMON_RYO);
    SYNC_SAVE_DATA_FROM_DATASTORE(SAVE_WINDUP_CAMERA);
    SYNC_SAVE_DATA_FROM_DATASTORE(SAVE_ICE_KUNAI);
    SYNC_SAVE_DATA_FROM_DATASTORE(SAVE_BAZOOKA);

    // Magic abilities
    SYNC_SAVE_DATA_FROM_DATASTORE(SAVE_SUDDEN_IMPACT_MAGIC);
    SYNC_SAVE_DATA_FROM_DATASTORE(SAVE_MINI_EBISU_MAGIC);
    SYNC_SAVE_DATA_FROM_DATASTORE(SAVE_SUPER_JUMP_MAGIC);
    SYNC_SAVE_DATA_FROM_DATASTORE(SAVE_MERMAID_MAGIC);

    // Key items
    SYNC_SAVE_DATA_FROM_DATASTORE(SAVE_TRITON_SHELL);
    SYNC_SAVE_DATA_FROM_DATASTORE(SAVE_SUPER_PASS);
    SYNC_SAVE_DATA_FROM_DATASTORE(SAVE_FORTUNE_DOLL_PROGRESS);
    SYNC_SAVE_DATA_FROM_DATASTORE(SAVE_ACHILLES_HEEL);
    SYNC_SAVE_DATA_FROM_DATASTORE(SAVE_QUALITY_CUCUMBER);

    // Fish counts
    SYNC_SAVE_DATA_FROM_DATASTORE(SAVE_RED_FISH_COUNT);
    SYNC_SAVE_DATA_FROM_DATASTORE(SAVE_YELLOW_FISH_COUNT);
    SYNC_SAVE_DATA_FROM_DATASTORE(SAVE_BLUE_FISH_COUNT);

    // Miracle items
    SYNC_SAVE_DATA_FROM_DATASTORE(SAVE_MIRACLE_STAR);
    SYNC_SAVE_DATA_FROM_DATASTORE(SAVE_MIRACLE_MOON);
    SYNC_SAVE_DATA_FROM_DATASTORE(SAVE_MIRACLE_FLOWER);
    SYNC_SAVE_DATA_FROM_DATASTORE(SAVE_MIRACLE_SNOW);

    // Map and special items
    SYNC_SAVE_DATA_FROM_DATASTORE(SAVE_MAP_OF_JAPAN);

    // Special weapon charge abilities
    SYNC_SAVE_DATA_FROM_DATASTORE(SAVE_FIRE_RYO);
    SYNC_SAVE_DATA_FROM_DATASTORE(SAVE_CAMERA_CHARGEABLE);
    SYNC_SAVE_DATA_FROM_DATASTORE(SAVE_KUNAI_BEAM_CHARGEABLE);
    SYNC_SAVE_DATA_FROM_DATASTORE(SAVE_BAZOOKA_CHARGEABLE);

    // Fortune doll system
    SYNC_SAVE_DATA_FROM_DATASTORE(SAVE_FORTUNE_DOLL_TOTAL);
    SYNC_SAVE_DATA_FROM_DATASTORE(SAVE_FORTUNE_DOLL_PROGRESS);

    // // Spawn coordinates (16-bit values)
    // SYNC_SAVE_DATA_H_FROM_DATASTORE(0x204); // SPAWN_ROOM
    // SYNC_SAVE_DATA_H_FROM_DATASTORE(0x20A); // SPAWN_X
    // SYNC_SAVE_DATA_H_FROM_DATASTORE(0x20C); // SPAWN_Z
    // SYNC_SAVE_DATA_H_FROM_DATASTORE(0x20E); // SPAWN_Y
    // SYNC_SAVE_DATA_FROM_DATASTORE(0x68);    // SPAWN_CHARACTER

    // We have this disabled for now as syncing all flags can be slow, we think we can just let it lazy load flags as needed
    // // Sync all flags from datastore
    // s32 flags_synced = 0;
    // // Only sync flags that are within the range of the save data array (0x304 bytes = 0x1820 bits) 
    // for (s32 flag_id = 0; flag_id < 0x1820; flag_id++) {
    //     char key[16];
    //     sprintf(key, "flag_%ld", flag_id);
    //     u32 flag_value = rando_get_datastorage_u32_sync(key);

    //     // If flag is set in datastore, set it in memory using the bit field
    //     if (flag_value != 0) {
    //         s32 byte_index = flag_id >> 3;  // Divide by 8
    //         s32 bit_index = flag_id & 7;    // Modulo 8

    //         // Ensure we don't write outside the array bounds
    //         if (byte_index < 0x304) {
    //             D_8015C608_15D208[byte_index] |= (1 << bit_index);
    //             flags_synced++;
    //         }
    //     }
    // }
}

u32 get_starting_room()
{
    // Only proceed if connected to Archipelago
    if (!rando_is_connected())
    {
        return 0; // Default room
    }

    // Get starting_room value directly from slot data
    u32 starting_room_handle[2];
    rando_get_slotdata_raw_o32("starting_room", starting_room_handle);

    // Get the integer value for spawn room
    u32 starting_room = rando_access_slotdata_raw_u32_o32(starting_room_handle);

    return starting_room;
}

// Sets up the starting items and characters when a new file is started
RECOMP_HOOK_RETURN("func_8000B640_C240")
void on_save_start_hook()
{
    // Set starting room from AP slotdata
    u32 starting_room = get_starting_room();
    WRITE_SPAWN_ROOM(starting_room);

    // Set spawn coordinates for specific room IDs
    if (starting_room == 0x167)
    {
        WRITE_SPAWN_X(0); // X coordinate
        WRITE_SPAWN_Y(0); // Y coordinate
        WRITE_SPAWN_Z(0); // Z coordinate
    }
    else if (starting_room == 0x1B6 || starting_room == 0x1B5 ||
             starting_room == 0x1B1 || starting_room == 0x1B4 ||
             starting_room == 0x1B3)
    {
        WRITE_SPAWN_X(0);   // X coordinate
        WRITE_SPAWN_Y(20);  // Y coordinate
        WRITE_SPAWN_Z(-25); // Z coordinate
    }

    // Set all characters weapon level to 0
    WRITE_SAVE_DATA(SAVE_GOEMON_WEAPON_LEVEL, 0);
    WRITE_SAVE_DATA(SAVE_EBISUMARU_WEAPON_LEVEL, 0);
    WRITE_SAVE_DATA(SAVE_SASUKE_WEAPON_LEVEL, 0);
    WRITE_SAVE_DATA(SAVE_YAE_WEAPON_LEVEL, 0);
    grant_starting_items();
    // Set starting character based on recruited characters
    set_starting_characters();

}

// Declares that a file has started for AP to know to work with file data
RECOMP_HOOK("func_8000B5D0_C1D0")
void on_file_started()
{
    // Set the file started flag so AP logic knows we're in a file
    set_file_started();

    // Sync all save data from datastore to memory when file is loaded
    sync_all_save_data_from_datastore();
}

void grant_starting_items()
{
    // Only proceed if connected to Archipelago
    if (!rando_is_connected())
    {
        return; // Do nothing if not connected
    }
    // Get the slot data for starting_items and using their ap_id pass it to
    // handle_item_by_id function
    u32 starting_items_handle[2];
    rando_get_slotdata_raw_o32("starting_items", starting_items_handle);
    u32 items_iter[2];
    rando_iter_slotdata_raw_dict_o32(starting_items_handle, items_iter);
    u32 item_key[2];
    u32 item_value[2];
    while (rando_iter_slotdata_raw_dict_next_o32(
        starting_items_handle, items_iter, item_key, item_value))
    {
        // Each item_value is an object with fields like 'ap_id', 'name', etc.
        // We need to get the 'ap_id' field from the item object
        u32 ap_id_handle[2];
        rando_access_slotdata_raw_dict_o32(item_value, "ap_id", ap_id_handle);
        u32 item_id = rando_access_slotdata_raw_u32_o32(ap_id_handle);
        recomp_printf("Granting starting item with AP ID: %d\n", item_id);
        handle_item_by_id(item_id);
    }
}