#include "scenario.h"

#include "common.h"

// Address: @9904

// {begin}{endline}
static s16 scenario_text_0000[] = {
    CTR_BEGIN, CTR_ENDLINE
};

// Goemon:And did you find anything {newline}{endline}
static s16 scenario_text_0014[] = {
    CHR_G, CHR_o, CHR_e, CHR_m, CHR_o, CHR_n, PCT_COLON, CHR_A, CHR_n, CHR_d,
    PCT_SPACE, CHR_d, CHR_i, CHR_d, PCT_SPACE, CHR_y, CHR_o, CHR_u, PCT_SPACE, CHR_f,
    CHR_i, CHR_n, CHR_d, PCT_SPACE, CHR_a, CHR_n, CHR_y, CHR_t, CHR_h, CHR_i,
    CHR_n, CHR_g, PCT_SPACE, CTR_NEWLINE, CTR_ENDLINE
};

//       out about the Flake Gang?{button}{endline}
static s16 scenario_text_004B[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_o, CHR_u, CHR_t, PCT_SPACE,
    CHR_a, CHR_b, CHR_o, CHR_u, CHR_t, PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE,
    CHR_F, CHR_l, CHR_a, CHR_k, CHR_e, PCT_SPACE, CHR_G, CHR_a, CHR_n, CHR_g,
    PCT_QUESTION, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_007F[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_0097[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Yae:Well, all I found out was...{button}{endline}
static s16 scenario_text_00AF[] = {
    CHR_Y, CHR_a, CHR_e, PCT_COLON, CHR_W, CHR_e, CHR_l, CHR_l, PCT_COMMA, PCT_SPACE,
    CHR_a, CHR_l, CHR_l, PCT_SPACE, CHR_I, PCT_SPACE, CHR_f, CHR_o, CHR_u, CHR_n,
    CHR_d, PCT_SPACE, CHR_o, CHR_u, CHR_t, PCT_SPACE, CHR_w, CHR_a, CHR_s, PCT_PERIOD,
    PCT_PERIOD, PCT_PERIOD, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_00E4[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Yae:...that there are several{newline}{endline}
static s16 scenario_text_00FC[] = {
    CHR_Y, CHR_a, CHR_e, PCT_COLON, PCT_PERIOD, PCT_PERIOD, PCT_PERIOD, CHR_t, CHR_h, CHR_a,
    CHR_t, PCT_SPACE, CHR_t, CHR_h, CHR_e, CHR_r, CHR_e, PCT_SPACE, CHR_a, CHR_r,
    CHR_e, PCT_SPACE, CHR_s, CHR_e, CHR_v, CHR_e, CHR_r, CHR_a, CHR_l, CTR_NEWLINE,
    CTR_ENDLINE
};

//       members,{button}{endline}
static s16 scenario_text_012F[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_m, CHR_e, CHR_m, CHR_b,
    CHR_e, CHR_r, CHR_s, PCT_COMMA, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_0152[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Yae:who call themselves the{newline}{endline}
static s16 scenario_text_016A[] = {
    CHR_Y, CHR_a, CHR_e, PCT_COLON, CHR_w, CHR_h, CHR_o, PCT_SPACE, CHR_c, CHR_a,
    CHR_l, CHR_l, PCT_SPACE, CHR_t, CHR_h, CHR_e, CHR_m, CHR_s, CHR_e, CHR_l,
    CHR_v, CHR_e, CHR_s, PCT_SPACE, CHR_t, CHR_h, CHR_e, CTR_NEWLINE, CTR_ENDLINE
};

//       [{em-yellow}Peach Mountain Shoguns{/em}].{button}{endline}
static s16 scenario_text_019B[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_LBRACKET, CTR_EM_YELLOW, CHR_P, CHR_e,
    CHR_a, CHR_c, CHR_h, PCT_SPACE, CHR_M, CHR_o, CHR_u, CHR_n, CHR_t, CHR_a,
    CHR_i, CHR_n, PCT_SPACE, CHR_S, CHR_h, CHR_o, CHR_g, CHR_u, CHR_n, CHR_s,
    CTR_CLOSE_EM, PCT_RBRACKET, PCT_PERIOD, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_01DF[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Ebisumaru:{em-yellow}Peach Mountain{/em}?{button}{endline}
static s16 scenario_text_01F7[] = {
    CHR_E, CHR_b, CHR_i, CHR_s, CHR_u, CHR_m, CHR_a, CHR_r, CHR_u, PCT_COLON,
    CTR_EM_YELLOW, CHR_P, CHR_e, CHR_a, CHR_c, CHR_h, PCT_SPACE, CHR_M, CHR_o, CHR_u,
    CHR_n, CHR_t, CHR_a, CHR_i, CHR_n, CTR_CLOSE_EM, PCT_QUESTION, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_0235[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Goemon:Huh!  {newline}{endline}
static s16 scenario_text_024D[] = {
    CHR_G, CHR_o, CHR_e, CHR_m, CHR_o, CHR_n, PCT_COLON, CHR_H, CHR_u, CHR_h,
    PCT_EXCLAMATION, PCT_SPACE, PCT_SPACE, CTR_NEWLINE, CTR_ENDLINE
};

//       I don't care if we're{newline}{endline}
static s16 scenario_text_0270[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_I, PCT_SPACE, CHR_d, CHR_o,
    CHR_n, PCT_APOSTROPHE, CHR_t, PCT_SPACE, CHR_c, CHR_a, CHR_r, CHR_e, PCT_SPACE, CHR_i,
    CHR_f, PCT_SPACE, CHR_w, CHR_e, PCT_APOSTROPHE, CHR_r, CHR_e, CTR_NEWLINE, CTR_ENDLINE
};

//       talking {em-yellow}Peach Mountain{/em} or...{button}{endline}
static s16 scenario_text_02A1[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_t, CHR_a, CHR_l, CHR_k,
    CHR_i, CHR_n, CHR_g, PCT_SPACE, CTR_EM_YELLOW, CHR_P, CHR_e, CHR_a, CHR_c, CHR_h,
    PCT_SPACE, CHR_M, CHR_o, CHR_u, CHR_n, CHR_t, CHR_a, CHR_i, CHR_n, CTR_CLOSE_EM,
    PCT_SPACE, CHR_o, CHR_r, PCT_PERIOD, PCT_PERIOD, PCT_PERIOD, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_02E8[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Goemon:{em-yellow}Chestnut Mountain{/em}...{button}{endline}
static s16 scenario_text_0300[] = {
    CHR_G, CHR_o, CHR_e, CHR_m, CHR_o, CHR_n, PCT_COLON, CTR_EM_YELLOW, CHR_C, CHR_h,
    CHR_e, CHR_s, CHR_t, CHR_n, CHR_u, CHR_t, PCT_SPACE, CHR_M, CHR_o, CHR_u,
    CHR_n, CHR_t, CHR_a, CHR_i, CHR_n, CTR_CLOSE_EM, PCT_PERIOD, PCT_PERIOD, PCT_PERIOD, CTR_BUTTON,
    CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_0340[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Goemon:...or even{newline}{endline}
static s16 scenario_text_0358[] = {
    CHR_G, CHR_o, CHR_e, CHR_m, CHR_o, CHR_n, PCT_COLON, PCT_PERIOD, PCT_PERIOD, PCT_PERIOD,
    CHR_o, CHR_r, PCT_SPACE, CHR_e, CHR_v, CHR_e, CHR_n, CTR_NEWLINE, CTR_ENDLINE
};

//       a{em-yellow} Pear Mountain{/em}.{newline}{endline}
static s16 scenario_text_037F[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_a, CTR_EM_YELLOW, PCT_SPACE, CHR_P,
    CHR_e, CHR_a, CHR_r, PCT_SPACE, CHR_M, CHR_o, CHR_u, CHR_n, CHR_t, CHR_a,
    CHR_i, CHR_n, CTR_CLOSE_EM, PCT_PERIOD, CTR_NEWLINE, CTR_ENDLINE
};

// {button}{endline}
static s16 scenario_text_03BB[] = {
    CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_03D0[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Goemon:They'd better be{newline}{endline}
static s16 scenario_text_03E8[] = {
    CHR_G, CHR_o, CHR_e, CHR_m, CHR_o, CHR_n, PCT_COLON, CHR_T, CHR_h, CHR_e,
    CHR_y, PCT_APOSTROPHE, CHR_d, PCT_SPACE, CHR_b, CHR_e, CHR_t, CHR_t, CHR_e, CHR_r,
    PCT_SPACE, CHR_b, CHR_e, CTR_NEWLINE, CTR_ENDLINE
};

//       ready 'cause I'm gonna{newline}{endline}
static s16 scenario_text_0415[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_r, CHR_e, CHR_a, CHR_d,
    CHR_y, PCT_SPACE, PCT_APOSTROPHE, CHR_c, CHR_a, CHR_u, CHR_s, CHR_e, PCT_SPACE, CHR_I,
    PCT_APOSTROPHE, CHR_m, PCT_SPACE, CHR_g, CHR_o, CHR_n, CHR_n, CHR_a, CTR_NEWLINE, CTR_ENDLINE
};

//       kick their butts!{button}{endline}
static s16 scenario_text_0447[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_k, CHR_i, CHR_c, CHR_k,
    PCT_SPACE, CHR_t, CHR_h, CHR_e, CHR_i, CHR_r, PCT_SPACE, CHR_b, CHR_u, CHR_t,
    CHR_t, CHR_s, PCT_EXCLAMATION, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_0473[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Yae:It looks like our{newline}{endline}
static s16 scenario_text_048B[] = {
    CHR_Y, CHR_a, CHR_e, PCT_COLON, CHR_I, CHR_t, PCT_SPACE, CHR_l, CHR_o, CHR_o,
    CHR_k, CHR_s, PCT_SPACE, CHR_l, CHR_i, CHR_k, CHR_e, PCT_SPACE, CHR_o, CHR_u,
    CHR_r, CTR_NEWLINE, CTR_ENDLINE
};

//       objectives are the same.{button}{endline}
static s16 scenario_text_04B6[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_o, CHR_b, CHR_j, CHR_e,
    CHR_c, CHR_t, CHR_i, CHR_v, CHR_e, CHR_s, PCT_SPACE, CHR_a, CHR_r, CHR_e,
    PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE, CHR_s, CHR_a, CHR_m, CHR_e, PCT_PERIOD,
    CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_04E9[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Ebisumaru:Wow!{newline}{endline}
static s16 scenario_text_0501[] = {
    CHR_E, CHR_b, CHR_i, CHR_s, CHR_u, CHR_m, CHR_a, CHR_r, CHR_u, PCT_COLON,
    CHR_W, CHR_o, CHR_w, PCT_EXCLAMATION, CTR_NEWLINE, CTR_ENDLINE
};

//        Then we can go together{newline}{endline}
static s16 scenario_text_0525[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_T, CHR_h, CHR_e,
    CHR_n, PCT_SPACE, CHR_w, CHR_e, PCT_SPACE, CHR_c, CHR_a, CHR_n, PCT_SPACE, CHR_g,
    CHR_o, PCT_SPACE, CHR_t, CHR_o, CHR_g, CHR_e, CHR_t, CHR_h, CHR_e, CHR_r,
    CTR_NEWLINE, CTR_ENDLINE
};

//        on our adventures!{button}{endline}
static s16 scenario_text_0559[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_o, CHR_n, PCT_SPACE,
    CHR_o, CHR_u, CHR_r, PCT_SPACE, CHR_a, CHR_d, CHR_v, CHR_e, CHR_n, CHR_t,
    CHR_u, CHR_r, CHR_e, CHR_s, PCT_EXCLAMATION, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_0587[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Yae:Yes, I guess you're right.{endline}
static s16 scenario_text_059F[] = {
    CHR_Y, CHR_a, CHR_e, PCT_COLON, CHR_Y, CHR_e, CHR_s, PCT_COMMA, PCT_SPACE, CHR_I,
    PCT_SPACE, CHR_g, CHR_u, CHR_e, CHR_s, CHR_s, PCT_SPACE, CHR_y, CHR_o, CHR_u,
    PCT_APOSTROPHE, CHR_r, CHR_e, PCT_SPACE, CHR_r, CHR_i, CHR_g, CHR_h, CHR_t, PCT_PERIOD,
    CTR_ENDLINE
};

// {end}{endline}
static s16 scenario_text_05CA[] = {
    CTR_END, CTR_ENDLINE
};

// {begin}{endline}
static s16 scenario_text_05DC[] = {
    CTR_BEGIN, CTR_ENDLINE
};

//  {newline}{endline}
static s16 scenario_text_05F0[] = {
    PCT_SPACE, CTR_NEWLINE, CTR_ENDLINE
};

//    Secret Ninja Agent{newline}{endline}
static s16 scenario_text_0607[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_S, CHR_e, CHR_c, CHR_r, CHR_e, CHR_t, PCT_SPACE,
    CHR_N, CHR_i, CHR_n, CHR_j, CHR_a, PCT_SPACE, CHR_A, CHR_g, CHR_e, CHR_n,
    CHR_t, CTR_NEWLINE, CTR_ENDLINE
};

//       {em-yellow}[Yae]{/em} becomes an ally!{endline}
static s16 scenario_text_0632[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CTR_EM_YELLOW, PCT_LBRACKET, CHR_Y, CHR_a,
    CHR_e, PCT_RBRACKET, CTR_CLOSE_EM, PCT_SPACE, CHR_b, CHR_e, CHR_c, CHR_o, CHR_m, CHR_e,
    CHR_s, PCT_SPACE, CHR_a, CHR_n, PCT_SPACE, CHR_a, CHR_l, CHR_l, CHR_y, PCT_EXCLAMATION,
    CTR_ENDLINE
};

// {end}{endline}
static s16 scenario_text_066B[] = {
    CTR_END, CTR_ENDLINE
};

extern s32 scenario_code_message_14c_9904[];

s32 scenario_code_message_14c_9904[] = {

    // Address: @9904

    // 9904: Write to RAM 801c7758 (Unknown)
    STW, (s32)&D_801C7758_1C8358,

    // 990c: Store Value: 20
    WTS, 0x20,

    // 9914: Write to RAM 801c775c (Dialogue Window Y Pos)
    STW, (s32)&D_801C775C_1C835C,

    // 991c: Store Value: 20
    WTS, 0x20,

    // 9924: Write to RAM 801c7768 (Dialogue Window Style)
    STW, (s32)&D_801C7768_1C8368,

    // 992c: Store Value: 7
    WTS, 0x7,

    // 9934: Write to RAM 8007785c (Dialogue Portrait Character)
    STW, (s32)&D_8007785C_7845C,

    // 993c: Store Value: 0
    WTS, 0x0,

    // 9944: Print Text
    TXT, (s32)&scenario_text_0000,

    // 994c: Write to RAM 801c77d8 (Text Speed)
    STW, 0x801c77d8,

    // 9954: Store Value: 1
    WTS, 0x1,

    // 995c: Write to RAM 801c7798 (Unknown)
    STW, 0x801c7798,

    // 9964: Store Value: 1
    WTS, 0x1,

    // 996c: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // 9974: Store Value: 1
    WTS, 0x1,

    // 997c: Print Text
    TXT, (s32)&scenario_text_0014,

    // 9984: Print Text
    TXT, (s32)&scenario_text_004B,

    // 998c: Print Text
    TXT, (s32)&scenario_text_007F,

    // 9994: Set Flag 004 (???)
    SFG, 0x04,

    // 999c: Write to RAM 8007785c (Dialogue Portrait Character)
    STW, (s32)&D_8007785C_7845C,

    // 99a4: Store Value: 6
    WTS, 0x6,

    // 99ac: Print Text
    TXT, (s32)&scenario_text_007F,

    // 99b4: Print Text
    TXT, (s32)&scenario_text_00AF,

    // 99bc: Print Text
    TXT, (s32)&scenario_text_007F,

    // 99c4: Print Text
    TXT, (s32)&scenario_text_00FC,

    // 99cc: Print Text
    TXT, (s32)&scenario_text_012F,

    // 99d4: Print Text
    TXT, (s32)&scenario_text_007F,

    // 99dc: Print Text
    TXT, (s32)&scenario_text_016A,

    // 99e4: Print Text
    TXT, (s32)&scenario_text_019B,

    // 99ec: Print Text
    TXT, (s32)&scenario_text_007F,

    // 99f4: Set Flag 05e (???)
    SFG, 0x5E,

    // 99fc: Write to RAM 8007785c (Dialogue Portrait Character)
    STW, (s32)&D_8007785C_7845C,

    // 9a04: Store Value: 2
    WTS, 0x2,

    // 9a0c: Print Text
    TXT, (s32)&scenario_text_01F7,

    // 9a14: Print Text
    TXT, (s32)&scenario_text_007F,

    // 9a1c: Write to RAM 8007785c (Dialogue Portrait Character)
    STW, (s32)&D_8007785C_7845C,

    // 9a24: Store Value: 0
    WTS, 0x0,

    // 9a2c: Print Text
    TXT, (s32)&scenario_text_024D,

    // 9a34: Print Text
    TXT, (s32)&scenario_text_0270,

    // 9a3c: Print Text
    TXT, (s32)&scenario_text_02A1,

    // 9a44: Print Text
    TXT, (s32)&scenario_text_007F,

    // 9a4c: Print Text
    TXT, (s32)&scenario_text_0300,

    // 9a54: Print Text
    TXT, (s32)&scenario_text_007F,

    // 9a5c: Print Text
    TXT, (s32)&scenario_text_0358,

    // 9a64: Print Text
    TXT, (s32)&scenario_text_037F,

    // 9a6c: Write to RAM 801c7740 (Scratch)
    STW, (s32)&D_801C7740_1C8340,

    // 9a74: Store Value: 141
    WTS, 0x141,

    // 9a7c: Execute Code: 8003f608 (Play Sound)
    ESR, (s32)&func_8003F608_40208,

    // 9a84: Print Text
    TXT, (s32)&scenario_text_03BB,

    // 9a8c: Print Text
    TXT, (s32)&scenario_text_007F,

    // 9a94: Print Text
    TXT, (s32)&scenario_text_03E8,

    // 9a9c: Print Text
    TXT, (s32)&scenario_text_0415,

    // 9aa4: Print Text
    TXT, (s32)&scenario_text_0447,

    // 9aac: Set Flag 003 (???)
    SFG, 0x03,

    // 9ab4: Print Text
    TXT, (s32)&scenario_text_007F,

    // 9abc: Write to RAM 8007785c (Dialogue Portrait Character)
    STW, (s32)&D_8007785C_7845C,

    // 9ac4: Store Value: 6
    WTS, 0x6,

    // 9acc: Print Text
    TXT, (s32)&scenario_text_048B,

    // 9ad4: Print Text
    TXT, (s32)&scenario_text_04B6,

    // 9adc: Set Flag 004 (???)
    SFG, 0x04,

    // 9ae4: Print Text
    TXT, (s32)&scenario_text_007F,

    // 9aec: Write to RAM 8007785c (Dialogue Portrait Character)
    STW, (s32)&D_8007785C_7845C,

    // 9af4: Store Value: 2
    WTS, 0x2,

    // 9afc: Print Text
    TXT, (s32)&scenario_text_0501,

    // 9b04: Print Text
    TXT, (s32)&scenario_text_0525,

    // 9b0c: Print Text
    TXT, (s32)&scenario_text_0559,

    // 9b14: Set Flag 05e (???)
    SFG, 0x5E,

    // 9b1c: Print Text
    TXT, (s32)&scenario_text_007F,

    // 9b24: Write to RAM 8007785c (Dialogue Portrait Character)
    STW, (s32)&D_8007785C_7845C,

    // 9b2c: Store Value: 6
    WTS, 0x6,

    // 9b34: Print Text
    TXT, (s32)&scenario_text_059F,

    // 9b3c: Write to RAM 801c7740 (Scratch)
    STW, (s32)&D_801C7740_1C8340,

    // 9b44: Store Value: 7
    WTS, 0x7,

    // 9b4c: Execute Code: 8003f608 (Play Sound)
    ESR, (s32)&func_8003F608_40208,

    // 9b54: Write to RAM 801c7740 (Scratch)
    STW, (s32)&D_801C7740_1C8340,

    // 9b5c: Store Value: 2d
    WTS, 0x2D,

    // 9b64: Execute Code: 8003f460 (Wait For Timer)
    ESR, (s32)&func_8003F460_40060,

    // 9b6c: Print Text
    TXT, (s32)&scenario_text_05CA,

    // 9b74: Write to RAM 801c7758 (Unknown)
    STW, (s32)&D_801C7758_1C8358,

    // 9b7c: Store Value: 20
    WTS, 0x20,

    // 9b84: Write to RAM 801c775c (Dialogue Window Y Pos)
    STW, (s32)&D_801C775C_1C835C,

    // 9b8c: Store Value: 48
    WTS, 0x48,

    // 9b94: Write to RAM 8007785c (Dialogue Portrait Character)
    STW, (s32)&D_8007785C_7845C,

    // 9b9c: Store Value: 100
    WTS, 0x100,

    // 9ba4: Write to RAM 801c7768 (Dialogue Window Style)
    STW, (s32)&D_801C7768_1C8368,

    // 9bac: Store Value: 7
    WTS, 0x7,

    // 9bb4: Set Flag 003 (???)
    SFG, 0x03,

    // 9bbc: Write to RAM 801c7740 (Scratch)
    STW, (s32)&D_801C7740_1C8340,

    // 9bc4: Store Value: 14
    WTS, 0x14,

    // 9bcc: Execute Code: 8003f608 (Play Sound)
    ESR, (s32)&func_8003F608_40208,

    // 9bd4: Print Text
    TXT, (s32)&scenario_text_0000,

    // 9bdc: Write to RAM 801c77d8 (Text Speed)
    STW, 0x801c77d8,

    // 9be4: Store Value: 64
    WTS, 0x64,

    // 9bec: Write to RAM 801c7798 (Unknown)
    STW, 0x801c7798,

    // 9bf4: Store Value: 1
    WTS, 0x1,

    // 9bfc: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // 9c04: Store Value: 1
    WTS, 0x1,

    // 9c0c: Print Text
    TXT, (s32)&scenario_text_05F0,

    // 9c14: Print Text
    TXT, (s32)&scenario_text_0607,

    // 9c1c: Print Text
    TXT, (s32)&scenario_text_0632,

    // 9c24: Write to RAM 8015c6a8 (Recruited Yae)
    STW, 0x8015c6a8,

    // 9c2c: Store Value: 1
    WTS, 0x1,

    // 9c34: Set Flag 03a (Recruited Yae)
    SFG, 0x3A,

    // 9c3c: Write to RAM 801c7740 (Scratch)
    STW, (s32)&D_801C7740_1C8340,

    // 9c44: Store Value: 5a
    WTS, 0x5A,

    // 9c4c: Execute Code: 8003f460 (Wait For Timer)
    ESR, (s32)&func_8003F460_40060,

    // 9c54: Print Text
    TXT, (s32)&scenario_text_05CA,

    // 9c5c: End Event
    END,

    // End scenario script
    END,
};

