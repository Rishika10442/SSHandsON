//1. Create the following types of a files using (i) shell command (ii) system call
//b. hard link (link system call)
//Name -prog1b.c
//Author-Rishika Gupta 
//Roll no - MT2024127
//Date - 07/08/24
//============================================================================

#include <stdio.h>
#include <unistd.h>

int main() {
    const char *oldpath = "sl1.txt";
    const char *newpath = "hard_link2";

    // Create a hard link
    if (link(oldpath, newpath) == 0) {
        printf("Hard link created successfully.\n");
    } else {
        perror("link");
    }

    return 0;
}
//============================================================================
//-rw-rw-r-- 3 rishika-gupta rishika-gupta     0 Aug  7 19:25 hard_link2

