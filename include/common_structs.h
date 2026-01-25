#pragma once

#include "types.h"

// Forward declarations for circular dependencies
typedef struct ActorDefinition ActorDefinition;
typedef struct ActorInstance ActorInstance;

// Basic position and rotation structures
typedef struct Position {
    short x;
    short y;
    short z;
} Position; // Size: 6

typedef struct Rotation {
    short pitch;
    short yaw;
    short roll;
} Rotation; // Size: 6

// Actor system core structures
typedef struct ActorDefinition {
    int data[4];
} ActorDefinition; // Size: 16

typedef struct ActorInstance {
    Position position;
    Rotation rotation;
    ActorDefinition *actor_definition;
    unsigned char is_spawned;
    unsigned char unk_11;
    unsigned char unk_12;
    unsigned char unk_13;
} ActorInstance; // Size: 20

typedef struct StageActorMetadata {
    ActorInstance *persistent_actor_instances;
    const char **actor_definition_names;
    ActorInstance *actor_instances;
    void *actor_partitions;              // Keep as void* since not used
    void *actor_partition_configuration; // Keep as void* since not used
    short actor_data_file_id;
    short unk_16;
    void (*load_stage_data_files)(void);
} StageActorMetadata; // Size: 28

// Common data structure used across multiple files
// Also known as OverlayEntry in actor_manager.c
typedef struct WAVE_W {
  unsigned short file_id;  // File identifier (also called wave_no in some contexts)
  int data;                // A pointer to the data, stored as an integer
} WAVE_W;

// Memory allocation structure
typedef struct AMEM_W {
  char *pt;
  unsigned int size;
  struct AMEM_W *next;
  struct AMEM_W *up;
} AMEM_W;

