#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>

int main(int argc, char **argv) {
    struct winsize ws;

    while (1) {
        ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws);
        printf("\033[H\033[J"); // clear screen
        printf("\033[%d;%dH", ws.ws_row / 2, ws.ws_col / 2);
        printf("\u2588\u2588");
        printf("\033[%d;1H", ws.ws_row);

        fflush(stdout);
        usleep(100000); // 100ms
    }

    return 0;
}
