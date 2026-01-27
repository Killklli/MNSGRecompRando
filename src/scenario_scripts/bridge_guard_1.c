#include "types.h"
#include "modding.h"
#include "save_data_tool.h"
#include "scenario.h"
#include "scenario_replacer.h"



// MACHI 0 - Oedo - Bridge to Musashi - Guard (Gatekeeper)
// Address: @8420

// {begin}{endline}
static s16 scenario_text_0000[] = {CTR_BEGIN, CTR_ENDLINE};

// Gate keeper:Well,{newline}{endline}
static s16 scenario_text_0014[] = {
    CHR_G, CHR_a, CHR_t, CHR_e, PCT_SPACE, CHR_k, CHR_e,
    CHR_e, CHR_p, CHR_e, CHR_r, PCT_COLON, CHR_W, CHR_e,
    CHR_l, CHR_l, PCT_COMMA, CTR_NEWLINE, CTR_ENDLINE};

//   the only way to pass{newline}{endline}
static s16 scenario_text_003B[] = {
    PCT_SPACE, PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE,
    CHR_o, CHR_n, CHR_l, CHR_y, PCT_SPACE, CHR_w,
    CHR_a, CHR_y, PCT_SPACE, CHR_t, CHR_o, PCT_SPACE,
    CHR_p, CHR_a, CHR_s, CHR_s, CTR_NEWLINE, CTR_ENDLINE};

//   this checkpoint...{button}{endline}
static s16 scenario_text_0067[] = {
    PCT_SPACE, PCT_SPACE, CHR_t, CHR_h, CHR_i, CHR_s,
    PCT_SPACE, CHR_c, CHR_h, CHR_e, CHR_c, CHR_k,
    CHR_p, CHR_o, CHR_i, CHR_n, CHR_t, PCT_PERIOD,
    PCT_PERIOD, PCT_PERIOD, CTR_BUTTON, CTR_ENDLINE};

// {newwindow}{endline}
static s16 scenario_text_0090[] = {CTR_NEWWINDOW, CTR_ENDLINE};

// ...is to get {em-yellow}the Super Pass{/em}{newline}{endline}
static s16 scenario_text_00A8[] = {
    PCT_PERIOD, PCT_PERIOD, PCT_PERIOD, CHR_i, CHR_s, PCT_SPACE,
    CHR_t, CHR_o, PCT_SPACE, CHR_g, CHR_e, CHR_t,
    PCT_SPACE, CTR_EM_YELLOW, CHR_t, CHR_h, CHR_e, PCT_SPACE,
    CHR_S, CHR_u, CHR_p, CHR_e, CHR_r, PCT_SPACE,
    CHR_P, CHR_a, CHR_s, CHR_s, CTR_CLOSE_EM, CTR_NEWLINE,
    CTR_ENDLINE};

// from {em-yellow}the Lord{/em}.{endline}
static s16 scenario_text_00E9[] = {
    CHR_f, CHR_r, CHR_o, CHR_m, PCT_SPACE, CTR_EM_YELLOW,
    CHR_t, CHR_h, CHR_e, PCT_SPACE, CHR_L, CHR_o,
    CHR_r, CHR_d, CTR_CLOSE_EM, PCT_PERIOD, CTR_ENDLINE};

// {waitinput}{end}{endline}
static s16 scenario_text_0114[] = {CTR_WAITINPUT, CTR_END, CTR_ENDLINE};

// Address: @8470

// Gate keeper:Wait a minute!{button}{endline}
static s16 scenario_text_0131[] = {
    CHR_G, CHR_a, CHR_t, CHR_e, PCT_SPACE, CHR_k, CHR_e,
    CHR_e, CHR_p, CHR_e, CHR_r, PCT_COLON, CHR_W, CHR_a,
    CHR_i, CHR_t, PCT_SPACE, CHR_a, PCT_SPACE, CHR_m, CHR_i,
    CHR_n, CHR_u, CHR_t, CHR_e, PCT_EXCLAMATION, CTR_BUTTON, CTR_ENDLINE};

// {newwindow}{endline}
static s16 scenario_text_0160[] = {CTR_NEWWINDOW, CTR_ENDLINE};

