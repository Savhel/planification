//
// Created by PFI BERTO COMPUTER on 26/10/2024.
//
#include <stdio.h>
#include <limits.h>
#include "processus.h"

void findWaitingTimeSRTF(struct Process proc[], int n) {
    int rt[n];
    for (int i = 0; i < n; i++) {
        rt[i] = proc[i].burstTime;
    }
    int complete = 0, t = 0, minm = INT_MAX;
    int shortest = 0, finish_time;
    int check = 0;

    while (complete != n) {
        for (int j = 0; j < n; j++) {
            if ((rt[j] < minm) && (rt[j] > 0) && (proc[j].arrivalTime <= t)) {
                minm = rt[j];
                shortest = j;
                check = 1;
            }
        }

        if (check == 0) {
            t++;
            continue;
        }

        rt[shortest]--;
        minm = rt[shortest];
        if (minm == 0) {
            minm = INT_MAX;
        }

        if (rt[shortest] == 0) {
            complete++;
            check = 0;
            finish_time = t + 1;
            proc[shortest].waitingTime = finish_time - proc[shortest].burstTime - proc[shortest].arrivalTime;
            if (proc[shortest].waitingTime < 0) {
                proc[shortest].waitingTime = 0;
            }
        }
        t++;
    }
}

void findTurnAroundTimeSRTF(struct Process proc[], int n) {
    for (int i = 0; i < n; i++) {
        proc[i].turnAroundTime = proc[i].burstTime + proc[i].waitingTime;
    }
}

void findAvgTimeSRTF(struct Process proc[], int n) {
    int total_wt = 0, total_tat = 0;

    findWaitingTimeSRTF(proc, n);
    findTurnAroundTimeSRTF(proc, n);

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

int mainSRTF(struct Process proc[], int n) {
    // struct Process proc[] = {{1, 6, 1}, {2, 8, 1}, {3, 7, 2}, {4, 3, 3}};
    // int n = sizeof(proc) / sizeof(proc[0]);

    findAvgTimeSRTF(proc, n);
    return 0;
}
