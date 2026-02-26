
#include "types.h"
#include "scenario.h"
#include "scenario_replacer.h"

// Function declarations
void update_wise_man_sogen_text(void);

// Forward declarations
s32 scenario_code_31dc[];
s32 scenario_code_31f0[];
s32 scenario_code_3290[];
s32 scenario_code_32f4[];
s32 scenario_code_3358[];
s32 scenario_code_33bc[];
s32 scenario_code_3428[];
s32 scenario_code_3a14[];
s32 scenario_code_3c30[];

// ==================== TEXT STRINGS ====================

// Omitsu:Good luck, everyone!{endline}
static s16 scenario_text_0000[] = {
    CHR_O, CHR_m, CHR_i, CHR_t, CHR_s, CHR_u, PCT_COLON, CHR_G, CHR_o, CHR_o, 
    CHR_d, PCT_SPACE, CHR_l, CHR_u, CHR_c, CHR_k, PCT_COMMA, PCT_SPACE, CHR_e, CHR_v, 
    CHR_e, CHR_r, CHR_y, CHR_o, CHR_n, CHR_e, PCT_EXCLAMATION, CTR_ENDLINE};

// {waitinput}{end}{endline}
static s16 scenario_text_0038[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE};

// {begin}{endline}
static s16 scenario_text_0065[] = {
    CTR_BEGIN, CTR_ENDLINE};

// Wise Man::Hey! {em-yellow}Goemon{/em}, it's you!{button}{end}{endline}
static s16 scenario_text_0089[] = {
    CHR_W, CHR_i, CHR_s, CHR_e, PCT_SPACE, CHR_M, CHR_a, CHR_n, PCT_COLON, PCT_COLON, 
    CHR_H, CHR_e, CHR_y, PCT_EXCLAMATION, PCT_SPACE, CTR_EM_YELLOW, CHR_G, CHR_o, CHR_e, CHR_m, 
    CHR_o, CHR_n, CTR_CLOSE_EM, PCT_COMMA, PCT_SPACE, CHR_i, CHR_t, PCT_APOSTROPHE, CHR_s, PCT_SPACE, 
    CHR_y, CHR_o, CHR_u, PCT_EXCLAMATION, CTR_BUTTON, CTR_END, CTR_ENDLINE};

// {begin}{endline}
static s16 scenario_text_00E3[] = {
    CTR_BEGIN, CTR_ENDLINE};

// Goemon:What?! {em-yellow}Wise Man{/em}!{button}{endline}
static s16 scenario_text_0107[] = {
    CHR_G, CHR_o, CHR_e, CHR_m, CHR_o, CHR_n, PCT_COLON, CHR_W, CHR_h, CHR_a, 
    CHR_t, PCT_QUESTION, PCT_EXCLAMATION, PCT_SPACE, CTR_EM_YELLOW, CHR_W, CHR_i, CHR_s, CHR_e, PCT_SPACE, 
    CHR_M, CHR_a, CHR_n, CTR_CLOSE_EM, PCT_EXCLAMATION, CTR_BUTTON, CTR_ENDLINE};

// Wise Man::Hey! {em-yellow}Ebisumaru{/em}, it's you!{button}{end}{endline}
static s16 scenario_text_0153[] = {
    CHR_W, CHR_i, CHR_s, CHR_e, PCT_SPACE, CHR_M, CHR_a, CHR_n, PCT_COLON, PCT_COLON, 
    CHR_H, CHR_e, CHR_y, PCT_EXCLAMATION, PCT_SPACE, CTR_EM_YELLOW, CHR_E, CHR_b, CHR_i, CHR_s, 
    CHR_u, CHR_m, CHR_a, CHR_r, CHR_u, CTR_CLOSE_EM, PCT_COMMA, PCT_SPACE, CHR_i, CHR_t, 
    PCT_APOSTROPHE, CHR_s, PCT_SPACE, CHR_y, CHR_o, CHR_u, PCT_EXCLAMATION, CTR_BUTTON, CTR_END, CTR_ENDLINE};

// {begin}{endline}
static s16 scenario_text_01B0[] = {
    CTR_BEGIN, CTR_ENDLINE};

// Ebisumaru:Huh?! {em-yellow}Wise Man{/em}!{button}{endline}
static s16 scenario_text_01D4[] = {
    CHR_E, CHR_b, CHR_i, CHR_s, CHR_u, CHR_m, CHR_a, CHR_r, CHR_u, PCT_COLON, 
    CHR_H, CHR_u, CHR_h, PCT_QUESTION, PCT_EXCLAMATION, PCT_SPACE, CTR_EM_YELLOW, CHR_W, CHR_i, CHR_s, 
    CHR_e, PCT_SPACE, CHR_M, CHR_a, CHR_n, CTR_CLOSE_EM, PCT_EXCLAMATION, CTR_BUTTON, CTR_ENDLINE};

// Wise Man::Hey! {em-yellow}Yae{/em}, it's you!{button}{end}{endline}
static s16 scenario_text_0222[] = {
    CHR_W, CHR_i, CHR_s, CHR_e, PCT_SPACE, CHR_M, CHR_a, CHR_n, PCT_COLON, PCT_COLON, 
    CHR_H, CHR_e, CHR_y, PCT_EXCLAMATION, PCT_SPACE, CTR_EM_YELLOW, CHR_Y, CHR_a, CHR_e, CTR_CLOSE_EM, 
    PCT_COMMA, PCT_SPACE, CHR_i, CHR_t, PCT_APOSTROPHE, CHR_s, PCT_SPACE, CHR_y, CHR_o, CHR_u, 
    PCT_EXCLAMATION, CTR_BUTTON, CTR_END, CTR_ENDLINE};

// {begin}{endline}
static s16 scenario_text_0279[] = {
    CTR_BEGIN, CTR_ENDLINE};

// Yae:It can't be! {em-yellow}Wise Man{/em}?!{button}{endline}
static s16 scenario_text_029D[] = {
    CHR_Y, CHR_a, CHR_e, PCT_COLON, CHR_I, CHR_t, PCT_SPACE, CHR_c, CHR_a, CHR_n, 
    PCT_APOSTROPHE, CHR_t, PCT_SPACE, CHR_b, CHR_e, PCT_EXCLAMATION, PCT_SPACE, CTR_EM_YELLOW, CHR_W, 
    CHR_i, 
    CHR_s, CHR_e, PCT_SPACE, CHR_M, CHR_a, CHR_n, CTR_CLOSE_EM, PCT_QUESTION, PCT_EXCLAMATION, CTR_BUTTON, 
    CTR_ENDLINE};

// Wise Man:Whoah! {em-yellow}Sasuke{/em}, it's you!{button}{end}{endline}
static s16 scenario_text_02ED[] = {
    CHR_W, CHR_i, CHR_s, CHR_e, PCT_SPACE, CHR_M, CHR_a, CHR_n, PCT_COLON, CHR_W, 
    CHR_h, CHR_o, CHR_a, CHR_h, PCT_EXCLAMATION, PCT_SPACE, CTR_EM_YELLOW, CHR_S, CHR_a, CHR_s, 
    CHR_u, CHR_k, CHR_e, CTR_CLOSE_EM, PCT_COMMA, PCT_SPACE, CHR_i, CHR_t, PCT_APOSTROPHE, CHR_s, 
    PCT_SPACE, CHR_y, CHR_o, CHR_u, PCT_EXCLAMATION, CTR_BUTTON, CTR_END, CTR_ENDLINE};

// {begin}{endline}
static s16 scenario_text_0348[] = {
    CTR_BEGIN, CTR_ENDLINE};

// Sasuke:Hey!{newline}{endline}
static s16 scenario_text_036C[] = {
    CHR_S, CHR_a, CHR_s, CHR_u, CHR_k, CHR_e, PCT_COLON, CHR_H, CHR_e, CHR_y, 
    PCT_EXCLAMATION, CTR_NEWLINE, CTR_ENDLINE};

//       If it's not my {em-yellow}ol' man{/em}!{button}{endline}
static s16 scenario_text_039D[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_I, CHR_f, PCT_SPACE, CHR_i, 
    CHR_t, PCT_APOSTROPHE, CHR_s, PCT_SPACE, CHR_n, CHR_o, CHR_t, PCT_SPACE, CHR_m, CHR_y, 
    PCT_SPACE, CTR_EM_YELLOW, CHR_o, CHR_l, PCT_APOSTROPHE, PCT_SPACE, CHR_m, CHR_a, CHR_n, CTR_CLOSE_EM, 
    PCT_EXCLAMATION, CTR_BUTTON, CTR_ENDLINE};

// {newwindow}{endline}
static s16 scenario_text_03EF[] = {
    CTR_NEWWINDOW, CTR_ENDLINE};

// Sasuke:It is!{newline}{endline}
static s16 scenario_text_0417[] = {
    CHR_S, CHR_a, CHR_s, CHR_u, CHR_k, CHR_e, PCT_COLON, CHR_I, CHR_t, PCT_SPACE, 
    CHR_i, CHR_s, PCT_EXCLAMATION, CTR_NEWLINE, CTR_ENDLINE};

//       It's my ol' man, {em-yellow}Wise Man{/em}!{newline}{endline}
static s16 scenario_text_044A[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_I, CHR_t, PCT_APOSTROPHE, CHR_s, 
    PCT_SPACE, CHR_m, CHR_y, PCT_SPACE, CHR_o, CHR_l, PCT_APOSTROPHE, PCT_SPACE, CHR_m, CHR_a, 
    CHR_n, PCT_COMMA, PCT_SPACE, CTR_EM_YELLOW, CHR_W, CHR_i, CHR_s, CHR_e, PCT_SPACE, CHR_M, 
    CHR_a, CHR_n, CTR_CLOSE_EM, PCT_EXCLAMATION, CTR_NEWLINE, CTR_ENDLINE};

