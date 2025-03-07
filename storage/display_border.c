#include <stdio.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>

void print_border(int, int);

int main(int argc, char **argv) {
    struct winsize ws;
    printf("\033[?25l"); // hide cursor

    while (1) {
        ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws);
        printf("\033[H\033[J"); // clear screen
        print_border(ws.ws_row, ws.ws_col);

        char input[16];
        if (fgets(input, sizeof(input), stdin) != NULL) {
            if (strcmp(input, ":q\n") == 0) {
                printf("\033[?25h"); // show cursor
                printf("\033[H\033[J");
                break;
            }
        }

        fflush(stdout);
        usleep(500000);
    }

    return 0;
}

void print_border(int row, int col) {
    printf("\u250C");
    for (int i = 2; i < col; i++) {
        printf("\u2500");
    }
    printf("\u2510\n");

    for (int i = 2; i < row - 1; i++) {
        printf("\u2502");
        printf("\033[%d;%dH", i, col);
        printf("\u2502\n");
    }

    printf("\u2514");
    for (int i = 2; i < col; i++) {
        printf("\u2500");
    }
    printf("\u2518");
}
