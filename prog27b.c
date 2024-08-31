//execlp
/*Name - prog27b.c
Author-Rishika Gupta 
Roll no - MT2024127
Date - 29/08/24*/
#include <stdio.h>
#include <unistd.h>

int main() {
     execlp("ls", "ls", "-Rl", (char *)NULL);

    
    perror("execlp failed");
    return 1;
}

