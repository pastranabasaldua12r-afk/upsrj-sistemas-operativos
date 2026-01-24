#include <stdio.h>
#include "process.h"

/* ============================================================
 * Student implementation area
 * ============================================================ */



void fcfs_schedule(Process p[], int n)
{
    // Ordenar por arrival_time
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (p[j].arrival_time > p[j + 1].arrival_time)
            {
                Process tmp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = tmp;
            }
        }
    }

    // Calcular tiempos (SIN CPU idle)
    p[0].waiting_time = 0;
    p[0].turnaround_time = p[0].burst_time;

    for (int i = 1; i < n; i++)
    {
        p[i].waiting_time = p[i - 1].waiting_time + p[i - 1].burst_time;
        p[i].turnaround_time = p[i].waiting_time + p[i].burst_time;
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

    fcfs_schedule(p, n);

    print_results(p, n, "FCFS Scheduling");
    return 0;
}
#endif
