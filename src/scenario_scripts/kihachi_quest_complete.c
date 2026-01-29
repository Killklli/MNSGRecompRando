// Adjusts scenario_code_message_162_d63c so you always learn Kihachi's favorite
// food
#include "types.h"
#include "modding.h"
#include "recomputils.h"
#include "scenario.h"



// Address: @cd8c

// {begin}{endline}
static s16 scenario_text_0000[] = {CTR_BEGIN, CTR_ENDLINE};

// What'd you say?{button}{endline}
static s16 scenario_text_0014[] = {
    CHR_W, CHR_h, CHR_a, CHR_t, PCT_APOSTROPHE, CHR_d,
    PCT_SPACE, CHR_y, CHR_o, CHR_u, PCT_SPACE, CHR_s,
    CHR_a, CHR_y, PCT_QUESTION, CTR_BUTTON, CTR_ENDLINE};

// {newwindow}{endline}
static s16 scenario_text_0038[] = {CTR_NEWWINDOW, CTR_ENDLINE};

// What do you want with me,{newline}{endline}
static s16 scenario_text_0050[] = {
    CHR_W, CHR_h, CHR_a, CHR_t, PCT_SPACE, CHR_d, CHR_o,
    PCT_SPACE, CHR_y, CHR_o, CHR_u, PCT_SPACE, CHR_w, CHR_a,
    CHR_n, CHR_t, PCT_SPACE, CHR_w, CHR_i, CHR_t, CHR_h,
    PCT_SPACE, CHR_m, CHR_e, PCT_COMMA, CTR_NEWLINE, CTR_ENDLINE};

// the mighty water imp {em-yellow}Kihachi{/em}?{button}{end}{endline}
static s16 scenario_text_007F[] = {
    CHR_t, CHR_h, CHR_e, PCT_SPACE, CHR_m, CHR_i,
    CHR_g, CHR_h, CHR_t, CHR_y, PCT_SPACE, CHR_w,
    CHR_a, CHR_t, CHR_e, CHR_r, PCT_SPACE, CHR_i,
    CHR_m, CHR_p, PCT_SPACE, CTR_EM_YELLOW, CHR_K, CHR_i,
    CHR_h, CHR_a, CHR_c, CHR_h, CHR_i, CTR_CLOSE_EM,
    PCT_QUESTION, CTR_BUTTON, CTR_END, CTR_ENDLINE};

// {waitinput}{end}{endline}
static s16 scenario_text_00C6[] = {CTR_WAITINPUT, CTR_END, CTR_ENDLINE};

// Address: @ce64

// {begin}{endline}
static s16 scenario_text_00E3[] = {CTR_BEGIN, CTR_ENDLINE};

// Goemon:I've got a question...{button}{endline}
static s16 scenario_text_00F7[] = {
    CHR_G, CHR_o, CHR_e, CHR_m, CHR_o, CHR_n,
    PCT_COLON, CHR_I, PCT_APOSTROPHE, CHR_v, CHR_e, PCT_SPACE,
    CHR_g, CHR_o, CHR_t, PCT_SPACE, CHR_a, PCT_SPACE,
    CHR_q, CHR_u, CHR_e, CHR_s, CHR_t, CHR_i,
    CHR_o, CHR_n, PCT_PERIOD, PCT_PERIOD, PCT_PERIOD, CTR_BUTTON,
    CTR_ENDLINE};

// {newwindow}{endline}
static s16 scenario_text_0129[] = {CTR_NEWWINDOW, CTR_ENDLINE};

// Goemon:Did you pick up{newline}{endline}
static s16 scenario_text_0141[] = {
    CHR_G, CHR_o, CHR_e, CHR_m, CHR_o, CHR_n, PCT_COLON, CHR_D,
    CHR_i, CHR_d, PCT_SPACE, CHR_y, CHR_o, CHR_u, PCT_SPACE, CHR_p,
    CHR_i, CHR_c, CHR_k, PCT_SPACE, CHR_u, CHR_p, CTR_NEWLINE, CTR_ENDLINE};

//       a strange {em-yellow}item{/em} around{newline}{endline}
static s16 scenario_text_016D[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE,
    CHR_a, PCT_SPACE, CHR_s, CHR_t, CHR_r, CHR_a,
    CHR_n, CHR_g, CHR_e, PCT_SPACE, CTR_EM_YELLOW, CHR_i,
    CHR_t, CHR_e, CHR_m, CTR_CLOSE_EM, PCT_SPACE, CHR_a,
    CHR_r, CHR_o, CHR_u, CHR_n, CHR_d, CTR_NEWLINE,
    CTR_ENDLINE};

//       here?{button}{end}{endline}
static s16 scenario_text_01AE[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE,
    PCT_SPACE, CHR_h, CHR_e, CHR_r, CHR_e,
    PCT_QUESTION, CTR_BUTTON, CTR_END, CTR_ENDLINE};

// Address: @ced0

// {begin}{endline}
static s16 scenario_text_01D3[] = {CTR_BEGIN, CTR_ENDLINE};

// Ebisumaru:I want to ask you{newline}{endline}
static s16 scenario_text_01E7[] = {
    CHR_E, CHR_b, CHR_i, CHR_s, CHR_u, CHR_m,
    CHR_a, CHR_r, CHR_u, PCT_COLON, CHR_I, PCT_SPACE,
    CHR_w, CHR_a, CHR_n, CHR_t, PCT_SPACE, CHR_t,
    CHR_o, PCT_SPACE, CHR_a, CHR_s, CHR_k, PCT_SPACE,
    CHR_y, CHR_o, CHR_u, CTR_NEWLINE, CTR_ENDLINE};

//        something...{button}{endline}
static s16 scenario_text_0218[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE,
    PCT_SPACE, CHR_s, CHR_o, CHR_m, CHR_e, CHR_t,
    CHR_h, CHR_i, CHR_n, CHR_g, PCT_PERIOD, PCT_PERIOD,
    PCT_PERIOD, CTR_BUTTON, CTR_ENDLINE};

// {newwindow}{endline}
static s16 scenario_text_0240[] = {CTR_NEWWINDOW, CTR_ENDLINE};

// Ebisumaru:Do you have a strange{newline}{endline}
static s16 scenario_text_0258[] = {
    CHR_E, CHR_b, CHR_i, CHR_s, CHR_u, CHR_m, CHR_a,
    CHR_r, CHR_u, PCT_COLON, CHR_D, CHR_o, PCT_SPACE, CHR_y,
    CHR_o, CHR_u, PCT_SPACE, CHR_h, CHR_a, CHR_v, CHR_e,
    PCT_SPACE, CHR_a, PCT_SPACE, CHR_s, CHR_t, CHR_r, CHR_a,
    CHR_n, CHR_g, CHR_e, CTR_NEWLINE, CTR_ENDLINE};

//        {em-yellow}item{/em} that you might have{newline}{endline}
static s16 scenario_text_028D[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE,
    PCT_SPACE, CTR_EM_YELLOW, CHR_i, CHR_t, CHR_e, CHR_m,
    CTR_CLOSE_EM, PCT_SPACE, CHR_t, CHR_h, CHR_a, CHR_t,
    PCT_SPACE, CHR_y, CHR_o, CHR_u, PCT_SPACE, CHR_m,
    CHR_i, CHR_g, CHR_h, CHR_t, PCT_SPACE, CHR_h,
    CHR_a, CHR_v, CHR_e, CTR_NEWLINE, CTR_ENDLINE};

//        picked up around here?{button}{end}{endline}
static s16 scenario_text_02D2[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE,
    PCT_SPACE, CHR_p, CHR_i, CHR_c, CHR_k, CHR_e,
    CHR_d, PCT_SPACE, CHR_u, CHR_p, PCT_SPACE, CHR_a,
    CHR_r, CHR_o, CHR_u, CHR_n, CHR_d, PCT_SPACE,
    CHR_h, CHR_e, CHR_r, CHR_e, PCT_QUESTION, CTR_BUTTON,
    CTR_END, CTR_ENDLINE};

// Address: @cf44

// {begin}{endline}
static s16 scenario_text_0309[] = {CTR_BEGIN, CTR_ENDLINE};

