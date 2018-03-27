
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/wait.h>
#include<signal.h>
void main()
{
    int d=kill(getpid(),-1);
    printf("d=%d\n",d);
}
