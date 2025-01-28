#include "getcwd.h"

#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

char* get_current_working_dir() {
    size_t size = 100;

    while (1) {
        char* buffer = (char*)malloc(size);

        if (getcwd(buffer, size) == buffer) {
            return buffer;
        }
        free(buffer);

        if (errno != ERANGE) {
            return 0;
        }

        size *= 2;
    }
}