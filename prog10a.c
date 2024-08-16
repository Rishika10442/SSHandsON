/*10. Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
bytes (use lseek) and write again 10 bytes.
a. check the return value of lseek*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {

    int fd = open("q_10.txt", O_RDWR | O_CREAT, 777);
    if (fd == -1) {
        perror("Error opening file");
        return 0;
    }

    char *data = "1234567890"; 
    int bytes = write(fd, data, 10);
    if (bytes== -1) {
        perror("Error writing to file");
        close(fd);
        return 0;
    }

    off_t of = lseek(fd, 10, SEEK_CUR);
   printf("lseek return value: %ld\n", of);

    
    data = "ABCDEFGHIJ";
    bytes= write(fd, data, 10);
    if (bytes== -1) {
        perror("Error writing to file");
        close(fd);
        return 0;
    }

    printf("written successfully");
    close(fd);

    return 0;
}
