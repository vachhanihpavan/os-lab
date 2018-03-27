#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

int pos;
int faults ,hits;
void print(int frame_size,int frame[])
{
	int i;
	for(i=0;i<frame_size;i++)
	{
		if(frame[i]==-1)
			printf("- ");
		else
			printf("%d ",frame[i]);
	}

	printf("\n");
}

void insert(int frame_size,int frame[], int reference)
{
	int i;
	bool alloted = false;
	for(i=0;i<frame_size;i++)
	{
		if(frame[i]==reference)
		{
			alloted = true;
			printf("  Hit for %d | ", reference);
			hits++;
			break;
		}
		else if(frame[i]==-1)
		{
			alloted = true;
			frame[i] = reference;
			printf("Fault for %d | ", reference);
			faults++;
			break;
		}
	}
	if(alloted == false)
	{
		faults++;
		printf("Fault for %d | ", reference);
		frame[pos] = reference;
		pos = (pos+1)%frame_size;
	}
	print(frame_size, frame);
}

int main()
{
	int frame_size,i,no_ref;
	printf("Enter frame size: ");
	scanf("%d",&frame_size);
	int frame[frame_size];
	for(i=0;i<frame_size;i++)
	{
		frame[i] = -1;
	}

	print(frame_size,frame);

	printf("Enter the number of references: ");
	scanf("%d",&no_ref);
	int reference[no_ref];

	for(i=0;i<no_ref;i++)
	{
		scanf("%d",&reference[i]);
		insert(frame_size,frame,reference[i]);
	}
	printf("\nNumber of faults: %d \nNumber of hits: %d\n",faults,hits );
}
