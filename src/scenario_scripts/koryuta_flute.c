#include "scenario.h"

#include "common.h"

// Address: @72b4

// {begin}{endline}
static s16 scenario_text_0000[] = {
    CTR_BEGIN, CTR_ENDLINE
};

// Goemon:What is this {em-yellow}flute{/em}?{button}{end}{endline}
static s16 scenario_text_0014[] = {
    CHR_G, CHR_o, CHR_e, CHR_m, CHR_o, CHR_n, PCT_COLON, CHR_W, CHR_h, CHR_a,
    CHR_t, PCT_SPACE, CHR_i, CHR_s, PCT_SPACE, CHR_t, CHR_h, CHR_i, CHR_s, PCT_SPACE,
    CTR_EM_YELLOW, CHR_f, CHR_l, CHR_u, CHR_t, CHR_e, CTR_CLOSE_EM, PCT_QUESTION, CTR_BUTTON, CTR_END,
    CTR_ENDLINE
};

// {begin}{endline}
static s16 scenario_text_0058[] = {
    CTR_BEGIN, CTR_ENDLINE
};

// Koryuta:At any time,{newline}{endline}
static s16 scenario_text_006C[] = {
    CHR_K, CHR_o, CHR_r, CHR_y, CHR_u, CHR_t, CHR_a, PCT_COLON, CHR_A, CHR_t,
    PCT_SPACE, CHR_a, CHR_n, CHR_y, PCT_SPACE, CHR_t, CHR_i, CHR_m, CHR_e, PCT_COMMA,
    CTR_NEWLINE, CTR_ENDLINE
};

//        or any place{newline}{endline}
static s16 scenario_text_0096[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_o, CHR_r, PCT_SPACE,
    CHR_a, CHR_n, CHR_y, PCT_SPACE, CHR_p, CHR_l, CHR_a, CHR_c, CHR_e, CTR_NEWLINE,
    CTR_ENDLINE
};

