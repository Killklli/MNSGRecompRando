#include "types.h"
#include "save_data_tool.h"
#include "scenario.h"
#include "scenario_replacer.h"



// MACHI 0 - Oedo - Bridge to Musashi - Guard (Gatekeeper)
// Address: @8258

// {begin}{endline}
static s16 scenario_text_0000[] = {CTR_BEGIN, CTR_ENDLINE};

// Gate keeper:Woo-oooooooow!{button}{endline}
static s16 scenario_text_0014[] = {
    CHR_G, CHR_a, CHR_t, CHR_e, PCT_SPACE, CHR_k, CHR_e,
    CHR_e, CHR_p, CHR_e, CHR_r, PCT_COLON, CHR_W, CHR_o,
    CHR_o, PCT_DASH, CHR_o, CHR_o, CHR_o, CHR_o, CHR_o,
    CHR_o, CHR_o, CHR_o, CHR_w, PCT_EXCLAMATION, CTR_BUTTON, CTR_ENDLINE};

// {newwindow}{endline}
static s16 scenario_text_0043[] = {CTR_NEWWINDOW, CTR_ENDLINE};

// {em-yellow}The automatic closing device{/em} has{newline}{endline}
static s16 scenario_text_005B[] = {
    CTR_EM_YELLOW, CHR_T, CHR_h, CHR_e, PCT_SPACE, CHR_a,
    CHR_u, CHR_t, CHR_o, CHR_m, CHR_a, CHR_t,
    CHR_i, CHR_c, PCT_SPACE, CHR_c, CHR_l, CHR_o,
    CHR_s, CHR_i, CHR_n, CHR_g, PCT_SPACE, CHR_d,
    CHR_e, CHR_v, CHR_i, CHR_c, CHR_e, CTR_CLOSE_EM,
    PCT_SPACE, CHR_h, CHR_a, CHR_s, CTR_NEWLINE, CTR_ENDLINE};

// been activated on the gate.{newline}{endline}
static s16 scenario_text_00A1[] = {
    CHR_b, CHR_e, CHR_e, CHR_n, PCT_SPACE, CHR_a,
    CHR_c, CHR_t, CHR_i, CHR_v, CHR_a, CHR_t,
    CHR_e, CHR_d, PCT_SPACE, CHR_o, CHR_n, PCT_SPACE,
    CHR_t, CHR_h, CHR_e, PCT_SPACE, CHR_g, CHR_a,
    CHR_t, CHR_e, PCT_PERIOD, CTR_NEWLINE, CTR_ENDLINE};

// It will no longer open!{button}{endline}
static s16 scenario_text_00D2[] = {
    CHR_I, CHR_t, PCT_SPACE, CHR_w, CHR_i, CHR_l, CHR_l,
    PCT_SPACE, CHR_n, CHR_o, PCT_SPACE, CHR_l, CHR_o, CHR_n,
    CHR_g, CHR_e, CHR_r, PCT_SPACE, CHR_o, CHR_p, CHR_e,
    CHR_n, PCT_EXCLAMATION, CTR_BUTTON, CTR_ENDLINE};

// {newwindow}{endline}
static s16 scenario_text_00FE[] = {CTR_NEWWINDOW, CTR_ENDLINE};

// What the...!{newline}{endline}
static s16 scenario_text_0116[] = {
    CHR_W, CHR_h, CHR_a, CHR_t, PCT_SPACE,
    CHR_t, CHR_h, CHR_e, PCT_PERIOD, PCT_PERIOD,
    PCT_PERIOD, PCT_EXCLAMATION, CTR_NEWLINE, CTR_ENDLINE};

