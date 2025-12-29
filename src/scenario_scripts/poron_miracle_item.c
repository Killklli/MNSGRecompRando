// Adjusts the Poron Miracle Item Script to not set the Beat Thaisamba flag so we can prevent the submarine from despawning.
#include "scenario.h"
#include "modding.h"
#include "recomputils.h"
#include "scenario_replacer.h"

#include "common.h"

// Forward declarations
extern s32 scenario_code_poron_encounter[];
extern s32 scenario_code_goemon_response[];
extern s32 scenario_code_ebisumaru_response[];
extern s32 scenario_code_yae_response[];
extern s32 scenario_code_sasuke_response[];
extern s32 scenario_code_poron_final_response[];

// {begin}{endline}
static s16 scenario_text_0000[] = {
    CTR_BEGIN,
    CTR_ENDLINE,
};

// Poron:You have finally made it{newline}{endline}
static s16 scenario_text_0004[] = {
    CHR_P,
    CHR_o,
    CHR_r,
    CHR_o,
    CHR_n,
    PCT_COLON,
    CHR_Y,
    CHR_o,
    CHR_u,
    PCT_SPACE,
    CHR_h,
    CHR_a,
    CHR_v,
    CHR_e,
    PCT_SPACE,
    CHR_f,
    CHR_i,
    CHR_n,
    CHR_a,
    CHR_l,
    CHR_l,
    CHR_y,
    PCT_SPACE,
    CHR_m,
    CHR_a,
    CHR_d,
    CHR_e,
    PCT_SPACE,
    CHR_i,
    CHR_t,
    CTR_NEWLINE,
    CTR_ENDLINE,
};

//       as far as here to see me,{newline}{endline}
static s16 scenario_text_0044[] = {
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    CHR_a,
    CHR_s,
    PCT_SPACE,
    CHR_f,
    CHR_a,
    CHR_r,
    PCT_SPACE,
    CHR_a,
    CHR_s,
    PCT_SPACE,
    CHR_h,
    CHR_e,
    CHR_r,
    CHR_e,
    PCT_SPACE,
    CHR_t,
    CHR_o,
    PCT_SPACE,
    CHR_s,
    CHR_e,
    CHR_e,
    PCT_SPACE,
    CHR_m,
    CHR_e,
    PCT_COMMA,
    CTR_NEWLINE,
    CTR_ENDLINE,
};

//       the mighty {em-yellow}Poron{/em}!{button}{endline}
static s16 scenario_text_0088[] = {
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    CHR_t,
    CHR_h,
    CHR_e,
    PCT_SPACE,
    CHR_m,
    CHR_i,
    CHR_g,
    CHR_h,
    CHR_t,
    CHR_y,
    PCT_SPACE,
    CTR_EM_YELLOW,
    CHR_P,
    CHR_o,
    CHR_r,
    CHR_o,
    CHR_n,
    CTR_CLOSE_EM,
    PCT_EXCLAMATION,
    CTR_BUTTON,
    CTR_ENDLINE,
};

// {newwindow}{endline}
static s16 scenario_text_00C0[] = {
    CTR_NEWWINDOW,
    CTR_ENDLINE,
};

// Poron:Do you ever give up?{newline}{endline}
static s16 scenario_text_00C4[] = {
    CHR_P,
    CHR_o,
    CHR_r,
    CHR_o,
    CHR_n,
    PCT_COLON,
    CHR_D,
    CHR_o,
    PCT_SPACE,
    CHR_y,
    CHR_o,
    CHR_u,
    PCT_SPACE,
    CHR_e,
    CHR_v,
    CHR_e,
    CHR_r,
    PCT_SPACE,
    CHR_g,
    CHR_i,
    CHR_v,
    CHR_e,
    PCT_SPACE,
    CHR_u,
    CHR_p,
    PCT_QUESTION,
    CTR_NEWLINE,
    CTR_ENDLINE,
};

//       I sense you are{newline}{endline}
static s16 scenario_text_00FC[] = {
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    CHR_I,
    PCT_SPACE,
    CHR_s,
    CHR_e,
    CHR_n,
    CHR_s,
    CHR_e,
    PCT_SPACE,
    CHR_y,
    CHR_o,
    CHR_u,
    PCT_SPACE,
    CHR_a,
    CHR_r,
    CHR_e,
    CTR_NEWLINE,
    CTR_ENDLINE,
};

