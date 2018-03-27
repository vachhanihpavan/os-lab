#include"stdio.h"
#include<bits/stdc++.h>
typedef struct{

    int arrival;
    int burst;
    int priorty;
    int index;
    int status;
}process;

void swap(process *x,process *y)
{
    process temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void bublesort(process p[], int n)
{

    int i,j;
    for(i=0;i<(n-1);i++)
        for(j=0;j<(n-(i+1));j++)
            if(p[j].arrival > p[j+1].arrival||(p[j].arrival==p[j+1].arrival&&p[j].priorty>p[j+1].priorty))
                swap(&p[j],&p[j+1]);
}

void sortpr(process p[],int n)
{
    int i,j;
    for(i=0;i<(n-1);i++)
        for(j=0;j<(n-(i+1));j++)
            if(p[j].priorty > p[j+1].priorty)
                swap(&p[j],&p[j+1]);
}

void deletep(process p[],int size,int index)
{
    int i=index;
    while(i<size-1)
    {
        p[i]=p[i+1];
        i++;
    }
    return;
}

bool nonew(process p[],int size)
{
    for(int i=0;i<size;i++)
    {
        if(p[i].status==0 )return false;
    }
    return true;
}

bool noready(process p[],int size)
{
    for(int i=0;i<size;i++)
        if(p[i].status==1)
            return false;
    return true;
}

int ready(process p[],int size)
{
    int min=0;
    for(int i=0;i<size;i++)
        if(p[i].status==1&&p[i].priorty<p[min].priorty)
            min=i;
    return min;
}

void NonPreemtive(process p[],int size)
{
    int i,j,minpr,current=p[0].arrival;
    for(i=0;i<size-1;i++)
    {
        printf("p%d from %d to %d\n",p[i].index,current,current+p[i].burst);
        current=current+p[i].burst;
        if (p[i+1].arrival==current)
        {
            continue;
        }
        else{
            if(p[i+1].arrival>current){
                current=p[i+1].arrival;}
            else{ j=i+1;
            minpr=p[j].priorty;
            for(j=i+1;j<size;j++)
            {
                if(p[j].arrival<current){
                    if (p[j].priorty<minpr){
                        minpr=p[j].priorty;
                        swap(&p[i+1],&p[j]);
                    }
                }
            }
            }
        }
}
    printf("p%d from %d to %d\n",p[i].index,current,current+p[i].burst);
}

void NonPreemtiveAging(process p[],int size)
{
    int i,j,minpr,current=p[0].arrival;
    for(i=0;i<size-1;i++)
    {
        printf("p%d from %d to %d\n",p[i].index,current,current+p[i].burst);
        current=current+p[i].burst;
        if (p[i+1].arrival==current)
        {
            continue;
        }
        else{
            if(p[i+1].arrival>current){
                current=p[i+1].arrival;
            }
            else{ j=i+1;
            minpr=p[j].priorty-(current-p[j].arrival)/5;
            for(j=i+1;j<size;j++)
            {
                if(p[j].arrival<current){
                    if (p[j].priorty-(current-p[j].arrival)/5<minpr)
                    {
                        minpr=p[j].priorty-(current-p[j].arrival)/5;
                        swap(&p[i+1],&p[j]);
                    }
                }
            }
            }
        }
    }
    printf("p%d from %d to %d\n",p[i].index,current,current+p[i].burst);
}

void Preemtive(process p[],int size)
{
    int i=0,current=p[0].arrival,j,test;
    while(size!=0)
    {
        printf("p%d from %d to ",p[i].index,current);
        if(nonew(p,size)){
            printf("%d\n",current+p[i].burst);
            current=current+p[i].burst;
            deletep(p,size,i);
            size--;
            if(size==0) break;
            i=ready(p,size);
            continue;
        }
        else{test=0;
        for(j=0;j<size;j++)
        {
            if(p[j].arrival<current+p[i].burst)
            {
                if(p[j].status==1)continue;
                if(p[j].priorty<p[i].priorty)
                {
                    printf(" %d\n",p[j].arrival);
                    p[i].burst=p[i].burst-(p[j].arrival-current);
                    p[i].status=1;
                    current=p[j].arrival;
                    test=1;
                    i=j;
                    break;
                }else p[j].status=1;
            }else if(p[j].arrival==current+p[i].burst)p[j].status=1;
        }
        if(test==1)continue;
        printf("%d\n",current+p[i].burst);
        current=current+p[i].burst;
        deletep(p,size,i);
        size--;
        if (!noready(p,size))
        {
            i=ready(p,size);
        }
        else {
            current=p[i].arrival;}
        }
    }
    return;
}

int main()
{
    process p[5];
    int i,c;
    printf("Welcome\n");
    printf( "Choose the mode of scedueling:\npress 1 for non preemtive\npress 2 for non preemtive with aging\npress 3 for preemptive\n");
    scanf("%d",&c);
    for (i=0;i<5;i++)
    {
        printf("\nenter the arrival time of p %d:",i);
        scanf("%d",&p[i].arrival);
        printf("enter the burst time of p %d:",i);
        scanf("%d",&p[i].burst);
        printf("enter the priorty of p %d:",i);
        scanf("%d",&p[i].priorty);
        p[i].status=0;
        p[i].index=i;
    }
    bublesort(p,5);
    printf("\nsorted:\nprocess arrival time burst time priorty\n");
    for (i=0;i<5;i++)
    {
        printf( " p%d %d %d %d\n",p[i].index,p[i].arrival,p[i].burst,p[i].priorty);
    }
    if(c==1)
        NonPreemtive(p,5);
    else{
        if(c==2) NonPreemtiveAging(p,5);
        else if (c==3)Preemtive(p,5);
    }
    return 0;
}
