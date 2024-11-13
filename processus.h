//
// Created by PFI BERTO COMPUTER on 24/10/2024.
//

#ifndef PROCESSUS_H
#define PROCESSUS_H
// Structure pour représenter un processus
struct Process {
    int pid;              // ID du processus
    int burstTime;        // Temps d'exécution
    int arrivalTime;      // Temps d'arrivée
    int waitingTime;      // Temps d'attente
    int turnAroundTime;   // Temps de rotation
    int remainingTime;
    int priority;
};
#endif //PROCESSUS_H
