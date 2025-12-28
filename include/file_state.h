#pragma once

#include "types.h"
#include "libc/stdbool.h"

// Global flag to track if we're in a file (save data loaded)
extern bool file_started;

// Function to check if we should run AP logic (connected, scouted, and in file)
bool should_run_ap_logic();

// Function to set the file started flag
void set_file_started();