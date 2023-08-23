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


void worstFit(struct MemoryBlock memory[], int n, int processSize) {
    int worstFitIdx = -1;
    int largestBlockSize = -1;

    for (int i = 0; i < n; i++) {
        if (!memory[i].allocated && memory[i].size >= processSize) {
            if (memory[i].size > largestBlockSize) {
                largestBlockSize = memory[i].size;
                worstFitIdx = i;
            }
        }
    }

    if (worstFitIdx != -1) {
        memory[worstFitIdx].allocated = 1;
        printf("Process of size %d allocated to memory block starting at %d\n", processSize, memory[worstFitIdx].start);
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
        worstFit(memory, n, processSize);
    }

    return 0;
}

