#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdarg.h>
#include<stdlib.h>
#include<string.h>
//2.дð����������������ַ�����
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
//1.ʹ��main�����Ĳ�����ʵ��һ��������������������Խ�����������
//��һ��������-a��ѡ��ִ�мӷ�����-s��ѡ��ִ�м�������-m��ѡ��ִ�г˷�����-d��ѡ��ִ�г�����������������Ϊ�������� 
//���磺�����в������룺test.exe - a 1 2
//ִ��1 + 2���3
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
//			printf("�ڶ���������������\n");
//			break;
//		}
//	}
//	va_end (arg);
//	printf("%d\n", ret);
//	return 0;
//}