#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SWAP(a,b)	do { (a) = (a)+(b); \
						 (b) = (a)-(b); \
						 (a) = (a)-(b); \
					   } while(0)
				   
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

void reverse(char *str)
{
	int i;
	int len = strlen(str);
	char tmp;
	
	for (i=0;i<len/2;i++)
		SWAP(str[i], str[len-1-i]);
	
	return;
}

// merge sorted arrays
char *merge_sorted(char *str1, char *str2)
{
	int i, cnt=0;
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	
	char *new = (char *)calloc((len1+len2-1), sizeof(char));
	new[len1+len2] = '\0';
	char *tmp = new;
	
	char *src1 = str1;
	char *src2 = str2;
		
	while (1)
	{
		if (!*src1 || !*src2)
			break;
		if (*src1 < *src2)
			*tmp++ = *src1++;
		else 
			*tmp++ = *src2++;
		cnt++;
	}
	//printf("%s, %s, 1[%s], 2[%s] new[%s]\n", str1, str2, src1, src2, new);
	//printf("len1[%d], len2[%d], cnt[%d]\n", len1, len2, cnt);
	for (i=cnt;i<(len1+len2);i++)
	{
		if (*src1)
			*tmp++ = *src1++;
		else
			*tmp++ = *src2++;
	}
	
	return new;
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
	printf("String: %s, pushed '%c', ((new string)) after push: %s\n", str, item, new);
	free(new);
	
	printf("String: %s, ", str);
	item = pop(str);
	printf("pop'd '%c', after pop: %s\n", item, str);
	
	printf("String: %s, ", str);
	index = 2; item = 'z';
	new = insert(str, index, item);
	printf("inserted '%c' at %d, ((new string)) after insert: %s\n", item, index, new);
	free(new);
	
	printf("String: %s, ", str);
	index = 4;
	delete(str, index);
	printf("delete at index %d, after delete: %s\n", index, str);
	
	printf("String: %s, ", str);
	reverse(str);
	printf("reversed: %s\n", str);

	char str1[] = "0234789";
	char str2[] = "01234569";
	printf("Merge of %s and %s: %s\n", str1, str2, merge_sorted(str1, str2));
	printf("Merge of %s and %s: %s\n", str2, str1, merge_sorted(str1, str2));
	free(new);

	char str3[] = "01";
	char str4[] = "12";
	printf("Merge of %s and %s: %s\n", str3, str4, merge_sorted(str3, str4));
	printf("Merge of %s and %s: %s\n", str4, str3, merge_sorted(str4, str3));
	free(new);
	
	char str5[] = "0";
	char str6[] = "0";
	printf("Merge of %s and %s: %s\n", str5, str6, merge_sorted(str5, str6));
	free(new);
	
	return 0;
}