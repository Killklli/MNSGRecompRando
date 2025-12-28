#ifndef ACTOR_COMMON_H
#define ACTOR_COMMON_H

#include "modding.h"
#include "common.h"
#include "recomputils.h"
#include "recompconfig.h"
#include "libc/stdbool.h"
#include "save_data_tool.h"

// Common structures used by all actor files

struct Position
{
    short x;
    short y;
    short z;
}; // Size: 6

struct Rotation
{
    short pitch;
    short yaw;
    short roll;
}; // Size: 6

struct ActorDefinition
{
    int data[4];
}; // Size: 16

struct ActorInstance
{
    struct Position position;
    struct Rotation rotation;
    struct ActorDefinition *actor_definition;
    unsigned char is_spawned;
    unsigned char unk_11;
    unsigned char unk_12;
    unsigned char unk_13;
}; // Size: 20

struct StageActorMetadata
{
    struct ActorInstance *persistent_actor_instances;
    const char **actor_definition_names;
    struct ActorInstance *actor_instances;
    void *actor_partitions;              // Keep as void* since not used
    void *actor_partition_configuration; // Keep as void* since not used
    short actor_data_file_id;
    short unk_16;
    void (*load_stage_data_files)(void);
}; // Size: 28

// External declarations
extern struct StageActorMetadata *D_80231300_5EC7D0[];
extern unsigned short D_800C7AB2; // Part of the huge "SYS_W" structure, ID of the current stage
extern void *func_800141C4_14DC4(unsigned int file_id);                // overlay_get_data_pointer
extern void *func_80014840_15440(void *pointer, unsigned int file_id); // overlay_resolve_pointer

// Function prototypes for actor processing
void process_enemy_actors(struct ActorInstance *actor_instance, struct ActorDefinition *resolved_actor_def, unsigned short actor_id, unsigned short actor_data_file_id, int overall_index);
void process_door_actors(struct ActorInstance *actor_instance, struct ActorDefinition *resolved_actor_def, unsigned short actor_id, unsigned short actor_data_file_id, int overall_index);
void process_key_actors(struct ActorInstance *actor_instance, struct ActorDefinition *resolved_actor_def, unsigned short actor_id, unsigned short actor_data_file_id, int overall_index);
void process_flag_actors(struct ActorInstance *actor_instance, struct ActorDefinition *resolved_actor_def, unsigned short actor_id, unsigned short actor_data_file_id, int overall_index);
void process_exit_actors(struct ActorInstance *actor_instance, struct ActorDefinition *resolved_actor_def, unsigned short actor_id, unsigned short actor_data_file_id, int overall_index);
void process_misc_actors(struct ActorInstance *actor_instance, struct ActorDefinition *resolved_actor_def, unsigned short actor_id, unsigned short actor_data_file_id, int overall_index);
void flag_locked_doors(struct ActorInstance *actor_instance, struct ActorDefinition *resolved_actor_def, unsigned short actor_id, unsigned short actor_data_file_id, int overall_index);

#endif // ACTOR_COMMON_H