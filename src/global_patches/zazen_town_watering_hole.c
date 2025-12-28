#include "types.h"
#include "modding.h"
#include "recomputils.h"

// Import struct definitions from turtle_rock.c
typedef struct WAVE_W
{
    unsigned short wave_no;
    int data;
} WAVE_W;

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

// Global struct containing spawn instance counter
typedef struct SPAWN_MANAGER_W {
    unsigned char      pad_00[0xD8];        // offset: 0x00
    unsigned char      instance_count;      // offset: 0xD8
} SPAWN_MANAGER_W;

extern SPAWN_MANAGER_W D_8015CC30_15D830;

// Parent actor that spawns child actors
typedef struct SPAWNER_ACTOR_W {
    TASK_W             task;                // offset: 0x00, size: 0x5C
    unsigned short     actor_id;            // offset: 0x5C
    unsigned short     model_id;            // offset: 0x5E
    unsigned int       unk_60;              // offset: 0x60
    unsigned char      pad_64[0x88];        // offset: 0x64, size: 0x88
    TASK_W*            spawned_actor;       // offset: 0xEC
} SPAWNER_ACTOR_W;

// Child actor that gets spawned
typedef struct SPAWNED_ACTOR_W {
    TASK_W             task;                // offset: 0x00, size: 0x5C
    unsigned short     actor_id;            // offset: 0x5C
    unsigned short     model_id;            // offset: 0x5E
    unsigned int       unk_60;              // offset: 0x60
    unsigned char      pad_64[4];           // offset: 0x64
    unsigned int       flags;               // offset: 0x68
    unsigned char      pad_6C[8];           // offset: 0x6C, size: 0x08
    unsigned char*     counter_ptr;         // offset: 0x74
    unsigned char      pad_78[0x58];        // offset: 0x78, size: 0x58
    unsigned int       unk_D0;              // offset: 0xD0
} SPAWNED_ACTOR_W;

// External function declarations
extern TASK_W* func_802171A8_5D2678(TASK_W* task, void (*func_ptr)(TASK_W*, CLS_BG_W*), unsigned short param);
extern void    func_80035214_35E14(TASK_W* task, void (*func_ptr)(TASK_W*, CLS_BG_W*));
extern void    func_80035244_35E44(TASK_W* task, void (*func_ptr)(TASK_W*, CLS_BG_W*));
extern void    func_8003521C_35E1C(void (*func_ptr)(TASK_W*, CLS_BG_W*));
extern void    func_080028D8_723EF8(TASK_W* task, CLS_BG_W* obj);
extern void    func_80023DF0_249F0(int param);
extern void    func_08000514_6AECF4(TASK_W* task, CLS_BG_W* obj);
extern void    func_08000908_6AF0E8(TASK_W* task, CLS_BG_W* obj);
extern int     func_800141C4_14DC4(unsigned short file_id);
extern void    func_80034ED4_35AD4(void);

// Callback function declarations
extern void    func_8021925C_5D472C(TASK_W* task, CLS_BG_W* obj);
extern void    func_80218F30_5D4400(TASK_W* task, CLS_BG_W* obj);

// External data declarations
extern SPAWN_MANAGER_W D_8015CC30_15D830;

RECOMP_PATCH void func_080027AC_723DCC(SPAWNER_ACTOR_W* spawner, CLS_BG_W* obj) {
    SPAWNED_ACTOR_W* spawned;
    CLS_BG_W*        spawned_obj;

    spawned = (SPAWNED_ACTOR_W*)func_802171A8_5D2678((TASK_W*)spawner, func_08000908_6AF0E8, 9);
    if (spawned != NULL) {
        func_80023DF0_249F0(2);

        spawned->model_id = 0x91;

        /* Load wave/sound file 0x1A */
        spawner->task.wave.wave_no = 0x1A;
        spawner->task.wave.data    = func_800141C4_14DC4(0x1A);

        /* Register this instance with global spawn manager */
        spawned->counter_ptr = &D_8015CC30_15D830.instance_count;
        D_8015CC30_15D830.instance_count++;

        /* Set up update and draw callbacks */
        func_80035214_35E14((TASK_W*)spawned, func_8021925C_5D472C);
        func_80035244_35E44((TASK_W*)spawned, func_80218F30_5D4400);

        /* Set initial spawn position */
        spawned_obj             = (CLS_BG_W*)spawned->task.unk_1c;
        spawned_obj->position.x = -6.0f;
        spawned_obj->position.y = 125.0f;
        spawned_obj->position.z = -102.0f;

        spawned->unk_D0          = 0xEE0000;
        spawner->spawned_actor   = (TASK_W*)spawned;

        func_8003521C_35E1C(func_080028D8_723EF8);
        return;
    }

    /* Spawn failed - cleanup */
    func_80034ED4_35AD4();
}