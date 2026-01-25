#include "common.h"
#include "scenario.h"

// External scenario code declarations
extern s32 scenario_code_message_227_3a14[];

// Address: @3a14

// {begin}{endline}
static s16 scenario_text_0000[] = {CTR_BEGIN, CTR_ENDLINE};

// Wise Man:Here, take {em-yellow}this{/em}!{button}{end}{endline}
static s16 scenario_text_0014[] = {
    CHR_W, CHR_i, CHR_s, CHR_e, PCT_SPACE, CHR_M,
    CHR_a, CHR_n, PCT_COLON, CHR_H, CHR_e, CHR_r,
    CHR_e, PCT_COMMA, PCT_SPACE, CHR_t, CHR_a, CHR_k,
    CHR_e, PCT_SPACE, CTR_EM_YELLOW, CHR_t, CHR_h, CHR_i,
    CHR_s, CTR_CLOSE_EM, PCT_EXCLAMATION, CTR_BUTTON, CTR_END, CTR_ENDLINE};

// {begin}{endline}
static s16 scenario_text_0057[] = {CTR_BEGIN, CTR_ENDLINE};

// The power of the {em-yellow}weapons{/em}{newline}{endline}
static s16 scenario_text_006B[] = {
    CHR_T, CHR_h, CHR_e, PCT_SPACE, CHR_p, CHR_o,
    CHR_w, CHR_e, CHR_r, PCT_SPACE, CHR_o, CHR_f,
    PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE, CTR_EM_YELLOW,
    CHR_w, CHR_e, CHR_a, CHR_p, CHR_o, CHR_n,
    CHR_s, CTR_CLOSE_EM, CTR_NEWLINE, CTR_ENDLINE};

// belonging to Goemon and the allies{newline}{endline}
static s16 scenario_text_00A9[] = {
    CHR_b, CHR_e, CHR_l, CHR_o, CHR_n, CHR_g,
    CHR_i, CHR_n, CHR_g, PCT_SPACE, CHR_t, CHR_o,
    PCT_SPACE, CHR_G, CHR_o, CHR_e, CHR_m, CHR_o,
    CHR_n, PCT_SPACE, CHR_a, CHR_n, CHR_d, PCT_SPACE,
    CHR_t, CHR_h, CHR_e, PCT_SPACE, CHR_a, CHR_l,
    CHR_l, CHR_i, CHR_e, CHR_s, CTR_NEWLINE, CTR_ENDLINE};

//      has increased to {em-yellow}[Level 3]{/em}!{newline}{endline}
static s16 scenario_text_00E1[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE,
    CHR_h, CHR_a, CHR_s, PCT_SPACE, CHR_i,
    CHR_n, CHR_c, CHR_r, CHR_e, CHR_a,
    CHR_s, CHR_e, CHR_d, PCT_SPACE, CHR_t,
    CHR_o, PCT_SPACE, CTR_EM_YELLOW, PCT_LBRACKET, CHR_L,
    CHR_e, CHR_v, CHR_e, CHR_l, PCT_SPACE,
    NUM_3, PCT_RBRACKET, CTR_CLOSE_EM, PCT_EXCLAMATION, CTR_NEWLINE,
    CTR_ENDLINE};

// {button}{endline}
static s16 scenario_text_0127[] = {CTR_BUTTON, CTR_ENDLINE};

// {newwindow}{endline}
static s16 scenario_text_013C[] = {CTR_NEWWINDOW, CTR_ENDLINE};

//  {newline}{endline}
static s16 scenario_text_0154[] = {PCT_SPACE, CTR_NEWLINE, CTR_ENDLINE};

// With these {em-yellow}weapons{/em},{newline}{endline}
static s16 scenario_text_016B[] = {
    CHR_W, CHR_i, CHR_t, CHR_h, PCT_SPACE, CHR_t,
    CHR_h, CHR_e, CHR_s, CHR_e, PCT_SPACE, CTR_EM_YELLOW,
    CHR_w, CHR_e, CHR_a, CHR_p, CHR_o, CHR_n,
    CHR_s, CTR_CLOSE_EM, PCT_COMMA, CTR_NEWLINE, CTR_ENDLINE};

