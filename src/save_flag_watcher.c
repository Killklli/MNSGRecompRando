#include "Archipelago.h"
#include "apconnect_ui.h"
#include "entities.h"
#include "libc/stdio.h"
#include "modding.h"
#include "recomputils.h"
#include "save_data_tool.h"
#include "types.h"

// External data declaration
extern u8 D_8015C608_15D208[];

// Flag cache structure
typedef struct
{
    s32 flag_id;
    s32 cached_value;
    int is_valid;
} flag_cache_entry_t;

// Cache for flag values (using a simple array for now)
#define FLAG_CACHE_SIZE 256
static flag_cache_entry_t flag_cache[FLAG_CACHE_SIZE];
static int cache_initialized = 0;

// Initialize the cache
static void init_flag_cache(void)
{
    if (!cache_initialized)
    {
        for (int i = 0; i < FLAG_CACHE_SIZE; i++)
        {
            flag_cache[i].flag_id = -1;
            flag_cache[i].cached_value = 0;
            flag_cache[i].is_valid = 0;
        }
        cache_initialized = 1;
    }
}

// Find cache entry for a flag ID
static flag_cache_entry_t *find_cache_entry(s32 flag_id)
{
    init_flag_cache();

    // First try to find existing entry
    for (int i = 0; i < FLAG_CACHE_SIZE; i++)
    {
        if (flag_cache[i].flag_id == flag_id && flag_cache[i].is_valid)
        {
            return &flag_cache[i];
        }
    }

    return NULL;
}

// Add or update cache entry
static void cache_flag_value(s32 flag_id, s32 value)
{
    init_flag_cache();

    // First try to update existing entry
    for (int i = 0; i < FLAG_CACHE_SIZE; i++)
    {
        if (flag_cache[i].flag_id == flag_id)
        {
            flag_cache[i].cached_value = value;
            flag_cache[i].is_valid = 1;
            return;
        }
    }

    // Find empty slot for new entry
    for (int i = 0; i < FLAG_CACHE_SIZE; i++)
    {
        if (!flag_cache[i].is_valid)
        {
            flag_cache[i].flag_id = flag_id;
            flag_cache[i].cached_value = value;
            flag_cache[i].is_valid = 1;
            return;
        }
    }

    // Cache is full, replace oldest entry (simple round-robin)
    static int next_slot = 0;
    flag_cache[next_slot].flag_id = flag_id;
    flag_cache[next_slot].cached_value = value;
    flag_cache[next_slot].is_valid = 1;
    next_slot = (next_slot + 1) % FLAG_CACHE_SIZE;
}

// Invalidate cache entry for a flag ID
static void invalidate_cache_entry(s32 flag_id)
{
    init_flag_cache();

    for (int i = 0; i < FLAG_CACHE_SIZE; i++)
    {
        if (flag_cache[i].flag_id == flag_id && flag_cache[i].is_valid)
        {
            flag_cache[i].is_valid = 0;
            DEBUG_PRINTF("FLAG CACHE: Invalidated cache for flag_id=%ld\n", flag_id);
            return;
        }
    }
}

RECOMP_PATCH s32 func_800240DC_24CDC(s32 flag_id)
{
    // Check cache first
    flag_cache_entry_t *cached_entry = find_cache_entry(flag_id);
    if (cached_entry != NULL)
    {
        DEBUG_PRINTF("FLAG READ: flag_id=%ld found in cache, value=%ld\n", flag_id, cached_entry->cached_value);
        return cached_entry->cached_value;
    }

    // if the flag_id is 0x0 AND we have the save item for super pass return 1
    if (flag_id == 0)
    {
        s32 super_pass_value = READ_SAVE_DATA(SAVE_SUPER_PASS);
        s32 result = (super_pass_value != 0) ? 1 : 0;
        cache_flag_value(flag_id, result);
        return result;
    }
    if (flag_id == 0x29)
    {
        s32 have_achilles_heel = READ_SAVE_DATA(SAVE_ACHILLES_HEEL);
        s32 result = (have_achilles_heel != 0) ? 1 : 0;
        cache_flag_value(flag_id, result);
        return result;
    }

    // First try to read from local game data if within bounds
    s32 local_value = 0;
    int local_read_success = 0;

    if (flag_id >= 0 && flag_id <= ((0x304 * 8) - 1))
    {
        s32 byte_index;
        s32 bit_index;
        u8 byte_value;
        s32 bit_mask;

        // Calculate byte index - divide by 8 with sign-aware right shift
        if (flag_id < 0)
        {
            byte_index = (flag_id + 7) >> 3; // Add 7 before shifting for negative numbers
        }
        else
        {
            byte_index = flag_id >> 3; // Simple right shift for positive numbers
        }

        // Mask to ensure byte_index is within u8 range
        byte_index &= 0xFF;

        // Load the byte from the data array
        byte_value = D_8015C608_15D208[byte_index];

        // Calculate bit position within the byte
        if (flag_id < 0)
        {
            bit_index = flag_id & 7;
            if (bit_index != 0)
            {
                bit_index -= 8; // Adjust for negative numbers
            }
        }
        else
        {
            bit_index = flag_id & 7;
        }

        // Mask to ensure bit_index is within u8 range
        bit_index &= 0xFF;

        // Create bit mask by shifting 1 left by bit_index positions
        bit_mask = 1 << bit_index;

        // Check if the bit is set
        local_value = (byte_value & bit_mask) ? 1 : 0;
        local_read_success = 1;
    }

    // Try to get from data storage if connected
    s32 remote_value = 0;
    int remote_read_success = 0;

    if (rando_is_connected())
    {
        char key[16];
        sprintf(key, "flag_%ld", flag_id);
        remote_value = rando_get_datastorage_u32_sync(key) ? 1 : 0;
        remote_read_success = 1;
        DEBUG_PRINTF("FLAG READ: flag_id=%ld, remote value=%ld\n", flag_id, remote_value);
    }

    // Determine final value - prefer remote if available, otherwise local
    s32 final_value = 0;
    if (remote_read_success && local_read_success)
    {
        // Use logical OR - if either local or remote is set, consider it set
        final_value = local_value || remote_value;
        DEBUG_PRINTF("FLAG READ: flag_id=%ld, using combined value (local=%ld, remote=%ld, final=%ld)\n",
                     flag_id, local_value, remote_value, final_value);
    }
    else if (remote_read_success)
    {
        final_value = remote_value;
        DEBUG_PRINTF("FLAG READ: flag_id=%ld, using remote value=%ld\n", flag_id, final_value);
    }
    else if (local_read_success)
    {
        final_value = local_value;
        DEBUG_PRINTF("FLAG READ: flag_id=%ld, using local value=%ld\n", flag_id, final_value);
    }
    else
    {
        DEBUG_PRINTF("FLAG READ: flag_id=%ld, no valid data source, returning 0\n", flag_id);
        final_value = 0;
    }

    // Cache the result
    cache_flag_value(flag_id, final_value);

    return final_value;
}