// Main task/entity structure
typedef struct TASK_W {
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

// 3D float vector
typedef struct VEC3F_W {
  float x;
  float y;
  float z;
} VEC3F_W;

// 3D signed short vector
typedef struct VEC3S_W {
  signed short x;
  signed short y;
  signed short z;
} VEC3S_W;

// Class/container header structure
typedef struct CLS_W {
  struct CLS_W *next;
  unsigned char kind;
  unsigned char pri;
  unsigned short s_pri;
} CLS_W;

// Background/object class structure
typedef struct CLS_BG_W {
  CLS_W header;                 // offset: 0x00, size: 0x08
  VEC3F_W position;             // offset: 0x08
  VEC3S_W rotation;             // offset: 0x14
  unsigned char unknown_1a[2];  // offset: 0x1A
  VEC3F_W scale;                // offset: 0x1C
  float animation_progress;     // offset: 0x28
  unsigned int graphics_1;      // offset: 0x2C
  void *graphics_2;             // offset: 0x30
  WAVE_W waves[6];              // offset: 0x34
  unsigned char unknown_64;     // offset: 0x64
  signed char unknown_65;       // offset: 0x65
  unsigned char unknown_66;     // offset: 0x66
  unsigned char unknown_67;     // offset: 0x67
  signed int unknown_68;        // offset: 0x68
  signed int unknown_6c;        // offset: 0x6C
  float unknown_70;             // offset: 0x70
  struct CLS_BG_W *left;        // offset: 0x74
  struct CLS_BG_W *right;       // offset: 0x78
  unsigned char unknown_7c[2];  // offset: 0x7C
  signed short unknown_7e;      // offset: 0x7E
  void *unknown_80;             // offset: 0x80
  unsigned short unknown_84;    // offset: 0x84
  unsigned char unknown_86;     // offset: 0x86
  unsigned char unknown_87;     // offset: 0x87
  VEC3F_W unknown_88;           // offset: 0x88
  struct CLS_BG_W *prev;        // offset: 0x94
} CLS_BG_W;

// Particle effect task structure
typedef struct PARTICLE_TASK_W {
  TASK_W task;                // offset: 0x00, size: 0x5C
  unsigned short actor_id;    // offset: 0x5C
  unsigned short model_id;    // offset: 0x5E
  unsigned int unk_60;        // offset: 0x60
  unsigned char pad_64[4];    // offset: 0x64
  unsigned int flags;         // offset: 0x68
  unsigned char pad_6C[100];  // offset: 0x6C, size: 0x64
  unsigned char stop;         // offset: 0xD0
} PARTICLE_TASK_W;

// Global struct containing spawn instance counter
typedef struct SPAWN_MANAGER_W {
  unsigned char pad_00[0xD8];    // offset: 0x00
  unsigned char instance_count;  // offset: 0xD8
} SPAWN_MANAGER_W;

// Parent actor that spawns child actors
typedef struct SPAWNER_ACTOR_W {
  TASK_W task;                 // offset: 0x00, size: 0x5C
  unsigned short actor_id;     // offset: 0x5C
  unsigned short model_id;     // offset: 0x5E
  unsigned int unk_60;         // offset: 0x60
  unsigned char pad_64[0x88];  // offset: 0x64, size: 0x88
  TASK_W *spawned_actor;       // offset: 0xEC
} SPAWNER_ACTOR_W;

// Child actor that gets spawned
typedef struct SPAWNED_ACTOR_W {
  TASK_W task;                 // offset: 0x00, size: 0x5C
  unsigned short actor_id;     // offset: 0x5C
  unsigned short model_id;     // offset: 0x5E
  unsigned int unk_60;         // offset: 0x60
  unsigned char pad_64[4];     // offset: 0x64
  unsigned int flags;          // offset: 0x68
  unsigned char pad_6C[8];     // offset: 0x6C, size: 0x08
  unsigned char *counter_ptr;  // offset: 0x74
  unsigned char pad_78[0x58];  // offset: 0x78, size: 0x58
  unsigned int unk_D0;         // offset: 0xD0
} SPAWNED_ACTOR_W;

// Ginneko (turtle rock) specific state and task structures
typedef struct GINNEKO_STATE_W {
    unsigned char phase;         // offset: 0x00 (0xD0 in actor)
    unsigned char sound_played;  // offset: 0x01 (0xD1 in actor)
} GINNEKO_STATE_W;

typedef struct GINNEKO_TASK_W {
    TASK_W task;                     // offset: 0x00, size: 0x5C
    unsigned short actor_id;         // offset: 0x5C
    unsigned short model_id;         // offset: 0x5E
    unsigned int unk_60;             // offset: 0x60
    unsigned char pad_64[4];         // offset: 0x64
    unsigned int flags;              // offset: 0x68
    unsigned char pad_6C[100];       // offset: 0x6C, size: 0x64
    GINNEKO_STATE_W state;           // offset: 0xD0
    PARTICLE_TASK_W *particle_task;  // offset: 0xD4
} GINNEKO_TASK_W;

// Actor structure definitions for doors and items

// Locked door actor structure
typedef struct LockedDoorActor
{
    unsigned short actor_id;   // 0x23F
    unsigned short padding1;   // 0x0000
    unsigned char door_design; // 0x01 = Oedo Castle, 0x02 = other designs
    unsigned char key_type;    // 0x02 = Silver, etc.
    unsigned short padding2;   // 0x0000
    unsigned short lock_index; // 0x010F
    unsigned short accept_key; // 0x0110
    unsigned short exit_id;    // 0x02
    unsigned short padding3;   // 0x0000
} LockedDoorActor; // Size: 16

// Sliding door actor structure
typedef struct SlidingDoorActor
{
    unsigned short actor_id; // 0x24D
    unsigned short padding1; // 0x0000
    unsigned char graphic;   // Graphic/appearance type (e.g., 0x01)
    unsigned char padding2;  // 0x00
    unsigned short padding3; // 0x0000
    unsigned int padding4;   // 0x00000000
    unsigned char padding5;  // 0x00
    unsigned char exit_id;   // Exit ID (e.g., 0x03)
    unsigned short padding6; // 0x0000
} SlidingDoorActor; // Size: 16

// Exit actor structure
typedef struct ExitActor
{
    unsigned short actor_id;    // 0x008C
    unsigned short padding1;    // 0x0000
    unsigned short dest_room;   // Destination room
    short dest_x;               // Destination X coordinate
    short dest_z;               // Destination Z coordinate
    short dest_y;               // Destination Y coordinate
    unsigned short direction;   // Direction (0300 = South, etc.)
    unsigned char misc_exit_id; // Misc exit ID
    unsigned char misc_unknown; // Misc unknown value
} ExitActor; // Size: 16

// Key actor structure
typedef struct KeyActor
{
    unsigned short actor_id;  // 0x193
    unsigned short padding1;  // 0x0000
    unsigned short enemies;   // 0x0000 = No enemies required
    unsigned short padding2;  // 0x0000
    unsigned short key_index; // 0x0110
    unsigned short padding3;  // 0x0000
    unsigned int padding4;    // 0x00000000
} KeyActor; // Size: 16

// Flag actor structure
typedef struct FlagActor
{
    unsigned short actor_id; // 0x086, 0x087, 0x088, 0x089, 0x091, 0x226, 0x326, 0x345
    unsigned short padding1; // 0x0000
    unsigned short flag;     // Flag identifier (e.g., 0x00DA, 0x00F7)
    unsigned short padding2; // 0x0000
    unsigned int padding3;   // 0x00000000
    unsigned int padding4;   // 0x00000000
} FlagActor; // Size: 16

// Ryo (money) actor structure
typedef struct RyoActor
{
    unsigned short actor_id; // 0x082
    unsigned short padding1; // 0x0000
    unsigned char size;      // Size type (e.g., 0x01 = Normal)
    unsigned char padding2;  // 0x00
    unsigned short padding3; // 0x0000
    unsigned int padding4;   // 0x00000000
    unsigned int padding5;   // 0x00000000
} RyoActor; // Size: 16

// Item replacement management structures
typedef struct ItemReplacementPair
{
    int instance_id;
    u32 new_item_ap_id;
    unsigned short new_item_id;
    unsigned short flag_id;
} ItemReplacementPair;

typedef struct ItemReplacementList
{
    struct ItemReplacementPair *pairs;
    int count;
} ItemReplacementList;

// Enemy replacement management structures  
typedef struct EnemyReplacementPair
{
    int index;
    unsigned short new_enemy_id;
} EnemyReplacementPair;

typedef struct EnemyReplacementList
{
    struct EnemyReplacementPair *pairs;
    int count;
} EnemyReplacementList;