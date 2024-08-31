//22. Write a program, open a file, call fork,
// and then write to the file by both the child as well as the
//parent processes. Check output of the file.
/*Name - prog22.c
Author-Rishika Gupta 
Roll no - MT2024127
Date - 30/08/24*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int main() {
    int fd;
    pid_t pid;
    char *fname = "text22.txt";
    fd = open(fname, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    pid = fork();
     if (pid == 0) {
        char c[] = "this is the child writing.\n";
        write(fd, c, sizeof(c) - 1);
       printf("Child has written to file ");
    } else {
        char p[] = "This is the parent writing.\n";
        write(fd, p, sizeof(p) - 1);
        printf("Parent has written to file.\n");
    }
    lseek(fd, 0, SEEK_SET);

    char buff[1024];
    ssize_t bytes_read;
    while ((bytes_read = read(fd, buff, sizeof(buff) - 1)) > 0) {
        buff[bytes_read] = '\0';
        printf("%s", buff);
    }
    close(fd);
    
    return 0;
}

//This is the parent writing.
//this is the child writing.