//       I am just overjoyed to{newline}{endline}
static s16 scenario_text_04A0[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_I, PCT_SPACE, CHR_a, CHR_m, 
    PCT_SPACE, CHR_j, CHR_u, CHR_s, CHR_t, PCT_SPACE, CHR_o, CHR_v, CHR_e, CHR_r, 
    CHR_j, CHR_o, CHR_y, CHR_e, CHR_d, PCT_SPACE, CHR_t, CHR_o, CTR_NEWLINE, CTR_ENDLINE};

//       see you!{button}{endline}
static s16 scenario_text_04E2[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_s, CHR_e, CHR_e, PCT_SPACE, 
    CHR_y, CHR_o, CHR_u, PCT_EXCLAMATION, CTR_BUTTON, CTR_ENDLINE};

// {newwindow}{endline}
static s16 scenario_text_0515[] = {
    CTR_NEWWINDOW, CTR_ENDLINE};

// Goemon:But I thought{newline}{endline}
static s16 scenario_text_053D[] = {
    CHR_G, CHR_o, CHR_e, CHR_m, CHR_o, CHR_n, PCT_COLON, CHR_B, CHR_u, CHR_t, 
    PCT_SPACE, CHR_I, PCT_SPACE, CHR_t, CHR_h, CHR_o, CHR_u, CHR_g, CHR_h, CHR_t, 
    CTR_NEWLINE, CTR_ENDLINE};

//       Wise Man died.{button}{end}{endline}
static s16 scenario_text_0577[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_W, CHR_i, CHR_s, CHR_e, 
    PCT_SPACE, CHR_M, CHR_a, CHR_n, PCT_SPACE, CHR_d, CHR_i, CHR_e, CHR_d, PCT_PERIOD, 
    CTR_BUTTON, CTR_END, CTR_ENDLINE};

// {begin}{endline}
static s16 scenario_text_05B5[] = {
    CTR_BEGIN, CTR_ENDLINE};

// Wise Man:You couldn't be further{newline}{endline}
static s16 scenario_text_05D9[] = {
    CHR_W, CHR_i, CHR_s, CHR_e, PCT_SPACE, CHR_M, CHR_a, CHR_n, PCT_COLON, CHR_Y, 
    CHR_o, CHR_u, PCT_SPACE, CHR_c, CHR_o, CHR_u, CHR_l, CHR_d, CHR_n, PCT_APOSTROPHE, 
    CHR_t, PCT_SPACE, CHR_b, CHR_e, PCT_SPACE, CHR_f, CHR_u, CHR_r, CHR_t, CHR_h, 
    CHR_e, CHR_r, CTR_NEWLINE, CTR_ENDLINE};

//       from the truth!{newline}{endline}
static s16 scenario_text_061F[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_f, CHR_r, CHR_o, CHR_m, 
    PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE, CHR_t, CHR_r, CHR_u, CHR_t, CHR_h, 
    PCT_EXCLAMATION, CTR_NEWLINE, CTR_ENDLINE};

//       Just look at me,{newline}{endline}
static s16 scenario_text_065A[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_J, CHR_u, CHR_s, CHR_t, 
    PCT_SPACE, CHR_l, CHR_o, CHR_o, CHR_k, PCT_SPACE, CHR_a, CHR_t, PCT_SPACE, CHR_m, 
    CHR_e, PCT_COMMA, CTR_NEWLINE, CTR_ENDLINE};

//       I'm as {em-yellow}healthy{/em} as ever!{button}{end}{endline}
static s16 scenario_text_0696[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_I, PCT_APOSTROPHE, CHR_m, PCT_SPACE, 
    CHR_a, CHR_s, PCT_SPACE, CTR_EM_YELLOW, CHR_h, CHR_e, CHR_a, CHR_l, CHR_t, CHR_h, 
    CHR_y, CTR_CLOSE_EM, PCT_SPACE, CHR_a, CHR_s, PCT_SPACE, CHR_e, CHR_v, CHR_e, CHR_r, 
    PCT_EXCLAMATION, CTR_BUTTON, CTR_END, CTR_ENDLINE};

// {begin}{endline}
static s16 scenario_text_06ED[] = {
    CTR_BEGIN, CTR_ENDLINE};

// Goemon:Then {em-yellow}who{/em} was the spirit{newline}{endline}
static s16 scenario_text_0711[] = {
    CHR_G, CHR_o, CHR_e, CHR_m, CHR_o, CHR_n, PCT_COLON, CHR_T, CHR_h, CHR_e, 
    CHR_n, PCT_SPACE, CTR_EM_YELLOW, CHR_w, CHR_h, CHR_o, CTR_CLOSE_EM, PCT_SPACE, CHR_w, CHR_a, 
    CHR_s, PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE, CHR_s, CHR_p, CHR_i, CHR_r, 
    CHR_i, CHR_t, CTR_NEWLINE, CTR_ENDLINE};

//       the {em-yellow}Witch{/em} called for us?{endline}
static s16 scenario_text_0765[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE, 
    CTR_EM_YELLOW, CHR_W, CHR_i, CHR_t, CHR_c, CHR_h, CTR_CLOSE_EM, PCT_SPACE, CHR_c, CHR_a, 
    CHR_l, CHR_l, CHR_e, CHR_d, PCT_SPACE, CHR_f, CHR_o, CHR_r, PCT_SPACE, CHR_u, 
    CHR_s, PCT_QUESTION, CTR_ENDLINE};

// {button}{endline}
static s16 scenario_text_07B0[] = {
    CTR_BUTTON, CTR_ENDLINE};

// {newwindow}{endline}
static s16 scenario_text_07D5[] = {
    CTR_NEWWINDOW, CTR_ENDLINE};

// Yae:Yes, there is something{newline}{endline}
static s16 scenario_text_07FD[] = {
    CHR_Y, CHR_a, CHR_e, PCT_COLON, CHR_Y, CHR_e, CHR_s, PCT_COMMA, PCT_SPACE, CHR_t, 
    CHR_h, CHR_e, CHR_r, CHR_e, PCT_SPACE, CHR_i, CHR_s, PCT_SPACE, CHR_s, CHR_o, 
    CHR_m, CHR_e, CHR_t, CHR_h, CHR_i, CHR_n, CHR_g, CTR_NEWLINE, CTR_ENDLINE};

//       strange about that,{newline}{endline}
static s16 scenario_text_083E[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_s, CHR_t, CHR_r, CHR_a, 
    CHR_n, CHR_g, CHR_e, PCT_SPACE, CHR_a, CHR_b, CHR_o, CHR_u, CHR_t, PCT_SPACE, 
    CHR_t, CHR_h, CHR_a, CHR_t, PCT_COMMA, CTR_NEWLINE, CTR_ENDLINE};

//       but let's not worry{newline}{endline}
static s16 scenario_text_087D[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_b, CHR_u, CHR_t, PCT_SPACE, 
    CHR_l, CHR_e, CHR_t, PCT_APOSTROPHE, CHR_s, PCT_SPACE, CHR_n, CHR_o, CHR_t, PCT_SPACE, 
    CHR_w, CHR_o, CHR_r, CHR_r, CHR_y, CTR_NEWLINE, CTR_ENDLINE};

//       about it now.{newline}{endline}
static s16 scenario_text_08BC[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_a, CHR_b, CHR_o, CHR_u, 
    CHR_t, PCT_SPACE, CHR_i, CHR_t, PCT_SPACE, CHR_n, CHR_o, CHR_w, PCT_PERIOD, CTR_NEWLINE, 
    CTR_ENDLINE};

// {button}{endline}
static s16 scenario_text_08F5[] = {
    CTR_BUTTON, CTR_ENDLINE};

// {newwindow}{endline}
static s16 scenario_text_091A[] = {
    CTR_NEWWINDOW, CTR_ENDLINE};

// Yae:But what are you doing here?!{button}{end}{endline}
static s16 scenario_text_0942[] = {
    CHR_Y, CHR_a, CHR_e, PCT_COLON, CHR_B, CHR_u, CHR_t, PCT_SPACE, CHR_w, CHR_h, 
    CHR_a, CHR_t, PCT_SPACE, CHR_a, CHR_r, CHR_e, PCT_SPACE, CHR_y, CHR_o, CHR_u, 
    PCT_SPACE, CHR_d, CHR_o, CHR_i, CHR_n, CHR_g, PCT_SPACE, CHR_h, CHR_e, CHR_r, 
    CHR_e, PCT_QUESTION, PCT_EXCLAMATION, CTR_BUTTON, CTR_END, CTR_ENDLINE};

// {begin}{endline}
static s16 scenario_text_098D[] = {
    CTR_BEGIN, CTR_ENDLINE};

// Wise Man:Well... I was caught by {newline}{endline}
static s16 scenario_text_09B1[] = {
    CHR_W, CHR_i, CHR_s, CHR_e, PCT_SPACE, CHR_M, CHR_a, CHR_n, PCT_COLON, CHR_W, 
    CHR_e, CHR_l, CHR_l, PCT_PERIOD, PCT_PERIOD, PCT_PERIOD, PCT_SPACE, CHR_I, PCT_SPACE, CHR_w, 
    CHR_a, CHR_s, PCT_SPACE, CHR_c, CHR_a, CHR_u, CHR_g, CHR_h, CHR_t, PCT_SPACE, 
    CHR_b, CHR_y, PCT_SPACE, CTR_NEWLINE, CTR_ENDLINE};

//       the {em-yellow}Peach Mountain guys{/em}.{button}{endline}
static s16 scenario_text_09F8[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE, 
    CTR_EM_YELLOW, CHR_P, CHR_e, CHR_a, CHR_c, CHR_h, PCT_SPACE, CHR_M, CHR_o, CHR_u, 
    CHR_n, CHR_t, CHR_a, CHR_i, CHR_n, PCT_SPACE, CHR_g, CHR_u, CHR_y, CHR_s, 
    CTR_CLOSE_EM, PCT_PERIOD, CTR_BUTTON, CTR_ENDLINE};

