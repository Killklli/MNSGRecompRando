
#include "types.h"
#include "scenario.h"
#include "scenario_replacer.h"

// External scenario code declarations
extern s32 scenario_code_message_15e_b798[];
extern s32 scenario_code_message_15e_b7d0[];
extern s32 scenario_code_message_15e_b81c[];
extern s32 scenario_code_message_15e_b858[];
extern s32 scenario_code_message_15e_b874[];
extern s32 scenario_code_message_15e_b8f0[];
extern s32 scenario_code_message_15e_b924[];
extern s32 scenario_code_message_15e_b978[];
extern s32 scenario_code_message_15e_b9b4[];
extern s32 scenario_code_message_15e_bb10[];
extern s32 scenario_code_message_15e_bb5c[];
extern s32 scenario_code_message_15e_bb70[];

void update_quality_cucumber_text(void);

// MACHI 18 - Zazen - Mt. Nyoigatake - Priest
// Address: @b798

// {begin}{endline}
static s16 scenario_text_0000[] = {CTR_BEGIN, CTR_ENDLINE};

// Son:What?{newline}{endline}
static s16 scenario_text_0014[] = {
    CHR_S, CHR_o, CHR_n, PCT_COLON, CHR_W, CHR_h,
    CHR_a, CHR_t, PCT_QUESTION, CTR_NEWLINE, CTR_ENDLINE};

//    You've come all the way here...{button}{endline}
static s16 scenario_text_0033[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_Y, CHR_o,
    CHR_u, PCT_APOSTROPHE, CHR_v, CHR_e, PCT_SPACE,
    CHR_c, CHR_o, CHR_m, CHR_e, PCT_SPACE,
    CHR_a, CHR_l, CHR_l, PCT_SPACE, CHR_t,
    CHR_h, CHR_e, PCT_SPACE, CHR_w, CHR_a,
    CHR_y, PCT_SPACE, CHR_h, CHR_e, CHR_r,
    CHR_e, PCT_PERIOD, PCT_PERIOD, PCT_PERIOD, CTR_BUTTON,
    CTR_ENDLINE};

// Address: @b7d0

// {newwindow}{endline}
static s16 scenario_text_006A[] = {CTR_NEWWINDOW, CTR_ENDLINE};

// Son:So what do you want?{newline}{endline}
static s16 scenario_text_0082[] = {
    CHR_S, CHR_o, CHR_n, PCT_COLON, CHR_S, CHR_o, PCT_SPACE,
    CHR_w, CHR_h, CHR_a, CHR_t, PCT_SPACE, CHR_d, CHR_o,
    PCT_SPACE, CHR_y, CHR_o, CHR_u, PCT_SPACE, CHR_w, CHR_a,
    CHR_n, CHR_t, PCT_QUESTION, CTR_NEWLINE, CTR_ENDLINE};

//  {newline}{endline}
static s16 scenario_text_00B0[] = {PCT_SPACE, CTR_NEWLINE, CTR_ENDLINE};

//   {em-yellow}To see the Big Sacred Fire...{newline}{endline}
static s16 scenario_text_00C7[] = {
    PCT_SPACE, PCT_SPACE, CTR_EM_YELLOW, CHR_T, CHR_o, PCT_SPACE,
    CHR_s, CHR_e, CHR_e, PCT_SPACE, CHR_t, CHR_h,
    CHR_e, PCT_SPACE, CHR_B, CHR_i, CHR_g, PCT_SPACE,
    CHR_S, CHR_a, CHR_c, CHR_r, CHR_e, CHR_d,
    PCT_SPACE, CHR_F, CHR_i, CHR_r, CHR_e, PCT_PERIOD,
    PCT_PERIOD, PCT_PERIOD, CTR_NEWLINE, CTR_ENDLINE};

//   {em-yellow}Do you have Kihachi's favorite?{newline}{endline}
static s16 scenario_text_0107[] = {
    PCT_SPACE, PCT_SPACE, CTR_EM_YELLOW, CHR_D, CHR_o,
    PCT_SPACE, CHR_y, CHR_o, CHR_u, PCT_SPACE,
    CHR_h, CHR_a, CHR_v, CHR_e, PCT_SPACE,
    CHR_K, CHR_i, CHR_h, CHR_a, CHR_c,
    CHR_h, CHR_i, PCT_APOSTROPHE, CHR_s, PCT_SPACE,
    CHR_f, CHR_a, CHR_v, CHR_o, CHR_r,
    CHR_i, CHR_t, CHR_e, PCT_QUESTION, CTR_NEWLINE,
    CTR_ENDLINE};

// {end}{endline}
static s16 scenario_text_0149[] = {CTR_END, CTR_ENDLINE};

// Address: @b81c

// {newwindow}{endline}
static s16 scenario_text_015B[] = {CTR_NEWWINDOW, CTR_ENDLINE};

