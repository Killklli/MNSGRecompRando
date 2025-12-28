#include "modding.h"
#include "libc/stdbool.h"
#include "libc/stdint.h"
#include "types.h"
RECOMP_IMPORT(".", bool rando_is_connected());
RECOMP_IMPORT(".", bool rando_connect_failed());
RECOMP_IMPORT(".", bool rando_is_scouted());
RECOMP_IMPORT(".", u32 rando_get_datastorage_u32_sync(char* key));
RECOMP_IMPORT(".", void rando_set_datastorage_u32_sync(char* key, u32 value));
RECOMP_IMPORT(".", void rando_set_datastorage_u32_async(char* key, u32 value));
RECOMP_IMPORT(".", bool rando_has_item(u32 item_id));
RECOMP_IMPORT(".", bool rando_has_item_async(u32 item_id));
RECOMP_IMPORT(".", u32 rando_get_items_size());
RECOMP_IMPORT(".", u32 rando_get_item(u32 item_i));
RECOMP_IMPORT(".", u32 rando_get_item_type(u32 item_i));
RECOMP_IMPORT(".", bool rando_send_location(u32 location_id));
RECOMP_IMPORT(".", bool rando_location_exists(u32 location_id));
RECOMP_IMPORT(".", bool rando_get_location_has_local_item(u32 location_id));
RECOMP_IMPORT(".", u32 rando_get_item_at_location(u32 location_id));
RECOMP_IMPORT(".", int rando_get_location_type(u32 location_id));
RECOMP_IMPORT(".", bool rando_location_is_checked(u32 location_id));
RECOMP_IMPORT(".", bool rando_location_is_checked_async(u32 location_id));
RECOMP_IMPORT(".", u32 rando_get_sending_player(u32 items_i));
RECOMP_IMPORT(".", u32 rando_get_slotdata_u32(char* key));
RECOMP_IMPORT(".", u32 rando_get_seed_name(char* seed_name_out, u32 buffer_size));
RECOMP_IMPORT(".", void rando_get_own_slot_name(char* out_str));
RECOMP_IMPORT(".", void rando_get_item_name_from_id(u32 item_id, char* out_str));
RECOMP_IMPORT(".", void rando_get_sending_player_name(u32 items_i, char* out_str));
RECOMP_IMPORT(".", void rando_queue_scout(u32 location));
RECOMP_IMPORT(".", void rando_queue_scouts_all());
RECOMP_IMPORT(".", void rando_remove_queued_scout(u32 location));
RECOMP_IMPORT(".", void rando_send_queued_scouts(int hint));
RECOMP_IMPORT(".", void rando_get_saved_apconnect(u8* save_dir, char* address, char* player_name, char* password));
RECOMP_IMPORT(".", void rando_set_saved_apconnect(u8* save_dir, char* address, char* player_name, char* password));
RECOMP_IMPORT(".", bool rando_complete_goal());