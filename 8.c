//Write a program to open a file in read only mode,
// read line by line and display each line as it is read.
//Close the file when end of file is reached.
/*Name - prog8.c
Author-Rishika Gupta 
Roll no - MT2024127
Date - 13/08/24*/
//============================================================================
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
//============================================================================
/*Lorem Ipsum is simply dummy text of the printing and typesetting industry.
Lorem Ipsum has been the industry's standard dummy text ever since the 1500s,
when an unknown printer took a galley of type and scrambled it to make a type specimen book.
It has survived not only five centuries, but also the leap into electronic typesetting,
remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages,
and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum.
*/
