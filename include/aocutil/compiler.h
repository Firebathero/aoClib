#pragma once

#define FORCE_INLINE inline __attribute__((always_inline))
#define likely(x) (__builtin_expect((x) != 0, 1))
#define unlikely(x) (__builtin_expect((x) != 0, 0))