//       {em-yellow}a die hard fan of mine{/em}!{endline}
static s16 scenario_text_012C[] = {
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    CTR_EM_YELLOW,
    CHR_a,
    PCT_SPACE,
    CHR_d,
    CHR_i,
    CHR_e,
    PCT_SPACE,
    CHR_h,
    CHR_a,
    CHR_r,
    CHR_d,
    PCT_SPACE,
    CHR_f,
    CHR_a,
    CHR_n,
    PCT_SPACE,
    CHR_o,
    CHR_f,
    PCT_SPACE,
    CHR_m,
    CHR_i,
    CHR_n,
    CHR_e,
    CTR_CLOSE_EM,
    PCT_EXCLAMATION,
    CTR_ENDLINE,
};

// {button}{end}{endline}
static s16 scenario_text_016C[] = {
    CTR_BUTTON,
    CTR_END,
    CTR_ENDLINE,
};

// Goemon:Huh!{newline}{endline}
static s16 scenario_text_0174[] = {
    CHR_G,
    CHR_o,
    CHR_e,
    CHR_m,
    CHR_o,
    CHR_n,
    PCT_COLON,
    CHR_H,
    CHR_u,
    CHR_h,
    PCT_EXCLAMATION,
    CTR_NEWLINE,
    CTR_ENDLINE,
};

//       I didn't come here to see{newline}{endline}
static s16 scenario_text_0190[] = {
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    CHR_I,
    PCT_SPACE,
    CHR_d,
    CHR_i,
    CHR_d,
    CHR_n,
    PCT_APOSTROPHE,
    CHR_t,
    PCT_SPACE,
    CHR_c,
    CHR_o,
    CHR_m,
    CHR_e,
    PCT_SPACE,
    CHR_h,
    CHR_e,
    CHR_r,
    CHR_e,
    PCT_SPACE,
    CHR_t,
    CHR_o,
    PCT_SPACE,
    CHR_s,
    CHR_e,
    CHR_e,
    CTR_NEWLINE,
    CTR_ENDLINE,
};

//       you, I've come to get{newline}{endline}
static s16 scenario_text_01D4[] = {
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    CHR_y,
    CHR_o,
    CHR_u,
    PCT_COMMA,
    PCT_SPACE,
    CHR_I,
    PCT_APOSTROPHE,
    CHR_v,
    CHR_e,
    PCT_SPACE,
    CHR_c,
    CHR_o,
    CHR_m,
    CHR_e,
    PCT_SPACE,
    CHR_t,
    CHR_o,
    PCT_SPACE,
    CHR_g,
    CHR_e,
    CHR_t,
    CTR_NEWLINE,
    CTR_ENDLINE,
};

//       the {em-yellow}Miracle item{/em}!{button}{end}{endline}
static s16 scenario_text_0210[] = {
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    CHR_t,
    CHR_h,
    CHR_e,
    PCT_SPACE,
    CTR_EM_YELLOW,
    CHR_M,
    CHR_i,
    CHR_r,
    CHR_a,
    CHR_c,
    CHR_l,
    CHR_e,
    PCT_SPACE,
    CHR_i,
    CHR_t,
    CHR_e,
    CHR_m,
    CTR_CLOSE_EM,
    PCT_EXCLAMATION,
    CTR_BUTTON,
    CTR_END,
    CTR_ENDLINE,
};

// Ebisumaru:What a joker!{newline}{endline}
static s16 scenario_text_0248[] = {
    CHR_E,
    CHR_b,
    CHR_i,
    CHR_s,
    CHR_u,
    CHR_m,
    CHR_a,
    CHR_r,
    CHR_u,
    PCT_COLON,
    CHR_W,
    CHR_h,
    CHR_a,
    CHR_t,
    PCT_SPACE,
    CHR_a,
    PCT_SPACE,
    CHR_j,
    CHR_o,
    CHR_k,
    CHR_e,
    CHR_r,
    PCT_EXCLAMATION,
    CTR_NEWLINE,
    CTR_ENDLINE,
};

//        I'm not here to see you,{newline}{endline}
static s16 scenario_text_027C[] = {
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    CHR_I,
    PCT_APOSTROPHE,
    CHR_m,
    PCT_SPACE,
    CHR_n,
    CHR_o,
    CHR_t,
    PCT_SPACE,
    CHR_h,
    CHR_e,
    CHR_r,
    CHR_e,
    PCT_SPACE,
    CHR_t,
    CHR_o,
    PCT_SPACE,
    CHR_s,
    CHR_e,
    CHR_e,
    PCT_SPACE,
    CHR_y,
    CHR_o,
    CHR_u,
    PCT_COMMA,
    CTR_NEWLINE,
    CTR_ENDLINE,
};