// Yae:I'm sorry to bother you...{button}{endline}
static s16 scenario_text_031D[] = {
    CHR_Y, CHR_a, CHR_e, PCT_COLON, CHR_I, PCT_APOSTROPHE,
    CHR_m, PCT_SPACE, CHR_s, CHR_o, CHR_r, CHR_r,
    CHR_y, PCT_SPACE, CHR_t, CHR_o, PCT_SPACE, CHR_b,
    CHR_o, CHR_t, CHR_h, CHR_e, CHR_r, PCT_SPACE,
    CHR_y, CHR_o, CHR_u, PCT_PERIOD, PCT_PERIOD, PCT_PERIOD,
    CTR_BUTTON, CTR_ENDLINE};

// {newwindow}{endline}
static s16 scenario_text_0350[] = {CTR_NEWWINDOW, CTR_ENDLINE};

// Yae:But do you remember{newline}{endline}
static s16 scenario_text_0368[] = {
    CHR_Y, CHR_a, CHR_e, PCT_COLON, CHR_B, CHR_u, CHR_t,
    PCT_SPACE, CHR_d, CHR_o, PCT_SPACE, CHR_y, CHR_o, CHR_u,
    PCT_SPACE, CHR_r, CHR_e, CHR_m, CHR_e, CHR_m, CHR_b,
    CHR_e, CHR_r, CTR_NEWLINE, CTR_ENDLINE};

//       picking up an unusual {em-yellow}item{/em}{newline}{endline}
static s16 scenario_text_0395[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE,
    CHR_p, CHR_i, CHR_c, CHR_k, CHR_i, CHR_n,
    CHR_g, PCT_SPACE, CHR_u, CHR_p, PCT_SPACE, CHR_a,
    CHR_n, PCT_SPACE, CHR_u, CHR_n, CHR_u, CHR_s,
    CHR_u, CHR_a, CHR_l, PCT_SPACE, CTR_EM_YELLOW, CHR_i,
    CHR_t, CHR_e, CHR_m, CTR_CLOSE_EM, CTR_NEWLINE, CTR_ENDLINE};

//       around here?{button}{end}{endline}
static s16 scenario_text_03DB[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE,
    CHR_a, CHR_r, CHR_o, CHR_u, CHR_n, CHR_d,
    PCT_SPACE, CHR_h, CHR_e, CHR_r, CHR_e, PCT_QUESTION,
    CTR_BUTTON, CTR_END, CTR_ENDLINE};

// Address: @cfb0

// {begin}{endline}
static s16 scenario_text_0407[] = {CTR_BEGIN, CTR_ENDLINE};

// Sasuke:Mr.Kihachi,{newline}{endline}
static s16 scenario_text_041B[] = {
    CHR_S, CHR_a, CHR_s, CHR_u, CHR_k, CHR_e, PCT_COLON,
    CHR_M, CHR_r, PCT_PERIOD, CHR_K, CHR_i, CHR_h, CHR_a,
    CHR_c, CHR_h, CHR_i, PCT_COMMA, CTR_NEWLINE, CTR_ENDLINE};

//       I was wondering...{button}{endline}
static s16 scenario_text_0443[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE,
    CHR_I, PCT_SPACE, CHR_w, CHR_a, CHR_s, PCT_SPACE,
    CHR_w, CHR_o, CHR_n, CHR_d, CHR_e, CHR_r,
    CHR_i, CHR_n, CHR_g, PCT_PERIOD, PCT_PERIOD, PCT_PERIOD,
    CTR_BUTTON, CTR_ENDLINE};

// {newwindow}{endline}
static s16 scenario_text_0470[] = {CTR_NEWWINDOW, CTR_ENDLINE};

// Sasuke:That maybe you might have{newline}{endline}
static s16 scenario_text_0488[] = {
    CHR_S, CHR_a, CHR_s, CHR_u, CHR_k, CHR_e, PCT_COLON,
    CHR_T, CHR_h, CHR_a, CHR_t, PCT_SPACE, CHR_m, CHR_a,
    CHR_y, CHR_b, CHR_e, PCT_SPACE, CHR_y, CHR_o, CHR_u,
    PCT_SPACE, CHR_m, CHR_i, CHR_g, CHR_h, CHR_t, PCT_SPACE,
    CHR_h, CHR_a, CHR_v, CHR_e, CTR_NEWLINE, CTR_ENDLINE};

//       picked up a peculiar {em-yellow}item{/em}{newline}{endline}
static s16 scenario_text_04BE[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE,
    CHR_p, CHR_i, CHR_c, CHR_k, CHR_e, CHR_d,
    PCT_SPACE, CHR_u, CHR_p, PCT_SPACE, CHR_a, PCT_SPACE,
    CHR_p, CHR_e, CHR_c, CHR_u, CHR_l, CHR_i,
    CHR_a, CHR_r, PCT_SPACE, CTR_EM_YELLOW, CHR_i, CHR_t,
    CHR_e, CHR_m, CTR_CLOSE_EM, CTR_NEWLINE, CTR_ENDLINE};

//       in this town recently.{button}{end}{endline}
static s16 scenario_text_0503[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE,
    CHR_i, CHR_n, PCT_SPACE, CHR_t, CHR_h, CHR_i,
    CHR_s, PCT_SPACE, CHR_t, CHR_o, CHR_w, CHR_n,
    PCT_SPACE, CHR_r, CHR_e, CHR_c, CHR_e, CHR_n,
    CHR_t, CHR_l, CHR_y, PCT_PERIOD, CTR_BUTTON, CTR_END,
    CTR_ENDLINE};

// Address: @d024

// {begin}{endline}
static s16 scenario_text_0539[] = {CTR_BEGIN, CTR_ENDLINE};

// Kihachi:Hmmm... {newline}{endline}
static s16 scenario_text_054D[] = {
    CHR_K, CHR_i, CHR_h, CHR_a, CHR_c, CHR_h,
    CHR_i, PCT_COLON, CHR_H, CHR_m, CHR_m, CHR_m,
    PCT_PERIOD, PCT_PERIOD, PCT_PERIOD, PCT_SPACE, CTR_NEWLINE, CTR_ENDLINE};

//       Maybe you're referring to{newline}{endline}
static s16 scenario_text_0573[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE,
    CHR_M, CHR_a, CHR_y, CHR_b, CHR_e, PCT_SPACE,
    CHR_y, CHR_o, CHR_u, PCT_APOSTROPHE, CHR_r, CHR_e,
    PCT_SPACE, CHR_r, CHR_e, CHR_f, CHR_e, CHR_r,
    CHR_r, CHR_i, CHR_n, CHR_g, PCT_SPACE, CHR_t,
    CHR_o, CTR_NEWLINE, CTR_ENDLINE};

//       this {em-yellow}odd item{/em} I picked up{newline}{endline}
static s16 scenario_text_05A8[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE,
    CHR_t, CHR_h, CHR_i, CHR_s, PCT_SPACE, CTR_EM_YELLOW,
    CHR_o, CHR_d, CHR_d, PCT_SPACE, CHR_i, CHR_t,
    CHR_e, CHR_m, CTR_CLOSE_EM, PCT_SPACE, CHR_I, PCT_SPACE,
    CHR_p, CHR_i, CHR_c, CHR_k, CHR_e, CHR_d,
    PCT_SPACE, CHR_u, CHR_p, CTR_NEWLINE, CTR_ENDLINE};

//       the other day?{button}{end}{endline}
static s16 scenario_text_05ED[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE,
    CHR_t, CHR_h, CHR_e, PCT_SPACE, CHR_o, CHR_t,
    CHR_h, CHR_e, CHR_r, PCT_SPACE, CHR_d, CHR_a,
    CHR_y, PCT_QUESTION, CTR_BUTTON, CTR_END, CTR_ENDLINE};

// {begin}{endline}
static s16 scenario_text_061B[] = {CTR_BEGIN, CTR_ENDLINE};

// Goemon:Is that a fact?{newline}{endline}
static s16 scenario_text_062F[] = {
    CHR_G, CHR_o, CHR_e, CHR_m, CHR_o, CHR_n,
    PCT_COLON, CHR_I, CHR_s, PCT_SPACE, CHR_t, CHR_h,
    CHR_a, CHR_t, PCT_SPACE, CHR_a, PCT_SPACE, CHR_f,
    CHR_a, CHR_c, CHR_t, PCT_QUESTION, CTR_NEWLINE, CTR_ENDLINE};

