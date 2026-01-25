// Allows us to change the item granted by the Oedo Castle Lord.
#include "modding.h"
#include "recomputils.h"
#include "scenario.h"
#include "scenario_replacer.h"

#include "common.h"

// Address: @4b70

// {begin}{endline}
static s16 scenario_text_0000[] = {CTR_BEGIN, CTR_ENDLINE};

//   {newline}{endline}
static s16 scenario_text_0014[] = {PCT_SPACE, PCT_SPACE, CTR_NEWLINE,
                                   CTR_ENDLINE};

//  Goemon and Ebisumaru receive{newline}{endline}
static s16 scenario_text_002C[] = {
    PCT_SPACE, CHR_G, CHR_o, CHR_e, CHR_m, CHR_o, CHR_n,
    PCT_SPACE, CHR_a, CHR_n, CHR_d, PCT_SPACE, CHR_E, CHR_b,
    CHR_i, CHR_s, CHR_u, CHR_m, CHR_a, CHR_r, CHR_u,
    PCT_SPACE, CHR_r, CHR_e, CHR_c, CHR_e, CHR_i, CHR_v,
    CHR_e, CTR_NEWLINE, CTR_ENDLINE};

//    a [{em-yellow}Super Pass{/em}] from the Lord!{endline}
static s16 scenario_text_005F[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, CHR_a, PCT_SPACE,
    PCT_LBRACKET, CTR_EM_YELLOW, CHR_S, CHR_u, CHR_p,
    CHR_e, CHR_r, PCT_SPACE, CHR_P, CHR_a,
    CHR_s, CHR_s, CTR_CLOSE_EM, PCT_RBRACKET, PCT_SPACE,
    CHR_f, CHR_r, CHR_o, CHR_m, PCT_SPACE,
    CHR_t, CHR_h, CHR_e, PCT_SPACE, CHR_L,
    CHR_o, CHR_r, CHR_d, PCT_EXCLAMATION, CTR_ENDLINE};

// {end}{endline}
static s16 scenario_text_009C[] = {CTR_END, CTR_ENDLINE};

// {begin}{endline}
static s16 scenario_text_00AE[] = {CTR_BEGIN, CTR_ENDLINE};

// Lord:I'm counting on you!{endline}
static s16 scenario_text_00C2[] = {
    CHR_L, CHR_o, CHR_r, CHR_d, PCT_COLON, CHR_I, PCT_APOSTROPHE,
    CHR_m, PCT_SPACE, CHR_c, CHR_o, CHR_u, CHR_n, CHR_t,
    CHR_i, CHR_n, CHR_g, PCT_SPACE, CHR_o, CHR_n, PCT_SPACE,
    CHR_y, CHR_o, CHR_u, PCT_EXCLAMATION, CTR_ENDLINE};

// {button}{end}{endline}
static s16 scenario_text_00E8[] = {CTR_BUTTON, CTR_END, CTR_ENDLINE};

extern s32 scenario_code_message_0ca_4b70[];

s32 scenario_code_message_0ca_4b70[] = {

    // Address: @4b70

    // 4b70: Write to RAM 801c7758 (Unknown)
    STW,
    (s32)&D_801C7758_1C8358,

    // 4b78: Store Value: 20
    WTS,
    0x20,

    // 4b80: Write to RAM 801c775c (Dialogue Window Y Pos)
    STW,
    (s32)&D_801C775C_1C835C,

    // 4b88: Store Value: 48
    WTS,
    0x48,

    // 4b90: Write to RAM 801c7768 (Dialogue Window Style)
    STW,
    (s32)&D_801C7768_1C8368,

    // 4b98: Store Value: 7
    WTS,
    0x7,

    // 4ba0: Print Text
    TXT,
    (s32)&scenario_text_0000,

    // 4ba8: Write to RAM 801c7770 (Unknown)
    STW,
    (s32)&D_801C7770_1C8370,

    // 4bb0: Store Value: 1
    WTS,
    0x1,

    // 4bb8: Write to RAM 801c77d8 (Text Speed)
    STW,
    0x801c77d8,

    // 4bc0: Store Value: 64
    WTS,
    0x64,

    // 4bc8: Write to RAM 801c7798 (Unknown)
    STW,
    0x801c7798,

    // 4bd0: Store Value: 1
    WTS,
    0x1,

    // 4bd8: Write to RAM 801c7740 (Scratch)
    STW,
    (s32)&D_801C7740_1C8340,

    // 4be0: Store Value: 14
    WTS,
    0x14,

    // 4be8: Execute Code: 8003f608 (Play Sound)
    ESR,
    (s32)&func_8003F608_40208,

    // 4bf0: Print Text
    TXT,
    (s32)&scenario_text_0014,

    // 4bf8: Print Text
    TXT,
    (s32)&scenario_text_002C,

    // 4c00: Print Text
    TXT,
    (s32)&scenario_text_005F,

    // 4c08: Write to RAM 801c7740 (Scratch)
    STW,
    (s32)&D_801C7740_1C8340,

    // 4c10: Store Value: 96
    WTS,
    0x96,

    // 4c18: Execute Code: 8003f460 (Wait For Timer)
    ESR,
    (s32)&func_8003F460_40060,

    // 4c20: Print Text
    TXT,
    (s32)&scenario_text_009C,

    // 4c28: Write to RAM 801c7758 (Unknown)
    STW,
    (s32)&D_801C7758_1C8358,

    // 4c30: Store Value: 20
    WTS,
    0x20,

    // 4c38: Write to RAM 801c775c (Dialogue Window Y Pos)
    STW,
    (s32)&D_801C775C_1C835C,

    // 4c40: Store Value: 20
    WTS,
    0x20,

    // 4c48: Write to RAM 801c7768 (Dialogue Window Style)
    STW,
    (s32)&D_801C7768_1C8368,

    // 4c50: Store Value: 1
    WTS,
    0x1,

    // 4c58: Set Flag 05e (???)
    SFG,
    0x5E,

    // 4c60: Print Text
    TXT,
    (s32)&scenario_text_0000,

    // 4c68: Write to RAM 801c7770 (Unknown)
    STW,
    (s32)&D_801C7770_1C8370,

    // 4c70: Store Value: 1
    WTS,
    0x1,

    // 4c78: Write to RAM 801c77d8 (Text Speed)
    STW,
    0x801c77d8,

    // 4c80: Store Value: 1
    WTS,
    0x1,

    // 4c88: Write to RAM 801c7798 (Unknown)
    STW,
    0x801c7798,

    // 4c90: Store Value: 1
    WTS,
    0x1,

    // 4c98: Print Text
    TXT,
    (s32)&scenario_text_00C2,

    // 4ca0: Set Flag 000 (Received Super Pass)
    SFG,
    0x00,

    // DISABLED ITEM
    // // 4ca8: Write to RAM 8015c700 (Obtained Super Pass)
    // STW, 0x8015c700,

    // // 4cb0: Store Value: 1
    // WTS, 0x1,

    // 4cb8: Write to RAM 8015c89c (Unknown)
    STW,
    0x8015c89c,

    // 4cc0: Increase By 1
    INC,
    0x1,

    // 4cc8: Write to RAM 8015c81c (Unknown)
    STW,
    0x8015c81c,

    // 4cd0: Store Value: 1
    WTS,
    0x1,

    // 4cd8: Print Text
    TXT,
    (s32)&scenario_text_00E8,

    // // 4ce0: Jump To @6548 SAVE FUNCTION
    // JMP, 0x6548,
    // WARNING: Jump to @6548 - this address may be in a different message file

    // 4ce8: End Event
    END,

    // End scenario script
    END,
};
