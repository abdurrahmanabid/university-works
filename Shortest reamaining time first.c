#include <stdio.h>

typedef struct {
    int process_id;
    int burst_time;
    int arrival_time;
    int remaining_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
} Process;

void srtf_scheduling(Process processes[], int num_processes) {
    int remaining_time[num_processes];
    int completed_processes = 0;
    int current_time = 0;

    // Initialize remaining_time array
    for (int i = 0; i < num_processes; i++) {
        remaining_time[i] = processes[i].burst_time;
    }

    while (completed_processes < num_processes) {
        int shortest_index = -1;
        int shortest_time = 9999;

        // Find the process with the shortest remaining time
        for (int i = 0; i < num_processes; i++) {
            if (processes[i].arrival_time <= current_time && remaining_time[i] > 0 && remaining_time[i] < shortest_time) {
                shortest_index = i;
                shortest_time = remaining_time[i];
            }
        }

        // Execute the process for 1 unit of time
        remaining_time[shortest_index]--;
        current_time++;

        // Check if the process is completed
        if (remaining_time[shortest_index] == 0) {
            completed_processes++;
            processes[shortest_index].completion_time = current_time;
        }
    }

    // Calculate turnaround time and waiting time for each process
    for (int i = 0; i < num_processes; i++) {
        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
    }
}

int main() {
    int num_processes;

    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    Process processes[num_processes];

    // Input process information
    for (int i = 0; i < num_processes; i++) {
        printf("Enter the burst time for process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);

        printf("Enter the arrival time for process %d: ", i + 1);
        scanf("%d", &processes[i].arrival_time);

        processes[i].process_id = i + 1;
        processes[i].remaining_time = processes[i].burst_time;
    }

    srtf_scheduling(processes, num_processes);

    printf("\nProcess\tBurst Time\tArrival Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");

    // Print process details
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].process_id, processes[i].burst_time, processes[i].arrival_time,
               processes[i].completion_time, processes[i].turnaround_time, processes[i].waiting_time);
    }

    return 0;
}
