#include <stdio.h>
#include <stdlib.h>

// the dll is circular - head --- through the list -- back to head

typedef struct dll_node
{
	int a;
	struct dll_node *next;
	struct dll_node *prev;
} dll_node_t;

enum
{
	forward=0,
	reverse
};

// insert a node before a value
void dll_insert_before(int x, int before, dll_node_t *head)
{
	dll_node_t *tmp, *new;
	
	printf("Insert before: ");
	
	tmp = head;
	while(tmp->next != head)
	{
		if (tmp->a == before)
			break;
		tmp = tmp->next;
	}
	
	if ((tmp->next == head)&&(tmp->a!=before))
	{
		printf("%d does not exist in the list!\n", before);
		return;
	}
	
	new = (dll_node_t *)malloc(sizeof(dll_node_t));
	new->a = x;
	new->next = tmp;
	new->prev = tmp->prev;
	
	tmp->prev->next = new;
	tmp->prev = new;
	
	printf("%d inserted before %d\n", x, before);
	
	return;
}

// delete a node before a value
int dll_delete_before(int before, dll_node_t *head)
{
	dll_node_t *tmp, *pre, *prev;
	int x;
	
	printf("Delete Before: ");
	
	if (head->next->a == before)
	{
		printf("Can't delete before first node!\n");
		return -1;
	}
	
	tmp=head;
	while (tmp->next != head)
	{
		if (tmp->a==before)
			break;
		tmp = tmp->next;
	}
	
	if ((tmp->next == head)&&(tmp->a!=before))
	{
		printf("%d doesn't exist in the list!\n", before);
		return -1;
	}
	
	prev = tmp->prev;
	pre = prev->prev;
	
	x = prev->a;
	
	pre->next = tmp;
	tmp->prev = pre;
	
	free(prev);
	
	printf("%d deleted before %d\n", x, before);
	
	return -1;
}

// add a node at the end
void dll_add_last(int x, dll_node_t *head)
{
	dll_node_t *tmp, *new;
	
	printf("Add Last: ");
	
	tmp = head;
	while (tmp->next != head)
		tmp = tmp->next;
	
	new = (dll_node_t *)malloc(sizeof(dll_node_t));
	new->a = x;
	new->prev = tmp;
	new->next = head;
	
	tmp->next = new;
	head->prev = new;
	
	printf("%d added\n", x);
	
	return;
}

// add a node at the first
void dll_add_first(int x, dll_node_t *head)
{
	dll_node_t *tmp, *new;
	
	printf("Add First: ");
	
	new = (dll_node_t *)malloc(sizeof(dll_node_t));
	new->a = x;
	new->prev = head;
	new->next = head->next;
	
	head->next->prev = new;
	head->next = new;
	
	printf("%d added\n", x);
	
	return;
}

// remove the last node
int dll_remove_last(dll_node_t *head)
{
	int a;
	dll_node_t *tmp, *prev;
	
	printf("Remove Last: ");
	
	tmp = head;
	if (tmp->next == head || tmp->prev == head)
		return -1;
	
	while (tmp->next != head)
		tmp = tmp->next;
	
	prev = tmp->prev;
	
	prev->next = head;
	head->prev = prev;
	
	a = tmp->a;
	free(tmp);
	
	return a;
}

// remove the first node
int dll_remove_first(dll_node_t *head)
{
	int a;
	dll_node_t *tmp, *next;
	
	printf("Remove First: ");
	
	tmp = head->next;
	
	next = tmp->next;
	
	head->next = next;
	next->prev = head;
	
	a= tmp->a;
	free(tmp);
	
	return a;
}

void dll_print(int direction, dll_node_t *head)
{
	dll_node_t *tmp;
	
	tmp = head;
	printf("%c : HEAD\t", (direction==forward)?'f':'r');
	
	if (direction == forward)
	{
		while(tmp->next != head)
		{
			tmp = tmp->next;
			printf("%d\t", tmp->a);
		}
	}
	else if (direction == reverse)
	{
		while(tmp->prev != head)
		{
			tmp = tmp->prev;
			printf("%d\t", tmp->a);
		}
	}
	
	printf("\n");
	return;
}

int main(int argc, char *argv[])
{
	dll_node_t head;
	
	head.a = -1;
	head.next = &head;
	head.prev = &head;
	
	dll_print(forward, &head);
	dll_print(reverse, &head);
	dll_add_last(10, &head);
	dll_print(forward, &head);
	dll_print(reverse, &head);
	dll_add_last(24, &head);
	dll_print(forward, &head);
	dll_print(reverse, &head);
	dll_add_first(1021, &head);
	dll_print(forward, &head);
	dll_print(reverse, &head);
	dll_add_last(2345, &head);
	dll_print(forward, &head);
	dll_print(reverse, &head);
	
	dll_insert_before(1500, 2400, &head);
	dll_print(forward, &head);
	dll_print(reverse, &head);
	dll_insert_before(100, 24, &head);
	dll_print(forward, &head);
	dll_print(reverse, &head);
	dll_insert_before(23, 2345, &head);
	dll_print(forward, &head);
	dll_print(reverse, &head);
	
	dll_delete_before(1021, &head);
	dll_print(forward, &head);
	dll_print(reverse, &head);
	dll_delete_before(678, &head);
	dll_print(forward, &head);
	dll_print(reverse, &head);
	dll_delete_before(100, &head);
	dll_print(forward, &head);
	dll_print(reverse, &head);
	dll_delete_before(2345, &head);
	dll_print(forward, &head);
	dll_print(reverse, &head);
	
	printf("%d removed\n", dll_remove_first(&head));
	dll_print(forward, &head);
	dll_print(reverse, &head);
	
	printf("%d removed\n", dll_remove_last(&head));
	dll_print(forward, &head);
	dll_print(reverse, &head);
		
	printf("%d removed\n", dll_remove_last(&head));
	dll_print(forward, &head);
	dll_print(reverse, &head);
		
	printf("%d removed\n", dll_remove_first(&head));
	dll_print(forward, &head);
	dll_print(reverse, &head);
		
	printf("%d removed\n", dll_remove_last(&head));
	dll_print(forward, &head);
	dll_print(reverse, &head);
	
	printf("%d removed\n", dll_remove_last(&head));
	dll_print(forward, &head);
	dll_print(reverse, &head);
	
	return 0;
}
