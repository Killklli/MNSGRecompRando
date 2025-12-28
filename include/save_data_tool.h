#ifndef SAVE_DATA_TOOL_H
#define SAVE_DATA_TOOL_H

#include "types.h"
#include "libc/stdio.h"
#include "libc/stdbool.h"

// External reference to the main data structure
extern u8 D_8015C608_15D208[0x304];

// Import rando data storage functions (from Archipelago.h)
extern u32 rando_get_datastorage_u32_sync(char* key);
extern void rando_set_datastorage_u32_sync(char* key, u32 value);
extern bool rando_is_connected();

// ================================================================================
// CORE MACROS FOR SAVE DATA MANIPULATION
// ================================================================================

// Write 32-bit values to save data at specified offset
#define WRITE_SAVE_DATA(offset, value) \
    do { \
        if (rando_is_connected()) { \
            char key[32]; \
            sprintf(key, "save_%ld", (long)(offset)); \
            rando_set_datastorage_u32_sync(key, (u32)(value)); \
        } \
        (*(s32 *)(D_8015C608_15D208 + (offset)) = (value)); \
    } while (0)

// Write 16-bit values to save data at specified offset
#define WRITE_SAVE_DATA_H(offset, value) \
    do { \
        if (rando_is_connected()) { \
            char key[32]; \
            sprintf(key, "save_h_%ld", (long)(offset)); \
            rando_set_datastorage_u32_sync(key, (u32)(value)); \
        } \
        (*(s16 *)(D_8015C608_15D208 + (offset)) = (value)); \
    } while (0)

// Write 8-bit values to save data at specified offset
#define WRITE_SAVE_DATA_B(offset, value) \
    do { \
        if (rando_is_connected()) { \
            char key[32]; \
            sprintf(key, "save_b_%ld", (long)(offset)); \
            rando_set_datastorage_u32_sync(key, (u32)(value)); \
        } \
        (*(u8 *)(D_8015C608_15D208 + (offset)) = (value)); \
    } while (0)

// Read 32-bit values from save data at specified offset
#define READ_SAVE_DATA(offset) \
    (*(s32 *)(D_8015C608_15D208 + (offset)))

// Read 16-bit values from save data at specified offset
#define READ_SAVE_DATA_H(offset) \
    (*(s16 *)(D_8015C608_15D208 + (offset)))

// Read 8-bit values from save data at specified offset
#define READ_SAVE_DATA_B(offset) \
    (*(u8 *)(D_8015C608_15D208 + (offset)))

// Set or clear individual flag bits
#define SET_FLAG_BIT(byte_offset, bit, value) \
    do { \
        if (value) { \
            (*(u8 *)(D_8015C608_15D208 + (byte_offset)) |= (1 << (bit))); \
        } else { \
            (*(u8 *)(D_8015C608_15D208 + (byte_offset)) &= ~(1 << (bit))); \
        } \
    } while (0)

// ================================================================================
// FLAG MANAGEMENT SYSTEM
// ================================================================================

// Enable a flag by its hexadecimal ID (e.g., 0x12A)
#define ENABLE_FLAG(flag_id) SET_FLAG_BIT((flag_id) / 8, (flag_id) % 8, 1)

// Disable a flag by its hexadecimal ID
#define DISABLE_FLAG(flag_id) SET_FLAG_BIT((flag_id) / 8, (flag_id) % 8, 0)

// Toggle a flag by its hexadecimal ID
#define TOGGLE_FLAG(flag_id) \
    do { \
        u8 byte_offset = (flag_id) / 8; \
        u8 bit = (flag_id) % 8; \
        (*(u8 *)(D_8015C608_15D208 + byte_offset) ^= (1 << bit)); \
    } while (0)

// Check if a flag is set
#define IS_FLAG_SET(flag_id) \
    ((*(u8 *)(D_8015C608_15D208 + ((flag_id) / 8)) & (1 << ((flag_id) % 8))) != 0)

// ================================================================================
// SAVE DATA SYNCHRONIZATION FUNCTIONS
// ================================================================================

// Sync a single save data value from datastore to memory
#define SYNC_SAVE_DATA_FROM_DATASTORE(offset) \
    do { \
        if (rando_is_connected()) { \
            char key[32]; \
            sprintf(key, "save_%ld", (long)(offset)); \
            u32 datastore_value = rando_get_datastorage_u32_sync(key); \
            if (datastore_value != 0) { \
                (*(s32 *)(D_8015C608_15D208 + (offset)) = (s32)datastore_value); \
            } \
        } \
    } while (0)

#define SYNC_SAVE_DATA_H_FROM_DATASTORE(offset) \
    do { \
        if (rando_is_connected()) { \
            char key[32]; \
            sprintf(key, "save_h_%ld", (long)(offset)); \
            u32 datastore_value = rando_get_datastorage_u32_sync(key); \
            if (datastore_value != 0) { \
                (*(s16 *)(D_8015C608_15D208 + (offset)) = (s16)datastore_value); \
            } \
        } \
    } while (0)

#define SYNC_SAVE_DATA_B_FROM_DATASTORE(offset) \
    do { \
        if (rando_is_connected()) { \
            char key[32]; \
            sprintf(key, "save_b_%ld", (long)(offset)); \
            u32 datastore_value = rando_get_datastorage_u32_sync(key); \
            if (datastore_value != 0) { \
                (*(u8 *)(D_8015C608_15D208 + (offset)) = (u8)datastore_value); \
            } \
        } \
    } while (0)

// Function to sync all save data from datastore to memory
// Call this when loading a save file or starting a new game
void sync_all_save_data_from_datastore(void);

// ================================================================================
// SPAWN COORDINATE SYSTEM
// ================================================================================

#define WRITE_SPAWN_ROOM(value) WRITE_SAVE_DATA_H(0x204, value)
#define WRITE_SPAWN_X(value) WRITE_SAVE_DATA_H(0x20A, value)
#define WRITE_SPAWN_Z(value) WRITE_SAVE_DATA_H(0x20C, value)
#define WRITE_SPAWN_Y(value) WRITE_SAVE_DATA_H(0x20E, value)
#define WRITE_SPAWN_CHARACTER(value) WRITE_SAVE_DATA(0x68, value)

// ================================================================================
// COMMON GAME FLAGS (FOR EASY REFERENCE)
// ================================================================================

// Story progression flags
#define FLAG_RECEIVED_SUPER_PASS 0x000 // Byte 0X00, Bit 0 - Switch -  Musical Castle 1 Big Aquarium
#define FLAG_OPENED_SUPER_PASS_GATE 0x001 // Byte 0X00, Bit 1
#define FLAG_OLD_MAN_SOUTH_OEDO 0x002 // Byte 0X00, Bit 2
#define FLAG_OMITSU_FAN 0x008 // Byte 0X01, Bit 0
#define FLAG_RECEIVED_MAP_JAPAN 0x009 // Byte 0X01, Bit 1
#define FLAG_HEARD_ZAZEN_DWARF 0x00A // Byte 0X01, Bit 2
#define FLAG_SPOKE_KOMPIRA_PRIEST 0x00B // Byte 0X01, Bit 3
#define FLAG_RECEIVED_SASUKE_BATTERY 0x00D // Byte 0X01, Bit 5
#define FLAG_RECRUITED_SASUKE 0x00E // Byte 0X01, Bit 6
#define FLAG_RECEIVED_CUCUMBER 0x00F // Byte 0X01, Bit 7