// That's {em-yellow}the Lord's Super Pass{/em}!{button}{endline}
static s16 scenario_text_0178[] = {
    CHR_T, CHR_h, CHR_a, CHR_t, PCT_APOSTROPHE,
    CHR_s, PCT_SPACE, CTR_EM_YELLOW, CHR_t, CHR_h,
    CHR_e, PCT_SPACE, CHR_L, CHR_o, CHR_r,
    CHR_d, PCT_APOSTROPHE, CHR_s, PCT_SPACE, CHR_S,
    CHR_u, CHR_p, CHR_e, CHR_r, PCT_SPACE,
    CHR_P, CHR_a, CHR_s, CHR_s, CTR_CLOSE_EM,
    PCT_EXCLAMATION, CTR_BUTTON, CTR_ENDLINE};

// {newwindow}{endline}
static s16 scenario_text_01BA[] = {CTR_NEWWINDOW, CTR_ENDLINE};

// As long as you have it,{newline}{endline}
static s16 scenario_text_01D2[] = {
    CHR_A, CHR_s, PCT_SPACE, CHR_l, CHR_o, CHR_n, CHR_g,
    PCT_SPACE, CHR_a, CHR_s, PCT_SPACE, CHR_y, CHR_o, CHR_u,
    PCT_SPACE, CHR_h, CHR_a, CHR_v, CHR_e, PCT_SPACE, CHR_i,
    CHR_t, PCT_COMMA, CTR_NEWLINE, CTR_ENDLINE};

// you can open the gate!{endline}
static s16 scenario_text_01FF[] = {
    CHR_y, CHR_o, CHR_u, PCT_SPACE, CHR_c, CHR_a,
    CHR_n, PCT_SPACE, CHR_o, CHR_p, CHR_e, CHR_n,
    PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE, CHR_g,
    CHR_a, CHR_t, CHR_e, PCT_EXCLAMATION, CTR_ENDLINE};

// {waitinput}{end}{endline}
static s16 scenario_text_0222[] = {CTR_WAITINPUT, CTR_END, CTR_ENDLINE};

// Address: @84d0

// Gate keeper:We'll{newline}{endline}
static s16 scenario_text_023F[] = {
    CHR_G, CHR_a, CHR_t, CHR_e, PCT_SPACE, CHR_k, CHR_e,
    CHR_e, CHR_p, CHR_e, CHR_r, PCT_COLON, CHR_W, CHR_e,
    PCT_APOSTROPHE, CHR_l, CHR_l, CTR_NEWLINE, CTR_ENDLINE};

//      just keep standing here{newline}{endline}
static s16 scenario_text_0266[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_j,
    CHR_u, CHR_s, CHR_t, PCT_SPACE, CHR_k, CHR_e,
    CHR_e, CHR_p, PCT_SPACE, CHR_s, CHR_t, CHR_a,
    CHR_n, CHR_d, CHR_i, CHR_n, CHR_g, PCT_SPACE,
    CHR_h, CHR_e, CHR_r, CHR_e, CTR_NEWLINE, CTR_ENDLINE};

//      until you clear the game.{button}{endline}
static s16 scenario_text_0298[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_u, CHR_n,
    CHR_t, CHR_i, CHR_l, PCT_SPACE, CHR_y, CHR_o, CHR_u,
    PCT_SPACE, CHR_c, CHR_l, CHR_e, CHR_a, CHR_r, PCT_SPACE,
    CHR_t, CHR_h, CHR_e, PCT_SPACE, CHR_g, CHR_a, CHR_m,
    CHR_e, PCT_PERIOD, CTR_BUTTON, CTR_ENDLINE};

// {newwindow}{endline}
static s16 scenario_text_02CB[] = {CTR_NEWWINDOW, CTR_ENDLINE};

// ...{newline}{endline}
static s16 scenario_text_02E3[] = {PCT_PERIOD, PCT_PERIOD, PCT_PERIOD,
                                   CTR_NEWLINE, CTR_ENDLINE};

// ...kinda painful...{button}{endline}
static s16 scenario_text_02FC[] = {
    PCT_PERIOD, PCT_PERIOD, PCT_PERIOD, CHR_k, CHR_i, CHR_n,
    CHR_d, CHR_a, PCT_SPACE, CHR_p, CHR_a, CHR_i,
    CHR_n, CHR_f, CHR_u, CHR_l, PCT_PERIOD, PCT_PERIOD,
    PCT_PERIOD, CTR_BUTTON, CTR_ENDLINE};

// {newwindow}{endline}
static s16 scenario_text_0324[] = {CTR_NEWWINDOW, CTR_ENDLINE};

// ...{newline}{endline}
static s16 scenario_text_033C[] = {PCT_PERIOD, PCT_PERIOD, PCT_PERIOD,
                                   CTR_NEWLINE, CTR_ENDLINE};

