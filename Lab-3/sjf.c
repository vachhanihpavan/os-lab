#include<stdio.h>

int main()
{
  int i,n,p[10],min,k=0,current=0;
  int bt[10],temp,j,at[10],wt[10],tt[10],ta=0,sum=0;
  float avg_waiting=0,avg_turn=0,sum_turn=0,sum_wait=0;
  printf("\nEnter the No. of processes :");
  scanf("%d",&n);

  for(i=0;i<n;i++)
  {
    p[i]=i+1;
    printf("\tEnter the burst time of %d process :",i+1);
    scanf(" %d",&bt[i]);
    printf("\tEnter the arrival time of %d process :",i+1);
    scanf(" %d",&at[i]);
  }

//Arrival Time sorting
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      if(at[i]<at[j])
      {
        temp=p[j];
        p[j]=p[i];
        p[i]=temp;

        temp=at[j];
        at[j]=at[i];
        at[i]=temp;

        temp=bt[j];
        bt[j]=bt[i];
        bt[i]=temp;
      }
    }
  }

  /*Arranging the table according to Burst time,
  Execution time and Arrival Time
  Arrival time <= Execution time
  */
//Burst time sorting on condition
  for(j=0;j<n;j++)
  {
    current=current+bt[j];
    min=bt[k];
    for(i=k;i<n;i++)
    {
      if (current>=at[i] && bt[i]<min)
      {  /*Sorting According to Arrival Time*/

        temp=p[k];
        p[k]=p[i];
        p[i]=temp;

        temp=at[k];
        at[k]=at[i];
        at[i]=temp;

        temp=bt[k];
        bt[k]=bt[i];
        bt[i]=temp;
      }
    }
    k++;
  }
  wt[0]=0;
  for(i=1;i<n;i++)
  {
    sum=sum+bt[i-1];
    wt[i]=sum-at[i];
    sum_wait=sum_wait+wt[i];
  }

  avg_waiting=(sum_wait/n);
  for(i=0;i<n;i++)
  {
    ta=ta+bt[i];
    tt[i]=ta-at[i];
    sum_turn=sum_turn+tt[i];
  }

  avg_turn=(sum_turn/n);

  printf("\nProcess\t Burst\t Arrival\t Waiting\t Turn-around" );
  for(i=0;i<n;i++)
  {
    printf("\n p%d\t %d\t %d\t\t %d\t\t\t%d",p[i],bt[i],at[i],wt[i],tt[i]);
  }

  printf("\n\nAverage Waiting Time: %f",avg_waiting);
  printf("\nAverage Turnaround Time: %f",avg_turn);
  return 0;
}
