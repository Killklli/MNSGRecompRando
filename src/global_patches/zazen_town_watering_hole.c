#include "common_structs.h"
#include "modding.h"
#include "recomputils.h"
#include "types.h"

// External declarations
extern SPAWN_MANAGER_W D_8015CC30_15D830;

// External function declarations
extern TASK_W *func_802171A8_5D2678(TASK_W *task,
                                    void (*func_ptr)(TASK_W *, CLS_BG_W *),
                                    unsigned short param);
extern void func_80035214_35E14(TASK_W *task,
                                void (*func_ptr)(TASK_W *, CLS_BG_W *));
extern void func_80035244_35E44(TASK_W *task,
                                void (*func_ptr)(TASK_W *, CLS_BG_W *));
extern void func_8003521C_35E1C(void (*func_ptr)(TASK_W *, CLS_BG_W *));
extern void func_080028D8_723EF8(TASK_W *task, CLS_BG_W *obj);
extern void func_80023DF0_249F0(int param);
extern void func_08000514_6AECF4(TASK_W *task, CLS_BG_W *obj);
extern void func_08000908_6AF0E8(TASK_W *task, CLS_BG_W *obj);
extern int func_800141C4_14DC4(unsigned short file_id);
extern void func_80034ED4_35AD4(void);

// Callback function declarations
extern void func_8021925C_5D472C(TASK_W *task, CLS_BG_W *obj);
extern void func_80218F30_5D4400(TASK_W *task, CLS_BG_W *obj);

// External data declarations
extern SPAWN_MANAGER_W D_8015CC30_15D830;

RECOMP_PATCH void func_080027AC_723DCC(SPAWNER_ACTOR_W *spawner,
                                       CLS_BG_W *obj)
{
  SPAWNED_ACTOR_W *spawned;
  CLS_BG_W *spawned_obj;

  spawned = (SPAWNED_ACTOR_W *)func_802171A8_5D2678((TASK_W *)spawner,
                                                    func_08000908_6AF0E8, 9);
  if (spawned != NULL)
  {
    func_80023DF0_249F0(2);

    spawned->model_id = 0x91;

    /* Load wave/sound file 0x1A */
    spawner->task.wave.file_id = 0x1A;
    spawner->task.wave.data = func_800141C4_14DC4(0x1A);

    /* Register this instance with global spawn manager */
    spawned->counter_ptr = &D_8015CC30_15D830.instance_count;
    D_8015CC30_15D830.instance_count++;

    /* Set up update and draw callbacks */
    func_80035214_35E14((TASK_W *)spawned, func_8021925C_5D472C);
    func_80035244_35E44((TASK_W *)spawned, func_80218F30_5D4400);

    /* Set initial spawn position */
    spawned_obj = (CLS_BG_W *)spawned->task.unk_1c;
    spawned_obj->position.x = -6.0f;
    spawned_obj->position.y = 125.0f;
    spawned_obj->position.z = -102.0f;

    spawned->unk_D0 = 0xEE0000;
    spawner->spawned_actor = (TASK_W *)spawned;

    func_8003521C_35E1C(func_080028D8_723EF8);
    return;
  }

  /* Spawn failed - cleanup */
  func_80034ED4_35AD4();
}
