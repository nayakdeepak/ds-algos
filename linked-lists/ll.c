#include <stdio.h>
#include <stdlib.h>

typedef struct ll_node
{
	int a;
	struct ll_node *next;
} ll_node_t;

void ll_print(ll_node_t *head)
{
	ll_node_t *tmp;
	
	tmp = head;

	while(tmp)
	{
		if (tmp->a == -1)
			printf("HEAD\t");
		else
			printf("%d\t", tmp->a);
		tmp = tmp->next;
	} 
	
	printf("\n");
	return;
}

// add a node at the end
void ll_add(int x, ll_node_t *head)
{
	ll_node_t *tmp;
	ll_node_t *new;
	
	tmp = head;
	
	while(tmp->next != NULL)
		tmp = tmp->next;
	new = (ll_node_t *)malloc(sizeof(ll_node_t));
	new->a = x;
	new->next = NULL;
	tmp->next = new;
	
	printf("%d added\n", x);
	
	return;
}

// remove the  last node
int ll_remove(ll_node_t *head)
{
	int a;
	ll_node_t *tmp, *prev;
	
	tmp = head;
	if (tmp->next == NULL)
		return -1;
	
	while(tmp->next != NULL)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	
	a = tmp->a;
	
	free(tmp);
	prev->next = NULL;
	
	return a;
}
	
int main(int argc, char *argv[])
{
	ll_node_t head;
	
	head.a = -1;
	head.next = NULL;
	
	ll_print(&head);
	ll_add(23, &head);
	ll_print(&head);
	ll_add(45, &head);
	ll_print(&head);
	ll_add(895, &head);
	ll_print(&head);
	
	printf("%d removed\n", ll_remove(&head));
	ll_print(&head);
	printf("%d removed\n", ll_remove(&head));
	ll_print(&head);
	
	printf("%d removed\n", ll_remove(&head));
	ll_print(&head);
	
	printf("%d removed\n", ll_remove(&head));
	ll_print(&head);
	
	printf("%d removed\n", ll_remove(&head));
	ll_print(&head);
	
	printf("%d removed\n", ll_remove(&head));
	ll_print(&head);
	
	return 0;
}