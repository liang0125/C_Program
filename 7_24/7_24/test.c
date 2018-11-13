#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//1.调整数组使奇数全部都位于偶数前面。
//
//题目：
//
//输入一个整数数组，实现一个函数，来调整该数组中数字的顺序使得数组中所有的奇数位于数组的前半部分，所有偶数位于数组的后半部分。

void Swap(int arr[], int length)
{
	int i = 0;
	int j = length - 1;
	int tmp = 0;
	while (i<j)
	{
		while (arr[i] % 2 != 0)
			i++;
		while (arr[j] % 2 == 0)
			j--;
		if (i<j)
		{
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
		}
	}
}
int main()//1 9 3 7 5 6 4 8 2
{
	int arr[] = { 1,2,3,4,5,6,7,8,9 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	Swap(arr, sz);
	for (int a = 0; a<sz; a++)
		printf("%d ", arr[a]);
	printf("\n");
	return 0;
}
//2.

//杨氏矩阵 
//有一个二维数组.
//数组的每行从左到右是递增的，每列从上到下是递增的.
//在这样的数组中查找一个数字是否存在。
//时间复杂度小于O(N);
#define ROW 3
#define COL 3

int judge(int arr[ROW][COL], int value)
{
	int l = 0;
	int h = COL-1;
	while (l<ROW&&h>=0)
	{
		if (value < arr[l][h])
		{
			h--;
			
		}
		else if (value > arr[l][h])
		{
			l++;

			
		}
		else if (value == arr[l][h])
		{
			return 1;
		}
	}
	return 0;
}
int main()
{

	int arr[ROW][COL] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int i = 0;
	int j = 0;
	int value = 0;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			printf("%d ", arr[i][j]);
		}

		printf("\n");
	}
	printf("请输入要查找的数字:");
	scanf("%d", &value);

	if (judge(arr, value))
	{
		printf("%d找到了\n", value);
	}
	else
	{
		printf("%d没找到\n", value);
	}
	return 0;
}