// Something serious is taking place{newline}{endline}
static s16 scenario_text_0138[] = {
    CHR_S, CHR_o, CHR_m, CHR_e, CHR_t, CHR_h, CHR_i,
    CHR_n, CHR_g, PCT_SPACE, CHR_s, CHR_e, CHR_r, CHR_i,
    CHR_o, CHR_u, CHR_s, PCT_SPACE, CHR_i, CHR_s, PCT_SPACE,
    CHR_t, CHR_a, CHR_k, CHR_i, CHR_n, CHR_g, PCT_SPACE,
    CHR_p, CHR_l, CHR_a, CHR_c, CHR_e, CTR_NEWLINE, CTR_ENDLINE};

// at {em-yellow}Oedo Castle{/em}!{endline}
static s16 scenario_text_016F[] = {
    CHR_a, CHR_t, PCT_SPACE, CTR_EM_YELLOW, CHR_O, CHR_e,
    CHR_d, CHR_o, PCT_SPACE, CHR_C, CHR_a, CHR_s,
    CHR_t, CHR_l, CHR_e, CTR_CLOSE_EM, PCT_EXCLAMATION, CTR_ENDLINE};

// {waitinput}{end}{endline}
static s16 scenario_text_019B[] = {CTR_WAITINPUT, CTR_END, CTR_ENDLINE};

// Address: @82c0

// Gate keeper:Oh my god!{button}{endline}
static s16 scenario_text_01B8[] = {
    CHR_G, CHR_a, CHR_t, CHR_e, PCT_SPACE, CHR_k,
    CHR_e, CHR_e, CHR_p, CHR_e, CHR_r, PCT_COLON,
    CHR_O, CHR_h, PCT_SPACE, CHR_m, CHR_y, PCT_SPACE,
    CHR_g, CHR_o, CHR_d, PCT_EXCLAMATION, CTR_BUTTON, CTR_ENDLINE};

// {newwindow}{endline}
static s16 scenario_text_01E3[] = {CTR_NEWWINDOW, CTR_ENDLINE};

// This is {em-yellow}the Lord's Super Pass{/em}!{button}{endline}
static s16 scenario_text_01FB[] = {
    CHR_T, CHR_h, CHR_i, CHR_s, PCT_SPACE,
    CHR_i, CHR_s, PCT_SPACE, CTR_EM_YELLOW, CHR_t,
    CHR_h, CHR_e, PCT_SPACE, CHR_L, CHR_o,
    CHR_r, CHR_d, PCT_APOSTROPHE, CHR_s, PCT_SPACE,
    CHR_S, CHR_u, CHR_p, CHR_e, CHR_r,
    PCT_SPACE, CHR_P, CHR_a, CHR_s, CHR_s,
    CTR_CLOSE_EM, PCT_EXCLAMATION, CTR_BUTTON, CTR_ENDLINE};

// {newwindow}{endline}
static s16 scenario_text_023E[] = {CTR_NEWWINDOW, CTR_ENDLINE};

// With this, the gate will open!{endline}
static s16 scenario_text_0256[] = {
    CHR_W, CHR_i, CHR_t, CHR_h, PCT_SPACE, CHR_t,
    CHR_h, CHR_i, CHR_s, PCT_COMMA, PCT_SPACE, CHR_t,
    CHR_h, CHR_e, PCT_SPACE, CHR_g, CHR_a, CHR_t,
    CHR_e, PCT_SPACE, CHR_w, CHR_i, CHR_l, CHR_l,
    PCT_SPACE, CHR_o, CHR_p, CHR_e, CHR_n, PCT_EXCLAMATION,
    CTR_ENDLINE};

// {waitinput}{end}{endline}
static s16 scenario_text_0281[] = {CTR_WAITINPUT, CTR_END, CTR_ENDLINE};

// Address: @8344

// Gate keeper:That's it for us!{button}{endline}
static s16 scenario_text_029E[] = {
    CHR_G, CHR_a, CHR_t, CHR_e, PCT_SPACE, CHR_k, CHR_e,
    CHR_e, CHR_p, CHR_e, CHR_r, PCT_COLON, CHR_T, CHR_h,
    CHR_a, CHR_t, PCT_APOSTROPHE, CHR_s, PCT_SPACE, CHR_i, CHR_t,
    PCT_SPACE, CHR_f, CHR_o, CHR_r, PCT_SPACE, CHR_u, CHR_s,
    PCT_EXCLAMATION, CTR_BUTTON, CTR_ENDLINE};

