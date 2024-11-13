#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "processus.h"

void findWaitingTimeRR(struct Process proc[], int n, int quantum) {
    int t = 0; // temps actuel

    while (1) {
        bool done = true;
        for (int i = 0; i < n; i++) {
            if (proc[i].remainingTime > 0) {
                done = false; // Il reste des processus à traiter

                if (proc[i].remainingTime > quantum) {
                    t += quantum;
                    proc[i].remainingTime -= quantum;
                } else {
                    t += proc[i].remainingTime;
                    proc[i].waitingTime = t - proc[i].burstTime;
                    proc[i].remainingTime = 0;
                }
            }
        }

        if (done == true) break;
    }
}

void findTurnAroundTimeRR(struct Process proc[], int n) {
    for (int i = 0; i < n; i++) {
        proc[i].turnAroundTime = proc[i].burstTime + proc[i].waitingTime;
    }
}

void findAvgTimeRR(struct Process proc[], int n, int quantum) {
    int totalWaitingTime = 0, totalTurnAroundTime = 0;

    for (int i = 0; i < n; i++)
        proc[i].remainingTime = proc[i].burstTime;

    findWaitingTimeRR(proc, n, quantum);
    findTurnAroundTimeRR(proc, n);

    printf("Processus    Burst Time    Waiting Time    Turnaround Time\n");
    for (int i = 0; i < n; i++) {
        totalWaitingTime += proc[i].waitingTime;
        totalTurnAroundTime += proc[i].turnAroundTime;
        printf(" %d\t\t%d\t\t%d\t\t%d\n", proc[i].pid, proc[i].burstTime, proc[i].waitingTime, proc[i].turnAroundTime);
    }

    printf("Average waiting time = %.2f\n", (float)totalWaitingTime / n);
    printf("Average turnaround time = %.2f\n", (float)totalTurnAroundTime / n);
}

int mainRR(struct Process proc[], int n, int quantum) {
    // struct Process proc[] = {{1, 10, 0, 0, 0}, {2, 5, 0, 0, 0}, {3, 8, 0, 0, 0}};
    // int n = sizeof proc / sizeof proc[0];
    // int quantum = 4;

    findAvgTimeRR(proc, n, quantum);

    return 0;
}
