//1. Create the following types of a files using (i) shell command (ii) system call
//b. hard link (link system call)
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
