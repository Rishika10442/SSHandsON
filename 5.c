/*5. Write a program to create five new files with infinite loop. Execute the program in the background
and check the file descriptor table at /proc/pid/fd.*/
/*Name - prog5.c
Author-Rishika Gupta 
Roll no - MT2024127
Date - 30/08/24*/
//============================================================================

#include<stdio.h>
#include<fcntl.h>
int main(){
int f1,f2,f3,f4,f5;
f1=open("file1",O_CREAT|O_RDWR,0764);
f2=open("file2",O_CREAT|O_RDWR,0764);
f3=open("file3",O_CREAT|O_RDWR,0764);
f4=open("file4",O_CREAT|O_RDWR,0764);
f5=open("file5",O_CREAT|O_RDWR,0764);
for(;;);
return 0;
}
//============================================================================
//to check output  lsof -p 11501(pid) in /proc/pid

