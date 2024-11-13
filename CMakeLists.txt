cmake_minimum_required(VERSION 3.29)
project(Planification C)

set(CMAKE_C_STANDARD 11)

add_executable(Planification main.c
        FCFS.c
        FCFS.h
        processus.h
        SJF.c
        SJF.h
        RR.c
        RR.h
        SRTF.c
        SRTF.h
        RRP.c
        RRP.h)
