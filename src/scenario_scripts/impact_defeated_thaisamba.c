// Adjusts the Impact Miracle Item Script to not set the Beat Thaisamba flag so
// we can prevent the submarine from despawning.

#include "common.h"
#include "modding.h"
#include "recomputils.h"
#include "scenario.h"
#include "scenario_replacer.h"

// Forward declarations for scenario functions
extern s32 scenario_code_save_sequence[];
extern s32 scenario_code_save_yes[];
extern s32 scenario_code_save_no[];
extern s32 scenario_code_save_no_pak[];
extern s32 scenario_code_save_processing[];
extern s32 scenario_code_save_success[];

// Text fragments for Impact's departure scene

// {begin}{endline}
static s16 scenario_text_begin[] = {
    CTR_BEGIN,
    CTR_ENDLINE,
};

// {newwindow}{endline}
static s16 scenario_text_newwindow[] = {
    CTR_NEWWINDOW,
    CTR_ENDLINE,
};

// {waitinput}{end}{endline}
static s16 scenario_text_waitinput_end[] = {
    CTR_WAITINPUT,
    CTR_END,
    CTR_ENDLINE,
};

// {end}{endline}
static s16 scenario_text_end[] = {
    CTR_END,
    CTR_ENDLINE,
};

// {/em}
static s16 scenario_text_close_em[] = {
    CTR_CLOSE_EM,
};

//  {newline}{endline}
static s16 scenario_text_space_newline[] = {
    PCT_SPACE,
    PCT_SPACE,
    CTR_NEWLINE,
    CTR_ENDLINE,
};

// {button}{endline}
static s16 scenario_text_button[] = {
    CTR_BUTTON,
    CTR_ENDLINE,
};

// {newline}{endline}
static s16 scenario_text_newline[] = {
    CTR_NEWLINE,
    CTR_ENDLINE,
};

// Impact:Well, I've got{newline}{endline}
static s16 scenario_text_impact_well_ive_got[] = {
    CHR_I,
    CHR_m,
    CHR_p,
    CHR_a,
    CHR_c,
    CHR_t,
    PCT_COLON,
    CHR_W,
    CHR_e,
    CHR_l,
    CHR_l,
    PCT_COMMA,
    PCT_SPACE,
    CHR_I,
    PCT_APOSTROPHE,
    CHR_v,
    CHR_e,
    PCT_SPACE,
    CHR_g,
    CHR_o,
    CHR_t,
    CTR_NEWLINE,
    CTR_ENDLINE,
};

//       a {em-yellow}movie{/em} to complete...{button}{endline}
static s16 scenario_text_movie_to_complete[] = {
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    CHR_a,
    PCT_SPACE,
    CTR_EM_YELLOW,
    CHR_m,
    CHR_o,
    CHR_v,
    CHR_i,
    CHR_e,
    CTR_CLOSE_EM,
    PCT_SPACE,
    CHR_t,
    CHR_o,
    PCT_SPACE,
    CHR_c,
    CHR_o,
    CHR_m,
    CHR_p,
    CHR_l,
    CHR_e,
    CHR_t,
    CHR_e,
    PCT_PERIOD,
    PCT_PERIOD,
    PCT_PERIOD,
    CTR_BUTTON,
    CTR_ENDLINE,
};

// Impact:...so I must head back{newline}{endline}
static s16 scenario_text_so_i_must_head_back[] = {
    CHR_I,
    CHR_m,
    CHR_p,
    CHR_a,
    CHR_c,
    CHR_t,
    PCT_COLON,
    PCT_PERIOD,
    PCT_PERIOD,
    PCT_PERIOD,
    CHR_s,
    CHR_o,
    PCT_SPACE,
    CHR_I,
    PCT_SPACE,
    CHR_m,
    CHR_u,
    CHR_s,
    CHR_t,
    PCT_SPACE,
    CHR_h,
    CHR_e,
    CHR_a,
    CHR_d,
    PCT_SPACE,
    CHR_b,
    CHR_a,
    CHR_c,
    CHR_k,
    CTR_NEWLINE,
    CTR_ENDLINE,
};