// ...kinda depressing...{endline}
static s16 scenario_text_0355[] = {
    PCT_PERIOD, PCT_PERIOD, PCT_PERIOD, CHR_k, CHR_i, CHR_n,
    CHR_d, CHR_a, PCT_SPACE, CHR_d, CHR_e, CHR_p,
    CHR_r, CHR_e, CHR_s, CHR_s, CHR_i, CHR_n,
    CHR_g, PCT_PERIOD, PCT_PERIOD, PCT_PERIOD, CTR_ENDLINE};

// {waitinput}{end}{endline}
static s16 scenario_text_0378[] = {CTR_WAITINPUT, CTR_END, CTR_ENDLINE};

// Address: @8530

// Gate keeper:The northeast!{newline}{endline}
static s16 scenario_text_0395[] = {
    CHR_G, CHR_a, CHR_t, CHR_e, PCT_SPACE, CHR_k, CHR_e,
    CHR_e, CHR_p, CHR_e, CHR_r, PCT_COLON, CHR_T, CHR_h,
    CHR_e, PCT_SPACE, CHR_n, CHR_o, CHR_r, CHR_t, CHR_h,
    CHR_e, CHR_a, CHR_s, CHR_t, PCT_EXCLAMATION, CTR_NEWLINE, CTR_ENDLINE};

//   Metal chest!{newline}{endline}
static s16 scenario_text_03C5[] = {
    PCT_SPACE, PCT_SPACE, CHR_M, CHR_e, CHR_t, CHR_a,
    CHR_l, PCT_SPACE, CHR_c, CHR_h, CHR_e, CHR_s,
    CHR_t, PCT_EXCLAMATION, CTR_NEWLINE, CTR_ENDLINE};

//   The northeast! Metal chest!{newline}{endline}
static s16 scenario_text_03E9[] = {
    PCT_SPACE, PCT_SPACE, CHR_T, CHR_h, CHR_e, PCT_SPACE,
    CHR_n, CHR_o, CHR_r, CHR_t, CHR_h, CHR_e,
    CHR_a, CHR_s, CHR_t, PCT_EXCLAMATION, PCT_SPACE, CHR_M,
    CHR_e, CHR_t, CHR_a, CHR_l, PCT_SPACE, CHR_c,
    CHR_h, CHR_e, CHR_s, CHR_t, PCT_EXCLAMATION, CTR_NEWLINE,
    CTR_ENDLINE};

//   [{em-yellow}Musashi{/em}]'s {em-yellow}Metal chest{/em}!{button}{endline}
static s16 scenario_text_041C[] = {
    PCT_SPACE, PCT_SPACE, PCT_LBRACKET, CTR_EM_YELLOW, CHR_M,
    CHR_u, CHR_s, CHR_a, CHR_s, CHR_h,
    CHR_i, CTR_CLOSE_EM, PCT_RBRACKET, PCT_APOSTROPHE, CHR_s,
    PCT_SPACE, CTR_EM_YELLOW, CHR_M, CHR_e, CHR_t,
    CHR_a, CHR_l, PCT_SPACE, CHR_c, CHR_h,
    CHR_e, CHR_s, CHR_t, CTR_CLOSE_EM, PCT_EXCLAMATION,
    CTR_BUTTON, CTR_ENDLINE};

// {newwindow}{endline}
static s16 scenario_text_046B[] = {CTR_NEWWINDOW, CTR_ENDLINE};

// Wait, maybe{newline}{endline}
static s16 scenario_text_0483[] = {
    CHR_W, CHR_a, CHR_i, CHR_t, PCT_COMMA, PCT_SPACE, CHR_m,
    CHR_a, CHR_y, CHR_b, CHR_e, CTR_NEWLINE, CTR_ENDLINE};

// I am being a bit too obvious.{endline}
static s16 scenario_text_04A4[] = {
    CHR_I, PCT_SPACE, CHR_a, CHR_m, PCT_SPACE, CHR_b,
    CHR_e, CHR_i, CHR_n, CHR_g, PCT_SPACE, CHR_a,
    PCT_SPACE, CHR_b, CHR_i, CHR_t, PCT_SPACE, CHR_t,
    CHR_o, CHR_o, PCT_SPACE, CHR_o, CHR_b, CHR_v,
    CHR_i, CHR_o, CHR_u, CHR_s, PCT_PERIOD, CTR_ENDLINE};

// {waitinput}{end}{endline}
static s16 scenario_text_04CE[] = {CTR_WAITINPUT, CTR_END, CTR_ENDLINE};