// Combat and magic flags
#define FLAG_RECEIVED_CHAIN_PIPE 0x010 // Byte 0X02, Bit 0
#define FLAG_MOKUBEI_UPGRADE_WEAPONS 0x011 // Byte 0X02, Bit 1
#define FLAG_UPGRADED_SILVER_WEAPONS 0x012 // Byte 0X02, Bit 2
#define FLAG_RECEIVED_FIRE_RYO 0x013 // Byte 0X02, Bit 3
#define FLAG_FREED_KORYUTA_DRAGON 0x014 // Byte 0X02, Bit 4
#define FLAG_MET_GHOST_WISE_MAN 0x015 // Byte 0X02, Bit 5
#define FLAG_SPOKE_TO_WITCH 0x016 // Byte 0X02, Bit 6
#define FLAG_KYUSHU_DISAPPEARED 0x017 // Byte 0X02, Bit 7
#define FLAG_DEFEATED_DHARMANYO 0x018 // Byte 0X03, Bit 0 - Invisible Wall That Blocks Doors Un Bridge to Bizen
#define FLAG_UPGRADED_GOLD_WEAPONS 0x01A // Byte 0X03, Bit 2
#define FLAG_SUDDEN_IMPACT_TRAINING 0x01B // Byte 0X03, Bit 3
#define FLAG_OBTAINED_SUDDEN_IMPACT 0x01C // Byte 0X03, Bit 4
#define FLAG_UNKNOWN_01D 0x01D // Byte 0X03, Bit 5
#define FLAG_OBTAINED_MERMAID_MAGIC 0x01F // Byte 0X03, Bit 7
#define FLAG_OBTAINED_SUPER_JUMP 0x020 // Byte 0X04, Bit 0
#define FLAG_SUPER_JUMP_TRAINING 0x021 // Byte 0X04, Bit 1
#define FLAG_KIHACHI_FAVORITE_FOOD 0x022 // Byte 0X04, Bit 2
#define FLAG_HEARD_KIHACHI_FROM_BENKEI 0x023 // Byte 0X04, Bit 3
#define FLAG_LEARNED_KIHACHI_FOOD 0x024 // Byte 0X04, Bit 4
#define FLAG_TALK_USHIWAKA_BENKEI 0x025 // Byte 0X04, Bit 5
#define FLAG_REJECTED_PRIEST_TRAINING 0x026 // Byte 0X04, Bit 6
#define FLAG_OBTAINED_KEY_TO_TRAINING 0x027 // Byte 0X04, Bit 7
#define FLAG_USHIWAKA_GOLDEN_TEMPLE 0x028 // Byte 0X05, Bit 0
#define FLAG_OBTAINED_ACHILLES_HEEL 0x029 // Byte 0X05, Bit 1
#define FLAG_LOOKING_RED_FISH 0x02A // Byte 0X05, Bit 2
#define FLAG_LOOKING_YELLOW_FISH 0x02B // Byte 0X05, Bit 3
#define FLAG_LOOKING_BLUE_FISH 0x02C // Byte 0X05, Bit 4
#define FLAG_ASKED_USHIWAKA_WHO 0x02D // Byte 0X05, Bit 5

// Character flags
#define FLAG_REJECTED_MINI_EBISU 0x030 // Byte 0X06, Bit 0
#define FLAG_OBTAINED_MINI_EBISU 0x031 // Byte 0X06, Bit 1
#define FLAG_DEFEATED_THAISAMBA 0x032 // Byte 0X06, Bit 2 - Invisible Wall That Blocks Doors Un Underwater
#define FLAG_DEFEATED_BENKEI 0x033 // Byte 0X06, Bit 3
#define FLAG_MET_BENKEI 0x034 // Byte 0X06, Bit 4
#define FLAG_OBTAINED_MIRACLE_SNOW 0x035 // Byte 0X06, Bit 5
#define FLAG_MERMAID_MAGIC_UNUSED 0x036 // Byte 0X06, Bit 6
#define FLAG_KIHACHI_FOOD_HINT 0x037 // Byte 0X06, Bit 7
#define FLAG_KIHACHI_GAVE_HINT 0x038 // Byte 0X07, Bit 0
#define FLAG_RECRUITED_YAE 0x03A // Byte 0X07, Bit 2
#define FLAG_SPOKE_PRIEST_SON 0x03B // Byte 0X07, Bit 3
#define FLAG_SUDDEN_IMPACT_FROM_PLASMA 0x03C // Byte 0X07, Bit 4
#define FLAG_ARRIVED_FOLKYPOKE_CENTER 0x03D // Byte 0X07, Bit 5
#define FLAG_SAW_CRACKED_DOOR 0x03E // Byte 0X07, Bit 6
#define FLAG_HEARD_INABA_BATTERY 0x03F // Byte 0X07, Bit 7
#define FLAG_DEFEATED_TSURAMI 0x040 // Byte 0X08, Bit 0
#define FLAG_HEARD_SILVER_FROM_PLASMA 0x041 // Byte 0X08, Bit 1
#define FLAG_PLASMA_SILVER_WEAPONS 0x042 // Byte 0X08, Bit 2
#define FLAG_PLASMA_FESTIVAL_VILLAGE 0x043 // Byte 0X08, Bit 3
#define FLAG_PLASMA_WATERFALL_KEGON 0x044 // Byte 0X08, Bit 4
#define FLAG_PLASMA_ASK_BENKEI_SNOW 0x045 // Byte 0X08, Bit 5
#define FLAG_PLASMA_NO_MORE_ADVICE 0x046 // Byte 0X08, Bit 6

// ================================================================================
// COMMON SAVE DATA OFFSETS (FOR ITEMS AND STATS)
// ================================================================================

// Character availability
#define SAVE_GOEMON_RECRUITED 0x94
#define SAVE_EBISUMARU_RECRUITED 0x98
#define SAVE_SASUKE_RECRUITED 0x9C
#define SAVE_YAE_RECRUITED 0xA0

// Weapon levels (0=Default, 1=Silver, 2=Gold)
#define SAVE_GOEMON_WEAPON_LEVEL 0xA4
#define SAVE_EBISUMARU_WEAPON_LEVEL 0xA8
#define SAVE_SASUKE_WEAPON_LEVEL 0xAC
#define SAVE_YAE_WEAPON_LEVEL 0xB0

// Special weapons/items
#define SAVE_CHAIN_PIPE 0xB4
#define SAVE_MEATSAW_HAMMER 0xB8
#define SAVE_FIRECRACKER_BOMB 0xBC
#define SAVE_FLUTE 0xC0
#define SAVE_GOEMON_RYO 0xC4
#define SAVE_WINDUP_CAMERA 0xC8
#define SAVE_ICE_KUNAI 0xCC
#define SAVE_BAZOOKA 0xD0

