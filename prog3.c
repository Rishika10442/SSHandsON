//3. Write a program to create a file and print the file descriptor value.
// Use creat ( ) system call

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    const char *filename = "fd_test.txt";

   
    int fd = creat(filename, 0744);

    if (fd == -1) {
        perror("creat");
        return 1;
    }

    printf("File created successfully. File descriptor: %d\n", fd);

   
    
    return 0;
}

