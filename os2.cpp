#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 4096

int main(int argc, char *argv[]) {
if (argc != 3) {
    fprintf(stderr, "Usage: %s <source_file> <destination_file>\n", argv[0]);
    return 1;
}

int source_fd = open(argv[1], O_RDONLY);
if (source_fd == -1) {
    perror("Error opening source file");
    return 1;
}

int dest_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0666);
if (dest_fd == -1) {
    perror("Error opening destination file");
    close(source_fd);
    return 1;
}

char buffer[BUFFER_SIZE];
ssize_t bytes_read;

while ((bytes_read = read(source_fd, buffer, BUFFER_SIZE)) > 0) {
    ssize_t bytes_written = write(dest_fd, buffer, bytes_read);
    if (bytes_written == -1) {
        perror("Error writing to destination file");
        close(source_fd);
        close(dest_fd);
        return 1;
}
}

if (bytes_read == -1) {
    perror("Error reading from source file");
    close(source_fd);
    close(dest_fd);
    return 1;
}

close(source_fd);
close(dest_fd);

printf("File copy successful.\n");

return 0;
}

