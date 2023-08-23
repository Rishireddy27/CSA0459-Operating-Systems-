#include <stdio.h>
#include <pthread.h>

void* thread_function(void* arg) {
    printf("This is a thread.\n");
    return NULL;
}

int main() {
    pthread_t thread_id;
    
    if (pthread_create(&thread_id, NULL, thread_function, NULL) != 0) {
        fprintf(stderr, "Thread creation failed.\n");
        return 1;
    }
    
    pthread_join(thread_id, NULL);
    printf("Main thread exiting.\n");
    return 0;
}

