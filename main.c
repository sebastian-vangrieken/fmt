#include <stdio.h>
#include <string.h>
#include "getcwd.h"

int main(int argc, char** argv) {
    char input[20];

    int i = 0;
    while (1) {
        fgets(input, sizeof(input), stdin);

        if (strcmp(input, ":q\n") == 0) {
            break;
        }

        printf("%d\n", i);
        i++;
    }

    return 0;
}

// if (argc == 1) {
//     printf("no options given\n");

//     return 0;
// }

// if (strcmp(argv[1], "-e") == 0) {
//     printf("option %s given\n", argv[1]);
// }
// else {
//     printf("Unknown options: %s\n", argv[1]);
// }

// printf("argc: %d\n", argc);
// for (int i = 0; i < argc; i++) {
//     printf("argv[%d]: %s\n", argc, argv[i]);
// }
// printf("%s\n", get_current_working_dir());