#pragma once

#include <compiler.h>
#include <ctype.h>

static FORCE_INLINE int fast_atoi(const char *str) {
    int val = 0;
    while (*str && isdigit(*str)) {
        val = val * 10 + (*str++ - '0');
    }
    return val;
}