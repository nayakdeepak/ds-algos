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
		up = tmp;
		if (val < tmp->val)
		{
			tmp = tmp->left;
			printf("L ");
		}
		else
		{
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

// find the node with min val given a starting node
bnode_t *find_min_node(bnode_t *start)
{
	bnode_t *tmp;
	
	tmp = start;
	while(tmp && tmp->left != NULL)
		tmp = tmp->left;
	
	return tmp;
}
	
int delete(bnode_t *btree, int x)
{
	bnode_t *tmp, *up;
	
	printf("Delete: ");
	
	if (btree_empty==TRUE)
	{
		printf("Tree empty!\n");
		return NOT_FOUND;
	}

	tmp = btree;
	
	while(1)
	{
		up = tmp;
		if (x < tmp->val)
			tmp = tmp->left;
		else
			tmp = tmp->right;

		if (tmp==NULL)
		{
			printf("%d not found!\n", x);
			return NOT_FOUND;
		}
		
		//printf("upval - %d, tmpval - %d\n", up->val, tmp->val);
		if (tmp->val == x)
		{
			// leaf node - no child
			if ((tmp->left==NULL) && (tmp->right==NULL))
			{
				if (x < up->val)
					up->left = NULL;
				else
					up->right = NULL;
			}
			
			// node with only 1 child
			if (tmp->left == NULL)
			{
				up->right = tmp->right;
				free(tmp);
			}
			else if (tmp->right == NULL)
			{
				up->left = tmp->left;
				free(tmp);
			}
			else // worst case - both children exist!
			{
				printf("Worst case! ");
				bnode_t *min_node = find_min_node(tmp->right);
				//printf("Min node [%d]\n",  min_node->val);
				if (x < up->val)
					up->left = min_node;
				else
					up->right = min_node;
				min_node->right = tmp->right;
				free(tmp);
			}
			
			printf("%d deleted!\n", x);
			return FOUND;
		}
	}
	
	printf("%d not found!\n", x);
	return NOT_FOUND;
}

int main()
{
	bnode_t *btree = (bnode_t *)calloc(1, sizeof(bnode_t));
	
	insert(btree, 9);
	insert(btree, 4);
	insert(btree, 6);
	insert(btree, 5);
	insert(btree, 7);
	insert(btree, 8);
	insert(btree, 20);
	insert(btree, 170);	
	insert(btree, 15);	
	insert(btree, 1);
	insert(btree, 0);
	insert(btree, 16);
	
	printf("\n");
	
	search(btree, 1);
	search(btree, -10);
	search(btree, 170);
	search(btree, 16);
	
#if 1
	delete(btree, 1);
	search(btree, 1);
	search(btree, 0);
#endif

#if 1
	delete(btree, 15);
	search(btree, 15);
	search(btree, 16);
#endif

	delete(btree, 1099);
	
	delete(btree, 4);
	search(btree, 4);
	search(btree, 5);
	search(btree, 6);
	search(btree, 7);
	search(btree, 8);
	
	return 0;
}