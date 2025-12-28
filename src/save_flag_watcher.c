#include "types.h"
#include "modding.h"
#include "apconnect_ui.h"
#include "recomputils.h"
#include "save_data_tool.h"
#include "entities.h"
#include "Archipelago.h"
#include "libc/stdio.h"

// External data declaration
extern u8 D_8015C608_15D208[];

// Whitelist of flag IDs that should always read from local game data
static const s32 local_read_whitelist[] = {
    0x18,  // WALL_UNKNOWN_0018 (24 decimal) - Invisible Wall That Blocks Doors
    0x32,  // WALL_UNKNOWN_0032 (50 decimal) - Invisible Wall That Blocks Doors  
    0xA4,  // WALL_UNKNOWN_00A4 (164 decimal) - Invisible Wall That Blocks Doors
    0xC7,  // WALL_YAMATO - Invisible Wall That Blocks Doors Un Yamato Shrine
    0x138, // WALL_FESTIVAL_FISH_KIT - Invisible Wall That Blocks Doors Un Festival Temple North Fish Kit
    0x193, // WALL_MUSICAL_DIAMOND_KEY - Invisible Wall That Blocks Doors Un Musical Castle 2 Diamond Key
    0x194, // WALL_MUSICAL_LEFT_ENTRANCE - Invisible Wall That Blocks Doors Un Musical Castle 2 Left Entrance
    0x195, // WALL_MUSICAL_METAL_BOX - Invisible Wall That Blocks Doors Un Musical Castle 2 Metal Box Lav
    0x197, // WALL_IYO - Invisible Wall That Blocks Doors Un Iyo
    0x198, // WALL_UNKNOWN_0198 (408 decimal) - Invisible Wall That Blocks Doors Un
    0x19C, // WALL_GHOST_ENTRANCE - Invisible Wall That Blocks Doors Un Ghost Toys Entrance
    0x19D  // SWITCH_SHORELINE - Switch - Shoreline
};
static const s32 local_read_whitelist_size = sizeof(local_read_whitelist) / sizeof(local_read_whitelist[0]);

// Check if a flag ID is in the local read whitelist
static int is_flag_in_local_whitelist(s32 flag_id)
{
    for (int i = 0; i < local_read_whitelist_size; i++)
    {
        if (local_read_whitelist[i] == flag_id)
        {
            return 1;
        }
    }
    return 0;
}

RECOMP_PATCH s32 func_800240DC_24CDC(s32 flag_id)
{
    // if the flag_id is 0x0 AND we have the save item for super pass return 1
    if (flag_id == 0)
    {
        s32 super_pass_value = READ_SAVE_DATA(SAVE_SUPER_PASS);
        if (super_pass_value != 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    if (flag_id == 0x29)
    {
        s32 have_achilles_heel = READ_SAVE_DATA(SAVE_ACHILLES_HEEL);
        if (have_achilles_heel != 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    // Check if this flag should always read from local game data
    if (is_flag_in_local_whitelist(flag_id))
    {
        DEBUG_PRINTF("FLAG READ: flag_id=%ld is whitelisted, reading from local game data\n", flag_id);
        
        // Read from local game data using the original logic
        if (flag_id >= 0 && flag_id <= ((0x304 * 8) - 1))
        {
            s32 byte_index;
            s32 bit_index;
            u8 byte_value;
            s32 bit_mask;
            s32 result;
            
            // Calculate byte index - divide by 8 with sign-aware right shift
            if (flag_id < 0)
            {
                byte_index = (flag_id + 7) >> 3;  // Add 7 before shifting for negative numbers
            }
            else
            {
                byte_index = flag_id >> 3;  // Simple right shift for positive numbers
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
                    bit_index -= 8;  // Adjust for negative numbers
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
            result = byte_value & bit_mask;
            
            // Return 1 if bit is set, 0 otherwise
            return result ? 1 : 0;
        }
        else
        {
            DEBUG_PRINTF("FLAG READ: whitelisted flag_id=%ld is outside bounds, returning 0\n", flag_id);
            return 0;
        }
    }

    // Use data storage system for all other flags
    char key[16];
    sprintf(key, "flag_%ld", flag_id);

    DEBUG_PRINTF("FLAG READ: flag_id=%ld, using data storage with key=%s\n", flag_id, key);

    // Get flag value from data storage only if connected
    u32 flag_value = 0;
    if (rando_is_connected())
    {
        flag_value = rando_get_datastorage_u32_sync(key);
    }
    DEBUG_PRINTF("FLAG READ: data storage returned value=%lu\n", flag_value);

    // Return 1 if flag is set, 0 otherwise
    return flag_value ? 1 : 0;
}

RECOMP_PATCH void func_80024038_24C38(s32 flag_id)
{
    // Create key string for this flag
    char key[16];
    sprintf(key, "flag_%ld", flag_id);

    // Write to data storage only if connected
    if (rando_is_connected())
    {
        rando_set_datastorage_u32_async(key, 1);
    } // If flag is within bounds of D_8015C608_15D208 (0x304 bytes = 6144 flags max)
    if (flag_id >= 0 && flag_id <= ((0x304 * 8) - 1))
    {
        s32 byte_index;
        s32 bit_index;
        u8 current_byte;
        u8 bit_mask;

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

        DEBUG_PRINTF("FLAG SET: flag_id=%ld written to BOTH local array and datastore\n", flag_id);
    }
    else
    {
        DEBUG_PRINTF("FLAG SET: flag_id=%ld is OUTSIDE bounds, written to datastore only\n", flag_id);
    }
}

RECOMP_PATCH void func_80024088_24C88(int bit_index)
{
    // Create key string for this flag
    char key[16];
    sprintf(key, "flag_%d", bit_index);

    // Clear in data storage only if connected
    if (rando_is_connected())
    {
        rando_set_datastorage_u32_async(key, 0);
    } // If flag is within bounds of D_8015C608_15D208 (0x304 bytes = 6144 flags max)
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

        DEBUG_PRINTF("FLAG CLEAR: flag_id=%d cleared from BOTH local array and datastore\n", bit_index);
    }
    else
    {
        DEBUG_PRINTF("FLAG CLEAR: flag_id=%d is OUTSIDE bounds, cleared from datastore only\n", bit_index);
    }
}



// s32 func_800240DC_24CDC(s32 flag_id) {
//     s32 byte_index;
//     s32 bit_index;
//     u8 byte_value;
//     s32 bit_mask;
//     s32 result;
    
//     // Calculate byte index - divide by 8 with sign-aware right shift
//     if (flag_id < 0) {
//         byte_index = (flag_id + 7) >> 3;  // Add 7 before shifting for negative numbers
//     } else {
//         byte_index = flag_id >> 3;  // Simple right shift for positive numbers
//     }
    
//     // Mask to ensure byte_index is within u8 range
//     byte_index &= 0xFF;
    
//     // Load the byte from the data array
//     byte_value = D_8015C608_15D208[byte_index];
    
//     // Calculate bit position within the byte
//     if (flag_id < 0) {
//         bit_index = flag_id & 7;
//         if (bit_index != 0) {
//             bit_index -= 8;  // Adjust for negative numbers
//         }
//     } else {
//         bit_index = flag_id & 7;
//     }
    
//     // Mask to ensure bit_index is within u8 range
//     bit_index &= 0xFF;
    
//     // Create bit mask by shifting 1 left by bit_index positions
//     bit_mask = 1 << bit_index;
    
//     // Check if the bit is set
//     result = byte_value & bit_mask;
    
//     // Mask result to u8 and return
//     return result & 0xFF;
// }