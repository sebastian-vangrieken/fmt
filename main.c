#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main() {
    struct dirent* entry;
    DIR* dp = opendir(".");

    if (dp == NULL) {
        perror("opendir");
        return EXIT_FAILURE;
    }

    while ((entry = readdir(dp)) != NULL) {
        printf("Found file: %s\n", entry->d_name);
    }

    closedir(dp);
    return EXIT_SUCCESS;
}