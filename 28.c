//28. Write a program to get maximum and minimum real time priority.
/*Name - prog28.c
Author-Rishika Gupta 
Roll no - MT2024127
Date - 30/08/24*/
//============================================================================
#include <stdio.h>
#include <sched.h>

int main() {
    int maxfifo, minfifo;
    int maxrr, minrr;

   
    maxfifo = sched_get_priority_max(SCHED_FIFO);
    minfifo = sched_get_priority_min(SCHED_FIFO);

   
    maxrr = sched_get_priority_max(SCHED_RR);
    minrr = sched_get_priority_min(SCHED_RR);

   
    printf("SCHED_FIFO:\n");
    printf("Maximum priority: %d\n", maxfifo);
    printf("Minimum priority: %d\n", minfifo);

    printf("SCHED_RR:\n");
    printf("Maximum priority: %d\n", maxrr);
    printf("Minimum priority: %d\n", minrr);

    return 0;
}

/*SCHED_FIFO:
Maximum priority: 99
Minimum priority: 1
SCHED_RR:
Maximum priority: 99
Minimum priority: 1
*/
