// Disables PLASMA from granting flags that affect game progression.
// We have to do this because we're going to be setting this up to be the hint
// system - Main Entry and Payment Logic
#include "types.h"
#include "scenario.h"

// SHOP 27 - Unknown Town Plasma - Unused - Plasma Backup Dancer
// Main entry point with BOS/EOS selection logic

// {begin}{endline}
static s16 scenario_text_0000[] = {CTR_BEGIN, CTR_ENDLINE};

//  {newline}{endline}
static s16 scenario_text_0014[] = {PCT_SPACE, CTR_NEWLINE, CTR_ENDLINE};

//        {big}{blink}P L A S M A ! {/blink}{/big}{button}{endline}
static s16 scenario_text_002B[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE,
    PCT_SPACE, PCT_SPACE, CTR_BIG, CTR_BLINK, CHR_P,
    PCT_SPACE, CHR_L, PCT_SPACE, CHR_A, PCT_SPACE,
    CHR_S, PCT_SPACE, CHR_M, PCT_SPACE, CHR_A,
    PCT_SPACE, PCT_EXCLAMATION, PCT_SPACE, CTR_CLOSE_BLINK, CTR_CLOSE_BIG,
    CTR_BUTTON, CTR_ENDLINE};

// {newwindow}{endline}
static s16 scenario_text_006F[] = {CTR_NEWWINDOW, CTR_ENDLINE};

// Plasma Man:{newline}{endline}
static s16 scenario_text_0087[] = {
    CHR_P, CHR_l, CHR_a, CHR_s, CHR_m, CHR_a, PCT_SPACE,
    CHR_M, CHR_a, CHR_n, PCT_COLON, CTR_NEWLINE, CTR_ENDLINE};

//     Howdy!  Welcome to{newline}{endline}
static s16 scenario_text_00A8[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_H, CHR_o,
    CHR_w, CHR_d, CHR_y, PCT_EXCLAMATION, PCT_SPACE, PCT_SPACE,
    CHR_W, CHR_e, CHR_l, CHR_c, CHR_o, CHR_m,
    CHR_e, PCT_SPACE, CHR_t, CHR_o, CTR_NEWLINE, CTR_ENDLINE};

//     the {em-yellow}Plasma Fortune Teller{/em}.{button}{endline}
static s16 scenario_text_00D4[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_t, CHR_h,
    CHR_e, PCT_SPACE, CTR_EM_YELLOW, CHR_P, CHR_l, CHR_a,
    CHR_s, CHR_m, CHR_a, PCT_SPACE, CHR_F, CHR_o,
    CHR_r, CHR_t, CHR_u, CHR_n, CHR_e, PCT_SPACE,
    CHR_T, CHR_e, CHR_l, CHR_l, CHR_e, CHR_r,
    CTR_CLOSE_EM, PCT_PERIOD, CTR_BUTTON, CTR_ENDLINE};

// Buy a hint for ryo, plasma!{newline}{endline}
static s16 scenario_text_012F[] = {
    CHR_B, CHR_u, CHR_y, PCT_SPACE, CHR_a, PCT_SPACE,
    CHR_h, CHR_i, CHR_n, CHR_t, PCT_SPACE, CHR_f,
    CHR_o, CHR_r, PCT_SPACE, CHR_r, CHR_y, CHR_o,
    PCT_COMMA, PCT_SPACE, CHR_p, CHR_l, CHR_a, CHR_s,
    CHR_m, CHR_a, PCT_EXCLAMATION, CTR_NEWLINE, CTR_ENDLINE};

//   {em-yellow}Big Hint (50 ryo){newline}{endline}
static s16 scenario_text_0197[] = {
    PCT_SPACE, PCT_SPACE, CTR_EM_YELLOW, CHR_B, CHR_i,
    CHR_g, PCT_SPACE, CHR_H, CHR_i, CHR_n,
    CHR_t, PCT_SPACE, PCT_LPAREN, NUM_5, NUM_0,
    PCT_SPACE, CHR_r, CHR_y, CHR_o, PCT_RPAREN,
    CTR_NEWLINE, CTR_ENDLINE};