// Magic abilities
#define SAVE_SUDDEN_IMPACT_MAGIC 0xE4
#define SAVE_MINI_EBISU_MAGIC 0xE8
#define SAVE_SUPER_JUMP_MAGIC 0xEC
#define SAVE_MERMAID_MAGIC 0xF0

// Key items
#define SAVE_TRITON_SHELL 0xF4
#define SAVE_SUPER_PASS 0xF8
#define SAVE_FORTUNE_DOLL_PROGRESS 0xFC
#define SAVE_ACHILLES_HEEL 0x104
#define SAVE_KEY_ON_PAUSE 0x108
#define SAVE_QUALITY_CUCUMBER 0x10C

// Fish counts
#define SAVE_RED_FISH_COUNT 0x110
#define SAVE_YELLOW_FISH_COUNT 0x114
#define SAVE_BLUE_FISH_COUNT 0x118

// Miracle items
#define SAVE_MIRACLE_STAR 0x250
#define SAVE_MIRACLE_MOON 0x254
#define SAVE_MIRACLE_FLOWER 0x258
#define SAVE_MIRACLE_SNOW 0x25C

// Map and special items
#define SAVE_MAP_OF_JAPAN 0x268

// Warp points (0x2A4 - 0x2DC)
#define SAVE_WARP_GOEMON_HOUSE 0x2A4
#define SAVE_WARP_KAI_HIGHWAY 0x2A8
#define SAVE_WARP_OEDO_CASTLE 0x2AC
#define SAVE_WARP_ZAZEN_TOWN 0x2B0
#define SAVE_WARP_KII_COFFEE 0x2B4
#define SAVE_WARP_FOLKYPOKE_VILLAGE 0x2B8
#define SAVE_WARP_KOMPIRA_MOUNTAIN 0x2BC
#define SAVE_WARP_IYO_TEA_HOUSE 0x2C0
#define SAVE_WARP_GHOST_TOYS 0x2C4
#define SAVE_WARP_IZUMO_TEA_HOUSE 0x2C8
#define SAVE_WARP_FESTIVAL_TEMPLE 0x2CC
#define SAVE_WARP_FESTIVAL_VILLAGE 0x2D0
#define SAVE_WARP_WITCHES_HUT 0x2D4

// ================================================================================
// ADDITIONAL DOCUMENTED SAVE DATA OFFSETS
// ================================================================================

// Rice Ball system (negative offsets from base)
#define SAVE_CURRENT_RICE_BALL -0x18  // Values: 1,2,3
#define SAVE_RICE_BALL_AMOUNT_3 -0x14 // Values: 1,2,3
#define SAVE_RICE_BALL_AMOUNT_8 -0x10 // Values: 3,5,8

// Life system
#define SAVE_CURRENT_LIFE_TOTAL -0x1C // Current total lives (8015c5ec)

// Currency system
#define SAVE_RYO -0x20 // Current ryo/money (8015c5e8)

// Health system
#define SAVE_CURRENT_HEALTH -0x24 // Current HP (8015c5e4)
#define SAVE_TOTAL_HEALTH -0x28   // Maximum HP (8015c5e0)

// Character weapon systems (already defined above, but adding comments)
// 0x9C = Sasuke recruited, 0xA0 = Yae recruited
// 0xA4-0xB0 = Weapon levels for each character (0=Default, 1=Silver, 2=Gold)

// Special weapon charge abilities
#define SAVE_FIRE_RYO 0xD4
#define SAVE_CAMERA_CHARGEABLE 0xD8
#define SAVE_KUNAI_BEAM_CHARGEABLE 0xDC
#define SAVE_BAZOOKA_CHARGEABLE 0xE0

// Fortune doll system
#define SAVE_FORTUNE_DOLL_TOTAL 0x100

// Fish collection totals
#define SAVE_RED_FISH_TOTAL 0x110
#define SAVE_YELLOW_FISH_TOTAL 0x114
#define SAVE_BLUE_FISH_TOTAL 0x118

// Story progression markers
#define SAVE_UNKNOWN_WARP_214 0x214 - // Unknown, possibly warp related
#define SAVE_AFTER_DHARMANYO_218 0x218 -  // After defeating Dharmanyo
#define SAVE_AFTER_TSURAMI_21C 0x21C -  // After defeating Tsurami
#define SAVE_SUBMARINE_DESTRUCT_220 0x220 // After submarine self-destruct
#define SAVE_KYUSHU_TIME_BOMB_224 0x224 - // Reactivated time bomb on Kyushu

// Dead Sasuke system
#define SAVE_DEAD_SASUKE_PROFILE 0x260 // Sauske Status - 0 = body, 1 = battery 1, 2 = battery 2

// Mr. Elephant and Mr. Arrow item systems
#define SAVE_MR_ELLY_OEDO_CASTLE 0x26C
#define SAVE_MR_ELLY_GHOST_TOYS 0x270
#define SAVE_MR_ELLY_FESTIVAL_TEMPLE 0x274
#define SAVE_MR_ELLY_SUBMARINE 0x278
#define SAVE_MR_ELLY_MUSICAL 0x27C
#define SAVE_MR_ARROW_OEDO_CASTLE 0x280
#define SAVE_MR_ARROW_GHOST_TOYS 0x284
#define SAVE_MR_ARROW_FESTIVAL_TEMPLE 0x288
#define SAVE_MR_ARROW_SUBMARINE 0x28C
#define SAVE_MR_ARROW_MUSICAL 0x290
#define SAVE_LORDS_SUPERPASS 0x294

// Submarine castle map
#define SAVE_SUBMARINE_CASTLE_MAP 0x2D8

// Key-related system (5 different key types)
#define SAVE_KEY_RELATED_1 0x2F0
#define SAVE_KEY_RELATED_2 0x2F4
#define SAVE_KEY_RELATED_3 0x2F8
#define SAVE_KEY_RELATED_4 0x2FC
#define SAVE_KEY_RELATED_5 0x300

// Cutscene and special event flags
#define SAVE_KITTY_DANCIN_SPACE 0x610 -  // Kitty and Dancin blasting off cutscene
#define SAVE_BARON_SPINNING_IMPACT 0x614 // Baron spinning away impact cutscene
#define SAVE_KYUSHU_TIME_BOMB_FLAG 0x618 // Time bomb on Kyushu flag

// Shop system
#define SAVE_IN_SHOP_FLAG 0x7DC // Values: 0,1,2 for different shop types

// ================================================================================
// ADDITIONAL GAME FLAGS FROM DOCUMENTATION
// ================================================================================

