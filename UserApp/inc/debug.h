#ifndef DBG_PRINT_H_
#define DBG_PRINT_H_

#include <stdio.h>
#include <string.h>

#define DEBUG_M

#ifdef DEBUG_M
#define DBG(...)    printf(__VA_ARGS__);\
                    printf("\n");
#else
#define DBG(...)
#endif

#endif