//        I'm here to get{newline}{endline}
static s16 scenario_text_02C0[] = {
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    CHR_I,
    PCT_APOSTROPHE,
    CHR_m,
    PCT_SPACE,
    CHR_h,
    CHR_e,
    CHR_r,
    CHR_e,
    PCT_SPACE,
    CHR_t,
    CHR_o,
    PCT_SPACE,
    CHR_g,
    CHR_e,
    CHR_t,
    CTR_NEWLINE,
    CTR_ENDLINE,
};

//        the {em-yellow}Miracle item{/em}!{button}{end}{endline}
static s16 scenario_text_02F0[] = {
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    CHR_t,
    CHR_h,
    CHR_e,
    PCT_SPACE,
    CTR_EM_YELLOW,
    CHR_M,
    CHR_i,
    CHR_r,
    CHR_a,
    CHR_c,
    CHR_l,
    CHR_e,
    PCT_SPACE,
    CHR_i,
    CHR_t,
    CHR_e,
    CHR_m,
    CTR_CLOSE_EM,
    PCT_EXCLAMATION,
    CTR_BUTTON,
    CTR_END,
    CTR_ENDLINE,
};

// Yae:I've come here, not to see{newline}{endline}
static s16 scenario_text_032C[] = {
    CHR_Y,
    CHR_a,
    CHR_e,
    PCT_COLON,
    CHR_I,
    PCT_APOSTROPHE,
    CHR_v,
    CHR_e,
    PCT_SPACE,
    CHR_c,
    CHR_o,
    CHR_m,
    CHR_e,
    PCT_SPACE,
    CHR_h,
    CHR_e,
    CHR_r,
    CHR_e,
    PCT_COMMA,
    PCT_SPACE,
    CHR_n,
    CHR_o,
    CHR_t,
    PCT_SPACE,
    CHR_t,
    CHR_o,
    PCT_SPACE,
    CHR_s,
    CHR_e,
    CHR_e,
    CTR_NEWLINE,
    CTR_ENDLINE,
};

//       you, but to find{newline}{endline}
static s16 scenario_text_036C[] = {
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    CHR_y,
    CHR_o,
    CHR_u,
    PCT_COMMA,
    PCT_SPACE,
    CHR_b,
    CHR_u,
    CHR_t,
    PCT_SPACE,
    CHR_t,
    CHR_o,
    PCT_SPACE,
    CHR_f,
    CHR_i,
    CHR_n,
    CHR_d,
    CTR_NEWLINE,
    CTR_ENDLINE,
};

// Sasuke:Don't misunderstand!{newline}{endline}
static s16 scenario_text_039C[] = {
    CHR_S,
    CHR_a,
    CHR_s,
    CHR_u,
    CHR_k,
    CHR_e,
    PCT_COLON,
    CHR_D,
    CHR_o,
    CHR_n,
    PCT_APOSTROPHE,
    CHR_t,
    PCT_SPACE,
    CHR_m,
    CHR_i,
    CHR_s,
    CHR_u,
    CHR_n,
    CHR_d,
    CHR_e,
    CHR_r,
    CHR_s,
    CHR_t,
    CHR_a,
    CHR_n,
    CHR_d,
    PCT_EXCLAMATION,
    CTR_NEWLINE,
    CTR_ENDLINE,
};

//       I have come here for{newline}{endline}
static s16 scenario_text_03D8[] = {
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    CHR_I,
    PCT_SPACE,
    CHR_h,
    CHR_a,
    CHR_v,
    CHR_e,
    PCT_SPACE,
    CHR_c,
    CHR_o,
    CHR_m,
    CHR_e,
    PCT_SPACE,
    CHR_h,
    CHR_e,
    CHR_r,
    CHR_e,
    PCT_SPACE,
    CHR_f,
    CHR_o,
    CHR_r,
    CTR_NEWLINE,
    CTR_ENDLINE,
};