// {newwindow}{endline}
static s16 scenario_text_0A4B[] = {
    CTR_NEWWINDOW, CTR_ENDLINE};

// Wise Man:And... I gave them{newline}{endline}
static s16 scenario_text_0A73[] = {
    CHR_W, CHR_i, CHR_s, CHR_e, PCT_SPACE, CHR_M, CHR_a, CHR_n, PCT_COLON, CHR_A, 
    CHR_n, CHR_d, PCT_PERIOD, PCT_PERIOD, PCT_PERIOD, PCT_SPACE, CHR_I, PCT_SPACE, CHR_g, CHR_a, 
    CHR_v, CHR_e, PCT_SPACE, CHR_t, CHR_h, CHR_e, CHR_m, CTR_NEWLINE, CTR_ENDLINE};

//       {em-yellow}Mechanical Robots{/em} and{newline}{endline}
static s16 scenario_text_0AB4[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CTR_EM_YELLOW, CHR_M, CHR_e, CHR_c, 
    CHR_h, CHR_a, CHR_n, CHR_i, CHR_c, CHR_a, CHR_l, PCT_SPACE, CHR_R, CHR_o, 
    CHR_b, CHR_o, CHR_t, CHR_s, CTR_CLOSE_EM, PCT_SPACE, CHR_a, CHR_n, CHR_d, CTR_NEWLINE, 
    CTR_ENDLINE};

//       an {em-yellow}Instant Stage Beam{/em}...{button}{endline}
static s16 scenario_text_0B05[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_a, CHR_n, PCT_SPACE, CTR_EM_YELLOW, 
    CHR_I, CHR_n, CHR_s, CHR_t, CHR_a, CHR_n, CHR_t, PCT_SPACE, CHR_S, CHR_t, 
    CHR_a, CHR_g, CHR_e, PCT_SPACE, CHR_B, CHR_e, CHR_a, CHR_m, CTR_CLOSE_EM, PCT_PERIOD, 
    PCT_PERIOD, PCT_PERIOD, CTR_BUTTON, CTR_ENDLINE};

// {newwindow}{endline}
static s16 scenario_text_0B58[] = {
    CTR_NEWWINDOW, CTR_ENDLINE};

// Wise Man:Well... in exchange for{newline}{endline}
static s16 scenario_text_0B80[] = {
    CHR_W, CHR_i, CHR_s, CHR_e, PCT_SPACE, CHR_M, CHR_a, CHR_n, PCT_COLON, CHR_W, 
    CHR_e, CHR_l, CHR_l, PCT_PERIOD, PCT_PERIOD, PCT_PERIOD, PCT_SPACE, CHR_i, CHR_n, PCT_SPACE, 
    CHR_e, CHR_x, CHR_c, CHR_h, CHR_a, CHR_n, CHR_g, CHR_e, PCT_SPACE, CHR_f, 
    CHR_o, CHR_r, CTR_NEWLINE, CTR_ENDLINE};

//       a {em-yellow}muscle car{/em} poster and{newline}{endline}
static s16 scenario_text_0BC6[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_a, PCT_SPACE, CTR_EM_YELLOW, 
    CHR_m, 
    CHR_u, CHR_s, CHR_c, CHR_l, CHR_e, PCT_SPACE, CHR_c, CHR_a, CHR_r, CTR_CLOSE_EM, 
    PCT_SPACE, CHR_p, CHR_o, CHR_s, CHR_t, CHR_e, CHR_r, PCT_SPACE, CHR_a, CHR_n, 
    CHR_d, CTR_NEWLINE, CTR_ENDLINE};

//       five {em-yellow}car magazines{/em}...{newline}{endline}
static s16 scenario_text_0C19[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_f, CHR_i, CHR_v, CHR_e, 
    PCT_SPACE, CTR_EM_YELLOW, CHR_c, CHR_a, CHR_r, PCT_SPACE, CHR_m, CHR_a, CHR_g, CHR_a, 
    CHR_z, CHR_i, CHR_n, CHR_e, CHR_s, CTR_CLOSE_EM, PCT_PERIOD, PCT_PERIOD, PCT_PERIOD, CTR_NEWLINE, 
    CTR_ENDLINE};

// {button}{end}{endline}
static s16 scenario_text_0C6A[] = {
    CTR_BUTTON, CTR_END, CTR_ENDLINE};

// {begin}{endline}
static s16 scenario_text_0C94[] = {
    CTR_BEGIN, CTR_ENDLINE};

// Goemon:...{newline}{endline}
static s16 scenario_text_0CB8[] = {
    CHR_G, CHR_o, CHR_e, CHR_m, CHR_o, CHR_n, PCT_COLON, PCT_PERIOD, PCT_PERIOD, PCT_PERIOD, CTR_NEWLINE, CTR_ENDLINE};

//        {big}{em-yellow}W h a t ? ! {/em}{/big}{newline}{endline}
static s16 scenario_text_0CE8[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CTR_BIG, CTR_EM_YELLOW, 
    CHR_W, 
    PCT_SPACE, CHR_h, PCT_SPACE, CHR_a, PCT_SPACE, CHR_t, PCT_SPACE, PCT_QUESTION, PCT_SPACE, PCT_EXCLAMATION, 
    PCT_SPACE, CTR_CLOSE_EM, CTR_CLOSE_BIG, CTR_NEWLINE, CTR_ENDLINE};

// {button}{end}{endline}
static s16 scenario_text_0D3C[] = {
    CTR_BUTTON, CTR_END, CTR_ENDLINE};

// {begin}{endline}
static s16 scenario_text_0D66[] = {
    CTR_BEGIN, CTR_ENDLINE};

// Wise Man:Oh, ah, I mean{newline}{endline}
static s16 scenario_text_0D8A[] = {
    CHR_W, CHR_i, CHR_s, CHR_e, PCT_SPACE, CHR_M, CHR_a, CHR_n, PCT_COLON, CHR_O, 
    CHR_h, PCT_COMMA, PCT_SPACE, CHR_a, CHR_h, PCT_COMMA, PCT_SPACE, CHR_I, PCT_SPACE, CHR_m, 
    CHR_e, CHR_a, CHR_n, CTR_NEWLINE, CTR_ENDLINE};

//       I strongly resisted{newline}{endline}
static s16 scenario_text_0DC7[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_I, PCT_SPACE, CHR_s, CHR_t, 
    CHR_r, CHR_o, CHR_n, CHR_g, CHR_l, CHR_y, PCT_SPACE, CHR_r, CHR_e, CHR_s, 
    CHR_i, CHR_s, CHR_t, CHR_e, CHR_d, CTR_NEWLINE, CTR_ENDLINE};

//       but they {em-yellow}forced{/em} me{newline}{endline}
static s16 scenario_text_0E06[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_b, CHR_u, CHR_t, PCT_SPACE, 
    CHR_t, CHR_h, CHR_e, CHR_y, PCT_SPACE, CTR_EM_YELLOW, CHR_f, CHR_o, CHR_r, CHR_c, 
    CHR_e, CHR_d, CTR_CLOSE_EM, PCT_SPACE, CHR_m, CHR_e, CTR_NEWLINE, CTR_ENDLINE};

//       to make them.{newline}{endline}
static s16 scenario_text_0E54[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_t, CHR_o, PCT_SPACE, CHR_m, 
    CHR_a, CHR_k, CHR_e, PCT_SPACE, CHR_t, CHR_h, CHR_e, CHR_m, PCT_PERIOD, CTR_NEWLINE, 
    CTR_ENDLINE};

// {button}{end}{endline}
static s16 scenario_text_0E8D[] = {
    CTR_BUTTON, CTR_END, CTR_ENDLINE};

// {begin}{endline}
static s16 scenario_text_0EB7[] = {
    CTR_BEGIN, CTR_ENDLINE};

// Ebisumaru:Well it all makes sense{newline}{endline}
static s16 scenario_text_0EDB[] = {
    CHR_E, CHR_b, CHR_i, CHR_s, CHR_u, CHR_m, CHR_a, CHR_r, CHR_u, PCT_COLON, 
    CHR_W, CHR_e, CHR_l, CHR_l, PCT_SPACE, CHR_i, CHR_t, PCT_SPACE, CHR_a, CHR_l, 
    CHR_l, PCT_SPACE, CHR_m, CHR_a, CHR_k, CHR_e, CHR_s, PCT_SPACE, CHR_s, CHR_e, 
    CHR_n, CHR_s, CHR_e, CTR_NEWLINE, CTR_ENDLINE};

//        then, the mechanics{newline}{endline}
static s16 scenario_text_0F22[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_t, CHR_h, CHR_e, 
    CHR_n, PCT_COMMA, PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE, CHR_m, CHR_e, CHR_c, 
    CHR_h, CHR_a, CHR_n, CHR_i, CHR_c, CHR_s, CTR_NEWLINE, CTR_ENDLINE};

//        seemed so familiar.{button}{end}{endline}
static s16 scenario_text_0F62[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_s, CHR_e, CHR_e, 
    CHR_m, CHR_e, CHR_d, PCT_SPACE, CHR_s, CHR_o, PCT_SPACE, CHR_f, CHR_a, CHR_m, 
    CHR_i, CHR_l, CHR_i, CHR_a, CHR_r, PCT_PERIOD, CTR_BUTTON, CTR_END, CTR_ENDLINE};

// {begin}{endline}
static s16 scenario_text_0FA6[] = {
    CTR_BEGIN, CTR_ENDLINE};

