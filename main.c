#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>

#define MAX_DIR_CONT 64

void print_border(int, int);
int string_compare(const void *, const void *);

int main(int argc, char **argv) {
    struct winsize ws;
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

    char *dir_cont[MAX_DIR_CONT];
    int dir_size = 0;

    struct dirent *dirent;
    while ((dirent = readdir(dir)) != NULL) {
        if (dir_size < MAX_DIR_CONT) {
            dir_cont[dir_size] = malloc(strlen(dirent->d_name) + 1);

            if (dir_cont[dir_size]) {
                strcpy(dir_cont[dir_size], dirent->d_name);
                dir_size++;
            } else {
                perror("malloc failed");
            }
        }
    }

    closedir(dir);

    qsort(dir_cont, dir_size, sizeof(char *), string_compare);

    printf("\033[?25l"); // hide cursor

    int cursor_pos = 0;
    while (1) {
        ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws);
        printf("\033[H\033[J"); // clear screen
        print_border(ws.ws_row, ws.ws_col);

        for (int i = 0; i < dir_size; i++) {
            if (i == cursor_pos) {
                printf("\033[%d;%dH", i + 2, 2);
                printf("> ");
            } else {
                printf("\033[%d;%dH", i + 2, 2);
                printf(" ");
            }
            printf("%s", dir_cont[i]);
        }

        printf("\033[%d;3H", ws.ws_row - 1);

        char input[16];
        if (fgets(input, sizeof(input), stdin) != NULL) {
            if (strcmp(input, ":q\n") == 0) {
                printf("\033[?25h"); // show cursor
                printf("\033[H\033[J");
                break;
            } else if (strcmp(input, "j\n") == 0) {
                cursor_pos++;
                if (cursor_pos >= dir_size) {
                    cursor_pos = 0;
                }
            } else if (strcmp(input, "k\n") == 0) {
                cursor_pos--;
                if (cursor_pos < 0) {
                    cursor_pos = dir_size - 1;
                }
            }
        }

        fflush(stdout);
        usleep(100000);
    }

    for (int i = 0; i < dir_size; i++) {
        free(dir_cont[i]);
    }

    return 0;
}

void print_border(int row, int col) {
    printf("\u250C");
    for (int i = 2; i < col; i++) {
        printf("\u2500");
    }
    printf("\u2510\n");

    for (int i = 2; i < row - 2; i++) {
        printf("\u2502");
        printf("\033[%d;%dH", i, col);
        printf("\u2502\n");
    }

    printf("\u251C");
    for (int i = 2; i < col; i++) {
        printf("\u2500");
    }
    printf("\u2524\n");

    printf("\u2502");
    printf("\033[%d;%dH", row - 1, col);
    printf("\u2502");

    printf("\u2514");
    for (int i = 2; i < col; i++) {
        printf("\u2500");
    }
    printf("\u2518");
}

int string_compare(const void *a, const void *b) {
    char *str1 = *(char **)a;
    char *str2 = *(char **)b;
    return strcmp(str1, str2);
}
