#ifndef EXTENDED_SAVE_H
#define EXTENDED_SAVE_H

#include "types.h"

// Extended save configuration
#define EXTENDED_SAVE_SIZE 0x200 // 512 bytes for extended flags

// Function declarations
void init_extended_save(void);
u8 get_extended_save_byte(int index);
void set_extended_save_byte(int index, u8 value);
int get_extended_save_size(void);

#endif // EXTENDED_SAVE_H