// Wise Man:I don't know{newline}{endline}
static s16 scenario_text_0FCA[] = {
    CHR_W, CHR_i, CHR_s, CHR_e, PCT_SPACE, CHR_M, CHR_a, CHR_n, PCT_COLON, CHR_I, 
    PCT_SPACE, CHR_d, CHR_o, CHR_n, PCT_APOSTROPHE, CHR_t, PCT_SPACE, CHR_k, CHR_n, CHR_o, 
    CHR_w, CTR_NEWLINE, CTR_ENDLINE};

//        what to say.{button}{end}{endline}
static s16 scenario_text_1005[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_w, CHR_h, CHR_a, 
    CHR_t, PCT_SPACE, CHR_t, CHR_o, PCT_SPACE, CHR_s, CHR_a, CHR_y, PCT_PERIOD, CTR_BUTTON, 
    CTR_END, CTR_ENDLINE};

// {begin}{endline}
static s16 scenario_text_1042[] = {
    CTR_BEGIN, CTR_ENDLINE};

// Goemon:But that's strange.{newline}{endline}
static s16 scenario_text_1066[] = {
    CHR_G, CHR_o, CHR_e, CHR_m, CHR_o, CHR_n, PCT_COLON, CHR_B, CHR_u, CHR_t, 
    PCT_SPACE, CHR_t, CHR_h, CHR_a, CHR_t, PCT_APOSTROPHE, CHR_s, PCT_SPACE, CHR_s, CHR_t, 
    CHR_r, CHR_a, CHR_n, CHR_g, CHR_e, PCT_PERIOD, CTR_NEWLINE, CTR_ENDLINE};

//       If they {em-yellow}kidnapped you{/em},{newline}{endline}
static s16 scenario_text_10A6[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_I, CHR_f, PCT_SPACE, CHR_t, 
    CHR_h, CHR_e, CHR_y, PCT_SPACE, CTR_EM_YELLOW, CHR_k, CHR_i, CHR_d, CHR_n, CHR_a, 
    CHR_p, CHR_p, CHR_e, CHR_d, PCT_SPACE, CHR_y, CHR_o, CHR_u, CTR_CLOSE_EM, PCT_COMMA, 
    CTR_NEWLINE, CTR_ENDLINE};

//       what reason did they have{newline}{endline}
static s16 scenario_text_10F8[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_w, CHR_h, CHR_a, CHR_t, 
    PCT_SPACE, CHR_r, CHR_e, CHR_a, CHR_s, CHR_o, CHR_n, PCT_SPACE, CHR_d, CHR_i, 
    CHR_d, PCT_SPACE, CHR_t, CHR_h, CHR_e, CHR_y, PCT_SPACE, CHR_h, CHR_a, CHR_v, 
    CHR_e, CTR_NEWLINE, CTR_ENDLINE};

//       to {em-yellow}blow up your home{/em}?{button}{end}{endline}
static s16 scenario_text_113D[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_t, CHR_o, PCT_SPACE, CTR_EM_YELLOW, 
    CHR_b, CHR_l, CHR_o, CHR_w, PCT_SPACE, CHR_u, CHR_p, PCT_SPACE, CHR_y, CHR_o, 
    CHR_u, CHR_r, PCT_SPACE, CHR_h, CHR_o, CHR_m, CHR_e, CTR_CLOSE_EM, PCT_QUESTION, CTR_BUTTON, 
    CTR_END, CTR_ENDLINE};

// {begin}{endline}
static s16 scenario_text_1192[] = {
    CTR_BEGIN, CTR_ENDLINE};

// Wise Man:What did you just say?!{newline}{endline}
static s16 scenario_text_11B6[] = {
    CHR_W, CHR_i, CHR_s, CHR_e, PCT_SPACE, CHR_M, CHR_a, CHR_n, PCT_COLON, CHR_W, 
    CHR_h, CHR_a, CHR_t, PCT_SPACE, CHR_d, CHR_i, CHR_d, PCT_SPACE, CHR_y, CHR_o, 
    CHR_u, PCT_SPACE, CHR_j, CHR_u, CHR_s, CHR_t, PCT_SPACE, CHR_s, CHR_a, CHR_y, 
    PCT_QUESTION, PCT_EXCLAMATION, CTR_NEWLINE, CTR_ENDLINE};

//        My house has been{newline}{endline}
static s16 scenario_text_11FC[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_M, CHR_y, PCT_SPACE, 
    CHR_h, CHR_o, CHR_u, CHR_s, CHR_e, PCT_SPACE, CHR_h, CHR_a, CHR_s, PCT_SPACE, 
    CHR_b, CHR_e, CHR_e, CHR_n, CTR_NEWLINE, CTR_ENDLINE};

//        {em-yellow}blown up{/em}?!{button}{endline}
static s16 scenario_text_123A[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CTR_EM_YELLOW, CHR_b, 
    CHR_l, 
    CHR_o, CHR_w, CHR_n, PCT_SPACE, CHR_u, CHR_p, CTR_CLOSE_EM, PCT_QUESTION, PCT_EXCLAMATION, CTR_BUTTON, 
    CTR_ENDLINE};

// {newwindow}{endline}
static s16 scenario_text_1280[] = {
    CTR_NEWWINDOW, CTR_ENDLINE};

// Wise Man:Grrrr!{newline}{endline}
static s16 scenario_text_12A8[] = {
    CHR_W, CHR_i, CHR_s, CHR_e, PCT_SPACE, CHR_M, CHR_a, CHR_n, PCT_COLON, CHR_G, 
    CHR_r, CHR_r, CHR_r, CHR_r, PCT_EXCLAMATION, CTR_NEWLINE, CTR_ENDLINE};

//       All those {blink}{em-yellow}car magazines{/em}{/blink}{newline}{endline}
static s16 scenario_text_12DD[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_A, CHR_l, CHR_l, PCT_SPACE, 
    CHR_t, CHR_h, CHR_o, CHR_s, CHR_e, PCT_SPACE, CTR_BLINK, CTR_EM_YELLOW, CHR_c, CHR_a, 
    CHR_r, PCT_SPACE, CHR_m, CHR_a, CHR_g, CHR_a, CHR_z, CHR_i, CHR_n, CHR_e, 
    CHR_s, CTR_CLOSE_EM, CTR_CLOSE_BLINK, CTR_NEWLINE, CTR_ENDLINE};

//       I collected over the years!{newline}{endline}
static s16 scenario_text_133F[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_I, PCT_SPACE, CHR_c, CHR_o, 
    CHR_l, CHR_l, CHR_e, CHR_c, CHR_t, CHR_e, CHR_d, PCT_SPACE, CHR_o, CHR_v, 
    CHR_e, CHR_r, PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE, CHR_y, CHR_e, CHR_a, 
    CHR_r, CHR_s, PCT_EXCLAMATION, CTR_NEWLINE, CTR_ENDLINE};

// {button}{endline}
static s16 scenario_text_1386[] = {
    CTR_BUTTON, CTR_ENDLINE};

// {newwindow}{endline}
static s16 scenario_text_13AB[] = {
    CTR_NEWWINDOW, CTR_ENDLINE};

// Wise Man:Who would do such{newline}{endline}
static s16 scenario_text_13D3[] = {
    CHR_W, CHR_i, CHR_s, CHR_e, PCT_SPACE, CHR_M, CHR_a, CHR_n, PCT_COLON, CHR_W, 
    CHR_h, CHR_o, PCT_SPACE, CHR_w, CHR_o, CHR_u, CHR_l, CHR_d, PCT_SPACE, CHR_d, 
    CHR_o, PCT_SPACE, CHR_s, CHR_u, CHR_c, CHR_h, CTR_NEWLINE, CTR_ENDLINE};

//        a thing?!{button}{end}{endline}
static s16 scenario_text_1413[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_a, PCT_SPACE, CHR_t, 
    CHR_h, CHR_i, CHR_n, CHR_g, PCT_QUESTION, PCT_EXCLAMATION, CTR_BUTTON, CTR_END, CTR_ENDLINE};

// {begin}{endline}
static s16 scenario_text_144D[] = {
    CTR_BEGIN, CTR_ENDLINE};

// Ebisumaru:We believe{newline}{endline}
static s16 scenario_text_1471[] = {
    CHR_E, CHR_b, CHR_i, CHR_s, CHR_u, CHR_m, CHR_a, CHR_r, CHR_u, PCT_COLON, 
    CHR_W, CHR_e, PCT_SPACE, CHR_b, CHR_e, CHR_l, CHR_i, CHR_e, CHR_v, CHR_e, 
    CTR_NEWLINE, CTR_ENDLINE};

//        it was probably{newline}{endline}
static s16 scenario_text_14AB[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_i, CHR_t, PCT_SPACE, 
    CHR_w, CHR_a, CHR_s, PCT_SPACE, CHR_p, CHR_r, CHR_o, CHR_b, CHR_a, CHR_b, 
    CHR_l, CHR_y, CTR_NEWLINE, CTR_ENDLINE};

//        the {em-yellow}Peach Mountain guys{/em}.{button}{endline}
static s16 scenario_text_14E7[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_t, CHR_h, CHR_e, 
    PCT_SPACE, CTR_EM_YELLOW, CHR_P, CHR_e, CHR_a, CHR_c, CHR_h, PCT_SPACE, CHR_M, CHR_o, 
    CHR_u, CHR_n, CHR_t, CHR_a, CHR_i, CHR_n, PCT_SPACE, CHR_g, CHR_u, CHR_y, 
    CHR_s, CTR_CLOSE_EM, PCT_PERIOD, CTR_BUTTON, CTR_ENDLINE};

// {newwindow}{endline}
static s16 scenario_text_153B[] = {
    CTR_NEWWINDOW, CTR_ENDLINE};

// Sasuke:..{button}{end}{endline}
static s16 scenario_text_1563[] = {
    CHR_S, CHR_a, CHR_s, CHR_u, CHR_k, CHR_e, PCT_COLON, PCT_PERIOD, PCT_PERIOD, CTR_BUTTON, CTR_END, CTR_ENDLINE};

