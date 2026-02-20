#include "Archipelago.h"
#include "modding.h"
#include "recomputils.h"
#include "save_data_tool.h"
#include "types.h"

// Silver lock flags
#define LOCK_SILVER_OEDO_CASTLE_1F_TILE 0x0109
#define LOCK_SILVER_OEDO_CASTLE_1F_CHAIN_PIPE 0x010F
#define LOCK_SILVER_OEDO_CASTLE_1F_TURTLE 0x010B
#define LOCK_SILVER_OEDO_CASTLE_2F_CRUSHER 0x0111
#define LOCK_SILVER_OEDO_CASTLE_2F_SPIKE 0x0113
#define LOCK_SILVER_GHOST_TOYS_1F_FLOWER 0x01AC
#define LOCK_SILVER_GHOST_TOYS_1F_SHOGI 0x01AE
#define LOCK_SILVER_GHOST_TOYS_1F_SPIKE_DAR 0x01B0
#define LOCK_SILVER_GHOST_TOYS_1F_2F_ELEVATOR 0x01B2
#define LOCK_SILVER_GHOST_TOYS_2F_BIG_SPIKE_2 0x01B4
#define LOCK_SILVER_GHOST_TOYS_2F_BILLIARDS 0x01BA
#define LOCK_SILVER_FESTIVAL_TEMPLE_FORK 0x0170
#define LOCK_SILVER_GOURMET_SUB_2F_JETPACK_2 0x017A
#define LOCK_SILVER_GOURMET_SUB_2F_LAVA 0x017E
#define LOCK_SILVER_GOURMET_SUB_2F_UNDERWATER 0x0180
#define LOCK_SILVER_GOURMET_SUB_3F_FOX_2 0x0182
#define LOCK_SILVER_GOURMET_SUB_3F_TOFU 0x0186
#define LOCK_SILVER_MUSICAL_CASTLE_1_TALL 0x018A

// Gold lock flags
#define LOCK_GOLD_OEDO_CASTLE_1F_FORK 0x010D
#define LOCK_GOLD_GHOST_TOYS_2F_BIG_SPIKE_1 0x01B6
#define LOCK_GOLD_FESTIVAL_TEMPLE 0x016F
#define LOCK_GOLD_GOURMET_SUB_2F_JETPACK_1 0x017C
#define LOCK_GOLD_MUSICAL_CASTLE_1_ENTRANCE 0x0188
#define LOCK_GOLD_MUSICAL_CASTLE_1_FAN 0x018D
#define LOCK_GOLD_MUSICAL_CASTLE_1_MULTI_1 0x018E

// Diamond lock flags
#define LOCK_DIAMOND_GHOST_TOYS_2F 0x01B8
#define LOCK_DIAMOND_GOURMET_SUB_3F_FOX_1 0x0184
#define LOCK_DIAMOND_MUSICAL_CASTLE_1_MULTI_2 0x0190
#define LOCK_DIAMOND_MUSICAL_CASTLE_2_ENTRANCE 0x0192

// External function declarations
extern s32 func_800240DC_24CDC(u16 flag);
extern void func_8003521C_35E1C(void *callback);
extern void func_08001240_6F4720(void *entity_ptr, void *arg1);
extern void func_80024038_24C38(u16 param);
extern void func_801FB240_5B7150(void);
extern s32 func_8003F1D8_3FDD8(void);
extern void func_8003D310_3DF10(s32 param);

// External data declarations
extern u32 D_8015C8F8[];
extern s32 D_800C7AA8;

// Key cache structure
typedef struct {
    u32 item_id;
    u32 cached_count;
    int is_valid;
} key_cache_entry_t;

// Cache for key counts
static key_cache_entry_t key_cache[4]; // 4 key types: Silver, Gold, Diamond, Jump Gym
static int key_cache_initialized = 0;

// Initialize the key cache
static void init_key_cache(void) {
    if (!key_cache_initialized) {
        // Initialize all cache entries as invalid
        for (int i = 0; i < 4; i++) {
            key_cache[i].item_id = 0;
            key_cache[i].cached_count = 0;
            key_cache[i].is_valid = 0;
        }

        // Set up the item IDs for each key type
        key_cache[0].item_id = 6464000; // Silver
        key_cache[1].item_id = 6464001; // Gold
        key_cache[2].item_id = 6464002; // Diamond
        key_cache[3].item_id = 6464003; // Jump Gym

        key_cache_initialized = 1;
    }
}

// Find cache entry for an item ID
static key_cache_entry_t *find_key_cache_entry(u32 item_id) {
    init_key_cache();

    for (int i = 0; i < 4; i++) {
        if (key_cache[i].item_id == item_id) {
            return &key_cache[i];
        }
    }

    return NULL;
}

