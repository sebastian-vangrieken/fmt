#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>

int main(int argc, char** argv) {
    struct winsize ws;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws);

    int middle = ((ws.ws_col - (ws.ws_col % 2)) / 2) + 1;

    for (int i = 1; i < ws.ws_row; i++) {
        if (i == 1) {
            printf("|");
            for (int j = 1; j < ws.ws_col - 1; j++) {
                if (j == middle) {
                    printf("|");
                }
                else {
                    printf("-");
                }
            }
            printf("|\n");
        }
        else if (i == ws.ws_row - 1) {
            printf("|");
            for (int j = 1; j < ws.ws_col - 1; j++) {
                if (j == middle) {
                    printf("|");
                }
                else {
                    printf("_");
                }
            }
            printf("|\n");
        }
        else {
            printf("|");
            for (int j = 0; j < ws.ws_col - 2; j++) {
                if (j == middle - 1) {
                    printf("|");
                }
                else {
                    printf(" ");
                }
            }
            printf("|\n");
        }
    }

    printf("%d cols x %d rows, middle = %d", ws.ws_col, ws.ws_row, middle);

    return 0;
}