// Poron:You're saying...{newline}{endline}
static s16 scenario_text_0410[] = {
    CHR_P,
    CHR_o,
    CHR_r,
    CHR_o,
    CHR_n,
    PCT_COLON,
    CHR_Y,
    CHR_o,
    CHR_u,
    PCT_APOSTROPHE,
    CHR_r,
    CHR_e,
    PCT_SPACE,
    CHR_s,
    CHR_a,
    CHR_y,
    CHR_i,
    CHR_n,
    CHR_g,
    PCT_PERIOD,
    PCT_PERIOD,
    PCT_PERIOD,
    CTR_NEWLINE,
    CTR_ENDLINE,
};

//       not for me... but{newline}{endline}
static s16 scenario_text_0440[] = {
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    CHR_n,
    CHR_o,
    CHR_t,
    PCT_SPACE,
    CHR_f,
    CHR_o,
    CHR_r,
    PCT_SPACE,
    CHR_m,
    CHR_e,
    PCT_PERIOD,
    PCT_PERIOD,
    PCT_PERIOD,
    PCT_SPACE,
    CHR_b,
    CHR_u,
    CHR_t,
    CTR_NEWLINE,
    CTR_ENDLINE,
};

//       the {em-yellow}Miracle...{/em}is that so?{button}{endline}
static s16 scenario_text_0474[] = {
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    CHR_t,
    CHR_h,
    CHR_e,
    PCT_SPACE,
    CTR_EM_YELLOW,
    CHR_M,
    CHR_i,
    CHR_r,
    CHR_a,
    CHR_c,
    CHR_l,
    CHR_e,
    PCT_PERIOD,
    PCT_PERIOD,
    PCT_PERIOD,
    CTR_CLOSE_EM,
    CHR_i,
    CHR_s,
    PCT_SPACE,
    CHR_t,
    CHR_h,
    CHR_a,
    CHR_t,
    PCT_SPACE,
    CHR_s,
    CHR_o,
    PCT_QUESTION,
    CTR_BUTTON,
    CTR_ENDLINE,
};

// Poron:Tsk, tsk... it's too bad.{button}{endline}
static s16 scenario_text_04BC[] = {
    CHR_P,
    CHR_o,
    CHR_r,
    CHR_o,
    CHR_n,
    PCT_COLON,
    CHR_T,
    CHR_s,
    CHR_k,
    PCT_COMMA,
    PCT_SPACE,
    CHR_t,
    CHR_s,
    CHR_k,
    PCT_PERIOD,
    PCT_PERIOD,
    PCT_PERIOD,
    PCT_SPACE,
    CHR_i,
    CHR_t,
    PCT_APOSTROPHE,
    CHR_s,
    PCT_SPACE,
    CHR_t,
    CHR_o,
    CHR_o,
    PCT_SPACE,
    CHR_b,
    CHR_a,
    CHR_d,
    PCT_PERIOD,
    CTR_BUTTON,
    CTR_ENDLINE,
};

// Poron:Last time I was in{newline}{endline}
static s16 scenario_text_0500[] = {
    CHR_P,
    CHR_o,
    CHR_r,
    CHR_o,
    CHR_n,
    PCT_COLON,
    CHR_L,
    CHR_a,
    CHR_s,
    CHR_t,
    PCT_SPACE,
    CHR_t,
    CHR_i,
    CHR_m,
    CHR_e,
    PCT_SPACE,
    CHR_I,
    PCT_SPACE,
    CHR_w,
    CHR_a,
    CHR_s,
    PCT_SPACE,
    CHR_i,
    CHR_n,
    CTR_NEWLINE,
    CTR_ENDLINE,
};

//       the{em-yellow} Kansai Region{/em} on{newline}{endline}
static s16 scenario_text_0534[] = {
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    CHR_t,
    CHR_h,
    CHR_e,
    CTR_EM_YELLOW,
    PCT_SPACE,
    CHR_K,
    CHR_a,
    CHR_n,
    CHR_s,
    CHR_a,
    CHR_i,
    PCT_SPACE,
    CHR_R,
    CHR_e,
    CHR_g,
    CHR_i,
    CHR_o,
    CHR_n,
    CTR_CLOSE_EM,
    PCT_SPACE,
    CHR_o,
    CHR_n,
    CTR_NEWLINE,
    CTR_ENDLINE,
};

//       {em-yellow}a vacation{/em}...{button}{endline}
static s16 scenario_text_0570[] = {
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    CTR_EM_YELLOW,
    CHR_a,
    PCT_SPACE,
    CHR_v,
    CHR_a,
    CHR_c,
    CHR_a,
    CHR_t,
    CHR_i,
    CHR_o,
    CHR_n,
    CTR_CLOSE_EM,
    PCT_PERIOD,
    PCT_PERIOD,
    PCT_PERIOD,
    CTR_BUTTON,
    CTR_ENDLINE,
};

