#include <stdio.h>
#include "process.h"

/* ============================================================
 * Student implementation area
 * ============================================================ */
void sjf_schedule(Process p[], int n)
{
    int time = 0;
    int completed = 0;
    int visited[n];
    Process result[n];

    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    /* Main loop: continue until all processes are scheduled */
    while (completed < n)
    {
        int idx = -1;
        int min_bt = 999999;

        /* Search for the shortest job among the processes that have already arrived */
        for (int i = 0; i < n; i++)
        {
            if (visited[i] == 0 && p[i].arrival_time <= time)
            {
                if (p[i].burst_time < min_bt)
                {
                    min_bt = p[i].burst_time;
                    idx = i;
                }
            }
        }

        /* If no process is available, CPU is idle */
        if (idx == -1)
        {
            time++;
            continue;
        }

        visited[idx] = 1;

        p[idx].waiting_time = time - p[idx].arrival_time;
        p[idx].turnaround_time = p[idx].waiting_time + p[idx].burst_time;
        time += p[idx].burst_time;

        result[completed] = p[idx];
        completed++;
    }

    /* Copy final execution order */
    for (int i = 0; i < n; i++)
    {
        p[i] = result[i];
    }
}

/* ============================================================
 * DO NOT MODIFY MAIN
 * ============================================================ */
#ifndef UNIT_TEST
int main(void)
{
    int n;
    printf("Número de procesos: ");
    scanf("%d", &n);

    Process p[n];
    read_processes(p, n);
    init_processes(p, n);

    sjf_schedule(p, n);

    print_results(p, n, "SJF Scheduling");
    return 0;
}
#endif