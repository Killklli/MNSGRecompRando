// Disables PLASMA from granting flags that affect game progression.
// We have to do this because we're going to be setting this up to be the hint system
#include "scenario.h"

#include "common.h"

// SHOP 27 - Unknown Town Plasma - Unused - Plasma Backup Dancer
// Address: @2f98

// {begin}{endline}
static s16 scenario_text_0000[] = {
    CTR_BEGIN, CTR_ENDLINE
};

//  {newline}{endline}
static s16 scenario_text_0014[] = {
    PCT_SPACE, CTR_NEWLINE, CTR_ENDLINE
};

//        {big}{blink}P L A S M A ! {/blink}{/big}{button}{endline}
static s16 scenario_text_002B[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CTR_BIG, CTR_BLINK, CHR_P,
    PCT_SPACE, CHR_L, PCT_SPACE, CHR_A, PCT_SPACE, CHR_S, PCT_SPACE, CHR_M, PCT_SPACE, CHR_A,
    PCT_SPACE, PCT_EXCLAMATION, PCT_SPACE, CTR_CLOSE_BLINK, CTR_CLOSE_BIG, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_006F[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Plasma Man:{newline}{endline}
static s16 scenario_text_0087[] = {
    CHR_P, CHR_l, CHR_a, CHR_s, CHR_m, CHR_a, PCT_SPACE, CHR_M, CHR_a, CHR_n,
    PCT_COLON, CTR_NEWLINE, CTR_ENDLINE
};

//     Howdy!  Welcome to{newline}{endline}
static s16 scenario_text_00A8[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_H, CHR_o, CHR_w, CHR_d, CHR_y, PCT_EXCLAMATION,
    PCT_SPACE, PCT_SPACE, CHR_W, CHR_e, CHR_l, CHR_c, CHR_o, CHR_m, CHR_e, PCT_SPACE,
    CHR_t, CHR_o, CTR_NEWLINE, CTR_ENDLINE
};

//     the {em-yellow}Plasma Fortune Teller{/em}.{button}{endline}
static s16 scenario_text_00D4[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE, CTR_EM_YELLOW, CHR_P,
    CHR_l, CHR_a, CHR_s, CHR_m, CHR_a, PCT_SPACE, CHR_F, CHR_o, CHR_r, CHR_t,
    CHR_u, CHR_n, CHR_e, PCT_SPACE, CHR_T, CHR_e, CHR_l, CHR_l, CHR_e, CHR_r,
    CTR_CLOSE_EM, PCT_PERIOD, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_0117[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// I will solve your worries{newline}{endline}
static s16 scenario_text_012F[] = {
    CHR_I, PCT_SPACE, CHR_w, CHR_i, CHR_l, CHR_l, PCT_SPACE, CHR_s, CHR_o, CHR_l,
    CHR_v, CHR_e, PCT_SPACE, CHR_y, CHR_o, CHR_u, CHR_r, PCT_SPACE, CHR_w, CHR_o,
    CHR_r, CHR_r, CHR_i, CHR_e, CHR_s, CTR_NEWLINE, CTR_ENDLINE
};

// for {em-yellow}10{/em} ryo, plasma!{newline}{endline}
static s16 scenario_text_015E[] = {
    CHR_f, CHR_o, CHR_r, PCT_SPACE, CTR_EM_YELLOW, NUM_1, NUM_0, CTR_CLOSE_EM, PCT_SPACE, CHR_r,
    CHR_y, CHR_o, PCT_COMMA, PCT_SPACE, CHR_p, CHR_l, CHR_a, CHR_s, CHR_m, CHR_a,
    PCT_EXCLAMATION, CTR_NEWLINE, CTR_ENDLINE
};

//   {em-yellow}Ah, yes please.{newline}{endline}
static s16 scenario_text_0197[] = {
    PCT_SPACE, PCT_SPACE, CTR_EM_YELLOW, CHR_A, CHR_h, PCT_COMMA, PCT_SPACE, CHR_y, CHR_e, CHR_s,
    PCT_SPACE, CHR_p, CHR_l, CHR_e, CHR_a, CHR_s, CHR_e, PCT_PERIOD, CTR_NEWLINE, CTR_ENDLINE
};

//   {em-yellow}No, no thank you.{newline}{endline}
static s16 scenario_text_01C9[] = {
    PCT_SPACE, PCT_SPACE, CTR_EM_YELLOW, CHR_N, CHR_o, PCT_COMMA, PCT_SPACE, CHR_n, CHR_o, PCT_SPACE,
    CHR_t, CHR_h, CHR_a, CHR_n, CHR_k, PCT_SPACE, CHR_y, CHR_o, CHR_u, PCT_PERIOD,
    CTR_NEWLINE, CTR_ENDLINE
};

// {end}{endline}
static s16 scenario_text_01FD[] = {
    CTR_END, CTR_ENDLINE
};

// Address: @3094

// {newwindow}{endline}
static s16 scenario_text_020F[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// {/em}Okay,{newline}{endline}
static s16 scenario_text_0227[] = {
    CTR_CLOSE_EM, CHR_O, CHR_k, CHR_a, CHR_y, PCT_COMMA, CTR_NEWLINE, CTR_ENDLINE
};

// well let's get started!!{button}{endline}
static s16 scenario_text_0247[] = {
    CHR_w, CHR_e, CHR_l, CHR_l, PCT_SPACE, CHR_l, CHR_e, CHR_t, PCT_APOSTROPHE, CHR_s,
    PCT_SPACE, CHR_g, CHR_e, CHR_t, PCT_SPACE, CHR_s, CHR_t, CHR_a, CHR_r, CHR_t,
    CHR_e, CHR_d, PCT_EXCLAMATION, PCT_EXCLAMATION, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_0274[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Hmmmm, abababa, hmmmm, abababa,{newline}{endline}
static s16 scenario_text_028C[] = {
    CHR_H, CHR_m, CHR_m, CHR_m, CHR_m, PCT_COMMA, PCT_SPACE, CHR_a, CHR_b, CHR_a,
    CHR_b, CHR_a, CHR_b, CHR_a, PCT_COMMA, PCT_SPACE, CHR_h, CHR_m, CHR_m, CHR_m,
    CHR_m, PCT_COMMA, PCT_SPACE, CHR_a, CHR_b, CHR_a, CHR_b, CHR_a, CHR_b, CHR_a,
    PCT_COMMA, CTR_NEWLINE, CTR_ENDLINE
};

// hmmmm, abababa, hmmmm, abababa,{newline}{endline}
static s16 scenario_text_02C1[] = {
    CHR_h, CHR_m, CHR_m, CHR_m, CHR_m, PCT_COMMA, PCT_SPACE, CHR_a, CHR_b, CHR_a,
    CHR_b, CHR_a, CHR_b, CHR_a, PCT_COMMA, PCT_SPACE, CHR_h, CHR_m, CHR_m, CHR_m,
    CHR_m, PCT_COMMA, PCT_SPACE, CHR_a, CHR_b, CHR_a, CHR_b, CHR_a, CHR_b, CHR_a,
    PCT_COMMA, CTR_NEWLINE, CTR_ENDLINE
};

// hmmmm, abababa, hmmmm, abababa...{button}{endline}
static s16 scenario_text_02F6[] = {
    CHR_h, CHR_m, CHR_m, CHR_m, CHR_m, PCT_COMMA, PCT_SPACE, CHR_a, CHR_b, CHR_a,
    CHR_b, CHR_a, CHR_b, CHR_a, PCT_COMMA, PCT_SPACE, CHR_h, CHR_m, CHR_m, CHR_m,
    CHR_m, PCT_COMMA, PCT_SPACE, CHR_a, CHR_b, CHR_a, CHR_b, CHR_a, CHR_b, CHR_a,
    PCT_PERIOD, PCT_PERIOD, PCT_PERIOD, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_032C[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

//  {newline}{endline}
static s16 scenario_text_0344[] = {
    PCT_SPACE, CTR_NEWLINE, CTR_ENDLINE
};

//        {em-yellow}{blink}{big}P L A S M A ! {/big}{/blink}{/em}{button}{endline}
static s16 scenario_text_035B[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CTR_EM_YELLOW, CTR_BLINK, CTR_BIG,
    CHR_P, PCT_SPACE, CHR_L, PCT_SPACE, CHR_A, PCT_SPACE, CHR_S, PCT_SPACE, CHR_M, PCT_SPACE,
    CHR_A, PCT_SPACE, PCT_EXCLAMATION, PCT_SPACE, CTR_CLOSE_BIG, CTR_CLOSE_BLINK, CTR_CLOSE_EM, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_03AF[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Address: @31a8

// {newwindow}{endline}
static s16 scenario_text_03C7[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// {/em}Go ahead then, {newline}{endline}
static s16 scenario_text_03DF[] = {
    CTR_CLOSE_EM, CHR_G, CHR_o, PCT_SPACE, CHR_a, CHR_h, CHR_e, CHR_a, CHR_d, PCT_SPACE,
    CHR_t, CHR_h, CHR_e, CHR_n, PCT_COMMA, PCT_SPACE, CTR_NEWLINE, CTR_ENDLINE
};

// worry for the rest of your life,{newline}{endline}
static s16 scenario_text_0409[] = {
    CHR_w, CHR_o, CHR_r, CHR_r, CHR_y, PCT_SPACE, CHR_f, CHR_o, CHR_r, PCT_SPACE,
    CHR_t, CHR_h, CHR_e, PCT_SPACE, CHR_r, CHR_e, CHR_s, CHR_t, PCT_SPACE, CHR_o,
    CHR_f, PCT_SPACE, CHR_y, CHR_o, CHR_u, CHR_r, PCT_SPACE, CHR_l, CHR_i, CHR_f,
    CHR_e, PCT_COMMA, CTR_NEWLINE, CTR_ENDLINE
};

// plasma.{endline}
static s16 scenario_text_043F[] = {
    CHR_p, CHR_l, CHR_a, CHR_s, CHR_m, CHR_a, PCT_PERIOD, CTR_ENDLINE
};

// {waitinput}{end}{endline}
static s16 scenario_text_0453[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE
};

// Address: @31d4

// {/em}I'm not telling anything to anyone{newline}{endline}
static s16 scenario_text_0470[] = {
    CTR_CLOSE_EM, CHR_I, PCT_APOSTROPHE, CHR_m, PCT_SPACE, CHR_n, CHR_o, CHR_t, PCT_SPACE, CHR_t,
    CHR_e, CHR_l, CHR_l, CHR_i, CHR_n, CHR_g, PCT_SPACE, CHR_a, CHR_n, CHR_y,
    CHR_t, CHR_h, CHR_i, CHR_n, CHR_g, PCT_SPACE, CHR_t, CHR_o, PCT_SPACE, CHR_a,
    CHR_n, CHR_y, CHR_o, CHR_n, CHR_e, CTR_NEWLINE, CTR_ENDLINE
};

// who's got no money, plasma!{endline}
static s16 scenario_text_04AD[] = {
    CHR_w, CHR_h, CHR_o, PCT_APOSTROPHE, CHR_s, PCT_SPACE, CHR_g, CHR_o, CHR_t, PCT_SPACE,
    CHR_n, CHR_o, PCT_SPACE, CHR_m, CHR_o, CHR_n, CHR_e, CHR_y, PCT_COMMA, PCT_SPACE,
    CHR_p, CHR_l, CHR_a, CHR_s, CHR_m, CHR_a, PCT_EXCLAMATION, CTR_ENDLINE
};

// {waitinput}{end}{endline}
static s16 scenario_text_04D5[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE
};

// Address: @3208

// If you want to enter {em-yellow}Oedo Castle{/em}...{button}{endline}
static s16 scenario_text_04F2[] = {
    CHR_I, CHR_f, PCT_SPACE, CHR_y, CHR_o, CHR_u, PCT_SPACE, CHR_w, CHR_a, CHR_n,
    CHR_t, PCT_SPACE, CHR_t, CHR_o, PCT_SPACE, CHR_e, CHR_n, CHR_t, CHR_e, CHR_r,
    PCT_SPACE, CTR_EM_YELLOW, CHR_O, CHR_e, CHR_d, CHR_o, PCT_SPACE, CHR_C, CHR_a, CHR_s,
    CHR_t, CHR_l, CHR_e, CTR_CLOSE_EM, PCT_PERIOD, PCT_PERIOD, PCT_PERIOD, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_053A[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Enter on the {em-yellow}left{/em} hand side{newline}{endline}
static s16 scenario_text_0552[] = {
    CHR_E, CHR_n, CHR_t, CHR_e, CHR_r, PCT_SPACE, CHR_o, CHR_n, PCT_SPACE, CHR_t,
    CHR_h, CHR_e, PCT_SPACE, CTR_EM_YELLOW, CHR_l, CHR_e, CHR_f, CHR_t, CTR_CLOSE_EM, PCT_SPACE,
    CHR_h, CHR_a, CHR_n, CHR_d, PCT_SPACE, CHR_s, CHR_i, CHR_d, CHR_e, CTR_NEWLINE,
    CTR_ENDLINE
};

// when you face {em-yellow}this fortune teller{/em}.{button}{endline}
static s16 scenario_text_0593[] = {
    CHR_w, CHR_h, CHR_e, CHR_n, PCT_SPACE, CHR_y, CHR_o, CHR_u, PCT_SPACE, CHR_f,
    CHR_a, CHR_c, CHR_e, PCT_SPACE, CTR_EM_YELLOW, CHR_t, CHR_h, CHR_i, CHR_s, PCT_SPACE,
    CHR_f, CHR_o, CHR_r, CHR_t, CHR_u, CHR_n, CHR_e, PCT_SPACE, CHR_t, CHR_e,
    CHR_l, CHR_l, CHR_e, CHR_r, CTR_CLOSE_EM, PCT_PERIOD, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_05DA[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// That will take you to{newline}{endline}
static s16 scenario_text_05F2[] = {
    CHR_T, CHR_h, CHR_a, CHR_t, PCT_SPACE, CHR_w, CHR_i, CHR_l, CHR_l, PCT_SPACE,
    CHR_t, CHR_a, CHR_k, CHR_e, PCT_SPACE, CHR_y, CHR_o, CHR_u, PCT_SPACE, CHR_t,
    CHR_o, CTR_NEWLINE, CTR_ENDLINE
};

// the [Kai Highway] which will{newline}{endline}
static s16 scenario_text_061D[] = {
    CHR_t, CHR_h, CHR_e, PCT_SPACE, PCT_LBRACKET, CHR_K, CHR_a, CHR_i, PCT_SPACE, CHR_H,
    CHR_i, CHR_g, CHR_h, CHR_w, CHR_a, CHR_y, PCT_RBRACKET, PCT_SPACE, CHR_w, CHR_h,
    CHR_i, CHR_c, CHR_h, PCT_SPACE, CHR_w, CHR_i, CHR_l, CHR_l, CTR_NEWLINE, CTR_ENDLINE
};

// lead you to {em-yellow}Mt. Fuji{/em}, plasma!{endline}
static s16 scenario_text_064F[] = {
    CHR_l, CHR_e, CHR_a, CHR_d, PCT_SPACE, CHR_y, CHR_o, CHR_u, PCT_SPACE, CHR_t,
    CHR_o, PCT_SPACE, CTR_EM_YELLOW, CHR_M, CHR_t, PCT_PERIOD, PCT_SPACE, CHR_F, CHR_u, CHR_j,
    CHR_i, CTR_CLOSE_EM, PCT_COMMA, PCT_SPACE, CHR_p, CHR_l, CHR_a, CHR_s, CHR_m, CHR_a,
    PCT_EXCLAMATION, CTR_ENDLINE
};

// {waitinput}{end}{endline}
static s16 scenario_text_0689[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE
};

// Address: @3260

// Use the {em-yellow}Chain Pipe{/em} to cross{newline}{endline}
static s16 scenario_text_06A6[] = {
    CHR_U, CHR_s, CHR_e, PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE, CTR_EM_YELLOW, CHR_C,
    CHR_h, CHR_a, CHR_i, CHR_n, PCT_SPACE, CHR_P, CHR_i, CHR_p, CHR_e, CTR_CLOSE_EM,
    PCT_SPACE, CHR_t, CHR_o, PCT_SPACE, CHR_c, CHR_r, CHR_o, CHR_s, CHR_s, CTR_NEWLINE,
    CTR_ENDLINE
};

// the damaged [{em-yellow}Bridge{/em}] and{newline}{endline}
static s16 scenario_text_06E7[] = {
    CHR_t, CHR_h, CHR_e, PCT_SPACE, CHR_d, CHR_a, CHR_m, CHR_a, CHR_g, CHR_e,
    CHR_d, PCT_SPACE, PCT_LBRACKET, CTR_EM_YELLOW, CHR_B, CHR_r, CHR_i, CHR_d, CHR_g, CHR_e,
    CTR_CLOSE_EM, PCT_RBRACKET, PCT_SPACE, CHR_a, CHR_n, CHR_d, CTR_NEWLINE, CTR_ENDLINE
};

// enter into {em-yellow}Oedo Castle{/em}, plasma!{endline}
static s16 scenario_text_0725[] = {
    CHR_e, CHR_n, CHR_t, CHR_e, CHR_r, PCT_SPACE, CHR_i, CHR_n, CHR_t, CHR_o,
    PCT_SPACE, CTR_EM_YELLOW, CHR_O, CHR_e, CHR_d, CHR_o, PCT_SPACE, CHR_C, CHR_a, CHR_s,
    CHR_t, CHR_l, CHR_e, CTR_CLOSE_EM, PCT_COMMA, PCT_SPACE, CHR_p, CHR_l, CHR_a, CHR_s,
    CHR_m, CHR_a, PCT_EXCLAMATION, CTR_ENDLINE
};

// {waitinput}{end}{endline}
static s16 scenario_text_0761[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE
};

// Address: @3290

// As you leave the {em-yellow}gate{/em}, {newline}{endline}
static s16 scenario_text_077E[] = {
    CHR_A, CHR_s, PCT_SPACE, CHR_y, CHR_o, CHR_u, PCT_SPACE, CHR_l, CHR_e, CHR_a,
    CHR_v, CHR_e, PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE, CTR_EM_YELLOW, CHR_g, CHR_a,
    CHR_t, CHR_e, CTR_CLOSE_EM, PCT_COMMA, PCT_SPACE, CTR_NEWLINE, CTR_ENDLINE
};

// take the {em-yellow}West{/em} tunnel to [{em-yellow}Iga{/em}],{newline}{endline}
static s16 scenario_text_07BB[] = {
    CHR_t, CHR_a, CHR_k, CHR_e, PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE, CTR_EM_YELLOW,
    CHR_W, CHR_e, CHR_s, CHR_t, CTR_CLOSE_EM, PCT_SPACE, CHR_t, CHR_u, CHR_n, CHR_n,
    CHR_e, CHR_l, PCT_SPACE, CHR_t, CHR_o, PCT_SPACE, PCT_LBRACKET, CTR_EM_YELLOW, CHR_I, CHR_g,
    CHR_a, CTR_CLOSE_EM, PCT_RBRACKET, PCT_COMMA, CTR_NEWLINE, CTR_ENDLINE
};

// plasma!{button}{endline}
static s16 scenario_text_080F[] = {
    CHR_p, CHR_l, CHR_a, CHR_s, CHR_m, CHR_a, PCT_EXCLAMATION, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_082B[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// You shall meet{newline}{endline}
static s16 scenario_text_0843[] = {
    CHR_Y, CHR_o, CHR_u, PCT_SPACE, CHR_s, CHR_h, CHR_a, CHR_l, CHR_l, PCT_SPACE,
    CHR_m, CHR_e, CHR_e, CHR_t, CTR_NEWLINE, CTR_ENDLINE
};

// the [{em-yellow}Wise Man{/em}] there!{endline}
static s16 scenario_text_0867[] = {
    CHR_t, CHR_h, CHR_e, PCT_SPACE, PCT_LBRACKET, CTR_EM_YELLOW, CHR_W, CHR_i, CHR_s, CHR_e,
    PCT_SPACE, CHR_M, CHR_a, CHR_n, CTR_CLOSE_EM, PCT_RBRACKET, PCT_SPACE, CHR_t, CHR_h, CHR_e,
    CHR_r, CHR_e, PCT_EXCLAMATION, CTR_ENDLINE
};

// {waitinput}{end}{endline}
static s16 scenario_text_0899[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE
};

// Address: @32d8

// In order to make {em-yellow}Benkei{/em} move{newline}{endline}
static s16 scenario_text_08B6[] = {
    CHR_I, CHR_n, PCT_SPACE, CHR_o, CHR_r, CHR_d, CHR_e, CHR_r, PCT_SPACE, CHR_t,
    CHR_o, PCT_SPACE, CHR_m, CHR_a, CHR_k, CHR_e, PCT_SPACE, CTR_EM_YELLOW, CHR_B, CHR_e,
    CHR_n, CHR_k, CHR_e, CHR_i, CTR_CLOSE_EM, PCT_SPACE, CHR_m, CHR_o, CHR_v, CHR_e,
    CTR_NEWLINE, CTR_ENDLINE
};

// over on the {em-yellow}Gojo Ohashi Bridge{/em},{button}{endline}
static s16 scenario_text_08F8[] = {
    CHR_o, CHR_v, CHR_e, CHR_r, PCT_SPACE, CHR_o, CHR_n, PCT_SPACE, CHR_t, CHR_h,
    CHR_e, PCT_SPACE, CTR_EM_YELLOW, CHR_G, CHR_o, CHR_j, CHR_o, PCT_SPACE, CHR_O, CHR_h,
    CHR_a, CHR_s, CHR_h, CHR_i, PCT_SPACE, CHR_B, CHR_r, CHR_i, CHR_d, CHR_g,
    CHR_e, CTR_CLOSE_EM, PCT_COMMA, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_093C[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// go and meet the {em-yellow}Rude Guy{/em}, {newline}{endline}
static s16 scenario_text_0954[] = {
    CHR_g, CHR_o, PCT_SPACE, CHR_a, CHR_n, CHR_d, PCT_SPACE, CHR_m, CHR_e, CHR_e,
    CHR_t, PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE, CTR_EM_YELLOW, CHR_R, CHR_u, CHR_d,
    CHR_e, PCT_SPACE, CHR_G, CHR_u, CHR_y, CTR_CLOSE_EM, PCT_COMMA, PCT_SPACE, CTR_NEWLINE, CTR_ENDLINE
};

// who you'll find fishing at{newline}{endline}
static s16 scenario_text_0994[] = {
    CHR_w, CHR_h, CHR_o, PCT_SPACE, CHR_y, CHR_o, CHR_u, PCT_APOSTROPHE, CHR_l, CHR_l,
    PCT_SPACE, CHR_f, CHR_i, CHR_n, CHR_d, PCT_SPACE, CHR_f, CHR_i, CHR_s, CHR_h,
    CHR_i, CHR_n, CHR_g, PCT_SPACE, CHR_a, CHR_t, CTR_NEWLINE, CTR_ENDLINE
};

// the [{em-yellow}Duck Creek{/em}] in Zazen Town,{newline}{endline}
static s16 scenario_text_09C4[] = {
    CHR_t, CHR_h, CHR_e, PCT_SPACE, PCT_LBRACKET, CTR_EM_YELLOW, CHR_D, CHR_u, CHR_c, CHR_k,
    PCT_SPACE, CHR_C, CHR_r, CHR_e, CHR_e, CHR_k, CTR_CLOSE_EM, PCT_RBRACKET, PCT_SPACE, CHR_i,
    CHR_n, PCT_SPACE, CHR_Z, CHR_a, CHR_z, CHR_e, CHR_n, PCT_SPACE, CHR_T, CHR_o,
    CHR_w, CHR_n, PCT_COMMA, CTR_NEWLINE, CTR_ENDLINE
};

// plasma!{endline}
static s16 scenario_text_0A09[] = {
    CHR_p, CHR_l, CHR_a, CHR_s, CHR_m, CHR_a, PCT_EXCLAMATION, CTR_ENDLINE
};

// {waitinput}{end}{endline}
static s16 scenario_text_0A1D[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE
};

// Address: @3340

// Throw the [{em-yellow}Achilles' heel{/em}],{newline}{endline}
static s16 scenario_text_0A3A[] = {
    CHR_T, CHR_h, CHR_r, CHR_o, CHR_w, PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE,
    PCT_LBRACKET, CTR_EM_YELLOW, CHR_A, CHR_c, CHR_h, CHR_i, CHR_l, CHR_l, CHR_e, CHR_s,
    PCT_APOSTROPHE, PCT_SPACE, CHR_h, CHR_e, CHR_e, CHR_l, CTR_CLOSE_EM, PCT_RBRACKET, PCT_COMMA, CTR_NEWLINE,
    CTR_ENDLINE
};

// which you have with you,{newline}{endline}
static s16 scenario_text_0A7B[] = {
    CHR_w, CHR_h, CHR_i, CHR_c, CHR_h, PCT_SPACE, CHR_y, CHR_o, CHR_u, PCT_SPACE,
    CHR_h, CHR_a, CHR_v, CHR_e, PCT_SPACE, CHR_w, CHR_i, CHR_t, CHR_h, PCT_SPACE,
    CHR_y, CHR_o, CHR_u, PCT_COMMA, CTR_NEWLINE, CTR_ENDLINE
};

// directly at {em-yellow}Benkei{/em}, plasma!{endline}
static s16 scenario_text_0AA9[] = {
    CHR_d, CHR_i, CHR_r, CHR_e, CHR_c, CHR_t, CHR_l, CHR_y, PCT_SPACE, CHR_a,
    CHR_t, PCT_SPACE, CTR_EM_YELLOW, CHR_B, CHR_e, CHR_n, CHR_k, CHR_e, CHR_i, CTR_CLOSE_EM,
    PCT_COMMA, PCT_SPACE, CHR_p, CHR_l, CHR_a, CHR_s, CHR_m, CHR_a, PCT_EXCLAMATION, CTR_ENDLINE
};

// {waitinput}{end}{endline}
static s16 scenario_text_0AE1[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE
};

// Address: @3370

// Cross the {em-yellow}Gojo Ohashi Bridge{/em},{newline}{endline}
static s16 scenario_text_0AFE[] = {
    CHR_C, CHR_r, CHR_o, CHR_s, CHR_s, PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE,
    CTR_EM_YELLOW, CHR_G, CHR_o, CHR_j, CHR_o, PCT_SPACE, CHR_O, CHR_h, CHR_a, CHR_s,
    CHR_h, CHR_i, PCT_SPACE, CHR_B, CHR_r, CHR_i, CHR_d, CHR_g, CHR_e, CTR_CLOSE_EM,
    PCT_COMMA, CTR_NEWLINE, CTR_ENDLINE
};

// and pass through [Yamato] and{newline}{endline}
static s16 scenario_text_0B41[] = {
    CHR_a, CHR_n, CHR_d, PCT_SPACE, CHR_p, CHR_a, CHR_s, CHR_s, PCT_SPACE, CHR_t,
    CHR_h, CHR_r, CHR_o, CHR_u, CHR_g, CHR_h, PCT_SPACE, PCT_LBRACKET, CHR_Y, CHR_a,
    CHR_m, CHR_a, CHR_t, CHR_o, PCT_RBRACKET, PCT_SPACE, CHR_a, CHR_n, CHR_d, CTR_NEWLINE,
    CTR_ENDLINE
};

// [Kii - Awaji] to get to{newline}{endline}
static s16 scenario_text_0B74[] = {
    PCT_LBRACKET, CHR_K, CHR_i, CHR_i, PCT_SPACE, PCT_DASH, PCT_SPACE, CHR_A, CHR_w, CHR_a,
    CHR_j, CHR_i, PCT_RBRACKET, PCT_SPACE, CHR_t, CHR_o, PCT_SPACE, CHR_g, CHR_e, CHR_t,
    PCT_SPACE, CHR_t, CHR_o, CTR_NEWLINE, CTR_ENDLINE
};

// {em-yellow}Shikoku Region{/em}, plasma!{endline}
static s16 scenario_text_0BA1[] = {
    CTR_EM_YELLOW, CHR_S, CHR_h, CHR_i, CHR_k, CHR_o, CHR_k, CHR_u, PCT_SPACE, CHR_R,
    CHR_e, CHR_g, CHR_i, CHR_o, CHR_n, CTR_CLOSE_EM, PCT_COMMA, PCT_SPACE, CHR_p, CHR_l,
    CHR_a, CHR_s, CHR_m, CHR_a, PCT_EXCLAMATION, CTR_ENDLINE
};

// {waitinput}{end}{endline}
static s16 scenario_text_0BD5[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE
};

// Address: @33a8

// Destroy the {em-yellow}Control Machine{/em}{newline}{endline}
static s16 scenario_text_0BF2[] = {
    CHR_D, CHR_e, CHR_s, CHR_t, CHR_r, CHR_o, CHR_y, PCT_SPACE, CHR_t, CHR_h,
    CHR_e, PCT_SPACE, CTR_EM_YELLOW, CHR_C, CHR_o, CHR_n, CHR_t, CHR_r, CHR_o, CHR_l,
    PCT_SPACE, CHR_M, CHR_a, CHR_c, CHR_h, CHR_i, CHR_n, CHR_e, CTR_CLOSE_EM, CTR_NEWLINE,
    CTR_ENDLINE
};

// attached to the head{newline}{endline}
static s16 scenario_text_0C33[] = {
    CHR_a, CHR_t, CHR_t, CHR_a, CHR_c, CHR_h, CHR_e, CHR_d, PCT_SPACE, CHR_t,
    CHR_o, PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE, CHR_h, CHR_e, CHR_a, CHR_d,
    CTR_NEWLINE, CTR_ENDLINE
};

// of the {em-yellow}dragon{/em}, plasma!{button}{endline}
static s16 scenario_text_0C5D[] = {
    CHR_o, CHR_f, PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE, CTR_EM_YELLOW, CHR_d, CHR_r,
    CHR_a, CHR_g, CHR_o, CHR_n, CTR_CLOSE_EM, PCT_COMMA, PCT_SPACE, CHR_p, CHR_l, CHR_a,
    CHR_s, CHR_m, CHR_a, PCT_EXCLAMATION, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_0C98[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Unless you do this,{newline}{endline}
static s16 scenario_text_0CB0[] = {
    CHR_U, CHR_n, CHR_l, CHR_e, CHR_s, CHR_s, PCT_SPACE, CHR_y, CHR_o, CHR_u,
    PCT_SPACE, CHR_d, CHR_o, PCT_SPACE, CHR_t, CHR_h, CHR_i, CHR_s, PCT_COMMA, CTR_NEWLINE,
    CTR_ENDLINE
};

// the {em-yellow}dragon{/em} cannot return to{newline}{endline}
static s16 scenario_text_0CD9[] = {
    CHR_t, CHR_h, CHR_e, PCT_SPACE, CTR_EM_YELLOW, CHR_d, CHR_r, CHR_a, CHR_g, CHR_o,
    CHR_n, CTR_CLOSE_EM, PCT_SPACE, CHR_c, CHR_a, CHR_n, CHR_n, CHR_o, CHR_t, PCT_SPACE,
    CHR_r, CHR_e, CHR_t, CHR_u, CHR_r, CHR_n, PCT_SPACE, CHR_t, CHR_o, CTR_NEWLINE,
    CTR_ENDLINE
};

// its normal state!{endline}
static s16 scenario_text_0D1A[] = {
    CHR_i, CHR_t, CHR_s, PCT_SPACE, CHR_n, CHR_o, CHR_r, CHR_m, CHR_a, CHR_l,
    PCT_SPACE, CHR_s, CHR_t, CHR_a, CHR_t, CHR_e, PCT_EXCLAMATION, CTR_ENDLINE
};

// {waitinput}{end}{endline}
static s16 scenario_text_0D38[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE
};

// Address: @33f8

// You cannot just simply enter{newline}{endline}
static s16 scenario_text_0D55[] = {
    CHR_Y, CHR_o, CHR_u, PCT_SPACE, CHR_c, CHR_a, CHR_n, CHR_n, CHR_o, CHR_t,
    PCT_SPACE, CHR_j, CHR_u, CHR_s, CHR_t, PCT_SPACE, CHR_s, CHR_i, CHR_m, CHR_p,
    CHR_l, CHR_y, PCT_SPACE, CHR_e, CHR_n, CHR_t, CHR_e, CHR_r, CTR_NEWLINE, CTR_ENDLINE
};

// the {em-yellow}Dogo Hot Springs{/em} of [Iyo].{button}{endline}
static s16 scenario_text_0D87[] = {
    CHR_t, CHR_h, CHR_e, PCT_SPACE, CTR_EM_YELLOW, CHR_D, CHR_o, CHR_g, CHR_o, PCT_SPACE,
    CHR_H, CHR_o, CHR_t, PCT_SPACE, CHR_S, CHR_p, CHR_r, CHR_i, CHR_n, CHR_g,
    CHR_s, CTR_CLOSE_EM, PCT_SPACE, CHR_o, CHR_f, PCT_SPACE, PCT_LBRACKET, CHR_I, CHR_y, CHR_o,
    PCT_RBRACKET, PCT_PERIOD, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_0DCA[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// You must first obtain information{newline}{endline}
static s16 scenario_text_0DE2[] = {
    CHR_Y, CHR_o, CHR_u, PCT_SPACE, CHR_m, CHR_u, CHR_s, CHR_t, PCT_SPACE, CHR_f,
    CHR_i, CHR_r, CHR_s, CHR_t, PCT_SPACE, CHR_o, CHR_b, CHR_t, CHR_a, CHR_i,
    CHR_n, PCT_SPACE, CHR_i, CHR_n, CHR_f, CHR_o, CHR_r, CHR_m, CHR_a, CHR_t,
    CHR_i, CHR_o, CHR_n, CTR_NEWLINE, CTR_ENDLINE
};

// from the [{em-yellow}Iyo's Coffee Shop{/em}] at{newline}{endline}
static s16 scenario_text_0E19[] = {
    CHR_f, CHR_r, CHR_o, CHR_m, PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE, PCT_LBRACKET,
    CTR_EM_YELLOW, CHR_I, CHR_y, CHR_o, PCT_APOSTROPHE, CHR_s, PCT_SPACE, CHR_C, CHR_o, CHR_f,
    CHR_f, CHR_e, CHR_e, PCT_SPACE, CHR_S, CHR_h, CHR_o, CHR_p, CTR_CLOSE_EM, PCT_RBRACKET,
    PCT_SPACE, CHR_a, CHR_t, CTR_NEWLINE, CTR_ENDLINE
};

// {em-yellow}Dogo Hot Springs{/em}, plasma!{button}{endline}
static s16 scenario_text_0E5E[] = {
    CTR_EM_YELLOW, CHR_D, CHR_o, CHR_g, CHR_o, PCT_SPACE, CHR_H, CHR_o, CHR_t, PCT_SPACE,
    CHR_S, CHR_p, CHR_r, CHR_i, CHR_n, CHR_g, CHR_s, CTR_CLOSE_EM, PCT_COMMA, PCT_SPACE,
    CHR_p, CHR_l, CHR_a, CHR_s, CHR_m, CHR_a, PCT_EXCLAMATION, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_0E9C[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Also, it would be a good idea to{newline}{endline}
static s16 scenario_text_0EB4[] = {
    CHR_A, CHR_l, CHR_s, CHR_o, PCT_COMMA, PCT_SPACE, CHR_i, CHR_t, PCT_SPACE, CHR_w,
    CHR_o, CHR_u, CHR_l, CHR_d, PCT_SPACE, CHR_b, CHR_e, PCT_SPACE, CHR_a, PCT_SPACE,
    CHR_g, CHR_o, CHR_o, CHR_d, PCT_SPACE, CHR_i, CHR_d, CHR_e, CHR_a, PCT_SPACE,
    CHR_t, CHR_o, CTR_NEWLINE, CTR_ENDLINE
};

// first go to [{em-yellow}Mt. Kompira{/em}] to{newline}{endline}
static s16 scenario_text_0EEA[] = {
    CHR_f, CHR_i, CHR_r, CHR_s, CHR_t, PCT_SPACE, CHR_g, CHR_o, PCT_SPACE, CHR_t,
    CHR_o, PCT_SPACE, PCT_LBRACKET, CTR_EM_YELLOW, CHR_M, CHR_t, PCT_PERIOD, PCT_SPACE, CHR_K, CHR_o,
    CHR_m, CHR_p, CHR_i, CHR_r, CHR_a, CTR_CLOSE_EM, PCT_RBRACKET, PCT_SPACE, CHR_t, CHR_o,
    CTR_NEWLINE, CTR_ENDLINE
};

// worship, plasma.{endline}
static s16 scenario_text_0F2C[] = {
    CHR_w, CHR_o, CHR_r, CHR_s, CHR_h, CHR_i, CHR_p, PCT_COMMA, PCT_SPACE, CHR_p,
    CHR_l, CHR_a, CHR_s, CHR_m, CHR_a, PCT_PERIOD, CTR_ENDLINE
};

// {waitinput}{end}{endline}
static s16 scenario_text_0F49[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE
};

// Address: @3460

// Go to {em-yellow}Zazen Town{/em} in [Yamashiro]{newline}{endline}
static s16 scenario_text_0F66[] = {
    CHR_G, CHR_o, PCT_SPACE, CHR_t, CHR_o, PCT_SPACE, CTR_EM_YELLOW, CHR_Z, CHR_a, CHR_z,
    CHR_e, CHR_n, PCT_SPACE, CHR_T, CHR_o, CHR_w, CHR_n, CTR_CLOSE_EM, PCT_SPACE, CHR_i,
    CHR_n, PCT_SPACE, PCT_LBRACKET, CHR_Y, CHR_a, CHR_m, CHR_a, CHR_s, CHR_h, CHR_i,
    CHR_r, CHR_o, PCT_RBRACKET, CTR_NEWLINE, CTR_ENDLINE
};

// to meet the fish-loving{newline}{endline}
static s16 scenario_text_0FAB[] = {
    CHR_t, CHR_o, PCT_SPACE, CHR_m, CHR_e, CHR_e, CHR_t, PCT_SPACE, CHR_t, CHR_h,
    CHR_e, PCT_SPACE, CHR_f, CHR_i, CHR_s, CHR_h, PCT_DASH, CHR_l, CHR_o, CHR_v,
    CHR_i, CHR_n, CHR_g, CTR_NEWLINE, CTR_ENDLINE
};

// {em-yellow}lazy man{/em}, plasma!{endline}
static s16 scenario_text_0FD8[] = {
    CTR_EM_YELLOW, CHR_l, CHR_a, CHR_z, CHR_y, PCT_SPACE, CHR_m, CHR_a, CHR_n, CTR_CLOSE_EM,
    PCT_COMMA, PCT_SPACE, CHR_p, CHR_l, CHR_a, CHR_s, CHR_m, CHR_a, PCT_EXCLAMATION, CTR_ENDLINE
};

// {waitinput}{end}{endline}
static s16 scenario_text_1006[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE
};

// Address: @34a8

// With secret training at{newline}{endline}
static s16 scenario_text_1023[] = {
    CHR_W, CHR_i, CHR_t, CHR_h, PCT_SPACE, CHR_s, CHR_e, CHR_c, CHR_r, CHR_e,
    CHR_t, PCT_SPACE, CHR_t, CHR_r, CHR_a, CHR_i, CHR_n, CHR_i, CHR_n, CHR_g,
    PCT_SPACE, CHR_a, CHR_t, CTR_NEWLINE, CTR_ENDLINE
};

// the [{em-yellow}Golden Temple{/em}] in{newline}{endline}
static s16 scenario_text_1050[] = {
    CHR_t, CHR_h, CHR_e, PCT_SPACE, PCT_LBRACKET, CTR_EM_YELLOW, CHR_G, CHR_o, CHR_l, CHR_d,
    CHR_e, CHR_n, PCT_SPACE, CHR_T, CHR_e, CHR_m, CHR_p, CHR_l, CHR_e, CTR_CLOSE_EM,
    PCT_RBRACKET, PCT_SPACE, CHR_i, CHR_n, CTR_NEWLINE, CTR_ENDLINE
};

// Zazen Town, you could also{newline}{endline}
static s16 scenario_text_108C[] = {
    CHR_Z, CHR_a, CHR_z, CHR_e, CHR_n, PCT_SPACE, CHR_T, CHR_o, CHR_w, CHR_n,
    PCT_COMMA, PCT_SPACE, CHR_y, CHR_o, CHR_u, PCT_SPACE, CHR_c, CHR_o, CHR_u, CHR_l,
    CHR_d, PCT_SPACE, CHR_a, CHR_l, CHR_s, CHR_o, CTR_NEWLINE, CTR_ENDLINE
};

// become {em-yellow}smaller{/em}, plasma!{endline}
static s16 scenario_text_10BC[] = {
    CHR_b, CHR_e, CHR_c, CHR_o, CHR_m, CHR_e, PCT_SPACE, CTR_EM_YELLOW, CHR_s, CHR_m,
    CHR_a, CHR_l, CHR_l, CHR_e, CHR_r, CTR_CLOSE_EM, PCT_COMMA, PCT_SPACE, CHR_p, CHR_l,
    CHR_a, CHR_s, CHR_m, CHR_a, PCT_EXCLAMATION, CTR_ENDLINE
};

// {waitinput}{end}{endline}
static s16 scenario_text_10F0[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE
};

// Address: @34e0

// By making your body {em-yellow}smaller{/em},{newline}{endline}
static s16 scenario_text_110D[] = {
    CHR_B, CHR_y, PCT_SPACE, CHR_m, CHR_a, CHR_k, CHR_i, CHR_n, CHR_g, PCT_SPACE,
    CHR_y, CHR_o, CHR_u, CHR_r, PCT_SPACE, CHR_b, CHR_o, CHR_d, CHR_y, PCT_SPACE,
    CTR_EM_YELLOW, CHR_s, CHR_m, CHR_a, CHR_l, CHR_l, CHR_e, CHR_r, CTR_CLOSE_EM, PCT_COMMA,
    CTR_NEWLINE, CTR_ENDLINE
};

// you could enter {em-yellow}Dogo Hot Springs{/em}{newline}{endline}
static s16 scenario_text_114F[] = {
    CHR_y, CHR_o, CHR_u, PCT_SPACE, CHR_c, CHR_o, CHR_u, CHR_l, CHR_d, PCT_SPACE,
    CHR_e, CHR_n, CHR_t, CHR_e, CHR_r, PCT_SPACE, CTR_EM_YELLOW, CHR_D, CHR_o, CHR_g,
    CHR_o, PCT_SPACE, CHR_H, CHR_o, CHR_t, PCT_SPACE, CHR_S, CHR_p, CHR_r, CHR_i,
    CHR_n, CHR_g, CHR_s, CTR_CLOSE_EM, CTR_NEWLINE, CTR_ENDLINE
};

// of [Iyo] by sneaking through{newline}{endline}
static s16 scenario_text_1195[] = {
    CHR_o, CHR_f, PCT_SPACE, PCT_LBRACKET, CHR_I, CHR_y, CHR_o, PCT_RBRACKET, PCT_SPACE, CHR_b,
    CHR_y, PCT_SPACE, CHR_s, CHR_n, CHR_e, CHR_a, CHR_k, CHR_i, CHR_n, CHR_g,
    PCT_SPACE, CHR_t, CHR_h, CHR_r, CHR_o, CHR_u, CHR_g, CHR_h, CTR_NEWLINE, CTR_ENDLINE
};

// the {em-yellow}small hole{/em}, plasma!{endline}
static s16 scenario_text_11C7[] = {
    CHR_t, CHR_h, CHR_e, PCT_SPACE, CTR_EM_YELLOW, CHR_s, CHR_m, CHR_a, CHR_l, CHR_l,
    PCT_SPACE, CHR_h, CHR_o, CHR_l, CHR_e, CTR_CLOSE_EM, PCT_COMMA, PCT_SPACE, CHR_p, CHR_l,
    CHR_a, CHR_s, CHR_m, CHR_a, PCT_EXCLAMATION, CTR_ENDLINE
};

// {waitinput}{end}{endline}
static s16 scenario_text_11FB[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE
};

// Address: @3518

// The Chugoku Region to the {em-yellow}West{/em}{newline}{endline}
static s16 scenario_text_1218[] = {
    CHR_T, CHR_h, CHR_e, PCT_SPACE, CHR_C, CHR_h, CHR_u, CHR_g, CHR_o, CHR_k,
    CHR_u, PCT_SPACE, CHR_R, CHR_e, CHR_g, CHR_i, CHR_o, CHR_n, PCT_SPACE, CHR_t,
    CHR_o, PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE, CTR_EM_YELLOW, CHR_W, CHR_e, CHR_s,
    CHR_t, CTR_CLOSE_EM, CTR_NEWLINE, CTR_ENDLINE
};

// of Zazen Town in the caves of{newline}{endline}
static s16 scenario_text_125C[] = {
    CHR_o, CHR_f, PCT_SPACE, CHR_Z, CHR_a, CHR_z, CHR_e, CHR_n, PCT_SPACE, CHR_T,
    CHR_o, CHR_w, CHR_n, PCT_SPACE, CHR_i, CHR_n, PCT_SPACE, CHR_t, CHR_h, CHR_e,
    PCT_SPACE, CHR_c, CHR_a, CHR_v, CHR_e, CHR_s, PCT_SPACE, CHR_o, CHR_f, CTR_NEWLINE,
    CTR_ENDLINE
};

// {em-yellow}Akiyoshidai{/em} found in this region,{newline}{endline}
static s16 scenario_text_128F[] = {
    CTR_EM_YELLOW, CHR_A, CHR_k, CHR_i, CHR_y, CHR_o, CHR_s, CHR_h, CHR_i, CHR_d,
    CHR_a, CHR_i, CTR_CLOSE_EM, PCT_SPACE, CHR_f, CHR_o, CHR_u, CHR_n, CHR_d, PCT_SPACE,
    CHR_i, CHR_n, PCT_SPACE, CHR_t, CHR_h, CHR_i, CHR_s, PCT_SPACE, CHR_r, CHR_e,
    CHR_g, CHR_i, CHR_o, CHR_n, PCT_COMMA, CTR_NEWLINE, CTR_ENDLINE
};

// you will find a {em-yellow}cracked door{/em}.{button}{endline}
static s16 scenario_text_12D6[] = {
    CHR_y, CHR_o, CHR_u, PCT_SPACE, CHR_w, CHR_i, CHR_l, CHR_l, PCT_SPACE, CHR_f,
    CHR_i, CHR_n, CHR_d, PCT_SPACE, CHR_a, PCT_SPACE, CTR_EM_YELLOW, CHR_c, CHR_r, CHR_a,
    CHR_c, CHR_k, CHR_e, CHR_d, PCT_SPACE, CHR_d, CHR_o, CHR_o, CHR_r, CTR_CLOSE_EM,
    PCT_PERIOD, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_1318[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// To open this door, you must{newline}{endline}
static s16 scenario_text_1330[] = {
    CHR_T, CHR_o, PCT_SPACE, CHR_o, CHR_p, CHR_e, CHR_n, PCT_SPACE, CHR_t, CHR_h,
    CHR_i, CHR_s, PCT_SPACE, CHR_d, CHR_o, CHR_o, CHR_r, PCT_COMMA, PCT_SPACE, CHR_y,
    CHR_o, CHR_u, PCT_SPACE, CHR_m, CHR_u, CHR_s, CHR_t, CTR_NEWLINE, CTR_ENDLINE
};

// revive [{em-yellow}Sasuke{/em}], for his expertise{newline}{endline}
static s16 scenario_text_1361[] = {
    CHR_r, CHR_e, CHR_v, CHR_i, CHR_v, CHR_e, PCT_SPACE, PCT_LBRACKET, CTR_EM_YELLOW, CHR_S,
    CHR_a, CHR_s, CHR_u, CHR_k, CHR_e, CTR_CLOSE_EM, PCT_RBRACKET, PCT_COMMA, PCT_SPACE, CHR_f,
    CHR_o, CHR_r, PCT_SPACE, CHR_h, CHR_i, CHR_s, PCT_SPACE, CHR_e, CHR_x, CHR_p,
    CHR_e, CHR_r, CHR_t, CHR_i, CHR_s, CHR_e, CTR_NEWLINE, CTR_ENDLINE
};

// in the use of {em-yellow}bombs{/em}, plasma!{button}{endline}
static s16 scenario_text_13A9[] = {
    CHR_i, CHR_n, PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE, CHR_u, CHR_s, CHR_e,
    PCT_SPACE, CHR_o, CHR_f, PCT_SPACE, CTR_EM_YELLOW, CHR_b, CHR_o, CHR_m, CHR_b, CHR_s,
    CTR_CLOSE_EM, PCT_COMMA, PCT_SPACE, CHR_p, CHR_l, CHR_a, CHR_s, CHR_m, CHR_a, PCT_EXCLAMATION,
    CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_13EA[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// It is time to resurrect [{em-yellow}Sasuke{/em}],{newline}{endline}
static s16 scenario_text_1402[] = {
    CHR_I, CHR_t, PCT_SPACE, CHR_i, CHR_s, PCT_SPACE, CHR_t, CHR_i, CHR_m, CHR_e,
    PCT_SPACE, CHR_t, CHR_o, PCT_SPACE, CHR_r, CHR_e, CHR_s, CHR_u, CHR_r, CHR_r,
    CHR_e, CHR_c, CHR_t, PCT_SPACE, PCT_LBRACKET, CTR_EM_YELLOW, CHR_S, CHR_a, CHR_s, CHR_u,
    CHR_k, CHR_e, CTR_CLOSE_EM, PCT_RBRACKET, PCT_COMMA, CTR_NEWLINE, CTR_ENDLINE
};

// the {em-yellow}Mechanical Ninja{/em}, plasma!{endline}
static s16 scenario_text_1449[] = {
    CHR_t, CHR_h, CHR_e, PCT_SPACE, CTR_EM_YELLOW, CHR_M, CHR_e, CHR_c, CHR_h, CHR_a,
    CHR_n, CHR_i, CHR_c, CHR_a, CHR_l, PCT_SPACE, CHR_N, CHR_i, CHR_n, CHR_j,
    CHR_a, CTR_CLOSE_EM, PCT_COMMA, PCT_SPACE, CHR_p, CHR_l, CHR_a, CHR_s, CHR_m, CHR_a,
    PCT_EXCLAMATION, CTR_ENDLINE
};

// {waitinput}{end}{endline}
static s16 scenario_text_1483[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE
};

// Address: @35b4

// You will obtain a clue by {newline}{endline}
static s16 scenario_text_14A0[] = {
    CHR_Y, CHR_o, CHR_u, PCT_SPACE, CHR_w, CHR_i, CHR_l, CHR_l, PCT_SPACE, CHR_o,
    CHR_b, CHR_t, CHR_a, CHR_i, CHR_n, PCT_SPACE, CHR_a, PCT_SPACE, CHR_c, CHR_l,
    CHR_u, CHR_e, PCT_SPACE, CHR_b, CHR_y, PCT_SPACE, CTR_NEWLINE, CTR_ENDLINE
};

// going to [{em-yellow}Izumo's Coffee Shop{/em}] {newline}{endline}
static s16 scenario_text_14D0[] = {
    CHR_g, CHR_o, CHR_i, CHR_n, CHR_g, PCT_SPACE, CHR_t, CHR_o, PCT_SPACE, PCT_LBRACKET,
    CTR_EM_YELLOW, CHR_I, CHR_z, CHR_u, CHR_m, CHR_o, PCT_APOSTROPHE, CHR_s, PCT_SPACE, CHR_C,
    CHR_o, CHR_f, CHR_f, CHR_e, CHR_e, PCT_SPACE, CHR_S, CHR_h, CHR_o, CHR_p,
    CTR_CLOSE_EM, PCT_RBRACKET, PCT_SPACE, CTR_NEWLINE, CTR_ENDLINE
};

// in the Chugoku Region, plasma!{endline}
static s16 scenario_text_1515[] = {
    CHR_i, CHR_n, PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE, CHR_C, CHR_h, CHR_u,
    CHR_g, CHR_o, CHR_k, CHR_u, PCT_SPACE, CHR_R, CHR_e, CHR_g, CHR_i, CHR_o,
    CHR_n, PCT_COMMA, PCT_SPACE, CHR_p, CHR_l, CHR_a, CHR_s, CHR_m, CHR_a, PCT_EXCLAMATION,
    CTR_ENDLINE
};

// {waitinput}{end}{endline}
static s16 scenario_text_1540[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE
};

// Address: @35d8

// The [{em-yellow}Dune of Inaba{/em}], {newline}{endline}
static s16 scenario_text_155D[] = {
    CHR_T, CHR_h, CHR_e, PCT_SPACE, PCT_LBRACKET, CTR_EM_YELLOW, CHR_D, CHR_u, CHR_n, CHR_e,
    PCT_SPACE, CHR_o, CHR_f, PCT_SPACE, CHR_I, CHR_n, CHR_a, CHR_b, CHR_a, CTR_CLOSE_EM,
    PCT_RBRACKET, PCT_COMMA, PCT_SPACE, CTR_NEWLINE, CTR_ENDLINE
};

// to the {em-yellow}East{/em} of [Izumo].{button}{endline}
static s16 scenario_text_1598[] = {
    CHR_t, CHR_o, PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE, CTR_EM_YELLOW, CHR_E, CHR_a,
    CHR_s, CHR_t, CTR_CLOSE_EM, PCT_SPACE, CHR_o, CHR_f, PCT_SPACE, PCT_LBRACKET, CHR_I, CHR_z,
    CHR_u, CHR_m, CHR_o, PCT_RBRACKET, PCT_PERIOD, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_15D4[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// There is something floating on{newline}{endline}
static s16 scenario_text_15EC[] = {
    CHR_T, CHR_h, CHR_e, CHR_r, CHR_e, PCT_SPACE, CHR_i, CHR_s, PCT_SPACE, CHR_s,
    CHR_o, CHR_m, CHR_e, CHR_t, CHR_h, CHR_i, CHR_n, CHR_g, PCT_SPACE, CHR_f,
    CHR_l, CHR_o, CHR_a, CHR_t, CHR_i, CHR_n, CHR_g, PCT_SPACE, CHR_o, CHR_n,
    CTR_NEWLINE, CTR_ENDLINE
};

// the {em-yellow}oasis{/em}, plasma.{button}{endline}
static s16 scenario_text_1620[] = {
    CHR_t, CHR_h, CHR_e, PCT_SPACE, CTR_EM_YELLOW, CHR_o, CHR_a, CHR_s, CHR_i, CHR_s,
    CTR_CLOSE_EM, PCT_COMMA, PCT_SPACE, CHR_p, CHR_l, CHR_a, CHR_s, CHR_m, CHR_a, PCT_PERIOD,
    CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_1657[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// It is something vitally needed to{newline}{endline}
static s16 scenario_text_166F[] = {
    CHR_I, CHR_t, PCT_SPACE, CHR_i, CHR_s, PCT_SPACE, CHR_s, CHR_o, CHR_m, CHR_e,
    CHR_t, CHR_h, CHR_i, CHR_n, CHR_g, PCT_SPACE, CHR_v, CHR_i, CHR_t, CHR_a,
    CHR_l, CHR_l, CHR_y, PCT_SPACE, CHR_n, CHR_e, CHR_e, CHR_d, CHR_e, CHR_d,
    PCT_SPACE, CHR_t, CHR_o, CTR_NEWLINE, CTR_ENDLINE
};

// resurrect {em-yellow}Sasuke{/em}, plasma!{button}{endline}
static s16 scenario_text_16A6[] = {
    CHR_r, CHR_e, CHR_s, CHR_u, CHR_r, CHR_r, CHR_e, CHR_c, CHR_t, PCT_SPACE,
    CTR_EM_YELLOW, CHR_S, CHR_a, CHR_s, CHR_u, CHR_k, CHR_e, CTR_CLOSE_EM, PCT_COMMA, PCT_SPACE,
    CHR_p, CHR_l, CHR_a, CHR_s, CHR_m, CHR_a, PCT_EXCLAMATION, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_16E4[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// You shall go there, plasma!{endline}
static s16 scenario_text_16FC[] = {
    CHR_Y, CHR_o, CHR_u, PCT_SPACE, CHR_s, CHR_h, CHR_a, CHR_l, CHR_l, PCT_SPACE,
    CHR_g, CHR_o, PCT_SPACE, CHR_t, CHR_h, CHR_e, CHR_r, CHR_e, PCT_COMMA, PCT_SPACE,
    CHR_p, CHR_l, CHR_a, CHR_s, CHR_m, CHR_a, PCT_EXCLAMATION, CTR_ENDLINE
};

// {waitinput}{end}{endline}
static s16 scenario_text_1724[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE
};

// Address: @3640

// The big tree behind{newline}{endline}
static s16 scenario_text_1741[] = {
    CHR_T, CHR_h, CHR_e, PCT_SPACE, CHR_b, CHR_i, CHR_g, PCT_SPACE, CHR_t, CHR_r,
    CHR_e, CHR_e, PCT_SPACE, CHR_b, CHR_e, CHR_h, CHR_i, CHR_n, CHR_d, CTR_NEWLINE,
    CTR_ENDLINE
};

// the [{em-yellow}Izumo Shrine{/em}] on the {em-yellow}summit{/em}{newline}{endline}
static s16 scenario_text_176A[] = {
    CHR_t, CHR_h, CHR_e, PCT_SPACE, PCT_LBRACKET, CTR_EM_YELLOW, CHR_I, CHR_z, CHR_u, CHR_m,
    CHR_o, PCT_SPACE, CHR_S, CHR_h, CHR_r, CHR_i, CHR_n, CHR_e, CTR_CLOSE_EM, PCT_RBRACKET,
    PCT_SPACE, CHR_o, CHR_n, PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE, CTR_EM_YELLOW, CHR_s,
    CHR_u, CHR_m, CHR_m, CHR_i, CHR_t, CTR_CLOSE_EM, CTR_NEWLINE, CTR_ENDLINE
};

// of the mountain of Izumo.{button}{endline}
static s16 scenario_text_17C0[] = {
    CHR_o, CHR_f, PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE, CHR_m, CHR_o, CHR_u,
    CHR_n, CHR_t, CHR_a, CHR_i, CHR_n, PCT_SPACE, CHR_o, CHR_f, PCT_SPACE, CHR_I,
    CHR_z, CHR_u, CHR_m, CHR_o, PCT_PERIOD, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_17EE[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// That's where you will find{newline}{endline}
static s16 scenario_text_1806[] = {
    CHR_T, CHR_h, CHR_a, CHR_t, PCT_APOSTROPHE, CHR_s, PCT_SPACE, CHR_w, CHR_h, CHR_e,
    CHR_r, CHR_e, PCT_SPACE, CHR_y, CHR_o, CHR_u, PCT_SPACE, CHR_w, CHR_i, CHR_l,
    CHR_l, PCT_SPACE, CHR_f, CHR_i, CHR_n, CHR_d, CTR_NEWLINE, CTR_ENDLINE
};

// something shining!{button}{endline}
static s16 scenario_text_1836[] = {
    CHR_s, CHR_o, CHR_m, CHR_e, CHR_t, CHR_h, CHR_i, CHR_n, CHR_g, PCT_SPACE,
    CHR_s, CHR_h, CHR_i, CHR_n, CHR_i, CHR_n, CHR_g, PCT_EXCLAMATION, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_185D[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// To find out what it is,{newline}{endline}
static s16 scenario_text_1875[] = {
    CHR_T, CHR_o, PCT_SPACE, CHR_f, CHR_i, CHR_n, CHR_d, PCT_SPACE, CHR_o, CHR_u,
    CHR_t, PCT_SPACE, CHR_w, CHR_h, CHR_a, CHR_t, PCT_SPACE, CHR_i, CHR_t, PCT_SPACE,
    CHR_i, CHR_s, PCT_COMMA, CTR_NEWLINE, CTR_ENDLINE
};

// aim your {em-yellow}windup camera{/em} at{newline}{endline}
static s16 scenario_text_18A2[] = {
    CHR_a, CHR_i, CHR_m, PCT_SPACE, CHR_y, CHR_o, CHR_u, CHR_r, PCT_SPACE, CTR_EM_YELLOW,
    CHR_w, CHR_i, CHR_n, CHR_d, CHR_u, CHR_p, PCT_SPACE, CHR_c, CHR_a, CHR_m,
    CHR_e, CHR_r, CHR_a, CTR_CLOSE_EM, PCT_SPACE, CHR_a, CHR_t, CTR_NEWLINE, CTR_ENDLINE
};

// the [{em-yellow}Tree{/em}] and take a picture,{newline}{endline}
static s16 scenario_text_18E1[] = {
    CHR_t, CHR_h, CHR_e, PCT_SPACE, PCT_LBRACKET, CTR_EM_YELLOW, CHR_T, CHR_r, CHR_e, CHR_e,
    CTR_CLOSE_EM, PCT_RBRACKET, PCT_SPACE, CHR_a, CHR_n, CHR_d, PCT_SPACE, CHR_t, CHR_a, CHR_k,
    CHR_e, PCT_SPACE, CHR_a, PCT_SPACE, CHR_p, CHR_i, CHR_c, CHR_t, CHR_u, CHR_r,
    CHR_e, PCT_COMMA, CTR_NEWLINE, CTR_ENDLINE
};

// plasma!{endline}
static s16 scenario_text_1925[] = {
    CHR_p, CHR_l, CHR_a, CHR_s, CHR_m, CHR_a, PCT_EXCLAMATION, CTR_ENDLINE
};

// {waitinput}{end}{endline}
static s16 scenario_text_1939[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE
};

// Address: @36b0

// Destroy the {em-yellow}cracked door{/em} found{newline}{endline}
static s16 scenario_text_1956[] = {
    CHR_D, CHR_e, CHR_s, CHR_t, CHR_r, CHR_o, CHR_y, PCT_SPACE, CHR_t, CHR_h,
    CHR_e, PCT_SPACE, CTR_EM_YELLOW, CHR_c, CHR_r, CHR_a, CHR_c, CHR_k, CHR_e, CHR_d,
    PCT_SPACE, CHR_d, CHR_o, CHR_o, CHR_r, CTR_CLOSE_EM, PCT_SPACE, CHR_f, CHR_o, CHR_u,
    CHR_n, CHR_d, CTR_NEWLINE, CTR_ENDLINE
};

// in the caves of [Akiyoshidai] by{newline}{endline}
static s16 scenario_text_199A[] = {
    CHR_i, CHR_n, PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE, CHR_c, CHR_a, CHR_v,
    CHR_e, CHR_s, PCT_SPACE, CHR_o, CHR_f, PCT_SPACE, PCT_LBRACKET, CHR_A, CHR_k, CHR_i,
    CHR_y, CHR_o, CHR_s, CHR_h, CHR_i, CHR_d, CHR_a, CHR_i, PCT_RBRACKET, PCT_SPACE,
    CHR_b, CHR_y, CTR_NEWLINE, CTR_ENDLINE
};

// using a {em-yellow}Fire Cracker Bomb{/em}, plasma!{endline}
static s16 scenario_text_19D0[] = {
    CHR_u, CHR_s, CHR_i, CHR_n, CHR_g, PCT_SPACE, CHR_a, PCT_SPACE, CTR_EM_YELLOW, CHR_F,
    CHR_i, CHR_r, CHR_e, PCT_SPACE, CHR_C, CHR_r, CHR_a, CHR_c, CHR_k, CHR_e,
    CHR_r, PCT_SPACE, CHR_B, CHR_o, CHR_m, CHR_b, CTR_CLOSE_EM, PCT_COMMA, PCT_SPACE, CHR_p,
    CHR_l, CHR_a, CHR_s, CHR_m, CHR_a, PCT_EXCLAMATION, CTR_ENDLINE
};

// {waitinput}{end}{endline}
static s16 scenario_text_1A0F[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE
};

// Address: @36e0

// Go to [{em-yellow}Kyushu{/em}] at once!{newline}{endline}
static s16 scenario_text_1A2C[] = {
    CHR_G, CHR_o, PCT_SPACE, CHR_t, CHR_o, PCT_SPACE, PCT_LBRACKET, CTR_EM_YELLOW, CHR_K, CHR_y,
    CHR_u, CHR_s, CHR_h, CHR_u, CTR_CLOSE_EM, PCT_RBRACKET, PCT_SPACE, CHR_a, CHR_t, PCT_SPACE,
    CHR_o, CHR_n, CHR_c, CHR_e, PCT_EXCLAMATION, CTR_NEWLINE, CTR_ENDLINE
};

// Head {em-yellow}west{/em}, head {em-yellow}west{/em}, plasma!{newline}{endline}
static s16 scenario_text_1A69[] = {
    CHR_H, CHR_e, CHR_a, CHR_d, PCT_SPACE, CTR_EM_YELLOW, CHR_w, CHR_e, CHR_s, CHR_t,
    CTR_CLOSE_EM, PCT_COMMA, PCT_SPACE, CHR_h, CHR_e, CHR_a, CHR_d, PCT_SPACE, CTR_EM_YELLOW, CHR_w,
    CHR_e, CHR_s, CHR_t, CTR_CLOSE_EM, PCT_COMMA, PCT_SPACE, CHR_p, CHR_l, CHR_a, CHR_s,
    CHR_m, CHR_a, PCT_EXCLAMATION, CTR_NEWLINE, CTR_ENDLINE
};

// {waitinput}{end}{endline}
static s16 scenario_text_1ABC[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE
};

// Address: @3708

// In a cold region to your {em-yellow}North{/em},{newline}{endline}
static s16 scenario_text_1AD9[] = {
    CHR_I, CHR_n, PCT_SPACE, CHR_a, PCT_SPACE, CHR_c, CHR_o, CHR_l, CHR_d, PCT_SPACE,
    CHR_r, CHR_e, CHR_g, CHR_i, CHR_o, CHR_n, PCT_SPACE, CHR_t, CHR_o, PCT_SPACE,
    CHR_y, CHR_o, CHR_u, CHR_r, PCT_SPACE, CTR_EM_YELLOW, CHR_N, CHR_o, CHR_r, CHR_t,
    CHR_h, CTR_CLOSE_EM, PCT_COMMA, CTR_NEWLINE, CTR_ENDLINE
};

// there is the [{em-yellow}Mt. Fear{/em}], where{newline}{endline}
static s16 scenario_text_1B1E[] = {
    CHR_t, CHR_h, CHR_e, CHR_r, CHR_e, PCT_SPACE, CHR_i, CHR_s, PCT_SPACE, CHR_t,
    CHR_h, CHR_e, PCT_SPACE, PCT_LBRACKET, CTR_EM_YELLOW, CHR_M, CHR_t, PCT_PERIOD, PCT_SPACE, CHR_F,
    CHR_e, CHR_a, CHR_r, CTR_CLOSE_EM, PCT_RBRACKET, PCT_COMMA, PCT_SPACE, CHR_w, CHR_h, CHR_e,
    CHR_r, CHR_e, CTR_NEWLINE, CTR_ENDLINE
};

// it snows!{button}{endline}
static s16 scenario_text_1B62[] = {
    CHR_i, CHR_t, PCT_SPACE, CHR_s, CHR_n, CHR_o, CHR_w, CHR_s, PCT_EXCLAMATION, CTR_BUTTON,
    CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_1B80[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// There, you shall meet someone{newline}{endline}
static s16 scenario_text_1B98[] = {
    CHR_T, CHR_h, CHR_e, CHR_r, CHR_e, PCT_COMMA, PCT_SPACE, CHR_y, CHR_o, CHR_u,
    PCT_SPACE, CHR_s, CHR_h, CHR_a, CHR_l, CHR_l, PCT_SPACE, CHR_m, CHR_e, CHR_e,
    CHR_t, PCT_SPACE, CHR_s, CHR_o, CHR_m, CHR_e, CHR_o, CHR_n, CHR_e, CTR_NEWLINE,
    CTR_ENDLINE
};

// who will be of great help to you,{newline}{endline}
static s16 scenario_text_1BCB[] = {
    CHR_w, CHR_h, CHR_o, PCT_SPACE, CHR_w, CHR_i, CHR_l, CHR_l, PCT_SPACE, CHR_b,
    CHR_e, PCT_SPACE, CHR_o, CHR_f, PCT_SPACE, CHR_g, CHR_r, CHR_e, CHR_a, CHR_t,
    PCT_SPACE, CHR_h, CHR_e, CHR_l, CHR_p, PCT_SPACE, CHR_t, CHR_o, PCT_SPACE, CHR_y,
    CHR_o, CHR_u, PCT_COMMA, CTR_NEWLINE, CTR_ENDLINE
};

// plasma!{button}{endline}
static s16 scenario_text_1C02[] = {
    CHR_p, CHR_l, CHR_a, CHR_s, CHR_m, CHR_a, PCT_EXCLAMATION, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_1C1E[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

//   {newline}{endline}
static s16 scenario_text_1C36[] = {
    PCT_SPACE, PCT_SPACE, CTR_NEWLINE, CTR_ENDLINE
};

//     {em-yellow}{big}H O W E V E R ! {/big}{/em}{button}{endline}
static s16 scenario_text_1C4E[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CTR_EM_YELLOW, CTR_BIG, CHR_H, PCT_SPACE, CHR_O, PCT_SPACE,
    CHR_W, PCT_SPACE, CHR_E, PCT_SPACE, CHR_V, PCT_SPACE, CHR_E, PCT_SPACE, CHR_R, PCT_SPACE,
    PCT_EXCLAMATION, PCT_SPACE, CTR_CLOSE_BIG, CTR_CLOSE_EM, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_1C92[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// You must first go to [{em-yellow}Oedo Town{/em}]{newline}{endline}
static s16 scenario_text_1CAA[] = {
    CHR_Y, CHR_o, CHR_u, PCT_SPACE, CHR_m, CHR_u, CHR_s, CHR_t, PCT_SPACE, CHR_f,
    CHR_i, CHR_r, CHR_s, CHR_t, PCT_SPACE, CHR_g, CHR_o, PCT_SPACE, CHR_t, CHR_o,
    PCT_SPACE, PCT_LBRACKET, CTR_EM_YELLOW, CHR_O, CHR_e, CHR_d, CHR_o, PCT_SPACE, CHR_T, CHR_o,
    CHR_w, CHR_n, CTR_CLOSE_EM, PCT_RBRACKET, CTR_NEWLINE, CTR_ENDLINE
};

// to undergo one training session,{newline}{endline}
static s16 scenario_text_1CF0[] = {
    CHR_t, CHR_o, PCT_SPACE, CHR_u, CHR_n, CHR_d, CHR_e, CHR_r, CHR_g, CHR_o,
    PCT_SPACE, CHR_o, CHR_n, CHR_e, PCT_SPACE, CHR_t, CHR_r, CHR_a, CHR_i, CHR_n,
    CHR_i, CHR_n, CHR_g, PCT_SPACE, CHR_s, CHR_e, CHR_s, CHR_s, CHR_i, CHR_o,
    CHR_n, PCT_COMMA, CTR_NEWLINE, CTR_ENDLINE
};

// plasma!{endline}
static s16 scenario_text_1D26[] = {
    CHR_p, CHR_l, CHR_a, CHR_s, CHR_m, CHR_a, PCT_EXCLAMATION, CTR_ENDLINE
};

// {waitinput}{end}{endline}
static s16 scenario_text_1D3A[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE
};

// Address: @37b4

// Go to the {em-yellow}Goemon tenement{/em}{newline}{endline}
static s16 scenario_text_1D57[] = {
    CHR_G, CHR_o, PCT_SPACE, CHR_t, CHR_o, PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE,
    CTR_EM_YELLOW, CHR_G, CHR_o, CHR_e, CHR_m, CHR_o, CHR_n, PCT_SPACE, CHR_t, CHR_e,
    CHR_n, CHR_e, CHR_m, CHR_e, CHR_n, CHR_t, CTR_CLOSE_EM, CTR_NEWLINE, CTR_ENDLINE
};

// in [{em-yellow}Oedo Town{/em}], plasma!{button}{endline}
static s16 scenario_text_1D96[] = {
    CHR_i, CHR_n, PCT_SPACE, PCT_LBRACKET, CTR_EM_YELLOW, CHR_O, CHR_e, CHR_d, CHR_o, PCT_SPACE,
    CHR_T, CHR_o, CHR_w, CHR_n, CTR_CLOSE_EM, PCT_RBRACKET, PCT_COMMA, PCT_SPACE, CHR_p, CHR_l,
    CHR_a, CHR_s, CHR_m, CHR_a, PCT_EXCLAMATION, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_1DD2[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// There awaits the [{em-yellow}Training{/em}] that{newline}{endline}
static s16 scenario_text_1DEA[] = {
    CHR_T, CHR_h, CHR_e, CHR_r, CHR_e, PCT_SPACE, CHR_a, CHR_w, CHR_a, CHR_i,
    CHR_t, CHR_s, PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE, PCT_LBRACKET, CTR_EM_YELLOW, CHR_T,
    CHR_r, CHR_a, CHR_i, CHR_n, CHR_i, CHR_n, CHR_g, CTR_CLOSE_EM, PCT_RBRACKET, PCT_SPACE,
    CHR_t, CHR_h, CHR_a, CHR_t, CTR_NEWLINE, CTR_ENDLINE
};

// you must undertake, plasma!{endline}
static s16 scenario_text_1E30[] = {
    CHR_y, CHR_o, CHR_u, PCT_SPACE, CHR_m, CHR_u, CHR_s, CHR_t, PCT_SPACE, CHR_u,
    CHR_n, CHR_d, CHR_e, CHR_r, CHR_t, CHR_a, CHR_k, CHR_e, PCT_COMMA, PCT_SPACE,
    CHR_p, CHR_l, CHR_a, CHR_s, CHR_m, CHR_a, PCT_EXCLAMATION, CTR_ENDLINE
};

// {waitinput}{end}{endline}
static s16 scenario_text_1E58[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE
};

// Address: @37e8

// Use the magic power of{newline}{endline}
static s16 scenario_text_1E75[] = {
    CHR_U, CHR_s, CHR_e, PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE, CHR_m, CHR_a,
    CHR_g, CHR_i, CHR_c, PCT_SPACE, CHR_p, CHR_o, CHR_w, CHR_e, CHR_r, PCT_SPACE,
    CHR_o, CHR_f, CTR_NEWLINE, CTR_ENDLINE
};

// {em-yellow}Sudden Impact{/em} to move{newline}{endline}
static s16 scenario_text_1EA1[] = {
    CTR_EM_YELLOW, CHR_S, CHR_u, CHR_d, CHR_d, CHR_e, CHR_n, PCT_SPACE, CHR_I, CHR_m,
    CHR_p, CHR_a, CHR_c, CHR_t, CTR_CLOSE_EM, PCT_SPACE, CHR_t, CHR_o, PCT_SPACE, CHR_m,
    CHR_o, CHR_v, CHR_e, CTR_NEWLINE, CTR_ENDLINE
};

// the {em-yellow}Metal Box{/em} located on the {em-yellow}east{/em}{newline}{endline}
static s16 scenario_text_1EDC[] = {
    CHR_t, CHR_h, CHR_e, PCT_SPACE, CTR_EM_YELLOW, CHR_M, CHR_e, CHR_t, CHR_a, CHR_l,
    PCT_SPACE, CHR_B, CHR_o, CHR_x, CTR_CLOSE_EM, PCT_SPACE, CHR_l, CHR_o, CHR_c, CHR_a,
    CHR_t, CHR_e, CHR_d, PCT_SPACE, CHR_o, CHR_n, PCT_SPACE, CHR_t, CHR_h, CHR_e,
    PCT_SPACE, CTR_EM_YELLOW, CHR_e, CHR_a, CHR_s, CHR_t, CTR_CLOSE_EM, CTR_NEWLINE, CTR_ENDLINE
};

// cliff of [Musashi],{button}{endline}
static s16 scenario_text_1F33[] = {
    CHR_c, CHR_l, CHR_i, CHR_f, CHR_f, PCT_SPACE, CHR_o, CHR_f, PCT_SPACE, PCT_LBRACKET,
    CHR_M, CHR_u, CHR_s, CHR_a, CHR_s, CHR_h, CHR_i, PCT_RBRACKET, PCT_COMMA, CTR_BUTTON,
    CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_1F5B[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// past the gates to{newline}{endline}
static s16 scenario_text_1F73[] = {
    CHR_p, CHR_a, CHR_s, CHR_t, PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE, CHR_g,
    CHR_a, CHR_t, CHR_e, CHR_s, PCT_SPACE, CHR_t, CHR_o, CTR_NEWLINE, CTR_ENDLINE
};

// [Oedo Town], plasma!{button}{endline}
static s16 scenario_text_1F9A[] = {
    PCT_LBRACKET, CHR_O, CHR_e, CHR_d, CHR_o, PCT_SPACE, CHR_T, CHR_o, CHR_w, CHR_n,
    PCT_RBRACKET, PCT_COMMA, PCT_SPACE, CHR_p, CHR_l, CHR_a, CHR_s, CHR_m, CHR_a, PCT_EXCLAMATION,
    CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_1FC3[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Then, far way to the [{em-yellow}North{/em}],{newline}{endline}
static s16 scenario_text_1FDB[] = {
    CHR_T, CHR_h, CHR_e, CHR_n, PCT_COMMA, PCT_SPACE, CHR_f, CHR_a, CHR_r, PCT_SPACE,
    CHR_w, CHR_a, CHR_y, PCT_SPACE, CHR_t, CHR_o, PCT_SPACE, CHR_t, CHR_h, CHR_e,
    PCT_SPACE, PCT_LBRACKET, CTR_EM_YELLOW, CHR_N, CHR_o, CHR_r, CHR_t, CHR_h, CTR_CLOSE_EM, PCT_RBRACKET,
    PCT_COMMA, CTR_NEWLINE, CTR_ENDLINE
};

// at [{em-yellow}Mt. Fear{/em}], you shall meet{newline}{endline}
static s16 scenario_text_201E[] = {
    CHR_a, CHR_t, PCT_SPACE, PCT_LBRACKET, CTR_EM_YELLOW, CHR_M, CHR_t, PCT_PERIOD, PCT_SPACE, CHR_F,
    CHR_e, CHR_a, CHR_r, CTR_CLOSE_EM, PCT_RBRACKET, PCT_COMMA, PCT_SPACE, CHR_y, CHR_o, CHR_u,
    PCT_SPACE, CHR_s, CHR_h, CHR_a, CHR_l, CHR_l, PCT_SPACE, CHR_m, CHR_e, CHR_e,
    CHR_t, CTR_NEWLINE, CTR_ENDLINE
};

// {em-yellow}someone{/em} who'd be of great help{newline}{endline}
static s16 scenario_text_2061[] = {
    CTR_EM_YELLOW, CHR_s, CHR_o, CHR_m, CHR_e, CHR_o, CHR_n, CHR_e, CTR_CLOSE_EM, PCT_SPACE,
    CHR_w, CHR_h, CHR_o, PCT_APOSTROPHE, CHR_d, PCT_SPACE, CHR_b, CHR_e, PCT_SPACE, CHR_o,
    CHR_f, PCT_SPACE, CHR_g, CHR_r, CHR_e, CHR_a, CHR_t, PCT_SPACE, CHR_h, CHR_e,
    CHR_l, CHR_p, CTR_NEWLINE, CTR_ENDLINE
};

// to you, plasma!{endline}
static s16 scenario_text_20A5[] = {
    CHR_t, CHR_o, PCT_SPACE, CHR_y, CHR_o, CHR_u, PCT_COMMA, PCT_SPACE, CHR_p, CHR_l,
    CHR_a, CHR_s, CHR_m, CHR_a, PCT_EXCLAMATION, CTR_ENDLINE
};

// {waitinput}{end}{endline}
static s16 scenario_text_20C1[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE
};

// Address: @3860

// If you are to climb [Mt. Fear],{newline}{endline}
static s16 scenario_text_20DE[] = {
    CHR_I, CHR_f, PCT_SPACE, CHR_y, CHR_o, CHR_u, PCT_SPACE, CHR_a, CHR_r, CHR_e,
    PCT_SPACE, CHR_t, CHR_o, PCT_SPACE, CHR_c, CHR_l, CHR_i, CHR_m, CHR_b, PCT_SPACE,
    PCT_LBRACKET, CHR_M, CHR_t, PCT_PERIOD, PCT_SPACE, CHR_F, CHR_e, CHR_a, CHR_r, PCT_RBRACKET,
    PCT_COMMA, CTR_NEWLINE, CTR_ENDLINE
};

// you must first increase the power{newline}{endline}
static s16 scenario_text_2113[] = {
    CHR_y, CHR_o, CHR_u, PCT_SPACE, CHR_m, CHR_u, CHR_s, CHR_t, PCT_SPACE, CHR_f,
    CHR_i, CHR_r, CHR_s, CHR_t, PCT_SPACE, CHR_i, CHR_n, CHR_c, CHR_r, CHR_e,
    CHR_a, CHR_s, CHR_e, PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE, CHR_p, CHR_o,
    CHR_w, CHR_e, CHR_r, CTR_NEWLINE, CTR_ENDLINE
};

// of your {em-yellow}weapons{/em} to a {em-yellow}higher level{/em},{newline}{endline}
static s16 scenario_text_214A[] = {
    CHR_o, CHR_f, PCT_SPACE, CHR_y, CHR_o, CHR_u, CHR_r, PCT_SPACE, CTR_EM_YELLOW, CHR_w,
    CHR_e, CHR_a, CHR_p, CHR_o, CHR_n, CHR_s, CTR_CLOSE_EM, PCT_SPACE, CHR_t, CHR_o,
    PCT_SPACE, CHR_a, PCT_SPACE, CTR_EM_YELLOW, CHR_h, CHR_i, CHR_g, CHR_h, CHR_e, CHR_r,
    PCT_SPACE, CHR_l, CHR_e, CHR_v, CHR_e, CHR_l, CTR_CLOSE_EM, PCT_COMMA, CTR_NEWLINE, CTR_ENDLINE
};

// plasma!{button}{endline}
static s16 scenario_text_21A2[] = {
    CHR_p, CHR_l, CHR_a, CHR_s, CHR_m, CHR_a, PCT_EXCLAMATION, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_21BE[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// The best method to increase{newline}{endline}
static s16 scenario_text_21D6[] = {
    CHR_T, CHR_h, CHR_e, PCT_SPACE, CHR_b, CHR_e, CHR_s, CHR_t, PCT_SPACE, CHR_m,
    CHR_e, CHR_t, CHR_h, CHR_o, CHR_d, PCT_SPACE, CHR_t, CHR_o, PCT_SPACE, CHR_i,
    CHR_n, CHR_c, CHR_r, CHR_e, CHR_a, CHR_s, CHR_e, CTR_NEWLINE, CTR_ENDLINE
};

// the power of your weapons would{newline}{endline}
static s16 scenario_text_2207[] = {
    CHR_t, CHR_h, CHR_e, PCT_SPACE, CHR_p, CHR_o, CHR_w, CHR_e, CHR_r, PCT_SPACE,
    CHR_o, CHR_f, PCT_SPACE, CHR_y, CHR_o, CHR_u, CHR_r, PCT_SPACE, CHR_w, CHR_e,
    CHR_a, CHR_p, CHR_o, CHR_n, CHR_s, PCT_SPACE, CHR_w, CHR_o, CHR_u, CHR_l,
    CHR_d, CTR_NEWLINE, CTR_ENDLINE
};

// be to have a {em-yellow}skilled technician{newline}{endline}
static s16 scenario_text_223C[] = {
    CHR_b, CHR_e, PCT_SPACE, CHR_t, CHR_o, PCT_SPACE, CHR_h, CHR_a, CHR_v, CHR_e,
    PCT_SPACE, CHR_a, PCT_SPACE, CTR_EM_YELLOW, CHR_s, CHR_k, CHR_i, CHR_l, CHR_l, CHR_e,
    CHR_d, PCT_SPACE, CHR_t, CHR_e, CHR_c, CHR_h, CHR_n, CHR_i, CHR_c, CHR_i,
    CHR_a, CHR_n, CTR_NEWLINE, CTR_ENDLINE
};

// handle{/em} it, plasma!{endline}
static s16 scenario_text_227C[] = {
    CHR_h, CHR_a, CHR_n, CHR_d, CHR_l, CHR_e, CTR_CLOSE_EM, PCT_SPACE, CHR_i, CHR_t,
    PCT_COMMA, PCT_SPACE, CHR_p, CHR_l, CHR_a, CHR_s, CHR_m, CHR_a, PCT_EXCLAMATION, CTR_ENDLINE
};

// {waitinput}{end}{endline}
static s16 scenario_text_22A0[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE
};

// Address: @38e0

// Mokubei, a {em-yellow}pipe maker{/em} at {em-yellow}Mt. Fuji{/em},{newline}{endline}
static s16 scenario_text_22BD[] = {
    CHR_M, CHR_o, CHR_k, CHR_u, CHR_b, CHR_e, CHR_i, PCT_COMMA, PCT_SPACE, CHR_a,
    PCT_SPACE, CTR_EM_YELLOW, CHR_p, CHR_i, CHR_p, CHR_e, PCT_SPACE, CHR_m, CHR_a, CHR_k,
    CHR_e, CHR_r, CTR_CLOSE_EM, PCT_SPACE, CHR_a, CHR_t, PCT_SPACE, CTR_EM_YELLOW, CHR_M, CHR_t,
    PCT_PERIOD, PCT_SPACE, CHR_F, CHR_u, CHR_j, CHR_i, CTR_CLOSE_EM, PCT_COMMA, CTR_NEWLINE, CTR_ENDLINE
};

// should be able to increase{newline}{endline}
static s16 scenario_text_2315[] = {
    CHR_s, CHR_h, CHR_o, CHR_u, CHR_l, CHR_d, PCT_SPACE, CHR_b, CHR_e, PCT_SPACE,
    CHR_a, CHR_b, CHR_l, CHR_e, PCT_SPACE, CHR_t, CHR_o, PCT_SPACE, CHR_i, CHR_n,
    CHR_c, CHR_r, CHR_e, CHR_a, CHR_s, CHR_e, CTR_NEWLINE, CTR_ENDLINE
};

// the power of your weapons,{newline}{endline}
static s16 scenario_text_2345[] = {
    CHR_t, CHR_h, CHR_e, PCT_SPACE, CHR_p, CHR_o, CHR_w, CHR_e, CHR_r, PCT_SPACE,
    CHR_o, CHR_f, PCT_SPACE, CHR_y, CHR_o, CHR_u, CHR_r, PCT_SPACE, CHR_w, CHR_e,
    CHR_a, CHR_p, CHR_o, CHR_n, CHR_s, PCT_COMMA, CTR_NEWLINE, CTR_ENDLINE
};

// plasma!{endline}
static s16 scenario_text_2375[] = {
    CHR_p, CHR_l, CHR_a, CHR_s, CHR_m, CHR_a, PCT_EXCLAMATION, CTR_ENDLINE
};

// {waitinput}{end}{endline}
static s16 scenario_text_2389[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE
};

// Address: @3918

// Destroy the {em-yellow}rock{/em} blocking{newline}{endline}
static s16 scenario_text_23A6[] = {
    CHR_D, CHR_e, CHR_s, CHR_t, CHR_r, CHR_o, CHR_y, PCT_SPACE, CHR_t, CHR_h,
    CHR_e, PCT_SPACE, CTR_EM_YELLOW, CHR_r, CHR_o, CHR_c, CHR_k, CTR_CLOSE_EM, PCT_SPACE, CHR_b,
    CHR_l, CHR_o, CHR_c, CHR_k, CHR_i, CHR_n, CHR_g, CTR_NEWLINE, CTR_ENDLINE
};

// the Rear Entrance of [Mt. Fear],{newline}{endline}
static s16 scenario_text_23E5[] = {
    CHR_t, CHR_h, CHR_e, PCT_SPACE, CHR_R, CHR_e, CHR_a, CHR_r, PCT_SPACE, CHR_E,
    CHR_n, CHR_t, CHR_r, CHR_a, CHR_n, CHR_c, CHR_e, PCT_SPACE, CHR_o, CHR_f,
    PCT_SPACE, PCT_LBRACKET, CHR_M, CHR_t, PCT_PERIOD, PCT_SPACE, CHR_F, CHR_e, CHR_a, CHR_r,
    PCT_RBRACKET, PCT_COMMA, CTR_NEWLINE, CTR_ENDLINE
};

// using your newly powered {em-yellow}weapons{/em},{newline}{endline}
static s16 scenario_text_241B[] = {
    CHR_u, CHR_s, CHR_i, CHR_n, CHR_g, PCT_SPACE, CHR_y, CHR_o, CHR_u, CHR_r,
    PCT_SPACE, CHR_n, CHR_e, CHR_w, CHR_l, CHR_y, PCT_SPACE, CHR_p, CHR_o, CHR_w,
    CHR_e, CHR_r, CHR_e, CHR_d, PCT_SPACE, CTR_EM_YELLOW, CHR_w, CHR_e, CHR_a, CHR_p,
    CHR_o, CHR_n, CHR_s, CTR_CLOSE_EM, PCT_COMMA, CTR_NEWLINE, CTR_ENDLINE
};

// plasma!{endline}
static s16 scenario_text_2462[] = {
    CHR_p, CHR_l, CHR_a, CHR_s, CHR_m, CHR_a, PCT_EXCLAMATION, CTR_ENDLINE
};

// {waitinput}{end}{endline}
static s16 scenario_text_2476[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE
};

// Address: @3950

// The {em-yellow}weirdo{/em} of Peach Mountain,{newline}{endline}
static s16 scenario_text_2493[] = {
    CHR_T, CHR_h, CHR_e, PCT_SPACE, CTR_EM_YELLOW, CHR_w, CHR_e, CHR_i, CHR_r, CHR_d,
    CHR_o, CTR_CLOSE_EM, PCT_SPACE, CHR_o, CHR_f, PCT_SPACE, CHR_P, CHR_e, CHR_a, CHR_c,
    CHR_h, PCT_SPACE, CHR_M, CHR_o, CHR_u, CHR_n, CHR_t, CHR_a, CHR_i, CHR_n,
    PCT_COMMA, CTR_NEWLINE, CTR_ENDLINE
};

// who's around somewhere, {newline}{endline}
static s16 scenario_text_24D6[] = {
    CHR_w, CHR_h, CHR_o, PCT_APOSTROPHE, CHR_s, PCT_SPACE, CHR_a, CHR_r, CHR_o, CHR_u,
    CHR_n, CHR_d, PCT_SPACE, CHR_s, CHR_o, CHR_m, CHR_e, CHR_w, CHR_h, CHR_e,
    CHR_r, CHR_e, PCT_COMMA, PCT_SPACE, CTR_NEWLINE, CTR_ENDLINE
};

// has the {em-yellow}Miracle Item{/em} you are{newline}{endline}
static s16 scenario_text_2504[] = {
    CHR_h, CHR_a, CHR_s, PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE, CTR_EM_YELLOW, CHR_M,
    CHR_i, CHR_r, CHR_a, CHR_c, CHR_l, CHR_e, PCT_SPACE, CHR_I, CHR_t, CHR_e,
    CHR_m, CTR_CLOSE_EM, PCT_SPACE, CHR_y, CHR_o, CHR_u, PCT_SPACE, CHR_a, CHR_r, CHR_e,
    CTR_NEWLINE, CTR_ENDLINE
};

// looking for, plasma.{button}{endline}
static s16 scenario_text_2546[] = {
    CHR_l, CHR_o, CHR_o, CHR_k, CHR_i, CHR_n, CHR_g, PCT_SPACE, CHR_f, CHR_o,
    CHR_r, PCT_COMMA, PCT_SPACE, CHR_p, CHR_l, CHR_a, CHR_s, CHR_m, CHR_a, PCT_PERIOD,
    CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_256F[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// To find out where he is,{newline}{endline}
static s16 scenario_text_2587[] = {
    CHR_T, CHR_o, PCT_SPACE, CHR_f, CHR_i, CHR_n, CHR_d, PCT_SPACE, CHR_o, CHR_u,
    CHR_t, PCT_SPACE, CHR_w, CHR_h, CHR_e, CHR_r, CHR_e, PCT_SPACE, CHR_h, CHR_e,
    PCT_SPACE, CHR_i, CHR_s, PCT_COMMA, CTR_NEWLINE, CTR_ENDLINE
};

// listen well to the people{newline}{endline}
static s16 scenario_text_25B5[] = {
    CHR_l, CHR_i, CHR_s, CHR_t, CHR_e, CHR_n, PCT_SPACE, CHR_w, CHR_e, CHR_l,
    CHR_l, PCT_SPACE, CHR_t, CHR_o, PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE, CHR_p,
    CHR_e, CHR_o, CHR_p, CHR_l, CHR_e, CTR_NEWLINE, CTR_ENDLINE
};

// of the [{em-yellow}Festival Village{/em}],{newline}{endline}
static s16 scenario_text_25E4[] = {
    CHR_o, CHR_f, PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE, PCT_LBRACKET, CTR_EM_YELLOW, CHR_F,
    CHR_e, CHR_s, CHR_t, CHR_i, CHR_v, CHR_a, CHR_l, PCT_SPACE, CHR_V, CHR_i,
    CHR_l, CHR_l, CHR_a, CHR_g, CHR_e, CTR_CLOSE_EM, PCT_RBRACKET, PCT_COMMA, CTR_NEWLINE, CTR_ENDLINE
};

// plasma!{endline}
static s16 scenario_text_2624[] = {
    CHR_p, CHR_l, CHR_a, CHR_s, CHR_m, CHR_a, PCT_EXCLAMATION, CTR_ENDLINE
};

// {waitinput}{end}{endline}
static s16 scenario_text_2638[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE
};

// Address: @39d4

// The weirdo of Peach Mountain is{newline}{endline}
static s16 scenario_text_2655[] = {
    CHR_T, CHR_h, CHR_e, PCT_SPACE, CHR_w, CHR_e, CHR_i, CHR_r, CHR_d, CHR_o,
    PCT_SPACE, CHR_o, CHR_f, PCT_SPACE, CHR_P, CHR_e, CHR_a, CHR_c, CHR_h, PCT_SPACE,
    CHR_M, CHR_o, CHR_u, CHR_n, CHR_t, CHR_a, CHR_i, CHR_n, PCT_SPACE, CHR_i,
    CHR_s, CTR_NEWLINE, CTR_ENDLINE
};

// in the [{em-yellow}Ocean{/em}], plasma!{button}{endline}
static s16 scenario_text_268A[] = {
    CHR_i, CHR_n, PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE, PCT_LBRACKET, CTR_EM_YELLOW, CHR_O,
    CHR_c, CHR_e, CHR_a, CHR_n, CTR_CLOSE_EM, PCT_RBRACKET, PCT_COMMA, PCT_SPACE, CHR_p, CHR_l,
    CHR_a, CHR_s, CHR_m, CHR_a, PCT_EXCLAMATION, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_26C6[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// How does one enter the {em-yellow}ocean{/em}?!{button}{endline}
static s16 scenario_text_26DE[] = {
    CHR_H, CHR_o, CHR_w, PCT_SPACE, CHR_d, CHR_o, CHR_e, CHR_s, PCT_SPACE, CHR_o,
    CHR_n, CHR_e, PCT_SPACE, CHR_e, CHR_n, CHR_t, CHR_e, CHR_r, PCT_SPACE, CHR_t,
    CHR_h, CHR_e, PCT_SPACE, CTR_EM_YELLOW, CHR_o, CHR_c, CHR_e, CHR_a, CHR_n, CTR_CLOSE_EM,
    PCT_QUESTION, PCT_EXCLAMATION, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_2721[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Listen well to the{newline}{endline}
static s16 scenario_text_2739[] = {
    CHR_L, CHR_i, CHR_s, CHR_t, CHR_e, CHR_n, PCT_SPACE, CHR_w, CHR_e, CHR_l,
    CHR_l, PCT_SPACE, CHR_t, CHR_o, PCT_SPACE, CHR_t, CHR_h, CHR_e, CTR_NEWLINE, CTR_ENDLINE
};

// people of [{em-yellow}Festival Village{/em}], {newline}{endline}
static s16 scenario_text_2761[] = {
    CHR_p, CHR_e, CHR_o, CHR_p, CHR_l, CHR_e, PCT_SPACE, CHR_o, CHR_f, PCT_SPACE,
    PCT_LBRACKET, CTR_EM_YELLOW, CHR_F, CHR_e, CHR_s, CHR_t, CHR_i, CHR_v, CHR_a, CHR_l,
    PCT_SPACE, CHR_V, CHR_i, CHR_l, CHR_l, CHR_a, CHR_g, CHR_e, CTR_CLOSE_EM, PCT_RBRACKET,
    PCT_COMMA, PCT_SPACE, CTR_NEWLINE, CTR_ENDLINE
};

// and find the solution, plasma!{endline}
static s16 scenario_text_27A5[] = {
    CHR_a, CHR_n, CHR_d, PCT_SPACE, CHR_f, CHR_i, CHR_n, CHR_d, PCT_SPACE, CHR_t,
    CHR_h, CHR_e, PCT_SPACE, CHR_s, CHR_o, CHR_l, CHR_u, CHR_t, CHR_i, CHR_o,
    CHR_n, PCT_COMMA, PCT_SPACE, CHR_p, CHR_l, CHR_a, CHR_s, CHR_m, CHR_a, PCT_EXCLAMATION,
    CTR_ENDLINE
};

// {waitinput}{end}{endline}
static s16 scenario_text_27D0[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE
};

// Address: @3a34

// Try talking to the {em-yellow}sign{/em} at{newline}{endline}
static s16 scenario_text_27ED[] = {
    CHR_T, CHR_r, CHR_y, PCT_SPACE, CHR_t, CHR_a, CHR_l, CHR_k, CHR_i, CHR_n,
    CHR_g, PCT_SPACE, CHR_t, CHR_o, PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE, CTR_EM_YELLOW,
    CHR_s, CHR_i, CHR_g, CHR_n, CTR_CLOSE_EM, PCT_SPACE, CHR_a, CHR_t, CTR_NEWLINE, CTR_ENDLINE
};

// the [{em-yellow}Waterfall of Kegon{/em}], plasma!{button}{endline}
static s16 scenario_text_282D[] = {
    CHR_t, CHR_h, CHR_e, PCT_SPACE, PCT_LBRACKET, CTR_EM_YELLOW, CHR_W, CHR_a, CHR_t, CHR_e,
    CHR_r, CHR_f, CHR_a, CHR_l, CHR_l, PCT_SPACE, CHR_o, CHR_f, PCT_SPACE, CHR_K,
    CHR_e, CHR_g, CHR_o, CHR_n, CTR_CLOSE_EM, PCT_RBRACKET, PCT_COMMA, PCT_SPACE, CHR_p, CHR_l,
    CHR_a, CHR_s, CHR_m, CHR_a, PCT_EXCLAMATION, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_2873[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// It will provide you with{newline}{endline}
static s16 scenario_text_288B[] = {
    CHR_I, CHR_t, PCT_SPACE, CHR_w, CHR_i, CHR_l, CHR_l, PCT_SPACE, CHR_p, CHR_r,
    CHR_o, CHR_v, CHR_i, CHR_d, CHR_e, PCT_SPACE, CHR_y, CHR_o, CHR_u, PCT_SPACE,
    CHR_w, CHR_i, CHR_t, CHR_h, CTR_NEWLINE, CTR_ENDLINE
};

// the {em-yellow}training{/em} you are in{newline}{endline}
static s16 scenario_text_28B9[] = {
    CHR_t, CHR_h, CHR_e, PCT_SPACE, CTR_EM_YELLOW, CHR_t, CHR_r, CHR_a, CHR_i, CHR_n,
    CHR_i, CHR_n, CHR_g, CTR_CLOSE_EM, PCT_SPACE, CHR_y, CHR_o, CHR_u, PCT_SPACE, CHR_a,
    CHR_r, CHR_e, PCT_SPACE, CHR_i, CHR_n, CTR_NEWLINE, CTR_ENDLINE
};

// need of now, plasma!{endline}
static s16 scenario_text_28F6[] = {
    CHR_n, CHR_e, CHR_e, CHR_d, PCT_SPACE, CHR_o, CHR_f, PCT_SPACE, CHR_n, CHR_o,
    CHR_w, PCT_COMMA, PCT_SPACE, CHR_p, CHR_l, CHR_a, CHR_s, CHR_m, CHR_a, PCT_EXCLAMATION,
    CTR_ENDLINE
};

// {waitinput}{end}{endline}
static s16 scenario_text_2917[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE
};

// Address: @3a7c

// There is something mysterious in{newline}{endline}
static s16 scenario_text_2934[] = {
    CHR_T, CHR_h, CHR_e, CHR_r, CHR_e, PCT_SPACE, CHR_i, CHR_s, PCT_SPACE, CHR_s,
    CHR_o, CHR_m, CHR_e, CHR_t, CHR_h, CHR_i, CHR_n, CHR_g, PCT_SPACE, CHR_m,
    CHR_y, CHR_s, CHR_t, CHR_e, CHR_r, CHR_i, CHR_o, CHR_u, CHR_s, PCT_SPACE,
    CHR_i, CHR_n, CTR_NEWLINE, CTR_ENDLINE
};

// the [Japan Sea] to the {em-yellow}North{/em} of{newline}{endline}
static s16 scenario_text_296A[] = {
    CHR_t, CHR_h, CHR_e, PCT_SPACE, PCT_LBRACKET, CHR_J, CHR_a, CHR_p, CHR_a, CHR_n,
    PCT_SPACE, CHR_S, CHR_e, CHR_a, PCT_RBRACKET, PCT_SPACE, CHR_t, CHR_o, PCT_SPACE, CHR_t,
    CHR_h, CHR_e, PCT_SPACE, CTR_EM_YELLOW, CHR_N, CHR_o, CHR_r, CHR_t, CHR_h, CTR_CLOSE_EM,
    PCT_SPACE, CHR_o, CHR_f, CTR_NEWLINE, CTR_ENDLINE
};

// here, plasma!{button}{endline}
static s16 scenario_text_29AF[] = {
    CHR_h, CHR_e, CHR_r, CHR_e, PCT_COMMA, PCT_SPACE, CHR_p, CHR_l, CHR_a, CHR_s,
    CHR_m, CHR_a, PCT_EXCLAMATION, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_29D1[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// If you press the {em-yellow}red switch{/em} in{newline}{endline}
static s16 scenario_text_29E9[] = {
    CHR_I, CHR_f, PCT_SPACE, CHR_y, CHR_o, CHR_u, PCT_SPACE, CHR_p, CHR_r, CHR_e,
    CHR_s, CHR_s, PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE, CTR_EM_YELLOW, CHR_r, CHR_e,
    CHR_d, PCT_SPACE, CHR_s, CHR_w, CHR_i, CHR_t, CHR_c, CHR_h, CTR_CLOSE_EM, PCT_SPACE,
    CHR_i, CHR_n, CTR_NEWLINE, CTR_ENDLINE
};

// the ocean, a {em-yellow}new road{/em} will appear,{newline}{endline}
static s16 scenario_text_2A2D[] = {
    CHR_t, CHR_h, CHR_e, PCT_SPACE, CHR_o, CHR_c, CHR_e, CHR_a, CHR_n, PCT_COMMA,
    PCT_SPACE, CHR_a, PCT_SPACE, CTR_EM_YELLOW, CHR_n, CHR_e, CHR_w, PCT_SPACE, CHR_r, CHR_o,
    CHR_a, CHR_d, CTR_CLOSE_EM, PCT_SPACE, CHR_w, CHR_i, CHR_l, CHR_l, PCT_SPACE, CHR_a,
    CHR_p, CHR_p, CHR_e, CHR_a, CHR_r, PCT_COMMA, CTR_NEWLINE, CTR_ENDLINE
};

// plasma!{endline}
static s16 scenario_text_2A75[] = {
    CHR_p, CHR_l, CHR_a, CHR_s, CHR_m, CHR_a, PCT_EXCLAMATION, CTR_ENDLINE
};

// {waitinput}{end}{endline}
static s16 scenario_text_2A89[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE
};

// Address: @3acc

// Ask the {em-yellow}Collector{/em} of [{em-yellow}Zazen Town{/em}], {newline}{endline}
static s16 scenario_text_2AA6[] = {
    CHR_A, CHR_s, CHR_k, PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE, CTR_EM_YELLOW, CHR_C,
    CHR_o, CHR_l, CHR_l, CHR_e, CHR_c, CHR_t, CHR_o, CHR_r, CTR_CLOSE_EM, PCT_SPACE,
    CHR_o, CHR_f, PCT_SPACE, PCT_LBRACKET, CTR_EM_YELLOW, CHR_Z, CHR_a, CHR_z, CHR_e, CHR_n,
    PCT_SPACE, CHR_T, CHR_o, CHR_w, CHR_n, CTR_CLOSE_EM, PCT_RBRACKET, PCT_COMMA, PCT_SPACE, CTR_NEWLINE,
    CTR_ENDLINE
};

// plasma!{endline}
static s16 scenario_text_2AFF[] = {
    CHR_p, CHR_l, CHR_a, CHR_s, CHR_m, CHR_a, PCT_EXCLAMATION, CTR_ENDLINE
};

// {waitinput}{end}{endline}
static s16 scenario_text_2B13[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE
};

// Address: @3b18

// The{em-yellow} Collector{/em} of [Zazen Town]?{newline}{endline}
static s16 scenario_text_2B30[] = {
    CHR_T, CHR_h, CHR_e, CTR_EM_YELLOW, PCT_SPACE, CHR_C, CHR_o, CHR_l, CHR_l, CHR_e,
    CHR_c, CHR_t, CHR_o, CHR_r, CTR_CLOSE_EM, PCT_SPACE, CHR_o, CHR_f, PCT_SPACE, PCT_LBRACKET,
    CHR_Z, CHR_a, CHR_z, CHR_e, CHR_n, PCT_SPACE, CHR_T, CHR_o, CHR_w, CHR_n,
    PCT_RBRACKET, PCT_QUESTION, CTR_NEWLINE, CTR_ENDLINE
};

// Why, that would be {em-yellow}Benkei{/em}{newline}{endline}
static s16 scenario_text_2B74[] = {
    CHR_W, CHR_h, CHR_y, PCT_COMMA, PCT_SPACE, CHR_t, CHR_h, CHR_a, CHR_t, PCT_SPACE,
    CHR_w, CHR_o, CHR_u, CHR_l, CHR_d, PCT_SPACE, CHR_b, CHR_e, PCT_SPACE, CTR_EM_YELLOW,
    CHR_B, CHR_e, CHR_n, CHR_k, CHR_e, CHR_i, CTR_CLOSE_EM, CTR_NEWLINE, CTR_ENDLINE
};

// of course, plasma!{endline}
static s16 scenario_text_2BB3[] = {
    CHR_o, CHR_f, PCT_SPACE, CHR_c, CHR_o, CHR_u, CHR_r, CHR_s, CHR_e, PCT_COMMA,
    PCT_SPACE, CHR_p, CHR_l, CHR_a, CHR_s, CHR_m, CHR_a, PCT_EXCLAMATION, CTR_ENDLINE
};

// {waitinput}{end}{endline}
static s16 scenario_text_2BD2[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE
};

// Address: @3b48

// {em-yellow}Kihachi{/em} lives just off{newline}{endline}
static s16 scenario_text_2BEF[] = {
    CTR_EM_YELLOW, CHR_K, CHR_i, CHR_h, CHR_a, CHR_c, CHR_h, CHR_i, CTR_CLOSE_EM, PCT_SPACE,
    CHR_l, CHR_i, CHR_v, CHR_e, CHR_s, PCT_SPACE, CHR_j, CHR_u, CHR_s, CHR_t,
    PCT_SPACE, CHR_o, CHR_f, CHR_f, CTR_NEWLINE, CTR_ENDLINE
};

// the {em-yellow}Center Pond{/em}, which is{newline}{endline}
static s16 scenario_text_2C2B[] = {
    CHR_t, CHR_h, CHR_e, PCT_SPACE, CTR_EM_YELLOW, CHR_C, CHR_e, CHR_n, CHR_t, CHR_e,
    CHR_r, PCT_SPACE, CHR_P, CHR_o, CHR_n, CHR_d, CTR_CLOSE_EM, PCT_COMMA, PCT_SPACE, CHR_w,
    CHR_h, CHR_i, CHR_c, CHR_h, PCT_SPACE, CHR_i, CHR_s, CTR_NEWLINE, CTR_ENDLINE
};

// surrounded by the bamboo forest{newline}{endline}
static s16 scenario_text_2C6A[] = {
    CHR_s, CHR_u, CHR_r, CHR_r, CHR_o, CHR_u, CHR_n, CHR_d, CHR_e, CHR_d,
    PCT_SPACE, CHR_b, CHR_y, PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE, CHR_b, CHR_a,
    CHR_m, CHR_b, CHR_o, CHR_o, PCT_SPACE, CHR_f, CHR_o, CHR_r, CHR_e, CHR_s,
    CHR_t, CTR_NEWLINE, CTR_ENDLINE
};

// between the shopping districts!{newline}{endline}
static s16 scenario_text_2C9F[] = {
    CHR_b, CHR_e, CHR_t, CHR_w, CHR_e, CHR_e, CHR_n, PCT_SPACE, CHR_t, CHR_h,
    CHR_e, PCT_SPACE, CHR_s, CHR_h, CHR_o, CHR_p, CHR_p, CHR_i, CHR_n, CHR_g,
    PCT_SPACE, CHR_d, CHR_i, CHR_s, CHR_t, CHR_r, CHR_i, CHR_c, CHR_t, CHR_s,
    PCT_EXCLAMATION, CTR_NEWLINE, CTR_ENDLINE
};

// {waitinput}{end}{endline}
static s16 scenario_text_2CD4[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE
};

// Address: @3b80

// The {em-yellow}son{/em} of the Priest of {newline}{endline}
static s16 scenario_text_2CF1[] = {
    CHR_T, CHR_h, CHR_e, PCT_SPACE, CTR_EM_YELLOW, CHR_s, CHR_o, CHR_n, CTR_CLOSE_EM, PCT_SPACE,
    CHR_o, CHR_f, PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE, CHR_P, CHR_r, CHR_i,
    CHR_e, CHR_s, CHR_t, PCT_SPACE, CHR_o, CHR_f, PCT_SPACE, CTR_NEWLINE, CTR_ENDLINE
};

// the {em-yellow}Golden Temple{/em} makes{newline}{endline}
static s16 scenario_text_2D30[] = {
    CHR_t, CHR_h, CHR_e, PCT_SPACE, CTR_EM_YELLOW, CHR_G, CHR_o, CHR_l, CHR_d, CHR_e,
    CHR_n, PCT_SPACE, CHR_T, CHR_e, CHR_m, CHR_p, CHR_l, CHR_e, CTR_CLOSE_EM, PCT_SPACE,
    CHR_m, CHR_a, CHR_k, CHR_e, CHR_s, CTR_NEWLINE, CTR_ENDLINE
};

// {em-yellow}cucumbers{/em}, a favorite of{newline}{endline}
static s16 scenario_text_2D6D[] = {
    CTR_EM_YELLOW, CHR_c, CHR_u, CHR_c, CHR_u, CHR_m, CHR_b, CHR_e, CHR_r, CHR_s,
    CTR_CLOSE_EM, PCT_COMMA, PCT_SPACE, CHR_a, PCT_SPACE, CHR_f, CHR_a, CHR_v, CHR_o, CHR_r,
    CHR_i, CHR_t, CHR_e, PCT_SPACE, CHR_o, CHR_f, CTR_NEWLINE, CTR_ENDLINE
};

// Kihachi's, plasma!{endline}
static s16 scenario_text_2DAB[] = {
    CHR_K, CHR_i, CHR_h, CHR_a, CHR_c, CHR_h, CHR_i, PCT_APOSTROPHE, CHR_s, PCT_COMMA,
    PCT_SPACE, CHR_p, CHR_l, CHR_a, CHR_s, CHR_m, CHR_a, PCT_EXCLAMATION, CTR_ENDLINE
};

// {waitinput}{end}{endline}
static s16 scenario_text_2DCA[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE
};

// Address: @3bd0

// To climb the extremely {em-yellow}high step{/em}{newline}{endline}
static s16 scenario_text_2DE7[] = {
    CHR_T, CHR_o, PCT_SPACE, CHR_c, CHR_l, CHR_i, CHR_m, CHR_b, PCT_SPACE, CHR_t,
    CHR_h, CHR_e, PCT_SPACE, CHR_e, CHR_x, CHR_t, CHR_r, CHR_e, CHR_m, CHR_e,
    CHR_l, CHR_y, PCT_SPACE, CTR_EM_YELLOW, CHR_h, CHR_i, CHR_g, CHR_h, PCT_SPACE, CHR_s,
    CHR_t, CHR_e, CHR_p, CTR_CLOSE_EM, CTR_NEWLINE, CTR_ENDLINE
};

// of {em-yellow}Mt.Nyoigatake{/em}, and meet {newline}{endline}
static s16 scenario_text_2E2D[] = {
    CHR_o, CHR_f, PCT_SPACE, CTR_EM_YELLOW, CHR_M, CHR_t, PCT_PERIOD, CHR_N, CHR_y, CHR_o,
    CHR_i, CHR_g, CHR_a, CHR_t, CHR_a, CHR_k, CHR_e, CTR_CLOSE_EM, PCT_COMMA, PCT_SPACE,
    CHR_a, CHR_n, CHR_d, PCT_SPACE, CHR_m, CHR_e, CHR_e, CHR_t, PCT_SPACE, CTR_NEWLINE,
    CTR_ENDLINE
};

// the {em-yellow}cucumber{/em}-making expert,{button}{endline}
static s16 scenario_text_2E6E[] = {
    CHR_t, CHR_h, CHR_e, PCT_SPACE, CTR_EM_YELLOW, CHR_c, CHR_u, CHR_c, CHR_u, CHR_m,
    CHR_b, CHR_e, CHR_r, CTR_CLOSE_EM, PCT_DASH, CHR_m, CHR_a, CHR_k, CHR_i, CHR_n,
    CHR_g, PCT_SPACE, CHR_e, CHR_x, CHR_p, CHR_e, CHR_r, CHR_t, PCT_COMMA, CTR_BUTTON,
    CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_2EAE[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// you need to train to obtain{newline}{endline}
static s16 scenario_text_2EC6[] = {
    CHR_y, CHR_o, CHR_u, PCT_SPACE, CHR_n, CHR_e, CHR_e, CHR_d, PCT_SPACE, CHR_t,
    CHR_o, PCT_SPACE, CHR_t, CHR_r, CHR_a, CHR_i, CHR_n, PCT_SPACE, CHR_t, CHR_o,
    PCT_SPACE, CHR_o, CHR_b, CHR_t, CHR_a, CHR_i, CHR_n, CTR_NEWLINE, CTR_ENDLINE
};

// the technique to increase your {newline}{endline}
static s16 scenario_text_2EF7[] = {
    CHR_t, CHR_h, CHR_e, PCT_SPACE, CHR_t, CHR_e, CHR_c, CHR_h, CHR_n, CHR_i,
    CHR_q, CHR_u, CHR_e, PCT_SPACE, CHR_t, CHR_o, PCT_SPACE, CHR_i, CHR_n, CHR_c,
    CHR_r, CHR_e, CHR_a, CHR_s, CHR_e, PCT_SPACE, CHR_y, CHR_o, CHR_u, CHR_r,
    PCT_SPACE, CTR_NEWLINE, CTR_ENDLINE
};

// power to {em-yellow}jump{/em}, plasma!{button}{endline}
static s16 scenario_text_2F2C[] = {
    CHR_p, CHR_o, CHR_w, CHR_e, CHR_r, PCT_SPACE, CHR_t, CHR_o, PCT_SPACE, CTR_EM_YELLOW,
    CHR_j, CHR_u, CHR_m, CHR_p, CTR_CLOSE_EM, PCT_COMMA, PCT_SPACE, CHR_p, CHR_l, CHR_a,
    CHR_s, CHR_m, CHR_a, PCT_EXCLAMATION, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_2F67[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Ask the [{em-yellow}Priest{/em}] of{newline}{endline}
static s16 scenario_text_2F7F[] = {
    CHR_A, CHR_s, CHR_k, PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE, PCT_LBRACKET, CTR_EM_YELLOW,
    CHR_P, CHR_r, CHR_i, CHR_e, CHR_s, CHR_t, CTR_CLOSE_EM, PCT_RBRACKET, PCT_SPACE, CHR_o,
    CHR_f, CTR_NEWLINE, CTR_ENDLINE
};

// the Golden Temple, plasma!{endline}
static s16 scenario_text_2FB8[] = {
    CHR_t, CHR_h, CHR_e, PCT_SPACE, CHR_G, CHR_o, CHR_l, CHR_d, CHR_e, CHR_n,
    PCT_SPACE, CHR_T, CHR_e, CHR_m, CHR_p, CHR_l, CHR_e, PCT_COMMA, PCT_SPACE, CHR_p,
    CHR_l, CHR_a, CHR_s, CHR_m, CHR_a, PCT_EXCLAMATION, CTR_ENDLINE
};

// {waitinput}{end}{endline}
static s16 scenario_text_2FDF[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE
};

// Address: @3c38

// Inside the {em-yellow}locked warehouse{/em} of{newline}{endline}
static s16 scenario_text_2FFC[] = {
    CHR_I, CHR_n, CHR_s, CHR_i, CHR_d, CHR_e, PCT_SPACE, CHR_t, CHR_h, CHR_e,
    PCT_SPACE, CTR_EM_YELLOW, CHR_l, CHR_o, CHR_c, CHR_k, CHR_e, CHR_d, PCT_SPACE, CHR_w,
    CHR_a, CHR_r, CHR_e, CHR_h, CHR_o, CHR_u, CHR_s, CHR_e, CTR_CLOSE_EM, PCT_SPACE,
    CHR_o, CHR_f, CTR_NEWLINE, CTR_ENDLINE
};

// [Bizen] is a {em-yellow}Training Gym{/em},{newline}{endline}
static s16 scenario_text_3040[] = {
    PCT_LBRACKET, CHR_B, CHR_i, CHR_z, CHR_e, CHR_n, PCT_RBRACKET, PCT_SPACE, CHR_i, CHR_s,
    PCT_SPACE, CHR_a, PCT_SPACE, CTR_EM_YELLOW, CHR_T, CHR_r, CHR_a, CHR_i, CHR_n, CHR_i,
    CHR_n, CHR_g, PCT_SPACE, CHR_G, CHR_y, CHR_m, CTR_CLOSE_EM, PCT_COMMA, CTR_NEWLINE, CTR_ENDLINE
};

// plasma!{endline}
static s16 scenario_text_3080[] = {
    CHR_p, CHR_l, CHR_a, CHR_s, CHR_m, CHR_a, PCT_EXCLAMATION, CTR_ENDLINE
};

// {waitinput}{end}{endline}
static s16 scenario_text_3094[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE
};

// Address: @3c68

// Use the [{em-yellow}Flying{/em}] magic powers{newline}{endline}
static s16 scenario_text_30B1[] = {
    CHR_U, CHR_s, CHR_e, PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE, PCT_LBRACKET, CTR_EM_YELLOW,
    CHR_F, CHR_l, CHR_y, CHR_i, CHR_n, CHR_g, CTR_CLOSE_EM, PCT_RBRACKET, PCT_SPACE, CHR_m,
    CHR_a, CHR_g, CHR_i, CHR_c, PCT_SPACE, CHR_p, CHR_o, CHR_w, CHR_e, CHR_r,
    CHR_s, CTR_NEWLINE, CTR_ENDLINE
};

// to climb on to the steps{newline}{endline}
static s16 scenario_text_30F4[] = {
    CHR_t, CHR_o, PCT_SPACE, CHR_c, CHR_l, CHR_i, CHR_m, CHR_b, PCT_SPACE, CHR_o,
    CHR_n, PCT_SPACE, CHR_t, CHR_o, PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE, CHR_s,
    CHR_t, CHR_e, CHR_p, CHR_s, CTR_NEWLINE, CTR_ENDLINE
};

// of {em-yellow}Mt. Nyoigatake{/em}.{button}{endline}
static s16 scenario_text_3122[] = {
    CHR_o, CHR_f, PCT_SPACE, CTR_EM_YELLOW, CHR_M, CHR_t, PCT_PERIOD, PCT_SPACE, CHR_N, CHR_y,
    CHR_o, CHR_i, CHR_g, CHR_a, CHR_t, CHR_a, CHR_k, CHR_e, CTR_CLOSE_EM, PCT_PERIOD,
    CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_3159[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// There you'll meet the {em-yellow}son{/em} of{newline}{endline}
static s16 scenario_text_3171[] = {
    CHR_T, CHR_h, CHR_e, CHR_r, CHR_e, PCT_SPACE, CHR_y, CHR_o, CHR_u, PCT_APOSTROPHE,
    CHR_l, CHR_l, PCT_SPACE, CHR_m, CHR_e, CHR_e, CHR_t, PCT_SPACE, CHR_t, CHR_h,
    CHR_e, PCT_SPACE, CTR_EM_YELLOW, CHR_s, CHR_o, CHR_n, CTR_CLOSE_EM, PCT_SPACE, CHR_o, CHR_f,
    CTR_NEWLINE, CTR_ENDLINE
};

// the priest, plasma!{endline}
static s16 scenario_text_31B3[] = {
    CHR_t, CHR_h, CHR_e, PCT_SPACE, CHR_p, CHR_r, CHR_i, CHR_e, CHR_s, CHR_t,
    PCT_COMMA, PCT_SPACE, CHR_p, CHR_l, CHR_a, CHR_s, CHR_m, CHR_a, PCT_EXCLAMATION, CTR_ENDLINE
};

// {waitinput}{end}{endline}
static s16 scenario_text_31D3[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE
};

// Address: @3cb0

// Go! Take those {em-yellow}Cucumbers{/em}{newline}{endline}
static s16 scenario_text_31F0[] = {
    CHR_G, CHR_o, PCT_EXCLAMATION, PCT_SPACE, CHR_T, CHR_a, CHR_k, CHR_e, PCT_SPACE, CHR_t,
    CHR_h, CHR_o, CHR_s, CHR_e, PCT_SPACE, CTR_EM_YELLOW, CHR_C, CHR_u, CHR_c, CHR_u,
    CHR_m, CHR_b, CHR_e, CHR_r, CHR_s, CTR_CLOSE_EM, CTR_NEWLINE, CTR_ENDLINE
};

// you have to {em-yellow}Kihachi{/em}, plasma!{endline}
static s16 scenario_text_322E[] = {
    CHR_y, CHR_o, CHR_u, PCT_SPACE, CHR_h, CHR_a, CHR_v, CHR_e, PCT_SPACE, CHR_t,
    CHR_o, PCT_SPACE, CTR_EM_YELLOW, CHR_K, CHR_i, CHR_h, CHR_a, CHR_c, CHR_h, CHR_i,
    CTR_CLOSE_EM, PCT_COMMA, PCT_SPACE, CHR_p, CHR_l, CHR_a, CHR_s, CHR_m, CHR_a, PCT_EXCLAMATION,
    CTR_ENDLINE
};

// {waitinput}{end}{endline}
static s16 scenario_text_3267[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE
};

// Address: @3cd8

// Go to the {em-yellow}Stone Circle{/em} of [Ugo]{newline}{endline}
static s16 scenario_text_3284[] = {
    CHR_G, CHR_o, PCT_SPACE, CHR_t, CHR_o, PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE,
    CTR_EM_YELLOW, CHR_S, CHR_t, CHR_o, CHR_n, CHR_e, PCT_SPACE, CHR_C, CHR_i, CHR_r,
    CHR_c, CHR_l, CHR_e, CTR_CLOSE_EM, PCT_SPACE, CHR_o, CHR_f, PCT_SPACE, PCT_LBRACKET, CHR_U,
    CHR_g, CHR_o, PCT_RBRACKET, CTR_NEWLINE, CTR_ENDLINE
};

// which you will find to the {em-yellow}West{/em}{newline}{endline}
static s16 scenario_text_32C9[] = {
    CHR_w, CHR_h, CHR_i, CHR_c, CHR_h, PCT_SPACE, CHR_y, CHR_o, CHR_u, PCT_SPACE,
    CHR_w, CHR_i, CHR_l, CHR_l, PCT_SPACE, CHR_f, CHR_i, CHR_n, CHR_d, PCT_SPACE,
    CHR_t, CHR_o, PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE, CTR_EM_YELLOW, CHR_W, CHR_e,
    CHR_s, CHR_t, CTR_CLOSE_EM, CTR_NEWLINE, CTR_ENDLINE
};

// of [Mt. Fear].{button}{endline}
static s16 scenario_text_330E[] = {
    CHR_o, CHR_f, PCT_SPACE, PCT_LBRACKET, CHR_M, CHR_t, PCT_PERIOD, PCT_SPACE, CHR_F, CHR_e,
    CHR_a, CHR_r, PCT_RBRACKET, PCT_PERIOD, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_3331[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// From there, you can get on{newline}{endline}
static s16 scenario_text_3349[] = {
    CHR_F, CHR_r, CHR_o, CHR_m, PCT_SPACE, CHR_t, CHR_h, CHR_e, CHR_r, CHR_e,
    PCT_COMMA, PCT_SPACE, CHR_y, CHR_o, CHR_u, PCT_SPACE, CHR_c, CHR_a, CHR_n, PCT_SPACE,
    CHR_g, CHR_e, CHR_t, PCT_SPACE, CHR_o, CHR_n, CTR_NEWLINE, CTR_ENDLINE
};

// the {em-yellow}Alter{/em}, plasma!{button}{endline}
static s16 scenario_text_3379[] = {
    CHR_t, CHR_h, CHR_e, PCT_SPACE, CTR_EM_YELLOW, CHR_A, CHR_l, CHR_t, CHR_e, CHR_r,
    CTR_CLOSE_EM, PCT_COMMA, PCT_SPACE, CHR_p, CHR_l, CHR_a, CHR_s, CHR_m, CHR_a, PCT_EXCLAMATION,
    CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_33B0[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// At that point, the entrance to{newline}{endline}
static s16 scenario_text_33C8[] = {
    CHR_A, CHR_t, PCT_SPACE, CHR_t, CHR_h, CHR_a, CHR_t, PCT_SPACE, CHR_p, CHR_o,
    CHR_i, CHR_n, CHR_t, PCT_COMMA, PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE, CHR_e,
    CHR_n, CHR_t, CHR_r, CHR_a, CHR_n, CHR_c, CHR_e, PCT_SPACE, CHR_t, CHR_o,
    CTR_NEWLINE, CTR_ENDLINE
};

// {em-yellow}outer space{/em} will open, plasma!{endline}
static s16 scenario_text_33FC[] = {
    CTR_EM_YELLOW, CHR_o, CHR_u, CHR_t, CHR_e, CHR_r, PCT_SPACE, CHR_s, CHR_p, CHR_a,
    CHR_c, CHR_e, CTR_CLOSE_EM, PCT_SPACE, CHR_w, CHR_i, CHR_l, CHR_l, PCT_SPACE, CHR_o,
    CHR_p, CHR_e, CHR_n, PCT_COMMA, PCT_SPACE, CHR_p, CHR_l, CHR_a, CHR_s, CHR_m,
    CHR_a, PCT_EXCLAMATION, CTR_ENDLINE
};

// {waitinput}{end}{endline}
static s16 scenario_text_3437[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE
};

// Address: @3d50

// This is the last thing {newline}{endline}
static s16 scenario_text_3454[] = {
    CHR_T, CHR_h, CHR_i, CHR_s, PCT_SPACE, CHR_i, CHR_s, PCT_SPACE, CHR_t, CHR_h,
    CHR_e, PCT_SPACE, CHR_l, CHR_a, CHR_s, CHR_t, PCT_SPACE, CHR_t, CHR_h, CHR_i,
    CHR_n, CHR_g, PCT_SPACE, CTR_NEWLINE, CTR_ENDLINE
};

// I am going to tell you guys.{button}{endline}
static s16 scenario_text_3481[] = {
    CHR_I, PCT_SPACE, CHR_a, CHR_m, PCT_SPACE, CHR_g, CHR_o, CHR_i, CHR_n, CHR_g,
    PCT_SPACE, CHR_t, CHR_o, PCT_SPACE, CHR_t, CHR_e, CHR_l, CHR_l, PCT_SPACE, CHR_y,
    CHR_o, CHR_u, PCT_SPACE, CHR_g, CHR_u, CHR_y, CHR_s, PCT_PERIOD, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_34B2[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Did you pick up {em-yellow}ALL{/em}{newline}{endline}
static s16 scenario_text_34CA[] = {
    CHR_D, CHR_i, CHR_d, PCT_SPACE, CHR_y, CHR_o, CHR_u, PCT_SPACE, CHR_p, CHR_i,
    CHR_c, CHR_k, PCT_SPACE, CHR_u, CHR_p, PCT_SPACE, CTR_EM_YELLOW, CHR_A, CHR_L, CHR_L,
    CTR_CLOSE_EM, CTR_NEWLINE, CTR_ENDLINE
};

// the [{em-yellow}fortune dolls{/em}] along{newline}{endline}
static s16 scenario_text_3503[] = {
    CHR_t, CHR_h, CHR_e, PCT_SPACE, PCT_LBRACKET, CTR_EM_YELLOW, CHR_f, CHR_o, CHR_r, CHR_t,
    CHR_u, CHR_n, CHR_e, PCT_SPACE, CHR_d, CHR_o, CHR_l, CHR_l, CHR_s, CTR_CLOSE_EM,
    PCT_RBRACKET, PCT_SPACE, CHR_a, CHR_l, CHR_o, CHR_n, CHR_g, CTR_NEWLINE, CTR_ENDLINE
};

// the way on the {em-yellow}roads{/em}, {em-yellow}castles{/em},{newline}{endline}
static s16 scenario_text_3542[] = {
    CHR_t, CHR_h, CHR_e, PCT_SPACE, CHR_w, CHR_a, CHR_y, PCT_SPACE, CHR_o, CHR_n,
    PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE, CTR_EM_YELLOW, CHR_r, CHR_o, CHR_a, CHR_d,
    CHR_s, CTR_CLOSE_EM, PCT_COMMA, PCT_SPACE, CTR_EM_YELLOW, CHR_c, CHR_a, CHR_s, CHR_t, CHR_l,
    CHR_e, CHR_s, CTR_CLOSE_EM, PCT_COMMA, CTR_NEWLINE, CTR_ENDLINE
};

// {em-yellow}towns{/em} and {em-yellow}villages{/em}?{button}{endline}
static s16 scenario_text_3596[] = {
    CTR_EM_YELLOW, CHR_t, CHR_o, CHR_w, CHR_n, CHR_s, CTR_CLOSE_EM, PCT_SPACE, CHR_a, CHR_n,
    CHR_d, PCT_SPACE, CTR_EM_YELLOW, CHR_v, CHR_i, CHR_l, CHR_l, CHR_a, CHR_g, CHR_e,
    CHR_s, CTR_CLOSE_EM, PCT_QUESTION, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_35DE[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// When you get all the {em-yellow}fortune dolls{/em},{newline}{endline}
static s16 scenario_text_35F6[] = {
    CHR_W, CHR_h, CHR_e, CHR_n, PCT_SPACE, CHR_y, CHR_o, CHR_u, PCT_SPACE, CHR_g,
    CHR_e, CHR_t, PCT_SPACE, CHR_a, CHR_l, CHR_l, PCT_SPACE, CHR_t, CHR_h, CHR_e,
    PCT_SPACE, CTR_EM_YELLOW, CHR_f, CHR_o, CHR_r, CHR_t, CHR_u, CHR_n, CHR_e, PCT_SPACE,
    CHR_d, CHR_o, CHR_l, CHR_l, CHR_s, CTR_CLOSE_EM, PCT_COMMA, CTR_NEWLINE, CTR_ENDLINE
};

// you'd be able to play cool,{newline}{endline}
static s16 scenario_text_363F[] = {
    CHR_y, CHR_o, CHR_u, PCT_APOSTROPHE, CHR_d, PCT_SPACE, CHR_b, CHR_e, PCT_SPACE, CHR_a,
    CHR_b, CHR_l, CHR_e, PCT_SPACE, CHR_t, CHR_o, PCT_SPACE, CHR_p, CHR_l, CHR_a,
    CHR_y, PCT_SPACE, CHR_c, CHR_o, CHR_o, CHR_l, PCT_COMMA, CTR_NEWLINE, CTR_ENDLINE
};

// great and fantastic appendix!{newline}{endline}
static s16 scenario_text_3670[] = {
    CHR_g, CHR_r, CHR_e, CHR_a, CHR_t, PCT_SPACE, CHR_a, CHR_n, CHR_d, PCT_SPACE,
    CHR_f, CHR_a, CHR_n, CHR_t, CHR_a, CHR_s, CHR_t, CHR_i, CHR_c, PCT_SPACE,
    CHR_a, CHR_p, CHR_p, CHR_e, CHR_n, CHR_d, CHR_i, CHR_x, PCT_EXCLAMATION, CTR_NEWLINE,
    CTR_ENDLINE
};

// Plasma!{endline}
static s16 scenario_text_36A3[] = {
    CHR_P, CHR_l, CHR_a, CHR_s, CHR_m, CHR_a, PCT_EXCLAMATION, CTR_ENDLINE
};

// {waitinput}{end}{endline}
static s16 scenario_text_36B7[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE
};

extern s32 scenario_code_message_288_2f98[];
extern s32 scenario_code_message_288_3094[];
extern s32 scenario_code_message_288_31a8[];
extern s32 scenario_code_message_288_31d4[];
extern s32 scenario_code_message_288_3208[];
extern s32 scenario_code_message_288_3260[];
extern s32 scenario_code_message_288_3290[];
extern s32 scenario_code_message_288_32d8[];
extern s32 scenario_code_message_288_3340[];
extern s32 scenario_code_message_288_3370[];
extern s32 scenario_code_message_288_33a8[];
extern s32 scenario_code_message_288_33f8[];
extern s32 scenario_code_message_288_3460[];
extern s32 scenario_code_message_288_34a8[];
extern s32 scenario_code_message_288_34e0[];
extern s32 scenario_code_message_288_3518[];
extern s32 scenario_code_message_288_35b4[];
extern s32 scenario_code_message_288_35d8[];
extern s32 scenario_code_message_288_3640[];
extern s32 scenario_code_message_288_36b0[];
extern s32 scenario_code_message_288_36e0[];
extern s32 scenario_code_message_288_3708[];
extern s32 scenario_code_message_288_37b4[];
extern s32 scenario_code_message_288_37e8[];
extern s32 scenario_code_message_288_3860[];
extern s32 scenario_code_message_288_38e0[];
extern s32 scenario_code_message_288_3918[];
extern s32 scenario_code_message_288_3950[];
extern s32 scenario_code_message_288_39d4[];
extern s32 scenario_code_message_288_3a34[];
extern s32 scenario_code_message_288_3a7c[];
extern s32 scenario_code_message_288_3acc[];
extern s32 scenario_code_message_288_3b18[];
extern s32 scenario_code_message_288_3b48[];
extern s32 scenario_code_message_288_3b80[];
extern s32 scenario_code_message_288_3bd0[];
extern s32 scenario_code_message_288_3c38[];
extern s32 scenario_code_message_288_3c68[];
extern s32 scenario_code_message_288_3cb0[];
extern s32 scenario_code_message_288_3cd8[];
extern s32 scenario_code_message_288_3d50[];

s32 scenario_code_message_288_2f98[] = {

    // Address: @2f98
    // SHOP 27 - Unknown Town Plasma - Unused - Plasma Backup Dancer

    // 2f98: Write to RAM 801c7758 (Unknown)
    STW, (s32)&D_801C7758_1C8358,

    // 2fa0: Store Value: 20
    WTS, 0x20,

    // 2fa8: Write to RAM 801c775c (Dialogue Window Y Pos)
    STW, (s32)&D_801C775C_1C835C,

    // 2fb0: Store Value: 68
    WTS, 0x68,

    // 2fb8: Print Text
    TXT, (s32)&scenario_text_0000,

    // 2fc0: Write to RAM 801c77d8 (Text Speed)
    STW, 0x801c77d8,

    // 2fc8: Store Value: 64
    WTS, 0x64,

    // 2fd0: Write to RAM 801c7798 (Unknown)
    STW, 0x801c7798,

    // 2fd8: Store Value: 1
    WTS, 0x1,

    // 2fe0: Write to RAM 801c7740 (Scratch)
    STW, (s32)&D_801C7740_1C8340,

    // 2fe8: Store Value: 354
    WTS, 0x354,

    // 2ff0: Execute Code: 8003f608 (Play Sound)
    ESR, (s32)&func_8003F608_40208,

    // 2ff8: Print Text
    TXT, (s32)&scenario_text_0014,

    // 3000: Print Text
    TXT, (s32)&scenario_text_002B,

    // 3008: Print Text
    TXT, (s32)&scenario_text_006F,

    // 3010: Write to RAM 801c77d8 (Text Speed)
    STW, 0x801c77d8,

    // 3018: Store Value: 1
    WTS, 0x1,

    // 3020: Write to RAM 801c7798 (Unknown)
    STW, 0x801c7798,

    // 3028: Store Value: 1
    WTS, 0x1,

    // 3030: Print Text
    TXT, (s32)&scenario_text_0087,

    // 3038: Print Text
    TXT, (s32)&scenario_text_00A8,

    // 3040: Print Text
    TXT, (s32)&scenario_text_00D4,

    // 3048: Print Text
    TXT, (s32)&scenario_text_006F,

    // 3050: Print Text
    TXT, (s32)&scenario_text_012F,

    // 3058: Print Text
    TXT, (s32)&scenario_text_015E,

    // 3060: Begin Option Selection
    BOS,

    // 3064: Print Text
    TXT, (s32)&scenario_text_0197,

    // 306c: Jump To @3094
    JMP, (s32)&scenario_code_message_288_3094,

    // 3074: Print Text
    TXT, (s32)&scenario_text_01C9,

    // 307c: Jump To @31a8
    JMP, (s32)&scenario_code_message_288_31a8,

    // 3084: End Option Selection
    EOS,

    // 3088: Print Text
    TXT, (s32)&scenario_text_01FD,

    // 3090: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_288_3094[] = {

    // Address: @3094

    // 3094: Print Text
    TXT, (s32)&scenario_text_006F,

    // 309c: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // 30a4: Store Value: 1
    WTS, 0x1,

    // 30ac: Write to RAM 801c7740 (Scratch)
    STW, (s32)&D_801C7740_1C8340,

    // 30b4: Store Value: fffffff6
    WTS, 0xFFFFFFF6,

    // 30bc: Execute Code: 80221fd4 (Give/Take Ryo)
    ESR, 0x80221fd4,

    // 30c4: Read from RAM 801c7750 (Scratch)
    LDW, 0x801c7750,

    // 30cc: Skip Next If Not Equal: 1
    SNE, 0x1,

    // 30d4: Jump To @31d4
    JMP, (s32)&scenario_code_message_288_31d4,

    // 30dc: Write to RAM 801c7740 (Scratch)
    STW, (s32)&D_801C7740_1C8340,

    // 30e4: Store Value: 23c
    WTS, 0x23C,

    // 30ec: Execute Code: 8003f608 (Play Sound)
    ESR, (s32)&func_8003F608_40208,

    // 30f4: Print Text
    TXT, (s32)&scenario_text_0227,

    // 30fc: Print Text
    TXT, (s32)&scenario_text_0247,

    // 3104: Print Text
    TXT, (s32)&scenario_text_006F,

    // 310c: Print Text
    TXT, (s32)&scenario_text_028C,

    // 3114: Print Text
    TXT, (s32)&scenario_text_02C1,

    // 311c: Print Text
    TXT, (s32)&scenario_text_02F6,

    // 3124: Print Text
    TXT, (s32)&scenario_text_006F,

    // 312c: Write to RAM 801c77d8 (Text Speed)
    STW, 0x801c77d8,

    // 3134: Store Value: 64
    WTS, 0x64,

    // 313c: Write to RAM 801c7798 (Unknown)
    STW, 0x801c7798,

    // 3144: Store Value: 1
    WTS, 0x1,

    // 314c: Write to RAM 801c7740 (Scratch)
    STW, (s32)&D_801C7740_1C8340,

    // 3154: Store Value: 354
    WTS, 0x354,

    // 315c: Execute Code: 8003f608 (Play Sound)
    ESR, (s32)&func_8003F608_40208,

    // 3164: Print Text
    TXT, (s32)&scenario_text_0014,

    // 316c: Print Text
    TXT, (s32)&scenario_text_035B,

    // 3174: Print Text
    TXT, (s32)&scenario_text_006F,

    // 317c: Write to RAM 801c77d8 (Text Speed)
    STW, 0x801c77d8,

    // 3184: Store Value: 1
    WTS, 0x1,

    // 318c: Write to RAM 801c7798 (Unknown)
    STW, 0x801c7798,

    // 3194: Store Value: 1
    WTS, 0x1,

    // 319c: Jump To @3208
    JMP, (s32)&scenario_code_message_288_3208,

    // 31a4: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_288_31a8[] = {

    // Address: @31a8

    // 31a8: Print Text
    TXT, (s32)&scenario_text_006F,

    // 31b0: Print Text
    TXT, (s32)&scenario_text_03DF,

    // 31b8: Print Text
    TXT, (s32)&scenario_text_0409,

    // 31c0: Print Text
    TXT, (s32)&scenario_text_043F,

    // 31c8: Print Text
    TXT, (s32)&scenario_text_0453,

    // 31d0: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_288_31d4[] = {

    // Address: @31d4

    // 31d4: Write to RAM 801c7740 (Scratch)
    STW, (s32)&D_801C7740_1C8340,

    // 31dc: Store Value: 2b2
    WTS, 0x2B2,

    // 31e4: Execute Code: 8003f608 (Play Sound)
    ESR, (s32)&func_8003F608_40208,

    // 31ec: Print Text
    TXT, (s32)&scenario_text_0470,

    // 31f4: Print Text
    TXT, (s32)&scenario_text_04AD,

    // 31fc: Print Text
    TXT, (s32)&scenario_text_0453,

    // 3204: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_288_3208[] = {

    // Address: @3208

    // 3208: If Flag 010 (Received Chain Pipe), Jump To @3260
    // Jump if flag 0x10 is SET to @3260
    JFS, 0x10, (s32)&scenario_code_message_288_3260,

    // 3214: Print Text
    TXT, (s32)&scenario_text_04F2,

    // 321c: Print Text
    TXT, (s32)&scenario_text_006F,

    // 3224: Print Text
    TXT, (s32)&scenario_text_0552,

    // 322c: Print Text
    TXT, (s32)&scenario_text_0593,

    // 3234: Print Text
    TXT, (s32)&scenario_text_006F,

    // 323c: Print Text
    TXT, (s32)&scenario_text_05F2,

    // 3244: Print Text
    TXT, (s32)&scenario_text_061D,

    // 324c: Print Text
    TXT, (s32)&scenario_text_064F,

    // 3254: Print Text
    TXT, (s32)&scenario_text_0453,

    // 325c: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_288_3260[] = {

    // Address: @3260

    // 3260: If Flag 000 (Received Super Pass), Jump To @3290
    // Jump if flag 0x00 is SET to @3290
    JFS, 0x00, (s32)&scenario_code_message_288_3290,

    // 326c: Print Text
    TXT, (s32)&scenario_text_06A6,

    // 3274: Print Text
    TXT, (s32)&scenario_text_06E7,

    // 327c: Print Text
    TXT, (s32)&scenario_text_0725,

    // 3284: Print Text
    TXT, (s32)&scenario_text_0453,

    // 328c: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_288_3290[] = {

    // Address: @3290

    // 3290: If Flag 03a (Recruited Yae), Jump To @32d8
    // Jump if flag 0x3A is SET to @32d8
    JFS, 0x3A, (s32)&scenario_code_message_288_32d8,

    // 329c: Print Text
    TXT, (s32)&scenario_text_077E,

    // 32a4: Print Text
    TXT, (s32)&scenario_text_07BB,

    // 32ac: Print Text
    TXT, (s32)&scenario_text_080F,

    // 32b4: Print Text
    TXT, (s32)&scenario_text_006F,

    // 32bc: Print Text
    TXT, (s32)&scenario_text_0843,

    // 32c4: Print Text
    TXT, (s32)&scenario_text_0867,

    // 32cc: Print Text
    TXT, (s32)&scenario_text_0453,

    // 32d4: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_288_32d8[] = {

    // Address: @32d8

    // 32d8: If Flag 029 (Obtained Achilles' Heel), Jump To @3340
    // Jump if flag 0x29 is SET to @3340
    JFS, 0x29, (s32)&scenario_code_message_288_3340,

    // 32e4: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // 32ec: Store Value: 1
    WTS, 0x1,

    // 32f4: Print Text
    TXT, (s32)&scenario_text_08B6,

    // 32fc: Print Text
    TXT, (s32)&scenario_text_08F8,

    // 3304: Print Text
    TXT, (s32)&scenario_text_006F,

    // 330c: Print Text
    TXT, (s32)&scenario_text_0954,

    // 3314: Print Text
    TXT, (s32)&scenario_text_0994,

    // 331c: Print Text
    TXT, (s32)&scenario_text_09C4,

    // 3324: Print Text
    TXT, (s32)&scenario_text_0A09,

    // 332c: Set Flag 025 (Can Talk to Ushiwaka about Benkei)
    // SFG, 0x25,

    // 3334: Print Text
    TXT, (s32)&scenario_text_0453,

    // 333c: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_288_3340[] = {

    // Address: @3340

    // 3340: If Flag 033 (Defeated Benkei), Jump To @3370
    // Jump if flag 0x33 is SET to @3370
    JFS, 0x33, (s32)&scenario_code_message_288_3370,

    // 334c: Print Text
    TXT, (s32)&scenario_text_0A3A,

    // 3354: Print Text
    TXT, (s32)&scenario_text_0A7B,

    // 335c: Print Text
    TXT, (s32)&scenario_text_0AA9,

    // 3364: Print Text
    TXT, (s32)&scenario_text_0453,

    // 336c: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_288_3370[] = {

    // Address: @3370

    // 3370: If Flag 063 (Heard about Dragon Problem), Jump To @33a8
    // Jump if flag 0x63 is SET to @33a8
    JFS, 0x63, (s32)&scenario_code_message_288_33a8,

    // 337c: Print Text
    TXT, (s32)&scenario_text_0AFE,

    // 3384: Print Text
    TXT, (s32)&scenario_text_0B41,

    // 338c: Print Text
    TXT, (s32)&scenario_text_0B74,

    // 3394: Print Text
    TXT, (s32)&scenario_text_0BA1,

    // 339c: Print Text
    TXT, (s32)&scenario_text_0453,

    // 33a4: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_288_33a8[] = {

    // Address: @33a8

    // 33a8: If Flag 014 (Freed Koryuta the Dragon), Jump To @33f8
    // Jump if flag 0x14 is SET to @33f8
    JFS, 0x14, (s32)&scenario_code_message_288_33f8,

    // 33b4: Print Text
    TXT, (s32)&scenario_text_0BF2,

    // 33bc: Print Text
    TXT, (s32)&scenario_text_0C33,

    // 33c4: Print Text
    TXT, (s32)&scenario_text_0C5D,

    // 33cc: Print Text
    TXT, (s32)&scenario_text_006F,

    // 33d4: Print Text
    TXT, (s32)&scenario_text_0CB0,

    // 33dc: Print Text
    TXT, (s32)&scenario_text_0CD9,

    // 33e4: Print Text
    TXT, (s32)&scenario_text_0D1A,

    // 33ec: Print Text
    TXT, (s32)&scenario_text_0453,

    // 33f4: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_288_33f8[] = {

    // Address: @33f8

    // 33f8: If Flag 00a (Heard about Zazen Dwarf), Jump To @3460
    // Jump if flag 0x0A is SET to @3460
    JFS, 0x0A, (s32)&scenario_code_message_288_3460,

    // 3404: Print Text
    TXT, (s32)&scenario_text_0D55,

    // 340c: Print Text
    TXT, (s32)&scenario_text_0D87,

    // 3414: Print Text
    TXT, (s32)&scenario_text_006F,

    // 341c: Print Text
    TXT, (s32)&scenario_text_0DE2,

    // 3424: Print Text
    TXT, (s32)&scenario_text_0E19,

    // 342c: Print Text
    TXT, (s32)&scenario_text_0E5E,

    // 3434: Print Text
    TXT, (s32)&scenario_text_006F,

    // 343c: Print Text
    TXT, (s32)&scenario_text_0EB4,

    // 3444: Print Text
    TXT, (s32)&scenario_text_0EEA,

    // 344c: Print Text
    TXT, (s32)&scenario_text_0F2C,

    // 3454: Print Text
    TXT, (s32)&scenario_text_0453,

    // 345c: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_288_3460[] = {

    // Address: @3460

    // 3460: If Flag 028 (Ushiwaka Went to Golden Temple), Jump To @34a8
    // Jump if flag 0x28 is SET to @34a8
    JFS, 0x28, (s32)&scenario_code_message_288_34a8,

    // 346c: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // 3474: Store Value: 1
    WTS, 0x1,

    // 347c: Print Text
    TXT, (s32)&scenario_text_0F66,

    // 3484: Print Text
    TXT, (s32)&scenario_text_0FAB,

    // 348c: Print Text
    TXT, (s32)&scenario_text_0FD8,

    // 3494: Set Flag 00a (Heard about Zazen Dwarf)
    // SFG, 0x0A,

    // 349c: Print Text
    TXT, (s32)&scenario_text_0453,

    // 34a4: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_288_34a8[] = {

    // Address: @34a8

    // 34a8: If Flag 031 (Obtained Mini-Ebisu Magic), Jump To @34e0
    // Jump if flag 0x31 is SET to @34e0
    JFS, 0x31, (s32)&scenario_code_message_288_34e0,

    // 34b4: Print Text
    TXT, (s32)&scenario_text_1023,

    // 34bc: Print Text
    TXT, (s32)&scenario_text_1050,

    // 34c4: Print Text
    TXT, (s32)&scenario_text_108C,

    // 34cc: Print Text
    TXT, (s32)&scenario_text_10BC,

    // 34d4: Print Text
    TXT, (s32)&scenario_text_0453,

    // 34dc: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_288_34e0[] = {

    // Address: @34e0

    // 34e0: If Flag 018 (Defeated Dharmanyo), Jump To @3518
    // Jump if flag 0x18 is SET to @3518
    JFS, 0x18, (s32)&scenario_code_message_288_3518,

    // 34ec: Print Text
    TXT, (s32)&scenario_text_110D,

    // 34f4: Print Text
    TXT, (s32)&scenario_text_114F,

    // 34fc: Print Text
    TXT, (s32)&scenario_text_1195,

    // 3504: Print Text
    TXT, (s32)&scenario_text_11C7,

    // 350c: Print Text
    TXT, (s32)&scenario_text_0453,

    // 3514: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_288_3518[] = {

    // Address: @3518

    // 3518: If Flag 00d (Received Sasuke's #1 Battery), Jump To @3640
    // Jump if flag 0x0D is SET to @3640
    JFS, 0x0D, (s32)&scenario_code_message_288_3640,

    // 3524: If Flag 03e (Saw a Cracked Door), Jump To @35d8
    // Jump if flag 0x3E is SET to @35d8
    JFS, 0x3E, (s32)&scenario_code_message_288_35d8,

    // 3530: If Flag 03f (Heard about Inaba Desert Battery), Jump To @35d8
    // Jump if flag 0x3F is SET to @35d8
    JFS, 0x3F, (s32)&scenario_code_message_288_35d8,

    // 353c: If Flag 080 (Plasma told you to Resurrect Sasuke), Jump To @35b4
    // Jump if flag 0x80 is SET to @35b4
    JFS, 0x80, (s32)&scenario_code_message_288_35b4,

    // 3548: Print Text
    TXT, (s32)&scenario_text_1218,

    // 3550: Print Text
    TXT, (s32)&scenario_text_125C,

    // 3558: Print Text
    TXT, (s32)&scenario_text_128F,

    // 3560: Print Text
    TXT, (s32)&scenario_text_12D6,

    // 3568: Print Text
    TXT, (s32)&scenario_text_006F,

    // 3570: Print Text
    TXT, (s32)&scenario_text_1330,

    // 3578: Print Text
    TXT, (s32)&scenario_text_1361,

    // 3580: Print Text
    TXT, (s32)&scenario_text_13A9,

    // 3588: Print Text
    TXT, (s32)&scenario_text_006F,

    // 3590: Print Text
    TXT, (s32)&scenario_text_1402,

    // 3598: Print Text
    TXT, (s32)&scenario_text_1449,

    // 35a0: Print Text
    TXT, (s32)&scenario_text_0453,

    // 35a8: Set Flag 080 (Plasma told you to Resurrect Sasuke)
    // SFG, 0x80,

    // 35b0: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_288_35b4[] = {

    // Address: @35b4

    // 35b4: Print Text
    TXT, (s32)&scenario_text_14A0,

    // 35bc: Print Text
    TXT, (s32)&scenario_text_14D0,

    // 35c4: Print Text
    TXT, (s32)&scenario_text_1515,

    // 35cc: Print Text
    TXT, (s32)&scenario_text_0453,

    // 35d4: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_288_35d8[] = {

    // Address: @35d8

    // 35d8: If Flag 00d (Received Sasuke's #1 Battery), Jump To @3640
    // Jump if flag 0x0D is SET to @3640
    JFS, 0x0D, (s32)&scenario_code_message_288_3640,

    // 35e4: Print Text
    TXT, (s32)&scenario_text_155D,

    // 35ec: Print Text
    TXT, (s32)&scenario_text_1598,

    // 35f4: Print Text
    TXT, (s32)&scenario_text_006F,

    // 35fc: Print Text
    TXT, (s32)&scenario_text_15EC,

    // 3604: Print Text
    TXT, (s32)&scenario_text_1620,

    // 360c: Print Text
    TXT, (s32)&scenario_text_006F,

    // 3614: Print Text
    TXT, (s32)&scenario_text_166F,

    // 361c: Print Text
    TXT, (s32)&scenario_text_16A6,

    // 3624: Print Text
    TXT, (s32)&scenario_text_006F,

    // 362c: Print Text
    TXT, (s32)&scenario_text_16FC,

    // 3634: Print Text
    TXT, (s32)&scenario_text_0453,

    // 363c: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_288_3640[] = {

    // Address: @3640

    // 3640: If Flag 00e (Recruited Sasuke), Jump To @36b0
    // Jump if flag 0x0E is SET to @36b0
    JFS, 0x0E, (s32)&scenario_code_message_288_36b0,

    // 364c: Print Text
    TXT, (s32)&scenario_text_1741,

    // 3654: Print Text
    TXT, (s32)&scenario_text_176A,

    // 365c: Print Text
    TXT, (s32)&scenario_text_17C0,

    // 3664: Print Text
    TXT, (s32)&scenario_text_006F,

    // 366c: Print Text
    TXT, (s32)&scenario_text_1806,

    // 3674: Print Text
    TXT, (s32)&scenario_text_1836,

    // 367c: Print Text
    TXT, (s32)&scenario_text_006F,

    // 3684: Print Text
    TXT, (s32)&scenario_text_1875,

    // 368c: Print Text
    TXT, (s32)&scenario_text_18A2,

    // 3694: Print Text
    TXT, (s32)&scenario_text_18E1,

    // 369c: Print Text
    TXT, (s32)&scenario_text_0A09,

    // 36a4: Print Text
    TXT, (s32)&scenario_text_0453,

    // 36ac: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_288_36b0[] = {

    // Address: @36b0

    // 36b0: If Flag 040 (Defeated Tsurami), Jump To @36e0
    // Jump if flag 0x40 is SET to @36e0
    JFS, 0x40, (s32)&scenario_code_message_288_36e0,

    // 36bc: Print Text
    TXT, (s32)&scenario_text_1956,

    // 36c4: Print Text
    TXT, (s32)&scenario_text_199A,

    // 36cc: Print Text
    TXT, (s32)&scenario_text_19D0,

    // 36d4: Print Text
    TXT, (s32)&scenario_text_0453,

    // 36dc: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_288_36e0[] = {

    // Address: @36e0

    // 36e0: If Flag 017 (Kyushu Disappeared), Jump To @3708
    // Jump if flag 0x17 is SET to @3708
    JFS, 0x17, (s32)&scenario_code_message_288_3708,

    // 36ec: Print Text
    TXT, (s32)&scenario_text_1A2C,

    // 36f4: Print Text
    TXT, (s32)&scenario_text_1A69,

    // 36fc: Print Text
    TXT, (s32)&scenario_text_0453,

    // 3704: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_288_3708[] = {

    // Address: @3708

    // 3708: If Flag 01c (Obtained Sudden Impact Magic), Jump To @37e8
    // Jump if flag 0x1C is SET to @37e8
    JFS, 0x1C, (s32)&scenario_code_message_288_37e8,

    // 3714: If Flag 03c (Heard about Sudden Impact Training from Plasma), Jump To @37b4
    // Jump if flag 0x3C is SET to @37b4
    JFS, 0x3C, (s32)&scenario_code_message_288_37b4,

    // 3720: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // 3728: Store Value: 1
    WTS, 0x1,

    // 3730: Print Text
    TXT, (s32)&scenario_text_1AD9,

    // 3738: Print Text
    TXT, (s32)&scenario_text_1B1E,

    // 3740: Print Text
    TXT, (s32)&scenario_text_1B62,

    // 3748: Print Text
    TXT, (s32)&scenario_text_006F,

    // 3750: Print Text
    TXT, (s32)&scenario_text_1B98,

    // 3758: Print Text
    TXT, (s32)&scenario_text_1BCB,

    // 3760: Print Text
    TXT, (s32)&scenario_text_080F,

    // 3768: Print Text
    TXT, (s32)&scenario_text_006F,

    // 3770: Print Text
    TXT, (s32)&scenario_text_1C36,

    // 3778: Print Text
    TXT, (s32)&scenario_text_1C4E,

    // 3780: Print Text
    TXT, (s32)&scenario_text_006F,

    // 3788: Print Text
    TXT, (s32)&scenario_text_1CAA,

    // 3790: Print Text
    TXT, (s32)&scenario_text_1CF0,

    // 3798: Print Text
    TXT, (s32)&scenario_text_0A09,

    // 37a0: Set Flag 03c (Heard about Sudden Impact Training from Plasma)
    // SFG, 0x3C,

    // 37a8: Print Text
    TXT, (s32)&scenario_text_0453,

    // 37b0: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_288_37b4[] = {

    // Address: @37b4

    // 37b4: Print Text
    TXT, (s32)&scenario_text_1D57,

    // 37bc: Print Text
    TXT, (s32)&scenario_text_1D96,

    // 37c4: Print Text
    TXT, (s32)&scenario_text_006F,

    // 37cc: Print Text
    TXT, (s32)&scenario_text_1DEA,

    // 37d4: Print Text
    TXT, (s32)&scenario_text_1E30,

    // 37dc: Print Text
    TXT, (s32)&scenario_text_0453,

    // 37e4: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_288_37e8[] = {

    // Address: @37e8

    // 37e8: If Flag 042 (Plasma will tell you about Silver Weapons), Jump To @3860
    // Jump if flag 0x42 is SET to @3860
    JFS, 0x42, (s32)&scenario_code_message_288_3860,

    // 37f4: Print Text
    TXT, (s32)&scenario_text_1E75,

    // 37fc: Print Text
    TXT, (s32)&scenario_text_1EA1,

    // 3804: Print Text
    TXT, (s32)&scenario_text_1EDC,

    // 380c: Print Text
    TXT, (s32)&scenario_text_1F33,

    // 3814: Print Text
    TXT, (s32)&scenario_text_006F,

    // 381c: Print Text
    TXT, (s32)&scenario_text_1F73,

    // 3824: Print Text
    TXT, (s32)&scenario_text_1F9A,

    // 382c: Print Text
    TXT, (s32)&scenario_text_006F,

    // 3834: Print Text
    TXT, (s32)&scenario_text_1FDB,

    // 383c: Print Text
    TXT, (s32)&scenario_text_201E,

    // 3844: Print Text
    TXT, (s32)&scenario_text_2061,

    // 384c: Print Text
    TXT, (s32)&scenario_text_20A5,

    // 3854: Print Text
    TXT, (s32)&scenario_text_0453,

    // 385c: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_288_3860[] = {

    // Address: @3860

    // 3860: If Flag 011 (Mokubei Can Upgrade Weapons), Jump To @38e0
    // Jump if flag 0x11 is SET to @38e0
    JFS, 0x11, (s32)&scenario_code_message_288_38e0,

    // 386c: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // 3874: Store Value: 1
    WTS, 0x1,

    // 387c: Print Text
    TXT, (s32)&scenario_text_20DE,

    // 3884: Print Text
    TXT, (s32)&scenario_text_2113,

    // 388c: Print Text
    TXT, (s32)&scenario_text_214A,

    // 3894: Print Text
    TXT, (s32)&scenario_text_080F,

    // 389c: Print Text
    TXT, (s32)&scenario_text_006F,

    // 38a4: Print Text
    TXT, (s32)&scenario_text_21D6,

    // 38ac: Print Text
    TXT, (s32)&scenario_text_2207,

    // 38b4: Print Text
    TXT, (s32)&scenario_text_223C,

    // 38bc: Print Text
    TXT, (s32)&scenario_text_227C,

    // 38c4: Set Flag 041 (Heard about Silver Weapons from Plasma)
    // SFG, 0x41,

    // 38cc: Set Flag 011 (Mokubei Can Upgrade Weapons)
    // SFG, 0x11,

    // 38d4: Print Text
    TXT, (s32)&scenario_text_0453,

    // 38dc: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_288_38e0[] = {

    // Address: @38e0

    // 38e0: If Flag 012 (Upgraded to Silver Weapons), Jump To @3918
    // Jump if flag 0x12 is SET to @3918
    JFS, 0x12, (s32)&scenario_code_message_288_3918,

    // 38ec: Print Text
    TXT, (s32)&scenario_text_22BD,

    // 38f4: Print Text
    TXT, (s32)&scenario_text_2315,

    // 38fc: Print Text
    TXT, (s32)&scenario_text_2345,

    // 3904: Print Text
    TXT, (s32)&scenario_text_0A09,

    // 390c: Print Text
    TXT, (s32)&scenario_text_0453,

    // 3914: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_288_3918[] = {

    // Address: @3918

    // 3918: If Flag 015 (Met Ghost of Wise Man), Jump To @3950
    // Jump if flag 0x15 is SET to @3950
    JFS, 0x15, (s32)&scenario_code_message_288_3950,

    // 3924: Print Text
    TXT, (s32)&scenario_text_23A6,

    // 392c: Print Text
    TXT, (s32)&scenario_text_23E5,

    // 3934: Print Text
    TXT, (s32)&scenario_text_241B,

    // 393c: Print Text
    TXT, (s32)&scenario_text_0A09,

    // 3944: Print Text
    TXT, (s32)&scenario_text_0453,

    // 394c: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_288_3950[] = {

    // Address: @3950

    // 3950: If Flag 01f (Obtained Mermaid Magic), Jump To @3a7c
    // Jump if flag 0x1F is SET to @3a7c
    JFS, 0x1F, (s32)&scenario_code_message_288_3a7c,

    // 395c: If Flag 043 (Plasma told you to go to Festival Village once already), Jump To @39d4
    // Jump if flag 0x43 is SET to @39d4
    JFS, 0x43, (s32)&scenario_code_message_288_39d4,

    // 3968: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // 3970: Store Value: 1
    WTS, 0x1,

    // 3978: Print Text
    TXT, (s32)&scenario_text_2493,

    // 3980: Print Text
    TXT, (s32)&scenario_text_24D6,

    // 3988: Print Text
    TXT, (s32)&scenario_text_2504,

    // 3990: Print Text
    TXT, (s32)&scenario_text_2546,

    // 3998: Print Text
    TXT, (s32)&scenario_text_006F,

    // 39a0: Print Text
    TXT, (s32)&scenario_text_2587,

    // 39a8: Print Text
    TXT, (s32)&scenario_text_25B5,

    // 39b0: Print Text
    TXT, (s32)&scenario_text_25E4,

    // 39b8: Print Text
    TXT, (s32)&scenario_text_0A09,

    // 39c0: Set Flag 043 (Plasma told you to go to Festival Village once already)
    // SFG, 0x43,

    // 39c8: Print Text
    TXT, (s32)&scenario_text_0453,

    // 39d0: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_288_39d4[] = {

    // Address: @39d4

    // 39d4: If Flag 044 (Plasma will tell you about the Waterfall of Kegon), Jump To @3a34
    // Jump if flag 0x44 is SET to @3a34
    JFS, 0x44, (s32)&scenario_code_message_288_3a34,

    // 39e0: Print Text
    TXT, (s32)&scenario_text_2655,

    // 39e8: Print Text
    TXT, (s32)&scenario_text_268A,

    // 39f0: Print Text
    TXT, (s32)&scenario_text_006F,

    // 39f8: Print Text
    TXT, (s32)&scenario_text_26DE,

    // 3a00: Print Text
    TXT, (s32)&scenario_text_006F,

    // 3a08: Print Text
    TXT, (s32)&scenario_text_2739,

    // 3a10: Print Text
    TXT, (s32)&scenario_text_2761,

    // 3a18: Print Text
    TXT, (s32)&scenario_text_27A5,

    // 3a20: Set Flag 044 (Plasma will tell you about the Waterfall of Kegon)
    // SFG, 0x44,

    // 3a28: Print Text
    TXT, (s32)&scenario_text_0453,

    // 3a30: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_288_3a34[] = {

    // Address: @3a34

    // 3a34: If Flag 01f (Obtained Mermaid Magic), Jump To @3a7c
    // Jump if flag 0x1F is SET to @3a7c
    JFS, 0x1F, (s32)&scenario_code_message_288_3a7c,

    // 3a40: Print Text
    TXT, (s32)&scenario_text_27ED,

    // 3a48: Print Text
    TXT, (s32)&scenario_text_282D,

    // 3a50: Print Text
    TXT, (s32)&scenario_text_006F,

    // 3a58: Print Text
    TXT, (s32)&scenario_text_288B,

    // 3a60: Print Text
    TXT, (s32)&scenario_text_28B9,

    // 3a68: Print Text
    TXT, (s32)&scenario_text_28F6,

    // 3a70: Print Text
    TXT, (s32)&scenario_text_0453,

    // 3a78: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_288_3a7c[] = {

    // Address: @3a7c

    // 3a7c: If Flag 032 (Defeated Thaisamba), Jump To @3acc
    // Jump if flag 0x32 is SET to @3acc
    JFS, 0x32, (s32)&scenario_code_message_288_3acc,

    // 3a88: Print Text
    TXT, (s32)&scenario_text_2934,

    // 3a90: Print Text
    TXT, (s32)&scenario_text_296A,

    // 3a98: Print Text
    TXT, (s32)&scenario_text_29AF,

    // 3aa0: Print Text
    TXT, (s32)&scenario_text_006F,

    // 3aa8: Print Text
    TXT, (s32)&scenario_text_29E9,

    // 3ab0: Print Text
    TXT, (s32)&scenario_text_2A2D,

    // 3ab8: Print Text
    TXT, (s32)&scenario_text_0A09,

    // 3ac0: Print Text
    TXT, (s32)&scenario_text_0453,

    // 3ac8: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_288_3acc[] = {

    // Address: @3acc

    // 3acc: If Flag 023 (Heard about Kihachi from Benkei), Jump To @3b48
    // Jump if flag 0x23 is SET to @3b48
    JFS, 0x23, (s32)&scenario_code_message_288_3b48,

    // 3ad8: If Flag 045 (Plasma will tell you to ask Benkei about Miracle Snow), Jump To @3b18
    // Jump if flag 0x45 is SET to @3b18
    JFS, 0x45, (s32)&scenario_code_message_288_3b18,

    // 3ae4: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // 3aec: Store Value: 1
    WTS, 0x1,

    // 3af4: Print Text
    TXT, (s32)&scenario_text_2AA6,

    // 3afc: Print Text
    TXT, (s32)&scenario_text_0A09,

    // 3b04: Set Flag 045 (Plasma will tell you to ask Benkei about Miracle Snow)
    // SFG, 0x45,

    // 3b0c: Print Text
    TXT, (s32)&scenario_text_0453,

    // 3b14: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_288_3b18[] = {

    // Address: @3b18

    // 3b18: If Flag 023 (Heard about Kihachi from Benkei), Jump To @3b48
    // Jump if flag 0x23 is SET to @3b48
    JFS, 0x23, (s32)&scenario_code_message_288_3b48,

    // 3b24: Print Text
    TXT, (s32)&scenario_text_2B30,

    // 3b2c: Print Text
    TXT, (s32)&scenario_text_2B74,

    // 3b34: Print Text
    TXT, (s32)&scenario_text_2BB3,

    // 3b3c: Print Text
    TXT, (s32)&scenario_text_0453,

    // 3b44: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_288_3b48[] = {

    // Address: @3b48

    // 3b48: If Flag 022 (Looking for Kihachi's Favorite Food), Jump To @3b80
    // Jump if flag 0x22 is SET to @3b80
    JFS, 0x22, (s32)&scenario_code_message_288_3b80,

    // 3b54: Print Text
    TXT, (s32)&scenario_text_2BEF,

    // 3b5c: Print Text
    TXT, (s32)&scenario_text_2C2B,

    // 3b64: Print Text
    TXT, (s32)&scenario_text_2C6A,

    // 3b6c: Print Text
    TXT, (s32)&scenario_text_2C9F,

    // 3b74: Print Text
    TXT, (s32)&scenario_text_0453,

    // 3b7c: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_288_3b80[] = {

    // Address: @3b80

    // 3b80: If Flag 024 (Learned Kihachi's Favorite Food), Jump To @3bd0
    // Jump if flag 0x24 is SET to @3bd0
    JFS, 0x24, (s32)&scenario_code_message_288_3bd0,

    // 3b8c: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // 3b94: Store Value: 1
    WTS, 0x1,

    // 3b9c: Print Text
    TXT, (s32)&scenario_text_2CF1,

    // 3ba4: Print Text
    TXT, (s32)&scenario_text_2D30,

    // 3bac: Print Text
    TXT, (s32)&scenario_text_2D6D,

    // 3bb4: Print Text
    TXT, (s32)&scenario_text_2DAB,

    // 3bbc: Set Flag 024 (Learned Kihachi's Favorite Food)
    // SFG, 0x24,

    // 3bc4: Print Text
    TXT, (s32)&scenario_text_0453,

    // 3bcc: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_288_3bd0[] = {

    // Address: @3bd0

    // 3bd0: If Flag 027 (Obtained Key to Training from Priest), Jump To @3c38
    // Jump if flag 0x27 is SET to @3c38
    JFS, 0x27, (s32)&scenario_code_message_288_3c38,

    // 3bdc: Print Text
    TXT, (s32)&scenario_text_2DE7,

    // 3be4: Print Text
    TXT, (s32)&scenario_text_2E2D,

    // 3bec: Print Text
    TXT, (s32)&scenario_text_2E6E,

    // 3bf4: Print Text
    TXT, (s32)&scenario_text_006F,

    // 3bfc: Print Text
    TXT, (s32)&scenario_text_2EC6,

    // 3c04: Print Text
    TXT, (s32)&scenario_text_2EF7,

    // 3c0c: Print Text
    TXT, (s32)&scenario_text_2F2C,

    // 3c14: Print Text
    TXT, (s32)&scenario_text_006F,

    // 3c1c: Print Text
    TXT, (s32)&scenario_text_2F7F,

    // 3c24: Print Text
    TXT, (s32)&scenario_text_2FB8,

    // 3c2c: Print Text
    TXT, (s32)&scenario_text_0453,

    // 3c34: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_288_3c38[] = {

    // Address: @3c38

    // 3c38: If Flag 020 (Obtained Super Jump Magic), Jump To @3c68
    // Jump if flag 0x20 is SET to @3c68
    JFS, 0x20, (s32)&scenario_code_message_288_3c68,

    // 3c44: Print Text
    TXT, (s32)&scenario_text_2FFC,

    // 3c4c: Print Text
    TXT, (s32)&scenario_text_3040,

    // 3c54: Print Text
    TXT, (s32)&scenario_text_0A09,

    // 3c5c: Print Text
    TXT, (s32)&scenario_text_0453,

    // 3c64: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_288_3c68[] = {

    // Address: @3c68

    // 3c68: If Flag 00f (Received Cucumber), Jump To @3cb0
    // Jump if flag 0x0F is SET to @3cb0
    JFS, 0x0F, (s32)&scenario_code_message_288_3cb0,

    // 3c74: Print Text
    TXT, (s32)&scenario_text_30B1,

    // 3c7c: Print Text
    TXT, (s32)&scenario_text_30F4,

    // 3c84: Print Text
    TXT, (s32)&scenario_text_3122,

    // 3c8c: Print Text
    TXT, (s32)&scenario_text_006F,

    // 3c94: Print Text
    TXT, (s32)&scenario_text_3171,

    // 3c9c: Print Text
    TXT, (s32)&scenario_text_31B3,

    // 3ca4: Print Text
    TXT, (s32)&scenario_text_0453,

    // 3cac: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_288_3cb0[] = {

    // Address: @3cb0

    // 3cb0: If Flag 035 (Obtained Miracle Snow), Jump To @3cd8
    // Jump if flag 0x35 is SET to @3cd8
    JFS, 0x35, (s32)&scenario_code_message_288_3cd8,

    // 3cbc: Print Text
    TXT, (s32)&scenario_text_31F0,

    // 3cc4: Print Text
    TXT, (s32)&scenario_text_322E,

    // 3ccc: Print Text
    TXT, (s32)&scenario_text_0453,

    // 3cd4: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_288_3cd8[] = {

    // Address: @3cd8

    // 3cd8: If Flag 046 (Plasma has no more advice), Jump To @3d50
    // Jump if flag 0x46 is SET to @3d50
    JFS, 0x46, (s32)&scenario_code_message_288_3d50,

    // 3ce4: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // 3cec: Store Value: 1
    WTS, 0x1,

    // 3cf4: Print Text
    TXT, (s32)&scenario_text_3284,

    // 3cfc: Print Text
    TXT, (s32)&scenario_text_32C9,

    // 3d04: Print Text
    TXT, (s32)&scenario_text_330E,

    // 3d0c: Print Text
    TXT, (s32)&scenario_text_006F,

    // 3d14: Print Text
    TXT, (s32)&scenario_text_3349,

    // 3d1c: Print Text
    TXT, (s32)&scenario_text_3379,

    // 3d24: Print Text
    TXT, (s32)&scenario_text_006F,

    // 3d2c: Print Text
    TXT, (s32)&scenario_text_33C8,

    // 3d34: Print Text
    TXT, (s32)&scenario_text_33FC,

    // 3d3c: Set Flag 046 (Plasma has no more advice)
    // SFG, 0x46,

    // 3d44: Print Text
    TXT, (s32)&scenario_text_0453,

    // 3d4c: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_288_3d50[] = {

    // Address: @3d50

    // 3d50: Print Text
    TXT, (s32)&scenario_text_3454,

    // 3d58: Print Text
    TXT, (s32)&scenario_text_3481,

    // 3d60: Print Text
    TXT, (s32)&scenario_text_006F,

    // 3d68: Print Text
    TXT, (s32)&scenario_text_34CA,

    // 3d70: Print Text
    TXT, (s32)&scenario_text_3503,

    // 3d78: Print Text
    TXT, (s32)&scenario_text_3542,

    // 3d80: Print Text
    TXT, (s32)&scenario_text_3596,

    // 3d88: Print Text
    TXT, (s32)&scenario_text_006F,

    // 3d90: Print Text
    TXT, (s32)&scenario_text_35F6,

    // 3d98: Print Text
    TXT, (s32)&scenario_text_363F,

    // 3da0: Print Text
    TXT, (s32)&scenario_text_3670,

    // 3da8: Print Text
    TXT, (s32)&scenario_text_36A3,

    // 3db0: Print Text
    TXT, (s32)&scenario_text_0453,

    // 3db8: End Event
    END,

    // End scenario script
    END,
};

