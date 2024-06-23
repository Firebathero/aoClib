#include <stdio.h>
#include <stdlib.h>

#include "days.h"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <day_number>\n", argv[0]);
        return 1;
    }

    int day = atoi(argv[1]);
    char input_file[20];
    snprintf(input_file, sizeof(input_file), "input/day%d.txt", day);

    switch (day) {
        case 4:
            printf("Launching Day4...");
            day4(input_file);
            break;
        default:
            fprintf(stderr, "Day %d aint here yet... \n", day);
            return EXIT_FAILURE;
    }

    return 0;
}