#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    
    int fd;
    char buffer[100];
    const char *filename = "example.txt";
    const char *text = "This is a test message.\n";

    fd = creat(filename, 0644);
    if (fd < 0) {
        perror("Error creating file");
        exit(1);
    }

    write(fd, text, strlen(text));
    close(fd);

    
    fd = open(filename, O_RDONLY);
    if (fd < 0) {
        perror("Error opening file");
        exit(1);
    }

   
    printf("Contents of %s:\n", filename);
    while (read(fd, buffer, sizeof(buffer)) > 0) {
        printf("%s", buffer);
    }

    close(fd);

    
    fd = open(filename, O_WRONLY | O_APPEND);
    if (fd < 0) {
        perror("Error opening file for appending");
        exit(1);
    }

    const char *newText = "This is an appended message.\n";
    write(fd, newText, strlen(newText));

    close(fd);

   
    fd = open(filename, O_RDONLY);
    if (fd < 0) {
        perror("Error reopening file for reading");
        exit(1);
    }

    printf("\nUpdated contents of %s:\n", filename);
    while (read(fd, buffer, sizeof(buffer)) > 0) {
        printf("%s", buffer);
    }

    close(fd);

   
    if (unlink(filename) == 0) {
        printf("\nFile %s deleted successfully.\n", filename);
    } else {
        perror("Error deleting file");
    }

    return 0;
}

