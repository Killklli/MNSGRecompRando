#include "types.h"
#include "scenario.h"
#include "scenario_replacer.h"

extern void update_sudden_impact_text(void);
// Forward declarations
s32 scenario_code_2410[];
s32 scenario_code_2500[];
s32 scenario_code_252c[];
s32 scenario_code_2558[];
s32 scenario_code_25bc[];
s32 scenario_code_28bc[];
s32 scenario_code_2a78[];

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

// This is the {em-yellow}Muscle Training Gym{/em},{newline}{endline}
static s16 scenario_text_0085[] = {
    CHR_T, CHR_h, CHR_i, CHR_s, PCT_SPACE, CHR_i, CHR_s, PCT_SPACE, CHR_t, CHR_h, 
    CHR_e, PCT_SPACE, CTR_EM_YELLOW, CHR_M, CHR_u, CHR_s, CHR_c, CHR_l, CHR_e, PCT_SPACE, 
    CHR_T, CHR_r, CHR_a, CHR_i, CHR_n, CHR_i, CHR_n, CHR_g, PCT_SPACE, CHR_G, 
    CHR_y, CHR_m, CTR_CLOSE_EM, PCT_COMMA, CTR_NEWLINE, CTR_ENDLINE};

// where you can train to develop{newline}{endline}
static s16 scenario_text_00DB[] = {
    CHR_w, CHR_h, CHR_e, CHR_r, CHR_e, PCT_SPACE, CHR_y, CHR_o, CHR_u, PCT_SPACE, 
    CHR_c, CHR_a, CHR_n, PCT_SPACE, CHR_t, CHR_r, CHR_a, CHR_i, CHR_n, PCT_SPACE, 
    CHR_t, CHR_o, PCT_SPACE, CHR_d, CHR_e, CHR_v, CHR_e, CHR_l, CHR_o, CHR_p, 
    CTR_NEWLINE, CTR_ENDLINE};

// your {em-yellow}muscles{/em}!{button}{endline}
static s16 scenario_text_011F[] = {
    CHR_y, CHR_o, CHR_u, CHR_r, PCT_SPACE, CTR_EM_YELLOW, CHR_m, CHR_u, CHR_s, CHR_c, 
    CHR_l, CHR_e, CHR_s, CTR_CLOSE_EM, PCT_EXCLAMATION, CTR_BUTTON, CTR_ENDLINE};

// {newwindow}{endline}
static s16 scenario_text_0161[] = {
    CTR_NEWWINDOW, CTR_ENDLINE};

// Once you're done training here,{newline}{endline}
static s16 scenario_text_0189[] = {
    CHR_O, CHR_n, CHR_c, CHR_e, PCT_SPACE, CHR_y, CHR_o, CHR_u, PCT_APOSTROPHE, CHR_r, 
    CHR_e, PCT_SPACE, CHR_d, CHR_o, CHR_n, CHR_e, PCT_SPACE, CHR_t, CHR_r, CHR_a, 
    CHR_i, CHR_n, CHR_i, CHR_n, CHR_g, PCT_SPACE, CHR_h, CHR_e, CHR_r, CHR_e, 
    PCT_COMMA, CTR_NEWLINE, CTR_ENDLINE};

// you'd be able to simply push{newline}{endline}
static s16 scenario_text_01CE[] = {
    CHR_y, CHR_o, CHR_u, PCT_APOSTROPHE, CHR_d, PCT_SPACE, CHR_b, CHR_e, PCT_SPACE, CHR_a, 
    CHR_b, CHR_l, CHR_e, PCT_SPACE, CHR_t, CHR_o, PCT_SPACE, CHR_s, CHR_i, CHR_m, 
    CHR_p, CHR_l, CHR_y, PCT_SPACE, CHR_p, CHR_u, CHR_s, CHR_h, CTR_NEWLINE, CTR_ENDLINE};

// the {em-yellow}[Metal Box]{/em}!{button}{endline}
static s16 scenario_text_0210[] = {
    CHR_t, CHR_h, CHR_e, PCT_SPACE, CTR_EM_YELLOW, CHR_M, CHR_e, CHR_t, CHR_a, CHR_l, 
    PCT_SPACE, CHR_B, CHR_o, CHR_x, CTR_CLOSE_EM, PCT_EXCLAMATION, CTR_BUTTON, CTR_ENDLINE};

// {newwindow}{endline}
static s16 scenario_text_0255[] = {
    CTR_NEWWINDOW, CTR_ENDLINE};

