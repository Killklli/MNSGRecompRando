// Patches out Ushiwaka events you're always able to fish and do mini ebismaru
#include "scenario.h"
#include "modding.h"
#include "recomputils.h"

#include "common.h"

// MACHI 21 - Zazen - Ushiwaka - Ushiwaka
// Address: @c028

// {begin}{endline}
static s16 scenario_text_0000[] = {
    CTR_BEGIN, CTR_ENDLINE
};

// Darn! I know there are {em-yellow}fish{/em} in{newline}{endline}
static s16 scenario_text_0014[] = {
    CHR_D, CHR_a, CHR_r, CHR_n, PCT_EXCLAMATION, PCT_SPACE, CHR_I, PCT_SPACE, CHR_k, CHR_n,
    CHR_o, CHR_w, PCT_SPACE, CHR_t, CHR_h, CHR_e, CHR_r, CHR_e, PCT_SPACE, CHR_a,
    CHR_r, CHR_e, PCT_SPACE, CTR_EM_YELLOW, CHR_f, CHR_i, CHR_s, CHR_h, CTR_CLOSE_EM, PCT_SPACE,
    CHR_i, CHR_n, CTR_NEWLINE, CTR_ENDLINE
};

// this Creek!{newline}{endline}
static s16 scenario_text_0058[] = {
    CHR_t, CHR_h, CHR_i, CHR_s, PCT_SPACE, CHR_C, CHR_r, CHR_e, CHR_e, CHR_k,
    PCT_EXCLAMATION, CTR_NEWLINE, CTR_ENDLINE
};

// But I haven't caught any!{endline}
static s16 scenario_text_0079[] = {
    CHR_B, CHR_u, CHR_t, PCT_SPACE, CHR_I, PCT_SPACE, CHR_h, CHR_a, CHR_v, CHR_e,
    CHR_n, PCT_APOSTROPHE, CHR_t, PCT_SPACE, CHR_c, CHR_a, CHR_u, CHR_g, CHR_h, CHR_t,
    PCT_SPACE, CHR_a, CHR_n, CHR_y, PCT_EXCLAMATION, CTR_ENDLINE
};

// {waitinput}{end}{endline}
static s16 scenario_text_009F[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE
};

// Address: @c0a8

// What?{newline}{endline}
static s16 scenario_text_00BC[] = {
    CHR_W, CHR_h, CHR_a, CHR_t, PCT_QUESTION, CTR_NEWLINE, CTR_ENDLINE
};

// Whaddya want?{newline}{endline}
static s16 scenario_text_00D7[] = {
    CHR_W, CHR_h, CHR_a, CHR_d, CHR_d, CHR_y, CHR_a, PCT_SPACE, CHR_w, CHR_a,
    CHR_n, CHR_t, PCT_QUESTION, CTR_NEWLINE, CTR_ENDLINE
};

//   {em-yellow}Who are you?{newline}{endline}
static s16 scenario_text_00FA[] = {
    PCT_SPACE, PCT_SPACE, CTR_EM_YELLOW, CHR_W, CHR_h, CHR_o, PCT_SPACE, CHR_a, CHR_r, CHR_e,
    PCT_SPACE, CHR_y, CHR_o, CHR_u, PCT_QUESTION, CTR_NEWLINE, CTR_ENDLINE
};

//   {em-yellow}Do you know Benkei?{newline}{endline}
static s16 scenario_text_0129[] = {
    PCT_SPACE, PCT_SPACE, CTR_EM_YELLOW, CHR_D, CHR_o, PCT_SPACE, CHR_y, CHR_o, CHR_u, PCT_SPACE,
    CHR_k, CHR_n, CHR_o, CHR_w, PCT_SPACE, CHR_B, CHR_e, CHR_n, CHR_k, CHR_e,
    CHR_i, PCT_QUESTION, CTR_NEWLINE, CTR_ENDLINE
};

// {end}{endline}
static s16 scenario_text_015F[] = {
    CTR_END, CTR_ENDLINE
};

// Address: @c0ec