// {/em}Son:Well, beautiful isn't it!{endline}
static s16 scenario_text_0173[] = {
    CTR_CLOSE_EM, CHR_S, CHR_o, CHR_n, PCT_COLON, CHR_W,
    CHR_e, CHR_l, CHR_l, PCT_COMMA, PCT_SPACE, CHR_b,
    CHR_e, CHR_a, CHR_u, CHR_t, CHR_i, CHR_f,
    CHR_u, CHR_l, PCT_SPACE, CHR_i, CHR_s, CHR_n,
    PCT_APOSTROPHE, CHR_t, PCT_SPACE, CHR_i, CHR_t, PCT_EXCLAMATION,
    CTR_ENDLINE};

// {waitinput}{end}{endline}
static s16 scenario_text_01A2[] = {CTR_WAITINPUT, CTR_END, CTR_ENDLINE};

// Address: @b858

// {/em}Son:To be able to watch with{newline}{endline}
static s16 scenario_text_01BF[] = {
    CTR_CLOSE_EM, CHR_S, CHR_o, CHR_n, PCT_COLON, CHR_T, CHR_o,
    PCT_SPACE, CHR_b, CHR_e, PCT_SPACE, CHR_a, CHR_b, CHR_l,
    CHR_e, PCT_SPACE, CHR_t, CHR_o, PCT_SPACE, CHR_w, CHR_a,
    CHR_t, CHR_c, CHR_h, PCT_SPACE, CHR_w, CHR_i, CHR_t,
    CHR_h, CTR_NEWLINE, CTR_ENDLINE};

//    such a {em-yellow}cute girl{/em}!{endline}
static s16 scenario_text_01F6[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_s, CHR_u, CHR_c,
    CHR_h, PCT_SPACE, CHR_a, PCT_SPACE, CTR_EM_YELLOW, CHR_c,
    CHR_u, CHR_t, CHR_e, PCT_SPACE, CHR_g, CHR_i,
    CHR_r, CHR_l, CTR_CLOSE_EM, PCT_EXCLAMATION, CTR_ENDLINE};

// {waitinput}{end}{endline}
static s16 scenario_text_0227[] = {CTR_WAITINPUT, CTR_END, CTR_ENDLINE};

// Address: @b874

// {newwindow}{endline}
static s16 scenario_text_0244[] = {CTR_NEWWINDOW, CTR_ENDLINE};

// {/em}Son:Ah?{newline}{endline}
static s16 scenario_text_025C[] = {
    CTR_CLOSE_EM, CHR_S, CHR_o, CHR_n, PCT_COLON,
    CHR_A, CHR_h, PCT_QUESTION, CTR_NEWLINE, CTR_ENDLINE};

//    About the {em-yellow}cucumber{/em}?{button}{endline}
static s16 scenario_text_027E[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_A, CHR_b, CHR_o,
    CHR_u, CHR_t, PCT_SPACE, CHR_t, CHR_h, CHR_e,
    PCT_SPACE, CTR_EM_YELLOW, CHR_c, CHR_u, CHR_c, CHR_u,
    CHR_m, CHR_b, CHR_e, CHR_r, CTR_CLOSE_EM, PCT_QUESTION,
    CTR_BUTTON, CTR_ENDLINE};

// {newwindow}{endline}
static s16 scenario_text_02B9[] = {CTR_NEWWINDOW, CTR_ENDLINE};

// Oh, did you want some of{newline}{endline}
static s16 scenario_text_02D1[] = {
    CHR_O, CHR_h, PCT_COMMA, PCT_SPACE, CHR_d, CHR_i, CHR_d,
    PCT_SPACE, CHR_y, CHR_o, CHR_u, PCT_SPACE, CHR_w, CHR_a,
    CHR_n, CHR_t, PCT_SPACE, CHR_s, CHR_o, CHR_m, CHR_e,
    PCT_SPACE, CHR_o, CHR_f, CTR_NEWLINE, CTR_ENDLINE};

// the {em-yellow}cucumber{/em} I grew?{newline}{endline}
static s16 scenario_text_02FF[] = {
    CHR_t, CHR_h, CHR_e, PCT_SPACE, CTR_EM_YELLOW, CHR_c,
    CHR_u, CHR_c, CHR_u, CHR_m, CHR_b, CHR_e,
    CHR_r, CTR_CLOSE_EM, PCT_SPACE, CHR_I, PCT_SPACE, CHR_g,
    CHR_r, CHR_e, CHR_w, PCT_QUESTION, CTR_NEWLINE, CTR_ENDLINE};

//   {em-yellow}Yes!{newline}{endline}
static s16 scenario_text_0339[] = {PCT_SPACE, PCT_SPACE, CTR_EM_YELLOW,
                                   CHR_Y, CHR_e, CHR_s,
                                   PCT_EXCLAMATION, CTR_NEWLINE, CTR_ENDLINE};