//   {em-yellow}Small Hint (10 ryo){newline}{endline}
static s16 scenario_text_01B5[] = {
    PCT_SPACE, PCT_SPACE, CTR_EM_YELLOW, CHR_S, CHR_m,
    CHR_a, CHR_l, CHR_l, PCT_SPACE, CHR_H,
    CHR_i, CHR_n, CHR_t, PCT_SPACE, PCT_LPAREN,
    NUM_1, NUM_0, PCT_SPACE, CHR_r, CHR_y,
    CHR_o, PCT_RPAREN, CTR_NEWLINE, CTR_ENDLINE};

//   {em-yellow}No, no thank you.{newline}{endline}
static s16 scenario_text_01C9[] = {
    PCT_SPACE, PCT_SPACE, CTR_EM_YELLOW, CHR_N, CHR_o, PCT_COMMA,
    PCT_SPACE, CHR_n, CHR_o, PCT_SPACE, CHR_t, CHR_h,
    CHR_a, CHR_n, CHR_k, PCT_SPACE, CHR_y, CHR_o,
    CHR_u, PCT_PERIOD, CTR_NEWLINE, CTR_ENDLINE};

// {end}{endline}
static s16 scenario_text_01FD[] = {CTR_END, CTR_ENDLINE};

// {/em}Okay,{newline}{endline}
static s16 scenario_text_0227[] = {CTR_CLOSE_EM, CHR_O, CHR_k,
                                   CHR_a, CHR_y, PCT_COMMA,
                                   CTR_NEWLINE, CTR_ENDLINE};

// well let's get started!!{button}{endline}
static s16 scenario_text_0247[] = {
    CHR_w, CHR_e, CHR_l, CHR_l, PCT_SPACE,
    CHR_l, CHR_e, CHR_t, PCT_APOSTROPHE, CHR_s,
    PCT_SPACE, CHR_g, CHR_e, CHR_t, PCT_SPACE,
    CHR_s, CHR_t, CHR_a, CHR_r, CHR_t,
    CHR_e, CHR_d, PCT_EXCLAMATION, PCT_EXCLAMATION, CTR_BUTTON,
    CTR_ENDLINE};

// Hmmmm, abababa, hmmmm, abababa,{newline}{endline}
static s16 scenario_text_028C[] = {
    CHR_H, CHR_m, CHR_m, CHR_m, CHR_m, PCT_COMMA, PCT_SPACE, CHR_a,
    CHR_b, CHR_a, CHR_b, CHR_a, CHR_b, CHR_a, PCT_COMMA, PCT_SPACE,
    CHR_h, CHR_m, CHR_m, CHR_m, CHR_m, PCT_COMMA, PCT_SPACE, CHR_a,
    CHR_b, CHR_a, CHR_b, CHR_a, CHR_b, CHR_a, PCT_COMMA, CTR_NEWLINE,
    CTR_ENDLINE};

// hmmmm, abababa, hmmmm, abababa,{newline}{endline}
static s16 scenario_text_02C1[] = {
    CHR_h, CHR_m, CHR_m, CHR_m, CHR_m, PCT_COMMA, PCT_SPACE, CHR_a,
    CHR_b, CHR_a, CHR_b, CHR_a, CHR_b, CHR_a, PCT_COMMA, PCT_SPACE,
    CHR_h, CHR_m, CHR_m, CHR_m, CHR_m, PCT_COMMA, PCT_SPACE, CHR_a,
    CHR_b, CHR_a, CHR_b, CHR_a, CHR_b, CHR_a, PCT_COMMA, CTR_NEWLINE,
    CTR_ENDLINE};

// hmmmm, abababa, hmmmm, abababa...{button}{endline}
static s16 scenario_text_02F6[] = {
    CHR_h, CHR_m, CHR_m, CHR_m, CHR_m, PCT_COMMA,
    PCT_SPACE, CHR_a, CHR_b, CHR_a, CHR_b, CHR_a,
    CHR_b, CHR_a, PCT_COMMA, PCT_SPACE, CHR_h, CHR_m,
    CHR_m, CHR_m, CHR_m, PCT_COMMA, PCT_SPACE, CHR_a,
    CHR_b, CHR_a, CHR_b, CHR_a, CHR_b, CHR_a,
    PCT_PERIOD, PCT_PERIOD, PCT_PERIOD, CTR_BUTTON, CTR_ENDLINE};