//       to {em-yellow}France{/em}!{button}{endline}
static s16 scenario_text_to_france[] = {
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    CHR_t,
    CHR_o,
    PCT_SPACE,
    CTR_EM_YELLOW,
    CHR_F,
    CHR_r,
    CHR_a,
    CHR_n,
    CHR_c,
    CHR_e,
    CTR_CLOSE_EM,
    PCT_EXCLAMATION,
    CTR_BUTTON,
    CTR_ENDLINE,
};

// Impact:If you need me again,{newline}{endline}
static s16 scenario_text_if_you_need_me_again[] = {
    CHR_I,
    CHR_m,
    CHR_p,
    CHR_a,
    CHR_c,
    CHR_t,
    PCT_COLON,
    CHR_I,
    CHR_f,
    PCT_SPACE,
    CHR_y,
    CHR_o,
    CHR_u,
    PCT_SPACE,
    CHR_n,
    CHR_e,
    CHR_e,
    CHR_d,
    PCT_SPACE,
    CHR_m,
    CHR_e,
    PCT_SPACE,
    CHR_a,
    CHR_g,
    CHR_a,
    CHR_i,
    CHR_n,
    PCT_COMMA,
    CTR_NEWLINE,
    CTR_ENDLINE,
};

//       {em-yellow}Au Revoir!{/em}{endline}
static s16 scenario_text_au_revoir[] = {
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    CTR_EM_YELLOW,
    CHR_A,
    CHR_u,
    PCT_SPACE,
    CHR_R,
    CHR_e,
    CHR_v,
    CHR_o,
    CHR_i,
    CHR_r,
    PCT_EXCLAMATION,
    CTR_CLOSE_EM,
    CTR_ENDLINE,
};

// Do you wish to save {newline}{endline}
static s16 scenario_text_do_you_wish_to_save[] = {
    CHR_D,
    CHR_o,
    PCT_SPACE,
    CHR_y,
    CHR_o,
    CHR_u,
    PCT_SPACE,
    CHR_w,
    CHR_i,
    CHR_s,
    CHR_h,
    PCT_SPACE,
    CHR_t,
    CHR_o,
    PCT_SPACE,
    CHR_s,
    CHR_a,
    CHR_v,
    CHR_e,
    PCT_SPACE,
    CTR_NEWLINE,
    CTR_ENDLINE,
};

// the game to this point in {newline}{endline}
static s16 scenario_text_the_game_to_this_point[] = {
    CHR_t,
    CHR_h,
    CHR_e,
    PCT_SPACE,
    CHR_g,
    CHR_a,
    CHR_m,
    CHR_e,
    PCT_SPACE,
    CHR_t,
    CHR_o,
    PCT_SPACE,
    CHR_t,
    CHR_h,
    CHR_i,
    CHR_s,
    PCT_SPACE,
    CHR_p,
    CHR_o,
    CHR_i,
    CHR_n,
    CHR_t,
    PCT_SPACE,
    CHR_i,
    CHR_n,
    PCT_SPACE,
    CTR_NEWLINE,
    CTR_ENDLINE,
};

// your {em-yellow}Adventure Diary{/em}?{newline}{endline}
static s16 scenario_text_adventure_diary[] = {
    CHR_y,
    CHR_o,
    CHR_u,
    CHR_r,
    PCT_SPACE,
    CTR_EM_YELLOW,
    CHR_A,
    CHR_d,
    CHR_v,
    CHR_e,
    CHR_n,
    CHR_t,
    CHR_u,
    CHR_r,
    CHR_e,
    PCT_SPACE,
    CHR_D,
    CHR_i,
    CHR_a,
    CHR_r,
    CHR_y,
    CTR_CLOSE_EM,
    PCT_QUESTION,
    CTR_NEWLINE,
    CTR_ENDLINE,
};

//   {em-yellow}Yes      {endline}
static s16 scenario_text_yes_option[] = {
    PCT_SPACE,
    PCT_SPACE,
    CTR_EM_YELLOW,
    CHR_Y,
    CHR_e,
    CHR_s,
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    CTR_ENDLINE,
};

//   {em-yellow}No{endline}
static s16 scenario_text_no_option[] = {
    PCT_SPACE,
    PCT_SPACE,
    CTR_EM_YELLOW,
    CHR_N,
    CHR_o,
    CTR_ENDLINE,
};

// Very well!{newline}{endline}
static s16 scenario_text_very_well[] = {
    CHR_V,
    CHR_e,
    CHR_r,
    CHR_y,
    PCT_SPACE,
    CHR_w,
    CHR_e,
    CHR_l,
    CHR_l,
    PCT_EXCLAMATION,
    CTR_NEWLINE,
    CTR_ENDLINE,
};