//   {em-yellow}No, I won't bother.{newline}{endline}
static s16 scenario_text_0360[] = {
    PCT_SPACE, PCT_SPACE, CTR_EM_YELLOW, CHR_N, CHR_o,
    PCT_COMMA, PCT_SPACE, CHR_I, PCT_SPACE, CHR_w,
    CHR_o, CHR_n, PCT_APOSTROPHE, CHR_t, PCT_SPACE,
    CHR_b, CHR_o, CHR_t, CHR_h, CHR_e,
    CHR_r, PCT_PERIOD, CTR_NEWLINE, CTR_ENDLINE};

// {end}{endline}
static s16 scenario_text_0396[] = {CTR_END, CTR_ENDLINE};

// Address: @b8f0

// {newwindow}{endline}
static s16 scenario_text_03A8[] = {CTR_NEWWINDOW, CTR_ENDLINE};

// {/em}Son:I didn't think so.{newline}{endline}
static s16 scenario_text_03C0[] = {
    CTR_CLOSE_EM, CHR_S, CHR_o, CHR_n, PCT_COLON,
    CHR_I, PCT_SPACE, CHR_d, CHR_i, CHR_d,
    CHR_n, PCT_APOSTROPHE, CHR_t, PCT_SPACE, CHR_t,
    CHR_h, CHR_i, CHR_n, CHR_k, PCT_SPACE,
    CHR_s, CHR_o, PCT_PERIOD, CTR_NEWLINE, CTR_ENDLINE};

//    You don't look like {newline}{endline}
static s16 scenario_text_03F1[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_Y, CHR_o,
    CHR_u, PCT_SPACE, CHR_d, CHR_o, CHR_n,
    PCT_APOSTROPHE, CHR_t, PCT_SPACE, CHR_l, CHR_o,
    CHR_o, CHR_k, PCT_SPACE, CHR_l, CHR_i,
    CHR_k, CHR_e, PCT_SPACE, CTR_NEWLINE, CTR_ENDLINE};

//    a {em-yellow}water imp{/em} to me.{endline}
static s16 scenario_text_041E[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_a, PCT_SPACE, CTR_EM_YELLOW,
    CHR_w, CHR_a, CHR_t, CHR_e, CHR_r, PCT_SPACE,
    CHR_i, CHR_m, CHR_p, CTR_CLOSE_EM, PCT_SPACE, CHR_t,
    CHR_o, PCT_SPACE, CHR_m, CHR_e, PCT_PERIOD, CTR_ENDLINE};

// {waitinput}{end}{endline}
static s16 scenario_text_0450[] = {CTR_WAITINPUT, CTR_END, CTR_ENDLINE};

// Address: @b924

// {newwindow}{endline}
static s16 scenario_text_046D[] = {CTR_NEWWINDOW, CTR_ENDLINE};

// {/em}Ok, I'll sell it to you for {em-yellow}400{/em}ryo!{newline}{endline}
static s16 scenario_text_0485[] = {
    CTR_CLOSE_EM, CHR_O, CHR_k, PCT_COMMA, PCT_SPACE,
    CHR_I, PCT_APOSTROPHE, CHR_l, CHR_l, PCT_SPACE,
    CHR_s, CHR_e, CHR_l, CHR_l, PCT_SPACE,
    CHR_i, CHR_t, PCT_SPACE, CHR_t, CHR_o,
    PCT_SPACE, CHR_y, CHR_o, CHR_u, PCT_SPACE,
    CHR_f, CHR_o, CHR_r, PCT_SPACE, CTR_EM_YELLOW,
    NUM_4, NUM_0, NUM_0, CTR_CLOSE_EM, CHR_r,
    CHR_y, CHR_o, PCT_EXCLAMATION, CTR_NEWLINE, CTR_ENDLINE};

// Do you want it even at that price?{newline}{endline}
static s16 scenario_text_04D3[] = {
    CHR_D, CHR_o, PCT_SPACE, CHR_y, CHR_o, CHR_u,
    PCT_SPACE, CHR_w, CHR_a, CHR_n, CHR_t, PCT_SPACE,
    CHR_i, CHR_t, PCT_SPACE, CHR_e, CHR_v, CHR_e,
    CHR_n, PCT_SPACE, CHR_a, CHR_t, PCT_SPACE, CHR_t,
    CHR_h, CHR_a, CHR_t, PCT_SPACE, CHR_p, CHR_r,
    CHR_i, CHR_c, CHR_e, PCT_QUESTION, CTR_NEWLINE, CTR_ENDLINE};