// Memory Pak flags
#define FLAG_NOT_USING_MEMORY_PAK 0x047 // Byte 0X08, Bit 7
#define FLAG_MEMORY_PAK_1 0x048 // Byte 0X09, Bit 0
#define FLAG_MEMORY_PAK_2 0x049 // Byte 0X09, Bit 1
#define FLAG_MEMORY_PAK_3 0x04A // Byte 0X09, Bit 2
#define FLAG_MEMORY_PAK_4 0x04B // Byte 0X09, Bit 3
#define FLAG_MEMORY_PAK_5 0x04C // Byte 0X09, Bit 4
#define FLAG_MEMORY_PAK_6 0x04D // Byte 0X09, Bit 5
#define FLAG_MEMORY_PAK_7 0x06D // Byte 0X0D, Bit 5
#define FLAG_STRENGTH_GAUGE_INCREASING 0x04E // Byte 0X09, Bit 6
#define FLAG_CANNOT_CATCH_BLUE_FISH 0x04F // Byte 0X09, Bit 7
#define FLAG_CANNOT_CATCH_YELLOW_FISH 0x050 // Byte 0X0A, Bit 0
#define FLAG_CANNOT_CATCH_RED_FISH 0x051 // Byte 0X0A, Bit 1

// Character interaction flags
#define FLAG_GOEMON_TENEMENTS_1 0x052 // Byte 0X0A, Bit 2
#define FLAG_GOEMON_TENEMENTS_2 0x053 // Byte 0X0A, Bit 3
#define FLAG_GOEMON_TENEMENTS_3 0x054 // Byte 0X0A, Bit 4
#define FLAG_GOEMON_TENEMENTS_4 0x055 // Byte 0X0A, Bit 5
#define FLAG_OLD_WOMAN_BEFORE_DHARMANYO 0x056 // Byte 0X0A, Bit 6
#define FLAG_OLD_WOMAN_AFTER_DHARMANYO 0x057 // Byte 0X0A, Bit 7
#define FLAG_OLD_WOMAN_BOTH_TIMES 0x058 // Byte 0X0B, Bit 0
#define FLAG_OLD_WOMAN_REWARD 0x059 // Byte 0X0B, Bit 1

// Shopping and service flags
#define FLAG_BUYING_1ST_ITEM 0x05A // Byte 0X0B, Bit 2
#define FLAG_BUYING_2ND_ITEM 0x05B // Byte 0X0B, Bit 3
#define FLAG_BUYING_3RD_ITEM 0x05C // Byte 0X0B, Bit 4
#define FLAG_USING_TOURISM_SERVICE 0x05D // Byte 0X0B, Bit 5
#define FLAG_UNKNOWN_05E 0x05E // Byte 0X0B, Bit 6

// Story progression flags
#define FLAG_HEARD_DRAGON_PROBLEM 0x063 // Byte 0X0C, Bit 3
#define FLAG_TOURIST_CENTER_GRATITUDE 0x064 // Byte 0X0C, Bit 4
#define FLAG_TALKED_SON_NO_CUCUMBER 0x065 // Byte 0X0C, Bit 5
#define FLAG_HEARD_WISE_MAN_FROM_OMITSU 0x066 // Byte 0X0C, Bit 6
#define FLAG_LOST_TO_BENKEI 0x067 // Byte 0X0C, Bit 7
#define FLAG_SASUKE_SECRET_FROM_WITCH 0x068 // Byte 0X0D, Bit 0
#define FLAG_WENT_TO_OUTER_SPACE 0x06B // Byte 0X0D, Bit 3
#define FLAG_GOING_TO_OUTER_SPACE 0x06C // Byte 0X0D, Bit 4
#define FLAG_SPOKE_TO_DANCIN_ALNITE 0x06E // Byte 0X0D, Bit 6
#define FLAG_MET_BARON_IN_IGA 0x06F // Byte 0X0D, Bit 7

// Cutscene flags
#define FLAG_AFTER_DHARMANYO_2 0x070 // Byte 0X0E, Bit 0
#define FLAG_AFTER_DHARMANYO_3 0x071 // Byte 0X0E, Bit 1
#define FLAG_AFTER_DHARMANYO_4 0x072 // Byte 0X0E, Bit 2
#define FLAG_AFTER_DHARMANYO_1 0x073 // Byte 0X0E, Bit 3
#define FLAG_AFTER_TSURAMI_CUTSCENE 0x074 // Byte 0X0E, Bit 4
#define FLAG_GORGEOUS_STAGE_2 0x075 // Byte 0X0E, Bit 5
#define FLAG_GORGEOUS_STAGE_1 0x076 // Byte 0X0E, Bit 6
#define FLAG_SOGEN_GIRL_LILY 0x077 // Byte 0X0E, Bit 7
#define FLAG_SOGEN_GIRL_DANCIN 0x078 // Byte 0X0F, Bit 0
#define FLAG_STARTED_SUDDEN_SUPER_MINI 0x079 // Byte 0X0F, Bit 1
#define FLAG_STARTED_BENKEI_MERMAID 0x07A // Byte 0X0F, Bit 2
#define FLAG_FIGHT_COLON_MIND_CONTROL 0x07B // Byte 0X0F, Bit 3
#define FLAG_WITCH_CUTSCENE_1 0x07C // Byte 0X0F, Bit 4
#define FLAG_STARTED_MINI_EBISU_MINI 0x07D // Byte 0X0F, Bit 5
#define FLAG_REJECTED_LORD_OEDO 0x07E // Byte 0X0F, Bit 6
#define FLAG_RIDING_DRAGON_FOLKYPOKE 0x07F // Byte 0X0F, Bit 7
#define FLAG_PLASMA_RESURRECT_SASUKE 0x080 // Byte 0X10, Bit 0
#define FLAG_REJECTED_MINI_EBISU_UNUSED 0x081 // Byte 0X10, Bit 1
#define FLAG_MONEY_HANDLING 0x082 // Byte 0X10, Bit 2

// Special flags from new documentation
#define FLAG_UNKNOWN_083 0x083 // Byte 0X10, Bit 3
#define FLAG_TOURIST_CENTER_RELATED 0x098 // Byte 0X13, Bit 0
#define FLAG_BARON_CUTSCENE_WISE_MAN 0x099 // Byte 0X13, Bit 1
#define FLAG_WITCH_CUTSCENE_2 0x09C // Byte 0X13, Bit 4
#define FLAG_WITCH_CUTSCENE_3 0x09D // Byte 0X13, Bit 5
#define FLAG_WITCH_CUTSCENE_4 0x09E // Byte 0X13, Bit 6
#define FLAG_WITCH_CUTSCENE_5 0x09F // Byte 0X13, Bit 7
#define FLAG_WITCH_CUTSCENE_6 0x0A0 // Byte 0X14, Bit 0
#define FLAG_UNKNOWN_0A3 0x0A3 // Byte 0X14, Bit 3
#define FLAG_UNKNOWN_0A4 0x0A4 // Byte 0X14, Bit 4 - Invisible Wall That Blocks Doors Un Oedo Castle 2F Congo Boss Room

// Shrine and special area flags
#define FLAG_TURTLE_SHRINE_RYO 0x0C5 // Byte 0X18, Bit 5
#define FLAG_TURTLE_SHRINE_DOLL_SPAWN 0x0C6 // Byte 0X18, Bit 6
#define FLAG_TURTLE_SHRINE_YAMATO 0x0C7 // Byte 0X18, Bit 7 - Invisible Wall That Blocks Doors
#define FLAG_TURTLE_SHRINE_RED_GATE 0x0C8 // Byte 0X19, Bit 0
#define FLAG_UNLOCK_YAMATO_SHRINE 0x0C9 // Byte 0X19, Bit 1