// Are you ready to start training?{newline}{endline}
static s16 scenario_text_027D[] = {
    CHR_A, CHR_r, CHR_e, PCT_SPACE, CHR_y, CHR_o, CHR_u, PCT_SPACE, CHR_r, CHR_e, 
    CHR_a, CHR_d, CHR_y, PCT_SPACE, CHR_t, CHR_o, PCT_SPACE, CHR_s, CHR_t, CHR_a, 
    CHR_r, CHR_t, PCT_SPACE, CHR_t, CHR_r, CHR_a, CHR_i, CHR_n, CHR_i, CHR_n, 
    CHR_g, PCT_QUESTION, CTR_NEWLINE, CTR_ENDLINE};

//  {newline}{endline}
static s16 scenario_text_02C3[] = {
    PCT_SPACE, CTR_NEWLINE, CTR_ENDLINE};

//   {em-yellow}Let's get started!{newline}{endline}
static s16 scenario_text_02EA[] = {
    PCT_SPACE, PCT_SPACE, CTR_EM_YELLOW, CHR_L, CHR_e, CHR_t, PCT_APOSTROPHE, CHR_s, PCT_SPACE, CHR_g, 
    CHR_e, CHR_t, PCT_SPACE, CHR_s, CHR_t, CHR_a, CHR_r, CHR_t, CHR_e, CHR_d, 
    PCT_EXCLAMATION, CTR_NEWLINE, CTR_ENDLINE};

//   {em-yellow}I'd rather not.{newline}{endline}
static s16 scenario_text_032F[] = {
    PCT_SPACE, PCT_SPACE, CTR_EM_YELLOW, CHR_I, PCT_APOSTROPHE, CHR_d, PCT_SPACE, CHR_r, CHR_a, CHR_t, 
    CHR_h, CHR_e, CHR_r, PCT_SPACE, CHR_n, CHR_o, CHR_t, PCT_PERIOD, CTR_NEWLINE, CTR_ENDLINE};

// {end}{endline}
static s16 scenario_text_0371[] = {
    CTR_END, CTR_ENDLINE};

// {newwindow}{endline}
static s16 scenario_text_0393[] = {
    CTR_NEWWINDOW, CTR_ENDLINE};

// {/em}Well that's a surprise.{newline}{endline}
static s16 scenario_text_03BB[] = {
    CTR_CLOSE_EM, CHR_W, CHR_e, CHR_l, CHR_l, PCT_SPACE, CHR_t, CHR_h, CHR_a, CHR_t, 
    PCT_APOSTROPHE, CHR_s, PCT_SPACE, CHR_a, PCT_SPACE, CHR_s, CHR_u, CHR_r, CHR_p, CHR_r, 
    CHR_i, CHR_s, CHR_e, PCT_PERIOD, CTR_NEWLINE, CTR_ENDLINE};

// It's your chance to really develop{newline}{endline}
static s16 scenario_text_03FD[] = {
    CHR_I, CHR_t, PCT_APOSTROPHE, CHR_s, PCT_SPACE, CHR_y, CHR_o, CHR_u, CHR_r, PCT_SPACE, 
    CHR_c, CHR_h, CHR_a, CHR_n, CHR_c, CHR_e, PCT_SPACE, CHR_t, CHR_o, PCT_SPACE, 
    CHR_r, CHR_e, CHR_a, CHR_l, CHR_l, CHR_y, PCT_SPACE, CHR_d, CHR_e, CHR_v, 
    CHR_e, CHR_l, CHR_o, CHR_p, CTR_NEWLINE, CTR_ENDLINE};

// your from into a {em-yellow}body of steel{/em}.{endline}
static s16 scenario_text_0445[] = {
    CHR_y, CHR_o, CHR_u, CHR_r, PCT_SPACE, CHR_f, CHR_r, CHR_o, CHR_m, PCT_SPACE, 
    CHR_i, CHR_n, CHR_t, CHR_o, PCT_SPACE, CHR_a, PCT_SPACE, CTR_EM_YELLOW, CHR_b, CHR_o, 
    CHR_d, CHR_y, PCT_SPACE, CHR_o, CHR_f, PCT_SPACE, CHR_s, CHR_t, CHR_e, CHR_e, 
    CHR_l, CTR_CLOSE_EM, PCT_PERIOD, CTR_ENDLINE};

// {waitinput}{end}{endline}
static s16 scenario_text_0491[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE};

// {newwindow}{endline}
static s16 scenario_text_04BE[] = {
    CTR_NEWWINDOW, CTR_ENDLINE};

