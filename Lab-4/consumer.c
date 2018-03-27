#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<stdlib.h>
#include<unistd.h>
int buf[5],f,r,pvn,v,pvn2;
sem_t mutex,full,empty;
void *produce(void *arg)
{
    int i;
    for(i=0;i<10;i++)
    {
        sem_wait(&empty);
        sem_wait(&mutex);
        printf("produced item is %d\n",i);
        buf[(++r)%5]=i;
        sleep(1);
        sem_post(&mutex);
                sem_post(&full);
        v=sem_getvalue(&full,&pvn);   //convert to int
        printf("full %d\n",pvn);
    }
}
void *consume(void *arg)
{
        int item,i;
        for(i=0;i<10;i++)
        {
                sem_wait(&full);    //lock and --
                v=sem_getvalue(&full,&pvn2);    //hehehehe
                printf("full %d\n",pvn2);
                sem_wait(&mutex);
                item=buf[(++f)%5];
                printf("consumed item is %d\n",item);
                sleep(1);
                sem_post(&mutex);
                sem_post(&empty);
        }
}
int main()
{
    //thread has id
    pthread_t tid1,tid2;
    sem_init(&mutex,0,1);   //(sem_name, flag for sharing with forked process, init value)
    sem_init(&full,0,1);
    sem_init(&empty,0,5);
    pthread_create(&tid1,NULL,produce,NULL);    //(name, attr, func, func_parameters)
    pthread_create(&tid2,NULL,consume,NULL);
    pthread_join(tid1,NULL);    //waiting....still waiting boring
    pthread_join(tid2,NULL);

    return 0;
}
