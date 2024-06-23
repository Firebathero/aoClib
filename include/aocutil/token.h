#pragma once

#include <stdio.h>

#include <compiler.h>
#include <panstring.h>

typedef struct {
    const char* current;
    const char* end;
    const char* delims;
    pan_string token;
} TokenIterator;

static FORCE_INLINE TokenIterator token_next(TokenIterator it) {
    while (it.current < it.end && strchr(it.delims, *it.current))
        it.current++;

    const char* token_start = it.current;

    while (it.current < it.end && !strchr(it.delims, *it.current))
        it.current++;

    it.token = string_create(token_start, it.current - token_start);

    return it;
}

static FORCE_INLINE TokenIterator token_begin(pan_string str, const char* delims) {
    TokenIterator it = {
            .current = str.data,
            .end = str.data + str.length,
            .delims = delims,
            .token = {NULL, 0}
    };
    return token_next(it);
}

static FORCE_INLINE int token_is_end(const TokenIterator* it) {
    return it->current >= it->end && it->token.length == 0;
}

static FORCE_INLINE pan_string token_value(const TokenIterator* it) {
    return it->token;
}