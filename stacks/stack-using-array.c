#include <stdio.h>

#define STACK_SZ	(5)
#define STACK_EMPTY	(-100)

int *stack_top;

void print_array(int *stack)
{
	int i;
	int *ptr = stack;
	
	printf("Array: ");
	for (i=0;i<STACK_SZ;i++)
		printf("%d\t", *ptr++);
	printf("\n");
	
	return;
}

void print_stack(int *stack)
{
	int *stack_ptr = stack_top-1;
	
	printf("Stack: ");

	while(stack_ptr >= stack)
	{
		printf("%d\t", *stack_ptr--);
	}
	printf("\n\n");
	
	return;
}

void push(int *stack, int x)
{
	printf("Push: ");
	
	if (stack_top >= (stack + STACK_SZ))
	{
		printf("Stack full!\n");
		return;
	}
	
	*stack_top++ = x;
	
	printf("Pushed %d\n", x);
	
	return;
}

int pop(int *stack)
{
	int x;
	
	printf("Pop: ");
	
	if(stack_top <= stack)
	{
		printf("Stack empty!\n");
		return STACK_EMPTY;
	}
	
	x = *(--stack_top);
	
	printf("Popped %d\n", x);
	
	return x;
}
	
int main()
{
	int stack_array[STACK_SZ] = {-1};
	
	stack_top = stack_array;
	
	push(stack_array, -10);
	print_array(stack_array);
	print_stack(stack_array);
	
	push(stack_array, -20);
	print_array(stack_array);
	print_stack(stack_array);
	
	push(stack_array, 50);
	print_array(stack_array);
	print_stack(stack_array);
	
	push(stack_array, 75);
	print_array(stack_array);
	print_stack(stack_array);
	
	pop(stack_array);
	print_array(stack_array);
	print_stack(stack_array);

	push(stack_array, 100);
	print_array(stack_array);
	print_stack(stack_array);
	
	pop(stack_array);
	print_array(stack_array);
	print_stack(stack_array);

	pop(stack_array);
	print_array(stack_array);
	print_stack(stack_array);

	pop(stack_array);
	print_array(stack_array);
	print_stack(stack_array);
	
	push(stack_array, -120);
	print_array(stack_array);
	print_stack(stack_array);
	
	pop(stack_array);
	print_array(stack_array);
	print_stack(stack_array);

	pop(stack_array);
	print_array(stack_array);
	print_stack(stack_array);
	
	pop(stack_array);
	print_array(stack_array);
	print_stack(stack_array);


	
	return 0;
}
	
	
	
	