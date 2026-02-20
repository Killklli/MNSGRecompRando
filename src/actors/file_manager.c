#include "Archipelago.h"
#include "actor_common.h"
#include "common_structs.h"
#include "file_state.h"
#include "libc/stdbool.h"
#include "libc/stdio.h"
#include "libc/string.h"
#include "modding.h"
#include "types.h"

// Define constants
#define WAVE_MAX 48
#define ALIGN_4KB(addr) (((unsigned int)(addr) + 0xFFF) & 0xFFFFF000)
#define ALIGN_64B(addr) (((unsigned int)(addr) + 0x3F) & 0xFFFFFFC0)

// External data declarations
extern unsigned short D_800C7AB2; // Part of the huge "SYS_W" structure, ID of the current stage
extern u32 D_8015C5C8_15D1C8;     // Current level/index value
extern WAVE_W D_80167FC0_168BC0[WAVE_MAX];

// External function declarations
extern unsigned int func_80001DF4_29F4(unsigned short);
extern int func_80001C00_2800(unsigned short, int);
extern int func_800142BC_14EBC(unsigned short, int);

// Function declarations
void func_80013AC4_146C4(short *file_list);

RECOMP_PATCH void func_8020D6BC_5C8B8C(void) {
    u32 level_index;
    u32 base_offset;
    StageActorMetadata *level_struct;
    void *func_ptr;
    void *func_at_303C;

    // Get the current level index
    level_index = D_8015C5C8_15D1C8;

    // Calculate base offset (0x38000)
    base_offset = 0x38000;
    // print D_800C7AB2
    DEBUG_PRINTF("D_800C7AB2 (current room): 0x%03X\n", D_800C7AB2);
    // Print the level index and base offset
    DEBUG_PRINTF("Level Index: 0x%X, Base Offset: 0x%X\n", level_index, base_offset);
    // Get the level data structure from the array
    level_struct = D_80231300_5EC7D0[*(u16 *)((u8 *)level_index + base_offset + 0x2DF2)];

    // Extract function pointer from offset 0x18 in the structure
    func_ptr = *(void **)((char *)level_struct + 0x18);
    DEBUG_PRINTF("Function pointer at offset 0x18: %p\n", func_ptr);

    // Store the function pointer at computed address (0x3B03C + level_index)
    *(void **)(0x3B03C + level_index) = func_ptr;

    // Get and call the function at offset 0x303C
    func_at_303C = *(void **)((u8 *)level_index + base_offset + 0x303C);
    DEBUG_PRINTF("Function at offset 0x303C: %p\n", func_at_303C);

    // Check if we should use Archipelago data instead of calling the original
    // function
    static short ap_file_list[WAVE_MAX] = {0};
    bool use_ap_data = false;

    if (should_run_ap_logic()) {
        DEBUG_PRINTF("Archipelago connected, checking for room %d file list\n", D_800C7AB2);

        // Convert room ID to string for lookup
        char room_id_str[16];
        sprintf(room_id_str, "%d", D_800C7AB2);

        // Get room file data from Archipelago slot data
        u32 room_files_handle[2];
        rando_get_slotdata_raw_o32("room_file_data", room_files_handle);

        u32 current_room_files[2];
        rando_access_slotdata_raw_dict_o32(room_files_handle, room_id_str, current_room_files);

        // Check if we have valid room data
        u32 files_iter[2];
        rando_iter_slotdata_raw_dict_o32(current_room_files, files_iter);

        u32 test_file_key[2];
        u32 test_file_value[2];
        bool has_archipelago_data = rando_iter_slotdata_raw_dict_next_o32(current_room_files, files_iter, test_file_key, test_file_value);

        // Close the iterator after checking
        rando_iter_slotdata_raw_dict_close_o32(current_room_files, files_iter);

        if (has_archipelago_data) {
            // Clear the AP file list
            for (int i = 0; i < WAVE_MAX; i++) {
                ap_file_list[i] = 0;
            }

            // Fill AP file list with data from Archipelago first
            int file_count = 0;

            // Re-create the iterator for actual processing
            rando_iter_slotdata_raw_dict_o32(current_room_files, files_iter);

            u32 file_key[2];
            u32 file_value[2];

            while (rando_iter_slotdata_raw_dict_next_o32(current_room_files, files_iter, file_key, file_value) && file_count < WAVE_MAX - 2) {
                char value_str[256];
                rando_access_slotdata_raw_string_o32(file_value, value_str);

                // Debug: Print the raw string value before parsing
                DEBUG_PRINTF("Raw file value string: '%s'\n", value_str);

                // Convert file ID string to integer
                unsigned int file_id_int = 0;
                int i = 0;
                while (value_str[i] >= '0' && value_str[i] <= '9') {
                    file_id_int = file_id_int * 10 + (value_str[i] - '0');
                    i++;
                }

                if (file_id_int > 0) {
                    // Check if this file ID is not already in the list
                    bool already_exists = false;
                    for (int j = 0; j < file_count; j++) {
                        if (ap_file_list[j] == (short)file_id_int) {
                            already_exists = true;
                            break;
                        }
                    }

                    if (!already_exists) {
                        ap_file_list[file_count] = (short)file_id_int;
                        DEBUG_PRINTF("AP file %d: 0x%X\n", file_count, (unsigned short)ap_file_list[file_count]);
                        file_count++;
                    }
                }
            }

            // Close the iterator after processing
            rando_iter_slotdata_raw_dict_close_o32(current_room_files, files_iter);

            // Always inject safety file 0x01A at the END when connected to AP
            bool safety_file_exists = false;
            for (int j = 0; j < file_count; j++) {
                if (ap_file_list[j] == 0x01A) {
                    safety_file_exists = true;
                    break;
                }
            }
            // TODO: We should just do this via AP instead of here
            if (!safety_file_exists && file_count < WAVE_MAX - 1) {
                ap_file_list[file_count] = 0x01A;
                DEBUG_PRINTF("Safety file injected at end: 0x01A\n");
                file_count++;
            }
            // Ensure the list is properly null-terminated
            if (file_count < WAVE_MAX) {
                ap_file_list[file_count] = 0;
            }

            use_ap_data = (file_count > 0);
        }
    }

    // Call func_80013AC4_146C4 with appropriate data
    if (use_ap_data) {
        DEBUG_PRINTF("Using Archipelago file data\n");
        func_80013AC4_146C4(ap_file_list);
    } else {
        DEBUG_PRINTF("Using original function call\n");
        ((void (*)())func_at_303C)();
    }
}

