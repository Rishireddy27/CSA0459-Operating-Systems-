#include <stdio.h>
#include <stdbool.h>

struct Process 
{
int process_id;
int arrival_time;
int burst_time;
int remaining_time;
};

int findSmallestProcess(struct Process processes[], int n) 
{
int smallest_index = -1;
int smallest_burst = -1;
for (int i = 0; i < n; i++) 
{
if (processes[i].remaining_time > 0 &&
(smallest_burst == -1 || processes[i].remaining_time < smallest_burst)) 
{
smallest_burst = processes[i].remaining_time;
smallest_index = i;
}
}
return smallest_index;
}
int main() 
{
int n;
printf("Enter the number of processes: ");
scanf("%d", &n);
struct Process processes[n];
for (int i = 0; i < n; i++) 
{
processes[i].process_id = i + 1;
printf("Enter arrival time for process %d: ", i + 1);
scanf("%d", &processes[i].arrival_time);
printf("Enter burst time for process %d: ", i + 1);
scanf("%d", &processes[i].burst_time);
processes[i].remaining_time = processes[i].burst_time;
}
int current_time = 0;
int completed = 0;
while (completed < n) 
{
int smallest_index = findSmallestProcess(processes, n);
if (smallest_index == -1) 
{
current_time++;
continue;
}
struct Process *current_process = &processes[smallest_index];
printf("Time %d: Process %d\n", current_time, current_process->process_id);
current_time += current_process->remaining_time;
current_process->remaining_time = 0;
completed++;
}
return 0;
}

