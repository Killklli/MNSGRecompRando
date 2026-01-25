#pragma once

#include "types.h"

// Game entity structures for surprise pack and other entity patches
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