// Game mechanics flags
#define FLAG_BEAT_CONGO 0x012D // Byte 0X25, Bit 5
#define FLAG_EVERY_4_TICKS 0x012E // Byte 0X25, Bit 6
#define FLAG_CONGO_BOSS_INTRO 0x0133 // Byte 0X26, Bit 3
#define FLAG_UNKNOWN_0154 0x0154 // Byte 0X2A, Bit 4
#define FLAG_UNKNOWN_0155 0x0155 // Byte 0X2A, Bit 5
#define FLAG_CRANE_POWER_ON 0x015A // Byte 0X2B, Bit 2
#define FLAG_CRANE_POWER_OFF_TEXT 0x015B // Byte 0X2B, Bit 3
#define FLAG_CRANE_GAME_ENTERED 0x015C // Byte 0X2B, Bit 4
#define FLAG_GRABBED_CAMERA 0x015E // Byte 0X2B, Bit 6
#define FLAG_CAMERA_ON_BELT 0x015F // Byte 0X2B, Bit 7
#define FLAG_UNKNOWN_0165 0x0165 // Byte 0X2C, Bit 5
#define FLAG_UNKNOWN_0167 0x0167 // Byte 0X2C, Bit 7
#define FLAG_UNKNOWN_016A 0x016A // Byte 0X2D, Bit 2
#define FLAG_UNKNOWN_0175 0x0175 // Byte 0X2E, Bit 5
#define FLAG_GOEMON_LETS_GO_START 0x0199 // Byte 0X33, Bit 1
#define FLAG_DOOR_RELATED_19A 0x019A // Byte 0X33, Bit 2
#define FLAG_DOOR_RELATED_19B 0x019B // Byte 0X33, Bit 3
#define FLAG_DOOR_RELATED_19C 0x019C // Byte 0X33, Bit 4 - Invisible Wall That Blocks Doors Un Ghost Toys Entrance
#define FLAG_UNKNOWN_019E 0x019E // Byte 0X33, Bit 6
#define FLAG_COLLECTED_CAMERA_MINIGAME 0x01A3 // Byte 0X34, Bit 3
#define FLAG_UNKNOWN_01A4 0x01A4 // Byte 0X34, Bit 4
#define FLAG_GOT_YAE_BAZOOKA 0x01A5 // Byte 0X34, Bit 5
#define FLAG_COLLECTED_MEAT_HAMMER 0x01A6 // Byte 0X34, Bit 6
#define FLAG_SHUHUDO_TUNNEL_BLOWN 0x01C3 // Byte 0X38, Bit 3
#define FLAG_CRANE_GAME_HELP_TEXT 0x01C4 // Byte 0X38, Bit 4
#define FLAG_BOUGHT_DHARMA_CAT_EYES 0x1C5 // Byte 0X38, Bit 5
#define FLAG_BOUGHT_NOTICE_CAT_EYES 0x1C6 // Byte 0X38, Bit 6
#define FLAG_BOUGHT_DOLL_CAT_EYES 0x1C7 // Byte 0X38, Bit 7

// ================================================================================
// KEYS AND LOCKS SYSTEM
// ================================================================================

// Key flags (items that unlock doors)
#define KEY_SILVER_OEDO_CASTLE_1F_TILE 0x010A // Byte 0X21, Bit 2 - Oedo Castle 1F Tile Room
#define KEY_SILVER_OEDO_CASTLE_1F 0x010C // Byte 0X21, Bit 4 - Oedo Castle 1F Swatting Robot Silver Key Room
#define KEY_SILVER_OEDO_CASTLE_1F_CHAIN_PIPE 0x0110 // Byte 0X22, Bit 0 - Oedo Castle 1F Chain Pipe Key Room
#define KEY_GOLD_OEDO_CASTLE_1F 0x010E // Byte 0X21, Bit 6 - Oedo Castle 1F Swatting Robot Gold Key Room
#define KEY_SILVER_OEDO_CASTLE_2F_CRUSHER 0x0112 // Byte 0X22, Bit 2 - Oedo Castle 2F Crusher Key Room
#define KEY_SILVER_OEDO_CASTLE_2F 0x0114 // Byte 0X22, Bit 4 - Oedo Castle 2F Silver Key Room
#define KEY_SILVER_CONGO_BOSS_UNUSED 0x011A // Byte 0X23, Bit 2 - Congo Boss Room - Unused
#define KEY_SILVER_GHOST_TOYS_1F_CRANE 0x01AF // Byte 0X35, Bit 7 - Ghost Toys 1F Crane Room
#define KEY_SILVER_GHOST_TOYS_1F_FLOWER 0x01AD // Byte 0X35, Bit 5 - Ghost Toys 1F Flower Blooming Key Room
#define KEY_SILVER_GHOST_TOYS_1F_INVISIBLE 0x01B1 // Byte 0X36, Bit 1 - Ghost Toys 1F Invisible Ghost Key Room
#define KEY_SILVER_GHOST_TOYS_2F_SPINNING 0x01B3 // Byte 0X36, Bit 3 - Ghost Toys 2F Spinning Top Key Room
#define KEY_SILVER_GHOST_TOYS_2F_DARUMANYO 0x01B5 // Byte 0X36, Bit 5 - Ghost Toys 2F Invisible Darumanyo Key Room
#define KEY_GOLD_GHOST_TOYS_2F_FALSE_FLOOR 0x01B7 // Byte 0X36, Bit 7 - Ghost Toys 2F False Floor Gold Key Room
#define KEY_SILVER_GHOST_TOYS_2F_BILLIARDS 0x01BB // Byte 0X37, Bit 3 - Ghost Toys 2F Billiards Room
#define KEY_DIAMOND_GHOST_TOYS_2F_SPIKE_CANNON 0x01B9 // Byte 0X37, Bit 1 - Ghost Toys 2F Spike Cannon Diamond Key Room
#define KEY_GOLD_FESTIVAL_TEMPLE_HOT 0x016E // Byte 0X2D, Bit 6 - Festival Temple West Hot Platform Gold Key Room
#define KEY_SILVER_FESTIVAL_TEMPLE_RING 0x0171 // Byte 0X2E, Bit 1 - Festival Temple Central Ring Key Hallway

