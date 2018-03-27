#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>

bool isCompleted[100];
bool available[100];

bool isOk(int temp , int A[] ,int p)
{
	int i;
	for(i=0;i<p;i++)
	{
		if(A[i]>=temp && available[i])
			return true;
	}
	return false;
}

int main()
{
		int i,j,total_memory,no_of_partition,block_size,no_of_process,memory_of_process[100],partition[100];
		int aa[100],ext=0;
		char cc;

		printf("Enter the total amount of memory :");
		scanf("%d",&total_memory);

		ext=total_memory;

		printf("Enter the number of partition :");
		scanf("%d",&no_of_partition);

		int total_partition=0;
		for(i=0;i<no_of_partition;i++)
		{
			printf("Enter the memory for partition %d : ",i+1);
			scanf("%d",partition+i);
			total_partition+=partition[i];
		}

		ext-=total_partition;
		printf("Enter the number of process:");
		scanf("%d",&no_of_process);

		for(i=0;i<no_of_partition;i++)
		{
			int temp;
			for(j=i+1;j<no_of_partition;j++)
			{
				if(partition[i]>partition[j])
				{
					temp=partition[i];
					partition[i]=partition[j];
					partition[j]=temp;
				}
			}
		}

		int memory_allocated=0,swap_with;
		bool allocated = false;
		char choice[100];
		for(i=0;i<no_of_process;i++)
		{
				//__fpurge(stdin);
				ext=(total_memory-total_partition);
				//ext+=(total_partition-memory_allocated);
				printf("Enter the memory required for process %d : ",i+1);
				scanf("%d",memory_of_process+i);
				allocated = false;
				memset(choice,'\0',sizeof(choice));
				for(j=0;j<no_of_partition;j++)
				{
						if(!available[j]&&partition[j]>=memory_of_process[i])
						{
							isCompleted[i]=true;
							available[j]=true;
							memory_allocated+=memory_of_process[i];
							allocated=true;
							aa[j]=i;
							printf("Allocate \n");
							break;
						}
				}

				if(allocated )
				{
					printf("allocated..\n");
					printf("\n\nProcess\t\tMemory of processt\t\tAllocated or Not\n");
					for(j=0;j<=i;j++)
					{
						printf("%d\t\t%d\t\t\t\t%s\n",j+1,memory_of_process[j],(isCompleted[j]?"YES":"NO"));
					}
					continue;
				}


				if(!allocated && isOk(memory_of_process[i],partition,no_of_partition))
				{


					printf("External Fragmentation : %d\n",ext);
					printf("Internal Fragmentation : %d\n\n",total_partition-memory_allocated);
					printf("Do you want to swap the process [yes\\no]:");
					scanf("%s",choice);
					if(!strcmp(choice,"yes"))
					{
							printf("Enter the partition number want to swap with : ");
							scanf("%d",&swap_with);
							swap_with--;
							if(partition[swap_with]>=memory_of_process[i])
							{
								isCompleted[aa[swap_with]]=false;
								isCompleted[i]=true;
								memory_allocated-=memory_of_process[aa[swap_with]];
								memory_allocated+=memory_of_process[i];
								//available[swap_with]=true;
								//available[j]=true;
								aa[swap_with]=i;
								ext=(total_memory-total_partition);
								//ext+=(total_partition-memory_allocated);
							}
							else
							{
								printf("Can't Allocate\n");
							}
					}
					printf("External Fragmentation : %d\n",ext);
					printf("Internal Fragmentation : %d\n\n",total_partition-memory_allocated);
					printf("\n\nProcess\t\tMemory of processt\t\tAllocated or Not\n");
					for(j=0;j<=i;j++)
					{
							printf("%d\t\t%d\t\t\t\t%s\n",j+1,memory_of_process[j],(isCompleted[j]?"YES":"NO"));
					}
				}
				else
				{
					printf("Couldn't allocate :( \n");
				}
		}

		printf("\n\nProcess\t\tMemory of processt\t\tAllocated or Not\n");
		for(j=0;j<i;j++)
		{
				printf("%d\t\t%d\t\t\t\t%s\n",j+1,memory_of_process[j],(isCompleted[j]?"YES":"NO"));
		}


}
rtition %d : ",i+1);
