/*
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.
*/

#include <stdio.h>

#define SWAP(a,b)		do { (a) = (a) + (b); \
							 (b) = (a) - (b); \
							 (a) = (a) - (b); \
						   } while(0)
							   
void move_zeroes(int *nums, int size)
{
	int i, j;
	
	if (size<2)
		return;
	
	for (i=0;i<size;i++)
	{
		//printf("i[%d]:\t ", i);
		//for (j=0;j<size;j++)
		//	printf("%d\t", nums[j]);
		//printf("\n");
		
		if (nums[i]==0)
		{
			if (nums[i+1]==0)
				SWAP(nums[i], nums[i+2]);
			else 
				SWAP(nums[i], nums[i+1]);
		}
	}
	return;
}

void compute(int *nums, int size)
{
	int i;
	
	for (i=0;i<size;i++)
		printf("%d\t", nums[i]);
	printf("\n");
	
	move_zeroes(nums, size);
	
	for (i=0;i<size;i++)
		printf("%d\t", nums[i]);
	printf("\n\n");
	
	return;
}

int main()
{
	int nums1[] = {0,1,0,3,12};
	int nums2[] = {0};
	
	int size;
	
	size = sizeof(nums1) / sizeof(nums1[0]);
	compute(nums1, size);
	
	size = sizeof(nums2) / sizeof(nums2[0]);
	compute(nums2, size);
	
	return 0;
}
	
	