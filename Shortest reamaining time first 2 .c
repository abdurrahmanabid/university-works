#include <stdio.h>

void srtf_scheduling(int burst_time[], int arrival_time[], int num_processes) {
    int remaining_time[num_processes];
    int completion_time[num_processes];
    int turnaround_time[num_processes];
    int waiting_time[num_processes];
    int total_turnaround_time = 0;
    int total_waiting_time = 0;

    for (int i = 0; i < num_processes; i++) {
        remaining_time[i] = burst_time[i];
    }

    int completed_processes = 0;
    int current_time = 0;

    while (completed_processes < num_processes) {
        int shortest_index = -1;
        int shortest_time = 9999;

        for (int i = 0; i < num_processes; i++) {
            if (arrival_time[i] <= current_time && remaining_time[i] > 0 && remaining_time[i] < shortest_time) {
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
                completion_time[shortest_index] = current_time;
                turnaround_time[shortest_index] = completion_time[shortest_index] - arrival_time[shortest_index];
                waiting_time[shortest_index] = turnaround_time[shortest_index] - burst_time[shortest_index];

                total_turnaround_time += turnaround_time[shortest_index];
                total_waiting_time += waiting_time[shortest_index];
            }
        }
    }

    printf("\nProcess\tBurst Time\tArrival Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");

    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, burst_time[i], arrival_time[i], completion_time[i],
               turnaround_time[i], waiting_time[i]);
    }

    double avg_turnaround_time = (double)total_turnaround_time / num_processes;
    double avg_waiting_time = (double)total_waiting_time / num_processes;

    printf("\nAverage Turnaround Time: %.2lf\n", avg_turnaround_time);
    printf("Average Waiting Time: %.2lf\n", avg_waiting_time);
}

int main() {
    int num_processes=4;

    int burst_time[]={8,4,9,5};
    int arrival_time[]={0,1,2,3};

    srtf_scheduling(burst_time, arrival_time, num_processes);

    return 0;
}
