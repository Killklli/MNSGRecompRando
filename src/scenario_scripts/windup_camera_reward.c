// Wind-Up Camera item reward scenario script
// Based on original MESSAGE 083: 05d-3834.3834


#include "types.h"
#include "modding.h"
#include "recomputils.h"
#include "scenario.h"
#include "scenario_replacer.h"

// Function declarations
void update_windup_camera_text(void);

// Text fragments for Wind-Up Camera reward scene

// {begin}{endline}
static s16 scenario_text_begin[] = {
    CTR_BEGIN,
    CTR_ENDLINE,
};

// {newwindow}{endline}
static s16 scenario_text_newwindow[] = {
    CTR_NEWWINDOW,
    CTR_ENDLINE,
};

// {waitinput}{end}{endline}
static s16 scenario_text_waitinput_end[] = {
    CTR_WAITINPUT,
    CTR_END,
    CTR_ENDLINE,
};

// {button}{endline}
static s16 scenario_text_button[] = {
    CTR_BUTTON,
    CTR_ENDLINE,
};

// {newline}{endline}
static s16 scenario_text_newline[] = {
    CTR_NEWLINE,
    CTR_ENDLINE,
};

//    Ebisumaru receives{newline}{endline}
static s16 scenario_text_ebisumaru_receives[] = {
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    CHR_E,
    CHR_b,
    CHR_i,
    CHR_s,
    CHR_u,
    CHR_m,
    CHR_a,
    CHR_r,
    CHR_u,
    PCT_SPACE,
    CHR_r,
    CHR_e,
    CHR_c,
    CHR_e,
    CHR_i,
    CHR_v,
    CHR_e,
    CHR_s,
    CTR_NEWLINE,
    CTR_ENDLINE,
};

//       the {em-yellow}[Windup Camera]{/em}!{newline}{endline}
static s16 scenario_text_windup_camera[] = {
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    PCT_SPACE,
    CHR_t,
    CHR_h,
    CHR_e,
    PCT_SPACE,
    CTR_EM_YELLOW,
    PCT_LBRACKET,
    CHR_W,
    CHR_i,
    CHR_n,
    CHR_d,
    CHR_u,
    CHR_p,
    PCT_SPACE,
    CHR_C,
    CHR_a,
    CHR_m,
    CHR_e,
    CHR_r,
    CHR_a,
    PCT_RBRACKET,
    CTR_CLOSE_EM,
    PCT_EXCLAMATION,
    CTR_NEWLINE,
    CTR_ENDLINE,
};

//By continuously holding down{newline}{endline}
static s16 scenario_text_continuously_holding[] = {
    CHR_B,
    CHR_y,
    PCT_SPACE,
    CHR_c,
    CHR_o,
    CHR_n,
    CHR_t,
    CHR_i,
    CHR_n,
    CHR_u,
    CHR_o,
    CHR_u,
    CHR_s,
    CHR_l,
    CHR_y,
    PCT_SPACE,
    CHR_h,
    CHR_o,
    CHR_l,
    CHR_d,
    CHR_i,
    CHR_n,
    CHR_g,
    PCT_SPACE,
    CHR_d,
    CHR_o,
    CHR_w,
    CHR_n,
    CTR_NEWLINE,
    CTR_ENDLINE,
};

//the {em-yellow}B Button{/em} and then letting go...{newline}{endline}
static s16 scenario_text_b_button_letting_go[] = {
    CHR_t,
    CHR_h,
    CHR_e,
    PCT_SPACE,
    CTR_EM_YELLOW,
    CHR_B,
    PCT_SPACE,
    CHR_B,
    CHR_u,
    CHR_t,
    CHR_t,
    CHR_o,
    CHR_n,
    CTR_CLOSE_EM,
    PCT_SPACE,
    CHR_a,
    CHR_n,
    CHR_d,
    PCT_SPACE,
    CHR_t,
    CHR_h,
    CHR_e,
    CHR_n,
    PCT_SPACE,
    CHR_l,
    CHR_e,
    CHR_t,
    CHR_t,
    CHR_i,
    CHR_n,
    CHR_g,
    PCT_SPACE,
    CHR_g,
    CHR_o,
    PCT_PERIOD,
    PCT_PERIOD,
    PCT_PERIOD,
    CTR_NEWLINE,
    CTR_ENDLINE,
};