// {/em}Well, you need a head full of{newline}{endline}
static s16 scenario_text_04E6[] = {
    CTR_CLOSE_EM, CHR_W, CHR_e, CHR_l, CHR_l, PCT_COMMA, PCT_SPACE, CHR_y, CHR_o, CHR_u, 
    PCT_SPACE, CHR_n, CHR_e, CHR_e, CHR_d, PCT_SPACE, CHR_a, PCT_SPACE, CHR_h, CHR_e, 
    CHR_a, CHR_d, PCT_SPACE, CHR_f, CHR_u, CHR_l, CHR_l, PCT_SPACE, CHR_o, CHR_f, 
    CTR_NEWLINE, CTR_ENDLINE};

// {em-yellow}thorns{/em} and a mouth shaped like{newline}{endline}
static s16 scenario_text_052E[] = {
    CTR_EM_YELLOW, CHR_t, CHR_h, CHR_o, CHR_r, CHR_n, CHR_s, CTR_CLOSE_EM, PCT_SPACE, CHR_a, 
    CHR_n, CHR_d, PCT_SPACE, CHR_a, PCT_SPACE, CHR_m, CHR_o, CHR_u, CHR_t, CHR_h, 
    PCT_SPACE, CHR_s, CHR_h, CHR_a, CHR_p, CHR_e, CHR_d, PCT_SPACE, CHR_l, CHR_i, 
    CHR_k, CHR_e, CTR_NEWLINE, CTR_ENDLINE};

// an {em-yellow}upside-down{/em} "{em-yellow}V{/em}".{endline}
static s16 scenario_text_0582[] = {
    CHR_a, CHR_n, PCT_SPACE, CTR_EM_YELLOW, CHR_u, CHR_p, CHR_s, CHR_i, CHR_d, CHR_e, 
    PCT_DASH, CHR_d, CHR_o, CHR_w, CHR_n, CTR_CLOSE_EM, PCT_SPACE, PCT_QUOTE, CTR_EM_YELLOW, 
    CHR_V, 
    CTR_CLOSE_EM, PCT_QUOTE, PCT_PERIOD, CTR_ENDLINE};

// {waitinput}{end}{endline}
static s16 scenario_text_05D2[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE};

// {newwindow}{endline}
static s16 scenario_text_05FF[] = {
    CTR_NEWWINDOW, CTR_ENDLINE};

// {/em}All right!{newline}{endline}
static s16 scenario_text_0627[] = {
    CTR_CLOSE_EM, CHR_A, CHR_l, CHR_l, PCT_SPACE, CHR_r, CHR_i, CHR_g, CHR_h, CHR_t, 
    PCT_EXCLAMATION, CTR_NEWLINE, CTR_ENDLINE};

// Let me show you to{newline}{endline}
static s16 scenario_text_065C[] = {
    CHR_L, CHR_e, CHR_t, PCT_SPACE, CHR_m, CHR_e, PCT_SPACE, CHR_s, CHR_h, CHR_o, 
    CHR_w, PCT_SPACE, CHR_y, CHR_o, CHR_u, PCT_SPACE, CHR_t, CHR_o, CTR_NEWLINE, CTR_ENDLINE};

// the Training Gym!{endline}
static s16 scenario_text_0694[] = {
    CHR_t, CHR_h, CHR_e, PCT_SPACE, CHR_T, CHR_r, CHR_a, CHR_i, CHR_n, CHR_i, 
    CHR_n, CHR_g, PCT_SPACE, CHR_G, CHR_y, CHR_m, PCT_EXCLAMATION, CTR_ENDLINE};

// {waitinput}{end}{endline}
static s16 scenario_text_06C2[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE};

// Just think that you're developing{newline}{endline}
static s16 scenario_text_06EF[] = {
    CHR_J, CHR_u, CHR_s, CHR_t, PCT_SPACE, CHR_t, CHR_h, CHR_i, CHR_n, CHR_k, 
    PCT_SPACE, CHR_t, CHR_h, CHR_a, CHR_t, PCT_SPACE, CHR_y, CHR_o, CHR_u, PCT_APOSTROPHE, 
    CHR_r, CHR_e, PCT_SPACE, CHR_d, CHR_e, CHR_v, CHR_e, CHR_l, CHR_o, CHR_p, 
    CHR_i, CHR_n, CHR_g, CTR_NEWLINE, CTR_ENDLINE};

// your {em-yellow}muscles{/em} to save {em-yellow}Japan{/em}!{endline}
static s16 scenario_text_0736[] = {
    CHR_y, CHR_o, CHR_u, CHR_r, PCT_SPACE, CTR_EM_YELLOW, CHR_m, CHR_u, CHR_s, CHR_c, 
    CHR_l, CHR_e, CHR_s, CTR_CLOSE_EM, PCT_SPACE, CHR_t, CHR_o, PCT_SPACE, CHR_s, CHR_a, 
    CHR_v, CHR_e, PCT_SPACE, CTR_EM_YELLOW, CHR_J, CHR_a, CHR_p, CHR_a, CHR_n, CTR_CLOSE_EM, 
    PCT_EXCLAMATION, CTR_ENDLINE};

