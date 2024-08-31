//26. Write a program to execute an executable program.
//a. use some executable program
//b. pass some input to an executable program. (for example execute an executable of $./a.out name)
/*Name - prog26.c
Author-Rishika Gupta 
Roll no - MT2024127
Date - 29/08/24*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char fname[50];

   
    printf("Enter file  name: ");
    fgets(fname, sizeof(fname), stdin);
   fname[strcspn(fname, "\n")] = 0;

    
    char *command = "./fourteen";

    char command_with_arg[100];
    snprintf(command_with_arg, sizeof(command_with_arg), "%s %s", command, fname);

    int result = system(command_with_arg);
    if (result == -1) {
        printf("Failed to execute command.\n");
        return 1;
    }

    return 0;
}
//Enter file  name: my_link
//41471The file is a symbolic link.