//   {em-yellow}Yeah!{newline}{endline}
static s16 scenario_text_050B[] = {
    PCT_SPACE, PCT_SPACE, CTR_EM_YELLOW, CHR_Y, CHR_e,
    CHR_a, CHR_h, PCT_EXCLAMATION, CTR_NEWLINE, CTR_ENDLINE};

//   {em-yellow}What?! That's too much!!{newline}{endline}
static s16 scenario_text_0533[] = {
    PCT_SPACE, PCT_SPACE, CTR_EM_YELLOW, CHR_W, CHR_h, CHR_a,
    CHR_t, PCT_QUESTION, PCT_EXCLAMATION, PCT_SPACE, CHR_T, CHR_h,
    CHR_a, CHR_t, PCT_APOSTROPHE, CHR_s, PCT_SPACE, CHR_t,
    CHR_o, CHR_o, PCT_SPACE, CHR_m, CHR_u, CHR_c,
    CHR_h, PCT_EXCLAMATION, PCT_EXCLAMATION, CTR_NEWLINE, CTR_ENDLINE};

// {end}{endline}
static s16 scenario_text_056E[] = {CTR_END, CTR_ENDLINE};

// Address: @b978

// {newwindow}{endline}
static s16 scenario_text_0580[] = {CTR_NEWWINDOW, CTR_ENDLINE};

// {/em}Son:If you can't appreciate{newline}{endline}
static s16 scenario_text_0598[] = {
    CTR_CLOSE_EM, CHR_S, CHR_o, CHR_n, PCT_COLON, CHR_I,
    CHR_f, PCT_SPACE, CHR_y, CHR_o, CHR_u, PCT_SPACE,
    CHR_c, CHR_a, CHR_n, PCT_APOSTROPHE, CHR_t, PCT_SPACE,
    CHR_a, CHR_p, CHR_p, CHR_r, CHR_e, CHR_c,
    CHR_i, CHR_a, CHR_t, CHR_e, CTR_NEWLINE, CTR_ENDLINE};

//    the value of my cucumbers,{newline}{endline}
static s16 scenario_text_05CE[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE,
    CHR_v, CHR_a, CHR_l, CHR_u, CHR_e, PCT_SPACE, CHR_o,
    CHR_f, PCT_SPACE, CHR_m, CHR_y, PCT_SPACE, CHR_c, CHR_u,
    CHR_c, CHR_u, CHR_m, CHR_b, CHR_e, CHR_r, CHR_s,
    PCT_COMMA, CTR_NEWLINE, CTR_ENDLINE};

//    you can leave right now!{endline}
static s16 scenario_text_0601[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_y, CHR_o, CHR_u,
    PCT_SPACE, CHR_c, CHR_a, CHR_n, PCT_SPACE, CHR_l,
    CHR_e, CHR_a, CHR_v, CHR_e, PCT_SPACE, CHR_r,
    CHR_i, CHR_g, CHR_h, CHR_t, PCT_SPACE, CHR_n,
    CHR_o, CHR_w, PCT_EXCLAMATION, CTR_ENDLINE};

// {waitinput}{end}{endline}
static s16 scenario_text_0629[] = {CTR_WAITINPUT, CTR_END, CTR_ENDLINE};

// Address: @b9b4

// {newwindow}{endline}
static s16 scenario_text_0646[] = {CTR_NEWWINDOW, CTR_ENDLINE};

// {/em}Son:You've made a wise purchase!{button}{endline}
static s16 scenario_text_065E[] = {
    CTR_CLOSE_EM, CHR_S, CHR_o, CHR_n, PCT_COLON, CHR_Y,
    CHR_o, CHR_u, PCT_APOSTROPHE, CHR_v, CHR_e, PCT_SPACE,
    CHR_m, CHR_a, CHR_d, CHR_e, PCT_SPACE, CHR_a,
    PCT_SPACE, CHR_w, CHR_i, CHR_s, CHR_e, PCT_SPACE,
    CHR_p, CHR_u, CHR_r, CHR_c, CHR_h, CHR_a,
    CHR_s, CHR_e, PCT_EXCLAMATION, CTR_BUTTON, CTR_ENDLINE};

// {newwindow}{endline}
static s16 scenario_text_0698[] = {CTR_NEWWINDOW, CTR_ENDLINE};

// Son:Here you go.{button}{end}{endline}
static s16 scenario_text_06B0[] = {
    CHR_S, CHR_o, CHR_n, PCT_COLON, CHR_H, CHR_e, CHR_r,
    CHR_e, PCT_SPACE, CHR_y, CHR_o, CHR_u, PCT_SPACE, CHR_g,
    CHR_o, PCT_PERIOD, CTR_BUTTON, CTR_END, CTR_ENDLINE};

// {begin}{endline}
static s16 scenario_text_06DA[] = {CTR_BEGIN, CTR_ENDLINE};

