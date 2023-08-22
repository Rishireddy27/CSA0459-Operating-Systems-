#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *thread_function1(void *arg) {
    for (int i = 1; i <= 5; i++) {
        printf("Thread 1: Counter %d\n", i);
        
    }
    pthread_exit(NULL);
}
void *thread_function2(void *arg) {
    for (int i = 1; i <= 5; i++) {
        printf("Thread 2: Counter %d\n", i);
        
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t thread1, thread2; 
    
    if (pthread_create(&thread1, NULL, thread_function1, NULL) != 0) {
        perror("pthread_create");
        exit(1);
    }

    
    if (pthread_create(&thread2, NULL, thread_function2, NULL) != 0) {
        perror("pthread_create");
        exit(1);
    }

    
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Both threads have finished.\n");

    return 0;
}

