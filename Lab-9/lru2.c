#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define N 1000
int tim = 1;

void print(int frame_table[], int no_frame)
{
	for(int i=0; i<no_frame; i++)
	{
		if(frame_table[i] == -1)
			printf("-- ");
		else
			printf("%2d ", frame_table[i]);
	}
	printf(" |");
}

int exists(int frame_table[], int no_frame, int page, int used[])
{
	for(int i=0; i<no_frame; i++)
		if(page == frame_table[i])
		{
			used[i] = tim++;
			return 1;
		}
	return 0;
}

int getpos(int no_frame, int used[])
{
	int mini = 1e9, pos = -1;
	for(int i=0; i<no_frame; i++)
		if(mini > used[i])
		{
			mini = used[i];
			pos = i;
		}

	return pos;
}

int main()
{
	int n, pos = 0, no_frame;
	int frame_table[N], pages[N], used[N];

	for(int i=0; i<N; i++)
	{
		frame_table[i] = -1;
		used[i] = 0;
	}

	printf("Enter number of frames : ");
	scanf("%d", &no_frame);

	printf("Enter number of page requests: ");
	scanf("%d", &n);

	printf("Enter pages\n");
	for(int i=0; i<n; i++)
		scanf("%d", &pages[i]);

	int cnt = 0;
	printf("\nFrame table after each request\n");
	printf("---------------------------------\n");
	for(int i=0; i<n; i++)
	{
		printf("Table after request %2d | ", pages[i]);
		if(!exists(frame_table, no_frame, pages[i], used))
		{
			pos = getpos(no_frame, used);
			frame_table[pos] = pages[i];
			used[pos] = tim++;

			print(frame_table, no_frame);
			printf("  Page Fault\n");
			cnt++;
			continue;
		}

		print(frame_table, no_frame);
		printf("\n");
	}

	printf("\nNumber of page faults : %d\n\n", cnt);
}