// {newwindow}{endline}
static s16 scenario_text_0171[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// {/em}You've got a nerve asking me{newline}{endline}
static s16 scenario_text_0189[] = {
    CTR_CLOSE_EM, CHR_Y, CHR_o, CHR_u, PCT_APOSTROPHE, CHR_v, CHR_e, PCT_SPACE, CHR_g, CHR_o,
    CHR_t, PCT_SPACE, CHR_a, PCT_SPACE, CHR_n, CHR_e, CHR_r, CHR_v, CHR_e, PCT_SPACE,
    CHR_a, CHR_s, CHR_k, CHR_i, CHR_n, CHR_g, PCT_SPACE, CHR_m, CHR_e, CTR_NEWLINE,
    CTR_ENDLINE
};

// who I am!{newline}{endline}
static s16 scenario_text_01C0[] = {
    CHR_w, CHR_h, CHR_o, PCT_SPACE, CHR_I, PCT_SPACE, CHR_a, CHR_m, PCT_EXCLAMATION, CTR_NEWLINE,
    CTR_ENDLINE
};

// You don't recognize me?{button}{endline}
static s16 scenario_text_01DF[] = {
    CHR_Y, CHR_o, CHR_u, PCT_SPACE, CHR_d, CHR_o, CHR_n, PCT_APOSTROPHE, CHR_t, PCT_SPACE,
    CHR_r, CHR_e, CHR_c, CHR_o, CHR_g, CHR_n, CHR_i, CHR_z, CHR_e, PCT_SPACE,
    CHR_m, CHR_e, PCT_QUESTION, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_020B[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// I'm only telling you once, {newline}{endline}
static s16 scenario_text_0223[] = {
    CHR_I, PCT_APOSTROPHE, CHR_m, PCT_SPACE, CHR_o, CHR_n, CHR_l, CHR_y, PCT_SPACE, CHR_t,
    CHR_e, CHR_l, CHR_l, CHR_i, CHR_n, CHR_g, PCT_SPACE, CHR_y, CHR_o, CHR_u,
    PCT_SPACE, CHR_o, CHR_n, CHR_c, CHR_e, PCT_COMMA, PCT_SPACE, CTR_NEWLINE, CTR_ENDLINE
};

// keep your ears wide open!{button}{endline}
static s16 scenario_text_0254[] = {
    CHR_k, CHR_e, CHR_e, CHR_p, PCT_SPACE, CHR_y, CHR_o, CHR_u, CHR_r, PCT_SPACE,
    CHR_e, CHR_a, CHR_r, CHR_s, PCT_SPACE, CHR_w, CHR_i, CHR_d, CHR_e, PCT_SPACE,
    CHR_o, CHR_p, CHR_e, CHR_n, PCT_EXCLAMATION, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_0282[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// I'm {em-yellow}Ushiwaka{/em},{newline}{endline}
static s16 scenario_text_029A[] = {
    CHR_I, PCT_APOSTROPHE, CHR_m, PCT_SPACE, CTR_EM_YELLOW, CHR_U, CHR_s, CHR_h, CHR_i, CHR_w,
    CHR_a, CHR_k, CHR_a, CTR_CLOSE_EM, PCT_COMMA, CTR_NEWLINE, CTR_ENDLINE
};

// the {em-yellow}best-looking knight{/em} in{newline}{endline}
static s16 scenario_text_02CD[] = {
    CHR_t, CHR_h, CHR_e, PCT_SPACE, CTR_EM_YELLOW, CHR_b, CHR_e, CHR_s, CHR_t, PCT_DASH,
    CHR_l, CHR_o, CHR_o, CHR_k, CHR_i, CHR_n, CHR_g, PCT_SPACE, CHR_k, CHR_n,
    CHR_i, CHR_g, CHR_h, CHR_t, CTR_CLOSE_EM, PCT_SPACE, CHR_i, CHR_n, CTR_NEWLINE, CTR_ENDLINE
};

// the world!{newline}{endline}
static s16 scenario_text_030D[] = {
    CHR_t, CHR_h, CHR_e, PCT_SPACE, CHR_w, CHR_o, CHR_r, CHR_l, CHR_d, PCT_EXCLAMATION,
    CTR_NEWLINE, CTR_ENDLINE
};

// Now remember that!{endline}
static s16 scenario_text_032D[] = {
    CHR_N, CHR_o, CHR_w, PCT_SPACE, CHR_r, CHR_e, CHR_m, CHR_e, CHR_m, CHR_b,
    CHR_e, CHR_r, PCT_SPACE, CHR_t, CHR_h, CHR_a, CHR_t, PCT_EXCLAMATION, CTR_ENDLINE
};

// {waitinput}{end}{endline}
static s16 scenario_text_034C[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE
};

// Address: @c17c

// {newwindow}{endline}
static s16 scenario_text_0369[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// {/em}I told you I was only going to{newline}{endline}
static s16 scenario_text_0381[] = {
    CTR_CLOSE_EM, CHR_I, PCT_SPACE, CHR_t, CHR_o, CHR_l, CHR_d, PCT_SPACE, CHR_y, CHR_o,
    CHR_u, PCT_SPACE, CHR_I, PCT_SPACE, CHR_w, CHR_a, CHR_s, PCT_SPACE, CHR_o, CHR_n,
    CHR_l, CHR_y, PCT_SPACE, CHR_g, CHR_o, CHR_i, CHR_n, CHR_g, PCT_SPACE, CHR_t,
    CHR_o, CTR_NEWLINE, CTR_ENDLINE
};

// tell you once!{newline}{endline}
static s16 scenario_text_03BA[] = {
    CHR_t, CHR_e, CHR_l, CHR_l, PCT_SPACE, CHR_y, CHR_o, CHR_u, PCT_SPACE, CHR_o,
    CHR_n, CHR_c, CHR_e, PCT_EXCLAMATION, CTR_NEWLINE, CTR_ENDLINE
};

// I'm not telling you again!!{endline}
static s16 scenario_text_03DE[] = {
    CHR_I, PCT_APOSTROPHE, CHR_m, PCT_SPACE, CHR_n, CHR_o, CHR_t, PCT_SPACE, CHR_t, CHR_e,
    CHR_l, CHR_l, CHR_i, CHR_n, CHR_g, PCT_SPACE, CHR_y, CHR_o, CHR_u, PCT_SPACE,
    CHR_a, CHR_g, CHR_a, CHR_i, CHR_n, PCT_EXCLAMATION, PCT_EXCLAMATION, CTR_ENDLINE
};

// {waitinput}{end}{endline}
static s16 scenario_text_0406[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE
};

// Address: @c1a8

// {newwindow}{endline}
static s16 scenario_text_0423[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// {/em}Of course I do!{newline}{endline}
static s16 scenario_text_043B[] = {
    CTR_CLOSE_EM, CHR_O, CHR_f, PCT_SPACE, CHR_c, CHR_o, CHR_u, CHR_r, CHR_s, CHR_e,
    PCT_SPACE, CHR_I, PCT_SPACE, CHR_d, CHR_o, PCT_EXCLAMATION, CTR_NEWLINE, CTR_ENDLINE
};

// He's like a follower to me!{button}{endline}
static s16 scenario_text_0465[] = {
    CHR_H, CHR_e, PCT_APOSTROPHE, CHR_s, PCT_SPACE, CHR_l, CHR_i, CHR_k, CHR_e, PCT_SPACE,
    CHR_a, PCT_SPACE, CHR_f, CHR_o, CHR_l, CHR_l, CHR_o, CHR_w, CHR_e, CHR_r,
    PCT_SPACE, CHR_t, CHR_o, PCT_SPACE, CHR_m, CHR_e, PCT_EXCLAMATION, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_0495[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Wait a sec...{button}{endline}
static s16 scenario_text_04AD[] = {
    CHR_W, CHR_a, CHR_i, CHR_t, PCT_SPACE, CHR_a, PCT_SPACE, CHR_s, CHR_e, CHR_c,
    PCT_PERIOD, PCT_PERIOD, PCT_PERIOD, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_04CF[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// I bet you're trying to get across{newline}{endline}
static s16 scenario_text_04E7[] = {
    CHR_I, PCT_SPACE, CHR_b, CHR_e, CHR_t, PCT_SPACE, CHR_y, CHR_o, CHR_u, PCT_APOSTROPHE,
    CHR_r, CHR_e, PCT_SPACE, CHR_t, CHR_r, CHR_y, CHR_i, CHR_n, CHR_g, PCT_SPACE,
    CHR_t, CHR_o, PCT_SPACE, CHR_g, CHR_e, CHR_t, PCT_SPACE, CHR_a, CHR_c, CHR_r,
    CHR_o, CHR_s, CHR_s, CTR_NEWLINE, CTR_ENDLINE
};

// the {em-yellow}Gojo Ohashi Bridge{/em}{newline}{endline}
static s16 scenario_text_051E[] = {
    CHR_t, CHR_h, CHR_e, PCT_SPACE, CTR_EM_YELLOW, CHR_G, CHR_o, CHR_j, CHR_o, PCT_SPACE,
    CHR_O, CHR_h, CHR_a, CHR_s, CHR_h, CHR_i, PCT_SPACE, CHR_B, CHR_r, CHR_i,
    CHR_d, CHR_g, CHR_e, CTR_CLOSE_EM, CTR_NEWLINE, CTR_ENDLINE
};

// that {em-yellow}Benkei's blocking{/em}.{button}{endline}
static s16 scenario_text_055A[] = {
    CHR_t, CHR_h, CHR_a, CHR_t, PCT_SPACE, CTR_EM_YELLOW, CHR_B, CHR_e, CHR_n, CHR_k,
    CHR_e, CHR_i, PCT_APOSTROPHE, CHR_s, PCT_SPACE, CHR_b, CHR_l, CHR_o, CHR_c, CHR_k,
    CHR_i, CHR_n, CHR_g, CTR_CLOSE_EM, PCT_PERIOD, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_0596[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Am I right?{newline}{endline}
static s16 scenario_text_05AE[] = {
    CHR_A, CHR_m, PCT_SPACE, CHR_I, PCT_SPACE, CHR_r, CHR_i, CHR_g, CHR_h, CHR_t,
    PCT_QUESTION, CTR_NEWLINE, CTR_ENDLINE
};

//   {newline}{endline}
static s16 scenario_text_05CF[] = {
    PCT_SPACE, PCT_SPACE, CTR_NEWLINE, CTR_ENDLINE
};

//   {em-yellow}Uh, well, yes.{newline}{endline}
static s16 scenario_text_05E7[] = {
    PCT_SPACE, PCT_SPACE, CTR_EM_YELLOW, CHR_U, CHR_h, PCT_COMMA, PCT_SPACE, CHR_w, CHR_e, CHR_l,
    CHR_l, PCT_COMMA, PCT_SPACE, CHR_y, CHR_e, CHR_s, PCT_PERIOD, CTR_NEWLINE, CTR_ENDLINE
};

//   {em-yellow}Uh, no, not at all...{newline}{endline}
static s16 scenario_text_0618[] = {
    PCT_SPACE, PCT_SPACE, CTR_EM_YELLOW, CHR_U, CHR_h, PCT_COMMA, PCT_SPACE, CHR_n, CHR_o, PCT_COMMA,
    PCT_SPACE, CHR_n, CHR_o, CHR_t, PCT_SPACE, CHR_a, CHR_t, PCT_SPACE, CHR_a, CHR_l,
    CHR_l, PCT_PERIOD, PCT_PERIOD, PCT_PERIOD, CTR_NEWLINE, CTR_ENDLINE
};

// {end}{endline}
static s16 scenario_text_0650[] = {
    CTR_END, CTR_ENDLINE
};

// Address: @c23c

// {newwindow}{endline}
static s16 scenario_text_0662[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// {/em}Well, why didn't you tell me in{newline}{endline}
static s16 scenario_text_067A[] = {
    CTR_CLOSE_EM, CHR_W, CHR_e, CHR_l, CHR_l, PCT_COMMA, PCT_SPACE, CHR_w, CHR_h, CHR_y,
    PCT_SPACE, CHR_d, CHR_i, CHR_d, CHR_n, PCT_APOSTROPHE, CHR_t, PCT_SPACE, CHR_y, CHR_o,
    CHR_u, PCT_SPACE, CHR_t, CHR_e, CHR_l, CHR_l, PCT_SPACE, CHR_m, CHR_e, PCT_SPACE,
    CHR_i, CHR_n, CTR_NEWLINE, CTR_ENDLINE
};

// the first place?{button}{endline}
static s16 scenario_text_06B4[] = {
    CHR_t, CHR_h, CHR_e, PCT_SPACE, CHR_f, CHR_i, CHR_r, CHR_s, CHR_t, PCT_SPACE,
    CHR_p, CHR_l, CHR_a, CHR_c, CHR_e, PCT_QUESTION, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_06D9[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Just do me a favour, and I'll{newline}{endline}
static s16 scenario_text_06F1[] = {
    CHR_J, CHR_u, CHR_s, CHR_t, PCT_SPACE, CHR_d, CHR_o, PCT_SPACE, CHR_m, CHR_e,
    PCT_SPACE, CHR_a, PCT_SPACE, CHR_f, CHR_a, CHR_v, CHR_o, CHR_u, CHR_r, PCT_COMMA,
    PCT_SPACE, CHR_a, CHR_n, CHR_d, PCT_SPACE, CHR_I, PCT_APOSTROPHE, CHR_l, CHR_l, CTR_NEWLINE,
    CTR_ENDLINE
};

// tell you how to deal with Benkei!{newline}{endline}
static s16 scenario_text_0724[] = {
    CHR_t, CHR_e, CHR_l, CHR_l, PCT_SPACE, CHR_y, CHR_o, CHR_u, PCT_SPACE, CHR_h,
    CHR_o, CHR_w, PCT_SPACE, CHR_t, CHR_o, PCT_SPACE, CHR_d, CHR_e, CHR_a, CHR_l,
    PCT_SPACE, CHR_w, CHR_i, CHR_t, CHR_h, PCT_SPACE, CHR_B, CHR_e, CHR_n, CHR_k,
    CHR_e, CHR_i, PCT_EXCLAMATION, CTR_NEWLINE, CTR_ENDLINE
};

// Well, whaddya say?{button}{endline}
static s16 scenario_text_075B[] = {
    CHR_W, CHR_e, CHR_l, CHR_l, PCT_COMMA, PCT_SPACE, CHR_w, CHR_h, CHR_a, CHR_d,
    CHR_d, CHR_y, CHR_a, PCT_SPACE, CHR_s, CHR_a, CHR_y, PCT_QUESTION, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_0782[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Will you do me a favour?{newline}{endline}
static s16 scenario_text_079A[] = {
    CHR_W, CHR_i, CHR_l, CHR_l, PCT_SPACE, CHR_y, CHR_o, CHR_u, PCT_SPACE, CHR_d,
    CHR_o, PCT_SPACE, CHR_m, CHR_e, PCT_SPACE, CHR_a, PCT_SPACE, CHR_f, CHR_a, CHR_v,
    CHR_o, CHR_u, CHR_r, PCT_QUESTION, CTR_NEWLINE, CTR_ENDLINE
};

//   {newline}{endline}
static s16 scenario_text_07C8[] = {
    PCT_SPACE, PCT_SPACE, CTR_NEWLINE, CTR_ENDLINE
};

//   {em-yellow}Well, all right.{newline}{endline}
static s16 scenario_text_07E0[] = {
    PCT_SPACE, PCT_SPACE, CTR_EM_YELLOW, CHR_W, CHR_e, CHR_l, CHR_l, PCT_COMMA, PCT_SPACE, CHR_a,
    CHR_l, CHR_l, PCT_SPACE, CHR_r, CHR_i, CHR_g, CHR_h, CHR_t, PCT_PERIOD, CTR_NEWLINE,
    CTR_ENDLINE
};

//   {em-yellow}No way!{newline}{endline}
static s16 scenario_text_0813[] = {
    PCT_SPACE, PCT_SPACE, CTR_EM_YELLOW, CHR_N, CHR_o, PCT_SPACE, CHR_w, CHR_a, CHR_y, PCT_EXCLAMATION,
    CTR_NEWLINE, CTR_ENDLINE
};

// {end}{endline}
static s16 scenario_text_083D[] = {
    CTR_END, CTR_ENDLINE
};

// Address: @c2c0

// {newwindow}{endline}
static s16 scenario_text_084F[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// {/em}Then it's decided!{button}{endline}
static s16 scenario_text_0867[] = {
    CTR_CLOSE_EM, CHR_T, CHR_h, CHR_e, CHR_n, PCT_SPACE, CHR_i, CHR_t, PCT_APOSTROPHE, CHR_s,
    PCT_SPACE, CHR_d, CHR_e, CHR_c, CHR_i, CHR_d, CHR_e, CHR_d, PCT_EXCLAMATION, CTR_BUTTON,
    CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_0893[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Okay, [{em-yellow}Catch{/em}] me some {em-yellow}fish{/em} from{newline}{endline}
static s16 scenario_text_08AB[] = {
    CHR_O, CHR_k, CHR_a, CHR_y, PCT_COMMA, PCT_SPACE, PCT_LBRACKET, CTR_EM_YELLOW, CHR_C, CHR_a,
    CHR_t, CHR_c, CHR_h, CTR_CLOSE_EM, PCT_RBRACKET, PCT_SPACE, CHR_m, CHR_e, PCT_SPACE, CHR_s,
    CHR_o, CHR_m, CHR_e, PCT_SPACE, CTR_EM_YELLOW, CHR_f, CHR_i, CHR_s, CHR_h, CTR_CLOSE_EM,
    PCT_SPACE, CHR_f, CHR_r, CHR_o, CHR_m, CTR_NEWLINE, CTR_ENDLINE
};

// the {em-yellow}Duck Creek{/em}!{button}{endline}
static s16 scenario_text_0900[] = {
    CHR_t, CHR_h, CHR_e, PCT_SPACE, CTR_EM_YELLOW, CHR_D, CHR_u, CHR_c, CHR_k, PCT_SPACE,
    CHR_C, CHR_r, CHR_e, CHR_e, CHR_k, CTR_CLOSE_EM, PCT_EXCLAMATION, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_0934[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// First catch [{em-yellow}Three{/em}][{em-yellow}Blue Fish{/em}]!{endline}
static s16 scenario_text_094C[] = {
    CHR_F, CHR_i, CHR_r, CHR_s, CHR_t, PCT_SPACE, CHR_c, CHR_a, CHR_t, CHR_c,
    CHR_h, PCT_SPACE, PCT_LBRACKET, CTR_EM_YELLOW, CHR_T, CHR_h, CHR_r, CHR_e, CHR_e, CTR_CLOSE_EM,
    PCT_RBRACKET, PCT_LBRACKET, CTR_EM_YELLOW, CHR_B, CHR_l, CHR_u, CHR_e, PCT_SPACE, CHR_F, CHR_i,
    CHR_s, CHR_h, CTR_CLOSE_EM, PCT_RBRACKET, PCT_EXCLAMATION, CTR_ENDLINE
};

// {waitinput}{end}{endline}
static s16 scenario_text_0998[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE
};

// Address: @c324

// {newwindow}{endline}
static s16 scenario_text_09B5[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// {/em}Is that so...{newline}{endline}
static s16 scenario_text_09CD[] = {
    CTR_CLOSE_EM, CHR_I, CHR_s, PCT_SPACE, CHR_t, CHR_h, CHR_a, CHR_t, PCT_SPACE, CHR_s,
    CHR_o, PCT_PERIOD, PCT_PERIOD, PCT_PERIOD, CTR_NEWLINE, CTR_ENDLINE
};

// In that case, you're in the way!{newline}{endline}
static s16 scenario_text_09F5[] = {
    CHR_I, CHR_n, PCT_SPACE, CHR_t, CHR_h, CHR_a, CHR_t, PCT_SPACE, CHR_c, CHR_a,
    CHR_s, CHR_e, PCT_COMMA, PCT_SPACE, CHR_y, CHR_o, CHR_u, PCT_APOSTROPHE, CHR_r, CHR_e,
    PCT_SPACE, CHR_i, CHR_n, PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE, CHR_w, CHR_a,
    CHR_y, PCT_EXCLAMATION, CTR_NEWLINE, CTR_ENDLINE
};

// Scram!!{endline}
static s16 scenario_text_0A2B[] = {
    CHR_S, CHR_c, CHR_r, CHR_a, CHR_m, PCT_EXCLAMATION, PCT_EXCLAMATION, CTR_ENDLINE
};

// {waitinput}{end}{endline}
static s16 scenario_text_0A3F[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE
};

// Address: @c350

// {newwindow}{endline}
static s16 scenario_text_0A5C[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Hurry up and{newline}{endline}
static s16 scenario_text_0A74[] = {
    CHR_H, CHR_u, CHR_r, CHR_r, CHR_y, PCT_SPACE, CHR_u, CHR_p, PCT_SPACE, CHR_a,
    CHR_n, CHR_d, CTR_NEWLINE, CTR_ENDLINE
};

// get me those {em-yellow}three{/em} [{em-yellow}Blue Fish{/em}]!{endline}
static s16 scenario_text_0A96[] = {
    CHR_g, CHR_e, CHR_t, PCT_SPACE, CHR_m, CHR_e, PCT_SPACE, CHR_t, CHR_h, CHR_o,
    CHR_s, CHR_e, PCT_SPACE, CTR_EM_YELLOW, CHR_t, CHR_h, CHR_r, CHR_e, CHR_e, CTR_CLOSE_EM,
    PCT_SPACE, PCT_LBRACKET, CTR_EM_YELLOW, CHR_B, CHR_l, CHR_u, CHR_e, PCT_SPACE, CHR_F, CHR_i,
    CHR_s, CHR_h, CTR_CLOSE_EM, PCT_RBRACKET, PCT_EXCLAMATION, CTR_ENDLINE
};

// {waitinput}{end}{endline}
static s16 scenario_text_0AE2[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE
};

// Address: @c38c

// {newwindow}{endline}
static s16 scenario_text_0AFF[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// You did it!{button}{endline}
static s16 scenario_text_0B17[] = {
    CHR_Y, CHR_o, CHR_u, PCT_SPACE, CHR_d, CHR_i, CHR_d, PCT_SPACE, CHR_i, CHR_t,
    PCT_EXCLAMATION, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_0B37[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Okay, next get me {newline}{endline}
static s16 scenario_text_0B4F[] = {
    CHR_O, CHR_k, CHR_a, CHR_y, PCT_COMMA, PCT_SPACE, CHR_n, CHR_e, CHR_x, CHR_t,
    PCT_SPACE, CHR_g, CHR_e, CHR_t, PCT_SPACE, CHR_m, CHR_e, PCT_SPACE, CTR_NEWLINE, CTR_ENDLINE
};

//       [{em-yellow}Five{/em}][{em-yellow}Yellow Fish{/em}]!{newline}{endline}
static s16 scenario_text_0B77[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_LBRACKET, CTR_EM_YELLOW, CHR_F, CHR_i,
    CHR_v, CHR_e, CTR_CLOSE_EM, PCT_RBRACKET, PCT_LBRACKET, CTR_EM_YELLOW, CHR_Y, CHR_e, CHR_l, CHR_l,
    CHR_o, CHR_w, PCT_SPACE, CHR_F, CHR_i, CHR_s, CHR_h, CTR_CLOSE_EM, PCT_RBRACKET, PCT_EXCLAMATION,
    CTR_NEWLINE, CTR_ENDLINE
};

// {waitinput}{end}{endline}
static s16 scenario_text_0BC7[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE
};

// Address: @c3f0

// {newwindow}{endline}
static s16 scenario_text_0BE4[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Hurry up and{newline}{endline}
static s16 scenario_text_0BFC[] = {
    CHR_H, CHR_u, CHR_r, CHR_r, CHR_y, PCT_SPACE, CHR_u, CHR_p, PCT_SPACE, CHR_a,
    CHR_n, CHR_d, CTR_NEWLINE, CTR_ENDLINE
};

//  get me those {em-yellow}five{/em} [{em-yellow}Yellow Fish{/em}]!{endline}
static s16 scenario_text_0C1E[] = {
    PCT_SPACE, CHR_g, CHR_e, CHR_t, PCT_SPACE, CHR_m, CHR_e, PCT_SPACE, CHR_t, CHR_h,
    CHR_o, CHR_s, CHR_e, PCT_SPACE, CTR_EM_YELLOW, CHR_f, CHR_i, CHR_v, CHR_e, CTR_CLOSE_EM,
    PCT_SPACE, PCT_LBRACKET, CTR_EM_YELLOW, CHR_Y, CHR_e, CHR_l, CHR_l, CHR_o, CHR_w, PCT_SPACE,
    CHR_F, CHR_i, CHR_s, CHR_h, CTR_CLOSE_EM, PCT_RBRACKET, PCT_EXCLAMATION, CTR_ENDLINE
};

// {waitinput}{end}{endline}
static s16 scenario_text_0C6C[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE
};

// Address: @c42c

// {newwindow}{endline}
static s16 scenario_text_0C89[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Pretty good!{button}{endline}
static s16 scenario_text_0CA1[] = {
    CHR_P, CHR_r, CHR_e, CHR_t, CHR_t, CHR_y, PCT_SPACE, CHR_g, CHR_o, CHR_o,
    CHR_d, PCT_EXCLAMATION, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_0CC2[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Okay, this is the last!{newline}{endline}
static s16 scenario_text_0CDA[] = {
    CHR_O, CHR_k, CHR_a, CHR_y, PCT_COMMA, PCT_SPACE, CHR_t, CHR_h, CHR_i, CHR_s,
    PCT_SPACE, CHR_i, CHR_s, PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE, CHR_l, CHR_a,
    CHR_s, CHR_t, PCT_EXCLAMATION, CTR_NEWLINE, CTR_ENDLINE
};

//     Get me [{em-yellow}Eight{/em}][{em-yellow}Red Fish{/em}]!{newline}{endline}
static s16 scenario_text_0D07[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_G, CHR_e, CHR_t, PCT_SPACE, CHR_m, CHR_e,
    PCT_SPACE, PCT_LBRACKET, CTR_EM_YELLOW, CHR_E, CHR_i, CHR_g, CHR_h, CHR_t, CTR_CLOSE_EM, PCT_RBRACKET,
    PCT_LBRACKET, CTR_EM_YELLOW, CHR_R, CHR_e, CHR_d, PCT_SPACE, CHR_F, CHR_i, CHR_s, CHR_h,
    CTR_CLOSE_EM, PCT_RBRACKET, PCT_EXCLAMATION, CTR_NEWLINE, CTR_ENDLINE
};

// {waitinput}{end}{endline}
static s16 scenario_text_0D5A[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE
};

// Address: @c490

// {newwindow}{endline}
static s16 scenario_text_0D77[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Hurry up and{newline}{endline}
static s16 scenario_text_0D8F[] = {
    CHR_H, CHR_u, CHR_r, CHR_r, CHR_y, PCT_SPACE, CHR_u, CHR_p, PCT_SPACE, CHR_a,
    CHR_n, CHR_d, CTR_NEWLINE, CTR_ENDLINE
};

//  get me those {em-yellow}eight{/em} [{em-yellow}Red Fish{/em}]!{endline}
static s16 scenario_text_0DB1[] = {
    PCT_SPACE, CHR_g, CHR_e, CHR_t, PCT_SPACE, CHR_m, CHR_e, PCT_SPACE, CHR_t, CHR_h,
    CHR_o, CHR_s, CHR_e, PCT_SPACE, CTR_EM_YELLOW, CHR_e, CHR_i, CHR_g, CHR_h, CHR_t,
    CTR_CLOSE_EM, PCT_SPACE, PCT_LBRACKET, CTR_EM_YELLOW, CHR_R, CHR_e, CHR_d, PCT_SPACE, CHR_F, CHR_i,
    CHR_s, CHR_h, CTR_CLOSE_EM, PCT_RBRACKET, PCT_EXCLAMATION, CTR_ENDLINE
};

// {waitinput}{end}{endline}
static s16 scenario_text_0DFD[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE
};

// Address: @c4cc

// {newwindow}{endline}
static s16 scenario_text_0E1A[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

//   {newline}{endline}
static s16 scenario_text_0E32[] = {
    PCT_SPACE, PCT_SPACE, CTR_NEWLINE, CTR_ENDLINE
};

//     {blink}{em-yellow}All right, you did it!{/em}{/blink}{button}{endline}
static s16 scenario_text_0E4A[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CTR_BLINK, CTR_EM_YELLOW, CHR_A, CHR_l, CHR_l, PCT_SPACE,
    CHR_r, CHR_i, CHR_g, CHR_h, CHR_t, PCT_COMMA, PCT_SPACE, CHR_y, CHR_o, CHR_u,
    PCT_SPACE, CHR_d, CHR_i, CHR_d, PCT_SPACE, CHR_i, CHR_t, PCT_EXCLAMATION, CTR_CLOSE_EM, CTR_CLOSE_BLINK,
    CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_0E98[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// With all this fish, {newline}{endline}
static s16 scenario_text_0EB0[] = {
    CHR_W, CHR_i, CHR_t, CHR_h, PCT_SPACE, CHR_a, CHR_l, CHR_l, PCT_SPACE, CHR_t,
    CHR_h, CHR_i, CHR_s, PCT_SPACE, CHR_f, CHR_i, CHR_s, CHR_h, PCT_COMMA, PCT_SPACE,
    CTR_NEWLINE, CTR_ENDLINE
};

// I won't go hungry for some time!{button}{endline}
static s16 scenario_text_0EDA[] = {
    CHR_I, PCT_SPACE, CHR_w, CHR_o, CHR_n, PCT_APOSTROPHE, CHR_t, PCT_SPACE, CHR_g, CHR_o,
    PCT_SPACE, CHR_h, CHR_u, CHR_n, CHR_g, CHR_r, CHR_y, PCT_SPACE, CHR_f, CHR_o,
    CHR_r, PCT_SPACE, CHR_s, CHR_o, CHR_m, CHR_e, PCT_SPACE, CHR_t, CHR_i, CHR_m,
    CHR_e, PCT_EXCLAMATION, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_0F0F[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Well, as I promised...{button}{endline}
static s16 scenario_text_0F27[] = {
    CHR_W, CHR_e, CHR_l, CHR_l, PCT_COMMA, PCT_SPACE, CHR_a, CHR_s, PCT_SPACE, CHR_I,
    PCT_SPACE, CHR_p, CHR_r, CHR_o, CHR_m, CHR_i, CHR_s, CHR_e, CHR_d, PCT_PERIOD,
    PCT_PERIOD, PCT_PERIOD, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_0F52[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Throw this at Benkei!{newline}{endline}
static s16 scenario_text_0F6A[] = {
    CHR_T, CHR_h, CHR_r, CHR_o, CHR_w, PCT_SPACE, CHR_t, CHR_h, CHR_i, CHR_s,
    PCT_SPACE, CHR_a, CHR_t, PCT_SPACE, CHR_B, CHR_e, CHR_n, CHR_k, CHR_e, CHR_i,
    PCT_EXCLAMATION, CTR_NEWLINE, CTR_ENDLINE
};

// I'm sure he'll move to the aside.{button}{endline}
static s16 scenario_text_0F95[] = {
    CHR_I, PCT_APOSTROPHE, CHR_m, PCT_SPACE, CHR_s, CHR_u, CHR_r, CHR_e, PCT_SPACE, CHR_h,
    CHR_e, PCT_APOSTROPHE, CHR_l, CHR_l, PCT_SPACE, CHR_m, CHR_o, CHR_v, CHR_e, PCT_SPACE,
    CHR_t, CHR_o, PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE, CHR_a, CHR_s, CHR_i,
    CHR_d, CHR_e, PCT_PERIOD, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_0FCB[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// {end}{endline}
static s16 scenario_text_0FE3[] = {
    CTR_END, CTR_ENDLINE
};

// {begin}{endline}
static s16 scenario_text_0FF5[] = {
    CTR_BEGIN, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_1009[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

//   {newline}{endline}
static s16 scenario_text_1021[] = {
    PCT_SPACE, PCT_SPACE, CTR_NEWLINE, CTR_ENDLINE
};

//  Goemon and allies{newline}{endline}
static s16 scenario_text_1039[] = {
    PCT_SPACE, CHR_G, CHR_o, CHR_e, CHR_m, CHR_o, CHR_n, PCT_SPACE, CHR_a, CHR_n,
    CHR_d, PCT_SPACE, CHR_a, CHR_l, CHR_l, CHR_i, CHR_e, CHR_s, CTR_NEWLINE, CTR_ENDLINE
};

//      receive an [{em-yellow}Achilles' heel{/em}]!{endline}
static s16 scenario_text_1061[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_r, CHR_e, CHR_c, CHR_e, CHR_i,
    CHR_v, CHR_e, PCT_SPACE, CHR_a, CHR_n, PCT_SPACE, PCT_LBRACKET, CTR_EM_YELLOW, CHR_A, CHR_c,
    CHR_h, CHR_i, CHR_l, CHR_l, CHR_e, CHR_s, PCT_APOSTROPHE, PCT_SPACE, CHR_h, CHR_e,
    CHR_e, CHR_l, CTR_CLOSE_EM, PCT_RBRACKET, PCT_EXCLAMATION, CTR_ENDLINE
};

// {end}{endline}
static s16 scenario_text_109F[] = {
    CTR_END, CTR_ENDLINE
};

// Address: @c690

// My dream is to sit back, relax,{newline}{endline}
static s16 scenario_text_10B1[] = {
    CHR_M, CHR_y, PCT_SPACE, CHR_d, CHR_r, CHR_e, CHR_a, CHR_m, PCT_SPACE, CHR_i,
    CHR_s, PCT_SPACE, CHR_t, CHR_o, PCT_SPACE, CHR_s, CHR_i, CHR_t, PCT_SPACE, CHR_b,
    CHR_a, CHR_c, CHR_k, PCT_COMMA, PCT_SPACE, CHR_r, CHR_e, CHR_l, CHR_a, CHR_x,
    PCT_COMMA, CTR_NEWLINE, CTR_ENDLINE
};

// and have no worries for{newline}{endline}
static s16 scenario_text_10E6[] = {
    CHR_a, CHR_n, CHR_d, PCT_SPACE, CHR_h, CHR_a, CHR_v, CHR_e, PCT_SPACE, CHR_n,
    CHR_o, PCT_SPACE, CHR_w, CHR_o, CHR_r, CHR_r, CHR_i, CHR_e, CHR_s, PCT_SPACE,
    CHR_f, CHR_o, CHR_r, CTR_NEWLINE, CTR_ENDLINE
};

// the rest of my life.{endline}
static s16 scenario_text_1113[] = {
    CHR_t, CHR_h, CHR_e, PCT_SPACE, CHR_r, CHR_e, CHR_s, CHR_t, PCT_SPACE, CHR_o,
    CHR_f, PCT_SPACE, CHR_m, CHR_y, PCT_SPACE, CHR_l, CHR_i, CHR_f, CHR_e, PCT_PERIOD,
    CTR_ENDLINE
};

// {waitinput}{end}{endline}
static s16 scenario_text_1134[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE
};

// Address: @c6b4

// {begin}{endline}
static s16 scenario_text_1151[] = {
    CTR_BEGIN, CTR_ENDLINE
};

// Hey! Long time no see!{button}{endline}
static s16 scenario_text_1165[] = {
    CHR_H, CHR_e, CHR_y, PCT_EXCLAMATION, PCT_SPACE, CHR_L, CHR_o, CHR_n, CHR_g, PCT_SPACE,
    CHR_t, CHR_i, CHR_m, CHR_e, PCT_SPACE, CHR_n, CHR_o, PCT_SPACE, CHR_s, CHR_e,
    CHR_e, PCT_EXCLAMATION, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_1190[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// I'm {em-yellow}Ushiwaka{/em}!{button}{end}{endline}
static s16 scenario_text_11A8[] = {
    CHR_I, PCT_APOSTROPHE, CHR_m, PCT_SPACE, CTR_EM_YELLOW, CHR_U, CHR_s, CHR_h, CHR_i, CHR_w,
    CHR_a, CHR_k, CHR_a, CTR_CLOSE_EM, PCT_EXCLAMATION, CTR_BUTTON, CTR_END, CTR_ENDLINE
};

// {begin}{endline}
static s16 scenario_text_11DF[] = {
    CTR_BEGIN, CTR_ENDLINE
};

// Goemon:Gasp! What happened?{newline}{endline}
static s16 scenario_text_11F3[] = {
    CHR_G, CHR_o, CHR_e, CHR_m, CHR_o, CHR_n, PCT_COLON, CHR_G, CHR_a, CHR_s,
    CHR_p, PCT_EXCLAMATION, PCT_SPACE, CHR_W, CHR_h, CHR_a, CHR_t, PCT_SPACE, CHR_h, CHR_a,
    CHR_p, CHR_p, CHR_e, CHR_n, CHR_e, CHR_d, PCT_QUESTION, CTR_NEWLINE, CTR_ENDLINE
};

//       Why are you so small?!{button}{end}{endline}
static s16 scenario_text_1224[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_W, CHR_h, CHR_y, PCT_SPACE,
    CHR_a, CHR_r, CHR_e, PCT_SPACE, CHR_y, CHR_o, CHR_u, PCT_SPACE, CHR_s, CHR_o,
    PCT_SPACE, CHR_s, CHR_m, CHR_a, CHR_l, CHR_l, PCT_QUESTION, PCT_EXCLAMATION, CTR_BUTTON, CTR_END,
    CTR_ENDLINE
};

// {begin}{endline}
static s16 scenario_text_125A[] = {
    CTR_BEGIN, CTR_ENDLINE
};

// Ushiwaka:Let me tell you.{button}{endline}
static s16 scenario_text_126E[] = {
    CHR_U, CHR_s, CHR_h, CHR_i, CHR_w, CHR_a, CHR_k, CHR_a, PCT_COLON, CHR_L,
    CHR_e, CHR_t, PCT_SPACE, CHR_m, CHR_e, PCT_SPACE, CHR_t, CHR_e, CHR_l, CHR_l,
    PCT_SPACE, CHR_y, CHR_o, CHR_u, PCT_PERIOD, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_129C[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Those {em-yellow}sweets{/em} at{newline}{endline}
static s16 scenario_text_12B4[] = {
    CHR_T, CHR_h, CHR_o, CHR_s, CHR_e, PCT_SPACE, CTR_EM_YELLOW, CHR_s, CHR_w, CHR_e,
    CHR_e, CHR_t, CHR_s, CTR_CLOSE_EM, PCT_SPACE, CHR_a, CHR_t, CTR_NEWLINE, CTR_ENDLINE
};

// the {em-yellow}Golden Temple{/em}...{button}{endline}
static s16 scenario_text_12E9[] = {
    CHR_t, CHR_h, CHR_e, PCT_SPACE, CTR_EM_YELLOW, CHR_G, CHR_o, CHR_l, CHR_d, CHR_e,
    CHR_n, PCT_SPACE, CHR_T, CHR_e, CHR_m, CHR_p, CHR_l, CHR_e, CTR_CLOSE_EM, PCT_PERIOD,
    PCT_PERIOD, PCT_PERIOD, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_1322[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Well if you eat {em-yellow}eight{/em} in a row,{newline}{endline}
static s16 scenario_text_133A[] = {
    CHR_W, CHR_e, CHR_l, CHR_l, PCT_SPACE, CHR_i, CHR_f, PCT_SPACE, CHR_y, CHR_o,
    CHR_u, PCT_SPACE, CHR_e, CHR_a, CHR_t, PCT_SPACE, CTR_EM_YELLOW, CHR_e, CHR_i, CHR_g,
    CHR_h, CHR_t, CTR_CLOSE_EM, PCT_SPACE, CHR_i, CHR_n, PCT_SPACE, CHR_a, PCT_SPACE, CHR_r,
    CHR_o, CHR_w, PCT_COMMA, CTR_NEWLINE, CTR_ENDLINE
};

// there's a strange power that{newline}{endline}
static s16 scenario_text_137F[] = {
    CHR_t, CHR_h, CHR_e, CHR_r, CHR_e, PCT_APOSTROPHE, CHR_s, PCT_SPACE, CHR_a, PCT_SPACE,
    CHR_s, CHR_t, CHR_r, CHR_a, CHR_n, CHR_g, CHR_e, PCT_SPACE, CHR_p, CHR_o,
    CHR_w, CHR_e, CHR_r, PCT_SPACE, CHR_t, CHR_h, CHR_a, CHR_t, CTR_NEWLINE, CTR_ENDLINE
};

// makes you shrink!{button}{endline}
static s16 scenario_text_13B1[] = {
    CHR_m, CHR_a, CHR_k, CHR_e, CHR_s, PCT_SPACE, CHR_y, CHR_o, CHR_u, PCT_SPACE,
    CHR_s, CHR_h, CHR_r, CHR_i, CHR_n, CHR_k, PCT_EXCLAMATION, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_13D7[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// If for any reason you want to{newline}{endline}
static s16 scenario_text_13EF[] = {
    CHR_I, CHR_f, PCT_SPACE, CHR_f, CHR_o, CHR_r, PCT_SPACE, CHR_a, CHR_n, CHR_y,
    PCT_SPACE, CHR_r, CHR_e, CHR_a, CHR_s, CHR_o, CHR_n, PCT_SPACE, CHR_y, CHR_o,
    CHR_u, PCT_SPACE, CHR_w, CHR_a, CHR_n, CHR_t, PCT_SPACE, CHR_t, CHR_o, CTR_NEWLINE,
    CTR_ENDLINE
};

// shrink, go to the {em-yellow}Golden Temple{/em}!{newline}{endline}
static s16 scenario_text_1422[] = {
    CHR_s, CHR_h, CHR_r, CHR_i, CHR_n, CHR_k, PCT_COMMA, PCT_SPACE, CHR_g, CHR_o,
    PCT_SPACE, CHR_t, CHR_o, PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE, CTR_EM_YELLOW, CHR_G,
    CHR_o, CHR_l, CHR_d, CHR_e, CHR_n, PCT_SPACE, CHR_T, CHR_e, CHR_m, CHR_p,
    CHR_l, CHR_e, CTR_CLOSE_EM, PCT_EXCLAMATION, CTR_NEWLINE, CTR_ENDLINE
};

// I'll be there waiting for you.{endline}
static s16 scenario_text_1468[] = {
    CHR_I, PCT_APOSTROPHE, CHR_l, CHR_l, PCT_SPACE, CHR_b, CHR_e, PCT_SPACE, CHR_t, CHR_h,
    CHR_e, CHR_r, CHR_e, PCT_SPACE, CHR_w, CHR_a, CHR_i, CHR_t, CHR_i, CHR_n,
    CHR_g, PCT_SPACE, CHR_f, CHR_o, CHR_r, PCT_SPACE, CHR_y, CHR_o, CHR_u, PCT_PERIOD,
    CTR_ENDLINE
};

// {waitinput}{end}{endline}
static s16 scenario_text_1493[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE
};

// Address: @c838

// {begin}{endline}
static s16 scenario_text_14B0[] = {
    CTR_BEGIN, CTR_ENDLINE
};

// Ushiwaka:You made it!{button}{endline}
static s16 scenario_text_14C4[] = {
    CHR_U, CHR_s, CHR_h, CHR_i, CHR_w, CHR_a, CHR_k, CHR_a, PCT_COLON, CHR_Y,
    CHR_o, CHR_u, PCT_SPACE, CHR_m, CHR_a, CHR_d, CHR_e, PCT_SPACE, CHR_i, CHR_t,
    PCT_EXCLAMATION, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_14EE[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Narrator, please explain!{button}{end}{endline}
static s16 scenario_text_1506[] = {
    CHR_N, CHR_a, CHR_r, CHR_r, CHR_a, CHR_t, CHR_o, CHR_r, PCT_COMMA, PCT_SPACE,
    CHR_p, CHR_l, CHR_e, CHR_a, CHR_s, CHR_e, PCT_SPACE, CHR_e, CHR_x, CHR_p,
    CHR_l, CHR_a, CHR_i, CHR_n, PCT_EXCLAMATION, CTR_BUTTON, CTR_END, CTR_ENDLINE
};

// {begin}{endline}
static s16 scenario_text_1539[] = {
    CTR_BEGIN, CTR_ENDLINE
};

// Narrator:{em-yellow}My pleasure!{/em}{button}{endline}
static s16 scenario_text_154D[] = {
    CHR_N, CHR_a, CHR_r, CHR_r, CHR_a, CHR_t, CHR_o, CHR_r, PCT_COLON, CTR_EM_YELLOW,
    CHR_M, CHR_y, PCT_SPACE, CHR_p, CHR_l, CHR_e, CHR_a, CHR_s, CHR_u, CHR_r,
    CHR_e, PCT_EXCLAMATION, CTR_CLOSE_EM, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_1587[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Narrator:The {em-yellow}sweets{/em} in {newline}{endline}
static s16 scenario_text_159F[] = {
    CHR_N, CHR_a, CHR_r, CHR_r, CHR_a, CHR_t, CHR_o, CHR_r, PCT_COLON, CHR_T,
    CHR_h, CHR_e, PCT_SPACE, CTR_EM_YELLOW, CHR_s, CHR_w, CHR_e, CHR_e, CHR_t, CHR_s,
    CTR_CLOSE_EM, PCT_SPACE, CHR_i, CHR_n, PCT_SPACE, CTR_NEWLINE, CTR_ENDLINE
};

//       the {em-yellow}cupboard{/em} at {newline}{endline}
static s16 scenario_text_15DC[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE,
    CTR_EM_YELLOW, CHR_c, CHR_u, CHR_p, CHR_b, CHR_o, CHR_a, CHR_r, CHR_d, CTR_CLOSE_EM,
    PCT_SPACE, CHR_a, CHR_t, PCT_SPACE, CTR_NEWLINE, CTR_ENDLINE
};

//       the Temple... will start {newline}{endline}
static s16 scenario_text_1618[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE,
    CHR_T, CHR_e, CHR_m, CHR_p, CHR_l, CHR_e, PCT_PERIOD, PCT_PERIOD, PCT_PERIOD, PCT_SPACE,
    CHR_w, CHR_i, CHR_l, CHR_l, PCT_SPACE, CHR_s, CHR_t, CHR_a, CHR_r, CHR_t,
    PCT_SPACE, CTR_NEWLINE, CTR_ENDLINE
};

//       falling from above!{button}{endline}
static s16 scenario_text_164D[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_f, CHR_a, CHR_l, CHR_l,
    CHR_i, CHR_n, CHR_g, PCT_SPACE, CHR_f, CHR_r, CHR_o, CHR_m, PCT_SPACE, CHR_a,
    CHR_b, CHR_o, CHR_v, CHR_e, PCT_EXCLAMATION, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_167B[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Narrator:If you catch {em-yellow}eight{/em}{newline}{endline}
static s16 scenario_text_1693[] = {
    CHR_N, CHR_a, CHR_r, CHR_r, CHR_a, CHR_t, CHR_o, CHR_r, PCT_COLON, CHR_I,
    CHR_f, PCT_SPACE, CHR_y, CHR_o, CHR_u, PCT_SPACE, CHR_c, CHR_a, CHR_t, CHR_c,
    CHR_h, PCT_SPACE, CTR_EM_YELLOW, CHR_e, CHR_i, CHR_g, CHR_h, CHR_t, CTR_CLOSE_EM, CTR_NEWLINE,
    CTR_ENDLINE
};

//       sweets before the time{newline}{endline}
static s16 scenario_text_16D4[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_s, CHR_w, CHR_e, CHR_e,
    CHR_t, CHR_s, PCT_SPACE, CHR_b, CHR_e, CHR_f, CHR_o, CHR_r, CHR_e, PCT_SPACE,
    CHR_t, CHR_h, CHR_e, PCT_SPACE, CHR_t, CHR_i, CHR_m, CHR_e, CTR_NEWLINE, CTR_ENDLINE
};

//       is up...{button}{endline}
static s16 scenario_text_1706[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_i, CHR_s, PCT_SPACE, CHR_u,
    CHR_p, PCT_PERIOD, PCT_PERIOD, PCT_PERIOD, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_1729[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Narrator:you will be able to use{newline}{endline}
static s16 scenario_text_1741[] = {
    CHR_N, CHR_a, CHR_r, CHR_r, CHR_a, CHR_t, CHR_o, CHR_r, PCT_COLON, CHR_y,
    CHR_o, CHR_u, PCT_SPACE, CHR_w, CHR_i, CHR_l, CHR_l, PCT_SPACE, CHR_b, CHR_e,
    PCT_SPACE, CHR_a, CHR_b, CHR_l, CHR_e, PCT_SPACE, CHR_t, CHR_o, PCT_SPACE, CHR_u,
    CHR_s, CHR_e, CTR_NEWLINE, CTR_ENDLINE
};

//       {em-yellow}magical powers{/em} to make{newline}{endline}
static s16 scenario_text_1777[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CTR_EM_YELLOW, CHR_m, CHR_a, CHR_g,
    CHR_i, CHR_c, CHR_a, CHR_l, PCT_SPACE, CHR_p, CHR_o, CHR_w, CHR_e, CHR_r,
    CHR_s, CTR_CLOSE_EM, PCT_SPACE, CHR_t, CHR_o, PCT_SPACE, CHR_m, CHR_a, CHR_k, CHR_e,
    CTR_NEWLINE, CTR_ENDLINE
};

//       you shrink!{button}{endline}
static s16 scenario_text_17B9[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_y, CHR_o, CHR_u, PCT_SPACE,
    CHR_s, CHR_h, CHR_r, CHR_i, CHR_n, CHR_k, PCT_EXCLAMATION, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_17DF[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Narrator:However,{newline}{endline}
static s16 scenario_text_17F7[] = {
    CHR_N, CHR_a, CHR_r, CHR_r, CHR_a, CHR_t, CHR_o, CHR_r, PCT_COLON, CHR_H,
    CHR_o, CHR_w, CHR_e, CHR_v, CHR_e, CHR_r, PCT_COMMA, CTR_NEWLINE, CTR_ENDLINE
};

//       if you're seen catching{newline}{endline}
static s16 scenario_text_181E[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_i, CHR_f, PCT_SPACE, CHR_y,
    CHR_o, CHR_u, PCT_APOSTROPHE, CHR_r, CHR_e, PCT_SPACE, CHR_s, CHR_e, CHR_e, CHR_n,
    PCT_SPACE, CHR_c, CHR_a, CHR_t, CHR_c, CHR_h, CHR_i, CHR_n, CHR_g, CTR_NEWLINE,
    CTR_ENDLINE
};

//       these {em-yellow}sweets{/em}...{button}{endline}
static s16 scenario_text_1851[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_t, CHR_h, CHR_e, CHR_s,
    CHR_e, PCT_SPACE, CTR_EM_YELLOW, CHR_s, CHR_w, CHR_e, CHR_e, CHR_t, CHR_s, CTR_CLOSE_EM,
    PCT_PERIOD, PCT_PERIOD, PCT_PERIOD, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_188B[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Narrator:...something terrible{newline}{endline}
static s16 scenario_text_18A3[] = {
    CHR_N, CHR_a, CHR_r, CHR_r, CHR_a, CHR_t, CHR_o, CHR_r, PCT_COLON, PCT_PERIOD,
    PCT_PERIOD, PCT_PERIOD, CHR_s, CHR_o, CHR_m, CHR_e, CHR_t, CHR_h, CHR_i, CHR_n,
    CHR_g, PCT_SPACE, CHR_t, CHR_e, CHR_r, CHR_r, CHR_i, CHR_b, CHR_l, CHR_e,
    CTR_NEWLINE, CTR_ENDLINE
};

//       will happen!{button}{endline}
static s16 scenario_text_18D7[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_w, CHR_i, CHR_l, CHR_l,
    PCT_SPACE, CHR_h, CHR_a, CHR_p, CHR_p, CHR_e, CHR_n, PCT_EXCLAMATION, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_18FE[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Narrator:Ready, set...{button}{endline}
static s16 scenario_text_1916[] = {
    CHR_N, CHR_a, CHR_r, CHR_r, CHR_a, CHR_t, CHR_o, CHR_r, PCT_COLON, CHR_R,
    CHR_e, CHR_a, CHR_d, CHR_y, PCT_COMMA, PCT_SPACE, CHR_s, CHR_e, CHR_t, PCT_PERIOD,
    PCT_PERIOD, PCT_PERIOD, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_1941[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Narrator:{newline}{endline}
static s16 scenario_text_1959[] = {
    CHR_N, CHR_a, CHR_r, CHR_r, CHR_a, CHR_t, CHR_o, CHR_r, PCT_COLON, CTR_NEWLINE,
    CTR_ENDLINE
};

//          {big}{blink}{em-yellow}G o ! {/em}{/blink}{/big}{endline}
static s16 scenario_text_1978[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CTR_BIG,
    CTR_BLINK, CTR_EM_YELLOW, CHR_G, PCT_SPACE, CHR_o, PCT_SPACE, PCT_EXCLAMATION, PCT_SPACE, CTR_CLOSE_EM, CTR_CLOSE_BLINK,
    CTR_CLOSE_BIG, CTR_ENDLINE
};

// {waitinput}{end}{endline}
static s16 scenario_text_19BE[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE
};

// Address: @ca28

// Ushiwaka:{newline}{endline}
static s16 scenario_text_19DB[] = {
    CHR_U, CHR_s, CHR_h, CHR_i, CHR_w, CHR_a, CHR_k, CHR_a, PCT_COLON, CTR_NEWLINE,
    CTR_ENDLINE
};

//       It wouldn't be for you...{button}{endline}
static s16 scenario_text_19FA[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_I, CHR_t, PCT_SPACE, CHR_w,
    CHR_o, CHR_u, CHR_l, CHR_d, CHR_n, PCT_APOSTROPHE, CHR_t, PCT_SPACE, CHR_b, CHR_e,
    PCT_SPACE, CHR_f, CHR_o, CHR_r, PCT_SPACE, CHR_y, CHR_o, CHR_u, PCT_PERIOD, PCT_PERIOD,
    PCT_PERIOD, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_1A2E[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// It's got to be someone with{newline}{endline}
static s16 scenario_text_1A46[] = {
    CHR_I, CHR_t, PCT_APOSTROPHE, CHR_s, PCT_SPACE, CHR_g, CHR_o, CHR_t, PCT_SPACE, CHR_t,
    CHR_o, PCT_SPACE, CHR_b, CHR_e, PCT_SPACE, CHR_s, CHR_o, CHR_m, CHR_e, CHR_o,
    CHR_n, CHR_e, PCT_SPACE, CHR_w, CHR_i, CHR_t, CHR_h, CTR_NEWLINE, CTR_ENDLINE
};

// a {em-yellow}big nose{/em} and {em-yellow}thread of eyes{/em}.{endline}
static s16 scenario_text_1A77[] = {
    CHR_a, PCT_SPACE, CTR_EM_YELLOW, CHR_b, CHR_i, CHR_g, PCT_SPACE, CHR_n, CHR_o, CHR_s,
    CHR_e, CTR_CLOSE_EM, PCT_SPACE, CHR_a, CHR_n, CHR_d, PCT_SPACE, CTR_EM_YELLOW, CHR_t, CHR_h,
    CHR_r, CHR_e, CHR_a, CHR_d, PCT_SPACE, CHR_o, CHR_f, PCT_SPACE, CHR_e, CHR_y,
    CHR_e, CHR_s, CTR_CLOSE_EM, PCT_PERIOD, CTR_ENDLINE
};

// {waitinput}{end}{endline}
static s16 scenario_text_1AC2[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE
};

// Address: @ca5c

// {newwindow}{endline}
static s16 scenario_text_1ADF[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Ushiwaka:Way to go!{newline}{endline}
static s16 scenario_text_1AF7[] = {
    CHR_U, CHR_s, CHR_h, CHR_i, CHR_w, CHR_a, CHR_k, CHR_a, PCT_COLON, CHR_W,
    CHR_a, CHR_y, PCT_SPACE, CHR_t, CHR_o, PCT_SPACE, CHR_g, CHR_o, PCT_EXCLAMATION, CTR_NEWLINE,
    CTR_ENDLINE
};

//        Now you can shrink{newline}{endline}
static s16 scenario_text_1B20[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_N, CHR_o, CHR_w,
    PCT_SPACE, CHR_y, CHR_o, CHR_u, PCT_SPACE, CHR_c, CHR_a, CHR_n, PCT_SPACE, CHR_s,
    CHR_h, CHR_r, CHR_i, CHR_n, CHR_k, CTR_NEWLINE, CTR_ENDLINE
};

//        as you wish!{button}{end}{endline}
static s16 scenario_text_1B4F[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_a, CHR_s, PCT_SPACE,
    CHR_y, CHR_o, CHR_u, PCT_SPACE, CHR_w, CHR_i, CHR_s, CHR_h, PCT_EXCLAMATION, CTR_BUTTON,
    CTR_END, CTR_ENDLINE
};

// {begin}{endline}
static s16 scenario_text_1B7C[] = {
    CTR_BEGIN, CTR_ENDLINE
};

//   {newline}{endline}
static s16 scenario_text_1B90[] = {
    PCT_SPACE, PCT_SPACE, CTR_NEWLINE, CTR_ENDLINE
};

// Ebisumaru obtains{newline}{endline}
static s16 scenario_text_1BA8[] = {
    CHR_E, CHR_b, CHR_i, CHR_s, CHR_u, CHR_m, CHR_a, CHR_r, CHR_u, PCT_SPACE,
    CHR_o, CHR_b, CHR_t, CHR_a, CHR_i, CHR_n, CHR_s, CTR_NEWLINE, CTR_ENDLINE
};

//   the [{em-yellow}Mini-Ebisu{/em}] magic powers!{newline}{endline}
static s16 scenario_text_1BCF[] = {
    PCT_SPACE, PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE, PCT_LBRACKET, CTR_EM_YELLOW, CHR_M, CHR_i,
    CHR_n, CHR_i, PCT_DASH, CHR_E, CHR_b, CHR_i, CHR_s, CHR_u, CTR_CLOSE_EM, PCT_RBRACKET,
    PCT_SPACE, CHR_m, CHR_a, CHR_g, CHR_i, CHR_c, PCT_SPACE, CHR_p, CHR_o, CHR_w,
    CHR_e, CHR_r, CHR_s, PCT_EXCLAMATION, CTR_NEWLINE, CTR_ENDLINE
};

// {button}{endline}
static s16 scenario_text_1C15[] = {
    CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_1C2A[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// The powers will allow you to{newline}{endline}
static s16 scenario_text_1C42[] = {
    CHR_T, CHR_h, CHR_e, PCT_SPACE, CHR_p, CHR_o, CHR_w, CHR_e, CHR_r, CHR_s,
    PCT_SPACE, CHR_w, CHR_i, CHR_l, CHR_l, PCT_SPACE, CHR_a, CHR_l, CHR_l, CHR_o,
    CHR_w, PCT_SPACE, CHR_y, CHR_o, CHR_u, PCT_SPACE, CHR_t, CHR_o, CTR_NEWLINE, CTR_ENDLINE
};

// {em-yellow}shrink{/em} and get through{newline}{endline}
static s16 scenario_text_1C74[] = {
    CTR_EM_YELLOW, CHR_s, CHR_h, CHR_r, CHR_i, CHR_n, CHR_k, CTR_CLOSE_EM, PCT_SPACE, CHR_a,
    CHR_n, CHR_d, PCT_SPACE, CHR_g, CHR_e, CHR_t, PCT_SPACE, CHR_t, CHR_h, CHR_r,
    CHR_o, CHR_u, CHR_g, CHR_h, CTR_NEWLINE, CTR_ENDLINE
};

// {em-yellow}small holes{/em} and {em-yellow}narrow roads{/em}!{button}{endline}
static s16 scenario_text_1CB0[] = {
    CTR_EM_YELLOW, CHR_s, CHR_m, CHR_a, CHR_l, CHR_l, PCT_SPACE, CHR_h, CHR_o, CHR_l,
    CHR_e, CHR_s, CTR_CLOSE_EM, PCT_SPACE, CHR_a, CHR_n, CHR_d, PCT_SPACE, CTR_EM_YELLOW, CHR_n,
    CHR_a, CHR_r, CHR_r, CHR_o, CHR_w, PCT_SPACE, CHR_r, CHR_o, CHR_a, CHR_d,
    CHR_s, CTR_CLOSE_EM, PCT_EXCLAMATION, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_1D02[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// However, remember that while{newline}{endline}
static s16 scenario_text_1D1A[] = {
    CHR_H, CHR_o, CHR_w, CHR_e, CHR_v, CHR_e, CHR_r, PCT_COMMA, PCT_SPACE, CHR_r,
    CHR_e, CHR_m, CHR_e, CHR_m, CHR_b, CHR_e, CHR_r, PCT_SPACE, CHR_t, CHR_h,
    CHR_a, CHR_t, PCT_SPACE, CHR_w, CHR_h, CHR_i, CHR_l, CHR_e, CTR_NEWLINE, CTR_ENDLINE
};

// using the {em-yellow}Mini-Ebisu{/em} powers,{newline}{endline}
static s16 scenario_text_1D4C[] = {
    CHR_u, CHR_s, CHR_i, CHR_n, CHR_g, PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE,
    CTR_EM_YELLOW, CHR_M, CHR_i, CHR_n, CHR_i, PCT_DASH, CHR_E, CHR_b, CHR_i, CHR_s,
    CHR_u, CTR_CLOSE_EM, PCT_SPACE, CHR_p, CHR_o, CHR_w, CHR_e, CHR_r, CHR_s, PCT_COMMA,
    CTR_NEWLINE, CTR_ENDLINE
};

// you will not be able to {em-yellow}attack{/em}!{endline}
static s16 scenario_text_1D8E[] = {
    CHR_y, CHR_o, CHR_u, PCT_SPACE, CHR_w, CHR_i, CHR_l, CHR_l, PCT_SPACE, CHR_n,
    CHR_o, CHR_t, PCT_SPACE, CHR_b, CHR_e, PCT_SPACE, CHR_a, CHR_b, CHR_l, CHR_e,
    PCT_SPACE, CHR_t, CHR_o, PCT_SPACE, CTR_EM_YELLOW, CHR_a, CHR_t, CHR_t, CHR_a, CHR_c,
    CHR_k, CTR_CLOSE_EM, PCT_EXCLAMATION, CTR_ENDLINE
};

// {waitinput}{end}{endline}
static s16 scenario_text_1DCA[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE
};

// Address: @cbec

// {newwindow}{endline}
static s16 scenario_text_1DE7[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Ushiwaka:Looks like you failed.{newline}{endline}
static s16 scenario_text_1DFF[] = {
    CHR_U, CHR_s, CHR_h, CHR_i, CHR_w, CHR_a, CHR_k, CHR_a, PCT_COLON, CHR_L,
    CHR_o, CHR_o, CHR_k, CHR_s, PCT_SPACE, CHR_l, CHR_i, CHR_k, CHR_e, PCT_SPACE,
    CHR_y, CHR_o, CHR_u, PCT_SPACE, CHR_f, CHR_a, CHR_i, CHR_l, CHR_e, CHR_d,
    PCT_PERIOD, CTR_NEWLINE, CTR_ENDLINE
};

//        You wanna try again?{newline}{endline}
static s16 scenario_text_1E34[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_Y, CHR_o, CHR_u,
    PCT_SPACE, CHR_w, CHR_a, CHR_n, CHR_n, CHR_a, PCT_SPACE, CHR_t, CHR_r, CHR_y,
    PCT_SPACE, CHR_a, CHR_g, CHR_a, CHR_i, CHR_n, PCT_QUESTION, CTR_NEWLINE, CTR_ENDLINE
};

//   {em-yellow}Absolutely!{newline}{endline}
static s16 scenario_text_1E65[] = {
    PCT_SPACE, PCT_SPACE, CTR_EM_YELLOW, CHR_A, CHR_b, CHR_s, CHR_o, CHR_l, CHR_u, CHR_t,
    CHR_e, CHR_l, CHR_y, PCT_EXCLAMATION, CTR_NEWLINE, CTR_ENDLINE
};

//   {em-yellow}I need to rest a little.{newline}{endline}
static s16 scenario_text_1E93[] = {
    PCT_SPACE, PCT_SPACE, CTR_EM_YELLOW, CHR_I, PCT_SPACE, CHR_n, CHR_e, CHR_e, CHR_d, PCT_SPACE,
    CHR_t, CHR_o, PCT_SPACE, CHR_r, CHR_e, CHR_s, CHR_t, PCT_SPACE, CHR_a, PCT_SPACE,
    CHR_l, CHR_i, CHR_t, CHR_t, CHR_l, CHR_e, PCT_PERIOD, CTR_NEWLINE, CTR_ENDLINE
};

// {end}{endline}
static s16 scenario_text_1ECE[] = {
    CTR_END, CTR_ENDLINE
};

// Address: @cc48

// {newwindow}{endline}
static s16 scenario_text_1EE0[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// {/em}That's what I wanna hear!{newline}{endline}
static s16 scenario_text_1EF8[] = {
    CTR_CLOSE_EM, CHR_T, CHR_h, CHR_a, CHR_t, PCT_APOSTROPHE, CHR_s, PCT_SPACE, CHR_w, CHR_h,
    CHR_a, CHR_t, PCT_SPACE, CHR_I, PCT_SPACE, CHR_w, CHR_a, CHR_n, CHR_n, CHR_a,
    PCT_SPACE, CHR_h, CHR_e, CHR_a, CHR_r, PCT_EXCLAMATION, CTR_NEWLINE, CTR_ENDLINE
};

// Thats the spirit!{endline}
static s16 scenario_text_1F2C[] = {
    CHR_T, CHR_h, CHR_a, CHR_t, CHR_s, PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE,
    CHR_s, CHR_p, CHR_i, CHR_r, CHR_i, CHR_t, PCT_EXCLAMATION, CTR_ENDLINE
};

// {waitinput}{end}{endline}
static s16 scenario_text_1F4A[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE
};

// Address: @cc84

// {newwindow}{endline}
static s16 scenario_text_1F67[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// {/em}Is that so...{newline}{endline}
static s16 scenario_text_1F7F[] = {
    CTR_CLOSE_EM, CHR_I, CHR_s, PCT_SPACE, CHR_t, CHR_h, CHR_a, CHR_t, PCT_SPACE, CHR_s,
    CHR_o, PCT_PERIOD, PCT_PERIOD, PCT_PERIOD, CTR_NEWLINE, CTR_ENDLINE
};

// In that case,{newline}{endline}
static s16 scenario_text_1FA7[] = {
    CHR_I, CHR_n, PCT_SPACE, CHR_t, CHR_h, CHR_a, CHR_t, PCT_SPACE, CHR_c, CHR_a,
    CHR_s, CHR_e, PCT_COMMA, CTR_NEWLINE, CTR_ENDLINE
};

// come back when you're ready!{endline}
static s16 scenario_text_1FCA[] = {
    CHR_c, CHR_o, CHR_m, CHR_e, PCT_SPACE, CHR_b, CHR_a, CHR_c, CHR_k, PCT_SPACE,
    CHR_w, CHR_h, CHR_e, CHR_n, PCT_SPACE, CHR_y, CHR_o, CHR_u, PCT_APOSTROPHE, CHR_r,
    CHR_e, PCT_SPACE, CHR_r, CHR_e, CHR_a, CHR_d, CHR_y, PCT_EXCLAMATION, CTR_ENDLINE
};

// {waitinput}{end}{endline}
static s16 scenario_text_1FF3[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE
};

// Address: @ccc0

// Ushiwaka:You've returned to{newline}{endline}
static s16 scenario_text_2010[] = {
    CHR_U, CHR_s, CHR_h, CHR_i, CHR_w, CHR_a, CHR_k, CHR_a, PCT_COLON, CHR_Y,
    CHR_o, CHR_u, PCT_APOSTROPHE, CHR_v, CHR_e, PCT_SPACE, CHR_r, CHR_e, CHR_t, CHR_u,
    CHR_r, CHR_n, CHR_e, CHR_d, PCT_SPACE, CHR_t, CHR_o, CTR_NEWLINE, CTR_ENDLINE
};

//        give it another shot?{newline}{endline}
static s16 scenario_text_2041[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_g, CHR_i, CHR_v,
    CHR_e, PCT_SPACE, CHR_i, CHR_t, PCT_SPACE, CHR_a, CHR_n, CHR_o, CHR_t, CHR_h,
    CHR_e, CHR_r, PCT_SPACE, CHR_s, CHR_h, CHR_o, CHR_t, PCT_QUESTION, CTR_NEWLINE, CTR_ENDLINE
};

//   {em-yellow}You bet.{newline}{endline}
static s16 scenario_text_2073[] = {
    PCT_SPACE, PCT_SPACE, CTR_EM_YELLOW, CHR_Y, CHR_o, CHR_u, PCT_SPACE, CHR_b, CHR_e, CHR_t,
    PCT_PERIOD, CTR_NEWLINE, CTR_ENDLINE
};

//   {em-yellow}Well, not quite...{newline}{endline}
static s16 scenario_text_209E[] = {
    PCT_SPACE, PCT_SPACE, CTR_EM_YELLOW, CHR_W, CHR_e, CHR_l, CHR_l, PCT_COMMA, PCT_SPACE, CHR_n,
    CHR_o, CHR_t, PCT_SPACE, CHR_q, CHR_u, CHR_i, CHR_t, CHR_e, PCT_PERIOD, PCT_PERIOD,
    PCT_PERIOD, CTR_NEWLINE, CTR_ENDLINE
};

// {end}{endline}
static s16 scenario_text_20D3[] = {
    CTR_END, CTR_ENDLINE
};

// Address: @cd04

// {newwindow}{endline}
static s16 scenario_text_20E5[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Ushiwaka:When you're smaller,{newline}{endline}
static s16 scenario_text_20FD[] = {
    CHR_U, CHR_s, CHR_h, CHR_i, CHR_w, CHR_a, CHR_k, CHR_a, PCT_COLON, CHR_W,
    CHR_h, CHR_e, CHR_n, PCT_SPACE, CHR_y, CHR_o, CHR_u, PCT_APOSTROPHE, CHR_r, CHR_e,
    PCT_SPACE, CHR_s, CHR_m, CHR_a, CHR_l, CHR_l, CHR_e, CHR_r, PCT_COMMA, CTR_NEWLINE,
    CTR_ENDLINE
};

//        you don't need to{newline}{endline}
static s16 scenario_text_2130[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_y, CHR_o, CHR_u,
    PCT_SPACE, CHR_d, CHR_o, CHR_n, PCT_APOSTROPHE, CHR_t, PCT_SPACE, CHR_n, CHR_e, CHR_e,
    CHR_d, PCT_SPACE, CHR_t, CHR_o, CTR_NEWLINE, CTR_ENDLINE
};

//        eat as much,{button}{endline}
static s16 scenario_text_215E[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_e, CHR_a, CHR_t,
    PCT_SPACE, CHR_a, CHR_s, PCT_SPACE, CHR_m, CHR_u, CHR_c, CHR_h, PCT_COMMA, CTR_BUTTON,
    CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_2186[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// and a room can seem so large,{newline}{endline}
static s16 scenario_text_219E[] = {
    CHR_a, CHR_n, CHR_d, PCT_SPACE, CHR_a, PCT_SPACE, CHR_r, CHR_o, CHR_o, CHR_m,
    PCT_SPACE, CHR_c, CHR_a, CHR_n, PCT_SPACE, CHR_s, CHR_e, CHR_e, CHR_m, PCT_SPACE,
    CHR_s, CHR_o, PCT_SPACE, CHR_l, CHR_a, CHR_r, CHR_g, CHR_e, PCT_COMMA, CTR_NEWLINE,
    CTR_ENDLINE
};

// that even a bachelor pad will{newline}{endline}
static s16 scenario_text_21D1[] = {
    CHR_t, CHR_h, CHR_a, CHR_t, PCT_SPACE, CHR_e, CHR_v, CHR_e, CHR_n, PCT_SPACE,
    CHR_a, PCT_SPACE, CHR_b, CHR_a, CHR_c, CHR_h, CHR_e, CHR_l, CHR_o, CHR_r,
    PCT_SPACE, CHR_p, CHR_a, CHR_d, PCT_SPACE, CHR_w, CHR_i, CHR_l, CHR_l, CTR_NEWLINE,
    CTR_ENDLINE
};

// look like a castle!{endline}
static s16 scenario_text_2204[] = {
    CHR_l, CHR_o, CHR_o, CHR_k, PCT_SPACE, CHR_l, CHR_i, CHR_k, CHR_e, PCT_SPACE,
    CHR_a, PCT_SPACE, CHR_c, CHR_a, CHR_s, CHR_t, CHR_l, CHR_e, PCT_EXCLAMATION, CTR_ENDLINE
};

// {waitinput}{end}{endline}
static s16 scenario_text_2224[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE
};

extern s32 scenario_code_message_160_c028[];
extern s32 scenario_code_message_160_c0a8[];
extern s32 scenario_code_message_160_c0ec[];
extern s32 scenario_code_message_160_c17c[];
extern s32 scenario_code_message_160_c1a8[];
extern s32 scenario_code_message_160_c23c[];
extern s32 scenario_code_message_160_c2c0[];
extern s32 scenario_code_message_160_c324[];
extern s32 scenario_code_message_160_c350[];
extern s32 scenario_code_message_160_c38c[];
extern s32 scenario_code_message_160_c3f0[];
extern s32 scenario_code_message_160_c42c[];
extern s32 scenario_code_message_160_c490[];
extern s32 scenario_code_message_160_c4cc[];
extern s32 scenario_code_message_160_c690[];
extern s32 scenario_code_message_160_c6b4[];
extern s32 scenario_code_message_160_c838[];
extern s32 scenario_code_message_160_ca28[];
extern s32 scenario_code_message_160_ca5c[];
extern s32 scenario_code_message_160_cbec[];
extern s32 scenario_code_message_160_cc48[];
extern s32 scenario_code_message_160_cc84[];
extern s32 scenario_code_message_160_ccc0[];
extern s32 scenario_code_message_160_cd04[];


s32 scenario_code_message_160_c028[] = {

    // Address: @c028
    // MACHI 21 - Zazen - Ushiwaka - Ushiwaka

    // cd04: Print Text
    TXT, (s32)&scenario_text_0000,

    // c048: If Flag 029 (Obtained Achilles' Heel), Jump To @cd041
    // Jump if flag 0x29 is SET to @cd041
    JFS, 0x29, (s32)&scenario_code_message_160_cd04,

    // c054: If Flag 02a (Looking for Red Fish), Jump To @c490
    // Jump if flag 0x2A is SET to @c490
    JFS, 0x2A, (s32)&scenario_code_message_160_c490,

    // c060: If Flag 02b (Looking for Yellow Fish), Jump To @c3f0
    // Jump if flag 0x2B is SET to @c3f0
    JFS, 0x2B, (s32)&scenario_code_message_160_c3f0,

    // c06c: If Flag 02c (Looking for Blue Fish), Jump To @c350
    // Jump if flag 0x2C is SET to @c350
    JFS, 0x2C, (s32)&scenario_code_message_160_c350,

    // c078: If Flag 025 (Can Talk to Ushiwaka about Benkei), Jump To @c0a8
    // Jump if flag 0x25 is SET to @c0a8
    JFS, 0x25, (s32)&scenario_code_message_160_c0a8,

    // Jump To @cd041
    JMP, (s32)&scenario_code_message_160_cd04,

    // End scenario script
    END,
};

s32 scenario_code_message_160_c0a8[] = {

    // Address: @c0a8

    // c0a8: Print Text
    TXT, (s32)&scenario_text_00BC,

    // c0b0: Print Text
    TXT, (s32)&scenario_text_00D7,

    // c0b8: Begin Option Selection
    BOS,

    // c0bc: Print Text
    TXT, (s32)&scenario_text_00FA,

    // c0c4: Jump To @c0ec
    JMP, (s32)&scenario_code_message_160_c0ec,

    // c0cc: Print Text
    TXT, (s32)&scenario_text_0129,

    // c0d4: Jump To @c1a8
    JMP, (s32)&scenario_code_message_160_c1a8,

    // c0dc: End Option Selection
    EOS,

    // c0e0: Print Text
    TXT, (s32)&scenario_text_015F,

    // c0e8: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_160_c0ec[] = {

    // Address: @c0ec

    // c0ec: If Flag 02d (Asked Ushiwaka Who He Is), Jump To @c17c
    // Jump if flag 0x2D is SET to @c17c
    JFS, 0x2D, (s32)&scenario_code_message_160_c17c,

    // c0f8: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // c100: Store Value: 1
    WTS, 0x1,

    // c108: Print Text
    TXT, (s32)&scenario_text_0171,

    // c110: Print Text
    TXT, (s32)&scenario_text_0189,

    // c118: Print Text
    TXT, (s32)&scenario_text_01C0,

    // c120: Print Text
    TXT, (s32)&scenario_text_01DF,

    // c128: Print Text
    TXT, (s32)&scenario_text_0171,

    // c130: Print Text
    TXT, (s32)&scenario_text_0223,

    // c138: Print Text
    TXT, (s32)&scenario_text_0254,

    // c140: Print Text
    TXT, (s32)&scenario_text_0171,

    // c148: Print Text
    TXT, (s32)&scenario_text_029A,

    // c150: Print Text
    TXT, (s32)&scenario_text_02CD,

    // c158: Print Text
    TXT, (s32)&scenario_text_030D,

    // c160: Print Text
    TXT, (s32)&scenario_text_032D,

    // c168: Set Flag 02d (Asked Ushiwaka Who He Is)
    SFG, 0x2D,

    // c170: Print Text
    TXT, (s32)&scenario_text_009F,

    // c178: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_160_c17c[] = {

    // Address: @c17c

    // c17c: Print Text
    TXT, (s32)&scenario_text_0171,

    // c184: Print Text
    TXT, (s32)&scenario_text_0381,

    // c18c: Print Text
    TXT, (s32)&scenario_text_03BA,

    // c194: Print Text
    TXT, (s32)&scenario_text_03DE,

    // c19c: Print Text
    TXT, (s32)&scenario_text_009F,

    // c1a4: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_160_c1a8[] = {

    // Address: @c1a8

    // c1a8: Print Text
    TXT, (s32)&scenario_text_0171,

    // c1b0: Print Text
    TXT, (s32)&scenario_text_043B,

    // c1b8: Print Text
    TXT, (s32)&scenario_text_0465,

    // c1c0: Print Text
    TXT, (s32)&scenario_text_0171,

    // c1c8: Print Text
    TXT, (s32)&scenario_text_04AD,

    // c1d0: Print Text
    TXT, (s32)&scenario_text_0171,

    // c1d8: Print Text
    TXT, (s32)&scenario_text_04E7,

    // c1e0: Print Text
    TXT, (s32)&scenario_text_051E,

    // c1e8: Print Text
    TXT, (s32)&scenario_text_055A,

    // c1f0: Print Text
    TXT, (s32)&scenario_text_0171,

    // c1f8: Print Text
    TXT, (s32)&scenario_text_05AE,

    // c200: Print Text
    TXT, (s32)&scenario_text_05CF,

    // c208: Begin Option Selection
    BOS,

    // c20c: Print Text
    TXT, (s32)&scenario_text_05E7,

    // c214: Jump To @c23c
    JMP, (s32)&scenario_code_message_160_c23c,

    // c21c: Print Text
    TXT, (s32)&scenario_text_0618,

    // c224: Jump To @c324
    JMP, (s32)&scenario_code_message_160_c324,

    // c22c: End Option Selection
    EOS,

    // c230: Print Text
    TXT, (s32)&scenario_text_015F,

    // c238: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_160_c23c[] = {

    // Address: @c23c

    // c23c: Print Text
    TXT, (s32)&scenario_text_0171,

    // c244: Print Text
    TXT, (s32)&scenario_text_067A,

    // c24c: Print Text
    TXT, (s32)&scenario_text_06B4,

    // c254: Print Text
    TXT, (s32)&scenario_text_0171,

    // c25c: Print Text
    TXT, (s32)&scenario_text_06F1,

    // c264: Print Text
    TXT, (s32)&scenario_text_0724,

    // c26c: Print Text
    TXT, (s32)&scenario_text_075B,

    // c274: Print Text
    TXT, (s32)&scenario_text_0171,

    // c27c: Print Text
    TXT, (s32)&scenario_text_079A,

    // c284: Print Text
    TXT, (s32)&scenario_text_05CF,

    // c28c: Begin Option Selection
    BOS,

    // c290: Print Text
    TXT, (s32)&scenario_text_07E0,

    // c298: Jump To @c2c0
    JMP, (s32)&scenario_code_message_160_c2c0,

    // c2a0: Print Text
    TXT, (s32)&scenario_text_0813,

    // c2a8: Jump To @c324
    JMP, (s32)&scenario_code_message_160_c324,

    // c2b0: End Option Selection
    EOS,

    // c2b4: Print Text
    TXT, (s32)&scenario_text_015F,

    // c2bc: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_160_c2c0[] = {

    // Address: @c2c0

    // c2c0: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // c2c8: Store Value: 1
    WTS, 0x1,

    // c2d0: Print Text
    TXT, (s32)&scenario_text_0171,

    // c2d8: Print Text
    TXT, (s32)&scenario_text_0867,

    // c2e0: Print Text
    TXT, (s32)&scenario_text_0171,

    // c2e8: Print Text
    TXT, (s32)&scenario_text_08AB,

    // c2f0: Print Text
    TXT, (s32)&scenario_text_0900,

    // c2f8: Print Text
    TXT, (s32)&scenario_text_0171,

    // c300: Print Text
    TXT, (s32)&scenario_text_094C,

    // c308: Set Flag 02c (Looking for Blue Fish)
    SFG, 0x2C,

    // c310: Set Flag 003 (???)
    SFG, 0x03,

    // c318: Print Text
    TXT, (s32)&scenario_text_009F,

    // c320: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_160_c324[] = {

    // Address: @c324

    // c324: Print Text
    TXT, (s32)&scenario_text_0171,

    // c32c: Print Text
    TXT, (s32)&scenario_text_09CD,

    // c334: Print Text
    TXT, (s32)&scenario_text_09F5,

    // c33c: Print Text
    TXT, (s32)&scenario_text_0A2B,

    // c344: Print Text
    TXT, (s32)&scenario_text_009F,

    // c34c: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_160_c350[] = {

    // Address: @c350

    // c350: Read from RAM 8015c720 (Total Blue Fish Obtained)
    LDW, 0x8015c720,

    // c358: Skip Next If Not Equal: 3
    SNE, 0x3,

    // c360: Jump To @c38c
    JMP, (s32)&scenario_code_message_160_c38c,

    // c368: Print Text
    TXT, (s32)&scenario_text_0171,

    // c370: Print Text
    TXT, (s32)&scenario_text_0A74,

    // c378: Print Text
    TXT, (s32)&scenario_text_0A96,

    // c380: Print Text
    TXT, (s32)&scenario_text_009F,

    // c388: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_160_c38c[] = {

    // Address: @c38c

    // c38c: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // c394: Store Value: 1
    WTS, 0x1,

    // c39c: Print Text
    TXT, (s32)&scenario_text_0171,

    // c3a4: Print Text
    TXT, (s32)&scenario_text_0B17,

    // c3ac: Print Text
    TXT, (s32)&scenario_text_0171,

    // c3b4: Print Text
    TXT, (s32)&scenario_text_0B4F,

    // c3bc: Print Text
    TXT, (s32)&scenario_text_0B77,

    // c3c4: Write to RAM 8015c720 (Total Blue Fish Obtained)
    STW, 0x8015c720,

    // c3cc: Store Value: 0
    WTS, 0x0,

    // c3d4: Set Flag 003 (???)
    SFG, 0x03,

    // c3dc: Set Flag 02b (Looking for Yellow Fish)
    SFG, 0x2B,

    // c3e4: Print Text
    TXT, (s32)&scenario_text_009F,

    // c3ec: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_160_c3f0[] = {

    // Address: @c3f0

    // c3f0: Read from RAM 8015c71c (Total Yellow Fish Obtained)
    LDW, 0x8015c71c,

    // c3f8: Skip Next If Not Equal: 5
    SNE, 0x5,

    // c400: Jump To @c42c
    JMP, (s32)&scenario_code_message_160_c42c,

    // c408: Print Text
    TXT, (s32)&scenario_text_0171,

    // c410: Print Text
    TXT, (s32)&scenario_text_0A74,

    // c418: Print Text
    TXT, (s32)&scenario_text_0C1E,

    // c420: Print Text
    TXT, (s32)&scenario_text_009F,

    // c428: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_160_c42c[] = {

    // Address: @c42c

    // c42c: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // c434: Store Value: 1
    WTS, 0x1,

    // c43c: Print Text
    TXT, (s32)&scenario_text_0171,

    // c444: Print Text
    TXT, (s32)&scenario_text_0CA1,

    // c44c: Print Text
    TXT, (s32)&scenario_text_0171,

    // c454: Print Text
    TXT, (s32)&scenario_text_0CDA,

    // c45c: Print Text
    TXT, (s32)&scenario_text_0D07,

    // c464: Write to RAM 8015c71c (Total Yellow Fish Obtained)
    STW, 0x8015c71c,

    // c46c: Store Value: 0
    WTS, 0x0,

    // c474: Set Flag 02a (Looking for Red Fish)
    SFG, 0x2A,

    // c47c: Set Flag 003 (???)
    SFG, 0x03,

    // c484: Print Text
    TXT, (s32)&scenario_text_009F,

    // c48c: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_160_c490[] = {

    // Address: @c490

    // c490: Read from RAM 8015c718 (Total Red Fish Obtained)
    LDW, 0x8015c718,

    // c498: Skip Next If Not Equal: 8
    SNE, 0x8,

    // c4a0: Jump To @c4cc
    JMP, (s32)&scenario_code_message_160_c4cc,

    // c4a8: Print Text
    TXT, (s32)&scenario_text_0171,

    // c4b0: Print Text
    TXT, (s32)&scenario_text_0A74,

    // c4b8: Print Text
    TXT, (s32)&scenario_text_0DB1,

    // c4c0: Print Text
    TXT, (s32)&scenario_text_009F,

    // c4c8: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_160_c4cc[] = {

    // Address: @c4cc

    // c4cc: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // c4d4: Store Value: 1
    WTS, 0x1,

    // c4dc: Print Text
    TXT, (s32)&scenario_text_0171,

    // c4e4: Write to RAM 801c77d8 (Text Speed)
    STW, 0x801c77d8,

    // c4ec: Store Value: 64
    WTS, 0x64,

    // c4f4: Write to RAM 801c7798 (Unknown)
    STW, 0x801c7798,

    // c4fc: Store Value: 1
    WTS, 0x1,

    // c504: Print Text
    TXT, (s32)&scenario_text_05CF,

    // c50c: Print Text
    TXT, (s32)&scenario_text_0E4A,

    // c514: Write to RAM 801c77d8 (Text Speed)
    STW, 0x801c77d8,

    // c51c: Store Value: 1
    WTS, 0x1,

    // c524: Write to RAM 801c7798 (Unknown)
    STW, 0x801c7798,

    // c52c: Store Value: 1
    WTS, 0x1,

    // c534: Print Text
    TXT, (s32)&scenario_text_0171,

    // c53c: Print Text
    TXT, (s32)&scenario_text_0EB0,

    // c544: Print Text
    TXT, (s32)&scenario_text_0EDA,

    // c54c: Print Text
    TXT, (s32)&scenario_text_0171,

    // c554: Print Text
    TXT, (s32)&scenario_text_0F27,

    // c55c: Set Flag 004 (???)
    SFG, 0x04,

    // c564: Write to RAM 801c7740 (Scratch)
    STW, (s32)&D_801C7740_1C8340,

    // c56c: Store Value: 3c
    WTS, 0x3C,

    // c574: Execute Code: 8003f460 (Wait For Timer)
    ESR, (s32)&func_8003F460_40060,

    // c57c: Print Text
    TXT, (s32)&scenario_text_0171,

    // c584: Print Text
    TXT, (s32)&scenario_text_0F6A,

    // c58c: Print Text
    TXT, (s32)&scenario_text_0F95,

    // c594: Print Text
    TXT, (s32)&scenario_text_0171,

    // c59c: Print Text
    TXT, (s32)&scenario_text_015F,

    // c5a4: Write to RAM 8015c718 (Total Red Fish Obtained)
    STW, 0x8015c718,

    // c5ac: Store Value: 0
    WTS, 0x0,

    // c5b4: Write to RAM 801c7758 (Unknown)
    STW, (s32)&D_801C7758_1C8358,

    // c5bc: Store Value: 20
    WTS, 0x20,

    // c5c4: Write to RAM 801c775c (Dialogue Window Y Pos)
    STW, (s32)&D_801C775C_1C835C,

    // c5cc: Store Value: 48
    WTS, 0x48,

    // c5d4: Write to RAM 801c7768 (Dialogue Window Style)
    STW, (s32)&D_801C7768_1C8368,

    // c5dc: Store Value: 7
    WTS, 0x7,

    // c5e4: Print Text
    TXT, (s32)&scenario_text_0000,

    // c5ec: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // c5f4: Store Value: 1
    WTS, 0x1,

    // c5fc: Write to RAM 801c77d8 (Text Speed)
    STW, 0x801c77d8,

    // c604: Store Value: 64
    WTS, 0x64,

    // c60c: Write to RAM 801c7798 (Unknown)
    STW, 0x801c7798,

    // c614: Store Value: 1
    WTS, 0x1,

    // c61c: Print Text
    TXT, (s32)&scenario_text_0171,

    // c624: Write to RAM 801c7740 (Scratch)
    STW, (s32)&D_801C7740_1C8340,

    // c62c: Store Value: 14
    WTS, 0x14,

    // c634: Execute Code: 8003f608 (Play Sound)
    ESR, (s32)&func_8003F608_40208,

    // c63c: Print Text
    TXT, (s32)&scenario_text_05CF,

    // c644: Print Text
    TXT, (s32)&scenario_text_1039,

    // c64c: Print Text
    TXT, (s32)&scenario_text_1061,

    // DISABLED ITEM
    // // c654: Write to RAM 8015c70c (Obtained Achilles Heel)
    // STW, 0x8015c70c,

    // // c65c: Store Value: 1
    // WTS, 0x1,

    // c664: Set Flag 029 (Obtained Achilles' Heel)
    SFG, 0x29,

    // c66c: Write to RAM 801c7740 (Scratch)
    STW, (s32)&D_801C7740_1C8340,

    // c674: Store Value: 96
    WTS, 0x96,

    // c67c: Execute Code: 8003f460 (Wait For Timer)
    ESR, (s32)&func_8003F460_40060,

    // c684: Print Text
    TXT, (s32)&scenario_text_015F,

    // c68c: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_160_c690[] = {

    // Address: @c690

    // c690: Print Text
    TXT, (s32)&scenario_text_10B1,

    // c698: Print Text
    TXT, (s32)&scenario_text_10E6,

    // c6a0: Print Text
    TXT, (s32)&scenario_text_1113,

    // c6a8: Print Text
    TXT, (s32)&scenario_text_009F,

    // c6b0: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_160_c6b4[] = {

    // Address: @c6b4

    // c6b4: Write to RAM 801c7758 (Unknown)
    STW, (s32)&D_801C7758_1C8358,

    // c6bc: Store Value: 20
    WTS, 0x20,

    // c6c4: Write to RAM 801c775c (Dialogue Window Y Pos)
    STW, (s32)&D_801C775C_1C835C,

    // c6cc: Store Value: 68
    WTS, 0x68,

    // c6d4: Print Text
    TXT, (s32)&scenario_text_0000,

    // c6dc: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // c6e4: Store Value: 1
    WTS, 0x1,

    // c6ec: Print Text
    TXT, (s32)&scenario_text_1165,

    // c6f4: Print Text
    TXT, (s32)&scenario_text_0171,

    // c6fc: Print Text
    TXT, (s32)&scenario_text_11A8,

    // c704: Write to RAM 801c7758 (Unknown)
    STW, (s32)&D_801C7758_1C8358,

    // c70c: Store Value: 20
    WTS, 0x20,

    // c714: Write to RAM 801c775c (Dialogue Window Y Pos)
    STW, (s32)&D_801C775C_1C835C,

    // c71c: Store Value: 68
    WTS, 0x68,

    // c724: Write to RAM 801c7768 (Dialogue Window Style)
    STW, (s32)&D_801C7768_1C8368,

    // c72c: Store Value: 7
    WTS, 0x7,

    // c734: Write to RAM 8007785c (Dialogue Portrait Character)
    STW, (s32)&D_8007785C_7845C,

    // c73c: Store Value: 0
    WTS, 0x0,

    // c744: Print Text
    TXT, (s32)&scenario_text_0000,

    // c74c: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // c754: Store Value: 1
    WTS, 0x1,

    // c75c: Print Text
    TXT, (s32)&scenario_text_11F3,

    // c764: Print Text
    TXT, (s32)&scenario_text_1224,

    // c76c: Write to RAM 801c7758 (Unknown)
    STW, (s32)&D_801C7758_1C8358,

    // c774: Store Value: 20
    WTS, 0x20,

    // c77c: Write to RAM 801c775c (Dialogue Window Y Pos)
    STW, (s32)&D_801C775C_1C835C,

    // c784: Store Value: 68
    WTS, 0x68,

    // c78c: Write to RAM 801c7768 (Dialogue Window Style)
    STW, (s32)&D_801C7768_1C8368,

    // c794: Store Value: 1
    WTS, 0x1,

    // c79c: Write to RAM 8007785c (Dialogue Portrait Character)
    STW, (s32)&D_8007785C_7845C,

    // c7a4: Store Value: 100
    WTS, 0x100,

    // c7ac: Print Text
    TXT, (s32)&scenario_text_0000,

    // c7b4: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // c7bc: Store Value: 1
    WTS, 0x1,

    // c7c4: Print Text
    TXT, (s32)&scenario_text_126E,

    // c7cc: Print Text
    TXT, (s32)&scenario_text_0171,

    // c7d4: Print Text
    TXT, (s32)&scenario_text_12B4,

    // c7dc: Print Text
    TXT, (s32)&scenario_text_12E9,

    // c7e4: Print Text
    TXT, (s32)&scenario_text_0171,

    // c7ec: Print Text
    TXT, (s32)&scenario_text_133A,

    // c7f4: Print Text
    TXT, (s32)&scenario_text_137F,

    // c7fc: Print Text
    TXT, (s32)&scenario_text_13B1,

    // c804: Print Text
    TXT, (s32)&scenario_text_0171,

    // c80c: Print Text
    TXT, (s32)&scenario_text_13EF,

    // c814: Print Text
    TXT, (s32)&scenario_text_1422,

    // c81c: Print Text
    TXT, (s32)&scenario_text_1468,

    // c824: Print Text
    TXT, (s32)&scenario_text_009F,

    // c82c: Set Flag 028 (Ushiwaka Went to Golden Temple)
    SFG, 0x28,

    // c834: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_160_c838[] = {

    // Address: @c838

    // c838: Print Text
    TXT, (s32)&scenario_text_0000,

    // c840: If Flag 02e (Passed Mini-Ebisu Training), Jump To @ca5c
    // Jump if flag 0x2E is SET to @ca5c
    JFS, 0x2E, (s32)&scenario_code_message_160_ca5c,

    // c84c: Execute Code: 8003f594 (Load Current Character)
    ESR, (s32)&func_8003F594_40194,

    // c854: Read from RAM 801c7750 (Scratch)
    LDW, 0x801c7750,

    // c85c: Skip Next If Equal: 1
    SEQ, 0x1,

    // c864: Jump To @ca28
    JMP, (s32)&scenario_code_message_160_ca28,

    // c86c: If Flag 030 (Rejected Mini-Ebisu Training Offer), Jump To @ccc0
    // Jump if flag 0x30 is SET to @ccc0
    JFS, 0x30, (s32)&scenario_code_message_160_ccc0,

    // c878: If Flag 02f (Failed Mini-Ebisu Training), Jump To @cbec
    // Jump if flag 0x2F is SET to @cbec
    JFS, 0x2F, (s32)&scenario_code_message_160_cbec,

    // c884: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // c88c: Store Value: 1
    WTS, 0x1,

    // c894: Print Text
    TXT, (s32)&scenario_text_14C4,

    // c89c: Print Text
    TXT, (s32)&scenario_text_0171,

    // c8a4: Print Text
    TXT, (s32)&scenario_text_1506,

    // c8ac: Set Flag 004 (???)
    SFG, 0x04,

    // c8b4: Write to RAM 801c7758 (Unknown)
    STW, (s32)&D_801C7758_1C8358,

    // c8bc: Store Value: 20
    WTS, 0x20,

    // c8c4: Write to RAM 801c775c (Dialogue Window Y Pos)
    STW, (s32)&D_801C775C_1C835C,

    // c8cc: Store Value: 48
    WTS, 0x48,

    // c8d4: Write to RAM 801c7768 (Dialogue Window Style)
    STW, (s32)&D_801C7768_1C8368,

    // c8dc: Store Value: 1
    WTS, 0x1,

    // c8e4: Write to RAM 8007785c (Dialogue Portrait Character)
    STW, (s32)&D_8007785C_7845C,

    // c8ec: Store Value: 14
    WTS, 0x14,

    // c8f4: Print Text
    TXT, (s32)&scenario_text_0000,

    // c8fc: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // c904: Store Value: 1
    WTS, 0x1,

    // c90c: Print Text
    TXT, (s32)&scenario_text_154D,

    // c914: Print Text
    TXT, (s32)&scenario_text_0171,

    // c91c: Print Text
    TXT, (s32)&scenario_text_159F,

    // c924: Print Text
    TXT, (s32)&scenario_text_15DC,

    // c92c: Print Text
    TXT, (s32)&scenario_text_1618,

    // c934: Print Text
    TXT, (s32)&scenario_text_164D,

    // c93c: Print Text
    TXT, (s32)&scenario_text_0171,

    // c944: Print Text
    TXT, (s32)&scenario_text_1693,

    // c94c: Print Text
    TXT, (s32)&scenario_text_16D4,

    // c954: Print Text
    TXT, (s32)&scenario_text_1706,

    // c95c: Print Text
    TXT, (s32)&scenario_text_0171,

    // c964: Print Text
    TXT, (s32)&scenario_text_1741,

    // c96c: Print Text
    TXT, (s32)&scenario_text_1777,

    // c974: Print Text
    TXT, (s32)&scenario_text_17B9,

    // c97c: Print Text
    TXT, (s32)&scenario_text_0171,

    // c984: Print Text
    TXT, (s32)&scenario_text_17F7,

    // c98c: Print Text
    TXT, (s32)&scenario_text_181E,

    // c994: Print Text
    TXT, (s32)&scenario_text_1851,

    // c99c: Print Text
    TXT, (s32)&scenario_text_0171,

    // c9a4: Print Text
    TXT, (s32)&scenario_text_18A3,

    // c9ac: Print Text
    TXT, (s32)&scenario_text_18D7,

    // c9b4: Print Text
    TXT, (s32)&scenario_text_0171,

    // c9bc: Print Text
    TXT, (s32)&scenario_text_1916,

    // c9c4: Print Text
    TXT, (s32)&scenario_text_0171,

    // c9cc: Write to RAM 801c77d8 (Text Speed)
    STW, 0x801c77d8,

    // c9d4: Store Value: 64
    WTS, 0x64,

    // c9dc: Write to RAM 801c7798 (Unknown)
    STW, 0x801c7798,

    // c9e4: Store Value: 1
    WTS, 0x1,

    // c9ec: Print Text
    TXT, (s32)&scenario_text_1959,

    // c9f4: Print Text
    TXT, (s32)&scenario_text_1978,

    // c9fc: Write to RAM 801c7740 (Scratch)
    STW, (s32)&D_801C7740_1C8340,

    // ca04: Store Value: 292
    WTS, 0x292,

    // ca0c: Execute Code: 8003f608 (Play Sound)
    ESR, (s32)&func_8003F608_40208,

    // ca14: Print Text
    TXT, (s32)&scenario_text_009F,

    // ca1c: Set Flag 07d (Started Mini-Ebisu Minigame)
    SFG, 0x7D,

    // ca24: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_160_ca28[] = {

    // Address: @ca28

    // ca28: Print Text
    TXT, (s32)&scenario_text_19DB,

    // ca30: Print Text
    TXT, (s32)&scenario_text_19FA,

    // ca38: Print Text
    TXT, (s32)&scenario_text_0171,

    // ca40: Print Text
    TXT, (s32)&scenario_text_1A46,

    // ca48: Print Text
    TXT, (s32)&scenario_text_1A77,

    // ca50: Print Text
    TXT, (s32)&scenario_text_009F,

    // ca58: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_160_ca5c[] = {

    // Address: @ca5c

    // ca5c: If Flag 031 (Obtained Mini-Ebisu Magic), Jump To @cd04
    // Jump if flag 0x31 is SET to @cd04
    JFS, 0x31, (s32)&scenario_code_message_160_cd04,

    // ca68: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // ca70: Store Value: 1
    WTS, 0x1,

    // ca78: Print Text
    TXT, (s32)&scenario_text_0171,

    // ca80: Print Text
    TXT, (s32)&scenario_text_1AF7,

    // ca88: Print Text
    TXT, (s32)&scenario_text_1B20,

    // ca90: Print Text
    TXT, (s32)&scenario_text_1B4F,

    // ca98: Write to RAM 801c7758 (Unknown)
    STW, (s32)&D_801C7758_1C8358,

    // caa0: Store Value: 20
    WTS, 0x20,

    // caa8: Write to RAM 801c775c (Dialogue Window Y Pos)
    STW, (s32)&D_801C775C_1C835C,

    // cab0: Store Value: 48
    WTS, 0x48,

    // cab8: Write to RAM 801c7768 (Dialogue Window Style)
    STW, (s32)&D_801C7768_1C8368,

    // cac0: Store Value: 7
    WTS, 0x7,

    // cac8: Print Text
    TXT, (s32)&scenario_text_0000,

    // cad0: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // cad8: Store Value: 1
    WTS, 0x1,

    // cae0: Write to RAM 801c77d8 (Text Speed)
    STW, 0x801c77d8,

    // cae8: Store Value: 64
    WTS, 0x64,

    // caf0: Write to RAM 801c7798 (Unknown)
    STW, 0x801c7798,

    // caf8: Store Value: 1
    WTS, 0x1,

    // cb00: Write to RAM 801c7740 (Scratch)
    STW, (s32)&D_801C7740_1C8340,

    // cb08: Store Value: 14
    WTS, 0x14,

    // cb10: Execute Code: 8003f608 (Play Sound)
    ESR, (s32)&func_8003F608_40208,

    // cb18: Print Text
    TXT, (s32)&scenario_text_05CF,

    // cb20: Print Text
    TXT, (s32)&scenario_text_1BA8,

    // cb28: Print Text
    TXT, (s32)&scenario_text_1BCF,

    // cb30: Write to RAM 801c7740 (Scratch)
    STW, (s32)&D_801C7740_1C8340,

    // cb38: Store Value: 96
    WTS, 0x96,

    // cb40: Execute Code: 8003f460 (Wait For Timer)
    ESR, (s32)&func_8003F460_40060,

    // cb48: Write to RAM 801c7740 (Scratch)
    STW, (s32)&D_801C7740_1C8340,

    // cb50: Store Value: 6b
    WTS, 0x6B,

    // cb58: Execute Code: 8003f608 (Play Sound)
    ESR, (s32)&func_8003F608_40208,

    // cb60: Print Text
    TXT, (s32)&scenario_text_1C15,

    // cb68: Print Text
    TXT, (s32)&scenario_text_0171,

    // cb70: Write to RAM 801c77d8 (Text Speed)
    STW, 0x801c77d8,

    // cb78: Store Value: 1
    WTS, 0x1,

    // cb80: Write to RAM 801c7798 (Unknown)
    STW, 0x801c7798,

    // cb88: Store Value: 1
    WTS, 0x1,

    // cb90: Print Text
    TXT, (s32)&scenario_text_1C42,

    // cb98: Print Text
    TXT, (s32)&scenario_text_1C74,

    // cba0: Print Text
    TXT, (s32)&scenario_text_1CB0,

    // cba8: Print Text
    TXT, (s32)&scenario_text_0171,

    // cbb0: Print Text
    TXT, (s32)&scenario_text_1D1A,

    // cbb8: Print Text
    TXT, (s32)&scenario_text_1D4C,

    // cbc0: Print Text
    TXT, (s32)&scenario_text_1D8E,

    // DISABLED ITEM
    // // cbc8: Write to RAM 8015c6f0 (Obtained Mini-Ebisu Magic)
    // STW, 0x8015c6f0,

    // // cbd0: Store Value: 1
    // WTS, 0x1,

    // cbd8: Set Flag 031 (Obtained Mini-Ebisu Magic)
    SFG, 0x31,

    // cbe0: Print Text
    TXT, (s32)&scenario_text_009F,

    // cbe8: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_160_cbec[] = {

    // Address: @cbec

    // cbec: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // cbf4: Store Value: 1
    WTS, 0x1,

    // cbfc: Print Text
    TXT, (s32)&scenario_text_0171,

    // cc04: Print Text
    TXT, (s32)&scenario_text_1DFF,

    // cc0c: Print Text
    TXT, (s32)&scenario_text_1E34,

    // cc14: Begin Option Selection
    BOS,

    // cc18: Print Text
    TXT, (s32)&scenario_text_1E65,

    // cc20: Jump To @cc48
    JMP, (s32)&scenario_code_message_160_cc48,

    // cc28: Print Text
    TXT, (s32)&scenario_text_1E93,

    // cc30: Jump To @cc84
    JMP, (s32)&scenario_code_message_160_cc84,

    // cc38: End Option Selection
    EOS,

    // cc3c: Print Text
    TXT, (s32)&scenario_text_015F,

    // cc44: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_160_cc48[] = {

    // Address: @cc48

    // cc48: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // cc50: Store Value: 1
    WTS, 0x1,

    // cc58: Print Text
    TXT, (s32)&scenario_text_0171,

    // cc60: Print Text
    TXT, (s32)&scenario_text_1EF8,

    // cc68: Print Text
    TXT, (s32)&scenario_text_1F2C,

    // cc70: Print Text
    TXT, (s32)&scenario_text_009F,

    // cc78: Set Flag 07d (Started Mini-Ebisu Minigame)
    SFG, 0x7D,

    // cc80: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_160_cc84[] = {

    // Address: @cc84

    // cc84: Print Text
    TXT, (s32)&scenario_text_0171,

    // cc8c: Print Text
    TXT, (s32)&scenario_text_09CD,

    // cc94: Print Text
    TXT, (s32)&scenario_text_1FA7,

    // cc9c: Print Text
    TXT, (s32)&scenario_text_1FCA,

    // cca4: Set Flag 030 (Rejected Mini-Ebisu Training Offer)
    SFG, 0x30,

    // ccac: Set Flag 081 (Rejected Mini-Ebisu Training Offer (Unused?))
    SFG, 0x81,

    // ccb4: Print Text
    TXT, (s32)&scenario_text_009F,

    // ccbc: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_160_ccc0[] = {

    // Address: @ccc0

    // ccc0: Print Text
    TXT, (s32)&scenario_text_2010,

    // ccc8: Print Text
    TXT, (s32)&scenario_text_2041,

    // ccd0: Begin Option Selection
    BOS,

    // ccd4: Print Text
    TXT, (s32)&scenario_text_2073,

    // ccdc: Jump To @cc48
    JMP, (s32)&scenario_code_message_160_cc48,

    // cce4: Print Text
    TXT, (s32)&scenario_text_209E,

    // ccec: Jump To @cc84
    JMP, (s32)&scenario_code_message_160_cc84,

    // ccf4: End Option Selection
    EOS,

    // ccf8: Print Text
    TXT, (s32)&scenario_text_015F,

    // cd00: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_160_cd04[] = {

    // Address: @cd04

    // cd04: Print Text
    TXT, (s32)&scenario_text_0171,

    // cd0c: Print Text
    TXT, (s32)&scenario_text_20FD,

    // cd14: Print Text
    TXT, (s32)&scenario_text_2130,

    // cd1c: Print Text
    TXT, (s32)&scenario_text_215E,

    // cd24: Print Text
    TXT, (s32)&scenario_text_0171,

    // cd2c: Print Text
    TXT, (s32)&scenario_text_219E,

    // cd34: Print Text
    TXT, (s32)&scenario_text_21D1,

    // cd3c: Print Text
    TXT, (s32)&scenario_text_2204,

    // cd44: Print Text
    TXT, (s32)&scenario_text_009F,

    // cd4c: End Event
    END,

    // End scenario script
    END,
};

