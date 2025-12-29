#include "scenario.h"

#include "common.h"

// SHOP 4 - Sogen - Restaurant - Wise Old Man (Sogen Restaurant)
// Address: @31f0

// {begin}{endline}
static s16 scenario_text_0000[] = {
    CTR_BEGIN, CTR_ENDLINE
};

// Address: @3290

// Wise Man::Hey! {em-yellow}Goemon{/em}, it's you!{button}{end}{endline}
static s16 scenario_text_0014[] = {
    CHR_W, CHR_i, CHR_s, CHR_e, PCT_SPACE, CHR_M, CHR_a, CHR_n, PCT_COLON, PCT_COLON,
    CHR_H, CHR_e, CHR_y, PCT_EXCLAMATION, PCT_SPACE, CTR_EM_YELLOW, CHR_G, CHR_o, CHR_e, CHR_m,
    CHR_o, CHR_n, CTR_CLOSE_EM, PCT_COMMA, PCT_SPACE, CHR_i, CHR_t, PCT_APOSTROPHE, CHR_s, PCT_SPACE,
    CHR_y, CHR_o, CHR_u, PCT_EXCLAMATION, CTR_BUTTON, CTR_END, CTR_ENDLINE
};

// {begin}{endline}
static s16 scenario_text_005E[] = {
    CTR_BEGIN, CTR_ENDLINE
};

// Goemon:What?! {em-yellow}Wise Man{/em}!{button}{endline}
static s16 scenario_text_0072[] = {
    CHR_G, CHR_o, CHR_e, CHR_m, CHR_o, CHR_n, PCT_COLON, CHR_W, CHR_h, CHR_a,
    CHR_t, PCT_QUESTION, PCT_EXCLAMATION, PCT_SPACE, CTR_EM_YELLOW, CHR_W, CHR_i, CHR_s, CHR_e, PCT_SPACE,
    CHR_M, CHR_a, CHR_n, CTR_CLOSE_EM, PCT_EXCLAMATION, CTR_BUTTON, CTR_ENDLINE
};

// Address: @32f4

// Wise Man::Hey! {em-yellow}Ebisumaru{/em}, it's you!{button}{end}{endline}
static s16 scenario_text_00AE[] = {
    CHR_W, CHR_i, CHR_s, CHR_e, PCT_SPACE, CHR_M, CHR_a, CHR_n, PCT_COLON, PCT_COLON,
    CHR_H, CHR_e, CHR_y, PCT_EXCLAMATION, PCT_SPACE, CTR_EM_YELLOW, CHR_E, CHR_b, CHR_i, CHR_s,
    CHR_u, CHR_m, CHR_a, CHR_r, CHR_u, CTR_CLOSE_EM, PCT_COMMA, PCT_SPACE, CHR_i, CHR_t,
    PCT_APOSTROPHE, CHR_s, PCT_SPACE, CHR_y, CHR_o, CHR_u, PCT_EXCLAMATION, CTR_BUTTON, CTR_END, CTR_ENDLINE
};

// {begin}{endline}
static s16 scenario_text_00FB[] = {
    CTR_BEGIN, CTR_ENDLINE
};

// Ebisumaru:Huh?! {em-yellow}Wise Man{/em}!{button}{endline}
static s16 scenario_text_010F[] = {
    CHR_E, CHR_b, CHR_i, CHR_s, CHR_u, CHR_m, CHR_a, CHR_r, CHR_u, PCT_COLON,
    CHR_H, CHR_u, CHR_h, PCT_QUESTION, PCT_EXCLAMATION, PCT_SPACE, CTR_EM_YELLOW, CHR_W, CHR_i, CHR_s,
    CHR_e, PCT_SPACE, CHR_M, CHR_a, CHR_n, CTR_CLOSE_EM, PCT_EXCLAMATION, CTR_BUTTON, CTR_ENDLINE
};

// Address: @3358

// Wise Man::Hey! {em-yellow}Yae{/em}, it's you!{button}{end}{endline}
static s16 scenario_text_014D[] = {
    CHR_W, CHR_i, CHR_s, CHR_e, PCT_SPACE, CHR_M, CHR_a, CHR_n, PCT_COLON, PCT_COLON,
    CHR_H, CHR_e, CHR_y, PCT_EXCLAMATION, PCT_SPACE, CTR_EM_YELLOW, CHR_Y, CHR_a, CHR_e, CTR_CLOSE_EM,
    PCT_COMMA, PCT_SPACE, CHR_i, CHR_t, PCT_APOSTROPHE, CHR_s, PCT_SPACE, CHR_y, CHR_o, CHR_u,
    PCT_EXCLAMATION, CTR_BUTTON, CTR_END, CTR_ENDLINE
};

// {begin}{endline}
static s16 scenario_text_0194[] = {
    CTR_BEGIN, CTR_ENDLINE
};

// Yae:It can't be! {em-yellow}Wise Man{/em}?!{button}{endline}
static s16 scenario_text_01A8[] = {
    CHR_Y, CHR_a, CHR_e, PCT_COLON, CHR_I, CHR_t, PCT_SPACE, CHR_c, CHR_a, CHR_n,
    PCT_APOSTROPHE, CHR_t, PCT_SPACE, CHR_b, CHR_e, PCT_EXCLAMATION, PCT_SPACE, CTR_EM_YELLOW, CHR_W, CHR_i,
    CHR_s, CHR_e, PCT_SPACE, CHR_M, CHR_a, CHR_n, CTR_CLOSE_EM, PCT_QUESTION, PCT_EXCLAMATION, CTR_BUTTON,
    CTR_ENDLINE
};

// Address: @33bc

// Wise Man:Whoah! {em-yellow}Sasuke{/em}, it's you!{button}{end}{endline}
static s16 scenario_text_01E8[] = {
    CHR_W, CHR_i, CHR_s, CHR_e, PCT_SPACE, CHR_M, CHR_a, CHR_n, PCT_COLON, CHR_W,
    CHR_h, CHR_o, CHR_a, CHR_h, PCT_EXCLAMATION, PCT_SPACE, CTR_EM_YELLOW, CHR_S, CHR_a, CHR_s,
    CHR_u, CHR_k, CHR_e, CTR_CLOSE_EM, PCT_COMMA, PCT_SPACE, CHR_i, CHR_t, PCT_APOSTROPHE, CHR_s,
    PCT_SPACE, CHR_y, CHR_o, CHR_u, PCT_EXCLAMATION, CTR_BUTTON, CTR_END, CTR_ENDLINE
};

// {begin}{endline}
static s16 scenario_text_0233[] = {
    CTR_BEGIN, CTR_ENDLINE
};

// Sasuke:Hey!{newline}{endline}
static s16 scenario_text_0247[] = {
    CHR_S, CHR_a, CHR_s, CHR_u, CHR_k, CHR_e, PCT_COLON, CHR_H, CHR_e, CHR_y,
    PCT_EXCLAMATION, CTR_NEWLINE, CTR_ENDLINE
};

//       If it's not my {em-yellow}ol' man{/em}!{button}{endline}
static s16 scenario_text_0268[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_I, CHR_f, PCT_SPACE, CHR_i,
    CHR_t, PCT_APOSTROPHE, CHR_s, PCT_SPACE, CHR_n, CHR_o, CHR_t, PCT_SPACE, CHR_m, CHR_y,
    PCT_SPACE, CTR_EM_YELLOW, CHR_o, CHR_l, PCT_APOSTROPHE, PCT_SPACE, CHR_m, CHR_a, CHR_n, CTR_CLOSE_EM,
    PCT_EXCLAMATION, CTR_BUTTON, CTR_ENDLINE
};

