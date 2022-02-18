#include <stdio.h>
#include <stdlib.h>

// as is, complexity is (2^n)!! 
// does recursion suck then?!
uint64_t fibo_recursive(int n)
{	
	if (n==0)
		return 0;
	else if (n==1)
		return 1;
	else
		return fibo_recursive(n-1) + fibo_recursive(n-2);
}

// complexity is O(n) in time, O(n) in space
uint64_t fibo_iterative(int n)
{
	int i;
	uint64_t ret;
	
	uint64_t *tmp = (uint64_t *)malloc(n * sizeof(uint64_t));
	tmp[0] = 1;
	
	for (i=1;i<n;i++)
		tmp[i] = tmp[i-1] + ((i>1)?tmp[i-2]:0);
	
	ret = tmp[n-1];
	free(tmp);
	
	return ret;
}

int main()
{
	int i = 1;

	for (i=0;i<50;i++)
		printf("[%d]:\tFibo_iterative[%U]\tFibo_recursive[%U]\n", i, fibo_iterative(i), fibo_recursive(i));

	return 0;
}