RECOMP_PATCH int func_80013B14_14714(unsigned short wave_no) {
    WAVE_W *slot;
    int load_addr;
    int end_addr;
    int is_code_overlay;

    slot = D_80167FC0_168BC0;

    /* Search for existing overlay or first empty slot */
    if (D_80167FC0_168BC0[0].file_id != 0) {
        do {
            /* Found existing overlay - return its code address */
            if (slot->file_id == wave_no) {
                return slot[1].data;
            }

            slot++;

            /* Check if we've exceeded the slot array */
            if (slot > &D_80167FC0_168BC0[WAVE_MAX - 1]) {
                return 0;
            }
        } while (slot->file_id != 0);
    }

    /* Found empty slot - load overlay here */
    load_addr = slot->data;
    slot->file_id = wave_no;

    /* Check if overlay requires uncached memory access */
    is_code_overlay = func_80001DF4_29F4(wave_no);
    if (is_code_overlay != 0) {
        load_addr = ALIGN_4KB(load_addr);
        slot->data = load_addr;
    }

    /* Load file data from ROM */
    end_addr = func_80001C00_2800(slot->file_id, load_addr);

    /* Decompress PIC data if present */
    func_800142BC_14EBC(slot->file_id, load_addr);

    /* Initialize next slot with aligned end address */
    slot[1].file_id = 0;
    slot[1].data = ALIGN_64B(end_addr);

    return ALIGN_64B(end_addr);
}
