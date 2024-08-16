//4. Write a program to open an existing file with read write mode.
// Try O_EXCL flag also.

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    const char *filename = "fd_test.txt";
    int fd = open(filename, O_RDWR);
    if (fd == -1) {
        perror("Error opening file with O_RDWR");
        return 1;
    }
    printf("File opened successfully with read-write mode. File descriptor: %d\n", fd);

    int fd_excl = open(filename, O_CREAT | O_EXCL | O_RDWR, 0744);
    if (fd_excl == -1) {
            printf("File already exists. O_EXCL failed as expected.\n");       
       }
     else {
 printf("File opened successfully with O_EXCL. File descriptor: %d\n", fd_excl);
    }
    return 0;
}

