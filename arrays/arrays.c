#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char lookup(char *str, int index)
{
	return str[index];
}

char *push(char *str, char item)
{
	int i;
	int len = strlen(str);
	
	char *new = (char *)calloc((len+1),sizeof(char));
	for (i=0;i<len;i++)
		new[i] = str[i];
	new[i] = item;
	
	return new;
}

char pop(char *str)
{
	int len = strlen(str);
	char item = str[len-1];
	
	str[len-1] = '\0';

	return item;
}

char *insert(char *str, int index, char item)
{
	int i;
	int len = strlen(str);
	
	char *new = (char *)calloc((len+1), sizeof(char));
	for (i=0;i<index;i++)
		new[i] = str[i];
	new[index] = item;
	for (i=index;i<len;i++)
		new[i+1] = str[i];
	new[len+1] = '\0';
	
	return new;
}

void delete(char *str, int index)
{
	int i;
	int len = strlen(str);
	
	for(i=index; i<len; i++)
		str[i] = str[i+1];
	str[len-1] = '\0';
	
	return;	
}

int main()
{
	char str[] = "Hello there!";
	
	int index;
	char item;
	char *new;
	
	index = 4;
	printf("String: %s, lookup of %d: '%c'\n", str, index, lookup(str, index));
	
	item = 2;
	new = push(str, item);
	printf("String: %s, pushed '%c', after push: %s\n", str, item, new);
	free(new);
	
	printf("String: %s, ", str);
	item = pop(str);
	printf("pop'd '%c', after pop: %s\n", item, str);
	
	printf("String: %s, ", str);
	index = 2; item = 'z';
	new = insert(str, index, item);
	printf("inserted '%c' at %d, after insert: %s\n", item, index, new);
	free(new);
	
	printf("String: %s, ", str);
	index = 4;
	delete(str, index);
	printf("delete at index %d, after delete: %s\n", index, str);
	
	return 0;
}