// {begin}{endline}
static s16 scenario_text_1596[] = {
    CTR_BEGIN, CTR_ENDLINE};

// Wise Man:{blink}{em-yellow}I will not forgive them.{/em}{/blink}{button}{endline}
static s16 scenario_text_15BA[] = {
    CHR_W, CHR_i, CHR_s, CHR_e, PCT_SPACE, CHR_M, CHR_a, CHR_n, PCT_COLON, CTR_BLINK, 
    CTR_EM_YELLOW, CHR_I, PCT_SPACE, CHR_w, CHR_i, CHR_l, CHR_l, PCT_SPACE, CHR_n, CHR_o, 
    CHR_t, PCT_SPACE, CHR_f, CHR_o, CHR_r, CHR_g, CHR_i, CHR_v, CHR_e, PCT_SPACE, 
    CHR_t, CHR_h, CHR_e, CHR_m, PCT_PERIOD, CTR_CLOSE_EM, CTR_CLOSE_BLINK, CTR_BUTTON, CTR_ENDLINE};

// {newwindow}{endline}
static s16 scenario_text_161F[] = {
    CTR_NEWWINDOW, CTR_ENDLINE};

// Wise Man:Hand me your [{em-yellow}Weapons{/em}].{endline}
static s16 scenario_text_1647[] = {
    CHR_W, CHR_i, CHR_s, CHR_e, PCT_SPACE, CHR_M, CHR_a, CHR_n, PCT_COLON, CHR_H, 
    CHR_a, CHR_n, CHR_d, PCT_SPACE, CHR_m, CHR_e, PCT_SPACE, CHR_y, CHR_o, CHR_u, 
    CHR_r, PCT_SPACE, CTR_EM_YELLOW, CHR_W, CHR_e, CHR_a, CHR_p, CHR_o, CHR_n, CHR_s, 
    CTR_CLOSE_EM, PCT_PERIOD, CTR_ENDLINE};

// {waitinput}{end}{endline}
static s16 scenario_text_1694[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE};

// {begin}{endline}
static s16 scenario_text_16C1[] = {
    CTR_BEGIN, CTR_ENDLINE};

// Wise Man:Here, take {em-yellow}this{/em}!{button}{end}{endline}
static s16 scenario_text_16E5[] = {
    CHR_W, CHR_i, CHR_s, CHR_e, PCT_SPACE, CHR_M, CHR_a, CHR_n, PCT_COLON, CHR_H, 
    CHR_e, CHR_r, CHR_e, PCT_COMMA, PCT_SPACE, CHR_t, CHR_a, CHR_k, CHR_e, PCT_SPACE, 
    CTR_EM_YELLOW, CHR_t, CHR_h, CHR_i, CHR_s, CTR_CLOSE_EM, PCT_EXCLAMATION, CTR_BUTTON, CTR_END, CTR_ENDLINE};

// {begin}{endline}
static s16 scenario_text_1738[] = {
    CTR_BEGIN, CTR_ENDLINE};

// The power of the {em-yellow}weapons{/em}{newline}{endline}
static s16 scenario_text_175C[] = {
    CHR_T, CHR_h, CHR_e, PCT_SPACE, CHR_p, CHR_o, CHR_w, CHR_e, CHR_r, PCT_SPACE, 
    CHR_o, CHR_f, PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE, CTR_EM_YELLOW, CHR_w, CHR_e, 
    CHR_a, CHR_p, CHR_o, CHR_n, CHR_s, CTR_CLOSE_EM, CTR_NEWLINE, CTR_ENDLINE};

// belonging to Goemon and the allies{newline}{endline}
static s16 scenario_text_17AA[] = {
    CHR_b, CHR_e, CHR_l, CHR_o, CHR_n, CHR_g, CHR_i, CHR_n, CHR_g, PCT_SPACE, 
    CHR_t, CHR_o, PCT_SPACE, CHR_G, CHR_o, CHR_e, CHR_m, CHR_o, CHR_n, PCT_SPACE, 
    CHR_a, CHR_n, CHR_d, PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE, CHR_a, CHR_l, 
    CHR_l, CHR_i, CHR_e, CHR_s, CTR_NEWLINE, CTR_ENDLINE};

//      has increased to {em-yellow}[Level 3]{/em}!{newline}{endline}
static s16 scenario_text_17F2[256] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_h, CHR_a, CHR_s, PCT_SPACE, CHR_i, 
    CHR_n, CHR_c, CHR_r, CHR_e, CHR_a, CHR_s, CHR_e, CHR_d, PCT_SPACE, CHR_t, 
    CHR_o, PCT_SPACE, CTR_EM_YELLOW, CHR_L, CHR_e, CHR_v, CHR_e, CHR_l, PCT_SPACE, CTR_CLOSE_EM, 
    PCT_EXCLAMATION, CTR_NEWLINE, CTR_ENDLINE};

// {button}{endline}
static s16 scenario_text_1848[] = {
    CTR_BUTTON, CTR_ENDLINE};

// {newwindow}{endline}
static s16 scenario_text_186D[] = {
    CTR_NEWWINDOW, CTR_ENDLINE};

//  {newline}{endline}
static s16 scenario_text_1895[] = {
    PCT_SPACE, CTR_NEWLINE, CTR_ENDLINE};

// With these {em-yellow}weapons{/em},{newline}{endline}
static s16 scenario_text_18BC[] = {
    CHR_W, CHR_i, CHR_t, CHR_h, PCT_SPACE, CHR_t, CHR_h, CHR_e, CHR_s, CHR_e, 
    PCT_SPACE, CTR_EM_YELLOW, CHR_w, CHR_e, CHR_a, CHR_p, CHR_o, CHR_n, CHR_s, CTR_CLOSE_EM, 
    PCT_COMMA, CTR_NEWLINE, CTR_ENDLINE};

// even rigid {em-yellow}doors{/em} can be destroyed!{button}{end}{endline}
static s16 scenario_text_1905[] = {
 CTR_BUTTON, CTR_END, CTR_ENDLINE};

// {begin}{endline}
static s16 scenario_text_1961[] = {
    CTR_BEGIN, CTR_ENDLINE};

// Ebisumaru:Don't you feel{newline}{endline}
static s16 scenario_text_1985[] = {
    CHR_E, CHR_b, CHR_i, CHR_s, CHR_u, CHR_m, CHR_a, CHR_r, CHR_u, PCT_COLON, 
    CHR_D, CHR_o, CHR_n, PCT_APOSTROPHE, CHR_t, PCT_SPACE, CHR_y, CHR_o, CHR_u, PCT_SPACE, 
    CHR_f, CHR_e, CHR_e, CHR_l, CTR_NEWLINE, CTR_ENDLINE};

//        our journey is taking{newline}{endline}
static s16 scenario_text_19C3[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_o, CHR_u, CHR_r, 
    PCT_SPACE, CHR_j, CHR_o, CHR_u, CHR_r, CHR_n, CHR_e, CHR_y, PCT_SPACE, CHR_i, 
    CHR_s, PCT_SPACE, CHR_t, CHR_a, CHR_k, CHR_i, CHR_n, CHR_g, CTR_NEWLINE, CTR_ENDLINE};

//        some wild turns?!{endline}
static s16 scenario_text_1A05[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_s, CHR_o, CHR_m, 
    CHR_e, PCT_SPACE, CHR_w, CHR_i, CHR_l, CHR_d, PCT_SPACE, CHR_t, CHR_u, CHR_r, 
    CHR_n, CHR_s, PCT_QUESTION, PCT_EXCLAMATION, CTR_ENDLINE};

// {waitinput}{end}{endline}
static s16 scenario_text_1A3A[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE};

// Wise Man:Go get 'em!{newline}{endline}
static s16 scenario_text_1A67[] = {
    CHR_W, CHR_i, CHR_s, CHR_e, PCT_SPACE, CHR_M, CHR_a, CHR_n, PCT_COLON, CHR_G, 
    CHR_o, PCT_SPACE, CHR_g, CHR_e, CHR_t, PCT_SPACE, PCT_APOSTROPHE, CHR_e, CHR_m, PCT_EXCLAMATION, 
    CTR_NEWLINE, CTR_ENDLINE};

//       Take revenge for my poor{newline}{endline}
static s16 scenario_text_1AA1[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_T, CHR_a, CHR_k, CHR_e, 
    PCT_SPACE, CHR_r, CHR_e, CHR_v, CHR_e, CHR_n, CHR_g, CHR_e, PCT_SPACE, CHR_f, 
    CHR_o, CHR_r, PCT_SPACE, CHR_m, CHR_y, PCT_SPACE, CHR_p, CHR_o, CHR_o, CHR_r, 
    CTR_NEWLINE, CTR_ENDLINE};

//       {em-yellow}car magazines{/em}.{endline}
static s16 scenario_text_1AE5[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CTR_EM_YELLOW, CHR_c, CHR_a, CHR_r, 
    PCT_SPACE, CHR_m, CHR_a, CHR_g, CHR_a, CHR_z, CHR_i, CHR_n, CHR_e, CHR_s, 
    CTR_CLOSE_EM, PCT_PERIOD, CTR_ENDLINE};

// {waitinput}{end}{endline}
static s16 scenario_text_1B26[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE};

// ==================== SCENARIO CODE ====================

// Message at @31dc
s32 scenario_code_31dc[] = {

    // 31dc: Print Text
    TXT,
    (s32)&scenario_text_0000,

    // 31e4: Print Text
    TXT,
    (s32)&scenario_text_0038,

    // 31ec: End Event
    END,

};

