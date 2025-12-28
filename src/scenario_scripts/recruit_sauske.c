#include "scenario.h"

#include "common.h"

// Address: @797c

// {begin}{endline}
static s16 scenario_text_0000[] = {
    CTR_BEGIN, CTR_ENDLINE
};

// Sasuke:What the...?!{newline}{endline}
static s16 scenario_text_0014[] = {
    CHR_S, CHR_a, CHR_s, CHR_u, CHR_k, CHR_e, PCT_COLON, CHR_W, CHR_h, CHR_a,
    CHR_t, PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_PERIOD, PCT_PERIOD, PCT_PERIOD, PCT_QUESTION, PCT_EXCLAMATION,
    CTR_NEWLINE, CTR_ENDLINE
};

//       Isn't that {em-yellow}Goemon{/em}?!{button}{endline}
static s16 scenario_text_003E[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_I, CHR_s, CHR_n, PCT_APOSTROPHE,
    CHR_t, PCT_SPACE, CHR_t, CHR_h, CHR_a, CHR_t, PCT_SPACE, CTR_EM_YELLOW, CHR_G, CHR_o,
    CHR_e, CHR_m, CHR_o, CHR_n, CTR_CLOSE_EM, PCT_QUESTION, PCT_EXCLAMATION, CTR_BUTTON, CTR_ENDLINE
};

// Address: @7a18

// Sasuke:What the...?!{newline}{endline}
static s16 scenario_text_007C[] = {
    CHR_S, CHR_a, CHR_s, CHR_u, CHR_k, CHR_e, PCT_COLON, CHR_W, CHR_h, CHR_a,
    CHR_t, PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_PERIOD, PCT_PERIOD, PCT_PERIOD, PCT_QUESTION, PCT_EXCLAMATION,
    CTR_NEWLINE, CTR_ENDLINE
};

//       Isn't that {em-yellow}Ebisumaru{/em}?!{button}{endline}
static s16 scenario_text_00A6[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_I, CHR_s, CHR_n, PCT_APOSTROPHE,
    CHR_t, PCT_SPACE, CHR_t, CHR_h, CHR_a, CHR_t, PCT_SPACE, CTR_EM_YELLOW, CHR_E, CHR_b,
    CHR_i, CHR_s, CHR_u, CHR_m, CHR_a, CHR_r, CHR_u, CTR_CLOSE_EM, PCT_QUESTION, PCT_EXCLAMATION,
    CTR_BUTTON, CTR_ENDLINE
};

// Address: @7a44

// Sasuke:What the...?!{newline}{endline}
static s16 scenario_text_00E7[] = {
    CHR_S, CHR_a, CHR_s, CHR_u, CHR_k, CHR_e, PCT_COLON, CHR_W, CHR_h, CHR_a,
    CHR_t, PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_PERIOD, PCT_PERIOD, PCT_PERIOD, PCT_QUESTION, PCT_EXCLAMATION,
    CTR_NEWLINE, CTR_ENDLINE
};

//       Isn't that {em-yellow}Yae{/em}?!{button}{endline}
static s16 scenario_text_0111[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_I, CHR_s, CHR_n, PCT_APOSTROPHE,
    CHR_t, PCT_SPACE, CHR_t, CHR_h, CHR_a, CHR_t, PCT_SPACE, CTR_EM_YELLOW, CHR_Y, CHR_a,
    CHR_e, CTR_CLOSE_EM, PCT_QUESTION, PCT_EXCLAMATION, CTR_BUTTON, CTR_ENDLINE
};

// Address: @7a70

