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

// add a node at the end
void dll_add(int x, dll_node_t *head)
{
	dll_node_t *tmp, *new;
	
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

// remove the last node
int dll_remove(dll_node_t *head)
{
	int a;
	dll_node_t *tmp, *prev;
	
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
	dll_add(10, &head);
	dll_add(24, &head);
	dll_add(1021, &head);
	dll_add(2345, &head);
	dll_print(forward, &head);
	dll_print(reverse, &head);
	
	printf("%d removed\n", dll_remove_first(&head));
	dll_print(forward, &head);
	dll_print(reverse, &head);
	
	printf("%d removed\n", dll_remove(&head));
	dll_print(forward, &head);
	dll_print(reverse, &head);
		
	printf("%d removed\n", dll_remove(&head));
	dll_print(forward, &head);
	dll_print(reverse, &head);
		
	printf("%d removed\n", dll_remove(&head));
	dll_print(forward, &head);
	dll_print(reverse, &head);
		
	printf("%d removed\n", dll_remove(&head));
	dll_print(forward, &head);
	dll_print(reverse, &head);
	
	printf("%d removed\n", dll_remove(&head));
	dll_print(forward, &head);
	dll_print(reverse, &head);
	
	
		
	return 0;
}
