#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>


//2.判断一个字符串是否为另外一个字符串旋转之后的字符串。 
//例如：给定s1 ＝ AABCD和s2 = BCDAA，返回1，给定s1 = abcd和s2 = ACBD，返回0.
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
//	printf("s2是s1旋转得到的\n");
//	else   printf("s2不是s1旋转得到的\n");*/
//	printf("%d\n", ret);
//	return 0;
//}
//1.实现一个函数，可以左旋字符串中的k个字符。 
//ABCD左旋一个字符得到BCDA
//ABCD左旋两个字符得到CDAB
//void reverse(char *left, char *right)     //翻转函数
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
//	int len = strlen(p);   //求字符串长度
//	if (k > len)
//		k = k % len;
//	if (k <= len)
//	{
//		reverse(p, p + k - 1);        //前n个字符串逆序翻转
//		reverse(p + k, p + len - 1);    //n+1之后的字符进行翻转
//		reverse(p, p + len - 1);//整个字符串逆序翻转
//	}    
//
//
//}
//
//int main()
//{
//	int k = 0;
//	char arr[] = "ABCD";
//	printf("请输入左旋字符的个数:\n");
//	scanf("%d", &k);
//	left_move(arr,k);
//	printf("%s\n", arr);
//	return 0;
//}