// {newwindow}{endline}
static s16 scenario_text_02D0[] = {CTR_NEWWINDOW, CTR_ENDLINE};

// If only the title to this game{newline}{endline}
static s16 scenario_text_02E8[] = {
    CHR_I, CHR_f, PCT_SPACE, CHR_o, CHR_n, CHR_l, CHR_y,
    PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE, CHR_t, CHR_i,
    CHR_t, CHR_l, CHR_e, PCT_SPACE, CHR_t, CHR_o, PCT_SPACE,
    CHR_t, CHR_h, CHR_i, CHR_s, PCT_SPACE, CHR_g, CHR_a,
    CHR_m, CHR_e, CTR_NEWLINE, CTR_ENDLINE};

// was "{em-yellow}Starring Gate keeper{/em}" {newline}{endline}
static s16 scenario_text_031C[] = {
    CHR_w, CHR_a, CHR_s, PCT_SPACE, PCT_QUOTE, CTR_EM_YELLOW,
    CHR_S, CHR_t, CHR_a, CHR_r, CHR_r, CHR_i,
    CHR_n, CHR_g, PCT_SPACE, CHR_G, CHR_a, CHR_t,
    CHR_e, PCT_SPACE, CHR_k, CHR_e, CHR_e, CHR_p,
    CHR_e, CHR_r, CTR_CLOSE_EM, PCT_QUOTE, PCT_SPACE, CTR_NEWLINE,
    CTR_ENDLINE};

// rather than "{em-yellow}Starring Goemon{/em}".{button}{endline}
static s16 scenario_text_035D[] = {
    CHR_r, CHR_a, CHR_t, CHR_h, CHR_e, CHR_r,
    PCT_SPACE, CHR_t, CHR_h, CHR_a, CHR_n, PCT_SPACE,
    PCT_QUOTE, CTR_EM_YELLOW, CHR_S, CHR_t, CHR_a, CHR_r,
    CHR_r, CHR_i, CHR_n, CHR_g, PCT_SPACE, CHR_G,
    CHR_o, CHR_e, CHR_m, CHR_o, CHR_n, CTR_CLOSE_EM,
    PCT_QUOTE, PCT_PERIOD, CTR_BUTTON, CTR_ENDLINE};

// {newwindow}{endline}
static s16 scenario_text_03A0[] = {CTR_NEWWINDOW, CTR_ENDLINE};

// Then, we'd have a lot more fun!{newline}{endline}
static s16 scenario_text_03B8[] = {
    CHR_T, CHR_h, CHR_e, CHR_n, PCT_COMMA,
    PCT_SPACE, CHR_w, CHR_e, PCT_APOSTROPHE, CHR_d,
    PCT_SPACE, CHR_h, CHR_a, CHR_v, CHR_e,
    PCT_SPACE, CHR_a, PCT_SPACE, CHR_l, CHR_o,
    CHR_t, PCT_SPACE, CHR_m, CHR_o, CHR_r,
    CHR_e, PCT_SPACE, CHR_f, CHR_u, CHR_n,
    PCT_EXCLAMATION, CTR_NEWLINE, CTR_ENDLINE};

// Awww!{endline}
static s16 scenario_text_03ED[] = {CHR_A, CHR_w, CHR_w,
                                   CHR_w, PCT_EXCLAMATION, CTR_ENDLINE};

// {waitinput}{end}{endline}
static s16 scenario_text_03FF[] = {CTR_WAITINPUT, CTR_END, CTR_ENDLINE};

// Address: @839c