#define KEY_SILVER_GOURMET_SUB_2F_BAZOOKA 0x017B // Byte 0X2F, Bit 3 - Gourmet Sub 2F Bazooka Room
#define KEY_GOLD_GOURMET_SUB_2F_JETPACK 0x017D // Byte 0X2F, Bit 5 - Gourmet Sub 2F Jetpack Crab Gold Key & Double Lock
#define KEY_SILVER_GOURMET_SUB_2F_LAVA 0x017F // Byte 0X2F, Bit 7 - Gourmet Sub 2F Lava Treadmill Key & Lock Room
#define KEY_SILVER_GOURMET_SUB_2F_UNDERWATER 0x0181 // Byte 0X30, Bit 1 - Gourmet Sub 2F Underwater Spiny Key & Lock Room
#define KEY_DIAMOND_GOURMET_SUB_3F_INVISIBLE 0x0185 // Byte 0X30, Bit 5 - Gourmet Sub 3F Invisible Path Diamond Key Room
#define KEY_SILVER_GOURMET_SUB_3F_SWORD 0x0183 // Byte 0X30, Bit 3 - Gourmet Sub 3F Sword Robot Key Room
#define KEY_SILVER_GOURMET_SUB_3F_SUSHI 0x0187 // Byte 0X30, Bit 7 - Gourmet Sub 3F Sushi Belt Silver Key Room
#define KEY_SILVER_MUSICAL_CASTLE_1_TALL 0x018B // Byte 0X31, Bit 3 - Musical Castle 1 Tall Key & Lock Room
#define KEY_GOLD_MUSICAL_CASTLE_1_FAN 0x0189 // Byte 0X31, Bit 1 - Musical Castle 1 Gold Key Fan Room
#define KEY_GOLD_MUSICAL_CASTLE_1_HIGH_JUMP 0x018C // Byte 0X31, Bit 4 - Musical Castle 1 High Jump Gold Key Waves Room
#define KEY_DIAMOND_MUSICAL_CASTLE_1_CUBE 0x0191 // Byte 0X32, Bit 1 - Musical Castle 1 B1F Rotating Cube Diamond Key Roo
#define KEY_GOLD_MUSICAL_CASTLE_1_MINI 0x018F // Byte 0X31, Bit 7 - Musical Castle 1 Mini Gold Key Big Wave Generator
#define KEY_DIAMOND_MUSICAL_CASTLE_2 0x0193 // Byte 0X32, Bit 3 - Invisible Wall That Blocks Doors Un Musical Castle 2 Diamond Key P

// Lock flags (doors that need keys)
#define LOCK_SILVER_OEDO_CASTLE_1F_TILE 0x0109 // Byte 0X21, Bit 1 - Oedo Castle 1F Tile Room
#define LOCK_GOLD_OEDO_CASTLE_1F_FORK 0x010D // Byte 0X21, Bit 5 - Oedo Castle 1F Chain Pipe Fork
#define LOCK_SILVER_OEDO_CASTLE_1F_CHAIN_PIPE 0x010F // Byte 0X21, Bit 7 - Oedo Castle 1F Chain Pipe Key Room
#define LOCK_SILVER_OEDO_CASTLE_1F_TURTLE 0x010B // Byte 0X21, Bit 3 - Oedo Castle 1F Turtle Pad Room
#define LOCK_SILVER_OEDO_CASTLE_2F_CRUSHER 0x0111 // Byte 0X22, Bit 1 - Oedo Castle 2F Crusher Key Room
#define LOCK_SILVER_OEDO_CASTLE_2F_SPIKE 0x0113 // Byte 0X22, Bit 3 - Oedo Castle 2F Spike Chain Room
#define LOCK_SILVER_GHOST_TOYS_1F_FLOWER 0x01AC // Byte 0X35, Bit 4 - Ghost Toys 1F Flower Blooming Key Room
#define LOCK_SILVER_GHOST_TOYS_1F_SHOGI 0x01AE // Byte 0X35, Bit 6 - Ghost Toys 1F Shogi Cannon Gold Cat Room
#define LOCK_SILVER_GHOST_TOYS_1F_SPIKE_DAR 0x01B0 // Byte 0X36, Bit 0 - Ghost Toys 1F Spike Darumanyo Room
#define LOCK_SILVER_GHOST_TOYS_1F_2F_ELEVATOR 0x01B2 // Byte 0X36, Bit 2 - Ghost Toys 1F-2F Elevator / Tiny Darumanyo Room
#define LOCK_GOLD_GHOST_TOYS_2F_BIG_SPIKE_1 0x01B6 // Byte 0X36, Bit 6 - Ghost Toys 2F Big Spinning Spike Chain Room
#define LOCK_SILVER_GHOST_TOYS_2F_BIG_SPIKE_2 0x01B4 // Byte 0X36, Bit 4 - Ghost Toys 2F Big Spinning Spike Chain Room
#define LOCK_DIAMOND_GHOST_TOYS_2F 0x01B8 // Byte 0X37, Bit 0 - Ghost Toys 2F Darumanyo Diamond Lock Room
#define LOCK_SILVER_GHOST_TOYS_2F_BILLIARDS 0x01BA // Byte 0X37, Bit 2 - Ghost Toys 2F Billiards Room
#define LOCK_SILVER_FESTIVAL_TEMPLE_FORK 0x0170 // Byte 0X2E, Bit 0 - Festival Temple East Silver Cat Lock Fork
#define LOCK_GOLD_FESTIVAL_TEMPLE 0x016F // Byte 0X2D, Bit 7 - Festival Temple Central Gold Lock Room
#define LOCK_GOLD_GOURMET_SUB_2F_JETPACK_1 0x017C // Byte 0X2F, Bit 4 - Gourmet Sub 2F Jetpack Crab Gold Key & Double Lock
#define LOCK_SILVER_GOURMET_SUB_2F_JETPACK_2 0x017A // Byte 0X2F, Bit 2 - Gourmet Sub 2F Jetpack Crab Gold Key & Double Lock
#define LOCK_SILVER_GOURMET_SUB_2F_LAVA 0x017E // Byte 0X2F, Bit 6 - Gourmet Sub 2F Lava Treadmill Key & Lock Room
#define LOCK_SILVER_GOURMET_SUB_2F_UNDERWATER 0x0180 // Byte 0X30, Bit 0 - Gourmet Sub 2F Underwater Spiny Key & Lock Room
#define LOCK_DIAMOND_GOURMET_SUB_3F_FOX_1 0x0184 // Byte 0X30, Bit 4 - Gourmet Sub 3F Fox Ramen Platforms & Diamond Lock
#define LOCK_SILVER_GOURMET_SUB_3F_FOX_2 0x0182 // Byte 0X30, Bit 2 - Gourmet Sub 3F Fox Ramen Platforms & Diamond Lock
#define LOCK_SILVER_GOURMET_SUB_3F_TOFU 0x0186 // Byte 0X30, Bit 6 - Gourmet Sub 3F Floating Tofu Silver Lock Room
#define LOCK_GOLD_MUSICAL_CASTLE_1_ENTRANCE 0x0188 // Byte 0X31, Bit 0 - Musical Castle 1 Entrance
#define LOCK_SILVER_MUSICAL_CASTLE_1_TALL 0x018A // Byte 0X31, Bit 2 - Musical Castle 1 Tall Key & Lock Room
#define LOCK_GOLD_MUSICAL_CASTLE_1_FAN 0x018D // Byte 0X31, Bit 5 - Musical Castle 1 Gold Lock Fan Room
#define LOCK_GOLD_MUSICAL_CASTLE_1_MULTI_1 0x018E // Byte 0X31, Bit 6 - Musical Castle 1 Multi-Lock 3-Way Fork
#define LOCK_DIAMOND_MUSICAL_CASTLE_1_MULTI_2 0x0190 // Byte 0X32, Bit 0 - Musical Castle 1 Multi-Lock 3-Way Fork
#define LOCK_DIAMOND_MUSICAL_CASTLE_2_ENTRANCE 0x0192 // Byte 0X32, Bit 2 - Musical Castle 2 Entrance
#define LOCK_SPECIAL_BIZEN 0x0196 // Byte 0X32, Bit 6 - Musical Castle 2 B1F Gorgeous Stage

