#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
//4.模拟实现strcat
//char *my_strcat(char *dest, const char *src)
//{
//	assert(dest&&src);
//	while (*dest)
//	{
//		dest++;
//	}
//	while (*dest++ = *src++)
//	{
//		;
//	}
//	return dest;
//}
//int main()
//{
//	char arr[20] = "Hello ";
//	my_strcat(arr, "World");
//	printf("%s\n", arr);
//	return 0;
//}
//3.模拟实现strcpy 
//char *my_strcpy(char *dest, const char *src)
//{
//	assert(dest&&src);
//	while(*dest++=*src++)
//	{
//		;
//	}
//	return dest;
//}
//int main()
//{
//	char arr[20] = { 0 };
//	my_strcpy(arr, "Hello world");
//	printf("%s\n", arr);
//	return 0;
//}
//2.喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，给20元，可以多少汽水。编程实现。 
//int main()
//{
//	int n = 20;
//	int sum = n;
//	while (n > 1)
//	{
//		sum = sum + n / 2;
//		n = n / 2 + n % 2;
//	}
//	printf("%d\n", sum);
//	return 0;
//}
//1.一个数组中只有两个数字是出现一次，其他所有数字都出现了两次。 
//找出这两个数字，编程实现。
//12312345
//11223345
//void sort(int arr[], int sz)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < sz; i++)
//	{
//		for (j = 0; j < sz - 1 - i; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//			}
//		}
//	}
//}
//void Print(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d", arr[i]);
//	}
//	printf("\n");
//}
//void Find(int arr[], int sz)
//{
//	int i = 0;
//	while (i < sz)
//	{
//		if (arr[i] == arr[i + 1])
//		{
//			i=i + 2;
//		}
//		else
//		{
//			printf("%d ", arr[i]);
//			i++;
//		}
//		
//	}
//	
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,1,2,3,4,5,6};
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	sort(arr, sz);
//	printf("排序之后的数组\n");
//	Print(arr, sz);
//	printf("以下两个数只出现一次\n");
//	Find(arr, sz);
//	return 0;
//}