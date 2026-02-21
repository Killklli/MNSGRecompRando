#include "types.h"
#include "scenario.h"
#include "scenario_replacer.h"

// Function declarations
void update_super_jump_text(void);


// Forward declarations
s32 scenario_code_3260[];
s32 scenario_code_3320[];
s32 scenario_code_334c[];
s32 scenario_code_33a0[];
s32 scenario_code_3650[];
s32 scenario_code_37e4[];
s32 scenario_code_3868[];

// ==================== TEXT STRINGS ====================

// {begin}{endline}
static s16 scenario_text_0000[] = {
    CTR_BEGIN, CTR_ENDLINE};

// Good of you to come!{button}{endline}
static s16 scenario_text_0024[] = {
    CHR_G, CHR_o, CHR_o, CHR_d, PCT_SPACE, CHR_o, CHR_f, PCT_SPACE, CHR_y, CHR_o, 
    CHR_u, PCT_SPACE, CHR_t, CHR_o, PCT_SPACE, CHR_c, CHR_o, CHR_m, CHR_e, PCT_EXCLAMATION, 
    CTR_BUTTON, CTR_ENDLINE};

// {newwindow}{endline}
static s16 scenario_text_005D[] = {
    CTR_NEWWINDOW, CTR_ENDLINE};

// This is where you will train to{newline}{endline}
static s16 scenario_text_0085[] = {
    CHR_T, CHR_h, CHR_i, CHR_s, PCT_SPACE, CHR_i, CHR_s, PCT_SPACE, CHR_w, CHR_h, 
    CHR_e, CHR_r, CHR_e, PCT_SPACE, CHR_y, CHR_o, CHR_u, PCT_SPACE, CHR_w, CHR_i, 
    CHR_l, CHR_l, PCT_SPACE, CHR_t, CHR_r, CHR_a, CHR_i, CHR_n, PCT_SPACE, CHR_t, 
    CHR_o, CTR_NEWLINE, CTR_ENDLINE};

// develop your legs and ankles,{newline}{endline}
static s16 scenario_text_00CA[] = {
    CHR_d, CHR_e, CHR_v, CHR_e, CHR_l, CHR_o, CHR_p, PCT_SPACE, CHR_y, CHR_o, 
    CHR_u, CHR_r, PCT_SPACE, CHR_l, CHR_e, CHR_g, CHR_s, PCT_SPACE, CHR_a, CHR_n, 
    CHR_d, PCT_SPACE, CHR_a, CHR_n, CHR_k, CHR_l, CHR_e, CHR_s, PCT_COMMA, CTR_NEWLINE, 
    CTR_ENDLINE};

// and become a {em-yellow}Super Jumper{/em}!{button}{endline}
static s16 scenario_text_010D[] = {
    CHR_a, CHR_n, CHR_d, PCT_SPACE, CHR_b, CHR_e, CHR_c, CHR_o, CHR_m, CHR_e, 
    PCT_SPACE, CHR_a, PCT_SPACE, CTR_EM_YELLOW, CHR_S, CHR_u, CHR_p, CHR_e, CHR_r, PCT_SPACE, 
    CHR_J, CHR_u, CHR_m, CHR_p, CHR_e, CHR_r, CTR_CLOSE_EM, PCT_EXCLAMATION, CTR_BUTTON, CTR_ENDLINE};

// {newwindow}{endline}
static s16 scenario_text_015C[] = {
    CTR_NEWWINDOW, CTR_ENDLINE};

// Have you come to take on {newline}{endline}
static s16 scenario_text_0184[] = {
    CHR_H, CHR_a, CHR_v, CHR_e, PCT_SPACE, CHR_y, CHR_o, CHR_u, PCT_SPACE, CHR_c, 
    CHR_o, CHR_m, CHR_e, PCT_SPACE, CHR_t, CHR_o, PCT_SPACE, CHR_t, CHR_a, CHR_k, 
    CHR_e, PCT_SPACE, CHR_o, CHR_n, PCT_SPACE, CTR_NEWLINE, CTR_ENDLINE};

