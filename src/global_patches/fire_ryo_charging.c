// Splits up fire ryo charging so other chargable attacks can still be used without having fire ryo
#include "file_state.h"
#include "save_data_tool.h"
#include "recomputils.h"

// External references
extern s32 D_8015C5D8_15D1D8[]; // Global state array
extern s32 D_8015C5DC_15D1DC[]; // Primary controller/flag array (added for patch)
extern s32 D_8015C6DC[];        // Secondary controller array
extern s32 D_8015C604;          // Global state
extern u16 D_800C7DB2[];        // Controller input array (indexed by controller)

// Function prototypes
extern s32 func_801E7E40_5A3D50(void *entity);
extern s32 func_801E7DE8_5A3CF8(void *entity);
extern s32 func_801E7F30_5A3E40(void *entity);
extern void func_801DC498_5983A8(void *entity);
extern void func_80038BC8_397C8(s32 soundId);
extern void func_801E8964_5A4874(void *entity, s32 actionType);

RECOMP_PATCH s32 func_801DC27C_59818C(void *entity)
{
    u8 *entityData;
    u8 *entityStruct;
    u16 *counter;
    u8 entityType;
    u8 controllerIdx;
    s32 gameMode;
    u16 inputData;
    u16 currentCounter;

    entityData = (u8 *)entity;

    // Check if timer at offset 0xC is positive
    if (D_8015C5D8_15D1D8[3] <= 0)
    {
        entityStruct = *(u8 **)(entityData + 0x5C);
        *(u16 *)(entityStruct + 0x36) = 0;
        return 0;
    }

    entityType = entityData[0x60];

    // If entity type is 3 (special character?)
    if (entityType == 3)
    {
        gameMode = D_8015C5D8_15D1D8[11]; // offset 0x2C

        // If game mode is 2, clear counter and return 0
        if (gameMode == 2)
        {
            entityStruct = *(u8 **)(entityData + 0x5C);
            *(u16 *)(entityStruct + 0x36) = 0;
            return 0;
        }

        // Call entity check function
        if (func_801E7E40_5A3D50(entity))
        {
            entityStruct = *(u8 **)(entityData + 0x5C);
            *(u16 *)(entityStruct + 0x36) = 0;
            return 0;
        }
    }
    else
    {
        // For other entity types, check game mode
        gameMode = D_8015C5D8_15D1D8[11]; // offset 0x2C
        if (gameMode == 3)
        {
            controllerIdx = entityData[0x90];
            // Check if controller data exists - now checks BOTH arrays (matches ASM patch)
            // Original: if (D_8015C6DC[controllerIdx] == 0)
            // Patched:  if ((D_8015C5DC_15D1DC[controllerIdx] | D_8015C6DC[controllerIdx]) == 0)
            if ((D_8015C5DC_15D1DC[controllerIdx] | D_8015C6DC[controllerIdx]) == 0)
            {
                entityStruct = *(u8 **)(entityData + 0x5C);
                *(u16 *)(entityStruct + 0x36) = 0;
                return 0;
            }
        }
    }

    // Check entity state functions
    if (func_801E7DE8_5A3CF8(entity))
    {
        return 0;
    }

    if (func_801E7F30_5A3E40(entity))
    {
        return 0;
    }

    // === B BUTTON CHECK ===
    controllerIdx = entityData[0x90];
    inputData = D_800C7DB2[controllerIdx * 3];

    // Check if B button (0x4000) is pressed
    if (inputData & 0x4000)
    {
        // B button is held down!
        entityStruct = *(u8 **)(entityData + 0x5C);
        counter = (u16 *)(entityStruct + 0x36);
        (*counter)++;

        // Call function that handles B button press
        func_801DC498_5983A8(entity);

        // Handle entity type 3 special logic
        if (entityType == 3)
        {
            if (D_8015C604 == 1)
            {
                // For entityType 3 with D_8015C604 == 1, trigger action but skip sound check
                func_801E8964_5A4874(entity, 0x11);
                // Skip to counter check section
                goto counter_check;
            }
        }
        if (D_8015C604 == 3)
        {
            // Check if counter is exactly 15 frames (0xF) to play sound (for all entity types except the special case above)
            currentCounter = *counter;
            if (currentCounter == 0xF)
            {
                // Play sound and trigger action
                func_80038BC8_397C8(0x24C);
                func_801E8964_5A4874(entity, 0x11);
            }
        }
    counter_check:
        // Check counter values for different states
        currentCounter = *counter;

        if (currentCounter == 0x3C)
        { // 60 frames = 1 second at 60fps
            if (entityType == 3 && D_8015C604 == 3)
            {
                func_801E8964_5A4874(entity, 0x1C);
            }
        }

        if (currentCounter >= 0x3C)
        {
            return 2; // Long press state
        }
        else if (currentCounter >= 0xF)
        {             // 15 frames = 0.25 seconds
            return 1; // Short press state
        }
        else
        {
            return 0; // Just started pressing
        }
    }
    else
    {
        // B button not pressed - reset counter
        entityStruct = *(u8 **)(entityData + 0x5C);
        counter = (u16 *)(entityStruct + 0x36);

        if (*counter >= 0x3C)
        {
            *counter = 0;
            return 3; // Released after long press
        }

        *counter = 0;
        return 0;
    }
}