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

// insert before given value
void ll_insert_before(ll_node_t *head, int x, int before)
{
	ll_node_t *tmp, *prev, *new;
	
	printf("INSERT: ");
	
	tmp = head;
	
	while(tmp->next != NULL)
	{
		prev = tmp;
		tmp = tmp->next;
		if (tmp->a == before)
			break;
	}
	
	if (tmp->a != before)
	{
		printf("%d doesn't exist in list!\n", before);
		return;
	}
	
	new = (ll_node_t *)malloc(sizeof(ll_node_t));
	new->a = x;
	new->next = tmp;

	if (tmp == head)
		tmp->next = new;
	else
		prev->next = new;
	
	printf("%d inserted before %d\n", x, before);
	
	return;	
}

// delete item before
// p1 -- p2 -- p3 (holds before)
int ll_delete_before(ll_node_t *head, int before)
{
	int x;
	ll_node_t *p1, *p2, *p3;
	
	printf("DELETE: ");
	
	if ((head->next)->a == before)
	{
		printf("Can't delete HEAD!\n");
		return -1;
	}
	
	p1 = head;
	while(p1->next->next != NULL)
	{
		p2 = p1->next;
		p3 = p2->next;
		if (p3->a == before)
			break;
		p1 = p1->next;
	}
	
	if (p3->a != before)
	{
		printf("%d doesn't exist in list!\n", before);
		return -1;
	}
	
	x = p2->a;
	
	p1->next = p2->next;
	free(p2);
	
	printf("%d deleted, was before %d\n", x, before);
	
	return x;	
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

	ll_insert_before(&head, 100, 45);
	ll_print(&head);
	
	ll_insert_before(&head, 1145, 23);
	ll_print(&head);
	
	ll_insert_before(&head, 2000, 895);
	ll_print(&head);
	
	ll_insert_before(&head, 199, 678);
	ll_print(&head);
	
	int a = ll_delete_before(&head, 1145);
	ll_print(&head);
	
	a = ll_delete_before(&head, 23);
	ll_print(&head);
	
	a = ll_delete_before(&head, 100);
	ll_print(&head);
	
	a = ll_delete_before(&head, 1290);
	ll_print(&head);
	
	a = ll_delete_before(&head, 895);
	ll_print(&head);
	
	a = ll_delete_before(&head, 1290);
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