//       If that's true,{newline}{endline}
static s16 scenario_text_065B[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE,
    CHR_I, CHR_f, PCT_SPACE, CHR_t, CHR_h, CHR_a,
    CHR_t, PCT_APOSTROPHE, CHR_s, PCT_SPACE, CHR_t, CHR_r,
    CHR_u, CHR_e, PCT_COMMA, CTR_NEWLINE, CTR_ENDLINE};

//       can you give it to us?{button}{end}{endline}
static s16 scenario_text_0686[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE,
    CHR_c, CHR_a, CHR_n, PCT_SPACE, CHR_y, CHR_o,
    CHR_u, PCT_SPACE, CHR_g, CHR_i, CHR_v, CHR_e,
    PCT_SPACE, CHR_i, CHR_t, PCT_SPACE, CHR_t, CHR_o,
    PCT_SPACE, CHR_u, CHR_s, PCT_QUESTION, CTR_BUTTON, CTR_END,
    CTR_ENDLINE};

// {begin}{endline}
static s16 scenario_text_06BC[] = {CTR_BEGIN, CTR_ENDLINE};

// Kihachi:Get real!{newline}{endline}
static s16 scenario_text_06D0[] = {
    CHR_K, CHR_i, CHR_h, CHR_a, CHR_c, CHR_h, CHR_i,
    PCT_COLON, CHR_G, CHR_e, CHR_t, PCT_SPACE, CHR_r, CHR_e,
    CHR_a, CHR_l, PCT_EXCLAMATION, CTR_NEWLINE, CTR_ENDLINE};

//       You don't just ask to {newline}{endline}
static s16 scenario_text_06F7[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE,
    CHR_Y, CHR_o, CHR_u, PCT_SPACE, CHR_d, CHR_o,
    CHR_n, PCT_APOSTROPHE, CHR_t, PCT_SPACE, CHR_j, CHR_u,
    CHR_s, CHR_t, PCT_SPACE, CHR_a, CHR_s, CHR_k,
    PCT_SPACE, CHR_t, CHR_o, PCT_SPACE, CTR_NEWLINE, CTR_ENDLINE};

//       get something for nothing!{button}{endline}
static s16 scenario_text_0729[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE,
    CHR_g, CHR_e, CHR_t, PCT_SPACE, CHR_s, CHR_o,
    CHR_m, CHR_e, CHR_t, CHR_h, CHR_i, CHR_n,
    CHR_g, PCT_SPACE, CHR_f, CHR_o, CHR_r, PCT_SPACE,
    CHR_n, CHR_o, CHR_t, CHR_h, CHR_i, CHR_n,
    CHR_g, PCT_EXCLAMATION, CTR_BUTTON, CTR_ENDLINE};

// {newwindow}{endline}
static s16 scenario_text_075E[] = {CTR_NEWWINDOW, CTR_ENDLINE};

// Kihachi:Try carving the word{newline}{endline}
static s16 scenario_text_0776[] = {
    CHR_K, CHR_i, CHR_h, CHR_a, CHR_c, CHR_h, CHR_i, PCT_COLON,
    CHR_T, CHR_r, CHR_y, PCT_SPACE, CHR_c, CHR_a, CHR_r, CHR_v,
    CHR_i, CHR_n, CHR_g, PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE,
    CHR_w, CHR_o, CHR_r, CHR_d, CTR_NEWLINE, CTR_ENDLINE};

//       "{em-yellow}WORLD{/em}" in that piece{newline}{endline}
static s16 scenario_text_07A8[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE,
    PCT_QUOTE, CTR_EM_YELLOW, CHR_W, CHR_O, CHR_R, CHR_L,
    CHR_D, CTR_CLOSE_EM, PCT_QUOTE, PCT_SPACE, CHR_i, CHR_n,
    PCT_SPACE, CHR_t, CHR_h, CHR_a, CHR_t, PCT_SPACE,
    CHR_p, CHR_i, CHR_e, CHR_c, CHR_e, CTR_NEWLINE,
    CTR_ENDLINE};

//       of rock...{button}{endline}
static s16 scenario_text_07E9[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE,
    CHR_o, CHR_f, PCT_SPACE, CHR_r, CHR_o, CHR_c,
    CHR_k, PCT_PERIOD, PCT_PERIOD, PCT_PERIOD, CTR_BUTTON, CTR_ENDLINE};

// {newwindow}{endline}
static s16 scenario_text_080E[] = {CTR_NEWWINDOW, CTR_ENDLINE};

// Kihachi:And tell me out loud{newline}{endline}
static s16 scenario_text_0826[] = {
    CHR_K, CHR_i, CHR_h, CHR_a, CHR_c, CHR_h,
    CHR_i, PCT_COLON, CHR_A, CHR_n, CHR_d, PCT_SPACE,
    CHR_t, CHR_e, CHR_l, CHR_l, PCT_SPACE, CHR_m,
    CHR_e, PCT_SPACE, CHR_o, CHR_u, CHR_t, PCT_SPACE,
    CHR_l, CHR_o, CHR_u, CHR_d, CTR_NEWLINE, CTR_ENDLINE};

//       what you have...{button}{end}{endline}
static s16 scenario_text_0858[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE,
    PCT_SPACE, CHR_w, CHR_h, CHR_a, CHR_t,
    PCT_SPACE, CHR_y, CHR_o, CHR_u, PCT_SPACE,
    CHR_h, CHR_a, CHR_v, CHR_e, PCT_PERIOD,
    PCT_PERIOD, PCT_PERIOD, CTR_BUTTON, CTR_END, CTR_ENDLINE};

// {begin}{endline}
static s16 scenario_text_0888[] = {CTR_BEGIN, CTR_ENDLINE};

// Ebisumaru:Hey, that's pretty{newline}{endline}
static s16 scenario_text_089C[] = {
    CHR_E, CHR_b, CHR_i, CHR_s, CHR_u, CHR_m,
    CHR_a, CHR_r, CHR_u, PCT_COLON, CHR_H, CHR_e,
    CHR_y, PCT_COMMA, PCT_SPACE, CHR_t, CHR_h, CHR_a,
    CHR_t, PCT_APOSTROPHE, CHR_s, PCT_SPACE, CHR_p, CHR_r,
    CHR_e, CHR_t, CHR_t, CHR_y, CTR_NEWLINE, CTR_ENDLINE};

//        tough, it's no easy task{newline}{endline}
static s16 scenario_text_08CE[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE,
    PCT_SPACE, CHR_t, CHR_o, CHR_u, CHR_g, CHR_h,
    PCT_COMMA, PCT_SPACE, CHR_i, CHR_t, PCT_APOSTROPHE, CHR_s,
    PCT_SPACE, CHR_n, CHR_o, PCT_SPACE, CHR_e, CHR_a,
    CHR_s, CHR_y, PCT_SPACE, CHR_t, CHR_a, CHR_s,
    CHR_k, CTR_NEWLINE, CTR_ENDLINE};

//        to carve "{em-yellow}WORLD{/em}" on{newline}{endline}
static s16 scenario_text_0903[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE,
    PCT_SPACE, CHR_t, CHR_o, PCT_SPACE, CHR_c, CHR_a,
    CHR_r, CHR_v, CHR_e, PCT_SPACE, PCT_QUOTE, CTR_EM_YELLOW,
    CHR_W, CHR_O, CHR_R, CHR_L, CHR_D, CTR_CLOSE_EM,
    PCT_QUOTE, PCT_SPACE, CHR_o, CHR_n, CTR_NEWLINE, CTR_ENDLINE};

//        here!{button}{endline}
static s16 scenario_text_0943[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE,
    PCT_SPACE, PCT_SPACE, CHR_h, CHR_e, CHR_r,
    CHR_e, PCT_EXCLAMATION, CTR_BUTTON, CTR_ENDLINE};

// {newwindow}{endline}
static s16 scenario_text_0964[] = {CTR_NEWWINDOW, CTR_ENDLINE};

// Goemon:It's a tough world!{button}{end}{endline}
static s16 scenario_text_097C[] = {
    CHR_G, CHR_o, CHR_e, CHR_m, CHR_o,
    CHR_n, PCT_COLON, CHR_I, CHR_t, PCT_APOSTROPHE,
    CHR_s, PCT_SPACE, CHR_a, PCT_SPACE, CHR_t,
    CHR_o, CHR_u, CHR_g, CHR_h, PCT_SPACE,
    CHR_w, CHR_o, CHR_r, CHR_l, CHR_d,
    PCT_EXCLAMATION, CTR_BUTTON, CTR_END, CTR_ENDLINE};