//a light will shine... {button}{endline}
static s16 scenario_text_light_will_shine[] = {
    CHR_a,
    PCT_SPACE,
    CHR_l,
    CHR_i,
    CHR_g,
    CHR_h,
    CHR_t,
    PCT_SPACE,
    CHR_w,
    CHR_i,
    CHR_l,
    CHR_l,
    PCT_SPACE,
    CHR_s,
    CHR_h,
    CHR_i,
    CHR_n,
    CHR_e,
    PCT_PERIOD,
    PCT_PERIOD,
    PCT_PERIOD,
    PCT_SPACE,
    CTR_BUTTON,
    CTR_ENDLINE,
};

//allowing you to see items{newline}{endline}
static s16 scenario_text_allowing_see_items[] = {
    CHR_a,
    CHR_l,
    CHR_l,
    CHR_o,
    CHR_w,
    CHR_i,
    CHR_n,
    CHR_g,
    PCT_SPACE,
    CHR_y,
    CHR_o,
    CHR_u,
    PCT_SPACE,
    CHR_t,
    CHR_o,
    PCT_SPACE,
    CHR_s,
    CHR_e,
    CHR_e,
    PCT_SPACE,
    CHR_i,
    CHR_t,
    CHR_e,
    CHR_m,
    CHR_s,
    CTR_NEWLINE,
    CTR_ENDLINE,
};

//you would not normally see or{newline}{endline}
static s16 scenario_text_not_normally_see[] = {
    CHR_y,
    CHR_o,
    CHR_u,
    PCT_SPACE,
    CHR_w,
    CHR_o,
    CHR_u,
    CHR_l,
    CHR_d,
    PCT_SPACE,
    CHR_n,
    CHR_o,
    CHR_t,
    PCT_SPACE,
    CHR_n,
    CHR_o,
    CHR_r,
    CHR_m,
    CHR_a,
    CHR_l,
    CHR_l,
    CHR_y,
    PCT_SPACE,
    CHR_s,
    CHR_e,
    CHR_e,
    PCT_SPACE,
    CHR_o,
    CHR_r,
    CTR_NEWLINE,
    CTR_ENDLINE,
};

//hidden items!{newline}{endline}
static s16 scenario_text_hidden_items[] = {
    CHR_h,
    CHR_i,
    CHR_d,
    CHR_d,
    CHR_e,
    CHR_n,
    PCT_SPACE,
    CHR_i,
    CHR_t,
    CHR_e,
    CHR_m,
    CHR_s,
    PCT_EXCLAMATION,
    CTR_NEWLINE,
    CTR_ENDLINE,
};

//  (Even {em-yellow}ghosts{/em} will appear){endline}
static s16 scenario_text_ghosts_appear[] = {
    PCT_SPACE,
    PCT_SPACE,
    PCT_LPAREN,
    CHR_E,
    CHR_v,
    CHR_e,
    CHR_n,
    PCT_SPACE,
    CTR_EM_YELLOW,
    CHR_g,
    CHR_h,
    CHR_o,
    CHR_s,
    CHR_t,
    CHR_s,
    CTR_CLOSE_EM,
    PCT_SPACE,
    CHR_w,
    CHR_i,
    CHR_l,
    CHR_l,
    PCT_SPACE,
    CHR_a,
    CHR_p,
    CHR_p,
    CHR_e,
    CHR_a,
    CHR_r,
    PCT_RPAREN,
    CTR_ENDLINE,
};

