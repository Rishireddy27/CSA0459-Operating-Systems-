#include <stdio.h>

#define MEMORY_SIZE 1000


struct MemoryBlock {
    int start;
    int size;
    int allocated;
};


void initializeMemory(struct MemoryBlock memory[], int n) {
    for (int i = 0; i < n; i++) {
        memory[i].start = 0;
        memory[i].size = 0;
        memory[i].allocated = 0;
    }
}


void bestFit(struct MemoryBlock memory[], int n, int processSize) {
    int bestFitIdx = -1;
    int smallestBlockSize = MEMORY_SIZE + 1; 
    for (int i = 0; i < n; i++) {
        if (!memory[i].allocated && memory[i].size >= processSize) {
            if (memory[i].size < smallestBlockSize) {
                smallestBlockSize = memory[i].size;
                bestFitIdx = i;
            }
        }
    }

    if (bestFitIdx != -1) {
        memory[bestFitIdx].allocated = 1;
        printf("Process of size %d allocated to memory block starting at %d\n", processSize, memory[bestFitIdx].start);
    } else {
        printf("Unable to allocate memory for process of size %d\n", processSize);
    }
}

int main() {
    int n;
    printf("Enter the number of memory blocks: ");
    scanf("%d", &n);

    struct MemoryBlock memory[n];

    printf("Enter the details of each memory block:\n");
    for (int i = 0; i < n; i++) {
        printf("Memory Block %d (start address and size): ", i + 1);
        scanf("%d %d", &memory[i].start, &memory[i].size);
        memory[i].allocated = 0;
    }

    int numProcesses;
    printf("Enter the number of processes: ");
    scanf("%d", &numProcesses);

    for (int i = 0; i < numProcesses; i++) {
        int processSize;
        printf("Enter the size of process %d: ", i + 1);
        scanf("%d", &processSize);
        bestFit(memory, n, processSize);
    }

    return 0;
}

