// Item Hint system for Plasma Fortune Teller
// Provides brief hints for progression
#include "types.h"
#include "scenario.h"
#include "Archipelago.h"
#include "modding.h"
#include "recomputils.h"
#include "libc/string.h"
#include "scenario_replacer.h"

// Small location hint response text - now dynamically generated
static s16 scenario_text_small_hint_0001[256]; // Static buffer for dynamic content

// Counter to track which hint we're on (persists between calls)
static int current_hint_index = 0;

// Function to populate the scenario_text_small_hint_0001 buffer with the next hint
void populate_small_location_hint()
{
    s16 *hint_text = get_next_location_hint();
    
    // Copy the hint text to the scenario buffer
    // We need to check for CTR_ENDLINE specifically, not just 0, since PCT_SPACE is 0
    int i = 0;
    while (i < 255)
    {
        scenario_text_small_hint_0001[i] = hint_text[i];
        
        // Stop when we hit CTR_ENDLINE (which marks the actual end of text)
        if (hint_text[i] == CTR_ENDLINE) {
            i++;
            break;
        }
        
        i++;
    }
}

// {waitinput}{end}{endline}
static s16 scenario_text_small_hint_end[] = {CTR_WAITINPUT, CTR_END, CTR_ENDLINE};

// {newwindow}{endline}
static s16 scenario_text_006F[] = {CTR_NEWWINDOW, CTR_ENDLINE};

//  {newline}{endline}
static s16 scenario_text_0014[] = {PCT_SPACE, CTR_NEWLINE, CTR_ENDLINE};

// {/em}Okay,{newline}{endline}
static s16 scenario_text_0227[] = {CTR_CLOSE_EM, CHR_O, CHR_k,
                                   CHR_a, CHR_y, PCT_COMMA,
                                   CTR_NEWLINE, CTR_ENDLINE};

// well let's get started!!{button}{endline}
static s16 scenario_text_0247[] = {
    CHR_w, CHR_e, CHR_l, CHR_l, PCT_SPACE,
    CHR_l, CHR_e, CHR_t, PCT_APOSTROPHE, CHR_s,
    PCT_SPACE, CHR_g, CHR_e, CHR_t, PCT_SPACE,
    CHR_s, CHR_t, CHR_a, CHR_r, CHR_t,
    CHR_e, CHR_d, PCT_EXCLAMATION, PCT_EXCLAMATION, CTR_BUTTON,
    CTR_ENDLINE};

// Hmmmm, abababa, hmmmm, abababa,{newline}{endline}
static s16 scenario_text_028C[] = {
    CHR_H, CHR_m, CHR_m, CHR_m, CHR_m, PCT_COMMA, PCT_SPACE, CHR_a,
    CHR_b, CHR_a, CHR_b, CHR_a, CHR_b, CHR_a, PCT_COMMA, PCT_SPACE,
    CHR_h, CHR_m, CHR_m, CHR_m, CHR_m, PCT_COMMA, PCT_SPACE, CHR_a,
    CHR_b, CHR_a, CHR_b, CHR_a, CHR_b, CHR_a, PCT_COMMA, CTR_NEWLINE,
    CTR_ENDLINE};

// hmmmm, abababa, hmmmm, abababa,{newline}{endline}
static s16 scenario_text_02C1[] = {
    CHR_h, CHR_m, CHR_m, CHR_m, CHR_m, PCT_COMMA, PCT_SPACE, CHR_a,
    CHR_b, CHR_a, CHR_b, CHR_a, CHR_b, CHR_a, PCT_COMMA, PCT_SPACE,
    CHR_h, CHR_m, CHR_m, CHR_m, CHR_m, PCT_COMMA, PCT_SPACE, CHR_a,
    CHR_b, CHR_a, CHR_b, CHR_a, CHR_b, CHR_a, PCT_COMMA, CTR_NEWLINE,
    CTR_ENDLINE};

// hmmmm, abababa, hmmmm, abababa...{button}{endline}
static s16 scenario_text_02F6[] = {
    CHR_h, CHR_m, CHR_m, CHR_m, CHR_m, PCT_COMMA,
    PCT_SPACE, CHR_a, CHR_b, CHR_a, CHR_b, CHR_a,
    CHR_b, CHR_a, PCT_COMMA, PCT_SPACE, CHR_h, CHR_m,
    CHR_m, CHR_m, CHR_m, PCT_COMMA, PCT_SPACE, CHR_a,
    CHR_b, CHR_a, CHR_b, CHR_a, CHR_b, CHR_a,
    PCT_PERIOD, PCT_PERIOD, PCT_PERIOD, CTR_BUTTON, CTR_ENDLINE};

//        {em-yellow}{blink}{big}P L A S M A !
//        {/big}{/blink}{/em}{button}{endline}
static s16 scenario_text_035B[] = {
    PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE, PCT_SPACE,
    PCT_SPACE, PCT_SPACE, CTR_EM_YELLOW, CTR_BLINK, CTR_BIG,
    CHR_P, PCT_SPACE, CHR_L, PCT_SPACE, CHR_A,
    PCT_SPACE, CHR_S, PCT_SPACE, CHR_M, PCT_SPACE,
    CHR_A, PCT_SPACE, PCT_EXCLAMATION, PCT_SPACE, CTR_CLOSE_BIG,
    CTR_CLOSE_BLINK, CTR_CLOSE_EM, CTR_BUTTON, CTR_ENDLINE};

