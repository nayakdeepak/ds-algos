#include <stdio.h>

void print_array(int *array, int size)
{
	int i;
	
	for (i=0;i<size;i++)
		printf("%d\t", array[i]);
	printf("\n");
	
	return;
}

void sub_sort(int *array, int end)
{
	int i=0,j;
	int tmp;
	
	tmp = array[end];
	//printf("end[%d]\ttmp[%d]\n", end, tmp);
	do 
	{
		if (tmp < array[i])
		{
			//printf("Less!\n");
			for (j=end;j>i;j--)
				array[j] = array[j-1];
			array[i] = tmp;
			break;
		}
		i++;
	} while (i<=(end-1));
	
	return;
}

int main()
{
	int i, j, min, index;
	int size;
	int array[] = { 768, 12, 5, 45, 3, 14, 109, 9, 456 };
	
	size = sizeof(array) / sizeof(array[0]);

	printf("Before:\t");
	print_array(array, size);
	
	for (i=1;i<size;i++)
	{
		sub_sort(array, i);
	}
			
	printf("\nAfter:\t");
	print_array(array, size);
	
	return 0;
}