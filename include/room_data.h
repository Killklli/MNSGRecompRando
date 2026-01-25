#pragma once

#include "types.h"

// Configuration for room/stage file management
typedef struct
{
    unsigned short stage_id;
    short file_list[32]; // Null-terminated list of files
} stage_file_config_t;