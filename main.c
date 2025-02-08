#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "getcwd.h"
#include <dirent.h>

int main(int argc, char** argv) {
    DIR* current_dir = opendir(".");
    struct dirent* entry;

    if (current_dir == NULL) {
        perror("opendir");
        return EXIT_FAILURE;
    }
    else {
        printf("Succesfully opened directory\n");
        printf("\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2510\n");
        while ((entry = readdir(current_dir)) != NULL) {
            printf("\t\u251c\u2500 File: %s (Type: %d)\n", entry->d_name, entry->d_type);
        }
        closedir(current_dir);
        return EXIT_SUCCESS;
    }

    return 0;
}


// constant program checks for :q to stop
// char input[20];

// int i = 0;
// while (1) {
//     fgets(input, sizeof(input), stdin);

//     if (strcmp(input, ":q\n") == 0) {
//         break;
//     }

//     printf("%d\n", i);
//     i++;
// }


// options when running program
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