// Gate keeper:Hey!{newline}{endline}
static s16 scenario_text_041C[] = {
    CHR_G, CHR_a, CHR_t, CHR_e, PCT_SPACE, CHR_k,
    CHR_e, CHR_e, CHR_p, CHR_e, CHR_r, PCT_COLON,
    CHR_H, CHR_e, CHR_y, PCT_EXCLAMATION, CTR_NEWLINE, CTR_ENDLINE};

//   Long time no see!{button}{endline}
static s16 scenario_text_0442[] = {
    PCT_SPACE, PCT_SPACE, CHR_L, CHR_o, CHR_n, CHR_g,
    PCT_SPACE, CHR_t, CHR_i, CHR_m, CHR_e, PCT_SPACE,
    CHR_n, CHR_o, PCT_SPACE, CHR_s, CHR_e, CHR_e,
    PCT_EXCLAMATION, CTR_BUTTON, CTR_ENDLINE};

// {newwindow}{endline}
static s16 scenario_text_046A[] = {CTR_NEWWINDOW, CTR_ENDLINE};

// The next {em-yellow}area{/em} you must{newline}{endline}
static s16 scenario_text_0482[] = {
    CHR_T, CHR_h, CHR_e, PCT_SPACE, CHR_n, CHR_e,
    CHR_x, CHR_t, PCT_SPACE, CTR_EM_YELLOW, CHR_a, CHR_r,
    CHR_e, CHR_a, CTR_CLOSE_EM, PCT_SPACE, CHR_y, CHR_o,
    CHR_u, PCT_SPACE, CHR_m, CHR_u, CHR_s, CHR_t,
    CTR_NEWLINE, CTR_ENDLINE};

// enter is...{button}{endline}
static s16 scenario_text_04BE[] = {
    CHR_e, CHR_n, CHR_t, CHR_e, CHR_r, PCT_SPACE, CHR_i,
    CHR_s, PCT_PERIOD, PCT_PERIOD, PCT_PERIOD, CTR_BUTTON, CTR_ENDLINE};

// {newwindow}{endline}
static s16 scenario_text_04DE[] = {CTR_NEWWINDOW, CTR_ENDLINE};

// I think it's to the {em-yellow}east{/em}{newline}{endline}
static s16 scenario_text_04F6[] = {
    CHR_I, PCT_SPACE, CHR_t, CHR_h, CHR_i, CHR_n,
    CHR_k, PCT_SPACE, CHR_i, CHR_t, PCT_APOSTROPHE, CHR_s,
    PCT_SPACE, CHR_t, CHR_o, PCT_SPACE, CHR_t, CHR_h,
    CHR_e, PCT_SPACE, CTR_EM_YELLOW, CHR_e, CHR_a, CHR_s,
    CHR_t, CTR_CLOSE_EM, CTR_NEWLINE, CTR_ENDLINE};

// of [{em-yellow}Musashi{/em}].{button}{endline}
static s16 scenario_text_0534[] = {
    CHR_o, CHR_f, PCT_SPACE, PCT_LBRACKET, CTR_EM_YELLOW, CHR_M,
    CHR_u, CHR_s, CHR_a, CHR_s, CHR_h, CHR_i,
    CTR_CLOSE_EM, PCT_RBRACKET, PCT_PERIOD, CTR_BUTTON, CTR_ENDLINE};

// {newwindow}{endline}
static s16 scenario_text_0566[] = {CTR_NEWWINDOW, CTR_ENDLINE};

// You'll find [{em-yellow}Musashi{/em}] as you{newline}{endline}
static s16 scenario_text_057E[] = {
    CHR_Y, CHR_o, CHR_u, PCT_APOSTROPHE, CHR_l,
    CHR_l, PCT_SPACE, CHR_f, CHR_i, CHR_n,
    CHR_d, PCT_SPACE, PCT_LBRACKET, CTR_EM_YELLOW, CHR_M,
    CHR_u, CHR_s, CHR_a, CHR_s, CHR_h,
    CHR_i, CTR_CLOSE_EM, PCT_RBRACKET, PCT_SPACE, CHR_a,
    CHR_s, PCT_SPACE, CHR_y, CHR_o, CHR_u,
    CTR_NEWLINE, CTR_ENDLINE};

