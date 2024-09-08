#include <stdio.h>


int* twoSum(int*, int, int);


int main(int argc, int* argv[])
{
	int nums[]			= { 2, 7, 11, 15 };
	int target			= 13;

	int* nums_result	= twoSum(nums, sizeof(nums) / sizeof(*nums), target) ;

	printf("%d\n", *nums_result);
	printf("%d\n", *(nums_result + 1));

	return 0;    
}


int* twoSum(int* nums, int numsSize, int target) {
	int sum;
	static int output[2];

	for (size_t i = 0; i < numsSize; i++)
	{
		for (size_t j = i + 1; j < numsSize; j++) {
			sum = *(nums + i) + *(nums + j);

			if (sum == target) {
				*output			= i;
				*(output + 1)	= j;
			}
		}
	}
	return output;
}