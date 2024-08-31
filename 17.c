////
/*17. Write a program to simulate online ticket reservation. Implement write lock
Write a program to open a file, store a ticket number and exit. Write a separate program, to
open the file, implement write lock, read the ticket number, increment the number and print
the new ticket number then close the file*/

/*Name - prog17.c
Author-Rishika Gupta 
Roll no - MT2024127
Date - 30/08/24*/
//============================================================================
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<stdio.h>

int main(){
	struct{
	int t_no;
	}db;
	struct flock lock;
	int fd;
	fd = open("db",O_RDWR);
	read(fd,&db,sizeof(db));
	lock.l_type=F_WRLCK;
	lock.l_whence=SEEK_SET;
	lock.l_start=0;
	lock.l_len=0;
	lock.l_pid=getpid();
printf("before enterning CS\n");
fcntl(fd,F_SETLKW,&lock);
printf("current ticket no %d\n",db.t_no);
db.t_no++;
lseek(fd,0L,SEEK_SET);
printf("Inside CS\n");
write(fd,&db,sizeof(db));
printf("your ticket no is %d ,\n",db.t_no);
printf("enter to leave CS");
getchar();
lock.l_type=F_UNLCK;
printf("unlocked and leaving\n");
fcntl(fd,F_SETLK,&lock);
printf("finished");
return 0;
}

//============================================================================
/*before enterning CS
current ticket no 3
Inside CS
your ticket no is 4 ,
enter to leave CS
unlocked and leaving
*/
