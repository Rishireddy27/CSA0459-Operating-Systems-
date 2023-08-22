#include <stdio.h>

struct Process 
{
int process_id;
int arrival_time;
int burst_time;
int waiting_time;
int turnaround_time;
};
void calculateTimes(struct Process processes[], int n) 
{
processes[0].waiting_time = 0;
processes[0].turnaround_time = processes[0].burst_time;
for (int i = 1; i < n; i++) 
{
processes[i].waiting_time = processes[i - 1].waiting_time + processes[i - 1].burst_time;
processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
}
}
void displayResults(struct Process processes[], int n) {
printf("Process\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
for (int i = 0; i < n; i++) 
{
printf("%d\t%d\t\t%d\t\t%d\t\t%d\n",
processes[i].process_id,
processes[i].arrival_time,
processes[i].burst_time,
processes[i].waiting_time,
processes[i].turnaround_time);
}
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
processes[i].arrival_time = 0;
printf("Enter burst time for process %d: ", i + 1);
scanf("%d", &processes[i].burst_time);
}
calculateTimes(processes, n);
displayResults(processes, n);
return 0;
}

