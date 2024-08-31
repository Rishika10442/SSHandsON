//Write a program to find out the opening mode of a file. Use fcntl.
/*NAme - prog12.c
Author-Rishika Gupta
Roll NO- MT2024127
Date-13/08/24*/

#include<stdio.h>
#include <fcntl.h>  
#include <unistd.h> 


int main() {
FILE *file = fopen("fd_test.txt", "r");
int fd = fileno(file);
int mode = fcntl(fd, F_GETFL);
printf("%d",mode);
switch(mode){
    case 32768 : printf("read"); break;
    case 32769 : printf("write"); break;
    case 33793 : printf("append"); break;
    case 32770 : printf("r+ || w+"); break;
    case 32794 : printf("a+"); break;
}
return 0;
}

// output - 32768read
 
