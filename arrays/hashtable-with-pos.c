// Create a hash table that encodes position also

#include <stdio.h>
#include <stdlib.h>

#define INIT	(-100)

typedef struct hashtbl
{
	int key;
	int pos;
} hash_tbl_t;

int sz_hashtable;
hash_tbl_t *hashtable;

int hashcode(int key)
{
    return key % sz_hashtable;
}

void insert(hash_tbl_t *table, int key, int pos)
{
    int i;
    int code;
    
    code = hashcode(key);

    while(table[code].key!=INIT)
    {
        ++code;
        code %= sz_hashtable;
    }
    
    table[code].key = key;
	table[code].pos = pos;
}

void print_hashtable(hash_tbl_t *table)
{
    int i;
    
    for (i=0;i<sz_hashtable;i++)
    {
        int key = table[i].key;
		if (key != INIT)
			printf("%d-%d(%d)\t", i, key, table[i].pos);
		else
			printf("%d-~\t", i);
    }
	
	printf("\n\n");
}

int search(hash_tbl_t *table, int key)
{
	int i;
	int code = hashcode(key);
	
	while(table[code].key != INIT)
	{
		if (table[code].key == key)
			return table[code].pos;
		
		++code;
		
		code %= sz_hashtable;
	}
	
	return -1;
}

int main()
{
	int i;
	
	int nums[] = { 1,2,3,4,5,20,14,15 };
	int sz_nums = sizeof(nums) / sizeof(nums[0]);
	
	for (i=0;i<sz_nums;i++)
		printf("%d\t", nums[i]);
	printf("\n\n");
	
	sz_hashtable = sz_nums * 2;
	hashtable = (hash_tbl_t *)malloc(sz_hashtable * sizeof(hash_tbl_t));
	
	for (i=0;i<sz_hashtable;i++)
	{
		hashtable[i].key = INIT;
		hashtable[i].pos = INIT;
	}
	print_hashtable(hashtable);
	
	for (i=0;i<sz_nums;i++)
	{
		insert(hashtable, nums[i], i);
	}
	
	print_hashtable(hashtable);
	
	int query = 14;
	int pos = search(hashtable, query);
	printf("Found %d at position %d\n", query, pos);
	
	return 0;
}
	