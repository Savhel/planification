//
// Created by PFI BERTO COMPUTER on 24/10/2024.
//

#ifndef RR_H
#define RR_H
#include "processus.h"

void findWaitingTimeRR(struct Process proc[], int n, int quantum);

void findTurnAroundTimeRR(struct Process proc[], int n);

void findAvgTimeRR(struct Process proc[], int n, int quantum);

int mainRR(struct Process proc[], int n, int quantum);


#endif //RR_H
