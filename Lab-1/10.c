
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
    printf("alarm = %d alarm = %d\n",alarm(1),alarm(3));
    char pvn[1000];
    printf("Current Directory: %s\n",getcwd(pvn, sizeof(pvn)));
    int d = chdir("/home/student/Desktop");
    printf("Current Directory: %s\n",getcwd(pvn, sizeof(pvn)));
    if(d==-1)
    {
         printf("Here\n");
         perror("Error");
    }
    else
         printf("d = %d\n",d);
}
