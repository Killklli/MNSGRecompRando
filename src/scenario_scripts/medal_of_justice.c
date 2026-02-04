#include "types.h"
#include "scenario.h"

// Medal of Justice scenario script
// Based on MESSAGE 1ed: 066-6b44.6b44 and 066-6b44.6bd4
// Handles giving the Medal of Justice to the God of Money

// Text arrays

// {begin}{endline}
static s16 begin_text[] = {
    CTR_BEGIN,
    CTR_ENDLINE
};

// God of Money:{newline}{endline}
static s16 god_of_money_text[] = {
    CHR_G, CHR_o, CHR_d, PCT_SPACE, CHR_o, CHR_f, PCT_SPACE,
    CHR_M, CHR_o, CHR_n, CHR_e, CHR_y, PCT_COLON,
    CTR_NEWLINE, CTR_ENDLINE
};

//     Yes, I have hereby received{newline}{endline}
static s16 received_text[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE,
    CHR_Y, CHR_e, CHR_s, PCT_COMMA, PCT_SPACE,
    CHR_I, PCT_SPACE, CHR_h, CHR_a, CHR_v, CHR_e, PCT_SPACE,
    CHR_h, CHR_e, CHR_r, CHR_e, CHR_b, CHR_y, PCT_SPACE,
    CHR_r, CHR_e, CHR_c, CHR_e, CHR_i, CHR_v, CHR_e, CHR_d,
    CTR_NEWLINE, CTR_ENDLINE
};

//     your {em-yellow}Medal of Justice{/em}!{endline}
static s16 medal_text[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE,
    CHR_y, CHR_o, CHR_u, CHR_r, PCT_SPACE,
    CTR_EM_YELLOW,
    CHR_M, CHR_e, CHR_d, CHR_a, CHR_l, PCT_SPACE,
    CHR_o, CHR_f, PCT_SPACE,
    CHR_J, CHR_u, CHR_s, CHR_t, CHR_i, CHR_c, CHR_e,
    CTR_CLOSE_EM,
    PCT_EXCLAMATION,
    CTR_ENDLINE
};

//     I'm not giving you{newline}{endline}
static s16 not_giving_text[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE,
    CHR_I, PCT_APOSTROPHE, CHR_m, PCT_SPACE,
    CHR_n, CHR_o, CHR_t, PCT_SPACE,
    CHR_g, CHR_i, CHR_v, CHR_i, CHR_n, CHR_g, PCT_SPACE,
    CHR_y, CHR_o, CHR_u,
    CTR_NEWLINE, CTR_ENDLINE
};

//     anything else...{endline}
static s16 anything_else_text[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE,
    CHR_a, CHR_n, CHR_y, CHR_t, CHR_h, CHR_i, CHR_n, CHR_g, PCT_SPACE,
    CHR_e, CHR_l, CHR_s, CHR_e, PCT_PERIOD, PCT_PERIOD, PCT_PERIOD,
    CTR_ENDLINE
};

// {end}{endline}
static s16 end_text[] = {
    CTR_END,
    CTR_ENDLINE
};

// Main scenario function - First branch (before receiving Fire Ryo)
s32 scenario_code_message_1ed_6b44[] = {

    // Address: @6b44

    // 6b44: Write to RAM 801c7768 (Dialogue Window Style)
    STW,
    (s32)&D_801C7768_1C8368,

    // 6b4c: Store Value: 1
    WTS,
    0x1,

    // 6b54: Print Text: {begin}{endline}
    TXT,
    (s32)&begin_text,

    // 6b5c: Write to RAM 801c7770 (Unknown)
    STW,
    (s32)&D_801C7770_1C8370,

    // 6b64: Store Value: 1
    WTS,
    0x1,

    // 6b6c: If Flag 013 (Received Fire Ryo), Jump To @6bd4
    JFS,
    0x13,
    (s32)&scenario_code_message_1ed_6bd4,

    // 6b78: Write to RAM 801c7740 (Scratch)
    STW,
    (s32)&D_801C7740_1C8340,

    // 6b80: Store Value: 23c
    WTS,
    0x23c,

    // 6b88: Execute Code: 8003f608 (Play Sound)
    ESR,
    (s32)&func_8003F608_40208,

    // 6b90: Print Text: God of Money:{newline}{endline}
    TXT,
    (s32)&god_of_money_text,

    // 6b98: Print Text:     Yes, I have hereby received{newline}{endline}
    TXT,
    (s32)&received_text,

    // 6ba0: Print Text:     your {em-yellow}Medal of Justice{/em}!{endline}
    TXT,
    (s32)&medal_text,

    // 6ba8: Set Flag 013 (Received Fire Ryo)
    SFG,
    0x13,

    // 6bb0: Write to RAM 801c7740 (Scratch)
    STW,
    (s32)&D_801C7740_1C8340,

    // 6bb8: Store Value: 3c
    WTS,
    0x3c,

    // 6bc0: Execute Code: 8003f460 (Wait For Timer)
    ESR,
    (s32)&func_8003F460_40060,

    // 6bc8: Print Text: {end}{endline}
    TXT,
    (s32)&end_text,

    // 6bd0: End Event
    END,

    // End scenario script
    END,
};

// Second scenario function - After receiving Fire Ryo
s32 scenario_code_message_1ed_6bd4[] = {

    // Address: @6bd4

    // 6bd4: Write to RAM 801c7740 (Scratch)
    STW,
    (s32)&D_801C7740_1C8340,

    // 6bdc: Store Value: 2b2
    WTS,
    0x2b2,

    // 6be4: Execute Code: 8003f608 (Play Sound)
    ESR,
    (s32)&func_8003F608_40208,

    // 6bec: Print Text: God of Money:{newline}{endline}
    TXT,
    (s32)&god_of_money_text,

    // 6bf4: Print Text:     I'm not giving you{newline}{endline}
    TXT,
    (s32)&not_giving_text,

    // 6bfc: Print Text:     anything else...{endline}
    TXT,
    (s32)&anything_else_text,

    // 6c04: Write to RAM 801c7740 (Scratch)
    STW,
    (s32)&D_801C7740_1C8340,

    // 6c0c: Store Value: 3c
    WTS,
    0x3c,

    // 6c14: Execute Code: 8003f460 (Wait For Timer)
    ESR,
    (s32)&func_8003F460_40060,

    // 6c1c: Print Text: {end}{endline}
    TXT,
    (s32)&end_text,

    // 6c24: End Event
    END,

    // End scenario script
    END,
};
