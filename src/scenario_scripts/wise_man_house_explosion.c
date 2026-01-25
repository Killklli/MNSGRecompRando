#include "common.h"
#include "scenario.h"

// External scenario code declarations
extern s32 scenario_code_message_1cd_185c[];
extern s32 scenario_code_message_1cd_1920[];

// Address: @185c

// {begin}{endline}
static s16 scenario_text_0000[] = {CTR_BEGIN, CTR_ENDLINE};

// Goemon:See this?{button}{endline}
static s16 scenario_text_0014[] = {
    CHR_G, CHR_o, CHR_e, CHR_m, CHR_o, CHR_n,
    PCT_COLON, CHR_S, CHR_e, CHR_e, PCT_SPACE, CHR_t,
    CHR_h, CHR_i, CHR_s, PCT_QUESTION, CTR_BUTTON, CTR_ENDLINE};

// {newwindow}{endline}
static s16 scenario_text_0039[] = {CTR_NEWWINDOW, CTR_ENDLINE};

// Goemon:It's the {em-yellow}Triton Shell{/em}{newline}{endline}
static s16 scenario_text_0051[] = {
    CHR_G, CHR_o, CHR_e, CHR_m, CHR_o, CHR_n,
    PCT_COLON, CHR_I, CHR_t, PCT_APOSTROPHE, CHR_s, PCT_SPACE,
    CHR_t, CHR_h, CHR_e, PCT_SPACE, CTR_EM_YELLOW, CHR_T,
    CHR_r, CHR_i, CHR_t, CHR_o, CHR_n, PCT_SPACE,
    CHR_S, CHR_h, CHR_e, CHR_l, CHR_l, CTR_CLOSE_EM,
    CTR_NEWLINE, CTR_ENDLINE};

//       that summons{newline}{endline}
static s16 scenario_text_0093[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_t,
    CHR_h, CHR_a, CHR_t, PCT_SPACE, CHR_s, CHR_u, CHR_m,
    CHR_m, CHR_o, CHR_n, CHR_s, CTR_NEWLINE, CTR_ENDLINE};

//       Gigantic Robot "{em-yellow}Impact{/em}"!!{newline}{endline}
static s16 scenario_text_00BB[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE,
    PCT_SPACE, CHR_G, CHR_i, CHR_g, CHR_a,
    CHR_n, CHR_t, CHR_i, CHR_c, PCT_SPACE,
    CHR_R, CHR_o, CHR_b, CHR_o, CHR_t,
    PCT_SPACE, PCT_QUOTE, CTR_EM_YELLOW, CHR_I, CHR_m,
    CHR_p, CHR_a, CHR_c, CHR_t, CTR_CLOSE_EM,
    PCT_QUOTE, PCT_EXCLAMATION, PCT_EXCLAMATION, CTR_NEWLINE, CTR_ENDLINE};

//       {em-yellow}Wise Man{/em} had it...{button}{endline}
static s16 scenario_text_0100[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE,
    CTR_EM_YELLOW, CHR_W, CHR_i, CHR_s, CHR_e, PCT_SPACE,
    CHR_M, CHR_a, CHR_n, CTR_CLOSE_EM, PCT_SPACE, CHR_h,
    CHR_a, CHR_d, PCT_SPACE, CHR_i, CHR_t, PCT_PERIOD,
    PCT_PERIOD, PCT_PERIOD, CTR_BUTTON, CTR_ENDLINE};

// {newwindow}{endline}
static s16 scenario_text_013D[] = {CTR_NEWWINDOW, CTR_ENDLINE};

// Goemon:...and so is this rubble{newline}{endline}
static s16 scenario_text_0155[] = {
    CHR_G, CHR_o, CHR_e, CHR_m, CHR_o, CHR_n,
    PCT_COLON, PCT_PERIOD, PCT_PERIOD, PCT_PERIOD, CHR_a, CHR_n,
    CHR_d, PCT_SPACE, CHR_s, CHR_o, PCT_SPACE, CHR_i,
    CHR_s, PCT_SPACE, CHR_t, CHR_h, CHR_i, CHR_s,
    PCT_SPACE, CHR_r, CHR_u, CHR_b, CHR_b, CHR_l,
    CHR_e, CTR_NEWLINE, CTR_ENDLINE};

//       all that remains of{newline}{endline}
static s16 scenario_text_018A[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_a,
    CHR_l, CHR_l, PCT_SPACE, CHR_t, CHR_h, CHR_a, CHR_t,
    PCT_SPACE, CHR_r, CHR_e, CHR_m, CHR_a, CHR_i, CHR_n,
    CHR_s, PCT_SPACE, CHR_o, CHR_f, CTR_NEWLINE, CTR_ENDLINE};

//       {em-yellow}Wise Man's house{/em}?!{endline}
static s16 scenario_text_01B9[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE,
    PCT_SPACE, CTR_EM_YELLOW, CHR_W, CHR_i, CHR_s,
    CHR_e, PCT_SPACE, CHR_M, CHR_a, CHR_n,
    PCT_APOSTROPHE, CHR_s, PCT_SPACE, CHR_h, CHR_o,
    CHR_u, CHR_s, CHR_e, CTR_CLOSE_EM, PCT_QUESTION,
    PCT_EXCLAMATION, CTR_ENDLINE};

