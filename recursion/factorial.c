#include <stdio.h>

uint64_t factorial_recursive(int n)
{
	if (n<=1)
		return 1;
	else
		return n * factorial_recursive(n-1);
}

uint64_t factorial_iterative(int n)
{
	int i;
	uint64_t ret = 1;
	
	for (i=1;i<=n;i++)
		ret *= i;
	
	return ret;
}
		
int main()
{
	int i;
	uint64_t ans;
	
	printf("Factorial calculator\n");
	printf("====================\n");
	printf("Enter the number: ");
	scanf("%d", &i);
	
	
	printf("Recursive: The factorial of %d is ", i);
	ans = factorial_recursive(i);
	if (ans)
		printf("%U\n", ans);
	else
		printf("--overflow--\n");
	
	printf("Iterative: The factorial of %d is ", i);
	ans = factorial_iterative(i);
	if (ans)
		printf("%U\n", ans);
	else
		printf("--overflow--\n");
	
	
	return 0;
}