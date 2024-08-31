//16. Write a program to perform mandatory locking.
//b. Implement read lock
/*Name - prog16b.c
Author-Rishika Gupta 
Roll no - MT2024127
Date - 28/08/24*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

void lock_file(int fd) {
    struct flock lock;
    lock.l_type = F_RDLCK; 
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;
    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("cant get read lock");
        return ;
    } else {
        printf("Read lock acquired by PID %d.\n", getpid());
    }
}

void unlock_file(int fd) {
    struct flock lock;
    lock.l_type = F_UNLCK; 
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;
   fcntl(fd, F_SETLK, &lock);
        printf("Lock released by PID %d.\n", getpid());
}

int main() {
    const char *fp = "lockingexample.txt";
    int fd = open(fp, O_RDONLY);
    lock_file(fd);
    printf("Reading file by PID %d...\n", getpid());
    sleep(20);
    unlock_file(fd);   
    close(fd);
    return 0;
}

/*Read lock acquired by PID 11650.
Reading file by PID 11650...
Lock released by PID 11650.
*/
