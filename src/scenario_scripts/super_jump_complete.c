#include "types.h"
#include "scenario.h"
#include "scenario_replacer.h"

// Function declarations
void update_super_jump_text(void);



// Address: @3650

// {begin}{endline}
static s16 scenario_text_0000[] = {CTR_BEGIN, CTR_ENDLINE};

// {em-yellow}Bravo!{/em}{newline}{endline}
static s16 scenario_text_0014[] = {
    CTR_EM_YELLOW, CHR_B, CHR_r, CHR_a, CHR_v,
    CHR_o, PCT_EXCLAMATION, CTR_CLOSE_EM, CTR_NEWLINE, CTR_ENDLINE};

// From now on, you can call{newline}{endline}
static s16 scenario_text_0040[] = {
    CHR_F, CHR_r, CHR_o, CHR_m, PCT_SPACE, CHR_n, CHR_o,
    CHR_w, PCT_SPACE, CHR_o, CHR_n, PCT_COMMA, PCT_SPACE, CHR_y,
    CHR_o, CHR_u, PCT_SPACE, CHR_c, CHR_a, CHR_n, PCT_SPACE,
    CHR_c, CHR_a, CHR_l, CHR_l, CTR_NEWLINE, CTR_ENDLINE};

// yourself a {em-yellow}Super Jumper{/em}!{button}{endline}
static s16 scenario_text_006F[] = {
    CHR_y, CHR_o, CHR_u, CHR_r, CHR_s,
    CHR_e, CHR_l, CHR_f, PCT_SPACE, CHR_a,
    PCT_SPACE, CTR_EM_YELLOW, CHR_S, CHR_u, CHR_p,
    CHR_e, CHR_r, PCT_SPACE, CHR_J, CHR_u,
    CHR_m, CHR_p, CHR_e, CHR_r, CTR_CLOSE_EM,
    PCT_EXCLAMATION, CTR_BUTTON, CTR_ENDLINE};

// {newwindow}{endline}
static s16 scenario_text_00AC[] = {CTR_NEWWINDOW, CTR_ENDLINE};

// {end}{endline}
static s16 scenario_text_00C4[] = {CTR_END, CTR_ENDLINE};

// {begin}{endline}
static s16 scenario_text_00D6[] = {CTR_BEGIN, CTR_ENDLINE};

//   {newline}{endline}
static s16 scenario_text_00EA[] = {PCT_SPACE, PCT_SPACE, CTR_NEWLINE,
                                   CTR_ENDLINE};

// Sasuke obtains{newline}{endline}
static s16 scenario_text_0102[] = {
    CHR_S, CHR_a, CHR_s, CHR_u, CHR_k, CHR_e, PCT_SPACE, CHR_o,
    CHR_b, CHR_t, CHR_a, CHR_i, CHR_n, CHR_s, CTR_NEWLINE, CTR_ENDLINE};

//    the [{em-yellow}Flying{/em}] magic powers!{newline}{endline}
static s16 scenario_text_0126[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_t, CHR_h,
    CHR_e, PCT_SPACE, PCT_LBRACKET, CTR_EM_YELLOW, CHR_F,
    CHR_l, CHR_y, CHR_i, CHR_n, CHR_g,
    CTR_CLOSE_EM, PCT_RBRACKET, PCT_SPACE, CHR_m, CHR_a,
    CHR_g, CHR_i, CHR_c, PCT_SPACE, CHR_p,
    CHR_o, CHR_w, CHR_e, CHR_r, CHR_s,
    PCT_EXCLAMATION, CTR_NEWLINE, CTR_ENDLINE};

// {button}{endline}
static s16 scenario_text_0169[] = {CTR_BUTTON, CTR_ENDLINE};

// {newwindow}{endline}
static s16 scenario_text_017E[] = {CTR_NEWWINDOW, CTR_ENDLINE};

// Using the {em-yellow}Super Jump{/em}, you can {newline}{endline}
static s16 scenario_text_0196[] = {
    CHR_U, CHR_s, CHR_i, CHR_n, CHR_g, PCT_SPACE,
    CHR_t, CHR_h, CHR_e, PCT_SPACE, CTR_EM_YELLOW, CHR_S,
    CHR_u, CHR_p, CHR_e, CHR_r, PCT_SPACE, CHR_J,
    CHR_u, CHR_m, CHR_p, CTR_CLOSE_EM, PCT_COMMA, PCT_SPACE,
    CHR_y, CHR_o, CHR_u, PCT_SPACE, CHR_c, CHR_a,
    CHR_n, PCT_SPACE, CTR_NEWLINE, CTR_ENDLINE};

// go to {em-yellow}high places{/em} that were{newline}{endline}
static s16 scenario_text_01DA[] = {
    CHR_g, CHR_o, PCT_SPACE, CHR_t, CHR_o, PCT_SPACE,
    CTR_EM_YELLOW, CHR_h, CHR_i, CHR_g, CHR_h, PCT_SPACE,
    CHR_p, CHR_l, CHR_a, CHR_c, CHR_e, CHR_s,
    CTR_CLOSE_EM, PCT_SPACE, CHR_t, CHR_h, CHR_a, CHR_t,
    PCT_SPACE, CHR_w, CHR_e, CHR_r, CHR_e, CTR_NEWLINE,
    CTR_ENDLINE};

