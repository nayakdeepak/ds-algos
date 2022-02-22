#include <stdio.h>
#include <stdlib.h>

// protos
void swap(int *x, int *y);
void print_array(int *array, int size);
void merge_sort(int *array, int size);
void merge(int *left, int *right, int size);

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

void merge(int *left, int *right, int size)
{
	int i, j, k;
	int *l, *r; // internal arrays
	
	l = (int *)calloc(size, sizeof(int));
	r = (int *)calloc(size, sizeof(int));
	
	printf("\nMerge:\tsize[%d]\n", size);
	print_array(left, size);
	print_array(right, size);

	for (i=0;i<size;i++)
	{
		l[i] = left[i];
		r[i] = right[i];
	}
		
	i=j=k=0;
	while(i<size && j<size)
	{
		if (l[i]<r[j])
			left[k++] = l[i++];
		else
			left[k++] = r[j++];
	}
	
	while(i<size)
		left[k++] = l[i++];
	while(j<size)
		left[k++] = r[j++];
	
	printf("---\n");
	print_array(left, size);
	print_array(right, size);
	
	free(l);
	free(r);
	return;
}

void merge_sort(int *array, int size)
{
	if (size<=2)
	{
		if (*array > *(array+1))
		{
			printf("Swap!");
			swap(array, array+1);
		}
		return;
	}
	
	int i, new_size;
	int *left, *right;
	
	new_size = size/2;
	
	left = array;
	right = array + new_size;
	
	printf("Left:\t");
	for (i=0;i<new_size;i++)
		printf("%d\t", left[i]);
	printf("\tRight:\t");
	for (i=0;i<new_size;i++)
		printf("%d\t", right[i]);
	printf("\n");
	
	merge_sort(left, new_size);
	merge_sort(right, new_size);
	
	merge(left, right, new_size);
	
	printf("Post-merge:\t");
	print_array(array, size);
	printf("\n");
}

int main()
{
	int i, j, min, index;
	int size;
	//int array[] = { 768, 12, 5, 45, 3, 14, 109, 9};
	int array[] = { 768, 12, 123, 45, 1100, 200, 4199, 345};
	//int array[] = {0, 100, 355};
	
	size = sizeof(array) / sizeof(array[0]);
	if (size%2 != 0)
	{
		printf("Array size = %d, need even sized array as of now!\n", size);
		return 0;
	}

	printf("Before:\t");
	print_array(array, size);
	printf("\n");
	
	merge_sort(array, size);
	
	printf("\nAfter:\t");
	print_array(array, size);
	
	return 0;
}
