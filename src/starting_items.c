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
extern u8 D_8015C66C_15D26C[];
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
    // Always try to load existing save data from storage first
    load_full_save_data_from_storage();
    
    // Check if this is the first time the seed has been started
    bool should_set_starting_data = false;
    if (rando_is_connected())
    {
        u32 seed_started = rando_get_datastorage_u32_sync("seed_started");
        should_set_starting_data = (seed_started == 0);
    }
        
    
    // Only set starting characters if this is the first time starting the seed
    if (should_set_starting_data)
    {
        grant_starting_items();
        
        // Check if pre-unlocked warps option is enabled
        u32 pre_unlocked_warps = rando_get_slotdata_u32("pre_unlocked_warps");
        if (pre_unlocked_warps)
        {
            recomp_printf("Pre-unlocking all flute warp destinations\n");
            WRITE_SAVE_DATA(SAVE_WARP_GOEMON_HOUSE, 1);
            WRITE_SAVE_DATA(SAVE_WARP_KAI_HIGHWAY, 1);
            WRITE_SAVE_DATA(SAVE_WARP_OEDO_CASTLE, 1);
            WRITE_SAVE_DATA(SAVE_WARP_ZAZEN_TOWN, 1);
            WRITE_SAVE_DATA(SAVE_WARP_KII_COFFEE, 1);
            WRITE_SAVE_DATA(SAVE_WARP_FOLKYPOKE_VILLAGE, 1);
            WRITE_SAVE_DATA(SAVE_WARP_KOMPIRA_MOUNTAIN, 1);
            WRITE_SAVE_DATA(SAVE_WARP_IYO_TEA_HOUSE, 1);
            WRITE_SAVE_DATA(SAVE_WARP_GHOST_TOYS, 1);
            WRITE_SAVE_DATA(SAVE_WARP_IZUMO_TEA_HOUSE, 1);
            WRITE_SAVE_DATA(SAVE_WARP_FESTIVAL_TEMPLE, 1);
            WRITE_SAVE_DATA(SAVE_WARP_FESTIVAL_VILLAGE, 1);
            WRITE_SAVE_DATA(SAVE_WARP_WITCHES_HUT, 1);
        }
        
        // Set starting character based on recruited characters
        set_starting_characters();
    }
}

// Declares that a file has started for AP to know to work with file data
RECOMP_HOOK_RETURN("func_8000B5D0_C1D0")
void on_file_started()
{
    // Check if we should restore saved game state values
    if (rando_is_connected())
    {
        u32 saved_total_health = rando_get_datastorage_u32_sync("save_total_health");
        u32 saved_current_lives = rando_get_datastorage_u32_sync("save_current_lives");
        u32 saved_current_ryo = rando_get_datastorage_u32_sync("save_current_ryo");
        u32 saved_current_health = rando_get_datastorage_u32_sync("save_current_health");
        recomp_printf("RESTORE SAVE: Retrieved saved_total_health=%u from datastore\n", saved_total_health);
        // If save_total_health is not 0, restore all 4 values
        if (saved_total_health != 0 && saved_current_health != 0 && saved_current_health != NULL && saved_total_health != NULL)
        {

            // Write the values back to player data
            WRITE_SAVE_DATA(SAVE_CURRENT_LIFE_TOTAL, (s32)saved_current_lives);
            WRITE_SAVE_DATA(SAVE_RYO, (s32)saved_current_ryo);
            WRITE_SAVE_DATA(SAVE_CURRENT_HEALTH, (s32)saved_current_health);
            WRITE_SAVE_DATA(SAVE_TOTAL_HEALTH, (s32)saved_total_health);
            
            recomp_printf("RESTORE SAVE: Restored lives=%u, ryo=%u, current_health=%u, total_health=%u\n",
                        saved_current_lives, saved_current_ryo, saved_current_health, saved_total_health);
                        
        }
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
            // Spawn Related
            WRITE_SAVE_DATA(0x20A, 0x00);
            WRITE_SAVE_DATA(0x20C, 0x00);
            WRITE_SAVE_DATA(0x20D, 0x00);
            WRITE_SPAWN_X(0);   // X coordinate
            WRITE_SPAWN_Y(20);  // Y coordinate
            WRITE_SPAWN_Z(-25); // Z coordinate
        }
        else if (starting_room == 0x1D1)
        {
            // Spawn Related
            WRITE_SAVE_DATA(0x20A, 0x00);
            WRITE_SAVE_DATA(0x20C, 0x00);
            WRITE_SAVE_DATA(0x20D, 0x00);
            WRITE_SPAWN_X(0);   // X coordinate
            WRITE_SPAWN_Y(0);   // Y coordinate
            WRITE_SPAWN_Z(-80);  // Z coordinate
        }

    }

    // Set the file started flag so AP logic knows we're in a file
    set_file_started();

    // Sync all save data from datastore to memory when file is loaded
    // sync_all_save_data_from_datastore();
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
