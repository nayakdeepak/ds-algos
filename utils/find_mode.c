#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_INT	(100)
#define SZ_INP	(1000)

int find_max_index(int *x, int sz)
{
	int i;
	int max = -1;
	
	for (i=0;i<sz;i++)
		max = (x[i]>max) ? i : max;
		
	return max;
}
	
	
int main()
{
	int i;
	time_t t;
	
	unsigned int *input = (unsigned int *)calloc(SZ_INP, sizeof(int));
	
	int input_size = SZ_INP;
	
	srand((unsigned int) time (&t));
	
	for (i=0;i<input_size;i++)
		input[i] = rand() % MAX_INT;
	
	int freq[MAX_INT] = {0};
	
	for (i=0;i<input_size;i++)
	{
		freq[ input[i] ]++;
	}
	
	for (i=0;i<MAX_INT;i++)
		printf("%d:%d\t", i, freq[i]);
	
	printf("\nMode is %d\n", find_max_index(freq, MAX_INT));
	
	return 0;
}
	
	
	
	
	