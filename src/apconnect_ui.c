#include "recompui.h"
#include "apconnect_ui.h"
#include "menus.h"
#include "Archipelago.h"
#include "recomputils.h"
#include "types.h"

RECOMP_IMPORT(".", void rando_init(char *game, char *address, char *player_name, char *password));
RECOMP_IMPORT(".", void rando_get_location_item_name(u32 location_id, char* item_name));

// Function declarations
void setup_defaults();
void progressive_weapon_handler();

ApconnectMenu connect_menu;

static void connectPressed(RecompuiResource resource, const RecompuiEventData *event, void *userdata)
{
    recomp_printf("Connect button pressed\n");
    if (event->type == UI_EVENT_CLICK)
    {
        recomp_printf("Pressed connect.\n");
        char *server_text = recompui_get_input_text(connect_menu.server_textinput);
        char *slot_text = recompui_get_input_text(connect_menu.slot_textinput);
        char *password_text = recompui_get_input_text(connect_menu.password_textinput);
        rando_init("Mystical Ninja Starring Goemon", server_text, slot_text, password_text);
        recomp_free(server_text);
        recomp_free(slot_text);
        recomp_free(password_text);
        bool failure = rando_connect_failed();

        if (!failure)
        {
            recomp_printf("Successfully connected\n");
            recompui_hide_context(connect_menu.context);
            recompui_close_context(connect_menu.context);

            recompui_open_context(connect_menu.context);
        }
        else
        {
            recompui_close_context(connect_menu.context);
            recomp_printf("Failed to connect\n");
            recompui_open_context(connect_menu.context);
        }
    }
}

RecompuiResource create_spacer(RecompuiContext context, RecompuiResource parent, float flex_grow, float flex_shrink, float flex_basis)
{
    RecompuiResource ret = recompui_create_element(context, parent);

    recompui_set_flex_basis(ret, flex_basis, UNIT_DP);
    recompui_set_flex_grow(ret, flex_grow);
    recompui_set_flex_shrink(ret, flex_shrink);

    return ret;
}

void randoCreateAPConnectMenu()
{
    connect_menu.context = recompui_create_context();
    recompui_open_context(connect_menu.context);

    createUiFrame(connect_menu.context, &connect_menu.frame);

    // Create a label for the server address.
    connect_menu.server_label = recompui_create_label(connect_menu.context, connect_menu.frame.container, "Server Address:Port", LABELSTYLE_NORMAL);
    recompui_set_font_size(connect_menu.server_label, 30.0f, UNIT_DP);

    // Create a text input for the server address.
    connect_menu.server_textinput = recompui_create_textinput(connect_menu.context, connect_menu.frame.container);
    recompui_set_font_size(connect_menu.server_textinput, 30.0f, UNIT_DP);
    recompui_set_input_text(connect_menu.server_textinput, "localhost:38281");
    recompui_set_margin_top(connect_menu.server_textinput, 10.0f, UNIT_DP);
    recompui_set_margin_bottom(connect_menu.server_textinput, 20.0f, UNIT_DP);
    recompui_set_max_width(connect_menu.server_textinput, 100.0f, UNIT_PERCENT);

    // Create a label for the slotname.
    connect_menu.slotname_label = recompui_create_label(connect_menu.context, connect_menu.frame.container, "Slotname", LABELSTYLE_NORMAL);
    recompui_set_font_size(connect_menu.slotname_label, 30.0f, UNIT_DP);

    // Create a text input for the slotname.
    connect_menu.slot_textinput = recompui_create_textinput(connect_menu.context, connect_menu.frame.container);
    recompui_set_font_size(connect_menu.slot_textinput, 30.0f, UNIT_DP);
    recompui_set_input_text(connect_menu.slot_textinput, "Player1");
    recompui_set_margin_top(connect_menu.slot_textinput, 10.0f, UNIT_DP);
    recompui_set_margin_bottom(connect_menu.slot_textinput, 20.0f, UNIT_DP);
    recompui_set_max_width(connect_menu.slot_textinput, 100.0f, UNIT_PERCENT);

    // Create a label for the password.
    connect_menu.password_label = recompui_create_label(connect_menu.context, connect_menu.frame.container, "Password", LABELSTYLE_NORMAL);
    recompui_set_font_size(connect_menu.password_label, 30.0f, UNIT_DP);

    // Create a text input for the password.
    connect_menu.password_textinput = recompui_create_passwordinput(connect_menu.context, connect_menu.frame.container);
    recompui_set_font_size(connect_menu.password_textinput, 30.0f, UNIT_DP);
    recompui_set_input_text(connect_menu.password_textinput, "");
    recompui_set_margin_top(connect_menu.password_textinput, 20.0f, UNIT_DP);
    recompui_set_max_width(connect_menu.password_textinput, 100.0f, UNIT_PERCENT);

    // Create the connect button.
    connect_menu.connect_button = recompui_create_button(connect_menu.context, connect_menu.frame.container, "Connect", BUTTONSTYLE_SECONDARY);
    recompui_set_text_align(connect_menu.connect_button, TEXT_ALIGN_CENTER);
    recompui_set_margin_top(connect_menu.connect_button, 70.0f, UNIT_DP);
    recompui_register_callback(connect_menu.connect_button, connectPressed, NULL);

    recompui_close_context(connect_menu.context);
}

