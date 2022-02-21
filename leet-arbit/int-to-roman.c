#include <stdio.h>

#define	FOUND		(1)
#define NOT_FOUND	(0)

typedef struct romans
{
	int num;
	char roman;
} romans_t;

romans_t refs[] =
{
	{   1, 'I'}, //0
	{   5, 'V'}, //1
	{  10, 'X'}, //2
    {  50, 'L'}, //3
	{ 100, 'C'}, //4
	{ 500, 'D'}, //5
	{1000, 'M'}  //6
};

int main()
{
	int i,j;
	int inp = 1994;
	char ans[100] = {0};
	
	int num = inp;
	char *ans_ptr = ans;
	
	int refs_sz = sizeof(refs) / sizeof(refs[0]);
	
	int chars;
	int rem;
	while(num)
	{
		for(j=0;j<refs_sz;j++)
		{
			if (refs[j].num > num)
				break;
		}
			
		chars = num / refs[j-1].num;				
		
		//printf("num[%d]\tj[%d]\tchars[%d]\t", num, j, chars);
		//fflush(NULL);
		
		if (chars==4)
		{
			*ans_ptr++ = refs[j-1].roman;
			*ans_ptr++ = refs[j].roman;
			num -= chars*refs[j-1].num;
		}
		else if ((num<1000) && (refs[j].num - num) <= refs[j-2].num)
		{
			rem = num - 9*refs[j-2].num;
			//printf("rem[%d]\n", rem);
			*ans_ptr++ = refs[j-2].roman;
			*ans_ptr++ = refs[j].roman;
			num = rem;
		}
		else
		{
			for (i=0;i<chars;i++)
				*ans_ptr++ = refs[j-1].roman;
			num -= chars*refs[j-1].num;
		}
		
		//printf("ans[%s]\n", ans);
		//fflush(NULL);
		
	}
	printf("Roman number for %d is %s\n", inp, ans);
	
	
	
	return 0;
}