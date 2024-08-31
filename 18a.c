/*18. Write a program to perform Record locking.
a. Implement write lock*/
/*Name - prog18a.c
Author-Rishika Gupta 
Roll no - MT2024127
Date - 30/08/24*/
//============================================================================

#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>

#define TRAIN_COUNT 3
#define TRAIN_RECORD_SIZE sizeof(int) * 2

struct {
    int t_no;
    int train_no;
} db2[TRAIN_COUNT] = {
    {0, 1},
    {0, 2},
    {0, 3}  
};

int lock_train(int fd, int train_no) {
    struct flock lock;

   
    lock.l_type = F_WRLCK;   
    lock.l_whence = SEEK_SET;
    lock.l_start = TRAIN_RECORD_SIZE * (train_no - 1);
    lock.l_len = TRAIN_RECORD_SIZE; 
    lock.l_pid = getpid();   
	printf("process attempting to lock train\n");
    
    fcntl(fd, F_SETLKW, &lock);
printf("process accquired lock on train %d\n",train_no);

    return 0;
}

void unlock_train(int fd, int train_no) {
    struct flock lock;
    lock.l_type = F_UNLCK;   
    lock.l_whence = SEEK_SET;
    lock.l_start = TRAIN_RECORD_SIZE * (train_no - 1);
    lock.l_len = TRAIN_RECORD_SIZE;
    lock.l_pid = getpid();
	printf("enter to unlock train \n");
	getchar();	
getchar();

    fcntl(fd, F_SETLK, &lock);
   printf("Process released lock on train %d.\n",  train_no);
}

void initialize_db2(int fd) {
    lseek(fd, 0, SEEK_SET);
    write(fd, db2, sizeof(db2));
}

int main() {
    int fd;
    int train_no;
    
   
    fd = open("db2", O_CREAT | O_RDWR, 0744);
   
    if (lseek(fd, 0, SEEK_END) == 0) {
        initialize_db2(fd);
    }

   
    printf("Enter train number (1-%d) to lock: ", TRAIN_COUNT);
    scanf("%d", &train_no);

   lock_train(fd, train_no);
    lseek(fd, TRAIN_RECORD_SIZE * (train_no - 1), SEEK_SET);
    read(fd, &db2[train_no - 1], sizeof(db2[0]));
    db2[train_no - 1].t_no++;
    lseek(fd, TRAIN_RECORD_SIZE * (train_no - 1), SEEK_SET);
    write(fd, &db2[train_no - 1], sizeof(db2[0]));
	//sleep(5);
    
    unlock_train(fd, train_no);

   
    lseek(fd, TRAIN_RECORD_SIZE * (train_no - 1), SEEK_SET);
    read(fd, &db2[train_no - 1], sizeof(db2[0]));
    printf("Train no: %d\n", db2[train_no - 1].train_no);
    printf("Ticket no: %d\n", db2[train_no - 1].t_no);

    close(fd);

    return 0;
}

//============================================================================
/*Enter train number (1-3) to lock: 2
process attempting to lock train
process accquired lock on train 2
enter to unlock train 

Process released lock on train 2.
Train no: 2
Ticket no: 2
*/
