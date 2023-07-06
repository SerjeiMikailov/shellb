#include "App.h"

void remove_directory(const char *path) {
    DIR *dir = opendir(path);
    if (dir == NULL) {
        printf("Error opening directory\n");
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        char entry_path[MAX_PATH];
        snprintf(entry_path, sizeof(entry_path), "%s/%s", path, entry->d_name);

        struct stat st;
        if (lstat(entry_path, &st) == -1) {
            printf("Error getting file/directory information\n");
            continue;
        }

        if (S_ISDIR(st.st_mode)) {
            remove_directory(entry_path);
        } else {
            if (remove(entry_path) != 0) {
                printf("Error removing file: %s\n", entry_path);
            }
        }
    }

    closedir(dir);

    if (rmdir(path) != 0) {
        printf("Error removing directory: %s\n", path);
    }
}
