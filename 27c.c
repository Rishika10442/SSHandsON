//excle
/*Name - prog27c.c
Author-Rishika Gupta 
Roll no - MT2024127
Date - 29/08/24*/
//============================================================================
#include <stdio.h>
#include <unistd.h>

int main() {
   
    char *env[] = { NULL }; 

    execle("/bin/ls", "ls", "-Rl", (char *)NULL, env);

    perror("execle failed");
    return 1;
}