// {begin}{endline}
static s16 scenario_text_09B0[] = {CTR_BEGIN, CTR_ENDLINE};

// Kihachi:In any case,{newline}{endline}
static s16 scenario_text_09C4[] = {
    CHR_K, CHR_i, CHR_h, CHR_a, CHR_c, CHR_h,
    CHR_i, PCT_COLON, CHR_I, CHR_n, PCT_SPACE, CHR_a,
    CHR_n, CHR_y, PCT_SPACE, CHR_c, CHR_a, CHR_s,
    CHR_e, PCT_COMMA, CTR_NEWLINE, CTR_ENDLINE};

//       I can't just go around{newline}{endline}
static s16 scenario_text_09EE[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE,
    CHR_I, PCT_SPACE, CHR_c, CHR_a, CHR_n, PCT_APOSTROPHE,
    CHR_t, PCT_SPACE, CHR_j, CHR_u, CHR_s, CHR_t,
    PCT_SPACE, CHR_g, CHR_o, PCT_SPACE, CHR_a, CHR_r,
    CHR_o, CHR_u, CHR_n, CHR_d, CTR_NEWLINE, CTR_ENDLINE};

//       giving away parts of my{newline}{endline}
static s16 scenario_text_0A20[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_g,
    CHR_i, CHR_v, CHR_i, CHR_n, CHR_g, PCT_SPACE, CHR_a,
    CHR_w, CHR_a, CHR_y, PCT_SPACE, CHR_p, CHR_a, CHR_r,
    CHR_t, CHR_s, PCT_SPACE, CHR_o, CHR_f, PCT_SPACE, CHR_m,
    CHR_y, CTR_NEWLINE, CTR_ENDLINE};

//       valuable {em-yellow}collection{/em}.{button}{end}{endline}
static s16 scenario_text_0A53[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE,
    CHR_v, CHR_a, CHR_l, CHR_u, CHR_a, CHR_b,
    CHR_l, CHR_e, PCT_SPACE, CTR_EM_YELLOW, CHR_c, CHR_o,
    CHR_l, CHR_l, CHR_e, CHR_c, CHR_t, CHR_i,
    CHR_o, CHR_n, CTR_CLOSE_EM, PCT_PERIOD, CTR_BUTTON, CTR_END,
    CTR_ENDLINE};

// {begin}{endline}
static s16 scenario_text_0A97[] = {CTR_BEGIN, CTR_ENDLINE};

// Yae:Please reconsider.{newline}{endline}
static s16 scenario_text_0AAB[] = {
    CHR_Y, CHR_a, CHR_e, PCT_COLON, CHR_P, CHR_l,
    CHR_e, CHR_a, CHR_s, CHR_e, PCT_SPACE, CHR_r,
    CHR_e, CHR_c, CHR_o, CHR_n, CHR_s, CHR_i,
    CHR_d, CHR_e, CHR_r, PCT_PERIOD, CTR_NEWLINE, CTR_ENDLINE};

//       We really need {em-yellow}that item{/em}.{button}{end}{endline}
static s16 scenario_text_0AD7[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE,
    CHR_W, CHR_e, PCT_SPACE, CHR_r, CHR_e, CHR_a,
    CHR_l, CHR_l, CHR_y, PCT_SPACE, CHR_n, CHR_e,
    CHR_e, CHR_d, PCT_SPACE, CTR_EM_YELLOW, CHR_t, CHR_h,
    CHR_a, CHR_t, PCT_SPACE, CHR_i, CHR_t, CHR_e,
    CHR_m, CTR_CLOSE_EM, PCT_PERIOD, CTR_BUTTON, CTR_END, CTR_ENDLINE};

// {begin}{endline}
static s16 scenario_text_0B20[] = {CTR_BEGIN, CTR_ENDLINE};

// Kihachi:Hmmmmmm...{button}{endline}
static s16 scenario_text_0B34[] = {
    CHR_K, CHR_i, CHR_h, CHR_a, CHR_c,
    CHR_h, CHR_i, PCT_COLON, CHR_H, CHR_m,
    CHR_m, CHR_m, CHR_m, CHR_m, CHR_m,
    PCT_PERIOD, PCT_PERIOD, PCT_PERIOD, CTR_BUTTON, CTR_ENDLINE};

// {newwindow}{endline}
static s16 scenario_text_0B5B[] = {CTR_NEWWINDOW, CTR_ENDLINE};

// Kihachi:It's so hard to say no{newline}{endline}
static s16 scenario_text_0B73[] = {
    CHR_K, CHR_i, CHR_h, CHR_a, CHR_c, CHR_h,
    CHR_i, PCT_COLON, CHR_I, CHR_t, PCT_APOSTROPHE, CHR_s,
    PCT_SPACE, CHR_s, CHR_o, PCT_SPACE, CHR_h, CHR_a,
    CHR_r, CHR_d, PCT_SPACE, CHR_t, CHR_o, PCT_SPACE,
    CHR_s, CHR_a, CHR_y, PCT_SPACE, CHR_n, CHR_o,
    CTR_NEWLINE, CTR_ENDLINE};

//       to someone so {em-yellow}cute{/em}{newline}{endline}
static s16 scenario_text_0BA7[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE,
    CHR_t, CHR_o, PCT_SPACE, CHR_s, CHR_o, CHR_m,
    CHR_e, CHR_o, CHR_n, CHR_e, PCT_SPACE, CHR_s,
    CHR_o, PCT_SPACE, CTR_EM_YELLOW, CHR_c, CHR_u, CHR_t,
    CHR_e, CTR_CLOSE_EM, CTR_NEWLINE, CTR_ENDLINE};

//       as you.{newline}{endline}
static s16 scenario_text_0BE5[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE,
    PCT_SPACE, CHR_a, CHR_s, PCT_SPACE, CHR_y,
    CHR_o, CHR_u, PCT_PERIOD, CTR_NEWLINE, CTR_ENDLINE};

// {button}{end}{endline}
static s16 scenario_text_0C08[] = {CTR_BUTTON, CTR_END, CTR_ENDLINE};

// Address: @d41c

// {begin}{endline}
static s16 scenario_text_0C22[] = {CTR_BEGIN, CTR_ENDLINE};

// Kihachi:{em-yellow}Cucumber{/em}...{endline}
static s16 scenario_text_0C36[] = {
    CHR_K, CHR_i, CHR_h, CHR_a, CHR_c, CHR_h,
    CHR_i, PCT_COLON, CTR_EM_YELLOW, CHR_C, CHR_u, CHR_c,
    CHR_u, CHR_m, CHR_b, CHR_e, CHR_r, CTR_CLOSE_EM,
    PCT_PERIOD, PCT_PERIOD, PCT_PERIOD, CTR_ENDLINE};

// {waitinput}{end}{endline}
static s16 scenario_text_0C66[] = {CTR_WAITINPUT, CTR_END, CTR_ENDLINE};

// Address: @d45c

// Kihachi:{em-yellow}Cucumber{/em} that{newline}{endline}
static s16 scenario_text_0C83[] = {
    CHR_K, CHR_i, CHR_h, CHR_a, CHR_c,
    CHR_h, CHR_i, PCT_COLON, CTR_EM_YELLOW, CHR_C,
    CHR_u, CHR_c, CHR_u, CHR_m, CHR_b,
    CHR_e, CHR_r, CTR_CLOSE_EM, PCT_SPACE, CHR_t,
    CHR_h, CHR_a, CHR_t, CTR_NEWLINE, CTR_ENDLINE};

//       the {em-yellow}priest's son{/em} makes...{endline}
static s16 scenario_text_0CBE[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE,
    PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE,
    CTR_EM_YELLOW, CHR_p, CHR_r, CHR_i, CHR_e,
    CHR_s, CHR_t, PCT_APOSTROPHE, CHR_s, PCT_SPACE,
    CHR_s, CHR_o, CHR_n, CTR_CLOSE_EM, PCT_SPACE,
    CHR_m, CHR_a, CHR_k, CHR_e, CHR_s,
    PCT_PERIOD, PCT_PERIOD, PCT_PERIOD, CTR_ENDLINE};

// {waitinput}{end}{endline}
static s16 scenario_text_0CFA[] = {CTR_WAITINPUT, CTR_END, CTR_ENDLINE};

// Address: @d490