// this training?{newline}{endline}
static s16 scenario_text_01C3[] = {
    CHR_t, CHR_h, CHR_i, CHR_s, PCT_SPACE, CHR_t, CHR_r, CHR_a, CHR_i, CHR_n, 
    CHR_i, CHR_n, CHR_g, PCT_QUESTION, CTR_NEWLINE, CTR_ENDLINE};

//   {em-yellow}Yes!{newline}{endline}
static s16 scenario_text_01F7[] = {
    PCT_SPACE, PCT_SPACE, CTR_EM_YELLOW, CHR_Y, CHR_e, CHR_s, PCT_EXCLAMATION, CTR_NEWLINE, CTR_ENDLINE};

//   {em-yellow}Not quite.{newline}{endline}
static s16 scenario_text_022E[] = {
    PCT_SPACE, PCT_SPACE, CTR_EM_YELLOW, CHR_N, CHR_o, CHR_t, PCT_SPACE, CHR_q, CHR_u, CHR_i, 
    CHR_t, CHR_e, PCT_PERIOD, CTR_NEWLINE, CTR_ENDLINE};

// {end}{endline}
static s16 scenario_text_026B[] = {
    CTR_END, CTR_ENDLINE};

// {newwindow}{endline}
static s16 scenario_text_028D[] = {
    CTR_NEWWINDOW, CTR_ENDLINE};

// {/em}Is that so!{newline}{endline}
static s16 scenario_text_02B5[] = {
    CTR_CLOSE_EM, CHR_I, CHR_s, PCT_SPACE, CHR_t, CHR_h, CHR_a, CHR_t, PCT_SPACE, CHR_s, 
    CHR_o, PCT_EXCLAMATION, CTR_NEWLINE, CTR_ENDLINE};

// I'm too busy to be dealing{newline}{endline}
static s16 scenario_text_02EB[] = {
    CHR_I, PCT_APOSTROPHE, CHR_m, PCT_SPACE, CHR_t, CHR_o, CHR_o, PCT_SPACE, CHR_b, CHR_u, 
    CHR_s, CHR_y, PCT_SPACE, CHR_t, CHR_o, PCT_SPACE, CHR_b, CHR_e, PCT_SPACE, CHR_d, 
    CHR_e, CHR_a, CHR_l, CHR_i, CHR_n, CHR_g, CTR_NEWLINE, CTR_ENDLINE};

// with jokers like you anyway!{endline}
static s16 scenario_text_032B[] = {
    CHR_w, CHR_i, CHR_t, CHR_h, PCT_SPACE, CHR_j, CHR_o, CHR_k, CHR_e, CHR_r, 
    CHR_s, PCT_SPACE, CHR_l, CHR_i, CHR_k, CHR_e, PCT_SPACE, CHR_y, CHR_o, CHR_u, 
    PCT_SPACE, CHR_a, CHR_n, CHR_y, CHR_w, CHR_a, CHR_y, PCT_EXCLAMATION, CTR_ENDLINE};

// {waitinput}{end}{endline}
static s16 scenario_text_0364[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE};

// {newwindow}{endline}
static s16 scenario_text_0391[] = {
    CTR_NEWWINDOW, CTR_ENDLINE};

// {/em}I'll show you to the Training Gym.{endline}
static s16 scenario_text_03B9[] = {
    CTR_CLOSE_EM, CHR_I, PCT_APOSTROPHE, CHR_l, CHR_l, PCT_SPACE, CHR_s, CHR_h, CHR_o, CHR_w, 
    PCT_SPACE, CHR_y, CHR_o, CHR_u, PCT_SPACE, CHR_t, CHR_o, PCT_SPACE, CHR_t, CHR_h, 
    CHR_e, PCT_SPACE, CHR_T, CHR_r, CHR_a, CHR_i, CHR_n, CHR_i, CHR_n, CHR_g, 
    PCT_SPACE, CHR_G, CHR_y, CHR_m, PCT_PERIOD, CTR_ENDLINE};

