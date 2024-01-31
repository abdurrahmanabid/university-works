#include <stdio.h>

typedef struct {
    int process_id;
    int burst_time;
    int arrival_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
} Process;

void srtf_scheduling(Process processes[], int num_processes) {
    int remaining_time[num_processes];

    for (int i = 0; i < num_processes; i++) {
        remaining_time[i] = processes[i].burst_time;
    }

    int completed_processes = 0;
    int current_time = 0;

    while (completed_processes < num_processes) {
        int shortest_index = -1;
        int shortest_time = 9999;

        for (int i = 0; i < num_processes; i++) {
            if (processes[i].arrival_time <= current_time && remaining_time[i] > 0 && remaining_time[i] < shortest_time) {
                shortest_index = i;
                shortest_time = remaining_time[i];
            }
        }

        if (shortest_index == -1) {
            current_time++;
        } else {
            remaining_time[shortest_index]--;
            current_time++;

            if (remaining_time[shortest_index] == 0) {
                completed_processes++;
                processes[shortest_index].completion_time = current_time;
                processes[shortest_index].turnaround_time = processes[shortest_index].completion_time - processes[shortest_index].arrival_time;
                processes[shortest_index].waiting_time = processes[shortest_index].turnaround_time - processes[shortest_index].burst_time;
            }
        }
    }
}

int main() {
    int num_processes;

    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    Process processes[num_processes];

    for (int i = 0; i < num_processes; i++) {
        printf("Enter the burst time for process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);

        printf("Enter the arrival time for process %d: ", i + 1);
        scanf("%d", &processes[i].arrival_time);

        processes[i].process_id = i + 1;
        processes[i].completion_time = 0;
        processes[i].turnaround_time = 0;
        processes[i].waiting_time = 0;
    }

    srtf_scheduling(processes, num_processes);

    int total_turnaround_time = 0;
    int total_waiting_time = 0;

    printf("\nProcess\tBurst Time\tArrival Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");

    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].process_id, processes[i].burst_time, processes[i].arrival_time,
               processes[i].completion_time, processes[i].turnaround_time, processes[i].waiting_time);

        total_turnaround_time += processes[i].turnaround_time;
        total_waiting_time += processes[i].waiting_time;
    }

    double avg_turnaround_time = (double)total_turnaround_time / num_processes;
    double avg_waiting_time = (double)total_waiting_time / num_processes;

    printf("\nAverage Turnaround Time: %.2lf\n", avg_turnaround_time);
    printf("Average Waiting Time: %.2lf\n", avg_waiting_time);

    return 0;
}