// even rigid {em-yellow}doors{/em} can be destroyed!{button}{end}{endline}
static s16 scenario_text_01A4[] = {
    CHR_e, CHR_v, CHR_e, CHR_n, PCT_SPACE, CHR_r,
    CHR_i, CHR_g, CHR_i, CHR_d, PCT_SPACE, CTR_EM_YELLOW,
    CHR_d, CHR_o, CHR_o, CHR_r, CHR_s, CTR_CLOSE_EM,
    PCT_SPACE, CHR_c, CHR_a, CHR_n, PCT_SPACE, CHR_b,
    CHR_e, PCT_SPACE, CHR_d, CHR_e, CHR_s, CHR_t,
    CHR_r, CHR_o, CHR_y, CHR_e, CHR_d, PCT_EXCLAMATION,
    CTR_BUTTON, CTR_END, CTR_ENDLINE};

// {begin}{endline}
static s16 scenario_text_01F0[] = {CTR_BEGIN, CTR_ENDLINE};

// Ebisumaru:Don't you feel{newline}{endline}
static s16 scenario_text_0204[] = {
    CHR_E, CHR_b, CHR_i, CHR_s, CHR_u, CHR_m,
    CHR_a, CHR_r, CHR_u, PCT_COLON, CHR_D, CHR_o,
    CHR_n, PCT_APOSTROPHE, CHR_t, PCT_SPACE, CHR_y, CHR_o,
    CHR_u, PCT_SPACE, CHR_f, CHR_e, CHR_e, CHR_l,
    CTR_NEWLINE, CTR_ENDLINE};

//        our journey is taking{newline}{endline}
static s16 scenario_text_0232[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE,
    PCT_SPACE, CHR_o, CHR_u, CHR_r, PCT_SPACE, CHR_j,
    CHR_o, CHR_u, CHR_r, CHR_n, CHR_e, CHR_y,
    PCT_SPACE, CHR_i, CHR_s, PCT_SPACE, CHR_t, CHR_a,
    CHR_k, CHR_i, CHR_n, CHR_g, CTR_NEWLINE, CTR_ENDLINE};

//        some wild turns?!{endline}
static s16 scenario_text_0264[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE,
    PCT_SPACE, PCT_SPACE, CHR_s, CHR_o, CHR_m,
    CHR_e, PCT_SPACE, CHR_w, CHR_i, CHR_l,
    CHR_d, PCT_SPACE, CHR_t, CHR_u, CHR_r,
    CHR_n, CHR_s, PCT_QUESTION, PCT_EXCLAMATION, CTR_ENDLINE};

// {waitinput}{end}{endline}
static s16 scenario_text_0289[] = {CTR_WAITINPUT, CTR_END, CTR_ENDLINE};

