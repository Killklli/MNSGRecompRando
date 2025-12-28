#include "scenario.h"

#include "common.h"

// Address: @251c

// {begin}{endline}
static s16 scenario_text_0000[] = {
    CTR_BEGIN, CTR_ENDLINE
};

// Goemon:Which is?{button}{endline}
static s16 scenario_text_0014[] = {
    CHR_G, CHR_o, CHR_e, CHR_m, CHR_o, CHR_n, PCT_COLON, CHR_W, CHR_h, CHR_i,
    CHR_c, CHR_h, PCT_SPACE, CHR_i, CHR_s, PCT_QUESTION, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_0039[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Ebisumaru:Wow, wow!{newline}{endline}
static s16 scenario_text_0051[] = {
    CHR_E, CHR_b, CHR_i, CHR_s, CHR_u, CHR_m, CHR_a, CHR_r, CHR_u, PCT_COLON,
    CHR_W, CHR_o, CHR_w, PCT_COMMA, PCT_SPACE, CHR_w, CHR_o, CHR_w, PCT_EXCLAMATION, CTR_NEWLINE,
    CTR_ENDLINE
};

//        It's our friend, {em-yellow}Sasuke{/em}!{button}{endline}
static s16 scenario_text_007A[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_I, CHR_t, PCT_APOSTROPHE,
    CHR_s, PCT_SPACE, CHR_o, CHR_u, CHR_r, PCT_SPACE, CHR_f, CHR_r, CHR_i, CHR_e,
    CHR_n, CHR_d, PCT_COMMA, PCT_SPACE, CTR_EM_YELLOW, CHR_S, CHR_a, CHR_s, CHR_u, CHR_k,
    CHR_e, CTR_CLOSE_EM, PCT_EXCLAMATION, CTR_BUTTON, CTR_ENDLINE
};

// {end}{endline}
static s16 scenario_text_00BE[] = {
    CTR_END, CTR_ENDLINE
};

// {begin}{endline}
static s16 scenario_text_00D0[] = {
    CTR_BEGIN, CTR_ENDLINE
};

// Narrator:What Benkei pulled out{newline}{endline}
static s16 scenario_text_00E4[] = {
    CHR_N, CHR_a, CHR_r, CHR_r, CHR_a, CHR_t, CHR_o, CHR_r, PCT_COLON, CHR_W,
    CHR_h, CHR_a, CHR_t, PCT_SPACE, CHR_B, CHR_e, CHR_n, CHR_k, CHR_e, CHR_i,
    PCT_SPACE, CHR_p, CHR_u, CHR_l, CHR_l, CHR_e, CHR_d, PCT_SPACE, CHR_o, CHR_u,
    CHR_t, CTR_NEWLINE, CTR_ENDLINE
};

//        was...{button}{endline}
static s16 scenario_text_0119[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_w, CHR_a, CHR_s,
    PCT_PERIOD, PCT_PERIOD, PCT_PERIOD, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_013B[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Narrator:...all stiff,{newline}{endline}
static s16 scenario_text_0153[] = {
    CHR_N, CHR_a, CHR_r, CHR_r, CHR_a, CHR_t, CHR_o, CHR_r, PCT_COLON, PCT_PERIOD,
    PCT_PERIOD, PCT_PERIOD, CHR_a, CHR_l, CHR_l, PCT_SPACE, CHR_s, CHR_t, CHR_i, CHR_f,
    CHR_f, PCT_COMMA, CTR_NEWLINE, CTR_ENDLINE
};

//       with [{em-yellow}batteries{/em}]{newline}{endline}
static s16 scenario_text_017F[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_w, CHR_i, CHR_t, CHR_h,
    PCT_SPACE, PCT_LBRACKET, CTR_EM_YELLOW, CHR_b, CHR_a, CHR_t, CHR_t, CHR_e, CHR_r, CHR_i,
    CHR_e, CHR_s, CTR_CLOSE_EM, PCT_RBRACKET, CTR_NEWLINE, CTR_ENDLINE
};

//        almost falling out...{button}{endline}
static s16 scenario_text_01BB[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_a, CHR_l, CHR_m,
    CHR_o, CHR_s, CHR_t, PCT_SPACE, CHR_f, CHR_a, CHR_l, CHR_l, CHR_i, CHR_n,
    CHR_g, PCT_SPACE, CHR_o, CHR_u, CHR_t, PCT_PERIOD, PCT_PERIOD, PCT_PERIOD, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_01EC[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Narrator:It was none other than{newline}{endline}
static s16 scenario_text_0204[] = {
    CHR_N, CHR_a, CHR_r, CHR_r, CHR_a, CHR_t, CHR_o, CHR_r, PCT_COLON, CHR_I,
    CHR_t, PCT_SPACE, CHR_w, CHR_a, CHR_s, PCT_SPACE, CHR_n, CHR_o, CHR_n, CHR_e,
    PCT_SPACE, CHR_o, CHR_t, CHR_h, CHR_e, CHR_r, PCT_SPACE, CHR_t, CHR_h, CHR_a,
    CHR_n, CTR_NEWLINE, CTR_ENDLINE
};

//        the Mechanical Ninja,{newline}{endline}
static s16 scenario_text_0239[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_t, CHR_h, CHR_e,
    PCT_SPACE, CHR_M, CHR_e, CHR_c, CHR_h, CHR_a, CHR_n, CHR_i, CHR_c, CHR_a,
    CHR_l, PCT_SPACE, CHR_N, CHR_i, CHR_n, CHR_j, CHR_a, PCT_COMMA, CTR_NEWLINE, CTR_ENDLINE
};

//        {em-yellow}Sasuke{/em}!{button}{end}{endline}
static s16 scenario_text_026B[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CTR_EM_YELLOW, CHR_S, CHR_a,
    CHR_s, CHR_u, CHR_k, CHR_e, CTR_CLOSE_EM, PCT_EXCLAMATION, CTR_BUTTON, CTR_END, CTR_ENDLINE
};

// {begin}{endline}
static s16 scenario_text_02A3[] = {
    CTR_BEGIN, CTR_ENDLINE
};

// Yae:Where did you get this?!{button}{end}{endline}
static s16 scenario_text_02B7[] = {
    CHR_Y, CHR_a, CHR_e, PCT_COLON, CHR_W, CHR_h, CHR_e, CHR_r, CHR_e, PCT_SPACE,
    CHR_d, CHR_i, CHR_d, PCT_SPACE, CHR_y, CHR_o, CHR_u, PCT_SPACE, CHR_g, CHR_e,
    CHR_t, PCT_SPACE, CHR_t, CHR_h, CHR_i, CHR_s, PCT_QUESTION, PCT_EXCLAMATION, CTR_BUTTON, CTR_END,
    CTR_ENDLINE
};

// {begin}{endline}
static s16 scenario_text_02ED[] = {
    CTR_BEGIN, CTR_ENDLINE
};

// Benkei:It came falling from {newline}{endline}
static s16 scenario_text_0301[] = {
    CHR_B, CHR_e, CHR_n, CHR_k, CHR_e, CHR_i, PCT_COLON, CHR_I, CHR_t, PCT_SPACE,
    CHR_c, CHR_a, CHR_m, CHR_e, PCT_SPACE, CHR_f, CHR_a, CHR_l, CHR_l, CHR_i,
    CHR_n, CHR_g, PCT_SPACE, CHR_f, CHR_r, CHR_o, CHR_m, PCT_SPACE, CTR_NEWLINE, CTR_ENDLINE
};

//       the {em-yellow}sky{/em} just the other day.{button}{end}{endline}
static s16 scenario_text_0333[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE,
    CTR_EM_YELLOW, CHR_s, CHR_k, CHR_y, CTR_CLOSE_EM, PCT_SPACE, CHR_j, CHR_u, CHR_s, CHR_t,
    PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE, CHR_o, CHR_t, CHR_h, CHR_e, CHR_r,
    PCT_SPACE, CHR_d, CHR_a, CHR_y, PCT_PERIOD, CTR_BUTTON, CTR_END, CTR_ENDLINE
};

// {begin}{endline}
static s16 scenario_text_037E[] = {
    CTR_BEGIN, CTR_ENDLINE
};

// Goemon:I wonder if it has anything{newline}{endline}
static s16 scenario_text_0392[] = {
    CHR_G, CHR_o, CHR_e, CHR_m, CHR_o, CHR_n, PCT_COLON, CHR_I, PCT_SPACE, CHR_w,
    CHR_o, CHR_n, CHR_d, CHR_e, CHR_r, PCT_SPACE, CHR_i, CHR_f, PCT_SPACE, CHR_i,
    CHR_t, PCT_SPACE, CHR_h, CHR_a, CHR_s, PCT_SPACE, CHR_a, CHR_n, CHR_y, CHR_t,
    CHR_h, CHR_i, CHR_n, CHR_g, CTR_NEWLINE, CTR_ENDLINE
};

//       to do with the explosion{newline}{endline}
static s16 scenario_text_03CA[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_t, CHR_o, PCT_SPACE, CHR_d,
    CHR_o, PCT_SPACE, CHR_w, CHR_i, CHR_t, CHR_h, PCT_SPACE, CHR_t, CHR_h, CHR_e,
    PCT_SPACE, CHR_e, CHR_x, CHR_p, CHR_l, CHR_o, CHR_s, CHR_i, CHR_o, CHR_n,
    CTR_NEWLINE, CTR_ENDLINE
};

//       at {em-yellow}the Wise Man's house{/em}...{button}{end}{endline}
static s16 scenario_text_03FE[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_a, CHR_t, PCT_SPACE, CTR_EM_YELLOW,
    CHR_t, CHR_h, CHR_e, PCT_SPACE, CHR_W, CHR_i, CHR_s, CHR_e, PCT_SPACE, CHR_M,
    CHR_a, CHR_n, PCT_APOSTROPHE, CHR_s, PCT_SPACE, CHR_h, CHR_o, CHR_u, CHR_s, CHR_e,
    CTR_CLOSE_EM, PCT_PERIOD, PCT_PERIOD, PCT_PERIOD, CTR_BUTTON, CTR_END, CTR_ENDLINE
};

// {begin}{endline}
static s16 scenario_text_0448[] = {
    CTR_BEGIN, CTR_ENDLINE
};

// Benkei:Well, in any case,{newline}{endline}
static s16 scenario_text_045C[] = {
    CHR_B, CHR_e, CHR_n, CHR_k, CHR_e, CHR_i, PCT_COLON, CHR_W, CHR_e, CHR_l,
    CHR_l, PCT_COMMA, PCT_SPACE, CHR_i, CHR_n, PCT_SPACE, CHR_a, CHR_n, CHR_y, PCT_SPACE,
    CHR_c, CHR_a, CHR_s, CHR_e, PCT_COMMA, CTR_NEWLINE, CTR_ENDLINE
};

//       don't tell a single soul{newline}{endline}
static s16 scenario_text_048B[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_d, CHR_o, CHR_n, PCT_APOSTROPHE,
    CHR_t, PCT_SPACE, CHR_t, CHR_e, CHR_l, CHR_l, PCT_SPACE, CHR_a, PCT_SPACE, CHR_s,
    CHR_i, CHR_n, CHR_g, CHR_l, CHR_e, PCT_SPACE, CHR_s, CHR_o, CHR_u, CHR_l,
    CTR_NEWLINE, CTR_ENDLINE
};

//       that I lost!{button}{end}{endline}
static s16 scenario_text_04BF[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_t, CHR_h, CHR_a, CHR_t,
    PCT_SPACE, CHR_I, PCT_SPACE, CHR_l, CHR_o, CHR_s, CHR_t, PCT_EXCLAMATION, CTR_BUTTON, CTR_END,
    CTR_ENDLINE
};

// {begin}{endline}
static s16 scenario_text_04EB[] = {
    CTR_BEGIN, CTR_ENDLINE
};

//   {newline}{endline}
static s16 scenario_text_04FF[] = {
    PCT_SPACE, PCT_SPACE, CTR_NEWLINE, CTR_ENDLINE
};

// Goemon and allies receive{newline}{endline}
static s16 scenario_text_0517[] = {
    CHR_G, CHR_o, CHR_e, CHR_m, CHR_o, CHR_n, PCT_SPACE, CHR_a, CHR_n, CHR_d,
    PCT_SPACE, CHR_a, CHR_l, CHR_l, CHR_i, CHR_e, CHR_s, PCT_SPACE, CHR_r, CHR_e,
    CHR_c, CHR_e, CHR_i, CHR_v, CHR_e, CTR_NEWLINE, CTR_ENDLINE
};

//     the Mechanical Ninja [{em-yellow}Sasuke{/em}].{endline}
static s16 scenario_text_0546[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE, CHR_M, CHR_e,
    CHR_c, CHR_h, CHR_a, CHR_n, CHR_i, CHR_c, CHR_a, CHR_l, PCT_SPACE, CHR_N,
    CHR_i, CHR_n, CHR_j, CHR_a, PCT_SPACE, PCT_LBRACKET, CTR_EM_YELLOW, CHR_S, CHR_a, CHR_s,
    CHR_u, CHR_k, CHR_e, CTR_CLOSE_EM, PCT_RBRACKET, PCT_PERIOD, CTR_ENDLINE
};

// {end}{endline}
static s16 scenario_text_0585[] = {
    CTR_END, CTR_ENDLINE
};

extern s32 scenario_code_message_30e_251c[];

s32 scenario_code_message_30e_251c[] = {

    // Address: @251c

    // 251c: Write to RAM 801c7758 (Unknown)
    STW, (s32)&D_801C7758_1C8358,

    // 2524: Store Value: 20
    WTS, 0x20,

    // 252c: Write to RAM 801c775c (Dialogue Window Y Pos)
    STW, (s32)&D_801C775C_1C835C,

    // 2534: Store Value: 20
    WTS, 0x20,

    // 253c: Write to RAM 801c7768 (Dialogue Window Style)
    STW, (s32)&D_801C7768_1C8368,

    // 2544: Store Value: 7
    WTS, 0x7,

    // 254c: Write to RAM 8007785c (Dialogue Portrait Character)
    STW, (s32)&D_8007785C_7845C,

    // 2554: Store Value: 0
    WTS, 0x0,

    // 255c: Print Text
    TXT, (s32)&scenario_text_0000,

    // 2564: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // 256c: Store Value: 1
    WTS, 0x1,

    // 2574: Print Text
    TXT, (s32)&scenario_text_0014,

    // 257c: Print Text
    TXT, (s32)&scenario_text_0039,

    // 2584: Write to RAM 8007785c (Dialogue Portrait Character)
    STW, (s32)&D_8007785C_7845C,

    // 258c: Store Value: 2
    WTS, 0x2,

    // 2594: Print Text
    TXT, (s32)&scenario_text_0051,

    // 259c: Print Text
    TXT, (s32)&scenario_text_007A,

    // 25a4: Print Text
    TXT, (s32)&scenario_text_00BE,

    // 25ac: Write to RAM 801c7758 (Unknown)
    STW, (s32)&D_801C7758_1C8358,

    // 25b4: Store Value: 20
    WTS, 0x20,

    // 25bc: Write to RAM 801c775c (Dialogue Window Y Pos)
    STW, (s32)&D_801C775C_1C835C,

    // 25c4: Store Value: 48
    WTS, 0x48,

    // 25cc: Write to RAM 801c7768 (Dialogue Window Style)
    STW, (s32)&D_801C7768_1C8368,

    // 25d4: Store Value: 1
    WTS, 0x1,

    // 25dc: Write to RAM 8007785c (Dialogue Portrait Character)
    STW, (s32)&D_8007785C_7845C,

    // 25e4: Store Value: 100
    WTS, 0x100,

    // 25ec: Print Text
    TXT, (s32)&scenario_text_0000,

    // 25f4: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // 25fc: Store Value: 1
    WTS, 0x1,

    // 2604: Write to RAM 8007785c (Dialogue Portrait Character)
    STW, (s32)&D_8007785C_7845C,

    // 260c: Store Value: 14
    WTS, 0x14,

    // 2614: Print Text
    TXT, (s32)&scenario_text_00E4,

    // 261c: Print Text
    TXT, (s32)&scenario_text_0119,

    // 2624: Print Text
    TXT, (s32)&scenario_text_0039,

    // 262c: Print Text
    TXT, (s32)&scenario_text_0153,

    // 2634: Print Text
    TXT, (s32)&scenario_text_017F,

    // 263c: Print Text
    TXT, (s32)&scenario_text_01BB,

    // 2644: Print Text
    TXT, (s32)&scenario_text_0039,

    // 264c: Print Text
    TXT, (s32)&scenario_text_0204,

    // 2654: Print Text
    TXT, (s32)&scenario_text_0239,

    // 265c: Print Text
    TXT, (s32)&scenario_text_026B,

    // 2664: Write to RAM 801c7758 (Unknown)
    STW, (s32)&D_801C7758_1C8358,

    // 266c: Store Value: 20
    WTS, 0x20,

    // 2674: Write to RAM 801c775c (Dialogue Window Y Pos)
    STW, (s32)&D_801C775C_1C835C,

    // 267c: Store Value: 20
    WTS, 0x20,

    // 2684: Write to RAM 801c7768 (Dialogue Window Style)
    STW, (s32)&D_801C7768_1C8368,

    // 268c: Store Value: 7
    WTS, 0x7,

    // 2694: Write to RAM 8007785c (Dialogue Portrait Character)
    STW, (s32)&D_8007785C_7845C,

    // 269c: Store Value: 6
    WTS, 0x6,

    // 26a4: Print Text
    TXT, (s32)&scenario_text_0000,

    // 26ac: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // 26b4: Store Value: 1
    WTS, 0x1,

    // 26bc: Print Text
    TXT, (s32)&scenario_text_02B7,

    // 26c4: Write to RAM 801c7758 (Unknown)
    STW, (s32)&D_801C7758_1C8358,

    // 26cc: Store Value: 20
    WTS, 0x20,

    // 26d4: Write to RAM 801c775c (Dialogue Window Y Pos)
    STW, (s32)&D_801C775C_1C835C,

    // 26dc: Store Value: 68
    WTS, 0x68,

    // 26e4: Write to RAM 8007785c (Dialogue Portrait Character)
    STW, (s32)&D_8007785C_7845C,

    // 26ec: Store Value: 100
    WTS, 0x100,

    // 26f4: Write to RAM 801c7768 (Dialogue Window Style)
    STW, (s32)&D_801C7768_1C8368,

    // 26fc: Store Value: 1
    WTS, 0x1,

    // 2704: Print Text
    TXT, (s32)&scenario_text_0000,

    // 270c: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // 2714: Store Value: 1
    WTS, 0x1,

    // 271c: Print Text
    TXT, (s32)&scenario_text_0301,

    // 2724: Print Text
    TXT, (s32)&scenario_text_0333,

    // 272c: Write to RAM 801c7758 (Unknown)
    STW, (s32)&D_801C7758_1C8358,

    // 2734: Store Value: 20
    WTS, 0x20,

    // 273c: Write to RAM 801c775c (Dialogue Window Y Pos)
    STW, (s32)&D_801C775C_1C835C,

    // 2744: Store Value: 20
    WTS, 0x20,

    // 274c: Write to RAM 801c7768 (Dialogue Window Style)
    STW, (s32)&D_801C7768_1C8368,

    // 2754: Store Value: 7
    WTS, 0x7,

    // 275c: Write to RAM 8007785c (Dialogue Portrait Character)
    STW, (s32)&D_8007785C_7845C,

    // 2764: Store Value: 0
    WTS, 0x0,

    // 276c: Print Text
    TXT, (s32)&scenario_text_0000,

    // 2774: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // 277c: Store Value: 1
    WTS, 0x1,

    // 2784: Print Text
    TXT, (s32)&scenario_text_0392,

    // 278c: Print Text
    TXT, (s32)&scenario_text_03CA,

    // 2794: Print Text
    TXT, (s32)&scenario_text_03FE,

    // 279c: Write to RAM 801c7758 (Unknown)
    STW, (s32)&D_801C7758_1C8358,

    // 27a4: Store Value: 20
    WTS, 0x20,

    // 27ac: Write to RAM 801c775c (Dialogue Window Y Pos)
    STW, (s32)&D_801C775C_1C835C,

    // 27b4: Store Value: 68
    WTS, 0x68,

    // 27bc: Write to RAM 8007785c (Dialogue Portrait Character)
    STW, (s32)&D_8007785C_7845C,

    // 27c4: Store Value: 100
    WTS, 0x100,

    // 27cc: Write to RAM 801c7768 (Dialogue Window Style)
    STW, (s32)&D_801C7768_1C8368,

    // 27d4: Store Value: 1
    WTS, 0x1,

    // 27dc: Print Text
    TXT, (s32)&scenario_text_0000,

    // 27e4: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // 27ec: Store Value: 1
    WTS, 0x1,

    // 27f4: Print Text
    TXT, (s32)&scenario_text_045C,

    // 27fc: Print Text
    TXT, (s32)&scenario_text_048B,

    // 2804: Print Text
    TXT, (s32)&scenario_text_04BF,

    // 280c: Write to RAM 801c7758 (Unknown)
    STW, (s32)&D_801C7758_1C8358,

    // 2814: Store Value: 20
    WTS, 0x20,

    // 281c: Write to RAM 801c775c (Dialogue Window Y Pos)
    STW, (s32)&D_801C775C_1C835C,

    // 2824: Store Value: 48
    WTS, 0x48,

    // 282c: Write to RAM 801c7768 (Dialogue Window Style)
    STW, (s32)&D_801C7768_1C8368,

    // 2834: Store Value: 7
    WTS, 0x7,

    // 283c: Print Text
    TXT, (s32)&scenario_text_0000,

    // 2844: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // 284c: Store Value: 1
    WTS, 0x1,

    // 2854: Write to RAM 801c7740 (Scratch)
    STW, (s32)&D_801C7740_1C8340,

    // 285c: Store Value: 14
    WTS, 0x14,

    // 2864: Execute Code: 8003f608 (Play Sound)
    ESR, (s32)&func_8003F608_40208,

    // 286c: Print Text
    TXT, (s32)&scenario_text_04FF,

    // 2874: Print Text
    TXT, (s32)&scenario_text_0517,

    // 287c: Print Text
    TXT, (s32)&scenario_text_0546,

    // 2884: Write to RAM 801c7740 (Scratch)
    STW, (s32)&D_801C7740_1C8340,

    // 288c: Store Value: 96
    WTS, 0x96,

    // 2894: Execute Code: 8003f460 (Wait For Timer)
    ESR, (s32)&func_8003F460_40060,

    // 289c: Print Text
    TXT, (s32)&scenario_text_00BE,

    // DISABLED ITEM (SASUKE)
    // // 28a4: Write to RAM 8015c868 (Unknown)
    // STW, 0x8015c868,

    // // 28ac: Increase By 1
    // INC, 0x1,

    // 28b4: Set Flag 033 (Defeated Benkei)
    SFG, 0x33,

    // 28bc: Write to RAM 801c7740 (Scratch)
    STW, (s32)&D_801C7740_1C8340,

    // 28c4: Store Value: 6b
    WTS, 0x6B,

    // 28cc: Execute Code: 8003f608 (Play Sound)
    ESR, (s32)&func_8003F608_40208,

    // 28d4: End Event
    END,

    // End scenario script
    END,
};

