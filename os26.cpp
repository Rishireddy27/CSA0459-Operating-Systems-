#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file; 
    char filename[] = "example.txt"; 

    
    file = fopen(filename, "w");

    
    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1; 
    }

    
    fprintf(file, "Hello, World!\n");
    fprintf(file, "This is a C program for file management.\n");

    
    fclose(file);

    
    file = fopen(filename, "r");

    
    if (file == NULL) {
        printf("Error opening the file for reading.\n");
        return 1;
    }

    
    char line[100];
    printf("Contents of the file:\n");
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    fclose(file);

    return 0; 
}

