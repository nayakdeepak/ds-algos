#include <stdio.h>

#define QUE_SZ	(5)
#define QUE_EMPTY	(-100)

int *que_ptr;

void print_array(int *que)
{
	int i;
	int *ptr = que;
	
	printf("Array: ");
	for (i=0;i<QUE_SZ;i++)
		printf("%d\t", *ptr++);
	printf("\n");
	
	return;
}

void print_queue(int *que)
{
	int *ptr;
	
	ptr = que;
	
	printf("Queue: ");
	while(ptr < que_ptr)
	{
		printf("%d\t", *ptr++);
	}
	printf("\n\n");
	
	return;
}

void enque(int *que, int x)
{
	printf("Enq: ");
	
	if (que_ptr >= que + QUE_SZ)
	{
		printf("Queue full!\n");
		return;
	}
	
	*que_ptr++ = x;

	printf("%d enque'd\n", x);

	return;
}

int deque(int *que)
{
	int x;
	int *ptr = que;
	
	printf("Deque: ");
	
	if (que_ptr <= que)
	{
		printf("Queue is empty!\n");
		return -1;
	}
	
	x = *ptr++;
	
	printf("%d deque'd\n", x);
	
	return x;
}

int main()
{
	int queue[QUE_SZ] = {0};
	int *que = queue;
	
	que_ptr = queue;
	
	enque(que, 12);
	print_array(que);
	print_queue(que);
	
	enque(que, 15);
	print_array(que);
	print_queue(que);
	
	enque(que, 99);
	print_array(que);
	print_queue(que);
	
	enque(que, 1900);
	print_array(que);
	print_queue(que);
	
	enque(que, 34);
	print_array(que);
	print_queue(que);
	
	enque(que, 567);
	print_array(que);
	print_queue(que);
	
	deque(que);
	print_array(que);
	print_queue(que);
	
	deque(que);
	print_array(que);
	print_queue(que);
	
	deque(que);
	print_array(que);
	print_queue(que);
	
	deque(que);
	print_array(que);
	print_queue(que);
	
	deque(que);
	print_array(que);
	print_queue(que);
	
	deque(que);
	print_array(que);
	print_queue(que);
	
	deque(que);
	print_array(que);
	print_queue(que);
	
	
	
	return 0;
}
	
	
	
	
	
	
	