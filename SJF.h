//
// Created by PFI BERTO COMPUTER on 24/10/2024.
//

#ifndef SJF_H
#define SJF_H

#include <stdio.h>
#include "processus.h"

void findWaitingTimeSJF(struct Process proc[], int n);

void findTurnAroundTimeSJF(struct Process proc[], int n) ;

void findAvgTimeSJF(struct Process proc[], int n);

int mainSJF(struct Process proc[], int n) ;

#endif //SJF_H
