//20. Find out the priority of your running program.
// Modify the priority with nice command.
/*Name - prog20.c
Author-Rishika Gupta 
Roll no - MT2024127
Date - 30/08/24*/
//============================================================================

#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>

int main() {
    pid_t pid;
    int priority;

   
    pid = getpid();
   
    priority = getpriority(PRIO_PROCESS, pid);
    printf("Current priority (niceness): %d\n", priority);
    int increment = 5; 
    nice(increment);
    priority = getpriority(PRIO_PROCESS, pid);
    printf("New priority (niceness): %d\n", priority);

    return 0;
}
//============================================================================
//Current priority (niceness): 0
//New priority (niceness): 5