// {waitinput}{end}{endline}
static s16 scenario_text_078E[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE};

// Way to go!{newline}{endline}
static s16 scenario_text_07BB[] = {
    CHR_W, CHR_a, CHR_y, PCT_SPACE, CHR_t, CHR_o, PCT_SPACE, CHR_g, CHR_o, PCT_EXCLAMATION, CTR_NEWLINE, CTR_ENDLINE};

// Now, you can call yourself{newline}{endline}
static s16 scenario_text_07EB[] = {
    CHR_N, CHR_o, CHR_w, PCT_COMMA, PCT_SPACE, CHR_y, CHR_o, CHR_u, PCT_SPACE, CHR_c, 
    CHR_a, CHR_n, PCT_SPACE, CHR_c, CHR_a, CHR_l, CHR_l, PCT_SPACE, CHR_y, CHR_o, 
    CHR_u, CHR_r, CHR_s, CHR_e, CHR_l, CHR_f, CTR_NEWLINE, CTR_ENDLINE};

// a {em-yellow}Muscle Man{/em}!{button}{endline}
static s16 scenario_text_082B[] = {
    CHR_a, PCT_SPACE, CTR_EM_YELLOW, CHR_M, CHR_u, CHR_s, CHR_c, CHR_l, CHR_e, PCT_SPACE, 
    CHR_M, CHR_a, CHR_n, CTR_CLOSE_EM, PCT_EXCLAMATION, CTR_BUTTON, CTR_ENDLINE};

// {newwindow}{endline}
static s16 scenario_text_086D[] = {
    CTR_NEWWINDOW, CTR_ENDLINE};

// {end}{endline}
static s16 scenario_text_0895[] = {
    CTR_END, CTR_ENDLINE};

// {begin}{endline}
static s16 scenario_text_08B7[] = {
    CTR_BEGIN, CTR_ENDLINE};

//  {newline}{endline}
static s16 scenario_text_08DB[] = {
    PCT_SPACE, CTR_NEWLINE, CTR_ENDLINE};

// Goemon obtains{newline}{endline}
static s16 scenario_text_0902[] = {
    CHR_G, CHR_o, CHR_e, CHR_m, CHR_o, CHR_n, PCT_SPACE, CHR_o, CHR_b, CHR_t, 
    CHR_a, CHR_i, CHR_n, CHR_s, CTR_NEWLINE, CTR_ENDLINE};

// the [{em-yellow}Sudden Impact{/em}] magic powers!{newline}{endline}
static s16 scenario_text_0936[] = {
    CHR_t, CHR_h, CHR_e, PCT_SPACE, CTR_EM_YELLOW, CHR_S, CHR_u, CHR_d, CHR_d, CHR_e, 
    CHR_n, PCT_SPACE, CHR_I, CHR_m, CHR_p, CHR_a, CHR_c, CHR_t, CTR_CLOSE_EM, PCT_SPACE, 
    CHR_m, CHR_a, CHR_g, CHR_i, CHR_c, PCT_SPACE, CHR_p, CHR_o, CHR_w, CHR_e, 
    CHR_r, CHR_s, PCT_EXCLAMATION, CTR_NEWLINE, CTR_ENDLINE};

// {button}{endline}
static s16 scenario_text_098D[] = {
    CTR_BUTTON, CTR_ENDLINE};

// {newwindow}{endline}
static s16 scenario_text_09B2[] = {
    CTR_NEWWINDOW, CTR_ENDLINE};

// By consuming some {em-yellow}money{/em},{newline}{endline}
static s16 scenario_text_09DA[] = {
    CHR_B, CHR_y, PCT_SPACE, CHR_c, CHR_o, CHR_n, CHR_s, CHR_u, CHR_m, CHR_i, 
    CHR_n, CHR_g, PCT_SPACE, CHR_s, CHR_o, CHR_m, CHR_e, PCT_SPACE, CTR_EM_YELLOW, CHR_m, 
    CHR_o, CHR_n, CHR_e, CHR_y, CTR_CLOSE_EM, PCT_COMMA, CTR_NEWLINE, CTR_ENDLINE};

// you will be able to move{newline}{endline}
static s16 scenario_text_0A28[] = {
    CHR_y, CHR_o, CHR_u, PCT_SPACE, CHR_w, CHR_i, CHR_l, CHR_l, PCT_SPACE, CHR_b, 
    CHR_e, PCT_SPACE, CHR_a, CHR_b, CHR_l, CHR_e, PCT_SPACE, CHR_t, CHR_o, PCT_SPACE, 
    CHR_m, CHR_o, CHR_v, CHR_e, CTR_NEWLINE, CTR_ENDLINE};

