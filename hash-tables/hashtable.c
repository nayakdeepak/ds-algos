#include <stdio.h>
#include <stdlib.h>

#define FOUND       (0)
#define NOT_FOUND   (-1)
#define INIT		(-100)

#define MAX(a,b)    ((a)>(b)?(a):(b))

char a1[] = {'H', 'e', 'l', 'o'};
char a2[] = {'h', 'e', 'l', 'l', 'o', '!'};

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
	
void print_hashtable(int *table)
{
    int i;
    
    for (i=0;i<sz_hashtable;i++)
    {
        int key = table[i];
		if (key != INIT)
			printf("%d-%d(%c)\t", i, key, key);
		else
			printf("%d-~\t", i);
    }
	
	printf("\n\n");
}

int main()
{
    int i;
    int sz_a1 = sizeof(a1) / sizeof(a1[0]);
    int sz_a2 = sizeof(a2) / sizeof(a2[0]);

    sz_hashtable = MAX(sz_a1, sz_a2) * 2;
    
    hashtable = (int *)malloc(sz_hashtable * sizeof(int));
    for (i=0;i<sz_hashtable;i++)
    {
        hashtable[i] = INIT;
    }

	print_hashtable(hashtable);
	
	for(i=0;i<sz_a1;i++)
		insert(hashtable, a1[i]);
	
    print_hashtable(hashtable);
	
	printf("a1 = ");
	for(i=0;i<sz_a1;i++)
		printf("%c", a1[i]);
	printf("\n");
	
	printf("a2 = ");
	for(i=0;i<sz_a2;i++)
		printf("%c", a2[i]);
	printf("\n");
    
	printf("Res= ");
	for (i=0;i<sz_a2;i++)
	{
		if (search(hashtable, a2[i]) == FOUND)
			printf("%c", a2[i]);
		else
			printf("~");
	}
	printf("\n");
	
    return 0;
}