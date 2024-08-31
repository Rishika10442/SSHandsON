/*Name - prog27d.c
Author-Rishika Gupta 
Roll no - MT2024127
Date - 29/08/24*/
//execv

#include <stdio.h>
#include <unistd.h>

int main() {
   
    char *args[] = { "ls", "-Rl", NULL };

    execv("/bin/ls", args);

   
    perror("execv failed");
    return 1;
}
