//
// Created by PFI BERTO COMPUTER on 24/10/2024.
//

#include <stdio.h>

#include "processus.h"


void findWaitingTimeFCFS(struct Process proc[], int n) {
    proc[0].waitingTime = 0; // Premier processus n'a pas de temps d'attente

    for (int i = 1; i < n; i++) {
        proc[i].waitingTime = proc[i-1].burstTime + proc[i-1].waitingTime +proc[i-1].arrivalTime - proc[i].arrivalTime;
    }
}

void findTurnAroundTimeFCFS(struct Process proc[], int n) {
    for (int i = 0; i < n; i++) {
        proc[i].turnAroundTime = proc[i].burstTime + proc[i].waitingTime;
    }
}

void findAverageTimeFCFS(struct Process proc[], int n) {
    int totalWaitingTime = 0, totalTurnAroundTime = 0;

    findWaitingTimeFCFS(proc, n);
    findTurnAroundTimeFCFS(proc, n);

    printf("Processus    Burst Time    Waiting Time    Turnaround Time\n");
    for (int i = 0; i < n; i++) {
        totalWaitingTime += proc[i].waitingTime;
        totalTurnAroundTime += proc[i].turnAroundTime;
        printf(" %d\t\t%d\t\t%d\t\t%d\n", proc[i].pid, proc[i].burstTime, proc[i].waitingTime, proc[i].turnAroundTime);
    }

    printf("\nAverage waiting time = %.2f", (float)totalWaitingTime / n);
    printf("\nAverage turnaround time = %.2f\n", (float)totalTurnAroundTime / n);
}

int mainFCFS(struct Process proc[],int n) {
    // struct Process proc[] = {{1, 10, 0, 0}, {2, 5, 0, 0}, {3, 8, 0, 0}};
    // int n = sizeof proc / sizeof proc[0];

    findAverageTimeFCFS(proc, n);

    return 0;
}

