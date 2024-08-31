/*27. Write a program to execute ls -Rl by the following system calls
a. execl
*/
/*Name - prog27a.c
Author-Rishika Gupta 
Roll no - MT2024127
Date - 29/08/24*/

#include <stdio.h>
#include <unistd.h>

int main() {
   
    execl("/bin/ls", "ls", "-Rl", (char *)NULL);

   
    perror("execl failed");
    return 1;
}