// Poron:...I dropped it somewhere{newline}{endline}
static s16 scenario_text_05A0[] = {
    CHR_P,
    CHR_o,
    CHR_r,
    CHR_o,
    CHR_n,
    PCT_COLON,
    PCT_PERIOD,
    PCT_PERIOD,
    PCT_PERIOD,
    CHR_I,
    PCT_SPACE,
    CHR_d,
    CHR_r,
    CHR_o,
    CHR_p,
    CHR_p,
    CHR_e,
    CHR_d,
    PCT_SPACE,
    CHR_i,
    CHR_t,
    PCT_SPACE,
    CHR_s,
    CHR_o,
    CHR_m,
    CHR_e,
    CHR_w,
    CHR_h,
    CHR_e,
    CHR_r,
    CHR_e,
    CTR_NEWLINE,
    CTR_ENDLINE,
};

//       in the [{em-yellow}Zazen Town{/em}].{newline}{endline}
static s16 scenario_text_05E4[] = {
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    CHR_i,
    CHR_n,
    PCT_SPACE,
    CHR_t,
    CHR_h,
    CHR_e,
    PCT_SPACE,
    PCT_LBRACKET,
    CTR_EM_YELLOW,
    CHR_Z,
    CHR_a,
    CHR_z,
    CHR_e,
    CHR_n,
    PCT_SPACE,
    CHR_T,
    CHR_o,
    CHR_w,
    CHR_n,
    CTR_CLOSE_EM,
    PCT_RBRACKET,
    PCT_PERIOD,
    CTR_NEWLINE,
    CTR_ENDLINE,
};

// Ebisumaru:Gasp!{newline}{endline}
static s16 scenario_text_0620[] = {
    CHR_E,
    CHR_b,
    CHR_i,
    CHR_s,
    CHR_u,
    CHR_m,
    CHR_a,
    CHR_r,
    CHR_u,
    PCT_COLON,
    CHR_G,
    CHR_a,
    CHR_s,
    CHR_p,
    PCT_EXCLAMATION,
    CTR_NEWLINE,
    CTR_ENDLINE,
};

//        You've gotta be kidding!{button}{endline}
static s16 scenario_text_0644[] = {
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    CHR_Y,
    CHR_o,
    CHR_u,
    PCT_APOSTROPHE,
    CHR_v,
    CHR_e,
    PCT_SPACE,
    CHR_g,
    CHR_o,
    CHR_t,
    CHR_t,
    CHR_a,
    PCT_SPACE,
    CHR_b,
    CHR_e,
    PCT_SPACE,
    CHR_k,
    CHR_i,
    CHR_d,
    CHR_d,
    CHR_i,
    CHR_n,
    CHR_g,
    PCT_EXCLAMATION,
    CTR_BUTTON,
    CTR_ENDLINE,
};

// Yae:Well, if he's not kidding,{newline}{endline}
static s16 scenario_text_0688[] = {
    CHR_Y,
    CHR_a,
    CHR_e,
    PCT_COLON,
    CHR_W,
    CHR_e,
    CHR_l,
    CHR_l,
    PCT_COMMA,
    PCT_SPACE,
    CHR_i,
    CHR_f,
    PCT_SPACE,
    CHR_h,
    CHR_e,
    PCT_APOSTROPHE,
    CHR_s,
    PCT_SPACE,
    CHR_n,
    CHR_o,
    CHR_t,
    PCT_SPACE,
    CHR_k,
    CHR_i,
    CHR_d,
    CHR_d,
    CHR_i,
    CHR_n,
    CHR_g,
    PCT_COMMA,
    CTR_NEWLINE,
    CTR_ENDLINE,
};

//       we must return to{newline}{endline}
static s16 scenario_text_06C8[] = {
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    CHR_w,
    CHR_e,
    PCT_SPACE,
    CHR_m,
    CHR_u,
    CHR_s,
    CHR_t,
    PCT_SPACE,
    CHR_r,
    CHR_e,
    CHR_t,
    CHR_u,
    CHR_r,
    CHR_n,
    PCT_SPACE,
    CHR_t,
    CHR_o,
    CTR_NEWLINE,
    CTR_ENDLINE,
};

