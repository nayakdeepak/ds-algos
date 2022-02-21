#include <stdio.h>

#define SWAP(a,b)	do {	(a) = (a) + (b); \
							(b) = (a) - (b); \
							(a) = (a) - (b); \
						} while(0)
					
int main()
{
	int i, j;
	int size;
	int array[] = { 12, 5, 56, 78, 12, 45, 34 };
	
	size = sizeof(array) / sizeof(array[0]);

	printf("Before:\t");
	for (i=0;i<size;i++)
		printf("%d\t", array[i]);
	
	for (i=0;i<size;i++)
		for (j=0;j<size;j++)
		{
			if (array[j] > array[j+1])
				SWAP(array[j], array[j+1]);
		}
	
	printf("\nAfter:\t");
	for (i=0;i<size;i++)
		printf("%d\t", array[i]);
	
	return 0;
}
		

	