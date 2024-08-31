/* 11. Write a program to open a file, duplicate the file descriptor and append the file with both the
descriptors and check whether the file is updated properly or not.
a. use dup*/
/*Name - prog11a.c
Author-Rishika Gupta 
Roll no - MT2024127
Date - 13/08/24*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {

    int fd = open("q_11.txt", O_RDWR | O_CREAT | O_APPEND, 777);
    if (fd == -1) {
        perror("Error opening file");
       return 0;
    }

   
    int fd2 = dup(fd);
	if (fd2 == -1) {
        perror("Error duplicating file descriptor");
        close(fd);
        exit(EXIT_FAILURE);
    }

//	printf("%d",fd2);   
    char *data = "Original FD\n";
    write(fd, data, 13);
       

   
    char *data2 = "Duplicated FD\n";
   if (write(fd2, data2, 14) == -1) {
        perror("Error writing with duplicated FD");
        close(fd);
        close(fd2);
        exit(EXIT_FAILURE);
    }
//	printf("written second data also");

    
    close(fd);
    close(fd2);

   
    char buffer[256];
    fd = open("q_11.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error opening file for reading");
        return 0;
    }
    int bytes;
    while (bytes = read(fd, buffer,1) > 0) {
        
        printf("%s", buffer);
    }
   // int bytes= read(fd, buffer, sizeof(buffer) - 1);
   
   // buffer[bytes] = '\0';
    //printf("File content:\n%s", buffer);

   
    close(fd);

    return 0;
}

//Original FD
//Duplicated FD

