#include <stdio.h>
#define MAX_PROCESS 10
int n, i;
int pid[MAX_PROCESS];
int burst_time[MAX_PROCESS];
int arrival_time[MAX_PROCESS];
int priority[MAX_PROCESS];
int remaining_time[MAX_PROCESS] = {0};
int completed = 0;
int current_time = 0;
int highest_priority = -1;
int completion_time[MAX_PROCESS] = {0};
int turnaround_time[MAX_PROCESS] = {0};
int waiting_time[MAX_PROCESS] = {0};
float avg_turnaround_time = 0;
float avg_waiting_time = 0;

void main()
{
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter the brust time and priority for process %d: ", i + 1);
        arrival_time[i] = 0;

        scanf("%d", &burst_time[i]);

        scanf("%d", &priority[i]);

        pid[i] = i + 1;
        remaining_time[i] = burst_time[i];
    }
    priorityScheduling();
}

void priorityScheduling()
{
    while (completed != n)
    {
        highest_priority = -1;
        for (i = 0; i < n; i++)
        {
            if (arrival_time[i] <= current_time && remaining_time[i] > 0)
            {
                if (highest_priority == -1 || priority[i] < priority[highest_priority])
                {
                    highest_priority = i;
                }
            }
        }

        remaining_time[highest_priority]--;

        if (remaining_time[highest_priority] == 0)
        {
            completed++;
            completion_time[highest_priority] = current_time + 1;
        }

        current_time++;
    }
    calculate();
}
void calculate()
{

    // Calculate turnaround time and waiting time for each process
    for (i = 0; i < n; i++)
    {
        turnaround_time[i] = completion_time[i] - arrival_time[i];
        waiting_time[i] = turnaround_time[i] - burst_time[i];

        avg_turnaround_time += turnaround_time[i];
        avg_waiting_time += waiting_time[i];
    }

    avg_turnaround_time /= n;
    avg_waiting_time /= n;

    printf("\nProcess\tBurst Time\tArrival Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", pid[i], burst_time[i], arrival_time[i], completion_time[i], turnaround_time[i], waiting_time[i]);
    }

    printf("\nAverage Turnaround Time: %.2f\n", avg_turnaround_time);
    printf("Average Waiting Time: %.2f\n", avg_waiting_time);
}

