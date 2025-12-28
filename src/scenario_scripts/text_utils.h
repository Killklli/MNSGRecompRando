#ifndef TEXT_UTILS_H
#define TEXT_UTILS_H

#include "types.h"

// Function to convert character to CHR_ constant
s16 char_to_chr(char c);

// Function to dynamically create "Received [item]!" text
s16 *create_received_text(const char *item_name);

#endif // TEXT_UTILS_H