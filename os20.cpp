#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define NUM_READERS 3
#define NUM_WRITERS 2

int shared_resource = 0;
int reader_count = 0;

sem_t mutex;         
sem_t resource_mutex; 
void *reader(void *arg) {
    int reader_id = *((int *)arg);
    while (1) {
        sem_wait(&mutex); 
        reader_count++;
        if (reader_count == 1) {
            sem_wait(&resource_mutex); 
        }
        sem_post(&mutex); 
        
        
        printf("Reader %d is reading: %d\n", reader_id, shared_resource);

        sem_wait(&mutex); 
        reader_count--;
        if (reader_count == 0) {
            sem_post(&resource_mutex); 
        }
        sem_post(&mutex);
        sleep(rand() % 3); 
    }
    pthread_exit(NULL);
}

void *writer(void *arg) {
    int writer_id = *((int *)arg);
    while (1) {
        sem_wait(&resource_mutex); 

        
        shared_resource++;
        printf("Writer %d is writing: %d\n", writer_id, shared_resource);

        sem_post(&resource_mutex); 

        sleep(rand() % 3); 
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t readers[NUM_READERS];
    pthread_t writers[NUM_WRITERS];

    int reader_ids[NUM_READERS];
    int writer_ids[NUM_WRITERS];

    sem_init(&mutex, 0, 1);
    sem_init(&resource_mutex, 0, 1);

    
    for (int i = 0; i < NUM_READERS; i++) {
        reader_ids[i] = i;
        pthread_create(&readers[i], NULL, reader, (void *)&reader_ids[i]);
    }

    
    for (int i = 0; i < NUM_WRITERS; i++) {
        writer_ids[i] = i;
        pthread_create(&writers[i], NULL, writer, (void *)&writer_ids[i]);
    }

    for (int i = 0; i < NUM_READERS; i++) {
        pthread_join(readers[i], NULL);
    }
    for (int i = 0; i < NUM_WRITERS; i++) {
        pthread_join(writers[i], NULL);
    }

    sem_destroy(&mutex);
    sem_destroy(&resource_mutex);

    return 0;
}

