#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int n,pid[20],burst_time[20],arrival_time[20],wait_time[20],turn_time[20],average_waiting_time=0,average_turnaround_time=0,i,j,pos;
    printf("Enter total number of processes:");
    scanf("%d",&n);
    printf("\nEnter Process Arrival Time and Burst Time\n");
    for(i=0;i<n;i++)
    {
        printf("Process- %d:",i+1);
        pid[i]=i+1;
        scanf("%d",&arrival_time[i]);
        scanf("%d",&burst_time[i]);
    }
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(arrival_time[j]<arrival_time[pos])
                pos=j;
        }
        swap(&arrival_time[i],&arrival_time[pos]);
        swap(&burst_time[i],&burst_time[pos]);
        swap(&pid[i], &pid[pos]);
    }

    wait_time[0]=0;

    for(i=1;i<n;i++)
    {
        wait_time[i]=0;
        for(j=0;j<i;j++)
            wait_time[i]=wait_time[i]+burst_time[j];
        wait_time[i]-=arrival_time[i];
    }

    printf("\nProcess\t\tArrival Time\t\tBurst Time\tWaiting Time\tTurnaround Time");

    for(i=0;i<n;i++)
    {
        turn_time[i]=burst_time[i]+wait_time[i];
        average_waiting_time+=wait_time[i];
        average_turnaround_time+=turn_time[i];
        printf("\nProcess- %d\t\t%d\t\t%d\t\t%d\t\t%d",pid[i],arrival_time[i],burst_time[i],wait_time[i],turn_time[i]);
    }

    average_waiting_time/=i;
    average_turnaround_time/=i;
    printf("\n\nAverage Waiting Time:%d",average_waiting_time);
    printf("\nAverage Turnaround Time:%d\n",average_turnaround_time);

    return 0;
}