//        {em-yellow}{blink}{big}P L A S M A !
//        {/big}{/blink}{/em}{button}{endline}
static s16 scenario_text_035B[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE,
    PCT_SPACE, PCT_SPACE, CTR_EM_YELLOW, CTR_BLINK, CTR_BIG,
    CHR_P, PCT_SPACE, CHR_L, PCT_SPACE, CHR_A,
    PCT_SPACE, CHR_S, PCT_SPACE, CHR_M, PCT_SPACE,
    CHR_A, PCT_SPACE, PCT_EXCLAMATION, PCT_SPACE, CTR_CLOSE_BIG,
    CTR_CLOSE_BLINK, CTR_CLOSE_EM, CTR_BUTTON, CTR_ENDLINE};

// {/em}Go ahead then, {newline}{endline}
static s16 scenario_text_03DF[] = {
    CTR_CLOSE_EM, CHR_G, CHR_o, PCT_SPACE, CHR_a, CHR_h,
    CHR_e, CHR_a, CHR_d, PCT_SPACE, CHR_t, CHR_h,
    CHR_e, CHR_n, PCT_COMMA, PCT_SPACE, CTR_NEWLINE, CTR_ENDLINE};

// worry for the rest of your life,{newline}{endline}
static s16 scenario_text_0409[] = {
    CHR_w, CHR_o, CHR_r, CHR_r, CHR_y, PCT_SPACE, CHR_f,
    CHR_o, CHR_r, PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE,
    CHR_r, CHR_e, CHR_s, CHR_t, PCT_SPACE, CHR_o, CHR_f,
    PCT_SPACE, CHR_y, CHR_o, CHR_u, CHR_r, PCT_SPACE, CHR_l,
    CHR_i, CHR_f, CHR_e, PCT_COMMA, CTR_NEWLINE, CTR_ENDLINE};

// plasma.{endline}
static s16 scenario_text_043F[] = {CHR_p, CHR_l, CHR_a, CHR_s,
                                   CHR_m, CHR_a, PCT_PERIOD, CTR_ENDLINE};

// {waitinput}{end}{endline}
static s16 scenario_text_0453[] = {CTR_WAITINPUT, CTR_END, CTR_ENDLINE};

// {/em}I'm not telling anything to anyone{newline}{endline}
static s16 scenario_text_0470[] = {
    CTR_CLOSE_EM, CHR_I, PCT_APOSTROPHE, CHR_m, PCT_SPACE, CHR_n, CHR_o,
    CHR_t, PCT_SPACE, CHR_t, CHR_e, CHR_l, CHR_l, CHR_i,
    CHR_n, CHR_g, PCT_SPACE, CHR_a, CHR_n, CHR_y, CHR_t,
    CHR_h, CHR_i, CHR_n, CHR_g, PCT_SPACE, CHR_t, CHR_o,
    PCT_SPACE, CHR_a, CHR_n, CHR_y, CHR_o, CHR_n, CHR_e,
    CTR_NEWLINE, CTR_ENDLINE};

// who's got no money, plasma!{endline}
static s16 scenario_text_04AD[] = {
    CHR_w, CHR_h, CHR_o, PCT_APOSTROPHE, CHR_s, PCT_SPACE,
    CHR_g, CHR_o, CHR_t, PCT_SPACE, CHR_n, CHR_o,
    PCT_SPACE, CHR_m, CHR_o, CHR_n, CHR_e, CHR_y,
    PCT_COMMA, PCT_SPACE, CHR_p, CHR_l, CHR_a, CHR_s,
    CHR_m, CHR_a, PCT_EXCLAMATION, CTR_ENDLINE};

// {waitinput}{end}{endline}
static s16 scenario_text_04D5[] = {CTR_WAITINPUT, CTR_END, CTR_ENDLINE};

