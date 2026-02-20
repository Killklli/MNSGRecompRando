#include "Archipelago.h"
#include "common_structs.h"
#include "file_state.h"
#include "libc/stdio.h"
#include "modding.h"
#include "recomputils.h"
#include "types.h"

// External declarations for surprise pack scenario
extern void replace_surprise_pack_scenario(s32 scenario_id, s32 *scenario_code, s16 scenario_file_id, const char *item_name);
extern s32 scenario_code_surprise_pack[];

// External function declarations
extern void func_8000F5F8_101F8(s32 sound_id, void *param1, f32 x, f32 y, f32 z, f32 param6);
extern void func_8003D310_3DF10(s32 param);
extern void func_8021A22C_5D56FC(void *entity);
extern PARTICLE_TASK_W *func_8021804C_5D351C(void *entity, s32 param);
extern void func_80024038_24C38(s32 param);
extern s32 func_8003F1D8_3FDD8(void);
extern void func_8000B824_C424(void);
extern void func_80034ED4_35AD4(void);
extern void func_80216E1C_5D22EC(void *entity, s32 param);
extern void func_80218DA8_5D4278(void *entity, s32 param1, s32 param2, s32 param3);
extern void func_80219E70_5D5340(void *entity, s32 param1, s32 param2);
// External data declarations
extern void *D_08000860_726490;

#define GINNEKO_FLAG_IN_AIR 0x0020
#define GINNEKO_FLAG_TOUCHED 0x0200

#define GINNEKO_PHASE_INIT 0
#define GINNEKO_PHASE_UPDATE 1
#define GINNEKO_PHASE_DESTROY 2

#define GINNEKO_BLOOP_SOUND_ID 0x2A5

RECOMP_PATCH void func_08000060_725C90(GINNEKO_TASK_W *ginneko, CLS_BG_W *obj) {
    GINNEKO_STATE_W *state;
    unsigned char phase;

    phase = ginneko->state.phase;
    if (phase != GINNEKO_PHASE_INIT) {
        state = &ginneko->state;
        switch (phase) {
        case GINNEKO_PHASE_UPDATE:
            /* Rotate the object slowly */
            obj->rotation.y = (obj->rotation.y + 4) & 0x3FF;
            /* Play bloop sound when cat doll lands on floor */
            if ((state->sound_played == 0) && !(ginneko->flags & GINNEKO_FLAG_IN_AIR)) {
                func_8000F5F8_101F8(GINNEKO_BLOOP_SOUND_ID, D_08000860_726490, obj->position.x, obj->position.y, obj->position.z, 400.0f);
                /* Create particles as soon as surprise pack lands */
                ginneko->particle_task = func_8021804C_5D351C(ginneko, 1);
                state->sound_played = 1;
            }
            /* Transition to landed state when grounded */
            if (ginneko->flags & GINNEKO_FLAG_TOUCHED) {
                // flag id 0xE0
                u32 flag_id = 0xE0;
                // Check AP logic for this surprise pack
                if (should_run_ap_logic()) {
                    // Convert flag to string key
                    char flag_str[16];
                    sprintf(flag_str, "%lu", flag_id);
                    DEBUG_PRINTF("Surprise Pack flag ID: %d\n", flag_id);
                    // Get the flag_id_to_ap_location_id dictionary from slot data
                    u32 flag_to_location_handle[2];
                    rando_get_slotdata_raw_o32("flag_id_to_ap_location_id", flag_to_location_handle);

                    // Try to get the location_id value for this flag directly
                    u32 location_id_handle[2];
                    rando_access_slotdata_raw_dict_o32(flag_to_location_handle, flag_str, location_id_handle);

                    // Check if we got a valid handle (non-zero indicates success)
                    if (location_id_handle[0] != 0 || location_id_handle[1] != 0) {
                        // Extract the integer value
                        u32 location_id = rando_access_slotdata_raw_u32_o32(location_id_handle);

                        DEBUG_PRINTF("Surprise Pack flag %d maps to location_id: %d\n", flag_id, location_id);

                        // Check if it's not our local item
                        bool has_local_item = rando_get_location_has_local_item(location_id);

                        if (has_local_item) {
                            // Get the player
                            char player[17];
                            rando_get_location_item_player(location_id, player);
                            DEBUG_PRINTF("got player %s\n", player);

                            // Get the item at the location
                            u32 item_id = rando_get_item_at_location(location_id);

                            // Get the item name
                            char item_name[33];
                            rando_get_item_name_from_id(item_id, item_name);

                            DEBUG_PRINTF("Item at location %d: 0x%08X (%s)\n", location_id, item_id, item_name);

                            // Create formatted message: "Player's Item_name"
                            char surprise_message[64];
                            sprintf(surprise_message, "%s's %s", player, item_name);

                            replace_surprise_pack_scenario(0x064, scenario_code_surprise_pack, 0x05d, surprise_message);
                        } else {
                            DEBUG_PRINTF("Location %d has local item\n", location_id);
                        }
                    } else {
                        DEBUG_PRINTF("Flag %d not found in flag_id_to_ap_location_id mapping\n", flag_id);
                        replace_surprise_pack_scenario(0x064, scenario_code_surprise_pack, 0x05d, "a Surprise Pack");
                    }
                } else {
                    replace_surprise_pack_scenario(0x064, scenario_code_surprise_pack, 0x05d, "a Surprise Pack");
                }

                DEBUG_PRINTF("Ginneko landed, transitioning to LANDED phase\n");
                /* Transition to landed state when touched */
                if (ginneko->flags & GINNEKO_FLAG_TOUCHED) {
                    func_8003D310_3DF10(0x64);
                    func_8021A22C_5D56FC(ginneko);
                    (void)func_8021804C_5D351C(ginneko, 0);
                    func_80024038_24C38(0xE0);
                    ginneko->unk_60 = 0;

                    /* Stop particle effect */
                    if (ginneko->particle_task != NULL) {
                        ginneko->particle_task->stop = 1;
                    }

                    state->phase = GINNEKO_PHASE_DESTROY;
                    return;
                }
                return;
            }
            return;
        case GINNEKO_PHASE_DESTROY:
            /* Cleanup after landing */
            if (func_8003F1D8_3FDD8() == 0) {
                func_8000B824_C424();
                func_80034ED4_35AD4();
            }
            break;
        }
    } else {
        /* Initialize cat doll - spawn in sky and begin falling */
        ginneko->task.unk_4c = 8;
        ginneko->model_id = 0x91;
        ginneko->actor_id = 1;
        ginneko->unk_60 = 0x02C007E0;
        func_80216E1C_5D22EC(ginneko, 0);
        obj->scale.x = 0.02f;
        obj->scale.y = 0.02f;
        obj->scale.z = 0.02f;
        func_80218DA8_5D4278(ginneko, 0x1F4, 0x32, 0);
        func_80219E70_5D5340(ginneko, 8, 0);
        // func_8021A310_5D57E0(ginneko);
        ginneko->state.phase = GINNEKO_PHASE_UPDATE;
    }
}