// {em-yellow}heavy thing{/em} for a specific period{newline}{endline}
static s16 scenario_text_0A66[] = {
    CTR_EM_YELLOW, CHR_h, CHR_e, CHR_a, CHR_v, CHR_y, PCT_SPACE, CHR_t, CHR_h, CHR_i, 
    CHR_n, CHR_g, CTR_CLOSE_EM, PCT_SPACE, CHR_f, CHR_o, CHR_r, PCT_SPACE, CHR_a, PCT_SPACE, 
    CHR_s, CHR_p, CHR_e, CHR_c, CHR_i, CHR_f, CHR_i, CHR_c, PCT_SPACE, CHR_p, 
    CHR_e, CHR_r, CHR_i, CHR_o, CHR_d, CTR_NEWLINE, CTR_ENDLINE};

// of time!{button}{endline}
static s16 scenario_text_0ABD[] = {
    CHR_o, CHR_f, PCT_SPACE, CHR_t, CHR_i, CHR_m, CHR_e, PCT_EXCLAMATION, CTR_BUTTON, CTR_ENDLINE};

// {newwindow}{endline}
static s16 scenario_text_0AEA[] = {
    CTR_NEWWINDOW, CTR_ENDLINE};

// Furthermore,{newline}{endline}
static s16 scenario_text_0B12[] = {
    CHR_F, CHR_u, CHR_r, CHR_t, CHR_h, CHR_e, CHR_r, CHR_m, CHR_o, CHR_r, 
    CHR_e, PCT_COMMA, CTR_NEWLINE, CTR_ENDLINE};

// while the magic power is{newline}{endline}
static s16 scenario_text_0B44[] = {
    CHR_w, CHR_h, CHR_i, CHR_l, CHR_e, PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE, 
    CHR_m, CHR_a, CHR_g, CHR_i, CHR_c, PCT_SPACE, CHR_p, CHR_o, CHR_w, CHR_e, 
    CHR_r, PCT_SPACE, CHR_i, CHR_s, CTR_NEWLINE, CTR_ENDLINE};

// in effect, you will have {em-yellow}double{/em}{newline}{endline}
static s16 scenario_text_0B82[] = {
    CHR_i, CHR_n, PCT_SPACE, CHR_e, CHR_f, CHR_f, CHR_e, CHR_c, CHR_t, PCT_COMMA, 
    PCT_SPACE, CHR_y, CHR_o, CHR_u, PCT_SPACE, CHR_w, CHR_i, CHR_l, CHR_l, PCT_SPACE, 
    CHR_h, CHR_a, CHR_v, CHR_e, PCT_SPACE, CTR_EM_YELLOW, CHR_d, CHR_o, CHR_u, CHR_b, 
    CHR_l, CHR_e, CTR_CLOSE_EM, CTR_NEWLINE, CTR_ENDLINE};

// the {em-yellow}attacking power{/em}!{button}{endline}
static s16 scenario_text_0BD7[] = {
    CHR_t, CHR_h, CHR_e, PCT_SPACE, CTR_EM_YELLOW, CHR_a, CHR_t, CHR_t, CHR_a, CHR_c, 
    CHR_k, CHR_i, CHR_n, CHR_g, PCT_SPACE, CHR_p, CHR_o, CHR_w, CHR_e, CHR_r, 
    CTR_CLOSE_EM, PCT_EXCLAMATION, CTR_BUTTON, CTR_ENDLINE};

// {newwindow}{endline}
static s16 scenario_text_0C20[] = {
    CTR_NEWWINDOW, CTR_ENDLINE};

//   {newline}{endline}
static s16 scenario_text_0C48[] = {
    PCT_SPACE, PCT_SPACE, CTR_NEWLINE, CTR_ENDLINE};

// (However, be careful, as {em-yellow}damage{/em}{newline}{endline}
static s16 scenario_text_0C70[] = {
    PCT_LPAREN, CHR_H, CHR_o, CHR_w, CHR_e, CHR_v, CHR_e, CHR_r, PCT_COMMA, PCT_SPACE, 
    CHR_b, CHR_e, PCT_SPACE, CHR_c, CHR_a, CHR_r, CHR_e, CHR_f, CHR_u, CHR_l, 
    PCT_COMMA, PCT_SPACE, CHR_a, CHR_s, PCT_SPACE, CTR_EM_YELLOW, CHR_d, CHR_a, CHR_m, CHR_a, 
    CHR_g, CHR_e, CTR_CLOSE_EM, CTR_NEWLINE, CTR_ENDLINE};