//        you play that {em-yellow}flute{/em},{button}{endline}
static s16 scenario_text_00BF[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_y, CHR_o, CHR_u,
    PCT_SPACE, CHR_p, CHR_l, CHR_a, CHR_y, PCT_SPACE, CHR_t, CHR_h, CHR_a, CHR_t,
    PCT_SPACE, CTR_EM_YELLOW, CHR_f, CHR_l, CHR_u, CHR_t, CHR_e, CTR_CLOSE_EM, PCT_COMMA, CTR_BUTTON,
    CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_00FF[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Koryuta:I will arrive right{newline}{endline}
static s16 scenario_text_0117[] = {
    CHR_K, CHR_o, CHR_r, CHR_y, CHR_u, CHR_t, CHR_a, PCT_COLON, CHR_I, PCT_SPACE,
    CHR_w, CHR_i, CHR_l, CHR_l, PCT_SPACE, CHR_a, CHR_r, CHR_r, CHR_i, CHR_v,
    CHR_e, PCT_SPACE, CHR_r, CHR_i, CHR_g, CHR_h, CHR_t, CTR_NEWLINE, CTR_ENDLINE
};

//        by your side in {em-yellow}Dragon{/em}{newline}{endline}
static s16 scenario_text_0148[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_b, CHR_y, PCT_SPACE,
    CHR_y, CHR_o, CHR_u, CHR_r, PCT_SPACE, CHR_s, CHR_i, CHR_d, CHR_e, PCT_SPACE,
    CHR_i, CHR_n, PCT_SPACE, CTR_EM_YELLOW, CHR_D, CHR_r, CHR_a, CHR_g, CHR_o, CHR_n,
    CTR_CLOSE_EM, CTR_NEWLINE, CTR_ENDLINE
};

//        form!{button}{endline}
static s16 scenario_text_018B[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_f, CHR_o, CHR_r,
    CHR_m, PCT_EXCLAMATION, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_01AC[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Koryuta:I will take you to any{newline}{endline}
static s16 scenario_text_01C4[] = {
    CHR_K, CHR_o, CHR_r, CHR_y, CHR_u, CHR_t, CHR_a, PCT_COLON, CHR_I, PCT_SPACE,
    CHR_w, CHR_i, CHR_l, CHR_l, PCT_SPACE, CHR_t, CHR_a, CHR_k, CHR_e, PCT_SPACE,
    CHR_y, CHR_o, CHR_u, PCT_SPACE, CHR_t, CHR_o, PCT_SPACE, CHR_a, CHR_n, CHR_y,
    CTR_NEWLINE, CTR_ENDLINE
};

//        {em-yellow}town{/em}, {em-yellow}village{/em}, {em-yellow}coffee shop{/em} {newline}{endline}
static s16 scenario_text_01F8[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CTR_EM_YELLOW, CHR_t, CHR_o,
    CHR_w, CHR_n, CTR_CLOSE_EM, PCT_COMMA, PCT_SPACE, CTR_EM_YELLOW, CHR_v, CHR_i, CHR_l, CHR_l,
    CHR_a, CHR_g, CHR_e, CTR_CLOSE_EM, PCT_COMMA, PCT_SPACE, CTR_EM_YELLOW, CHR_c, CHR_o, CHR_f,
    CHR_f, CHR_e, CHR_e, PCT_SPACE, CHR_s, CHR_h, CHR_o, CHR_p, CTR_CLOSE_EM, PCT_SPACE,
    CTR_NEWLINE, CTR_ENDLINE
};

//        or {em-yellow}castle{/em} you've been to!{button}{end}{endline}
static s16 scenario_text_0260[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_o, CHR_r, PCT_SPACE,
    CTR_EM_YELLOW, CHR_c, CHR_a, CHR_s, CHR_t, CHR_l, CHR_e, CTR_CLOSE_EM, PCT_SPACE, CHR_y,
    CHR_o, CHR_u, PCT_APOSTROPHE, CHR_v, CHR_e, PCT_SPACE, CHR_b, CHR_e, CHR_e, CHR_n,
    PCT_SPACE, CHR_t, CHR_o, PCT_EXCLAMATION, CTR_BUTTON, CTR_END, CTR_ENDLINE
};

// {begin}{endline}
static s16 scenario_text_02AA[] = {
    CTR_BEGIN, CTR_ENDLINE
};

// Goemon:That would help{newline}{endline}
static s16 scenario_text_02BE[] = {
    CHR_G, CHR_o, CHR_e, CHR_m, CHR_o, CHR_n, PCT_COLON, CHR_T, CHR_h, CHR_a,
    CHR_t, PCT_SPACE, CHR_w, CHR_o, CHR_u, CHR_l, CHR_d, PCT_SPACE, CHR_h, CHR_e,
    CHR_l, CHR_p, CTR_NEWLINE, CTR_ENDLINE
};

//       tremendously!{newline}{endline}
static s16 scenario_text_02EA[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_t, CHR_r, CHR_e, CHR_m,
    CHR_e, CHR_n, CHR_d, CHR_o, CHR_u, CHR_s, CHR_l, CHR_y, PCT_EXCLAMATION, CTR_NEWLINE,
    CTR_ENDLINE
};

//       But, I have no idea how{newline}{endline}
static s16 scenario_text_0313[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_B, CHR_u, CHR_t, PCT_COMMA,
    PCT_SPACE, CHR_I, PCT_SPACE, CHR_h, CHR_a, CHR_v, CHR_e, PCT_SPACE, CHR_n, CHR_o,
    PCT_SPACE, CHR_i, CHR_d, CHR_e, CHR_a, PCT_SPACE, CHR_h, CHR_o, CHR_w, CTR_NEWLINE,
    CTR_ENDLINE
};

//       to play the {em-yellow}flute{/em}...{button}{endline}
static s16 scenario_text_0346[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_t, CHR_o, PCT_SPACE, CHR_p,
    CHR_l, CHR_a, CHR_y, PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE, CTR_EM_YELLOW, CHR_f,
    CHR_l, CHR_u, CHR_t, CHR_e, CTR_CLOSE_EM, PCT_PERIOD, PCT_PERIOD, PCT_PERIOD, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_0385[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Yae:I know how to play{newline}{endline}
static s16 scenario_text_039D[] = {
    CHR_Y, CHR_a, CHR_e, PCT_COLON, CHR_I, PCT_SPACE, CHR_k, CHR_n, CHR_o, CHR_w,
    PCT_SPACE, CHR_h, CHR_o, CHR_w, PCT_SPACE, CHR_t, CHR_o, PCT_SPACE, CHR_p, CHR_l,
    CHR_a, CHR_y, CTR_NEWLINE, CTR_ENDLINE
};

//       the flute.{button}{endline}
static s16 scenario_text_03C9[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE,
    CHR_f, CHR_l, CHR_u, CHR_t, CHR_e, PCT_PERIOD, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_03EE[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Ebisumaru:Me too!{button}{endline}
static s16 scenario_text_0406[] = {
    CHR_E, CHR_b, CHR_i, CHR_s, CHR_u, CHR_m, CHR_a, CHR_r, CHR_u, PCT_COLON,
    CHR_M, CHR_e, PCT_SPACE, CHR_t, CHR_o, CHR_o, PCT_EXCLAMATION, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_042C[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Goemon:Okay then, {em-yellow}Yae{/em},{newline}{endline}
static s16 scenario_text_0444[] = {
    CHR_G, CHR_o, CHR_e, CHR_m, CHR_o, CHR_n, PCT_COLON, CHR_O, CHR_k, CHR_a,
    CHR_y, PCT_SPACE, CHR_t, CHR_h, CHR_e, CHR_n, PCT_COMMA, PCT_SPACE, CTR_EM_YELLOW, CHR_Y,
    CHR_a, CHR_e, CTR_CLOSE_EM, PCT_COMMA, CTR_NEWLINE, CTR_ENDLINE
};

//       I'll hand this flute{newline}{endline}
static s16 scenario_text_0480[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_I, PCT_APOSTROPHE, CHR_l, CHR_l,
    PCT_SPACE, CHR_h, CHR_a, CHR_n, CHR_d, PCT_SPACE, CHR_t, CHR_h, CHR_i, CHR_s,
    PCT_SPACE, CHR_f, CHR_l, CHR_u, CHR_t, CHR_e, CTR_NEWLINE, CTR_ENDLINE
};

//       to {em-yellow}you{/em}!{button}{endline}
static s16 scenario_text_04B0[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_t, CHR_o, PCT_SPACE, CTR_EM_YELLOW,
    CHR_y, CHR_o, CHR_u, CTR_CLOSE_EM, PCT_EXCLAMATION, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_04E2[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Ebisumaru:Why not me?!{newline}{endline}
static s16 scenario_text_04FA[] = {
    CHR_E, CHR_b, CHR_i, CHR_s, CHR_u, CHR_m, CHR_a, CHR_r, CHR_u, PCT_COLON,
    CHR_W, CHR_h, CHR_y, PCT_SPACE, CHR_n, CHR_o, CHR_t, PCT_SPACE, CHR_m, CHR_e,
    PCT_QUESTION, PCT_EXCLAMATION, CTR_NEWLINE, CTR_ENDLINE
};

// {button}{end}{endline}
static s16 scenario_text_0526[] = {
    CTR_BUTTON, CTR_END, CTR_ENDLINE
};

// {begin}{endline}
static s16 scenario_text_0540[] = {
    CTR_BEGIN, CTR_ENDLINE
};

//   {newline}{endline}
static s16 scenario_text_0554[] = {
    PCT_SPACE, PCT_SPACE, CTR_NEWLINE, CTR_ENDLINE
};

//   Yae receives{newline}{endline}
static s16 scenario_text_056C[] = {
    PCT_SPACE, PCT_SPACE, CHR_Y, CHR_a, CHR_e, PCT_SPACE, CHR_r, CHR_e, CHR_c, CHR_e,
    CHR_i, CHR_v, CHR_e, CHR_s, CTR_NEWLINE, CTR_ENDLINE
};

//        [{em-yellow}Koryuta's flute{/em}]!{newline}{endline}
static s16 scenario_text_0590[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_LBRACKET, CTR_EM_YELLOW, CHR_K,
    CHR_o, CHR_r, CHR_y, CHR_u, CHR_t, CHR_a, PCT_APOSTROPHE, CHR_s, PCT_SPACE, CHR_f,
    CHR_l, CHR_u, CHR_t, CHR_e, CTR_CLOSE_EM, PCT_RBRACKET, PCT_EXCLAMATION, CTR_NEWLINE, CTR_ENDLINE
};

// {button}{endline}
static s16 scenario_text_05CF[] = {
    CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_05E4[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

//   {newline}{endline}
static s16 scenario_text_05FC[] = {
    PCT_SPACE, PCT_SPACE, CTR_NEWLINE, CTR_ENDLINE
};

// With this, you can fly to any{newline}{endline}
static s16 scenario_text_0614[] = {
    CHR_W, CHR_i, CHR_t, CHR_h, PCT_SPACE, CHR_t, CHR_h, CHR_i, CHR_s, PCT_COMMA,
    PCT_SPACE, CHR_y, CHR_o, CHR_u, PCT_SPACE, CHR_c, CHR_a, CHR_n, PCT_SPACE, CHR_f,
    CHR_l, CHR_y, PCT_SPACE, CHR_t, CHR_o, PCT_SPACE, CHR_a, CHR_n, CHR_y, CTR_NEWLINE,
    CTR_ENDLINE
};

// location you've been to before!{button}{endline}
static s16 scenario_text_0647[] = {
    CHR_l, CHR_o, CHR_c, CHR_a, CHR_t, CHR_i, CHR_o, CHR_n, PCT_SPACE, CHR_y,
    CHR_o, CHR_u, PCT_APOSTROPHE, CHR_v, CHR_e, PCT_SPACE, CHR_b, CHR_e, CHR_e, CHR_n,
    PCT_SPACE, CHR_t, CHR_o, PCT_SPACE, CHR_b, CHR_e, CHR_f, CHR_o, CHR_r, CHR_e,
    PCT_EXCLAMATION, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_067B[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// (This feature can be cancelled by{newline}{endline}
static s16 scenario_text_0693[] = {
    PCT_LPAREN, CHR_T, CHR_h, CHR_i, CHR_s, PCT_SPACE, CHR_f, CHR_e, CHR_a, CHR_t,
    CHR_u, CHR_r, CHR_e, PCT_SPACE, CHR_c, CHR_a, CHR_n, PCT_SPACE, CHR_b, CHR_e,
    PCT_SPACE, CHR_c, CHR_a, CHR_n, CHR_c, CHR_e, CHR_l, CHR_l, CHR_e, CHR_d,
    PCT_SPACE, CHR_b, CHR_y, CTR_NEWLINE, CTR_ENDLINE
};

//  pressing the [{em-yellow}B{/em} Button] before{newline}{endline}
static s16 scenario_text_06CA[] = {
    PCT_SPACE, CHR_p, CHR_r, CHR_e, CHR_s, CHR_s, CHR_i, CHR_n, CHR_g, PCT_SPACE,
    CHR_t, CHR_h, CHR_e, PCT_SPACE, PCT_LBRACKET, CTR_EM_YELLOW, CHR_B, CTR_CLOSE_EM, PCT_SPACE, CHR_B,
    CHR_u, CHR_t, CHR_t, CHR_o, CHR_n, PCT_RBRACKET, PCT_SPACE, CHR_b, CHR_e, CHR_f,
    CHR_o, CHR_r, CHR_e, CTR_NEWLINE, CTR_ENDLINE
};

//  the flute {em-yellow}stops playing{/em}){endline}
static s16 scenario_text_070F[] = {
    PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE, CHR_f, CHR_l, CHR_u, CHR_t, CHR_e,
    PCT_SPACE, CTR_EM_YELLOW, CHR_s, CHR_t, CHR_o, CHR_p, CHR_s, PCT_SPACE, CHR_p, CHR_l,
    CHR_a, CHR_y, CHR_i, CHR_n, CHR_g, CTR_CLOSE_EM, PCT_RPAREN, CTR_ENDLINE
};

// {waitinput}{end}{endline}
static s16 scenario_text_0745[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE
};

// {begin}{endline}
static s16 scenario_text_0762[] = {
    CTR_BEGIN, CTR_ENDLINE
};

// Koryuta:Oh! I nearly forgot!{newline}{endline}
static s16 scenario_text_0776[] = {
    CHR_K, CHR_o, CHR_r, CHR_y, CHR_u, CHR_t, CHR_a, PCT_COLON, CHR_O, CHR_h,
    PCT_EXCLAMATION, PCT_SPACE, CHR_I, PCT_SPACE, CHR_n, CHR_e, CHR_a, CHR_r, CHR_l, CHR_y,
    PCT_SPACE, CHR_f, CHR_o, CHR_r, CHR_g, CHR_o, CHR_t, PCT_EXCLAMATION, CTR_NEWLINE, CTR_ENDLINE
};

//        Inside a {em-yellow}building{/em}{newline}{endline}
static s16 scenario_text_07A8[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_I, CHR_n, CHR_s,
    CHR_i, CHR_d, CHR_e, PCT_SPACE, CHR_a, PCT_SPACE, CTR_EM_YELLOW, CHR_b, CHR_u, CHR_i,
    CHR_l, CHR_d, CHR_i, CHR_n, CHR_g, CTR_CLOSE_EM, CTR_NEWLINE, CTR_ENDLINE
};

//        such as a {em-yellow}castle{/em} or{newline}{endline}
static s16 scenario_text_07E6[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_s, CHR_u, CHR_c,
    CHR_h, PCT_SPACE, CHR_a, CHR_s, PCT_SPACE, CHR_a, PCT_SPACE, CTR_EM_YELLOW, CHR_c, CHR_a,
    CHR_s, CHR_t, CHR_l, CHR_e, CTR_CLOSE_EM, PCT_SPACE, CHR_o, CHR_r, CTR_NEWLINE, CTR_ENDLINE
};

//        {em-yellow}store{/em}...{button}{endline}
static s16 scenario_text_0826[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CTR_EM_YELLOW, CHR_s, CHR_t,
    CHR_o, CHR_r, CHR_e, CTR_CLOSE_EM, PCT_PERIOD, PCT_PERIOD, PCT_PERIOD, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_085A[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Koryuta:...I won't be able to hear{newline}{endline}
static s16 scenario_text_0872[] = {
    CHR_K, CHR_o, CHR_r, CHR_y, CHR_u, CHR_t, CHR_a, PCT_COLON, PCT_PERIOD, PCT_PERIOD,
    PCT_PERIOD, CHR_I, PCT_SPACE, CHR_w, CHR_o, CHR_n, PCT_APOSTROPHE, CHR_t, PCT_SPACE, CHR_b,
    CHR_e, PCT_SPACE, CHR_a, CHR_b, CHR_l, CHR_e, PCT_SPACE, CHR_t, CHR_o, PCT_SPACE,
    CHR_h, CHR_e, CHR_a, CHR_r, CTR_NEWLINE, CTR_ENDLINE
};

//        the flute, so make sure{newline}{endline}
static s16 scenario_text_08AA[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_t, CHR_h, CHR_e,
    PCT_SPACE, CHR_f, CHR_l, CHR_u, CHR_t, CHR_e, PCT_COMMA, PCT_SPACE, CHR_s, CHR_o,
    PCT_SPACE, CHR_m, CHR_a, CHR_k, CHR_e, PCT_SPACE, CHR_s, CHR_u, CHR_r, CHR_e,
    CTR_NEWLINE, CTR_ENDLINE
};

//        you're {em-yellow}outside{/em} when you{newline}{endline}
static s16 scenario_text_08DE[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_y, CHR_o, CHR_u,
    PCT_APOSTROPHE, CHR_r, CHR_e, PCT_SPACE, CTR_EM_YELLOW, CHR_o, CHR_u, CHR_t, CHR_s, CHR_i,
    CHR_d, CHR_e, CTR_CLOSE_EM, PCT_SPACE, CHR_w, CHR_h, CHR_e, CHR_n, PCT_SPACE, CHR_y,
    CHR_o, CHR_u, CTR_NEWLINE, CTR_ENDLINE
};

//        play it!{button}{endline}
static s16 scenario_text_0922[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_p, CHR_l, CHR_a,
    CHR_y, PCT_SPACE, CHR_i, CHR_t, PCT_EXCLAMATION, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_0946[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Koryuta:Oh yes,{newline}{endline}
static s16 scenario_text_095E[] = {
    CHR_K, CHR_o, CHR_r, CHR_y, CHR_u, CHR_t, CHR_a, PCT_COLON, CHR_O, CHR_h,
    PCT_SPACE, CHR_y, CHR_e, CHR_s, PCT_COMMA, CTR_NEWLINE, CTR_ENDLINE
};

//        and take this {em-yellow}map{/em}!{newline}{endline}
static s16 scenario_text_0983[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_a, CHR_n, CHR_d,
    PCT_SPACE, CHR_t, CHR_a, CHR_k, CHR_e, PCT_SPACE, CHR_t, CHR_h, CHR_i, CHR_s,
    PCT_SPACE, CTR_EM_YELLOW, CHR_m, CHR_a, CHR_p, CTR_CLOSE_EM, PCT_EXCLAMATION, CTR_NEWLINE, CTR_ENDLINE
};

//        I'm sure it will come in{newline}{endline}
static s16 scenario_text_09C2[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_I, PCT_APOSTROPHE, CHR_m,
    PCT_SPACE, CHR_s, CHR_u, CHR_r, CHR_e, PCT_SPACE, CHR_i, CHR_t, PCT_SPACE, CHR_w,
    CHR_i, CHR_l, CHR_l, PCT_SPACE, CHR_c, CHR_o, CHR_m, CHR_e, PCT_SPACE, CHR_i,
    CHR_n, CTR_NEWLINE, CTR_ENDLINE
};

//        handy!{button}{end}{endline}
static s16 scenario_text_09F7[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_h, CHR_a, CHR_n,
    CHR_d, CHR_y, PCT_EXCLAMATION, CTR_BUTTON, CTR_END, CTR_ENDLINE
};

// {begin}{endline}
static s16 scenario_text_0A1E[] = {
    CTR_BEGIN, CTR_ENDLINE
};

//   {newline}{endline}
static s16 scenario_text_0A32[] = {
    PCT_SPACE, PCT_SPACE, CTR_NEWLINE, CTR_ENDLINE
};

// Goemon and allies{newline}{endline}
static s16 scenario_text_0A4A[] = {
    CHR_G, CHR_o, CHR_e, CHR_m, CHR_o, CHR_n, PCT_SPACE, CHR_a, CHR_n, CHR_d,
    PCT_SPACE, CHR_a, CHR_l, CHR_l, CHR_i, CHR_e, CHR_s, CTR_NEWLINE, CTR_ENDLINE
};

// also receive the [{em-yellow}Map of Japan{/em}]!{button}{endline}
static s16 scenario_text_0A71[] = {
    CHR_a, CHR_l, CHR_s, CHR_o, PCT_SPACE, CHR_r, CHR_e, CHR_c, CHR_e, CHR_i,
    CHR_v, CHR_e, PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE, PCT_LBRACKET, CTR_EM_YELLOW, CHR_M,
    CHR_a, CHR_p, PCT_SPACE, CHR_o, CHR_f, PCT_SPACE, CHR_J, CHR_a, CHR_p, CHR_a,
    CHR_n, CTR_CLOSE_EM, PCT_RBRACKET, PCT_EXCLAMATION, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_0AB6[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Step out of any building and{newline}{endline}
static s16 scenario_text_0ACE[] = {
    CHR_S, CHR_t, CHR_e, CHR_p, PCT_SPACE, CHR_o, CHR_u, CHR_t, PCT_SPACE, CHR_o,
    CHR_f, PCT_SPACE, CHR_a, CHR_n, CHR_y, PCT_SPACE, CHR_b, CHR_u, CHR_i, CHR_l,
    CHR_d, CHR_i, CHR_n, CHR_g, PCT_SPACE, CHR_a, CHR_n, CHR_d, CTR_NEWLINE, CTR_ENDLINE
};

// press the {em-red}START{/em} Button,{newline}{endline}
static s16 scenario_text_0B00[] = {
    CHR_p, CHR_r, CHR_e, CHR_s, CHR_s, PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE,
    CTR_EM_RED, CHR_S, CHR_T, CHR_A, CHR_R, CHR_T, CTR_CLOSE_EM, PCT_SPACE, CHR_B, CHR_u,
    CHR_t, CHR_t, CHR_o, CHR_n, PCT_COMMA, CTR_NEWLINE, CTR_ENDLINE
};

// then by pressing the {em-yellow}Z{/em} Button,{newline}{endline}
static s16 scenario_text_0B3A[] = {
    CHR_t, CHR_h, CHR_e, CHR_n, PCT_SPACE, CHR_b, CHR_y, PCT_SPACE, CHR_p, CHR_r,
    CHR_e, CHR_s, CHR_s, CHR_i, CHR_n, CHR_g, PCT_SPACE, CHR_t, CHR_h, CHR_e,
    PCT_SPACE, CTR_EM_YELLOW, CHR_Z, CTR_CLOSE_EM, PCT_SPACE, CHR_B, CHR_u, CHR_t, CHR_t, CHR_o,
    CHR_n, PCT_COMMA, CTR_NEWLINE, CTR_ENDLINE
};

// you can switch back and forth.{waitinput}{end}{endline}
static s16 scenario_text_0B7E[] = {
    CHR_y, CHR_o, CHR_u, PCT_SPACE, CHR_c, CHR_a, CHR_n, PCT_SPACE, CHR_s, CHR_w,
    CHR_i, CHR_t, CHR_c, CHR_h, PCT_SPACE, CHR_b, CHR_a, CHR_c, CHR_k, PCT_SPACE,
    CHR_a, CHR_n, CHR_d, PCT_SPACE, CHR_f, CHR_o, CHR_r, CHR_t, CHR_h, PCT_PERIOD,
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE
};

// {begin}{endline}
static s16 scenario_text_0BB9[] = {
    CTR_BEGIN, CTR_ENDLINE
};

// Address: @781c

// Koryuta:Well, I must be going!{endline}
static s16 scenario_text_0BCD[] = {
    CHR_K, CHR_o, CHR_r, CHR_y, CHR_u, CHR_t, CHR_a, PCT_COLON, CHR_W, CHR_e,
    CHR_l, CHR_l, PCT_COMMA, PCT_SPACE, CHR_I, PCT_SPACE, CHR_m, CHR_u, CHR_s, CHR_t,
    PCT_SPACE, CHR_b, CHR_e, PCT_SPACE, CHR_g, CHR_o, CHR_i, CHR_n, CHR_g, PCT_EXCLAMATION,
    CTR_ENDLINE
};

// {waitinput}{end}{endline}
static s16 scenario_text_0BF8[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE
};

extern s32 scenario_code_message_1ef_72b4[];
extern s32 scenario_code_message_1ef_781c[];

s32 scenario_code_message_1ef_72b4[] = {

    // Address: @72b4

    // 72b4: Write to RAM 801c7740 (Scratch)
    STW, (s32)&D_801C7740_1C8340,

    // 72bc: Store Value: 30
    WTS, 0x30,

    // 72c4: Execute Code: 8003f460 (Wait For Timer)
    ESR, (s32)&func_8003F460_40060,

    // 72cc: Write to RAM 801c7768 (Dialogue Window Style)
    STW, (s32)&D_801C7768_1C8368,

    // 72d4: Store Value: 7
    WTS, 0x7,

    // 72dc: Write to RAM 8007785c (Dialogue Portrait Character)
    STW, (s32)&D_8007785C_7845C,

    // 72e4: Store Value: 0
    WTS, 0x0,

    // 72ec: Print Text
    TXT, (s32)&scenario_text_0000,

    // 72f4: Write to RAM 801c7740 (Scratch)
    STW, (s32)&D_801C7740_1C8340,

    // 72fc: Store Value: 26c
    WTS, 0x26C,

    // 7304: Execute Code: 8003f608 (Play Sound)
    ESR, (s32)&func_8003F608_40208,

    // 730c: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // 7314: Store Value: 1
    WTS, 0x1,

    // 731c: Print Text
    TXT, (s32)&scenario_text_0014,

    // 7324: Write to RAM 801c7768 (Dialogue Window Style)
    STW, (s32)&D_801C7768_1C8368,

    // 732c: Store Value: 1
    WTS, 0x1,

    // 7334: Write to RAM 8007785c (Dialogue Portrait Character)
    STW, (s32)&D_8007785C_7845C,

    // 733c: Store Value: 16
    WTS, 0x16,

    // 7344: Print Text
    TXT, (s32)&scenario_text_0000,

    // 734c: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // 7354: Store Value: 1
    WTS, 0x1,

    // 735c: Print Text
    TXT, (s32)&scenario_text_006C,

    // 7364: Print Text
    TXT, (s32)&scenario_text_0096,

    // 736c: Print Text
    TXT, (s32)&scenario_text_00BF,

    // 7374: Print Text
    TXT, (s32)&scenario_text_00FF,

    // 737c: Print Text
    TXT, (s32)&scenario_text_0117,

    // 7384: Print Text
    TXT, (s32)&scenario_text_0148,

    // 738c: Print Text
    TXT, (s32)&scenario_text_018B,

    // 7394: Print Text
    TXT, (s32)&scenario_text_00FF,

    // 739c: Print Text
    TXT, (s32)&scenario_text_01C4,

    // 73a4: Print Text
    TXT, (s32)&scenario_text_01F8,

    // 73ac: Print Text
    TXT, (s32)&scenario_text_0260,

    // 73b4: Write to RAM 801c7768 (Dialogue Window Style)
    STW, (s32)&D_801C7768_1C8368,

    // 73bc: Store Value: 7
    WTS, 0x7,

    // 73c4: Write to RAM 8007785c (Dialogue Portrait Character)
    STW, (s32)&D_8007785C_7845C,

    // 73cc: Store Value: 0
    WTS, 0x0,

    // 73d4: Print Text
    TXT, (s32)&scenario_text_0000,

    // 73dc: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // 73e4: Store Value: 1
    WTS, 0x1,

    // 73ec: Print Text
    TXT, (s32)&scenario_text_02BE,

    // 73f4: Print Text
    TXT, (s32)&scenario_text_02EA,

    // 73fc: Print Text
    TXT, (s32)&scenario_text_0313,

    // 7404: Print Text
    TXT, (s32)&scenario_text_0346,

    // 740c: Print Text
    TXT, (s32)&scenario_text_00FF,

    // 7414: Write to RAM 8007785c (Dialogue Portrait Character)
    STW, (s32)&D_8007785C_7845C,

    // 741c: Store Value: 6
    WTS, 0x6,

    // 7424: Print Text
    TXT, (s32)&scenario_text_039D,

    // 742c: Print Text
    TXT, (s32)&scenario_text_03C9,

    // 7434: Print Text
    TXT, (s32)&scenario_text_00FF,

    // 743c: Write to RAM 8007785c (Dialogue Portrait Character)
    STW, (s32)&D_8007785C_7845C,

    // 7444: Store Value: 2
    WTS, 0x2,

    // 744c: Print Text
    TXT, (s32)&scenario_text_0406,

    // 7454: Print Text
    TXT, (s32)&scenario_text_00FF,

    // 745c: Write to RAM 8007785c (Dialogue Portrait Character)
    STW, (s32)&D_8007785C_7845C,

    // 7464: Store Value: 0
    WTS, 0x0,

    // 746c: Print Text
    TXT, (s32)&scenario_text_0444,

    // 7474: Print Text
    TXT, (s32)&scenario_text_0480,

    // 747c: Print Text
    TXT, (s32)&scenario_text_04B0,

    // 7484: Print Text
    TXT, (s32)&scenario_text_00FF,

    // 748c: Write to RAM 8007785c (Dialogue Portrait Character)
    STW, (s32)&D_8007785C_7845C,

    // 7494: Store Value: 2
    WTS, 0x2,

    // 749c: Print Text
    TXT, (s32)&scenario_text_04FA,

    // 74a4: Write to RAM 801c7740 (Scratch)
    STW, (s32)&D_801C7740_1C8340,

    // 74ac: Store Value: 140
    WTS, 0x140,

    // 74b4: Execute Code: 8003f608 (Play Sound)
    ESR, (s32)&func_8003F608_40208,

    // 74bc: Print Text
    TXT, (s32)&scenario_text_0526,

    // 74c4: Write to RAM 801c7758 (Unknown)
    STW, (s32)&D_801C7758_1C8358,

    // 74cc: Store Value: 20
    WTS, 0x20,

    // 74d4: Write to RAM 801c775c (Dialogue Window Y Pos)
    STW, (s32)&D_801C775C_1C835C,

    // 74dc: Store Value: 48
    WTS, 0x48,

    // 74e4: Write to RAM 801c7768 (Dialogue Window Style)
    STW, (s32)&D_801C7768_1C8368,

    // 74ec: Store Value: 7
    WTS, 0x7,

    // 74f4: Write to RAM 8007785c (Dialogue Portrait Character)
    STW, (s32)&D_8007785C_7845C,

    // 74fc: Store Value: 100
    WTS, 0x100,

    // 7504: Print Text
    TXT, (s32)&scenario_text_0000,

    // 750c: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // 7514: Store Value: 1
    WTS, 0x1,

    // 751c: Write to RAM 801c77d8 (Text Speed)
    STW, 0x801c77d8,

    // 7524: Store Value: 64
    WTS, 0x64,

    // 752c: Write to RAM 801c7798 (Unknown)
    STW, 0x801c7798,

    // 7534: Store Value: 1
    WTS, 0x1,

    // 753c: Write to RAM 801c7740 (Scratch)
    STW, (s32)&D_801C7740_1C8340,

    // 7544: Store Value: 14
    WTS, 0x14,

    // 754c: Execute Code: 8003f608 (Play Sound)
    ESR, (s32)&func_8003F608_40208,

    // 7554: Print Text
    TXT, (s32)&scenario_text_0554,

    // 755c: Print Text
    TXT, (s32)&scenario_text_056C,

    // 7564: Print Text
    TXT, (s32)&scenario_text_0590,

    // 756c: Write to RAM 801c7740 (Scratch)
    STW, (s32)&D_801C7740_1C8340,

    // 7574: Store Value: 96
    WTS, 0x96,

    // 757c: Execute Code: 8003f460 (Wait For Timer)
    ESR, (s32)&func_8003F460_40060,

    // 7584: Write to RAM 801c7740 (Scratch)
    STW, (s32)&D_801C7740_1C8340,

    // 758c: Store Value: 58
    WTS, 0x58,

    // 7594: Execute Code: 8003f608 (Play Sound)
    ESR, (s32)&func_8003F608_40208,

    // 759c: Print Text
    TXT, (s32)&scenario_text_05CF,

    // 75a4: Print Text
    TXT, (s32)&scenario_text_00FF,

    // 75ac: Print Text
    TXT, (s32)&scenario_text_0554,

    // 75b4: Print Text
    TXT, (s32)&scenario_text_0614,

    // 75bc: Print Text
    TXT, (s32)&scenario_text_0647,

    // 75c4: Print Text
    TXT, (s32)&scenario_text_00FF,

    // 75cc: Print Text
    TXT, (s32)&scenario_text_0693,

    // 75d4: Print Text
    TXT, (s32)&scenario_text_06CA,

    // 75dc: Print Text
    TXT, (s32)&scenario_text_070F,

    // 75e4: Print Text
    TXT, (s32)&scenario_text_0745,

    // DISABLED ITEM
    // // 75ec: Write to RAM 8015c6c8 (Obtained Flute)
    // STW, 0x8015c6c8,

    // // 75f4: Store Value: 1
    // WTS, 0x1,

    // 75fc: Write to RAM 801c7758 (Unknown)
    STW, (s32)&D_801C7758_1C8358,

    // 7604: Store Value: 20
    WTS, 0x20,

    // 760c: Write to RAM 801c775c (Dialogue Window Y Pos)
    STW, (s32)&D_801C775C_1C835C,

    // 7614: Store Value: 20
    WTS, 0x20,

    // 761c: Write to RAM 801c7768 (Dialogue Window Style)
    STW, (s32)&D_801C7768_1C8368,

    // 7624: Store Value: 1
    WTS, 0x1,

    // 762c: Print Text
    TXT, (s32)&scenario_text_0000,

    // 7634: Write to RAM 801c77d8 (Text Speed)
    STW, 0x801c77d8,

    // 763c: Store Value: 1
    WTS, 0x1,

    // 7644: Write to RAM 801c7798 (Unknown)
    STW, 0x801c7798,

    // 764c: Store Value: 1
    WTS, 0x1,

    // 7654: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // 765c: Store Value: 1
    WTS, 0x1,

    // 7664: Write to RAM 8007785c (Dialogue Portrait Character)
    STW, (s32)&D_8007785C_7845C,

    // 766c: Store Value: 16
    WTS, 0x16,

    // 7674: Print Text
    TXT, (s32)&scenario_text_0776,

    // 767c: Print Text
    TXT, (s32)&scenario_text_07A8,

    // 7684: Print Text
    TXT, (s32)&scenario_text_07E6,

    // 768c: Print Text
    TXT, (s32)&scenario_text_0826,

    // 7694: Print Text
    TXT, (s32)&scenario_text_00FF,

    // 769c: Print Text
    TXT, (s32)&scenario_text_0872,

    // 76a4: Print Text
    TXT, (s32)&scenario_text_08AA,

    // 76ac: Print Text
    TXT, (s32)&scenario_text_08DE,

    // 76b4: Print Text
    TXT, (s32)&scenario_text_0922,

    // 76bc: Print Text
    TXT, (s32)&scenario_text_00FF,

    // 76c4: If Flag 009 (Received Map of Japan), Jump To @781c
    // Jump if flag 0x09 is SET to @781c
    JFS, 0x09, (s32)&scenario_code_message_1ef_781c,

    // 76d0: Print Text
    TXT, (s32)&scenario_text_095E,

    // 76d8: Print Text
    TXT, (s32)&scenario_text_0983,

    // 76e0: Print Text
    TXT, (s32)&scenario_text_09C2,

    // 76e8: Print Text
    TXT, (s32)&scenario_text_09F7,

    // 76f0: Write to RAM 801c7758 (Unknown)
    STW, (s32)&D_801C7758_1C8358,

    // 76f8: Store Value: 20
    WTS, 0x20,

    // 7700: Write to RAM 801c775c (Dialogue Window Y Pos)
    STW, (s32)&D_801C775C_1C835C,

    // 7708: Store Value: 48
    WTS, 0x48,

    // 7710: Write to RAM 8007785c (Dialogue Portrait Character)
    STW, (s32)&D_8007785C_7845C,

    // 7718: Store Value: 100
    WTS, 0x100,

    // 7720: Write to RAM 801c7768 (Dialogue Window Style)
    STW, (s32)&D_801C7768_1C8368,

    // 7728: Store Value: 7
    WTS, 0x7,

    // 7730: Print Text
    TXT, (s32)&scenario_text_0000,

    // 7738: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // 7740: Store Value: 1
    WTS, 0x1,

    // 7748: Write to RAM 801c77d8 (Text Speed)
    STW, 0x801c77d8,

    // 7750: Store Value: 64
    WTS, 0x64,

    // 7758: Write to RAM 801c7798 (Unknown)
    STW, 0x801c7798,

    // 7760: Store Value: 1
    WTS, 0x1,

    // 7768: Write to RAM 801c7740 (Scratch)
    STW, (s32)&D_801C7740_1C8340,

    // 7770: Store Value: 26c
    WTS, 0x26C,

    // 7778: Execute Code: 8003f608 (Play Sound)
    ESR, (s32)&func_8003F608_40208,

    // 7780: Print Text
    TXT, (s32)&scenario_text_0554,

    // 7788: Print Text
    TXT, (s32)&scenario_text_0A4A,

    // 7790: Print Text
    TXT, (s32)&scenario_text_0A71,

    // 7798: Print Text
    TXT, (s32)&scenario_text_00FF,

    // 77a0: Print Text
    TXT, (s32)&scenario_text_0ACE,

    // 77a8: Print Text
    TXT, (s32)&scenario_text_0B00,

    // 77b0: Print Text
    TXT, (s32)&scenario_text_0B3A,

    // 77b8: Print Text
    TXT, (s32)&scenario_text_0B7E,

    // 77c0: Write to RAM 8015c870 (Unknown)
    STW, 0x8015c870,

    // 77c8: Store Value: 1
    WTS, 0x1,

    // 77d0: Set Flag 009 (Received Map of Japan)
    SFG, 0x09,

    // 77d8: Write to RAM 801c7758 (Unknown)
    STW, (s32)&D_801C7758_1C8358,

    // 77e0: Store Value: 20
    WTS, 0x20,

    // 77e8: Write to RAM 801c775c (Dialogue Window Y Pos)
    STW, (s32)&D_801C775C_1C835C,

    // 77f0: Store Value: 20
    WTS, 0x20,

    // 77f8: Write to RAM 801c7768 (Dialogue Window Style)
    STW, (s32)&D_801C7768_1C8368,

    // 7800: Store Value: 1
    WTS, 0x1,

    // 7808: Print Text
    TXT, (s32)&scenario_text_0000,

    // 7810: Jump To @781c
    JMP, (s32)&scenario_code_message_1ef_781c,

    // 7818: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_1ef_781c[] = {

    // Address: @781c

    // 781c: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // 7824: Store Value: 1
    WTS, 0x1,

    // 782c: Write to RAM 801c77d8 (Text Speed)
    STW, 0x801c77d8,

    // 7834: Store Value: 1
    WTS, 0x1,

    // 783c: Write to RAM 801c7798 (Unknown)
    STW, 0x801c7798,

    // 7844: Store Value: 1
    WTS, 0x1,

    // 784c: Write to RAM 8007785c (Dialogue Portrait Character)
    STW, (s32)&D_8007785C_7845C,

    // 7854: Store Value: 16
    WTS, 0x16,

    // 785c: Print Text
    TXT, (s32)&scenario_text_0BCD,

    // 7864: Print Text
    TXT, (s32)&scenario_text_0745,

    // 786c: Write to RAM 801c7740 (Scratch)
    STW, (s32)&D_801C7740_1C8340,

    // 7874: Store Value: 7
    WTS, 0x7,

    // 787c: Execute Code: 8003f608 (Play Sound)
    ESR, (s32)&func_8003F608_40208,

    // 7884: Write to RAM 801c7740 (Scratch)
    STW, (s32)&D_801C7740_1C8340,

    // 788c: Store Value: 3c
    WTS, 0x3C,

    // 7894: Execute Code: 8003f460 (Wait For Timer)
    ESR, (s32)&func_8003F460_40060,

    // 789c: Write to RAM 801c7740 (Scratch)
    STW, (s32)&D_801C7740_1C8340,

    // 78a4: Store Value: 31
    WTS, 0x31,

    // 78ac: Execute Code: 8003f608 (Play Sound)
    ESR, (s32)&func_8003F608_40208,

    // 78b4: Write to RAM 800c7ac4 (Unknown)
    STW, 0x800c7ac4,

    // 78bc: Store Value: 0
    WTS, 0x0,

    // 78c4: End Event
    END,

    // End scenario script
    END,
};

