#include "scenario.h"

#include "common.h"

// Address: @2ad4

// {begin}{endline}
static s16 scenario_text_0000[] = {
    CTR_BEGIN, CTR_ENDLINE
};

// [Waterfall of Kegon]{newline}{endline}
static s16 scenario_text_0014[] = {
    PCT_LBRACKET, CHR_W, CHR_a, CHR_t, CHR_e, CHR_r, CHR_f, CHR_a, CHR_l, CHR_l,
    PCT_SPACE, CHR_o, CHR_f, PCT_SPACE, CHR_K, CHR_e, CHR_g, CHR_o, CHR_n, PCT_RBRACKET,
    CTR_NEWLINE, CTR_ENDLINE
};

// Legend has it that those {newline}{endline}
static s16 scenario_text_003E[] = {
    CHR_L, CHR_e, CHR_g, CHR_e, CHR_n, CHR_d, PCT_SPACE, CHR_h, CHR_a, CHR_s,
    PCT_SPACE, CHR_i, CHR_t, PCT_SPACE, CHR_t, CHR_h, CHR_a, CHR_t, PCT_SPACE, CHR_t,
    CHR_h, CHR_o, CHR_s, CHR_e, PCT_SPACE, CTR_NEWLINE, CTR_ENDLINE
};

// who successfully swim to the top{newline}{endline}
static s16 scenario_text_006D[] = {
    CHR_w, CHR_h, CHR_o, PCT_SPACE, CHR_s, CHR_u, CHR_c, CHR_c, CHR_e, CHR_s,
    CHR_s, CHR_f, CHR_u, CHR_l, CHR_l, CHR_y, PCT_SPACE, CHR_s, CHR_w, CHR_i,
    CHR_m, PCT_SPACE, CHR_t, CHR_o, PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE, CHR_t,
    CHR_o, CHR_p, CTR_NEWLINE, CTR_ENDLINE
};

