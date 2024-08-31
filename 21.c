//21. Write a program, call fork and print the parent and child process id.
/*Name - prog21.c
Author-Rishika Gupta 
Roll no - MT2024127
Date - 30/08/24*/
//============================================================================

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid;
    pid = fork();

    if (pid == 0) {
        printf("Child process: PID %d\n",getpid());
    } else {
        printf("Parent process:PID %d\n",getpid());
         }

    return 0;
}
//============================================================================
//Parent process:PID 71320
//Child process: PID 71321

