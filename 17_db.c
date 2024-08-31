//dummy database
//Name-prog17_db.c
//Author-Rishika Gupta
//Roll NO-MT2024127
//Date-30/08/24
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<stdio.h>

int main(){
int fd;
struct{
int t_no;
}db;

db.t_no = 1;
fd = open("db",O_CREAT|O_RDWR,0744);
write(fd,&db,sizeof(db));
close(fd);
fd=open("db",O_RDONLY);
read(fd,&db,sizeof(db));
printf("ticket no:%d\n",db.t_no);
close(fd);

return 0;
}