// of this {em-yellow}waterfall{/em}...{button}{endline}
static s16 scenario_text_00A3[] = {
    CHR_o, CHR_f, PCT_SPACE, CHR_t, CHR_h, CHR_i, CHR_s, PCT_SPACE, CTR_EM_YELLOW, CHR_w,
    CHR_a, CHR_t, CHR_e, CHR_r, CHR_f, CHR_a, CHR_l, CHR_l, CTR_CLOSE_EM, PCT_PERIOD,
    PCT_PERIOD, PCT_PERIOD, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_00DC[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// [Waterfall of Kegon]{newline}{endline}
static s16 scenario_text_00F4[] = {
    PCT_LBRACKET, CHR_W, CHR_a, CHR_t, CHR_e, CHR_r, CHR_f, CHR_a, CHR_l, CHR_l,
    PCT_SPACE, CHR_o, CHR_f, PCT_SPACE, CHR_K, CHR_e, CHR_g, CHR_o, CHR_n, PCT_RBRACKET,
    CTR_NEWLINE, CTR_ENDLINE
};

// ...can become a {em-yellow}mermaid{/em}.{button}{endline}
static s16 scenario_text_011E[] = {
    PCT_PERIOD, PCT_PERIOD, PCT_PERIOD, CHR_c, CHR_a, CHR_n, PCT_SPACE, CHR_b, CHR_e, CHR_c,
    CHR_o, CHR_m, CHR_e, PCT_SPACE, CHR_a, PCT_SPACE, CTR_EM_YELLOW, CHR_m, CHR_e, CHR_r,
    CHR_m, CHR_a, CHR_i, CHR_d, CTR_CLOSE_EM, PCT_PERIOD, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_015B[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// [Waterfall of Kegon]{newline}{endline}
static s16 scenario_text_0173[] = {
    PCT_LBRACKET, CHR_W, CHR_a, CHR_t, CHR_e, CHR_r, CHR_f, CHR_a, CHR_l, CHR_l,
    PCT_SPACE, CHR_o, CHR_f, PCT_SPACE, CHR_K, CHR_e, CHR_g, CHR_o, CHR_n, PCT_RBRACKET,
    CTR_NEWLINE, CTR_ENDLINE
};

// (It may still be too early {newline}{endline}
static s16 scenario_text_019D[] = {
    PCT_LPAREN, CHR_I, CHR_t, PCT_SPACE, CHR_m, CHR_a, CHR_y, PCT_SPACE, CHR_s, CHR_t,
    CHR_i, CHR_l, CHR_l, PCT_SPACE, CHR_b, CHR_e, PCT_SPACE, CHR_t, CHR_o, CHR_o,
    PCT_SPACE, CHR_e, CHR_a, CHR_r, CHR_l, CHR_y, PCT_SPACE, CTR_NEWLINE, CTR_ENDLINE
};

//      for you to arrive here){endline}
static s16 scenario_text_01CE[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_f, CHR_o, CHR_r, PCT_SPACE, CHR_y,
    CHR_o, CHR_u, PCT_SPACE, CHR_t, CHR_o, PCT_SPACE, CHR_a, CHR_r, CHR_r, CHR_i,
    CHR_v, CHR_e, PCT_SPACE, CHR_h, CHR_e, CHR_r, CHR_e, PCT_RPAREN, CTR_ENDLINE
};

// {waitinput}{end}{endline}
static s16 scenario_text_01F7[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE
};

// Address: @2c2c

// Narrator:Take control of the{newline}{endline}
static s16 scenario_text_0214[] = {
    CHR_N, CHR_a, CHR_r, CHR_r, CHR_a, CHR_t, CHR_o, CHR_r, PCT_COLON, CHR_T,
    CHR_a, CHR_k, CHR_e, PCT_SPACE, CHR_c, CHR_o, CHR_n, CHR_t, CHR_r, CHR_o,
    CHR_l, PCT_SPACE, CHR_o, CHR_f, PCT_SPACE, CHR_t, CHR_h, CHR_e, CTR_NEWLINE, CTR_ENDLINE
};

//        {em-yellow}Legend of the Mermaid{/em}!{newline}{endline}
static s16 scenario_text_0246[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CTR_EM_YELLOW, CHR_L, CHR_e,
    CHR_g, CHR_e, CHR_n, CHR_d, PCT_SPACE, CHR_o, CHR_f, PCT_SPACE, CHR_t, CHR_h,
    CHR_e, PCT_SPACE, CHR_M, CHR_e, CHR_r, CHR_m, CHR_a, CHR_i, CHR_d, CTR_CLOSE_EM,
    PCT_EXCLAMATION, CTR_NEWLINE, CTR_ENDLINE
};

//        Looking for applicants!{button}{endline}
static s16 scenario_text_0289[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_L, CHR_o, CHR_o,
    CHR_k, CHR_i, CHR_n, CHR_g, PCT_SPACE, CHR_f, CHR_o, CHR_r, PCT_SPACE, CHR_a,
    CHR_p, CHR_p, CHR_l, CHR_i, CHR_c, CHR_a, CHR_n, CHR_t, CHR_s, PCT_EXCLAMATION,
    CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_02BC[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Do you wish to challenge{newline}{endline}
static s16 scenario_text_02D4[] = {
    CHR_D, CHR_o, PCT_SPACE, CHR_y, CHR_o, CHR_u, PCT_SPACE, CHR_w, CHR_i, CHR_s,
    CHR_h, PCT_SPACE, CHR_t, CHR_o, PCT_SPACE, CHR_c, CHR_h, CHR_a, CHR_l, CHR_l,
    CHR_e, CHR_n, CHR_g, CHR_e, CTR_NEWLINE, CTR_ENDLINE
};

// the Legend?{newline}{endline}
static s16 scenario_text_0302[] = {
    CHR_t, CHR_h, CHR_e, PCT_SPACE, CHR_L, CHR_e, CHR_g, CHR_e, CHR_n, CHR_d,
    PCT_QUESTION, CTR_NEWLINE, CTR_ENDLINE
};

//   {em-yellow}Yes, I do!{newline}{endline}
static s16 scenario_text_0323[] = {
    PCT_SPACE, PCT_SPACE, CTR_EM_YELLOW, CHR_Y, CHR_e, CHR_s, PCT_COMMA, PCT_SPACE, CHR_I, PCT_SPACE,
    CHR_d, CHR_o, PCT_EXCLAMATION, CTR_NEWLINE, CTR_ENDLINE
};

//   {em-yellow}I'm going to pass on this one.{newline}{endline}
static s16 scenario_text_0350[] = {
    PCT_SPACE, PCT_SPACE, CTR_EM_YELLOW, CHR_I, PCT_APOSTROPHE, CHR_m, PCT_SPACE, CHR_g, CHR_o, CHR_i,
    CHR_n, CHR_g, PCT_SPACE, CHR_t, CHR_o, PCT_SPACE, CHR_p, CHR_a, CHR_s, CHR_s,
    PCT_SPACE, CHR_o, CHR_n, PCT_SPACE, CHR_t, CHR_h, CHR_i, CHR_s, PCT_SPACE, CHR_o,
    CHR_n, CHR_e, PCT_PERIOD, CTR_NEWLINE, CTR_ENDLINE
};

// {end}{endline}
static s16 scenario_text_0391[] = {
    CTR_END, CTR_ENDLINE
};

// Address: @2cb0

// {newwindow}{endline}
static s16 scenario_text_03A3[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// {/em}If you say so.{newline}{endline}
static s16 scenario_text_03BB[] = {
    CTR_CLOSE_EM, CHR_I, CHR_f, PCT_SPACE, CHR_y, CHR_o, CHR_u, PCT_SPACE, CHR_s, CHR_a,
    CHR_y, PCT_SPACE, CHR_s, CHR_o, PCT_PERIOD, CTR_NEWLINE, CTR_ENDLINE
};

// Come back if you change{newline}{endline}
static s16 scenario_text_03E4[] = {
    CHR_C, CHR_o, CHR_m, CHR_e, PCT_SPACE, CHR_b, CHR_a, CHR_c, CHR_k, PCT_SPACE,
    CHR_i, CHR_f, PCT_SPACE, CHR_y, CHR_o, CHR_u, PCT_SPACE, CHR_c, CHR_h, CHR_a,
    CHR_n, CHR_g, CHR_e, CTR_NEWLINE, CTR_ENDLINE
};

// your mind.{endline}
static s16 scenario_text_0411[] = {
    CHR_y, CHR_o, CHR_u, CHR_r, PCT_SPACE, CHR_m, CHR_i, CHR_n, CHR_d, PCT_PERIOD,
    CTR_ENDLINE
};

// {waitinput}{end}{endline}
static s16 scenario_text_0428[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE
};

// Address: @2cdc

// {newwindow}{endline}
static s16 scenario_text_0445[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// {/em}Narrator:Are you ready?!{endline}
static s16 scenario_text_045D[] = {
    CTR_CLOSE_EM, CHR_N, CHR_a, CHR_r, CHR_r, CHR_a, CHR_t, CHR_o, CHR_r, PCT_COLON,
    CHR_A, CHR_r, CHR_e, PCT_SPACE, CHR_y, CHR_o, CHR_u, PCT_SPACE, CHR_r, CHR_e,
    CHR_a, CHR_d, CHR_y, PCT_QUESTION, PCT_EXCLAMATION, CTR_ENDLINE
};

// {waitinput}{end}{endline}
static s16 scenario_text_0487[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE
};

// Address: @2f00

// Do you want to try again?{newline}{endline}
static s16 scenario_text_04A4[] = {
    CHR_D, CHR_o, PCT_SPACE, CHR_y, CHR_o, CHR_u, PCT_SPACE, CHR_w, CHR_a, CHR_n,
    CHR_t, PCT_SPACE, CHR_t, CHR_o, PCT_SPACE, CHR_t, CHR_r, CHR_y, PCT_SPACE, CHR_a,
    CHR_g, CHR_a, CHR_i, CHR_n, PCT_QUESTION, CTR_NEWLINE, CTR_ENDLINE
};

//   {newline}{endline}
static s16 scenario_text_04D3[] = {
    PCT_SPACE, PCT_SPACE, CTR_NEWLINE, CTR_ENDLINE
};

//   {em-yellow}Yes!{newline}{endline}
static s16 scenario_text_04EB[] = {
    PCT_SPACE, PCT_SPACE, CTR_EM_YELLOW, CHR_Y, CHR_e, CHR_s, PCT_EXCLAMATION, CTR_NEWLINE, CTR_ENDLINE
};

//   {em-yellow}No, I'd rather not.{newline}{endline}
static s16 scenario_text_0512[] = {
    PCT_SPACE, PCT_SPACE, CTR_EM_YELLOW, CHR_N, CHR_o, PCT_COMMA, PCT_SPACE, CHR_I, PCT_APOSTROPHE, CHR_d,
    PCT_SPACE, CHR_r, CHR_a, CHR_t, CHR_h, CHR_e, CHR_r, PCT_SPACE, CHR_n, CHR_o,
    CHR_t, PCT_PERIOD, CTR_NEWLINE, CTR_ENDLINE
};

// {end}{endline}
static s16 scenario_text_0548[] = {
    CTR_END, CTR_ENDLINE
};

// Address: @2fe8

// {newwindow}{endline}
static s16 scenario_text_055A[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// {/em}Narrator:I dread the thought of{newline}{endline}
static s16 scenario_text_0572[] = {
    CTR_CLOSE_EM, CHR_N, CHR_a, CHR_r, CHR_r, CHR_a, CHR_t, CHR_o, CHR_r, PCT_COLON,
    CHR_I, PCT_SPACE, CHR_d, CHR_r, CHR_e, CHR_a, CHR_d, PCT_SPACE, CHR_t, CHR_h,
    CHR_e, PCT_SPACE, CHR_t, CHR_h, CHR_o, CHR_u, CHR_g, CHR_h, CHR_t, PCT_SPACE,
    CHR_o, CHR_f, CTR_NEWLINE, CTR_ENDLINE
};

//        seeing a {em-yellow}male{/em} mermaid.{endline}
static s16 scenario_text_05AC[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_s, CHR_e, CHR_e,
    CHR_i, CHR_n, CHR_g, PCT_SPACE, CHR_a, PCT_SPACE, CTR_EM_YELLOW, CHR_m, CHR_a, CHR_l,
    CHR_e, CTR_CLOSE_EM, PCT_SPACE, CHR_m, CHR_e, CHR_r, CHR_m, CHR_a, CHR_i, CHR_d,
    PCT_PERIOD, CTR_ENDLINE
};

// {waitinput}{end}{endline}
static s16 scenario_text_05E6[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE
};

// Address: @301c

// {begin}{endline}
static s16 scenario_text_0603[] = {
    CTR_BEGIN, CTR_ENDLINE
};

//  {newline}{endline}
static s16 scenario_text_0617[] = {
    PCT_SPACE, CTR_NEWLINE, CTR_ENDLINE
};

//     {blink}{em-yellow}BEAUTIFULLY{newline}{endline}
static s16 scenario_text_062E[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CTR_BLINK, CTR_EM_YELLOW, CHR_B, CHR_E, CHR_A, CHR_U,
    CHR_T, CHR_I, CHR_F, CHR_U, CHR_L, CHR_L, CHR_Y, CTR_NEWLINE, CTR_ENDLINE
};

//             DONE!! {/em}{/blink}{button}{endline}
static s16 scenario_text_0665[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE,
    PCT_SPACE, PCT_SPACE, CHR_D, CHR_O, CHR_N, CHR_E, PCT_EXCLAMATION, PCT_EXCLAMATION, PCT_SPACE, CTR_CLOSE_EM,
    CTR_CLOSE_BLINK, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_069A[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// Narrator:Your gracious swimming{newline}{endline}
static s16 scenario_text_06B2[] = {
    CHR_N, CHR_a, CHR_r, CHR_r, CHR_a, CHR_t, CHR_o, CHR_r, PCT_COLON, CHR_Y,
    CHR_o, CHR_u, CHR_r, PCT_SPACE, CHR_g, CHR_r, CHR_a, CHR_c, CHR_i, CHR_o,
    CHR_u, CHR_s, PCT_SPACE, CHR_s, CHR_w, CHR_i, CHR_m, CHR_m, CHR_i, CHR_n,
    CHR_g, CTR_NEWLINE, CTR_ENDLINE
};

//        skills are like that of{newline}{endline}
static s16 scenario_text_06E7[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_s, CHR_k, CHR_i,
    CHR_l, CHR_l, CHR_s, PCT_SPACE, CHR_a, CHR_r, CHR_e, PCT_SPACE, CHR_l, CHR_i,
    CHR_k, CHR_e, PCT_SPACE, CHR_t, CHR_h, CHR_a, CHR_t, PCT_SPACE, CHR_o, CHR_f,
    CTR_NEWLINE, CTR_ENDLINE
};

//        the {em-yellow}Mermaid Princess{/em}!{button}{endline}
static s16 scenario_text_071B[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_t, CHR_h, CHR_e,
    PCT_SPACE, CTR_EM_YELLOW, CHR_M, CHR_e, CHR_r, CHR_m, CHR_a, CHR_i, CHR_d, PCT_SPACE,
    CHR_P, CHR_r, CHR_i, CHR_n, CHR_c, CHR_e, CHR_s, CHR_s, CTR_CLOSE_EM, PCT_EXCLAMATION,
    CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_075C[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// {end}{endline}
static s16 scenario_text_0774[] = {
    CTR_END, CTR_ENDLINE
};

// {begin}{endline}
static s16 scenario_text_0786[] = {
    CTR_BEGIN, CTR_ENDLINE
};

//  {newline}{endline}
static s16 scenario_text_079A[] = {
    PCT_SPACE, CTR_NEWLINE, CTR_ENDLINE
};

// Yae obtains{newline}{endline}
static s16 scenario_text_07B1[] = {
    CHR_Y, CHR_a, CHR_e, PCT_SPACE, CHR_o, CHR_b, CHR_t, CHR_a, CHR_i, CHR_n,
    CHR_s, CTR_NEWLINE, CTR_ENDLINE
};

//    the [{em-yellow}Mermaid{/em}] magic powers!{button}{endline}
static s16 scenario_text_07D2[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE, PCT_LBRACKET, CTR_EM_YELLOW, CHR_M,
    CHR_e, CHR_r, CHR_m, CHR_a, CHR_i, CHR_d, CTR_CLOSE_EM, PCT_RBRACKET, PCT_SPACE, CHR_m,
    CHR_a, CHR_g, CHR_i, CHR_c, PCT_SPACE, CHR_p, CHR_o, CHR_w, CHR_e, CHR_r,
    CHR_s, PCT_EXCLAMATION, CTR_BUTTON, CTR_ENDLINE
};

// {newwindow}{endline}
static s16 scenario_text_0815[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

//  {newline}{endline}
static s16 scenario_text_082D[] = {
    PCT_SPACE, CTR_NEWLINE, CTR_ENDLINE
};

// Now you can swim {em-yellow}underwater{/em} in{newline}{endline}
static s16 scenario_text_0844[] = {
    CHR_N, CHR_o, CHR_w, PCT_SPACE, CHR_y, CHR_o, CHR_u, PCT_SPACE, CHR_c, CHR_a,
    CHR_n, PCT_SPACE, CHR_s, CHR_w, CHR_i, CHR_m, PCT_SPACE, CTR_EM_YELLOW, CHR_u, CHR_n,
    CHR_d, CHR_e, CHR_r, CHR_w, CHR_a, CHR_t, CHR_e, CHR_r, CTR_CLOSE_EM, PCT_SPACE,
    CHR_i, CHR_n, CTR_NEWLINE, CTR_ENDLINE
};

// the deep ocean and rivers!{endline}
static s16 scenario_text_0888[] = {
    CHR_t, CHR_h, CHR_e, PCT_SPACE, CHR_d, CHR_e, CHR_e, CHR_p, PCT_SPACE, CHR_o,
    CHR_c, CHR_e, CHR_a, CHR_n, PCT_SPACE, CHR_a, CHR_n, CHR_d, PCT_SPACE, CHR_r,
    CHR_i, CHR_v, CHR_e, CHR_r, CHR_s, PCT_EXCLAMATION, CTR_ENDLINE
};

// {waitinput}{end}{endline}
static s16 scenario_text_08AF[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE
};

// Address: @31ec

// {newwindow}{endline}
static s16 scenario_text_08CC[] = {
    CTR_NEWWINDOW, CTR_ENDLINE
};

// [Waterfall of Kegon]{newline}{endline}
static s16 scenario_text_08E4[] = {
    PCT_LBRACKET, CHR_W, CHR_a, CHR_t, CHR_e, CHR_r, CHR_f, CHR_a, CHR_l, CHR_l,
    PCT_SPACE, CHR_o, CHR_f, PCT_SPACE, CHR_K, CHR_e, CHR_g, CHR_o, CHR_n, PCT_RBRACKET,
    CTR_NEWLINE, CTR_ENDLINE
};

// I hear that recently someone{newline}{endline}
static s16 scenario_text_090E[] = {
    CHR_I, PCT_SPACE, CHR_h, CHR_e, CHR_a, CHR_r, PCT_SPACE, CHR_t, CHR_h, CHR_a,
    CHR_t, PCT_SPACE, CHR_r, CHR_e, CHR_c, CHR_e, CHR_n, CHR_t, CHR_l, CHR_y,
    PCT_SPACE, CHR_s, CHR_o, CHR_m, CHR_e, CHR_o, CHR_n, CHR_e, CTR_NEWLINE, CTR_ENDLINE
};

// swam up this waterfall,{newline}{endline}
static s16 scenario_text_0940[] = {
    CHR_s, CHR_w, CHR_a, CHR_m, PCT_SPACE, CHR_u, CHR_p, PCT_SPACE, CHR_t, CHR_h,
    CHR_i, CHR_s, PCT_SPACE, CHR_w, CHR_a, CHR_t, CHR_e, CHR_r, CHR_f, CHR_a,
    CHR_l, CHR_l, PCT_COMMA, CTR_NEWLINE, CTR_ENDLINE
};

// and became a beautiful {em-yellow}mermaid{/em}.{endline}
static s16 scenario_text_096D[] = {
    CHR_a, CHR_n, CHR_d, PCT_SPACE, CHR_b, CHR_e, CHR_c, CHR_a, CHR_m, CHR_e,
    PCT_SPACE, CHR_a, PCT_SPACE, CHR_b, CHR_e, CHR_a, CHR_u, CHR_t, CHR_i, CHR_f,
    CHR_u, CHR_l, PCT_SPACE, CTR_EM_YELLOW, CHR_m, CHR_e, CHR_r, CHR_m, CHR_a, CHR_i,
    CHR_d, CTR_CLOSE_EM, PCT_PERIOD, CTR_ENDLINE
};

// {waitinput}{end}{endline}
static s16 scenario_text_09A9[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE
};

extern s32 scenario_code_message_176_2ad4[];
extern s32 scenario_code_message_176_2c2c[];
extern s32 scenario_code_message_176_2cb0[];
extern s32 scenario_code_message_176_2cdc[];
extern s32 scenario_code_message_176_2f00[];
extern s32 scenario_code_message_176_2fe8[];
extern s32 scenario_code_message_176_301c[];
extern s32 scenario_code_message_176_31ec[];

s32 scenario_code_message_176_2ad4[] = {

    // Address: @2ad4

    // 2ad4: Print Text
    TXT, (s32)&scenario_text_0000,

    // 2adc: Unset Flag 07a (Started Benkei/Mermaid Minigame)
    CFG, 0x7A,

    // 2ae4: If Flag 01e (Passed Mermaid Training), Jump To @301c
    // Jump if flag 0x1E is SET to @301c
    JFS, 0x1E, (s32)&scenario_code_message_176_301c,

    // 2af0: If Flag 01d (Failed Mermaid Training), Jump To @2f00
    // Jump if flag 0x1D is SET to @2f00
    JFS, 0x1D, (s32)&scenario_code_message_176_2f00,

    // 2afc: If Flag 015 (Met Ghost of Wise Man), Jump To @2c2c
    // Jump if flag 0x15 is SET to @2c2c
    JFS, 0x15, (s32)&scenario_code_message_176_2c2c,

    // 2b08: Write to RAM 801c77d8 (Text Speed)
    STW, 0x801c77d8,

    // 2b10: Store Value: 64
    WTS, 0x64,

    // 2b18: Write to RAM 801c7798 (Unknown)
    STW, 0x801c7798,

    // 2b20: Store Value: 1
    WTS, 0x1,

    // 2b28: Print Text
    TXT, (s32)&scenario_text_0014,

    // 2b30: Write to RAM 801c77d8 (Text Speed)
    STW, 0x801c77d8,

    // 2b38: Store Value: 1
    WTS, 0x1,

    // 2b40: Write to RAM 801c7798 (Unknown)
    STW, 0x801c7798,

    // 2b48: Store Value: 1
    WTS, 0x1,

    // 2b50: Print Text
    TXT, (s32)&scenario_text_003E,

    // 2b58: Print Text
    TXT, (s32)&scenario_text_006D,

    // 2b60: Print Text
    TXT, (s32)&scenario_text_00A3,

    // 2b68: Print Text
    TXT, (s32)&scenario_text_00DC,

    // 2b70: Write to RAM 801c77d8 (Text Speed)
    STW, 0x801c77d8,

    // 2b78: Store Value: 64
    WTS, 0x64,

    // 2b80: Write to RAM 801c7798 (Unknown)
    STW, 0x801c7798,

    // 2b88: Store Value: 1
    WTS, 0x1,

    // 2b90: Print Text
    TXT, (s32)&scenario_text_0014,

    // 2b98: Write to RAM 801c77d8 (Text Speed)
    STW, 0x801c77d8,

    // 2ba0: Store Value: 1
    WTS, 0x1,

    // 2ba8: Write to RAM 801c7798 (Unknown)
    STW, 0x801c7798,

    // 2bb0: Store Value: 1
    WTS, 0x1,

    // 2bb8: Print Text
    TXT, (s32)&scenario_text_011E,

    // 2bc0: Print Text
    TXT, (s32)&scenario_text_00DC,

    // 2bc8: Write to RAM 801c77d8 (Text Speed)
    STW, 0x801c77d8,

    // 2bd0: Store Value: 64
    WTS, 0x64,

    // 2bd8: Write to RAM 801c7798 (Unknown)
    STW, 0x801c7798,

    // 2be0: Store Value: 1
    WTS, 0x1,

    // 2be8: Print Text
    TXT, (s32)&scenario_text_0014,

    // 2bf0: Write to RAM 801c77d8 (Text Speed)
    STW, 0x801c77d8,

    // 2bf8: Store Value: 1
    WTS, 0x1,

    // 2c00: Write to RAM 801c7798 (Unknown)
    STW, 0x801c7798,

    // 2c08: Store Value: 1
    WTS, 0x1,

    // 2c10: Print Text
    TXT, (s32)&scenario_text_019D,

    // 2c18: Print Text
    TXT, (s32)&scenario_text_01CE,

    // 2c20: Print Text
    TXT, (s32)&scenario_text_01F7,

    // 2c28: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_176_2c2c[] = {

    // Address: @2c2c

    // 2c2c: Write to RAM 8007785c (Dialogue Portrait Character)
    STW, (s32)&D_8007785C_7845C,

    // 2c34: Store Value: 14
    WTS, 0x14,

    // 2c3c: Print Text
    TXT, (s32)&scenario_text_0214,

    // 2c44: Print Text
    TXT, (s32)&scenario_text_0246,

    // 2c4c: Print Text
    TXT, (s32)&scenario_text_0289,

    // 2c54: Print Text
    TXT, (s32)&scenario_text_00DC,

    // 2c5c: Write to RAM 8007785c (Dialogue Portrait Character)
    STW, (s32)&D_8007785C_7845C,

    // 2c64: Store Value: 100
    WTS, 0x100,

    // 2c6c: Print Text
    TXT, (s32)&scenario_text_02D4,

    // 2c74: Print Text
    TXT, (s32)&scenario_text_0302,

    // 2c7c: Begin Option Selection
    BOS,

    // 2c80: Print Text
    TXT, (s32)&scenario_text_0323,

    // 2c88: Jump To @2cdc
    JMP, (s32)&scenario_code_message_176_2cdc,

    // 2c90: Print Text
    TXT, (s32)&scenario_text_0350,

    // 2c98: Jump To @2cb0
    JMP, (s32)&scenario_code_message_176_2cb0,

    // 2ca0: End Option Selection
    EOS,

    // 2ca4: Print Text
    TXT, (s32)&scenario_text_0391,

    // 2cac: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_176_2cb0[] = {

    // Address: @2cb0

    // 2cb0: Print Text
    TXT, (s32)&scenario_text_00DC,

    // 2cb8: Print Text
    TXT, (s32)&scenario_text_03BB,

    // 2cc0: Print Text
    TXT, (s32)&scenario_text_03E4,

    // 2cc8: Print Text
    TXT, (s32)&scenario_text_0411,

    // 2cd0: Print Text
    TXT, (s32)&scenario_text_01F7,

    // 2cd8: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_176_2cdc[] = {

    // Address: @2cdc

    // 2cdc: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // 2ce4: Store Value: 1
    WTS, 0x1,

    // 2cec: Print Text
    TXT, (s32)&scenario_text_00DC,

    // 2cf4: Execute Code: 8003f594 (Load Current Character)
    ESR, (s32)&func_8003F594_40194,

    // 2cfc: Read from RAM 801c7750 (Scratch)
    LDW, 0x801c7750,

    // 2d04: Skip Next If Equal: 3
    SEQ, 0x3,

    // 2d0c: Jump To @2fe8
    JMP, (s32)&scenario_code_message_176_2fe8,

    // 2d14: Write to RAM 8007785c (Dialogue Portrait Character)
    STW, (s32)&D_8007785C_7845C,

    // 2d1c: Store Value: 14
    WTS, 0x14,

    // 2d24: Print Text
    TXT, (s32)&scenario_text_045D,

    // 2d2c: Print Text
    TXT, (s32)&scenario_text_01F7,

    // 2d34: Set Flag 07a (Started Benkei/Mermaid Minigame)
    SFG, 0x7A,

    // 2d3c: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_176_2f00[] = {

    // Address: @2f00

    // 2f00: Print Text
    TXT, (s32)&scenario_text_04A4,

    // 2f08: Print Text
    TXT, (s32)&scenario_text_04D3,

    // 2f10: Begin Option Selection
    BOS,

    // 2f14: Print Text
    TXT, (s32)&scenario_text_04EB,

    // 2f1c: Jump To @2cdc
    JMP, (s32)&scenario_code_message_176_2cdc,

    // 2f24: Print Text
    TXT, (s32)&scenario_text_0512,

    // 2f2c: Jump To @2cb0
    JMP, (s32)&scenario_code_message_176_2cb0,

    // 2f34: End Option Selection
    EOS,

    // 2f38: Print Text
    TXT, (s32)&scenario_text_0391,

    // 2f40: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_176_2fe8[] = {

    // Address: @2fe8

    // 2fe8: Print Text
    TXT, (s32)&scenario_text_00DC,

    // 2ff0: Write to RAM 8007785c (Dialogue Portrait Character)
    STW, (s32)&D_8007785C_7845C,

    // 2ff8: Store Value: 14
    WTS, 0x14,

    // 3000: Print Text
    TXT, (s32)&scenario_text_0572,

    // 3008: Print Text
    TXT, (s32)&scenario_text_05AC,

    // 3010: Print Text
    TXT, (s32)&scenario_text_01F7,

    // 3018: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_176_301c[] = {

    // Address: @301c

    // 301c: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // 3024: Store Value: 1
    WTS, 0x1,

    // 302c: Print Text
    TXT, (s32)&scenario_text_0000,

    // 3034: If Flag 01f (Obtained Mermaid Magic), Jump To @31ec
    // Jump if flag 0x1F is SET to @31ec
    JFS, 0x1F, (s32)&scenario_code_message_176_31ec,

    // 3040: Write to RAM 801c77d8 (Text Speed)
    STW, 0x801c77d8,

    // 3048: Store Value: 64
    WTS, 0x64,

    // 3050: Write to RAM 801c7798 (Unknown)
    STW, 0x801c7798,

    // 3058: Store Value: 1
    WTS, 0x1,

    // 3060: Print Text
    TXT, (s32)&scenario_text_0617,

    // 3068: Print Text
    TXT, (s32)&scenario_text_062E,

    // 3070: Print Text
    TXT, (s32)&scenario_text_0665,

    // 3078: Write to RAM 8007785c (Dialogue Portrait Character)
    STW, (s32)&D_8007785C_7845C,

    // 3080: Store Value: 14
    WTS, 0x14,

    // 3088: Print Text
    TXT, (s32)&scenario_text_00DC,

    // 3090: Write to RAM 801c77d8 (Text Speed)
    STW, 0x801c77d8,

    // 3098: Store Value: 1
    WTS, 0x1,

    // 30a0: Write to RAM 801c7798 (Unknown)
    STW, 0x801c7798,

    // 30a8: Store Value: 1
    WTS, 0x1,

    // 30b0: Print Text
    TXT, (s32)&scenario_text_06B2,

    // 30b8: Print Text
    TXT, (s32)&scenario_text_06E7,

    // 30c0: Print Text
    TXT, (s32)&scenario_text_071B,

    // 30c8: Print Text
    TXT, (s32)&scenario_text_00DC,

    // 30d0: Print Text
    TXT, (s32)&scenario_text_0391,

    // 30d8: Write to RAM 801c7758 (Unknown)
    STW, (s32)&D_801C7758_1C8358,

    // 30e0: Store Value: 20
    WTS, 0x20,

    // 30e8: Write to RAM 801c775c (Dialogue Window Y Pos)
    STW, (s32)&D_801C775C_1C835C,

    // 30f0: Store Value: 48
    WTS, 0x48,

    // 30f8: Write to RAM 8007785c (Dialogue Portrait Character)
    STW, (s32)&D_8007785C_7845C,

    // 3100: Store Value: 100
    WTS, 0x100,

    // 3108: Write to RAM 801c7768 (Dialogue Window Style)
    STW, (s32)&D_801C7768_1C8368,

    // 3110: Store Value: 7
    WTS, 0x7,

    // 3118: Print Text
    TXT, (s32)&scenario_text_0000,

    // 3120: Write to RAM 801c7770 (Unknown)
    STW, (s32)&D_801C7770_1C8370,

    // 3128: Store Value: 1
    WTS, 0x1,

    // 3130: Write to RAM 801c7740 (Scratch)
    STW, (s32)&D_801C7740_1C8340,

    // 3138: Store Value: 14
    WTS, 0x14,

    // 3140: Execute Code: 8003f608 (Play Sound)
    ESR, (s32)&func_8003F608_40208,

    // 3148: Set Flag 036 (Obtained Mermaid Magic (Unused?))
    SFG, 0x36,

    // 3150: Write to RAM 801c77d8 (Text Speed)
    STW, 0x801c77d8,

    // 3158: Store Value: 64
    WTS, 0x64,

    // 3160: Write to RAM 801c7798 (Unknown)
    STW, 0x801c7798,

    // 3168: Store Value: 1
    WTS, 0x1,

    // 3170: Print Text
    TXT, (s32)&scenario_text_0617,

    // 3178: Print Text
    TXT, (s32)&scenario_text_07B1,

    // 3180: Print Text
    TXT, (s32)&scenario_text_07D2,

    // 3188: Print Text
    TXT, (s32)&scenario_text_00DC,

    // 3190: Write to RAM 801c77d8 (Text Speed)
    STW, 0x801c77d8,

    // 3198: Store Value: 1
    WTS, 0x1,

    // 31a0: Write to RAM 801c7798 (Unknown)
    STW, 0x801c7798,

    // 31a8: Store Value: 1
    WTS, 0x1,

    // 31b0: Print Text
    TXT, (s32)&scenario_text_0617,

    // 31b8: Print Text
    TXT, (s32)&scenario_text_0844,

    // 31c0: Print Text
    TXT, (s32)&scenario_text_0888,

    // 31c8: Write to RAM 8015c6f8 (Obtained Mermaid Magic)
    STW, 0x8015c6f8,

    // 31d0: Store Value: 1
    WTS, 0x1,

    // 31d8: Set Flag 01f (Obtained Mermaid Magic)
    SFG, 0x1F,

    // 31e0: Print Text
    TXT, (s32)&scenario_text_01F7,

    // 31e8: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_176_31ec[] = {

    // Address: @31ec

    // 31ec: Print Text
    TXT, (s32)&scenario_text_00DC,

    // 31f4: Write to RAM 801c77d8 (Text Speed)
    STW, 0x801c77d8,

    // 31fc: Store Value: 64
    WTS, 0x64,

    // 3204: Write to RAM 801c7798 (Unknown)
    STW, 0x801c7798,

    // 320c: Store Value: 1
    WTS, 0x1,

    // 3214: Print Text
    TXT, (s32)&scenario_text_0014,

    // 321c: Write to RAM 801c77d8 (Text Speed)
    STW, 0x801c77d8,

    // 3224: Store Value: 1
    WTS, 0x1,

    // 322c: Write to RAM 801c7798 (Unknown)
    STW, 0x801c7798,

    // 3234: Store Value: 1
    WTS, 0x1,

    // 323c: Print Text
    TXT, (s32)&scenario_text_090E,

    // 3244: Print Text
    TXT, (s32)&scenario_text_0940,

    // 324c: Print Text
    TXT, (s32)&scenario_text_096D,

    // 3254: Print Text
    TXT, (s32)&scenario_text_01F7,

    // 325c: End Event
    END,

    // End scenario script
    END,
};

