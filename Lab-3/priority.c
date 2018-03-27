#include<stdio.h>

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int at[20],bt[20],process[20],wt[20],tat[20],priority[20],i,j,n,total=0,pos,temp,avg_wt,avg_tat,current=0,k=0,min;
    printf("Enter total number of processes:");
    scanf("%d",&n);

    printf("\nEnter Process Burst Time and Priority\n");
    for(i=0;i<n;i++)
    {
        printf("\nProcess- %d\n",i+1);
        printf("Arrival Time:  ");
        scanf("%d",&at[i]);
        printf("Burst Time:  ");
        scanf("%d",&bt[i]);
        printf("Priority:  ");
        scanf("%d",&priority[i]);
        process[i]=i+1;
    }

    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(at[j]<at[pos])
                pos=j;
        }

        swap(&priority[i],&priority[pos]);
        swap(&bt[i],&bt[pos]);
        swap(&process[i], &process[pos]);
        swap(&at[i], &at[pos]);
    }

    for(i=0;i<n;i++)
    {
        current+=bt[i];
        min=priority[k];
        for(i=k;i<n;i++)
        {
          if (current>=at[i] && priority[i]<min)
          {  /*Sorting According to priority*/

            temp=process[k];
            process[k]=process[i];
            process[i]=temp;

            temp=at[k];
            at[k]=at[i];
            at[i]=temp;

            temp=bt[k];
            bt[k]=bt[i];
            bt[i]=temp;

            temp=priority[k];
            priority[k]=priority[i];
            priority[i]=temp;
          }
        }
        k++;
  }

    wt[0]=0;

    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
        wt[i]-=at[i];
        total+=wt[i];
    }

    avg_wt=total/n;
    total=0;

    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time\tPriority");
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];
        total+=tat[i];
        printf("\nP[%d]\t\t  %d\t\t    %d\t\t\t%d\t\t\t%d",process[i],bt[i],wt[i],tat[i],priority[i]);
    }

    avg_tat=total/n;
    printf("\n\nAverage Waiting Time=%d",avg_wt);
    printf("\nAverage Turnaround Time=%d\n",avg_tat);

    return 0;
}
