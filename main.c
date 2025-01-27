#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>

int main(int argc, char** argv) {
    struct winsize ws;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws);

    int middle = ((ws.ws_col - 3) / 2) + 1;
    int q1 = ((ws.ws_col - 5) / 4) + 1;
    int q3 = (((ws.ws_col - 5) / 4) * 3) + 3;

    for (int i = 0; i < ws.ws_row - 1; i++) {
        if (i == 0) {
            printf("\u250c");
            for (int j = 0; j < ws.ws_col - 2; j++) {
                if (j == middle) {
                    printf("\u252c");
                }
                else if (j == q1) {
                    printf("\u252c");
                }
                else if (j == q3) {
                    printf("\u252c");
                }
                else {
                    printf("\u2500");
                }
            }
            printf("\u2510\n");
        }
        else if (i == ws.ws_row - 2) {
            printf("\u2514");
            for (int j = 0; j < ws.ws_col - 2; j++) {
                if (j == middle) {
                    printf("\u2534");
                }
                else if (j == q1) {
                    printf("\u2534");
                }
                else if (j == q3) {
                    printf("\u2534");
                }
                else {
                    printf("\u2500");
                }
            }
            printf("\u2518\n");
        }
        else {
            printf("\u2502");
            for (int j = 0; j < ws.ws_col - 2; j++) {
                if (j == middle) {
                    printf("\u2502");
                }
                else if (j == q1) {
                    printf("\u2502");
                }
                else if (j == q3) {
                    printf("\u2502");
                }
                else {
                    printf(" ");
                }
            }
            printf("\u2502\n");
        }
    }

    printf("%d cols x %d rows, middle = %d", ws.ws_col, ws.ws_row, middle);

    return 0;
}
