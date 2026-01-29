#include "libc/stdbool.h"
#include "libc/stdint.h"
#include "modding.h"
#include "recomputils.h"
#include "types.h"
extern void func_08002E20_719CC0(void);
extern void func_80034ED4_35AD4(void);
extern s32 func_800240DC_24CDC(s32 id);
extern void  func_80221C0C_5DD0DC(void* obj, int a1, float a2, int a3);
extern void  func_80221A90_5DCF60(void* obj);
extern void func_8003521C_35E1C(void *callback);
RECOMP_PATCH void func_08002D6C_719C0C(void* entity, void* arg1) {
    s32 button_check1, button_check2;
    recomp_printf("func_08002D6C_719C0C called\n");
    // Check button input 0x28 (40)
    button_check1 = func_800240DC_24CDC(0x28);
    
    // if (button_check1 != 0) {
        // // Check button input 0x31 (49)
        // button_check2 = func_800240DC_24CDC(0x31);
        
        // if (button_check2 == 0) {
        //     // Call some cleanup/exit function
        //     func_80034ED4_35AD4();
        //     return;
        // }
    // }
    
    // Set up entity properties
    *(u16*)(entity + 0x5E) = 0x300;  // Set value 0x300 to offset 0x5E
    
    // Call entity setup function
    func_80221C0C_5DD0DC(entity, 0, 0.5f, 1);
    
    // Call another entity function
    func_80221A90_5DCF60(entity);
    
    // Set entity state
    *(u8*)(entity + 0x99) = 8;
    
    // Register callback function
    func_8003521C_35E1C(func_08002E20_719CC0);
}