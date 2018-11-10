#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdarg.h>
#include<stdlib.h>
#include<string.h>
//2.写冒泡排序可以排序多个字符串。
//
//void bubble_sort(char(*p)[10])
//{
//	int i = 0;
//	int j = 0;
//	char tmp[10] = {0};
//	char *t = tmp;
//	for (i = 0; i < 3; i++)
//	{
//		for (j = 0; j < 2 - i; j++)
//			if (strcmp(p[j], p[j + 1]) > 0)
//			{
//				strcpy(t, p[j]);
//				strcpy(p[j], p[j + 1]);
//				strcpy(p[j + 1], t);
//			}
//	}
//}
//int main()
//{
//	char arr[3][10] = { "abc","eaf","bcd" };
//	int i = 0;
//	bubble_sort(arr);
//	for(i=0;i<3;i++)
//	{
//		printf("%s ", arr[i]);
//	}
//	return 0;
//}
//1.使用main函数的参数，实现一个整数计算器，程序可以接受三个参数
//第一个参数“-a”选项执行加法，“-s”选项执行减法，“-m”选项执行乘法，“-d”选项执行除法，后面两个参数为操作数。 
//例如：命令行参数输入：test.exe - a 1 2
//执行1 + 2输出3
//int main(int argc,char *argv[])
//{
//	va_list arg;
//	int ret = 0;
//	va_start(arg, argv);
//	if (argv[1][0]=='-')
//	{
//		switch (argv[1][1])
//		{
//		case'a':
//			ret=(atoi(argv[2])) + (atoi(argv[3]));
//			break;
//		case's':
//			ret = (atoi(argv[2])) - (atoi(argv[3]));
//			break;
//		case'm':
//			ret = (atoi(argv[2])) * (atoi(argv[3]));
//			break;
//		case'd':
//			ret = (atoi(argv[2])) / (atoi(argv[3]));
//			break;
//		default:
//			printf("第二个参数输入有误\n");
//			break;
//		}
//	}
//	va_end (arg);
//	printf("%d\n", ret);
//	return 0;
//}