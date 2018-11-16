//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
////void print(int(*p)[5], int x, int y)
////{
////	int i = 0;
////	int j = 0;
////	for (i = 0; i < x; i++)
////	{
////		for (j = 0; j < y; j++)
////		{
////			printf("%d ", p[i][j]);
////		}
////		printf("\n");
////	}
////}
////int main()
////{
////	int arr[3][5] = { 1,2,3,4,5,5,4,3,2,1,6,7,8,9,0 };
////	print(arr, 3, 5);
////	return 0;
////}
////int arr[5];
////int *parr1[10];
////int(*parr2)[10];
////int(*parr3[10])[5];
////void test()
////{
////	printf("hehe\n");
////}
////int main()
////{
////	printf("%p\n", &test);
////	printf("%p\n", test);
////	return 0;
////}
//int Add(int x, int y)
//{
//	return x + y;
//}
//int Sub(int x, int y)
//{
//	return x - y;
//}
//int Mul(int x, int y)
//{
//	return x * y;
//}
//int Div(int x, int y)
//{
//	return x / y;
//}
//
//void menu()
//{
//	printf("******************************\n");
//	printf("**     1. add     2. sub    **\n");
//	printf("**     3. mul     4. div    **\n");
//	printf("**          0.exit          **\n");
//	printf("******************************\n");
//}
//void calc(int(*pfun)(int, int))
//{
//	int x = 0;
//	int y = 0;
//	int ret = 0;
//	printf("请输入两个操作数:>");
//	scanf("%d%d", &x, &y);
//	ret = pfun(x, y);
//	printf("ret = %d\n", ret);
//}
////
//int main()
//{
//	int input = 0;
//	int x = 0;
//	int y = 0;
//	int ret = 0;
//
//	//转移表
//	int(*pfun[5])(int, int) = { 0, Add, Sub, Mul, Div };
//
//	do
//	{
//		menu();
//		printf("请选择:>");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			calc(Add);
//			break;
//		case 2:
//			calc(Sub);
//			break;
//		case 3:
//			calc(Mul);
//			break;
//		case 4:
//			calc(Div);
//			break;
//		case 0:
//			printf("退出程序\n");
//			break;
//		default:
//			printf("选择错误\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}
void GetMemory(char *p)
{
	p = (char *)malloc(100);
}

int main()
{
	char *str = NULL;

	return 0;
}