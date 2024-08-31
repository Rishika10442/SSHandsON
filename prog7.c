//Write a program to copy file1 into file2 ($cp file1 file2)
/*Name - prog7.c
Author-Rishika Gupta 
Roll no - MT2024127
Date - 13/08/24*/
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char *argv[]){

if(argc!=3){
 printf("incorrect parameters"); return 0;
}



int fd_read= open(argv[1],O_RDONLY);

int fd_write = open(argv[2], O_WRONLY | O_CREAT | O_EXCL, 777);



while(1){ 
char buff;

int char_read= read(fd_read,&buff,1);
 if(char_read==0)
	break;

int char_write= write(fd_write,&buff, 1);

}
int x = close(fd_write); 

int y= close(fd_read);

return 0;

}
//file name - samppledata1 testing data
