#include "modding.h"
#include "libc/stdbool.h"
#include "libc/stdint.h"
#include "types.h"
RECOMP_IMPORT(".", bool rando_is_connected());
RECOMP_IMPORT(".", bool rando_connect_failed());
RECOMP_IMPORT(".", bool rando_is_scouted());
RECOMP_IMPORT(".", u32 rando_get_datastorage_u32_sync(char* key));
RECOMP_IMPORT(".", void rando_get_datastorage_string_sync(char* key, char* out_str));
RECOMP_IMPORT(".", void rando_set_datastorage_u32_sync(char* key, u32 value));
RECOMP_IMPORT(".", void rando_set_datastorage_u32_async(char* key, u32 value));
RECOMP_IMPORT(".", void rando_set_datastorage_string_async(char* key, char* value));
RECOMP_IMPORT(".", u32 rando_has_item(u32 item_id));
RECOMP_IMPORT(".", u32 rando_has_item_async(u32 item_id));
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
RECOMP_IMPORT(".", u32 rando_get_own_slot_id());
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

// Raw slotdata access functions - commonly used across files
RECOMP_IMPORT(".", void rando_get_slotdata_raw_o32(const char* key, u32* out_handle_ptr));
RECOMP_IMPORT(".", void rando_access_slotdata_raw_dict_o32(u32* in_handle_ptr, const char* key, u32* out_handle_ptr));
RECOMP_IMPORT(".", u32 rando_access_slotdata_raw_u32_o32(u32* in_handle_ptr));
RECOMP_IMPORT(".", void rando_access_slotdata_raw_string_o32(u32* slotdata_str, char* out_str));
RECOMP_IMPORT(".", void rando_access_slotdata_raw_array_o32(u32* in_handle_ptr, u32 index, u32* out_handle_ptr));
RECOMP_IMPORT(".", bool rando_access_slotdata_raw_dict_has_member_o32(u32* dict, char* key));
RECOMP_IMPORT(".", void rando_iter_slotdata_raw_dict_o32(u32* dict, u32* iter_out));
RECOMP_IMPORT(".", bool rando_iter_slotdata_raw_dict_next_o32(u32* dict, u32* iter, u32* key_out, u32* value_out));
RECOMP_IMPORT(".", void rando_iter_slotdata_raw_dict_close_o32(u32* dict, u32* iter));

// Location and item functions
RECOMP_IMPORT(".", void rando_get_location_item_name(u32 location_id, char* item_name));
RECOMP_IMPORT(".", void rando_get_location_item_player(u32 location_id, char* player));
RECOMP_IMPORT(".", void rando_init(char* game, char* address, char* player_name, char* password));

// Death link functions
RECOMP_IMPORT(".", bool rando_get_death_link_enabled());
RECOMP_IMPORT(".", bool rando_get_death_link_pending());
RECOMP_IMPORT(".", void rando_reset_death_link_pending());
RECOMP_IMPORT(".", void rando_send_death_link());