//  from the enemy will also {em-yellow}double{/em}){endline}
static s16 scenario_text_0CC5[] = {
    PCT_SPACE, CHR_f, CHR_r, CHR_o, CHR_m, PCT_SPACE, CHR_t, CHR_h, CHR_e, PCT_SPACE, 
    CHR_e, CHR_n, CHR_e, CHR_m, CHR_y, PCT_SPACE, CHR_w, CHR_i, CHR_l, CHR_l, 
    PCT_SPACE, CHR_a, CHR_l, CHR_s, CHR_o, PCT_SPACE, CTR_EM_YELLOW, CHR_d, CHR_o, CHR_u, 
    CHR_b, CHR_l, CHR_e, CTR_CLOSE_EM, PCT_RPAREN, CTR_ENDLINE};

// {waitinput}{end}{endline}
static s16 scenario_text_0D13[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE};

// {begin}{endline}
static s16 scenario_text_0D40[] = {
    CTR_BEGIN, CTR_ENDLINE};

// That was too bad,{newline}{endline}
static s16 scenario_text_0D64[] = {
    CHR_T, CHR_h, CHR_a, CHR_t, PCT_SPACE, CHR_w, CHR_a, CHR_s, PCT_SPACE, CHR_t, 
    CHR_o, CHR_o, PCT_SPACE, CHR_b, CHR_a, CHR_d, PCT_COMMA, CTR_NEWLINE, CTR_ENDLINE};

// give it another try.{endline}
static s16 scenario_text_0D9B[] = {
    CHR_g, CHR_i, CHR_v, CHR_e, PCT_SPACE, CHR_i, CHR_t, PCT_SPACE, CHR_a, CHR_n, 
    CHR_o, CHR_t, CHR_h, CHR_e, CHR_r, PCT_SPACE, CHR_t, CHR_r, CHR_y, PCT_PERIOD, 
    CTR_ENDLINE};

// {waitinput}{end}{endline}
static s16 scenario_text_0DCC[] = {
    CTR_WAITINPUT, CTR_END, CTR_ENDLINE};

// ==================== SCENARIO CODE ====================

// Message at @2410
s32 scenario_code_2410[] = {

    // 2410: Write to RAM 801c7758 (Unknown)
    STW,
    0x801c7758,

    // 2418: Store Value: 20
    WTS,
    0x20,

    // 2420: Write to RAM 801c775c (Dialogue Window Y Pos)
    STW,
    0x801c775c,

    // 2428: Store Value: 68
    WTS,
    0x68,

    // 2430: Print Text
    TXT,
    (s32)&scenario_text_0000,

    // 2438: If Flag 01c (Obtained Sudden Impact Magic), Jump To @25bc
    JFS,
    0x1c,
    (s32)&scenario_code_25bc,

    // 2444: If Flag 05f (Passed Sudden Impact Training), Jump To @28bc
    JFS,
    0x5f,
    (s32)&scenario_code_28bc,

    // 2450: If Flag 060 (Failed Sudden Impact Training), Jump To @2a78
    JFS,
    0x60,
    (s32)&scenario_code_2a78,

    // 245c: Print Text
    TXT,
    (s32)&scenario_text_0024,

    // 2464: Print Text
    TXT,
    (s32)&scenario_text_005D,

    // 246c: Print Text
    TXT,
    (s32)&scenario_text_0085,

    // 2474: Print Text
    TXT,
    (s32)&scenario_text_00DB,

    // 247c: Print Text
    TXT,
    (s32)&scenario_text_011F,

    // 2484: Print Text
    TXT,
    (s32)&scenario_text_0161,

    // 248c: Print Text
    TXT,
    (s32)&scenario_text_0189,

    // 2494: Print Text
    TXT,
    (s32)&scenario_text_01CE,

    // 249c: Print Text
    TXT,
    (s32)&scenario_text_0210,

    // 24a4: Print Text
    TXT,
    (s32)&scenario_text_0255,

    // 24ac: Write to RAM 801c7770 (Unknown)
    STW,
    0x801c7770,

    // 24b4: Store Value: 1
    WTS,
    0x1,

    // 24bc: Print Text
    TXT,
    (s32)&scenario_text_027D,

    // 24c4: Print Text
    TXT,
    (s32)&scenario_text_02C3,

    // 24cc: Begin Option Selection
    BOS,

    // 24d0: Print Text
    TXT,
    (s32)&scenario_text_02EA,

    // 24d8: Jump To @2558
    JMP,
    (s32)&scenario_code_2558,

    // 24e0: Print Text
    TXT,
    (s32)&scenario_text_032F,

    // 24e8: Jump To @2500
    JMP,
    (s32)&scenario_code_2500,

    // 24f0: End Option Selection
    EOS,

    // 24f4: Print Text
    TXT,
    (s32)&scenario_text_0371,

    // 24fc: End Event
    END,

};

