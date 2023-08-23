#include <stdio.h>
#include <dirent.h>

int main() {
    struct dirent *entry;
    DIR *dir = opendir("."); 

    if (dir == NULL) {
        perror("Error opening directory");
        return 1;
    }

    printf("Contents of the current directory:\n");

    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }

    closedir(dir);

    return 0;
}

