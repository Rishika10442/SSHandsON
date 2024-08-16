//Write a program to open a file in read only mode,
// read line by line and display each line as it is read.
//Close the file when end of file is reached.

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("incorrect parameters");
        return 0;
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    char buffer;
    int bytes_read;

    while ((bytes_read = read(fd, &buffer, 1)) > 0) {
        write(1, &buffer, 1); 

        if (buffer == '\n') {
            getchar(); 
        }
    }


    close(fd);
    return 0;
}
