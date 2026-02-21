// Disables writing any save data so we don't have to worry about overwriting non AP data.
#include "Archipelago.h"
RECOMP_PATCH void func_8000B718_C318() { return; }