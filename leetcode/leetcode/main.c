#include"test.h"
int main()
{
	int nums[] = { 2,7,11,15 };
	int numsSize = sizeof(nums) / sizeof(int);
	int target = 35;
	int *a=twoSum(nums, numsSize, target);
	printf("%d,%d", a[0], a[1]);
	return 0;
}