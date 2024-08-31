/* Write a program to print the following information about a given file.
a. inode
b. number of hard links
c. uid
d. gid
e. size
f. block size
g. number of blocks
h. time of last access
i. time of last modification
j. time of last change */
/*Author- Rishika Gupta 
Name- prog9.c
Roll no - MT2024127
Date - 13/08/24*/

#include <stdio.h>
#include <sys/stat.h>
#include <time.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("incorrect parameters");
        return 0;
    }

    struct stat fs;
    stat(argv[1], &fs);

    printf("File name : %s\n", argv[1]);
    printf("Inode no : %ld\n", (long)fs.st_ino);
    printf("Number of hard links: %ld\n", (long)fs.st_nlink);
    printf("UID: %d\n", fs.st_uid);
    printf("GID: %d\n", fs.st_gid);
    printf("Size: %ld bytes\n", (long)fs.st_size);
    printf("Block size: %ld bytes\n", (long)fs.st_blksize);
    printf("Number of blocks: %ld\n", (long)fs.st_blocks);
    printf("Time of last access: %s",ctime(&fs.st_atime));
    printf("Time of last modification: %s", ctime(&fs.st_mtime));
    printf("Time of last change: %s", ctime(&fs.st_ctime));

    return 0;
}
/*File name : prog9.c
Inode no : 1451335
Number of hard links: 1
UID: 1000
GID: 1000
Size: 1064 bytes
Block size: 4096 bytes
Number of blocks: 8
Time of last access: Fri Aug 30 12:36:56 2024
Time of last modification: Tue Aug 13 18:56:16 2024
Time of last change: Tue Aug 13 18:56:16 2024
*/
