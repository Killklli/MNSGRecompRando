#ifndef AP_DATASTORAGE_H
#define AP_DATASTORAGE_H

#include "libc/stdbool.h"
#include "types.h"

// Function declarations for save data synchronization
void update_full_save_data(void);
bool load_full_save_data_from_storage(void);
void save_player_data(void);

#endif // AP_DATASTORAGE_H