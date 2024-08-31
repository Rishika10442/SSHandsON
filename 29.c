//29. Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,
//SCHED_RR).
/*Name - prog29.c
Author-Rishika Gupta 
Roll no - MT2024127
Date - 30/08/24*/
//============================================================================
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <unistd.h>

void print_policy(int pol) {
    switch (pol) {
        case SCHED_OTHER:
            printf("Current scheduling policy: SCHED_OTHER\n");
            break;
        case SCHED_FIFO:
            printf("Current scheduling policy: SCHED_FIFO\n");
            break;
        case SCHED_RR:
            printf("Current scheduling policy: SCHED_RR\n");
            break;
        default:
            printf("Unknown scheduling policy\n");
    }
}

int main() {
    int pol;
    struct sched_param param;

   
    pol = sched_getscheduler(0);

    print_policy(pol);

    param.sched_priority = sched_get_priority_max(SCHED_FIFO);
    sched_setscheduler(0, SCHED_FIFO, &param);
  

  printf("Scheduling policy changed to SCHED_FIFO with priority %d\n", param.sched_priority);

    
    pol = sched_getscheduler(0);
   
    print_policy(pol);

   
    param.sched_priority = sched_get_priority_max(SCHED_RR);
   sched_setscheduler(0, SCHED_RR, &param);
    printf("Scheduling policy changed to SCHED_RR with priority %d\n", param.sched_priority);

    
    pol = sched_getscheduler(0);
   
    print_policy(pol);

    return 0;
}
//============================================================================
/*Current scheduling policy: SCHED_OTHER
Scheduling policy changed to SCHED_FIFO with priority 99
Current scheduling policy: SCHED_FIFO
Scheduling policy changed to SCHED_RR with priority 99
Current scheduling policy: SCHED_RR
*/
