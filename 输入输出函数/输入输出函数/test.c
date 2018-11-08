#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int a = 0;
	int b = 0;
	printf("请输入a和b的值");
	scanf("%d%d", &a, &b);
	printf("%d+%d=%d", a, b, a + b);
	return 0;
}