// Your game will now be saved in{newline}{endline}
static s16 scenario_text_your_game_will_be_saved[] = {
    CHR_Y,
    CHR_o,
    CHR_u,
    CHR_r,
    PCT_SPACE,
    CHR_g,
    CHR_a,
    CHR_m,
    CHR_e,
    PCT_SPACE,
    CHR_w,
    CHR_i,
    CHR_l,
    CHR_l,
    PCT_SPACE,
    CHR_n,
    CHR_o,
    CHR_w,
    PCT_SPACE,
    CHR_b,
    CHR_e,
    PCT_SPACE,
    CHR_s,
    CHR_a,
    CHR_v,
    CHR_e,
    CHR_d,
    PCT_SPACE,
    CHR_i,
    CHR_n,
    CTR_NEWLINE,
    CTR_ENDLINE,
};

// the {em-yellow}Adventure Diary{/em}.{button}{endline}
static s16 scenario_text_the_adventure_diary[] = {
    CHR_t,
    CHR_h,
    CHR_e,
    PCT_SPACE,
    CTR_EM_YELLOW,
    CHR_A,
    CHR_d,
    CHR_v,
    CHR_e,
    CHR_n,
    CHR_t,
    CHR_u,
    CHR_r,
    CHR_e,
    PCT_SPACE,
    CHR_D,
    CHR_i,
    CHR_a,
    CHR_r,
    CHR_y,
    CTR_CLOSE_EM,
    PCT_PERIOD,
    CTR_BUTTON,
    CTR_ENDLINE,
};

// Press the [{em-yellow}A{/em} Button]{newline}{endline}
static s16 scenario_text_press_a_button[] = {
    CHR_P,
    CHR_r,
    CHR_e,
    CHR_s,
    CHR_s,
    PCT_SPACE,
    CHR_t,
    CHR_h,
    CHR_e,
    PCT_SPACE,
    PCT_LBRACKET,
    CTR_EM_YELLOW,
    CHR_A,
    CTR_CLOSE_EM,
    PCT_SPACE,
    CHR_B,
    CHR_u,
    CHR_t,
    CHR_t,
    CHR_o,
    CHR_n,
    PCT_RBRACKET,
    CTR_NEWLINE,
    CTR_ENDLINE,
};

//         when you are ready.{button}{endline}
static s16 scenario_text_when_you_are_ready[] = {
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    CHR_w,
    CHR_h,
    CHR_e,
    CHR_n,
    PCT_SPACE,
    CHR_y,
    CHR_o,
    CHR_u,
    PCT_SPACE,
    CHR_a,
    CHR_r,
    CHR_e,
    PCT_SPACE,
    CHR_r,
    CHR_e,
    CHR_a,
    CHR_d,
    CHR_y,
    PCT_PERIOD,
    CTR_BUTTON,
    CTR_ENDLINE,
};

// Your game has been saved in{newline}{endline}
static s16 scenario_text_game_has_been_saved[] = {
    CHR_Y,
    CHR_o,
    CHR_u,
    CHR_r,
    PCT_SPACE,
    CHR_g,
    CHR_a,
    CHR_m,
    CHR_e,
    PCT_SPACE,
    CHR_h,
    CHR_a,
    CHR_s,
    PCT_SPACE,
    CHR_b,
    CHR_e,
    CHR_e,
    CHR_n,
    PCT_SPACE,
    CHR_s,
    CHR_a,
    CHR_v,
    CHR_e,
    CHR_d,
    PCT_SPACE,
    CHR_i,
    CHR_n,
    CTR_NEWLINE,
    CTR_ENDLINE,
};

// The present situation will be{newline}{endline}
static s16 scenario_text_present_situation_will_be[] = {
    CHR_T,
    CHR_h,
    CHR_e,
    PCT_SPACE,
    CHR_p,
    CHR_r,
    CHR_e,
    CHR_s,
    CHR_e,
    CHR_n,
    CHR_t,
    PCT_SPACE,
    CHR_s,
    CHR_i,
    CHR_t,
    CHR_u,
    CHR_a,
    CHR_t,
    CHR_i,
    CHR_o,
    CHR_n,
    PCT_SPACE,
    CHR_w,
    CHR_i,
    CHR_l,
    CHR_l,
    PCT_SPACE,
    CHR_b,
    CHR_e,
    CTR_NEWLINE,
    CTR_ENDLINE,
};

