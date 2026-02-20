#include "extended_save.h"

// Extended save data for flags outside the main array range
// Calculate size needed for flags beyond 0x304 * 8 (up to reasonable limit)
static u8 extended_save[EXTENDED_SAVE_SIZE];
static int extended_save_initialized = 0;

// Initialize extended save array
void init_extended_save(void) {
    if (!extended_save_initialized) {
        for (int i = 0; i < EXTENDED_SAVE_SIZE; i++) {
            extended_save[i] = 0;
        }
        extended_save_initialized = 1;
    }
}

// Get a byte from the extended save array
u8 get_extended_save_byte(int index) {
    init_extended_save();

    if (index >= 0 && index < EXTENDED_SAVE_SIZE) {
        return extended_save[index];
    }

    return 0; // Return 0 for out-of-bounds access
}

// Set a byte in the extended save array
void set_extended_save_byte(int index, u8 value) {
    init_extended_save();

    if (index >= 0 && index < EXTENDED_SAVE_SIZE) {
        extended_save[index] = value;
    }
}

// Get the size of the extended save array
int get_extended_save_size(void) { return EXTENDED_SAVE_SIZE; }