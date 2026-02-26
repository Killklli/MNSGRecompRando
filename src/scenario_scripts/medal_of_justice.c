#include "types.h"
#include "scenario.h"
#include "scenario_replacer.h"

// Function declarations
void update_medal_of_justice_text(void);



// Address: @36e0

// {begin}{endline}
static s16 scenario_text_0000[] = {CTR_BEGIN, CTR_ENDLINE};

//  {newline}{endline}
static s16 scenario_text_0014[] = {PCT_SPACE, CTR_NEWLINE, CTR_ENDLINE};

//   Goemon receives{newline}{endline}
static s16 scenario_text_002B[] = {
    PCT_SPACE, PCT_SPACE, CHR_G, CHR_o, CHR_e, CHR_m, CHR_o,
    CHR_n, PCT_SPACE, CHR_r, CHR_e, CHR_c, CHR_e, CHR_i,
    CHR_v, CHR_e, CHR_s, CTR_NEWLINE, CTR_ENDLINE};

//      the {em-yellow}Medal of Flames{/em}!{endline}
static s16 scenario_text_0060[256] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE,
    CHR_t, CHR_h, CHR_e, PCT_SPACE, CTR_EM_YELLOW,
    PCT_LBRACKET, CHR_M, CHR_e, CHR_d, CHR_a,
    CHR_l, PCT_SPACE, CHR_o, CHR_f, PCT_SPACE,
    CHR_F, CHR_l, CHR_a, CHR_m, CHR_e,
    CHR_s, PCT_RBRACKET, CTR_CLOSE_EM, PCT_EXCLAMATION, CTR_ENDLINE};

// {button}{endline}
static s16 scenario_text_00A7[] = {CTR_BUTTON, CTR_ENDLINE};

// {newwindow}{endline}
static s16 scenario_text_00B9[] = {CTR_NEWWINDOW, CTR_ENDLINE};

//   {newline}{endline}
static s16 scenario_text_00D1[] = {PCT_SPACE, PCT_SPACE, CTR_NEWLINE,
                                   CTR_ENDLINE};

// By continuously holding down{newline}{endline}
static s16 scenario_text_00E8[] = {
    CHR_B, CHR_y, PCT_SPACE, CHR_c, CHR_o, CHR_n, CHR_t, CHR_i,
    CHR_n, CHR_u, CHR_o, CHR_u, CHR_s, CHR_l, CHR_y, PCT_SPACE,
    CHR_h, CHR_o, CHR_l, CHR_d, CHR_i, CHR_n, CHR_g, PCT_SPACE,
    CHR_d, CHR_o, CHR_w, CHR_n, CTR_NEWLINE, CTR_ENDLINE};

// the {em-yellow}B Button{/em} and then letting go...{button}{endline}
static s16 scenario_text_0124[] = {
    CHR_t, CHR_h, CHR_e, PCT_SPACE, CTR_EM_YELLOW, CHR_B,
    PCT_SPACE, CHR_B, CHR_u, CHR_t, CHR_t, CHR_o,
    CHR_n, CTR_CLOSE_EM, PCT_SPACE, CHR_a, CHR_n, CHR_d,
    PCT_SPACE, CHR_t, CHR_h, CHR_e, CHR_n, PCT_SPACE,
    CHR_l, CHR_e, CHR_t, CHR_t, CHR_i, CHR_n,
    CHR_g, PCT_SPACE, CHR_g, CHR_o, PCT_PERIOD, PCT_PERIOD,
    PCT_PERIOD, CTR_BUTTON, CTR_ENDLINE};

// a powerful {em-yellow}medal{/em} surrounded by{newline}{endline}
static s16 scenario_text_0174[] = {
    CHR_a, PCT_SPACE, CHR_p, CHR_o, CHR_w, CHR_e, CHR_r,
    CHR_f, CHR_u, CHR_l, PCT_SPACE, CTR_EM_YELLOW, CHR_m, CHR_e,
    CHR_d, CHR_a, CHR_l, CTR_CLOSE_EM, PCT_SPACE, CHR_s, CHR_u,
    CHR_r, CHR_r, CHR_o, CHR_u, CHR_n, CHR_d, CHR_e,
    CHR_d, PCT_SPACE, CHR_b, CHR_y, CTR_NEWLINE, CTR_ENDLINE};

// {em-yellow}flames{/em} will be thrown!{newline}{endline}
static s16 scenario_text_01B8[] = {
    CTR_EM_YELLOW, CHR_f, CHR_l, CHR_a, CHR_m, CHR_e,
    CHR_s, CTR_CLOSE_EM, PCT_SPACE, CHR_w, CHR_i, CHR_l,
    CHR_l, PCT_SPACE, CHR_b, CHR_e, PCT_SPACE, CHR_t,
    CHR_h, CHR_r, CHR_o, CHR_w, CHR_n, PCT_EXCLAMATION,
    CTR_NEWLINE, CTR_ENDLINE};

// (The {em-yellow}torch{/em} can also be lit{newline}{endline}
static s16 scenario_text_01EC[] = {
    PCT_LPAREN, CHR_T, CHR_h, CHR_e, PCT_SPACE, CTR_EM_YELLOW,
    CHR_t, CHR_o, CHR_r, CHR_c, CHR_h, CTR_CLOSE_EM,
    PCT_SPACE, CHR_c, CHR_a, CHR_n, PCT_SPACE, CHR_a,
    CHR_l, CHR_s, CHR_o, PCT_SPACE, CHR_b, CHR_e,
    PCT_SPACE, CHR_l, CHR_i, CHR_t, CTR_NEWLINE, CTR_ENDLINE};

