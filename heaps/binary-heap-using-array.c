#include <stdio.h>

#define HEAP_SZ	(10)

int binheap[HEAP_SZ] = {0};
int heap_size = 0;

#define SWAP(a,b)	do { (a) = (a) + (b); \
						 (b) = (a) - (b); \
						 (a) = (a) - (b); \
					   } while(0)
		
int swap_ptrs(int *x, int *y)
{
	int tmp;
	
	tmp = *x;
	*x = *y;
	*y = tmp;
}

int parent(int i)
{
	return (i-1)/2;
}	

void insert(int *heap, int x)
{
	int i;
	
	printf("Insert: ");
	
	if (heap_size >= HEAP_SZ)
	{
		printf("Heap overflow!\n");
		return;
	}
	
	heap_size++;
	i = heap_size - 1;
	binheap[i] = x;
	
	while(i!=0 && binheap[parent(i)] > binheap[i])
	{
		swap_ptrs(&binheap[i], &binheap[parent(i)]);
		i = parent(i);
	}
	
	printf("%d inserted\n", x);
	
	return;
}

void print_array(int *heap, int size)
{
	int i;
	
	printf("Array: ");
	for (i=0;i<size;i++)
		printf("%d\t", heap[i]);
	printf("\n");
}
		

int main()
{
	int i;

	print_array(binheap, HEAP_SZ);
	
	insert(binheap, 10);
	print_array(binheap, HEAP_SZ);
	insert(binheap, 2);
	print_array(binheap, HEAP_SZ);
	insert(binheap, 200);
	print_array(binheap, HEAP_SZ);
	insert(binheap, 55);
	print_array(binheap, HEAP_SZ);
	insert(binheap, 62);
	print_array(binheap, HEAP_SZ);
	insert(binheap, 78);
	print_array(binheap, HEAP_SZ);
	insert(binheap, 999);
	print_array(binheap, HEAP_SZ);
	
	
	return 0;
}