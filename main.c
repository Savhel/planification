#include <stdio.h>

#include <stdio.h>
#include <stdbool.h>
#include "FCFS.h"
#include "processus.h"
#include "SJF.h"
#include "RR.h"
#include "SRTF.h"
#include "RRP.h"
#include <time.h>
#include <stdlib.h>
#include <limits.h>

//hello world
int main(void) {
    srand(time(NULL));
    int NB_PROCESSUS = rand() % 20 + 1;
    //struct Process proc[] = {{1, 10, 0, 0, 0}, {2, 5, 0, 0, 0}, {3, 8, 0, 0, 0}};
    struct Process proc[NB_PROCESSUS];
    //generation des processu aleatoirement
    for (int i = 0; i < NB_PROCESSUS; i++) {
        proc[i].pid = i + 1;
        proc[i].burstTime = rand() % 10 + 1; // temps de burst aléatoire entre 1 et 10
        proc[i].waitingTime = 0;
        proc[i].turnAroundTime = 0;
        proc[i].arrivalTime = rand() % 10 + 1; // temps de burst aléatoire entre 1 et 10
        proc[i].remainingTime = 0;
        proc[i].priority = rand() % 10 + 1;
    }
    //filn de generation aleatoire
    int n = sizeof proc / sizeof proc[0];
    int quantum = 4;
    int choice = 5 ;
    printf("Bonjour a toi !\n");
    printf("testons les algorithmes FCFS,SJF et RR\n");
    printf("Voici les processus \n");
    printf("Processus    Burst Time     Arrival Time    Waiting Time    Turnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf(" %d\t\t%d\t\t%d\t\t%d\t%d\n", proc[i].pid, proc[i].burstTime, proc[i].arrivalTime, proc[i].waitingTime, proc[i].turnAroundTime);
    }
    printf("Quels algorithmes veux tu appliquer aux processus ? \n\n");
    printf("1. FCFS \n2. SJF \n3. RR \n4.SRTF \n5. RRP  \n0. pour sortir \n");
    scanf("%d",&choice);
    while (choice != 0) {
        switch (choice) {
            case 1:
                mainFCFS(proc, n);
                break;
            case 2:
                mainSJF(proc, n);
                break;
            case 3:
                mainRR(proc, n, quantum);
                break;
            case 4:
                mainSRTF(proc, n);
                break;
            case 5:
                mainRRP(proc, n, quantum);
                break;
            default:
                printf("Hello, World!\n");
                break;
        }
        printf("Quels algorithmes veux tu appliquer a ces memes processus ? \n\n");
        printf("1. FCFS \n2. SJF \n3. RR \n4.SRTF \n5. RRP \n0. pour sortir \n");
        scanf("%d",&choice);

    }
    return 0;
}