// ================================================================================
// COLLECTIBLE ITEMS SYSTEM
// ================================================================================

// Switches and special items
#define ITEM_SWITCH_MUSICAL_AQUARIUM 0x0000 // Byte 0X00, Bit 0 - Switch -  Musical Castle 1 Big Aquarium
#define ITEM_WALL_BRIDGE_BIZEN 0x0018 // Byte 0X03, Bit 0 - Invisible Wall That Blocks Doors Un Bridge to Bizen
#define ITEM_WALL_UNDERWATER 0x0032 // Byte 0X06, Bit 2 - Invisible Wall That Blocks Doors Un Underwater
#define ITEM_WALL_OEDO_CONGO_BOSS 0x00A4 // Byte 0X14, Bit 4 - Invisible Wall That Blocks Doors Un Oedo Castle 2F Congo Boss Room
#define ITEM_WALL_YAMATO 0x00C7 // Byte 0X18, Bit 7 - Invisible Wall That Blocks Doors Un Yamato

// Silver Dolls (0x00CA - 0x00F1)
#define SILVER_DOLL_TURTLE_ROCK 0x00E0 // Byte 0X1C, Bit 0
#define SILVER_DOLL_OEDO_TURTLE 0x00CA // Byte 0X19, Bit 2 - Silver Doll - Oedo Castle 1F Turtle Pad Room
#define SILVER_DOLL_OEDO_SILVER_CAT 0x00CB // Byte 0X19, Bit 3 - Silver Doll - Oedo Castle 2F Silver Cat Room
#define SILVER_DOLL_OEDO_BLOCKED 0x00CC // Byte 0X19, Bit 4 - Silver Doll - Oedo Castle 2F Blocked Silver
#define SILVER_DOLL_OEDO_ELEVATOR 0x00CD // Byte 0X19, Bit 5 - Silver Doll - Oedo Castle 2F-3F Elevator / B
#define SILVER_DOLL_GHOST_ELEVATOR 0x00CE // Byte 0X19, Bit 6 - Silver Doll - Ghost Toys 1F Elevator Shogi R
#define SILVER_DOLL_GHOST_CRANE 0x00CF // Byte 0X19, Bit 7 - Silver Doll - Ghost Toys 1F Crane Room
#define SILVER_DOLL_GHOST_CANNON 0x00D0 // Byte 0X1A, Bit 0 - Silver Doll - Ghost Toys 1F Cannon Room
#define SILVER_DOLL_GHOST_BIG_SPIKE 0x00D1 // Byte 0X1A, Bit 1 - Silver Doll - Ghost Toys 2F Big Spinning Spi
#define SILVER_DOLL_FESTIVAL_SILVER_CAT 0x00D2 // Byte 0X1A, Bit 2 - Silver Doll - Festival Temple East Silver Ca
#define SILVER_DOLL_FESTIVAL_RING 0x00D3 // Byte 0X1A, Bit 3 - Silver Doll - Festival Temple Central Ring K
#define SILVER_DOLL_FESTIVAL_ICE_KUNAI 0x00D4 // Byte 0X1A, Bit 4 - Silver Doll - Festival Temple East Ice Kunai
#define SILVER_DOLL_FESTIVAL_FISH_KIT 0x00D5 // Byte 0X1A, Bit 5 - Silver Doll - Festival Temple North Fish Kit
#define SILVER_DOLL_MUSICAL_GOLD_FAN 0x00D6 // Byte 0X1A, Bit 6 - Silver Doll - Musical Castle 1 Gold Lock Fan
#define SILVER_DOLL_MUSICAL_MULTI_LOCK 0x00D7 // Byte 0X1A, Bit 7 - Silver Doll - Musical Castle 1 Multi-Lock 3-
#define SILVER_DOLL_MUSICAL_BIG_AQUA 0x00D8 // Byte 0X1B, Bit 0 - Silver Doll - Musical Castle 1 Big Aquarium
#define SILVER_DOLL_MUSICAL_DESCENT 0x00D9 // Byte 0X1B, Bit 1 - Silver Doll - Musical Castle 2 B1F Descent
#define SILVER_DOLL_KAI_HIGHWAY 0x00DA // Byte 0X1B, Bit 2 - Silver Doll - Kai Highway
#define SILVER_DOLL_MT_FUJI 0x00DB // Byte 0X1B, Bit 3 - Silver Doll - Mt. Fuji
#define SILVER_DOLL_MUSASHI 0x00DC // Byte 0X1B, Bit 4 - Silver Doll - Musashi
#define SILVER_DOLL_YAMATO_UPPER 0x00DD // Byte 0X1B, Bit 5 - Silver Doll - Yamato Shrine Upper
#define SILVER_DOLL_YAMATO_LOWER 0x00DE // Byte 0X1B, Bit 6 - Silver Doll - Yamato Shrine Lower
#define SILVER_DOLL_YAMATO_UNDERWATER 0x00DF // Byte 0X1B, Bit 7 - Silver Doll - Yamato - Underwater Cave
#define SILVER_DOLL_KII_AWAJI 0x00E1 // Byte 0X1C, Bit 1 - Silver Doll - Kii-Awaji Island
#define SILVER_DOLL_HUSBAND_WIFE_ROCKS 0x00E2 // Byte 0X1C, Bit 2 - Silver Doll - Husband and Wife Rocks
#define SILVER_DOLL_IGA_VINE 0x00E3 // Byte 0X1C, Bit 3 - Silver Doll - Iga - Vine Bridge
#define SILVER_DOLL_DOGO_HOT_SPRINGS 0x00E4 // Byte 0X1C, Bit 4 - Silver Doll - Dogo Hot Springs
#define SILVER_DOLL_BIZEN 0x00E5 // Byte 0X1C, Bit 5 - Silver Doll - Bizen
#define SILVER_DOLL_NAGATO_MINI_EBI 0x00E6 // Byte 0X1C, Bit 6 - Silver Doll - Nagato Mini Ebisumaru
#define SILVER_DOLL_NAGATO_GATE 0x00E7 // Byte 0X1C, Bit 7 - Silver Doll - Nagato On top of Gate
#define SILVER_DOLL_INABA 0x00E8 // Byte 0X1D, Bit 0 - Silver Doll - Inaba
#define SILVER_DOLL_JAPAN_SEA 0x00E9 // Byte 0X1D, Bit 1 - Silver Doll - Japan Sea - Underwater
#define SILVER_DOLL_NORTHEAST_TUNNEL 0x00EA // Byte 0X1D, Bit 2 - Silver Doll - Northeast Tunnel to Festival V
#define SILVER_DOLL_UZEN_TUNNEL 0x00EB // Byte 0X1D, Bit 3 - Silver Doll - Uzen Tunnel
#define SILVER_DOLL_OEDO_BRIDGE_MUSASHI 0x00EC // Byte 0X1D, Bit 4 - Silver Doll - Oedo Town - Bridge to Musashi
#define SILVER_DOLL_OEDO_PATH_CASTLE 0x00ED // Byte 0X1D, Bit 5 - Silver Doll - Oedo Town - Path to Oedo Castl
#define SILVER_DOLL_ZAZEN_WATERWAY 0x00EF // Byte 0X1D, Bit 7 - Silver Doll - Zazen Waterway
#define SILVER_DOLL_FOLKYPOKE_EAST 0x00F0 // Byte 0X1E, Bit 0 - Silver Doll - Folkypoke Village (East)
#define SILVER_DOLL_FESTIVAL_HIDDEN 0x00F1 // Byte 0X1E, Bit 1 - Silver Doll - Festival Village - Hidden Lake
#define SILVER_DOLL_WATERING_HOLE 0x00EE // Byte 0X1D, Bit 6 - Silver Doll - Zazen Watering Hole

