// Benkei will introduce himself and fight you even after thaisamba
#include "scenario.h"

#include "common.h"

// Address: @1cd8

// {begin}{endline}
static s16 scenario_text_0000[] = {
    CTR_BEGIN, CTR_ENDLINE
};

// Benkei:Hey! {newline}{endline}
static s16 scenario_text_0014[] = {
    CHR_B, CHR_e, CHR_n, CHR_k, CHR_e, CHR_i, PCT_COLON, CHR_H, CHR_e, CHR_y,
    PCT_EXCLAMATION, PCT_SPACE, CTR_NEWLINE, CTR_ENDLINE
};

//       Stop, stop right there!{button}{endline}
static s16 scenario_text_0036[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_S, CHR_t, CHR_o, CHR_p,
    PCT_COMMA, PCT_SPACE, CHR_s, CHR_t, CHR_o, CHR_p, PCT_SPACE, CHR_r, CHR_i, CHR_g,
    CHR_h, CHR_t, PCT_SPACE, CHR_t, CHR_h, CHR_e, CHR_r, CHR_e, PCT_EXCLAMATION, CTR_BUTTON,
    CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_0068[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// If you want to get by here,{newline}{endline}
static s16 scenario_text_0080[] = {
    CHR_I, CHR_f, PCT_SPACE, CHR_y, CHR_o, CHR_u, PCT_SPACE, CHR_w, CHR_a, CHR_n,
    CHR_t, PCT_SPACE, CHR_t, CHR_o, PCT_SPACE, CHR_g, CHR_e, CHR_t, PCT_SPACE, CHR_b,
    CHR_y, PCT_SPACE, CHR_h, CHR_e, CHR_r, CHR_e, PCT_COMMA, CTR_NEWLINE, CTR_ENDLINE
};

// hand over the {em-yellow}treasure{/em} you have!{button}{endline}
static s16 scenario_text_00B1[] = {
    CHR_h, CHR_a, CHR_n, CHR_d, PCT_SPACE, CHR_o, CHR_v, CHR_e, CHR_r, PCT_SPACE,
    CHR_t, CHR_h, CHR_e, PCT_SPACE, CTR_EM_YELLOW, CHR_t, CHR_r, CHR_e, CHR_a, CHR_s,
    CHR_u, CHR_r, CHR_e, CTR_CLOSE_EM, PCT_SPACE, CHR_y, CHR_o, CHR_u, PCT_SPACE, CHR_h,
    CHR_a, CHR_v, CHR_e, PCT_EXCLAMATION, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_00F6[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Well come on, {newline}{endline}
static s16 scenario_text_010E[] = {
    CHR_W, CHR_e, CHR_l, CHR_l, PCT_SPACE, CHR_c, CHR_o, CHR_m, CHR_e, PCT_SPACE,
    CHR_o, CHR_n, PCT_COMMA, PCT_SPACE, CTR_NEWLINE, CTR_ENDLINE
};

//    what is it going to be?{newline}{endline}
static s16 scenario_text_0132[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_w, CHR_h, CHR_a, CHR_t, PCT_SPACE, CHR_i, CHR_s,
    PCT_SPACE, CHR_i, CHR_t, PCT_SPACE, CHR_g, CHR_o, CHR_i, CHR_n, CHR_g, PCT_SPACE,
    CHR_t, CHR_o, PCT_SPACE, CHR_b, CHR_e, PCT_QUESTION, CTR_NEWLINE, CTR_ENDLINE
};

//   {em-yellow}I'll take a different route...{newline}{endline}
static s16 scenario_text_0162[] = {
    PCT_SPACE, PCT_SPACE, CTR_EM_YELLOW, CHR_I, PCT_APOSTROPHE, CHR_l, CHR_l, PCT_SPACE, CHR_t, CHR_a,
    CHR_k, CHR_e, PCT_SPACE, CHR_a, PCT_SPACE, CHR_d, CHR_i, CHR_f, CHR_f, CHR_e,
    CHR_r, CHR_e, CHR_n, CHR_t, PCT_SPACE, CHR_r, CHR_o, CHR_u, CHR_t, CHR_e,
    PCT_PERIOD, PCT_PERIOD, PCT_PERIOD, CTR_NEWLINE, CTR_ENDLINE
};

//   {em-yellow}I have no treasure with me...{newline}{endline}
static s16 scenario_text_01A3[] = {
    PCT_SPACE, PCT_SPACE, CTR_EM_YELLOW, CHR_I, PCT_SPACE, CHR_h, CHR_a, CHR_v, CHR_e, PCT_SPACE,
    CHR_n, CHR_o, PCT_SPACE, CHR_t, CHR_r, CHR_e, CHR_a, CHR_s, CHR_u, CHR_r,
    CHR_e, PCT_SPACE, CHR_w, CHR_i, CHR_t, CHR_h, PCT_SPACE, CHR_m, CHR_e, PCT_PERIOD,
    PCT_PERIOD, PCT_PERIOD, CTR_NEWLINE, CTR_ENDLINE
};

// {end}{endline}
static s16 scenario_text_01E3[] = {
    CTR_END, CTR_ENDLINE
};

// Address: @1e00

// {newwindow}{endline}
static s16 scenario_text_01F5[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// {/em}Haw, haw, haw!{newline}{endline}
static s16 scenario_text_020D[] = {
    CTR_CLOSE_EM, CHR_H, CHR_a, CHR_w, PCT_COMMA, PCT_SPACE, CHR_h, CHR_a, CHR_w, PCT_COMMA,
    PCT_SPACE, CHR_h, CHR_a, CHR_w, PCT_EXCLAMATION, CTR_NEWLINE, CTR_ENDLINE
};

//   {newline}{endline}
static s16 scenario_text_0236[] = {
    PCT_SPACE, PCT_SPACE, CTR_NEWLINE, CTR_ENDLINE
};

//    {big}{em-yellow}Y o u   c o w a r d ! {/em}{/big}{waitinput}{endline}
static s16 scenario_text_024E[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, CTR_BIG, CTR_EM_YELLOW, CHR_Y, PCT_SPACE, CHR_o, PCT_SPACE, CHR_u,
    PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_c, PCT_SPACE, CHR_o, PCT_SPACE, CHR_w, PCT_SPACE, CHR_a,
    PCT_SPACE, CHR_r, PCT_SPACE, CHR_d, PCT_SPACE, PCT_EXCLAMATION, PCT_SPACE, CTR_CLOSE_EM, CTR_CLOSE_BIG, CTR_WAITINPUT,
    CTR_ENDLINE
};

// {end}{endline}
static s16 scenario_text_029A[] = {
    CTR_END, CTR_ENDLINE
};

// Address: @1e34

// {newwindow}{endline}
static s16 scenario_text_02AC[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// {/em}What?{newline}{endline}
static s16 scenario_text_02C4[] = {
    CTR_CLOSE_EM, CHR_W, CHR_h, CHR_a, CHR_t, PCT_QUESTION, CTR_NEWLINE, CTR_ENDLINE
};

//   You poverty-stricken good{newline}{endline}
static s16 scenario_text_02E4[] = {
    PCT_SPACE, PCT_SPACE, CHR_Y, CHR_o, CHR_u, PCT_SPACE, CHR_p, CHR_o, CHR_v, CHR_e,
    CHR_r, CHR_t, CHR_y, PCT_DASH, CHR_s, CHR_t, CHR_r, CHR_i, CHR_c, CHR_k,
    CHR_e, CHR_n, PCT_SPACE, CHR_g, CHR_o, CHR_o, CHR_d, CTR_NEWLINE, CTR_ENDLINE
};

//   for nothing!{endline}
static s16 scenario_text_0315[] = {
    PCT_SPACE, PCT_SPACE, CHR_f, CHR_o, CHR_r, PCT_SPACE, CHR_n, CHR_o, CHR_t, CHR_h,
    CHR_i, CHR_n, CHR_g, PCT_EXCLAMATION, CTR_ENDLINE
};

// {waitinput}{end}{endline}
static s16 scenario_text_0330[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE
};

// Address: @1e68

// {begin}{endline}
static s16 scenario_text_034D[] = {
    CTR_BEGIN, CTR_ENDLINE
};

// Benkei:So you're back again!{button}{endline}
static s16 scenario_text_0361[] = {
    CHR_B, CHR_e, CHR_n, CHR_k, CHR_e, CHR_i, PCT_COLON, CHR_S, CHR_o, PCT_SPACE,
    CHR_y, CHR_o, CHR_u, PCT_APOSTROPHE, CHR_r, CHR_e, PCT_SPACE, CHR_b, CHR_a, CHR_c,
    CHR_k, PCT_SPACE, CHR_a, CHR_g, CHR_a, CHR_i, CHR_n, PCT_EXCLAMATION, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_0392[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// I have no interest in seeing you!{newline}{endline}
static s16 scenario_text_03AA[] = {
    CHR_I, PCT_SPACE, CHR_h, CHR_a, CHR_v, CHR_e, PCT_SPACE, CHR_n, CHR_o, PCT_SPACE,
    CHR_i, CHR_n, CHR_t, CHR_e, CHR_r, CHR_e, CHR_s, CHR_t, PCT_SPACE, CHR_i,
    CHR_n, PCT_SPACE, CHR_s, CHR_e, CHR_e, CHR_i, CHR_n, CHR_g, PCT_SPACE, CHR_y,
    CHR_o, CHR_u, PCT_EXCLAMATION, CTR_NEWLINE, CTR_ENDLINE
};

// Go home!  Go home!!{endline}
static s16 scenario_text_03E1[] = {
    CHR_G, CHR_o, PCT_SPACE, CHR_h, CHR_o, CHR_m, CHR_e, PCT_EXCLAMATION, PCT_SPACE, PCT_SPACE,
    CHR_G, CHR_o, PCT_SPACE, CHR_h, CHR_o, CHR_m, CHR_e, PCT_EXCLAMATION, PCT_EXCLAMATION, CTR_ENDLINE
};

// {waitinput}{end}{endline}
static s16 scenario_text_0401[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE
};

// Address: @1ebc

// {begin}{endline}
static s16 scenario_text_041E[] = {
    CTR_BEGIN, CTR_ENDLINE
};

// {/em}Benkei:Hey!  You over there!{newline}{endline}
static s16 scenario_text_0432[] = {
    CTR_CLOSE_EM, CHR_B, CHR_e, CHR_n, CHR_k, CHR_e, CHR_i, PCT_COLON, CHR_H, CHR_e,
    CHR_y, PCT_EXCLAMATION, PCT_SPACE, PCT_SPACE, CHR_Y, CHR_o, CHR_u, PCT_SPACE, CHR_o, CHR_v,
    CHR_e, CHR_r, PCT_SPACE, CHR_t, CHR_h, CHR_e, CHR_r, CHR_e, PCT_EXCLAMATION, CTR_NEWLINE,
    CTR_ENDLINE
};

//       If you want to cross{newline}{endline}
static s16 scenario_text_0469[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_I, CHR_f, PCT_SPACE, CHR_y,
    CHR_o, CHR_u, PCT_SPACE, CHR_w, CHR_a, CHR_n, CHR_t, PCT_SPACE, CHR_t, CHR_o,
    PCT_SPACE, CHR_c, CHR_r, CHR_o, CHR_s, CHR_s, CTR_NEWLINE, CTR_ENDLINE
};

//       this {em-yellow}bridge{/em}...{button}{endline}
static s16 scenario_text_0499[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_t, CHR_h, CHR_i, CHR_s,
    PCT_SPACE, CTR_EM_YELLOW, CHR_b, CHR_r, CHR_i, CHR_d, CHR_g, CHR_e, CTR_CLOSE_EM, PCT_PERIOD,
    PCT_PERIOD, PCT_PERIOD, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_04D2[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

//   {newline}{endline}
static s16 scenario_text_04EA[] = {
    PCT_SPACE, PCT_SPACE, CTR_NEWLINE, CTR_ENDLINE
};

//          {big}U g h ! {/big}{button}{endline}
static s16 scenario_text_0502[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CTR_BIG,
    CHR_U, PCT_SPACE, CHR_g, PCT_SPACE, CHR_h, PCT_SPACE, PCT_EXCLAMATION, PCT_SPACE, CTR_CLOSE_BIG, CTR_BUTTON,
    CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_0533[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// I can see in your eyes,{newline}{endline}
static s16 scenario_text_054B[] = {
    CHR_I, PCT_SPACE, CHR_c, CHR_a, CHR_n, PCT_SPACE, CHR_s, CHR_e, CHR_e, PCT_SPACE,
    CHR_i, CHR_n, PCT_SPACE, CHR_y, CHR_o, CHR_u, CHR_r, PCT_SPACE, CHR_e, CHR_y,
    CHR_e, CHR_s, PCT_COMMA, CTR_NEWLINE, CTR_ENDLINE
};

// you want to {em-yellow}fight{/em}!{button}{endline}
static s16 scenario_text_0578[] = {
    CHR_y, CHR_o, CHR_u, PCT_SPACE, CHR_w, CHR_a, CHR_n, CHR_t, PCT_SPACE, CHR_t,
    CHR_o, PCT_SPACE, CTR_EM_YELLOW, CHR_f, CHR_i, CHR_g, CHR_h, CHR_t, CTR_CLOSE_EM, PCT_EXCLAMATION,
    CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_05AF[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Very well!{newline}{endline}
static s16 scenario_text_05C7[] = {
    CHR_V, CHR_e, CHR_r, CHR_y, PCT_SPACE, CHR_w, CHR_e, CHR_l, CHR_l, PCT_EXCLAMATION,
    CTR_NEWLINE, CTR_ENDLINE
};

// However, if you {em-yellow}lose{/em}...{button}{endline}
static s16 scenario_text_05E7[] = {
    CHR_H, CHR_o, CHR_w, CHR_e, CHR_v, CHR_e, CHR_r, PCT_COMMA, PCT_SPACE, CHR_i,
    CHR_f, PCT_SPACE, CHR_y, CHR_o, CHR_u, PCT_SPACE, CTR_EM_YELLOW, CHR_l, CHR_o, CHR_s,
    CHR_e, CTR_CLOSE_EM, PCT_PERIOD, PCT_PERIOD, PCT_PERIOD, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_0623[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

//   {newline}{endline}
static s16 scenario_text_063B[] = {
    PCT_SPACE, PCT_SPACE, CTR_NEWLINE, CTR_ENDLINE
};

//  {blink}{em-yellow}I will blast you far, far away!{/em}{/blink}{button}{end}{endline}
static s16 scenario_text_0653[] = {
    PCT_SPACE, CTR_BLINK, CTR_EM_YELLOW, CHR_I, PCT_SPACE, CHR_w, CHR_i, CHR_l, CHR_l, PCT_SPACE,
    CHR_b, CHR_l, CHR_a, CHR_s, CHR_t, PCT_SPACE, CHR_y, CHR_o, CHR_u, PCT_SPACE,
    CHR_f, CHR_a, CHR_r, PCT_COMMA, PCT_SPACE, CHR_f, CHR_a, CHR_r, PCT_SPACE, CHR_a,
    CHR_w, CHR_a, CHR_y, PCT_EXCLAMATION, CTR_CLOSE_EM, CTR_CLOSE_BLINK, CTR_BUTTON, CTR_END, CTR_ENDLINE
};

// {begin}{endline}
static s16 scenario_text_06AC[] = {
    CTR_BEGIN, CTR_ENDLINE
};

// Narrator:Well, well!{newline}{endline}
static s16 scenario_text_06C0[] = {
    CHR_N, CHR_a, CHR_r, CHR_r, CHR_a, CHR_t, CHR_o, CHR_r, PCT_COLON, CHR_W,
    CHR_e, CHR_l, CHR_l, PCT_COMMA, PCT_SPACE, CHR_w, CHR_e, CHR_l, CHR_l, PCT_EXCLAMATION,
    CTR_NEWLINE, CTR_ENDLINE
};

//        It's a fight with Benkei!{button}{endline}
static s16 scenario_text_06EA[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_I, CHR_t, PCT_APOSTROPHE,
    CHR_s, PCT_SPACE, CHR_a, PCT_SPACE, CHR_f, CHR_i, CHR_g, CHR_h, CHR_t, PCT_SPACE,
    CHR_w, CHR_i, CHR_t, CHR_h, PCT_SPACE, CHR_B, CHR_e, CHR_n, CHR_k, CHR_e,
    CHR_i, PCT_EXCLAMATION, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_071F[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Narrator:Look for the instant{newline}{endline}
static s16 scenario_text_0737[] = {
    CHR_N, CHR_a, CHR_r, CHR_r, CHR_a, CHR_t, CHR_o, CHR_r, PCT_COLON, CHR_L,
    CHR_o, CHR_o, CHR_k, PCT_SPACE, CHR_f, CHR_o, CHR_r, PCT_SPACE, CHR_t, CHR_h,
    CHR_e, PCT_SPACE, CHR_i, CHR_n, CHR_s, CHR_t, CHR_a, CHR_n, CHR_t, CTR_NEWLINE,
    CTR_ENDLINE
};

//        Benkei {em-yellow}reaches the ground{/em}{newline}{endline}
static s16 scenario_text_076A[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_B, CHR_e, CHR_n,
    CHR_k, CHR_e, CHR_i, PCT_SPACE, CTR_EM_YELLOW, CHR_r, CHR_e, CHR_a, CHR_c, CHR_h,
    CHR_e, CHR_s, PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE, CHR_g, CHR_r, CHR_o,
    CHR_u, CHR_n, CHR_d, CTR_CLOSE_EM, CTR_NEWLINE, CTR_ENDLINE
};

//        when {em-yellow}jumping{/em}...{button}{endline}
static s16 scenario_text_07B0[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_w, CHR_h, CHR_e,
    CHR_n, PCT_SPACE, CTR_EM_YELLOW, CHR_j, CHR_u, CHR_m, CHR_p, CHR_i, CHR_n, CHR_g,
    CTR_CLOSE_EM, PCT_PERIOD, PCT_PERIOD, PCT_PERIOD, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_07EB[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Narrator:...and throw the {em-yellow}Achilles'{newline}{endline}
static s16 scenario_text_0803[] = {
    CHR_N, CHR_a, CHR_r, CHR_r, CHR_a, CHR_t, CHR_o, CHR_r, PCT_COLON, PCT_PERIOD,
    PCT_PERIOD, PCT_PERIOD, CHR_a, CHR_n, CHR_d, PCT_SPACE, CHR_t, CHR_h, CHR_r, CHR_o,
    CHR_w, PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE, CTR_EM_YELLOW, CHR_A, CHR_c, CHR_h,
    CHR_i, CHR_l, CHR_l, CHR_e, CHR_s, PCT_APOSTROPHE, CTR_NEWLINE, CTR_ENDLINE
};

//        heel{/em} at him {em-yellow}three{/em} times {newline}{endline}
static s16 scenario_text_0847[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_h, CHR_e, CHR_e,
    CHR_l, CTR_CLOSE_EM, PCT_SPACE, CHR_a, CHR_t, PCT_SPACE, CHR_h, CHR_i, CHR_m, PCT_SPACE,
    CTR_EM_YELLOW, CHR_t, CHR_h, CHR_r, CHR_e, CHR_e, CTR_CLOSE_EM, PCT_SPACE, CHR_t, CHR_i,
    CHR_m, CHR_e, CHR_s, PCT_SPACE, CTR_NEWLINE, CTR_ENDLINE
};

//        within the time limit.{button}{endline}
static s16 scenario_text_0891[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_w, CHR_i, CHR_t,
    CHR_h, CHR_i, CHR_n, PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE, CHR_t, CHR_i,
    CHR_m, CHR_e, PCT_SPACE, CHR_l, CHR_i, CHR_m, CHR_i, CHR_t, PCT_PERIOD, CTR_BUTTON,
    CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_08C3[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Narrator:The item can be {newline}{endline}
static s16 scenario_text_08DB[] = {
    CHR_N, CHR_a, CHR_r, CHR_r, CHR_a, CHR_t, CHR_o, CHR_r, PCT_COLON, CHR_T,
    CHR_h, CHR_e, PCT_SPACE, CHR_i, CHR_t, CHR_e, CHR_m, PCT_SPACE, CHR_c, CHR_a,
    CHR_n, PCT_SPACE, CHR_b, CHR_e, PCT_SPACE, CTR_NEWLINE, CTR_ENDLINE
};

//        thrown by pressing{newline}{endline}
static s16 scenario_text_090A[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_t, CHR_h, CHR_r,
    CHR_o, CHR_w, CHR_n, PCT_SPACE, CHR_b, CHR_y, PCT_SPACE, CHR_p, CHR_r, CHR_e,
    CHR_s, CHR_s, CHR_i, CHR_n, CHR_g, CTR_NEWLINE, CTR_ENDLINE
};

//        the [{em-yellow}B{/em} Button].{button}{end}{endline}
static s16 scenario_text_0939[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_t, CHR_h, CHR_e,
    PCT_SPACE, PCT_LBRACKET, CTR_EM_YELLOW, CHR_B, CTR_CLOSE_EM, PCT_SPACE, CHR_B, CHR_u, CHR_t, CHR_t,
    CHR_o, CHR_n, PCT_RBRACKET, PCT_PERIOD, CTR_BUTTON, CTR_END, CTR_ENDLINE
};

// Address: @20c0

// {begin}{endline}
static s16 scenario_text_0979[] = {
    CTR_BEGIN, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_098D[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// {/em}Benkei:Then,{newline}{endline}
static s16 scenario_text_09A5[] = {
    CTR_CLOSE_EM, CHR_B, CHR_e, CHR_n, CHR_k, CHR_e, CHR_i, PCT_COLON, CHR_T, CHR_h,
    CHR_e, CHR_n, PCT_COMMA, CTR_NEWLINE, CTR_ENDLINE
};

//   {newline}{endline}
static s16 scenario_text_09CC[] = {
    PCT_SPACE, PCT_SPACE, CTR_NEWLINE, CTR_ENDLINE
};

//  {em-yellow}{big}{blink}w e   s h a l l   b e g i n ! {/blink}{/big}{/em}{newline}{endline}
static s16 scenario_text_09E4[] = {
    PCT_SPACE, CTR_EM_YELLOW, CTR_BIG, CTR_BLINK, CHR_w, PCT_SPACE, CHR_e, PCT_SPACE, PCT_SPACE, PCT_SPACE,
    CHR_s, PCT_SPACE, CHR_h, PCT_SPACE, CHR_a, PCT_SPACE, CHR_l, PCT_SPACE, CHR_l, PCT_SPACE,
    PCT_SPACE, PCT_SPACE, CHR_b, PCT_SPACE, CHR_e, PCT_SPACE, CHR_g, PCT_SPACE, CHR_i, PCT_SPACE,
    CHR_n, PCT_SPACE, PCT_EXCLAMATION, PCT_SPACE, CTR_CLOSE_BLINK, CTR_CLOSE_BIG, CTR_CLOSE_EM, CTR_NEWLINE, CTR_ENDLINE
};

// {end}{endline}
static s16 scenario_text_0A43[] = {
    CTR_END, CTR_ENDLINE
};

// Address: @21d4

// {begin}{endline}
static s16 scenario_text_0A55[] = {
    CTR_BEGIN, CTR_ENDLINE
};

// Benkei:You fool!{newline}{endline}
static s16 scenario_text_0A69[] = {
    CHR_B, CHR_e, CHR_n, CHR_k, CHR_e, CHR_i, PCT_COLON, CHR_Y, CHR_o, CHR_u,
    PCT_SPACE, CHR_f, CHR_o, CHR_o, CHR_l, PCT_EXCLAMATION, CTR_NEWLINE, CTR_ENDLINE
};

//       That's what you get for{newline}{endline}
static s16 scenario_text_0A8F[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_T, CHR_h, CHR_a, CHR_t,
    PCT_APOSTROPHE, CHR_s, PCT_SPACE, CHR_w, CHR_h, CHR_a, CHR_t, PCT_SPACE, CHR_y, CHR_o,
    CHR_u, PCT_SPACE, CHR_g, CHR_e, CHR_t, PCT_SPACE, CHR_f, CHR_o, CHR_r, CTR_NEWLINE,
    CTR_ENDLINE
};

//       taking me lightly!{endline}
static s16 scenario_text_0AC2[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_t, CHR_a, CHR_k, CHR_i,
    CHR_n, CHR_g, PCT_SPACE, CHR_m, CHR_e, PCT_SPACE, CHR_l, CHR_i, CHR_g, CHR_h,
    CHR_t, CHR_l, CHR_y, PCT_EXCLAMATION, CTR_ENDLINE
};

// {end}{endline}
static s16 scenario_text_0AE7[] = {
    CTR_END, CTR_ENDLINE
};

// Address: @2280

// {begin}{endline}
static s16 scenario_text_0AF9[] = {
    CTR_BEGIN, CTR_ENDLINE
};

// Benkei:Do you want to challenge{newline}{endline}
static s16 scenario_text_0B0D[] = {
    CHR_B, CHR_e, CHR_n, CHR_k, CHR_e, CHR_i, PCT_COLON, CHR_D, CHR_o, PCT_SPACE,
    CHR_y, CHR_o, CHR_u, PCT_SPACE, CHR_w, CHR_a, CHR_n, CHR_t, PCT_SPACE, CHR_t,
    CHR_o, PCT_SPACE, CHR_c, CHR_h, CHR_a, CHR_l, CHR_l, CHR_e, CHR_n, CHR_g,
    CHR_e, CTR_NEWLINE, CTR_ENDLINE
};

//       me to another fight?{newline}{endline}
static s16 scenario_text_0B42[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_m, CHR_e, PCT_SPACE, CHR_t,
    CHR_o, PCT_SPACE, CHR_a, CHR_n, CHR_o, CHR_t, CHR_h, CHR_e, CHR_r, PCT_SPACE,
    CHR_f, CHR_i, CHR_g, CHR_h, CHR_t, PCT_QUESTION, CTR_NEWLINE, CTR_ENDLINE
};

//   {em-yellow}I will not lose this time!{newline}{endline}
static s16 scenario_text_0B72[] = {
    PCT_SPACE, PCT_SPACE, CTR_EM_YELLOW, CHR_I, PCT_SPACE, CHR_w, CHR_i, CHR_l, CHR_l, PCT_SPACE,
    CHR_n, CHR_o, CHR_t, PCT_SPACE, CHR_l, CHR_o, CHR_s, CHR_e, PCT_SPACE, CHR_t,
    CHR_h, CHR_i, CHR_s, PCT_SPACE, CHR_t, CHR_i, CHR_m, CHR_e, PCT_EXCLAMATION, CTR_NEWLINE,
    CTR_ENDLINE
};

//   {em-yellow}No, I've decided not to...{newline}{endline}
static s16 scenario_text_0BAF[] = {
    PCT_SPACE, PCT_SPACE, CTR_EM_YELLOW, CHR_N, CHR_o, PCT_COMMA, PCT_SPACE, CHR_I, PCT_APOSTROPHE, CHR_v,
    CHR_e, PCT_SPACE, CHR_d, CHR_e, CHR_c, CHR_i, CHR_d, CHR_e, CHR_d, PCT_SPACE,
    CHR_n, CHR_o, CHR_t, PCT_SPACE, CHR_t, CHR_o, PCT_PERIOD, PCT_PERIOD, PCT_PERIOD, CTR_NEWLINE,
    CTR_ENDLINE
};

// {end}{endline}
static s16 scenario_text_0BEC[] = {
    CTR_END, CTR_ENDLINE
};

// Address: @22ec

// {begin}{endline}
static s16 scenario_text_0BFE[] = {
    CTR_BEGIN, CTR_ENDLINE
};

// Narrator:Ever since{newline}{endline}
static s16 scenario_text_0C12[] = {
    CHR_N, CHR_a, CHR_r, CHR_r, CHR_a, CHR_t, CHR_o, CHR_r, PCT_COLON, CHR_E,
    CHR_v, CHR_e, CHR_r, PCT_SPACE, CHR_s, CHR_i, CHR_n, CHR_c, CHR_e, CTR_NEWLINE,
    CTR_ENDLINE
};

//        the {em-yellow}Achilles' heel{/em}{newline}{endline}
static s16 scenario_text_0C3B[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_t, CHR_h, CHR_e,
    PCT_SPACE, CTR_EM_YELLOW, CHR_A, CHR_c, CHR_h, CHR_i, CHR_l, CHR_l, CHR_e, CHR_s,
    PCT_APOSTROPHE, PCT_SPACE, CHR_h, CHR_e, CHR_e, CHR_l, CTR_CLOSE_EM, CTR_NEWLINE, CTR_ENDLINE
};

//        was thrown at Benkei...{button}{endline}
static s16 scenario_text_0C7A[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_w, CHR_a, CHR_s,
    PCT_SPACE, CHR_t, CHR_h, CHR_r, CHR_o, CHR_w, CHR_n, PCT_SPACE, CHR_a, CHR_t,
    PCT_SPACE, CHR_B, CHR_e, CHR_n, CHR_k, CHR_e, CHR_i, PCT_PERIOD, PCT_PERIOD, PCT_PERIOD,
    CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_0CAD[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Narrator:Achilles' heel was meant{newline}{endline}
static s16 scenario_text_0CC5[] = {
    CHR_N, CHR_a, CHR_r, CHR_r, CHR_a, CHR_t, CHR_o, CHR_r, PCT_COLON, CHR_A,
    CHR_c, CHR_h, CHR_i, CHR_l, CHR_l, CHR_e, CHR_s, PCT_APOSTROPHE, PCT_SPACE, CHR_h,
    CHR_e, CHR_e, CHR_l, PCT_SPACE, CHR_w, CHR_a, CHR_s, PCT_SPACE, CHR_m, CHR_e,
    CHR_a, CHR_n, CHR_t, CTR_NEWLINE, CTR_ENDLINE
};

//        to be the {em-yellow}weak point{/em} of{newline}{endline}
static s16 scenario_text_0CFC[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_t, CHR_o, PCT_SPACE,
    CHR_b, CHR_e, PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE, CTR_EM_YELLOW, CHR_w, CHR_e,
    CHR_a, CHR_k, PCT_SPACE, CHR_p, CHR_o, CHR_i, CHR_n, CHR_t, CTR_CLOSE_EM, PCT_SPACE,
    CHR_o, CHR_f, CTR_NEWLINE, CTR_ENDLINE
};

//        someone.{button}{end}{endline}
static s16 scenario_text_0D40[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_s, CHR_o, CHR_m,
    CHR_e, CHR_o, CHR_n, CHR_e, PCT_PERIOD, CTR_BUTTON, CTR_END, CTR_ENDLINE
};

// {begin}{endline}
static s16 scenario_text_0D69[] = {
    CTR_BEGIN, CTR_ENDLINE
};

// Ebisumaru:There's something fishy{newline}{endline}
static s16 scenario_text_0D7D[] = {
    CHR_E, CHR_b, CHR_i, CHR_s, CHR_u, CHR_m, CHR_a, CHR_r, CHR_u, PCT_COLON,
    CHR_T, CHR_h, CHR_e, CHR_r, CHR_e, PCT_APOSTROPHE, CHR_s, PCT_SPACE, CHR_s, CHR_o,
    CHR_m, CHR_e, CHR_t, CHR_h, CHR_i, CHR_n, CHR_g, PCT_SPACE, CHR_f, CHR_i,
    CHR_s, CHR_h, CHR_y, CTR_NEWLINE, CTR_ENDLINE
};

//        about that story...{newline}{endline}
static s16 scenario_text_0DB4[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_a, CHR_b, CHR_o,
    CHR_u, CHR_t, PCT_SPACE, CHR_t, CHR_h, CHR_a, CHR_t, PCT_SPACE, CHR_s, CHR_t,
    CHR_o, CHR_r, CHR_y, PCT_PERIOD, PCT_PERIOD, PCT_PERIOD, CTR_NEWLINE, CTR_ENDLINE
};

// {button}{end}{endline}
static s16 scenario_text_0DE4[] = {
    CTR_BUTTON, CTR_END, CTR_ENDLINE
};

// Address: @28d8

// {begin}{endline}
static s16 scenario_text_0DFE[] = {
    CTR_BEGIN, CTR_ENDLINE
};

// Benkei:You can cross any time{newline}{endline}
static s16 scenario_text_0E12[] = {
    CHR_B, CHR_e, CHR_n, CHR_k, CHR_e, CHR_i, PCT_COLON, CHR_Y, CHR_o, CHR_u,
    PCT_SPACE, CHR_c, CHR_a, CHR_n, PCT_SPACE, CHR_c, CHR_r, CHR_o, CHR_s, CHR_s,
    PCT_SPACE, CHR_a, CHR_n, CHR_y, PCT_SPACE, CHR_t, CHR_i, CHR_m, CHR_e, CTR_NEWLINE,
    CTR_ENDLINE
};

//       you wish!{newline}{endline}
static s16 scenario_text_0E45[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_y, CHR_o, CHR_u, PCT_SPACE,
    CHR_w, CHR_i, CHR_s, CHR_h, PCT_EXCLAMATION, CTR_NEWLINE, CTR_ENDLINE
};

//       Go right ahead!{endline}
static s16 scenario_text_0E6A[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_G, CHR_o, PCT_SPACE, CHR_r,
    CHR_i, CHR_g, CHR_h, CHR_t, PCT_SPACE, CHR_a, CHR_h, CHR_e, CHR_a, CHR_d,
    PCT_EXCLAMATION, CTR_ENDLINE
};

// {waitinput}{end}{endline}
static s16 scenario_text_0E8C[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE
};

// Address: @2924

// {begin}{endline}
static s16 scenario_text_0EA9[] = {
    CTR_BEGIN, CTR_ENDLINE
};

// Benkei:I've seen strange things{newline}{endline}
static s16 scenario_text_0EBD[] = {
    CHR_B, CHR_e, CHR_n, CHR_k, CHR_e, CHR_i, PCT_COLON, CHR_I, PCT_APOSTROPHE, CHR_v,
    CHR_e, PCT_SPACE, CHR_s, CHR_e, CHR_e, CHR_n, PCT_SPACE, CHR_s, CHR_t, CHR_r,
    CHR_a, CHR_n, CHR_g, CHR_e, PCT_SPACE, CHR_t, CHR_h, CHR_i, CHR_n, CHR_g,
    CHR_s, CTR_NEWLINE, CTR_ENDLINE
};

//       recently...{button}{endline}
static s16 scenario_text_0EF2[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_r, CHR_e, CHR_c, CHR_e,
    CHR_n, CHR_t, CHR_l, CHR_y, PCT_PERIOD, PCT_PERIOD, PCT_PERIOD, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_0F18[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// What?{newline}{endline}
static s16 scenario_text_0F30[] = {
    CHR_W, CHR_h, CHR_a, CHR_t, PCT_QUESTION, CTR_NEWLINE, CTR_ENDLINE
};

// You ask me what I see?{button}{endline}
static s16 scenario_text_0F4B[] = {
    CHR_Y, CHR_o, CHR_u, PCT_SPACE, CHR_a, CHR_s, CHR_k, PCT_SPACE, CHR_m, CHR_e,
    PCT_SPACE, CHR_w, CHR_h, CHR_a, CHR_t, PCT_SPACE, CHR_I, PCT_SPACE, CHR_s, CHR_e,
    CHR_e, PCT_QUESTION, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_0F76[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Well it's a much, much smaller{newline}{endline}
static s16 scenario_text_0F8E[] = {
    CHR_W, CHR_e, CHR_l, CHR_l, PCT_SPACE, CHR_i, CHR_t, PCT_APOSTROPHE, CHR_s, PCT_SPACE,
    CHR_a, PCT_SPACE, CHR_m, CHR_u, CHR_c, CHR_h, PCT_COMMA, PCT_SPACE, CHR_m, CHR_u,
    CHR_c, CHR_h, PCT_SPACE, CHR_s, CHR_m, CHR_a, CHR_l, CHR_l, CHR_e, CHR_r,
    CTR_NEWLINE, CTR_ENDLINE
};

// {em-yellow}Ushiwaka{/em}!{endline}
static s16 scenario_text_0FC2[] = {
    CTR_EM_YELLOW, CHR_U, CHR_s, CHR_h, CHR_i, CHR_w, CHR_a, CHR_k, CHR_a, CTR_CLOSE_EM,
    PCT_EXCLAMATION, CTR_ENDLINE
};

// {waitinput}{end}{endline}
static s16 scenario_text_0FE8[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE
};

// Address: @2998

// {begin}{endline}
static s16 scenario_text_1005[] = {
    CTR_BEGIN, CTR_ENDLINE
};

// Benkei:What is it today?{button}{end}{endline}
static s16 scenario_text_1019[] = {
    CHR_B, CHR_e, CHR_n, CHR_k, CHR_e, CHR_i, PCT_COLON, CHR_W, CHR_h, CHR_a,
    CHR_t, PCT_SPACE, CHR_i, CHR_s, PCT_SPACE, CHR_i, CHR_t, PCT_SPACE, CHR_t, CHR_o,
    CHR_d, CHR_a, CHR_y, PCT_QUESTION, CTR_BUTTON, CTR_END, CTR_ENDLINE
};

// {begin}{endline}
static s16 scenario_text_104B[] = {
    CTR_BEGIN, CTR_ENDLINE
};

// Goemon:I have a question!{button}{endline}
static s16 scenario_text_105F[] = {
    CHR_G, CHR_o, CHR_e, CHR_m, CHR_o, CHR_n, PCT_COLON, CHR_I, PCT_SPACE, CHR_h,
    CHR_a, CHR_v, CHR_e, PCT_SPACE, CHR_a, PCT_SPACE, CHR_q, CHR_u, CHR_e, CHR_s,
    CHR_t, CHR_i, CHR_o, CHR_n, PCT_EXCLAMATION, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_108D[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Goemon:Do you have something{newline}{endline}
static s16 scenario_text_10A5[] = {
    CHR_G, CHR_o, CHR_e, CHR_m, CHR_o, CHR_n, PCT_COLON, CHR_D, CHR_o, PCT_SPACE,
    CHR_y, CHR_o, CHR_u, PCT_SPACE, CHR_h, CHR_a, CHR_v, CHR_e, PCT_SPACE, CHR_s,
    CHR_o, CHR_m, CHR_e, CHR_t, CHR_h, CHR_i, CHR_n, CHR_g, CTR_NEWLINE, CTR_ENDLINE
};

//       called a {em-yellow}Miracle Item{/em}?{button}{end}{endline}
static s16 scenario_text_10D7[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_c, CHR_a, CHR_l, CHR_l,
    CHR_e, CHR_d, PCT_SPACE, CHR_a, PCT_SPACE, CTR_EM_YELLOW, CHR_M, CHR_i, CHR_r, CHR_a,
    CHR_c, CHR_l, CHR_e, PCT_SPACE, CHR_I, CHR_t, CHR_e, CHR_m, CTR_CLOSE_EM, PCT_QUESTION,
    CTR_BUTTON, CTR_END, CTR_ENDLINE
};

// Address: @2a9c

// {begin}{endline}
static s16 scenario_text_111D[] = {
    CTR_BEGIN, CTR_ENDLINE
};

// Ebisumaru:I want to ask you {newline}{endline}
static s16 scenario_text_1131[] = {
    CHR_E, CHR_b, CHR_i, CHR_s, CHR_u, CHR_m, CHR_a, CHR_r, CHR_u, PCT_COLON,
    CHR_I, PCT_SPACE, CHR_w, CHR_a, CHR_n, CHR_t, PCT_SPACE, CHR_t, CHR_o, PCT_SPACE,
    CHR_a, CHR_s, CHR_k, PCT_SPACE, CHR_y, CHR_o, CHR_u, PCT_SPACE, CTR_NEWLINE, CTR_ENDLINE
};

//        a question, Benkei!{button}{endline}
static s16 scenario_text_1163[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_a, PCT_SPACE, CHR_q,
    CHR_u, CHR_e, CHR_s, CHR_t, CHR_i, CHR_o, CHR_n, PCT_COMMA, PCT_SPACE, CHR_B,
    CHR_e, CHR_n, CHR_k, CHR_e, CHR_i, PCT_EXCLAMATION, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_1192[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Ebisumaru:Do you know of{newline}{endline}
static s16 scenario_text_11AA[] = {
    CHR_E, CHR_b, CHR_i, CHR_s, CHR_u, CHR_m, CHR_a, CHR_r, CHR_u, PCT_COLON,
    CHR_D, CHR_o, PCT_SPACE, CHR_y, CHR_o, CHR_u, PCT_SPACE, CHR_k, CHR_n, CHR_o,
    CHR_w, PCT_SPACE, CHR_o, CHR_f, CTR_NEWLINE, CTR_ENDLINE
};

//        this thing called {newline}{endline}
static s16 scenario_text_11D8[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_t, CHR_h, CHR_i,
    CHR_s, PCT_SPACE, CHR_t, CHR_h, CHR_i, CHR_n, CHR_g, PCT_SPACE, CHR_c, CHR_a,
    CHR_l, CHR_l, CHR_e, CHR_d, PCT_SPACE, CTR_NEWLINE, CTR_ENDLINE
};

//        a {em-yellow}Miracle Item{/em}?{button}{end}{endline}
static s16 scenario_text_1207[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_a, PCT_SPACE, CTR_EM_YELLOW,
    CHR_M, CHR_i, CHR_r, CHR_a, CHR_c, CHR_l, CHR_e, PCT_SPACE, CHR_I, CHR_t,
    CHR_e, CHR_m, CTR_CLOSE_EM, PCT_QUESTION, CTR_BUTTON, CTR_END, CTR_ENDLINE
};

// Address: @2b00

// {begin}{endline}
static s16 scenario_text_1247[] = {
    CTR_BEGIN, CTR_ENDLINE
};

// Yae:Excuse me, Mr. Benkei,{newline}{endline}
static s16 scenario_text_125B[] = {
    CHR_Y, CHR_a, CHR_e, PCT_COLON, CHR_E, CHR_x, CHR_c, CHR_u, CHR_s, CHR_e,
    PCT_SPACE, CHR_m, CHR_e, PCT_COMMA, PCT_SPACE, CHR_M, CHR_r, PCT_PERIOD, PCT_SPACE, CHR_B,
    CHR_e, CHR_n, CHR_k, CHR_e, CHR_i, PCT_COMMA, CTR_NEWLINE, CTR_ENDLINE
};

//       I'd like to ask you{newline}{endline}
static s16 scenario_text_128B[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_I, PCT_APOSTROPHE, CHR_d, PCT_SPACE,
    CHR_l, CHR_i, CHR_k, CHR_e, PCT_SPACE, CHR_t, CHR_o, PCT_SPACE, CHR_a, CHR_s,
    CHR_k, PCT_SPACE, CHR_y, CHR_o, CHR_u, CTR_NEWLINE, CTR_ENDLINE
};

//       something...{button}{endline}
static s16 scenario_text_12BA[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_s, CHR_o, CHR_m, CHR_e,
    CHR_t, CHR_h, CHR_i, CHR_n, CHR_g, PCT_PERIOD, PCT_PERIOD, PCT_PERIOD, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_12E1[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Yae:Would you not have something{newline}{endline}
static s16 scenario_text_12F9[] = {
    CHR_Y, CHR_a, CHR_e, PCT_COLON, CHR_W, CHR_o, CHR_u, CHR_l, CHR_d, PCT_SPACE,
    CHR_y, CHR_o, CHR_u, PCT_SPACE, CHR_n, CHR_o, CHR_t, PCT_SPACE, CHR_h, CHR_a,
    CHR_v, CHR_e, PCT_SPACE, CHR_s, CHR_o, CHR_m, CHR_e, CHR_t, CHR_h, CHR_i,
    CHR_n, CHR_g, CTR_NEWLINE, CTR_ENDLINE
};

//       called a{em-yellow} Miracle Item{/em}?{button}{end}{endline}
static s16 scenario_text_132F[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_c, CHR_a, CHR_l, CHR_l,
    CHR_e, CHR_d, PCT_SPACE, CHR_a, CTR_EM_YELLOW, PCT_SPACE, CHR_M, CHR_i, CHR_r, CHR_a,
    CHR_c, CHR_l, CHR_e, PCT_SPACE, CHR_I, CHR_t, CHR_e, CHR_m, CTR_CLOSE_EM, PCT_QUESTION,
    CTR_BUTTON, CTR_END, CTR_ENDLINE
};

// Address: @2b64

// {begin}{endline}
static s16 scenario_text_1375[] = {
    CTR_BEGIN, CTR_ENDLINE
};

// Sasuke:I would like to ask you{newline}{endline}
static s16 scenario_text_1389[] = {
    CHR_S, CHR_a, CHR_s, CHR_u, CHR_k, CHR_e, PCT_COLON, CHR_I, PCT_SPACE, CHR_w,
    CHR_o, CHR_u, CHR_l, CHR_d, PCT_SPACE, CHR_l, CHR_i, CHR_k, CHR_e, PCT_SPACE,
    CHR_t, CHR_o, PCT_SPACE, CHR_a, CHR_s, CHR_k, PCT_SPACE, CHR_y, CHR_o, CHR_u,
    CTR_NEWLINE, CTR_ENDLINE
};

//       something Mr. Benkei.{button}{endline}
static s16 scenario_text_13BD[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_s, CHR_o, CHR_m, CHR_e,
    CHR_t, CHR_h, CHR_i, CHR_n, CHR_g, PCT_SPACE, CHR_M, CHR_r, PCT_PERIOD, PCT_SPACE,
    CHR_B, CHR_e, CHR_n, CHR_k, CHR_e, CHR_i, PCT_PERIOD, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_13ED[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Sasuke:By chance,{newline}{endline}
static s16 scenario_text_1405[] = {
    CHR_S, CHR_a, CHR_s, CHR_u, CHR_k, CHR_e, PCT_COLON, CHR_B, CHR_y, PCT_SPACE,
    CHR_c, CHR_h, CHR_a, CHR_n, CHR_c, CHR_e, PCT_COMMA, CTR_NEWLINE, CTR_ENDLINE
};

//       do you have something{newline}{endline}
static s16 scenario_text_142C[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_d, CHR_o, PCT_SPACE, CHR_y,
    CHR_o, CHR_u, PCT_SPACE, CHR_h, CHR_a, CHR_v, CHR_e, PCT_SPACE, CHR_s, CHR_o,
    CHR_m, CHR_e, CHR_t, CHR_h, CHR_i, CHR_n, CHR_g, CTR_NEWLINE, CTR_ENDLINE
};

//       called the {em-yellow}Miracle Item{/em}?{button}{end}{endline}
static s16 scenario_text_145D[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_c, CHR_a, CHR_l, CHR_l,
    CHR_e, CHR_d, PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE, CTR_EM_YELLOW, CHR_M, CHR_i,
    CHR_r, CHR_a, CHR_c, CHR_l, CHR_e, PCT_SPACE, CHR_I, CHR_t, CHR_e, CHR_m,
    CTR_CLOSE_EM, PCT_QUESTION, CTR_BUTTON, CTR_END, CTR_ENDLINE
};

// Address: @2bc8

// {begin}{endline}
static s16 scenario_text_14A5[] = {
    CTR_BEGIN, CTR_ENDLINE
};

// Benkei:Huh?{newline}{endline}
static s16 scenario_text_14B9[] = {
    CHR_B, CHR_e, CHR_n, CHR_k, CHR_e, CHR_i, PCT_COLON, CHR_H, CHR_u, CHR_h,
    PCT_QUESTION, CTR_NEWLINE, CTR_ENDLINE
};

//       A {em-yellow}Miracle{/em}...?{button}{endline}
static s16 scenario_text_14DA[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_A, PCT_SPACE, CTR_EM_YELLOW, CHR_M,
    CHR_i, CHR_r, CHR_a, CHR_c, CHR_l, CHR_e, CTR_CLOSE_EM, PCT_PERIOD, PCT_PERIOD, PCT_PERIOD,
    PCT_QUESTION, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_1512[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// No, I'm sorry,{newline}{endline}
static s16 scenario_text_152A[] = {
    CHR_N, CHR_o, PCT_COMMA, PCT_SPACE, CHR_I, PCT_APOSTROPHE, CHR_m, PCT_SPACE, CHR_s, CHR_o,
    CHR_r, CHR_r, CHR_y, PCT_COMMA, CTR_NEWLINE, CTR_ENDLINE
};

// I don't have any such thing.{button}{endline}
static s16 scenario_text_154E[] = {
    CHR_I, PCT_SPACE, CHR_d, CHR_o, CHR_n, PCT_APOSTROPHE, CHR_t, PCT_SPACE, CHR_h, CHR_a,
    CHR_v, CHR_e, PCT_SPACE, CHR_a, CHR_n, CHR_y, PCT_SPACE, CHR_s, CHR_u, CHR_c,
    CHR_h, PCT_SPACE, CHR_t, CHR_h, CHR_i, CHR_n, CHR_g, PCT_PERIOD, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_157F[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// But maybe {em-yellow}he{/em} would have it...{button}{end}{endline}
static s16 scenario_text_1597[] = {
    CHR_B, CHR_u, CHR_t, PCT_SPACE, CHR_m, CHR_a, CHR_y, CHR_b, CHR_e, PCT_SPACE,
    CTR_EM_YELLOW, CHR_h, CHR_e, CTR_CLOSE_EM, PCT_SPACE, CHR_w, CHR_o, CHR_u, CHR_l, CHR_d,
    PCT_SPACE, CHR_h, CHR_a, CHR_v, CHR_e, PCT_SPACE, CHR_i, CHR_t, PCT_PERIOD, PCT_PERIOD,
    PCT_PERIOD, CTR_BUTTON, CTR_END, CTR_ENDLINE
};

// {begin}{endline}
static s16 scenario_text_15DE[] = {
    CTR_BEGIN, CTR_ENDLINE
};

// Ebisumaru:Uh-huh, {newline}{endline}
static s16 scenario_text_15F2[] = {
    CHR_E, CHR_b, CHR_i, CHR_s, CHR_u, CHR_m, CHR_a, CHR_r, CHR_u, PCT_COLON,
    CHR_U, CHR_h, PCT_DASH, CHR_h, CHR_u, CHR_h, PCT_COMMA, PCT_SPACE, CTR_NEWLINE, CTR_ENDLINE
};

//        and who could that be?{button}{end}{endline}
static s16 scenario_text_161A[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_a, CHR_n, CHR_d,
    PCT_SPACE, CHR_w, CHR_h, CHR_o, PCT_SPACE, CHR_c, CHR_o, CHR_u, CHR_l, CHR_d,
    PCT_SPACE, CHR_t, CHR_h, CHR_a, CHR_t, PCT_SPACE, CHR_b, CHR_e, PCT_QUESTION, CTR_BUTTON,
    CTR_END, CTR_ENDLINE
};

// {begin}{endline}
static s16 scenario_text_1651[] = {
    CTR_BEGIN, CTR_ENDLINE
};

// Benkei:Well, there is the {em-yellow}collector{/em}{newline}{endline}
static s16 scenario_text_1665[] = {
    CHR_B, CHR_e, CHR_n, CHR_k, CHR_e, CHR_i, PCT_COLON, CHR_W, CHR_e, CHR_l,
    CHR_l, PCT_COMMA, PCT_SPACE, CHR_t, CHR_h, CHR_e, CHR_r, CHR_e, PCT_SPACE, CHR_i,
    CHR_s, PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE, CTR_EM_YELLOW, CHR_c, CHR_o, CHR_l,
    CHR_l, CHR_e, CHR_c, CHR_t, CHR_o, CHR_r, CTR_CLOSE_EM, CTR_NEWLINE, CTR_ENDLINE
};

//       with a collection even{newline}{endline}
static s16 scenario_text_16AE[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_w, CHR_i, CHR_t, CHR_h,
    PCT_SPACE, CHR_a, PCT_SPACE, CHR_c, CHR_o, CHR_l, CHR_l, CHR_e, CHR_c, CHR_t,
    CHR_i, CHR_o, CHR_n, PCT_SPACE, CHR_e, CHR_v, CHR_e, CHR_n, CTR_NEWLINE, CTR_ENDLINE
};

//       greater than mine...{button}{endline}
static s16 scenario_text_16E0[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_g, CHR_r, CHR_e, CHR_a,
    CHR_t, CHR_e, CHR_r, PCT_SPACE, CHR_t, CHR_h, CHR_a, CHR_n, PCT_SPACE, CHR_m,
    CHR_i, CHR_n, CHR_e, PCT_PERIOD, PCT_PERIOD, PCT_PERIOD, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_170F[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// ...I believe his name {newline}{endline}
static s16 scenario_text_1727[] = {
    PCT_PERIOD, PCT_PERIOD, PCT_PERIOD, CHR_I, PCT_SPACE, CHR_b, CHR_e, CHR_l, CHR_i, CHR_e,
    CHR_v, CHR_e, PCT_SPACE, CHR_h, CHR_i, CHR_s, PCT_SPACE, CHR_n, CHR_a, CHR_m,
    CHR_e, PCT_SPACE, CTR_NEWLINE, CTR_ENDLINE
};

// was [{em-yellow}Kihachi{/em}].{button}{end}{endline}
static s16 scenario_text_1753[] = {
    CHR_w, CHR_a, CHR_s, PCT_SPACE, PCT_LBRACKET, CTR_EM_YELLOW, CHR_K, CHR_i, CHR_h, CHR_a,
    CHR_c, CHR_h, CHR_i, CTR_CLOSE_EM, PCT_RBRACKET, PCT_PERIOD, CTR_BUTTON, CTR_END, CTR_ENDLINE
};

// {begin}{endline}
static s16 scenario_text_178B[] = {
    CTR_BEGIN, CTR_ENDLINE
};

// Yae:Where could we find{newline}{endline}
static s16 scenario_text_179F[] = {
    CHR_Y, CHR_a, CHR_e, PCT_COLON, CHR_W, CHR_h, CHR_e, CHR_r, CHR_e, PCT_SPACE,
    CHR_c, CHR_o, CHR_u, CHR_l, CHR_d, PCT_SPACE, CHR_w, CHR_e, PCT_SPACE, CHR_f,
    CHR_i, CHR_n, CHR_d, CTR_NEWLINE, CTR_ENDLINE
};

//       this {em-yellow}Mr. Kihachi{/em}?{button}{end}{endline}
static s16 scenario_text_17CC[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_t, CHR_h, CHR_i, CHR_s,
    PCT_SPACE, CTR_EM_YELLOW, CHR_M, CHR_r, PCT_PERIOD, PCT_SPACE, CHR_K, CHR_i, CHR_h, CHR_a,
    CHR_c, CHR_h, CHR_i, CTR_CLOSE_EM, PCT_QUESTION, CTR_BUTTON, CTR_END, CTR_ENDLINE
};

// {begin}{endline}
static s16 scenario_text_180D[] = {
    CTR_BEGIN, CTR_ENDLINE
};

// Benkei:He lives on {newline}{endline}
static s16 scenario_text_1821[] = {
    CHR_B, CHR_e, CHR_n, CHR_k, CHR_e, CHR_i, PCT_COLON, CHR_H, CHR_e, PCT_SPACE,
    CHR_l, CHR_i, CHR_v, CHR_e, CHR_s, PCT_SPACE, CHR_o, CHR_n, PCT_SPACE, CTR_NEWLINE,
    CTR_ENDLINE
};

//       the [{em-yellow}Center Pond{/em}]{newline}{endline}
static s16 scenario_text_184A[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE,
    PCT_LBRACKET, CTR_EM_YELLOW, CHR_C, CHR_e, CHR_n, CHR_t, CHR_e, CHR_r, PCT_SPACE, CHR_P,
    CHR_o, CHR_n, CHR_d, CTR_CLOSE_EM, PCT_RBRACKET, CTR_NEWLINE, CTR_ENDLINE
};

//       of Zazen Town!{endline}
static s16 scenario_text_1887[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_o, CHR_f, PCT_SPACE, CHR_Z,
    CHR_a, CHR_z, CHR_e, CHR_n, PCT_SPACE, CHR_T, CHR_o, CHR_w, CHR_n, PCT_EXCLAMATION,
    CTR_ENDLINE
};

// {waitinput}{end}{endline}
static s16 scenario_text_18A8[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE
};

// Address: @2e34

// {begin}{endline}
static s16 scenario_text_18C5[] = {
    CTR_BEGIN, CTR_ENDLINE
};

// Benkei:Hmmm... {newline}{endline}
static s16 scenario_text_18D9[] = {
    CHR_B, CHR_e, CHR_n, CHR_k, CHR_e, CHR_i, PCT_COLON, CHR_H, CHR_m, CHR_m,
    CHR_m, PCT_PERIOD, PCT_PERIOD, PCT_PERIOD, PCT_SPACE, CTR_NEWLINE, CTR_ENDLINE
};

//       I can't lose to {em-yellow}Kihachi{/em}!{button}{endline}
static s16 scenario_text_18FE[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_I, PCT_SPACE, CHR_c, CHR_a,
    CHR_n, PCT_APOSTROPHE, CHR_t, PCT_SPACE, CHR_l, CHR_o, CHR_s, CHR_e, PCT_SPACE, CHR_t,
    CHR_o, PCT_SPACE, CTR_EM_YELLOW, CHR_K, CHR_i, CHR_h, CHR_a, CHR_c, CHR_h, CHR_i,
    CTR_CLOSE_EM, PCT_EXCLAMATION, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_1941[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// I must build on my collection!{endline}
static s16 scenario_text_1959[] = {
    CHR_I, PCT_SPACE, CHR_m, CHR_u, CHR_s, CHR_t, PCT_SPACE, CHR_b, CHR_u, CHR_i,
    CHR_l, CHR_d, PCT_SPACE, CHR_o, CHR_n, PCT_SPACE, CHR_m, CHR_y, PCT_SPACE, CHR_c,
    CHR_o, CHR_l, CHR_l, CHR_e, CHR_c, CHR_t, CHR_i, CHR_o, CHR_n, PCT_EXCLAMATION,
    CTR_ENDLINE
};

// {waitinput}{end}{endline}
static s16 scenario_text_1984[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE
};

extern s32 scenario_code_message_30c_1cd8[];
extern s32 scenario_code_message_30c_1cd80[];
extern s32 scenario_code_message_30c_1cd81[];
extern s32 scenario_code_message_30c_1cd82[];
extern s32 scenario_code_message_30c_1cd83[];
extern s32 scenario_code_message_30c_1e00[];
extern s32 scenario_code_message_30c_1e34[];
extern s32 scenario_code_message_30c_1e68[];
extern s32 scenario_code_message_30c_1ebc[];
extern s32 scenario_code_message_30c_20c0[];
extern s32 scenario_code_message_30c_21d4[];
extern s32 scenario_code_message_30c_2280[];
extern s32 scenario_code_message_30c_22ec[];
extern s32 scenario_code_message_30c_28d8[];
extern s32 scenario_code_message_30c_2924[];
extern s32 scenario_code_message_30c_2998[];
extern s32 scenario_code_message_30c_2a9c[];
extern s32 scenario_code_message_30c_2b00[];
extern s32 scenario_code_message_30c_2b64[];
extern s32 scenario_code_message_30c_2bc8[];
extern s32 scenario_code_message_30c_2e34[];

s32 scenario_code_message_30c_1cd8[] = {

    // Address: @1cd8

    // 1cd8: Unset Flag 07a (Started Benkei/Mermaid Minigame)
    CFG, 0x7A,

    // 1d40: If Flag 034 (Met Benkei), Jump To @1cd81
    // Jump if flag 0x34 is SET to @1cd81
    JFS, 0x34, (s32)&scenario_code_message_30c_1cd81,

    // 10000: Jump To @1cd80 (Introduction)
    JMP, (s32)&scenario_code_message_30c_1cd80,

    // 10000: Jump To @1cd80 (Introduction)
    JMP, (s32)&scenario_code_message_30c_1cd80,

    // End scenario script
    END,
};

s32 scenario_code_message_30c_1cd81[] = {

    // Address: @1cd81

    // 1d04: If Flag 033 (Defeated Benkei), Jump To @1cd83
    // Jump if flag 0x33 is SET to @1cd83
    JFS, 0x33, (s32)&scenario_code_message_30c_1cd83,

    // 1d34: If Flag 029 (Obtained Achilles' Heel), Jump To @1cd82
    // Jump if flag 0x29 is SET to @1cd82
    JFS, 0x29, (s32)&scenario_code_message_30c_1cd82,

    // 10000: Jump To @1cd83 (Default case after meeting Benkei)
    JMP, (s32)&scenario_code_message_30c_1cd83,

    // End scenario script
    END,
};

s32 scenario_code_message_30c_1cd82[] = {

    // Address: @1cd82

    // 1d10: If Flag 069 (Won against Benkei Cutscene Flag), Jump To @22ec
    // Jump if flag 0x69 is SET to @22ec
    JFS, 0x69, (s32)&scenario_code_message_30c_22ec,

    // 1d1c: If Flag 067 (Lost to Benkei), Jump To @2280
    // Jump if flag 0x67 is SET to @2280
    JFS, 0x67, (s32)&scenario_code_message_30c_2280,

    // 1d28: If Flag 06a (Lost to Benkei Cutscene Flag), Jump To @21d4
    // Jump if flag 0x6A is SET to @21d4
    JFS, 0x6A, (s32)&scenario_code_message_30c_21d4,

    // 1d34: If Flag 029 (Obtained Achilles' Heel), Jump To @1ebc
    // Jump if flag 0x29 is SET to @1ebc
    JFS, 0x29, (s32)&scenario_code_message_30c_1ebc,

    // End scenario script
    END,
};

s32 scenario_code_message_30c_1cd83[] = {

    // Address: @1cd83

    // 1ce0: If Flag 023 (Heard about Kihachi from Benkei), Jump To @2e34
    // Jump if flag 0x23 is SET to @2e34
    JFS, 0x23, (s32)&scenario_code_message_30c_2e34,

    // UPDATED FLAG TO 0x88 to track in safety
    // 1cec: If Flag 032 (Defeated Thaisamba), Jump To @2998
    // Jump if flag 0x32 is SET to @2998
    JFS, 0x88, (s32)&scenario_code_message_30c_2998,

    // 1cf8: If Flag 00a (Heard about Zazen Dwarf), Jump To @2924
    // Jump if flag 0x0A is SET to @2924
    JFS, 0x0A, (s32)&scenario_code_message_30c_2924,

    // 1d04: If Flag 033 (Defeated Benkei), Jump To @28d8
    // Jump if flag 0x33 is SET to @28d8
    JFS, 0x33, (s32)&scenario_code_message_30c_28d8,

    // 1d40: If Flag 034 (Met Benkei), Jump To @1e68
    // Jump if flag 0x34 is SET to @1e68
    JFS, 0x34, (s32)&scenario_code_message_30c_1e68,

    // End scenario script
    END,
};

s32 scenario_code_message_30c_1cd80[] = {

    // Address: @1cd80

    // 1d4c: Write to RAM 801c7758 (Unknown)
    STW, (s32)&D_801C7758_1C8358,

    // 1d54: Store Value: 20
    WTS, 0x20,

    // 1d5c: Write to RAM 801c775c (Dialogue Window Y Pos)
    STW, (s32)&D_801C775C_1C835C,

    // 1d64: Store Value: 68
    WTS, 0x68,

    // 1d6c: Print Text
    TXT, (s32)&scenario_text_0000,

    // 1d74: Set Flag 025 (Can Talk to Ushiwaka about Benkei)
    SFG, 0x25,

    // 1d7c: Print Text
    TXT, (s32)&scenario_text_0014,

    // 1d84: Print Text
    TXT, (s32)&scenario_text_0036,

    // 1d8c: Print Text
    TXT, (s32)&scenario_text_0068,

    // 1d94: Print Text
    TXT, (s32)&scenario_text_0080,

    // 1d9c: Print Text
    TXT, (s32)&scenario_text_00B1,

    // 1da4: Print Text
    TXT, (s32)&scenario_text_0068,

    // 1dac: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // 1db4: Store Value: 1
    WTS, 0x1,

    // 1dbc: Print Text
    TXT, (s32)&scenario_text_010E,

    // 1dc4: Print Text
    TXT, (s32)&scenario_text_0132,

    // 1dcc: Begin Option Selection
    BOS,

    // 1dd0: Print Text
    TXT, (s32)&scenario_text_0162,

    // 1dd8: Jump To @1e00
    JMP, (s32)&scenario_code_message_30c_1e00,

    // 1de0: Print Text
    TXT, (s32)&scenario_text_01A3,

    // 1de8: Jump To @1e34
    JMP, (s32)&scenario_code_message_30c_1e34,

    // 1df0: End Option Selection
    EOS,

    // 1df4: Print Text
    TXT, (s32)&scenario_text_01E3,

    // 1dfc: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_30c_1e00[] = {

    // Address: @1e00

    // 1e00: Print Text
    TXT, (s32)&scenario_text_0068,

    // 1e08: Print Text
    TXT, (s32)&scenario_text_020D,

    // 1e10: Print Text
    TXT, (s32)&scenario_text_0236,

    // 1e18: Print Text
    TXT, (s32)&scenario_text_024E,

    // 1e20: Set Flag 034 (Met Benkei)
    SFG, 0x34,

    // 1e28: Print Text
    TXT, (s32)&scenario_text_01E3,

    // 1e30: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_30c_1e34[] = {

    // Address: @1e34

    // 1e34: Print Text
    TXT, (s32)&scenario_text_0068,

    // 1e3c: Print Text
    TXT, (s32)&scenario_text_02C4,

    // 1e44: Print Text
    TXT, (s32)&scenario_text_02E4,

    // 1e4c: Print Text
    TXT, (s32)&scenario_text_0315,

    // 1e54: Set Flag 034 (Met Benkei)
    SFG, 0x34,

    // 1e5c: Print Text
    TXT, (s32)&scenario_text_0330,

    // 1e64: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_30c_1e68[] = {

    // Address: @1e68

    // 1e68: Write to RAM 801c7758 (Unknown)
    STW, (s32)&D_801C7758_1C8358,

    // 1e70: Store Value: 20
    WTS, 0x20,

    // 1e78: Write to RAM 801c775c (Dialogue Window Y Pos)
    STW, (s32)&D_801C775C_1C835C,

    // 1e80: Store Value: 68
    WTS, 0x68,

    // 1e88: Print Text
    TXT, (s32)&scenario_text_0000,

    // 1e90: Print Text
    TXT, (s32)&scenario_text_0361,

    // 1e98: Print Text
    TXT, (s32)&scenario_text_0068,

    // 1ea0: Print Text
    TXT, (s32)&scenario_text_03AA,

    // 1ea8: Print Text
    TXT, (s32)&scenario_text_03E1,

    // 1eb0: Print Text
    TXT, (s32)&scenario_text_0330,

    // 1eb8: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_30c_1ebc[] = {

    // Address: @1ebc

    // 1ebc: Write to RAM 801c7758 (Unknown)
    STW, (s32)&D_801C7758_1C8358,

    // 1ec4: Store Value: 20
    WTS, 0x20,

    // 1ecc: Write to RAM 801c775c (Dialogue Window Y Pos)
    STW, (s32)&D_801C775C_1C835C,

    // 1ed4: Store Value: 68
    WTS, 0x68,

    // 1edc: Print Text
    TXT, (s32)&scenario_text_0000,

    // 1ee4: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // 1eec: Store Value: 1
    WTS, 0x1,

    // 1ef4: Print Text
    TXT, (s32)&scenario_text_0432,

    // 1efc: Print Text
    TXT, (s32)&scenario_text_0469,

    // 1f04: Print Text
    TXT, (s32)&scenario_text_0499,

    // 1f0c: Print Text
    TXT, (s32)&scenario_text_0068,

    // 1f14: Write to RAM 801c77d8 (Text Speed)
    STW, 0x801c77d8,

    // 1f1c: Store Value: 64
    WTS, 0x64,

    // 1f24: Write to RAM 801c7798 (Unknown)
    STW, 0x801c7798,

    // 1f2c: Store Value: 1
    WTS, 0x1,

    // 1f34: Print Text
    TXT, (s32)&scenario_text_0236,

    // 1f3c: Print Text
    TXT, (s32)&scenario_text_0502,

    // 1f44: Print Text
    TXT, (s32)&scenario_text_0068,

    // 1f4c: Write to RAM 801c77d8 (Text Speed)
    STW, 0x801c77d8,

    // 1f54: Store Value: 1
    WTS, 0x1,

    // 1f5c: Write to RAM 801c7798 (Unknown)
    STW, 0x801c7798,

    // 1f64: Store Value: 1
    WTS, 0x1,

    // 1f6c: Print Text
    TXT, (s32)&scenario_text_054B,

    // 1f74: Print Text
    TXT, (s32)&scenario_text_0578,

    // 1f7c: Print Text
    TXT, (s32)&scenario_text_0068,

    // 1f84: Print Text
    TXT, (s32)&scenario_text_05C7,

    // 1f8c: Print Text
    TXT, (s32)&scenario_text_05E7,

    // 1f94: Print Text
    TXT, (s32)&scenario_text_0068,

    // 1f9c: Write to RAM 801c77d8 (Text Speed)
    STW, 0x801c77d8,

    // 1fa4: Store Value: 64
    WTS, 0x64,

    // 1fac: Write to RAM 801c7798 (Unknown)
    STW, 0x801c7798,

    // 1fb4: Store Value: 1
    WTS, 0x1,

    // 1fbc: Print Text
    TXT, (s32)&scenario_text_0236,

    // 1fc4: Print Text
    TXT, (s32)&scenario_text_0653,

    // 1fcc: Write to RAM 801c7758 (Unknown)
    STW, (s32)&D_801C7758_1C8358,

    // 1fd4: Store Value: 20
    WTS, 0x20,

    // 1fdc: Write to RAM 801c775c (Dialogue Window Y Pos)
    STW, (s32)&D_801C775C_1C835C,

    // 1fe4: Store Value: 48
    WTS, 0x48,

    // 1fec: Write to RAM 801c7768 (Dialogue Window Style)
    STW, (s32)&D_801C7768_1C8368,

    // 1ff4: Store Value: 0
    WTS, 0x0,

    // 1ffc: Write to RAM 8007785c (Dialogue Portrait Character)
    STW, (s32)&D_8007785C_7845C,

    // 2004: Store Value: 14
    WTS, 0x14,

    // 200c: Print Text
    TXT, (s32)&scenario_text_0000,

    // 2014: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // 201c: Store Value: 1
    WTS, 0x1,

    // 2024: Write to RAM 801c77d8 (Text Speed)
    STW, 0x801c77d8,

    // 202c: Store Value: 1
    WTS, 0x1,

    // 2034: Write to RAM 801c7798 (Unknown)
    STW, 0x801c7798,

    // 203c: Store Value: 1
    WTS, 0x1,

    // 2044: Print Text
    TXT, (s32)&scenario_text_06C0,

    // 204c: Print Text
    TXT, (s32)&scenario_text_06EA,

    // 2054: Print Text
    TXT, (s32)&scenario_text_0068,

    // 205c: Print Text
    TXT, (s32)&scenario_text_0737,

    // 2064: Print Text
    TXT, (s32)&scenario_text_076A,

    // 206c: Print Text
    TXT, (s32)&scenario_text_07B0,

    // 2074: Print Text
    TXT, (s32)&scenario_text_0068,

    // 207c: Print Text
    TXT, (s32)&scenario_text_0803,

    // 2084: Print Text
    TXT, (s32)&scenario_text_0847,

    // 208c: Print Text
    TXT, (s32)&scenario_text_0891,

    // 2094: Print Text
    TXT, (s32)&scenario_text_0068,

    // 209c: Print Text
    TXT, (s32)&scenario_text_08DB,

    // 20a4: Print Text
    TXT, (s32)&scenario_text_090A,

    // 20ac: Print Text
    TXT, (s32)&scenario_text_0939,

    // 20b4: Jump To @20c0
    JMP, (s32)&scenario_code_message_30c_20c0,

    // 20bc: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_30c_20c0[] = {

    // Address: @20c0

    // 20c0: Write to RAM 801c7768 (Dialogue Window Style)
    STW, (s32)&D_801C7768_1C8368,

    // 20c8: Store Value: 1
    WTS, 0x1,

    // 20d0: Write to RAM 8007785c (Dialogue Portrait Character)
    STW, (s32)&D_8007785C_7845C,

    // 20d8: Store Value: 100
    WTS, 0x100,

    // 20e0: Write to RAM 801c7758 (Unknown)
    STW, (s32)&D_801C7758_1C8358,

    // 20e8: Store Value: 20
    WTS, 0x20,

    // 20f0: Write to RAM 801c775c (Dialogue Window Y Pos)
    STW, (s32)&D_801C775C_1C835C,

    // 20f8: Store Value: 68
    WTS, 0x68,

    // 2100: Print Text
    TXT, (s32)&scenario_text_0000,

    // 2108: Print Text
    TXT, (s32)&scenario_text_0068,

    // 2110: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // 2118: Store Value: 1
    WTS, 0x1,

    // 2120: Print Text
    TXT, (s32)&scenario_text_09A5,

    // 2128: Write to RAM 801c77d8 (Text Speed)
    STW, 0x801c77d8,

    // 2130: Store Value: 64
    WTS, 0x64,

    // 2138: Write to RAM 801c7798 (Unknown)
    STW, 0x801c7798,

    // 2140: Store Value: 1
    WTS, 0x1,

    // 2148: Print Text
    TXT, (s32)&scenario_text_0236,

    // 2150: Print Text
    TXT, (s32)&scenario_text_09E4,

    // 2158: Write to RAM 801c7740 (Scratch)
    STW, (s32)&D_801C7740_1C8340,

    // 2160: Store Value: 292
    WTS, 0x292,

    // 2168: Execute Code: 8003f608 (Play Sound)
    ESR, (s32)&func_8003F608_40208,

    // 2170: Write to RAM 801c7740 (Scratch)
    STW, (s32)&D_801C7740_1C8340,

    // 2178: Store Value: 7
    WTS, 0x7,

    // 2180: Execute Code: 8003f608 (Play Sound)
    ESR, (s32)&func_8003F608_40208,

    // 2188: Write to RAM 801c7740 (Scratch)
    STW, (s32)&D_801C7740_1C8340,

    // 2190: Store Value: 2d
    WTS, 0x2D,

    // 2198: Execute Code: 8003f460 (Wait For Timer)
    ESR, (s32)&func_8003F460_40060,

    // 21a0: Write to RAM 801c7740 (Scratch)
    STW, (s32)&D_801C7740_1C8340,

    // 21a8: Store Value: 52
    WTS, 0x52,

    // 21b0: Execute Code: 8003f608 (Play Sound)
    ESR, (s32)&func_8003F608_40208,

    // 21b8: Unset Flag 067 (Lost to Benkei)
    CFG, 0x67,

    // 21c0: Set Flag 07a (Started Benkei/Mermaid Minigame)
    SFG, 0x7A,

    // 21c8: Print Text
    TXT, (s32)&scenario_text_01E3,

    // 21d0: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_30c_21d4[] = {

    // Address: @21d4

    // 21d4: Write to RAM 801c7740 (Scratch)
    STW, (s32)&D_801C7740_1C8340,

    // 21dc: Store Value: 7
    WTS, 0x7,

    // 21e4: Execute Code: 8003f608 (Play Sound)
    ESR, (s32)&func_8003F608_40208,

    // 21ec: Write to RAM 801c7758 (Unknown)
    STW, (s32)&D_801C7758_1C8358,

    // 21f4: Store Value: 20
    WTS, 0x20,

    // 21fc: Write to RAM 801c775c (Dialogue Window Y Pos)
    STW, (s32)&D_801C775C_1C835C,

    // 2204: Store Value: 68
    WTS, 0x68,

    // 220c: Print Text
    TXT, (s32)&scenario_text_0000,

    // 2214: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // 221c: Store Value: 1
    WTS, 0x1,

    // 2224: Print Text
    TXT, (s32)&scenario_text_0A69,

    // 222c: Print Text
    TXT, (s32)&scenario_text_0A8F,

    // 2234: Print Text
    TXT, (s32)&scenario_text_0AC2,

    // 223c: Set Flag 067 (Lost to Benkei)
    SFG, 0x67,

    // 2244: Write to RAM 801c7740 (Scratch)
    STW, (s32)&D_801C7740_1C8340,

    // 224c: Store Value: 3c
    WTS, 0x3C,

    // 2254: Execute Code: 8003f460 (Wait For Timer)
    ESR, (s32)&func_8003F460_40060,

    // 225c: Print Text
    TXT, (s32)&scenario_text_01E3,

    // 2264: Write to RAM 801c7740 (Scratch)
    STW, (s32)&D_801C7740_1C8340,

    // 226c: Store Value: 6b
    WTS, 0x6B,

    // 2274: Execute Code: 8003f608 (Play Sound)
    ESR, (s32)&func_8003F608_40208,

    // 227c: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_30c_2280[] = {

    // Address: @2280

    // 2280: Write to RAM 801c7758 (Unknown)
    STW, (s32)&D_801C7758_1C8358,

    // 2288: Store Value: 20
    WTS, 0x20,

    // 2290: Write to RAM 801c775c (Dialogue Window Y Pos)
    STW, (s32)&D_801C775C_1C835C,

    // 2298: Store Value: 68
    WTS, 0x68,

    // 22a0: Print Text
    TXT, (s32)&scenario_text_0000,

    // 22a8: Print Text
    TXT, (s32)&scenario_text_0B0D,

    // 22b0: Print Text
    TXT, (s32)&scenario_text_0B42,

    // 22b8: Begin Option Selection
    BOS,

    // 22bc: Print Text
    TXT, (s32)&scenario_text_0B72,

    // 22c4: Jump To @20c0
    JMP, (s32)&scenario_code_message_30c_20c0,

    // 22cc: Print Text
    TXT, (s32)&scenario_text_0BAF,

    // 22d4: Jump To @1e00
    JMP, (s32)&scenario_code_message_30c_1e00,

    // 22dc: End Option Selection
    EOS,

    // 22e0: Print Text
    TXT, (s32)&scenario_text_01E3,

    // 22e8: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_30c_22ec[] = {

    // Address: @22ec

    // 22ec: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // 22f4: Store Value: 1
    WTS, 0x1,

    // 22fc: Write to RAM 801c7740 (Scratch)
    STW, (s32)&D_801C7740_1C8340,

    // 2304: Store Value: 7
    WTS, 0x7,

    // 230c: Execute Code: 8003f608 (Play Sound)
    ESR, (s32)&func_8003F608_40208,

    // 2314: Write to RAM 801c7740 (Scratch)
    STW, (s32)&D_801C7740_1C8340,

    // 231c: Store Value: 3c
    WTS, 0x3C,

    // 2324: Execute Code: 8003f460 (Wait For Timer)
    ESR, (s32)&func_8003F460_40060,

    // 232c: Write to RAM 801c7740 (Scratch)
    STW, (s32)&D_801C7740_1C8340,

    // 2334: Store Value: 6b
    WTS, 0x6B,

    // 233c: Execute Code: 8003f608 (Play Sound)
    ESR, (s32)&func_8003F608_40208,

    // 2344: Write to RAM 801c7758 (Unknown)
    STW, (s32)&D_801C7758_1C8358,

    // 234c: Store Value: 20
    WTS, 0x20,

    // 2354: Write to RAM 801c775c (Dialogue Window Y Pos)
    STW, (s32)&D_801C775C_1C835C,

    // 235c: Store Value: 48
    WTS, 0x48,

    // 2364: Write to RAM 801c7768 (Dialogue Window Style)
    STW, (s32)&D_801C7768_1C8368,

    // 236c: Store Value: 0
    WTS, 0x0,

    // 2374: Write to RAM 8007785c (Dialogue Portrait Character)
    STW, (s32)&D_8007785C_7845C,

    // 237c: Store Value: 14
    WTS, 0x14,

    // 2384: Print Text
    TXT, (s32)&scenario_text_0000,

    // 238c: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // 2394: Store Value: 1
    WTS, 0x1,

    // 239c: Print Text
    TXT, (s32)&scenario_text_0C12,

    // 23a4: Print Text
    TXT, (s32)&scenario_text_0C3B,

    // 23ac: Print Text
    TXT, (s32)&scenario_text_0C7A,

    // 23b4: Print Text
    TXT, (s32)&scenario_text_0068,

    // 23bc: Print Text
    TXT, (s32)&scenario_text_0CC5,

    // 23c4: Print Text
    TXT, (s32)&scenario_text_0CFC,

    // 23cc: Print Text
    TXT, (s32)&scenario_text_0D40,

    // 23d4: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // 23dc: Store Value: 1
    WTS, 0x1,

    // 23e4: Write to RAM 801c7758 (Unknown)
    STW, (s32)&D_801C7758_1C8358,

    // 23ec: Store Value: 20
    WTS, 0x20,

    // 23f4: Write to RAM 801c775c (Dialogue Window Y Pos)
    STW, (s32)&D_801C775C_1C835C,

    // 23fc: Store Value: 48
    WTS, 0x48,

    // 2404: Write to RAM 801c7768 (Dialogue Window Style)
    STW, (s32)&D_801C7768_1C8368,

    // 240c: Store Value: 7
    WTS, 0x7,

    // 2414: Write to RAM 8007785c (Dialogue Portrait Character)
    STW, (s32)&D_8007785C_7845C,

    // 241c: Store Value: 2
    WTS, 0x2,

    // 2424: Print Text
    TXT, (s32)&scenario_text_0000,

    // 242c: Print Text
    TXT, (s32)&scenario_text_0D7D,

    // 2434: Print Text
    TXT, (s32)&scenario_text_0DB4,

    // 243c: Write to RAM 801c7740 (Scratch)
    STW, (s32)&D_801C7740_1C8340,

    // 2444: Store Value: 141
    WTS, 0x141,

    // 244c: Execute Code: 8003f608 (Play Sound)
    ESR, (s32)&func_8003F608_40208,

    // 2454: Print Text
    TXT, (s32)&scenario_text_0DE4,

    // 245c: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_30c_28d8[] = {

    // Address: @28d8

    // 28d8: Write to RAM 801c7758 (Unknown)
    STW, (s32)&D_801C7758_1C8358,

    // 28e0: Store Value: 20
    WTS, 0x20,

    // 28e8: Write to RAM 801c775c (Dialogue Window Y Pos)
    STW, (s32)&D_801C775C_1C835C,

    // 28f0: Store Value: 68
    WTS, 0x68,

    // 28f8: Print Text
    TXT, (s32)&scenario_text_0000,

    // 2900: Print Text
    TXT, (s32)&scenario_text_0E12,

    // 2908: Print Text
    TXT, (s32)&scenario_text_0E45,

    // 2910: Print Text
    TXT, (s32)&scenario_text_0E6A,

    // 2918: Print Text
    TXT, (s32)&scenario_text_0330,

    // 2920: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_30c_2924[] = {

    // Address: @2924

    // 2924: Write to RAM 801c7758 (Unknown)
    STW, (s32)&D_801C7758_1C8358,

    // 292c: Store Value: 20
    WTS, 0x20,

    // 2934: Write to RAM 801c775c (Dialogue Window Y Pos)
    STW, (s32)&D_801C775C_1C835C,

    // 293c: Store Value: 68
    WTS, 0x68,

    // 2944: Print Text
    TXT, (s32)&scenario_text_0000,

    // 294c: Print Text
    TXT, (s32)&scenario_text_0EBD,

    // 2954: Print Text
    TXT, (s32)&scenario_text_0EF2,

    // 295c: Print Text
    TXT, (s32)&scenario_text_0068,

    // 2964: Print Text
    TXT, (s32)&scenario_text_0F30,

    // 296c: Print Text
    TXT, (s32)&scenario_text_0F4B,

    // 2974: Print Text
    TXT, (s32)&scenario_text_0068,

    // 297c: Print Text
    TXT, (s32)&scenario_text_0F8E,

    // 2984: Print Text
    TXT, (s32)&scenario_text_0FC2,

    // 298c: Print Text
    TXT, (s32)&scenario_text_0330,

    // 2994: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_30c_2998[] = {

    // Address: @2998

    // 2998: Write to RAM 801c7758 (Unknown)
    STW, (s32)&D_801C7758_1C8358,

    // 29a0: Store Value: 20
    WTS, 0x20,

    // 29a8: Write to RAM 801c775c (Dialogue Window Y Pos)
    STW, (s32)&D_801C775C_1C835C,

    // 29b0: Store Value: 68
    WTS, 0x68,

    // 29b8: Print Text
    TXT, (s32)&scenario_text_0000,

    // 29c0: Print Text
    TXT, (s32)&scenario_text_1019,

    // 29c8: Write to RAM 801c7768 (Dialogue Window Style)
    STW, (s32)&D_801C7768_1C8368,

    // 29d0: Store Value: 7
    WTS, 0x7,

    // 29d8: Write to RAM 801c7758 (Unknown)
    STW, (s32)&D_801C7758_1C8358,

    // 29e0: Store Value: 20
    WTS, 0x20,

    // 29e8: Write to RAM 801c775c (Dialogue Window Y Pos)
    STW, (s32)&D_801C775C_1C835C,

    // 29f0: Store Value: 20
    WTS, 0x20,

    // 29f8: Execute Code: 8003f594 (Load Current Character)
    ESR, (s32)&func_8003F594_40194,

    // 2a00: Read from RAM 801c7750 (Scratch)
    LDW, 0x801c7750,

    // 2a08: Skip Next If Not Equal: 1
    SNE, 0x1,

    // 2a10: Jump To @2a9c
    JMP, (s32)&scenario_code_message_30c_2a9c,

    // 2a18: Read from RAM 801c7750 (Scratch)
    LDW, 0x801c7750,

    // 2a20: Skip Next If Not Equal: 3
    SNE, 0x3,

    // 2a28: Jump To @2b00
    JMP, (s32)&scenario_code_message_30c_2b00,

    // 2a30: Read from RAM 801c7750 (Scratch)
    LDW, 0x801c7750,

    // 2a38: Skip Next If Not Equal: 2
    SNE, 0x2,

    // 2a40: Jump To @2b64
    JMP, (s32)&scenario_code_message_30c_2b64,

    // 2a48: Write to RAM 8007785c (Dialogue Portrait Character)
    STW, (s32)&D_8007785C_7845C,

    // 2a50: Store Value: 0
    WTS, 0x0,

    // 2a58: Print Text
    TXT, (s32)&scenario_text_0000,

    // 2a60: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // 2a68: Store Value: 1
    WTS, 0x1,

    // 2a70: Print Text
    TXT, (s32)&scenario_text_105F,

    // 2a78: Print Text
    TXT, (s32)&scenario_text_0068,

    // 2a80: Print Text
    TXT, (s32)&scenario_text_10A5,

    // 2a88: Print Text
    TXT, (s32)&scenario_text_10D7,

    // 2a90: Jump To @2bc8
    JMP, (s32)&scenario_code_message_30c_2bc8,

    // 2a98: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_30c_2a9c[] = {

    // Address: @2a9c

    // 2a9c: Write to RAM 8007785c (Dialogue Portrait Character)
    STW, (s32)&D_8007785C_7845C,

    // 2aa4: Store Value: 2
    WTS, 0x2,

    // 2aac: Print Text
    TXT, (s32)&scenario_text_0000,

    // 2ab4: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // 2abc: Store Value: 1
    WTS, 0x1,

    // 2ac4: Print Text
    TXT, (s32)&scenario_text_1131,

    // 2acc: Print Text
    TXT, (s32)&scenario_text_1163,

    // 2ad4: Print Text
    TXT, (s32)&scenario_text_0068,

    // 2adc: Print Text
    TXT, (s32)&scenario_text_11AA,

    // 2ae4: Print Text
    TXT, (s32)&scenario_text_11D8,

    // 2aec: Print Text
    TXT, (s32)&scenario_text_1207,

    // 2af4: Jump To @2bc8
    JMP, (s32)&scenario_code_message_30c_2bc8,

    // 2afc: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_30c_2b00[] = {

    // Address: @2b00

    // 2b00: Write to RAM 8007785c (Dialogue Portrait Character)
    STW, (s32)&D_8007785C_7845C,

    // 2b08: Store Value: 6
    WTS, 0x6,

    // 2b10: Print Text
    TXT, (s32)&scenario_text_0000,

    // 2b18: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // 2b20: Store Value: 1
    WTS, 0x1,

    // 2b28: Print Text
    TXT, (s32)&scenario_text_125B,

    // 2b30: Print Text
    TXT, (s32)&scenario_text_128B,

    // 2b38: Print Text
    TXT, (s32)&scenario_text_12BA,

    // 2b40: Print Text
    TXT, (s32)&scenario_text_0068,

    // 2b48: Print Text
    TXT, (s32)&scenario_text_12F9,

    // 2b50: Print Text
    TXT, (s32)&scenario_text_132F,

    // 2b58: Jump To @2bc8
    JMP, (s32)&scenario_code_message_30c_2bc8,

    // 2b60: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_30c_2b64[] = {

    // Address: @2b64

    // 2b64: Write to RAM 8007785c (Dialogue Portrait Character)
    STW, (s32)&D_8007785C_7845C,

    // 2b6c: Store Value: 4
    WTS, 0x4,

    // 2b74: Print Text
    TXT, (s32)&scenario_text_0000,

    // 2b7c: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // 2b84: Store Value: 1
    WTS, 0x1,

    // 2b8c: Print Text
    TXT, (s32)&scenario_text_1389,

    // 2b94: Print Text
    TXT, (s32)&scenario_text_13BD,

    // 2b9c: Print Text
    TXT, (s32)&scenario_text_0068,

    // 2ba4: Print Text
    TXT, (s32)&scenario_text_1405,

    // 2bac: Print Text
    TXT, (s32)&scenario_text_142C,

    // 2bb4: Print Text
    TXT, (s32)&scenario_text_145D,

    // 2bbc: Jump To @2bc8
    JMP, (s32)&scenario_code_message_30c_2bc8,

    // 2bc4: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_30c_2bc8[] = {

    // Address: @2bc8

    // 2bc8: Write to RAM 801c7758 (Unknown)
    STW, (s32)&D_801C7758_1C8358,

    // 2bd0: Store Value: 20
    WTS, 0x20,

    // 2bd8: Write to RAM 801c775c (Dialogue Window Y Pos)
    STW, (s32)&D_801C775C_1C835C,

    // 2be0: Store Value: 68
    WTS, 0x68,

    // 2be8: Write to RAM 801c7768 (Dialogue Window Style)
    STW, (s32)&D_801C7768_1C8368,

    // 2bf0: Store Value: 1
    WTS, 0x1,

    // 2bf8: Write to RAM 8007785c (Dialogue Portrait Character)
    STW, (s32)&D_8007785C_7845C,

    // 2c00: Store Value: 100
    WTS, 0x100,

    // 2c08: Print Text
    TXT, (s32)&scenario_text_0000,

    // 2c10: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // 2c18: Store Value: 1
    WTS, 0x1,

    // 2c20: Print Text
    TXT, (s32)&scenario_text_14B9,

    // 2c28: Print Text
    TXT, (s32)&scenario_text_14DA,

    // 2c30: Print Text
    TXT, (s32)&scenario_text_0068,

    // 2c38: Print Text
    TXT, (s32)&scenario_text_152A,

    // 2c40: Print Text
    TXT, (s32)&scenario_text_154E,

    // 2c48: Print Text
    TXT, (s32)&scenario_text_0068,

    // 2c50: Print Text
    TXT, (s32)&scenario_text_1597,

    // 2c58: Write to RAM 801c7758 (Unknown)
    STW, (s32)&D_801C7758_1C8358,

    // 2c60: Store Value: 20
    WTS, 0x20,

    // 2c68: Write to RAM 801c775c (Dialogue Window Y Pos)
    STW, (s32)&D_801C775C_1C835C,

    // 2c70: Store Value: 20
    WTS, 0x20,

    // 2c78: Write to RAM 801c7768 (Dialogue Window Style)
    STW, (s32)&D_801C7768_1C8368,

    // 2c80: Store Value: 7
    WTS, 0x7,

    // 2c88: Write to RAM 8007785c (Dialogue Portrait Character)
    STW, (s32)&D_8007785C_7845C,

    // 2c90: Store Value: 2
    WTS, 0x2,

    // 2c98: Print Text
    TXT, (s32)&scenario_text_0000,

    // 2ca0: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // 2ca8: Store Value: 1
    WTS, 0x1,

    // 2cb0: Print Text
    TXT, (s32)&scenario_text_15F2,

    // 2cb8: Print Text
    TXT, (s32)&scenario_text_161A,

    // 2cc0: Write to RAM 801c7758 (Unknown)
    STW, (s32)&D_801C7758_1C8358,

    // 2cc8: Store Value: 20
    WTS, 0x20,

    // 2cd0: Write to RAM 801c775c (Dialogue Window Y Pos)
    STW, (s32)&D_801C775C_1C835C,

    // 2cd8: Store Value: 68
    WTS, 0x68,

    // 2ce0: Write to RAM 8007785c (Dialogue Portrait Character)
    STW, (s32)&D_8007785C_7845C,

    // 2ce8: Store Value: 100
    WTS, 0x100,

    // 2cf0: Write to RAM 801c7768 (Dialogue Window Style)
    STW, (s32)&D_801C7768_1C8368,

    // 2cf8: Store Value: 1
    WTS, 0x1,

    // 2d00: Print Text
    TXT, (s32)&scenario_text_0000,

    // 2d08: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // 2d10: Store Value: 1
    WTS, 0x1,

    // 2d18: Print Text
    TXT, (s32)&scenario_text_1665,

    // 2d20: Print Text
    TXT, (s32)&scenario_text_16AE,

    // 2d28: Print Text
    TXT, (s32)&scenario_text_16E0,

    // 2d30: Print Text
    TXT, (s32)&scenario_text_0068,

    // 2d38: Print Text
    TXT, (s32)&scenario_text_1727,

    // 2d40: Print Text
    TXT, (s32)&scenario_text_1753,

    // 2d48: Write to RAM 801c7758 (Unknown)
    STW, (s32)&D_801C7758_1C8358,

    // 2d50: Store Value: 20
    WTS, 0x20,

    // 2d58: Write to RAM 801c775c (Dialogue Window Y Pos)
    STW, (s32)&D_801C775C_1C835C,

    // 2d60: Store Value: 20
    WTS, 0x20,

    // 2d68: Write to RAM 801c7768 (Dialogue Window Style)
    STW, (s32)&D_801C7768_1C8368,

    // 2d70: Store Value: 7
    WTS, 0x7,

    // 2d78: Write to RAM 8007785c (Dialogue Portrait Character)
    STW, (s32)&D_8007785C_7845C,

    // 2d80: Store Value: 6
    WTS, 0x6,

    // 2d88: Print Text
    TXT, (s32)&scenario_text_0000,

    // 2d90: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // 2d98: Store Value: 1
    WTS, 0x1,

    // 2da0: Print Text
    TXT, (s32)&scenario_text_179F,

    // 2da8: Print Text
    TXT, (s32)&scenario_text_17CC,

    // 2db0: Write to RAM 801c7758 (Unknown)
    STW, (s32)&D_801C7758_1C8358,

    // 2db8: Store Value: 20
    WTS, 0x20,

    // 2dc0: Write to RAM 801c775c (Dialogue Window Y Pos)
    STW, (s32)&D_801C775C_1C835C,

    // 2dc8: Store Value: 68
    WTS, 0x68,

    // 2dd0: Write to RAM 8007785c (Dialogue Portrait Character)
    STW, (s32)&D_8007785C_7845C,

    // 2dd8: Store Value: 100
    WTS, 0x100,

    // 2de0: Write to RAM 801c7768 (Dialogue Window Style)
    STW, (s32)&D_801C7768_1C8368,

    // 2de8: Store Value: 1
    WTS, 0x1,

    // 2df0: Print Text
    TXT, (s32)&scenario_text_0000,

    // 2df8: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // 2e00: Store Value: 1
    WTS, 0x1,

    // 2e08: Print Text
    TXT, (s32)&scenario_text_1821,

    // 2e10: Print Text
    TXT, (s32)&scenario_text_184A,

    // 2e18: Print Text
    TXT, (s32)&scenario_text_1887,

    // 2e20: Set Flag 023 (Heard about Kihachi from Benkei)
    SFG, 0x23,

    // 2e28: Print Text
    TXT, (s32)&scenario_text_0330,

    // 2e30: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_30c_2e34[] = {

    // Address: @2e34

    // 2e34: Write to RAM 801c7758 (Unknown)
    STW, (s32)&D_801C7758_1C8358,

    // 2e3c: Store Value: 20
    WTS, 0x20,

    // 2e44: Write to RAM 801c775c (Dialogue Window Y Pos)
    STW, (s32)&D_801C775C_1C835C,

    // 2e4c: Store Value: 68
    WTS, 0x68,

    // 2e54: Print Text
    TXT, (s32)&scenario_text_0000,

    // 2e5c: Print Text
    TXT, (s32)&scenario_text_18D9,

    // 2e64: Print Text
    TXT, (s32)&scenario_text_18FE,

    // 2e6c: Print Text
    TXT, (s32)&scenario_text_0068,

    // 2e74: Print Text
    TXT, (s32)&scenario_text_1959,

    // 2e7c: Print Text
    TXT, (s32)&scenario_text_0330,

    // 2e84: End Event
    END,

    // End scenario script
    END,
};

