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

// Extended save data for flags outside the main array range
// Calculate size needed for flags beyond 0x304 * 8 (up to reasonable limit)
#define EXTENDED_SAVE_SIZE 0x200  // 512 bytes for extended flags
static u8 extended_save[EXTENDED_SAVE_SIZE];
static int extended_save_initialized = 0;

// Initialize extended save array
static void init_extended_save(void)
{
    if (!extended_save_initialized)
    {
        for (int i = 0; i < EXTENDED_SAVE_SIZE; i++)
        {
            extended_save[i] = 0;
        }
        extended_save_initialized = 1;
    }
}

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

// Create comma-delimited string of all bytes in D_8015C608_15D208 and store it
void update_full_save_data(void)
{
    if (!rando_is_connected())
    {
        return;
    }

    // Calculate required buffer size: (0x304 + EXTENDED_SAVE_SIZE) bytes * 3 chars per byte ("255") + commas + 1 null terminator
    // = (0x304 + 0x200) * 3 + (0x304 + 0x200 - 1) + 1 = 3843 + 1283 + 1 = 5127 bytes
    static char full_save_string[5200];  // Round up for safety
    int pos = 0;

    // First, save the main D_8015C608_15D208 array
    for (int i = 0; i < 0x304; i++)
    {
        if (i > 0)
        {
            full_save_string[pos++] = ',';
        }
        pos += sprintf(&full_save_string[pos], "%u", (unsigned int)D_8015C608_15D208[i]);
    }

    // Then, save the extended_save array
    init_extended_save();
    for (int i = 0; i < EXTENDED_SAVE_SIZE; i++)
    {
        full_save_string[pos++] = ',';
        pos += sprintf(&full_save_string[pos], "%u", (unsigned int)extended_save[i]);
    }
    full_save_string[pos] = '\0';

    // Read the current values and store them
    s32 current_health = READ_SAVE_DATA(SAVE_CURRENT_HEALTH);
    s32 total_health = READ_SAVE_DATA(SAVE_TOTAL_HEALTH);
    
    // Only store if total_health is not 0 (indicating valid game state)
    if (total_health != 0 && current_health != 0)
    {
        // Store the full save string in the datastore
        rando_set_datastorage_string_async("full_save", full_save_string);
        DEBUG_PRINTF("FULL SAVE: Updated full_save data string\n");
        DEBUG_PRINTF("FULL SAVE STRING: %s\n", full_save_string);
        DEBUG_PRINTF("FULL SAVE: String length=%d\n", pos);
    }
}

// Load comma-delimited string from data storage back into D_8015C608_15D208 array
// Returns true if data was successfully loaded, false otherwise
bool load_full_save_data_from_storage(void)
{
    if (!rando_is_connected())
    {
        DEBUG_PRINTF("LOAD FULL SAVE: Not connected, cannot load data\n");
        return false;
    }

    // Allocate buffer for the full save string (same size as in update_full_save_data)
    static char full_save_string[5200];
    
    // Initialize extended save array
    init_extended_save();
    
    // Get the full save string from data storage
    rando_get_datastorage_string_sync("full_save", full_save_string);
    
    // Check if we got any data
    if (full_save_string[0] == '\0')
    {
        DEBUG_PRINTF("LOAD FULL SAVE: No full_save data found in storage\n");
        return false;
    }
    
    DEBUG_PRINTF("LOAD FULL SAVE: Retrieved string from storage\n");
    DEBUG_PRINTF("LOAD FULL SAVE STRING: %s\n", full_save_string);
    
    // Parse the comma-delimited string and load into arrays
    char *token = full_save_string;
    char *next_token;
    int byte_index = 0;
    int total_expected = 0x304 + EXTENDED_SAVE_SIZE;
    
    while (token != NULL && byte_index < total_expected)
    {
        // Find the next comma or end of string
        next_token = token;
        while (*next_token != ',' && *next_token != '\0')
        {
            next_token++;
        }
        
        // Temporarily null-terminate this token
        char saved_char = *next_token;
        *next_token = '\0';
        
        // Convert string to unsigned integer manually
        unsigned int byte_value = 0;
        char *digit_ptr = token;
        while (*digit_ptr >= '0' && *digit_ptr <= '9')
        {
            byte_value = byte_value * 10 + (*digit_ptr - '0');
            digit_ptr++;
        }
        
        // Store in the appropriate array (with bounds checking)
        if (byte_value <= 255)
        {
            if (byte_index < 0x304)
            {
                D_8015C608_15D208[byte_index] = (u8)byte_value;
            }
            else if (byte_index < 0x304 + EXTENDED_SAVE_SIZE)
            {
                extended_save[byte_index - 0x304] = (u8)byte_value;
            }
        }
        else
        {
            DEBUG_PRINTF("LOAD FULL SAVE: Warning - byte value %u out of range at index %d\n", byte_value, byte_index);
            if (byte_index < 0x304)
            {
                D_8015C608_15D208[byte_index] = 255; // Clamp to max value
            }
            else if (byte_index < 0x304 + EXTENDED_SAVE_SIZE)
            {
                extended_save[byte_index - 0x304] = 255;
            }
        }
        
        byte_index++;
        
        // Restore the character and move to next token
        *next_token = saved_char;
        if (saved_char == ',')
        {
            token = next_token + 1;
        }
        else
        {
            token = NULL; // End of string
        }
    }
    
    int main_bytes = (byte_index > 0x304) ? 0x304 : byte_index;
    int extended_bytes = (byte_index > 0x304) ? (byte_index - 0x304) : 0;
    
    DEBUG_PRINTF("LOAD FULL SAVE: Loaded %d bytes into D_8015C608_15D208 array\n", main_bytes);
    DEBUG_PRINTF("LOAD FULL SAVE: Loaded %d bytes into extended_save array\n", extended_bytes);
    
    if (byte_index != total_expected)
    {
        DEBUG_PRINTF("LOAD FULL SAVE: Warning - Expected %d bytes, got %d bytes\n", total_expected, byte_index);
    }
    
    return true;
}