// [{em-yellow}Saved{/em}] now.{newline}{endline}
static s16 scenario_text_saved_now[] = {
    PCT_LBRACKET,
    CTR_EM_YELLOW,
    CHR_S,
    CHR_a,
    CHR_v,
    CHR_e,
    CHR_d,
    CTR_CLOSE_EM,
    PCT_RBRACKET,
    PCT_SPACE,
    CHR_n,
    CHR_o,
    CHR_w,
    PCT_PERIOD,
    CTR_NEWLINE,
    CTR_ENDLINE,
};

//   Please press the [{em-yellow}A{/em} Button]{button}{endline}
static s16 scenario_text_please_press_a_button[] = {
    PCT_SPACE,
    PCT_SPACE,
    CHR_P,
    CHR_l,
    CHR_e,
    CHR_a,
    CHR_s,
    CHR_e,
    PCT_SPACE,
    CHR_p,
    CHR_r,
    CHR_e,
    CHR_s,
    CHR_s,
    PCT_SPACE,
    CHR_t,
    CHR_h,
    CHR_e,
    PCT_SPACE,
    PCT_LBRACKET,
    CTR_EM_YELLOW,
    CHR_A,
    CTR_CLOSE_EM,
    PCT_SPACE,
    CHR_B,
    CHR_u,
    CHR_t,
    CHR_t,
    CHR_o,
    CHR_n,
    PCT_RBRACKET,
    CTR_BUTTON,
    CTR_ENDLINE,
};

// The present situation has been{newline}{endline}
static s16 scenario_text_present_situation_has_been[] = {
    CHR_T,
    CHR_h,
    CHR_e,
    PCT_SPACE,
    CHR_p,
    CHR_r,
    CHR_e,
    CHR_s,
    CHR_e,
    CHR_n,
    CHR_t,
    PCT_SPACE,
    CHR_s,
    CHR_i,
    CHR_t,
    CHR_u,
    CHR_a,
    CHR_t,
    CHR_i,
    CHR_o,
    CHR_n,
    PCT_SPACE,
    CHR_h,
    CHR_a,
    CHR_s,
    PCT_SPACE,
    CHR_b,
    CHR_e,
    CHR_e,
    CHR_n,
    CTR_NEWLINE,
    CTR_ENDLINE,
};

// [{em-yellow}Saved{/em}].{button}{endline}
static s16 scenario_text_saved_complete[] = {
    PCT_LBRACKET,
    CTR_EM_YELLOW,
    CHR_S,
    CHR_a,
    CHR_v,
    CHR_e,
    CHR_d,
    CTR_CLOSE_EM,
    PCT_RBRACKET,
    PCT_PERIOD,
    CTR_BUTTON,
    CTR_ENDLINE,
};

// However, turning the {em-yellow}power off{/em}{newline}{endline}
static s16 scenario_text_however_turning_power_off[] = {
    CHR_H,
    CHR_o,
    CHR_w,
    CHR_e,
    CHR_v,
    CHR_e,
    CHR_r,
    PCT_COMMA,
    PCT_SPACE,
    CHR_t,
    CHR_u,
    CHR_r,
    CHR_n,
    CHR_i,
    CHR_n,
    CHR_g,
    PCT_SPACE,
    CHR_t,
    CHR_h,
    CHR_e,
    PCT_SPACE,
    CTR_EM_YELLOW,
    CHR_p,
    CHR_o,
    CHR_w,
    CHR_e,
    CHR_r,
    PCT_SPACE,
    CHR_o,
    CHR_f,
    CHR_f,
    CTR_CLOSE_EM,
    CTR_NEWLINE,
    CTR_ENDLINE,
};

// or {em-yellow}resetting the game{/em} will{newline}{endline}
static s16 scenario_text_or_resetting_game[] = {
    CHR_o,
    CHR_r,
    PCT_SPACE,
    CTR_EM_YELLOW,
    CHR_r,
    CHR_e,
    CHR_s,
    CHR_e,
    CHR_t,
    CHR_t,
    CHR_i,
    CHR_n,
    CHR_g,
    PCT_SPACE,
    CHR_t,
    CHR_h,
    CHR_e,
    PCT_SPACE,
    CHR_g,
    CHR_a,
    CHR_m,
    CHR_e,
    CTR_CLOSE_EM,
    PCT_SPACE,
    CHR_w,
    CHR_i,
    CHR_l,
    CHR_l,
    CTR_NEWLINE,
    CTR_ENDLINE,
};