// Kihachi:Yes! That's it!{button}{end}{endline}
static s16 scenario_text_0D17[] = {
    CHR_K, CHR_i, CHR_h, CHR_a, CHR_c, CHR_h,
    CHR_i, PCT_COLON, CHR_Y, CHR_e, CHR_s, PCT_EXCLAMATION,
    PCT_SPACE, CHR_T, CHR_h, CHR_a, CHR_t, PCT_APOSTROPHE,
    CHR_s, PCT_SPACE, CHR_i, CHR_t, PCT_EXCLAMATION, CTR_BUTTON,
    CTR_END, CTR_ENDLINE};

// {begin}{endline}
static s16 scenario_text_0D48[] = {CTR_BEGIN, CTR_ENDLINE};

// Goemon and allies trade their{newline}{endline}
static s16 scenario_text_0D5C[] = {
    CHR_G, CHR_o, CHR_e, CHR_m, CHR_o, CHR_n, PCT_SPACE,
    CHR_a, CHR_n, CHR_d, PCT_SPACE, CHR_a, CHR_l, CHR_l,
    CHR_i, CHR_e, CHR_s, PCT_SPACE, CHR_t, CHR_r, CHR_a,
    CHR_d, CHR_e, PCT_SPACE, CHR_t, CHR_h, CHR_e, CHR_i,
    CHR_r, CTR_NEWLINE, CTR_ENDLINE};

// {em-yellow}quality cucumber{/em} with{newline}{endline}
static s16 scenario_text_0D8F[] = {
    CTR_EM_YELLOW, CHR_q, CHR_u, CHR_a, CHR_l,
    CHR_i, CHR_t, CHR_y, PCT_SPACE, CHR_c,
    CHR_u, CHR_c, CHR_u, CHR_m, CHR_b,
    CHR_e, CHR_r, CTR_CLOSE_EM, PCT_SPACE, CHR_w,
    CHR_i, CHR_t, CHR_h, CTR_NEWLINE, CTR_ENDLINE};

// Kihachi's [{em-yellow}Miracle Item{/em}].{button}{end}{endline}
static s16 scenario_text_0DCA[] = {
    CHR_K, CHR_i, CHR_h, CHR_a, CHR_c,
    CHR_h, CHR_i, PCT_APOSTROPHE, CHR_s, PCT_SPACE,
    PCT_LBRACKET, CTR_EM_YELLOW, CHR_M, CHR_i, CHR_r,
    CHR_a, CHR_c, CHR_l, CHR_e, PCT_SPACE,
    CHR_I, CHR_t, CHR_e, CHR_m, CTR_CLOSE_EM,
    PCT_RBRACKET, PCT_PERIOD, CTR_BUTTON, CTR_END, CTR_ENDLINE};

// {begin}{endline}
static s16 scenario_text_0E0D[] = {CTR_BEGIN, CTR_ENDLINE};

// {newwindow}{endline}
static s16 scenario_text_0E21[] = {CTR_NEWWINDOW, CTR_ENDLINE};

//  Goemon and allies{newline}{endline}
static s16 scenario_text_0E39[] = {
    PCT_SPACE, CHR_G, CHR_o, CHR_e, CHR_m, CHR_o, CHR_n,
    PCT_SPACE, CHR_a, CHR_n, CHR_d, PCT_SPACE, CHR_a, CHR_l,
    CHR_l, CHR_i, CHR_e, CHR_s, CTR_NEWLINE, CTR_ENDLINE};

//   receive the [{em-yellow}Miracle Snow{/em}], {newline}{endline}
static s16 scenario_text_0E61[] = {
    PCT_SPACE, PCT_SPACE, CHR_r, CHR_e, CHR_c,
    CHR_e, CHR_i, CHR_v, CHR_e, PCT_SPACE,
    CHR_t, CHR_h, CHR_e, PCT_SPACE, PCT_LBRACKET,
    CTR_EM_YELLOW, CHR_M, CHR_i, CHR_r, CHR_a,
    CHR_c, CHR_l, CHR_e, PCT_SPACE, CHR_S,
    CHR_n, CHR_o, CHR_w, CTR_CLOSE_EM, PCT_RBRACKET,
    PCT_COMMA, PCT_SPACE, CTR_NEWLINE, CTR_ENDLINE};

//      shaped like a snow flake.{endline}
static s16 scenario_text_0EA5[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_s, CHR_h,
    CHR_a, CHR_p, CHR_e, CHR_d, PCT_SPACE, CHR_l, CHR_i,
    CHR_k, CHR_e, PCT_SPACE, CHR_a, PCT_SPACE, CHR_s, CHR_n,
    CHR_o, CHR_w, PCT_SPACE, CHR_f, CHR_l, CHR_a, CHR_k,
    CHR_e, PCT_PERIOD, CTR_ENDLINE};

// {end}{endline}
static s16 scenario_text_0ED0[] = {CTR_END, CTR_ENDLINE};

// {begin}{endline}
static s16 scenario_text_0EE2[] = {CTR_BEGIN, CTR_ENDLINE};

// {newwindow}{endline}
static s16 scenario_text_0EF6[] = {CTR_NEWWINDOW, CTR_ENDLINE};

// Kihachi:Farewell!{endline}
static s16 scenario_text_0F0E[] = {
    CHR_K, CHR_i, CHR_h, CHR_a, CHR_c, CHR_h,
    CHR_i, PCT_COLON, CHR_F, CHR_a, CHR_r, CHR_e,
    CHR_w, CHR_e, CHR_l, CHR_l, PCT_EXCLAMATION, CTR_ENDLINE};

// {button}{end}{endline}
static s16 scenario_text_0F2C[] = {CTR_BUTTON, CTR_END, CTR_ENDLINE};

// Address: @d63c

// Kihachi:Eating cucumber{newline}{endline}
static s16 scenario_text_0F46[] = {
    CHR_K, CHR_i, CHR_h, CHR_a, CHR_c, CHR_h, CHR_i,
    PCT_COLON, CHR_E, CHR_a, CHR_t, CHR_i, CHR_n, CHR_g,
    PCT_SPACE, CHR_c, CHR_u, CHR_c, CHR_u, CHR_m, CHR_b,
    CHR_e, CHR_r, CTR_NEWLINE, CTR_ENDLINE};

//       while watching{newline}{endline}
static s16 scenario_text_0F73[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE,
    CHR_w, CHR_h, CHR_i, CHR_l, CHR_e, PCT_SPACE,
    CHR_w, CHR_a, CHR_t, CHR_c, CHR_h, CHR_i,
    CHR_n, CHR_g, CTR_NEWLINE, CTR_ENDLINE};

//       the Big Sacred Fire...{button}{endline}
static s16 scenario_text_0F9D[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE,
    CHR_t, CHR_h, CHR_e, PCT_SPACE, CHR_B, CHR_i,
    CHR_g, PCT_SPACE, CHR_S, CHR_a, CHR_c, CHR_r,
    CHR_e, CHR_d, PCT_SPACE, CHR_F, CHR_i, CHR_r,
    CHR_e, PCT_PERIOD, PCT_PERIOD, PCT_PERIOD, CTR_BUTTON, CTR_ENDLINE};

// {newwindow}{endline}
static s16 scenario_text_0FCE[] = {CTR_NEWWINDOW, CTR_ENDLINE};

// Kihachi:Nothing could match{newline}{endline}
static s16 scenario_text_0FE6[] = {
    CHR_K, CHR_i, CHR_h, CHR_a, CHR_c, CHR_h, CHR_i, PCT_COLON,
    CHR_N, CHR_o, CHR_t, CHR_h, CHR_i, CHR_n, CHR_g, PCT_SPACE,
    CHR_c, CHR_o, CHR_u, CHR_l, CHR_d, PCT_SPACE, CHR_m, CHR_a,
    CHR_t, CHR_c, CHR_h, CTR_NEWLINE, CTR_ENDLINE};

//       this...{endline}
static s16 scenario_text_1017[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE,
    PCT_SPACE, CHR_t, CHR_h, CHR_i, CHR_s,
    PCT_PERIOD, PCT_PERIOD, PCT_PERIOD, CTR_ENDLINE};

// {waitinput}{end}{endline}
static s16 scenario_text_1031[] = {CTR_WAITINPUT, CTR_END, CTR_ENDLINE};

