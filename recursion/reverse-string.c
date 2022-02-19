#include <stdio.h>
#include <string.h>

void swap(char *x, char *y)
{
	char t;
	
	if (x==y)
		return;
	
	char *tmp = &t;
	
	*tmp = *x;
	*x = *y;
	*y = *tmp;
	
	return;
}

int i=0;
int string_size=0;
void reverse_string_recursive(char *str, int size)
{
	if (i==0)
		string_size = size;
	if (i==string_size/2)
		return;
	//printf("i[%d], size[%d], str[%c] str-end[%c]\n", i, size, *str, *(str+size-i-1));
	swap(str, str+size-i-1);	
	//printf("str changed: %s\n", str);
	i++;
	reverse_string_recursive(str+1, size-1);
	
	return;
}

void reverse_string_iterative(char *str, int size)
{
	int i;
	char *tmp = str;
	
	for (i=0;i<size/2;i++)
		swap(&str[i],&str[size-i-1]);

	return;
}

int main()
{
	char str[] = "Hello there!\n It's\t such ";
	
	printf("Original string: '%s'\n", str);
	fflush(NULL);
	reverse_string_recursive(str, strlen(str));
	printf("Reversed REC: '%s'\n", str);
	fflush(NULL);
	reverse_string_iterative(str, strlen(str));
	printf("Re-reversed ITER: '%s'\n", str);
	fflush(NULL);

	return 0;
}
