#include <stdio.h>

#define SWAP(a,b)	do {	(a) = (a) + (b); \
							(b) = (a) - (b); \
							(a) = (a) - (b); \
						} while(0)

int main()
{
	int i, j, min, index;
	int size;
	int array[] = { 599, 12, 5, 56, 78, 12, 45, 34, 100 };
	
	size = sizeof(array) / sizeof(array[0]);

	printf("Before:\t");
	for (i=0;i<size;i++)
		printf("%d\t", array[i]);
	
	for (i=0;i<size;i++)
	{
		min = array[i];
		index = i;
		for (j=i+1;j<size;j++)
		{
			if (min>array[j])
			{
				min = array[j];
				index=j;
			}
		if (min!= array[i])
			SWAP(array[i], array[j]);
		}
	}
			
	
	printf("\nAfter:\t");
	for (i=0;i<size;i++)
		printf("%d\t", array[i]);
	
	return 0;
}