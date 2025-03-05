#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int string_compare(const void *, const void *);
void print_structure(char *[], const int, int);

int main(int argc, char **argv) {
    DIR *dir;
    if (argc == 1) {
        dir = opendir(".");
    } else {
        dir = opendir(argv[1]);
    }

    if (dir == NULL) {
        perror("opendir failed");
        return 1;
    }

    char *dir_contents[64];
    int amount_in_dir = 0;

    struct dirent *dirent;
    while ((dirent = readdir(dir)) != NULL) {
        if (amount_in_dir < 64) {
            dir_contents[amount_in_dir] = malloc(strlen(dirent->d_name) + 1);

            if (dir_contents[amount_in_dir]) {
                strcpy(dir_contents[amount_in_dir], dirent->d_name);
                amount_in_dir++;
            } else {
                perror("malloc failed");
            }
        }
    }

    closedir(dir);

    qsort(dir_contents, amount_in_dir, sizeof(char *), string_compare);

    int cursor_pos = 0;
    while (1) {
        print_structure(dir_contents, amount_in_dir, cursor_pos);

        char input[64];
        if (fgets(input, sizeof(input), stdin) == NULL) {
            continue;
        }

        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, ":q") == 0) {
            break;
        } else if (strcmp(input, "j") == 0) {
            cursor_pos++;
            if (cursor_pos >= amount_in_dir) {
                cursor_pos = 0;
            }
        } else if (strcmp(input, "k") == 0) {
            cursor_pos--;
            if (cursor_pos < 0) {
                cursor_pos = amount_in_dir - 1;
            }
        }
    }

    //    printf("Directory contents:\n");
    //    for (int i = 0; i < amount_in_dir; i++) {
    //        printf("%s\n", dir_contents[i]);
    //    }

    for (int i = 0; i < amount_in_dir; i++) {
        free(dir_contents[i]);
    }

    return 0;
}

int string_compare(const void *a, const void *b) {
    char *str1 = *(char **)a;
    char *str2 = *(char **)b;
    return strcmp(str1, str2);
}

void print_structure(char *items[], const int size, int cursor_pos) {
    system("clear");

    for (int i = 0; i < size; i++) {
        if (i == cursor_pos) {
            printf("> ");
        } else {
            printf(" ");
        }
        printf("%s\n", items[i]);
    }
}
