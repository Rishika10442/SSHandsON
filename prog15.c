//15. Write a program to display the environmental variable of the user (use environ).
/*Name - prog15.c
Author-Rishika Gupta 
Roll no - MT2024127
Date - 22/08/24*/
#include <stdio.h>

extern char** environ;
int main(int argc, char* argv[])
{
    int i=0;
    while(environ[i]!=NULL){
        printf("%s\n",environ[i++]);
    
}
return 0;
}
