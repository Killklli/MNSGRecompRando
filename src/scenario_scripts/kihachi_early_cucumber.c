// Adjusts the Kihachi quest so you can give him a cucumber if you already have it.
#include "scenario.h"

#include "common.h"

// Address: @d320

// {begin}{endline}
static s16 scenario_text_0000[] = {
    CTR_BEGIN, CTR_ENDLINE
};

// Kihachi:All right!{newline}{endline}
static s16 scenario_text_0014[] = {
    CHR_K, CHR_i, CHR_h, CHR_a, CHR_c, CHR_h, CHR_i, PCT_COLON, CHR_A, CHR_l,
    CHR_l, PCT_SPACE, CHR_r, CHR_i, CHR_g, CHR_h, CHR_t, PCT_EXCLAMATION, CTR_NEWLINE, CTR_ENDLINE
};

//       I'll give it to you{newline}{endline}
static s16 scenario_text_003C[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_I, PCT_APOSTROPHE, CHR_l, CHR_l,
    PCT_SPACE, CHR_g, CHR_i, CHR_v, CHR_e, PCT_SPACE, CHR_i, CHR_t, PCT_SPACE, CHR_t,
    CHR_o, PCT_SPACE, CHR_y, CHR_o, CHR_u, CTR_NEWLINE, CTR_ENDLINE
};

//       if you bring me{newline}{endline}
static s16 scenario_text_006B[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_i, CHR_f, PCT_SPACE, CHR_y,
    CHR_o, CHR_u, PCT_SPACE, CHR_b, CHR_r, CHR_i, CHR_n, CHR_g, PCT_SPACE, CHR_m,
    CHR_e, CTR_NEWLINE, CTR_ENDLINE
};

//       my {em-yellow}favorite food{/em}.{button}{end}{endline}
static s16 scenario_text_0096[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_m, CHR_y, PCT_SPACE, CTR_EM_YELLOW,
    CHR_f, CHR_a, CHR_v, CHR_o, CHR_r, CHR_i, CHR_t, CHR_e, PCT_SPACE, CHR_f,
    CHR_o, CHR_o, CHR_d, CTR_CLOSE_EM, PCT_PERIOD, CTR_BUTTON, CTR_END, CTR_ENDLINE
};

// {begin}{endline}
static s16 scenario_text_00D7[] = {
    CTR_BEGIN, CTR_ENDLINE
};

// Ebisumaru:Your {em-yellow}favourite food{/em}?{button}{end}{endline}
static s16 scenario_text_00EB[] = {
    CHR_E, CHR_b, CHR_i, CHR_s, CHR_u, CHR_m, CHR_a, CHR_r, CHR_u, PCT_COLON,
    CHR_Y, CHR_o, CHR_u, CHR_r, PCT_SPACE, CTR_EM_YELLOW, CHR_f, CHR_a, CHR_v, CHR_o,
    CHR_u, CHR_r, CHR_i, CHR_t, CHR_e, PCT_SPACE, CHR_f, CHR_o, CHR_o, CHR_d,
    CTR_CLOSE_EM, PCT_QUESTION, CTR_BUTTON, CTR_END, CTR_ENDLINE
};

// {begin}{endline}
static s16 scenario_text_0133[] = {
    CTR_BEGIN, CTR_ENDLINE
};

// Kihachi:Yes! {newline}{endline}
static s16 scenario_text_0147[] = {
    CHR_K, CHR_i, CHR_h, CHR_a, CHR_c, CHR_h, CHR_i, PCT_COLON, CHR_Y, CHR_e,
    CHR_s, PCT_EXCLAMATION, PCT_SPACE, CTR_NEWLINE, CTR_ENDLINE
};