// Main Wind-Up Camera reward scenario (message 083: 05d-3834.3834)
s32 scenario_code_message_083_3834[] = {
    // Write to RAM 801c7768 (Dialogue Window Style): 7
    STW,
    0x801c7768,
    WTS,
    0x7,

    // Print Text: "{begin}{endline}"
    TXT,
    (s32)scenario_text_begin,

    // Write to RAM 801c7770 (Unknown): 1
    STW,
    0x801c7770,
    WTS,
    0x1,

    // Write to RAM 801c7740 (Scratch): 14
    STW,
    0x801c7740,
    WTS,
    0x14,

    // Execute Code: 8003f608 (Play Sound)
    ESR,
    0x8003f608,

    // Write to RAM 801c77d8 (Text Speed): 64
    STW,
    0x801c77d8,
    WTS,
    0x64,

    // Write to RAM 801c7798 (Unknown): 1
    STW,
    0x801c7798,
    WTS,
    0x1,

    // // Print Text: " {newline}{endline}"
    // TXT,
    // (s32)scenario_text_newline,

    // // Print Text: "   Ebisumaru receives{newline}{endline}"
    // TXT,
    // (s32)scenario_text_ebisumaru_receives,

    // Update scenario_text_windup_camera with AP location text before displaying it
    ESR,
    (s32)&update_windup_camera_text,

    // Print Text: "       the {em-yellow}[Windup Camera]{/em}!{newline}{endline}"
    TXT,
    (s32)scenario_text_windup_camera,

    // Write to RAM 801c7740 (Scratch): 96
    STW,
    0x801c7740,
    WTS,
    0x96,

    // Execute Code: 8003f460 (Wait For Timer)
    ESR,
    0x8003f460,

    // Write to RAM 801c7740 (Scratch): 40
    STW,
    0x801c7740,
    WTS,
    0x40,

    // Execute Code: 8003f608 (Play Sound)
    ESR,
    0x8003f608,

    // Print Text: "{button}{endline}"
    TXT,
    (s32)scenario_text_button,

    // // Print Text: "{newwindow}{endline}"
    // TXT,
    // (s32)scenario_text_newwindow,

    // Write to RAM 801c77d8 (Text Speed): 1
    STW,
    0x801c77d8,
    WTS,
    0x1,

    // Write to RAM 801c7798 (Unknown): 1
    STW,
    0x801c7798,
    WTS,
    0x1,

    // // Print Text: "By continuously holding down{newline}{endline}"
    // TXT,
    // (s32)scenario_text_continuously_holding,

    // // Print Text: "the {em-yellow}B Button{/em} and then letting go...{newline}{endline}"
    // TXT,
    // (s32)scenario_text_b_button_letting_go,

    // // Print Text: "a light will shine... {button}{endline}"
    // TXT,
    // (s32)scenario_text_light_will_shine,

    // // Print Text: "{newwindow}{endline}"
    // TXT,
    // (s32)scenario_text_newwindow,

    // // Print Text: "allowing you to see items{newline}{endline}"
    // TXT,
    // (s32)scenario_text_allowing_see_items,

    // // Print Text: "you would not normally see or{newline}{endline}"
    // TXT,
    // (s32)scenario_text_not_normally_see,

    // // Print Text: "hidden items!{newline}{endline}"
    // TXT,
    // (s32)scenario_text_hidden_items,

    // // Print Text: "  (Even {em-yellow}ghosts{/em} will appear){endline}"
    // TXT,
    // (s32)scenario_text_ghosts_appear,

    // // Write to RAM 8015c6d0 (Obtained Wind-Up Camera): 1
    // STW,
    // 0x8015c6d0,
    // WTS,
    // 0x1,

    // // Write to RAM 8015c6e0 (Wind-Up Camera Chargeable?): 1
    // STW,
    // 0x8015c6e0,
    // WTS,
    // 0x1,

    // Print Text: "{waitinput}{end}{endline}"
    TXT,
    (s32)scenario_text_waitinput_end,

    // End Event
    END,
};

// Function to update the Wind-Up Camera text with AP location data
void update_windup_camera_text(void)
{
  update_text_buffer_with_ap_location(scenario_text_windup_camera, 0x01A3, NULL, NULL);
}
