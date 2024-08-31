/*Name - prog1c.c
//Author-Rishika Gupta 
Roll no - MT2024127
Date - 30/08/24*/
//1. Create the following types of a files using (i) shell command (ii) system call
//c. FIFO (mkfifo Library Function or mknod system call)
//============================================================================

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
int main(){
int fd ;
char buf[80];
fd=open("myfifo",O_WRONLY);
printf("Enter: ");
scanf("%[^\n]",buf);
write(fd,buf,strlen(buf));

return 0;
}
//============================================================================
//hello
