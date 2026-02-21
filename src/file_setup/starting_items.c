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

// Check if starting characters should be set based on current save data
// Returns true if characters should be set (no existing data), false if they're already set
bool should_set_starting_characters(void) {
    // Check if any characters are already recruited
    s32 goemon_recruited = READ_SAVE_DATA(SAVE_GOEMON_RECRUITED);
    s32 ebisumaru_recruited = READ_SAVE_DATA(SAVE_EBISUMARU_RECRUITED);
    s32 sasuke_recruited = READ_SAVE_DATA(SAVE_SASUKE_RECRUITED);
    s32 yae_recruited = READ_SAVE_DATA(SAVE_YAE_RECRUITED);

    // If any character is already recruited, don't set starting characters
    if (goemon_recruited != 0 || ebisumaru_recruited != 0 || sasuke_recruited != 0 || yae_recruited != 0) {
        DEBUG_PRINTF("STARTING CHARS: Characters already recruited, skipping setup\n");
        return false;
    }

    // Check if any weapon levels are set (indicating existing save data)
    s32 goemon_weapon = READ_SAVE_DATA(SAVE_GOEMON_WEAPON_LEVEL);
    s32 ebisumaru_weapon = READ_SAVE_DATA(SAVE_EBISUMARU_WEAPON_LEVEL);
    s32 sasuke_weapon = READ_SAVE_DATA(SAVE_SASUKE_WEAPON_LEVEL);
    s32 yae_weapon = READ_SAVE_DATA(SAVE_YAE_WEAPON_LEVEL);

    if (goemon_weapon != 0 || ebisumaru_weapon != 0 || sasuke_weapon != 0 || yae_weapon != 0) {
        DEBUG_PRINTF("STARTING CHARS: Weapon levels already set, skipping setup\n");
        return false;
    }

    DEBUG_PRINTF("STARTING CHARS: No existing character data found, setting starting characters\n");
    return true;
}
u32 get_starting_room() {
    // Only proceed if connected to Archipelago
    if (!rando_is_connected()) {
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
void on_save_start_hook() {
    // Always try to load existing save data from storage first
    load_full_save_data_from_storage();

    // Check if this is the first time the seed has been started
    bool should_set_starting_data = false;
    if (rando_is_connected()) {
        u32 seed_started = rando_get_datastorage_u32_sync("seed_started");
        should_set_starting_data = (seed_started == 0);
    }

    // Only set starting characters if this is the first time starting the seed
    if (should_set_starting_data) {
        grant_starting_items();

        // Check if pre-unlocked warps option is enabled
        u32 pre_unlocked_warps = rando_get_slotdata_u32("pre_unlocked_warps");
        if (pre_unlocked_warps) {
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

    // Always grant the starting character regardless of seed_started status
    if (rando_is_connected()) {
        // Get starting characters data from Archipelago slot data
        bool goemon_starting = false;
        bool yae_starting = false;
        bool ebisumaru_starting = false;
        bool sasuke_starting = false;

        // Get starting characters dictionary from slot data
        u32 starting_characters_handle[2];
        rando_get_slotdata_raw_o32("starting_characters", starting_characters_handle);

        // Check and get each character's starting status
        if (rando_access_slotdata_raw_dict_has_member_o32(starting_characters_handle, "goemon")) {
            u32 goemon_handle[2];
            rando_access_slotdata_raw_dict_o32(starting_characters_handle, "goemon", goemon_handle);
            goemon_starting = (bool)rando_access_slotdata_raw_u32_o32(goemon_handle);
        }

        if (rando_access_slotdata_raw_dict_has_member_o32(starting_characters_handle, "yae")) {
            u32 yae_handle[2];
            rando_access_slotdata_raw_dict_o32(starting_characters_handle, "yae", yae_handle);
            yae_starting = (bool)rando_access_slotdata_raw_u32_o32(yae_handle);
        }

        if (rando_access_slotdata_raw_dict_has_member_o32(starting_characters_handle, "ebisumaru")) {
            u32 ebisumaru_handle[2];
            rando_access_slotdata_raw_dict_o32(starting_characters_handle, "ebisumaru", ebisumaru_handle);
            ebisumaru_starting = (bool)rando_access_slotdata_raw_u32_o32(ebisumaru_handle);
        }

        if (rando_access_slotdata_raw_dict_has_member_o32(starting_characters_handle, "sasuke")) {
            u32 sasuke_handle[2];
            rando_access_slotdata_raw_dict_o32(starting_characters_handle, "sasuke", sasuke_handle);
            sasuke_starting = (bool)rando_access_slotdata_raw_u32_o32(sasuke_handle);
        }

        // Only grant the character that is marked as starting
        if (goemon_starting) {
            WRITE_SAVE_DATA(SAVE_GOEMON_RECRUITED, 1);
        } else if (yae_starting) {
            WRITE_SAVE_DATA(SAVE_YAE_RECRUITED, 1);
        } else if (ebisumaru_starting) {
            WRITE_SAVE_DATA(SAVE_EBISUMARU_RECRUITED, 1);
        } else if (sasuke_starting) {
            WRITE_SAVE_DATA(SAVE_SASUKE_RECRUITED, 1);
        }
    }
}

// Declares that a file has started for AP to know to work with file data
RECOMP_HOOK_RETURN("func_8000B5D0_C1D0")
void on_file_started() {
    // Check if we should restore saved game state values
    if (rando_is_connected()) {
        // Set starting room if keep_intro_cutscene is enabled (after intro plays)
        u32 keep_intro = rando_get_slotdata_u32("keep_intro_cutscene");
        if (!keep_intro) {
            u32 starting_room = get_starting_room();
            WRITE_SPAWN_ROOM(starting_room);
        }

        u32 saved_total_health = rando_get_datastorage_u32_sync("save_total_health");
        u32 saved_current_lives = rando_get_datastorage_u32_sync("save_current_lives");
        u32 saved_current_ryo = rando_get_datastorage_u32_sync("save_current_ryo");
        u32 saved_current_health = rando_get_datastorage_u32_sync("save_current_health");
        // Load inventory data
        u32 saved_slot1_item = rando_get_datastorage_u32_sync("save_slot1_item");
        u32 saved_slot2_item = rando_get_datastorage_u32_sync("save_slot2_item");
        u32 saved_slot2_count = rando_get_datastorage_u32_sync("save_slot2_count");
        u32 saved_slot3_item = rando_get_datastorage_u32_sync("save_slot3_item");
        u32 saved_slot3_count = rando_get_datastorage_u32_sync("save_slot3_count");

        recomp_printf("RESTORE SAVE: Retrieved saved_total_health=%u from datastore\n", saved_total_health);
        // If save_total_health is not 0, restore all 4 values
        if (saved_total_health != 0 && saved_current_health != 0) {

            // Restore inventory data
            WRITE_SAVE_DATA(SAVE_SLOT_1_ITEM, (s32)saved_slot1_item);
            WRITE_SAVE_DATA(SAVE_SLOT_2_ITEM, (s32)saved_slot2_item);
            WRITE_SAVE_DATA(SAVE_SLOT_2_COUNT, (s32)saved_slot2_count);
            WRITE_SAVE_DATA(SAVE_SLOT_3_ITEM, (s32)saved_slot3_item);
            WRITE_SAVE_DATA(SAVE_SLOT_3_COUNT, (s32)saved_slot3_count);

            recomp_printf("RESTORE SAVE: Restored lives=%u, ryo=%u, current_health=%u, total_health=%u\n", saved_current_lives, saved_current_ryo, saved_current_health, saved_total_health);
            recomp_printf("RESTORE SAVE: Restored inventory - slot1_item=%u, slot2_item=%u, slot2_count=%u, slot3_item=%u, slot3_count=%u\n", saved_slot1_item, saved_slot2_item, saved_slot2_count,
                          saved_slot3_item, saved_slot3_count);
        }
    }

    // Set the file started flag so AP logic knows we're in a file
    set_file_started();

    // Sync all save data from datastore to memory when file is loaded
    // sync_all_save_data_from_datastore();
}

// External data declarations
extern u8 D_8015C608_15D208[]; // Saved game data array (0x304 bytes)

// Pre-hook to adjust spawn coordinates in save data before func_8000B2A0_BEA0 reads them
RECOMP_HOOK("func_8000B2A0_BEA0")
void adjust_spawn_location_pre_hook(void) {
    u8 *savedData = D_8015C608_15D208;

    // Get spawn coordinates from Archipelago slot data and write to saved data
    if (rando_is_connected()) {
        // Set starting room from AP slotdata only if keep_intro_cutscene is disabled
        u32 keep_intro = rando_get_slotdata_u32("keep_intro_cutscene");
        if (keep_intro) {
            u32 starting_room = get_starting_room();
            WRITE_SPAWN_ROOM(starting_room);
        }

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

        s16 spawnX = (s16)simple_atoi(x_str);
        s16 spawnZ = (s16)simple_atoi(z_str);
        s16 spawnY = (s16)simple_atoi(y_str);

        // Write coordinates to saved data so they can be read by func_8000B2A0_BEA0
        *(s16 *)&savedData[0x20A] = spawnX;
        *(s16 *)&savedData[0x20C] = spawnY;
        *(s16 *)&savedData[0x20E] = spawnZ - 28;

        recomp_printf("Set spawn coordinates from AP to savedData: X=%d, Y=%d, Z=%d\n", spawnX, spawnY, spawnZ);
    }
}

void grant_starting_items() {
    // Only proceed if connected to Archipelago
    if (!rando_is_connected()) {
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
    while (rando_iter_slotdata_raw_dict_next_o32(starting_items_handle, items_iter, item_key, item_value)) {
        // Each item_value is an object with fields like 'ap_id', 'name', etc.
        // We need to get the 'ap_id' field from the item object
        u32 ap_id_handle[2];
        rando_access_slotdata_raw_dict_o32(item_value, "ap_id", ap_id_handle);
        u32 item_id = rando_access_slotdata_raw_u32_o32(ap_id_handle);
        recomp_printf("Granting starting item with AP ID: %d\n", item_id);
        handle_item_by_id(item_id);
    }
}