extern s32 scenario_code_message_162_cd8c[];
extern s32 scenario_code_message_162_ce64[];
extern s32 scenario_code_message_162_ced0[];
extern s32 scenario_code_message_162_cf44[];
extern s32 scenario_code_message_162_cfb0[];
extern s32 scenario_code_message_162_d024[];
extern s32 scenario_code_message_162_d41c[];
extern s32 scenario_code_message_162_d45c[];
extern s32 scenario_code_message_162_d490[];
extern s32 scenario_code_message_162_d63c[];
extern void check_cucumber_and_set_flag(void);
s32 scenario_code_message_162_cd8c[] = {

    // Address: @cd8c

    // cd8c: Write to RAM 801c7770 (Unknown)
    STW,
    (s32)&D_801C7770_1C8370,

    // cd94: Store Value: 1
    WTS,
    0x1,

    // cd9c: Print Text
    TXT,
    (s32)&scenario_text_0000,

    // cda4: If Flag 035 (Obtained Miracle Snow), Jump To @d63c
    // Jump if flag 0x35 is SET to @d63c
    JFS,
    0x35,
    (s32)&scenario_code_message_162_d63c,

    // Execute subroutine to check Cucumber and set flag 0x501
    ESR,
    (s32)check_cucumber_and_set_flag,

    // cdb0: If Flag 0x501 (Received Cucumber), Jump To @d490
    // Jump if flag 0x501 is SET to @d490
    JFS,
    0x501,
    (s32)&scenario_code_message_162_d490,

    // Clear temporary flag 0x501
    CFG,
    0x501,

    // cdbc: If Flag 037 (Kihachi Will Give Favorite Food Hint), Jump To @d41c
    // Jump if flag 0x37 is SET to @d41c
    JFS,
    0x37,
    (s32)&scenario_code_message_162_d41c,

    // cdc8: Print Text
    TXT,
    (s32)&scenario_text_0014,

    // cdd0: Print Text
    TXT,
    (s32)&scenario_text_0038,

    // cdd8: Print Text
    TXT,
    (s32)&scenario_text_0050,

    // cde0: Print Text
    TXT,
    (s32)&scenario_text_007F,

    // cde8: Set Flag 003 (???)
    SFG,
    0x03,

    // cdf0: Execute Code: 8003f594 (Load Current Character)
    ESR,
    (s32)&func_8003F594_40194,

    // cdf8: Read from RAM 801c7750 (Scratch)
    LDW,
    0x801c7750,

    // ce00: Skip Next If Not Equal: 0
    SNE,
    0x0,

    // ce08: Jump To @ce64
    JMP,
    (s32)&scenario_code_message_162_ce64,

    // ce10: Read from RAM 801c7750 (Scratch)
    LDW,
    0x801c7750,

    // ce18: Skip Next If Not Equal: 1
    SNE,
    0x1,

    // ce20: Jump To @ced0
    JMP,
    (s32)&scenario_code_message_162_ced0,

    // ce28: Read from RAM 801c7750 (Scratch)
    LDW,
    0x801c7750,

    // ce30: Skip Next If Not Equal: 3
    SNE,
    0x3,

    // ce38: Jump To @cf44
    JMP,
    (s32)&scenario_code_message_162_cf44,

    // ce40: Read from RAM 801c7750 (Scratch)
    LDW,
    0x801c7750,

    // ce48: Skip Next If Not Equal: 2
    SNE,
    0x2,

    // ce50: Jump To @cfb0
    JMP,
    (s32)&scenario_code_message_162_cfb0,

    // ce58: Print Text
    TXT,
    (s32)&scenario_text_00C6,

    // ce60: End Event
    END,
};

s32 scenario_code_message_162_ce64[] = {

    // Address: @ce64

    // ce64: Write to RAM 801c7768 (Dialogue Window Style)
    STW,
    (s32)&D_801C7768_1C8368,

    // ce6c: Store Value: 7
    WTS,
    0x7,

    // ce74: Write to RAM 8007785c (Dialogue Portrait Character)
    STW,
    (s32)&D_8007785C_7845C,

    // ce7c: Store Value: 0
    WTS,
    0x0,

    // ce84: Print Text
    TXT,
    (s32)&scenario_text_0000,

    // ce8c: Write to RAM 801c7770 (Unknown)
    STW,
    (s32)&D_801C7770_1C8370,

    // ce94: Store Value: 1
    WTS,
    0x1,

    // ce9c: Print Text
    TXT,
    (s32)&scenario_text_00F7,

    // cea4: Print Text
    TXT,
    (s32)&scenario_text_0038,

    // ceac: Print Text
    TXT,
    (s32)&scenario_text_0141,

    // ceb4: Print Text
    TXT,
    (s32)&scenario_text_016D,

    // cebc: Print Text
    TXT,
    (s32)&scenario_text_01AE,

    // cec4: Jump To @d024
    JMP,
    (s32)&scenario_code_message_162_d024,

    // cecc: End Event
    END,
};

s32 scenario_code_message_162_ced0[] = {

    // Address: @ced0

    // ced0: Write to RAM 801c7768 (Dialogue Window Style)
    STW,
    (s32)&D_801C7768_1C8368,

    // ced8: Store Value: 7
    WTS,
    0x7,

    // cee0: Write to RAM 8007785c (Dialogue Portrait Character)
    STW,
    (s32)&D_8007785C_7845C,

    // cee8: Store Value: 2
    WTS,
    0x2,

    // cef0: Print Text
    TXT,
    (s32)&scenario_text_0000,

    // cef8: Write to RAM 801c7770 (Unknown)
    STW,
    (s32)&D_801C7770_1C8370,

    // cf00: Store Value: 1
    WTS,
    0x1,

    // cf08: Print Text
    TXT,
    (s32)&scenario_text_01E7,

    // cf10: Print Text
    TXT,
    (s32)&scenario_text_0218,

    // cf18: Print Text
    TXT,
    (s32)&scenario_text_0038,

    // cf20: Print Text
    TXT,
    (s32)&scenario_text_0258,

    // cf28: Print Text
    TXT,
    (s32)&scenario_text_028D,

    // cf30: Print Text
    TXT,
    (s32)&scenario_text_02D2,

    // cf38: Jump To @d024
    JMP,
    (s32)&scenario_code_message_162_d024,

    // cf40: End Event
    END,

};

s32 scenario_code_message_162_cf44[] = {

    // Address: @cf44

    // cf44: Write to RAM 801c7768 (Dialogue Window Style)
    STW,
    (s32)&D_801C7768_1C8368,

    // cf4c: Store Value: 7
    WTS,
    0x7,

    // cf54: Write to RAM 8007785c (Dialogue Portrait Character)
    STW,
    (s32)&D_8007785C_7845C,

    // cf5c: Store Value: 6
    WTS,
    0x6,

    // cf64: Print Text
    TXT,
    (s32)&scenario_text_0000,

    // cf6c: Write to RAM 801c7770 (Unknown)
    STW,
    (s32)&D_801C7770_1C8370,

    // cf74: Store Value: 1
    WTS,
    0x1,

    // cf7c: Print Text
    TXT,
    (s32)&scenario_text_031D,

    // cf84: Print Text
    TXT,
    (s32)&scenario_text_0038,

    // cf8c: Print Text
    TXT,
    (s32)&scenario_text_0368,

    // cf94: Print Text
    TXT,
    (s32)&scenario_text_0395,

    // cf9c: Print Text
    TXT,
    (s32)&scenario_text_03DB,

    // cfa4: Jump To @d024
    JMP,
    (s32)&scenario_code_message_162_d024,

    // cfac: End Event
    END,
};

s32 scenario_code_message_162_cfb0[] = {

    // Address: @cfb0

    // cfb0: Write to RAM 801c7768 (Dialogue Window Style)
    STW,
    (s32)&D_801C7768_1C8368,

    // cfb8: Store Value: 7
    WTS,
    0x7,

    // cfc0: Write to RAM 8007785c (Dialogue Portrait Character)
    STW,
    (s32)&D_8007785C_7845C,

    // cfc8: Store Value: 4
    WTS,
    0x4,

    // cfd0: Print Text
    TXT,
    (s32)&scenario_text_0000,

    // cfd8: Write to RAM 801c7770 (Unknown)
    STW,
    (s32)&D_801C7770_1C8370,

    // cfe0: Store Value: 1
    WTS,
    0x1,

    // cfe8: Print Text
    TXT,
    (s32)&scenario_text_041B,

    // cff0: Print Text
    TXT,
    (s32)&scenario_text_0443,

    // cff8: Print Text
    TXT,
    (s32)&scenario_text_0038,

    // d000: Print Text
    TXT,
    (s32)&scenario_text_0488,

    // d008: Print Text
    TXT,
    (s32)&scenario_text_04BE,

    // d010: Print Text
    TXT,
    (s32)&scenario_text_0503,

    // d018: Jump To @d024
    JMP,
    (s32)&scenario_code_message_162_d024,

    // d020: End Event
    END,

};

