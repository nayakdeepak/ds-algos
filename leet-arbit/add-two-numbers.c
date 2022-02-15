/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

Input: l1 = [0], l2 = [0]
Output: [0]

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct ll
{
	int val;
	struct ll *next;
} ll_t;

ll_t *create_number(int x)
{
	int num = x;
	ll_t *node, *prev, *head; 
	int first = 1;
	
	int divr = 10;
	int digit;
	do 
	{
		digit = num % divr;
		num /= 10;
		//printf("%d %d %d\n", num, divr, digit);
		node = (ll_t*)calloc(1, sizeof(ll_t));
		node->val = digit;
		if (first)
		{
			head = node;
			first = 0;
		}
		else	
			prev->next = node;
		prev = node;
	} while(num);
	
	return head;
}
		
void print_list(ll_t *head)
{
	ll_t *node = head;
	
	while(node != NULL)
	{
		printf("%d", node->val);
		node = node->next;
	}
	printf("\n");
	
	return;
}
	
ll_t *add_nums(ll_t *x, ll_t *y)
{
	ll_t *tmp1 = x, *tmp2 = y;
	
	ll_t *head, *node, *prev, *further=NULL;
	int first = 1;
	int ovflow = 0;
	
	while(tmp1 && tmp2)
	{
		int sum;
		
		sum = tmp1->val + tmp2->val + ovflow;
		if (sum>9)
		{
			ovflow = 1;
			sum -= 10;
		}
		else
			ovflow = 0;
		
		node = (ll_t *)calloc(1, sizeof(ll_t));
		node->val = sum;
		
		if(first)
		{
			head = node;
			first = 0;
		}
		else
			prev->next = node;
		
		prev = node;
		
		tmp1 = tmp1->next;
		tmp2 = tmp2->next;
		
		if(tmp1)
			further = tmp1;
		else
			further = tmp2;
	}		
	
	while(further)
	{
		int sum;
		
		sum = further->val + ovflow;
		if (sum>9)
		{
			ovflow = 1;
			sum -= 10;
		}
		else
			ovflow = 0;
		
		node = (ll_t *)calloc(1, sizeof(ll_t));
		node->val = sum;
		
		
		prev->next = node;
		prev = node;
		further = further->next;
	}
	
	if (ovflow==1)
	{
		node = (ll_t *)calloc(1, sizeof(ll_t));
		node->val = ovflow;
		prev->next = node;
	}
		
	return head;
}	
int main()
{
	ll_t *node1, *node2, *ans;
	
	node1 = create_number(170009);
	node2 = create_number(443);
	
	print_list(node1); 
	print_list(node2);
	
	ans = add_nums(node1, node2);
	print_list(ans);
	
	node1 = create_number(9999999);
	node2 = create_number(9999);
	
	print_list(node1); 
	print_list(node2);
	
	ans = add_nums(node1, node2);
	print_list(ans);
	
	return 0;
}