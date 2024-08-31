/*13. Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to
verify whether the data is available within 10 seconds or not (check in $man 2 select).*/
/*Name - prog13.c
Author-Rishika Gupta 
Roll no - MT2024127
Date - 13/08/24*/
//============================================================================

#include <stdio.h>
#include <sys/select.h>
#include <unistd.h>

int main() {
   
    fd_set rset;
    
    
    FD_ZERO(&rset);
    
   
    FD_SET(STDIN_FILENO, &rset);

    
    struct timeval timeout;
    timeout.tv_sec = 10;  
    

    printf("Waiting for input on STDIN for 10 seconds...\n");

    
    int val = select(STDIN_FILENO + 1, &rset, NULL, NULL, &timeout);

    if (val == -1) {
        printf("Error during select()");
    } else if (val == 0) {
        printf("No data available within 10 seconds.");
    } else {
        if (FD_ISSET(STDIN_FILENO, &rset)) {
            printf("Data is available on STDIN!");
        }
    }

    return 0;
}

//============================================================================
/*Waiting for input on STDIN for 10 seconds...
h
Data is available on STDIN!*/