// {newwindow}{endline}
static s16 scenario_text_014C[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Sasuke:What in the world{newline}{endline}
static s16 scenario_text_0164[] = {
    CHR_S, CHR_a, CHR_s, CHR_u, CHR_k, CHR_e, PCT_COLON, CHR_W, CHR_h, CHR_a,
    CHR_t, PCT_SPACE, CHR_i, CHR_n, PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE, CHR_w,
    CHR_o, CHR_r, CHR_l, CHR_d, CTR_NEWLINE, CTR_ENDLINE
};

//       am I doing here?{button}{endline}
static s16 scenario_text_0192[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_a, CHR_m, PCT_SPACE, CHR_I,
    PCT_SPACE, CHR_d, CHR_o, CHR_i, CHR_n, CHR_g, PCT_SPACE, CHR_h, CHR_e, CHR_r,
    CHR_e, PCT_QUESTION, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_01BD[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Goemon:Hey, that's {newline}{endline}
static s16 scenario_text_01D5[] = {
    CHR_G, CHR_o, CHR_e, CHR_m, CHR_o, CHR_n, PCT_COLON, CHR_H, CHR_e, CHR_y,
    PCT_COMMA, PCT_SPACE, CHR_t, CHR_h, CHR_a, CHR_t, PCT_APOSTROPHE, CHR_s, PCT_SPACE, CTR_NEWLINE,
    CTR_ENDLINE
};

//       what I want to know...{button}{endline}
static s16 scenario_text_01FE[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_w, CHR_h, CHR_a, CHR_t,
    PCT_SPACE, CHR_I, PCT_SPACE, CHR_w, CHR_a, CHR_n, CHR_t, PCT_SPACE, CHR_t, CHR_o,
    PCT_SPACE, CHR_k, CHR_n, CHR_o, CHR_w, PCT_PERIOD, PCT_PERIOD, PCT_PERIOD, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_022F[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Goemon:Your {em-yellow}batteries{/em} were{newline}{endline}
static s16 scenario_text_0247[] = {
    CHR_G, CHR_o, CHR_e, CHR_m, CHR_o, CHR_n, PCT_COLON, CHR_Y, CHR_o, CHR_u,
    CHR_r, PCT_SPACE, CTR_EM_YELLOW, CHR_b, CHR_a, CHR_t, CHR_t, CHR_e, CHR_r, CHR_i,
    CHR_e, CHR_s, CTR_CLOSE_EM, PCT_SPACE, CHR_w, CHR_e, CHR_r, CHR_e, CTR_NEWLINE, CTR_ENDLINE
};

//       knocked out of place,{newline}{endline}
static s16 scenario_text_0287[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_k, CHR_n, CHR_o, CHR_c,
    CHR_k, CHR_e, CHR_d, PCT_SPACE, CHR_o, CHR_u, CHR_t, PCT_SPACE, CHR_o, CHR_f,
    PCT_SPACE, CHR_p, CHR_l, CHR_a, CHR_c, CHR_e, PCT_COMMA, CTR_NEWLINE, CTR_ENDLINE
};

//       and you just froze!{button}{endline}
static s16 scenario_text_02B8[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_a, CHR_n, CHR_d, PCT_SPACE,
    CHR_y, CHR_o, CHR_u, PCT_SPACE, CHR_j, CHR_u, CHR_s, CHR_t, PCT_SPACE, CHR_f,
    CHR_r, CHR_o, CHR_z, CHR_e, PCT_EXCLAMATION, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_02E6[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Sasuke:That happened to me?!{button}{endline}
static s16 scenario_text_02FE[] = {
    CHR_S, CHR_a, CHR_s, CHR_u, CHR_k, CHR_e, PCT_COLON, CHR_T, CHR_h, CHR_a,
    CHR_t, PCT_SPACE, CHR_h, CHR_a, CHR_p, CHR_p, CHR_e, CHR_n, CHR_e, CHR_d,
    PCT_SPACE, CHR_t, CHR_o, PCT_SPACE, CHR_m, CHR_e, PCT_QUESTION, PCT_EXCLAMATION, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_032F[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Yae:Well, what happened?{button}{endline}
static s16 scenario_text_0347[] = {
    CHR_Y, CHR_a, CHR_e, PCT_COLON, CHR_W, CHR_e, CHR_l, CHR_l, PCT_COMMA, PCT_SPACE,
    CHR_w, CHR_h, CHR_a, CHR_t, PCT_SPACE, CHR_h, CHR_a, CHR_p, CHR_p, CHR_e,
    CHR_n, CHR_e, CHR_d, PCT_QUESTION, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_0374[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Sasuke:Hmmmmmm...{newline}{endline}
static s16 scenario_text_038C[] = {
    CHR_S, CHR_a, CHR_s, CHR_u, CHR_k, CHR_e, PCT_COLON, CHR_H, CHR_m, CHR_m,
    CHR_m, CHR_m, CHR_m, CHR_m, PCT_PERIOD, PCT_PERIOD, PCT_PERIOD, CTR_NEWLINE, CTR_ENDLINE
};

//       there seems to be a glitch{newline}{endline}
static s16 scenario_text_03B3[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_t, CHR_h, CHR_e, CHR_r,
    CHR_e, PCT_SPACE, CHR_s, CHR_e, CHR_e, CHR_m, CHR_s, PCT_SPACE, CHR_t, CHR_o,
    PCT_SPACE, CHR_b, CHR_e, PCT_SPACE, CHR_a, PCT_SPACE, CHR_g, CHR_l, CHR_i, CHR_t,
    CHR_c, CHR_h, CTR_NEWLINE, CTR_ENDLINE
};

//       in my {em-yellow}memory circuit{/em}...{button}{endline}
static s16 scenario_text_03E9[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_i, CHR_n, PCT_SPACE, CHR_m,
    CHR_y, PCT_SPACE, CTR_EM_YELLOW, CHR_m, CHR_e, CHR_m, CHR_o, CHR_r, CHR_y, PCT_SPACE,
    CHR_c, CHR_i, CHR_r, CHR_c, CHR_u, CHR_i, CHR_t, CTR_CLOSE_EM, PCT_PERIOD, PCT_PERIOD,
    PCT_PERIOD, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_042B[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Sasuke:I'm having trouble{newline}{endline}
static s16 scenario_text_0443[] = {
    CHR_S, CHR_a, CHR_s, CHR_u, CHR_k, CHR_e, PCT_COLON, CHR_I, PCT_APOSTROPHE, CHR_m,
    PCT_SPACE, CHR_h, CHR_a, CHR_v, CHR_i, CHR_n, CHR_g, PCT_SPACE, CHR_t, CHR_r,
    CHR_o, CHR_u, CHR_b, CHR_l, CHR_e, CTR_NEWLINE, CTR_ENDLINE
};

//       remembering.{button}{endline}
static s16 scenario_text_0472[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_r, CHR_e, CHR_m, CHR_e,
    CHR_m, CHR_b, CHR_e, CHR_r, CHR_i, CHR_n, CHR_g, PCT_PERIOD, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_0499[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Sasuke:I must hurry and{newline}{endline}
static s16 scenario_text_04B1[] = {
    CHR_S, CHR_a, CHR_s, CHR_u, CHR_k, CHR_e, PCT_COLON, CHR_I, PCT_SPACE, CHR_m,
    CHR_u, CHR_s, CHR_t, PCT_SPACE, CHR_h, CHR_u, CHR_r, CHR_r, CHR_y, PCT_SPACE,
    CHR_a, CHR_n, CHR_d, CTR_NEWLINE, CTR_ENDLINE
};

//       have my {em-yellow}wise ol' man{/em}{newline}{endline}
static s16 scenario_text_04DE[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_h, CHR_a, CHR_v, CHR_e,
    PCT_SPACE, CHR_m, CHR_y, PCT_SPACE, CTR_EM_YELLOW, CHR_w, CHR_i, CHR_s, CHR_e, PCT_SPACE,
    CHR_o, CHR_l, PCT_APOSTROPHE, PCT_SPACE, CHR_m, CHR_a, CHR_n, CTR_CLOSE_EM, CTR_NEWLINE, CTR_ENDLINE
};

//       repair it...{button}{endline}
static s16 scenario_text_051E[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_r, CHR_e, CHR_p, CHR_a,
    CHR_i, CHR_r, PCT_SPACE, CHR_i, CHR_t, PCT_PERIOD, PCT_PERIOD, PCT_PERIOD, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_0545[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Goemon:Sasuke...{newline}{endline}
static s16 scenario_text_055D[] = {
    CHR_G, CHR_o, CHR_e, CHR_m, CHR_o, CHR_n, PCT_COLON, CHR_S, CHR_a, CHR_s,
    CHR_u, CHR_k, CHR_e, PCT_PERIOD, PCT_PERIOD, PCT_PERIOD, CTR_NEWLINE, CTR_ENDLINE
};

//       about your {em-yellow}wise ol' man{/em},{newline}{endline}
static s16 scenario_text_0583[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_a, CHR_b, CHR_o, CHR_u,
    CHR_t, PCT_SPACE, CHR_y, CHR_o, CHR_u, CHR_r, PCT_SPACE, CTR_EM_YELLOW, CHR_w, CHR_i,
    CHR_s, CHR_e, PCT_SPACE, CHR_o, CHR_l, PCT_APOSTROPHE, PCT_SPACE, CHR_m, CHR_a, CHR_n,
    CTR_CLOSE_EM, PCT_COMMA, CTR_NEWLINE, CTR_ENDLINE
};

//       well...{button}{endline}
static s16 scenario_text_05C7[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_w, CHR_e, CHR_l, CHR_l,
    PCT_PERIOD, PCT_PERIOD, PCT_PERIOD, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_05E9[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Ebisumaru:There was an explosion{newline}{endline}
static s16 scenario_text_0601[] = {
    CHR_E, CHR_b, CHR_i, CHR_s, CHR_u, CHR_m, CHR_a, CHR_r, CHR_u, PCT_COLON,
    CHR_T, CHR_h, CHR_e, CHR_r, CHR_e, PCT_SPACE, CHR_w, CHR_a, CHR_s, PCT_SPACE,
    CHR_a, CHR_n, PCT_SPACE, CHR_e, CHR_x, CHR_p, CHR_l, CHR_o, CHR_s, CHR_i,
    CHR_o, CHR_n, CTR_NEWLINE, CTR_ENDLINE
};

//        that demolished{newline}{endline}
static s16 scenario_text_0637[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_t, CHR_h, CHR_a,
    CHR_t, PCT_SPACE, CHR_d, CHR_e, CHR_m, CHR_o, CHR_l, CHR_i, CHR_s, CHR_h,
    CHR_e, CHR_d, CTR_NEWLINE, CTR_ENDLINE
};

//        his whole house,{button}{endline}
static s16 scenario_text_0663[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_h, CHR_i, CHR_s,
    PCT_SPACE, CHR_w, CHR_h, CHR_o, CHR_l, CHR_e, PCT_SPACE, CHR_h, CHR_o, CHR_u,
    CHR_s, CHR_e, PCT_COMMA, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_068F[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Ebisumaru:...and he's gone missing{newline}{endline}
static s16 scenario_text_06A7[] = {
    CHR_E, CHR_b, CHR_i, CHR_s, CHR_u, CHR_m, CHR_a, CHR_r, CHR_u, PCT_COLON,
    PCT_PERIOD, PCT_PERIOD, PCT_PERIOD, CHR_a, CHR_n, CHR_d, PCT_SPACE, CHR_h, CHR_e, PCT_APOSTROPHE,
    CHR_s, PCT_SPACE, CHR_g, CHR_o, CHR_n, CHR_e, PCT_SPACE, CHR_m, CHR_i, CHR_s,
    CHR_s, CHR_i, CHR_n, CHR_g, CTR_NEWLINE, CTR_ENDLINE
};

//        since... well,{newline}{endline}
static s16 scenario_text_06DF[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_s, CHR_i, CHR_n,
    CHR_c, CHR_e, PCT_PERIOD, PCT_PERIOD, PCT_PERIOD, PCT_SPACE, CHR_w, CHR_e, CHR_l, CHR_l,
    PCT_COMMA, CTR_NEWLINE, CTR_ENDLINE
};

//        with the explosion...{button}{endline}
static s16 scenario_text_070A[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_w, CHR_i, CHR_t,
    CHR_h, PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE, CHR_e, CHR_x, CHR_p, CHR_l,
    CHR_o, CHR_s, CHR_i, CHR_o, CHR_n, PCT_PERIOD, PCT_PERIOD, PCT_PERIOD, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_073B[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Sasuke:Wh-wh-whaaaaat?!{newline}{endline}
static s16 scenario_text_0753[] = {
    CHR_S, CHR_a, CHR_s, CHR_u, CHR_k, CHR_e, PCT_COLON, CHR_W, CHR_h, PCT_DASH,
    CHR_w, CHR_h, PCT_DASH, CHR_w, CHR_h, CHR_a, CHR_a, CHR_a, CHR_a, CHR_a,
    CHR_t, PCT_QUESTION, PCT_EXCLAMATION, CTR_NEWLINE, CTR_ENDLINE
};

//       Who would do such{newline}{endline}
static s16 scenario_text_0780[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_W, CHR_h, CHR_o, PCT_SPACE,
    CHR_w, CHR_o, CHR_u, CHR_l, CHR_d, PCT_SPACE, CHR_d, CHR_o, PCT_SPACE, CHR_s,
    CHR_u, CHR_c, CHR_h, CTR_NEWLINE, CTR_ENDLINE
};

//       a thing?!{button}{endline}
static s16 scenario_text_07AD[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_a, PCT_SPACE, CHR_t, CHR_h,
    CHR_i, CHR_n, CHR_g, PCT_QUESTION, PCT_EXCLAMATION, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_07D1[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Goemon:We believe it had to do{newline}{endline}
static s16 scenario_text_07E9[] = {
    CHR_G, CHR_o, CHR_e, CHR_m, CHR_o, CHR_n, PCT_COLON, CHR_W, CHR_e, PCT_SPACE,
    CHR_b, CHR_e, CHR_l, CHR_i, CHR_e, CHR_v, CHR_e, PCT_SPACE, CHR_i, CHR_t,
    PCT_SPACE, CHR_h, CHR_a, CHR_d, PCT_SPACE, CHR_t, CHR_o, PCT_SPACE, CHR_d, CHR_o,
    CTR_NEWLINE, CTR_ENDLINE
};

//       with the {em-yellow}Peach Mountain{newline}{endline}
static s16 scenario_text_081D[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_w, CHR_i, CHR_t, CHR_h,
    PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE, CTR_EM_YELLOW, CHR_P, CHR_e, CHR_a, CHR_c,
    CHR_h, PCT_SPACE, CHR_M, CHR_o, CHR_u, CHR_n, CHR_t, CHR_a, CHR_i, CHR_n,
    CTR_NEWLINE, CTR_ENDLINE
};

//       guys{/em} that we're after...{button}{endline}
static s16 scenario_text_085B[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_g, CHR_u, CHR_y, CHR_s,
    CTR_CLOSE_EM, PCT_SPACE, CHR_t, CHR_h, CHR_a, CHR_t, PCT_SPACE, CHR_w, CHR_e, PCT_APOSTROPHE,
    CHR_r, CHR_e, PCT_SPACE, CHR_a, CHR_f, CHR_t, CHR_e, CHR_r, PCT_PERIOD, PCT_PERIOD,
    PCT_PERIOD, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_0893[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Sasuke:My wise ol' man?! {newline}{endline}
static s16 scenario_text_08AB[] = {
    CHR_S, CHR_a, CHR_s, CHR_u, CHR_k, CHR_e, PCT_COLON, CHR_M, CHR_y, PCT_SPACE,
    CHR_w, CHR_i, CHR_s, CHR_e, PCT_SPACE, CHR_o, CHR_l, PCT_APOSTROPHE, PCT_SPACE, CHR_m,
    CHR_a, CHR_n, PCT_QUESTION, PCT_EXCLAMATION, PCT_SPACE, CTR_NEWLINE, CTR_ENDLINE
};

//       Really?!{button}{endline}
static s16 scenario_text_08DA[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_R, CHR_e, CHR_a, CHR_l,
    CHR_l, CHR_y, PCT_QUESTION, PCT_EXCLAMATION, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_08FD[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Sasuke:By guys with {newline}{endline}
static s16 scenario_text_0915[] = {
    CHR_S, CHR_a, CHR_s, CHR_u, CHR_k, CHR_e, PCT_COLON, CHR_B, CHR_y, PCT_SPACE,
    CHR_g, CHR_u, CHR_y, CHR_s, PCT_SPACE, CHR_w, CHR_i, CHR_t, CHR_h, PCT_SPACE,
    CTR_NEWLINE, CTR_ENDLINE
};

//       a {em-yellow}crazy name{/em} like{newline}{endline}
static s16 scenario_text_093F[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_a, PCT_SPACE, CTR_EM_YELLOW, CHR_c,
    CHR_r, CHR_a, CHR_z, CHR_y, PCT_SPACE, CHR_n, CHR_a, CHR_m, CHR_e, CTR_CLOSE_EM,
    PCT_SPACE, CHR_l, CHR_i, CHR_k, CHR_e, CTR_NEWLINE, CTR_ENDLINE
};

//       {em-yellow}Peach Mountain{/em}?!{button}{endline}
static s16 scenario_text_097C[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CTR_EM_YELLOW, CHR_P, CHR_e, CHR_a,
    CHR_c, CHR_h, PCT_SPACE, CHR_M, CHR_o, CHR_u, CHR_n, CHR_t, CHR_a, CHR_i,
    CHR_n, CTR_CLOSE_EM, PCT_QUESTION, PCT_EXCLAMATION, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_09B7[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Sasuke:Grrr...{newline}{endline}
static s16 scenario_text_09CF[] = {
    CHR_S, CHR_a, CHR_s, CHR_u, CHR_k, CHR_e, PCT_COLON, CHR_G, CHR_r, CHR_r,
    CHR_r, PCT_PERIOD, PCT_PERIOD, PCT_PERIOD, CTR_NEWLINE, CTR_ENDLINE
};

//       I'm going to crush{newline}{endline}
static s16 scenario_text_09F3[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_I, PCT_APOSTROPHE, CHR_m, PCT_SPACE,
    CHR_g, CHR_o, CHR_i, CHR_n, CHR_g, PCT_SPACE, CHR_t, CHR_o, PCT_SPACE, CHR_c,
    CHR_r, CHR_u, CHR_s, CHR_h, CTR_NEWLINE, CTR_ENDLINE
};

//       those {em-yellow}Peach Mountain guys{/em}!{button}{endline}
static s16 scenario_text_0A21[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_t, CHR_h, CHR_o, CHR_s,
    CHR_e, PCT_SPACE, CTR_EM_YELLOW, CHR_P, CHR_e, CHR_a, CHR_c, CHR_h, PCT_SPACE, CHR_M,
    CHR_o, CHR_u, CHR_n, CHR_t, CHR_a, CHR_i, CHR_n, PCT_SPACE, CHR_g, CHR_u,
    CHR_y, CHR_s, CTR_CLOSE_EM, PCT_EXCLAMATION, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_0A66[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Sasuke:Let me go with you!{endline}
static s16 scenario_text_0A7E[] = {
    CHR_S, CHR_a, CHR_s, CHR_u, CHR_k, CHR_e, PCT_COLON, CHR_L, CHR_e, CHR_t,
    PCT_SPACE, CHR_m, CHR_e, PCT_SPACE, CHR_g, CHR_o, PCT_SPACE, CHR_w, CHR_i, CHR_t,
    CHR_h, PCT_SPACE, CHR_y, CHR_o, CHR_u, PCT_EXCLAMATION, CTR_ENDLINE
};

// {end}{endline}
static s16 scenario_text_0AA5[] = {
    CTR_END, CTR_ENDLINE
};

// {begin}{endline}
static s16 scenario_text_0AB7[] = {
    CTR_BEGIN, CTR_ENDLINE
};

// ...and as a result, {newline}{endline}
static s16 scenario_text_0ACB[] = {
    PCT_PERIOD, PCT_PERIOD, PCT_PERIOD, CHR_a, CHR_n, CHR_d, PCT_SPACE, CHR_a, CHR_s, PCT_SPACE,
    CHR_a, PCT_SPACE, CHR_r, CHR_e, CHR_s, CHR_u, CHR_l, CHR_t, PCT_COMMA, PCT_SPACE,
    CTR_NEWLINE, CTR_ENDLINE
};

//   the Mechanical Ninja [{em-yellow}Sasuke{/em}]{newline}{endline}
static s16 scenario_text_0AF5[] = {
    PCT_SPACE, PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE, CHR_M, CHR_e, CHR_c, CHR_h,
    CHR_a, CHR_n, CHR_i, CHR_c, CHR_a, CHR_l, PCT_SPACE, CHR_N, CHR_i, CHR_n,
    CHR_j, CHR_a, PCT_SPACE, PCT_LBRACKET, CTR_EM_YELLOW, CHR_S, CHR_a, CHR_s, CHR_u, CHR_k,
    CHR_e, CTR_CLOSE_EM, PCT_RBRACKET, CTR_NEWLINE, CTR_ENDLINE
};

//      joins forces with Goemon!{newline}{endline}
static s16 scenario_text_0B3A[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_j, CHR_o, CHR_i, CHR_n, CHR_s,
    PCT_SPACE, CHR_f, CHR_o, CHR_r, CHR_c, CHR_e, CHR_s, PCT_SPACE, CHR_w, CHR_i,
    CHR_t, CHR_h, PCT_SPACE, CHR_G, CHR_o, CHR_e, CHR_m, CHR_o, CHR_n, PCT_EXCLAMATION,
    CTR_NEWLINE, CTR_ENDLINE
};

// {button}{endline}
static s16 scenario_text_0B6E[] = {
    CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_0B83[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Now, with the addition of{newline}{endline}
static s16 scenario_text_0B9B[] = {
    CHR_N, CHR_o, CHR_w, PCT_COMMA, PCT_SPACE, CHR_w, CHR_i, CHR_t, CHR_h, PCT_SPACE,
    CHR_t, CHR_h, CHR_e, PCT_SPACE, CHR_a, CHR_d, CHR_d, CHR_i, CHR_t, CHR_i,
    CHR_o, CHR_n, PCT_SPACE, CHR_o, CHR_f, CTR_NEWLINE, CTR_ENDLINE
};

// Sasuke, {em-yellow}doors with cracks{/em} in{newline}{endline}
static s16 scenario_text_0BCA[] = {
    CHR_S, CHR_a, CHR_s, CHR_u, CHR_k, CHR_e, PCT_COMMA, PCT_SPACE, CTR_EM_YELLOW, CHR_d,
    CHR_o, CHR_o, CHR_r, CHR_s, PCT_SPACE, CHR_w, CHR_i, CHR_t, CHR_h, PCT_SPACE,
    CHR_c, CHR_r, CHR_a, CHR_c, CHR_k, CHR_s, CTR_CLOSE_EM, PCT_SPACE, CHR_i, CHR_n,
    CTR_NEWLINE, CTR_ENDLINE
};

// them can be destroyed using{newline}{endline}
static s16 scenario_text_0C0C[] = {
    CHR_t, CHR_h, CHR_e, CHR_m, PCT_SPACE, CHR_c, CHR_a, CHR_n, PCT_SPACE, CHR_b,
    CHR_e, PCT_SPACE, CHR_d, CHR_e, CHR_s, CHR_t, CHR_r, CHR_o, CHR_y, CHR_e,
    CHR_d, PCT_SPACE, CHR_u, CHR_s, CHR_i, CHR_n, CHR_g, CTR_NEWLINE, CTR_ENDLINE
};

// Sasuke's [{em-yellow}Fire Cracker Bomb{/em}]!{endline}
static s16 scenario_text_0C3D[] = {
    CHR_S, CHR_a, CHR_s, CHR_u, CHR_k, CHR_e, PCT_APOSTROPHE, CHR_s, PCT_SPACE, PCT_LBRACKET,
    CTR_EM_YELLOW, CHR_F, CHR_i, CHR_r, CHR_e, PCT_SPACE, CHR_C, CHR_r, CHR_a, CHR_c,
    CHR_k, CHR_e, CHR_r, PCT_SPACE, CHR_B, CHR_o, CHR_m, CHR_b, CTR_CLOSE_EM, PCT_RBRACKET,
    PCT_EXCLAMATION, CTR_ENDLINE
};

// {waitinput}{end}{endline}
static s16 scenario_text_0C77[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE
};

extern s32 scenario_code_message_1f1_797c[];
extern s32 scenario_code_message_1f1_7a18[];
extern s32 scenario_code_message_1f1_7a44[];
extern s32 scenario_code_message_1f1_7a70[];

s32 scenario_code_message_1f1_797c[] = {

    // Address: @797c

    // 797c: Write to RAM 801c7768 (Dialogue Window Style)
    STW, (s32)&D_801C7768_1C8368,

    // 7984: Store Value: 6
    WTS, 0x6,

    // 798c: Write to RAM 8007785c (Dialogue Portrait Character)
    STW, (s32)&D_8007785C_7845C,

    // 7994: Store Value: 4
    WTS, 0x4,

    // 799c: Print Text
    TXT, (s32)&scenario_text_0000,

    // 79a4: Write to RAM 8015c868 (Unknown)
    STW, 0x8015c868,

    // 79ac: Store Value: 0
    WTS, 0x0,

    // 79b4: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // 79bc: Store Value: 1
    WTS, 0x1,

    // 79c4: Execute Code: 8003f594 (Load Current Character)
    ESR, (s32)&func_8003F594_40194,

    // 79cc: Read from RAM 801c7750 (Scratch)
    LDW, 0x801c7750,

    // 79d4: Skip Next If Not Equal: 1
    SNE, 0x1,

    // 79dc: Jump To @7a18
    JMP, (s32)&scenario_code_message_1f1_7a18,

    // 79e4: Read from RAM 801c7750 (Scratch)
    LDW, 0x801c7750,

    // 79ec: Skip Next If Not Equal: 3
    SNE, 0x3,

    // 79f4: Jump To @7a44
    JMP, (s32)&scenario_code_message_1f1_7a44,

    // 79fc: Print Text
    TXT, (s32)&scenario_text_0014,

    // 7a04: Print Text
    TXT, (s32)&scenario_text_003E,

    // 7a0c: Jump To @7a70
    JMP, (s32)&scenario_code_message_1f1_7a70,

    // 7a14: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_1f1_7a18[] = {

    // Address: @7a18

    // 7a18: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // 7a20: Store Value: 1
    WTS, 0x1,

    // 7a28: Print Text
    TXT, (s32)&scenario_text_0014,

    // 7a30: Print Text
    TXT, (s32)&scenario_text_00A6,

    // 7a38: Jump To @7a70
    JMP, (s32)&scenario_code_message_1f1_7a70,

    // 7a40: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_1f1_7a44[] = {

    // Address: @7a44

    // 7a44: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // 7a4c: Store Value: 1
    WTS, 0x1,

    // 7a54: Print Text
    TXT, (s32)&scenario_text_0014,

    // 7a5c: Print Text
    TXT, (s32)&scenario_text_0111,

    // 7a64: Jump To @7a70
    JMP, (s32)&scenario_code_message_1f1_7a70,

    // 7a6c: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_1f1_7a70[] = {

    // Address: @7a70

    // 7a70: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // 7a78: Store Value: 1
    WTS, 0x1,

    // 7a80: Print Text
    TXT, (s32)&scenario_text_014C,

    // 7a88: Print Text
    TXT, (s32)&scenario_text_0164,

    // 7a90: Print Text
    TXT, (s32)&scenario_text_0192,

    // 7a98: Print Text
    TXT, (s32)&scenario_text_014C,

    // 7aa0: Write to RAM 8007785c (Dialogue Portrait Character)
    STW, (s32)&D_8007785C_7845C,

    // 7aa8: Store Value: 0
    WTS, 0x0,

    // 7ab0: Print Text
    TXT, (s32)&scenario_text_01D5,

    // 7ab8: Print Text
    TXT, (s32)&scenario_text_01FE,

    // 7ac0: Print Text
    TXT, (s32)&scenario_text_014C,

    // 7ac8: Print Text
    TXT, (s32)&scenario_text_0247,

    // 7ad0: Print Text
    TXT, (s32)&scenario_text_0287,

    // 7ad8: Print Text
    TXT, (s32)&scenario_text_02B8,

    // 7ae0: Print Text
    TXT, (s32)&scenario_text_014C,

    // 7ae8: Write to RAM 8007785c (Dialogue Portrait Character)
    STW, (s32)&D_8007785C_7845C,

    // 7af0: Store Value: 4
    WTS, 0x4,

    // 7af8: Print Text
    TXT, (s32)&scenario_text_02FE,

    // 7b00: Print Text
    TXT, (s32)&scenario_text_014C,

    // 7b08: Write to RAM 8007785c (Dialogue Portrait Character)
    STW, (s32)&D_8007785C_7845C,

    // 7b10: Store Value: 6
    WTS, 0x6,

    // 7b18: Print Text
    TXT, (s32)&scenario_text_0347,

    // 7b20: Print Text
    TXT, (s32)&scenario_text_014C,

    // 7b28: Write to RAM 8007785c (Dialogue Portrait Character)
    STW, (s32)&D_8007785C_7845C,

    // 7b30: Store Value: 4
    WTS, 0x4,

    // 7b38: Print Text
    TXT, (s32)&scenario_text_038C,

    // 7b40: Print Text
    TXT, (s32)&scenario_text_03B3,

    // 7b48: Print Text
    TXT, (s32)&scenario_text_03E9,

    // 7b50: Print Text
    TXT, (s32)&scenario_text_014C,

    // 7b58: Print Text
    TXT, (s32)&scenario_text_0443,

    // 7b60: Print Text
    TXT, (s32)&scenario_text_0472,

    // 7b68: Print Text
    TXT, (s32)&scenario_text_014C,

    // 7b70: Print Text
    TXT, (s32)&scenario_text_04B1,

    // 7b78: Print Text
    TXT, (s32)&scenario_text_04DE,

    // 7b80: Print Text
    TXT, (s32)&scenario_text_051E,

    // 7b88: Print Text
    TXT, (s32)&scenario_text_014C,

    // 7b90: Write to RAM 8007785c (Dialogue Portrait Character)
    STW, (s32)&D_8007785C_7845C,

    // 7b98: Store Value: 0
    WTS, 0x0,

    // 7ba0: Print Text
    TXT, (s32)&scenario_text_055D,

    // 7ba8: Print Text
    TXT, (s32)&scenario_text_0583,

    // 7bb0: Print Text
    TXT, (s32)&scenario_text_05C7,

    // 7bb8: Print Text
    TXT, (s32)&scenario_text_014C,

    // 7bc0: Write to RAM 8007785c (Dialogue Portrait Character)
    STW, (s32)&D_8007785C_7845C,

    // 7bc8: Store Value: 2
    WTS, 0x2,

    // 7bd0: Print Text
    TXT, (s32)&scenario_text_0601,

    // 7bd8: Print Text
    TXT, (s32)&scenario_text_0637,

    // 7be0: Print Text
    TXT, (s32)&scenario_text_0663,

    // 7be8: Print Text
    TXT, (s32)&scenario_text_014C,

    // 7bf0: Print Text
    TXT, (s32)&scenario_text_06A7,

    // 7bf8: Print Text
    TXT, (s32)&scenario_text_06DF,

    // 7c00: Print Text
    TXT, (s32)&scenario_text_070A,

    // 7c08: Print Text
    TXT, (s32)&scenario_text_014C,

    // 7c10: Set Flag 003 (???)
    SFG, 0x03,

    // 7c18: Write to RAM 8007785c (Dialogue Portrait Character)
    STW, (s32)&D_8007785C_7845C,

    // 7c20: Store Value: 4
    WTS, 0x4,

    // 7c28: Print Text
    TXT, (s32)&scenario_text_0753,

    // 7c30: Print Text
    TXT, (s32)&scenario_text_0780,

    // 7c38: Print Text
    TXT, (s32)&scenario_text_07AD,

    // 7c40: Print Text
    TXT, (s32)&scenario_text_014C,

    // 7c48: Write to RAM 8007785c (Dialogue Portrait Character)
    STW, (s32)&D_8007785C_7845C,

    // 7c50: Store Value: 0
    WTS, 0x0,

    // 7c58: Print Text
    TXT, (s32)&scenario_text_07E9,

    // 7c60: Print Text
    TXT, (s32)&scenario_text_081D,

    // 7c68: Print Text
    TXT, (s32)&scenario_text_085B,

    // 7c70: Print Text
    TXT, (s32)&scenario_text_014C,

    // 7c78: Set Flag 004 (???)
    SFG, 0x04,

    // 7c80: Write to RAM 8007785c (Dialogue Portrait Character)
    STW, (s32)&D_8007785C_7845C,

    // 7c88: Store Value: 4
    WTS, 0x4,

    // 7c90: Print Text
    TXT, (s32)&scenario_text_08AB,

    // 7c98: Print Text
    TXT, (s32)&scenario_text_08DA,

    // 7ca0: Print Text
    TXT, (s32)&scenario_text_014C,

    // 7ca8: Print Text
    TXT, (s32)&scenario_text_0915,

    // 7cb0: Print Text
    TXT, (s32)&scenario_text_093F,

    // 7cb8: Print Text
    TXT, (s32)&scenario_text_097C,

    // 7cc0: Print Text
    TXT, (s32)&scenario_text_014C,

    // 7cc8: Print Text
    TXT, (s32)&scenario_text_09CF,

    // 7cd0: Print Text
    TXT, (s32)&scenario_text_09F3,

    // 7cd8: Print Text
    TXT, (s32)&scenario_text_0A21,

    // 7ce0: Print Text
    TXT, (s32)&scenario_text_014C,

    // 7ce8: Print Text
    TXT, (s32)&scenario_text_0A7E,

    // 7cf0: Write to RAM 801c7740 (Scratch)
    STW, (s32)&D_801C7740_1C8340,

    // 7cf8: Store Value: 7
    WTS, 0x7,

    // 7d00: Execute Code: 8003f608 (Play Sound)
    ESR, (s32)&func_8003F608_40208,

    // 7d08: Write to RAM 801c7740 (Scratch)
    STW, (s32)&D_801C7740_1C8340,

    // 7d10: Store Value: 2d
    WTS, 0x2D,

    // 7d18: Execute Code: 8003f460 (Wait For Timer)
    ESR, (s32)&func_8003F460_40060,

    // 7d20: Print Text
    TXT, (s32)&scenario_text_0AA5,

    // 7d28: Write to RAM 801c7758 (Unknown)
    STW, (s32)&D_801C7758_1C8358,

    // 7d30: Store Value: 20
    WTS, 0x20,

    // 7d38: Write to RAM 801c775c (Dialogue Window Y Pos)
    STW, (s32)&D_801C775C_1C835C,

    // 7d40: Store Value: 48
    WTS, 0x48,

    // 7d48: Write to RAM 801c7768 (Dialogue Window Style)
    STW, (s32)&D_801C7768_1C8368,

    // 7d50: Store Value: 7
    WTS, 0x7,

    // 7d58: Write to RAM 8007785c (Dialogue Portrait Character)
    STW, (s32)&D_8007785C_7845C,

    // 7d60: Store Value: 100
    WTS, 0x100,

    // 7d68: Print Text
    TXT, (s32)&scenario_text_0000,

    // 7d70: Write to RAM 801c7740 (Scratch)
    STW, (s32)&D_801C7740_1C8340,

    // 7d78: Store Value: 14
    WTS, 0x14,

    // 7d80: Execute Code: 8003f608 (Play Sound)
    ESR, (s32)&func_8003F608_40208,

    // 7d88: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // 7d90: Store Value: 1
    WTS, 0x1,

    // 7d98: Print Text
    TXT, (s32)&scenario_text_0ACB,

    // 7da0: Print Text
    TXT, (s32)&scenario_text_0AF5,

    // 7da8: Print Text
    TXT, (s32)&scenario_text_0B3A,

    // 7db0: Write to RAM 801c7740 (Scratch)
    STW, (s32)&D_801C7740_1C8340,

    // 7db8: Store Value: 96
    WTS, 0x96,

    // 7dc0: Execute Code: 8003f460 (Wait For Timer)
    ESR, (s32)&func_8003F460_40060,

    // 7dc8: Write to RAM 801c7740 (Scratch)
    STW, (s32)&D_801C7740_1C8340,

    // 7dd0: Store Value: 2a
    WTS, 0x2A,

    // 7dd8: Execute Code: 8003f608 (Play Sound)
    ESR, (s32)&func_8003F608_40208,

    // 7de0: Print Text
    TXT, (s32)&scenario_text_0B6E,

    // 7de8: Print Text
    TXT, (s32)&scenario_text_014C,

    // 7df0: Print Text
    TXT, (s32)&scenario_text_0B9B,

    // 7df8: Print Text
    TXT, (s32)&scenario_text_0BCA,

    // 7e00: Print Text
    TXT, (s32)&scenario_text_0C0C,

    // 7e08: Print Text
    TXT, (s32)&scenario_text_0C3D,

    // DISABLED ITEM
    // // 7e10: Write to RAM 8015c6c4 (Obtained Firecracker Bomb)
    // STW, 0x8015c6c4,

    // // 7e18: Store Value: 1
    // WTS, 0x1,

    // // 7e20: Write to RAM 8015c6a4 (Recruited Sasuke)
    // STW, 0x8015c6a4,

    // // 7e28: Store Value: 1
    // WTS, 0x1,

    // 7e30: Set Flag 00e (Recruited Sasuke)
    SFG, 0x0E,

    // 7e38: Print Text
    TXT, (s32)&scenario_text_0C77,

    // 7e40: End Event
    END,

    // End scenario script
    END,
};