//       [{em-yellow}Zazen Town{/em}] at once!{endline}
static s16 scenario_text_06FC[] = {
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    PCT_LBRACKET,
    CTR_EM_YELLOW,
    CHR_Z,
    CHR_a,
    CHR_z,
    CHR_e,
    CHR_n,
    PCT_SPACE,
    CHR_T,
    CHR_o,
    CHR_w,
    CHR_n,
    CTR_CLOSE_EM,
    PCT_RBRACKET,
    PCT_SPACE,
    CHR_a,
    CHR_t,
    PCT_SPACE,
    CHR_o,
    CHR_n,
    CHR_c,
    CHR_e,
    PCT_EXCLAMATION,
    CTR_ENDLINE,
};

// {waitinput}{end}{endline}
static s16 scenario_text_0738[] = {
    CTR_WAITINPUT,
    CTR_END,
    CTR_ENDLINE,
};

s32 scenario_code_poron_encounter[] = {

    // Store the next value in g_scenario_text_window_style
    STW,
    (s32)&D_801C7768_1C8368,

    // Store the value 8
    WTS,
    0x8,

    // Store the next value in g_scenario_character_portrait
    STW,
    (s32)&D_8007785C_7845C,

    // Store the value 10
    WTS,
    0x10,

    // Print text block "{begin}{endline}"
    TXT,
    (s32)&scenario_text_0000,

    // Store the next value in D_801C7770_1C8370
    STW,
    (s32)&D_801C7770_1C8370,

    // Store the value 1
    WTS,
    0x1,

    // Print text block "Poron:You have finally made it{newline}{endline}"
    TXT,
    (s32)&scenario_text_0004,

    // Print text block "      as far as here to see me,{newline}{endline}"
    TXT,
    (s32)&scenario_text_0044,

    // Print text block "      the mighty {em-yellow}Poron{/em}!{button}{endline}"
    TXT,
    (s32)&scenario_text_0088,

    // Print text block "{newwindow}{endline}"
    TXT,
    (s32)&scenario_text_00C0,

    // Print text block "Poron:Do you ever give up?{newline}{endline}"
    TXT,
    (s32)&scenario_text_00C4,

    // Print text block "      I sense you are{newline}{endline}"
    TXT,
    (s32)&scenario_text_00FC,

    // Print text block "      {em-yellow}a die hard fan of mine{/em}!{endline}"
    TXT,
    (s32)&scenario_text_012C,

    // Store the next value in g_scenario_scratch_pad_0
    STW,
    (s32)&D_801C7740_1C8340,

    // Store the value 141
    WTS,
    0x141,

    // Execute subroutine at scenario_play_sound
    ESR,
    (s32)&func_8003F608_40208,

    // Print text block "{button}{end}{endline}"
    TXT,
    (s32)&scenario_text_016C,

    // Execute subroutine at scenario_get_current_character
    ESR,
    (s32)&func_8003F594_40194,

    // Load word from g_scenario_scratch_pad_0[4]
    LDW,
    (s32)&D_801C7740_1C8340[4],

    // Skip next if not equal to 0
    SNE,
    0x0,

    // Jump to goemon_response
    JMP,
    (s32)&scenario_code_goemon_response,

    // Load word from g_scenario_scratch_pad_0[4]
    LDW,
    (s32)&D_801C7740_1C8340[4],

    // Skip next if not equal to 1
    SNE,
    0x1,

    // Jump to ebisumaru_response
    JMP,
    (s32)&scenario_code_ebisumaru_response,

    // Load word from g_scenario_scratch_pad_0[4]
    LDW,
    (s32)&D_801C7740_1C8340[4],

    // Skip next if not equal to 3
    SNE,
    0x3,

    // Jump to yae_response
    JMP,
    (s32)&scenario_code_yae_response,

    // Load word from g_scenario_scratch_pad_0[4]
    LDW,
    (s32)&D_801C7740_1C8340[4],

    // Skip next if not equal to 2
    SNE,
    0x2,

    // Jump to sasuke_response
    JMP,
    (s32)&scenario_code_sasuke_response,

    // End scenario script
    END,
};

