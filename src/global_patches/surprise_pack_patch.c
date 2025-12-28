// Adjusts the surprise pack entity event to use our custom scenario script PER surprise pack collection.
// We can't just set a scenario script because it needs to be triggered only when the surprise pack is collected.
#include "modding.h"
#include "common.h"
#include "recomputils.h"
#include "types.h"

// External function declarations
extern void func_80221F70_5DD440(void);
extern void func_8003D310_3DF10(s32 param);
extern void func_80218DA8_5D4278(void *entity, s32 param2, s32 param3, s32 param4);
extern void func_8021A22C_5D56FC(void *entity);
extern void func_80024038_24C38(u16 param);
extern void func_8003521C_35E1C(void *callback);
extern void func_080004AC_6AEC8C(void);
extern void replace_surprise_pack_scenario(s32 scenario_id, s32 *scenario_code, s16 scenario_file_id);
extern s32 scenario_code_surprise_pack[];

typedef struct
{
    u8 pad_0x00[0x4C];
    u8 field_0x4C; // +0x4C
    u8 pad_0x4D[0x13];
    u32 field_0x60; // +0x60
    u8 pad_0x64[0x04];
    u32 flags; // +0x68
    u8 pad_0x6C[0x64];
    u16 field_0xD0; // +0xD0
    u8 pad_0xD2[0x12];
    void *field_0xE4; // +0xE4
} Entity;

typedef struct
{
    u8 pad_0x00[0x16];
    u16 field_0x16; // +0x16
} ParameterStruct;

RECOMP_PATCH void func_080009F4_6AF1D4(Entity *entity, ParameterStruct *param)
{
    u16 temp;
    void *entityData;

    // Increment the field at offset 0x16 by 4 and mask to 0x3FF
    temp = param->field_0x16 + 4;
    param->field_0x16 = temp & 0x3FF;

    // Check if bit 0x200 is set in entity flags
    if (entity->flags & 0x200)
    {
        // Call various functions to handle the entity state
        func_80221F70_5DD440();
        replace_surprise_pack_scenario(0x064, scenario_code_surprise_pack, 0x05d);
        func_8003D310_3DF10(0x64);
        func_80218DA8_5D4278(entity, 0, 0, 0);
        func_8021A22C_5D56FC(entity);

        // Clear the field at offset 0x60
        entity->field_0x60 = 0;

        func_80024038_24C38(entity->field_0xD0);

        // Check if there's data at offset 0xE4
        entityData = entity->field_0xE4;
        if (entityData != NULL)
        {
            // Set a byte at offset 0xD0 of the entity data to 1
            *(u8 *)((u8 *)entityData + 0xD0) = 1;
        }

        // Schedule a callback function
        func_8003521C_35E1C(func_080004AC_6AEC8C);
    }
}