// {waitinput}{end}{endline}
static s16 scenario_text_01EE[] = {CTR_WAITINPUT, CTR_END, CTR_ENDLINE};

// Address: @1920

// {begin}{endline}
static s16 scenario_text_020B[] = {CTR_BEGIN, CTR_ENDLINE};

// Ebisumaru:Hey!{button}{endline}
static s16 scenario_text_021F[] = {
    CHR_E, CHR_b, CHR_i, CHR_s, CHR_u, CHR_m,
    CHR_a, CHR_r, CHR_u, PCT_COLON, CHR_H, CHR_e,
    CHR_y, PCT_EXCLAMATION, CTR_BUTTON, CTR_ENDLINE};

// {newwindow}{endline}
static s16 scenario_text_0242[] = {CTR_NEWWINDOW, CTR_ENDLINE};

// Ebisumaru:This is the {em-yellow}Triton Shell{/em}{newline}{endline}
static s16 scenario_text_025A[] = {
    CHR_E, CHR_b, CHR_i, CHR_s, CHR_u, CHR_m, CHR_a,
    CHR_r, CHR_u, PCT_COLON, CHR_T, CHR_h, CHR_i, CHR_s,
    PCT_SPACE, CHR_i, CHR_s, PCT_SPACE, CHR_t, CHR_h, CHR_e,
    PCT_SPACE, CTR_EM_YELLOW, CHR_T, CHR_r, CHR_i, CHR_t, CHR_o,
    CHR_n, PCT_SPACE, CHR_S, CHR_h, CHR_e, CHR_l, CHR_l,
    CTR_CLOSE_EM, CTR_NEWLINE, CTR_ENDLINE};

//        that {em-yellow}Wise Man{/em} had that{newline}{endline}
static s16 scenario_text_02A2[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE,
    PCT_SPACE, CHR_t, CHR_h, CHR_a, CHR_t, PCT_SPACE,
    CTR_EM_YELLOW, CHR_W, CHR_i, CHR_s, CHR_e, PCT_SPACE,
    CHR_M, CHR_a, CHR_n, CTR_CLOSE_EM, PCT_SPACE, CHR_h,
    CHR_a, CHR_d, PCT_SPACE, CHR_t, CHR_h, CHR_a,
    CHR_t, CTR_NEWLINE, CTR_ENDLINE};

//        summons Gigantic Robot{newline}{endline}
static s16 scenario_text_02E5[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE,
    PCT_SPACE, CHR_s, CHR_u, CHR_m, CHR_m, CHR_o,
    CHR_n, CHR_s, PCT_SPACE, CHR_G, CHR_i, CHR_g,
    CHR_a, CHR_n, CHR_t, CHR_i, CHR_c, PCT_SPACE,
    CHR_R, CHR_o, CHR_b, CHR_o, CHR_t, CTR_NEWLINE,
    CTR_ENDLINE};

//        "{em-yellow}Impact{/em}"...{button}{endline}
static s16 scenario_text_0318[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE,
    PCT_SPACE, PCT_QUOTE, CTR_EM_YELLOW, CHR_I, CHR_m, CHR_p,
    CHR_a, CHR_c, CHR_t, CTR_CLOSE_EM, PCT_QUOTE, PCT_PERIOD,
    PCT_PERIOD, PCT_PERIOD, CTR_BUTTON, CTR_ENDLINE};

// {newwindow}{endline}
static s16 scenario_text_034F[] = {CTR_NEWWINDOW, CTR_ENDLINE};

// Ebisumaru:...wait!{newline}{endline}
static s16 scenario_text_0367[] = {
    CHR_E, CHR_b, CHR_i, CHR_s, CHR_u, CHR_m, CHR_a,
    CHR_r, CHR_u, PCT_COLON, PCT_PERIOD, PCT_PERIOD, PCT_PERIOD, CHR_w,
    CHR_a, CHR_i, CHR_t, PCT_EXCLAMATION, CTR_NEWLINE, CTR_ENDLINE};

//        That would mean{newline}{endline}
static s16 scenario_text_038F[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE,
    PCT_SPACE, CHR_T, CHR_h, CHR_a, CHR_t, PCT_SPACE,
    CHR_w, CHR_o, CHR_u, CHR_l, CHR_d, PCT_SPACE,
    CHR_m, CHR_e, CHR_a, CHR_n, CTR_NEWLINE, CTR_ENDLINE};

//        that this here is{newline}{endline}
static s16 scenario_text_03BB[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE,
    PCT_SPACE, CHR_t, CHR_h, CHR_a, CHR_t, PCT_SPACE,
    CHR_t, CHR_h, CHR_i, CHR_s, PCT_SPACE, CHR_h,
    CHR_e, CHR_r, CHR_e, PCT_SPACE, CHR_i, CHR_s,
    CTR_NEWLINE, CTR_ENDLINE};