// {waitinput}{end}{endline}
static s16 scenario_text_03FD[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE};

// Jumping is {em-yellow}my life{/em}, {newline}{endline}
static s16 scenario_text_042A[] = {
    CHR_J, CHR_u, CHR_m, CHR_p, CHR_i, CHR_n, CHR_g, PCT_SPACE, CHR_i, CHR_s, 
    PCT_SPACE, CTR_EM_YELLOW, CHR_m, CHR_y, PCT_SPACE, CHR_l, CHR_i, CHR_f, CHR_e, CTR_CLOSE_EM, 
    PCT_COMMA, PCT_SPACE, CTR_NEWLINE, CTR_ENDLINE};

// it's all I've known!{endline}
static s16 scenario_text_0474[] = {
    CHR_i, CHR_t, PCT_APOSTROPHE, CHR_s, PCT_SPACE, CHR_a, CHR_l, CHR_l, PCT_SPACE, CHR_I, 
    PCT_APOSTROPHE, CHR_v, CHR_e, PCT_SPACE, CHR_k, CHR_n, CHR_o, CHR_w, CHR_n, PCT_EXCLAMATION, 
    CTR_ENDLINE};

// {waitinput}{end}{endline}
static s16 scenario_text_04A5[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE};

// {begin}{endline}
static s16 scenario_text_04D2[] = {
    CTR_BEGIN, CTR_ENDLINE};

// {em-yellow}Bravo!{/em}{newline}{endline}
static s16 scenario_text_04F6[] = {
    CTR_EM_YELLOW, CHR_B, CHR_r, CHR_a, CHR_v, CHR_o, PCT_EXCLAMATION, CTR_CLOSE_EM, CTR_NEWLINE, CTR_ENDLINE};

// From now on, you can call{newline}{endline}
static s16 scenario_text_0532[] = {
    CHR_F, CHR_r, CHR_o, CHR_m, PCT_SPACE, CHR_n, CHR_o, CHR_w, PCT_SPACE, CHR_o, 
    CHR_n, PCT_COMMA, PCT_SPACE, CHR_y, CHR_o, CHR_u, PCT_SPACE, CHR_c, CHR_a, CHR_n, 
    PCT_SPACE, CHR_c, CHR_a, CHR_l, CHR_l, CTR_NEWLINE, CTR_ENDLINE};

// yourself a {em-yellow}Super Jumper{/em}!{button}{endline}
static s16 scenario_text_0571[] = {
    CHR_y, CHR_o, CHR_u, CHR_r, CHR_s, CHR_e, CHR_l, CHR_f, PCT_SPACE, CHR_a, 
    PCT_SPACE, CTR_EM_YELLOW, CHR_S, CHR_u, CHR_p, CHR_e, CHR_r, PCT_SPACE, CHR_J, CHR_u, 
    CHR_m, CHR_p, CHR_e, CHR_r, CTR_CLOSE_EM, PCT_EXCLAMATION, CTR_BUTTON, CTR_ENDLINE};

// {newwindow}{endline}
static s16 scenario_text_05BE[] = {
    CTR_NEWWINDOW, CTR_ENDLINE};

// {end}{endline}
static s16 scenario_text_05E6[] = {
    CTR_END, CTR_ENDLINE};

// {begin}{endline}
static s16 scenario_text_0608[] = {
    CTR_BEGIN, CTR_ENDLINE};

//   {newline}{endline}
static s16 scenario_text_062C[] = {
    PCT_SPACE, PCT_SPACE, CTR_NEWLINE, CTR_ENDLINE};

// Sasuke obtains{newline}{endline}
static s16 scenario_text_0654[] = {
    CHR_S, CHR_a, CHR_s, CHR_u, CHR_k, CHR_e, PCT_SPACE, CHR_o, CHR_b, CHR_t, 
    CHR_a, CHR_i, CHR_n, CHR_s, CTR_NEWLINE, CTR_ENDLINE};

