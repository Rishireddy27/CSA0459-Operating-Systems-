#include <stdio.h>
#include <pthread.h>

void* thread_function(void* arg) {
    pthread_t my_thread_id = pthread_self();
    
    if (pthread_equal(my_thread_id, *((pthread_t*)arg))) {
        printf("These threads are equal.\n");
    } else {
        printf("These threads are not equal.\n");
    }
    
    pthread_exit(NULL);
}

int main() {
    pthread_t thread_id;
    
    if (pthread_create(&thread_id, NULL, thread_function, &thread_id) != 0) {
        fprintf(stderr, "Thread creation failed.\n");
        return 1;
    }
    
    pthread_join(thread_id, NULL);
    printf("Main thread exiting.\n");
    return 0;
}

