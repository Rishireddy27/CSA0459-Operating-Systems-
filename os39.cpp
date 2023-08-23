#include <stdio.h>
#include <stdlib.h>

#define MAX_REQUESTS 100 
#define MAX_TRACKS 200 
void cscan(int requests[], int n, int head, int direction) {
    int totalSeekTime = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (requests[j] > requests[j + 1]) {
                int temp = requests[j];
                requests[j] = requests[j + 1];
                requests[j + 1] = temp;
            }
        }
    }

    printf("Head movement sequence: %d", head);

    if (direction == 1) {
        for (int track = head; track <= MAX_TRACKS; track++) {
            for (int i = 0; i < n; i++) {
                if (requests[i] == track) {
                    totalSeekTime += abs(head - track);
                    head = track;
                    printf(" -> %d", head);
                    break;
                }
            }
        }

        
        totalSeekTime += abs(head - 0);
        head = 0;
        printf(" -> %d", head);
        
        
        for (int track = 0; track < n; track++) {
            totalSeekTime += abs(head - requests[track]);
            head = requests[track];
            printf(" -> %d", head);
        }
    } else {
        
        for (int track = head; track >= 0; track--) {
            for (int i = 0; i < n; i++) {
                if (requests[i] == track) {
                    totalSeekTime += abs(head - track);
                    head = track;
                    printf(" -> %d", head);
                    break;
                }
            }
        }

        
        totalSeekTime += abs(head - MAX_TRACKS);
        head = MAX_TRACKS;
        printf(" -> %d", head);

        
        for (int track = n - 1; track >= 0; track--) {
            totalSeekTime += abs(head - requests[track]);
            head = requests[track];
            printf(" -> %d", head);
        }
    }

    printf("\nTotal seek time: %d\n", totalSeekTime);
}

int main() {
    int n; 
    int head; 
    int direction;
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

    printf("Enter the direction (1 for right, -1 for left): ");
    scanf("%d", &direction);

    if (direction != 1 && direction != -1) {
        printf("Invalid direction.\n");
        return 1;
    }

    cscan(requests, n, head, direction);

    return 0;
}

