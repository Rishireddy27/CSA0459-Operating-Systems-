#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t child_pid;

    
    child_pid = fork();

    if (child_pid < 0) {
        perror("Fork failed");
        return 1;
    }

   
    if (child_pid > 0) {
        printf("Parent process (PID=%d) created a child process (PID=%d)\n", getpid(), child_pid);
    }

   
    if (child_pid == 0) {
        printf("Child process (PID=%d) is running, and its parent is (PPID=%d)\n", getpid(), getppid());
    }

    return 0;
}

