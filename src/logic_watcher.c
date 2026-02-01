#include "Archipelago.h"
#include "apconnect_ui.h"
#include "entities.h"
#include "file_state.h"
#include "modding.h"
#include "recomputils.h"
#include "save_data_tool.h"
#include "types.h"

// External function declarations
extern void func_80221F70_5DD440(void);
extern void func_8021804C_5D351C(void *entity, s32 arg1);
extern void func_80024038_24C38(s32 flag);
extern s32 func_800240DC_24CDC(s32 flag);
extern void func_8003D310_3DF10(s32 sound_id);
extern void func_80218DA8_5D4278(void *entity, s32 arg1, s32 arg2, s32 arg3);
extern void func_8021A22C_5D56FC(void *entity);
extern void func_8003521C_35E1C(void *func_ptr);
extern void func_080006E0_6AEEC0(void *, void *);
extern void func_8003F608_40208();

// Hooks the cutscene text function, this will tell us if the game is completed
RECOMP_HOOK("func_8003D310_3DF10")
void game_completed_hook(s32 param)
{
    // if the param is 0x213
    if (param == 0x213)
    {
        DEBUG_PRINTF("Game completed with param 0x213 - notifying rando\n");
        if (rando_is_connected())
        {
            rando_complete_goal();
        }
    }
}
extern void save_player_data();

// Forward declarations for local functions
void deathlink_sender();
void deathlink_received();

void increase_silver_fortune_doll()
{
    s32 fortune_dolls = READ_SAVE_DATA(SAVE_FORTUNE_DOLL_TOTAL);
    fortune_dolls += 1;
    WRITE_SAVE_DATA(SAVE_FORTUNE_DOLL_TOTAL, fortune_dolls);

    s32 fortune_progress = READ_SAVE_DATA(SAVE_FORTUNE_DOLL_PROGRESS);
    fortune_progress += 1;
    // if it gets to 4 reset to 0
    if (fortune_progress >= 4)
    {
        fortune_progress = 0;
        // Raise SAVE_TOTAL_HEALTH by 1
        s32 total_health = READ_SAVE_DATA(SAVE_TOTAL_HEALTH);
        total_health += 2;
        WRITE_SAVE_DATA(SAVE_TOTAL_HEALTH, total_health);
    }
    WRITE_SAVE_DATA(SAVE_FORTUNE_DOLL_PROGRESS, fortune_progress);
    save_player_data();
}

void increase_gold_fortune_doll()
{
    s32 fortune_dolls = READ_SAVE_DATA(SAVE_FORTUNE_DOLL_TOTAL);
    fortune_dolls += 1;
    WRITE_SAVE_DATA(SAVE_FORTUNE_DOLL_TOTAL, fortune_dolls);
    // Raise SAVE_TOTAL_HEALTH by 1
    s32 total_health = READ_SAVE_DATA(SAVE_TOTAL_HEALTH);
    total_health += 2;
    WRITE_SAVE_DATA(SAVE_TOTAL_HEALTH, total_health);
    save_player_data();
}