// [Erase] the [Saved] information.{newline}{endline}
static s16 scenario_text_erase_saved_information[] = {
    PCT_LBRACKET,
    CHR_E,
    CHR_r,
    CHR_a,
    CHR_s,
    CHR_e,
    PCT_RBRACKET,
    PCT_SPACE,
    CHR_t,
    CHR_h,
    CHR_e,
    PCT_SPACE,
    PCT_LBRACKET,
    CHR_S,
    CHR_a,
    CHR_v,
    CHR_e,
    CHR_d,
    PCT_RBRACKET,
    PCT_SPACE,
    CHR_i,
    CHR_n,
    CHR_f,
    CHR_o,
    CHR_r,
    CHR_m,
    CHR_a,
    CHR_t,
    CHR_i,
    CHR_o,
    CHR_n,
    PCT_PERIOD,
    CTR_NEWLINE,
    CTR_ENDLINE,
};

// {em-yellow}Be careful{/em}.{endline}
static s16 scenario_text_be_careful[] = {
    CTR_EM_YELLOW,
    CHR_B,
    CHR_e,
    PCT_SPACE,
    CHR_c,
    CHR_a,
    CHR_r,
    CHR_e,
    CHR_f,
    CHR_u,
    CHR_l,
    CTR_CLOSE_EM,
    PCT_PERIOD,
    CTR_ENDLINE,
};

// Main Impact departure scenario (message 1f4: 066-9314.9314)
s32 scenario_code_impact_departure[] = {
    // Set up dialogue window
    STW,
    0x801c7758,
    WTS,
    0x20, // Write to RAM 801c7758 (Unknown): 0x20
    STW,
    0x801c775c,
    WTS,
    0x68, // Write to RAM 801c775c (Dialogue Window Y Pos): 0x68
    STW,
    0x801c7768,
    WTS,
    0x6, // Write to RAM 801c7768 (Dialogue Window Style): 0x6
    STW,
    0x8007785c,
    WTS,
    0x12, // Write to RAM 8007785c (Dialogue Portrait Character): 0x12 (Impact)

    // Print text: "{begin}{endline}"
    TXT,
    (s32)scenario_text_begin,

    STW,
    0x801c7770,
    WTS,
    0x1, // Write to RAM 801c7770 (Unknown): 0x1

    // Print text: "Impact:Well, I've got{newline}{endline}"
    TXT,
    (s32)scenario_text_impact_well_ive_got,

    // Print text: "      a {em-yellow}movie{/em} to
    // complete...{button}{endline}"
    TXT,
    (s32)scenario_text_movie_to_complete,

    // Print text: "{newwindow}{endline}"
    TXT,
    (s32)scenario_text_newwindow,

    // Print text: "Impact:...so I must head back{newline}{endline}"
    TXT,
    (s32)scenario_text_so_i_must_head_back,

    // Print text: "      to {em-yellow}France{/em}!{button}{endline}"
    TXT,
    (s32)scenario_text_to_france,

    // Print text: "{newwindow}{endline}"
    TXT,
    (s32)scenario_text_newwindow,

    // Print text: "Impact:If you need me again,{newline}{endline}"
    TXT,
    (s32)scenario_text_if_you_need_me_again,

    // Print text: "      {em-yellow}Au Revoir!{/em}{endline}"
    TXT,
    (s32)scenario_text_au_revoir,

    // Set Flag 032 (Defeated Thaisamba)
    SFG,
    0x88,

    // Increase value at 8015c89c by 1
    STW,
    0x8015c89c,
    INC,
    0x1,

    // Print text: "{waitinput}{end}{endline}"
    TXT,
    (s32)scenario_text_waitinput_end,

    // Play sound and wait
    STW,
    0x801c7740,
    WTS,
    0x125, // Store Value: 0x125
    ESR,
    0x8003f608, // Execute Code: 8003f608 (Play Sound)

    STW,
    0x8007785c,
    WTS,
    0x100, // Set Portrait Character: 100 (narrator)

    STW,
    0x801c7740,
    WTS,
    0x78, // Store Value: 0x78
    ESR,
    0x8003f460, // Execute Code: 8003f460 (Wait For Timer)

    // Jump to save sequence
    JMP,
    (s32)scenario_code_save_sequence,

    END,
};