s32 scenario_code_goemon_response[] = {

    // Store the next value in g_scenario_text_window_style
    STW,
    (s32)&D_801C7768_1C8368,

    // Store the value 7
    WTS,
    0x7,

    // Store the next value in g_scenario_character_portrait
    STW,
    (s32)&D_8007785C_7845C,

    // Store the value 0
    WTS,
    0x0,

    // Print text block "{begin}{endline}"
    TXT,
    (s32)&scenario_text_0000,

    // Store the next value in D_801C7770_1C8370
    STW,
    (s32)&D_801C7770_1C8370,

    // Store the value 1
    WTS,
    0x1,

    // Print text block "Goemon:Huh!{newline}{endline}"
    TXT,
    (s32)&scenario_text_0174,

    // Print text block "      I didn't come here to see{newline}{endline}"
    TXT,
    (s32)&scenario_text_0190,

    // Print text block "      you, I've come to get{newline}{endline}"
    TXT,
    (s32)&scenario_text_01D4,

    // Print text block "      the {em-yellow}Miracle item{/em}!{button}{end}{endline}"
    TXT,
    (s32)&scenario_text_0210,

    // Jump to poron_final_response
    JMP,
    (s32)&scenario_code_poron_final_response,

    // End scenario script
    END,
};

s32 scenario_code_ebisumaru_response[] = {

    // Store the next value in g_scenario_text_window_style
    STW,
    (s32)&D_801C7768_1C8368,

    // Store the value 7
    WTS,
    0x7,

    // Store the next value in g_scenario_character_portrait
    STW,
    (s32)&D_8007785C_7845C,

    // Store the value 2
    WTS,
    0x2,

    // Print text block "{begin}{endline}"
    TXT,
    (s32)&scenario_text_0000,

    // Store the next value in D_801C7770_1C8370
    STW,
    (s32)&D_801C7770_1C8370,

    // Store the value 1
    WTS,
    0x1,

    // Print text block "Ebisumaru:What a joker!{newline}{endline}"
    TXT,
    (s32)&scenario_text_0248,

    // Print text block "       I'm not here to see you,{newline}{endline}"
    TXT,
    (s32)&scenario_text_027C,

    // Print text block "       I'm here to get{newline}{endline}"
    TXT,
    (s32)&scenario_text_02C0,

    // Print text block "       the {em-yellow}Miracle item{/em}!{button}{end}{endline}"
    TXT,
    (s32)&scenario_text_02F0,

    // Jump to poron_final_response
    JMP,
    (s32)&scenario_code_poron_final_response,

    // End scenario script
    END,
};

s32 scenario_code_yae_response[] = {

    // Store the next value in g_scenario_text_window_style
    STW,
    (s32)&D_801C7768_1C8368,

    // Store the value 7
    WTS,
    0x7,

    // Store the next value in g_scenario_character_portrait
    STW,
    (s32)&D_8007785C_7845C,

    // Store the value 6
    WTS,
    0x6,

    // Print text block "{begin}{endline}"
    TXT,
    (s32)&scenario_text_0000,

    // Store the next value in D_801C7770_1C8370
    STW,
    (s32)&D_801C7770_1C8370,

    // Store the value 1
    WTS,
    0x1,

    // Print text block "Yae:I've come here, not to see{newline}{endline}"
    TXT,
    (s32)&scenario_text_032C,

    // Print text block "      you, but to find{newline}{endline}"
    TXT,
    (s32)&scenario_text_036C,

    // Print text block "      the {em-yellow}Miracle item{/em}!{button}{end}{endline}"
    TXT,
    (s32)&scenario_text_0210,

    // Jump to poron_final_response
    JMP,
    (s32)&scenario_code_poron_final_response,

    // End scenario script
    END,
};

s32 scenario_code_sasuke_response[] = {

    // Store the next value in g_scenario_text_window_style
    STW,
    (s32)&D_801C7768_1C8368,

    // Store the value 7
    WTS,
    0x7,

    // Store the next value in g_scenario_character_portrait
    STW,
    (s32)&D_8007785C_7845C,

    // Store the value 4
    WTS,
    0x4,

    // Print text block "{begin}{endline}"
    TXT,
    (s32)&scenario_text_0000,

    // Store the next value in D_801C7770_1C8370
    STW,
    (s32)&D_801C7770_1C8370,

    // Store the value 1
    WTS,
    0x1,

    // Print text block "Sasuke:Don't misunderstand!{newline}{endline}"
    TXT,
    (s32)&scenario_text_039C,

    // Print text block "      I have come here for{newline}{endline}"
    TXT,
    (s32)&scenario_text_03D8,

    // Print text block "      the {em-yellow}Miracle item{/em}!{button}{end}{endline}"
    TXT,
    (s32)&scenario_text_0210,

    // Jump to poron_final_response
    JMP,
    (s32)&scenario_code_poron_final_response,

    // End scenario script
    END,
};