// {/em}I'm not telling anything to anyone{newline}{endline}
static s16 scenario_text_0470[] = {
    CTR_CLOSE_EM, CHR_I, PCT_APOSTROPHE, CHR_m, PCT_SPACE, CHR_n, CHR_o,
    CHR_t, PCT_SPACE, CHR_t, CHR_e, CHR_l, CHR_l, CHR_i,
    CHR_n, CHR_g, PCT_SPACE, CHR_a, CHR_n, CHR_y, CHR_t,
    CHR_h, CHR_i, CHR_n, CHR_g, PCT_SPACE, CHR_t, CHR_o,
    PCT_SPACE, CHR_a, CHR_n, CHR_y, CHR_o, CHR_n, CHR_e,
    CTR_NEWLINE, CTR_ENDLINE};

// who's got no money, plasma!{endline}
static s16 scenario_text_04AD[] = {
    CHR_w, CHR_h, CHR_o, PCT_APOSTROPHE, CHR_s, PCT_SPACE,
    CHR_g, CHR_o, CHR_t, PCT_SPACE, CHR_n, CHR_o,
    PCT_SPACE, CHR_m, CHR_o, CHR_n, CHR_e, CHR_y,
    PCT_COMMA, PCT_SPACE, CHR_p, CHR_l, CHR_a, CHR_s,
    CHR_m, CHR_a, PCT_EXCLAMATION, CTR_ENDLINE};

// {waitinput}{end}{endline}
static s16 scenario_text_04D5[] = {CTR_WAITINPUT, CTR_END, CTR_ENDLINE};

// Forward declaration
extern s32 scenario_code_message_288_small_hint_no_money[];

s32 scenario_code_message_288_small_hint[] = {
    
    // Item Hint Logic with 10 ryo payment

    // Print new window
    TXT,
    (s32)&scenario_text_006F,

    // Write to RAM 801c7770 (Unknown)
    STW,
    (s32)&D_801C7770_1C8370,

    // Store Value: 1
    WTS,
    0x1,

    // Write to RAM 801c7740 (Scratch)
    STW,
    (s32)&D_801C7740_1C8340,

    // Store Value: fffffff6 (take 10 ryo)
    WTS,
    0xFFFFFFF6,

    // Execute Code: 80221fd4 (Give/Take Ryo)
    ESR,
    0x80221fd4,

    // Read from RAM 801c7750 (Scratch)
    LDW,
    0x801c7750,

    // Skip Next If Not Equal: 1
    SNE,
    0x1,

    // Jump To insufficient funds section
    JMP,
    (s32)&scenario_code_message_288_small_hint_no_money,

    // Write to RAM 801c7740 (Scratch)
    STW,
    (s32)&D_801C7740_1C8340,

    // Store Value: 23c (sound effect)
    WTS,
    0x23C,

    // Execute Code: 8003f608 (Play Sound)
    ESR,
    (s32)&func_8003F608_40208,

    // Print Text
    TXT,
    (s32)&scenario_text_0227,

    // Print Text
    TXT,
    (s32)&scenario_text_0247,

    // Print Text
    TXT,
    (s32)&scenario_text_006F,

    // Print Text
    TXT,
    (s32)&scenario_text_028C,

    // Print Text
    TXT,
    (s32)&scenario_text_02C1,

    // Print Text
    TXT,
    (s32)&scenario_text_02F6,

    // Print Text
    TXT,
    (s32)&scenario_text_006F,

    // Write to RAM 801c77d8 (Text Speed)
    STW,
    0x801c77d8,

    // Store Value: 64
    WTS,
    0x64,

    // Write to RAM 801c7798 (Unknown)
    STW,
    0x801c7798,

    // Store Value: 1
    WTS,
    0x1,

    // Write to RAM 801c7740 (Scratch)
    STW,
    (s32)&D_801C7740_1C8340,

    // Store Value: 354
    WTS,
    0x354,

    // Execute Code: 8003f608 (Play Sound)
    ESR,
    (s32)&func_8003F608_40208,

    // Print Text
    TXT,
    (s32)&scenario_text_0014,

    // Print Text
    TXT,
    (s32)&scenario_text_035B,

    // Print Text
    TXT,
    (s32)&scenario_text_006F,

    // Write to RAM 801c77d8 (Text Speed)
    STW,
    0x801c77d8,

    // Store Value: 1
    WTS,
    0x1,

    // Write to RAM 801c7798 (Unknown)
    STW,
    0x801c7798,

    // Store Value: 1
    WTS,
    0x1,

    // Generate fresh dynamic hint text right before displaying
    ESR,
    (s32)&populate_small_location_hint,

    // Print dynamic location hint (populated at runtime)
    TXT,
    (s32)&scenario_text_small_hint_0001,

    // Wait for input and end
    TXT,
    (s32)&scenario_text_small_hint_end,

    // End Event
    END,

    // End scenario script
    END,
};

// Insufficient funds handler for item hint
s32 scenario_code_message_288_small_hint_no_money[] = {

    // Write to RAM 801c7740 (Scratch)
    STW,
    (s32)&D_801C7740_1C8340,

    // Store Value: 2b2
    WTS,
    0x2B2,

    // Execute Code: 8003f608 (Play Sound)
    ESR,
    (s32)&func_8003F608_40208,

    // Print Text
    TXT,
    (s32)&scenario_text_0470,

    // Print Text
    TXT,
    (s32)&scenario_text_04AD,

    // Print Text
    TXT,
    (s32)&scenario_text_04D5,

    // End Event
    END,

    // End scenario script
    END,
};