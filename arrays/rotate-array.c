/*
Given an array, rotate the array to the right by k steps, where k is non-negative.
*/

// in-place rotate by k (<size) with O(1) space utilization

#include <stdio.h>
#include <stdlib.h>

void rotate_array(int *x, int size, int k)
{
	int i;
	
	if (k>size)
	{
		printf("Cannot rotate so much!\n");
		return;
	}
	
	int *tmp = (int *)malloc(k*sizeof(int));
	
	for (i=0;i<k;i++)
		tmp[i] = x[size-k+i];
	
	for (i=0;i<=(size-k);i++)
		x[size-i] = x[size-k-i];
	
	//for (i=0;i<size;i++)
	//	printf("%d\t", x[i]);
	//printf("\n");
	
	for (i=0;i<k;i++)
		x[i] = tmp[i];
	
	free(tmp);
	
	return;
}
	
int main()
{
	int i;
	int array[] = {1,2,3,4,5,6,7};
	
	int size = sizeof(array) / sizeof(array[0]);
	
	for (i=0;i<size;i++)
		printf("%d\t", array[i]);
	printf("\n");
	
	int k = 3;
	rotate_array(array, size, k);
	
	for (i=0;i<size;i++)
		printf("%d\t", array[i]);
	printf("\n");
	
	return 0;
}
	