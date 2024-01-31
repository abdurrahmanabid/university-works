
#include <stdio.h>
void calculateAverageTimes(int n, int burst_time[], int priority[], int arrival_time[]) {
    int remaining_time[n];
    int completion_time[n], waiting_time[n], turnaround_time[n];
    int total_waiting_time = 0, total_turnaround_time = 0;
    for (int i = 0; i < n; i++)
        remaining_time[i] = burst_time[i];
    int time = 0;
    int process_completed = 0;
    while (process_completed < n) {
        int highest_priority = -1, highest_priority_process;
        for (int i = 0; i < n; i++) {
            if (arrival_time[i] <= time && remaining_time[i] > 0) {
                if (highest_priority == -1 || priority[i] > highest_priority) {
                    highest_priority = priority[i];
                    highest_priority_process = i;
                }
            }
        }
        if (highest_priority == -1) {
            time++;
        }
         else {
            remaining_time[highest_priority_process]--;
            time++;
            if (remaining_time[highest_priority_process] == 0) {
                process_completed++;
                completion_time[highest_priority_process] = time;
                waiting_time[highest_priority_process] = completion_time[highest_priority_process] - burst_time[highest_priority_process] - arrival_time[highest_priority_process];
                turnaround_time[highest_priority_process] = completion_time[highest_priority_process] - arrival_time[highest_priority_process];
                total_waiting_time += waiting_time[highest_priority_process];
                total_turnaround_time += turnaround_time[highest_priority_process];
            }
        }
    }
    float avg_waiting_time = (float)total_waiting_time / n;
    float avg_turnaround_time = (float)total_turnaround_time / n;
    printf("Process\t\tBurst Time\tArrival Time\tPriority\tCompletion Time\t\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\t\t%d\n", i + 1, burst_time[i], arrival_time[i], priority[i], completion_time[i], waiting_time[i], turnaround_time[i]);
    }
    printf("Average Waiting Time: %.2f\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);
}
int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int burst_time[n], priority[n], arrival_time[n];
    printf("Enter burst time, priority, and arrival time for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d %d %d", &burst_time[i], &priority[i], &arrival_time[i]);
    }
    calculateAverageTimes(n, burst_time, priority, arrival_time);
    return 0;
}