extern s32 scenario_code_message_110_8420[];
extern s32 scenario_code_message_110_8470[];
extern s32 scenario_code_message_110_84d0[];
extern s32 scenario_code_message_110_8530[];

s32 scenario_code_message_110_8420[] = {

    // Address: @8420
    // MACHI 0 - Oedo - Bridge to Musashi - Guard (Gatekeeper)

    // 8420: Print Text
    TXT,
    (s32)&scenario_text_0000,

    // 8428: Execute subroutine to check super pass and set flag 0x501
    ESR,
    (s32)check_super_pass_and_set_flag,

    // 8430: If temporary flag 0x501 is set (has super pass), jump to @8470
    JFS,
    0x501,
    (s32)&scenario_code_message_110_8470,

    // 8434: Print Text
    TXT,
    (s32)&scenario_text_0014,

    // 843c: Print Text
    TXT,
    (s32)&scenario_text_003B,

    // 8444: Print Text
    TXT,
    (s32)&scenario_text_0067,

    // 844c: Print Text
    TXT,
    (s32)&scenario_text_0090,

    // 8454: Print Text
    TXT,
    (s32)&scenario_text_00A8,

    // 845c: Print Text
    TXT,
    (s32)&scenario_text_00E9,

    // 8464: Print Text
    TXT,
    (s32)&scenario_text_0114,

    // 846c: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_110_8470[] = {

    // Address: @8470

    // Clear temporary flag 0x80 since we've used it
    CFG,
    0x501,

    // 8470: If Flag 001 (Opened Super Pass Gate), Jump To @84d0
    // Jump if flag 0x01 is SET to @84d0
    JFS,
    0x01,
    (s32)&scenario_code_message_110_84d0,

    // 847c: Write to RAM 801c7770 (Unknown)
    STW,
    (s32)&D_801C7770_1C8370,

    // 8484: Store Value: 1
    WTS,
    0x1,

    // 848c: Print Text
    TXT,
    (s32)&scenario_text_0131,

    // 8494: Print Text
    TXT,
    (s32)&scenario_text_0090,

    // 849c: Print Text
    TXT,
    (s32)&scenario_text_0178,

    // 84a4: Print Text
    TXT,
    (s32)&scenario_text_0090,

    // 84ac: Print Text
    TXT,
    (s32)&scenario_text_01D2,

    // 84b4: Print Text
    TXT,
    (s32)&scenario_text_01FF,

    // 84bc: Set Flag 001 (Opened Super Pass Gate)
    SFG,
    0x01,

    // 84c4: Print Text
    TXT,
    (s32)&scenario_text_0114,

    // 84cc: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_110_84d0[] = {

    // Address: @84d0

    // 84d0: If Flag 017 (Kyushu Disappeared), Jump To @8530
    // Jump if flag 0x17 is SET to @8530
    JFS,
    0x17,
    (s32)&scenario_code_message_110_8530,

    // 84dc: Print Text
    TXT,
    (s32)&scenario_text_023F,

    // 84e4: Print Text
    TXT,
    (s32)&scenario_text_0266,

    // 84ec: Print Text
    TXT,
    (s32)&scenario_text_0298,

    // 84f4: Print Text
    TXT,
    (s32)&scenario_text_0090,

    // 84fc: Print Text
    TXT,
    (s32)&scenario_text_02E3,

    // 8504: Print Text
    TXT,
    (s32)&scenario_text_02FC,

    // 850c: Print Text
    TXT,
    (s32)&scenario_text_0090,

    // 8514: Print Text
    TXT,
    (s32)&scenario_text_02E3,

    // 851c: Print Text
    TXT,
    (s32)&scenario_text_0355,

    // 8524: Print Text
    TXT,
    (s32)&scenario_text_0114,

    // 852c: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_110_8530[] = {

    // Address: @8530

    // 8530: Print Text
    TXT,
    (s32)&scenario_text_0395,

    // 8538: Print Text
    TXT,
    (s32)&scenario_text_03C5,

    // 8540: Print Text
    TXT,
    (s32)&scenario_text_03E9,

    // 8548: Print Text
    TXT,
    (s32)&scenario_text_041C,

    // 8550: Print Text
    TXT,
    (s32)&scenario_text_0090,

    // 8558: Print Text
    TXT,
    (s32)&scenario_text_0483,

    // 8560: Print Text
    TXT,
    (s32)&scenario_text_04A4,

    // 8568: Print Text
    TXT,
    (s32)&scenario_text_0114,

    // 8570: End Event
    END,

    // End scenario script
    END,
};
