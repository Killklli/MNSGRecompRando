#include "recompui.h"
#include "apconnect_ui.h"
#include "menus.h"
#include "Archipelago.h"
#include "recomputils.h"
#include "types.h"
#include "libc/string.h"
#include "libc/stdio.h"
#include "file_state.h"


RECOMP_IMPORT(".", void rando_init(char *game, char *address, char *player_name, char *password));
RECOMP_IMPORT(".", void rando_get_location_item_name(u32 location_id, char* item_name));
RECOMP_IMPORT(".", void rando_get_slotdata_raw_o32(const char* key, u32* out_handle_ptr));
RECOMP_IMPORT(".", void rando_access_slotdata_raw_dict_o32(u32* in_handle_ptr, const char* key, u32* out_handle_ptr));
RECOMP_IMPORT(".", u32 rando_access_slotdata_raw_u32_o32(u32* in_handle_ptr));
RECOMP_IMPORT(".", void rando_access_slotdata_raw_array_o32(u32* in_handle_ptr, u32 index, u32* out_handle_ptr));
typedef u32 SlotdataVal[2];

RECOMP_IMPORT(".", void rando_access_slotdata_raw_string_o32(u32* slotdata_str, char* out_str));
RECOMP_IMPORT(".", void rando_iter_slotdata_raw_dict_o32(u32* dict, u32* iter_out));
RECOMP_IMPORT(".", bool rando_iter_slotdata_raw_dict_next_o32(u32* dict, u32* iter, u32* key_out, u32* value_out));
static bool metadata_parsed = false;
static bool has_connected_successfully = false;

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
            has_connected_successfully = true;
            recompui_hide_context(connect_menu.context);
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
    recompui_show_context(connect_menu.context);
}
RECOMP_HOOK("func_80002040_2C40")
void ap_watcher()
{
    static bool scouts_sent = false;
    static bool ui_closed_after_setup = false;
    
    if (rando_is_connected())
    {
        static bool slot_name_printed = false;
        if (!rando_is_scouted() && !scouts_sent)
        {
            recomp_printf("Rando connected, sending queued scouts\n");
           rando_queue_scouts_all();
            rando_send_queued_scouts(0);
            recomp_printf("Scouts sent\n");
            scouts_sent = true;
            if (!slot_name_printed) {
                char slot_name[256];
                rando_get_own_slot_name(slot_name);
                recomp_printf("Own slot name: %s\n", slot_name);
                slot_name_printed = true;
            }
            // rando_send_location(81);

        }
        
        // Close UI after connection and scouting are complete
        if (rando_is_scouted() && scouts_sent && !ui_closed_after_setup)
        {
            recomp_printf("Connection and scouting complete, closing UI\n");
            recompui_hide_context(connect_menu.context);
            ui_closed_after_setup = true;
        }
    }
    else{
        // If we're not connected but have successfully connected before, re-open the context window
        if (has_connected_successfully) {
            recomp_printf("Connection lost, re-opening connect menu\n");
            recompui_show_context(connect_menu.context);
            has_connected_successfully = false; // Reset flag to avoid repeatedly opening
            ui_closed_after_setup = false; // Reset so UI can be closed again after reconnection
        }
    }
}
