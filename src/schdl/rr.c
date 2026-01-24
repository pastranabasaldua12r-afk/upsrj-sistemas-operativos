#include <stdio.h>
#include "process.h"

/* ============================================================
 * Student implementation area
 * ============================================================ */
void rr_schedule(Process p[], int n, int quantum)
{
    int time = 0;
    int completed = 0;
    int remaining_bt[n];
    int visited[n];

    for (int i = 0; i < n; i++)
    {
        remaining_bt[i] = p[i].burst_time;
        visited[i] = 0;
    }

    while (completed < n)
    {
        int executed = 0;

        for (int i = 0; i < n; i++)
        {
            if (remaining_bt[i] > 0 && p[i].arrival_time <= time)
            {
                executed = 1;

                if (visited[i] == 0)
                {
                    p[i].waiting_time = time - p[i].arrival_time;
                    visited[i] = 1;
                }

                if (remaining_bt[i] > quantum)
                {
                    time += quantum;
                    remaining_bt[i] -= quantum;
                }
                else
                {
                    time += remaining_bt[i];
                    remaining_bt[i] = 0;
                    p[i].turnaround_time = time - p[i].arrival_time;
                    completed++;
                }
            }
        }

        /* If no process was executed, CPU is idle */
        if (!executed)
        {
            time++;
        }
    }
}


/* ============================================================
 * DO NOT MODIFY MAIN
 * ============================================================ */
#ifndef UNIT_TEST
int main(void)
{
    int n;
    int quantum;

    printf("Número de procesos: ");
    scanf("%d", &n);

    printf("Quantum: ");
    scanf("%d", &quantum);

    Process p[n];
    read_processes(p, n);
    init_processes(p, n);

    rr_schedule(p, n, quantum);

    print_results(p, n, "RR Scheduling");
    return 0;
}
#endif