// Message at @2500
s32 scenario_code_2500[] = {

    // 2500: Print Text
    TXT,
    (s32)&scenario_text_0393,

    // 2508: Print Text
    TXT,
    (s32)&scenario_text_03BB,

    // 2510: Print Text
    TXT,
    (s32)&scenario_text_03FD,

    // 2518: Print Text
    TXT,
    (s32)&scenario_text_0445,

    // 2520: Print Text
    TXT,
    (s32)&scenario_text_0491,

    // 2528: End Event
    END,

};

// Message at @252c
s32 scenario_code_252c[] = {

    // 252c: Print Text
    TXT,
    (s32)&scenario_text_04BE,

    // 2534: Print Text
    TXT,
    (s32)&scenario_text_04E6,

    // 253c: Print Text
    TXT,
    (s32)&scenario_text_052E,

    // 2544: Print Text
    TXT,
    (s32)&scenario_text_0582,

    // 254c: Print Text
    TXT,
    (s32)&scenario_text_05D2,

    // 2554: End Event
    END,

};

// Message at @2558
s32 scenario_code_2558[] = {

    // 2558: Print Text
    TXT,
    (s32)&scenario_text_05FF,

    // 2560: Execute Code: 8003f594 (Load Current Character)
    ESR,
    0x8003f594,

    // 2568: Read from RAM 801c7750 (Scratch)
    LDW,
    0x801c7750,

    // 2570: Skip Next If Equal: 0
    SEQ,
    0x0,

    // 2578: Jump To @252c
    JMP,
    (s32)&scenario_code_252c,

    // 2580: Write to RAM 801c7770 (Unknown)
    STW,
    0x801c7770,

    // 2588: Store Value: 1
    WTS,
    0x1,

    // 2590: Print Text
    TXT,
    (s32)&scenario_text_0627,

    // 2598: Print Text
    TXT,
    (s32)&scenario_text_065C,

    // 25a0: Print Text
    TXT,
    (s32)&scenario_text_0694,

    // 25a8: Set Flag 079 (Started Sudden Impact/Super Jump Minigame)
    SFG,
    0x79,

    // 25b0: Print Text
    TXT,
    (s32)&scenario_text_06C2,

    // 25b8: End Event
    END,

};

// Message at @25bc
s32 scenario_code_25bc[] = {

    // 25bc: Print Text
    TXT,
    (s32)&scenario_text_06EF,

    // 25c4: Print Text
    TXT,
    (s32)&scenario_text_0736,

    // 25cc: Print Text
    TXT,
    (s32)&scenario_text_078E,

    // 25d4: End Event
    END,

};

