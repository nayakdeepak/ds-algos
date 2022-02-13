#include <stdio.h>
#include <stdlib.h>

/*
	Stack
	
	
	head <- elem1 <- elem2 <- elem3
								^
								|
							stack_top
*/

typedef struct node
{
	int x;
	struct node *next;
} node_t;

node_t *stack_top = NULL;

void print_stack(node_t *head)
{
	node_t *tmp;
	
	tmp = stack_top;
	
	while(tmp != head)
	{
		printf("%d\t", tmp->x);
		tmp = tmp->next;
	}
	printf("\n\n");
	
	return;
}

void push(node_t *head, int x)
{
	node_t *tmp, *new;
	
	printf("Push: ");
	
	tmp = stack_top;
	
	new = (node_t *)calloc(1, sizeof(node_t));
	new->x = x;
	
	new->next = tmp;
	
	stack_top = new;

	printf("Pushed %d on to stack\n", x);	
	
	return;
}
	
int pop(node_t *stack)
{
	printf("Pop: ");
	
	int x;
	
	node_t *tmp;
	
	if (stack_top == stack)
	{
		printf("Stack empty!\n");
		return -1;
	}
	
	tmp = stack_top;
	
	x = tmp->x;
	stack_top = tmp->next;
	
	free(tmp);
	
	printf("Popped %d\n", x);
	
	return x;
}

int main()
{
	node_t head;
	node_t *stack = &head;
	
	head.x = -1;
	head.next = NULL;
	
	stack_top = stack;
	
	push(stack, 100);
	print_stack(stack);
	
	push(stack, -50);
	print_stack(stack);
	
	push(stack, -150);
	print_stack(stack);
	
	pop(stack);
	print_stack(stack);
	
	pop(stack);
	print_stack(stack);
	
	pop(stack);
	print_stack(stack);
	
	pop(stack);
	print_stack(stack);
	
	push(stack, 29);
	print_stack(stack);
	
	
	return 0;
}
	
	
	
	
	
	
	