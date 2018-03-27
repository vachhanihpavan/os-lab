#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
void main()
{
    int fd1 = creat("file1.txt",S_IRWXU|S_IRWXG|S_IRWXO);
    
    if(fd1==-1)
    {
          printf("Here\n");
          perror("error\n");
          exit(1);
    }
    printf("fd1=%d\n",fd1);
    
    fd1 = open("file1.txt",O_WRONLY);
    
    if(fd1==-1)
    {
          printf("Here\n");
          perror("Error\n");
    }
    
    printf("fd1=%d\n",fd1);

    int fd2 = write(fd1,"Hello World",sizeof("Hello World"));
    
    if(fd2==-1)
    {
          printf("Here\n");
          perror("Error or interrupt\n");
    }
    
    printf("Called write(%d,\"Hello World\",%d)"". It returned %d\n",fd1,sizeof("Hello World"),fd2);
    
    fd1 = open("file1.txt",O_RDWR);
    
    if(fd1==-1)
    {
          printf("Here\n");
          perror("Error\n");
    } 
    
    printf("opened in read & write mode fd1 = %d\n",fd1);
    
    char a[100];
    
    int fd3 = read(fd1,a,10);
    
    if(fd3==-1)
    {
          printf("Here\n");
          printf("Error or interrupt\n");
    }
    
    printf("Called read(%d,a,10). It returned %d\n",fd1,fd3);
    a[fd3]='\0';
    printf("Those read bytes are %s\n",a);
    
    char chh;
    
    lseek(fd1,0,SEEK_SET);
	while(read(fd1,&chh,1))
	{
                lseek(fd1,2,SEEK_CUR);
		write(fd1,chh,1);
		
		printf("lseek == %c\n",chh);
	}



    if(close(fd1)==-1)
    {
          printf("Here\n");
          perror("Error\n");
          exit(1);
    }
    
    printf("Closed the file\n");
    
}