//    the [{em-yellow}Flying{/em}] magic powers!{newline}{endline}
static s16 scenario_text_0688[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE, CTR_EM_YELLOW, CHR_F, CHR_l, 
    CHR_y, CHR_i, CHR_n, CHR_g, CTR_CLOSE_EM, PCT_SPACE, CHR_m, CHR_a, CHR_g, CHR_i, 
    CHR_c, PCT_SPACE, CHR_p, CHR_o, CHR_w, CHR_e, CHR_r, CHR_s, PCT_EXCLAMATION, CTR_NEWLINE, 
    CTR_ENDLINE};

// {button}{endline}
static s16 scenario_text_06DB[] = {
    CTR_BUTTON, CTR_ENDLINE};

// {newwindow}{endline}
static s16 scenario_text_0700[] = {
    CTR_NEWWINDOW, CTR_ENDLINE};

// Using the {em-yellow}Super Jump{/em}, you can {newline}{endline}
static s16 scenario_text_0728[] = {
    CHR_U, CHR_s, CHR_i, CHR_n, CHR_g, PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE, 
    CTR_EM_YELLOW, CHR_S, CHR_u, CHR_p, CHR_e, CHR_r, PCT_SPACE, CHR_J, CHR_u, CHR_m, 
    CHR_p, CTR_CLOSE_EM, PCT_COMMA, PCT_SPACE, CHR_y, CHR_o, CHR_u, PCT_SPACE, CHR_c, CHR_a, 
    CHR_n, PCT_SPACE, CTR_NEWLINE, CTR_ENDLINE};

// go to {em-yellow}high places{/em} that were{newline}{endline}
static s16 scenario_text_077C[] = {
    CHR_g, CHR_o, PCT_SPACE, CHR_t, CHR_o, PCT_SPACE, CTR_EM_YELLOW, CHR_h, CHR_i, CHR_g, 
    CHR_h, PCT_SPACE, CHR_p, CHR_l, CHR_a, CHR_c, CHR_e, CHR_s, CTR_CLOSE_EM, PCT_SPACE, 
    CHR_t, CHR_h, CHR_a, CHR_t, PCT_SPACE, CHR_w, CHR_e, CHR_r, CHR_e, CTR_NEWLINE, 
    CTR_ENDLINE};

// previously unreachable!{endline}
static s16 scenario_text_07CD[] = {
    CHR_p, CHR_r, CHR_e, CHR_v, CHR_i, CHR_o, CHR_u, CHR_s, CHR_l, CHR_y, 
    PCT_SPACE, CHR_u, CHR_n, CHR_r, CHR_e, CHR_a, CHR_c, CHR_h, CHR_a, CHR_b, 
    CHR_l, CHR_e, PCT_EXCLAMATION, CTR_ENDLINE};

// {waitinput}{end}{endline}
static s16 scenario_text_0801[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE};

// {begin}{endline}
static s16 scenario_text_082E[] = {
    CTR_BEGIN, CTR_ENDLINE};

// Oh! No good!{newline}{endline}
static s16 scenario_text_0852[] = {
    CHR_O, CHR_h, PCT_EXCLAMATION, PCT_SPACE, CHR_N, CHR_o, PCT_SPACE, CHR_g, CHR_o, CHR_o, 
    CHR_d, PCT_EXCLAMATION, CTR_NEWLINE, CTR_ENDLINE};

// That's really too bad!{button}{endline}
static s16 scenario_text_0884[] = {
    CHR_T, CHR_h, CHR_a, CHR_t, PCT_APOSTROPHE, CHR_s, PCT_SPACE, CHR_r, CHR_e, CHR_a, 
    CHR_l, CHR_l, CHR_y, PCT_SPACE, CHR_t, CHR_o, CHR_o, PCT_SPACE, CHR_b, CHR_a, 
    CHR_d, PCT_EXCLAMATION, CTR_BUTTON, CTR_ENDLINE};

// {newwindow}{endline}
static s16 scenario_text_08BF[] = {
    CTR_NEWWINDOW, CTR_ENDLINE};