s32 scenario_code_poron_final_response[] = {

    // Store the next value in g_scenario_text_window_style
    STW,
    (s32)&D_801C7768_1C8368,

    // Store the value 9
    WTS,
    0x9,

    // Store the next value in g_scenario_character_portrait
    STW,
    (s32)&D_8007785C_7845C,

    // Store the value 10
    WTS,
    0x10,

    // Print text block "{begin}{endline}"
    TXT,
    (s32)&scenario_text_0000,

    // Store the next value in D_801C7770_1C8370
    STW,
    (s32)&D_801C7770_1C8370,

    // Store the value 1
    WTS,
    0x1,

    // Print text block "Poron:You're saying...{newline}{endline}"
    TXT,
    (s32)&scenario_text_0410,

    // Print text block "      not for me... but{newline}{endline}"
    TXT,
    (s32)&scenario_text_0440,

    // Print text block "      the {em-yellow}Miracle...{/em}is that so?{button}{endline}"
    TXT,
    (s32)&scenario_text_0474,

    // Print text block "{newwindow}{endline}"
    TXT,
    (s32)&scenario_text_00C0,

    // Print text block "Poron:Tsk, tsk... it's too bad.{button}{endline}"
    TXT,
    (s32)&scenario_text_04BC,

    // Print text block "{newwindow}{endline}"
    TXT,
    (s32)&scenario_text_00C0,

    // Print text block "Poron:Last time I was in{newline}{endline}"
    TXT,
    (s32)&scenario_text_0500,

    // Print text block "      the{em-yellow} Kansai Region{/em} on{newline}{endline}"
    TXT,
    (s32)&scenario_text_0534,

    // Print text block "      {em-yellow}a vacation{/em}...{button}{endline}"
    TXT,
    (s32)&scenario_text_0570,

    // Print text block "{newwindow}{endline}"
    TXT,
    (s32)&scenario_text_00C0,

    // Print text block "Poron:...I dropped it somewhere{newline}{endline}"
    TXT,
    (s32)&scenario_text_05A0,

    // Print text block "      in the [{em-yellow}Zazen Town{/em}].{newline}{endline}"
    TXT,
    (s32)&scenario_text_05E4,

    // Store the next value in g_scenario_scratch_pad_0
    STW,
    (s32)&D_801C7740_1C8340,

    // Store the value 141
    WTS,
    0x141,

    // Execute subroutine at scenario_play_sound
    ESR,
    (s32)&func_8003F608_40208,

    // Print text block "{button}{end}{endline}"
    TXT,
    (s32)&scenario_text_016C,

    // // Set flag 032 (Defeated Thaisamba)
    SFG,
    0x88,

    // Store the next value in g_scenario_text_window_style
    STW,
    (s32)&D_801C7768_1C8368,

    // Store the value 7
    WTS,
    0x7,

    // Store the next value in g_scenario_character_portrait
    STW,
    (s32)&D_8007785C_7845C,

    // Store the value 2
    WTS,
    0x2,

    // Print text block "{begin}{endline}"
    TXT,
    (s32)&scenario_text_0000,

    // Store the next value in D_801C7770_1C8370
    STW,
    (s32)&D_801C7770_1C8370,

    // Store the value 1
    WTS,
    0x1,

    // Print text block "Ebisumaru:Gasp!{newline}{endline}"
    TXT,
    (s32)&scenario_text_0620,

    // Print text block "       You've gotta be kidding!{button}{endline}"
    TXT,
    (s32)&scenario_text_0644,

    // Print text block "{newwindow}{endline}"
    TXT,
    (s32)&scenario_text_00C0,

    // Store the next value in g_scenario_character_portrait
    STW,
    (s32)&D_8007785C_7845C,

    // Store the value 6
    WTS,
    0x6,

    // Print text block "Yae:Well, if he's not kidding,{newline}{endline}"
    TXT,
    (s32)&scenario_text_0688,

    // Print text block "      we must return to{newline}{endline}"
    TXT,
    (s32)&scenario_text_06C8,

    // Print text block "      [{em-yellow}Zazen Town{/em}] at once!{endline}"
    TXT,
    (s32)&scenario_text_06FC,

    // Print text block "{waitinput}{end}{endline}"
    TXT,
    (s32)&scenario_text_0738,

    // End scenario script
    END,
};