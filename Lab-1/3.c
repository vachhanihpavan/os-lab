#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
#include<sys/ioctl.h>
#include<ioctl.h>
void main()
{
    int fd1=access("file3.txt",F_OK);
    if(fd1==-1)
    {
         printf("Here\n");
         perror("Error\n");
    }
    printf("fd1=%d\n",fd1);
    
    int fd2 = chmod("file3.txt",S_ISUID | S_ISGID | S_IRUSR);
    
    if(fd2==-1)
    {
         printf("Here\n");
         perror("Error\n");
    }
    printf("fd2=%d\n",fd2);
    
    int fd3 = umask(S_IRUSR | S_IWUSR | S_IROTH | S_IRGRP);
    printf("fd3=%d\n",fd3);
}
