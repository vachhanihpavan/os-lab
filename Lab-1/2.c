#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
void main()
{
    int fd1 = creat("file3.txt",S_IRWXU | S_IRWXG | S_IRWXO);
    if(fd1==-1)
    {
         printf("Here\n");
         perror("Error\n");
    }
    
    printf("fd1=%d\n",fd1);

    int fd2 = dup(fd1);
    printf("Duplicate file des. is fd2 = %d\n",fd2);
    write(fd2,"Hi Bro\n",strlen("Hi Bro\n"));
    write(fd1,"Hello Bro\n",strlen("Hello Bro\n"));
    link("file3.txt","file4.txt");
    unlink("file4.txt");
    write(fd1,"OHHOOO\n",strlen("OHHOOO\n"));
  //  close(fd1);
    //close(fd2);
    // link,unlink,access,chmod,chown,unmask,ioctl
}
