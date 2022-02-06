#include <stdio.h>
#include <stdlib.h>

#define FOUND       (0)
#define NOT_FOUND   (-1)

#define MAX(a,b)    ((a)>(b)?(a):(b))

char a1[] = "Hello is this right!";
char a2[] = "This is simply awesome! But are you hello'd?";

typedef struct item
{
    int key;
} item_t;

item_t **hashtable;
int sz_hashtable;

int hashcode(int key)
{
    return key % sz_hashtable;
}

void insert(item_t **table, int key)
{
    int i;
    int code;
    
    item_t *item = (item_t *)malloc(sizeof(item_t));
    item->key = key;
    
    code = hashcode(key);

    while(table[code]!=NULL)
    {
        ++code;
        code %= sz_hashtable;
    }
    
    table[code] = item;
}

int search(item_t **table, int key)
{
	int i;
	int code = hashcode(key);
	
	while(table[code]!=NULL)
	{
		if (table[code]->key == key)
			return FOUND;
		
		++code;
		
		code %= sz_hashtable;
	}
	
	return NOT_FOUND;
}
	
void print_hashtable(item_t **table)
{
    int i;
    item_t *item;
    
    for (i=0;i<sz_hashtable;i++)
    {
        item = hashtable[i];
		if (item!=NULL)
			printf("%d -%d(%c)\t", i, item->key, item->key);
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
    
    hashtable = (item_t **)malloc(sz_hashtable * sizeof(item_t *));
    for (i=0;i<sz_hashtable;i++)
    {
        hashtable[i] = 0;
    }

	for(i=0;i<sz_a1;i++)
		insert(hashtable, a1[i]);
	
    print_hashtable(hashtable);
	
	printf("a1 = %s\n", a1);
	printf("a2 = %s\n", a2);
    
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