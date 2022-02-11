/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <time.h>

#define MAX_INT (100)
#define SZ_INT	(50)

#define INIT		(-100)

struct twosum_inds
{
	int ind1;
	int ind2;
};

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

struct twosum_inds *find_twosum(int *num, int size, int target)
{
	int i,j;
	struct twosum_inds *ret = (struct twosum_inds *)calloc(1, sizeof(struct twosum_inds));
	
	ret->ind1 = ret->ind2 = -1;
	
	for (i=0;i<size;i++)
	{
		for (j=i+1;j<size;j++)
		{
			if (num[i]+ num[j] == target)
			{	
				printf("%d[%d] %d[%d]\n", num[i], i, num[j], j);
				ret->ind1 = i;
				ret->ind2 = j;
				return ret;
			}
		}
	}
	
	return ret;
}

struct twosum_inds *find_twosum_fast(int *num, int size, int target)
{
	int i,j;
	struct twosum_inds *ret = (struct twosum_inds *)calloc(1, sizeof(struct twosum_inds));
	ret->ind1 = ret->ind2 = -1;
	
	for (i=0;i<size;i++)
	{
		printf("Search for %d\n", target-num[i]);
		int pos = search(hashtable, target-num[i]);
		
		if (pos!=-1)
		{
			ret->ind1 = i;
			ret->ind2 = pos;
			return ret;
		}
	}
	
	return ret;
}

/* Arrange the N elements of ARRAY in random order.
   Only effective if N is much smaller than RAND_MAX;
   if this may not be the case, use a better random
   number generator. */
void shuffle(int *array, size_t n)
{
    if (n > 1) {
        size_t i;
	for (i = 0; i < n - 1; i++) {
	  size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
	  int t = array[j];
	  array[j] = array[i];
	  array[i] = t;
	}
    }
}

int main()
{
	int i;
	time_t t;
	struct twosum_inds *answer;
	
	int *nums = (int *)calloc(SZ_INT, sizeof(int));
	
	srand((unsigned int) time (&t));

	for (i=0;i<SZ_INT;i++)
#if 0
		nums[i] = rand() % MAX_INT;
#else
		nums[i] = i;
	shuffle(nums, SZ_INT);
#endif
	
	for (i=0;i<SZ_INT;i++)
		printf("%d[%d]\t", nums[i], i);
	printf("\n\n");
	
	int target = 50;
	int size = SZ_INT;
	
	sz_hashtable = size * 2;
	hashtable = (hash_tbl_t *)malloc(sz_hashtable * sizeof(hash_tbl_t));
	
	for (i=0;i<sz_hashtable;i++)
	{
		hashtable[i].key = INIT;
		hashtable[i].pos = INIT;
	}
	print_hashtable(hashtable);
	
	for (i=0;i<size;i++)
	{
		insert(hashtable, nums[i], i);
	}
	
	print_hashtable(hashtable);
	
	answer = find_twosum(nums, size, target);
	printf("\nTarget:%d, Inds: %d, %d\n", target, answer->ind1, answer->ind2);
	
	answer = find_twosum_fast(nums, size, target);
	printf("\nTarget:%d, Inds: %d, %d\n", target, answer->ind1, answer->ind2);
	
	
	return 0;
	
}