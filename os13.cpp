#include <stdio.h>
#include <stdlib.h>

#define MEMORY_SIZE 1000 


struct MemoryBlock {
    int id;
    int size;
    int allocated;
    struct MemoryBlock* next;
};


struct MemoryBlock* initializeBlock(int id, int size) {
    struct MemoryBlock* block = (struct MemoryBlock*)malloc(sizeof(struct MemoryBlock));
    block->id = id;
    block->size = size;
    block->allocated = 0;
    block->next = NULL;
    return block;
}


int allocateFirstFit(struct MemoryBlock* head, int processId, int size) {
    struct MemoryBlock* current = head;

    while (current != NULL) {
        if (!current->allocated && current->size >= size) {
            current->allocated = 1;
            current->id = processId;
            return 1;
        }
        current = current->next;
    }

    return 0; 
}


int allocateBestFit(struct MemoryBlock* head, int processId, int size) {
    struct MemoryBlock* current = head;
    struct MemoryBlock* bestFit = NULL;

    while (current != NULL) {
        if (!current->allocated && current->size >= size) {
            if (bestFit == NULL || current->size < bestFit->size) {
                bestFit = current;
            }
        }
        current = current->next;
    }

    if (bestFit != NULL) {
        bestFit->allocated = 1;
        bestFit->id = processId;
        return 1;
    }

    return 0; 
}


int allocateWorstFit(struct MemoryBlock* head, int processId, int size) {
    struct MemoryBlock* current = head;
    struct MemoryBlock* worstFit = NULL;

    while (current != NULL) {
        if (!current->allocated && current->size >= size) {
            if (worstFit == NULL || current->size > worstFit->size) {
                worstFit = current;
            }
        }
        current = current->next;
    }

    if (worstFit != NULL) {
        worstFit->allocated = 1;
        worstFit->id = processId;
        return 1;
    }

    return 0; 
}

 
void printMemory(struct MemoryBlock* head) {
    struct MemoryBlock* current = head;

    while (current != NULL) {
        printf("Block %d (Size: %d, Allocated: %s, Process ID: %d)\n",
            current->id, current->size, current->allocated ? "Yes" : "No", current->id);
        current = current->next;
    }
}

int main() {
    struct MemoryBlock* memory = initializeBlock(1, MEMORY_SIZE);

    
    printf("Initial Memory Status:\n");
    printMemory(memory);
    printf("\n");

    int processId = 1;

    
    printf("Allocating using First Fit:\n");
    allocateFirstFit(memory, processId++, 200);
    allocateFirstFit(memory, processId++, 300);
    allocateFirstFit(memory, processId++, 150);
    printMemory(memory);
    printf("\n");

    
    free(memory);
    memory = initializeBlock(1, MEMORY_SIZE);
    processId = 1;

    
    printf("Allocating using Best Fit:\n");
    allocateBestFit(memory, processId++, 200);
    allocateBestFit(memory, processId++, 300);
    allocateBestFit(memory, processId++, 150);
    printMemory(memory);
    printf("\n");

    
    free(memory);
    memory = initializeBlock(1, MEMORY_SIZE);
    processId = 1;

   
    printf("Allocating using Worst Fit:\n");
    allocateWorstFit(memory, processId++, 200);
    allocateWorstFit(memory, processId++, 300);
    allocateWorstFit(memory, processId++, 150);
    printMemory(memory);

    free(memory);

    return 0;
}