// Invalidate cache entry for an item ID
void invalidate_key_cache_entry(u32 item_id) {
    key_cache_entry_t *entry = find_key_cache_entry(item_id);
    if (entry != NULL) {
        entry->is_valid = 0;
        recomp_printf("KEY CACHE: Invalidated cache for item_id=%lu\n", item_id);
    }
}

// Cache key count for an item ID
static void cache_key_count(u32 item_id, u32 count) {
    key_cache_entry_t *entry = find_key_cache_entry(item_id);
    if (entry != NULL) {
        entry->cached_count = count;
        entry->is_valid = 1;
        recomp_printf("KEY CACHE: Cached count=%lu for item_id=%lu\n", count, item_id);
    }
}

// Function to count collected keys of a specific type from archipelago
u8 count_collected_keys(u8 lock_type) {
    u32 item_id;

    // Only check Archipelago items if connected
    if (!rando_is_connected()) {
        return 0;
    }

    // Map lock type to item ID
    switch (lock_type) {
    case 2:                // Silver keys
        item_id = 6464000; // Silver
        break;
    case 1:                // Gold keys
        item_id = 6464001; // Gold
        break;
    case 0:                // Diamond keys
        item_id = 6464002; // Diamond
        break;
    default:
        return 0;
    }

    // Check cache first
    key_cache_entry_t *cached_entry = find_key_cache_entry(item_id);
    if (cached_entry != NULL && cached_entry->is_valid) {
        recomp_printf("KEY CACHE: Found cached count=%lu for type %d (item_id=%lu)\n", cached_entry->cached_count, lock_type, item_id);
        return (u8)cached_entry->cached_count;
    }

    // Cache miss - query the server
    u32 has_keys = rando_has_item(item_id);

    // Cache the result
    cache_key_count(item_id, has_keys);

    recomp_printf("KEY CACHE: Queried server for type %d (item_id=%lu): count=%lu\n", lock_type, item_id, has_keys);
    return (u8)has_keys;
}

// Function to get used key count by checking unlocked flags
u8 get_used_key_count(u8 lock_type) {
    u8 used_count = 0;

    switch (lock_type) {
    case 2: // Silver keys - count unlocked silver locks
    {
        u16 silver_locks[] = {LOCK_SILVER_OEDO_CASTLE_1F_TILE,       LOCK_SILVER_OEDO_CASTLE_1F_CHAIN_PIPE, LOCK_SILVER_OEDO_CASTLE_1F_TURTLE,     LOCK_SILVER_OEDO_CASTLE_2F_CRUSHER,
                              LOCK_SILVER_OEDO_CASTLE_2F_SPIKE,      LOCK_SILVER_GHOST_TOYS_1F_FLOWER,      LOCK_SILVER_GHOST_TOYS_1F_SHOGI,       LOCK_SILVER_GHOST_TOYS_1F_SPIKE_DAR,
                              LOCK_SILVER_GHOST_TOYS_1F_2F_ELEVATOR, LOCK_SILVER_GHOST_TOYS_2F_BIG_SPIKE_2, LOCK_SILVER_GHOST_TOYS_2F_BILLIARDS,   LOCK_SILVER_FESTIVAL_TEMPLE_FORK,
                              LOCK_SILVER_GOURMET_SUB_2F_JETPACK_2,  LOCK_SILVER_GOURMET_SUB_2F_LAVA,       LOCK_SILVER_GOURMET_SUB_2F_UNDERWATER, LOCK_SILVER_GOURMET_SUB_3F_FOX_2,
                              LOCK_SILVER_GOURMET_SUB_3F_TOFU,       LOCK_SILVER_MUSICAL_CASTLE_1_TALL};
        for (int i = 0; i < sizeof(silver_locks) / sizeof(silver_locks[0]); i++) {
            if (IS_FLAG_SET(silver_locks[i])) {
                used_count++;
            }
        }
    } break;
    case 1: // Gold keys - count unlocked gold locks
    {
        u16 gold_locks[] = {LOCK_GOLD_OEDO_CASTLE_1F_FORK,       LOCK_GOLD_GHOST_TOYS_2F_BIG_SPIKE_1, LOCK_GOLD_FESTIVAL_TEMPLE,         LOCK_GOLD_GOURMET_SUB_2F_JETPACK_1,
                            LOCK_GOLD_MUSICAL_CASTLE_1_ENTRANCE, LOCK_GOLD_MUSICAL_CASTLE_1_FAN,      LOCK_GOLD_MUSICAL_CASTLE_1_MULTI_1};
        for (int i = 0; i < sizeof(gold_locks) / sizeof(gold_locks[0]); i++) {
            if (IS_FLAG_SET(gold_locks[i])) {
                used_count++;
            }
        }
    } break;
    case 0: // Diamond keys - count unlocked diamond locks
    {
        u16 diamond_locks[] = {LOCK_DIAMOND_GHOST_TOYS_2F, LOCK_DIAMOND_GOURMET_SUB_3F_FOX_1, LOCK_DIAMOND_MUSICAL_CASTLE_1_MULTI_2, LOCK_DIAMOND_MUSICAL_CASTLE_2_ENTRANCE};
        for (int i = 0; i < sizeof(diamond_locks) / sizeof(diamond_locks[0]); i++) {
            if (IS_FLAG_SET(diamond_locks[i])) {
                used_count++;
            }
        }
    } break;
    default:
        return 0;
    }

    return used_count;
}