s32 scenario_code_message_162_d024[] = {

    // Address: @d024

    // d024: Write to RAM 801c7768 (Dialogue Window Style)
    STW,
    (s32)&D_801C7768_1C8368,

    // d02c: Store Value: 1
    WTS,
    0x1,

    // d034: Write to RAM 8007785c (Dialogue Portrait Character)
    STW,
    (s32)&D_8007785C_7845C,

    // d03c: Store Value: 100
    WTS,
    0x100,

    // d044: Print Text
    TXT,
    (s32)&scenario_text_0000,

    // d04c: Write to RAM 801c7770 (Unknown)
    STW,
    (s32)&D_801C7770_1C8370,

    // d054: Store Value: 1
    WTS,
    0x1,

    // d05c: Print Text
    TXT,
    (s32)&scenario_text_054D,

    // d064: Print Text
    TXT,
    (s32)&scenario_text_0573,

    // d06c: Print Text
    TXT,
    (s32)&scenario_text_05A8,

    // d074: Print Text
    TXT,
    (s32)&scenario_text_05ED,

    // d07c: Write to RAM 801c7768 (Dialogue Window Style)
    STW,
    (s32)&D_801C7768_1C8368,

    // d084: Store Value: 7
    WTS,
    0x7,

    // d08c: Write to RAM 8007785c (Dialogue Portrait Character)
    STW,
    (s32)&D_8007785C_7845C,

    // d094: Store Value: 0
    WTS,
    0x0,

    // d09c: Print Text
    TXT,
    (s32)&scenario_text_0000,

    // d0a4: Write to RAM 801c7770 (Unknown)
    STW,
    (s32)&D_801C7770_1C8370,

    // d0ac: Store Value: 1
    WTS,
    0x1,

    // d0b4: Print Text
    TXT,
    (s32)&scenario_text_062F,

    // d0bc: Print Text
    TXT,
    (s32)&scenario_text_065B,

    // d0c4: Print Text
    TXT,
    (s32)&scenario_text_0686,

    // d0cc: Set Flag 004 (???)
    SFG,
    0x04,

    // d0d4: Write to RAM 801c7768 (Dialogue Window Style)
    STW,
    (s32)&D_801C7768_1C8368,

    // d0dc: Store Value: 1
    WTS,
    0x1,

    // d0e4: Write to RAM 8007785c (Dialogue Portrait Character)
    STW,
    (s32)&D_8007785C_7845C,

    // d0ec: Store Value: 100
    WTS,
    0x100,

    // d0f4: Print Text
    TXT,
    (s32)&scenario_text_0000,

    // d0fc: Write to RAM 801c7770 (Unknown)
    STW,
    (s32)&D_801C7770_1C8370,

    // d104: Store Value: 1
    WTS,
    0x1,

    // d10c: Print Text
    TXT,
    (s32)&scenario_text_06D0,

    // d114: Print Text
    TXT,
    (s32)&scenario_text_06F7,

    // d11c: Print Text
    TXT,
    (s32)&scenario_text_0729,

    // d124: Print Text
    TXT,
    (s32)&scenario_text_0038,

    // d12c: Print Text
    TXT,
    (s32)&scenario_text_0776,

    // d134: Print Text
    TXT,
    (s32)&scenario_text_07A8,

    // d13c: Print Text
    TXT,
    (s32)&scenario_text_07E9,

    // d144: Print Text
    TXT,
    (s32)&scenario_text_0038,

    // d14c: Print Text
    TXT,
    (s32)&scenario_text_0826,

    // d154: Print Text
    TXT,
    (s32)&scenario_text_0858,

    // d15c: Write to RAM 801c7768 (Dialogue Window Style)
    STW,
    (s32)&D_801C7768_1C8368,

    // d164: Store Value: 7
    WTS,
    0x7,

    // d16c: Write to RAM 8007785c (Dialogue Portrait Character)
    STW,
    (s32)&D_8007785C_7845C,

    // d174: Store Value: 2
    WTS,
    0x2,

    // d17c: Print Text
    TXT,
    (s32)&scenario_text_0000,

    // d184: Write to RAM 801c7770 (Unknown)
    STW,
    (s32)&D_801C7770_1C8370,

    // d18c: Store Value: 1
    WTS,
    0x1,

    // d194: Print Text
    TXT,
    (s32)&scenario_text_089C,

    // d19c: Print Text
    TXT,
    (s32)&scenario_text_08CE,

    // d1a4: Print Text
    TXT,
    (s32)&scenario_text_0903,

    // d1ac: Print Text
    TXT,
    (s32)&scenario_text_0943,

    // d1b4: Print Text
    TXT,
    (s32)&scenario_text_0038,

    // d1bc: Write to RAM 801c7740 (Scratch)
    STW,
    (s32)&D_801C7740_1C8340,

    // d1c4: Store Value: 142
    WTS,
    0x142,

    // d1cc: Execute Code: 8003f608 (Play Sound)
    ESR,
    (s32)&func_8003F608_40208,

    // d1d4: Write to RAM 8007785c (Dialogue Portrait Character)
    STW,
    (s32)&D_8007785C_7845C,

    // d1dc: Store Value: 0
    WTS,
    0x0,

    // d1e4: Print Text
    TXT,
    (s32)&scenario_text_097C,

    // d1ec: Set Flag 05e (???)
    SFG,
    0x5E,

    // d1f4: Write to RAM 801c7768 (Dialogue Window Style)
    STW,
    (s32)&D_801C7768_1C8368,

    // d1fc: Store Value: 1
    WTS,
    0x1,

    // d204: Write to RAM 8007785c (Dialogue Portrait Character)
    STW,
    (s32)&D_8007785C_7845C,

    // d20c: Store Value: 100
    WTS,
    0x100,

    // d214: Print Text
    TXT,
    (s32)&scenario_text_0000,

    // d21c: Write to RAM 801c7770 (Unknown)
    STW,
    (s32)&D_801C7770_1C8370,

    // d224: Store Value: 1
    WTS,
    0x1,

    // d22c: Print Text
    TXT,
    (s32)&scenario_text_09C4,

    // d234: Print Text
    TXT,
    (s32)&scenario_text_09EE,

    // d23c: Print Text
    TXT,
    (s32)&scenario_text_0A20,

    // d244: Print Text
    TXT,
    (s32)&scenario_text_0A53,

    // d24c: Write to RAM 801c7768 (Dialogue Window Style)
    STW,
    (s32)&D_801C7768_1C8368,

    // d254: Store Value: 7
    WTS,
    0x7,

    // d25c: Write to RAM 8007785c (Dialogue Portrait Character)
    STW,
    (s32)&D_8007785C_7845C,

    // d264: Store Value: 6
    WTS,
    0x6,

    // d26c: Print Text
    TXT,
    (s32)&scenario_text_0000,

    // d274: Write to RAM 801c7770 (Unknown)
    STW,
    (s32)&D_801C7770_1C8370,

    // d27c: Store Value: 1
    WTS,
    0x1,

    // d284: Print Text
    TXT,
    (s32)&scenario_text_0AAB,

    // d28c: Print Text
    TXT,
    (s32)&scenario_text_0AD7,

    // d294: Set Flag 003 (???)
    SFG,
    0x03,

    // d29c: Write to RAM 801c7768 (Dialogue Window Style)
    STW,
    (s32)&D_801C7768_1C8368,

    // d2a4: Store Value: 1
    WTS,
    0x1,

    // d2ac: Write to RAM 8007785c (Dialogue Portrait Character)
    STW,
    (s32)&D_8007785C_7845C,

    // d2b4: Store Value: 100
    WTS,
    0x100,

    // d2bc: Print Text
    TXT,
    (s32)&scenario_text_0000,

    // d2c4: Write to RAM 801c7770 (Unknown)
    STW,
    (s32)&D_801C7770_1C8370,

    // d2cc: Store Value: 1
    WTS,
    0x1,

    // d2d4: Print Text
    TXT,
    (s32)&scenario_text_0B34,

    // d2dc: Print Text
    TXT,
    (s32)&scenario_text_0038,

    // d2e4: Print Text
    TXT,
    (s32)&scenario_text_0B73,

    // d2ec: Print Text
    TXT,
    (s32)&scenario_text_0BA7,

    // d2f4: Print Text
    TXT,
    (s32)&scenario_text_0BE5,

    // d2fc: Write to RAM 801c7740 (Scratch)
    STW,
    (s32)&D_801C7740_1C8340,

    // d304: Store Value: 141
    WTS,
    0x141,

    // d30c: Execute Code: 8003f608 (Play Sound)
    ESR,
    (s32)&func_8003F608_40208,

    // d314: Print Text
    TXT,
    (s32)&scenario_text_0C08,

    // d31c: End Event
    END,

};

