#include <stdio.h>
#include <stdlib.h>

#define N 1000

int abs(int a)
{
	if(a>0)
		return a;
	return -a;
}

int main()
{
	int n;
	int queue[N], done[N] = {0};

	printf("Enter the number of Requests\n");
	scanf("%d", &n);

	printf("Enter the current position of head\n");
	scanf("%d", &queue[0]);

	printf("Enter the sequeunce of Requests\n");
	for(int i=1; i<=n; i++)
		scanf("%d", &queue[i]);
	n++;

	int ans = 0, prev = queue[0];
	done[0] = 1;

	printf("\nHead movement\n");
	for(int i=1; i<n; i++)
	{
		int nextRequest, mini = 1e9;
		for(int j=1; j<n; j++)
			if(done[j] == 0 && abs(queue[j] - prev) < mini)
			{
				mini = abs(prev - queue[j]);
				nextRequest = j;
			}

		done[nextRequest] = 1;
		ans += mini;
		printf("%d -> %d\n", prev, queue[nextRequest]);
		prev = queue[nextRequest];
	}

	printf("\nTotal Head Movement : %d\n\n", ans);
}