// Check if starting characters should be set based on current save data
// Returns true if characters should be set (no existing data), false if they're already set
bool should_set_starting_characters(void)
{
    // Check if any characters are already recruited
    s32 goemon_recruited = READ_SAVE_DATA(SAVE_GOEMON_RECRUITED);
    s32 ebisumaru_recruited = READ_SAVE_DATA(SAVE_EBISUMARU_RECRUITED);
    s32 sasuke_recruited = READ_SAVE_DATA(SAVE_SASUKE_RECRUITED);
    s32 yae_recruited = READ_SAVE_DATA(SAVE_YAE_RECRUITED);
    
    // If any character is already recruited, don't set starting characters
    if (goemon_recruited != 0 || ebisumaru_recruited != 0 || sasuke_recruited != 0 || yae_recruited != 0)
    {
        DEBUG_PRINTF("STARTING CHARS: Characters already recruited, skipping setup\n");
        return false;
    }
    
    // Check if any weapon levels are set (indicating existing save data)
    s32 goemon_weapon = READ_SAVE_DATA(SAVE_GOEMON_WEAPON_LEVEL);
    s32 ebisumaru_weapon = READ_SAVE_DATA(SAVE_EBISUMARU_WEAPON_LEVEL);
    s32 sasuke_weapon = READ_SAVE_DATA(SAVE_SASUKE_WEAPON_LEVEL);
    s32 yae_weapon = READ_SAVE_DATA(SAVE_YAE_WEAPON_LEVEL);
    
    if (goemon_weapon != 0 || ebisumaru_weapon != 0 || sasuke_weapon != 0 || yae_weapon != 0)
    {
        DEBUG_PRINTF("STARTING CHARS: Weapon levels already set, skipping setup\n");
        return false;
    }
    
    DEBUG_PRINTF("STARTING CHARS: No existing character data found, setting starting characters\n");
    return true;
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
        return result;
    }
    if (flag_id == 0x29)
    {
        s32 have_achilles_heel = READ_SAVE_DATA(SAVE_ACHILLES_HEEL);
        s32 result = (have_achilles_heel != 0) ? 1 : 0;
        return result;
    }

    // Read from local game data if within bounds
    s32 result = 0;

    if (flag_id >= 0 && flag_id <= 6143)
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
        result = (byte_value & bit_mask) ? 1 : 0;
        DEBUG_PRINTF("FLAG READ: flag_id=%ld, local value=%ld\n", flag_id, result);
    }
    else if (flag_id >= 6144 && flag_id <= ((0x304 + EXTENDED_SAVE_SIZE) * 8 - 1))
    {
        // Handle extended save area
        init_extended_save();
        s32 extended_flag_id = flag_id - 6144;
        s32 byte_index = extended_flag_id >> 3;
        s32 bit_index = extended_flag_id & 7;
        
        if (byte_index >= 0 && byte_index < EXTENDED_SAVE_SIZE)
        {
            u8 byte_value = extended_save[byte_index];
            s32 bit_mask = 1 << bit_index;
            result = (byte_value & bit_mask) ? 1 : 0;
            DEBUG_PRINTF("FLAG READ: flag_id=%ld, extended save value=%ld\n", flag_id, result);
        }
        else
        {
            DEBUG_PRINTF("FLAG READ: flag_id=%ld is OUTSIDE extended bounds, returning 0\n", flag_id);
            result = 0;
        }
    }
    else
    {
        DEBUG_PRINTF("FLAG READ: flag_id=%ld is OUTSIDE all bounds, returning 0\n", flag_id);
        result = 0;
    }

    return result;
}

