#ifndef __RECOMPUTILS_H__
#define __RECOMPUTILS_H__

#include "libc/stdbool.h"
#include "modding.h"

RECOMP_IMPORT("*", void *recomp_alloc(unsigned long size));
RECOMP_IMPORT("*", void recomp_free(void *memory));
RECOMP_IMPORT("*", int recomp_printf(const char *fmt, ...));

// Utility functions
int simple_atoi(const char *str);

// Debug logging functionality
static bool debug_logging_enabled = false;

// Debug printf macro - only prints if debug logging is enabled
#define DEBUG_PRINTF(fmt, ...)                 \
    do {                                       \
        if (debug_logging_enabled) {           \
            recomp_printf(fmt, ##__VA_ARGS__); \
        }                                      \
    } while (0)

#endif