// Message at @31f0
s32 scenario_code_31f0[] = {

    // 31f0: Write to RAM 8007785c (Dialogue Portrait Character)
    STW,
    0x8007785c,

    // 31f8: Store Value: 18
    WTS,
    0x18,

    // 3200: Print Text
    TXT,
    (s32)&scenario_text_0065,

    // 3208: If Flag 01a (Upgraded to Gold Weapons), Jump To @3c30
    JFS,
    0x1a,
    (s32)&scenario_code_3c30,

    // 3214: Write to RAM 801c7770 (Unknown)
    STW,
    0x801c7770,

    // 321c: Store Value: 1
    WTS,
    0x1,

    // 3224: Execute Code: 8003f594 (Load Current Character)
    ESR,
    0x8003f594,

    // 322c: Read from RAM 801c7750 (Scratch)
    LDW,
    0x801c7750,

    // 3234: Skip Next If Not Equal: 0
    SNE,
    0x0,

    // 323c: Jump To @3290
    JMP,
    (s32)&scenario_code_3290,

    // 3244: Read from RAM 801c7750 (Scratch)
    LDW,
    0x801c7750,

    // 324c: Skip Next If Not Equal: 1
    SNE,
    0x1,

    // 3254: Jump To @32f4
    JMP,
    (s32)&scenario_code_32f4,

    // 325c: Read from RAM 801c7750 (Scratch)
    LDW,
    0x801c7750,

    // 3264: Skip Next If Not Equal: 3
    SNE,
    0x3,

    // 326c: Jump To @3358
    JMP,
    (s32)&scenario_code_3358,

    // 3274: Read from RAM 801c7750 (Scratch)
    LDW,
    0x801c7750,

    // 327c: Skip Next If Not Equal: 2
    SNE,
    0x2,

    // 3284: Jump To @33bc
    JMP,
    (s32)&scenario_code_33bc,

    // 328c: End Event
    END,

};

// Message at @3290
s32 scenario_code_3290[] = {

    // 3290: Write to RAM 801c7770 (Unknown)
    STW,
    0x801c7770,

    // 3298: Store Value: 1
    WTS,
    0x1,

    // 32a0: Print Text
    TXT,
    (s32)&scenario_text_0089,

    // 32a8: Write to RAM 801c7768 (Dialogue Window Style)
    STW,
    0x801c7768,

    // 32b0: Store Value: 7
    WTS,
    0x7,

    // 32b8: Write to RAM 8007785c (Dialogue Portrait Character)
    STW,
    0x8007785c,

    // 32c0: Store Value: 0
    WTS,
    0x0,

    // 32c8: Print Text
    TXT,
    (s32)&scenario_text_00E3,

    // 32d0: Write to RAM 801c7770 (Unknown)
    STW,
    0x801c7770,

    // 32d8: Store Value: 1
    WTS,
    0x1,

    // 32e0: Print Text
    TXT,
    (s32)&scenario_text_0107,

    // 32e8: Jump To @3428
    JMP,
    (s32)&scenario_code_3428,

    // 32f0: End Event
    END,

};

// Message at @32f4
s32 scenario_code_32f4[] = {

    // 32f4: Write to RAM 801c7770 (Unknown)
    STW,
    0x801c7770,

    // 32fc: Store Value: 1
    WTS,
    0x1,

    // 3304: Print Text
    TXT,
    (s32)&scenario_text_0153,

    // 330c: Write to RAM 801c7768 (Dialogue Window Style)
    STW,
    0x801c7768,

    // 3314: Store Value: 7
    WTS,
    0x7,

    // 331c: Write to RAM 8007785c (Dialogue Portrait Character)
    STW,
    0x8007785c,

    // 3324: Store Value: 2
    WTS,
    0x2,

    // 332c: Print Text
    TXT,
    (s32)&scenario_text_01B0,

    // 3334: Write to RAM 801c7770 (Unknown)
    STW,
    0x801c7770,

    // 333c: Store Value: 1
    WTS,
    0x1,

    // 3344: Print Text
    TXT,
    (s32)&scenario_text_01D4,

    // 334c: Jump To @3428
    JMP,
    (s32)&scenario_code_3428,

    // 3354: End Event
    END,

};

// Message at @3358
s32 scenario_code_3358[] = {

    // 3358: Write to RAM 801c7770 (Unknown)
    STW,
    0x801c7770,

    // 3360: Store Value: 1
    WTS,
    0x1,

    // 3368: Print Text
    TXT,
    (s32)&scenario_text_0222,

    // 3370: Write to RAM 801c7768 (Dialogue Window Style)
    STW,
    0x801c7768,

    // 3378: Store Value: 7
    WTS,
    0x7,

    // 3380: Write to RAM 8007785c (Dialogue Portrait Character)
    STW,
    0x8007785c,

    // 3388: Store Value: 6
    WTS,
    0x6,

    // 3390: Print Text
    TXT,
    (s32)&scenario_text_0279,

    // 3398: Write to RAM 801c7770 (Unknown)
    STW,
    0x801c7770,

    // 33a0: Store Value: 1
    WTS,
    0x1,

    // 33a8: Print Text
    TXT,
    (s32)&scenario_text_029D,

    // 33b0: Jump To @3428
    JMP,
    (s32)&scenario_code_3428,

    // 33b8: End Event
    END,

};

// Message at @33bc
s32 scenario_code_33bc[] = {

    // 33bc: Write to RAM 801c7770 (Unknown)
    STW,
    0x801c7770,

    // 33c4: Store Value: 1
    WTS,
    0x1,

    // 33cc: Print Text
    TXT,
    (s32)&scenario_text_02ED,

    // 33d4: Write to RAM 801c7768 (Dialogue Window Style)
    STW,
    0x801c7768,

    // 33dc: Store Value: 7
    WTS,
    0x7,

    // 33e4: Write to RAM 8007785c (Dialogue Portrait Character)
    STW,
    0x8007785c,

    // 33ec: Store Value: 4
    WTS,
    0x4,

    // 33f4: Print Text
    TXT,
    (s32)&scenario_text_0348,

    // 33fc: Write to RAM 801c7770 (Unknown)
    STW,
    0x801c7770,

    // 3404: Store Value: 1
    WTS,
    0x1,

    // 340c: Print Text
    TXT,
    (s32)&scenario_text_036C,

    // 3414: Print Text
    TXT,
    (s32)&scenario_text_039D,

    // 341c: Jump To @3428
    JMP,
    (s32)&scenario_code_3428,

    // 3424: End Event
    END,

};

