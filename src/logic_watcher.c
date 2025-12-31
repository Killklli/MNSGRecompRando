#include "types.h"
#include "modding.h"
#include "apconnect_ui.h"
#include "recomputils.h"
#include "save_data_tool.h"
#include "entities.h"
#include "Archipelago.h"

// Hooks the cutscene text function, this will tell us if the game is completed
RECOMP_HOOK("func_8003D310_3DF10") void game_completed_hook(s32 param) {
    // if the param is 0x213
    if (param == 0x213) {
        recomp_printf("Game completed with param 0x213 - notifying rando\n");
        rando_complete_goal();
    }
}



// External function declarations
extern void func_80221F70_5DD440(void);
extern void func_8021804C_5D351C(void* entity, s32 arg1);
extern void func_80024038_24C38(s32 flag);
extern s32 func_800240DC_24CDC(s32 flag);
extern void func_8003D310_3DF10(s32 sound_id);
extern void func_80218DA8_5D4278(void* entity, s32 arg1, s32 arg2, s32 arg3);
extern void func_8021A22C_5D56FC(void* entity);
extern void func_8003521C_35E1C(void* func_ptr);
extern void func_080006E0_6AEEC0(void*, void*);

extern void func_8003D310_3DF10(s32 message_id);
extern s32 func_800240DC_24CDC(s32 flag);
extern void func_8003F608_40208();
void increase_silver_fortune_doll(){
    s32 fortune_dolls = READ_SAVE_DATA(SAVE_FORTUNE_DOLL_TOTAL);
    fortune_dolls += 1;
    WRITE_SAVE_DATA(SAVE_FORTUNE_DOLL_TOTAL, fortune_dolls);
    
    s32 fortune_progress = READ_SAVE_DATA(SAVE_FORTUNE_DOLL_PROGRESS);
    fortune_progress += 1;
    // if it gets to 4 reset to 0
    if (fortune_progress >= 4){
        fortune_progress = 0;
        // Raise SAVE_TOTAL_HEALTH by 1
        s32 total_health = READ_SAVE_DATA(SAVE_TOTAL_HEALTH);
        total_health += 2;
        WRITE_SAVE_DATA(SAVE_TOTAL_HEALTH, total_health);
    }
    WRITE_SAVE_DATA(SAVE_FORTUNE_DOLL_PROGRESS, fortune_progress);
}

void increase_gold_fortune_doll(){
    s32 fortune_dolls = READ_SAVE_DATA(SAVE_FORTUNE_DOLL_TOTAL);
    fortune_dolls += 1;
    WRITE_SAVE_DATA(SAVE_FORTUNE_DOLL_TOTAL, fortune_dolls);
    // Raise SAVE_TOTAL_HEALTH by 1
    s32 total_health = READ_SAVE_DATA(SAVE_TOTAL_HEALTH);
    total_health += 2;
    WRITE_SAVE_DATA(SAVE_TOTAL_HEALTH, total_health);
}

void progressive_weapon_handler(void){
    static int first_call = 1;
    
    // For safety, set all to 0 on first call
    if (first_call) {
        WRITE_SAVE_DATA(SAVE_GOEMON_WEAPON_LEVEL, 0);
        WRITE_SAVE_DATA(SAVE_YAE_WEAPON_LEVEL, 0);
        WRITE_SAVE_DATA(SAVE_EBISUMARU_WEAPON_LEVEL, 0);
        WRITE_SAVE_DATA(SAVE_SASUKE_WEAPON_LEVEL, 0);
        first_call = 0;
        return;
    }
    
    // Read current weapon levels and increment them (0→1, 1→2)
    int goemon_level = READ_SAVE_DATA(SAVE_GOEMON_WEAPON_LEVEL);
    int yae_level = READ_SAVE_DATA(SAVE_YAE_WEAPON_LEVEL);
    int ebisumaru_level = READ_SAVE_DATA(SAVE_EBISUMARU_WEAPON_LEVEL);
    int sasuke_level = READ_SAVE_DATA(SAVE_SASUKE_WEAPON_LEVEL);
    
    // Increment levels: 0→1, 1→2 (max level 2)
    if (goemon_level == 0) WRITE_SAVE_DATA(SAVE_GOEMON_WEAPON_LEVEL, 1);
    else if (goemon_level == 1) WRITE_SAVE_DATA(SAVE_GOEMON_WEAPON_LEVEL, 2);
    
    if (yae_level == 0) WRITE_SAVE_DATA(SAVE_YAE_WEAPON_LEVEL, 1);
    else if (yae_level == 1) WRITE_SAVE_DATA(SAVE_YAE_WEAPON_LEVEL, 2);
    
    if (ebisumaru_level == 0) WRITE_SAVE_DATA(SAVE_EBISUMARU_WEAPON_LEVEL, 1);
    else if (ebisumaru_level == 1) WRITE_SAVE_DATA(SAVE_EBISUMARU_WEAPON_LEVEL, 2);
    
    if (sasuke_level == 0) WRITE_SAVE_DATA(SAVE_SASUKE_WEAPON_LEVEL, 1);
    else if (sasuke_level == 1) WRITE_SAVE_DATA(SAVE_SASUKE_WEAPON_LEVEL, 2);
}