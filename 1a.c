//Name -prog1a.c
//Author-rishika gupta
//Roll No- MT2024127
//Date - 07/08/24

//Create the following types of a files using (i) shell command (ii) system call
//a. soft link (symlink system call)
//============================================================================

#include<stdio.h>
#include<unistd.h>
int main(){
 char *file = "sl1.txt";
 char *linkname = "my_link";

    if (symlink(file,linkname) == -1) {
        perror("symlink");
        return 1;
    }

    printf("Soft link created successfully.\n");
    return 0;
}
//============================================================================
//my_link -> sl1.txt
