//
// Created by PFI BERTO COMPUTER on 26/10/2024.
//

#ifndef RRP_H
#define RRP_H
//
// Created by PFI BERTO COMPUTER on 26/10/2024.
//

#include "RRP.h"
#include "processus.h"

void findWaitingTimeRRP(struct Process proc[], int n, int quantum);

void findTurnAroundTimeRRP(struct Process proc[], int n);

void findAvgTimeRRP(struct Process proc[], int n, int quantum);

int mainRRP(struct Process proc[], int n, int quantum);

#endif //RRP_H