void progressive_weapon_handler(void)
{
    // Read current weapon levels and increment them (0→1, 1→2)
    int goemon_level = READ_SAVE_DATA(SAVE_GOEMON_WEAPON_LEVEL);
    int yae_level = READ_SAVE_DATA(SAVE_YAE_WEAPON_LEVEL);
    int ebisumaru_level = READ_SAVE_DATA(SAVE_EBISUMARU_WEAPON_LEVEL);
    int sasuke_level = READ_SAVE_DATA(SAVE_SASUKE_WEAPON_LEVEL);

    // Increment levels: 0→1, 1→2 (max level 2)
    if (goemon_level == 0)
        WRITE_SAVE_DATA(SAVE_GOEMON_WEAPON_LEVEL, 1);
    else if (goemon_level == 1)
        WRITE_SAVE_DATA(SAVE_GOEMON_WEAPON_LEVEL, 2);

    if (yae_level == 0)
        WRITE_SAVE_DATA(SAVE_YAE_WEAPON_LEVEL, 1);
    else if (yae_level == 1)
        WRITE_SAVE_DATA(SAVE_YAE_WEAPON_LEVEL, 2);

    if (ebisumaru_level == 0)
        WRITE_SAVE_DATA(SAVE_EBISUMARU_WEAPON_LEVEL, 1);
    else if (ebisumaru_level == 1)
        WRITE_SAVE_DATA(SAVE_EBISUMARU_WEAPON_LEVEL, 2);

    if (sasuke_level == 0)
        WRITE_SAVE_DATA(SAVE_SASUKE_WEAPON_LEVEL, 1);
    else if (sasuke_level == 1)
        WRITE_SAVE_DATA(SAVE_SASUKE_WEAPON_LEVEL, 2);
}

void increase_lives()
{
    // Grant an extra life so the player can survive the deathlink
    s32 current_lives = READ_SAVE_DATA(SAVE_CURRENT_LIFE_TOTAL);
    current_lives += 1;
    // If the current lives is greater than 9 set it to 9 (max 10 lives 0 is
    // included as a life)
    if (current_lives > 10)
    {
        current_lives = 10;
    }
    WRITE_SAVE_DATA(SAVE_CURRENT_LIFE_TOTAL, current_lives);
}

void fill_health()
{
    s32 total_health = READ_SAVE_DATA(SAVE_TOTAL_HEALTH);
    WRITE_SAVE_DATA(SAVE_CURRENT_HEALTH, total_health);
}

void normal_health()
{
    // Add exactly 1 heart (2 health points) to current health
    s32 current_health = READ_SAVE_DATA(SAVE_CURRENT_HEALTH);
    s32 total_health = READ_SAVE_DATA(SAVE_TOTAL_HEALTH);
    current_health += 2;
    // Don't exceed maximum health
    if (current_health > total_health)
    {
        current_health = total_health;
    }
    WRITE_SAVE_DATA(SAVE_CURRENT_HEALTH, current_health);
}

void sasuke_batteries()
{
    // SAVE_DEAD_SASUKE_PROFILE 0, 1, 2
    // We just want to increment up to 2
    s32 sasuke_profile = READ_SAVE_DATA(SAVE_DEAD_SASUKE_PROFILE);
    if (sasuke_profile < 2)
    {
        sasuke_profile += 1;
        WRITE_SAVE_DATA(SAVE_DEAD_SASUKE_PROFILE, sasuke_profile);
    }
}

RECOMP_HOOK("func_80002040_2C40") void deathlink_hooks()
{
    // Check if we've started 
    if (!should_run_ap_logic()) {
        return;
    }
    if (!rando_get_death_link_enabled()) {
        return;
    }
    
    if (rando_get_death_link_pending()) {
        deathlink_received();
    } else {
        deathlink_sender();
    }
}

void deathlink_sender()
{
    // if the players total health is 0 (or less), send a deathlink
    s32 current_health = READ_SAVE_DATA(SAVE_CURRENT_HEALTH);
    if (current_health <= 0) {
        rando_send_death_link();
    }
}

void deathlink_received()
{
    increase_lives();
    // Set their current health to 0
    WRITE_SAVE_DATA(SAVE_CURRENT_HEALTH, 0);
}

void ringlink()
{
    // Get the current value of SAVE_RYO and print it
    s32 current_ryo = READ_SAVE_DATA(SAVE_RYO);
    DEBUG_PRINTF("Current Ryo before Ringlink: %d\n", current_ryo);
    // We can increase or decrease ryo here as needed
}

