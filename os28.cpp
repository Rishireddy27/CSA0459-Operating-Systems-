#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <pattern> <filename>\n", argv[0]);
        return 1;
    }

    char *pattern = argv[1];
    char *filename = argv[2];

    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    int line_number = 0;

    printf("Lines matching pattern '%s' in '%s':\n", pattern, filename);

    while (fgets(line, sizeof(line), file)) {
        line_number++;

        if (strstr(line, pattern) != NULL) {
            printf("Line %d: %s", line_number, line);
        }
    }

    fclose(file);

    return 0;
}

