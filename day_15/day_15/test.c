#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdarg.h>
//4.1.模拟实现printf函数，可完成下面的功能
//能完成下面函数的调用。 
//print("s ccc d.\n","hello",'b','i','t'，100); 
//函数原型： 
//print(char *format, ...) 
// 
void show(int n)
{
	if (n > 9)
	{//1234
		show(n / 10);
	}
	putchar(n % 10 + '0');
}
my_printf(char *format, ...)
{
	va_list arg;
	va_start(arg,format);
		while (*format)
	{
		switch (*format)
		{
		case 's':
		{
			char * ret = va_arg(arg, char *);
		while (*ret)
		{
			putchar(*ret);
			ret++;
		}
		}break; 
		case 'c':
		{
			int ch = va_arg(arg, char);
		putchar(ch);
		
		}break;
		case 'd':
		{
			int ret = va_arg(arg, int);
			show(ret);
			
		}
			break;
		default:
			putchar(*format);
			break;
		}
		format++;
	}
}
int main()
{
	my_printf("s c d\n", "hello", 'b',100);
	return 0;
}

//3.使用可变参数，实现函数，求函数参数的最大值。
//int Max(int n, ...)
//{
//	int max = 0;
//	va_list arg;
//	int p = 0;
//	va_start(arg, n);
//	max = va_arg(arg, int);
//	int i = 0;
//	for (i = 1; i < n; i++)
//	{
//		p = va_arg(arg, int);
//		if (p > max)
//		{
//			max = p;
//		}
//
//	}
//	va_end(arg);
//
//	return max;
//}
//int main()
//{
//	int a = 2;
//	int b = 4;
//	int c = 6;
//	int max = Max(3, a, b, c);
//	printf("%d\n", max);
//	return 0;
//}
//2.使用可变参数，实现函数，求函数参数的平均值。
//int avg(int n, ...)
//{
//	va_list arg;
//	int i = 0;
//	int sum = 0;
//	va_start(arg, n);
//	for (i = 0; i < n; i++)
//	{
//		sum += va_arg(arg,int);
//	}
//	return sum / n;
//}
//int main()
//{
//	int a = 2;
//	int b = 4;
//	int c = 6;
//	int arg1 = avg(3, a, b, c);
//	printf("%d\n", arg1);
//	return 0;
//}