void set_starting_characters()
{
    // Get starting characters data from Archipelago slot data
    bool goemon_starting = false;
    bool yae_starting = false;
    bool ebisumaru_starting = false;
    bool sasuke_starting = false;

    // Only proceed if connected to Archipelago
    if (!rando_is_connected())
    {
        // Use default starting characters if not connected
        DEBUG_PRINTF(
            "Not connected to Archipelago, using default starting characters\n");
        return;
    }

    // Check if we should use AP logic for starting characters
    // Get starting characters dictionary from slot data
    u32 starting_characters_handle[2];
    rando_get_slotdata_raw_o32("starting_characters", starting_characters_handle);
    // print the handle data
    recomp_printf("Starting characters handle: %p %p\n",
                 (void *)starting_characters_handle[0],
                 (void *)starting_characters_handle[1]);
    // Check and get each character's starting status
    if (rando_access_slotdata_raw_dict_has_member_o32(starting_characters_handle,
                                                      "goemon"))
    {
        u32 goemon_handle[2];
        rando_access_slotdata_raw_dict_o32(starting_characters_handle, "goemon",
                                           goemon_handle);
        goemon_starting = (bool)rando_access_slotdata_raw_u32_o32(goemon_handle);
    }

    if (rando_access_slotdata_raw_dict_has_member_o32(starting_characters_handle,
                                                      "yae"))
    {
        u32 yae_handle[2];
        rando_access_slotdata_raw_dict_o32(starting_characters_handle, "yae",
                                           yae_handle);
        yae_starting = (bool)rando_access_slotdata_raw_u32_o32(yae_handle);
    }

    if (rando_access_slotdata_raw_dict_has_member_o32(starting_characters_handle,
                                                      "ebisumaru"))
    {
        u32 ebisumaru_handle[2];
        rando_access_slotdata_raw_dict_o32(starting_characters_handle, "ebisumaru",
                                           ebisumaru_handle);
        ebisumaru_starting =
            (bool)rando_access_slotdata_raw_u32_o32(ebisumaru_handle);
    }

    if (rando_access_slotdata_raw_dict_has_member_o32(starting_characters_handle,
                                                      "sasuke"))
    {
        u32 sasuke_handle[2];
        rando_access_slotdata_raw_dict_o32(starting_characters_handle, "sasuke",
                                           sasuke_handle);
        sasuke_starting = (bool)rando_access_slotdata_raw_u32_o32(sasuke_handle);
    }

    recomp_printf("Starting characters from AP: goemon=%d, yae=%d, ebisumaru=%d, "
                 "sasuke=%d\n",
                 goemon_starting, yae_starting, ebisumaru_starting,
                 sasuke_starting);

    // Set recruitment flags in save data based on starting characters
    WRITE_SAVE_DATA(SAVE_GOEMON_RECRUITED, goemon_starting ? 1 : 0);
    WRITE_SAVE_DATA(SAVE_YAE_RECRUITED, yae_starting ? 1 : 0);
    WRITE_SAVE_DATA(SAVE_EBISUMARU_RECRUITED, ebisumaru_starting ? 1 : 0);
    WRITE_SAVE_DATA(SAVE_SASUKE_RECRUITED, sasuke_starting ? 1 : 0);

    // Set WRITE_SPAWN_CHARACTER to the first available character
    u8 character_to_spawn = 0; // Default fallback to Goemon

    // Find the first available character
    if (goemon_starting)
    {
        character_to_spawn = 0; // Goemon
    }
    else if (ebisumaru_starting)
    {
        character_to_spawn = 0x01; // Ebisumaru
    }
    else if (sasuke_starting)
    {
        character_to_spawn = 0x02; // Sasuke
    }
    else if (yae_starting)
    {
        character_to_spawn = 0x03; // Yae
    }

    DEBUG_PRINTF("Setting spawn character to: %d\n", character_to_spawn);
    WRITE_SPAWN_CHARACTER(character_to_spawn);
}

RECOMP_HOOK("func_801DD50C_59941C")
void taglink() { DEBUG_PRINTF("Taglink event received\n"); }
