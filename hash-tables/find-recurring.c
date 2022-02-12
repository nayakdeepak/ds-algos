// find the element in an array that recurs 

#include <stdio.h>
#include <stdlib.h>

#define INIT		(-100)

int *hashtable;
int sz_hashtable;

int hashcode(int key)
{
    return key % sz_hashtable;
}

void insert(int *table, int key)
{
    int i;
    int code;
    
    code = hashcode(key);

    while(table[code]!=INIT)
    {
        ++code;
        code %= sz_hashtable;
    }
    
    table[code] = key;
}

#if 0
int search(int *table, int key)
{
	int i;
	int code = hashcode(key);
	
	while(table[code] != INIT)
	{
		if (table[code] == key)
			return FOUND;
		
		++code;
		
		code %= sz_hashtable;
	}
	
	return NOT_FOUND;
}
#endif

int find_recurring(int *table, int key)
{
	int i;
	int code = hashcode(key);
	int found_freq = 0;
	
	while(table[code] != INIT)
	{
		if (table[code] == key)
			found_freq++;
		
		//printf("%d~%d, freq:%d\n", code, key, found_freq);
		
		++code;
		
		code %= sz_hashtable;
		
		if (found_freq > 1)
			return key;
	}
	
	return -1;
}
		
void print_hashtable(int *table)
{
    int i;
    
    for (i=0;i<sz_hashtable;i++)
    {
        int key = table[i];
		if (key != INIT)
			printf("%d-%d\t", i, key);
		else
			printf("%d-~\t", i);
    }
	
	printf("\n\n");
}

int main()
{
	int i;
	int nums[] = {1,2,2,24,7,6,3,4,5};
	
	int size = sizeof(nums) / sizeof(nums[0]);
	sz_hashtable = size * 2;
	
	for (i=0;i<size;i++)
		printf("%d\t", nums[i]);
	printf("\n\n");
	
	hashtable = (int *)malloc(sz_hashtable * sizeof(int));
	
	for (i=0;i<sz_hashtable;i++)
	{
		hashtable[i] = INIT;
	}
	
	print_hashtable(hashtable);
	
	for (i=0;i<size;i++)
		insert(hashtable, nums[i]);
	
	print_hashtable(hashtable);
	
	for (i=0;i<size;i++)
	{
		int ret = find_recurring(hashtable, nums[i]);
		if (ret != -1)
		{
			printf("Found %d recurring\n", ret);
			return 0;
		}
	}
	printf("No recurring elements found!\n");
	
	return 0;
}