s32 scenario_code_message_162_d41c[] = {

    // Address: @d41c

    // d41c: Print Text
    TXT,
    (s32)&scenario_text_0000,

    // d424: Write to RAM 801c7770 (Unknown)
    STW,
    (s32)&D_801C7770_1C8370,

    // d42c: Store Value: 1
    WTS,
    0x1,

    // d434: If Flag 038 (Kihachi Gave Favorite Food Hint), Jump To @d45c
    // Jump if flag 0x38 is SET to @d45c
    JFS,
    0x38,
    (s32)&scenario_code_message_162_d45c,

    // d440: Print Text
    TXT,
    (s32)&scenario_text_0C36,

    // d448: Set Flag 038 (Kihachi Gave Favorite Food Hint)
    SFG,
    0x38,

    // d450: Print Text
    TXT,
    (s32)&scenario_text_00C6,

    // d458: End Event
    END,

};

s32 scenario_code_message_162_d45c[] = {

    // Address: @d45c

    // d45c: Write to RAM 801c7770 (Unknown)
    STW,
    (s32)&D_801C7770_1C8370,

    // d464: Store Value: 1
    WTS,
    0x1,

    // d46c: Print Text
    TXT,
    (s32)&scenario_text_0C83,

    // d474: Print Text
    TXT,
    (s32)&scenario_text_0CBE,

    // d47c: Set Flag 024 (Learned Kihachi's Favorite Food)
    SFG,
    0x24,

    // d484: Print Text
    TXT,
    (s32)&scenario_text_00C6,

    // d48c: End Event
    END,

};

s32 scenario_code_message_162_d490[] = {

    // Address: @d490

    // Clear temporary flag 0x501
    CFG,
    0x501,

    // d490: Write to RAM 801c7770 (Unknown)
    STW,
    (s32)&D_801C7770_1C8370,

    // d498: Store Value: 1
    WTS,
    0x1,

    // d4a0: Print Text
    TXT,
    (s32)&scenario_text_0D17,

    // d4a8: Write to RAM 801c7758 (Unknown)
    STW,
    (s32)&D_801C7758_1C8358,

    // d4b0: Store Value: 20
    WTS,
    0x20,

    // d4b8: Write to RAM 801c775c (Dialogue Window Y Pos)
    STW,
    (s32)&D_801C775C_1C835C,

    // d4c0: Store Value: 48
    WTS,
    0x48,

    // d4c8: Write to RAM 801c7768 (Dialogue Window Style)
    STW,
    (s32)&D_801C7768_1C8368,

    // d4d0: Store Value: 7
    WTS,
    0x7,

    // d4d8: Print Text
    TXT,
    (s32)&scenario_text_0000,

    // d4e0: Write to RAM 801c7770 (Unknown)
    STW,
    (s32)&D_801C7770_1C8370,

    // d4e8: Store Value: 1
    WTS,
    0x1,

    // d4f0: Write to RAM 801c7740 (Scratch)
    STW,
    (s32)&D_801C7740_1C8340,

    // d4f8: Store Value: 26c
    WTS,
    0x26C,

    // d500: Execute Code: 8003f608 (Play Sound)
    ESR,
    (s32)&func_8003F608_40208,

    // d508: Print Text
    TXT,
    (s32)&scenario_text_0D5C,

    // d510: Print Text
    TXT,
    (s32)&scenario_text_0D8F,

    // d518: Print Text
    TXT,
    (s32)&scenario_text_0DCA,

    // d520: Write to RAM 801c7758 (Unknown)
    STW,
    (s32)&D_801C7758_1C8358,

    // d528: Store Value: 20
    WTS,
    0x20,

    // d530: Write to RAM 801c775c (Dialogue Window Y Pos)
    STW,
    (s32)&D_801C775C_1C835C,

    // d538: Store Value: 20
    WTS,
    0x20,

    // d540: Write to RAM 801c7768 (Dialogue Window Style)
    STW,
    (s32)&D_801C7768_1C8368,

    // d548: Store Value: 7
    WTS,
    0x7,

    // d550: Print Text
    TXT,
    (s32)&scenario_text_0000,

    // d558: Write to RAM 801c7770 (Unknown)
    STW,
    (s32)&D_801C7770_1C8370,

    // d560: Store Value: 1
    WTS,
    0x1,

    // d568: Print Text
    TXT,
    (s32)&scenario_text_0038,

    // d570: Write to RAM 801c7740 (Scratch)
    STW,
    (s32)&D_801C7740_1C8340,

    // d578: Store Value: 14
    WTS,
    0x14,

    // d580: Execute Code: 8003f608 (Play Sound)
    ESR,
    (s32)&func_8003F608_40208,

    // d588: Print Text
    TXT,
    (s32)&scenario_text_0E39,

    // d590: Print Text
    TXT,
    (s32)&scenario_text_0E61,

    // d598: Print Text
    TXT,
    (s32)&scenario_text_0EA5,

    // d5a0: Write to RAM 801c7740 (Scratch)
    STW,
    (s32)&D_801C7740_1C8340,

    // d5a8: Store Value: 96
    WTS,
    0x96,

    // d5b0: Execute Code: 8003f460 (Wait For Timer)
    ESR,
    (s32)&func_8003F460_40060,

    // d5b8: Print Text
    TXT,
    (s32)&scenario_text_0ED0,

    // d5c0: Write to RAM 8015c864 (Obtained Miracle Snow)
    STW,
    0x8015c864,

    // d5c8: Store Value: 1
    WTS,
    0x1,
    // We patch this in here so we can always complete the rest of the quest
    // d47c: Set Flag 024 (Learned Kihachi's Favorite Food)
    SFG,
    0x22,
    // d5d0: Set Flag 035 (Obtained Miracle Snow)
    SFG,
    0x35,

    // d5d8: Write to RAM 801c7758 (Unknown)
    STW,
    (s32)&D_801C7758_1C8358,

    // d5e0: Store Value: 20
    WTS,
    0x20,

    // d5e8: Write to RAM 801c775c (Dialogue Window Y Pos)
    STW,
    (s32)&D_801C775C_1C835C,

    // d5f0: Store Value: 20
    WTS,
    0x20,

    // d5f8: Write to RAM 801c7768 (Dialogue Window Style)
    STW,
    (s32)&D_801C7768_1C8368,

    // d600: Store Value: 1
    WTS,
    0x1,

    // d608: Print Text
    TXT,
    (s32)&scenario_text_0000,

    // d610: Write to RAM 801c7770 (Unknown)
    STW,
    (s32)&D_801C7770_1C8370,

    // d618: Store Value: 1
    WTS,
    0x1,

    // d620: Print Text
    TXT,
    (s32)&scenario_text_0038,

    // d628: Print Text
    TXT,
    (s32)&scenario_text_0F0E,

    // d630: Print Text
    TXT,
    (s32)&scenario_text_0C08,

    // d638: End Event
    END,
};

s32 scenario_code_message_162_d63c[] = {

    // Address: @d63c

    // d63c: Set Flag 022 (Learned Kihachi's Favorite Food)
    SFG,
    0x22,

    // d644: Print Text
    TXT,
    (s32)&scenario_text_0F46,

    // d64c: Print Text
    TXT,
    (s32)&scenario_text_0F73,

    // d64c: Print Text
    TXT,
    (s32)&scenario_text_0F9D,

    // d654: Print Text
    TXT,
    (s32)&scenario_text_0038,

    // d65c: Print Text
    TXT,
    (s32)&scenario_text_0FE6,

    // d664: Print Text
    TXT,
    (s32)&scenario_text_1017,

    // d66c: Print Text
    TXT,
    (s32)&scenario_text_00C6,

    // d674: End Event
    END,

};
