#include <stdio.h>
#include <stdlib.h>

#define MAX_REQUESTS 100 
#define MAX_TRACKS 200  
void scan(int requests[], int n, int head, int direction) {
    int totalSeekTime = 0;

    if (direction == 1) {
        printf("Head movement sequence: %d", head);
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
        totalSeekTime += abs(head - MAX_TRACKS);
        head = MAX_TRACKS;
        printf(" -> %d", head);
        for (int track = MAX_TRACKS - 1; track >= 0; track--) {
            for (int i = 0; i < n; i++) {
                if (requests[i] == track) {
                    totalSeekTime += abs(head - track);
                    head = track;
                    printf(" -> %d", head);
                    break;
                }
            }
        }
    } else {
        printf("Head movement sequence: %d", head);
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
        totalSeekTime += abs(head);
        head = 0;
        printf(" -> %d", head);
        for (int track = 1; track <= MAX_TRACKS; track++) {
            for (int i = 0; i < n; i++) {
                if (requests[i] == track) {
                    totalSeekTime += abs(head - track);
                    head = track;
                    printf(" -> %d", head);
                    break;
                }
            }
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

    scan(requests, n, head, direction);

    return 0;
}

