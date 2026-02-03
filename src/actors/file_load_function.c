#include "Archipelago.h"
#include "modding.h"
#include "recomputils.h"
#include "types.h"
extern unsigned int func_80001E50_2A50(unsigned short);
extern int func_800141C4_14DC4(unsigned short);
RECOMP_PATCH int func_80014840_15440(int arg0, unsigned int wave_no) 
{
    int data;

    if (arg0 > 0) {
        data = func_800141C4_14DC4(wave_no);

        if (data == -1) {
            // *(int* )-1 = 0;
            return arg0; // Return the original value instead of crashing
        }

        data = data & 0xBFFFFFFF;
        return (arg0 - (func_80001E50_2A50(wave_no) << 24)) + data;
    }

    return arg0;
}