//        {em-yellow}Wise Man's house{/em}!{endline}
static s16 scenario_text_03E9[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE,
    PCT_SPACE, PCT_SPACE, CTR_EM_YELLOW, CHR_W, CHR_i,
    CHR_s, CHR_e, PCT_SPACE, CHR_M, CHR_a,
    CHR_n, PCT_APOSTROPHE, CHR_s, PCT_SPACE, CHR_h,
    CHR_o, CHR_u, CHR_s, CHR_e, CTR_CLOSE_EM,
    PCT_EXCLAMATION, CTR_ENDLINE};

// {button}{end}{endline}
static s16 scenario_text_041E[] = {CTR_BUTTON, CTR_END, CTR_ENDLINE};

s32 scenario_code_message_1cd_185c[] = {

    // Address: @185c

    // 185c: Write to RAM 801c7768 (Dialogue Window Style)
    STW,
    (s32)&D_801C7768_1C8368,

    // 1864: Store Value: 6
    WTS,
    0x6,

    // 186c: Execute Code: 8003f594 (Load Current Character)
    ESR,
    (s32)&func_8003F594_40194,

    // 1874: Read from RAM 801c7750 (Scratch)
    LDW,
    0x801c7750,

    // 187c: Skip Next If Not Equal: 1
    SNE,
    0x1,

    // 1884: Jump To @1920
    JMP,
    (s32)&scenario_code_message_1cd_1920,

    // 188c: Write to RAM 8007785c (Dialogue Portrait Character)
    STW,
    (s32)&D_8007785C_7845C,

    // 1894: Store Value: 0
    WTS,
    0x0,

    // 189c: Print Text
    TXT,
    (s32)&scenario_text_0000,

    // 18a4: Write to RAM 801c7770 (Unknown)
    STW,
    (s32)&D_801C7770_1C8370,

    // 18ac: Store Value: 1
    WTS,
    0x1,

    // 18b4: Print Text
    TXT,
    (s32)&scenario_text_0014,

    // 18bc: Print Text
    TXT,
    (s32)&scenario_text_0039,

    // 18c4: Print Text
    TXT,
    (s32)&scenario_text_0051,

    // 18cc: Print Text
    TXT,
    (s32)&scenario_text_0093,

    // 18d4: Print Text
    TXT,
    (s32)&scenario_text_00BB,

    // 18dc: Print Text
    TXT,
    (s32)&scenario_text_0100,

    // 18e4: Print Text
    TXT,
    (s32)&scenario_text_0039,

    // 18ec: Print Text
    TXT,
    (s32)&scenario_text_0155,

    // 18f4: Print Text
    TXT,
    (s32)&scenario_text_018A,

    // 18fc: Print Text
    TXT,
    (s32)&scenario_text_01B9,

    // 1904: Write to RAM 8015c6fc (Obtained Triton Shell)
    STW,
    0x8015c6fc,

    // 190c: Store Value: 1
    WTS,
    0x1,

    // 1914: Print Text
    TXT,
    (s32)&scenario_text_01EE,

    // 191c: End Event
    END,

    // End scenario script
    END,
};

s32 scenario_code_message_1cd_1920[] = {

    // Address: @1920

    // 1920: Write to RAM 8007785c (Dialogue Portrait Character)
    STW,
    (s32)&D_8007785C_7845C,

    // 1928: Store Value: 2
    WTS,
    0x2,

    // 1930: Print Text
    TXT,
    (s32)&scenario_text_0000,

    // 1938: Write to RAM 801c7770 (Unknown)
    STW,
    (s32)&D_801C7770_1C8370,

    // 1940: Store Value: 1
    WTS,
    0x1,

    // 1948: Print Text
    TXT,
    (s32)&scenario_text_021F,

    // 1950: Print Text
    TXT,
    (s32)&scenario_text_0039,

    // 1958: Print Text
    TXT,
    (s32)&scenario_text_025A,

    // 1960: Print Text
    TXT,
    (s32)&scenario_text_02A2,

    // 1968: Print Text
    TXT,
    (s32)&scenario_text_02E5,

    // 1970: Print Text
    TXT,
    (s32)&scenario_text_0318,

    // 1978: Print Text
    TXT,
    (s32)&scenario_text_0039,

    // 1980: Print Text
    TXT,
    (s32)&scenario_text_0367,

    // 1988: Print Text
    TXT,
    (s32)&scenario_text_038F,

    // 1990: Print Text
    TXT,
    (s32)&scenario_text_03BB,

    // 1998: Print Text
    TXT,
    (s32)&scenario_text_03E9,

    // 19a0: Write to RAM 8015c6fc (Obtained Triton Shell)
    STW,
    0x8015c6fc,

    // 19a8: Store Value: 1
    WTS,
    0x1,

    // 19b0: Print Text
    TXT,
    (s32)&scenario_text_041E,

    // 19b8: End Event
    END,

    // End scenario script
    END,
};
