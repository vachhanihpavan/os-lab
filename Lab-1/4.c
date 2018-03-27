#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>

void main()
{
     int fd1=open("file3.txt",O_RDWR);
     char *args[]={"7.c",NULL};
     execl("/7.c",args[0],0,0);
}
