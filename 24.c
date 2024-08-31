//24. Write a program to create an orphan process
/*Name - prog24.c
Author-Rishika Gupta 
Roll no - MT2024127
Date - 30/08/24*/
//============================================================================

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main() {
    pid_t pid;

    pid = fork();
 if (pid == 0) {
        printf("Child process (PID: %d) is running.\n", getpid());
        sleep(15);
        printf("Child process (PID: %d) is still running.Parent pid is %d\n", getpid(),getppid());
    } else {
        printf("Parent process (PID: %d)\n", getpid());
        exit(0);
	printf("parent exit");
    }

    return 0;
}
//============================================================================
//Child process (PID: 72018) is still running.

