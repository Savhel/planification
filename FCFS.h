//
// Created by PFI BERTO COMPUTER on 24/10/2024.
//

#ifndef FCFS_H
#define FCFS_H


//
// Created by PFI BERTO COMPUTER on 24/10/2024.
//

#include "processus.h"



void findWaitingTimeFCFS(struct Process proc[], int n);
void findTurnAroundTimeFCFS(struct Process proc[], int n);

void findAverageTimeFCFS(struct Process proc[], int n);

int mainFCFS();



#endif //FCFS_H