//   {newline}{endline}
static s16 scenario_text_06EE[] = {PCT_SPACE, PCT_SPACE, CTR_NEWLINE,
                                   CTR_ENDLINE};

//  Goemon and allies{newline}{endline}
static s16 scenario_text_0706[] = {
    PCT_SPACE, CHR_G, CHR_o, CHR_e, CHR_m, CHR_o, CHR_n,
    PCT_SPACE, CHR_a, CHR_n, CHR_d, PCT_SPACE, CHR_a, CHR_l,
    CHR_l, CHR_i, CHR_e, CHR_s, CTR_NEWLINE, CTR_ENDLINE};

//    receive [{em-yellow}Quality Cucumber{/em}]!{endline}
static s16 scenario_text_072E[256] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_r, CHR_e, CHR_c,
    CHR_e, CHR_i, CHR_v, CHR_e, PCT_SPACE, PCT_LBRACKET,
    CTR_EM_YELLOW, CHR_Q, CHR_u, CHR_a, CHR_l, CHR_i,
    CHR_t, CHR_y, PCT_SPACE, CHR_C, CHR_u, CHR_c,
    CHR_u, CHR_m, CHR_b, CHR_e, CHR_r, CTR_CLOSE_EM,
    PCT_RBRACKET, PCT_EXCLAMATION, CTR_ENDLINE};

// {end}{endline}
static s16 scenario_text_0769[] = {CTR_END, CTR_ENDLINE};

// Address: @bb10

// {newwindow}{endline}
static s16 scenario_text_077B[] = {CTR_NEWWINDOW, CTR_ENDLINE};

// {/em}Son:Sorry but{newline}{endline}
static s16 scenario_text_0793[] = {
    CTR_CLOSE_EM, CHR_S, CHR_o, CHR_n, PCT_COLON, CHR_S,
    CHR_o, CHR_r, CHR_r, CHR_y, PCT_SPACE, CHR_b,
    CHR_u, CHR_t, CTR_NEWLINE, CTR_ENDLINE};

//    that's not enough money!{endline}
static s16 scenario_text_07BB[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_t, CHR_h, CHR_a,
    CHR_t, PCT_APOSTROPHE, CHR_s, PCT_SPACE, CHR_n, CHR_o,
    CHR_t, PCT_SPACE, CHR_e, CHR_n, CHR_o, CHR_u,
    CHR_g, CHR_h, PCT_SPACE, CHR_m, CHR_o, CHR_n,
    CHR_e, CHR_y, PCT_EXCLAMATION, CTR_ENDLINE};

// {waitinput}{end}{endline}
static s16 scenario_text_07E3[] = {CTR_WAITINPUT, CTR_END, CTR_ENDLINE};

// Address: @bb5c

// {/em}Son:I already sold {em-yellow}you{/em} cucumbers!{endline}
static s16 scenario_text_0800[] = {
    CTR_CLOSE_EM, CHR_S, CHR_o, CHR_n, PCT_COLON, CHR_I,
    PCT_SPACE, CHR_a, CHR_l, CHR_r, CHR_e, CHR_a,
    CHR_d, CHR_y, PCT_SPACE, CHR_s, CHR_o, CHR_l,
    CHR_d, PCT_SPACE, CTR_EM_YELLOW, CHR_y, CHR_o, CHR_u,
    CTR_CLOSE_EM, PCT_SPACE, CHR_c, CHR_u, CHR_c, CHR_u,
    CHR_m, CHR_b, CHR_e, CHR_r, CHR_s, PCT_EXCLAMATION,
    CTR_ENDLINE};

// {waitinput}{end}{endline}
static s16 scenario_text_0843[] = {CTR_WAITINPUT, CTR_END, CTR_ENDLINE};

// Address: @bb70

// {/em}Son:So you want my {em-yellow}cucumbers{/em}{newline}{endline}
static s16 scenario_text_0860[] = {
    CTR_CLOSE_EM, CHR_S, CHR_o, CHR_n, PCT_COLON, CHR_S,
    CHR_o, PCT_SPACE, CHR_y, CHR_o, CHR_u, PCT_SPACE,
    CHR_w, CHR_a, CHR_n, CHR_t, PCT_SPACE, CHR_m,
    CHR_y, PCT_SPACE, CTR_EM_YELLOW, CHR_c, CHR_u, CHR_c,
    CHR_u, CHR_m, CHR_b, CHR_e, CHR_r, CHR_s,
    CTR_CLOSE_EM, CTR_NEWLINE, CTR_ENDLINE};

//    after all?{newline}{endline}
static s16 scenario_text_08A7[] = {PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_a,
                                   CHR_f, CHR_t, CHR_e, CHR_r,
                                   PCT_SPACE, CHR_a, CHR_l, CHR_l,
                                   PCT_QUESTION, CTR_NEWLINE, CTR_ENDLINE};

