#include <stdio.h>
#include <stdlib.h>

#define TRUE		(0)
#define FALSE		(-1)

#define FOUND		(1)
#define NOT_FOUND	(0)

#define MAX(a,b)	((a)>(b)?(a):(b))

typedef struct bnode 
{
	int val;
	struct bnode *left;
	struct bnode *right;
} bnode_t;

int btree_empty = TRUE;
int btree_level = -1;

void insert(bnode_t *btree, int val)
{
	bnode_t *tmp, *new, *up;
	
	printf("Insert: ");
	
	tmp = btree;
	
	if (btree_empty==TRUE)
	{
		btree_empty = FALSE;
		tmp->val = val;
		btree_level++;
		printf("(root) %d\n", val);
		return;
	}
	
	// find insertion point
	int level = 0;
	while(tmp != NULL)
	{
		if (val < tmp->val)
		{
			up = tmp;
			tmp = tmp->left;
			printf("L ");
		}
		else
		{
			up = tmp;
			tmp = tmp->right;
			printf("R ");
		}
		level++;
	}
	
	btree_level = MAX(btree_level, level);
	
	new = (bnode_t *)calloc(1, sizeof(bnode_t));
	new->val = val;
	
	if (val < up->val)
		up->left = new;
	else	
		up->right = new;
	
	printf("%d inserted; btree_level[%d]\n", val, btree_level);
	
	return;
}

int search(bnode_t *btree, int x)
{
	bnode_t *tmp;
	int srchs = 0;
	
	printf("Search: ");
	
	if (btree_empty==TRUE)
	{
		printf("Tree empty!\n");
		return NOT_FOUND;
	}

	tmp = btree;
	
	while(tmp != NULL)
	{
		if (tmp->val == x)
		{
			printf("%d found - took %d searches!\n" , x, srchs);
			return FOUND;
		}
		
		srchs++;
		if (x < tmp->val)
			tmp = tmp->left;
		else
			tmp = tmp->right;
	}
	
	printf("%d not found even after %d searches!\n", x, srchs);
	return NOT_FOUND;
}

int main()
{
	bnode_t *btree = (bnode_t *)calloc(1, sizeof(bnode_t));
	
	insert(btree, 9);
	insert(btree, 4);
	insert(btree, 6);
	insert(btree, 20);
	insert(btree, 170);	
	insert(btree, 15);	
	insert(btree, 1);
	insert(btree, 16);
	
	printf("\n");
	
	search(btree, 1);
	search(btree, -10);
	search(btree, 170);
	search(btree, 16);
	
	return 0;
}