#include "Archipelago.h"
#include "common.h"
#include "modding.h"
#include "recomputils.h"
#include "save_data_tool.h"
#include "types.h"

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

// Function to count collected keys of a specific type from archipelago
u8 count_collected_keys(u8 lock_type)
{
    u32 has_keys = 0;

    // Only check Archipelago items if connected
    if (!rando_is_connected())
    {
        return 0;
    }

    switch (lock_type)
    {
    case 2:                                 // Silver keys
        has_keys = rando_has_item(6464000); // Silver
        break;
    case 1:                                 // Gold keys
        has_keys = rando_has_item(6464001); // Gold
        break;
    case 0:                                 // Diamond keys
        has_keys = rando_has_item(6464002); // Diamond
        break;
    default:
        return 0;
    }

    DEBUG_PRINTF("Taglink items status for type %d: count=%d\n", lock_type,
                 has_keys);
    return (u8)has_keys;
}

// Function to get used key count from save data bytes
u8 get_used_key_count(u8 lock_type)
{
    u8 save_byte;

    switch (lock_type)
    {
    case 2: // Silver keys - save byte 0x37
        save_byte = 0x37;
        break;
    case 1: // Gold keys - save byte 0x38
        save_byte = 0x38;
        break;
    case 0: // Diamond keys - save byte 0x39
        save_byte = 0x39;
        break;
    default:
        return 0;
    }

    return READ_SAVE_DATA_B(save_byte);
}

// Function to get available (unused) key count
u8 get_key_count(u8 lock_type)
{
    u8 collected = count_collected_keys(lock_type);
    u8 used = get_used_key_count(lock_type);

    if (collected > used)
    {
        return collected - used;
    }
    return 0;
}

// Function to increment used key count in save data bytes
void increment_used_key_count(u8 lock_type)
{
    u8 save_byte;

    switch (lock_type)
    {
    case 2: // Silver keys - save byte 0x37
        save_byte = 0x37;
        break;
    case 1: // Gold keys - save byte 0x38
        save_byte = 0x38;
        break;
    case 0: // Diamond keys - save byte 0x39
        save_byte = 0x39;
        break;
    default:
        return;
    }

    u8 current_used = READ_SAVE_DATA_B(save_byte);
    WRITE_SAVE_DATA_B(save_byte, current_used + 1);
    DEBUG_PRINTF(
        "Incremented used key count for type %d (save byte 0x%02X) from %d to "
        "%d\n",
        lock_type, save_byte, current_used, current_used + 1);
}

void calculate_key_on_pause()
{
    u8 diamond_keys = get_key_count(0);
    u8 gold_keys = get_key_count(1);
    u8 silver_keys = get_key_count(2);
    if (diamond_keys > 0 || gold_keys > 0 || silver_keys > 0)
    {
        WRITE_SAVE_DATA(SAVE_KEY_ON_PAUSE, 1);
    }
    else
    {
        WRITE_SAVE_DATA(SAVE_KEY_ON_PAUSE, 0);
    }
}

RECOMP_PATCH void func_08001020_6F4500(void *entity_ptr, void *arg1)
{
    u8 *entity = (u8 *)entity_ptr;
    s32 (*flag_check_func)(u16) = func_800240DC_24CDC;
    u16 field_0xDA;
    u32 flags;
    u8 state;

    // Load field at offset 0xDA
    field_0xDA = *(u16 *)(entity + 0xDA);

    // If field_0xDA is non-zero, set bit 2 in flags at offset 0xEC
    if (field_0xDA != 0)
    {
        flags = *(u32 *)(entity + 0xEC);
        *(u32 *)(entity + 0xEC) = flags | 0x4;
    }

    // Load flags and check if bit 2 is set
    flags = *(u32 *)(entity + 0xEC);
    if (!(flags & 0x4))
    {
        return;
    }
    u8 lock_type = *(u8 *)(entity + 0xD1);
    DEBUG_PRINTF("Entity lock type: %d\n", lock_type);
    // Lock Type 0 = Diamond
    // Lock Type 1 = Gold
    // Lock Type 2 = Silver
    // Lock Type 3 = Special

    // If the lock type is 3 and D6 is 0xFFFF, skip checking D4 and D6
    if (lock_type != 3 && *(u16 *)(entity + 0xD6) != 0xFFFF)
    {
        u8 temp_flag_d4 = flag_check_func(*(u16 *)(entity + 0xD4));
        DEBUG_PRINTF("Flag check returned: %d\n", temp_flag_d4);
        DEBUG_PRINTF("Checking flag for 0x%04X at D4\n", *(u16 *)(entity + 0xD4));
        // Check flag for field at offset 0xD4
        if (flag_check_func(*(u16 *)(entity + 0xD4)) != 0)
        {
            // PROBABLY for a different key type
            DEBUG_PRINTF("D4");
            DEBUG_PRINTF("Item collection flag triggered for 0x%04X\n",
                         *(u16 *)(entity + 0xD4));
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

        DEBUG_PRINTF("Lock type: %d, Collected: %d, Used: %d, Available: %d\n",
                     lock_type, collected_keys, used_keys, available_keys);

        if (available_keys > 0)
        {
            DEBUG_PRINTF("Using key of type %d\n", lock_type);

            // Increment the used key count
            increment_used_key_count(lock_type);

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
    else if (lock_type == 3 && *(u16 *)(entity + 0xD6) == 0x027)
    {
        DEBUG_PRINTF("Attempting to open jump gym\n");
        // We use the ID because we use the other value for the pause menu key
        // tracking
        if (rando_is_connected() && rando_has_item(6464003) > 0)
        {
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

    // Handle different states - only call func_8003D310_3DF10 if
    // func_8003F1D8_3FDD8 returns 0
    if (state == 0)
    {
        if (func_8003F1D8_3FDD8() == 0)
        {
            func_8003D310_3DF10(0x89);
        }
    }
    else if (state == 1)
    {
        if (func_8003F1D8_3FDD8() == 0)
        {
            func_8003D310_3DF10(0x88);
        }
    }
    else if (state == 2)
    {
        if (func_8003F1D8_3FDD8() == 0)
        {
            func_8003D310_3DF10(0x87);
        }
    }
    else if (state == 3)
    {
        if (func_8003F1D8_3FDD8() == 0)
        {
            func_8003D310_3DF10(0x32);
        }
    }

    // Load flags again after potential modifications
    flags = *(u32 *)(entity + 0xEC);

    // Clear field_0xDA (set to 0)
    *(u16 *)(entity + 0xDA) = 0;

    // If bit 2 is set in flags, clear it. Otherwise, set up callback to re-run
    // this function
    if (flags & 0x4)
    {
        *(u32 *)(entity + 0xEC) = flags & ~0x4; // Clear bit 2
    }
    else
    {
        func_8003521C_35E1C(func_08001020_6F4500);
    }
}