// previously unreachable!{endline}
static s16 scenario_text_021B[] = {
    CHR_p, CHR_r, CHR_e, CHR_v, CHR_i, CHR_o, CHR_u, CHR_s,
    CHR_l, CHR_y, PCT_SPACE, CHR_u, CHR_n, CHR_r, CHR_e, CHR_a,
    CHR_c, CHR_h, CHR_a, CHR_b, CHR_l, CHR_e, PCT_EXCLAMATION, CTR_ENDLINE};

// {waitinput}{end}{endline}
static s16 scenario_text_023F[] = {CTR_WAITINPUT, CTR_END, CTR_ENDLINE};

extern s32 scenario_code_message_17a_3650[];

s32 scenario_code_message_17a_3650[] = {

    // Address: @3650

    // 3650: Write to RAM 801c7758 (Unknown)
    STW,
    (s32)&D_801C7758_1C8358,

    // 3658: Store Value: 20
    WTS,
    0x20,

    // 3660: Write to RAM 801c775c (Dialogue Window Y Pos)
    STW,
    (s32)&D_801C775C_1C835C,

    // 3668: Store Value: 68
    WTS,
    0x68,

    // 3670: Write to RAM 801c7770 (Unknown)
    STW,
    (s32)&D_801C7770_1C8370,

    // 3678: Store Value: 1
    WTS,
    0x1,

    // 3680: Print Text
    TXT,
    (s32)&scenario_text_0000,

    // 3688: Print Text
    TXT,
    (s32)&scenario_text_0014,

    // 3690: Print Text
    TXT,
    (s32)&scenario_text_0040,

    // 3698: Print Text
    TXT,
    (s32)&scenario_text_006F,

    // 36a0: Print Text
    TXT,
    (s32)&scenario_text_00AC,

    // 36a8: Print Text
    TXT,
    (s32)&scenario_text_00C4,

    // 36b0: Write to RAM 801c7758 (Unknown)
    STW,
    (s32)&D_801C7758_1C8358,

    // 36b8: Store Value: 20
    WTS,
    0x20,

    // 36c0: Write to RAM 801c775c (Dialogue Window Y Pos)
    STW,
    (s32)&D_801C775C_1C835C,

    // 36c8: Store Value: 48
    WTS,
    0x48,

    // 36d0: Write to RAM 801c7768 (Dialogue Window Style)
    STW,
    (s32)&D_801C7768_1C8368,

    // 36d8: Store Value: 7
    WTS,
    0x7,

    // 36e0: Print Text
    TXT,
    (s32)&scenario_text_0000,

    // 36e8: Write to RAM 801c7770 (Unknown)
    STW,
    (s32)&D_801C7770_1C8370,

    // 36f0: Store Value: 1
    WTS,
    0x1,

    // 36f8: Write to RAM 801c7740 (Scratch)
    STW,
    (s32)&D_801C7740_1C8340,

    // 3700: Store Value: 14
    WTS,
    0x14,

    // 3708: Execute Code: 8003f608 (Play Sound)
    ESR,
    (s32)&func_8003F608_40208,

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
    // (s32)&scenario_text_00EA,

    // // 3738: Print Text
    // TXT,
    // (s32)&scenario_text_0102,

    // Update scenario_text_0126 with AP location text before displaying it
    ESR,
    (s32)&update_super_jump_text,

    // 3740: Print Text
    TXT,
    (s32)&scenario_text_0126,

    // 3748: Write to RAM 801c7740 (Scratch)
    STW,
    (s32)&D_801C7740_1C8340,

    // 3750: Store Value: 96
    WTS,
    0x96,

    // 3758: Execute Code: 8003f460 (Wait For Timer)
    ESR,
    (s32)&func_8003F460_40060,

    // 3760: Write to RAM 801c7740 (Scratch)
    STW,
    (s32)&D_801C7740_1C8340,

    // 3768: Store Value: 23
    WTS,
    0x23,

    // 3770: Execute Code: 8003f608 (Play Sound)
    ESR,
    (s32)&func_8003F608_40208,

    // 3778: Print Text
    TXT,
    (s32)&scenario_text_0169,

    // 3780: Print Text
    TXT,
    (s32)&scenario_text_00AC,

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
    // (s32)&scenario_text_0196,

    // // 37b0: Print Text
    // TXT,
    // (s32)&scenario_text_01DA,

    // // 37b8: Print Text
    // TXT,
    // (s32)&scenario_text_021B,

    // DISABLED ITEM
    // // 37c0: Write to RAM 8015c6f4 (Obtained Super Jump Magic)
    // STW, 0x8015c6f4,

    // // 37c8: Store Value: 1
    // WTS, 0x1,

    // 37d0: Set Flag 020 (Obtained Super Jump Magic)
    SFG,
    0x20,

    // // 37d8: Print Text
    // TXT,
    // (s32)&scenario_text_023F,

    // 37e0: End Event
    END,

    // End scenario script
    END,
};

// Function to update the super jump text with AP location data
void update_super_jump_text(void)
{
  update_text_buffer_with_ap_location(scenario_text_0126, 6474081, NULL, NULL);
}