// At that rate, {newline}{endline}
static s16 scenario_text_08E7[] = {
    CHR_A, CHR_t, PCT_SPACE, CHR_t, CHR_h, CHR_a, CHR_t, PCT_SPACE, CHR_r, CHR_a, 
    CHR_t, CHR_e, PCT_COMMA, PCT_SPACE, CTR_NEWLINE, CTR_ENDLINE};

// you couldn't clear a {em-yellow}kerb{/em}.{button}{endline}
static s16 scenario_text_091B[] = {
    CHR_y, CHR_o, CHR_u, PCT_SPACE, CHR_c, CHR_o, CHR_u, CHR_l, CHR_d, CHR_n, 
    PCT_APOSTROPHE, CHR_t, PCT_SPACE, CHR_c, CHR_l, CHR_e, CHR_a, CHR_r, PCT_SPACE, CHR_a, 
    PCT_SPACE, CTR_EM_YELLOW, CHR_k, CHR_e, CHR_r, CHR_b, CTR_CLOSE_EM, PCT_PERIOD, CTR_BUTTON, CTR_ENDLINE};

// {newwindow}{endline}
static s16 scenario_text_096A[] = {
    CTR_NEWWINDOW, CTR_ENDLINE};

// Hya hya hya hya hya...{endline}
static s16 scenario_text_0992[] = {
    CHR_H, CHR_y, CHR_a, PCT_SPACE, CHR_h, CHR_y, CHR_a, PCT_SPACE, CHR_h, CHR_y, 
    CHR_a, PCT_SPACE, CHR_h, CHR_y, CHR_a, PCT_SPACE, CHR_h, CHR_y, CHR_a, PCT_PERIOD, 
    PCT_PERIOD, PCT_PERIOD, CTR_ENDLINE};

// {waitinput}{end}{endline}
static s16 scenario_text_09C5[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE};

// {/em}Hmmm.{newline}{endline}
static s16 scenario_text_09F2[] = {
    CTR_CLOSE_EM, CHR_H, CHR_m, CHR_m, CHR_m, PCT_PERIOD, CTR_NEWLINE, CTR_ENDLINE};

// It wouldn't be for you...{button}{endline}
static s16 scenario_text_0A22[] = {
    CHR_I, CHR_t, PCT_SPACE, CHR_w, CHR_o, CHR_u, CHR_l, CHR_d, CHR_n, PCT_APOSTROPHE, 
    CHR_t, PCT_SPACE, CHR_b, CHR_e, PCT_SPACE, CHR_f, CHR_o, CHR_r, PCT_SPACE, CHR_y, 
    CHR_o, CHR_u, PCT_PERIOD, PCT_PERIOD, PCT_PERIOD, CTR_BUTTON, CTR_ENDLINE};

// {newwindow}{endline}
static s16 scenario_text_0A60[] = {
    CTR_NEWWINDOW, CTR_ENDLINE};

// It's got to be someone with{newline}{endline}
static s16 scenario_text_0A88[] = {
    CHR_I, CHR_t, PCT_APOSTROPHE, CHR_s, PCT_SPACE, CHR_g, CHR_o, CHR_t, PCT_SPACE, CHR_t, 
    CHR_o, PCT_SPACE, CHR_b, CHR_e, PCT_SPACE, CHR_s, CHR_o, CHR_m, CHR_e, CHR_o, 
    CHR_n, CHR_e, PCT_SPACE, CHR_w, CHR_i, CHR_t, CHR_h, CTR_NEWLINE, CTR_ENDLINE};

// {em-yellow}triangular eyebrows{/em} and{newline}{endline}
static s16 scenario_text_0AC9[] = {
    CTR_EM_YELLOW, CHR_t, CHR_r, CHR_i, CHR_a, CHR_n, CHR_g, CHR_u, CHR_l, CHR_a, 
    CHR_r, PCT_SPACE, CHR_e, CHR_y, CHR_e, CHR_b, CHR_r, CHR_o, CHR_w, CHR_s, 
    CTR_CLOSE_EM, PCT_SPACE, CHR_a, CHR_n, CHR_d, CTR_NEWLINE, CTR_ENDLINE};