void ShowArchipelagoConnect()
{
    //recompui_show_context(connect_menu.context);
}
RECOMP_HOOK("func_80002040_2C40")
void ap_watcher()
{
    static bool scouts_sent = false;
    
    if (rando_is_connected())
    {
        if (!rando_is_scouted() && !scouts_sent)
        {
            recomp_printf("Rando connected, sending queued scouts\n");
           // rando_queue_scouts_all();
            //rando_send_queued_scouts(0);
            scouts_sent = true;
            setup_defaults();
            // u32 data = rando_get_item_id(0); // Dummy call to ensure imports are linked
            // // print the data
            // recomp_printf("Default item ID at location 0: %d\n", data);
            // rando_location_is_checked
            // Test: Print own slot name after scouting is complete
            static bool slot_name_printed = false;
            if (!slot_name_printed) {
                char slot_name[256];
                rando_get_own_slot_name(slot_name);
                recomp_printf("Own slot name: %s\n", slot_name);
                slot_name_printed = true;
            }
            // rando_send_location(81);

        }
        if (rando_is_scouted()){
            u32 item_at_81 = rando_get_item_at_location(6474000 + 10);
            recomp_printf("Item at location 82: %d\n", item_at_81);
        }
      u32 item_at_81 = rando_get_item_at_location(6474000 + 10);
            recomp_printf("Item at location 82: %d\n", item_at_81);
    }
}

void setup_defaults(){
    progressive_weapon_handler();
}


// #include "modding.h"

// RECOMP_IMPORT(".", bool rando_is_connected());
// RECOMP_IMPORT(".", bool rando_connect_failed());
// RECOMP_IMPORT(".", bool rando_is_scouted());
// RECOMP_IMPORT(".", u32 rando_get_datastorage_u32_sync(char* key));
// RECOMP_IMPORT(".", void rando_set_datastorage_u32_sync(char* key, u32 value));
// RECOMP_IMPORT(".", void rando_set_datastorage_u32_async(char* key, u32 value));
// RECOMP_IMPORT(".", bool rando_has_item(u32 item_id));
// RECOMP_IMPORT(".", bool rando_has_item_async(u32 item_id));
// RECOMP_IMPORT(".", u32 rando_get_items_size());
// RECOMP_IMPORT(".", u32 rando_get_item(u32 item_i));
// RECOMP_IMPORT(".", u32 rando_get_item_type(u32 item_i));
// RECOMP_IMPORT(".", bool rando_send_location(u32 location_id));
// RECOMP_IMPORT(".", bool rando_location_exists(u32 location_id));
// RECOMP_IMPORT(".", bool rando_get_location_has_local_item(u32 location_id));
// RECOMP_IMPORT(".", u32 rando_get_item_at_location(u32 location_id));
// RECOMP_IMPORT(".", int rando_get_location_type(u32 location_id));
// RECOMP_IMPORT(".", bool rando_location_is_checked(u32 location_id));
// RECOMP_IMPORT(".", bool rando_location_is_checked_async(u32 location_id));
// RECOMP_IMPORT(".", u32 rando_get_sending_player(u32 items_i));
// RECOMP_IMPORT(".", u32 rando_get_slotdata_u32(char* key));
// RECOMP_IMPORT(".", u32 rando_get_seed_name(char* seed_name_out, u32 buffer_size));
// RECOMP_IMPORT(".", void rando_get_own_slot_name(char* out_str));
// RECOMP_IMPORT(".", void rando_get_item_name_from_id(u32 item_id, char* out_str));
// RECOMP_IMPORT(".", void rando_get_sending_player_name(u32 items_i, char* out_str));
// RECOMP_IMPORT(".", void rando_queue_scout(u32 location));
// RECOMP_IMPORT(".", void rando_queue_scouts_all());
// RECOMP_IMPORT(".", void rando_remove_queued_scout(u32 location));
// RECOMP_IMPORT(".", void rando_send_queued_scouts(int hint));
// RECOMP_IMPORT(".", void rando_get_saved_apconnect(u8* save_dir, char* address, char* player_name, char* password));
// RECOMP_IMPORT(".", void rando_set_saved_apconnect(u8* save_dir, char* address, char* player_name, char* password));
// RECOMP_IMPORT(".", bool rando_complete_goal());