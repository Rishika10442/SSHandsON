//Write a program to take input from STDIN and display on STDOUT.
// Use only read/write system calls
#include<stdio.h>
#include <unistd.h>

int main(){
char buffer[20];


int bytes_read = read(0, buffer, 20);
if (bytes_read > 0) {
        write(1, buffer, bytes_read);
    }

return 0;
}
