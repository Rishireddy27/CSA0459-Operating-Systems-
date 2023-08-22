#include <stdio.h>
#include <stdbool.h>

#define MAX_PROCESSES 10

typedef struct {
    int id;
    int arrival_time;
    int burst_time;
    int remaining_time;
} Process;

int main() {
    int n, time_quantum;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    Process processes[MAX_PROCESSES];

    for (int i = 0; i < n; i++) {
        printf("Enter details for process %d:\n", i + 1);
        processes[i].id = i + 1;
        printf("Arrival Time: ");
        scanf("%d", &processes[i].arrival_time);
        printf("Burst Time: ");
        scanf("%d", &processes[i].burst_time);
        processes[i].remaining_time = processes[i].burst_time;
    }

    printf("Enter time quantum: ");
    scanf("%d", &time_quantum);

    int current_time = 0;
    int completed = 0;

    printf("\nGantt Chart:\n");

    while (completed < n) {
        bool is_completed = true;

        for (int i = 0; i < n; i++) {
            if (processes[i].remaining_time > 0) {
                is_completed = false;

                if (processes[i].remaining_time > time_quantum) {
                    printf("%d - P%d - ", current_time, processes[i].id);
                    current_time += time_quantum;
                    processes[i].remaining_time -= time_quantum;
                } else {
                    printf("%d - P%d - ", current_time, processes[i].id);
                    current_time += processes[i].remaining_time;
                    processes[i].remaining_time = 0;
                    completed++;
                }
            }
        }

        if (is_completed) {
            current_time++;
        }
    }

    printf("%d\n", current_time);

    return 0;
}

