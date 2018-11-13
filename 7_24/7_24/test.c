#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//1.��������ʹ����ȫ����λ��ż��ǰ�档
//
//��Ŀ��
//
//����һ���������飬ʵ��һ�������������������������ֵ�˳��ʹ�����������е�����λ�������ǰ�벿�֣�����ż��λ������ĺ�벿�֡�

void Swap(int arr[], int length)
{
	int i = 0;
	int j = length - 1;
	int tmp = 0;
	while (i<j)
	{
		while (arr[i] % 2 != 0)
			i++;
		while (arr[j] % 2 == 0)
			j--;
		if (i<j)
		{
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
		}
	}
}
int main()//1 9 3 7 5 6 4 8 2
{
	int arr[] = { 1,2,3,4,5,6,7,8,9 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	Swap(arr, sz);
	for (int a = 0; a<sz; a++)
		printf("%d ", arr[a]);
	printf("\n");
	return 0;
}
//2.

//���Ͼ��� 
//��һ����ά����.
//�����ÿ�д������ǵ����ģ�ÿ�д��ϵ����ǵ�����.
//�������������в���һ�������Ƿ���ڡ�
//ʱ�临�Ӷ�С��O(N);
#define ROW 3
#define COL 3

int judge(int arr[ROW][COL], int value)
{
	int l = 0;
	int h = COL-1;
	while (l<ROW&&h>=0)
	{
		if (value < arr[l][h])
		{
			h--;
			
		}
		else if (value > arr[l][h])
		{
			l++;

			
		}
		else if (value == arr[l][h])
		{
			return 1;
		}
	}
	return 0;
}
int main()
{

	int arr[ROW][COL] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int i = 0;
	int j = 0;
	int value = 0;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			printf("%d ", arr[i][j]);
		}

		printf("\n");
	}
	printf("������Ҫ���ҵ�����:");
	scanf("%d", &value);

	if (judge(arr, value))
	{
		printf("%d�ҵ���\n", value);
	}
	else
	{
		printf("%dû�ҵ�\n", value);
	}
	return 0;
}