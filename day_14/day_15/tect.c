#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>


//2.�ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ����� 
//���磺����s1 �� AABCD��s2 = BCDAA������1������s1 = abcd��s2 = ACBD������0.
//int Judge(char s1[],char s2[])
//{
//	int i = 0;
//	int j = 0;
//	int len = strlen(s2);
//	int m = 0;
//	char p = 0;
//	for (i = 0; i < len; i++)
//	{
//		{ p = s2[0];
//		for (j = 0; j < len - 1; j++)
//		{
//			
//			s2[j] = s2[j + 1];
//		}
//		s2[len-1] = p;
//		}
//		if (0 == strcmp(s1, s2))
//		{
//			return 1;
//		}
//	}
//	return 0;
//	
//}
//
//int main()
//{
//	int ret = 0;
//	char s1[] = "AABCD";
//	char s2[] ="DAABC";
//	 ret=Judge(s1, s2);
//	/*if(ret==0)
//	printf("s2��s1��ת�õ���\n");
//	else   printf("s2����s1��ת�õ���\n");*/
//	printf("%d\n", ret);
//	return 0;
//}
//1.ʵ��һ�����������������ַ����е�k���ַ��� 
//ABCD����һ���ַ��õ�BCDA
//ABCD���������ַ��õ�CDAB
//void reverse(char *left, char *right)     //��ת����
//
//{
//
//	while (left < right)
//	{
//		char tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//	}
//}
//
//void left_move(char *p, int k)
//
//{
//
//	int len = strlen(p);   //���ַ�������
//	if (k > len)
//		k = k % len;
//	if (k <= len)
//	{
//		reverse(p, p + k - 1);        //ǰn���ַ�������ת
//		reverse(p + k, p + len - 1);    //n+1֮����ַ����з�ת
//		reverse(p, p + len - 1);//�����ַ�������ת
//	}    
//
//
//}
//
//int main()
//{
//	int k = 0;
//	char arr[] = "ABCD";
//	printf("�����������ַ��ĸ���:\n");
//	scanf("%d", &k);
//	left_move(arr,k);
//	printf("%s\n", arr);
//	return 0;
//}