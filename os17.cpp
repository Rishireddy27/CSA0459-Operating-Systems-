#include <stdio.h>
#include <stdbool.h>

#define MAX_PROCESSES 5
#define MAX_RESOURCES 3


int available[MAX_RESOURCES] = {3, 3, 2};


int maximum[MAX_PROCESSES][MAX_RESOURCES] = {
    {7, 5, 3},
    {3, 2, 2},
    {9, 0, 2},
    {2, 2, 2},
    {4, 3, 3}
};


int allocation[MAX_PROCESSES][MAX_RESOURCES] = {
    {0, 1, 0},
    {2, 0, 0},
    {3, 0, 2},
    {2, 1, 1},
    {0, 0, 2}
};


int need[MAX_PROCESSES][MAX_RESOURCES];


void calculateNeed() {
    for (int i = 0; i < MAX_PROCESSES; i++) {
        for (int j = 0; j < MAX_RESOURCES; j++) {
            need[i][j] = maximum[i][j] - allocation[i][j];
        }
    }
}


bool isSafe(int process, int request[]) {
    int work[MAX_RESOURCES];
    int finish[MAX_PROCESSES] = {0};
    int i, j;

    
    for (i = 0; i < MAX_RESOURCES; i++) {
        work[i] = available[i];
    }

   
    for (i = 0; i < MAX_RESOURCES; i++) {
        if (request[i] > need[process][i]) {
            return false;
        }
    }

    for (i = 0; i < MAX_RESOURCES; i++) {
        if (request[i] > work[i]) {
            return false;
        }
    }

    for (i = 0; i < MAX_RESOURCES; i++) {
        work[i] -= request[i];
        allocation[process][i] += request[i];
        need[process][i] -= request[i];
    }

   
    bool done;
    do {
        done = true;
        for (i = 0; i < MAX_PROCESSES; i++) {
            if (!finish[i]) {
                bool canFinish = true;
                for (j = 0; j < MAX_RESOURCES; j++) {
                    if (need[i][j] > work[j]) {
                        canFinish = false;
                        break;
                    }
                }
                if (canFinish) {
                    for (j = 0; j < MAX_RESOURCES; j++) {
                        work[j] += allocation[i][j];
                    }
                    finish[i] = 1;
                    done = false;
                }
            }
        }
    } while (!done);

   
    for (i = 0; i < MAX_PROCESSES; i++) {
        if (!finish[i]) {
            return false;
        }
    }

    return true;
}


void simulate() {
    int process, request[MAX_RESOURCES];

    // Process to be tested for a resource request
    printf("Enter process (0-%d) to request resources: ", MAX_PROCESSES - 1);
    scanf("%d", &process);

    // Resource request
    printf("Enter resource request (R1 R2 R3): ");
    for (int i = 0; i < MAX_RESOURCES; i++) {
        scanf("%d", &request[i]);
    }

    if (isSafe(process, request)) {
        printf("Resource request granted. System is safe.\n");
    } else {
        printf("Resource request denied. System would be unsafe.\n");
    }
}

int main() {
    calculateNeed();

    
    printf("Available resources:\n");
    for (int i = 0; i < MAX_RESOURCES; i++) {
        printf("R%d ", i + 1);
    }
    printf("\n");
    for (int i = 0; i < MAX_RESOURCES; i++) {
        printf("%d  ", available[i]);
    }
    printf("\n\n");

    printf("Maximum resources that each process can claim:\n");
    for (int i = 0; i < MAX_PROCESSES; i++) {
        for (int j = 0; j < MAX_RESOURCES; j++) {
            printf("R%d ", j + 1);
        }
        printf("\n");
        for (int j = 0; j < MAX_RESOURCES; j++) {
            printf("%d  ", maximum[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    printf("Currently allocated resources:\n");
    for (int i = 0; i < MAX_PROCESSES; i++) {
        for (int j = 0; j < MAX_RESOURCES; j++) {
            printf("R%d ", j + 1);
        }
        printf("\n");
        for (int j = 0; j < MAX_RESOURCES; j++) {
            printf("%d  ", allocation[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    printf("Resource need for each process:\n");
    for (int i = 0; i < MAX_PROCESSES; i++) {
        for (int j = 0; j < MAX_RESOURCES; j++) {
            printf("R%d ", j + 1);
        }
        printf("\n");
        for (int j = 0; j < MAX_RESOURCES; j++) {
            printf("%d  ", need[i][j]);
        }
        printf("\n");
    }
    printf("\n");

   
    simulate();

    return 0;
}

