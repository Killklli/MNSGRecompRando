#include "types.h"
#include "modding.h"
#include "recomputils.h"
#include "Archipelago.h"
#include "file_state.h"
#include "libc/stdio.h"

// Archipelago slotdata imports
RECOMP_IMPORT(".", void rando_get_slotdata_raw_o32(const char *key, u32 *out_handle_ptr));
RECOMP_IMPORT(".", void rando_access_slotdata_raw_dict_o32(u32 *in_handle_ptr, const char *key, u32 *out_handle_ptr));
RECOMP_IMPORT(".", u32 rando_access_slotdata_raw_u32_o32(u32 *in_handle_ptr));
RECOMP_IMPORT(".", void rando_get_location_item_player(u32 location_id, char *player));

// External declarations for surprise pack scenario
extern void replace_surprise_pack_scenario(s32 scenario_id, s32 *scenario_code, s16 scenario_file_id, const char *item_name);
extern s32 scenario_code_surprise_pack[];

// Forward declaration for PARTICLE_TASK_W
typedef struct PARTICLE_TASK_W PARTICLE_TASK_W;

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

typedef struct WAVE_W
{
    unsigned short wave_no;
    int data;
} WAVE_W;

typedef struct AMEM_W
{
    char *pt;
    unsigned int size;
    struct AMEM_W *next;
    struct AMEM_W *up;
} AMEM_W;

typedef struct TASK_W
{
    struct TASK_W *next;
    struct TASK_W *unk_4;
    void (*functions[3])(struct TASK_W *, void *);
    void (*previous_function)(struct TASK_W *, void *);
    void *unk_14;
    void *unk_1c;
    unsigned short priority;
    unsigned short unk_22;
    unsigned short timer;
    WAVE_W wave;
    unsigned char unk_30;
    unsigned char unk_31;
    unsigned char unk_32;
    unsigned char unk_33;
    unsigned int unk_34;
    unsigned int unk_38;
    unsigned short unk_3c;
    unsigned short unk_3e;
    unsigned short unk_40;
    unsigned short unk_42;
    unsigned char unk_44;
    unsigned char unk_45;
    unsigned char unk_46;
    unsigned char unk_47;
    unsigned int unk_48;
    unsigned char unk_4c;
    unsigned char unk_4d;
    unsigned short unk_4e;
    unsigned short unk_50;
    unsigned short unk_52;
    unsigned int unk_54;
    unsigned int unk_58;
} TASK_W;

typedef struct VEC3F_W
{
    float x;
    float y;
    float z;
} VEC3F_W;

typedef struct VEC3S_W
{
    signed short x;
    signed short y;
    signed short z;
} VEC3S_W;

typedef struct CLS_W
{
    struct CLS_W *next;
    unsigned char kind;
    unsigned char pri;
    unsigned short s_pri;
} CLS_W;

typedef struct CLS_BG_W
{
    CLS_W header;                // offset: 0x00, size: 0x08
    VEC3F_W position;            // offset: 0x08
    VEC3S_W rotation;            // offset: 0x14
    unsigned char unknown_1a[2]; // offset: 0x1A
    VEC3F_W scale;               // offset: 0x1C
    float animation_progress;    // offset: 0x28
    unsigned int graphics_1;     // offset: 0x2C
    void *graphics_2;            // offset: 0x30
    WAVE_W waves[6];             // offset: 0x34
    unsigned char unknown_64;    // offset: 0x64
    signed char unknown_65;      // offset: 0x65
    unsigned char unknown_66;    // offset: 0x66
    unsigned char unknown_67;    // offset: 0x67
    signed int unknown_68;       // offset: 0x68
    signed int unknown_6c;       // offset: 0x6C
    float unknown_70;            // offset: 0x70
    struct CLS_BG_W *left;       // offset: 0x74
    struct CLS_BG_W *right;      // offset: 0x78
    unsigned char unknown_7c[2]; // offset: 0x7C
    signed short unknown_7e;     // offset: 0x7E
    void *unknown_80;            // offset: 0x80
    unsigned short unknown_84;   // offset: 0x84
    unsigned char unknown_86;    // offset: 0x86
    unsigned char unknown_87;    // offset: 0x87
    VEC3F_W unknown_88;          // offset: 0x88
    struct CLS_BG_W *prev;       // offset: 0x94
} CLS_BG_W;

// -------------------------

// -------------------------

typedef struct PARTICLE_TASK_W
{
    TASK_W task;               // offset: 0x00, size: 0x5C
    unsigned short actor_id;   // offset: 0x5C
    unsigned short model_id;   // offset: 0x5E
    unsigned int unk_60;       // offset: 0x60
    unsigned char pad_64[4];   // offset: 0x64
    unsigned int flags;        // offset: 0x68
    unsigned char pad_6C[100]; // offset: 0x6C, size: 0x64
    unsigned char stop;        // offset: 0xD0
} PARTICLE_TASK_W;

