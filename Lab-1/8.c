
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
        pid_t c = wait(NULL);
             printf("user Id = %d\n",getuid());
     printf("Effective user id = %d\n",geteuid());
     printf("Group Id = %d\n",getgid());
     printf("Effective group Id = %d\n",getegid());
     printf("Process id of calling process = %d\n",getpid());
     printf("Child id = %d\n",c);
     printf("Process id of a parent of a calling process = %d\n",getppid());
        printf("Again hi from parent after wait call\n");
     }
}
