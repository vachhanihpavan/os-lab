#include <stdio.h>
#include <stdlib.h>

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

	printf("Enter initial head movement (0: CW, 1: CCW) : ");
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

	//Find position of first request
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

		//Backward
		if(pos<n-1)
			printf("%d ----> %d\n", request[0], request[n-1]);
		for(int i=n-2; i>pos; i--)
			printf("%d -> %d\n", request[i+1], request[i]);

		ans = request[pos] - request[0];
		if(pos<n-1)
			ans += request[n-1] - request[pos+1];
	}
	else
	{
		//Forward
		for(int i=pos+1; i<n; i++)
			printf("%d -> %d\n", request[i-1], request[i]);

		//Backward
		if(pos>0)
			printf("%d ----> %d\n", request[n-1], request[0]);
		for(int i=1; i<pos; i++)
			printf("%d -> %d\n", request[i-1], request[i]);

		ans = request[n-1] - request[pos];
		if(pos>0)
			ans += request[pos-1] - request[0];
	}
	printf("\nTotal Head Movement : %d\n\n", ans);
}
