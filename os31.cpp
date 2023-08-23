#include <stdio.h>
#include <stdlib.h>

#define FRAME_SIZE 3 
void printMemory(int memory[], int n) {
    printf("Memory: ");
    for (int i = 0; i < n; i++) {
        if (memory[i] == -1) {
            printf("- ");
        } else {
            printf("%d ", memory[i]);
        }
    }
    printf("\n");
}

int main() {
    int referenceString[] = {0, 2, 1, 6, 4, 0, 1, 0, 3, 1, 2, 1}; 
    int n = sizeof(referenceString) / sizeof(referenceString[0]); 
    int memory[FRAME_SIZE]; 
    int framePointer = 0; 

    
    for (int i = 0; i < FRAME_SIZE; i++) {
        memory[i] = -1;
    }

    
    int pageFaults = 0;
    for (int i = 0; i < n; i++) {
        int page = referenceString[i];
        int pageFound = 0
		for (int j = 0; j < FRAME_SIZE; j++) {
            if (memory[j] == page) {
                pageFound = 1;
                break;
            }
        }

        if (!pageFound) {
           
            memory[framePointer] = page;
            framePointer = (framePointer + 1) % FRAME_SIZE;
            pageFaults++;
        }
        printf("Referencing Page %d: ", page);
        printMemory(memory, FRAME_SIZE);
    }

    printf("Total Page Faults: %d\n", pageFaults);

    return 0;
}