// Message at @3428
s32 scenario_code_3428[] = {

    // 3428: Write to RAM 801c7770 (Unknown)
    STW,
    0x801c7770,

    // 3430: Store Value: 1
    WTS,
    0x1,

    // 3438: Print Text
    TXT,
    (s32)&scenario_text_03EF,

    // 3440: Write to RAM 8007785c (Dialogue Portrait Character)
    STW,
    0x8007785c,

    // 3448: Store Value: 4
    WTS,
    0x4,

    // 3450: Print Text
    TXT,
    (s32)&scenario_text_0417,

    // 3458: Print Text
    TXT,
    (s32)&scenario_text_044A,

    // 3460: Print Text
    TXT,
    (s32)&scenario_text_04A0,

    // 3468: Print Text
    TXT,
    (s32)&scenario_text_04E2,

    // 3470: Print Text
    TXT,
    (s32)&scenario_text_0515,

    // 3478: Write to RAM 8007785c (Dialogue Portrait Character)
    STW,
    0x8007785c,

    // 3480: Store Value: 0
    WTS,
    0x0,

    // 3488: Print Text
    TXT,
    (s32)&scenario_text_053D,

    // 3490: Print Text
    TXT,
    (s32)&scenario_text_0577,

    // 3498: Write to RAM 801c7768 (Dialogue Window Style)
    STW,
    0x801c7768,

    // 34a0: Store Value: 1
    WTS,
    0x1,

    // 34a8: Write to RAM 8007785c (Dialogue Portrait Character)
    STW,
    0x8007785c,

    // 34b0: Store Value: 18
    WTS,
    0x18,

    // 34b8: Print Text
    TXT,
    (s32)&scenario_text_05B5,

    // 34c0: Write to RAM 801c7770 (Unknown)
    STW,
    0x801c7770,

    // 34c8: Store Value: 1
    WTS,
    0x1,

    // 34d0: Print Text
    TXT,
    (s32)&scenario_text_05D9,

    // 34d8: Print Text
    TXT,
    (s32)&scenario_text_061F,

    // 34e0: Print Text
    TXT,
    (s32)&scenario_text_065A,

    // 34e8: Print Text
    TXT,
    (s32)&scenario_text_0696,

    // 34f0: Write to RAM 801c7768 (Dialogue Window Style)
    STW,
    0x801c7768,

    // 34f8: Store Value: 7
    WTS,
    0x7,

    // 3500: Write to RAM 8007785c (Dialogue Portrait Character)
    STW,
    0x8007785c,

    // 3508: Store Value: 0
    WTS,
    0x0,

    // 3510: Print Text
    TXT,
    (s32)&scenario_text_06ED,

    // 3518: Write to RAM 801c7770 (Unknown)
    STW,
    0x801c7770,

    // 3520: Store Value: 1
    WTS,
    0x1,

    // 3528: Print Text
    TXT,
    (s32)&scenario_text_0711,

    // 3530: Print Text
    TXT,
    (s32)&scenario_text_0765,

    // 3538: Write to RAM 801c7740 (Scratch)
    STW,
    0x801c7740,

    // 3540: Store Value: 140
    WTS,
    0x140,

    // 3548: Execute Code: 8003f608 (Play Sound)
    ESR,
    0x8003f608,

    // 3550: Print Text
    TXT,
    (s32)&scenario_text_07B0,

    // 3558: Print Text
    TXT,
    (s32)&scenario_text_07D5,

    // 3560: Write to RAM 8007785c (Dialogue Portrait Character)
    STW,
    0x8007785c,

    // 3568: Store Value: 6
    WTS,
    0x6,

    // 3570: Print Text
    TXT,
    (s32)&scenario_text_07FD,

    // 3578: Print Text
    TXT,
    (s32)&scenario_text_083E,

    // 3580: Print Text
    TXT,
    (s32)&scenario_text_087D,

    // 3588: Print Text
    TXT,
    (s32)&scenario_text_08BC,

    // 3590: Write to RAM 801c7740 (Scratch)
    STW,
    0x801c7740,

    // 3598: Store Value: 142
    WTS,
    0x142,

    // 35a0: Execute Code: 8003f608 (Play Sound)
    ESR,
    0x8003f608,

    // 35a8: Print Text
    TXT,
    (s32)&scenario_text_08F5,

    // 35b0: Print Text
    TXT,
    (s32)&scenario_text_091A,

    // 35b8: Print Text
    TXT,
    (s32)&scenario_text_0942,

    // 35c0: Write to RAM 801c7768 (Dialogue Window Style)
    STW,
    0x801c7768,

    // 35c8: Store Value: 1
    WTS,
    0x1,

    // 35d0: Write to RAM 8007785c (Dialogue Portrait Character)
    STW,
    0x8007785c,

    // 35d8: Store Value: 18
    WTS,
    0x18,

    // 35e0: Print Text
    TXT,
    (s32)&scenario_text_098D,

    // 35e8: Write to RAM 801c7770 (Unknown)
    STW,
    0x801c7770,

    // 35f0: Store Value: 1
    WTS,
    0x1,

    // 35f8: Print Text
    TXT,
    (s32)&scenario_text_09B1,

    // 3600: Print Text
    TXT,
    (s32)&scenario_text_09F8,

    // 3608: Print Text
    TXT,
    (s32)&scenario_text_0A4B,

    // 3610: Print Text
    TXT,
    (s32)&scenario_text_0A73,

    // 3618: Print Text
    TXT,
    (s32)&scenario_text_0AB4,

    // 3620: Print Text
    TXT,
    (s32)&scenario_text_0B05,

    // 3628: Print Text
    TXT,
    (s32)&scenario_text_0B58,

    // 3630: Print Text
    TXT,
    (s32)&scenario_text_0B80,

    // 3638: Print Text
    TXT,
    (s32)&scenario_text_0BC6,

    // 3640: Print Text
    TXT,
    (s32)&scenario_text_0C19,

    // 3648: Write to RAM 801c7740 (Scratch)
    STW,
    0x801c7740,

    // 3650: Store Value: 141
    WTS,
    0x141,

    // 3658: Execute Code: 8003f608 (Play Sound)
    ESR,
    0x8003f608,

    // 3660: Print Text
    TXT,
    (s32)&scenario_text_0C6A,

    // 3668: Write to RAM 801c7768 (Dialogue Window Style)
    STW,
    0x801c7768,

    // 3670: Store Value: 7
    WTS,
    0x7,

    // 3678: Write to RAM 8007785c (Dialogue Portrait Character)
    STW,
    0x8007785c,

    // 3680: Store Value: 0
    WTS,
    0x0,

    // 3688: Print Text
    TXT,
    (s32)&scenario_text_0C94,

    // 3690: Write to RAM 801c7770 (Unknown)
    STW,
    0x801c7770,

    // 3698: Store Value: 1
    WTS,
    0x1,

    // 36a0: Print Text
    TXT,
    (s32)&scenario_text_0CB8,

    // 36a8: Print Text
    TXT,
    (s32)&scenario_text_0CE8,

    // 36b0: Write to RAM 801c7740 (Scratch)
    STW,
    0x801c7740,

    // 36b8: Store Value: 141
    WTS,
    0x141,

    // 36c0: Execute Code: 8003f608 (Play Sound)
    ESR,
    0x8003f608,

    // 36c8: Print Text
    TXT,
    (s32)&scenario_text_0D3C,

    // 36d0: Write to RAM 801c7768 (Dialogue Window Style)
    STW,
    0x801c7768,

    // 36d8: Store Value: 1
    WTS,
    0x1,

    // 36e0: Write to RAM 8007785c (Dialogue Portrait Character)
    STW,
    0x8007785c,

    // 36e8: Store Value: 18
    WTS,
    0x18,

    // 36f0: Print Text
    TXT,
    (s32)&scenario_text_0D66,

    // 36f8: Write to RAM 801c7770 (Unknown)
    STW,
    0x801c7770,

    // 3700: Store Value: 1
    WTS,
    0x1,

    // 3708: Print Text
    TXT,
    (s32)&scenario_text_0D8A,

    // 3710: Print Text
    TXT,
    (s32)&scenario_text_0DC7,

    // 3718: Print Text
    TXT,
    (s32)&scenario_text_0E06,

    // 3720: Print Text
    TXT,
    (s32)&scenario_text_0E54,

    // 3728: Write to RAM 801c7740 (Scratch)
    STW,
    0x801c7740,

    // 3730: Store Value: 140
    WTS,
    0x140,

    // 3738: Execute Code: 8003f608 (Play Sound)
    ESR,
    0x8003f608,

    // 3740: Print Text
    TXT,
    (s32)&scenario_text_0E8D,

    // 3748: Write to RAM 801c7768 (Dialogue Window Style)
    STW,
    0x801c7768,

    // 3750: Store Value: 7
    WTS,
    0x7,

    // 3758: Write to RAM 8007785c (Dialogue Portrait Character)
    STW,
    0x8007785c,

    // 3760: Store Value: 2
    WTS,
    0x2,

    // 3768: Print Text
    TXT,
    (s32)&scenario_text_0EB7,

    // 3770: Write to RAM 801c7770 (Unknown)
    STW,
    0x801c7770,

    // 3778: Store Value: 1
    WTS,
    0x1,

    // 3780: Print Text
    TXT,
    (s32)&scenario_text_0EDB,

    // 3788: Print Text
    TXT,
    (s32)&scenario_text_0F22,

    // 3790: Print Text
    TXT,
    (s32)&scenario_text_0F62,

    // 3798: Write to RAM 801c7768 (Dialogue Window Style)
    STW,
    0x801c7768,

    // 37a0: Store Value: 1
    WTS,
    0x1,

    // 37a8: Write to RAM 8007785c (Dialogue Portrait Character)
    STW,
    0x8007785c,

    // 37b0: Store Value: 18
    WTS,
    0x18,

    // 37b8: Print Text
    TXT,
    (s32)&scenario_text_0FA6,

    // 37c0: Write to RAM 801c7770 (Unknown)
    STW,
    0x801c7770,

    // 37c8: Store Value: 1
    WTS,
    0x1,

    // 37d0: Print Text
    TXT,
    (s32)&scenario_text_0FCA,

    // 37d8: Print Text
    TXT,
    (s32)&scenario_text_1005,

    // 37e0: Write to RAM 801c7768 (Dialogue Window Style)
    STW,
    0x801c7768,

    // 37e8: Store Value: 7
    WTS,
    0x7,

    // 37f0: Write to RAM 8007785c (Dialogue Portrait Character)
    STW,
    0x8007785c,

    // 37f8: Store Value: 0
    WTS,
    0x0,

    // 3800: Print Text
    TXT,
    (s32)&scenario_text_1042,

    // 3808: Write to RAM 801c7770 (Unknown)
    STW,
    0x801c7770,

    // 3810: Store Value: 1
    WTS,
    0x1,

    // 3818: Print Text
    TXT,
    (s32)&scenario_text_1066,

    // 3820: Print Text
    TXT,
    (s32)&scenario_text_10A6,

    // 3828: Print Text
    TXT,
    (s32)&scenario_text_10F8,

    // 3830: Print Text
    TXT,
    (s32)&scenario_text_113D,

    // 3838: Write to RAM 801c7768 (Dialogue Window Style)
    STW,
    0x801c7768,

    // 3840: Store Value: 1
    WTS,
    0x1,

    // 3848: Write to RAM 8007785c (Dialogue Portrait Character)
    STW,
    0x8007785c,

    // 3850: Store Value: 18
    WTS,
    0x18,

    // 3858: Print Text
    TXT,
    (s32)&scenario_text_1192,

    // 3860: Write to RAM 801c7770 (Unknown)
    STW,
    0x801c7770,

    // 3868: Store Value: 1
    WTS,
    0x1,

    // 3870: Print Text
    TXT,
    (s32)&scenario_text_11B6,

    // 3878: Print Text
    TXT,
    (s32)&scenario_text_11FC,

    // 3880: Print Text
    TXT,
    (s32)&scenario_text_123A,

    // 3888: Print Text
    TXT,
    (s32)&scenario_text_1280,

    // 3890: Print Text
    TXT,
    (s32)&scenario_text_12A8,

    // 3898: Print Text
    TXT,
    (s32)&scenario_text_12DD,

    // 38a0: Print Text
    TXT,
    (s32)&scenario_text_133F,

    // 38a8: Write to RAM 801c7740 (Scratch)
    STW,
    0x801c7740,

    // 38b0: Store Value: 141
    WTS,
    0x141,

    // 38b8: Execute Code: 8003f608 (Play Sound)
    ESR,
    0x8003f608,

    // 38c0: Print Text
    TXT,
    (s32)&scenario_text_1386,

    // 38c8: Print Text
    TXT,
    (s32)&scenario_text_13AB,

    // 38d0: Print Text
    TXT,
    (s32)&scenario_text_13D3,

    // 38d8: Print Text
    TXT,
    (s32)&scenario_text_1413,

    // 38e0: Write to RAM 801c7768 (Dialogue Window Style)
    STW,
    0x801c7768,

    // 38e8: Store Value: 7
    WTS,
    0x7,

    // 38f0: Write to RAM 8007785c (Dialogue Portrait Character)
    STW,
    0x8007785c,

    // 38f8: Store Value: 2
    WTS,
    0x2,

    // 3900: Print Text
    TXT,
    (s32)&scenario_text_144D,

    // 3908: Write to RAM 801c7770 (Unknown)
    STW,
    0x801c7770,

    // 3910: Store Value: 1
    WTS,
    0x1,

    // 3918: Print Text
    TXT,
    (s32)&scenario_text_1471,

    // 3920: Print Text
    TXT,
    (s32)&scenario_text_14AB,

    // 3928: Print Text
    TXT,
    (s32)&scenario_text_14E7,

    // 3930: Print Text
    TXT,
    (s32)&scenario_text_153B,

    // 3938: Write to RAM 8007785c (Dialogue Portrait Character)
    STW,
    0x8007785c,

    // 3940: Store Value: 4
    WTS,
    0x4,

    // 3948: Print Text
    TXT,
    (s32)&scenario_text_1563,

    // 3950: Write to RAM 801c7768 (Dialogue Window Style)
    STW,
    0x801c7768,

    // 3958: Store Value: 1
    WTS,
    0x1,

    // 3960: Write to RAM 8007785c (Dialogue Portrait Character)
    STW,
    0x8007785c,

    // 3968: Store Value: 18
    WTS,
    0x18,

    // 3970: Print Text
    TXT,
    (s32)&scenario_text_1596,

    // 3978: Write to RAM 801c7770 (Unknown)
    STW,
    0x801c7770,

    // 3980: Store Value: 1
    WTS,
    0x1,

    // 3988: Write to RAM 801c77d8 (Text Speed)
    STW,
    0x801c77d8,

    // 3990: Store Value: 64
    WTS,
    0x64,

    // 3998: Write to RAM 801c7798 (Unknown)
    STW,
    0x801c7798,

    // 39a0: Store Value: 1
    WTS,
    0x1,

    // 39a8: Print Text
    TXT,
    (s32)&scenario_text_15BA,

    // 39b0: Print Text
    TXT,
    (s32)&scenario_text_161F,

    // 39b8: Write to RAM 801c77d8 (Text Speed)
    STW,
    0x801c77d8,

    // 39c0: Store Value: 1
    WTS,
    0x1,

    // 39c8: Write to RAM 801c7798 (Unknown)
    STW,
    0x801c7798,

    // 39d0: Store Value: 1
    WTS,
    0x1,

    // 39d8: Print Text
    TXT,
    (s32)&scenario_text_1647,

    // 39e0: Print Text
    TXT,
    (s32)&scenario_text_1694,

    // 39e8: Set Flag 01a (Upgraded to Gold Weapons)
    SFG,
    0x1a,

    // 39f0: Write to RAM 801c7740 (Scratch)
    STW,
    0x801c7740,

    // 39f8: Store Value: 78
    WTS,
    0x78,

    // 3a00: Execute Code: 8003f460 (Wait For Timer)
    ESR,
    0x8003f460,

    // 3a08: Jump To @3a14
    JMP,
    (s32)&scenario_code_3a14,

    // 3a10: End Event
    END,

};

