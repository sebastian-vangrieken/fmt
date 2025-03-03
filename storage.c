#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
    if (argc > 1) {
        printf("arguments given\n");
        return EXIT_SUCCESS;
    }

    DIR *current_dir = opendir(".");
    if (current_dir == NULL) {
        perror("opendir");
        return EXIT_FAILURE;
    }

    struct dirent *entry;

    while (1) {
        system("clear");
        rewinddir(current_dir);
        printf("\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2510\n");
        while ((entry = readdir(current_dir)) != NULL) {
            printf("\t\u251c\u2500 File: %s (Type: %d)\n", entry->d_name,
                   entry->d_type);
        }

        char input[20];
        fgets(input, sizeof(input), stdin);

        if (strcmp(input, ":q\n") == 0) {
            closedir(current_dir);
            break;
        }
    }

    return EXIT_SUCCESS;
}