// a {em-yellow}round head{/em}.{endline}
static s16 scenario_text_0B16[] = {
    CHR_a, PCT_SPACE, CTR_EM_YELLOW, CHR_r, CHR_o, CHR_u, CHR_n, CHR_d, PCT_SPACE, CHR_h, 
    CHR_e, CHR_a, CHR_d, CTR_CLOSE_EM, PCT_PERIOD, CTR_ENDLINE};

// {waitinput}{end}{endline}
static s16 scenario_text_0B50[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE};

// ==================== SCENARIO CODE ====================

// Message at @3260
s32 scenario_code_3260[] = {

    // 3260: Write to RAM 801c7758 (Unknown)
    STW,
    0x801c7758,

    // 3268: Store Value: 20
    WTS,
    0x20,

    // 3270: Write to RAM 801c775c (Dialogue Window Y Pos)
    STW,
    0x801c775c,

    // 3278: Store Value: 68
    WTS,
    0x68,

    // 3280: Print Text
    TXT,
    (s32)&scenario_text_0000,

    // 3288: If Flag 020 (Obtained Super Jump Magic), Jump To @33a0
    JFS,
    0x20,
    (s32)&scenario_code_33a0,

    // 3294: If Flag 061 (Passed Super Jump Training), Jump To @3650
    JFS,
    0x61,
    (s32)&scenario_code_3650,

    // 32a0: If Flag 062 (Failed Super Jump Training), Jump To @37e4
    JFS,
    0x62,
    (s32)&scenario_code_37e4,

    // 32ac: Print Text
    TXT,
    (s32)&scenario_text_0024,

    // 32b4: Print Text
    TXT,
    (s32)&scenario_text_005D,

    // 32bc: Print Text
    TXT,
    (s32)&scenario_text_0085,

    // 32c4: Print Text
    TXT,
    (s32)&scenario_text_00CA,

    // 32cc: Print Text
    TXT,
    (s32)&scenario_text_010D,

    // 32d4: Print Text
    TXT,
    (s32)&scenario_text_015C,

    // 32dc: Print Text
    TXT,
    (s32)&scenario_text_0184,

    // 32e4: Print Text
    TXT,
    (s32)&scenario_text_01C3,

    // 32ec: Begin Option Selection
    BOS,

    // 32f0: Print Text
    TXT,
    (s32)&scenario_text_01F7,

    // 32f8: Jump To @334c
    JMP,
    (s32)&scenario_code_334c,

    // 3300: Print Text
    TXT,
    (s32)&scenario_text_022E,

    // 3308: Jump To @3320
    JMP,
    (s32)&scenario_code_3320,

    // 3310: End Option Selection
    EOS,

    // 3314: Print Text
    TXT,
    (s32)&scenario_text_026B,

    // 331c: End Event
    END,

};

// Message at @3320
s32 scenario_code_3320[] = {

    // 3320: Print Text
    TXT,
    (s32)&scenario_text_028D,

    // 3328: Print Text
    TXT,
    (s32)&scenario_text_02B5,

    // 3330: Print Text
    TXT,
    (s32)&scenario_text_02EB,

    // 3338: Print Text
    TXT,
    (s32)&scenario_text_032B,

    // 3340: Print Text
    TXT,
    (s32)&scenario_text_0364,

    // 3348: End Event
    END,

};

// Message at @334c
s32 scenario_code_334c[] = {

    // 334c: Print Text
    TXT,
    (s32)&scenario_text_0391,

    // 3354: Execute Code: 8003f594 (Load Current Character)
    ESR,
    0x8003f594,

    // 335c: Read from RAM 801c7750 (Scratch)
    LDW,
    0x801c7750,

    // 3364: Skip Next If Equal: 2
    SEQ,
    0x2,

    // 336c: Jump To @3868
    JMP,
    (s32)&scenario_code_3868,

    // 3374: Write to RAM 801c7770 (Unknown)
    STW,
    0x801c7770,

    // 337c: Store Value: 1
    WTS,
    0x1,

    // 3384: Print Text
    TXT,
    (s32)&scenario_text_03B9,

    // 338c: Set Flag 079 (Started Sudden Impact/Super Jump Minigame)
    SFG,
    0x79,

    // 3394: Print Text
    TXT,
    (s32)&scenario_text_03FD,

    // 339c: End Event
    END,

};

