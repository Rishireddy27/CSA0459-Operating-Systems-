#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 2
#define ITERATIONS 10000

int counter = 0;
pthread_mutex_t mutex;

void *increment_counter(void *thread_id) {
    int tid = *((int *)thread_id);
    for (int i = 0; i < ITERATIONS; i++) {
        pthread_mutex_lock(&mutex); 
        counter++;
        printf("Thread %d: Counter = %d\n", tid, counter);
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    pthread_mutex_init(&mutex, NULL);

    for (int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i;
        int rc = pthread_create(&threads[i], NULL, increment_counter, (void *)&thread_ids[i]);
        if (rc) {
            printf("Error creating thread %d\n", i);
            exit(-1);
        }
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&mutex);

    printf("Final Counter Value: %d\n", counter);

    return 0;
}