//       {em-yellow}My favourite food{/em}!{button}{endline}
static s16 scenario_text_016A[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CTR_EM_YELLOW, CHR_M, CHR_y, PCT_SPACE,
    CHR_f, CHR_a, CHR_v, CHR_o, CHR_u, CHR_r, CHR_i, CHR_t, CHR_e, PCT_SPACE,
    CHR_f, CHR_o, CHR_o, CHR_d, CTR_CLOSE_EM, PCT_EXCLAMATION, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_01A7[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Kihachi:Farewell!{endline}
static s16 scenario_text_01BF[] = {
    CHR_K, CHR_i, CHR_h, CHR_a, CHR_c, CHR_h, CHR_i, PCT_COLON, CHR_F, CHR_a,
    CHR_r, CHR_e, CHR_w, CHR_e, CHR_l, CHR_l, PCT_EXCLAMATION, CTR_ENDLINE
};

// {waitinput}{end}{endline}
static s16 scenario_text_01DD[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE
};

// Kihachi:Yes! That's it!{button}{end}{endline}
static s16 scenario_text_009120[] = {
    CHR_K, CHR_i, CHR_h, CHR_a, CHR_c, CHR_h, CHR_i, PCT_COLON, CHR_Y, CHR_e,
    CHR_s, PCT_EXCLAMATION, PCT_SPACE, CHR_T, CHR_h, CHR_a, CHR_t, PCT_APOSTROPHE, CHR_s,
    PCT_SPACE, CHR_i, CHR_t, PCT_EXCLAMATION, CTR_BUTTON, CTR_END, CTR_ENDLINE
};

// Goemon and allies trade their{newline}{endline}
static s16 scenario_text_009154[] = {
    CHR_G, CHR_o, CHR_e, CHR_m, CHR_o, CHR_n, PCT_SPACE, CHR_a, CHR_n, CHR_d,
    PCT_SPACE, CHR_a, CHR_l, CHR_l, CHR_i, CHR_e, CHR_s, PCT_SPACE, CHR_t, CHR_r,
    CHR_a, CHR_d, CHR_e, PCT_SPACE, CHR_t, CHR_h, CHR_e, CHR_i, CHR_r, CTR_NEWLINE, CTR_ENDLINE
};

// {em-yellow}quality cucumber{/em} with{newline}{endline}
static s16 scenario_text_009194[] = {
    CTR_EM_YELLOW, CHR_q, CHR_u, CHR_a, CHR_l, CHR_i, CHR_t, CHR_y, PCT_SPACE, CHR_c,
    CHR_u, CHR_c, CHR_u, CHR_m, CHR_b, CHR_e, CHR_r, CTR_CLOSE_EM, PCT_SPACE, CHR_w,
    CHR_i, CHR_t, CHR_h, CTR_NEWLINE, CTR_ENDLINE
};

// Kihachi's [{em-yellow}Miracle Item{/em}].{button}{end}{endline}
static s16 scenario_text_0091c8[] = {
    CHR_K, CHR_i, CHR_h, CHR_a, CHR_c, CHR_h, CHR_i, PCT_APOSTROPHE, CHR_s, PCT_SPACE,
    PCT_LBRACKET, CTR_EM_YELLOW, CHR_M, CHR_i, CHR_r, CHR_a, CHR_c, CHR_l, CHR_e, PCT_SPACE,
    CHR_I, CHR_t, CHR_e, CHR_m, CTR_CLOSE_EM, PCT_RBRACKET, PCT_PERIOD, CTR_BUTTON, CTR_END, CTR_ENDLINE
};

//  Goemon and allies{newline}{endline}
static s16 scenario_text_005e8c[] = {
    PCT_SPACE, CHR_G, CHR_o, CHR_e, CHR_m, CHR_o, CHR_n, PCT_SPACE, CHR_a, CHR_n,
    CHR_d, PCT_SPACE, CHR_a, CHR_l, CHR_l, CHR_i, CHR_e, CHR_s, CTR_NEWLINE, CTR_ENDLINE
};

//   receive the [{em-yellow}Miracle Snow{/em}], {newline}{endline}
static s16 scenario_text_009204[] = {
    PCT_SPACE, PCT_SPACE, CHR_r, CHR_e, CHR_c, CHR_e, CHR_i, CHR_v, CHR_e, PCT_SPACE,
    CHR_t, CHR_h, CHR_e, PCT_SPACE, PCT_LBRACKET, CTR_EM_YELLOW, CHR_M, CHR_i, CHR_r, CHR_a,
    CHR_c, CHR_l, CHR_e, PCT_SPACE, CHR_S, CHR_n, CHR_o, CHR_w, CTR_CLOSE_EM, PCT_RBRACKET,
    PCT_COMMA, PCT_SPACE, CTR_NEWLINE, CTR_ENDLINE
};

//      shaped like a snow flake.{endline}
static s16 scenario_text_009248[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_s, CHR_h, CHR_a, CHR_p, CHR_e,
    CHR_d, PCT_SPACE, CHR_l, CHR_i, CHR_k, CHR_e, PCT_SPACE, CHR_a, PCT_SPACE, CHR_s,
    CHR_n, CHR_o, CHR_w, PCT_SPACE, CHR_f, CHR_l, CHR_a, CHR_k, CHR_e, PCT_PERIOD, CTR_ENDLINE
};

// {end}{endline}
static s16 scenario_text_0000b0[] = {
    CTR_END, CTR_ENDLINE
};

// Kihachi:Farewell!{endline}
static s16 scenario_text_009058[] = {
    CHR_K, CHR_i, CHR_h, CHR_a, CHR_c, CHR_h, CHR_i, PCT_COLON, CHR_F, CHR_a,
    CHR_r, CHR_e, CHR_w, CHR_e, CHR_l, CHR_l, PCT_EXCLAMATION, CTR_ENDLINE
};

// {button}{end}{endline}
static s16 scenario_text_008ee8[] = {
    CTR_BUTTON, CTR_END, CTR_ENDLINE
};

extern s32 scenario_code_message_163_d320[];

s32 scenario_code_message_163_d320[] = {

    // Address: @d320

    // d320: Write to RAM 801c7768 (Dialogue Window Style)
    STW, (s32)&D_801C7768_1C8368,

    // d328: Store Value: 1
    WTS, 0x1,

    // d330: Print Text
    TXT, (s32)&scenario_text_0000,

    // d338: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // d340: Store Value: 1
    WTS, 0x1,

    // d348: Print Text
    TXT, (s32)&scenario_text_0014,

    // d350: Print Text
    TXT, (s32)&scenario_text_003C,

    // d358: Print Text
    TXT, (s32)&scenario_text_006B,

    // d360: Print Text
    TXT, (s32)&scenario_text_0096,

    // d368: Write to RAM 801c7768 (Dialogue Window Style)
    STW, (s32)&D_801C7768_1C8368,

    // d370: Store Value: 7
    WTS, 0x7,

    // d378: Write to RAM 8007785c (Dialogue Portrait Character)
    STW, (s32)&D_8007785C_7845C,

    // d380: Store Value: 2
    WTS, 0x2,

    // d388: Print Text
    TXT, (s32)&scenario_text_0000,

    // d390: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // d398: Store Value: 1
    WTS, 0x1,

    // d3a0: Print Text
    TXT, (s32)&scenario_text_00EB,

    // d3a8: Write to RAM 801c7768 (Dialogue Window Style)
    STW, (s32)&D_801C7768_1C8368,

    // d3b0: Store Value: 1
    WTS, 0x1,

    // d3b8: Write to RAM 8007785c (Dialogue Portrait Character)
    STW, (s32)&D_8007785C_7845C,

    // d3c0: Store Value: 100
    WTS, 0x100,

    // d3c8: Print Text
    TXT, (s32)&scenario_text_0000,

    // d3d0: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // d3d8: Store Value: 1
    WTS, 0x1,

    // d3e0: Print Text
    TXT, (s32)&scenario_text_0147,

    // d3e8: Print Text
    TXT, (s32)&scenario_text_016A,

    // d3f0: Print Text
    TXT, (s32)&scenario_text_01A7,

    // d3f8: Print Text
    TXT, (s32)&scenario_text_01BF,

    // d400: Set Flag 037 (Kihachi Will Give Favorite Food Hint)
    SFG, 0x37,

    // d408: Set Flag 022 (Looking for Kihachi's Favorite Food)
    SFG, 0x22,

    // d490: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // d498: Store Value: 1
    WTS, 0x1,

    // d4a0: Print Text
    TXT, (s32)&scenario_text_009120,

    // d4a8: Write to RAM 801c7758 (Unknown)
    STW, (s32)&D_801C7758_1C8358,

    // d4b0: Store Value: 20
    WTS, 0x20,

    // d4b8: Write to RAM 801c775c (Dialogue Portrait Y Pos)
    STW, (s32)&D_801C775C_1C835C,

    // d4c0: Store Value: 48
    WTS, 0x48,

    // d4c8: Write to RAM 801c7768 (Unknown)
    STW, (s32)&D_801C7768_1C8368,

    // d4d0: Store Value: 7
    WTS, 0x7,

    // d4d8: Print Text
    TXT, (s32)&scenario_text_0000,

    // d4e0: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // d4e8: Store Value: 1
    WTS, 0x1,

    // d4f0: Write to RAM 801c7740 (Scratch)
    STW, (s32)&D_801C7740_1C8340,

    // d4f8: Store Value: 26c
    WTS, 0x26c,

    // d500: Execute Code: 8003f608 (Unknown)
    ESR, (s32)&func_8003F608_40208,

    // d508: Print Text
    TXT, (s32)&scenario_text_009154,

    // d510: Print Text
    TXT, (s32)&scenario_text_009194,

    // d518: Print Text
    TXT, (s32)&scenario_text_0091c8,

    // d520: Write to RAM 801c7758 (Unknown)
    STW, (s32)&D_801C7758_1C8358,

    // d528: Store Value: 20
    WTS, 0x20,

    // d530: Write to RAM 801c775c (Dialogue Portrait Y Pos)
    STW, (s32)&D_801C775C_1C835C,

    // d538: Store Value: 20
    WTS, 0x20,

    // d540: Write to RAM 801c7768 (Unknown)
    STW, (s32)&D_801C7768_1C8368,

    // d548: Store Value: 7
    WTS, 0x7,

    // d550: Print Text
    TXT, (s32)&scenario_text_0000,

    // d558: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // d560: Store Value: 1
    WTS, 0x1,

    // d568: Print Text
    TXT, (s32)&scenario_text_01A7,

    // d570: Write to RAM 801c7740 (Scratch)
    STW, (s32)&D_801C7740_1C8340,

    // d578: Store Value: 14
    WTS, 0x14,

    // d580: Execute Code: 8003f608 (Unknown)
    ESR, (s32)&func_8003F608_40208,

    // d588: Print Text
    TXT, (s32)&scenario_text_005e8c,

    // d590: Print Text
    TXT, (s32)&scenario_text_009204,

    // d598: Print Text
    TXT, (s32)&scenario_text_009248,

    // d5a0: Write to RAM 801c7740 (Scratch)
    STW, (s32)&D_801C7740_1C8340,

    // d5a8: Store Value: 96
    WTS, 0x96,

    // d5b0: Execute Code: 8003f460 (Wait For Timer)
    ESR, (s32)&func_8003F460_40060,

    // d5b8: Print Text
    TXT, (s32)&scenario_text_0000b0,

    // d5c0: Write to RAM 8015c864 (Obtained Miracle Snow)
    STW, 0x8015c864,

    // d5c8: Store Value: 1
    WTS, 0x1,

    // d5d0: Set Flag 035 (Obtained Miracle Snow)
    SFG, 0x35,

    // d5d8: Write to RAM 801c7758 (Unknown)
    STW, (s32)&D_801C7758_1C8358,

    // d5e0: Store Value: 20
    WTS, 0x20,

    // d5e8: Write to RAM 801c775c (Dialogue Portrait Y Pos)
    STW, (s32)&D_801C775C_1C835C,

    // d5f0: Store Value: 20
    WTS, 0x20,

    // d5f8: Write to RAM 801c7768 (Unknown)
    STW, (s32)&D_801C7768_1C8368,

    // d600: Store Value: 1
    WTS, 0x1,

    // d608: Print Text
    TXT, (s32)&scenario_text_0000,

    // d610: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // d618: Store Value: 1
    WTS, 0x1,

    // d620: Print Text
    TXT, (s32)&scenario_text_01A7,

    // d628: Print Text
    TXT, (s32)&scenario_text_009058,

    // d630: Print Text
    TXT, (s32)&scenario_text_008ee8,

    // d638: End Event
    END,

    // End scenario script
    END,
};
