#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

//pan includes
#include <days.h>
#include <aocutil/compiler.h>
#include <aocutil/token.h>
#include <aocutil/fileops.h>
#include <aocutil/panstring.h>

static FORCE_INLINE void processLine(char *line) {
    pan_string str = string_from_cstr(line);
    const char *delims = ":| ";
    TokenIterator it1, it2;
    pan_string outer_token, inner_token;

    for (it1 = token_begin(str, delims); !token_is_end(&it1); it1 = token_next(it1)) {
        outer_token = token_value(&it1);
        if (!outer_token.length || !isdigit(outer_token.data[0]))
            continue;

        for (it2 = token_begin(str, delims); !token_is_end(&it2); it2 = token_next(it2)) {
            inner_token = token_value(&it2);
            if (!inner_token.length || !isdigit(inner_token.data[0]) ||
                inner_token.data == outer_token.data)
                continue;

            //do yer logique on tokens
            pan_printf(inner_token);
            printf("\n");
        }
    }
}

int day4(const char* input_file) {
    printf("pulling lawnmower cord...\n\n");

    // stuff file into buf
    char *buf = NULL;
    if (unlikely(file_to_buf(input_file, &buf) != EXIT_SUCCESS)) {
        fprintf(stderr, "Failed to read file\n");
        return EXIT_FAILURE;
    }
    if (unlikely(buf == NULL)) {
        fprintf(stderr, "Buffer is NULL after file_to_buf\n");
        return EXIT_FAILURE;
    }

    //let's hide guts later
    char *line = buf;
    char *nextLine;
    while ((nextLine = strchr(line, '\n')) != NULL) {
        *nextLine = '\0';
        processLine(line);
        line = nextLine + 1;
    }
    if (*line)
        processLine(line);



    free(buf);
    return EXIT_SUCCESS;
}
