#include <stdio.h>
#include "processus.h"

void findWaitingTimeSJF(struct Process proc[], int n) {
    proc[0].waitingTime = 0; // Le premier processus n'a pas de temps d'attente

    for (int i = 1; i < n; i++) {
        proc[i].waitingTime = proc[i - 1].burstTime + proc[i - 1].waitingTime;
    }
}

void findTurnAroundTimeSJF(struct Process proc[], int n) {
    for (int i = 0; i < n; i++) {
        proc[i].turnAroundTime = proc[i].burstTime + proc[i].waitingTime;
    }
}

void findAvgTimeSJF(struct Process proc[], int n) {
    int total_wt = 0, total_tat = 0;

    findWaitingTimeSJF(proc, n);
    findTurnAroundTimeSJF(proc, n);

    printf("Processes    Burst time    Waiting time    Turnaround time\n");
    for (int i = 0; i < n; i++) {
        total_wt += proc[i].waitingTime;
        total_tat += proc[i].turnAroundTime;
        printf(" %d ", proc[i].pid);
        printf("          %d ", proc[i].burstTime);
        printf("          %d ", proc[i].waitingTime);
        printf("            %d\n", proc[i].turnAroundTime);
    }

    printf("Average waiting time = %f\n", (float)total_wt / (float)n);
    printf("Average turnaround time = %f\n", (float)total_tat / (float)n);
}

int mainSJF(struct Process proc[], int n) {
    // struct Process proc[] = {{1, 6, 0}, {2, 8, 0}, {3, 7, 0}, {4, 3, 0}};
    // int n = sizeof(proc) / sizeof(proc[0]);

    findAvgTimeSJF(proc, n);
    return 0;
}
