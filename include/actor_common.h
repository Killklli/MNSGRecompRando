#ifndef ACTOR_COMMON_H
#define ACTOR_COMMON_H

#include "modding.h"
#include "common.h"
#include "recomputils.h"
#include "recompconfig.h"
#include "common_structs.h"

// External declarations
extern StageActorMetadata *D_80231300_5EC7D0[];
extern unsigned short D_800C7AB2; // Part of the huge "SYS_W" structure, ID of the current stage
extern s32 func_800141C4_14DC4(unsigned int file_id);              // overlay_get_data_pointer
extern s32 func_80014840_15440(s32 pointer, unsigned int file_id); // overlay_resolve_pointer

// Function prototypes for actor processing
void process_enemy_actors(ActorInstance *actor_instance, ActorDefinition *resolved_actor_def, unsigned short actor_id, unsigned short actor_data_file_id, int overall_index);
void process_door_actors(ActorInstance *actor_instance, ActorDefinition *resolved_actor_def, unsigned short actor_id, unsigned short actor_data_file_id, int overall_index);
void process_key_actors(ActorInstance *actor_instance, ActorDefinition *resolved_actor_def, unsigned short actor_id, unsigned short actor_data_file_id, int overall_index);
void process_flag_actors(ActorInstance *actor_instance, ActorDefinition *resolved_actor_def, unsigned short actor_id, unsigned short actor_data_file_id, int overall_index);
void process_exit_actors(ActorInstance *actor_instance, ActorDefinition *resolved_actor_def, unsigned short actor_id, unsigned short actor_data_file_id, int overall_index);
void process_misc_actors(ActorInstance *actor_instance, ActorDefinition *resolved_actor_def, unsigned short actor_id, unsigned short actor_data_file_id, int overall_index);
void process_items(ActorInstance *actor_instance, ActorDefinition *resolved_actor_def, unsigned short actor_id, unsigned short actor_data_file_id, int overall_index);
void flag_locked_doors(ActorInstance *actor_instance, ActorDefinition *resolved_actor_def, unsigned short actor_id, unsigned short actor_data_file_id, int overall_index);

#endif // ACTOR_COMMON_H