void save_player_data(){
    
    // Save additional game state values to their own datastore keys
    if (rando_is_connected())
    {
        // Read the current values and store them
        s32 current_lives = READ_SAVE_DATA(SAVE_CURRENT_LIFE_TOTAL);
        s32 current_ryo = READ_SAVE_DATA(SAVE_RYO);
        s32 current_health = READ_SAVE_DATA(SAVE_CURRENT_HEALTH);
        s32 total_health = READ_SAVE_DATA(SAVE_TOTAL_HEALTH);
        
        // Only store if total_health is not 0 (indicating valid game state)
        if (total_health != 0 && current_health != 0)
        {
            // Store each value with its own key
            rando_set_datastorage_u32_async("save_current_lives", (u32)current_lives);
            rando_set_datastorage_u32_async("save_current_ryo", (u32)current_ryo);
            rando_set_datastorage_u32_async("save_current_health", (u32)current_health);
            rando_set_datastorage_u32_async("save_total_health", (u32)total_health);
            
            DEBUG_PRINTF("EXTRA SAVE: Stored current_lives=%ld, ryo=%ld, current_health=%ld, total_health=%ld\n", 
                        current_lives, current_ryo, current_health, total_health);
        }
        else
        {
            DEBUG_PRINTF("EXTRA SAVE: Skipping save - total_health is 0 (invalid game state)\n");
        }
    }
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
      // max, so flags 0-6143)
    if (flag_id >= 0 && flag_id <= 6143)
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
    else if (flag_id >= 6144 && flag_id <= ((0x304 + EXTENDED_SAVE_SIZE) * 8 - 1))
    {
        // Handle extended save area
        init_extended_save();
        s32 extended_flag_id = flag_id - 6144;
        s32 byte_index = extended_flag_id >> 3;
        s32 bit_index = extended_flag_id & 7;
        
        if (byte_index >= 0 && byte_index < EXTENDED_SAVE_SIZE)
        {
            u8 current_byte = extended_save[byte_index];
            u8 bit_mask = 1 << bit_index;
            extended_save[byte_index] = current_byte | bit_mask;
            
            DEBUG_PRINTF(
                "FLAG SET: flag_id=%ld written to extended save array and datastore\n",
                flag_id);
        }
        else
        {
            DEBUG_PRINTF(
                "FLAG SET: flag_id=%ld is OUTSIDE extended bounds, written to datastore only\n",
                flag_id);
        }
    }
    else
    {
        DEBUG_PRINTF(
            "FLAG SET: flag_id=%ld is OUTSIDE all bounds, written to datastore only\n",
            flag_id);
    }
    save_player_data();
    // Update the full save data string
    update_full_save_data();
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
    else if (bit_index >= (0x304 * 8) && bit_index <= ((0x304 + EXTENDED_SAVE_SIZE) * 8 - 1))
    {
        // Handle extended save area
        init_extended_save();
        int extended_bit_index = bit_index - (0x304 * 8);
        int byte_index = extended_bit_index >> 3;
        int bit_offset = extended_bit_index & 7;
        
        if (byte_index >= 0 && byte_index < EXTENDED_SAVE_SIZE)
        {
            unsigned char current_byte = extended_save[byte_index];
            unsigned char bit_mask = ~(1 << bit_offset);
            extended_save[byte_index] = current_byte & bit_mask;
            
            DEBUG_PRINTF(
                "FLAG CLEAR: flag_id=%d cleared from extended save array and datastore\n",
                bit_index);
        }
        else
        {
            DEBUG_PRINTF("FLAG CLEAR: flag_id=%d is OUTSIDE extended bounds, cleared from "
                         "datastore only\n",
                         bit_index);
        }
    }
    else
    {
        DEBUG_PRINTF("FLAG CLEAR: flag_id=%d is OUTSIDE all bounds, cleared from "
                     "datastore only\n",
                     bit_index);
    }

    // Save additional game state values to their own datastore keys
    save_player_data();

    // Update the full save data string
    update_full_save_data();
}