s32 scenario_code_message_227_3a14[] = {

    // Address: @3a14

    // 3a14: Set Flag 09c (Witch Cutscene Flag #2)
    SFG,
    0x9C,

    // 3a1c: Write to RAM 801c7768 (Dialogue Window Style)
    STW,
    (s32)&D_801C7768_1C8368,

    // 3a24: Store Value: 1
    WTS,
    0x1,

    // 3a2c: Write to RAM 8007785c (Dialogue Portrait Character)
    STW,
    (s32)&D_8007785C_7845C,

    // 3a34: Store Value: 18
    WTS,
    0x18,

    // 3a3c: Print Text
    TXT,
    (s32)&scenario_text_0000,

    // 3a44: Write to RAM 801c7770 (Unknown)
    STW,
    (s32)&D_801C7770_1C8370,

    // 3a4c: Store Value: 1
    WTS,
    0x1,

    // 3a54: Write to RAM 801c77d8 (Text Speed)
    STW,
    0x801c77d8,

    // 3a5c: Store Value: 64
    WTS,
    0x64,

    // 3a64: Write to RAM 801c7798 (Unknown)
    STW,
    0x801c7798,

    // 3a6c: Store Value: 1
    WTS,
    0x1,

    // 3a74: Print Text
    TXT,
    (s32)&scenario_text_0014,

    // 3a7c: Write to RAM 801c7758 (Unknown)
    STW,
    (s32)&D_801C7758_1C8358,

    // 3a84: Store Value: 20
    WTS,
    0x20,

    // 3a8c: Write to RAM 801c775c (Dialogue Window Y Pos)
    STW,
    (s32)&D_801C775C_1C835C,

    // 3a94: Store Value: 48
    WTS,
    0x48,

    // 3a9c: Write to RAM 8007785c (Dialogue Portrait Character)
    STW,
    (s32)&D_8007785C_7845C,

    // 3aa4: Store Value: 100
    WTS,
    0x100,

    // 3aac: Write to RAM 801c7768 (Dialogue Window Style)
    STW,
    (s32)&D_801C7768_1C8368,

    // 3ab4: Store Value: 7
    WTS,
    0x7,

    // 3abc: Print Text
    TXT,
    (s32)&scenario_text_0000,

    // 3ac4: Write to RAM 801c7770 (Unknown)
    STW,
    (s32)&D_801C7770_1C8370,

    // 3acc: Store Value: 1
    WTS,
    0x1,

    // 3ad4: Write to RAM 801c7740 (Scratch)
    STW,
    (s32)&D_801C7740_1C8340,

    // 3adc: Store Value: 14
    WTS,
    0x14,

    // 3ae4: Execute Code: 8003f608 (Play Sound)
    ESR,
    (s32)&func_8003F608_40208,

    // 3aec: Print Text
    TXT,
    (s32)&scenario_text_006B,

    // 3af4: Print Text
    TXT,
    (s32)&scenario_text_00A9,

    // 3afc: Print Text
    TXT,
    (s32)&scenario_text_00E1,

    // 3b04: Write to RAM 801c7740 (Scratch)
    STW,
    (s32)&D_801C7740_1C8340,

    // 3b0c: Store Value: 96
    WTS,
    0x96,

    // 3b14: Execute Code: 8003f460 (Wait For Timer)
    ESR,
    (s32)&func_8003F460_40060,

    // 3b1c: Write to RAM 801c7740 (Scratch)
    STW,
    (s32)&D_801C7740_1C8340,

    // 3b24: Store Value: 23
    WTS,
    0x23,

    // 3b2c: Execute Code: 8003f608 (Play Sound)
    ESR,
    (s32)&func_8003F608_40208,

    // 3b34: Print Text
    TXT,
    (s32)&scenario_text_0127,

    // 3b3c: Print Text
    TXT,
    (s32)&scenario_text_013C,

    // 3b44: Print Text
    TXT,
    (s32)&scenario_text_0154,

    // 3b4c: Print Text
    TXT,
    (s32)&scenario_text_016B,

    // 3b54: Print Text
    TXT,
    (s32)&scenario_text_01A4,

    // 3b5c: Write to RAM 801c7758 (Unknown)
    STW,
    (s32)&D_801C7758_1C8358,

    // 3b64: Store Value: 20
    WTS,
    0x20,

    // 3b6c: Write to RAM 801c775c (Dialogue Window Y Pos)
    STW,
    (s32)&D_801C775C_1C835C,

    // 3b74: Store Value: 20
    WTS,
    0x20,

    // 3b7c: Write to RAM 801c7768 (Dialogue Window Style)
    STW,
    (s32)&D_801C7768_1C8368,

    // 3b84: Store Value: 7
    WTS,
    0x7,

    // 3b8c: Write to RAM 8007785c (Dialogue Portrait Character)
    STW,
    (s32)&D_8007785C_7845C,

    // 3b94: Store Value: 2
    WTS,
    0x2,

    // 3b9c: Print Text
    TXT,
    (s32)&scenario_text_0000,

    // 3ba4: Write to RAM 801c7770 (Unknown)
    STW,
    (s32)&D_801C7770_1C8370,

    // 3bac: Store Value: 1
    WTS,
    0x1,

    // 3bb4: Print Text
    TXT,
    (s32)&scenario_text_0204,

    // 3bbc: Print Text
    TXT,
    (s32)&scenario_text_0232,

    // 3bc4: Print Text
    TXT,
    (s32)&scenario_text_0264,

    // 3bcc: Write to RAM 801c7740 (Scratch)
    STW,
    (s32)&D_801C7740_1C8340,

    // 3bd4: Store Value: 140
    WTS,
    0x140,

    // 3bdc: Execute Code: 8003f608 (Play Sound)
    ESR,
    (s32)&func_8003F608_40208,

    // DISABLED ITEM
    // // 3be4: Write to RAM 8015c6ac (Goemon Weapon Level)
    // STW, 0x8015c6ac,

    // // 3bec: Store Value: 2
    // WTS, 0x2,

    // // 3bf4: Write to RAM 8015c6b0 (Ebisumaru Weapon Level)
    // STW, 0x8015c6b0,

    // // 3bfc: Store Value: 2
    // WTS, 0x2,

    // // 3c04: Write to RAM 8015c6b4 (Sasuke Weapon Level)
    // STW, 0x8015c6b4,

    // // 3c0c: Store Value: 2
    // WTS, 0x2,

    // // 3c14: Write to RAM 8015c6b8 (Yae Weapon Level)
    // STW, 0x8015c6b8,

    // // 3c1c: Store Value: 2
    // WTS, 0x2,

    // 3c24: Print Text
    TXT,
    (s32)&scenario_text_0289,

    // 3c2c: End Event
    END,

    // End scenario script
    END,
};
