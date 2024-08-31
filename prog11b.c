/*11. Write a program to open a file, duplicate the file descriptor and append the file with both the
descriptors and check whether the file is updated properly or not.

b. use dup2 */
/*Name - prog11b.c
Author-Rishika Gupta 
Roll no - MT2024127
Date - 13/08/24*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {

    int fd = open("q_11b.txt", O_RDWR | O_CREAT | O_APPEND, 0644);
   
    int fd2 = 10;
  dup2(fd, fd2);
   char *data = "Original FD\n";
   write(fd, data, 13);
   char *data2 = "Duplicated FD\n";
   write(fd2, data2, 14);

  
    close(fd);
    close(fd2);

   
    fd = open("q_11b.txt", O_RDONLY);
   

   
    char buffer[128];
    int  bytes;

    printf("File content:\n");
    while ((bytes = read(fd, buffer, 1)) > 0) {
       
        printf("%s", buffer);
    }

   
    close(fd);

    return 0;
}

/*Original FD
Duplicated FD
*/
