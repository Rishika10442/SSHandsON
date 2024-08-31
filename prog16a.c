//16. Write a program to perform mandatory locking.
//a. Implement write lock
/*Name - prog16a.c
Author-Rishika Gupta 
Roll no - MT2024127
Date - 28/08/24*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

void lock_file(int fd,int type) {
    struct flock lock;

    lock.l_type = F_WRLCK;
    lock.l_start = 0;  
    lock.l_whence = SEEK_SET;
    lock.l_len = 0;    

   
    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("Failed to lock file");
        exit(EXIT_FAILURE);
    }else {
        if (type == F_WRLCK) {
            printf("File locked by process %d.\n", getpid());
        } else if (type == F_UNLCK) {
            printf("File unlocked by process %d.\n", getpid());
        }
    }
}

int main() {
    const char *file_path = "writelock1.txt";

    // Open the file
    int fd = open(file_path, O_RDWR | O_CREAT, 0644);
    if (fd == -1) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

   
    if (chmod(file_path, 02644) == -1) {
        perror("Failed to change file mode");
        exit(EXIT_FAILURE);
    }

   
    lock_file(fd,F_WRLCK);

   
    printf("Process %d  in CS .\n", getpid());
	const char *data = "testing.\n";
    if (write(fd, data, strlen(data)) == -1) {
        perror("Failed to write to file");
        exit(EXIT_FAILURE);
    }	
    sleep(10); 

    printf("Process %d is leaving CS.\n", getpid());

    
    lock_file(fd, F_UNLCK);

    
    close(fd);

    return 0;
}
/*File locked by process 11637.
Process 11637  in CS .
Process 11637 is leaving CS.
File unlocked by process 11637.
*/