// pass through the gate into{newline}{endline}
static s16 scenario_text_05C0[] = {
    CHR_p, CHR_a, CHR_s, CHR_s, PCT_SPACE, CHR_t, CHR_h,
    CHR_r, CHR_o, CHR_u, CHR_g, CHR_h, PCT_SPACE, CHR_t,
    CHR_h, CHR_e, PCT_SPACE, CHR_g, CHR_a, CHR_t, CHR_e,
    PCT_SPACE, CHR_i, CHR_n, CHR_t, CHR_o, CTR_NEWLINE, CTR_ENDLINE};

// this town.{button}{endline}
static s16 scenario_text_05F0[] = {
    CHR_t, CHR_h, CHR_i, CHR_s, PCT_SPACE, CHR_t,
    CHR_o, CHR_w, CHR_n, PCT_PERIOD, CTR_BUTTON, CTR_ENDLINE};

// {newwindow}{endline}
static s16 scenario_text_060F[] = {CTR_NEWWINDOW, CTR_ENDLINE};

// ...or at least that's{newline}{endline}
static s16 scenario_text_0627[] = {
    PCT_PERIOD, PCT_PERIOD, PCT_PERIOD, CHR_o, CHR_r, PCT_SPACE,
    CHR_a, CHR_t, PCT_SPACE, CHR_l, CHR_e, CHR_a,
    CHR_s, CHR_t, PCT_SPACE, CHR_t, CHR_h, CHR_a,
    CHR_t, PCT_APOSTROPHE, CHR_s, CTR_NEWLINE, CTR_ENDLINE};

// what my gut feeling is!{endline}
static s16 scenario_text_0652[] = {
    CHR_w, CHR_h, CHR_a, CHR_t, PCT_SPACE, CHR_m,
    CHR_y, PCT_SPACE, CHR_g, CHR_u, CHR_t, PCT_SPACE,
    CHR_f, CHR_e, CHR_e, CHR_l, CHR_i, CHR_n,
    CHR_g, PCT_SPACE, CHR_i, CHR_s, PCT_EXCLAMATION, CTR_ENDLINE};

// {waitinput}{end}{endline}
static s16 scenario_text_0676[] = {CTR_WAITINPUT, CTR_END, CTR_ENDLINE};

extern s32 scenario_code_message_10e_8258[];
extern s32 scenario_code_message_10e_82c0[];
extern s32 scenario_code_message_10e_8344[];
extern s32 scenario_code_message_10e_839c[];