// Message at @3a14
s32 scenario_code_3a14[] = {

    // 3a14: Set Flag 09c (Witch Cutscene Flag #2)
    SFG,
    0x9c,

    // 3a1c: Write to RAM 801c7768 (Dialogue Window Style)
    STW,
    0x801c7768,

    // 3a24: Store Value: 1
    WTS,
    0x1,

    // 3a2c: Write to RAM 8007785c (Dialogue Portrait Character)
    STW,
    0x8007785c,

    // 3a34: Store Value: 18
    WTS,
    0x18,

    // 3a3c: Print Text
    TXT,
    (s32)&scenario_text_16C1,

    // 3a44: Write to RAM 801c7770 (Unknown)
    STW,
    0x801c7770,

    // 3a4c: Store Value: 1
    WTS,
    0x1,

    // 3a54: Write to RAM 801c77d8 (Text Speed)
    STW,
    0x801c77d8,

    // 3a5c: Store Value: 64
    WTS,
    0x64,

    // 3a64: Write to RAM 801c7798 (Unknown)
    STW,
    0x801c7798,

    // 3a6c: Store Value: 1
    WTS,
    0x1,

    // 3a74: Print Text
    TXT,
    (s32)&scenario_text_16E5,

    // 3a7c: Write to RAM 801c7758 (Unknown)
    STW,
    0x801c7758,

    // 3a84: Store Value: 20
    WTS,
    0x20,

    // 3a8c: Write to RAM 801c775c (Dialogue Window Y Pos)
    STW,
    0x801c775c,

    // 3a94: Store Value: 48
    WTS,
    0x48,

    // 3a9c: Write to RAM 8007785c (Dialogue Portrait Character)
    STW,
    0x8007785c,

    // 3aa4: Store Value: 100
    WTS,
    0x100,

    // 3aac: Write to RAM 801c7768 (Dialogue Window Style)
    STW,
    0x801c7768,

    // 3ab4: Store Value: 7
    WTS,
    0x7,

    // 3abc: Print Text
    TXT,
    (s32)&scenario_text_1738,

    // 3ac4: Write to RAM 801c7770 (Unknown)
    STW,
    0x801c7770,

    // 3acc: Store Value: 1
    WTS,
    0x1,

    // 3ad4: Write to RAM 801c7740 (Scratch)
    STW,
    0x801c7740,

    // 3adc: Store Value: 14
    WTS,
    0x14,

    // 3ae4: Execute Code: 8003f608 (Play Sound)
    ESR,
    0x8003f608,

    // // 3aec: Print Text
    // TXT,
    // (s32)&scenario_text_175C,

    // // 3af4: Print Text
    // TXT,
    // (s32)&scenario_text_17AA,

    ESR,
    (s32)update_wise_man_sogen_text,

    // 3afc: Print Text
    TXT,
    (s32)&scenario_text_17F2,

    // 3b04: Write to RAM 801c7740 (Scratch)
    STW,
    0x801c7740,

    // 3b0c: Store Value: 96
    WTS,
    0x96,

    // 3b14: Execute Code: 8003f460 (Wait For Timer)
    ESR,
    0x8003f460,

    // 3b1c: Write to RAM 801c7740 (Scratch)
    STW,
    0x801c7740,

    // 3b24: Store Value: 23
    WTS,
    0x23,

    // 3b2c: Execute Code: 8003f608 (Play Sound)
    ESR,
    0x8003f608,

    // 3b34: Print Text
    TXT,
    (s32)&scenario_text_1848,

    // // 3b3c: Print Text
    // TXT,
    // (s32)&scenario_text_186D,

    // // 3b44: Print Text
    // TXT,
    // (s32)&scenario_text_1895,

    // // 3b4c: Print Text
    // TXT,
    // (s32)&scenario_text_18BC,

    // 3b54: Print Text
    TXT,
    (s32)&scenario_text_1905,

    // 3b5c: Write to RAM 801c7758 (Unknown)
    STW,
    0x801c7758,

    // 3b64: Store Value: 20
    WTS,
    0x20,

    // 3b6c: Write to RAM 801c775c (Dialogue Window Y Pos)
    STW,
    0x801c775c,

    // 3b74: Store Value: 20
    WTS,
    0x20,

    // 3b7c: Write to RAM 801c7768 (Dialogue Window Style)
    STW,
    0x801c7768,

    // 3b84: Store Value: 7
    WTS,
    0x7,

    // 3b8c: Write to RAM 8007785c (Dialogue Portrait Character)
    STW,
    0x8007785c,

    // 3b94: Store Value: 2
    WTS,
    0x2,

    // 3b9c: Print Text
    TXT,
    (s32)&scenario_text_1961,

    // 3ba4: Write to RAM 801c7770 (Unknown)
    STW,
    0x801c7770,

    // 3bac: Store Value: 1
    WTS,
    0x1,

    // 3bb4: Print Text
    TXT,
    (s32)&scenario_text_1985,

    // 3bbc: Print Text
    TXT,
    (s32)&scenario_text_19C3,

    // 3bc4: Print Text
    TXT,
    (s32)&scenario_text_1A05,

    // 3bcc: Write to RAM 801c7740 (Scratch)
    STW,
    0x801c7740,

    // 3bd4: Store Value: 140
    WTS,
    0x140,

    // 3bdc: Execute Code: 8003f608 (Play Sound)
    ESR,
    0x8003f608,

    // // 3be4: Write to RAM 8015c6ac (Goemon Weapon Level)
    // STW,
    // 0x8015c6ac,

    // // 3bec: Store Value: 2
    // WTS,
    // 0x2,

    // // 3bf4: Write to RAM 8015c6b0 (Ebisumaru Weapon Level)
    // STW,
    // 0x8015c6b0,

    // // 3bfc: Store Value: 2
    // WTS,
    // 0x2,

    // // 3c04: Write to RAM 8015c6b4 (Sasuke Weapon Level)
    // STW,
    // 0x8015c6b4,

    // // 3c0c: Store Value: 2
    // WTS,
    // 0x2,

    // // 3c14: Write to RAM 8015c6b8 (Yae Weapon Level)
    // STW,
    // 0x8015c6b8,

    // // 3c1c: Store Value: 2
    // WTS,
    // 0x2,

    // 3c24: Print Text
    TXT,
    (s32)&scenario_text_1A3A,

    // 3c2c: End Event
    END,

};

// Message at @3c30
s32 scenario_code_3c30[] = {

    // 3c30: Print Text
    TXT,
    (s32)&scenario_text_1A67,

    // 3c38: Print Text
    TXT,
    (s32)&scenario_text_1AA1,

    // 3c40: Print Text
    TXT,
    (s32)&scenario_text_1AE5,

    // 3c48: Print Text
    TXT,
    (s32)&scenario_text_1B26,

    // 3c50: End Event
    END,

};


// Function to update the wise man sogen weapon upgrade text with AP location data
void update_wise_man_sogen_text(void)
{
  update_text_buffer_with_ap_location(scenario_text_17F2, 0x01A, NULL, NULL);
}
