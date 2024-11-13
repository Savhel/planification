//
// Created by PFI BERTO COMPUTER on 26/10/2024.
//

#include "RRP.h"
#include <stdio.h>
#include <stdbool.h>
#include "processus.h"


void findWaitingTimeRRP(struct Process proc[], int n, int quantum) {
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

void findTurnAroundTimeRRP(struct Process proc[], int n) {
    for (int i = 0; i < n; i++) {
        proc[i].turnAroundTime = proc[i].burstTime + proc[i].waitingTime;
    }
}

void findAvgTimeRRP(struct Process proc[], int n, int quantum) {
    int totalWaitingTime = 0, totalTurnAroundTime = 0;

    for (int i = 0; i < n; i++)
        proc[i].remainingTime = proc[i].burstTime;

    findWaitingTimeRRP(proc, n, quantum);
    findTurnAroundTimeRRP(proc, n);

    printf("Processus    Burst Time    Waiting Time    Turnaround Time    Priorité\n");
    for (int i = 0; i < n; i++) {
        totalWaitingTime += proc[i].waitingTime;
        totalTurnAroundTime += proc[i].turnAroundTime;
        printf(" %d\t\t%d\t\t%d\t\t%d\t\t%d\n", proc[i].pid, proc[i].burstTime, proc[i].waitingTime, proc[i].turnAroundTime, proc[i].priority);
    }

    printf("Average waiting time = %.2f\n", (float)totalWaitingTime / n);
    printf("Average turnaround time = %.2f\n", (float)totalTurnAroundTime / n);
}

int mainRRP(struct Process proc[], int n, int quantum) {
    findAvgTimeRRP(proc, n, quantum);

    return 0;
}
