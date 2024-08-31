//19. Write a program to find out time taken to execute getpid system call.
// Use time stamp counter.
/*Name - prog19.c
Author-Rishika Gupta 
Roll no - MT2024127
Date - 30/08/24*/

#include<stdio.h>
#include<unistd.h>
#include<sys/time.h>

unsigned long long int rdtsc(){
unsigned long long dst;
__asm__ __volatile__("rdtsc":"=A"(dst));

}
int main(){
	unsigned long long int  s, e;
    s = rdtsc();
    pid_t pid = getpid();
    e = rdtsc();
    printf("Time taken %llu\n", e - s);
return 0;
}
//output Time taken 38436

