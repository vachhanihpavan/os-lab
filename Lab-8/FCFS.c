#include<stdio.h>
#include<stdlib.h>
#define N 1000

int abs(int a)
{
    if(a<0)
        return -a;
    return a;
}
int main()
{
    int n, queue[N], i, total=0;
    printf("Enter the number of requests\n");
    scanf("%d",&n);
    printf("Enter the current position of head\n");
    scanf("%d",&queue[0]);
    printf("Enter the sequeunce of request\n");
    for(i=0;i<n;i++)
        scanf("%d",&queue[i+1]);

    printf("Movment of head.......\n");
    for(i=0;i<n;i++)
    {
        printf("Head moves from %d to %d: Distance = %d\n",queue[i],queue[i+1],abs(queue[i]-queue[i+1]));
        total += abs(queue[i]-queue[i+1]);
    }
    printf("\nTotal Distance traveeled by head: %d\n",total);
}
