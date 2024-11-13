//
// Created by PFI BERTO COMPUTER on 26/10/2024.
//

#ifndef SRTF_H
#define SRTF_H
//
// Created by PFI BERTO COMPUTER on 26/10/2024.
//
#include <stdio.h>
#include <limits.h>

void findWaitingTimeSRTF(struct Process proc[], int n);

void findTurnAroundTimeSRTF(struct Process proc[], int n) ;

void findAvgTimeSRTF(struct Process proc[], int n) ;

int mainSRTF(struct Process proc[], int n);

#endif //SRTF_H