// Save sequence scenario (message 1fa: 066-9f34.9f34)
s32 scenario_code_save_sequence[] = {
    STW,
    0x801c7770,
    WTS,
    0x1, // Write to RAM 801c7770 (Unknown): 0x1
    STW,
    0x8015c808,
    WTS,
    0xe, // Write to RAM 8015c808 (Unknown): 0xe
    STW,
    0x801c7768,
    WTS,
    0x0, // Write to RAM 801c7768 (Dialogue Window Style): 0x0
    STW,
    0x801c7758,
    WTS,
    0x20, // Write to RAM 801c7758 (Unknown): 0x20
    STW,
    0x801c775c,
    WTS,
    0x68, // Write to RAM 801c775c (Dialogue Window Y Pos): 0x68

    // Print text: "{begin}{endline}"
    TXT,
    (s32)scenario_text_begin,

    STW,
    0x801c7770,
    WTS,
    0x1, // Write to RAM 801c7770 (Unknown): 0x1

    // Print text: "Do you wish to save {newline}{endline}"
    TXT,
    (s32)scenario_text_do_you_wish_to_save,

    // Print text: "the game to this point in {newline}{endline}"
    TXT,
    (s32)scenario_text_the_game_to_this_point,

    // Print text: "your {em-yellow}Adventure Diary{/em}?{newline}{endline}"
    TXT,
    (s32)scenario_text_adventure_diary,

    // Begin option selection
    BOS,

    // Option 1: "Yes"
    TXT,
    (s32)scenario_text_yes_option,
    JMP,
    (s32)scenario_code_save_yes,

    // Option 2: "No"
    TXT,
    (s32)scenario_text_no_option,
    JMP,
    (s32)scenario_code_save_no,

    // End option selection
    EOS,

    // Print text: "{end}{endline}"
    TXT,
    (s32)scenario_text_end,

    END,
};

// Save "Yes" path (message 1fb: 066-9fe8.9fe8)
s32 scenario_code_save_yes[] = {
    // Check memory pak status
    LDW,
    0x800c7d00, // Read from RAM 800c7d00 (Using Controller Pak Status)
    SEQ,
    0xffffffff, // Skip Next If Equal: 0xffffffff
    JMP,
    (s32)scenario_code_save_no_pak,

    // Check flag 047 (Not Using a Memory Pak)
    // Note: Flag checking would need custom implementation

    ESR,
    0x8000b718, // Execute Code: 8000b718 (Unknown)
    CFG,
    0x6d, // Clear Flag 06d (Memory Pak Flag #7)

    // Print text: "{newwindow}{endline}"
    TXT,
    (s32)scenario_text_newwindow,

    // Print text: "Very well!{newline}{endline}"
    TXT,
    (s32)scenario_text_very_well,

    // Print text: "Your game will now be saved in{newline}{endline}"
    TXT,
    (s32)scenario_text_your_game_will_be_saved,

    // Print text: "the {em-yellow}Adventure Diary{/em}.{button}{endline}"
    TXT,
    (s32)scenario_text_the_adventure_diary,

    // Print text: "{newwindow}{endline}"
    TXT,
    (s32)scenario_text_newwindow,

    // Print text: "Press the [{em-yellow}A{/em} Button]{newline}{endline}"
    TXT,
    (s32)scenario_text_press_a_button,

    // Print text: "        when you are ready.{button}{endline}"
    TXT,
    (s32)scenario_text_when_you_are_ready,

    STW,
    0x801c7770,
    WTS,
    0x1, // Write to RAM 801c7770 (Unknown): 0x1

    // Jump to save processing
    JMP,
    (s32)scenario_code_save_processing,

    // Print text: "{end}{endline}"
    TXT,
    (s32)scenario_text_end,

    END,
};

// Save "No" path
s32 scenario_code_save_no[] = {
    STW,
    0x801c7770,
    WTS,
    0x1, // Write to RAM 801c7770 (Unknown): 0x1

    // Print text: "{end}{endline}"
    TXT,
    (s32)scenario_text_end,

    END,
};