// Message at @28bc
s32 scenario_code_28bc[] = {

    // 28bc: Write to RAM 801c7770 (Unknown)
    STW,
    0x801c7770,

    // 28c4: Store Value: 1
    WTS,
    0x1,

    // 28cc: Print Text
    TXT,
    (s32)&scenario_text_07BB,

    // 28d4: Print Text
    TXT,
    (s32)&scenario_text_07EB,

    // 28dc: Print Text
    TXT,
    (s32)&scenario_text_082B,

    // 28e4: Print Text
    TXT,
    (s32)&scenario_text_086D,

    // 28ec: Print Text
    TXT,
    (s32)&scenario_text_0895,

    // 28f4: Write to RAM 801c7758 (Unknown)
    STW,
    0x801c7758,

    // 28fc: Store Value: 20
    WTS,
    0x20,

    // 2904: Write to RAM 801c775c (Dialogue Window Y Pos)
    STW,
    0x801c775c,

    // 290c: Store Value: 48
    WTS,
    0x48,

    // 2914: Write to RAM 801c7768 (Dialogue Window Style)
    STW,
    0x801c7768,

    // 291c: Store Value: 7
    WTS,
    0x7,

    // 2924: Print Text
    TXT,
    (s32)&scenario_text_08B7,

    // 292c: Write to RAM 801c7770 (Unknown)
    STW,
    0x801c7770,

    // 2934: Store Value: 1
    WTS,
    0x1,

    // 293c: Write to RAM 801c7740 (Scratch)
    STW,
    0x801c7740,

    // 2944: Store Value: 14
    WTS,
    0x14,

    // 294c: Execute Code: 8003f608 (Play Sound)
    ESR,
    0x8003f608,

    // 2954: Write to RAM 801c77d8 (Text Speed)
    STW,
    0x801c77d8,

    // 295c: Store Value: 64
    WTS,
    0x64,

    // 2964: Write to RAM 801c7798 (Unknown)
    STW,
    0x801c7798,

    // 296c: Store Value: 1
    WTS,
    0x1,

    // // 2974: Print Text
    // TXT,
    // (s32)&scenario_text_08DB,

    // // 297c: Print Text
    // TXT,
    // (s32)&scenario_text_0902,

    ESR,
    (s32)&update_sudden_impact_text,

    // 2984: Print Text
    TXT,
    (s32)&scenario_text_0936,

    // 298c: Write to RAM 801c7740 (Scratch)
    STW,
    0x801c7740,

    // 2994: Store Value: 96
    WTS,
    0x96,

    // 299c: Execute Code: 8003f460 (Wait For Timer)
    ESR,
    0x8003f460,

    // 29a4: Write to RAM 801c7740 (Scratch)
    STW,
    0x801c7740,

    // 29ac: Store Value: 23
    WTS,
    0x23,

    // 29b4: Execute Code: 8003f608 (Play Sound)
    ESR,
    0x8003f608,

    // 29bc: Print Text
    TXT,
    (s32)&scenario_text_098D,

    // // 29c4: Print Text
    // TXT,
    // (s32)&scenario_text_09B2,

    // 29cc: Write to RAM 801c77d8 (Text Speed)
    STW,
    0x801c77d8,

    // 29d4: Store Value: 1
    WTS,
    0x1,

    // 29dc: Write to RAM 801c7798 (Unknown)
    STW,
    0x801c7798,

    // 29e4: Store Value: 1
    WTS,
    0x1,

    // // 29ec: Print Text
    // TXT,
    // (s32)&scenario_text_09DA,

    // // 29f4: Print Text
    // TXT,
    // (s32)&scenario_text_0A28,

    // // 29fc: Print Text
    // TXT,
    // (s32)&scenario_text_0A66,

    // // 2a04: Print Text
    // TXT,
    // (s32)&scenario_text_0ABD,

    // // 2a0c: Print Text
    // TXT,
    // (s32)&scenario_text_0AEA,

    // // 2a14: Print Text
    // TXT,
    // (s32)&scenario_text_0B12,

    // // 2a1c: Print Text
    // TXT,
    // (s32)&scenario_text_0B44,

    // // 2a24: Print Text
    // TXT,
    // (s32)&scenario_text_0B82,

    // // 2a2c: Print Text
    // TXT,
    // (s32)&scenario_text_0BD7,

    // // 2a34: Print Text
    // TXT,
    // (s32)&scenario_text_0C20,

    // // 2a3c: Print Text
    // TXT,
    // (s32)&scenario_text_0C48,

    // // 2a44: Print Text
    // TXT,
    // (s32)&scenario_text_0C70,

    // // 2a4c: Print Text
    // TXT,
    // (s32)&scenario_text_0CC5,

    // // 2a54: Write to RAM 8015c6ec (Obtained Sudden Impact Magic)
    // STW,
    // 0x8015c6ec,

    // // 2a5c: Store Value: 1
    // WTS,
    // 0x1,

    // 2a64: Set Flag 01c (Obtained Sudden Impact Magic)
    SFG,
    0x1c,

    // 2a6c: Print Text
    TXT,
    (s32)&scenario_text_0D13,

    // 2a74: End Event
    END,

};

// Message at @2a78
s32 scenario_code_2a78[] = {

    // 2a78: Write to RAM 801c7758 (Unknown)
    STW,
    0x801c7758,

    // 2a80: Store Value: 20
    WTS,
    0x20,

    // 2a88: Write to RAM 801c775c (Dialogue Window Y Pos)
    STW,
    0x801c775c,

    // 2a90: Store Value: 68
    WTS,
    0x68,

    // 2a98: Write to RAM 801c7770 (Unknown)
    STW,
    0x801c7770,

    // 2aa0: Store Value: 1
    WTS,
    0x1,

    // 2aa8: Print Text
    TXT,
    (s32)&scenario_text_0D40,

    // 2ab0: Print Text
    TXT,
    (s32)&scenario_text_0D64,

    // 2ab8: Print Text
    TXT,
    (s32)&scenario_text_0D9B,

    // 2ac0: Unset Flag 060 (Failed Sudden Impact Training)
    CFG,
    0x60,

    // 2ac8: Print Text
    TXT,
    (s32)&scenario_text_0DCC,

    // 2ad0: End Event
    END,

};

// Function to update the sudden impact text with AP location data
void update_sudden_impact_text(void)
{
  update_text_buffer_with_ap_location(scenario_text_0936, 0x01C, NULL, NULL);
}
