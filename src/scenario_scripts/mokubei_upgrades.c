// Adjusts Mokubei so you can always get chain pipe even if you already got the flag to upgrade your pipe.
#include "scenario.h"
#include "modding.h"
#include "recomputils.h"
#include "scenario_replacer.h"

#include "common.h"

// SHOP 66 - Mt. Fuji - Pipe Maker's House - Mokubei (Pipe maker)
// Address: @63fc

// {begin}{endline}
static s16 scenario_text_0000[] = {
    CTR_BEGIN, CTR_ENDLINE
};

// Mokubei:Wow! {newline}{endline}
static s16 scenario_text_0014[] = {
    CHR_M, CHR_o, CHR_k, CHR_u, CHR_b, CHR_e, CHR_i, PCT_COLON, CHR_W, CHR_o,
    CHR_w, PCT_EXCLAMATION, PCT_SPACE, CTR_NEWLINE, CTR_ENDLINE
};

//      I'm impressed that you{newline}{endline}
static s16 scenario_text_0037[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_I, PCT_APOSTROPHE, CHR_m, PCT_SPACE, CHR_i,
    CHR_m, CHR_p, CHR_r, CHR_e, CHR_s, CHR_s, CHR_e, CHR_d, PCT_SPACE, CHR_t,
    CHR_h, CHR_a, CHR_t, PCT_SPACE, CHR_y, CHR_o, CHR_u, CTR_NEWLINE, CTR_ENDLINE
};

