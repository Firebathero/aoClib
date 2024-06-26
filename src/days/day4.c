#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

//pan includes
#include <days.h>
#include <aocutil/compiler.h>
#include <aocutil/token.h>
#include <aocutil/fileops.h>
#include <aocutil/math.h>
#include <aocutil/panstring.h>

int cards[256] = {[0 ... 255] = 1};

static FORCE_INLINE void processLine(char *line, int linenum) {
    char *colonpos = strchr(line, ':');
    char *pipepos = strchr(line, '|');
    pan_string str = string_from_cstr(colonpos + 2);
    pan_string str2 = string_from_cstr(pipepos + 2);
    const char *delims = " ";
    TokenIterator it1, it2;
    uint64_t winning_cards[2] = {0, 0};
    int matches = 0;

    for (it1 = token_begin(str, delims); !token_is_end(&it1); it1 = token_next(it1)) {
        pan_string card = token_value(&it1);
        if (card.data >= pipepos) break;
        if (!card.length || !isdigit(card.data[0]))
            continue;
        int num = fast_atoi(card.data);
        winning_cards[num >> 6] |= 1ULL << (num & 63);
    }

    for (it2 = token_begin(str2, delims); !token_is_end(&it2); it2 = token_next(it2)) {
        pan_string card2 = token_value(&it2);
        if (!card2.length || !isdigit(card2.data[0]))
            continue;
        int num = fast_atoi(card2.data);
        if (winning_cards[num >> 6] & (1ULL << (num & 63)))
            matches++;
    }

    int copies = cards[linenum];
    for (int k = linenum + 1; k <= linenum + matches; ++k) {
        cards[k] += copies;
    }
}


int day4(const char* input_file) {
    printf("pulling lawnmower cord...\n\n");

    char *buf = NULL;
    if (unlikely(file_to_buf(input_file, &buf) != EXIT_SUCCESS)) {
        fprintf(stderr, "Failed to read file\n");
        return EXIT_FAILURE;
    }
    if (unlikely(buf == NULL)) {
        fprintf(stderr, "Buffer is NULL after file_to_buf\n");
        return EXIT_FAILURE;
    }

    int linenum = 0;
    FOREACH_LINE(buf, line) {
        processLine(line, linenum);
        linenum++;
    }

    free(buf);

    int res = 0;
    for (int i = 0; i < linenum; ++i)
        res += cards[i];

    printf("%d", res);

    return EXIT_SUCCESS;
}