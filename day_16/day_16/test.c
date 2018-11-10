#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
//7.递归方式实现打印一个整数的每一位 
//void  print(int n)
//{
//	if (n > 9)
//	{
//		print(n / 10);
//	}
//	printf("%d ", n % 10);
//}
//int main()
//{
//	int num = 0;
//	printf("请输入数值：\n");
//	scanf("%d", &num);
//	print(num);
//	return 0;
//}
//6.递归和非递归分别实现求n的阶乘 
//①非递归
//int fac(int n)
//{
//	int i = 0;
//	int m = 1;
//	for (i = 1; i <= n; i++)
//	{
//		m = m * i;
//	}
//	return m;
//}
//②递归
//int fac(int n)
//{
//	if (n <= 1)
//		return 1;
//	else 
//	return n*fac(n - 1);
//
//}
//int main()
//{
//	int num = 0;
//	printf("请输入数值：\n");
//	scanf("%d",&num);
//	int p = fac(num);
//	printf("%d\n", p);
//	return 0;
//}
//5.递归和非递归分别实现strlen 
//①非递归
//int my_strlen(const char *arr)
//{
//	int count = 0;
//	assert(arr!=NULL);
//	while (*arr++)
//	{
//		count++;
//	}
//	return count;
//}
//②递归
//int my_strlen(const char *arr)
//{
//	assert(arr != NULL);
//	if (*arr == '\0')
//		return 0;
//	else 
//		return 1 + my_strlen(arr + 1);
//}
//int main()
//{
//	char *arr = "abcdef";
//	int len = my_strlen(arr);
//	printf("%d\n", len);
//	return 0;
//}

//4. 编写一个函数reverse_string(char * string)（递归实现） 
//实现：将参数字符串中的字符反向排列。
//要求：不能使用C函数库中
//的字符串操作函数。
//my_strlen(char *arr)
//{
//	int len = 0;
//	while (*arr++)
//	{
//		len++;
//	}
//	return len;
//}
//char *reverse(char *arr)
//{
//	int len = my_strlen(arr);
//	char *left = arr;
//	char *right = arr + len-1 ;
//	char tmp = 0;
//	if (*arr)
//	{
//		tmp = *left;
//		*left = *right;
//		*right = '\0';
//		reverse(arr + 1);
//		*right = tmp;
//	}
//	
//	return arr;
//}
//int main()
//{
//	char arr[] = "abcdef";
//	char *p= reverse(arr);
//	printf("%s\n", p);
//	return 0;
//}
//3. 写一个递归函数DigitSum(n)，输入一个非负整数，返回组成它的数字之和
//例如，调用DigitSum(1729)，则应该返回1+7+2+9，它的和是19 
//int Add(int n)
//{
//	int sum = 0;
//	if (n > 9)
//	{
//		sum += Add((n / 10));
//	}
//	sum += n % 10;
//	return sum;
//}
//int main()
//{
//	int num = 0;
//	printf("请输入数值：\n");
//	scanf("%d", &num);
//	int ret = Add(num);
//	printf("%d\n", ret);
//	return 0;
//}
//2.编写一个函数实现n^k，使用递归实现 
//int my_power(int n, int k)
//{
//	if (k>0)
//	{
//		return my_power(n, k - 1)*n;
//	}
//	return 1;
//}
//int main()
//{
//	int n = 0;
//	int k = 0;
//	printf("请输入要计算的数及次方\n");
//	scanf("%d%d", &n, &k);
//	int ret = my_power(n, k);
//	printf("%d\n", ret);
//	return 0;
//}
//1.递归和非递归分别实现求第n个斐波那契数。
//①非递归
//int Fib(int k)
//{
//	int a = 1;
//	int b = 1;
//	int c = 0;
//	if (k <= 2)
//		return 1;
//	while (k > 2)
//	{
//		c = a + b;
//		a = b;
//		b = c;
//		k--;
//	}
//	return c;
//}
//②递归
//int Fib(int k)
//{
//	int count = 0;
//	if (k ==3)
//	{
//		count++;
//	}
//	if (k <= 2)
//		return 1;
//	else
//	return Fib(k - 1) + Fib(k + 1);
//}
//int main()
//{
//	int k = 0;
//	printf("请输入要找第几个数：\n");
//	scanf("%d", &k);
//	int ret = Fib(k);
//	printf("%d\n", ret);
//	return 0;
//}