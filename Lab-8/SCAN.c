#include<stdio.h>
#include<stdlib.h>
#define N 1000

void swap(int a[], int i, int j)
{
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}
void sort(int a[], int n)
{
	for(int i=0; i<n-1; i++)
		for(int j=i+1; j<n; j++)
			if(a[i] > a[j])
				swap(a, i, j);
}
int main()
{
	int n, tot_cy, choice;
	int request[N];

	printf("Enter number of cylinders : ");
	scanf("%d", &tot_cy);
	printf("Enter initial head movement (0: left, 1: right) : ");
	scanf("%d", &choice);
	printf("Enter number of requests : ");
	scanf("%d", &n);
	printf("Enter current head position : ");
	scanf("%d", &request[0]);
	printf("\nEnter the requests\n");
	for(int i=1; i<=n; i++)
		scanf("%d", &request[i]);
	n++;

	int ans, pos, firstRequest = request[0];
	sort(request, n);

	for(int i=0; i<n; i++)
		if(request[i] == firstRequest)
		{
			pos = i;
			break;
		}

	printf("\nHead movement\n");
	if(choice == 0)
	{
		//Forward
		for(int i=pos-1; i>=0; i--)
			printf("%d -> %d\n", request[i+1], request[i]);
		if(request[0] != 0);
			printf("%d -> 0\n", request[0]);

		//Backward
		if(pos<n-1)
			printf("0 -> %d\n", request[pos+1]);
		for(int i=pos+2; i<n; i++)
			printf("%d -> %d\n", request[i-1], request[i]);
		if(pos == n-1)
			printf("0 -> %d\n", tot_cy);
		else if(request[0] != 0)
			printf("%d -> %d\n", request[n-1], tot_cy);

		ans = tot_cy + firstRequest - 1;
	}
	else
	{
		//Forward
		for(int i=pos+1; i<n; i++)
			printf("%d -> %d\n", request[i-1], request[i]);
		if(request[n-1] != tot_cy);
			printf("%d -> %d\n", request[n-1], tot_cy -1);

		//Backward
		if(pos>0)
			printf("%d -> %d\n", tot_cy -1, request[pos-1]);
		for(int i=pos-2; i>=0; i--)
			printf("%d -> %d\n", request[i+1], request[i]);
		if(pos == 0)
			printf("%d -> 0\n", tot_cy);
		else if(request[0] != 0)
			printf("%d -> 0\n", request[0]);

		ans = 2*tot_cy -2 -firstRequest;
	}
	printf("\nTotal Head Movement : %d\n\n", ans);
}
