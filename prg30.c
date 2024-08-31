
#include<unistd.h>
#include<sys/stat.h>
#include<stdio.h>
#include<stdlib.h>

int main(){
if(!fork()){
setsid();
chdir("/")
umask(0);
 while(1){
sleep(4);
printf("child pid %d\n",getpid());
printf("daemon process");
}
}
else exit(0);

return 0;
}

