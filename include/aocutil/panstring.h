#pragma once

#include <string.h>

#include <compiler.h>
#include <panstring-t.h>


static FORCE_INLINE pan_string string_create(const char* data, size_t length) {
    return (pan_string){data, length};
}

static FORCE_INLINE pan_string string_from_cstr(const char* cstr) {
    return string_create(cstr, strlen(cstr));
}

static FORCE_INLINE void pan_printf(pan_string str) {
    printf("%.*s", (int)str.length, str.data);
}