s32 scenario_code_message_10e_8258[] = {

    // Address: @8258
    // MACHI 0 - Oedo - Bridge to Musashi - Guard (Gatekeeper)

    // 8258: Print Text
    TXT,
    (s32)&scenario_text_0000,

    // 82d0: Execute subroutine to check super pass and set flag 0x501
    ESR,
    (s32)check_super_pass_and_set_flag,

    // 8260: If Flag 000 (Received Super Pass), Jump To @82c0
    // Jump if flag 0x501 is SET to @82c0
    JFS,
    0x501,
    (s32)&scenario_code_message_10e_82c0,

    // 826c: Print Text
    TXT,
    (s32)&scenario_text_0014,

    // 8274: Print Text
    TXT,
    (s32)&scenario_text_0043,

    // 827c: Print Text
    TXT,
    (s32)&scenario_text_005B,

    // 8284: Print Text
    TXT,
    (s32)&scenario_text_00A1,

    // 828c: Print Text
    TXT,
    (s32)&scenario_text_00D2,

    // 8294: Print Text
    TXT,
    (s32)&scenario_text_0043,

    // 829c: Print Text
    TXT,
    (s32)&scenario_text_0116,

    // 82a4: Print Text
    TXT,
    (s32)&scenario_text_0138,

    // 82ac: Print Text
    TXT,
    (s32)&scenario_text_016F,

    // 82b4: Print Text
    TXT,
    (s32)&scenario_text_019B,

    // 82bc: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_10e_82c0[] = {

    // Address: @82c0

    // Clear temporary flag 0x80 since we've used it
    CFG,
    0x501,

    // 82c0: If Flag 001 (Opened Super Pass Gate), Jump To @8344
    // Jump if flag 0x01 is SET to @8344
    JFS,
    0x01,
    (s32)&scenario_code_message_10e_8344,

    // 82cc: Write to RAM 801c7770 (Unknown)
    STW,
    (s32)&D_801C7770_1C8370,

    // 82d4: Store Value: 1
    WTS,
    0x1,

    // 82dc: Print Text
    TXT,
    (s32)&scenario_text_01B8,

    // 82e4: Print Text
    TXT,
    (s32)&scenario_text_0043,

    // 82ec: Print Text
    TXT,
    (s32)&scenario_text_01FB,

    // 82f4: Print Text
    TXT,
    (s32)&scenario_text_0043,

    // 82fc: Print Text
    TXT,
    (s32)&scenario_text_0256,

    // 8304: Set Flag 001 (Opened Super Pass Gate)
    SFG,
    0x01,

    // 830c: Print Text
    TXT,
    (s32)&scenario_text_019B,

    // 8314: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_10e_8344[] = {

    // Address: @8344

    // 8344: If Flag 017 (Kyushu Disappeared), Jump To @839c
    // Jump if flag 0x17 is SET to @839c
    JFS,
    0x17,
    (s32)&scenario_code_message_10e_839c,

    // 8350: Print Text
    TXT,
    (s32)&scenario_text_029E,

    // 8358: Print Text
    TXT,
    (s32)&scenario_text_0043,

    // 8360: Print Text
    TXT,
    (s32)&scenario_text_02E8,

    // 8368: Print Text
    TXT,
    (s32)&scenario_text_031C,

    // 8370: Print Text
    TXT,
    (s32)&scenario_text_035D,

    // 8378: Print Text
    TXT,
    (s32)&scenario_text_0043,

    // 8380: Print Text
    TXT,
    (s32)&scenario_text_03B8,

    // 8388: Print Text
    TXT,
    (s32)&scenario_text_03ED,

    // 8390: Print Text
    TXT,
    (s32)&scenario_text_019B,

    // 8398: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_10e_839c[] = {

    // Address: @839c

    // 839c: Print Text
    TXT,
    (s32)&scenario_text_041C,

    // 83a4: Print Text
    TXT,
    (s32)&scenario_text_0442,

    // 83ac: Print Text
    TXT,
    (s32)&scenario_text_0043,

    // 83b4: Print Text
    TXT,
    (s32)&scenario_text_0482,

    // 83bc: Print Text
    TXT,
    (s32)&scenario_text_04BE,

    // 83c4: Print Text
    TXT,
    (s32)&scenario_text_0043,

    // 83cc: Print Text
    TXT,
    (s32)&scenario_text_04F6,

    // 83d4: Print Text
    TXT,
    (s32)&scenario_text_0534,

    // 83dc: Print Text
    TXT,
    (s32)&scenario_text_0043,

    // 83e4: Print Text
    TXT,
    (s32)&scenario_text_057E,

    // 83ec: Print Text
    TXT,
    (s32)&scenario_text_05C0,

    // 83f4: Print Text
    TXT,
    (s32)&scenario_text_05F0,

    // 83fc: Print Text
    TXT,
    (s32)&scenario_text_0043,

    // 8404: Print Text
    TXT,
    (s32)&scenario_text_0627,

    // 840c: Print Text
    TXT,
    (s32)&scenario_text_0652,

    // 8414: Print Text
    TXT,
    (s32)&scenario_text_019B,

    // 841c: End Event
    END,

    // End scenario script
    END,
};