//             by using this){endline}
static s16 scenario_text_022C[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE,
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE,
    CHR_b, CHR_y, PCT_SPACE, CHR_u, CHR_s, CHR_i,
    CHR_n, CHR_g, PCT_SPACE, CHR_t, CHR_h, CHR_i,
    CHR_s, PCT_RPAREN, CTR_ENDLINE};

// {waitinput}{end}{endline}
static s16 scenario_text_0260[] = {CTR_WAITINPUT, CTR_END, CTR_ENDLINE};

s32 scenario_code_message_082_36e0[] = {

    // Address: @36e0

    // 36e0: Write to RAM 801c7758 (Unknown)
    STW,
    (s32)&D_801C7758_1C8358,

    // 36e8: Store Value: 20
    WTS,
    0x20,

    // 36f0: Write to RAM 801c775c (Dialogue Window Y Pos)
    STW,
    (s32)&D_801C775C_1C835C,

    // 36f8: Store Value: 48
    WTS,
    0x48,

    // 3700: Write to RAM 801c7768 (Dialogue Window Style)
    STW,
    (s32)&D_801C7768_1C8368,

    // 3708: Store Value: 7
    WTS,
    0x7,

    // 3710: Print Text
    TXT,
    (s32)&scenario_text_0000,

    // 3718: Write to RAM 801c7770 (Unknown)
    STW,
    (s32)&D_801C7770_1C8370,

    // 3720: Store Value: 1
    WTS,
    0x1,

    // 3728: Write to RAM 801c7740 (Scratch)
    STW,
    (s32)&D_801C7740_1C8340,

    // 3730: Store Value: 14
    WTS,
    0x14,

    // 3738: Execute Code: 8003f608 (Play Sound)
    ESR,
    (s32)&func_8003F608_40208,

    // 3740: Write to RAM 801c77d8 (Text Speed)
    STW,
    (s32)&D_801C77D8_1C83D8,

    // 3748: Store Value: 64
    WTS,
    0x64,

    // 3750: Write to RAM 801c7798 (Unknown)
    STW,
    (s32)&D_801C7798_1C8398,

    // 3758: Store Value: 1
    WTS,
    0x1,

    // // 3760: Print Text
    // TXT,
    // (s32)&scenario_text_0014,

    // // 3768: Print Text
    // TXT,
    // (s32)&scenario_text_002B,

    // Update scenario_text_0060 with AP location text before displaying it
    ESR,
    (s32)&update_medal_of_justice_text,

    // 3770: Print Text
    TXT,
    (s32)&scenario_text_0060,

    // 3778: Write to RAM 801c7740 (Scratch)
    STW,
    (s32)&D_801C7740_1C8340,

    // 3780: Store Value: 96
    WTS,
    0x96,

    // 3788: Execute Code: 8003f460 (Wait For Timer)
    ESR,
    (s32)&func_8003F460_40060,

    // 3790: Write to RAM 801c7740 (Scratch)
    STW,
    (s32)&D_801C7740_1C8340,

    // 3798: Store Value: 31
    WTS,
    0x31,

    // 37a0: Execute Code: 8003f608 (Play Sound)
    ESR,
    (s32)&func_8003F608_40208,

    // 37a8: Print Text
    TXT,
    (s32)&scenario_text_00A7,

    // 37b0: Print Text
    TXT,
    (s32)&scenario_text_00B9,

    // 37b8: Write to RAM 801c77d8 (Text Speed)
    STW,
    (s32)&D_801C77D8_1C83D8,

    // 37c0: Store Value: 1
    WTS,
    0x1,

    // 37c8: Write to RAM 801c7798 (Unknown)
    STW,
    (s32)&D_801C7798_1C8398,

    // 37d0: Store Value: 1
    WTS,
    0x1,

    // // 37d8: Print Text
    // TXT,
    // (s32)&scenario_text_00D1,

    // // 37e0: Print Text
    // TXT,
    // (s32)&scenario_text_00E8,

    // // 37e8: Print Text
    // TXT,
    // (s32)&scenario_text_0124,

    // // 37f0: Print Text
    // TXT,
    // (s32)&scenario_text_00B9,

    // // 37f8: Print Text
    // TXT,
    // (s32)&scenario_text_0174,

    // // 3800: Print Text
    // TXT,
    // (s32)&scenario_text_01B8,

    // // 3808: Print Text
    // TXT,
    // (s32)&scenario_text_01EC,

    // // 3810: Print Text
    // TXT,
    // (s32)&scenario_text_022C,

    // // 3818: Write to RAM 8015c6dc (Fire Ryo Chargeable?)
    // STW, 0x8015c6dc,

    // // 3820: Store Value: 1
    // WTS, 0x1,

    // // 3828: Print Text
    // TXT,
    // (s32)&scenario_text_0260,

    // 3830: End Event
    END,

    // End scenario script
    END,
};

// Function to update the Medal of Justice text with AP location data
void update_medal_of_justice_text(void)
{
  update_text_buffer_with_ap_location(scenario_text_0060, 0x013, NULL, NULL);
}