// -------------------------

typedef struct GINNEKO_STATE_W
{
    unsigned char phase;        // offset: 0x00 (0xD0 in actor)
    unsigned char sound_played; // offset: 0x01 (0xD1 in actor)
} GINNEKO_STATE_W;

typedef struct GINNEKO_TASK_W
{
    TASK_W task;                    // offset: 0x00, size: 0x5C
    unsigned short actor_id;        // offset: 0x5C
    unsigned short model_id;        // offset: 0x5E
    unsigned int unk_60;            // offset: 0x60
    unsigned char pad_64[4];        // offset: 0x64
    unsigned int flags;             // offset: 0x68
    unsigned char pad_6C[100];      // offset: 0x6C, size: 0x64
    GINNEKO_STATE_W state;          // offset: 0xD0
    PARTICLE_TASK_W *particle_task; // offset: 0xD4
} GINNEKO_TASK_W;

#define GINNEKO_FLAG_IN_AIR 0x0020
#define GINNEKO_FLAG_TOUCHED 0x0200

#define GINNEKO_PHASE_INIT 0
#define GINNEKO_PHASE_UPDATE 1
#define GINNEKO_PHASE_DESTROY 2

#define GINNEKO_BLOOP_SOUND_ID 0x2A5

RECOMP_PATCH void func_08000060_725C90(GINNEKO_TASK_W *ginneko, CLS_BG_W *obj)
{
    GINNEKO_STATE_W *state;
    unsigned char phase;

    phase = ginneko->state.phase;
    if (phase != GINNEKO_PHASE_INIT)
    {
        state = &ginneko->state;
        switch (phase)
        {
        case GINNEKO_PHASE_UPDATE:
            /* Rotate the object slowly */
            obj->rotation.y = (obj->rotation.y + 4) & 0x3FF;
            /* Play bloop sound when cat doll lands on floor */
            if ((state->sound_played == 0) && !(ginneko->flags & GINNEKO_FLAG_IN_AIR))
            {
                func_8000F5F8_101F8(GINNEKO_BLOOP_SOUND_ID, D_08000860_726490, obj->position.x, obj->position.y, obj->position.z, 400.0f);
                /* Create particles as soon as surprise pack lands */
                ginneko->particle_task = func_8021804C_5D351C(ginneko, 1);
                state->sound_played = 1;
            }
            /* Transition to landed state when grounded */
            if (ginneko->flags & GINNEKO_FLAG_TOUCHED)
            {
                // flag id 0xE0
                u32 flag_id = 0xE0;
                // Check AP logic for this surprise pack
                if (should_run_ap_logic())
                {
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
                    if (location_id_handle[0] != 0 || location_id_handle[1] != 0)
                    {
                        // Extract the integer value
                        u32 location_id = rando_access_slotdata_raw_u32_o32(location_id_handle);

                        DEBUG_PRINTF("Surprise Pack flag %d maps to location_id: %d\n", flag_id, location_id);

                        // Check if it's not our local item
                        bool has_local_item = rando_get_location_has_local_item(location_id);

                        if (has_local_item)
                        {
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
                        }
                        else
                        {
                            DEBUG_PRINTF("Location %d has local item\n", location_id);
                        }
                    }
                    else
                    {
                        DEBUG_PRINTF("Flag %d not found in flag_id_to_ap_location_id mapping\n", flag_id);
                        replace_surprise_pack_scenario(0x064, scenario_code_surprise_pack, 0x05d, "a Surprise Pack");
                    }
                }
                else
                {
                    replace_surprise_pack_scenario(0x064, scenario_code_surprise_pack, 0x05d, "a Surprise Pack");
                }

                DEBUG_PRINTF("Ginneko landed, transitioning to LANDED phase\n");
                /* Transition to landed state when touched */
                if (ginneko->flags & GINNEKO_FLAG_TOUCHED)
                {
                    func_8003D310_3DF10(0x64);
                    func_8021A22C_5D56FC(ginneko);
                    (void)func_8021804C_5D351C(ginneko, 0);
                    func_80024038_24C38(0xE0);
                    ginneko->unk_60 = 0;

                    /* Stop particle effect */
                    if (ginneko->particle_task != NULL)
                    {
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
            if (func_8003F1D8_3FDD8() == 0)
            {
                func_8000B824_C424();
                func_80034ED4_35AD4();
            }
            break;
        }
    }
    else
    {
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