// Message at @33a0
s32 scenario_code_33a0[] = {

    // 33a0: Print Text
    TXT,
    (s32)&scenario_text_042A,

    // 33a8: Print Text
    TXT,
    (s32)&scenario_text_0474,

    // 33b0: Print Text
    TXT,
    (s32)&scenario_text_04A5,

    // 33b8: End Event
    END,

};

// Message at @3650
s32 scenario_code_3650[] = {

    // 3650: Write to RAM 801c7758 (Unknown)
    STW,
    0x801c7758,

    // 3658: Store Value: 20
    WTS,
    0x20,

    // 3660: Write to RAM 801c775c (Dialogue Window Y Pos)
    STW,
    0x801c775c,

    // 3668: Store Value: 68
    WTS,
    0x68,

    // 3670: Write to RAM 801c7770 (Unknown)
    STW,
    0x801c7770,

    // 3678: Store Value: 1
    WTS,
    0x1,

    // 3680: Print Text
    TXT,
    (s32)&scenario_text_04D2,

    // 3688: Print Text
    TXT,
    (s32)&scenario_text_04F6,

    // 3690: Print Text
    TXT,
    (s32)&scenario_text_0532,

    // 3698: Print Text
    TXT,
    (s32)&scenario_text_0571,

    // 36a0: Print Text
    TXT,
    (s32)&scenario_text_05BE,

    // 36a8: Print Text
    TXT,
    (s32)&scenario_text_05E6,

    // 36b0: Write to RAM 801c7758 (Unknown)
    STW,
    0x801c7758,

    // 36b8: Store Value: 20
    WTS,
    0x20,

    // 36c0: Write to RAM 801c775c (Dialogue Window Y Pos)
    STW,
    0x801c775c,

    // 36c8: Store Value: 48
    WTS,
    0x48,

    // 36d0: Write to RAM 801c7768 (Dialogue Window Style)
    STW,
    0x801c7768,

    // 36d8: Store Value: 7
    WTS,
    0x7,

    // 36e0: Print Text
    TXT,
    (s32)&scenario_text_0608,

    // 36e8: Write to RAM 801c7770 (Unknown)
    STW,
    0x801c7770,

    // 36f0: Store Value: 1
    WTS,
    0x1,

    // 36f8: Write to RAM 801c7740 (Scratch)
    STW,
    0x801c7740,

    // 3700: Store Value: 14
    WTS,
    0x14,

    // 3708: Execute Code: 8003f608 (Play Sound)
    ESR,
    0x8003f608,

    // 3710: Write to RAM 801c77d8 (Text Speed)
    STW,
    0x801c77d8,

    // 3718: Store Value: 64
    WTS,
    0x64,

    // 3720: Write to RAM 801c7798 (Unknown)
    STW,
    0x801c7798,

    // 3728: Store Value: 1
    WTS,
    0x1,

    // // 3730: Print Text
    // TXT,
    // (s32)&scenario_text_062C,

    // // 3738: Print Text
    // TXT,
    // (s32)&scenario_text_0654,

    ESR,
    (s32)&update_super_jump_text,

    // 3740: Print Text
    TXT,
    (s32)&scenario_text_0688,

    // 3748: Write to RAM 801c7740 (Scratch)
    STW,
    0x801c7740,

    // 3750: Store Value: 96
    WTS,
    0x96,

    // 3758: Execute Code: 8003f460 (Wait For Timer)
    ESR,
    0x8003f460,

    // 3760: Write to RAM 801c7740 (Scratch)
    STW,
    0x801c7740,

    // 3768: Store Value: 23
    WTS,
    0x23,

    // 3770: Execute Code: 8003f608 (Play Sound)
    ESR,
    0x8003f608,

    // 3778: Print Text
    TXT,
    (s32)&scenario_text_06DB,

    // // 3780: Print Text
    // TXT,
    // (s32)&scenario_text_0700,

    // 3788: Write to RAM 801c77d8 (Text Speed)
    STW,
    0x801c77d8,

    // 3790: Store Value: 1
    WTS,
    0x1,

    // 3798: Write to RAM 801c7798 (Unknown)
    STW,
    0x801c7798,

    // 37a0: Store Value: 1
    WTS,
    0x1,

    // // 37a8: Print Text
    // TXT,
    // (s32)&scenario_text_0728,

    // // 37b0: Print Text
    // TXT,
    // (s32)&scenario_text_077C,

    // // 37b8: Print Text
    // TXT,
    // (s32)&scenario_text_07CD,

    // // 37c0: Write to RAM 8015c6f4 (Obtained Super Jump Magic)
    // STW,
    // 0x8015c6f4,

    // // 37c8: Store Value: 1
    // WTS,
    // 0x1,

    // 37d0: Set Flag 020 (Obtained Super Jump Magic)
    SFG,
    0x20,

    // 37d8: Print Text
    TXT,
    (s32)&scenario_text_0801,

    // 37e0: End Event
    END,

};

