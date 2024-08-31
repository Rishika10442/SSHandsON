//Write a program to take input from STDIN and display on STDOUT.
// Use only read/write system calls
/*Name - prog6.c
Author-Rishika Gupta 
Roll no - MT2024127
Date - 07/08/24*/
#include<stdio.h>
#include <unistd.h>

int main(){
char buffer[20];


int bytes_read = read(0, buffer, 20);
if (bytes_read > 0) {
        write(1, buffer, bytes_read);
    }

return 0;
}
//hey 
