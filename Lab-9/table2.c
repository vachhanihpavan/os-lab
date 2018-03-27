#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

struct page {
    int pg_no;
    int frame;
};

int main()
{
    int la_size, pa_size, pg_size, i, j;
    printf("Enter size of logical address space: ");
    scanf("%d",&la_size);
    printf("Enter size of physical address space: ");
	scanf("%d",&pa_size);
	printf("Enter size of page: ");
	scanf("%d",&pg_size);

    int number_of_frames = pa_size/pg_size;
	int number_of_pages = la_size/pg_size;

	struct page page_table[number_of_pages];
	printf("Enter page table: \n");
	for(i=0;i<number_of_pages;i++)
	{
		page_table[i].frame = -1;
	}
    for(i=0;i<number_of_pages;i++)
	{
		int frame;
		bool replica = false;
		page_table[i].pg_no = i;
		printf("Enter frame for %d page number: ",i);
		scanf("%d",&frame);
		for(j=0;j<number_of_pages;j++)
		{
			if(frame!= -1 && page_table[j].frame == frame)
			{
				replica = true;
				printf("Frame number already stored\n");
                i--;
			}
		}
		if(frame >= number_of_frames)
		{
			replica = true;
			printf("Cannot exceed frame size\n");
            i--;
		}
		if(replica == false)
		{
			page_table[i].frame = frame;
		}
	}
	int logical_address;
	printf("Enter -1 to exit\n");
	while(1)
	{
		printf("Enter logical address: ");
		scanf("%d",&logical_address);
        if(logical_address >= la_size)
        {
            printf("Error\n");
            continue;
        }
		if(logical_address == -1)
			return 0;

		int pg_no = logical_address/pg_size;
		int offset = logical_address%pg_size;
		if(page_table[pg_no].frame == -1)
		{
			printf("No such logical address exist\n");
		}
		else
		{
			printf("Page no: %d \nOffset: %d\nFrame no: %d\nPhysical address: %d\n",pg_no, offset, page_table[pg_no].frame,page_table[pg_no].frame*pg_size + offset );
		}
	}
}