// Message at @37e4
s32 scenario_code_37e4[] = {

    // 37e4: Write to RAM 801c7758 (Unknown)
    STW,
    0x801c7758,

    // 37ec: Store Value: 20
    WTS,
    0x20,

    // 37f4: Write to RAM 801c775c (Dialogue Window Y Pos)
    STW,
    0x801c775c,

    // 37fc: Store Value: 68
    WTS,
    0x68,

    // 3804: Write to RAM 801c7770 (Unknown)
    STW,
    0x801c7770,

    // 380c: Store Value: 1
    WTS,
    0x1,

    // 3814: Print Text
    TXT,
    (s32)&scenario_text_082E,

    // 381c: Print Text
    TXT,
    (s32)&scenario_text_0852,

    // 3824: Print Text
    TXT,
    (s32)&scenario_text_0884,

    // 382c: Print Text
    TXT,
    (s32)&scenario_text_08BF,

    // 3834: Print Text
    TXT,
    (s32)&scenario_text_08E7,

    // 383c: Print Text
    TXT,
    (s32)&scenario_text_091B,

    // 3844: Print Text
    TXT,
    (s32)&scenario_text_096A,

    // 384c: Print Text
    TXT,
    (s32)&scenario_text_0992,

    // 3854: Unset Flag 062 (Failed Super Jump Training)
    CFG,
    0x62,

    // 385c: Print Text
    TXT,
    (s32)&scenario_text_09C5,

    // 3864: End Event
    END,

};

// Message at @3868
s32 scenario_code_3868[] = {

    // 3868: Write to RAM 801c7770 (Unknown)
    STW,
    0x801c7770,

    // 3870: Store Value: 1
    WTS,
    0x1,

    // 3878: Print Text
    TXT,
    (s32)&scenario_text_09F2,

    // 3880: Print Text
    TXT,
    (s32)&scenario_text_0A22,

    // 3888: Print Text
    TXT,
    (s32)&scenario_text_0A60,

    // 3890: Print Text
    TXT,
    (s32)&scenario_text_0A88,

    // 3898: Print Text
    TXT,
    (s32)&scenario_text_0AC9,

    // 38a0: Print Text
    TXT,
    (s32)&scenario_text_0B16,

    // 38a8: Print Text
    TXT,
    (s32)&scenario_text_0B50,

    // 38b0: End Event
    END,

};

// Function to update the super jump text with AP location data
void update_super_jump_text(void)
{
  update_text_buffer_with_ap_location(scenario_text_0688, 0x020, NULL, NULL);
}
