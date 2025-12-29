// Surprise Pack scenario script replacement, allows us to show a custom message when the Surprise Pack is collected.
#include "scenario.h"
#include "common.h"
#include "modding.h"
#include "recomputils.h"
#include "text_utils.h"
#include "scenario_replacer.h"

// External room ID variable from actor.c
extern unsigned short D_800C7AB2;

// Surprise Pack scenario - displays "Received a Surprise Pack!" message
// Based on MESSAGE 064: 05d-1a84.1a84
// This is a portable, self-contained scenario replacement

// Text arrays
// Renders: [Start of text dialog]
static s16 begin_text[] = {
    CTR_BEGIN,
    CTR_ENDLINE,
};

// Renders: "  \n"
static s16 space_newline_text[] = {
    PCT_SPACE,
    PCT_SPACE,
    CTR_NEWLINE,
    CTR_ENDLINE,
};

// Renders: [New dialog window]
static s16 newwindow_text[] = {
    CTR_NEWWINDOW,
    CTR_ENDLINE,
};

// Renders: "  Remaining players are\n"
static s16 remaining_players_text[] = {
    PCT_SPACE,
    PCT_SPACE,
    CHR_R,
    CHR_e,
    CHR_m,
    CHR_a,
    CHR_i,
    CHR_n,
    CHR_i,
    CHR_n,
    CHR_g,
    PCT_SPACE,
    CHR_p,
    CHR_l,
    CHR_a,
    CHR_y,
    CHR_e,
    CHR_r,
    CHR_s,
    PCT_SPACE,
    CHR_a,
    CHR_r,
    CHR_e,
    CTR_NEWLINE,
    CTR_ENDLINE,
};

// Renders: "         increased by 1!\n"
static s16 increased_by_one_text[] = {
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    CHR_i,
    CHR_n,
    CHR_c,
    CHR_r,
    CHR_e,
    CHR_a,
    CHR_s,
    CHR_e,
    CHR_d,
    PCT_SPACE,
    CHR_b,
    CHR_y,
    PCT_SPACE,
    CTR_EM_YELLOW,
    NUM_1,
    CTR_CLOSE_EM,
    PCT_EXCLAMATION,
    CTR_ENDLINE,
};

// Renders: [End of text dialog]
static s16 end_text[] = {
    CTR_END,
    CTR_ENDLINE,
};

// Forward declarations for conditional path
s32 surprise_pack_increase_players[];

s32 scenario_code_surprise_pack[] = {

    // Set dialogue window style
    STW,
    (s32)&D_801C7768_1C8368,
    WTS,
    7,

    // Print initial text
    TXT,
    (s32)begin_text,

    // Set up for sound and display
    STW,
    (s32)&D_801C7770_1C8370,
    WTS,
    1,

    // Set up sound scratch pad and play sound
    STW,
    (s32)&D_801C7740_1C8340,
    WTS,
    0x26C, // Sound ID 26c

    // Execute sound function
    ESR,
    (s32)&func_8003F608_40208,

    // Set text speed
    STW,
    (s32)&D_801C77D8_1C83D8,
    WTS,
    0x64, // Text speed value 100

    // Set unknown text parameter
    STW,
    (s32)&D_801C7798_1C8398,
    WTS,
    1,

    // Display the surprise pack message
    TXT,
    (s32)space_newline_text,
    TXT,
    (s32)0, // Placeholder - will be replaced dynamically

    // Wait for timer
    STW,
    (s32)&D_801C7740_1C8340,
    WTS,
    0x1E, // Wait value 30

    // Execute wait timer function
    ESR,
    (s32)&func_8003F460_40060,

    // // Check if we should increase players (reading from RAM 8015c5ec)
    // // Using available memory address as placeholder for condition check
    // LDW, (s32)&D_801C7900_1C8500,  // Placeholder for 8015c5ec check
    // SNE, 10,  // Skip next if not equal to 10 (condition check)

    // // Jump to increase players section
    // JMP, (s32)surprise_pack_increase_players,

    // Wait for additional time before ending
    STW,
    (s32)&D_801C7740_1C8340,
    WTS,
    0x3C, // Wait value 60 (longer pause)

    // Execute wait timer function
    ESR,
    (s32)&func_8003F460_40060,

    // End the scenario
    TXT,
    (s32)end_text,

    END,
};

// Section for increasing remaining players

s32 surprise_pack_increase_players[] = {

    // Reset text speed
    STW, (s32)&D_801C77D8_1C83D8,
    WTS, 1,

    // Reset text parameter
    STW, (s32)&D_801C7798_1C8398,
    WTS, 1,

    // Display new window and remaining players message
    TXT, (s32)newwindow_text,
    TXT, (s32)space_newline_text,
    TXT, (s32)remaining_players_text,
    TXT, (s32)increased_by_one_text,

    // Increase the player count (write to RAM 8015c5ec equivalent)
    // Using placeholder memory address
    STW, (s32)&D_801C7900_1C8500,  // Placeholder for 8015c5ec
    INC, 1,  // Increase by 1

    // Wait for timer again
    STW, (s32)&D_801C7740_1C8340,
    WTS, 0x2D,  // Wait value 45

    // Execute wait timer function
    ESR, (s32)&func_8003F460_40060,

    // End scenario
    TXT, (s32)end_text,

    END,
};

// Portable replacement function wrapper for surprise pack scenarios
void replace_surprise_pack_scenario(s32 scenario_id, s32 *scenario_code, s16 scenario_file_id, const char *item_name, s32 flag_id, s32 sfg_index)
{
    replace_scenario_with_flag(scenario_id, scenario_code, scenario_file_id, item_name, &flag_id, &sfg_index);
}