RECOMP_PATCH void func_80024038_24C38(s32 flag_id)
{
    // Invalidate cache since we're writing to this flag
    invalidate_cache_entry(flag_id);

    // Create key string for this flag
    char key[16];
    sprintf(key, "flag_%ld", flag_id);

    // Write to data storage only if connected
    if (rando_is_connected())
    {
        rando_set_datastorage_u32_async(key, 1);
    } // If flag is within bounds of D_8015C608_15D208 (0x304 bytes = 6144 flags
      // max)
    if (flag_id >= 0 && flag_id <= ((0x304 * 8) - 1))
    {
        s32 byte_index;
        s32 bit_index;
        u8 current_byte;
        u8 bit_mask;

        // Calculate byte index - divide by 8 with sign-aware right shift
        if (flag_id < 0)
        {
            byte_index =
                (flag_id + 7) >> 3; // Add 7 before shifting for negative numbers
        }
        else
        {
            byte_index = flag_id >> 3; // Simple right shift for positive numbers
        }

        // Mask to ensure byte_index is within u8 range
        byte_index &= 0xFF;

        // Load the current byte from the bitfield array
        current_byte = D_8015C608_15D208[byte_index];

        // Calculate bit position within the byte
        if (flag_id < 0)
        {
            bit_index = flag_id & 7;
            if (bit_index != 0)
            {
                bit_index -= 8; // Adjust for negative numbers
            }
        }
        else
        {
            bit_index = flag_id & 7;
        }

        // Mask to ensure bit_index is within u8 range
        bit_index &= 0xFF;

        // Create bit mask by shifting 1 left by bit_index positions
        bit_mask = 1 << bit_index;

        // Set the bit using OR operation
        current_byte |= bit_mask;

        // Store the modified byte back to the array
        D_8015C608_15D208[byte_index] = current_byte;

        DEBUG_PRINTF(
            "FLAG SET: flag_id=%ld written to BOTH local array and datastore\n",
            flag_id);
    }
    else
    {
        DEBUG_PRINTF(
            "FLAG SET: flag_id=%ld is OUTSIDE bounds, written to datastore only\n",
            flag_id);
    }
}

RECOMP_PATCH void func_80024088_24C88(int bit_index)
{
    // Invalidate cache since we're clearing this flag
    invalidate_cache_entry(bit_index);

    // Create key string for this flag
    char key[16];
    sprintf(key, "flag_%d", bit_index);

    // Clear in data storage only if connected
    if (rando_is_connected())
    {
        rando_set_datastorage_u32_async(key, 0);
    } // If flag is within bounds of D_8015C608_15D208 (0x304 bytes = 6144 flags
      // max)
    if (bit_index >= 0 && bit_index <= ((0x304 * 8) - 1))
    {
        int byte_index;
        int bit_offset;
        unsigned char current_byte;
        unsigned char bit_mask;

        // Calculate byte index (bit_index / 8)
        if (bit_index < 0)
        {
            byte_index = (bit_index + 7) >> 3;
        }
        else
        {
            byte_index = bit_index >> 3;
        }

        // Get the current byte from the array
        current_byte = D_8015C608_15D208[byte_index & 0xFF];

        // Calculate bit offset within the byte
        bit_offset = bit_index & 7;
        if (bit_index < 0 && bit_offset != 0)
        {
            bit_offset = bit_offset - 8;
        }
        bit_offset &= 0xFF;

        // Create bit mask and clear the bit
        bit_mask = ~(1 << bit_offset);
        D_8015C608_15D208[byte_index & 0xFF] = current_byte & bit_mask;

        DEBUG_PRINTF(
            "FLAG CLEAR: flag_id=%d cleared from BOTH local array and datastore\n",
            bit_index);
    }
    else
    {
        DEBUG_PRINTF("FLAG CLEAR: flag_id=%d is OUTSIDE bounds, cleared from "
                     "datastore only\n",
                     bit_index);
    }
}
