#include "types.h"
#include "modding.h"
#include "apconnect_ui.h"
#include "recomputils.h"
#include "save_data_tool.h"

// Forward declaration for configuration application

RECOMP_HOOK_RETURN("func_8000B640_C240") void on_save_start_hook() {
    //WRITE_SPAWN_ROOM(0x1B0);          // Set spawn room to Oedo Town
    // WRITE_SPAWN_ROOM(0x1B0);
    // WRITE_SPAWN_X(0);              // X coordinate
    // WRITE_SPAWN_Y(20);              // Y coordinate
    // WRITE_SPAWN_Z(-25);              // Z coordinate

    WRITE_SAVE_DATA(SAVE_MIRACLE_FLOWER, 1);
    ENABLE_FLAG(FLAG_UNKNOWN_0154);
    ENABLE_FLAG(FLAG_UNKNOWN_0155);
    ENABLE_FLAG(FLAG_EVERY_4_TICKS);
    ENABLE_FLAG(FLAG_CONGO_BOSS_INTRO);
    ENABLE_FLAG(FLAG_BEAT_CONGO);
    WRITE_SAVE_DATA(SAVE_CHAIN_PIPE, 1);
    WRITE_SAVE_DATA(SAVE_SUPER_PASS, 1);
    ENABLE_FLAG(FLAG_UPGRADED_SILVER_WEAPONS);
    ENABLE_FLAG(FLAG_MOKUBEI_UPGRADE_WEAPONS);
   // ENABLE_FLAG(FLAG_RECEIVED_SUPER_PASS);


// #define SAVE_MR_ELLY_RELATED 0x26C - actually oedo castle
// #define SAVE_MR_ELLY_OEDO_CASTLE 0x270 - Actually Ghost Toys
// #define SAVE_MR_ELLY_GHOST_TOYS 0x274 - Festival Temple
// #define SAVE_MR_ELLY_FESTIVAL_TEMPLE 0x278 - Submarine
// #define SAVE_MR_ELLY_SUBMARINE 0x27C - Musical Castle
// #define SAVE_MR_ARROW_RELATED 0x280 - actually oedo castle
// #define SAVE_MR_ARROW_GIVE_1 0x284 - Actually Ghost Toys
// #define SAVE_MR_ARROW_GIVE_2 0x288 - Festival Temple
// #define SAVE_MR_ARROW_GIVE_3 0x28C - Submarine
// #define SAVE_MR_ARROW_GIVE_4 0x290 - Musical Castle
    // WRITE_SAVE_DATA(SAVE_MR_ELLY_FESTIVAL_TEMPLE, 1);
    // WRITE_SAVE_DATA(SAVE_MR_ARROW_GIVE_3, 1);


    //ENABLE_FLAG(FLAG_EVERY_4_TICKS);
    //ENABLE_FLAG(FLAG_CONGO_BOSS_INTRO);
    //ENABLE_FLAG(FLAG_UNKNOWN_0154);
    //ENABLE_FLAG(FLAG_UNKNOWN_0155);
    // Apply all configured save data settings using the new tooling system
    
    // Example of custom manual overrides (uncomment as needed):
    // ENABLE_FLAG(0x1C3);  // Custom flag example
    // SET_RED_FISH_COUNT(42);  // Custom fish count
    // set_spawn_location(0x123, 100, 200, 300);  // Custom spawn location
    
    // Quick preset options (uncomment one to use):
    // apply_minimal_setup();           // Just basic characters and items
    // apply_speedrun_setup();          // All movement and key progression
    // apply_debug_setup();             // Everything enabled for testing
    // apply_items_only_setup();        // All items but no story progression
    // apply_unlock_all_setup();        // Unlock all areas and doors
    // apply_max_collectibles_setup();  // All collectible items
    // apply_mechanical_features_setup(); // All game mechanics
    // apply_story_and_cutscenes_setup(); // All story flags and cutscenes
}