//   {em-yellow}Yes! {newline}{endline}
static s16 scenario_text_08CA[] = {
    PCT_SPACE, PCT_SPACE, CTR_EM_YELLOW, CHR_Y, CHR_e,
    CHR_s, PCT_EXCLAMATION, PCT_SPACE, CTR_NEWLINE, CTR_ENDLINE};

//   {em-yellow}No thanks.{newline}{endline}
static s16 scenario_text_08F2[] = {
    PCT_SPACE, PCT_SPACE, CTR_EM_YELLOW, CHR_N, CHR_o,
    PCT_SPACE, CHR_t, CHR_h, CHR_a, CHR_n,
    CHR_k, CHR_s, PCT_PERIOD, CTR_NEWLINE, CTR_ENDLINE};

// {end}{endline}
static s16 scenario_text_091F[] = {CTR_END, CTR_ENDLINE};

s32 scenario_code_message_15e_b798[] = {

    // Address: @b798
    // MACHI 18 - Zazen - Mt. Nyoigatake - Priest

    // b798: Print Text
    TXT,
    (s32)&scenario_text_0000,

    // b7a0: If Flag 03b (Spoke to Priest's Son), Jump To @b7d0
    // Jump if flag 0x3B is SET to @b7d0
    JFS,
    0x3B,
    (s32)&scenario_code_message_15e_b7d0,

    // b7ac: Print Text
    TXT,
    (s32)&scenario_text_0014,

    // b7b4: Print Text
    TXT,
    (s32)&scenario_text_0033,

    // b7bc: Set Flag 03b (Spoke to Priest's Son)
    SFG,
    0x3B,

    // b7c4: Jump To @b7d0
    JMP,
    (s32)&scenario_code_message_15e_b7d0,

    // b7cc: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_15e_b7d0[] = {

    // Address: @b7d0

    // b7d0: Print Text
    TXT,
    (s32)&scenario_text_006A,

    // b7d8: Print Text
    TXT,
    (s32)&scenario_text_0082,

    // b7e0: Print Text
    TXT,
    (s32)&scenario_text_00B0,

    // b7e8: Begin Option Selection
    BOS,

    // b7ec: Print Text
    TXT,
    (s32)&scenario_text_00C7,

    // b7f4: Jump To @b81c
    JMP,
    (s32)&scenario_code_message_15e_b81c,

    // b7fc: Print Text
    TXT,
    (s32)&scenario_text_0107,

    // b804: Jump To @b874
    JMP,
    (s32)&scenario_code_message_15e_b874,

    // b80c: End Option Selection
    EOS,

    // b810: Print Text
    TXT,
    (s32)&scenario_text_0149,

    // b818: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_15e_b81c[] = {

    // Address: @b81c

    // b81c: Print Text
    TXT,
    (s32)&scenario_text_006A,

    // b824: Execute Code: 8003f594 (Load Current Character)
    ESR,
    (s32)&func_8003F594_40194,

    // b82c: Read from RAM 801c7750 (Scratch)
    LDW,
    0x801c7750,

    // b834: Skip Next If Not Equal: 3
    SNE,
    0x3,

    // b83c: Jump To @b858
    JMP,
    (s32)&scenario_code_message_15e_b858,

    // b844: Print Text
    TXT,
    (s32)&scenario_text_0173,

    // b84c: Print Text
    TXT,
    (s32)&scenario_text_01A2,

    // b854: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_15e_b858[] = {

    // Address: @b858

    // b858: Print Text
    TXT,
    (s32)&scenario_text_01BF,

    // b860: Print Text
    TXT,
    (s32)&scenario_text_01F6,

    // b868: Print Text
    TXT,
    (s32)&scenario_text_01A2,

    // b870: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_15e_b874[] = {

    // Address: @b874

    // b874: Print Text
    TXT,
    (s32)&scenario_text_006A,

    // b87c: If Flag 00f (Received Cucumber), Jump To @bb5c
    // Jump if flag 0x0F is SET to @bb5c
    JFS,
    0x0F,
    (s32)&scenario_code_message_15e_bb5c,

    // b888: If Flag 065 (Talked to Son but Did Not Buy Cucumber), Jump To @bb70
    // Jump if flag 0x65 is SET to @bb70
    JFS,
    0x65,
    (s32)&scenario_code_message_15e_bb70,

    // b894: Print Text
    TXT,
    (s32)&scenario_text_025C,

    // b89c: Print Text
    TXT,
    (s32)&scenario_text_027E,

    // b8a4: Print Text
    TXT,
    (s32)&scenario_text_006A,

    // b8ac: Print Text
    TXT,
    (s32)&scenario_text_02D1,

    // b8b4: Print Text
    TXT,
    (s32)&scenario_text_02FF,

    // b8bc: Begin Option Selection
    BOS,

    // b8c0: Print Text
    TXT,
    (s32)&scenario_text_0339,

    // b8c8: Jump To @b924
    JMP,
    (s32)&scenario_code_message_15e_b924,

    // b8d0: Print Text
    TXT,
    (s32)&scenario_text_0360,

    // b8d8: Jump To @b8f0
    JMP,
    (s32)&scenario_code_message_15e_b8f0,

    // b8e0: End Option Selection
    EOS,

    // b8e4: Print Text
    TXT,
    (s32)&scenario_text_0149,

    // b8ec: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_15e_b8f0[] = {

    // Address: @b8f0

    // b8f0: Print Text
    TXT,
    (s32)&scenario_text_006A,

    // b8f8: Print Text
    TXT,
    (s32)&scenario_text_03C0,

    // b900: Print Text
    TXT,
    (s32)&scenario_text_03F1,

    // b908: Print Text
    TXT,
    (s32)&scenario_text_041E,

    // b910: Set Flag 065 (Talked to Son but Did Not Buy Cucumber)
    SFG,
    0x65,

    // b918: Print Text
    TXT,
    (s32)&scenario_text_01A2,

    // b920: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_15e_b924[] = {

    // Address: @b924

    // b924: Set Flag 082 (Money Handling Flag)
    SFG,
    0x82,

    // b92c: Print Text
    TXT,
    (s32)&scenario_text_006A,

    // b934: Print Text
    TXT,
    (s32)&scenario_text_0485,

    // b93c: Print Text
    TXT,
    (s32)&scenario_text_04D3,

    // b944: Begin Option Selection
    BOS,

    // b948: Print Text
    TXT,
    (s32)&scenario_text_050B,

    // b950: Jump To @b9b4
    JMP,
    (s32)&scenario_code_message_15e_b9b4,

    // b958: Print Text
    TXT,
    (s32)&scenario_text_0533,

    // b960: Jump To @b978
    JMP,
    (s32)&scenario_code_message_15e_b978,

    // b968: End Option Selection
    EOS,

    // b96c: Print Text
    TXT,
    (s32)&scenario_text_0149,

    // b974: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_15e_b978[] = {

    // Address: @b978

    // b978: Print Text
    TXT,
    (s32)&scenario_text_006A,

    // b980: Print Text
    TXT,
    (s32)&scenario_text_0598,

    // b988: Print Text
    TXT,
    (s32)&scenario_text_05CE,

    // b990: Print Text
    TXT,
    (s32)&scenario_text_0601,

    // b998: Unset Flag 082 (Money Handling Flag)
    CFG,
    0x82,

    // b9a0: Set Flag 065 (Talked to Son but Did Not Buy Cucumber)
    SFG,
    0x65,

    // b9a8: Print Text
    TXT,
    (s32)&scenario_text_01A2,

    // b9b0: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_15e_b9b4[] = {

    // Address: @b9b4

    // b9b4: Print Text
    TXT,
    (s32)&scenario_text_006A,

    // b9bc: Write to RAM 801c7770 (Unknown)
    STW,
    (s32)&D_801C7770_1C8370,

    // b9c4: Store Value: 1
    WTS,
    0x1,

    // b9cc: Write to RAM 801c7740 (Scratch)
    STW,
    (s32)&D_801C7740_1C8340,

    // b9d4: Store Value: fffffce0
    WTS,
    0xFFFFFE70,

    // b9dc: Execute Code: 80221fd4 (Give/Take Ryo)
    ESR,
    0x80221fd4,

    // b9e4: Read from RAM 801c7750 (Scratch)
    LDW,
    0x801c7750,

    // b9ec: Skip Next If Not Equal: 1
    SNE,
    0x1,

    // b9f4: Jump To @bb10
    JMP,
    (s32)&scenario_code_message_15e_bb10,

    // b9fc: Write to RAM 801c7770 (Unknown)
    STW,
    (s32)&D_801C7770_1C8370,

    // ba04: Store Value: 1
    WTS,
    0x1,

    // ba0c: Write to RAM 801c7740 (Scratch)
    STW,
    (s32)&D_801C7740_1C8340,

    // ba14: Store Value: 23c
    WTS,
    0x23C,

    // ba1c: Execute Code: 8003f608 (Play Sound)
    ESR,
    (s32)&func_8003F608_40208,

    // ba24: Unset Flag 082 (Money Handling Flag)
    CFG,
    0x82,

    // ba2c: Print Text
    TXT,
    (s32)&scenario_text_065E,

    // ba34: Print Text
    TXT,
    (s32)&scenario_text_006A,

    // ba3c: Print Text
    TXT,
    (s32)&scenario_text_06B0,

    // ba44: Write to RAM 801c7758 (Unknown)
    STW,
    (s32)&D_801C7758_1C8358,

    // ba4c: Store Value: 20
    WTS,
    0x20,

    // ba54: Write to RAM 801c775c (Dialogue Window Y Pos)
    STW,
    (s32)&D_801C775C_1C835C,

    // ba5c: Store Value: 48
    WTS,
    0x48,

    // ba64: Write to RAM 801c7768 (Dialogue Window Style)
    STW,
    (s32)&D_801C7768_1C8368,

    // ba6c: Store Value: 7
    WTS,
    0x7,

    // ba74: Print Text
    TXT,
    (s32)&scenario_text_0000,

    // ba7c: Write to RAM 801c7770 (Unknown)
    STW,
    (s32)&D_801C7770_1C8370,

    // ba84: Store Value: 1
    WTS,
    0x1,

    // ba8c: Write to RAM 801c7740 (Scratch)
    STW,
    (s32)&D_801C7740_1C8340,

    // ba94: Store Value: 14
    WTS,
    0x14,

    // ba9c: Execute Code: 8003f608 (Play Sound)
    ESR,
    (s32)&func_8003F608_40208,

    // // baa4: Print Text
    // TXT,
    // (s32)&scenario_text_06EE,

    // // baac: Print Text
    // TXT,
    // (s32)&scenario_text_0706,

    // bab4: Execute Subroutine (Update Quality Cucumber Text)
    ESR,
    (s32)&update_quality_cucumber_text,

    // bab4: Print Text
    TXT,
    (s32)&scenario_text_072E,

    // DISABLED ITEM
    // // babc: Write to RAM 8015c714 (Obtained Quality Cucumber)
    // STW, 0x8015c714,

    // // bac4: Store Value: 1
    // WTS, 0x1,

    // bacc: Set Flag 00f (Received Cucumber)
    SFG,
    0x0F,

    // bad4: Write to RAM 801c7740 (Scratch)
    STW,
    (s32)&D_801C7740_1C8340,

    // badc: Store Value: 96
    WTS,
    0x96,

    // bae4: Execute Code: 8003f460 (Wait For Timer)
    ESR,
    (s32)&func_8003F460_40060,

    // baec: Print Text
    TXT,
    (s32)&scenario_text_0149,

    // baf4: Write to RAM 801c7740 (Scratch)
    STW,
    (s32)&D_801C7740_1C8340,

    // bafc: Store Value: 6b
    WTS,
    0x6B,

    // bb04: Execute Code: 8003f608 (Play Sound)
    ESR,
    (s32)&func_8003F608_40208,

    // bb0c: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_15e_bb10[] = {

    // Address: @bb10

    // bb10: Print Text
    TXT,
    (s32)&scenario_text_006A,

    // bb18: Write to RAM 801c7740 (Scratch)
    STW,
    (s32)&D_801C7740_1C8340,

    // bb20: Store Value: 2b2
    WTS,
    0x2B2,

    // bb28: Execute Code: 8003f608 (Play Sound)
    ESR,
    (s32)&func_8003F608_40208,

    // bb30: Unset Flag 082 (Money Handling Flag)
    CFG,
    0x82,

    // bb38: Print Text
    TXT,
    (s32)&scenario_text_0793,

    // bb40: Print Text
    TXT,
    (s32)&scenario_text_07BB,

    // bb48: Set Flag 065 (Talked to Son but Did Not Buy Cucumber)
    SFG,
    0x65,

    // bb50: Print Text
    TXT,
    (s32)&scenario_text_01A2,

    // bb58: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_15e_bb5c[] = {

    // Address: @bb5c

    // bb5c: Print Text
    TXT,
    (s32)&scenario_text_0800,

    // bb64: Print Text
    TXT,
    (s32)&scenario_text_01A2,

    // bb6c: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_15e_bb70[] = {

    // Address: @bb70

    // bb70: Print Text
    TXT,
    (s32)&scenario_text_0860,

    // bb78: Print Text
    TXT,
    (s32)&scenario_text_08A7,

    // bb80: Begin Option Selection
    BOS,

    // bb84: Print Text
    TXT,
    (s32)&scenario_text_08CA,

    // bb8c: Jump To @b924
    JMP,
    (s32)&scenario_code_message_15e_b924,

    // bb94: Print Text
    TXT,
    (s32)&scenario_text_08F2,

    // bb9c: Jump To @b8f0
    JMP,
    (s32)&scenario_code_message_15e_b8f0,

    // bba4: End Option Selection
    EOS,

    // bba8: Print Text
    TXT,
    (s32)&scenario_text_0149,

    // bbb0: End Event
    END,

    // End scenario script
    END,
};

void update_quality_cucumber_text(void) {
    update_text_buffer_with_ap_location(scenario_text_072E, 0x00F, NULL, NULL);
}
