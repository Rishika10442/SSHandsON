//execvp
/*Name - prog27e.c
Author-Rishika Gupta 
Roll no - MT2024127
Date - 29/08/24*/
#include <stdio.h>
#include <unistd.h>

int main() {
   
    char *args[] = { "ls", "-Rl", NULL };

    execvp("ls", args);

   
    perror("execvp failed");
    return 1;
}
