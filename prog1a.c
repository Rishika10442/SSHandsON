//Create the following types of a files using (i) shell command (ii) system call
//a. soft link (symlink system call)

#include<stdio.h>
#include<unistd.h>
int main(){
 char *oldpath = "sl1.txt";
 char *newpath = "my_link";

    if (symlink(oldpath, newpath) == -1) {
        perror("symlink");
        return 1;
    }

    printf("Soft link created successfully.\n");
    return 0;




}
