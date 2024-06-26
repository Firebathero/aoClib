#pragma once

#include <stdio.h>
#include <stdlib.h>

#include <aocutil/compiler.h>

#define FOREACH_LINE(buf, line) \
    for (char *line = (buf), *next = NULL; line; line = next ? (next + 1) : NULL) \
        if ((next = strchr(line, '\n')) ? (*next = '\0', 1) : 1)

static FORCE_INLINE int file_to_buf(const char *file_name, char **buf) {
    FILE *file = fopen(file_name, "rb");
    if (!file) {
        perror("Failed to open file");
        return EXIT_FAILURE;
    }

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    rewind(file);

    *buf = malloc(fileSize + 1);
    if (!*buf) {
        perror("Failed to allocate memory");
        fclose(file);
        return EXIT_FAILURE;
    }

    size_t bytesRead = fread(*buf, 1, fileSize, file);
    if (bytesRead != fileSize) {
        perror("Failed to read file");
        free(*buf);
        fclose(file);
        return EXIT_FAILURE;
    }

    fclose(file);
    (*buf)[fileSize] = '\0';

    return EXIT_SUCCESS;
}