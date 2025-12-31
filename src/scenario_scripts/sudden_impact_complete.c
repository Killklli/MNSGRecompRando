#include "scenario.h"

#include "common.h"

// Address: @28bc

// Way to go!{newline}{endline}
static s16 scenario_text_0000[] = {
    CHR_W, CHR_a, CHR_y, PCT_SPACE, CHR_t, CHR_o, PCT_SPACE, CHR_g, CHR_o, PCT_EXCLAMATION,
    CTR_NEWLINE, CTR_ENDLINE
};

// Now, you can call yourself{newline}{endline}
static s16 scenario_text_0020[] = {
    CHR_N, CHR_o, CHR_w, PCT_COMMA, PCT_SPACE, CHR_y, CHR_o, CHR_u, PCT_SPACE, CHR_c,
    CHR_a, CHR_n, PCT_SPACE, CHR_c, CHR_a, CHR_l, CHR_l, PCT_SPACE, CHR_y, CHR_o,
    CHR_u, CHR_r, CHR_s, CHR_e, CHR_l, CHR_f, CTR_NEWLINE, CTR_ENDLINE
};

// a {em-yellow}Muscle Man{/em}!{button}{endline}
static s16 scenario_text_0050[] = {
    CHR_a, PCT_SPACE, CTR_EM_YELLOW, CHR_M, CHR_u, CHR_s, CHR_c, CHR_l, CHR_e, PCT_SPACE,
    CHR_M, CHR_a, CHR_n, CTR_CLOSE_EM, PCT_EXCLAMATION, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_0082[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// {end}{endline}
static s16 scenario_text_009A[] = {
    CTR_END, CTR_ENDLINE
};

// {begin}{endline}
static s16 scenario_text_00AC[] = {
    CTR_BEGIN, CTR_ENDLINE
};

//  {newline}{endline}
static s16 scenario_text_00C0[] = {
    PCT_SPACE, CTR_NEWLINE, CTR_ENDLINE
};

// Goemon obtains{newline}{endline}
static s16 scenario_text_00D7[] = {
    CHR_G, CHR_o, CHR_e, CHR_m, CHR_o, CHR_n, PCT_SPACE, CHR_o, CHR_b, CHR_t,
    CHR_a, CHR_i, CHR_n, CHR_s, CTR_NEWLINE, CTR_ENDLINE
};

// the [{em-yellow}Sudden Impact{/em}] magic powers!{newline}{endline}
static s16 scenario_text_00FB[] = {
    CHR_t, CHR_h, CHR_e, PCT_SPACE, PCT_LBRACKET, CTR_EM_YELLOW, CHR_S, CHR_u, CHR_d, CHR_d,
    CHR_e, CHR_n, PCT_SPACE, CHR_I, CHR_m, CHR_p, CHR_a, CHR_c, CHR_t, CTR_CLOSE_EM,
    PCT_RBRACKET, PCT_SPACE, CHR_m, CHR_a, CHR_g, CHR_i, CHR_c, PCT_SPACE, CHR_p, CHR_o,
    CHR_w, CHR_e, CHR_r, CHR_s, PCT_EXCLAMATION, CTR_NEWLINE, CTR_ENDLINE
};

// {button}{endline}
static s16 scenario_text_0142[] = {
    CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_0157[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// By consuming some {em-yellow}money{/em},{newline}{endline}
static s16 scenario_text_016F[] = {
    CHR_B, CHR_y, PCT_SPACE, CHR_c, CHR_o, CHR_n, CHR_s, CHR_u, CHR_m, CHR_i,
    CHR_n, CHR_g, PCT_SPACE, CHR_s, CHR_o, CHR_m, CHR_e, PCT_SPACE, CTR_EM_YELLOW, CHR_m,
    CHR_o, CHR_n, CHR_e, CHR_y, CTR_CLOSE_EM, PCT_COMMA, CTR_NEWLINE, CTR_ENDLINE
};

// you will be able to move{newline}{endline}
static s16 scenario_text_01AD[] = {
    CHR_y, CHR_o, CHR_u, PCT_SPACE, CHR_w, CHR_i, CHR_l, CHR_l, PCT_SPACE, CHR_b,
    CHR_e, PCT_SPACE, CHR_a, CHR_b, CHR_l, CHR_e, PCT_SPACE, CHR_t, CHR_o, PCT_SPACE,
    CHR_m, CHR_o, CHR_v, CHR_e, CTR_NEWLINE, CTR_ENDLINE
};

// {em-yellow}heavy thing{/em} for a specific period{newline}{endline}
static s16 scenario_text_01DB[] = {
    CTR_EM_YELLOW, CHR_h, CHR_e, CHR_a, CHR_v, CHR_y, PCT_SPACE, CHR_t, CHR_h, CHR_i,
    CHR_n, CHR_g, CTR_CLOSE_EM, PCT_SPACE, CHR_f, CHR_o, CHR_r, PCT_SPACE, CHR_a, PCT_SPACE,
    CHR_s, CHR_p, CHR_e, CHR_c, CHR_i, CHR_f, CHR_i, CHR_c, PCT_SPACE, CHR_p,
    CHR_e, CHR_r, CHR_i, CHR_o, CHR_d, CTR_NEWLINE, CTR_ENDLINE
};

// of time!{button}{endline}
static s16 scenario_text_0222[] = {
    CHR_o, CHR_f, PCT_SPACE, CHR_t, CHR_i, CHR_m, CHR_e, PCT_EXCLAMATION, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_023F[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Furthermore,{newline}{endline}
static s16 scenario_text_0257[] = {
    CHR_F, CHR_u, CHR_r, CHR_t, CHR_h, CHR_e, CHR_r, CHR_m, CHR_o, CHR_r,
    CHR_e, PCT_COMMA, CTR_NEWLINE, CTR_ENDLINE
};

// while the magic power is{newline}{endline}
static s16 scenario_text_0279[] = {
    CHR_w, CHR_h, CHR_i, CHR_l, CHR_e, PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE,
    CHR_m, CHR_a, CHR_g, CHR_i, CHR_c, PCT_SPACE, CHR_p, CHR_o, CHR_w, CHR_e,
    CHR_r, PCT_SPACE, CHR_i, CHR_s, CTR_NEWLINE, CTR_ENDLINE
};

// in effect, you will have {em-yellow}double{/em}{newline}{endline}
static s16 scenario_text_02A7[] = {
    CHR_i, CHR_n, PCT_SPACE, CHR_e, CHR_f, CHR_f, CHR_e, CHR_c, CHR_t, PCT_COMMA,
    PCT_SPACE, CHR_y, CHR_o, CHR_u, PCT_SPACE, CHR_w, CHR_i, CHR_l, CHR_l, PCT_SPACE,
    CHR_h, CHR_a, CHR_v, CHR_e, PCT_SPACE, CTR_EM_YELLOW, CHR_d, CHR_o, CHR_u, CHR_b,
    CHR_l, CHR_e, CTR_CLOSE_EM, CTR_NEWLINE, CTR_ENDLINE
};

// the {em-yellow}attacking power{/em}!{button}{endline}
static s16 scenario_text_02EC[] = {
    CHR_t, CHR_h, CHR_e, PCT_SPACE, CTR_EM_YELLOW, CHR_a, CHR_t, CHR_t, CHR_a, CHR_c,
    CHR_k, CHR_i, CHR_n, CHR_g, PCT_SPACE, CHR_p, CHR_o, CHR_w, CHR_e, CHR_r,
    CTR_CLOSE_EM, PCT_EXCLAMATION, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_0325[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

//   {newline}{endline}
static s16 scenario_text_033D[] = {
    PCT_SPACE, PCT_SPACE, CTR_NEWLINE, CTR_ENDLINE
};

// (However, be careful, as {em-yellow}damage{/em}{newline}{endline}
static s16 scenario_text_0355[] = {
    PCT_LPAREN, CHR_H, CHR_o, CHR_w, CHR_e, CHR_v, CHR_e, CHR_r, PCT_COMMA, PCT_SPACE,
    CHR_b, CHR_e, PCT_SPACE, CHR_c, CHR_a, CHR_r, CHR_e, CHR_f, CHR_u, CHR_l,
    PCT_COMMA, PCT_SPACE, CHR_a, CHR_s, PCT_SPACE, CTR_EM_YELLOW, CHR_d, CHR_a, CHR_m, CHR_a,
    CHR_g, CHR_e, CTR_CLOSE_EM, CTR_NEWLINE, CTR_ENDLINE
};

//  from the enemy will also {em-yellow}double{/em}){endline}
static s16 scenario_text_039A[] = {
    PCT_SPACE, CHR_f, CHR_r, CHR_o, CHR_m, PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE,
    CHR_e, CHR_n, CHR_e, CHR_m, CHR_y, PCT_SPACE, CHR_w, CHR_i, CHR_l, CHR_l,
    PCT_SPACE, CHR_a, CHR_l, CHR_s, CHR_o, PCT_SPACE, CTR_EM_YELLOW, CHR_d, CHR_o, CHR_u,
    CHR_b, CHR_l, CHR_e, CTR_CLOSE_EM, PCT_RPAREN, CTR_ENDLINE
};

// {waitinput}{end}{endline}
static s16 scenario_text_03D8[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE
};

extern s32 scenario_code_message_174_28bc[];

s32 scenario_code_message_174_28bc[] = {

    // Address: @28bc

    // 28bc: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // 28c4: Store Value: 1
    WTS, 0x1,

    // 28cc: Print Text
    TXT, (s32)&scenario_text_0000,

    // 28d4: Print Text
    TXT, (s32)&scenario_text_0020,

    // 28dc: Print Text
    TXT, (s32)&scenario_text_0050,

    // 28e4: Print Text
    TXT, (s32)&scenario_text_0082,

    // 28ec: Print Text
    TXT, (s32)&scenario_text_009A,

    // 28f4: Write to RAM 801c7758 (Unknown)
    STW, (s32)&D_801C7758_1C8358,

    // 28fc: Store Value: 20
    WTS, 0x20,

    // 2904: Write to RAM 801c775c (Dialogue Window Y Pos)
    STW, (s32)&D_801C775C_1C835C,

    // 290c: Store Value: 48
    WTS, 0x48,

    // 2914: Write to RAM 801c7768 (Dialogue Window Style)
    STW, (s32)&D_801C7768_1C8368,

    // 291c: Store Value: 7
    WTS, 0x7,

    // 2924: Print Text
    TXT, (s32)&scenario_text_00AC,

    // 292c: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // 2934: Store Value: 1
    WTS, 0x1,

    // 293c: Write to RAM 801c7740 (Scratch)
    STW, (s32)&D_801C7740_1C8340,

    // 2944: Store Value: 14
    WTS, 0x14,

    // 294c: Execute Code: 8003f608 (Play Sound)
    ESR, (s32)&func_8003F608_40208,

    // 2954: Write to RAM 801c77d8 (Text Speed)
    STW, 0x801c77d8,

    // 295c: Store Value: 64
    WTS, 0x64,

    // 2964: Write to RAM 801c7798 (Unknown)
    STW, 0x801c7798,

    // 296c: Store Value: 1
    WTS, 0x1,

    // 2974: Print Text
    TXT, (s32)&scenario_text_00C0,

    // 297c: Print Text
    TXT, (s32)&scenario_text_00D7,

    // 2984: Print Text
    TXT, (s32)&scenario_text_00FB,

    // 298c: Write to RAM 801c7740 (Scratch)
    STW, (s32)&D_801C7740_1C8340,

    // 2994: Store Value: 96
    WTS, 0x96,

    // 299c: Execute Code: 8003f460 (Wait For Timer)
    ESR, (s32)&func_8003F460_40060,

    // 29a4: Write to RAM 801c7740 (Scratch)
    STW, (s32)&D_801C7740_1C8340,

    // 29ac: Store Value: 23
    WTS, 0x23,

    // 29b4: Execute Code: 8003f608 (Play Sound)
    ESR, (s32)&func_8003F608_40208,

    // 29bc: Print Text
    TXT, (s32)&scenario_text_0142,

    // 29c4: Print Text
    TXT, (s32)&scenario_text_0082,

    // 29cc: Write to RAM 801c77d8 (Text Speed)
    STW, 0x801c77d8,

    // 29d4: Store Value: 1
    WTS, 0x1,

    // 29dc: Write to RAM 801c7798 (Unknown)
    STW, 0x801c7798,

    // 29e4: Store Value: 1
    WTS, 0x1,

    // 29ec: Print Text
    TXT, (s32)&scenario_text_016F,

    // 29f4: Print Text
    TXT, (s32)&scenario_text_01AD,

    // 29fc: Print Text
    TXT, (s32)&scenario_text_01DB,

    // 2a04: Print Text
    TXT, (s32)&scenario_text_0222,

    // 2a0c: Print Text
    TXT, (s32)&scenario_text_0082,

    // 2a14: Print Text
    TXT, (s32)&scenario_text_0257,

    // 2a1c: Print Text
    TXT, (s32)&scenario_text_0279,

    // 2a24: Print Text
    TXT, (s32)&scenario_text_02A7,

    // 2a2c: Print Text
    TXT, (s32)&scenario_text_02EC,

    // 2a34: Print Text
    TXT, (s32)&scenario_text_0082,

    // 2a3c: Print Text
    TXT, (s32)&scenario_text_033D,

    // 2a44: Print Text
    TXT, (s32)&scenario_text_0355,

    // 2a4c: Print Text
    TXT, (s32)&scenario_text_039A,

    // DISABLED ITEM
    // // 2a54: Write to RAM 8015c6ec (Obtained Sudden Impact Magic)
    // STW, 0x8015c6ec,

    // // 2a5c: Store Value: 1
    // WTS, 0x1,

    // 2a64: Set Flag 01c (Obtained Sudden Impact Magic)
    SFG, 0x1C,

    // 2a6c: Print Text
    TXT, (s32)&scenario_text_03D8,

    // 2a74: End Event
    END,

    // End scenario script
    END,
};

