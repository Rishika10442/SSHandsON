//30. Write a program to run a script at a specific time using a Daemon process.
/*
Name - prog30.c
Author-Rishika Gupta 
Roll no - MT2024127
Date - 30/08/24*/
#include<unistd.h>
#include<sys/stat.h>
#include<stdio.h>
#include<stdlib.h>

int main(){
if(!fork()){
setsid();
chdir("/");
umask(0);
 while(1){
sleep(4);
printf("child pid %d\n",getpid());
printf("daemon process\n");

}
}
else exit(0);

return 0;
}

//daemon process
//child pid 8705

