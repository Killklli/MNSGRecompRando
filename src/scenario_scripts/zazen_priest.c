// This file just disables the Super Jump and Mini-Ebisu paths in the Zazen Priest scenario
// This allows the player to always receive both abilities from the priest
#include "scenario.h"
#include "modding.h"
#include "recomputils.h"

#include "common.h"

// MACHI 15 - Zazen - Golden Temple - Priest (Golden Temple)
// Address: @a930

// {begin}{endline}
static s16 scenario_text_0000[] = {
    CTR_BEGIN, CTR_ENDLINE
};

// Priest:Hey you!{newline}{endline}
static s16 scenario_text_0014[] = {
    CHR_P, CHR_r, CHR_i, CHR_e, CHR_s, CHR_t, PCT_COLON, CHR_H, CHR_e, CHR_y,
    PCT_SPACE, CHR_y, CHR_o, CHR_u, PCT_EXCLAMATION, CTR_NEWLINE, CTR_ENDLINE
};

//        Traveller!{button}{endline}
static s16 scenario_text_0039[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_T, CHR_r, CHR_a,
    CHR_v, CHR_e, CHR_l, CHR_l, CHR_e, CHR_r, PCT_EXCLAMATION, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_005F[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// You were lead to this{newline}{endline}
static s16 scenario_text_0077[] = {
    CHR_Y, CHR_o, CHR_u, PCT_SPACE, CHR_w, CHR_e, CHR_r, CHR_e, PCT_SPACE, CHR_l,
    CHR_e, CHR_a, CHR_d, PCT_SPACE, CHR_t, CHR_o, PCT_SPACE, CHR_t, CHR_h, CHR_i,
    CHR_s, CTR_NEWLINE, CTR_ENDLINE
};

// {em-yellow}Golden Temple{/em}, why not listen to{newline}{endline}
static s16 scenario_text_00A2[] = {
    CTR_EM_YELLOW, CHR_G, CHR_o, CHR_l, CHR_d, CHR_e, CHR_n, PCT_SPACE, CHR_T, CHR_e,
    CHR_m, CHR_p, CHR_l, CHR_e, CTR_CLOSE_EM, PCT_COMMA, PCT_SPACE, CHR_w, CHR_h, CHR_y,
    PCT_SPACE, CHR_n, CHR_o, CHR_t, PCT_SPACE, CHR_l, CHR_i, CHR_s, CHR_t, CHR_e,
    CHR_n, PCT_SPACE, CHR_t, CHR_o, CTR_NEWLINE, CTR_ENDLINE
};

// my sermon while you're here.{button}{endline}
static s16 scenario_text_00E8[] = {
    CHR_m, CHR_y, PCT_SPACE, CHR_s, CHR_e, CHR_r, CHR_m, CHR_o, CHR_n, PCT_SPACE,
    CHR_w, CHR_h, CHR_i, CHR_l, CHR_e, PCT_SPACE, CHR_y, CHR_o, CHR_u, PCT_APOSTROPHE,
    CHR_r, CHR_e, PCT_SPACE, CHR_h, CHR_e, CHR_r, CHR_e, PCT_PERIOD, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_0119[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// I'll also include a [{em-yellow}Song{/em}] and{newline}{endline}
static s16 scenario_text_0131[] = {
    CHR_I, PCT_APOSTROPHE, CHR_l, CHR_l, PCT_SPACE, CHR_a, CHR_l, CHR_s, CHR_o, PCT_SPACE,
    CHR_i, CHR_n, CHR_c, CHR_l, CHR_u, CHR_d, CHR_e, PCT_SPACE, CHR_a, PCT_SPACE,
    PCT_LBRACKET, CTR_EM_YELLOW, CHR_S, CHR_o, CHR_n, CHR_g, CTR_CLOSE_EM, PCT_RBRACKET, PCT_SPACE, CHR_a,
    CHR_n, CHR_d, CTR_NEWLINE, CTR_ENDLINE
};

// [{em-yellow}Autograph Session{/em}]!{endline}
static s16 scenario_text_0175[] = {
    PCT_LBRACKET, CTR_EM_YELLOW, CHR_A, CHR_u, CHR_t, CHR_o, CHR_g, CHR_r, CHR_a, CHR_p,
    CHR_h, PCT_SPACE, CHR_S, CHR_e, CHR_s, CHR_s, CHR_i, CHR_o, CHR_n, CTR_CLOSE_EM,
    PCT_RBRACKET, PCT_EXCLAMATION, CTR_ENDLINE
};

// {waitinput}{end}{endline}
static s16 scenario_text_01A6[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE
};

// Address: @a9c8

// Priest:Who could it be...{button}{endline}
static s16 scenario_text_01C3[] = {
    CHR_P, CHR_r, CHR_i, CHR_e, CHR_s, CHR_t, PCT_COLON, CHR_W, CHR_h, CHR_o,
    PCT_SPACE, CHR_c, CHR_o, CHR_u, CHR_l, CHR_d, PCT_SPACE, CHR_i, CHR_t, PCT_SPACE,
    CHR_b, CHR_e, PCT_PERIOD, PCT_PERIOD, PCT_PERIOD, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_01F1[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// That would steal the secret{newline}{endline}
static s16 scenario_text_0209[] = {
    CHR_T, CHR_h, CHR_a, CHR_t, PCT_SPACE, CHR_w, CHR_o, CHR_u, CHR_l, CHR_d,
    PCT_SPACE, CHR_s, CHR_t, CHR_e, CHR_a, CHR_l, PCT_SPACE, CHR_t, CHR_h, CHR_e,
    PCT_SPACE, CHR_s, CHR_e, CHR_c, CHR_r, CHR_e, CHR_t, CTR_NEWLINE, CTR_ENDLINE
};

// {em-yellow}sweets{/em} from the [{em-yellow}Cupboard{/em}]{newline}{endline}
static s16 scenario_text_023A[] = {
    CTR_EM_YELLOW, CHR_s, CHR_w, CHR_e, CHR_e, CHR_t, CHR_s, CTR_CLOSE_EM, PCT_SPACE, CHR_f,
    CHR_r, CHR_o, CHR_m, PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE, PCT_LBRACKET, CTR_EM_YELLOW,
    CHR_C, CHR_u, CHR_p, CHR_b, CHR_o, CHR_a, CHR_r, CHR_d, CTR_CLOSE_EM, PCT_RBRACKET,
    CTR_NEWLINE, CTR_ENDLINE
};

// day after day?{endline}
static s16 scenario_text_028A[] = {
    CHR_d, CHR_a, CHR_y, PCT_SPACE, CHR_a, CHR_f, CHR_t, CHR_e, CHR_r, PCT_SPACE,
    CHR_d, CHR_a, CHR_y, PCT_QUESTION, CTR_ENDLINE
};

// {waitinput}{end}{endline}
static s16 scenario_text_02A5[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE
};

// Address: @a9fc

// Priest:So, you've come to{newline}{endline}
static s16 scenario_text_02C2[] = {
    CHR_P, CHR_r, CHR_i, CHR_e, CHR_s, CHR_t, PCT_COLON, CHR_S, CHR_o, PCT_COMMA,
    PCT_SPACE, CHR_y, CHR_o, CHR_u, PCT_APOSTROPHE, CHR_v, CHR_e, PCT_SPACE, CHR_c, CHR_o,
    CHR_m, CHR_e, PCT_SPACE, CHR_t, CHR_o, CTR_NEWLINE, CTR_ENDLINE
};

//        listen to my sermon?{newline}{endline}
static s16 scenario_text_02F1[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_l, CHR_i, CHR_s,
    CHR_t, CHR_e, CHR_n, PCT_SPACE, CHR_t, CHR_o, PCT_SPACE, CHR_m, CHR_y, PCT_SPACE,
    CHR_s, CHR_e, CHR_r, CHR_m, CHR_o, CHR_n, PCT_QUESTION, CTR_NEWLINE, CTR_ENDLINE
};

//   {em-yellow}No, no, no. Where is your son?{newline}{endline}
static s16 scenario_text_0322[] = {
    PCT_SPACE, PCT_SPACE, CTR_EM_YELLOW, CHR_N, CHR_o, PCT_COMMA, PCT_SPACE, CHR_n, CHR_o, PCT_COMMA,
    PCT_SPACE, CHR_n, CHR_o, PCT_PERIOD, PCT_SPACE, CHR_W, CHR_h, CHR_e, CHR_r, CHR_e,
    PCT_SPACE, CHR_i, CHR_s, PCT_SPACE, CHR_y, CHR_o, CHR_u, CHR_r, PCT_SPACE, CHR_s,
    CHR_o, CHR_n, PCT_QUESTION, CTR_NEWLINE, CTR_ENDLINE
};

//   {em-yellow}We could save that for next...{newline}{endline}
static s16 scenario_text_0363[] = {
    PCT_SPACE, PCT_SPACE, CTR_EM_YELLOW, CHR_W, CHR_e, PCT_SPACE, CHR_c, CHR_o, CHR_u, CHR_l,
    CHR_d, PCT_SPACE, CHR_s, CHR_a, CHR_v, CHR_e, PCT_SPACE, CHR_t, CHR_h, CHR_a,
    CHR_t, PCT_SPACE, CHR_f, CHR_o, CHR_r, PCT_SPACE, CHR_n, CHR_e, CHR_x, CHR_t,
    PCT_PERIOD, PCT_PERIOD, PCT_PERIOD, CTR_NEWLINE, CTR_ENDLINE
};

// {end}{endline}
static s16 scenario_text_03A4[] = {
    CTR_END, CTR_ENDLINE
};

// Address: @aa40

// {newwindow}{endline}
static s16 scenario_text_03B6[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// {/em}Priest:What?{newline}{endline}
static s16 scenario_text_03CE[] = {
    CTR_CLOSE_EM, CHR_P, CHR_r, CHR_i, CHR_e, CHR_s, CHR_t, PCT_COLON, CHR_W, CHR_h,
    CHR_a, CHR_t, PCT_QUESTION, CTR_NEWLINE, CTR_ENDLINE
};

//       You want to see{newline}{endline}
static s16 scenario_text_03F5[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_Y, CHR_o, CHR_u, PCT_SPACE,
    CHR_w, CHR_a, CHR_n, CHR_t, PCT_SPACE, CHR_t, CHR_o, PCT_SPACE, CHR_s, CHR_e,
    CHR_e, CTR_NEWLINE, CTR_ENDLINE
};

//       my {em-yellow}son{/em}?{button}{endline}
static s16 scenario_text_0420[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_m, CHR_y, PCT_SPACE, CTR_EM_YELLOW,
    CHR_s, CHR_o, CHR_n, CTR_CLOSE_EM, PCT_QUESTION, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_0452[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// My son's gone to watch{newline}{endline}
static s16 scenario_text_046A[] = {
    CHR_M, CHR_y, PCT_SPACE, CHR_s, CHR_o, CHR_n, PCT_APOSTROPHE, CHR_s, PCT_SPACE, CHR_g,
    CHR_o, CHR_n, CHR_e, PCT_SPACE, CHR_t, CHR_o, PCT_SPACE, CHR_w, CHR_a, CHR_t,
    CHR_c, CHR_h, CTR_NEWLINE, CTR_ENDLINE
};

// the {em-yellow}Big Sacred Fire{/em}...{button}{endline}
static s16 scenario_text_0496[] = {
    CHR_t, CHR_h, CHR_e, PCT_SPACE, CTR_EM_YELLOW, CHR_B, CHR_i, CHR_g, PCT_SPACE, CHR_S,
    CHR_a, CHR_c, CHR_r, CHR_e, CHR_d, PCT_SPACE, CHR_F, CHR_i, CHR_r, CHR_e,
    CTR_CLOSE_EM, PCT_PERIOD, PCT_PERIOD, PCT_PERIOD, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_04D1[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// You'll find him at [{em-yellow}Mt.Nyoigatake{/em}],{newline}{endline}
static s16 scenario_text_04E9[] = {
    CHR_Y, CHR_o, CHR_u, PCT_APOSTROPHE, CHR_l, CHR_l, PCT_SPACE, CHR_f, CHR_i, CHR_n,
    CHR_d, PCT_SPACE, CHR_h, CHR_i, CHR_m, PCT_SPACE, CHR_a, CHR_t, PCT_SPACE, PCT_LBRACKET,
    CTR_EM_YELLOW, CHR_M, CHR_t, PCT_PERIOD, CHR_N, CHR_y, CHR_o, CHR_i, CHR_g, CHR_a,
    CHR_t, CHR_a, CHR_k, CHR_e, CTR_CLOSE_EM, PCT_RBRACKET, PCT_COMMA, CTR_NEWLINE, CTR_ENDLINE
};

// next to this Temple.{button}{end}{endline}
static s16 scenario_text_0532[] = {
    CHR_n, CHR_e, CHR_x, CHR_t, PCT_SPACE, CHR_t, CHR_o, PCT_SPACE, CHR_t, CHR_h,
    CHR_i, CHR_s, PCT_SPACE, CHR_T, CHR_e, CHR_m, CHR_p, CHR_l, CHR_e, PCT_PERIOD,
    CTR_BUTTON, CTR_END, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_0560[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Address: @ab14

// {begin}{endline}
static s16 scenario_text_0578[] = {
    CTR_BEGIN, CTR_ENDLINE
};

// Goemon:So we'd be able to{newline}{endline}
static s16 scenario_text_058C[] = {
    CHR_G, CHR_o, CHR_e, CHR_m, CHR_o, CHR_n, PCT_COLON, CHR_S, CHR_o, PCT_SPACE,
    CHR_w, CHR_e, PCT_APOSTROPHE, CHR_d, PCT_SPACE, CHR_b, CHR_e, PCT_SPACE, CHR_a, CHR_b,
    CHR_l, CHR_e, PCT_SPACE, CHR_t, CHR_o, CTR_NEWLINE, CTR_ENDLINE
};

//       meet him if we{newline}{endline}
static s16 scenario_text_05BB[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_m, CHR_e, CHR_e, CHR_t,
    PCT_SPACE, CHR_h, CHR_i, CHR_m, PCT_SPACE, CHR_i, CHR_f, PCT_SPACE, CHR_w, CHR_e,
    CTR_NEWLINE, CTR_ENDLINE
};

//       went to {em-yellow}Mt.Nyoigatake{/em}?{button}{end}{endline}
static s16 scenario_text_05E5[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_w, CHR_e, CHR_n, CHR_t,
    PCT_SPACE, CHR_t, CHR_o, PCT_SPACE, CTR_EM_YELLOW, CHR_M, CHR_t, PCT_PERIOD, CHR_N, CHR_y,
    CHR_o, CHR_i, CHR_g, CHR_a, CHR_t, CHR_a, CHR_k, CHR_e, CTR_CLOSE_EM, PCT_QUESTION,
    CTR_BUTTON, CTR_END, CTR_ENDLINE
};

// Address: @ab50

// {begin}{endline}
static s16 scenario_text_062B[] = {
    CTR_BEGIN, CTR_ENDLINE
};

// Ebisumaru:So we could meet{newline}{endline}
static s16 scenario_text_063F[] = {
    CHR_E, CHR_b, CHR_i, CHR_s, CHR_u, CHR_m, CHR_a, CHR_r, CHR_u, PCT_COLON,
    CHR_S, CHR_o, PCT_SPACE, CHR_w, CHR_e, PCT_SPACE, CHR_c, CHR_o, CHR_u, CHR_l,
    CHR_d, PCT_SPACE, CHR_m, CHR_e, CHR_e, CHR_t, CTR_NEWLINE, CTR_ENDLINE
};

//        him at {em-yellow}Mt.Nioigatake{/em}?{button}{end}{endline}
static s16 scenario_text_066F[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_h, CHR_i, CHR_m,
    PCT_SPACE, CHR_a, CHR_t, PCT_SPACE, CTR_EM_YELLOW, CHR_M, CHR_t, PCT_PERIOD, CHR_N, CHR_i,
    CHR_o, CHR_i, CHR_g, CHR_a, CHR_t, CHR_a, CHR_k, CHR_e, CTR_CLOSE_EM, PCT_QUESTION,
    CTR_BUTTON, CTR_END, CTR_ENDLINE
};

// Address: @ab84

// {begin}{endline}
static s16 scenario_text_06B5[] = {
    CTR_BEGIN, CTR_ENDLINE
};

// Yae:So, we can meet him{newline}{endline}
static s16 scenario_text_06C9[] = {
    CHR_Y, CHR_a, CHR_e, PCT_COLON, CHR_S, CHR_o, PCT_COMMA, PCT_SPACE, CHR_w, CHR_e,
    PCT_SPACE, CHR_c, CHR_a, CHR_n, PCT_SPACE, CHR_m, CHR_e, CHR_e, CHR_t, PCT_SPACE,
    CHR_h, CHR_i, CHR_m, CTR_NEWLINE, CTR_ENDLINE
};

//       at {em-yellow}Mt.Nyoigatake{/em}?{button}{end}{endline}
static s16 scenario_text_06F6[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_a, CHR_t, PCT_SPACE, CTR_EM_YELLOW,
    CHR_M, CHR_t, PCT_PERIOD, CHR_N, CHR_y, CHR_o, CHR_i, CHR_g, CHR_a, CHR_t,
    CHR_a, CHR_k, CHR_e, CTR_CLOSE_EM, PCT_QUESTION, CTR_BUTTON, CTR_END, CTR_ENDLINE
};

// Address: @abb8

// {begin}{endline}
static s16 scenario_text_0737[] = {
    CTR_BEGIN, CTR_ENDLINE
};

// Sasuke:Then we'll have {newline}{endline}
static s16 scenario_text_074B[] = {
    CHR_S, CHR_a, CHR_s, CHR_u, CHR_k, CHR_e, PCT_COLON, CHR_T, CHR_h, CHR_e,
    CHR_n, PCT_SPACE, CHR_w, CHR_e, PCT_APOSTROPHE, CHR_l, CHR_l, PCT_SPACE, CHR_h, CHR_a,
    CHR_v, CHR_e, PCT_SPACE, CTR_NEWLINE, CTR_ENDLINE
};

//       a chance to meet him{newline}{endline}
static s16 scenario_text_0778[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_a, PCT_SPACE, CHR_c, CHR_h,
    CHR_a, CHR_n, CHR_c, CHR_e, PCT_SPACE, CHR_t, CHR_o, PCT_SPACE, CHR_m, CHR_e,
    CHR_e, CHR_t, PCT_SPACE, CHR_h, CHR_i, CHR_m, CTR_NEWLINE, CTR_ENDLINE
};

//       at {em-yellow}Mt.Nyoigatake{/em}!{button}{end}{endline}
static s16 scenario_text_07A8[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_a, CHR_t, PCT_SPACE, CTR_EM_YELLOW,
    CHR_M, CHR_t, PCT_PERIOD, CHR_N, CHR_y, CHR_o, CHR_i, CHR_g, CHR_a, CHR_t,
    CHR_a, CHR_k, CHR_e, CTR_CLOSE_EM, PCT_EXCLAMATION, CTR_BUTTON, CTR_END, CTR_ENDLINE
};

// Address: @abf4

// {begin}{endline}
static s16 scenario_text_07E9[] = {
    CTR_BEGIN, CTR_ENDLINE
};

// Priest:Tsk, Tsk...{newline}{endline}
static s16 scenario_text_07FD[] = {
    CHR_P, CHR_r, CHR_i, CHR_e, CHR_s, CHR_t, PCT_COLON, CHR_T, CHR_s, CHR_k,
    PCT_COMMA, PCT_SPACE, CHR_T, CHR_s, CHR_k, PCT_PERIOD, PCT_PERIOD, PCT_PERIOD, CTR_NEWLINE, CTR_ENDLINE
};

//       It won't be quite{newline}{endline}
static s16 scenario_text_0825[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_I, CHR_t, PCT_SPACE, CHR_w,
    CHR_o, CHR_n, PCT_APOSTROPHE, CHR_t, PCT_SPACE, CHR_b, CHR_e, PCT_SPACE, CHR_q, CHR_u,
    CHR_i, CHR_t, CHR_e, CTR_NEWLINE, CTR_ENDLINE
};

//       that simple.{button}{endline}
static s16 scenario_text_0852[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_t, CHR_h, CHR_a, CHR_t,
    PCT_SPACE, CHR_s, CHR_i, CHR_m, CHR_p, CHR_l, CHR_e, PCT_PERIOD, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_0879[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// To get to the [{em-yellow}Big Fire{/em}] of{newline}{endline}
static s16 scenario_text_0891[] = {
    CHR_T, CHR_o, PCT_SPACE, CHR_g, CHR_e, CHR_t, PCT_SPACE, CHR_t, CHR_o, PCT_SPACE,
    CHR_t, CHR_h, CHR_e, PCT_SPACE, PCT_LBRACKET, CTR_EM_YELLOW, CHR_B, CHR_i, CHR_g, PCT_SPACE,
    CHR_F, CHR_i, CHR_r, CHR_e, CTR_CLOSE_EM, PCT_RBRACKET, PCT_SPACE, CHR_o, CHR_f, CTR_NEWLINE,
    CTR_ENDLINE
};

// {em-yellow}Mt.Nyoigatake{/em}...{button}{endline}
static s16 scenario_text_08D2[] = {
    CTR_EM_YELLOW, CHR_M, CHR_t, PCT_PERIOD, CHR_N, CHR_y, CHR_o, CHR_i, CHR_g, CHR_a,
    CHR_t, CHR_a, CHR_k, CHR_e, CTR_CLOSE_EM, PCT_PERIOD, PCT_PERIOD, PCT_PERIOD, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_0907[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Only those with extensive{newline}{endline}
static s16 scenario_text_091F[] = {
    CHR_O, CHR_n, CHR_l, CHR_y, PCT_SPACE, CHR_t, CHR_h, CHR_o, CHR_s, CHR_e,
    PCT_SPACE, CHR_w, CHR_i, CHR_t, CHR_h, PCT_SPACE, CHR_e, CHR_x, CHR_t, CHR_e,
    CHR_n, CHR_s, CHR_i, CHR_v, CHR_e, CTR_NEWLINE, CTR_ENDLINE
};

// {em-yellow}training{/em}, who can {em-yellow}jump{/em}{newline}{endline}
static s16 scenario_text_094E[] = {
    CTR_EM_YELLOW, CHR_t, CHR_r, CHR_a, CHR_i, CHR_n, CHR_i, CHR_n, CHR_g, CTR_CLOSE_EM,
    PCT_COMMA, PCT_SPACE, CHR_w, CHR_h, CHR_o, PCT_SPACE, CHR_c, CHR_a, CHR_n, PCT_SPACE,
    CTR_EM_YELLOW, CHR_j, CHR_u, CHR_m, CHR_p, CTR_CLOSE_EM, CTR_NEWLINE, CTR_ENDLINE
};

// unimaginable heights,{newline}{endline}
static s16 scenario_text_099A[] = {
    CHR_u, CHR_n, CHR_i, CHR_m, CHR_a, CHR_g, CHR_i, CHR_n, CHR_a, CHR_b,
    CHR_l, CHR_e, PCT_SPACE, CHR_h, CHR_e, CHR_i, CHR_g, CHR_h, CHR_t, CHR_s,
    PCT_COMMA, CTR_NEWLINE, CTR_ENDLINE
};

// will be able to proceed.{button}{endline}
static s16 scenario_text_09C5[] = {
    CHR_w, CHR_i, CHR_l, CHR_l, PCT_SPACE, CHR_b, CHR_e, PCT_SPACE, CHR_a, CHR_b,
    CHR_l, CHR_e, PCT_SPACE, CHR_t, CHR_o, PCT_SPACE, CHR_p, CHR_r, CHR_o, CHR_c,
    CHR_e, CHR_e, CHR_d, PCT_PERIOD, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_09F2[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Do you think you could do{newline}{endline}
static s16 scenario_text_0A0A[] = {
    CHR_D, CHR_o, PCT_SPACE, CHR_y, CHR_o, CHR_u, PCT_SPACE, CHR_t, CHR_h, CHR_i,
    CHR_n, CHR_k, PCT_SPACE, CHR_y, CHR_o, CHR_u, PCT_SPACE, CHR_c, CHR_o, CHR_u,
    CHR_l, CHR_d, PCT_SPACE, CHR_d, CHR_o, CTR_NEWLINE, CTR_ENDLINE
};

// that?{newline}{endline}
static s16 scenario_text_0A39[] = {
    CHR_t, CHR_h, CHR_a, CHR_t, PCT_QUESTION, CTR_NEWLINE, CTR_ENDLINE
};

//   {em-yellow}I'll try.{newline}{endline}
static s16 scenario_text_0A54[] = {
    PCT_SPACE, PCT_SPACE, CTR_EM_YELLOW, CHR_I, PCT_APOSTROPHE, CHR_l, CHR_l, PCT_SPACE, CHR_t, CHR_r,
    CHR_y, PCT_PERIOD, CTR_NEWLINE, CTR_ENDLINE
};

//   {em-yellow}I hate training.{newline}{endline}
static s16 scenario_text_0A80[] = {
    PCT_SPACE, PCT_SPACE, CTR_EM_YELLOW, CHR_I, PCT_SPACE, CHR_h, CHR_a, CHR_t, CHR_e, PCT_SPACE,
    CHR_t, CHR_r, CHR_a, CHR_i, CHR_n, CHR_i, CHR_n, CHR_g, PCT_PERIOD, CTR_NEWLINE,
    CTR_ENDLINE
};

// {end}{endline}
static s16 scenario_text_0AB3[] = {
    CTR_END, CTR_ENDLINE
};

// Address: @acc0

// {newwindow}{endline}
static s16 scenario_text_0AC5[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// {/em}Wow!{newline}{endline}
static s16 scenario_text_0ADD[] = {
    CTR_CLOSE_EM, CHR_W, CHR_o, CHR_w, PCT_EXCLAMATION, CTR_NEWLINE, CTR_ENDLINE
};

// I admire your spirit!{button}{endline}
static s16 scenario_text_0AFC[] = {
    CHR_I, PCT_SPACE, CHR_a, CHR_d, CHR_m, CHR_i, CHR_r, CHR_e, PCT_SPACE, CHR_y,
    CHR_o, CHR_u, CHR_r, PCT_SPACE, CHR_s, CHR_p, CHR_i, CHR_r, CHR_i, CHR_t,
    PCT_EXCLAMATION, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_0B26[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Let's begin with the training{newline}{endline}
static s16 scenario_text_0B3E[] = {
    CHR_L, CHR_e, CHR_t, PCT_APOSTROPHE, CHR_s, PCT_SPACE, CHR_b, CHR_e, CHR_g, CHR_i,
    CHR_n, PCT_SPACE, CHR_w, CHR_i, CHR_t, CHR_h, PCT_SPACE, CHR_t, CHR_h, CHR_e,
    PCT_SPACE, CHR_t, CHR_r, CHR_a, CHR_i, CHR_n, CHR_i, CHR_n, CHR_g, CTR_NEWLINE,
    CTR_ENDLINE
};

// then!{button}{endline}
static s16 scenario_text_0B71[] = {
    CHR_t, CHR_h, CHR_e, CHR_n, PCT_EXCLAMATION, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_0B8B[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// In [{em-yellow}Bizen{/em}] of{newline}{endline}
static s16 scenario_text_0BA3[] = {
    CHR_I, CHR_n, PCT_SPACE, PCT_LBRACKET, CTR_EM_YELLOW, CHR_B, CHR_i, CHR_z, CHR_e, CHR_n,
    CTR_CLOSE_EM, PCT_RBRACKET, PCT_SPACE, CHR_o, CHR_f, CTR_NEWLINE, CTR_ENDLINE
};

// the Chugoku Region, there is{newline}{endline}
static s16 scenario_text_0BD6[] = {
    CHR_t, CHR_h, CHR_e, PCT_SPACE, CHR_C, CHR_h, CHR_u, CHR_g, CHR_o, CHR_k,
    CHR_u, PCT_SPACE, CHR_R, CHR_e, CHR_g, CHR_i, CHR_o, CHR_n, PCT_COMMA, PCT_SPACE,
    CHR_t, CHR_h, CHR_e, CHR_r, CHR_e, PCT_SPACE, CHR_i, CHR_s, CTR_NEWLINE, CTR_ENDLINE
};

// a {em-yellow}locked warehouse{/em}...{button}{endline}
static s16 scenario_text_0C08[] = {
    CHR_a, PCT_SPACE, CTR_EM_YELLOW, CHR_l, CHR_o, CHR_c, CHR_k, CHR_e, CHR_d, PCT_SPACE,
    CHR_w, CHR_a, CHR_r, CHR_e, CHR_h, CHR_o, CHR_u, CHR_s, CHR_e, CTR_CLOSE_EM,
    PCT_PERIOD, PCT_PERIOD, PCT_PERIOD, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_0C42[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Inside that warehouse is{newline}{endline}
static s16 scenario_text_0C5A[] = {
    CHR_I, CHR_n, CHR_s, CHR_i, CHR_d, CHR_e, PCT_SPACE, CHR_t, CHR_h, CHR_a,
    CHR_t, PCT_SPACE, CHR_w, CHR_a, CHR_r, CHR_e, CHR_h, CHR_o, CHR_u, CHR_s,
    CHR_e, PCT_SPACE, CHR_i, CHR_s, CTR_NEWLINE, CTR_ENDLINE
};

// a {em-yellow}training gym{/em}, and here is{newline}{endline}
static s16 scenario_text_0C88[] = {
    CHR_a, PCT_SPACE, CTR_EM_YELLOW, CHR_t, CHR_r, CHR_a, CHR_i, CHR_n, CHR_i, CHR_n,
    CHR_g, PCT_SPACE, CHR_g, CHR_y, CHR_m, CTR_CLOSE_EM, PCT_COMMA, PCT_SPACE, CHR_a, CHR_n,
    CHR_d, PCT_SPACE, CHR_h, CHR_e, CHR_r, CHR_e, PCT_SPACE, CHR_i, CHR_s, CTR_NEWLINE,
    CTR_ENDLINE
};

// the [{em-yellow}key{/em}] to the gym.{button}{endline}
static s16 scenario_text_0CC9[] = {
    CHR_t, CHR_h, CHR_e, PCT_SPACE, PCT_LBRACKET, CTR_EM_YELLOW, CHR_k, CHR_e, CHR_y, CTR_CLOSE_EM,
    PCT_RBRACKET, PCT_SPACE, CHR_t, CHR_o, PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE, CHR_g,
    CHR_y, CHR_m, PCT_PERIOD, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_0D03[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// OK!{newline}{endline}
static s16 scenario_text_0D1B[] = {
    CHR_O, CHR_K, PCT_EXCLAMATION, CTR_NEWLINE, CTR_ENDLINE
};

// This is the {em-yellow}key{/em} that will{newline}{endline}
static s16 scenario_text_0D34[] = {
    CHR_T, CHR_h, CHR_i, CHR_s, PCT_SPACE, CHR_i, CHR_s, PCT_SPACE, CHR_t, CHR_h,
    CHR_e, PCT_SPACE, CTR_EM_YELLOW, CHR_k, CHR_e, CHR_y, CTR_CLOSE_EM, PCT_SPACE, CHR_t, CHR_h,
    CHR_a, CHR_t, PCT_SPACE, CHR_w, CHR_i, CHR_l, CHR_l, CTR_NEWLINE, CTR_ENDLINE
};

// open the training gym.{button}{endline}
static s16 scenario_text_0D73[] = {
    CHR_o, CHR_p, CHR_e, CHR_n, PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE, CHR_t,
    CHR_r, CHR_a, CHR_i, CHR_n, CHR_i, CHR_n, CHR_g, PCT_SPACE, CHR_g, CHR_y,
    CHR_m, PCT_PERIOD, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_0D9E[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Don't give up!{button}{end}{endline}
static s16 scenario_text_0DB6[] = {
    CHR_D, CHR_o, CHR_n, PCT_APOSTROPHE, CHR_t, PCT_SPACE, CHR_g, CHR_i, CHR_v, CHR_e,
    PCT_SPACE, CHR_u, CHR_p, PCT_EXCLAMATION, CTR_BUTTON, CTR_END, CTR_ENDLINE
};

// {begin}{endline}
static s16 scenario_text_0DDE[] = {
    CTR_BEGIN, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_0DF2[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

//   {newline}{endline}
static s16 scenario_text_0E0A[] = {
    PCT_SPACE, PCT_SPACE, CTR_NEWLINE, CTR_ENDLINE
};

// Goemon and allies{newline}{endline}
static s16 scenario_text_0E22[] = {
    CHR_G, CHR_o, CHR_e, CHR_m, CHR_o, CHR_n, PCT_SPACE, CHR_a, CHR_n, CHR_d,
    PCT_SPACE, CHR_a, CHR_l, CHR_l, CHR_i, CHR_e, CHR_s, CTR_NEWLINE, CTR_ENDLINE
};

//  receive the [{em-yellow}Key to Training{/em}]!{endline}
static s16 scenario_text_0E49[] = {
    PCT_SPACE, CHR_r, CHR_e, CHR_c, CHR_e, CHR_i, CHR_v, CHR_e, PCT_SPACE, CHR_t,
    CHR_h, CHR_e, PCT_SPACE, PCT_LBRACKET, CTR_EM_YELLOW, CHR_K, CHR_e, CHR_y, PCT_SPACE, CHR_t,
    CHR_o, PCT_SPACE, CHR_T, CHR_r, CHR_a, CHR_i, CHR_n, CHR_i, CHR_n, CHR_g,
    CTR_CLOSE_EM, PCT_RBRACKET, PCT_EXCLAMATION, CTR_ENDLINE
};

// {end}{endline}
static s16 scenario_text_0E85[] = {
    CTR_END, CTR_ENDLINE
};

// Address: @ae44

// {newwindow}{endline}
static s16 scenario_text_0E97[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// {/em}Youngsters today are all{newline}{endline}
static s16 scenario_text_0EAF[] = {
    CTR_CLOSE_EM, CHR_Y, CHR_o, CHR_u, CHR_n, CHR_g, CHR_s, CHR_t, CHR_e, CHR_r,
    CHR_s, PCT_SPACE, CHR_t, CHR_o, CHR_d, CHR_a, CHR_y, PCT_SPACE, CHR_a, CHR_r,
    CHR_e, PCT_SPACE, CHR_a, CHR_l, CHR_l, CTR_NEWLINE, CTR_ENDLINE
};

// a bunch of wimps...{endline}
static s16 scenario_text_0EE2[] = {
    CHR_a, PCT_SPACE, CHR_b, CHR_u, CHR_n, CHR_c, CHR_h, PCT_SPACE, CHR_o, CHR_f,
    PCT_SPACE, CHR_w, CHR_i, CHR_m, CHR_p, CHR_s, PCT_PERIOD, PCT_PERIOD, PCT_PERIOD, CTR_ENDLINE
};

// {waitinput}{end}{endline}
static s16 scenario_text_0F02[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE
};

// Address: @ae80

// {newwindow}{endline}
static s16 scenario_text_0F1F[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// {/em}Priest:If you don't want to{newline}{endline}
static s16 scenario_text_0F37[] = {
    CTR_CLOSE_EM, CHR_P, CHR_r, CHR_i, CHR_e, CHR_s, CHR_t, PCT_COLON, CHR_I, CHR_f,
    PCT_SPACE, CHR_y, CHR_o, CHR_u, PCT_SPACE, CHR_d, CHR_o, CHR_n, PCT_APOSTROPHE, CHR_t,
    PCT_SPACE, CHR_w, CHR_a, CHR_n, CHR_t, PCT_SPACE, CHR_t, CHR_o, CTR_NEWLINE, CTR_ENDLINE
};

//       listen, just say you{newline}{endline}
static s16 scenario_text_0F6D[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_l, CHR_i, CHR_s, CHR_t,
    CHR_e, CHR_n, PCT_COMMA, PCT_SPACE, CHR_j, CHR_u, CHR_s, CHR_t, PCT_SPACE, CHR_s,
    CHR_a, CHR_y, PCT_SPACE, CHR_y, CHR_o, CHR_u, CTR_NEWLINE, CTR_ENDLINE
};

//       don't want to listen!{endline}
static s16 scenario_text_0F9D[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_d, CHR_o, CHR_n, PCT_APOSTROPHE,
    CHR_t, PCT_SPACE, CHR_w, CHR_a, CHR_n, CHR_t, PCT_SPACE, CHR_t, CHR_o, PCT_SPACE,
    CHR_l, CHR_i, CHR_s, CHR_t, CHR_e, CHR_n, PCT_EXCLAMATION, CTR_ENDLINE
};

// {waitinput}{end}{endline}
static s16 scenario_text_0FC5[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE
};

// Address: @aeac

// Priest:You'll be in{newline}{endline}
static s16 scenario_text_0FE2[] = {
    CHR_P, CHR_r, CHR_i, CHR_e, CHR_s, CHR_t, PCT_COLON, CHR_Y, CHR_o, CHR_u,
    PCT_APOSTROPHE, CHR_l, CHR_l, PCT_SPACE, CHR_b, CHR_e, PCT_SPACE, CHR_i, CHR_n, CTR_NEWLINE,
    CTR_ENDLINE
};

//       the {em-yellow}warehouse{/em} at{newline}{endline}
static s16 scenario_text_100B[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE,
    CTR_EM_YELLOW, CHR_w, CHR_a, CHR_r, CHR_e, CHR_h, CHR_o, CHR_u, CHR_s, CHR_e,
    CTR_CLOSE_EM, PCT_SPACE, CHR_a, CHR_t, CTR_NEWLINE, CTR_ENDLINE
};

//       [Bizen] during the whole{newline}{endline}
static s16 scenario_text_1047[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_LBRACKET, CHR_B, CHR_i, CHR_z,
    CHR_e, CHR_n, PCT_RBRACKET, PCT_SPACE, CHR_d, CHR_u, CHR_r, CHR_i, CHR_n, CHR_g,
    PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE, CHR_w, CHR_h, CHR_o, CHR_l, CHR_e,
    CTR_NEWLINE, CTR_ENDLINE
};

//       time you're training!{button}{endline}
static s16 scenario_text_107B[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_t, CHR_i, CHR_m, CHR_e,
    PCT_SPACE, CHR_y, CHR_o, CHR_u, PCT_APOSTROPHE, CHR_r, CHR_e, PCT_SPACE, CHR_t, CHR_r,
    CHR_a, CHR_i, CHR_n, CHR_i, CHR_n, CHR_g, PCT_EXCLAMATION, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_10AB[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// I wonder if you have the {em-yellow}guts{/em}{newline}{endline}
static s16 scenario_text_10C3[] = {
    CHR_I, PCT_SPACE, CHR_w, CHR_o, CHR_n, CHR_d, CHR_e, CHR_r, PCT_SPACE, CHR_i,
    CHR_f, PCT_SPACE, CHR_y, CHR_o, CHR_u, PCT_SPACE, CHR_h, CHR_a, CHR_v, CHR_e,
    PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE, CTR_EM_YELLOW, CHR_g, CHR_u, CHR_t, CHR_s,
    CTR_CLOSE_EM, CTR_NEWLINE, CTR_ENDLINE
};

// to overcome the training...{endline}
static s16 scenario_text_1106[] = {
    CHR_t, CHR_o, PCT_SPACE, CHR_o, CHR_v, CHR_e, CHR_r, CHR_c, CHR_o, CHR_m,
    CHR_e, PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE, CHR_t, CHR_r, CHR_a, CHR_i,
    CHR_n, CHR_i, CHR_n, CHR_g, PCT_PERIOD, PCT_PERIOD, PCT_PERIOD, CTR_ENDLINE
};

// {waitinput}{end}{endline}
static s16 scenario_text_112E[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE
};

// Address: @aef0

// Priest:Hmm!{newline}{endline}
static s16 scenario_text_114B[] = {
    CHR_P, CHR_r, CHR_i, CHR_e, CHR_s, CHR_t, PCT_COLON, CHR_H, CHR_m, CHR_m,
    PCT_EXCLAMATION, CTR_NEWLINE, CTR_ENDLINE
};

//       You're pretty good.{button}{endline}
static s16 scenario_text_116C[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_Y, CHR_o, CHR_u, PCT_APOSTROPHE,
    CHR_r, CHR_e, PCT_SPACE, CHR_p, CHR_r, CHR_e, CHR_t, CHR_t, CHR_y, PCT_SPACE,
    CHR_g, CHR_o, CHR_o, CHR_d, PCT_PERIOD, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_119A[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// To commemorate this occasion,{newline}{endline}
static s16 scenario_text_11B2[] = {
    CHR_T, CHR_o, PCT_SPACE, CHR_c, CHR_o, CHR_m, CHR_m, CHR_e, CHR_m, CHR_o,
    CHR_r, CHR_a, CHR_t, CHR_e, PCT_SPACE, CHR_t, CHR_h, CHR_i, CHR_s, PCT_SPACE,
    CHR_o, CHR_c, CHR_c, CHR_a, CHR_s, CHR_i, CHR_o, CHR_n, PCT_COMMA, CTR_NEWLINE,
    CTR_ENDLINE
};

// how about an {em-yellow}autograph{/em} from me?{endline}
static s16 scenario_text_11E5[] = {
    CHR_h, CHR_o, CHR_w, PCT_SPACE, CHR_a, CHR_b, CHR_o, CHR_u, CHR_t, PCT_SPACE,
    CHR_a, CHR_n, PCT_SPACE, CTR_EM_YELLOW, CHR_a, CHR_u, CHR_t, CHR_o, CHR_g, CHR_r,
    CHR_a, CHR_p, CHR_h, CTR_CLOSE_EM, PCT_SPACE, CHR_f, CHR_r, CHR_o, CHR_m, PCT_SPACE,
    CHR_m, CHR_e, PCT_QUESTION, CTR_ENDLINE
};

// {waitinput}{end}{endline}
static s16 scenario_text_1221[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE
};

// Address: @af24

// Priest:Have you changed your mind{newline}{endline}
static s16 scenario_text_123E[] = {
    CHR_P, CHR_r, CHR_i, CHR_e, CHR_s, CHR_t, PCT_COLON, CHR_H, CHR_a, CHR_v,
    CHR_e, PCT_SPACE, CHR_y, CHR_o, CHR_u, PCT_SPACE, CHR_c, CHR_h, CHR_a, CHR_n,
    CHR_g, CHR_e, CHR_d, PCT_SPACE, CHR_y, CHR_o, CHR_u, CHR_r, PCT_SPACE, CHR_m,
    CHR_i, CHR_n, CHR_d, CTR_NEWLINE, CTR_ENDLINE
};

//       yet about the training?{newline}{endline}
static s16 scenario_text_1275[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_y, CHR_e, CHR_t, PCT_SPACE,
    CHR_a, CHR_b, CHR_o, CHR_u, CHR_t, PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE,
    CHR_t, CHR_r, CHR_a, CHR_i, CHR_n, CHR_i, CHR_n, CHR_g, PCT_QUESTION, CTR_NEWLINE,
    CTR_ENDLINE
};

//   {em-yellow}I'll try.{newline}{endline}
static s16 scenario_text_12A8[] = {
    PCT_SPACE, PCT_SPACE, CTR_EM_YELLOW, CHR_I, PCT_APOSTROPHE, CHR_l, CHR_l, PCT_SPACE, CHR_t, CHR_r,
    CHR_y, PCT_PERIOD, CTR_NEWLINE, CTR_ENDLINE
};

//   {em-yellow}No, no, no...{newline}{endline}
static s16 scenario_text_12D4[] = {
    PCT_SPACE, PCT_SPACE, CTR_EM_YELLOW, CHR_N, CHR_o, PCT_COMMA, PCT_SPACE, CHR_n, CHR_o, PCT_COMMA,
    PCT_SPACE, CHR_n, CHR_o, PCT_PERIOD, PCT_PERIOD, PCT_PERIOD, CTR_NEWLINE, CTR_ENDLINE
};

// {end}{endline}
static s16 scenario_text_1304[] = {
    CTR_END, CTR_ENDLINE
};

extern s32 scenario_code_message_157_a930[];
extern s32 scenario_code_message_157_a9c8[];
extern s32 scenario_code_message_157_a9fc[];
extern s32 scenario_code_message_157_aa40[];
extern s32 scenario_code_message_157_ab14[];
extern s32 scenario_code_message_157_ab50[];
extern s32 scenario_code_message_157_ab84[];
extern s32 scenario_code_message_157_abb8[];
extern s32 scenario_code_message_157_abf4[];
extern s32 scenario_code_message_157_acc0[];
extern s32 scenario_code_message_157_ae44[];
extern s32 scenario_code_message_157_ae80[];
extern s32 scenario_code_message_157_aeac[];
extern s32 scenario_code_message_157_aef0[];
extern s32 scenario_code_message_157_af24[];

s32 scenario_code_message_157_a930[] = {

    // Address: @a930
    // MACHI 15 - Zazen - Golden Temple - Priest (Golden Temple)

    // a930: Print Text
    TXT, (s32)&scenario_text_0000,

    // // a938: If Flag 020 (Obtained Super Jump Magic), Jump To @aef0
    // // Jump if flag 0x20 is SET to @aef0
    // JFS, 0x20, (s32)&scenario_code_message_157_aef0,

    // a944: If Flag 027 (Obtained Key to Training from Priest), Jump To @aeac
    // Jump if flag 0x27 is SET to @aeac
    JFS, 0x27, (s32)&scenario_code_message_157_aeac,

    // a950: If Flag 026 (Rejected Priest's Training Offer), Jump To @af24
    // Jump if flag 0x26 is SET to @af24
    JFS, 0x26, (s32)&scenario_code_message_157_af24,

    // a95c: If Flag 024 (Learned Kihachi's Favorite Food), Jump To @a9fc
    // Jump if flag 0x24 is SET to @a9fc
    JFS, 0x24, (s32)&scenario_code_message_157_a9fc,

    // // a968: If Flag 031 (Obtained Mini-Ebisu Magic), Jump To @a9c8
    // // Jump if flag 0x31 is SET to @a9c8
    // JFS, 0x31, (s32)&scenario_code_message_157_a9c8,

    // a974: Print Text
    TXT, (s32)&scenario_text_0014,

    // a97c: Print Text
    TXT, (s32)&scenario_text_0039,

    // a984: Print Text
    TXT, (s32)&scenario_text_005F,

    // a98c: Print Text
    TXT, (s32)&scenario_text_0077,

    // a994: Print Text
    TXT, (s32)&scenario_text_00A2,

    // a99c: Print Text
    TXT, (s32)&scenario_text_00E8,

    // a9a4: Print Text
    TXT, (s32)&scenario_text_005F,

    // a9ac: Print Text
    TXT, (s32)&scenario_text_0131,

    // a9b4: Print Text
    TXT, (s32)&scenario_text_0175,

    // a9bc: Print Text
    TXT, (s32)&scenario_text_01A6,

    // a9c4: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_157_a9c8[] = {

    // Address: @a9c8

    // a9c8: Print Text
    TXT, (s32)&scenario_text_01C3,

    // a9d0: Print Text
    TXT, (s32)&scenario_text_005F,

    // a9d8: Print Text
    TXT, (s32)&scenario_text_0209,

    // a9e0: Print Text
    TXT, (s32)&scenario_text_023A,

    // a9e8: Print Text
    TXT, (s32)&scenario_text_028A,

    // a9f0: Print Text
    TXT, (s32)&scenario_text_01A6,

    // a9f8: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_157_a9fc[] = {

    // Address: @a9fc

    // a9fc: Print Text
    TXT, (s32)&scenario_text_02C2,

    // aa04: Print Text
    TXT, (s32)&scenario_text_02F1,

    // aa0c: Begin Option Selection
    BOS,

    // aa10: Print Text
    TXT, (s32)&scenario_text_0322,

    // aa18: Jump To @aa40
    JMP, (s32)&scenario_code_message_157_aa40,

    // aa20: Print Text
    TXT, (s32)&scenario_text_0363,

    // aa28: Jump To @ae80
    JMP, (s32)&scenario_code_message_157_ae80,

    // aa30: End Option Selection
    EOS,

    // aa34: Print Text
    TXT, (s32)&scenario_text_03A4,

    // aa3c: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_157_aa40[] = {

    // Address: @aa40

    // aa40: Print Text
    TXT, (s32)&scenario_text_005F,

    // aa48: Print Text
    TXT, (s32)&scenario_text_03CE,

    // aa50: Print Text
    TXT, (s32)&scenario_text_03F5,

    // aa58: Print Text
    TXT, (s32)&scenario_text_0420,

    // aa60: Print Text
    TXT, (s32)&scenario_text_005F,

    // aa68: Print Text
    TXT, (s32)&scenario_text_046A,

    // aa70: Print Text
    TXT, (s32)&scenario_text_0496,

    // aa78: Print Text
    TXT, (s32)&scenario_text_005F,

    // aa80: Print Text
    TXT, (s32)&scenario_text_04E9,

    // aa88: Print Text
    TXT, (s32)&scenario_text_0532,

    // aa90: Print Text
    TXT, (s32)&scenario_text_005F,

    // aa98: Write to RAM 801c7768 (Dialogue Window Style)
    STW, (s32)&D_801C7768_1C8368,

    // aaa0: Store Value: 7
    WTS, 0x7,

    // aaa8: Execute Code: 8003f594 (Load Current Character)
    ESR, (s32)&func_8003F594_40194,

    // aab0: Read from RAM 801c7750 (Scratch)
    LDW, 0x801c7750,

    // aab8: Skip Next If Not Equal: 0
    SNE, 0x0,

    // aac0: Jump To @ab14
    JMP, (s32)&scenario_code_message_157_ab14,

    // aac8: Read from RAM 801c7750 (Scratch)
    LDW, 0x801c7750,

    // aad0: Skip Next If Not Equal: 1
    SNE, 0x1,

    // aad8: Jump To @ab50
    JMP, (s32)&scenario_code_message_157_ab50,

    // aae0: Read from RAM 801c7750 (Scratch)
    LDW, 0x801c7750,

    // aae8: Skip Next If Not Equal: 3
    SNE, 0x3,

    // aaf0: Jump To @ab84
    JMP, (s32)&scenario_code_message_157_ab84,

    // aaf8: Read from RAM 801c7750 (Scratch)
    LDW, 0x801c7750,

    // ab00: Skip Next If Not Equal: 2
    SNE, 0x2,

    // ab08: Jump To @abb8
    JMP, (s32)&scenario_code_message_157_abb8,

    // ab10: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_157_ab14[] = {

    // Address: @ab14

    // ab14: Write to RAM 8007785c (Dialogue Portrait Character)
    STW, (s32)&D_8007785C_7845C,

    // ab1c: Store Value: 0
    WTS, 0x0,

    // ab24: Print Text
    TXT, (s32)&scenario_text_0000,

    // ab2c: Print Text
    TXT, (s32)&scenario_text_058C,

    // ab34: Print Text
    TXT, (s32)&scenario_text_05BB,

    // ab3c: Print Text
    TXT, (s32)&scenario_text_05E5,

    // ab44: Jump To @abf4
    JMP, (s32)&scenario_code_message_157_abf4,

    // ab4c: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_157_ab50[] = {

    // Address: @ab50

    // ab50: Write to RAM 8007785c (Dialogue Portrait Character)
    STW, (s32)&D_8007785C_7845C,

    // ab58: Store Value: 2
    WTS, 0x2,

    // ab60: Print Text
    TXT, (s32)&scenario_text_0000,

    // ab68: Print Text
    TXT, (s32)&scenario_text_063F,

    // ab70: Print Text
    TXT, (s32)&scenario_text_066F,

    // ab78: Jump To @abf4
    JMP, (s32)&scenario_code_message_157_abf4,

    // ab80: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_157_ab84[] = {

    // Address: @ab84

    // ab84: Write to RAM 8007785c (Dialogue Portrait Character)
    STW, (s32)&D_8007785C_7845C,

    // ab8c: Store Value: 6
    WTS, 0x6,

    // ab94: Print Text
    TXT, (s32)&scenario_text_0000,

    // ab9c: Print Text
    TXT, (s32)&scenario_text_06C9,

    // aba4: Print Text
    TXT, (s32)&scenario_text_06F6,

    // abac: Jump To @abf4
    JMP, (s32)&scenario_code_message_157_abf4,

    // abb4: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_157_abb8[] = {

    // Address: @abb8

    // abb8: Write to RAM 8007785c (Dialogue Portrait Character)
    STW, (s32)&D_8007785C_7845C,

    // abc0: Store Value: 4
    WTS, 0x4,

    // abc8: Print Text
    TXT, (s32)&scenario_text_0000,

    // abd0: Print Text
    TXT, (s32)&scenario_text_074B,

    // abd8: Print Text
    TXT, (s32)&scenario_text_0778,

    // abe0: Print Text
    TXT, (s32)&scenario_text_07A8,

    // abe8: Jump To @abf4
    JMP, (s32)&scenario_code_message_157_abf4,

    // abf0: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_157_abf4[] = {

    // Address: @abf4

    // abf4: Write to RAM 801c7768 (Dialogue Window Style)
    STW, (s32)&D_801C7768_1C8368,

    // abfc: Store Value: 1
    WTS, 0x1,

    // ac04: Write to RAM 8007785c (Dialogue Portrait Character)
    STW, (s32)&D_8007785C_7845C,

    // ac0c: Store Value: 100
    WTS, 0x100,

    // ac14: Print Text
    TXT, (s32)&scenario_text_0000,

    // ac1c: Print Text
    TXT, (s32)&scenario_text_07FD,

    // ac24: Print Text
    TXT, (s32)&scenario_text_0825,

    // ac2c: Print Text
    TXT, (s32)&scenario_text_0852,

    // ac34: Print Text
    TXT, (s32)&scenario_text_005F,

    // ac3c: Print Text
    TXT, (s32)&scenario_text_0891,

    // ac44: Print Text
    TXT, (s32)&scenario_text_08D2,

    // ac4c: Print Text
    TXT, (s32)&scenario_text_005F,

    // ac54: Print Text
    TXT, (s32)&scenario_text_091F,

    // ac5c: Print Text
    TXT, (s32)&scenario_text_094E,

    // ac64: Print Text
    TXT, (s32)&scenario_text_099A,

    // ac6c: Print Text
    TXT, (s32)&scenario_text_09C5,

    // ac74: Print Text
    TXT, (s32)&scenario_text_005F,

    // ac7c: Print Text
    TXT, (s32)&scenario_text_0A0A,

    // ac84: Print Text
    TXT, (s32)&scenario_text_0A39,

    // ac8c: Begin Option Selection
    BOS,

    // ac90: Print Text
    TXT, (s32)&scenario_text_0A54,

    // ac98: Jump To @acc0
    JMP, (s32)&scenario_code_message_157_acc0,

    // aca0: Print Text
    TXT, (s32)&scenario_text_0A80,

    // aca8: Jump To @ae44
    JMP, (s32)&scenario_code_message_157_ae44,

    // acb0: End Option Selection
    EOS,

    // acb4: Print Text
    TXT, (s32)&scenario_text_03A4,

    // acbc: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_157_acc0[] = {

    // Address: @acc0

    // acc0: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // acc8: Store Value: 1
    WTS, 0x1,

    // acd0: Print Text
    TXT, (s32)&scenario_text_005F,

    // acd8: Print Text
    TXT, (s32)&scenario_text_0ADD,

    // ace0: Print Text
    TXT, (s32)&scenario_text_0AFC,

    // ace8: Print Text
    TXT, (s32)&scenario_text_005F,

    // acf0: Print Text
    TXT, (s32)&scenario_text_0B3E,

    // acf8: Print Text
    TXT, (s32)&scenario_text_0B71,

    // ad00: Print Text
    TXT, (s32)&scenario_text_005F,

    // ad08: Print Text
    TXT, (s32)&scenario_text_0BA3,

    // ad10: Print Text
    TXT, (s32)&scenario_text_0BD6,

    // ad18: Print Text
    TXT, (s32)&scenario_text_0C08,

    // ad20: Print Text
    TXT, (s32)&scenario_text_005F,

    // ad28: Print Text
    TXT, (s32)&scenario_text_0C5A,

    // ad30: Print Text
    TXT, (s32)&scenario_text_0C88,

    // ad38: Print Text
    TXT, (s32)&scenario_text_0CC9,

    // ad40: Print Text
    TXT, (s32)&scenario_text_005F,

    // ad48: Print Text
    TXT, (s32)&scenario_text_0D1B,

    // ad50: Print Text
    TXT, (s32)&scenario_text_0D34,

    // ad58: Print Text
    TXT, (s32)&scenario_text_0D73,

    // ad60: Print Text
    TXT, (s32)&scenario_text_005F,

    // ad68: Print Text
    TXT, (s32)&scenario_text_0DB6,

    // ad70: Write to RAM 801c7758 (Unknown)
    STW, (s32)&D_801C7758_1C8358,

    // ad78: Store Value: 20
    WTS, 0x20,

    // ad80: Write to RAM 801c775c (Dialogue Window Y Pos)
    STW, (s32)&D_801C775C_1C835C,

    // ad88: Store Value: 48
    WTS, 0x48,

    // ad90: Write to RAM 801c7768 (Dialogue Window Style)
    STW, (s32)&D_801C7768_1C8368,

    // ad98: Store Value: 7
    WTS, 0x7,

    // ada0: Print Text
    TXT, (s32)&scenario_text_0000,

    // ada8: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // adb0: Store Value: 1
    WTS, 0x1,

    // adb8: Print Text
    TXT, (s32)&scenario_text_005F,

    // adc0: Write to RAM 801c7740 (Scratch)
    STW, (s32)&D_801C7740_1C8340,

    // adc8: Store Value: 14
    WTS, 0x14,

    // add0: Execute Code: 8003f608 (Play Sound)
    ESR, (s32)&func_8003F608_40208,

    // add8: Print Text
    TXT, (s32)&scenario_text_0E0A,

    // ade0: Print Text
    TXT, (s32)&scenario_text_0E22,

    // ade8: Print Text
    TXT, (s32)&scenario_text_0E49,

    // adf0: Write to RAM 8015c710 (Obtained Key to Training)
    STW, 0x8015c710,

    // adf8: Store Value: 1
    WTS, 0x1,

    // ae00: Set Flag 027 (Obtained Key to Training from Priest)
    SFG, 0x27,

    // ae08: Write to RAM 801c7740 (Scratch)
    STW, (s32)&D_801C7740_1C8340,

    // ae10: Store Value: 96
    WTS, 0x96,

    // ae18: Execute Code: 8003f460 (Wait For Timer)
    ESR, (s32)&func_8003F460_40060,

    // ae20: Print Text
    TXT, (s32)&scenario_text_03A4,

    // ae28: Write to RAM 801c7740 (Scratch)
    STW, (s32)&D_801C7740_1C8340,

    // ae30: Store Value: 6b
    WTS, 0x6B,

    // ae38: Execute Code: 8003f608 (Play Sound)
    ESR, (s32)&func_8003F608_40208,

    // ae40: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_157_ae44[] = {

    // Address: @ae44

    // ae44: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // ae4c: Store Value: 1
    WTS, 0x1,

    // ae54: Print Text
    TXT, (s32)&scenario_text_005F,

    // ae5c: Print Text
    TXT, (s32)&scenario_text_0EAF,

    // ae64: Print Text
    TXT, (s32)&scenario_text_0EE2,

    // ae6c: Set Flag 026 (Rejected Priest's Training Offer)
    SFG, 0x26,

    // ae74: Print Text
    TXT, (s32)&scenario_text_01A6,

    // ae7c: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_157_ae80[] = {

    // Address: @ae80

    // ae80: Print Text
    TXT, (s32)&scenario_text_005F,

    // ae88: Print Text
    TXT, (s32)&scenario_text_0F37,

    // ae90: Print Text
    TXT, (s32)&scenario_text_0F6D,

    // ae98: Print Text
    TXT, (s32)&scenario_text_0F9D,

    // aea0: Print Text
    TXT, (s32)&scenario_text_01A6,

    // aea8: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_157_aeac[] = {

    // Address: @aeac

    // aeac: Print Text
    TXT, (s32)&scenario_text_0FE2,

    // aeb4: Print Text
    TXT, (s32)&scenario_text_100B,

    // aebc: Print Text
    TXT, (s32)&scenario_text_1047,

    // aec4: Print Text
    TXT, (s32)&scenario_text_107B,

    // aecc: Print Text
    TXT, (s32)&scenario_text_005F,

    // aed4: Print Text
    TXT, (s32)&scenario_text_10C3,

    // aedc: Print Text
    TXT, (s32)&scenario_text_1106,

    // aee4: Print Text
    TXT, (s32)&scenario_text_01A6,

    // aeec: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_157_aef0[] = {

    // Address: @aef0

    // aef0: Print Text
    TXT, (s32)&scenario_text_114B,

    // aef8: Print Text
    TXT, (s32)&scenario_text_116C,

    // af00: Print Text
    TXT, (s32)&scenario_text_005F,

    // af08: Print Text
    TXT, (s32)&scenario_text_11B2,

    // af10: Print Text
    TXT, (s32)&scenario_text_11E5,

    // af18: Print Text
    TXT, (s32)&scenario_text_01A6,

    // af20: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_157_af24[] = {

    // Address: @af24

    // af24: Print Text
    TXT, (s32)&scenario_text_123E,

    // af2c: Print Text
    TXT, (s32)&scenario_text_1275,

    // af34: Begin Option Selection
    BOS,

    // af38: Print Text
    TXT, (s32)&scenario_text_0A54,

    // af40: Jump To @acc0
    JMP, (s32)&scenario_code_message_157_acc0,

    // af48: Print Text
    TXT, (s32)&scenario_text_12D4,

    // af50: Jump To @ae44
    JMP, (s32)&scenario_code_message_157_ae44,

    // af58: End Option Selection
    EOS,

    // af5c: Print Text
    TXT, (s32)&scenario_text_03A4,

    // af64: End Event
    END,

    // End scenario script
    END,
};