// Forward declarations for other modules
extern s32 scenario_code_message_288_big_hint[];    // Implemented in plasma_big_hint.c
extern s32 scenario_code_message_288_small_hint[];  // Implemented in plasma_small_hint.c

// Forward declarations for functions defined later in this file
extern s32 scenario_code_message_288_3094[];
extern s32 scenario_code_message_288_31a8[];
extern s32 scenario_code_message_288_31d4[];

s32 scenario_code_message_288_2f98[] = {

    // Address: @2f98
    // SHOP 27 - Unknown Town Plasma - Unused - Plasma Backup Dancer

    // 2f98: Write to RAM 801c7758 (Unknown)
    STW,
    (s32)&D_801C7758_1C8358,

    // 2fa0: Store Value: 20
    WTS,
    0x20,

    // 2fa8: Write to RAM 801c775c (Dialogue Window Y Pos)
    STW,
    (s32)&D_801C775C_1C835C,

    // 2fb0: Store Value: 68
    WTS,
    0x68,

    // 2fb8: Print Text
    TXT,
    (s32)&scenario_text_0000,

    // 2fc0: Write to RAM 801c77d8 (Text Speed)
    STW,
    0x801c77d8,

    // 2fc8: Store Value: 64
    WTS,
    0x64,

    // 2fd0: Write to RAM 801c7798 (Unknown)
    STW,
    0x801c7798,

    // 2fd8: Store Value: 1
    WTS,
    0x1,

    // 2fe0: Write to RAM 801c7740 (Scratch)
    STW,
    (s32)&D_801C7740_1C8340,

    // 2fe8: Store Value: 354
    WTS,
    0x354,

    // 2ff0: Execute Code: 8003f608 (Play Sound)
    ESR,
    (s32)&func_8003F608_40208,

    // 2ff8: Print Text
    TXT,
    (s32)&scenario_text_0014,

    // 3000: Print Text
    TXT,
    (s32)&scenario_text_002B,

    // 3008: Print Text
    TXT,
    (s32)&scenario_text_006F,

    // 3010: Write to RAM 801c77d8 (Text Speed)
    STW,
    0x801c77d8,

    // 3018: Store Value: 1
    WTS,
    0x1,

    // 3020: Write to RAM 801c7798 (Unknown)
    STW,
    0x801c7798,

    // 3028: Store Value: 1
    WTS,
    0x1,

    // 3030: Print Text
    TXT,
    (s32)&scenario_text_0087,

    // 3038: Print Text
    TXT,
    (s32)&scenario_text_00A8,

    // 3040: Print Text
    TXT,
    (s32)&scenario_text_00D4,

    // 3048: Print Text
    TXT,
    (s32)&scenario_text_006F,

    // 3050: Print Text
    TXT,
    (s32)&scenario_text_012F,

    // 3060: Begin Option Selection
    BOS,

    // 3064: Print Text (Big Hint)
    TXT,
    (s32)&scenario_text_0197,

    // 306c: Jump To Big Hint System
    JMP,
    (s32)&scenario_code_message_288_big_hint,

    // 3074: Print Text (Small Hint)
    TXT,
    (s32)&scenario_text_01B5,

    // 307c: Jump To Small Hint System
    JMP,
    (s32)&scenario_code_message_288_small_hint,

    // 3084: Print Text (No, no thank you)
    TXT,
    (s32)&scenario_text_01C9,

    // 308c: Jump To @31a8
    JMP,
    (s32)&scenario_code_message_288_31a8,

    // 3094: End Option Selection
    EOS,

    // 3088: Print Text
    TXT,
    (s32)&scenario_text_01FD,

    // 3090: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_288_3094[] = {

    // Address: @3094

    // 3094: Print Text
    TXT,
    (s32)&scenario_text_006F,

    // 309c: Write to RAM 801c7770 (Unknown)
    STW,
    (s32)&D_801C7770_1C8370,

    // 30a4: Store Value: 1
    WTS,
    0x1,

    // 30ac: Write to RAM 801c7740 (Scratch)
    STW,
    (s32)&D_801C7740_1C8340,

    // 30b4: Store Value: fffffff6
    WTS,
    0xFFFFFFF6,

    // 30bc: Execute Code: 80221fd4 (Give/Take Ryo)
    ESR,
    0x80221fd4,

    // 30c4: Read from RAM 801c7750 (Scratch)
    LDW,
    0x801c7750,

    // 30cc: Skip Next If Not Equal: 1
    SNE,
    0x1,

    // 30d4: Jump To @31d4
    JMP,
    (s32)&scenario_code_message_288_31d4,

    // 30dc: Write to RAM 801c7740 (Scratch)
    STW,
    (s32)&D_801C7740_1C8340,

    // 30e4: Store Value: 23c
    WTS,
    0x23C,

    // 30ec: Execute Code: 8003f608 (Play Sound)
    ESR,
    (s32)&func_8003F608_40208,

    // 30f4: Print Text
    TXT,
    (s32)&scenario_text_0227,

    // 30fc: Print Text
    TXT,
    (s32)&scenario_text_0247,

    // 3104: Print Text
    TXT,
    (s32)&scenario_text_006F,

    // 310c: Print Text
    TXT,
    (s32)&scenario_text_028C,

    // 3114: Print Text
    TXT,
    (s32)&scenario_text_02C1,

    // 311c: Print Text
    TXT,
    (s32)&scenario_text_02F6,

    // 3124: Print Text
    TXT,
    (s32)&scenario_text_006F,

    // 312c: Write to RAM 801c77d8 (Text Speed)
    STW,
    0x801c77d8,

    // 3134: Store Value: 64
    WTS,
    0x64,

    // 313c: Write to RAM 801c7798 (Unknown)
    STW,
    0x801c7798,

    // 3144: Store Value: 1
    WTS,
    0x1,

    // 314c: Write to RAM 801c7740 (Scratch)
    STW,
    (s32)&D_801C7740_1C8340,

    // 3154: Store Value: 354
    WTS,
    0x354,

    // 315c: Execute Code: 8003f608 (Play Sound)
    ESR,
    (s32)&func_8003F608_40208,

    // 3164: Print Text
    TXT,
    (s32)&scenario_text_0014,

    // 316c: Print Text
    TXT,
    (s32)&scenario_text_035B,

    // 3174: Print Text
    TXT,
    (s32)&scenario_text_006F,

    // 317c: Write to RAM 801c77d8 (Text Speed)
    STW,
    0x801c77d8,

    // 3184: Store Value: 1
    WTS,
    0x1,

    // 318c: Write to RAM 801c7798 (Unknown)
    STW,
    0x801c7798,

    // 3194: Store Value: 1
    WTS,
    0x1,

    // 319c: This section is no longer used since hints jump to separate files
    // Jump logic now handled by external hint systems

    // 31a4: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_288_31a8[] = {

    // Address: @31a8

    // 31a8: Print Text
    TXT,
    (s32)&scenario_text_006F,

    // 31b0: Print Text
    TXT,
    (s32)&scenario_text_03DF,

    // 31b8: Print Text
    TXT,
    (s32)&scenario_text_0409,

    // 31c0: Print Text
    TXT,
    (s32)&scenario_text_043F,

    // 31c8: Print Text
    TXT,
    (s32)&scenario_text_0453,

    // 31d0: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_288_31d4[] = {

    // Address: @31d4

    // 31d4: Write to RAM 801c7740 (Scratch)
    STW,
    (s32)&D_801C7740_1C8340,

    // 31dc: Store Value: 2b2
    WTS,
    0x2B2,

    // 31e4: Execute Code: 8003f608 (Play Sound)
    ESR,
    (s32)&func_8003F608_40208,

    // 31ec: Print Text
    TXT,
    (s32)&scenario_text_0470,

    // 31f4: Print Text
    TXT,
    (s32)&scenario_text_04AD,

    // 31fc: Print Text
    TXT,
    (s32)&scenario_text_04D5,

    // 3204: End Event
    END,

    // End scenario script
    END,
};