// Address: @3428

// {newwindow}{endline}
static s16 scenario_text_02AA[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Sasuke:It is!{newline}{endline}
static s16 scenario_text_02C2[] = {
    CHR_S, CHR_a, CHR_s, CHR_u, CHR_k, CHR_e, PCT_COLON, CHR_I, CHR_t, PCT_SPACE,
    CHR_i, CHR_s, PCT_EXCLAMATION, CTR_NEWLINE, CTR_ENDLINE
};

//       It's my ol' man, {em-yellow}Wise Man{/em}!{newline}{endline}
static s16 scenario_text_02E5[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_I, CHR_t, PCT_APOSTROPHE, CHR_s,
    PCT_SPACE, CHR_m, CHR_y, PCT_SPACE, CHR_o, CHR_l, PCT_APOSTROPHE, PCT_SPACE, CHR_m, CHR_a,
    CHR_n, PCT_COMMA, PCT_SPACE, CTR_EM_YELLOW, CHR_W, CHR_i, CHR_s, CHR_e, PCT_SPACE, CHR_M,
    CHR_a, CHR_n, CTR_CLOSE_EM, PCT_EXCLAMATION, CTR_NEWLINE, CTR_ENDLINE
};

//       I am just overjoyed to{newline}{endline}
static s16 scenario_text_032B[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_I, PCT_SPACE, CHR_a, CHR_m,
    PCT_SPACE, CHR_j, CHR_u, CHR_s, CHR_t, PCT_SPACE, CHR_o, CHR_v, CHR_e, CHR_r,
    CHR_j, CHR_o, CHR_y, CHR_e, CHR_d, PCT_SPACE, CHR_t, CHR_o, CTR_NEWLINE, CTR_ENDLINE
};

//       see you!{button}{endline}
static s16 scenario_text_035D[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_s, CHR_e, CHR_e, PCT_SPACE,
    CHR_y, CHR_o, CHR_u, PCT_EXCLAMATION, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_0380[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Goemon:But I thought{newline}{endline}
static s16 scenario_text_0398[] = {
    CHR_G, CHR_o, CHR_e, CHR_m, CHR_o, CHR_n, PCT_COLON, CHR_B, CHR_u, CHR_t,
    PCT_SPACE, CHR_I, PCT_SPACE, CHR_t, CHR_h, CHR_o, CHR_u, CHR_g, CHR_h, CHR_t,
    CTR_NEWLINE, CTR_ENDLINE
};

//       Wise Man died.{button}{end}{endline}
static s16 scenario_text_03C2[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_W, CHR_i, CHR_s, CHR_e,
    PCT_SPACE, CHR_M, CHR_a, CHR_n, PCT_SPACE, CHR_d, CHR_i, CHR_e, CHR_d, PCT_PERIOD,
    CTR_BUTTON, CTR_END, CTR_ENDLINE
};

// {begin}{endline}
static s16 scenario_text_03F0[] = {
    CTR_BEGIN, CTR_ENDLINE
};

// Wise Man:You couldn't be further{newline}{endline}
static s16 scenario_text_0404[] = {
    CHR_W, CHR_i, CHR_s, CHR_e, PCT_SPACE, CHR_M, CHR_a, CHR_n, PCT_COLON, CHR_Y,
    CHR_o, CHR_u, PCT_SPACE, CHR_c, CHR_o, CHR_u, CHR_l, CHR_d, CHR_n, PCT_APOSTROPHE,
    CHR_t, PCT_SPACE, CHR_b, CHR_e, PCT_SPACE, CHR_f, CHR_u, CHR_r, CHR_t, CHR_h,
    CHR_e, CHR_r, CTR_NEWLINE, CTR_ENDLINE
};

//       from the truth!{newline}{endline}
static s16 scenario_text_043A[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_f, CHR_r, CHR_o, CHR_m,
    PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE, CHR_t, CHR_r, CHR_u, CHR_t, CHR_h,
    PCT_EXCLAMATION, CTR_NEWLINE, CTR_ENDLINE
};

//       Just look at me,{newline}{endline}
static s16 scenario_text_0465[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_J, CHR_u, CHR_s, CHR_t,
    PCT_SPACE, CHR_l, CHR_o, CHR_o, CHR_k, PCT_SPACE, CHR_a, CHR_t, PCT_SPACE, CHR_m,
    CHR_e, PCT_COMMA, CTR_NEWLINE, CTR_ENDLINE
};

//       I'm as {em-yellow}healthy{/em} as ever!{button}{end}{endline}
static s16 scenario_text_0491[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_I, PCT_APOSTROPHE, CHR_m, PCT_SPACE,
    CHR_a, CHR_s, PCT_SPACE, CTR_EM_YELLOW, CHR_h, CHR_e, CHR_a, CHR_l, CHR_t, CHR_h,
    CHR_y, CTR_CLOSE_EM, PCT_SPACE, CHR_a, CHR_s, PCT_SPACE, CHR_e, CHR_v, CHR_e, CHR_r,
    PCT_EXCLAMATION, CTR_BUTTON, CTR_END, CTR_ENDLINE
};

// {begin}{endline}
static s16 scenario_text_04D8[] = {
    CTR_BEGIN, CTR_ENDLINE
};

// Goemon:Then {em-yellow}who{/em} was the spirit{newline}{endline}
static s16 scenario_text_04EC[] = {
    CHR_G, CHR_o, CHR_e, CHR_m, CHR_o, CHR_n, PCT_COLON, CHR_T, CHR_h, CHR_e,
    CHR_n, PCT_SPACE, CTR_EM_YELLOW, CHR_w, CHR_h, CHR_o, CTR_CLOSE_EM, PCT_SPACE, CHR_w, CHR_a,
    CHR_s, PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE, CHR_s, CHR_p, CHR_i, CHR_r,
    CHR_i, CHR_t, CTR_NEWLINE, CTR_ENDLINE
};

//       the {em-yellow}Witch{/em} called for us?{endline}
static s16 scenario_text_0530[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE,
    CTR_EM_YELLOW, CHR_W, CHR_i, CHR_t, CHR_c, CHR_h, CTR_CLOSE_EM, PCT_SPACE, CHR_c, CHR_a,
    CHR_l, CHR_l, CHR_e, CHR_d, PCT_SPACE, CHR_f, CHR_o, CHR_r, PCT_SPACE, CHR_u,
    CHR_s, PCT_QUESTION, CTR_ENDLINE
};

// {button}{endline}
static s16 scenario_text_056B[] = {
    CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_0580[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Yae:Yes, there is something{newline}{endline}
static s16 scenario_text_0598[] = {
    CHR_Y, CHR_a, CHR_e, PCT_COLON, CHR_Y, CHR_e, CHR_s, PCT_COMMA, PCT_SPACE, CHR_t,
    CHR_h, CHR_e, CHR_r, CHR_e, PCT_SPACE, CHR_i, CHR_s, PCT_SPACE, CHR_s, CHR_o,
    CHR_m, CHR_e, CHR_t, CHR_h, CHR_i, CHR_n, CHR_g, CTR_NEWLINE, CTR_ENDLINE
};

//       strange about that,{newline}{endline}
static s16 scenario_text_05C9[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_s, CHR_t, CHR_r, CHR_a,
    CHR_n, CHR_g, CHR_e, PCT_SPACE, CHR_a, CHR_b, CHR_o, CHR_u, CHR_t, PCT_SPACE,
    CHR_t, CHR_h, CHR_a, CHR_t, PCT_COMMA, CTR_NEWLINE, CTR_ENDLINE
};

//       but let's not worry{newline}{endline}
static s16 scenario_text_05F8[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_b, CHR_u, CHR_t, PCT_SPACE,
    CHR_l, CHR_e, CHR_t, PCT_APOSTROPHE, CHR_s, PCT_SPACE, CHR_n, CHR_o, CHR_t, PCT_SPACE,
    CHR_w, CHR_o, CHR_r, CHR_r, CHR_y, CTR_NEWLINE, CTR_ENDLINE
};

//       about it now.{newline}{endline}
static s16 scenario_text_0627[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_a, CHR_b, CHR_o, CHR_u,
    CHR_t, PCT_SPACE, CHR_i, CHR_t, PCT_SPACE, CHR_n, CHR_o, CHR_w, PCT_PERIOD, CTR_NEWLINE,
    CTR_ENDLINE
};

// {button}{endline}
static s16 scenario_text_0650[] = {
    CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_0665[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Yae:But what are you doing here?!{button}{end}{endline}
static s16 scenario_text_067D[] = {
    CHR_Y, CHR_a, CHR_e, PCT_COLON, CHR_B, CHR_u, CHR_t, PCT_SPACE, CHR_w, CHR_h,
    CHR_a, CHR_t, PCT_SPACE, CHR_a, CHR_r, CHR_e, PCT_SPACE, CHR_y, CHR_o, CHR_u,
    PCT_SPACE, CHR_d, CHR_o, CHR_i, CHR_n, CHR_g, PCT_SPACE, CHR_h, CHR_e, CHR_r,
    CHR_e, PCT_QUESTION, PCT_EXCLAMATION, CTR_BUTTON, CTR_END, CTR_ENDLINE
};

// {begin}{endline}
static s16 scenario_text_06B8[] = {
    CTR_BEGIN, CTR_ENDLINE
};

// Wise Man:Well... I was caught by {newline}{endline}
static s16 scenario_text_06CC[] = {
    CHR_W, CHR_i, CHR_s, CHR_e, PCT_SPACE, CHR_M, CHR_a, CHR_n, PCT_COLON, CHR_W,
    CHR_e, CHR_l, CHR_l, PCT_PERIOD, PCT_PERIOD, PCT_PERIOD, PCT_SPACE, CHR_I, PCT_SPACE, CHR_w,
    CHR_a, CHR_s, PCT_SPACE, CHR_c, CHR_a, CHR_u, CHR_g, CHR_h, CHR_t, PCT_SPACE,
    CHR_b, CHR_y, PCT_SPACE, CTR_NEWLINE, CTR_ENDLINE
};

//       the {em-yellow}Peach Mountain guys{/em}.{button}{endline}
static s16 scenario_text_0703[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE,
    CTR_EM_YELLOW, CHR_P, CHR_e, CHR_a, CHR_c, CHR_h, PCT_SPACE, CHR_M, CHR_o, CHR_u,
    CHR_n, CHR_t, CHR_a, CHR_i, CHR_n, PCT_SPACE, CHR_g, CHR_u, CHR_y, CHR_s,
    CTR_CLOSE_EM, PCT_PERIOD, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_0746[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Wise Man:And... I gave them{newline}{endline}
static s16 scenario_text_075E[] = {
    CHR_W, CHR_i, CHR_s, CHR_e, PCT_SPACE, CHR_M, CHR_a, CHR_n, PCT_COLON, CHR_A,
    CHR_n, CHR_d, PCT_PERIOD, PCT_PERIOD, PCT_PERIOD, PCT_SPACE, CHR_I, PCT_SPACE, CHR_g, CHR_a,
    CHR_v, CHR_e, PCT_SPACE, CHR_t, CHR_h, CHR_e, CHR_m, CTR_NEWLINE, CTR_ENDLINE
};

//       {em-yellow}Mechanical Robots{/em} and{newline}{endline}
static s16 scenario_text_078F[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CTR_EM_YELLOW, CHR_M, CHR_e, CHR_c,
    CHR_h, CHR_a, CHR_n, CHR_i, CHR_c, CHR_a, CHR_l, PCT_SPACE, CHR_R, CHR_o,
    CHR_b, CHR_o, CHR_t, CHR_s, CTR_CLOSE_EM, PCT_SPACE, CHR_a, CHR_n, CHR_d, CTR_NEWLINE,
    CTR_ENDLINE
};

//       an {em-yellow}Instant Stage Beam{/em}...{button}{endline}
static s16 scenario_text_07D0[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_a, CHR_n, PCT_SPACE, CTR_EM_YELLOW,
    CHR_I, CHR_n, CHR_s, CHR_t, CHR_a, CHR_n, CHR_t, PCT_SPACE, CHR_S, CHR_t,
    CHR_a, CHR_g, CHR_e, PCT_SPACE, CHR_B, CHR_e, CHR_a, CHR_m, CTR_CLOSE_EM, PCT_PERIOD,
    PCT_PERIOD, PCT_PERIOD, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_0813[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Wise Man:Well... in exchange for{newline}{endline}
static s16 scenario_text_082B[] = {
    CHR_W, CHR_i, CHR_s, CHR_e, PCT_SPACE, CHR_M, CHR_a, CHR_n, PCT_COLON, CHR_W,
    CHR_e, CHR_l, CHR_l, PCT_PERIOD, PCT_PERIOD, PCT_PERIOD, PCT_SPACE, CHR_i, CHR_n, PCT_SPACE,
    CHR_e, CHR_x, CHR_c, CHR_h, CHR_a, CHR_n, CHR_g, CHR_e, PCT_SPACE, CHR_f,
    CHR_o, CHR_r, CTR_NEWLINE, CTR_ENDLINE
};

//       a {em-yellow}muscle car{/em} poster and{newline}{endline}
static s16 scenario_text_0861[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_a, PCT_SPACE, CTR_EM_YELLOW, CHR_m,
    CHR_u, CHR_s, CHR_c, CHR_l, CHR_e, PCT_SPACE, CHR_c, CHR_a, CHR_r, CTR_CLOSE_EM,
    PCT_SPACE, CHR_p, CHR_o, CHR_s, CHR_t, CHR_e, CHR_r, PCT_SPACE, CHR_a, CHR_n,
    CHR_d, CTR_NEWLINE, CTR_ENDLINE
};

//       five {em-yellow}car magazines{/em}...{newline}{endline}
static s16 scenario_text_08A4[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_f, CHR_i, CHR_v, CHR_e,
    PCT_SPACE, CTR_EM_YELLOW, CHR_c, CHR_a, CHR_r, PCT_SPACE, CHR_m, CHR_a, CHR_g, CHR_a,
    CHR_z, CHR_i, CHR_n, CHR_e, CHR_s, CTR_CLOSE_EM, PCT_PERIOD, PCT_PERIOD, PCT_PERIOD, CTR_NEWLINE,
    CTR_ENDLINE
};

// {button}{end}{endline}
static s16 scenario_text_08E5[] = {
    CTR_BUTTON, CTR_END, CTR_ENDLINE
};

// {begin}{endline}
static s16 scenario_text_08FF[] = {
    CTR_BEGIN, CTR_ENDLINE
};

// Goemon:...{newline}{endline}
static s16 scenario_text_0913[] = {
    CHR_G, CHR_o, CHR_e, CHR_m, CHR_o, CHR_n, PCT_COLON, PCT_PERIOD, PCT_PERIOD, PCT_PERIOD,
    CTR_NEWLINE, CTR_ENDLINE
};

//        {big}{em-yellow}W h a t ? ! {/em}{/big}{newline}{endline}
static s16 scenario_text_0933[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CTR_BIG, CTR_EM_YELLOW, CHR_W,
    PCT_SPACE, CHR_h, PCT_SPACE, CHR_a, PCT_SPACE, CHR_t, PCT_SPACE, PCT_QUESTION, PCT_SPACE, PCT_EXCLAMATION,
    PCT_SPACE, CTR_CLOSE_EM, CTR_CLOSE_BIG, CTR_NEWLINE, CTR_ENDLINE
};

// {button}{end}{endline}
static s16 scenario_text_0977[] = {
    CTR_BUTTON, CTR_END, CTR_ENDLINE
};

// {begin}{endline}
static s16 scenario_text_0991[] = {
    CTR_BEGIN, CTR_ENDLINE
};

// Wise Man:Oh, ah, I mean{newline}{endline}
static s16 scenario_text_09A5[] = {
    CHR_W, CHR_i, CHR_s, CHR_e, PCT_SPACE, CHR_M, CHR_a, CHR_n, PCT_COLON, CHR_O,
    CHR_h, PCT_COMMA, PCT_SPACE, CHR_a, CHR_h, PCT_COMMA, PCT_SPACE, CHR_I, PCT_SPACE, CHR_m,
    CHR_e, CHR_a, CHR_n, CTR_NEWLINE, CTR_ENDLINE
};

//       I strongly resisted{newline}{endline}
static s16 scenario_text_09D2[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_I, PCT_SPACE, CHR_s, CHR_t,
    CHR_r, CHR_o, CHR_n, CHR_g, CHR_l, CHR_y, PCT_SPACE, CHR_r, CHR_e, CHR_s,
    CHR_i, CHR_s, CHR_t, CHR_e, CHR_d, CTR_NEWLINE, CTR_ENDLINE
};

//       but they {em-yellow}forced{/em} me{newline}{endline}
static s16 scenario_text_0A01[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_b, CHR_u, CHR_t, PCT_SPACE,
    CHR_t, CHR_h, CHR_e, CHR_y, PCT_SPACE, CTR_EM_YELLOW, CHR_f, CHR_o, CHR_r, CHR_c,
    CHR_e, CHR_d, CTR_CLOSE_EM, PCT_SPACE, CHR_m, CHR_e, CTR_NEWLINE, CTR_ENDLINE
};

//       to make them.{newline}{endline}
static s16 scenario_text_0A3F[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_t, CHR_o, PCT_SPACE, CHR_m,
    CHR_a, CHR_k, CHR_e, PCT_SPACE, CHR_t, CHR_h, CHR_e, CHR_m, PCT_PERIOD, CTR_NEWLINE,
    CTR_ENDLINE
};

// {button}{end}{endline}
static s16 scenario_text_0A68[] = {
    CTR_BUTTON, CTR_END, CTR_ENDLINE
};

// {begin}{endline}
static s16 scenario_text_0A82[] = {
    CTR_BEGIN, CTR_ENDLINE
};

// Ebisumaru:Well it all makes sense{newline}{endline}
static s16 scenario_text_0A96[] = {
    CHR_E, CHR_b, CHR_i, CHR_s, CHR_u, CHR_m, CHR_a, CHR_r, CHR_u, PCT_COLON,
    CHR_W, CHR_e, CHR_l, CHR_l, PCT_SPACE, CHR_i, CHR_t, PCT_SPACE, CHR_a, CHR_l,
    CHR_l, PCT_SPACE, CHR_m, CHR_a, CHR_k, CHR_e, CHR_s, PCT_SPACE, CHR_s, CHR_e,
    CHR_n, CHR_s, CHR_e, CTR_NEWLINE, CTR_ENDLINE
};

//        then, the mechanics{newline}{endline}
static s16 scenario_text_0ACD[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_t, CHR_h, CHR_e,
    CHR_n, PCT_COMMA, PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE, CHR_m, CHR_e, CHR_c,
    CHR_h, CHR_a, CHR_n, CHR_i, CHR_c, CHR_s, CTR_NEWLINE, CTR_ENDLINE
};

//        seemed so familiar.{button}{end}{endline}
static s16 scenario_text_0AFD[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_s, CHR_e, CHR_e,
    CHR_m, CHR_e, CHR_d, PCT_SPACE, CHR_s, CHR_o, PCT_SPACE, CHR_f, CHR_a, CHR_m,
    CHR_i, CHR_l, CHR_i, CHR_a, CHR_r, PCT_PERIOD, CTR_BUTTON, CTR_END, CTR_ENDLINE
};

// {begin}{endline}
static s16 scenario_text_0B31[] = {
    CTR_BEGIN, CTR_ENDLINE
};

// Wise Man:I don't know{newline}{endline}
static s16 scenario_text_0B45[] = {
    CHR_W, CHR_i, CHR_s, CHR_e, PCT_SPACE, CHR_M, CHR_a, CHR_n, PCT_COLON, CHR_I,
    PCT_SPACE, CHR_d, CHR_o, CHR_n, PCT_APOSTROPHE, CHR_t, PCT_SPACE, CHR_k, CHR_n, CHR_o,
    CHR_w, CTR_NEWLINE, CTR_ENDLINE
};

//        what to say.{button}{end}{endline}
static s16 scenario_text_0B70[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_w, CHR_h, CHR_a,
    CHR_t, PCT_SPACE, CHR_t, CHR_o, PCT_SPACE, CHR_s, CHR_a, CHR_y, PCT_PERIOD, CTR_BUTTON,
    CTR_END, CTR_ENDLINE
};

// {begin}{endline}
static s16 scenario_text_0B9D[] = {
    CTR_BEGIN, CTR_ENDLINE
};

// Goemon:But that's strange.{newline}{endline}
static s16 scenario_text_0BB1[] = {
    CHR_G, CHR_o, CHR_e, CHR_m, CHR_o, CHR_n, PCT_COLON, CHR_B, CHR_u, CHR_t,
    PCT_SPACE, CHR_t, CHR_h, CHR_a, CHR_t, PCT_APOSTROPHE, CHR_s, PCT_SPACE, CHR_s, CHR_t,
    CHR_r, CHR_a, CHR_n, CHR_g, CHR_e, PCT_PERIOD, CTR_NEWLINE, CTR_ENDLINE
};

//       If they {em-yellow}kidnapped you{/em},{newline}{endline}
static s16 scenario_text_0BE1[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_I, CHR_f, PCT_SPACE, CHR_t,
    CHR_h, CHR_e, CHR_y, PCT_SPACE, CTR_EM_YELLOW, CHR_k, CHR_i, CHR_d, CHR_n, CHR_a,
    CHR_p, CHR_p, CHR_e, CHR_d, PCT_SPACE, CHR_y, CHR_o, CHR_u, CTR_CLOSE_EM, PCT_COMMA,
    CTR_NEWLINE, CTR_ENDLINE
};

//       what reason did they have{newline}{endline}
static s16 scenario_text_0C23[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_w, CHR_h, CHR_a, CHR_t,
    PCT_SPACE, CHR_r, CHR_e, CHR_a, CHR_s, CHR_o, CHR_n, PCT_SPACE, CHR_d, CHR_i,
    CHR_d, PCT_SPACE, CHR_t, CHR_h, CHR_e, CHR_y, PCT_SPACE, CHR_h, CHR_a, CHR_v,
    CHR_e, CTR_NEWLINE, CTR_ENDLINE
};

//       to {em-yellow}blow up your home{/em}?{button}{end}{endline}
static s16 scenario_text_0C58[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_t, CHR_o, PCT_SPACE, CTR_EM_YELLOW,
    CHR_b, CHR_l, CHR_o, CHR_w, PCT_SPACE, CHR_u, CHR_p, PCT_SPACE, CHR_y, CHR_o,
    CHR_u, CHR_r, PCT_SPACE, CHR_h, CHR_o, CHR_m, CHR_e, CTR_CLOSE_EM, PCT_QUESTION, CTR_BUTTON,
    CTR_END, CTR_ENDLINE
};

// {begin}{endline}
static s16 scenario_text_0C9D[] = {
    CTR_BEGIN, CTR_ENDLINE
};

// Wise Man:What did you just say?!{newline}{endline}
static s16 scenario_text_0CB1[] = {
    CHR_W, CHR_i, CHR_s, CHR_e, PCT_SPACE, CHR_M, CHR_a, CHR_n, PCT_COLON, CHR_W,
    CHR_h, CHR_a, CHR_t, PCT_SPACE, CHR_d, CHR_i, CHR_d, PCT_SPACE, CHR_y, CHR_o,
    CHR_u, PCT_SPACE, CHR_j, CHR_u, CHR_s, CHR_t, PCT_SPACE, CHR_s, CHR_a, CHR_y,
    PCT_QUESTION, PCT_EXCLAMATION, CTR_NEWLINE, CTR_ENDLINE
};

//        My house has been{newline}{endline}
static s16 scenario_text_0CE7[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_M, CHR_y, PCT_SPACE,
    CHR_h, CHR_o, CHR_u, CHR_s, CHR_e, PCT_SPACE, CHR_h, CHR_a, CHR_s, PCT_SPACE,
    CHR_b, CHR_e, CHR_e, CHR_n, CTR_NEWLINE, CTR_ENDLINE
};

//        {em-yellow}blown up{/em}?!{button}{endline}
static s16 scenario_text_0D15[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CTR_EM_YELLOW, CHR_b, CHR_l,
    CHR_o, CHR_w, CHR_n, PCT_SPACE, CHR_u, CHR_p, CTR_CLOSE_EM, PCT_QUESTION, PCT_EXCLAMATION, CTR_BUTTON,
    CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_0D4B[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Wise Man:Grrrr!{newline}{endline}
static s16 scenario_text_0D63[] = {
    CHR_W, CHR_i, CHR_s, CHR_e, PCT_SPACE, CHR_M, CHR_a, CHR_n, PCT_COLON, CHR_G,
    CHR_r, CHR_r, CHR_r, CHR_r, PCT_EXCLAMATION, CTR_NEWLINE, CTR_ENDLINE
};

//       All those {blink}{em-yellow}car magazines{/em}{/blink}{newline}{endline}
static s16 scenario_text_0D88[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_A, CHR_l, CHR_l, PCT_SPACE,
    CHR_t, CHR_h, CHR_o, CHR_s, CHR_e, PCT_SPACE, CTR_BLINK, CTR_EM_YELLOW, CHR_c, CHR_a,
    CHR_r, PCT_SPACE, CHR_m, CHR_a, CHR_g, CHR_a, CHR_z, CHR_i, CHR_n, CHR_e,
    CHR_s, CTR_CLOSE_EM, CTR_CLOSE_BLINK, CTR_NEWLINE, CTR_ENDLINE
};

//       I collected over the years!{newline}{endline}
static s16 scenario_text_0DDA[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_I, PCT_SPACE, CHR_c, CHR_o,
    CHR_l, CHR_l, CHR_e, CHR_c, CHR_t, CHR_e, CHR_d, PCT_SPACE, CHR_o, CHR_v,
    CHR_e, CHR_r, PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE, CHR_y, CHR_e, CHR_a,
    CHR_r, CHR_s, PCT_EXCLAMATION, CTR_NEWLINE, CTR_ENDLINE
};

// {button}{endline}
static s16 scenario_text_0E11[] = {
    CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_0E26[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Wise Man:Who would do such{newline}{endline}
static s16 scenario_text_0E3E[] = {
    CHR_W, CHR_i, CHR_s, CHR_e, PCT_SPACE, CHR_M, CHR_a, CHR_n, PCT_COLON, CHR_W,
    CHR_h, CHR_o, PCT_SPACE, CHR_w, CHR_o, CHR_u, CHR_l, CHR_d, PCT_SPACE, CHR_d,
    CHR_o, PCT_SPACE, CHR_s, CHR_u, CHR_c, CHR_h, CTR_NEWLINE, CTR_ENDLINE
};

//        a thing?!{button}{end}{endline}
static s16 scenario_text_0E6E[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_a, PCT_SPACE, CHR_t,
    CHR_h, CHR_i, CHR_n, CHR_g, PCT_QUESTION, PCT_EXCLAMATION, CTR_BUTTON, CTR_END, CTR_ENDLINE
};

// {begin}{endline}
static s16 scenario_text_0E98[] = {
    CTR_BEGIN, CTR_ENDLINE
};

// Ebisumaru:We believe{newline}{endline}
static s16 scenario_text_0EAC[] = {
    CHR_E, CHR_b, CHR_i, CHR_s, CHR_u, CHR_m, CHR_a, CHR_r, CHR_u, PCT_COLON,
    CHR_W, CHR_e, PCT_SPACE, CHR_b, CHR_e, CHR_l, CHR_i, CHR_e, CHR_v, CHR_e,
    CTR_NEWLINE, CTR_ENDLINE
};

//        it was probably{newline}{endline}
static s16 scenario_text_0ED6[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_i, CHR_t, PCT_SPACE,
    CHR_w, CHR_a, CHR_s, PCT_SPACE, CHR_p, CHR_r, CHR_o, CHR_b, CHR_a, CHR_b,
    CHR_l, CHR_y, CTR_NEWLINE, CTR_ENDLINE
};

//        the {em-yellow}Peach Mountain guys{/em}.{button}{endline}
static s16 scenario_text_0F02[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_t, CHR_h, CHR_e,
    PCT_SPACE, CTR_EM_YELLOW, CHR_P, CHR_e, CHR_a, CHR_c, CHR_h, PCT_SPACE, CHR_M, CHR_o,
    CHR_u, CHR_n, CHR_t, CHR_a, CHR_i, CHR_n, PCT_SPACE, CHR_g, CHR_u, CHR_y,
    CHR_s, CTR_CLOSE_EM, PCT_PERIOD, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_0F46[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Sasuke:..{button}{end}{endline}
static s16 scenario_text_0F5E[] = {
    CHR_S, CHR_a, CHR_s, CHR_u, CHR_k, CHR_e, PCT_COLON, PCT_PERIOD, PCT_PERIOD, CTR_BUTTON,
    CTR_END, CTR_ENDLINE
};

// {begin}{endline}
static s16 scenario_text_0F81[] = {
    CTR_BEGIN, CTR_ENDLINE
};

// Wise Man:{blink}{em-yellow}I will not forgive them.{/em}{/blink}{button}{endline}
static s16 scenario_text_0F95[] = {
    CHR_W, CHR_i, CHR_s, CHR_e, PCT_SPACE, CHR_M, CHR_a, CHR_n, PCT_COLON, CTR_BLINK,
    CTR_EM_YELLOW, CHR_I, PCT_SPACE, CHR_w, CHR_i, CHR_l, CHR_l, PCT_SPACE, CHR_n, CHR_o,
    CHR_t, PCT_SPACE, CHR_f, CHR_o, CHR_r, CHR_g, CHR_i, CHR_v, CHR_e, PCT_SPACE,
    CHR_t, CHR_h, CHR_e, CHR_m, PCT_PERIOD, CTR_CLOSE_EM, CTR_CLOSE_BLINK, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_0FEA[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Wise Man:Hand me your [{em-yellow}Weapons{/em}].{endline}
static s16 scenario_text_1002[] = {
    CHR_W, CHR_i, CHR_s, CHR_e, PCT_SPACE, CHR_M, CHR_a, CHR_n, PCT_COLON, CHR_H,
    CHR_a, CHR_n, CHR_d, PCT_SPACE, CHR_m, CHR_e, PCT_SPACE, CHR_y, CHR_o, CHR_u,
    CHR_r, PCT_SPACE, PCT_LBRACKET, CTR_EM_YELLOW, CHR_W, CHR_e, CHR_a, CHR_p, CHR_o, CHR_n,
    CHR_s, CTR_CLOSE_EM, PCT_RBRACKET, PCT_PERIOD, CTR_ENDLINE
};

// {waitinput}{end}{endline}
static s16 scenario_text_103F[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE
};

extern s32 scenario_code_message_226_31f0[];
extern s32 scenario_code_message_226_3290[];
extern s32 scenario_code_message_226_32f4[];
extern s32 scenario_code_message_226_3358[];
extern s32 scenario_code_message_226_33bc[];
extern s32 scenario_code_message_226_3428[];

s32 scenario_code_message_226_31f0[] = {

    // Address: @31f0
    // SHOP 4 - Sogen - Restaurant - Wise Old Man (Sogen Restaurant)

    // 31f0: Write to RAM 8007785c (Dialogue Portrait Character)
    STW, (s32)&D_8007785C_7845C,

    // 31f8: Store Value: 18
    WTS, 0x18,

    // 3200: Print Text
    TXT, (s32)&scenario_text_0000,

    // 3208: If Flag 01a (Upgraded to Gold Weapons), Jump To @3c30
    // Jump if flag 0x1A is SET to @3c30
    JFS, 0x1A, 0x3c30,
    // WARNING: Jump to @3c30 - this address may be in a different message file

    // 3214: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // 321c: Store Value: 1
    WTS, 0x1,

    // 3224: Execute Code: 8003f594 (Load Current Character)
    ESR, (s32)&func_8003F594_40194,

    // 322c: Read from RAM 801c7750 (Scratch)
    LDW, 0x801c7750,

    // 3234: Skip Next If Not Equal: 0
    SNE, 0x0,

    // 323c: Jump To @3290
    JMP, (s32)&scenario_code_message_226_3290,

    // 3244: Read from RAM 801c7750 (Scratch)
    LDW, 0x801c7750,

    // 324c: Skip Next If Not Equal: 1
    SNE, 0x1,

    // 3254: Jump To @32f4
    JMP, (s32)&scenario_code_message_226_32f4,

    // 325c: Read from RAM 801c7750 (Scratch)
    LDW, 0x801c7750,

    // 3264: Skip Next If Not Equal: 3
    SNE, 0x3,

    // 326c: Jump To @3358
    JMP, (s32)&scenario_code_message_226_3358,

    // 3274: Read from RAM 801c7750 (Scratch)
    LDW, 0x801c7750,

    // 327c: Skip Next If Not Equal: 2
    SNE, 0x2,

    // 3284: Jump To @33bc
    JMP, (s32)&scenario_code_message_226_33bc,

    // 328c: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_226_3290[] = {

    // Address: @3290

    // 3290: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // 3298: Store Value: 1
    WTS, 0x1,

    // 32a0: Print Text
    TXT, (s32)&scenario_text_0014,

    // 32a8: Write to RAM 801c7768 (Dialogue Window Style)
    STW, (s32)&D_801C7768_1C8368,

    // 32b0: Store Value: 7
    WTS, 0x7,

    // 32b8: Write to RAM 8007785c (Dialogue Portrait Character)
    STW, (s32)&D_8007785C_7845C,

    // 32c0: Store Value: 0
    WTS, 0x0,

    // 32c8: Print Text
    TXT, (s32)&scenario_text_0000,

    // 32d0: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // 32d8: Store Value: 1
    WTS, 0x1,

    // 32e0: Print Text
    TXT, (s32)&scenario_text_0072,

    // 32e8: Jump To @3428
    JMP, (s32)&scenario_code_message_226_3428,

    // 32f0: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_226_32f4[] = {

    // Address: @32f4

    // 32f4: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // 32fc: Store Value: 1
    WTS, 0x1,

    // 3304: Print Text
    TXT, (s32)&scenario_text_00AE,

    // 330c: Write to RAM 801c7768 (Dialogue Window Style)
    STW, (s32)&D_801C7768_1C8368,

    // 3314: Store Value: 7
    WTS, 0x7,

    // 331c: Write to RAM 8007785c (Dialogue Portrait Character)
    STW, (s32)&D_8007785C_7845C,

    // 3324: Store Value: 2
    WTS, 0x2,

    // 332c: Print Text
    TXT, (s32)&scenario_text_0000,

    // 3334: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // 333c: Store Value: 1
    WTS, 0x1,

    // 3344: Print Text
    TXT, (s32)&scenario_text_010F,

    // 334c: Jump To @3428
    JMP, (s32)&scenario_code_message_226_3428,

    // 3354: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_226_3358[] = {

    // Address: @3358

    // 3358: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // 3360: Store Value: 1
    WTS, 0x1,

    // 3368: Print Text
    TXT, (s32)&scenario_text_014D,

    // 3370: Write to RAM 801c7768 (Dialogue Window Style)
    STW, (s32)&D_801C7768_1C8368,

    // 3378: Store Value: 7
    WTS, 0x7,

    // 3380: Write to RAM 8007785c (Dialogue Portrait Character)
    STW, (s32)&D_8007785C_7845C,

    // 3388: Store Value: 6
    WTS, 0x6,

    // 3390: Print Text
    TXT, (s32)&scenario_text_0000,

    // 3398: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // 33a0: Store Value: 1
    WTS, 0x1,

    // 33a8: Print Text
    TXT, (s32)&scenario_text_01A8,

    // 33b0: Jump To @3428
    JMP, (s32)&scenario_code_message_226_3428,

    // 33b8: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_226_33bc[] = {

    // Address: @33bc

    // 33bc: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // 33c4: Store Value: 1
    WTS, 0x1,

    // 33cc: Print Text
    TXT, (s32)&scenario_text_01E8,

    // 33d4: Write to RAM 801c7768 (Dialogue Window Style)
    STW, (s32)&D_801C7768_1C8368,

    // 33dc: Store Value: 7
    WTS, 0x7,

    // 33e4: Write to RAM 8007785c (Dialogue Portrait Character)
    STW, (s32)&D_8007785C_7845C,

    // 33ec: Store Value: 4
    WTS, 0x4,

    // 33f4: Print Text
    TXT, (s32)&scenario_text_0000,

    // 33fc: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // 3404: Store Value: 1
    WTS, 0x1,

    // 340c: Print Text
    TXT, (s32)&scenario_text_0247,

    // 3414: Print Text
    TXT, (s32)&scenario_text_0268,

    // 341c: Jump To @3428
    JMP, (s32)&scenario_code_message_226_3428,

    // 3424: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_226_3428[] = {

    // Address: @3428

    // 3428: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // 3430: Store Value: 1
    WTS, 0x1,

    // 3438: Print Text
    TXT, (s32)&scenario_text_02AA,

    // 3440: Write to RAM 8007785c (Dialogue Portrait Character)
    STW, (s32)&D_8007785C_7845C,

    // 3448: Store Value: 4
    WTS, 0x4,

    // 3450: Print Text
    TXT, (s32)&scenario_text_02C2,

    // 3458: Print Text
    TXT, (s32)&scenario_text_02E5,

    // 3460: Print Text
    TXT, (s32)&scenario_text_032B,

    // 3468: Print Text
    TXT, (s32)&scenario_text_035D,

    // 3470: Print Text
    TXT, (s32)&scenario_text_02AA,

    // 3478: Write to RAM 8007785c (Dialogue Portrait Character)
    STW, (s32)&D_8007785C_7845C,

    // 3480: Store Value: 0
    WTS, 0x0,

    // 3488: Print Text
    TXT, (s32)&scenario_text_0398,

    // 3490: Print Text
    TXT, (s32)&scenario_text_03C2,

    // 3498: Write to RAM 801c7768 (Dialogue Window Style)
    STW, (s32)&D_801C7768_1C8368,

    // 34a0: Store Value: 1
    WTS, 0x1,

    // 34a8: Write to RAM 8007785c (Dialogue Portrait Character)
    STW, (s32)&D_8007785C_7845C,

    // 34b0: Store Value: 18
    WTS, 0x18,

    // 34b8: Print Text
    TXT, (s32)&scenario_text_0000,

    // 34c0: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // 34c8: Store Value: 1
    WTS, 0x1,

    // 34d0: Print Text
    TXT, (s32)&scenario_text_0404,

    // 34d8: Print Text
    TXT, (s32)&scenario_text_043A,

    // 34e0: Print Text
    TXT, (s32)&scenario_text_0465,

    // 34e8: Print Text
    TXT, (s32)&scenario_text_0491,

    // 34f0: Write to RAM 801c7768 (Dialogue Window Style)
    STW, (s32)&D_801C7768_1C8368,

    // 34f8: Store Value: 7
    WTS, 0x7,

    // 3500: Write to RAM 8007785c (Dialogue Portrait Character)
    STW, (s32)&D_8007785C_7845C,

    // 3508: Store Value: 0
    WTS, 0x0,

    // 3510: Print Text
    TXT, (s32)&scenario_text_0000,

    // 3518: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // 3520: Store Value: 1
    WTS, 0x1,

    // 3528: Print Text
    TXT, (s32)&scenario_text_04EC,

    // 3530: Print Text
    TXT, (s32)&scenario_text_0530,

    // 3538: Write to RAM 801c7740 (Scratch)
    STW, (s32)&D_801C7740_1C8340,

    // 3540: Store Value: 140
    WTS, 0x140,

    // 3548: Execute Code: 8003f608 (Play Sound)
    ESR, (s32)&func_8003F608_40208,

    // 3550: Print Text
    TXT, (s32)&scenario_text_056B,

    // 3558: Print Text
    TXT, (s32)&scenario_text_02AA,

    // 3560: Write to RAM 8007785c (Dialogue Portrait Character)
    STW, (s32)&D_8007785C_7845C,

    // 3568: Store Value: 6
    WTS, 0x6,

    // 3570: Print Text
    TXT, (s32)&scenario_text_0598,

    // 3578: Print Text
    TXT, (s32)&scenario_text_05C9,

    // 3580: Print Text
    TXT, (s32)&scenario_text_05F8,

    // 3588: Print Text
    TXT, (s32)&scenario_text_0627,

    // 3590: Write to RAM 801c7740 (Scratch)
    STW, (s32)&D_801C7740_1C8340,

    // 3598: Store Value: 142
    WTS, 0x142,

    // 35a0: Execute Code: 8003f608 (Play Sound)
    ESR, (s32)&func_8003F608_40208,

    // 35a8: Print Text
    TXT, (s32)&scenario_text_056B,

    // 35b0: Print Text
    TXT, (s32)&scenario_text_02AA,

    // 35b8: Print Text
    TXT, (s32)&scenario_text_067D,

    // 35c0: Write to RAM 801c7768 (Dialogue Window Style)
    STW, (s32)&D_801C7768_1C8368,

    // 35c8: Store Value: 1
    WTS, 0x1,

    // 35d0: Write to RAM 8007785c (Dialogue Portrait Character)
    STW, (s32)&D_8007785C_7845C,

    // 35d8: Store Value: 18
    WTS, 0x18,

    // 35e0: Print Text
    TXT, (s32)&scenario_text_0000,

    // 35e8: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // 35f0: Store Value: 1
    WTS, 0x1,

    // 35f8: Print Text
    TXT, (s32)&scenario_text_06CC,

    // 3600: Print Text
    TXT, (s32)&scenario_text_0703,

    // 3608: Print Text
    TXT, (s32)&scenario_text_02AA,

    // 3610: Print Text
    TXT, (s32)&scenario_text_075E,

    // 3618: Print Text
    TXT, (s32)&scenario_text_078F,

    // 3620: Print Text
    TXT, (s32)&scenario_text_07D0,

    // 3628: Print Text
    TXT, (s32)&scenario_text_02AA,

    // 3630: Print Text
    TXT, (s32)&scenario_text_082B,

    // 3638: Print Text
    TXT, (s32)&scenario_text_0861,

    // 3640: Print Text
    TXT, (s32)&scenario_text_08A4,

    // 3648: Write to RAM 801c7740 (Scratch)
    STW, (s32)&D_801C7740_1C8340,

    // 3650: Store Value: 141
    WTS, 0x141,

    // 3658: Execute Code: 8003f608 (Play Sound)
    ESR, (s32)&func_8003F608_40208,

    // 3660: Print Text
    TXT, (s32)&scenario_text_08E5,

    // 3668: Write to RAM 801c7768 (Dialogue Window Style)
    STW, (s32)&D_801C7768_1C8368,

    // 3670: Store Value: 7
    WTS, 0x7,

    // 3678: Write to RAM 8007785c (Dialogue Portrait Character)
    STW, (s32)&D_8007785C_7845C,

    // 3680: Store Value: 0
    WTS, 0x0,

    // 3688: Print Text
    TXT, (s32)&scenario_text_0000,

    // 3690: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // 3698: Store Value: 1
    WTS, 0x1,

    // 36a0: Print Text
    TXT, (s32)&scenario_text_0913,

    // 36a8: Print Text
    TXT, (s32)&scenario_text_0933,

    // 36b0: Write to RAM 801c7740 (Scratch)
    STW, (s32)&D_801C7740_1C8340,

    // 36b8: Store Value: 141
    WTS, 0x141,

    // 36c0: Execute Code: 8003f608 (Play Sound)
    ESR, (s32)&func_8003F608_40208,

    // 36c8: Print Text
    TXT, (s32)&scenario_text_08E5,

    // 36d0: Write to RAM 801c7768 (Dialogue Window Style)
    STW, (s32)&D_801C7768_1C8368,

    // 36d8: Store Value: 1
    WTS, 0x1,

    // 36e0: Write to RAM 8007785c (Dialogue Portrait Character)
    STW, (s32)&D_8007785C_7845C,

    // 36e8: Store Value: 18
    WTS, 0x18,

    // 36f0: Print Text
    TXT, (s32)&scenario_text_0000,

    // 36f8: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // 3700: Store Value: 1
    WTS, 0x1,

    // 3708: Print Text
    TXT, (s32)&scenario_text_09A5,

    // 3710: Print Text
    TXT, (s32)&scenario_text_09D2,

    // 3718: Print Text
    TXT, (s32)&scenario_text_0A01,

    // 3720: Print Text
    TXT, (s32)&scenario_text_0A3F,

    // 3728: Write to RAM 801c7740 (Scratch)
    STW, (s32)&D_801C7740_1C8340,

    // 3730: Store Value: 140
    WTS, 0x140,

    // 3738: Execute Code: 8003f608 (Play Sound)
    ESR, (s32)&func_8003F608_40208,

    // 3740: Print Text
    TXT, (s32)&scenario_text_08E5,

    // 3748: Write to RAM 801c7768 (Dialogue Window Style)
    STW, (s32)&D_801C7768_1C8368,

    // 3750: Store Value: 7
    WTS, 0x7,

    // 3758: Write to RAM 8007785c (Dialogue Portrait Character)
    STW, (s32)&D_8007785C_7845C,

    // 3760: Store Value: 2
    WTS, 0x2,

    // 3768: Print Text
    TXT, (s32)&scenario_text_0000,

    // 3770: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // 3778: Store Value: 1
    WTS, 0x1,

    // 3780: Print Text
    TXT, (s32)&scenario_text_0A96,

    // 3788: Print Text
    TXT, (s32)&scenario_text_0ACD,

    // 3790: Print Text
    TXT, (s32)&scenario_text_0AFD,

    // 3798: Write to RAM 801c7768 (Dialogue Window Style)
    STW, (s32)&D_801C7768_1C8368,

    // 37a0: Store Value: 1
    WTS, 0x1,

    // 37a8: Write to RAM 8007785c (Dialogue Portrait Character)
    STW, (s32)&D_8007785C_7845C,

    // 37b0: Store Value: 18
    WTS, 0x18,

    // 37b8: Print Text
    TXT, (s32)&scenario_text_0000,

    // 37c0: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // 37c8: Store Value: 1
    WTS, 0x1,

    // 37d0: Print Text
    TXT, (s32)&scenario_text_0B45,

    // 37d8: Print Text
    TXT, (s32)&scenario_text_0B70,

    // 37e0: Write to RAM 801c7768 (Dialogue Window Style)
    STW, (s32)&D_801C7768_1C8368,

    // 37e8: Store Value: 7
    WTS, 0x7,

    // 37f0: Write to RAM 8007785c (Dialogue Portrait Character)
    STW, (s32)&D_8007785C_7845C,

    // 37f8: Store Value: 0
    WTS, 0x0,

    // 3800: Print Text
    TXT, (s32)&scenario_text_0000,

    // 3808: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // 3810: Store Value: 1
    WTS, 0x1,

    // 3818: Print Text
    TXT, (s32)&scenario_text_0BB1,

    // 3820: Print Text
    TXT, (s32)&scenario_text_0BE1,

    // 3828: Print Text
    TXT, (s32)&scenario_text_0C23,

    // 3830: Print Text
    TXT, (s32)&scenario_text_0C58,

    // 3838: Write to RAM 801c7768 (Dialogue Window Style)
    STW, (s32)&D_801C7768_1C8368,

    // 3840: Store Value: 1
    WTS, 0x1,

    // 3848: Write to RAM 8007785c (Dialogue Portrait Character)
    STW, (s32)&D_8007785C_7845C,

    // 3850: Store Value: 18
    WTS, 0x18,

    // 3858: Print Text
    TXT, (s32)&scenario_text_0000,

    // 3860: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // 3868: Store Value: 1
    WTS, 0x1,

    // 3870: Print Text
    TXT, (s32)&scenario_text_0CB1,

    // 3878: Print Text
    TXT, (s32)&scenario_text_0CE7,

    // 3880: Print Text
    TXT, (s32)&scenario_text_0D15,

    // 3888: Print Text
    TXT, (s32)&scenario_text_02AA,

    // 3890: Print Text
    TXT, (s32)&scenario_text_0D63,

    // 3898: Print Text
    TXT, (s32)&scenario_text_0D88,

    // 38a0: Print Text
    TXT, (s32)&scenario_text_0DDA,

    // 38a8: Write to RAM 801c7740 (Scratch)
    STW, (s32)&D_801C7740_1C8340,

    // 38b0: Store Value: 141
    WTS, 0x141,

    // 38b8: Execute Code: 8003f608 (Play Sound)
    ESR, (s32)&func_8003F608_40208,

    // 38c0: Print Text
    TXT, (s32)&scenario_text_056B,

    // 38c8: Print Text
    TXT, (s32)&scenario_text_02AA,

    // 38d0: Print Text
    TXT, (s32)&scenario_text_0E3E,

    // 38d8: Print Text
    TXT, (s32)&scenario_text_0E6E,

    // 38e0: Write to RAM 801c7768 (Dialogue Window Style)
    STW, (s32)&D_801C7768_1C8368,

    // 38e8: Store Value: 7
    WTS, 0x7,

    // 38f0: Write to RAM 8007785c (Dialogue Portrait Character)
    STW, (s32)&D_8007785C_7845C,

    // 38f8: Store Value: 2
    WTS, 0x2,

    // 3900: Print Text
    TXT, (s32)&scenario_text_0000,

    // 3908: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // 3910: Store Value: 1
    WTS, 0x1,

    // 3918: Print Text
    TXT, (s32)&scenario_text_0EAC,

    // 3920: Print Text
    TXT, (s32)&scenario_text_0ED6,

    // 3928: Print Text
    TXT, (s32)&scenario_text_0F02,

    // 3930: Print Text
    TXT, (s32)&scenario_text_02AA,

    // 3938: Write to RAM 8007785c (Dialogue Portrait Character)
    STW, (s32)&D_8007785C_7845C,

    // 3940: Store Value: 4
    WTS, 0x4,

    // 3948: Print Text
    TXT, (s32)&scenario_text_0F5E,

    // 3950: Write to RAM 801c7768 (Dialogue Window Style)
    STW, (s32)&D_801C7768_1C8368,

    // 3958: Store Value: 1
    WTS, 0x1,

    // 3960: Write to RAM 8007785c (Dialogue Portrait Character)
    STW, (s32)&D_8007785C_7845C,

    // 3968: Store Value: 18
    WTS, 0x18,

    // 3970: Print Text
    TXT, (s32)&scenario_text_0000,

    // 3978: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // 3980: Store Value: 1
    WTS, 0x1,

    // 3988: Write to RAM 801c77d8 (Text Speed)
    STW, 0x801c77d8,

    // 3990: Store Value: 64
    WTS, 0x64,

    // 3998: Write to RAM 801c7798 (Unknown)
    STW, 0x801c7798,

    // 39a0: Store Value: 1
    WTS, 0x1,

    // 39a8: Print Text
    TXT, (s32)&scenario_text_0F95,

    // 39b0: Print Text
    TXT, (s32)&scenario_text_02AA,

    // 39b8: Write to RAM 801c77d8 (Text Speed)
    STW, 0x801c77d8,

    // 39c0: Store Value: 1
    WTS, 0x1,

    // 39c8: Write to RAM 801c7798 (Unknown)
    STW, 0x801c7798,

    // 39d0: Store Value: 1
    WTS, 0x1,

    // 39d8: Print Text
    TXT, (s32)&scenario_text_1002,

    // 39e0: Print Text
    TXT, (s32)&scenario_text_103F,

    // 39e8: Set Flag 01a (Upgraded to Gold Weapons)
    SFG, 0x1A,

    // 39f0: Write to RAM 801c7740 (Scratch)
    STW, (s32)&D_801C7740_1C8340,

    // 39f8: Store Value: 78
    WTS, 0x78,

    // 3a00: Execute Code: 8003f460 (Wait For Timer)
    ESR, (s32)&func_8003F460_40060,

    // 3a08: Jump To @3a14
    JMP, 0x3a14,
    // WARNING: Jump to @3a14 - this address may be in a different message file

    // 3a10: End Event
    END,

    // End scenario script
    END,
};

