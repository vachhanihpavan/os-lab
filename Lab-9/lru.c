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

int predict(int reference_length, int references[], int page_no ,int frame_size,int frame[], int start)
{
	int pos = -1, farthest = start, i;
	for(i=0;i<frame_size;i++)
	{
		int j;
		for(j=start-1;j>=0;j--)
		{
			if(frame[i]==references[j])
			{
				if(j<farthest)
				{
					farthest=j;
					pos=i;
				}
				break;
			}
		}
		if(j==page_no)
			return i;
	}
	if(pos == -1)
		return 0;
	else
		return pos;
}

void insert(int frame_size,int frame[], int reference, int current_position,int reference_length, int references[])
{
	int i;
	bool allocated=false;
	for(i=0;i<frame_size;i++)
	{

		if(frame[i]==reference)
		{
			printf("  Hit for %d | ", reference);
			hits++;
			allocated = true;
			break;
		}
		else if(frame[i]==-1)
		{
			frame[i] = reference;
			printf("Fault for %d | ", reference);
			faults++;
			allocated = true;
			break;
		}
	}
	if(allocated==false)
	{
		int j = predict(reference_length,references,current_position,frame_size,frame,current_position+1);

		frame[j] = reference;
		printf("Fault for %d | ", reference);
		faults++;
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
		insert(frame_size,frame,reference[i],i,no_ref,reference);
	}
	printf("\nNumber of faults: %d \nNumber of hits: %d\n",faults,hits);
}
