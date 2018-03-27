#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/wait.h>
void main()
{
     if(fork()==0)
     printf("Hello World from child\n");
     else
     {
        printf("HI from parent\n");
        _exit(0);
        wait(NULL);
        printf("Again hi from parent after wait call\n");
     }
}