//      made it this far!{button}{endline}
static s16 scenario_text_0068[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_m, CHR_a, CHR_d, CHR_e, PCT_SPACE,
    CHR_i, CHR_t, PCT_SPACE, CHR_t, CHR_h, CHR_i, CHR_s, PCT_SPACE, CHR_f, CHR_a,
    CHR_r, PCT_EXCLAMATION, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_0093[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// What do you want from me?{newline}{endline}
static s16 scenario_text_00AB[] = {
    CHR_W, CHR_h, CHR_a, CHR_t, PCT_SPACE, CHR_d, CHR_o, PCT_SPACE, CHR_y, CHR_o,
    CHR_u, PCT_SPACE, CHR_w, CHR_a, CHR_n, CHR_t, PCT_SPACE, CHR_f, CHR_r, CHR_o,
    CHR_m, PCT_SPACE, CHR_m, CHR_e, PCT_QUESTION, CTR_NEWLINE, CTR_ENDLINE
};

//   {newline}{endline}
static s16 scenario_text_00DA[] = {
    PCT_SPACE, PCT_SPACE, CTR_NEWLINE, CTR_ENDLINE
};

//   {em-yellow}What are you doing here?{newline}{endline}
static s16 scenario_text_00F2[] = {
    PCT_SPACE, PCT_SPACE, CTR_EM_YELLOW, CHR_W, CHR_h, CHR_a, CHR_t, PCT_SPACE, CHR_a, CHR_r,
    CHR_e, PCT_SPACE, CHR_y, CHR_o, CHR_u, PCT_SPACE, CHR_d, CHR_o, CHR_i, CHR_n,
    CHR_g, PCT_SPACE, CHR_h, CHR_e, CHR_r, CHR_e, PCT_QUESTION, CTR_NEWLINE, CTR_ENDLINE
};

//   {em-yellow}Do you have a good [Pipe]?{newline}{endline}
static s16 scenario_text_012D[] = {
    PCT_SPACE, PCT_SPACE, CTR_EM_YELLOW, CHR_D, CHR_o, PCT_SPACE, CHR_y, CHR_o, CHR_u, PCT_SPACE,
    CHR_h, CHR_a, CHR_v, CHR_e, PCT_SPACE, CHR_a, PCT_SPACE, CHR_g, CHR_o, CHR_o,
    CHR_d, PCT_SPACE, PCT_LBRACKET, CHR_P, CHR_i, CHR_p, CHR_e, PCT_RBRACKET, PCT_QUESTION, CTR_NEWLINE,
    CTR_ENDLINE
};

// {end}{endline}
static s16 scenario_text_016A[] = {
    CTR_END, CTR_ENDLINE
};

// Address: @648c

// {newwindow}{endline}
static s16 scenario_text_017C[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// {/em}Mokubei:I have come to{newline}{endline}
static s16 scenario_text_0194[] = {
    CTR_CLOSE_EM, CHR_M, CHR_o, CHR_k, CHR_u, CHR_b, CHR_e, CHR_i, PCT_COLON, CHR_I,
    PCT_SPACE, CHR_h, CHR_a, CHR_v, CHR_e, PCT_SPACE, CHR_c, CHR_o, CHR_m, CHR_e,
    PCT_SPACE, CHR_t, CHR_o, CTR_NEWLINE, CTR_ENDLINE
};

//      the greatest mountain{newline}{endline}
static s16 scenario_text_01C5[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE, CHR_g,
    CHR_r, CHR_e, CHR_a, CHR_t, CHR_e, CHR_s, CHR_t, PCT_SPACE, CHR_m, CHR_o,
    CHR_u, CHR_n, CHR_t, CHR_a, CHR_i, CHR_n, CTR_NEWLINE, CTR_ENDLINE
};

//      in Japan...{button}{endline}
static s16 scenario_text_01F5[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_i, CHR_n, PCT_SPACE, CHR_J, CHR_a,
    CHR_p, CHR_a, CHR_n, PCT_PERIOD, PCT_PERIOD, PCT_PERIOD, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_021A[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// so that I could train to become{newline}{endline}
static s16 scenario_text_0232[] = {
    CHR_s, CHR_o, PCT_SPACE, CHR_t, CHR_h, CHR_a, CHR_t, PCT_SPACE, CHR_I, PCT_SPACE,
    CHR_c, CHR_o, CHR_u, CHR_l, CHR_d, PCT_SPACE, CHR_t, CHR_r, CHR_a, CHR_i,
    CHR_n, PCT_SPACE, CHR_t, CHR_o, PCT_SPACE, CHR_b, CHR_e, CHR_c, CHR_o, CHR_m,
    CHR_e, CTR_NEWLINE, CTR_ENDLINE
};

// {em-yellow}the greatest worker{/em} in Japan!{endline}
static s16 scenario_text_0267[] = {
    CTR_EM_YELLOW, CHR_t, CHR_h, CHR_e, PCT_SPACE, CHR_g, CHR_r, CHR_e, CHR_a, CHR_t,
    CHR_e, CHR_s, CHR_t, PCT_SPACE, CHR_w, CHR_o, CHR_r, CHR_k, CHR_e, CHR_r,
    CTR_CLOSE_EM, PCT_SPACE, CHR_i, CHR_n, PCT_SPACE, CHR_J, CHR_a, CHR_p, CHR_a, CHR_n,
    PCT_EXCLAMATION, CTR_ENDLINE
};

// {waitinput}{end}{endline}
static s16 scenario_text_02A1[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE
};

// Address: @64d0

// {newwindow}{endline}
static s16 scenario_text_02BE[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// {/em}Mokubei:{em-yellow}Pipe{/em}?{button}{endline}
static s16 scenario_text_02D6[] = {
    CTR_CLOSE_EM, CHR_M, CHR_o, CHR_k, CHR_u, CHR_b, CHR_e, CHR_i, PCT_COLON, CTR_EM_YELLOW,
    CHR_P, CHR_i, CHR_p, CHR_e, CTR_CLOSE_EM, PCT_QUESTION, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_030D[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Let me think... {newline}{endline}
static s16 scenario_text_0325[] = {
    CHR_L, CHR_e, CHR_t, PCT_SPACE, CHR_m, CHR_e, PCT_SPACE, CHR_t, CHR_h, CHR_i,
    CHR_n, CHR_k, PCT_PERIOD, PCT_PERIOD, PCT_PERIOD, PCT_SPACE, CTR_NEWLINE, CTR_ENDLINE
};

//    well let's see...{button}{endline}
static s16 scenario_text_034B[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_w, CHR_e, CHR_l, CHR_l, PCT_SPACE, CHR_l, CHR_e,
    CHR_t, PCT_APOSTROPHE, CHR_s, PCT_SPACE, CHR_s, CHR_e, CHR_e, PCT_PERIOD, PCT_PERIOD, PCT_PERIOD,
    CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_0374[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// ...YES!!{button}{endline}
static s16 scenario_text_038C[] = {
    PCT_PERIOD, PCT_PERIOD, PCT_PERIOD, CHR_Y, CHR_E, CHR_S, PCT_EXCLAMATION, PCT_EXCLAMATION, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_03A9[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// I know!{button}{endline}
static s16 scenario_text_03C1[] = {
    CHR_I, PCT_SPACE, CHR_k, CHR_n, CHR_o, CHR_w, PCT_EXCLAMATION, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_03DD[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Take this!{button}{endline}
static s16 scenario_text_03F5[] = {
    CHR_T, CHR_a, CHR_k, CHR_e, PCT_SPACE, CHR_t, CHR_h, CHR_i, CHR_s, PCT_EXCLAMATION,
    CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_0414[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// I'm honoured to hand you my {em-yellow}Pipe{/em}!{newline}{endline}
static s16 scenario_text_042C[] = {
    CHR_I, PCT_APOSTROPHE, CHR_m, PCT_SPACE, CHR_h, CHR_o, CHR_n, CHR_o, CHR_u, CHR_r,
    CHR_e, CHR_d, PCT_SPACE, CHR_t, CHR_o, PCT_SPACE, CHR_h, CHR_a, CHR_n, CHR_d,
    PCT_SPACE, CHR_y, CHR_o, CHR_u, PCT_SPACE, CHR_m, CHR_y, PCT_SPACE, CTR_EM_YELLOW, CHR_P,
    CHR_i, CHR_p, CHR_e, CTR_CLOSE_EM, PCT_EXCLAMATION, CTR_NEWLINE, CTR_ENDLINE
};

// It attaches to the the {em-yellow}block{/em} with{newline}{endline}
static s16 scenario_text_0473[] = {
    CHR_I, CHR_t, PCT_SPACE, CHR_a, CHR_t, CHR_t, CHR_a, CHR_c, CHR_h, CHR_e,
    CHR_s, PCT_SPACE, CHR_t, CHR_o, PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE, CHR_t,
    CHR_h, CHR_e, PCT_SPACE, CTR_EM_YELLOW, CHR_b, CHR_l, CHR_o, CHR_c, CHR_k, CTR_CLOSE_EM,
    PCT_SPACE, CHR_w, CHR_i, CHR_t, CHR_h, CTR_NEWLINE, CTR_ENDLINE
};

// the [{em-yellow}Star Mark{/em}]!{button}{end}{endline}
static s16 scenario_text_04BA[] = {
    CHR_t, CHR_h, CHR_e, PCT_SPACE, PCT_LBRACKET, CTR_EM_YELLOW, CHR_S, CHR_t, CHR_a, CHR_r,
    PCT_SPACE, CHR_M, CHR_a, CHR_r, CHR_k, CTR_CLOSE_EM, PCT_RBRACKET, PCT_EXCLAMATION, CTR_BUTTON, CTR_END,
    CTR_ENDLINE
};

// {begin}{endline}
static s16 scenario_text_04F4[] = {
    CTR_BEGIN, CTR_ENDLINE
};

//   {newline}{endline}
static s16 scenario_text_0508[] = {
    PCT_SPACE, PCT_SPACE, CTR_NEWLINE, CTR_ENDLINE
};

//  Goemon{newline}{endline}
static s16 scenario_text_0520[] = {
    PCT_SPACE, CHR_G, CHR_o, CHR_e, CHR_m, CHR_o, CHR_n, CTR_NEWLINE, CTR_ENDLINE
};

//     receives the [{em-yellow}Chain Pipe{/em}]!{newline}{endline}
static s16 scenario_text_053D[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_r, CHR_e, CHR_c, CHR_e, CHR_i, CHR_v,
    CHR_e, CHR_s, PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE, PCT_LBRACKET, CTR_EM_YELLOW, CHR_C,
    CHR_h, CHR_a, CHR_i, CHR_n, PCT_SPACE, CHR_P, CHR_i, CHR_p, CHR_e, CTR_CLOSE_EM,
    PCT_RBRACKET, PCT_EXCLAMATION, CTR_NEWLINE, CTR_ENDLINE
};

// {button}{endline}
static s16 scenario_text_0581[] = {
    CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_0596[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// With this, it is now possible to{newline}{endline}
static s16 scenario_text_05AE[] = {
    CHR_W, CHR_i, CHR_t, CHR_h, PCT_SPACE, CHR_t, CHR_h, CHR_i, CHR_s, PCT_COMMA,
    PCT_SPACE, CHR_i, CHR_t, PCT_SPACE, CHR_i, CHR_s, PCT_SPACE, CHR_n, CHR_o, CHR_w,
    PCT_SPACE, CHR_p, CHR_o, CHR_s, CHR_s, CHR_i, CHR_b, CHR_l, CHR_e, PCT_SPACE,
    CHR_t, CHR_o, CTR_NEWLINE, CTR_ENDLINE
};

// attach this to the {em-yellow}Star Mark{/em} and{newline}{endline}
static s16 scenario_text_05E4[] = {
    CHR_a, CHR_t, CHR_t, CHR_a, CHR_c, CHR_h, PCT_SPACE, CHR_t, CHR_h, CHR_i,
    CHR_s, PCT_SPACE, CHR_t, CHR_o, PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE, CTR_EM_YELLOW,
    CHR_S, CHR_t, CHR_a, CHR_r, PCT_SPACE, CHR_M, CHR_a, CHR_r, CHR_k, CTR_CLOSE_EM,
    PCT_SPACE, CHR_a, CHR_n, CHR_d, CTR_NEWLINE, CTR_ENDLINE
};

// across large gaps!{endline}
static s16 scenario_text_062A[] = {
    CHR_a, CHR_c, CHR_r, CHR_o, CHR_s, CHR_s, PCT_SPACE, CHR_l, CHR_a, CHR_r,
    CHR_g, CHR_e, PCT_SPACE, CHR_g, CHR_a, CHR_p, CHR_s, PCT_EXCLAMATION, CTR_ENDLINE
};

// {waitinput}{end}{endline}
static s16 scenario_text_0649[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE
};

// Address: @668c

// Mokubei:Train yourself well...{button}{endline}
static s16 scenario_text_0666[] = {
    CHR_M, CHR_o, CHR_k, CHR_u, CHR_b, CHR_e, CHR_i, PCT_COLON, CHR_T, CHR_r,
    CHR_a, CHR_i, CHR_n, PCT_SPACE, CHR_y, CHR_o, CHR_u, CHR_r, CHR_s, CHR_e,
    CHR_l, CHR_f, PCT_SPACE, CHR_w, CHR_e, CHR_l, CHR_l, PCT_PERIOD, PCT_PERIOD, PCT_PERIOD,
    CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_0699[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// until the girls cheer for{newline}{endline}
static s16 scenario_text_06B1[] = {
    CHR_u, CHR_n, CHR_t, CHR_i, CHR_l, PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE,
    CHR_g, CHR_i, CHR_r, CHR_l, CHR_s, PCT_SPACE, CHR_c, CHR_h, CHR_e, CHR_e,
    CHR_r, PCT_SPACE, CHR_f, CHR_o, CHR_r, CTR_NEWLINE, CTR_ENDLINE
};

// you saying{newline}{endline}
static s16 scenario_text_06E0[] = {
    CHR_y, CHR_o, CHR_u, PCT_SPACE, CHR_s, CHR_a, CHR_y, CHR_i, CHR_n, CHR_g,
    CTR_NEWLINE, CTR_ENDLINE
};

// {em-yellow}"Oh my! That Pipe you have is{newline}{endline}
static s16 scenario_text_0700[] = {
    CTR_EM_YELLOW, PCT_QUOTE, CHR_O, CHR_h, PCT_SPACE, CHR_m, CHR_y, PCT_EXCLAMATION, PCT_SPACE, CHR_T,
    CHR_h, CHR_a, CHR_t, PCT_SPACE, CHR_P, CHR_i, CHR_p, CHR_e, PCT_SPACE, CHR_y,
    CHR_o, CHR_u, PCT_SPACE, CHR_h, CHR_a, CHR_v, CHR_e, PCT_SPACE, CHR_i, CHR_s,
    CTR_NEWLINE, CTR_ENDLINE
};

//  so fashionable!"{/em}{endline}
static s16 scenario_text_073E[] = {
    PCT_SPACE, CHR_s, CHR_o, PCT_SPACE, CHR_f, CHR_a, CHR_s, CHR_h, CHR_i, CHR_o,
    CHR_n, CHR_a, CHR_b, CHR_l, CHR_e, PCT_EXCLAMATION, PCT_QUOTE, CTR_CLOSE_EM, CTR_ENDLINE
};

// {waitinput}{end}{endline}
static s16 scenario_text_0761[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE
};

// Address: @66c8

// Mokubei:Well, well, well!{newline}{endline}
static s16 scenario_text_077E[] = {
    CHR_M, CHR_o, CHR_k, CHR_u, CHR_b, CHR_e, CHR_i, PCT_COLON, CHR_W, CHR_e,
    CHR_l, CHR_l, PCT_COMMA, PCT_SPACE, CHR_w, CHR_e, CHR_l, CHR_l, PCT_COMMA, PCT_SPACE,
    CHR_w, CHR_e, CHR_l, CHR_l, PCT_EXCLAMATION, CTR_NEWLINE, CTR_ENDLINE
};

//       Long time no see!{button}{endline}
static s16 scenario_text_07AD[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_L, CHR_o, CHR_n, CHR_g,
    PCT_SPACE, CHR_t, CHR_i, CHR_m, CHR_e, PCT_SPACE, CHR_n, CHR_o, PCT_SPACE, CHR_s,
    CHR_e, CHR_e, PCT_EXCLAMATION, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_07D9[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// What now?!{newline}{endline}
static s16 scenario_text_07F1[] = {
    CHR_W, CHR_h, CHR_a, CHR_t, PCT_SPACE, CHR_n, CHR_o, CHR_w, PCT_QUESTION, PCT_EXCLAMATION,
    CTR_NEWLINE, CTR_ENDLINE
};

//   {newline}{endline}
static s16 scenario_text_0811[] = {
    PCT_SPACE, PCT_SPACE, CTR_NEWLINE, CTR_ENDLINE
};

//   {em-yellow}We've come for a cup of coffee.{newline}{endline}
static s16 scenario_text_0829[] = {
    PCT_SPACE, PCT_SPACE, CTR_EM_YELLOW, CHR_W, CHR_e, PCT_APOSTROPHE, CHR_v, CHR_e, PCT_SPACE, CHR_c,
    CHR_o, CHR_m, CHR_e, PCT_SPACE, CHR_f, CHR_o, CHR_r, PCT_SPACE, CHR_a, PCT_SPACE,
    CHR_c, CHR_u, CHR_p, PCT_SPACE, CHR_o, CHR_f, PCT_SPACE, CHR_c, CHR_o, CHR_f,
    CHR_f, CHR_e, CHR_e, PCT_PERIOD, CTR_NEWLINE, CTR_ENDLINE
};

//   {em-yellow}Please improve our [Weapons].{newline}{endline}
static s16 scenario_text_086B[] = {
    PCT_SPACE, PCT_SPACE, CTR_EM_YELLOW, CHR_P, CHR_l, CHR_e, CHR_a, CHR_s, CHR_e, PCT_SPACE,
    CHR_i, CHR_m, CHR_p, CHR_r, CHR_o, CHR_v, CHR_e, PCT_SPACE, CHR_o, CHR_u,
    CHR_r, PCT_SPACE, PCT_LBRACKET, CHR_W, CHR_e, CHR_a, CHR_p, CHR_o, CHR_n, CHR_s,
    PCT_RBRACKET, PCT_PERIOD, CTR_NEWLINE, CTR_ENDLINE
};

// {end}{endline}
static s16 scenario_text_08AB[] = {
    CTR_END, CTR_ENDLINE
};

// Address: @6724

// {newwindow}{endline}
static s16 scenario_text_08BD[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// {/em}Mokubei:Hey,{newline}{endline}
static s16 scenario_text_08D5[] = {
    CTR_CLOSE_EM, CHR_M, CHR_o, CHR_k, CHR_u, CHR_b, CHR_e, CHR_i, PCT_COLON, CHR_H,
    CHR_e, CHR_y, PCT_COMMA, CTR_NEWLINE, CTR_ENDLINE
};

//       this is {em-yellow}no{/em} coffee shop!{endline}
static s16 scenario_text_08FC[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_t, CHR_h, CHR_i, CHR_s,
    PCT_SPACE, CHR_i, CHR_s, PCT_SPACE, CTR_EM_YELLOW, CHR_n, CHR_o, CTR_CLOSE_EM, PCT_SPACE, CHR_c,
    CHR_o, CHR_f, CHR_f, CHR_e, CHR_e, PCT_SPACE, CHR_s, CHR_h, CHR_o, CHR_p,
    PCT_EXCLAMATION, CTR_ENDLINE
};

// {waitinput}{end}{endline}
static s16 scenario_text_0936[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE
};

// Address: @6748

// {newwindow}{endline}
static s16 scenario_text_0953[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// {/em}Mokubei:Hm!{newline}{endline}
static s16 scenario_text_096B[] = {
    CTR_CLOSE_EM, CHR_M, CHR_o, CHR_k, CHR_u, CHR_b, CHR_e, CHR_i, PCT_COLON, CHR_H,
    CHR_m, PCT_EXCLAMATION, CTR_NEWLINE, CTR_ENDLINE
};

//       So that's what you have{newline}{endline}
static s16 scenario_text_0991[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_S, CHR_o, PCT_SPACE, CHR_t,
    CHR_h, CHR_a, CHR_t, PCT_APOSTROPHE, CHR_s, PCT_SPACE, CHR_w, CHR_h, CHR_a, CHR_t,
    PCT_SPACE, CHR_y, CHR_o, CHR_u, PCT_SPACE, CHR_h, CHR_a, CHR_v, CHR_e, CTR_NEWLINE,
    CTR_ENDLINE
};

//       come for... okay,{button}{endline}
static s16 scenario_text_09C4[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_c, CHR_o, CHR_m, CHR_e,
    PCT_SPACE, CHR_f, CHR_o, CHR_r, PCT_PERIOD, PCT_PERIOD, PCT_PERIOD, PCT_SPACE, CHR_o, CHR_k,
    CHR_a, CHR_y, PCT_COMMA, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_09F0[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// stand back... and{newline}{endline}
static s16 scenario_text_0A08[] = {
    CHR_s, CHR_t, CHR_a, CHR_n, CHR_d, PCT_SPACE, CHR_b, CHR_a, CHR_c, CHR_k,
    PCT_PERIOD, PCT_PERIOD, PCT_PERIOD, PCT_SPACE, CHR_a, CHR_n, CHR_d, CTR_NEWLINE, CTR_ENDLINE
};

// I'll show you what my training{newline}{endline}
static s16 scenario_text_0A2F[] = {
    CHR_I, PCT_APOSTROPHE, CHR_l, CHR_l, PCT_SPACE, CHR_s, CHR_h, CHR_o, CHR_w, PCT_SPACE,
    CHR_y, CHR_o, CHR_u, PCT_SPACE, CHR_w, CHR_h, CHR_a, CHR_t, PCT_SPACE, CHR_m,
    CHR_y, PCT_SPACE, CHR_t, CHR_r, CHR_a, CHR_i, CHR_n, CHR_i, CHR_n, CHR_g,
    CTR_NEWLINE, CTR_ENDLINE
};

// has done for me...{button}{endline}
static s16 scenario_text_0A63[] = {
    CHR_h, CHR_a, CHR_s, PCT_SPACE, CHR_d, CHR_o, CHR_n, CHR_e, PCT_SPACE, CHR_f,
    CHR_o, CHR_r, PCT_SPACE, CHR_m, CHR_e, PCT_PERIOD, PCT_PERIOD, PCT_PERIOD, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_0A8A[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// {blink}{em-yellow}Aaaaaaaaaaaaaaaaauuuuuuuggghh!!{/em}{/blink}{newline}{endline}
static s16 scenario_text_0AA2[] = {
    CTR_BLINK, CTR_EM_YELLOW, CHR_A, CHR_a, CHR_a, CHR_a, CHR_a, CHR_a, CHR_a, CHR_a,
    CHR_a, CHR_a, CHR_a, CHR_a, CHR_a, CHR_a, CHR_a, CHR_a, CHR_a, CHR_u,
    CHR_u, CHR_u, CHR_u, CHR_u, CHR_u, CHR_u, CHR_g, CHR_g, CHR_g, CHR_h,
    CHR_h, PCT_EXCLAMATION, PCT_EXCLAMATION, CTR_CLOSE_EM, CTR_CLOSE_BLINK, CTR_NEWLINE, CTR_ENDLINE
};

// {waitinput}{end}{endline}
static s16 scenario_text_0AF6[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE
};

// Address: @6a08

// Mokubei:It was a good thing{newline}{endline}
static s16 scenario_text_0B13[] = {
    CHR_M, CHR_o, CHR_k, CHR_u, CHR_b, CHR_e, CHR_i, PCT_COLON, CHR_I, CHR_t,
    PCT_SPACE, CHR_w, CHR_a, CHR_s, PCT_SPACE, CHR_a, PCT_SPACE, CHR_g, CHR_o, CHR_o,
    CHR_d, PCT_SPACE, CHR_t, CHR_h, CHR_i, CHR_n, CHR_g, CTR_NEWLINE, CTR_ENDLINE
};

//       I went to Mt. Fuji to{newline}{endline}
static s16 scenario_text_0B44[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_I, PCT_SPACE, CHR_w, CHR_e,
    CHR_n, CHR_t, PCT_SPACE, CHR_t, CHR_o, PCT_SPACE, CHR_M, CHR_t, PCT_PERIOD, PCT_SPACE,
    CHR_F, CHR_u, CHR_j, CHR_i, PCT_SPACE, CHR_t, CHR_o, CTR_NEWLINE, CTR_ENDLINE
};

//       train!{button}{endline}
static s16 scenario_text_0B75[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_t, CHR_r, CHR_a, CHR_i,
    CHR_n, PCT_EXCLAMATION, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_0B96[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// But I never made a decent pipe{newline}{endline}
static s16 scenario_text_0BAE[] = {
    CHR_B, CHR_u, CHR_t, PCT_SPACE, CHR_I, PCT_SPACE, CHR_n, CHR_e, CHR_v, CHR_e,
    CHR_r, PCT_SPACE, CHR_m, CHR_a, CHR_d, CHR_e, PCT_SPACE, CHR_a, PCT_SPACE, CHR_d,
    CHR_e, CHR_c, CHR_e, CHR_n, CHR_t, PCT_SPACE, CHR_p, CHR_i, CHR_p, CHR_e,
    CTR_NEWLINE, CTR_ENDLINE
};

// before...{endline}
static s16 scenario_text_0BE2[] = {
    CHR_b, CHR_e, CHR_f, CHR_o, CHR_r, CHR_e, PCT_PERIOD, PCT_PERIOD, PCT_PERIOD, CTR_ENDLINE
};

// {waitinput}{end}{endline}
static s16 scenario_text_0BF8[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE
};

extern s32 scenario_code_message_1ea_63fc[];
extern s32 scenario_code_message_1ea_63fc1[];
extern s32 scenario_code_message_1ea_63fc2[];
extern s32 scenario_code_message_1ea_648c[];
extern s32 scenario_code_message_1ea_64d0[];
extern s32 scenario_code_message_1ea_668c[];
extern s32 scenario_code_message_1ea_66c8[];
extern s32 scenario_code_message_1ea_6724[];
extern s32 scenario_code_message_1ea_6748[];
extern s32 scenario_code_message_1ea_6a08[];
extern s32 scenario_code_message_1eb_67dc[];

s32 scenario_code_message_1ea_63fc[] = {

    // Address: @63fc
    // SHOP 66 - Mt. Fuji - Pipe Maker's House - Mokubei (Pipe maker)

    // 63fc: Print Text
    TXT, (s32)&scenario_text_0000,

    // TODO: NEED TO HOOK TO THE ITEM
    // 6404: If Flag 010 (Received Chain Pipe) is set, check other flags
    // Jump if flag 0x10 is SET to flag check section
    JFS, 0x10, (s32)&scenario_code_message_1ea_63fc1,

    // If flag 0x10 is NOT set, jump to main dialogue
    JMP, (s32)&scenario_code_message_1ea_63fc2,

    // End scenario script
    END,
};

s32 scenario_code_message_1ea_63fc1[] = {

    // Address: @63fc1 - Flag check section (when Chain Pipe received)

    // TODO: NEED TO HOOK TO THE ITEM
    // 6404: If Flag 012 (Upgraded to Silver Weapons), Jump To @6a08
    // Jump if flag 0x12 is SET to @6a08
    JFS, 0x12, (s32)&scenario_code_message_1ea_6a08,

    // 6410: If Flag 011 (Mokubei Can Upgrade Weapons), Jump To @66c8
    // Jump if flag 0x11 is SET to @66c8
    JFS, 0x11, (s32)&scenario_code_message_1ea_66c8,

    // 641c: Jump To @668c (since flag 0x10 is set if we reach here)
    JMP, (s32)&scenario_code_message_1ea_668c,

    // End scenario script
    END,
};

s32 scenario_code_message_1ea_63fc2[] = {

    // Address: @63fc2 - Main dialogue (when Chain Pipe not received)

    // 6428: Print Text
    TXT, (s32)&scenario_text_0014,

    // 6430: Print Text
    TXT, (s32)&scenario_text_0037,

    // 6438: Print Text
    TXT, (s32)&scenario_text_0068,

    // 6440: Print Text
    TXT, (s32)&scenario_text_0093,

    // 6448: Print Text
    TXT, (s32)&scenario_text_00AB,

    // 6450: Print Text
    TXT, (s32)&scenario_text_00DA,

    // 6458: Begin Option Selection
    BOS,

    // 645c: Print Text
    TXT, (s32)&scenario_text_00F2,

    // 6464: Jump To @648c
    JMP, (s32)&scenario_code_message_1ea_648c,

    // 646c: Print Text
    TXT, (s32)&scenario_text_012D,

    // 6474: Jump To @64d0
    JMP, (s32)&scenario_code_message_1ea_64d0,

    // 647c: End Option Selection
    EOS,

    // 6480: Print Text
    TXT, (s32)&scenario_text_016A,

    // 6488: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_1ea_648c[] = {

    // Address: @648c

    // 648c: Print Text
    TXT, (s32)&scenario_text_0093,

    // 6494: Print Text
    TXT, (s32)&scenario_text_0194,

    // 649c: Print Text
    TXT, (s32)&scenario_text_01C5,

    // 64a4: Print Text
    TXT, (s32)&scenario_text_01F5,

    // 64ac: Print Text
    TXT, (s32)&scenario_text_0093,

    // 64b4: Print Text
    TXT, (s32)&scenario_text_0232,

    // 64bc: Print Text
    TXT, (s32)&scenario_text_0267,

    // 64c4: Print Text
    TXT, (s32)&scenario_text_02A1,

    // 64cc: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_1ea_64d0[] = {

    // Address: @64d0

    // 64d0: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // 64d8: Store Value: 1
    WTS, 0x1,

    // 64e0: Print Text
    TXT, (s32)&scenario_text_0093,

    // 64e8: Print Text
    TXT, (s32)&scenario_text_02D6,

    // 64f0: Print Text
    TXT, (s32)&scenario_text_0093,

    // 64f8: Print Text
    TXT, (s32)&scenario_text_0325,

    // 6500: Print Text
    TXT, (s32)&scenario_text_034B,

    // 6508: Print Text
    TXT, (s32)&scenario_text_0093,

    // 6510: Print Text
    TXT, (s32)&scenario_text_038C,

    // 6518: Print Text
    TXT, (s32)&scenario_text_0093,

    // 6520: Print Text
    TXT, (s32)&scenario_text_03C1,

    // 6528: Print Text
    TXT, (s32)&scenario_text_0093,

    // 6530: Print Text
    TXT, (s32)&scenario_text_03F5,

    // 6538: Print Text
    TXT, (s32)&scenario_text_0093,

    // 6540: Print Text
    TXT, (s32)&scenario_text_042C,

    // 6548: Print Text
    TXT, (s32)&scenario_text_0473,

    // 6550: Print Text
    TXT, (s32)&scenario_text_04BA,

    // 6558: Set Flag 010 (Received Chain Pipe)
    SFG, 0x10,

    // 6560: Write to RAM 801c7758 (Unknown)
    STW, (s32)&D_801C7758_1C8358,

    // 6568: Store Value: 20
    WTS, 0x20,

    // 6570: Write to RAM 801c775c (Dialogue Window Y Pos)
    STW, (s32)&D_801C775C_1C835C,

    // 6578: Store Value: 48
    WTS, 0x48,

    // 6580: Write to RAM 801c7768 (Dialogue Window Style)
    STW, (s32)&D_801C7768_1C8368,

    // 6588: Store Value: 7
    WTS, 0x7,

    // 6590: Print Text
    TXT, (s32)&scenario_text_0000,

    // 6598: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // 65a0: Store Value: 1
    WTS, 0x1,

    // 65a8: Write to RAM 801c7740 (Scratch)
    STW, (s32)&D_801C7740_1C8340,

    // 65b0: Store Value: 14
    WTS, 0x14,

    // 65b8: Execute Code: 8003f608 (Play Sound)
    ESR, (s32)&func_8003F608_40208,

    // 65c0: Write to RAM 801c77d8 (Text Speed)
    STW, 0x801c77d8,

    // 65c8: Store Value: 64
    WTS, 0x64,

    // 65d0: Write to RAM 801c7798 (Unknown)
    STW, 0x801c7798,

    // 65d8: Store Value: 1
    WTS, 0x1,

    // 65e0: Print Text
    TXT, (s32)&scenario_text_00DA,

    // 65e8: Print Text
    TXT, (s32)&scenario_text_0520,

    // 65f0: Print Text
    TXT, (s32)&scenario_text_053D,

    // 65f8: Write to RAM 801c7740 (Scratch)
    STW, (s32)&D_801C7740_1C8340,

    // 6600: Store Value: 96
    WTS, 0x96,

    // 6608: Execute Code: 8003f460 (Wait For Timer)
    ESR, (s32)&func_8003F460_40060,

    // 6610: Write to RAM 801c7740 (Scratch)
    STW, (s32)&D_801C7740_1C8340,

    // 6618: Store Value: 23
    WTS, 0x23,

    // 6620: Execute Code: 8003f608 (Play Sound)
    ESR, (s32)&func_8003F608_40208,

    // 6628: Print Text
    TXT, (s32)&scenario_text_0581,

    // 6630: Print Text
    TXT, (s32)&scenario_text_0093,

    // 6638: Write to RAM 801c77d8 (Text Speed)
    STW, 0x801c77d8,

    // 6640: Store Value: 1
    WTS, 0x1,

    // 6648: Write to RAM 801c7798 (Unknown)
    STW, 0x801c7798,

    // 6650: Store Value: 1
    WTS, 0x1,

    // 6658: Print Text
    TXT, (s32)&scenario_text_05AE,

    // 6660: Print Text
    TXT, (s32)&scenario_text_05E4,

    // 6668: Print Text
    TXT, (s32)&scenario_text_062A,

    // DISABLED ITEM
    // // 6670: Write to RAM 8015c6bc (Obtained Chain Pipe)
    // STW, 0x8015c6bc,

    // // 6678: Store Value: 1
    // WTS, 0x1,

    // 6680: Print Text
    TXT, (s32)&scenario_text_02A1,

    // 6688: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_1ea_668c[] = {

    // Address: @668c

    // 668c: Print Text
    TXT, (s32)&scenario_text_0666,

    // 6694: Print Text
    TXT, (s32)&scenario_text_0093,

    // 669c: Print Text
    TXT, (s32)&scenario_text_06B1,

    // 66a4: Print Text
    TXT, (s32)&scenario_text_06E0,

    // 66ac: Print Text
    TXT, (s32)&scenario_text_0700,

    // 66b4: Print Text
    TXT, (s32)&scenario_text_073E,

    // 66bc: Print Text
    TXT, (s32)&scenario_text_02A1,

    // 66c4: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_1ea_66c8[] = {

    // Address: @66c8

    // 66c8: Print Text
    TXT, (s32)&scenario_text_077E,

    // 66d0: Print Text
    TXT, (s32)&scenario_text_07AD,

    // 66d8: Print Text
    TXT, (s32)&scenario_text_0093,

    // 66e0: Print Text
    TXT, (s32)&scenario_text_07F1,

    // 66e8: Print Text
    TXT, (s32)&scenario_text_00DA,

    // 66f0: Begin Option Selection
    BOS,

    // 66f4: Print Text
    TXT, (s32)&scenario_text_0829,

    // 66fc: Jump To @6724
    JMP, (s32)&scenario_code_message_1ea_6724,

    // 6704: Print Text
    TXT, (s32)&scenario_text_086B,

    // 670c: Jump To @6748
    JMP, (s32)&scenario_code_message_1ea_6748,

    // 6714: End Option Selection
    EOS,

    // 6718: Print Text
    TXT, (s32)&scenario_text_016A,

    // 6720: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_1ea_6724[] = {

    // Address: @6724

    // 6724: Print Text
    TXT, (s32)&scenario_text_0093,

    // 672c: Print Text
    TXT, (s32)&scenario_text_08D5,

    // 6734: Print Text
    TXT, (s32)&scenario_text_08FC,

    // 673c: Print Text
    TXT, (s32)&scenario_text_02A1,

    // 6744: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_1ea_6748[] = {

    // Address: @6748

    // 6748: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // 6750: Store Value: 1
    WTS, 0x1,

    // 6758: Print Text
    TXT, (s32)&scenario_text_0093,

    // 6760: Print Text
    TXT, (s32)&scenario_text_096B,

    // 6768: Print Text
    TXT, (s32)&scenario_text_0991,

    // 6770: Print Text
    TXT, (s32)&scenario_text_09C4,

    // 6778: Print Text
    TXT, (s32)&scenario_text_0093,

    // 6780: Print Text
    TXT, (s32)&scenario_text_0A08,

    // 6788: Print Text
    TXT, (s32)&scenario_text_0A2F,

    // 6790: Print Text
    TXT, (s32)&scenario_text_0A63,

    // 6798: Print Text
    TXT, (s32)&scenario_text_0093,

    // 67a0: Print Text
    TXT, (s32)&scenario_text_0AA2,

    // 67a8: Print Text
    TXT, (s32)&scenario_text_02A1,

    // 67b0: Set Flag 012 (Upgraded to Silver Weapons)
    SFG, 0x12,

    // 67b8: Write to RAM 801c7740 (Scratch)
    STW, (s32)&D_801C7740_1C8340,

    // 67c0: Store Value: 78
    WTS, 0x78,

    // 67c8: Execute Code: 8003f460 (Wait For Timer)
    ESR, (s32)&func_8003F460_40060,

    // 67d0: Jump To @67dc
    JMP, (s32)&scenario_code_message_1eb_67dc,

    // 67d8: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_1ea_6a08[] = {

    // Address: @6a08

    // 6a08: Print Text
    TXT, (s32)&scenario_text_0B13,

    // 6a10: Print Text
    TXT, (s32)&scenario_text_0B44,

    // 6a18: Print Text
    TXT, (s32)&scenario_text_0B75,

    // 6a20: Print Text
    TXT, (s32)&scenario_text_0093,

    // 6a28: Print Text
    TXT, (s32)&scenario_text_0BAE,

    // 6a30: Print Text
    TXT, (s32)&scenario_text_0BE2,

    // 6a38: Print Text
    TXT, (s32)&scenario_text_02A1,

    // 6a40: End Event
    END,

    // End scenario script
    END,
};


// File 1EB


// {begin}{endline}
static s16 scenario_text_1eb_0000[] = {
    CTR_BEGIN, CTR_ENDLINE
};

// Mokubei:Whew! Well,{newline}{endline}
static s16 scenario_text_1eb_0014[] = {
    CHR_M, CHR_o, CHR_k, CHR_u, CHR_b, CHR_e, CHR_i, PCT_COLON, CHR_W, CHR_h,
    CHR_e, CHR_w, PCT_EXCLAMATION, PCT_SPACE, CHR_W, CHR_e, CHR_l, CHR_l, PCT_COMMA, CTR_NEWLINE,
    CTR_ENDLINE
};

//       how's that for{newline}{endline}
static s16 scenario_text_1eb_003D[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_h, CHR_o, CHR_w, PCT_APOSTROPHE,
    CHR_s, PCT_SPACE, CHR_t, CHR_h, CHR_a, CHR_t, PCT_SPACE, CHR_f, CHR_o, CHR_r,
    CTR_NEWLINE, CTR_ENDLINE
};

//       improvement!{newline}{endline}
static s16 scenario_text_1eb_0067[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_i, CHR_m, CHR_p, CHR_r,
    CHR_o, CHR_v, CHR_e, CHR_m, CHR_e, CHR_n, CHR_t, PCT_EXCLAMATION, CTR_NEWLINE, CTR_ENDLINE
};

//       There you go!{button}{end}{endline}
static s16 scenario_text_1eb_008F[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_T, CHR_h, CHR_e, CHR_r,
    CHR_e, PCT_SPACE, CHR_y, CHR_o, CHR_u, PCT_SPACE, CHR_g, CHR_o, PCT_EXCLAMATION, CTR_BUTTON,
    CTR_END, CTR_ENDLINE
};

// {begin}{endline}
static s16 scenario_text_1eb_00BC[] = {
    CTR_BEGIN, CTR_ENDLINE
};

// The [Weapons] belonging to{newline}{endline}
static s16 scenario_text_1eb_00D0[] = {
    CHR_T, CHR_h, CHR_e, PCT_SPACE, PCT_LBRACKET, CHR_W, CHR_e, CHR_a, CHR_p, CHR_o,
    CHR_n, CHR_s, PCT_RBRACKET, PCT_SPACE, CHR_b, CHR_e, CHR_l, CHR_o, CHR_n, CHR_g,
    CHR_i, CHR_n, CHR_g, PCT_SPACE, CHR_t, CHR_o, CTR_NEWLINE, CTR_ENDLINE
};

//  Goemon and allies{newline}{endline}
static s16 scenario_text_1eb_0100[] = {
    PCT_SPACE, CHR_G, CHR_o, CHR_e, CHR_m, CHR_o, CHR_n, PCT_SPACE, CHR_a, CHR_n,
    CHR_d, PCT_SPACE, CHR_a, CHR_l, CHR_l, CHR_i, CHR_e, CHR_s, CTR_NEWLINE, CTR_ENDLINE
};

//         improve to [{em-yellow}Level 2{/em}]!{newline}{endline}
static s16 scenario_text_1eb_0128[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_i, CHR_m,
    CHR_p, CHR_r, CHR_o, CHR_v, CHR_e, PCT_SPACE, CHR_t, CHR_o, PCT_SPACE, PCT_LBRACKET,
    CTR_EM_YELLOW, CHR_L, CHR_e, CHR_v, CHR_e, CHR_l, PCT_SPACE, NUM_2, CTR_CLOSE_EM, PCT_RBRACKET,
    PCT_EXCLAMATION, CTR_NEWLINE, CTR_ENDLINE
};

// {button}{endline}
static s16 scenario_text_1eb_016B[] = {
    CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_1eb_0180[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

//   {newline}{endline}
static s16 scenario_text_1eb_0198[] = {
    PCT_SPACE, PCT_SPACE, CTR_NEWLINE, CTR_ENDLINE
};

// ({em-yellow}Yae{/em} can now use{newline}{endline}
static s16 scenario_text_1eb_01B0[] = {
    PCT_LPAREN, CTR_EM_YELLOW, CHR_Y, CHR_a, CHR_e, CTR_CLOSE_EM, PCT_SPACE, CHR_c, CHR_a, CHR_n,
    PCT_SPACE, CHR_n, CHR_o, CHR_w, PCT_SPACE, CHR_u, CHR_s, CHR_e, CTR_NEWLINE, CTR_ENDLINE
};

//          the {em-yellow}Sword Shield{/em}!){newline}{endline}
static s16 scenario_text_1eb_01E6[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_t,
    CHR_h, CHR_e, PCT_SPACE, CTR_EM_YELLOW, CHR_S, CHR_w, CHR_o, CHR_r, CHR_d, PCT_SPACE,
    CHR_S, CHR_h, CHR_i, CHR_e, CHR_l, CHR_d, CTR_CLOSE_EM, PCT_EXCLAMATION, PCT_RPAREN, CTR_NEWLINE,
    CTR_ENDLINE
};

// {button}{end}{endline}
static s16 scenario_text_1eb_0227[] = {
    CTR_BUTTON, CTR_END, CTR_ENDLINE
};

// {begin}{endline}
static s16 scenario_text_1eb_0241[] = {
    CTR_BEGIN, CTR_ENDLINE
};

// Goemon:Thank you Mokubei!{button}{end}{endline}
static s16 scenario_text_1eb_0255[] = {
    CHR_G, CHR_o, CHR_e, CHR_m, CHR_o, CHR_n, PCT_COLON, CHR_T, CHR_h, CHR_a,
    CHR_n, CHR_k, PCT_SPACE, CHR_y, CHR_o, CHR_u, PCT_SPACE, CHR_M, CHR_o, CHR_k,
    CHR_u, CHR_b, CHR_e, CHR_i, PCT_EXCLAMATION, CTR_BUTTON, CTR_END, CTR_ENDLINE
};

// {begin}{endline}
static s16 scenario_text_1eb_0288[] = {
    CTR_BEGIN, CTR_ENDLINE
};

// Mokubei:No problem!{endline}
static s16 scenario_text_1eb_029C[] = {
    CHR_M, CHR_o, CHR_k, CHR_u, CHR_b, CHR_e, CHR_i, PCT_COLON, CHR_N, CHR_o,
    PCT_SPACE, CHR_p, CHR_r, CHR_o, CHR_b, CHR_l, CHR_e, CHR_m, PCT_EXCLAMATION, CTR_ENDLINE
};

// {waitinput}{end}{endline}
static s16 scenario_text_1eb_02BC[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE
};

s32 scenario_code_message_1eb_67dc[] = {

    // Address: @67dc

    // 67dc: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // 67e4: Store Value: 1
    WTS, 0x1,

    // 67ec: Write to RAM 801c7768 (Dialogue Window Style)
    STW, (s32)&D_801C7768_1C8368,

    // 67f4: Store Value: 1
    WTS, 0x1,

    // 67fc: Print Text
    TXT, (s32)&scenario_text_1eb_0000,

    // 6804: Print Text
    TXT, (s32)&scenario_text_1eb_0014,

    // 680c: Print Text
    TXT, (s32)&scenario_text_1eb_003D,

    // 6814: Print Text
    TXT, (s32)&scenario_text_1eb_0067,

    // 681c: Print Text
    TXT, (s32)&scenario_text_1eb_008F,

    // 6824: Write to RAM 801c7758 (Unknown)
    STW, (s32)&D_801C7758_1C8358,

    // 682c: Store Value: 20
    WTS, 0x20,

    // 6834: Write to RAM 801c775c (Dialogue Window Y Pos)
    STW, (s32)&D_801C775C_1C835C,

    // 683c: Store Value: 48
    WTS, 0x48,

    // 6844: Write to RAM 801c7768 (Dialogue Window Style)
    STW, (s32)&D_801C7768_1C8368,

    // 684c: Store Value: 7
    WTS, 0x7,

    // 6854: Print Text
    TXT, (s32)&scenario_text_1eb_0000,

    // 685c: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // 6864: Store Value: 1
    WTS, 0x1,

    // 686c: Write to RAM 801c7740 (Scratch)
    STW, (s32)&D_801C7740_1C8340,

    // 6874: Store Value: 14
    WTS, 0x14,

    // 687c: Execute Code: 8003f608 (Play Sound)
    ESR, (s32)&func_8003F608_40208,

    // 6884: Write to RAM 801c77d8 (Text Speed)
    STW, 0x801c77d8,

    // 688c: Store Value: 64
    WTS, 0x64,

    // 6894: Write to RAM 801c7798 (Unknown)
    STW, 0x801c7798,

    // 689c: Store Value: 1
    WTS, 0x1,

    // 68a4: Print Text
    TXT, (s32)&scenario_text_1eb_00D0,

    // 68ac: Print Text
    TXT, (s32)&scenario_text_1eb_0100,

    // 68b4: Print Text
    TXT, (s32)&scenario_text_1eb_0128,

    // 68bc: Write to RAM 801c7740 (Scratch)
    STW, (s32)&D_801C7740_1C8340,

    // 68c4: Store Value: 96
    WTS, 0x96,

    // 68cc: Execute Code: 8003f460 (Wait For Timer)
    ESR, (s32)&func_8003F460_40060,

    // 68d4: Write to RAM 801c7740 (Scratch)
    STW, (s32)&D_801C7740_1C8340,

    // 68dc: Store Value: 23
    WTS, 0x23,

    // 68e4: Execute Code: 8003f608 (Play Sound)
    ESR, (s32)&func_8003F608_40208,

    // 68ec: Print Text
    TXT, (s32)&scenario_text_1eb_016B,

    // 68f4: Print Text
    TXT, (s32)&scenario_text_1eb_0180,

    // 68fc: Print Text
    TXT, (s32)&scenario_text_1eb_0198,

    // 6904: Print Text
    TXT, (s32)&scenario_text_1eb_01B0,

    // 690c: Print Text
    TXT, (s32)&scenario_text_1eb_01E6,

    // 6914: Print Text
    TXT, (s32)&scenario_text_1eb_0227,

    // 691c: Write to RAM 801c7758 (Unknown)
    STW, (s32)&D_801C7758_1C8358,

    // 6924: Store Value: 20
    WTS, 0x20,

    // 692c: Write to RAM 801c775c (Dialogue Window Y Pos)
    STW, (s32)&D_801C775C_1C835C,

    // 6934: Store Value: 20
    WTS, 0x20,

    // 693c: Write to RAM 801c7768 (Dialogue Window Style)
    STW, (s32)&D_801C7768_1C8368,

    // 6944: Store Value: 7
    WTS, 0x7,

    // 694c: Print Text
    TXT, (s32)&scenario_text_1eb_0000,

    // 6954: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // 695c: Store Value: 1
    WTS, 0x1,

    // 6964: Write to RAM 8007785c (Dialogue Portrait Character)
    STW, (s32)&D_8007785C_7845C,

    // 696c: Store Value: 0
    WTS, 0x0,

    // 6974: Print Text
    TXT, (s32)&scenario_text_1eb_0255,

    // 697c: Write to RAM 801c7768 (Dialogue Window Style)
    STW, (s32)&D_801C7768_1C8368,

    // 6984: Store Value: 1
    WTS, 0x1,

    // 698c: Write to RAM 8007785c (Dialogue Portrait Character)
    STW, (s32)&D_8007785C_7845C,

    // 6994: Store Value: 100
    WTS, 0x100,

    // 699c: Print Text
    TXT, (s32)&scenario_text_1eb_0000,

    // 69a4: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // 69ac: Store Value: 1
    WTS, 0x1,

    // 69b4: Print Text
    TXT, (s32)&scenario_text_1eb_029C,

    // DISABLED ITEM
    // // 69bc: Write to RAM 8015c6ac (Goemon Weapon Level)
    // STW, 0x8015c6ac,

    // // 69c4: Store Value: 1
    // WTS, 0x1,

    // // 69cc: Write to RAM 8015c6b0 (Ebisumaru Weapon Level)
    // STW, 0x8015c6b0,

    // // 69d4: Store Value: 1
    // WTS, 0x1,

    // // 69dc: Write to RAM 8015c6b4 (Sasuke Weapon Level)
    // STW, 0x8015c6b4,

    // // 69e4: Store Value: 1
    // WTS, 0x1,

    // // 69ec: Write to RAM 8015c6b8 (Yae Weapon Level)
    // STW, 0x8015c6b8,

    // // 69f4: Store Value: 1
    // WTS, 0x1,

    // 69fc: Print Text
    TXT, (s32)&scenario_text_1eb_02BC,

    // 6a04: End Event
    END,

    // End scenario script
    END,
};











