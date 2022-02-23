#include <stdio.h>
#include <stdlib.h>

// protos
void swap(int *x, int *y);
void print_array(int *array, int size);

// funcs
void swap(int *x, int *y)
{
	int tmp;
	int *t = &tmp;
	
	*t = *x;
	*x = *y;
	*y = *t;
}

void print_array(int *array, int size)
{
	int i;
	
	for (i=0;i<size;i++)
		printf("%d\t", array[i]);
	printf("\n");
	
	return;
}

void quick_sort(int *array, int low, int high)
{
	int i, tmp;
	int pivot = array[high];
	int pivot_index = high;

	//print_array(array, high+1);
	
	if (low < high)
	{
		i=0;
		while(i<pivot_index)
		{
			while(array[i] > pivot)
			{
				array[pivot_index] = array[i];
				array[i] = array[pivot_index-1];
				array[pivot_index-1] = pivot;
				pivot_index--;
			}
			i++;
		}
		
		//print_array(array, high+1);
		
		quick_sort(array, low, pivot_index-1);
		quick_sort(array, pivot_index+1, high);	
	}
	
	return;
}

int main()
{
	int i, j, min, index;
	int size;
	//int array[] = { 11,25,3,8,15, 10};
	//int array[] = { 8, 12, 5, 45, 3, 14, 109, 9};
	int array[] = { 768, 12, 123, 45, 1100, 200, 4199, 345, -190};
	//int array[] = {0, 100, 355};
	
	size = sizeof(array) / sizeof(array[0]);

	printf("Before:\t");
	print_array(array, size);
	printf("\n");
	
	quick_sort(array, 0, size-1);
	
	printf("\nAfter:\t");
	print_array(array, size);
	
	return 0;
}