// Function to get available (unused) key count
u8 get_key_count(u8 lock_type) {
    u8 collected = count_collected_keys(lock_type);
    u8 used = get_used_key_count(lock_type);

    if (collected > used) {
        return collected - used;
    }
    return 0;
}

// Note: Key usage is now tracked automatically by checking which locks have been unlocked
// No need for manual increment function

void calculate_key_on_pause() {
    u8 diamond_keys = get_key_count(0);
    u8 gold_keys = get_key_count(1);
    u8 silver_keys = get_key_count(2);
    if (diamond_keys > 0 || gold_keys > 0 || silver_keys > 0) {
        WRITE_SAVE_DATA(SAVE_KEY_ON_PAUSE, 1);
    } else {
        WRITE_SAVE_DATA(SAVE_KEY_ON_PAUSE, 0);
    }
}

RECOMP_PATCH void func_08001020_6F4500(void *entity_ptr, void *arg1) {
    u8 *entity = (u8 *)entity_ptr;
    s32 (*flag_check_func)(u16) = func_800240DC_24CDC;
    u16 field_0xDA;
    u32 flags;
    u8 state;

    // Load field at offset 0xDA
    field_0xDA = *(u16 *)(entity + 0xDA);

    // If field_0xDA is non-zero, set bit 2 in flags at offset 0xEC
    if (field_0xDA != 0) {
        flags = *(u32 *)(entity + 0xEC);
        *(u32 *)(entity + 0xEC) = flags | 0x4;
    }

    // Load flags and check if bit 2 is set
    flags = *(u32 *)(entity + 0xEC);
    if (!(flags & 0x4)) {
        return;
    }
    u8 lock_type = *(u8 *)(entity + 0xD1);
    DEBUG_PRINTF("Entity lock type: %d\n", lock_type);
    // Lock Type 0 = Diamond
    // Lock Type 1 = Gold
    // Lock Type 2 = Silver
    // Lock Type 3 = Special

    // If the lock type is 3 and D6 is 0xFFFF, skip checking D4 and D6
    if (lock_type != 3 && *(u16 *)(entity + 0xD6) != 0xFFFF) {
        u8 temp_flag_d4 = flag_check_func(*(u16 *)(entity + 0xD4));
        DEBUG_PRINTF("Flag check returned: %d\n", temp_flag_d4);
        DEBUG_PRINTF("Checking flag for 0x%04X at D4\n", *(u16 *)(entity + 0xD4));
        // Check flag for field at offset 0xD4
        if (flag_check_func(*(u16 *)(entity + 0xD4)) != 0) {
            // PROBABLY for a different key type
            DEBUG_PRINTF("D4");
            DEBUG_PRINTF("Item collection flag triggered for 0x%04X\n", *(u16 *)(entity + 0xD4));
            // Call flag check again to consume/clear the flag
            flag_check_func(*(u16 *)(entity + 0xD4));

            // Set bit 1 in flags
            flags = *(u32 *)(entity + 0xEC);
            *(u32 *)(entity + 0xEC) = flags | 0x2;

            // Set up callback and return
            func_8003521C_35E1C(func_08001240_6F4720);
            return;
        }
        // print the value of flag_check_func(*(u16*)(entity + 0xD6))
        u8 temp_flag = flag_check_func(*(u16 *)(entity + 0xD6));
        DEBUG_PRINTF("Flag check returned: %d\n", temp_flag);
        DEBUG_PRINTF("Checking flag for 0x%04X at D6\n", *(u16 *)(entity + 0xD6));
        // print info about the entity itself
        DEBUG_PRINTF("Entity pointer: %p\n", entity);
        // we want to get info from the pointer itself

        // Check if we have any unused keys of the appropriate type
        u8 collected_keys = count_collected_keys(lock_type);
        u8 used_keys = get_used_key_count(lock_type);
        u8 available_keys = get_key_count(lock_type);

        DEBUG_PRINTF("Lock type: %d, Collected: %d, Used: %d, Available: %d\n", lock_type, collected_keys, used_keys, available_keys);

        if (available_keys > 0) {
            DEBUG_PRINTF("Using key of type %d\n", lock_type);

            // Set the unlock flag - this will automatically be counted as "used"
            func_80024038_24C38(*(u16 *)(entity + 0xD4));

            // Call cleanup function
            func_801FB240_5B7150();

            // Clear global state array entry
            D_8015C8F8[D_800C7AA8] = 0;

            // Set bit 0 in flags
            flags = *(u32 *)(entity + 0xEC);
            *(u32 *)(entity + 0xEC) = flags | 0x1;
            calculate_key_on_pause();
            // Set up callback and return
            func_8003521C_35E1C(func_08001240_6F4720);
            return;
        }
    } else if (lock_type == 3 && *(u16 *)(entity + 0xD6) == 0x027) {
        DEBUG_PRINTF("Attempting to open jump gym\n");
        // We use the ID because we use the other value for the pause menu key
        // tracking

        // Check cache first for Jump Gym key
        key_cache_entry_t *jump_gym_cache = find_key_cache_entry(6464003);
        u32 has_jump_gym_key = 0;

        if (jump_gym_cache != NULL && jump_gym_cache->is_valid) {
            has_jump_gym_key = jump_gym_cache->cached_count;
            DEBUG_PRINTF("KEY CACHE: Found cached Jump Gym key count=%lu\n", has_jump_gym_key);
        } else if (rando_is_connected()) {
            // Cache miss - query the server
            has_jump_gym_key = rando_has_item(6464003);
            cache_key_count(6464003, has_jump_gym_key);
            DEBUG_PRINTF("KEY CACHE: Queried server for Jump Gym key: count=%lu\n", has_jump_gym_key);
        }
        if (flag_check_func(*(u16 *)(entity + 0xD4)) == 1) {
            DEBUG_PRINTF("D4");
            DEBUG_PRINTF("Item collection flag triggered for 0x%04X\n", *(u16 *)(entity + 0xD4));
            // Call flag check again to consume/clear the flag
            flag_check_func(*(u16 *)(entity + 0xD4));

            // Set bit 1 in flags
            flags = *(u32 *)(entity + 0xEC);
            *(u32 *)(entity + 0xEC) = flags | 0x2;

            // Set up callback and return
            func_8003521C_35E1C(func_08001240_6F4720);
            return;
        }

        if (has_jump_gym_key > 0) {
            DEBUG_PRINTF("Using jump gym key\n");
            func_80024038_24C38(*(u16 *)(entity + 0xD4));

            // Call cleanup function
            func_801FB240_5B7150();

            // Clear global state array entry
            D_8015C8F8[D_800C7AA8] = 0;

            // Set bit 0 in flags
            flags = *(u32 *)(entity + 0xEC);
            *(u32 *)(entity + 0xEC) = flags | 0x1;
            calculate_key_on_pause();
            // Set up callback and return
            func_8003521C_35E1C(func_08001240_6F4720);
            return;
        }
    }

    // Load state from offset 0xD1
    state = entity[0xD1];
    recomp_printf("Entity state: %d\n", state);
    // Handle different states - only call func_8003D310_3DF10 if
    // func_8003F1D8_3FDD8 returns 0
    if (state == 0) {
        if (func_8003F1D8_3FDD8() == 0) {
            func_8003D310_3DF10(0x89);
        }
    } else if (state == 1) {
        if (func_8003F1D8_3FDD8() == 0) {
            func_8003D310_3DF10(0x88);
        }
    } else if (state == 2) {
        if (func_8003F1D8_3FDD8() == 0) {
            func_8003D310_3DF10(0x87);
        }
    } else if (state == 3) {
        if (func_8003F1D8_3FDD8() == 0) {
            func_8003D310_3DF10(0x32);
        }
    }

    // Load flags again after potential modifications
    flags = *(u32 *)(entity + 0xEC);

    // Clear field_0xDA (set to 0)
    *(u16 *)(entity + 0xDA) = 0;

    // If bit 2 is set in flags, clear it. Otherwise, set up callback to re-run
    // this function
    if (flags & 0x4) {
        *(u32 *)(entity + 0xEC) = flags & ~0x4; // Clear bit 2
    } else {
        func_8003521C_35E1C(func_08001020_6F4500);
    }
}