// No memory pak path
s32 scenario_code_save_no_pak[] = {
    STW,
    0x801c7770,
    WTS,
    0x1, // Write to RAM 801c7770 (Unknown): 0x1

    // Print text: "{newwindow}{endline}"
    TXT,
    (s32)scenario_text_newwindow,

    // Print text: "The present situation will be{newline}{endline}"
    TXT,
    (s32)scenario_text_present_situation_will_be,

    // Print text: "[{em-yellow}Saved{/em}] now.{newline}{endline}"
    TXT,
    (s32)scenario_text_saved_now,

    // Print text: "  {newline}{endline}"
    TXT,
    (s32)scenario_text_space_newline,

    // Print text: "  Please press the [{em-yellow}A{/em}
    // Button]{button}{endline}"
    TXT,
    (s32)scenario_text_please_press_a_button,

    // Print text: "{newwindow}{endline}"
    TXT,
    (s32)scenario_text_newwindow,

    ESR,
    0x8000b718, // Execute Code: 8000b718 (Unknown)

    STW,
    0x801c7740,
    WTS,
    0x1e, // Store Value: 0x1e
    ESR,
    0x8003f460, // Execute Code: 8003f460 (Wait For Timer)

    STW,
    0x801c7740,
    WTS,
    0x200, // Store Value: 0x200
    ESR,
    0x8003f608, // Execute Code: 8003f608 (Play Sound)

    // Print text: "  {newline}{endline}"
    TXT,
    (s32)scenario_text_space_newline,

    // Print text: "The present situation has been{newline}{endline}"
    TXT,
    (s32)scenario_text_present_situation_has_been,

    // Print text: "[{em-yellow}Saved{/em}].{button}{endline}"
    TXT,
    (s32)scenario_text_saved_complete,

    // Print text: "{newwindow}{endline}"
    TXT,
    (s32)scenario_text_newwindow,

    // Print text: "However, turning the {em-yellow}power
    // off{/em}{newline}{endline}"
    TXT,
    (s32)scenario_text_however_turning_power_off,

    // Print text: "or {em-yellow}resetting the game{/em}
    // will{newline}{endline}"
    TXT,
    (s32)scenario_text_or_resetting_game,

    // Print text: "[Erase] the [Saved] information.{newline}{endline}"
    TXT,
    (s32)scenario_text_erase_saved_information,

    // Print text: "{em-yellow}Be careful{/em}.{endline}"
    TXT,
    (s32)scenario_text_be_careful,

    // Print text: "{waitinput}{end}{endline}"
    TXT,
    (s32)scenario_text_waitinput_end,

    END,
};

// Save processing scenario (message 1fc: 066-a078.a078)
s32 scenario_code_save_processing[] = {
    STW,
    0x801c7770,
    WTS,
    0x1, // Write to RAM 801c7770 (Unknown): 0x1

    ESR,
    0x80214d58, // Execute Code: 80214d58 (Unknown)

    // Check result and branch accordingly
    LDW,
    0x801c7750, // Read from RAM 801c7750 (Scratch)
    SEQ,
    0x0, // Skip Next If Equal: 0
    JMP,
    (s32)scenario_code_save_success,

    // Note: Additional save processing paths would be implemented here
    // based on the various save result codes in the original script

    END,
};

// Save success scenario
s32 scenario_code_save_success[] = {
    STW,
    0x801c7770,
    WTS,
    0x1, // Write to RAM 801c7770 (Unknown): 0x1

    // Print text: "{newwindow}{endline}"
    TXT,
    (s32)scenario_text_newwindow,

    STW,
    0x801c7740,
    WTS,
    0x1e, // Store Value: 0x1e
    ESR,
    0x8003f460, // Execute Code: 8003f460 (Wait For Timer)

    STW,
    0x801c7740,
    WTS,
    0x200, // Store Value: 0x200
    ESR,
    0x8003f608, // Execute Code: 8003f608 (Play Sound)

    // Print text: "Your game has been saved in{newline}{endline}"
    TXT,
    (s32)scenario_text_game_has_been_saved,

    // Print text: "the {em-yellow}Adventure Diary{/em}.{button}{endline}"
    TXT,
    (s32)scenario_text_the_adventure_diary,

    // Print text: "{end}{endline}"
    TXT,
    (s32)scenario_text_end,

    END,
};
