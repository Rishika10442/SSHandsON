/*11. Write a program to open a file, duplicate the file descriptor and append the file with both the
descriptors and check whether the file is updated properly or not.

c. use fcntl */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
   
    int fd = open("q_11c.txt", O_RDWR | O_CREAT | O_APPEND, 777);
   
    int fd_dup = fcntl(fd, F_DUPFD, 0);
    char *data1 = "Original FD\n";
    write(fd, data1, 13);
    char *data2 = "Duplicated FD\n";
    write(fd_dup, data2, 14);
        close(fd);
        close(fd_dup);
       

   
    fd = open("q_11c.txt", O_RDONLY);
   
    char buffer[128];
   int bytes;

    printf("File content:\n");
    while ((bytes= read(fd, buffer,1)) > 0) {
       
        printf("%s", buffer);
    }

   
    close(fd);

    return 0;
}

