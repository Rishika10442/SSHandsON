/*14 Write a program to find the type of a file.
a. Input should be taken from command line.
b. program should be able to identify any type of a file.*/
/*Name - prog14.c
Author-Rishika Gupta 
Roll no - MT2024127
Date - 13/08/24*/

#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    struct stat fs;

   
    if (argc != 2) {
       printf("invalid arguments");
        return 1;
    }

   
 
int x = lstat(argv[1],&fs);
   printf("%d",fs.st_mode);
    if (S_ISREG(fs.st_mode)) {
        printf("The file is a regular file.\n");
    } else if (S_ISDIR(fs.st_mode)) {
        printf("The file is a directory.\n");
    } else if (S_ISLNK(fs.st_mode)) {
        printf("The file is a symbolic link.\n");
    } else if (S_ISCHR(fs.st_mode)) {
        printf("The file is a character device.\n");
    } else if (S_ISBLK(fs.st_mode)) {
        printf("The file is a block device.\n");
    } else if (S_ISFIFO(fs.st_mode)) {
        printf("The file is a FIFO (named pipe).\n");
    } else if (S_ISSOCK(fs.st_mode)) {
        printf("The file is a socket.\n");
    } else {
        printf("Unknown file type.\n");
    }

    return 0;
}

//output -33252The file is a regular file.


