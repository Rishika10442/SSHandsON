// Write a program to create a Zombie state of the running program.
/*Name - prog23.c
Author-Rishika Gupta 
Roll no - MT2024127
Date - 30/08/24*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid;

  
    pid = fork();
 if (pid == 0) {
        printf("Child process %d\n", getpid());
        exit(0);
    } else {
        printf("Parent process PID: %d \n", getpid());
        sleep(10);

      // wait(NULL);
    }

    return 0;
}
//PID    PPID STAT CMD
//  71977   71976 Z+   [a.out] <defunct>

