#include <stdio.h>
#include <stdlib.h>

#define MAX_REQUESTS 100 


void fcfs(int requests[], int n, int head) {
    int totalSeekTime = 0;

    printf("Head movement sequence: %d", head);

    for (int i = 0; i < n; i++) {
        
        int seek = abs(head - requests[i]);
        totalSeekTime += seek;
        head = requests[i];
        printf(" -> %d", head);
    }

    printf("\nTotal seek time: %d\n", totalSeekTime);
}

int main() {
    int n; 
    int head; 
    int requests[MAX_REQUESTS]; 

    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_REQUESTS) {
        printf("Invalid number of requests.\n");
        return 1;
    }

    printf("Enter the initial head position: ");
    scanf("%d", &head);

    printf("Enter the disk requests:\n");
    for (int i = 0; i < n; i++) {
        printf("Request %d: ", i + 1);
        scanf("%d", &requests[i]);
    }

    fcfs(requests, n, head);

    return 0;
}