// Gold Dolls
#define GOLD_DOLL_GHOST_SHOGI_CANNON 0x00F2 // Byte 0X1E, Bit 2 - Gold Doll - Ghost Toys 1F Shogi Cannon Gol
#define GOLD_DOLL_FESTIVAL_WEST_GOLD 0x00F3 // Byte 0X1E, Bit 3 - Gold Doll - Festival Temple West Gold Cat
#define GOLD_DOLL_MUSICAL_2_GOLD_CAT 0x00F4 // Byte 0X1E, Bit 4 - Gold Doll - Musical Castle 2 Gold Cat Hall
#define GOLD_DOLL_BIZEN 0x00F5 // Byte 0X1E, Bit 5 - Gold Doll - Bizen
#define GOLD_DOLL_WATERFALL_KEGON 0x00F6 // Byte 0X1E, Bit 6 - Gold Doll - Waterfall of Kegon

// Surprise Packs (Extra Lives)
#define SURPRISE_PACK_GHOST_FALSE_FLOOR 0x00F7 // Byte 0X1E, Bit 7 - Surprise Pack (Extra Life) -  Ghost Toys 2F False Floor Gold
#define SURPRISE_PACK_FESTIVAL_TANK 0x00F8 // Byte 0X1F, Bit 0 - Surprise Pack (Extra Life) -  Festival Temple East Tank Hall
#define SURPRISE_PACK_GOURMET_BLASTER 0x00F9 // Byte 0X1F, Bit 1 - Surprise Pack (Extra Life) -  Gourmet Sub 3F Blaster Crab Ro
#define SURPRISE_PACK_GOURMET_JETPACK 0x00FA // Byte 0X1F, Bit 2 - Surprise Pack (Extra Life) -  Gourmet Sub 2F Jetpack Crab Go
#define SURPRISE_PACK_MUSICAL_AQUARIUM 0x00FB // Byte 0X1F, Bit 3 - Surprise Pack (Extra Life) -  Musical Castle 1 Big Aquarium
#define SURPRISE_PACK_YAMATO_SHRINE 0x00FC // Byte 0X1F, Bit 4 - Surprise Pack (Extra Life) -  Yamato Shrine
#define SURPRISE_PACK_KII_AWAJI 0x00FD // Byte 0X1F, Bit 5 - Surprise Pack (Extra Life) -  Kii-Awaji Island
#define SURPRISE_PACK_UNDERWATER 0x00FE // Byte 0X1F, Bit 6 - Surprise Pack (Extra Life) - Japan Sea Underwater

// Mr. Elly Fant items
#define MR_ELLY_FANT_OEDO_TURTLE 0x00FF // Byte 0X1F, Bit 7 - Mr. Elly Fant - Oedo Castle 1F Turtle Pad Room
#define MR_ELLY_FANT_GHOST_SPIKE 0x0100 // Byte 0X20, Bit 0 - Mr. Elly Fant - Ghost Toys 1F Spike Cannon Boa
#define MR_ELLY_FANT_FESTIVAL_SPIKE 0x0101 // Byte 0X20, Bit 1 - Mr. Elly Fant - Festival Temple West Spike Cha
#define MR_ELLY_FANT_GOURMET_ENTRANCE 0x0102 // Byte 0X20, Bit 2 - Mr. Elly Fant - Gourmet Sub 1F-3F Entrance / E
#define MR_ELLY_FANT_MUSICAL_HIGH_JUMP 0x0103 // Byte 0X20, Bit 3 - Mr. Elly Fant - Musical Castle 1 High Jump Gol

// Mr. Arrow items
#define MR_ARROW_OEDO_SPIKE_CHAIN 0x0104 // Byte 0X20, Bit 4 - Mr. Arrow - Oedo Castle 2F Spike Chain Roo
#define MR_ARROW_GHOST_INVISIBLE 0x0105 // Byte 0X20, Bit 5 - Mr. Arrow - Ghost Toys 1F Invisible Ghost
#define MR_ARROW_FESTIVAL_SAMURAI 0x0106 // Byte 0X20, Bit 6 - Mr. Arrow - Festival Temple East Samurai B
#define MR_ARROW_GOURMET_RAMEN 0x0107 // Byte 0X20, Bit 7 - Mr. Arrow - Gourmet Sub 2F-3F Ramen Soup A
#define MR_ARROW_MUSICAL_BIG_AQUARIUM 0x0108 // Byte 0X21, Bit 0 - Mr. Arrow - Musical Castle 1 Big Aquarium

// Special walls and switches
#define WALL_FESTIVAL_FISH_KIT 0x0138 // Byte 0X27, Bit 0 - Invisible Wall That Blocks Doors Un Festival Temple North Fish Kit
#define WALL_MUSICAL_DIAMOND_KEY 0x0193 // Byte 0X32, Bit 3 - Invisible Wall That Blocks Doors Un Musical Castle 2 Diamond Key P
#define WALL_MUSICAL_LEFT_ENTRANCE 0x0194 // Byte 0X32, Bit 4 - Invisible Wall That Blocks Doors Un Musical Castle 2 Left Entrance
#define WALL_MUSICAL_METAL_BOX 0x0195 // Byte 0X32, Bit 5 - Invisible Wall That Blocks Doors Un Musical Castle 2 Metal Box Lav
#define WALL_IYO 0x0197 // Byte 0X32, Bit 7 - Invisible Wall That Blocks Doors Un Iyo
#define WALL_UNKNOWN_0198 0x0198 // Byte 0X33, Bit 0 - Invisible Wall That Blocks Doors Un
#define WALL_GHOST_ENTRANCE 0x019C // Byte 0X33, Bit 4 - Invisible Wall That Blocks Doors Un Ghost Toys Entrance
#define SWITCH_SHORELINE 0x019D // Byte 0X33, Bit 5 - Switch -  Shoreline

#endif // SAVE_DATA_TOOL_H