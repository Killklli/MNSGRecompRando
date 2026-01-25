#pragma once

#include "types.h"

// Actor management and file overlay structures
typedef struct OverlayRedirection {
    unsigned short file_id;
    void *redirected_data;  // OverlayRedirection owns this pointer
} OverlayRedirection;

// Configuration for room-specific instance creation
typedef struct RoomInstanceConfig {
    unsigned short room_id;
    int instance_count;
    unsigned int marker_value;  // Marker to identify instances for this room
} RoomInstanceConfig;