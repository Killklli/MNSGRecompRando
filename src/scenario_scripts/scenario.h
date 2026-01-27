#include "types.h"
#ifndef SCENARIO_H
#define SCENARIO_H



// Skip Next If Not Equal To Value
#define SNE 0x8002

// Skip Next If Equal To Value
#define SEQ 0x8003

// Store Word To Address
#define STW 0x8004

// Load Word From Address
#define LDW 0x8006

// End Scenario
#define END 0x8008

// Word To Store
#define WTS 0x8009

// Jump To Address
#define JMP 0x800A

// Execute Subroutine At Address
#define ESR 0x800B

// Skip Next If Not Less Than
#define SNL 0x800C

// Print Text
#define TXT 0x8010

// Begin Option Selection
#define BOS 0x8011

// End Option Selection
#define EOS 0x8012

// Increase By Value
#define INC 0x8013

// Set Flag
#define SFG 0x8020

// Clear Flag
#define CFG 0x8021

// Jump To Address If Flag Set
#define JFS 0x8022

// Set Flag Limited
#define SFL 0x8023

// Skip Next If Address Not Equal
#define SAN 0x8030

// Load Flag
#define LDF 0x8031

// Jump If Not Equal
#define JNE 0x8032

// Clear Flag Limited
#define CLF 0x8033

// Punctuation
#define PCT_SPACE 0x0000
#define PCT_EXCLAMATION 0x0001
#define PCT_QUOTE 0x0002
#define PCT_APOSTROPHE 0x0007
#define PCT_LPAREN 0x0008
#define PCT_RPAREN 0x0009
#define PCT_COMMA 0x000C
#define PCT_DASH 0x000D
#define PCT_PERIOD 0x000E
#define PCT_SLASH 0x000F
#define PCT_COLON 0x001A
#define PCT_QUESTION 0x001F
#define PCT_LBRACKET 0x003B
#define PCT_RBRACKET 0x003D

// Numbers: 0x0010-0x0019 ('0'-'9')
#define NUM_0 0x0010
#define NUM_1 0x0011
#define NUM_2 0x0012
#define NUM_3 0x0013
#define NUM_4 0x0014
#define NUM_5 0x0015
#define NUM_6 0x0016
#define NUM_7 0x0017
#define NUM_8 0x0018
#define NUM_9 0x0019

// Uppercase: 0x0021-0x003A ('A'-'Z')
#define CHR_A 0x0021
#define CHR_B 0x0022
#define CHR_C 0x0023
#define CHR_D 0x0024
#define CHR_E 0x0025
#define CHR_F 0x0026
#define CHR_G 0x0027
#define CHR_H 0x0028
#define CHR_I 0x0029
#define CHR_J 0x002A
#define CHR_K 0x002B
#define CHR_L 0x002C
#define CHR_M 0x002D
#define CHR_N 0x002E
#define CHR_O 0x002F
#define CHR_P 0x0030
#define CHR_Q 0x0031
#define CHR_R 0x0032
#define CHR_S 0x0033
#define CHR_T 0x0034
#define CHR_U 0x0035
#define CHR_V 0x0036
#define CHR_W 0x0037
#define CHR_X 0x0038
#define CHR_Y 0x0039
#define CHR_Z 0x003A

// Lowercase: 0x0041-0x005A ('a'-'z')
#define CHR_a 0x0041
#define CHR_b 0x0042
#define CHR_c 0x0043
#define CHR_d 0x0044
#define CHR_e 0x0045
#define CHR_f 0x0046
#define CHR_g 0x0047
#define CHR_h 0x0048
#define CHR_i 0x0049
#define CHR_j 0x004A
#define CHR_k 0x004B
#define CHR_l 0x004C
#define CHR_m 0x004D
#define CHR_n 0x004E
#define CHR_o 0x004F
#define CHR_p 0x0050
#define CHR_q 0x0051
#define CHR_r 0x0052
#define CHR_s 0x0053
#define CHR_t 0x0054
#define CHR_u 0x0055
#define CHR_v 0x0056
#define CHR_w 0x0057
#define CHR_x 0x0058
#define CHR_y 0x0059
#define CHR_z 0x005A

// Control
#define CTR_BEGIN 0xFFBA
#define CTR_END 0xFFB9
#define CTR_NEWWINDOW 0xFFC1
#define CTR_WAITINPUT 0xFFC2
#define CTR_BUTTON 0xFFC3
#define CTR_NEWLINE 0xFFC4
#define CTR_CLOSE_BIG 0xFFC7
#define CTR_BIG 0xFFC8
#define CTR_CLOSE_BLINK 0xFFCD
#define CTR_BLINK 0xFFCE
#define CTR_UNKNOWN_FFDB 0xFFDB
#define CTR_EM_GREEN 0xFFDC
#define CTR_EM_BLUE 0xFFDD
#define CTR_EM_RED 0xFFDE
#define CTR_EM_YELLOW 0xFFDF
#define CTR_CLOSE_EM 0xFFE0
#define CTR_ENDLINE 0xFFFF

extern s32 D_8007785C_7845C; // g_scenario_character_portrait

extern s32 *D_800779A0_785A0[]; // g_scenario_codes;
extern s16 D_80078608_79208[];  // g_scenario_file_ids;

extern s32 D_801C7900_1C8500;
extern s32 D_801C7904_1C8504;

extern s32 D_801C7740_1C8340[]; // g_scenario_scratch_pad_0
extern s32 D_801C7758_1C8358;   // g_scenario_text_window_x_position
extern s32 D_801C775C_1C835C;   // g_scenario_text_window_y_position
extern s32 D_801C7768_1C8368;   // g_scenario_text_window_style
extern s32 D_801C7770_1C8370;
extern s32 D_801C7798_1C8398;
extern s32 D_801C77D8_1C83D8;

void func_8003D428_3E028();
s32 func_8003D468_3E068(s32 *scenario_code, s32 scenario_file_id);
s32 func_8003F1D8_3FDD8();
void func_8003F460_40060(); // scenario_wait_for_timer
void func_8003F594_40194(); // scenario_get_current_character
void func_8003F608_40208(); // scenario_play_sound

#endif // SCENARIO_H
