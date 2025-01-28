#include <stdio.h>
#include <string.h>
#include "getcwd.h"

int main(int argc, char** argv) {
    // printf("%s\n", get_current_working_dir());
    if (argc == 1) {
        printf("no options given\n");

        return 0;
    }

    if (strcmp(argv[1], "-e") == 0) {
        printf("option %s given\n", argv[1]);
    }
    else {
        printf("Unknown options: %s\n", argv[1]);
    }

    return 0;
}
