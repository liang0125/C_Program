////#define _CRT_SECURE_NO_WARNINGS 1
////#include<stdio.h>
////int main()
////{
////	//struct Stu
////	//{
////	//	char name[20];//姓名
////	//	int age;//年龄
////	//	char sex[5];//性别
////	//	char id[20];//学号
////	//};//这里分号绝对不能丢
////	struct
////	{
////		int a;
////		char b;
////		float c;
////	}x;
////	struct
////	{
////		int a;
////		char b;
////		float c;
////	}a[20],*p;
////	struct S s;
////	strcpy(s.name, "zhangsan");
////	s.age = 20;
////	return 0;
////}
////struct B;
////struct A
////{
////	int _a;
////	struct B* pb;
////};
////struct B
////{
////	int _b;
////	struct A* pa;
////};
////
////
////
////
////struct Point
////{
////	int x;
////	int y;
////}p1;
////struct Point p2;
////
////
////struct Point p3 = { x,y };
////struct Stu
////{
////	char name[15];
////	int age;
////};
////struct Stu s = { "zhangsan",20 };
////
////struct Node
////{
////	int data;
////	struct Point p;
////	struct Node*next;
////}n1 = { 10,{5,6},NULL };
////struct Node n2 = { 20,{5,6},NULL };
////
////
////
////
////struct S1
////{
////	char c1;
////	int i;
////	char c2;
////};
////printf("%d\n", sizeof(struct S1));
//
//
//
//
//
//#include<stdio.h>
//#pragma pack(8)//设置默认对齐数为8
//struct S1
//{
//	char c1;
//	int i;
//	char c2;
//};
//#pragma pack()//取消设置的默认对齐数，还原为默认
//
//#pragma pack(1)//设置默认对齐数为1
//struct S2
//{
//	char c1;
//	int i;
//	char c2;
//};
//#pragma pack()//取消设置的默认对齐数，还原为默认
//int main()
//{
//	printf("%d\n", sizeof(struct S1));
//	printf("%d\n", sizeof(struct S2));
//	return 0;
//}






//struct S
//{
//	int data[1000];
//	int num;
//};
//struct S s = { {1,2,3,4},1000 };
//
//void  print1(struct S s)
//{
//	printf("%d\n", s.num);
//}
//
//void  print2(struct S* ps)
//{
//	printf("%d\n", ps->num);
//}
//int main()
//{
//	print1(s);
//	print2(&s);
//	return 0;
//}
struct A
{
	int _a : 2;
	int _b : 5;
	int _c : 10;
	int _d : 30;
};