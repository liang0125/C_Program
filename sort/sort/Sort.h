#pragma once
#include<stdio.h>
#include<malloc.h>
//插入排序
void InsertSort(int array[], int size)
{
	int key;
	int i, j;
	for (i = 1; i < size; i++)
	{
		key = array[i];
		for (j = i - 1; j >= 0; j--)
		{
			if (key >= array[j])
			{
				break;
			}
			else {
				array[j + 1] = array[j];
			}
		}
		array[j+1] = key;
	}
}
void _InsertSort(int array[], int size, int gap)
{
	for (int g = 0; g < gap; g++)
	{
		int key;
		int i, j;
		for (i = gap + g; i < size; i+=gap) {
			key = array[i];
			for (j = i - gap; j >= 0; j -= gap) {
				if (key >= array[j]) {
					break;
				}
				else {
					array[j + gap] = array[j];
				}
			}
			array[j + gap] = key;
		}
		
	}
}
void ShellSort(int array[], int size)
{
	int gap = size;
	while (1) {
		gap = gap / 3 + 1;
		_InsertSort(array, size, gap);
		if (gap == 1)
		{
			break;
		}
	}
}
void Swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
void SelectSort(int array[], int size)
{
	for (int i = size; i >1; i--)
	{
		int max = 0;
		for (int j = 1; j < i; j++)
		{
			if (array[j] > array[max]) {
				max = j;
			}
		}
		Swap(array + max, array + i - 1);
	}
}
void SelectSort1(int array[], int size)
{
	int left = 0;
	int right = size - 1;
	while (left < right)
	{
		int min = left;
		int max = left;
		for (int j = left + 1; j <= right; j++)
		{
			if (array[j] > array[max])
			{
				max = j;
			}
			if (array[j] < array[min])
			{
				min = j;
			}
		}
		Swap(array + left, array + min);
		if (max == left)
		{
			max = min;
		}
		Swap(array + right, array + max);
		left++;
		right--;
	}
}
void Print(int array[],int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}
}
void AdjustDown(int array[], int size, int root)
{
	int left = 2 * root + 1;
	int right = 2 * root + 2;
	if (left >= size)
	{
		return;
	}
	int max = left;
	if (right<size&&array[right]>array[left])
	{
		max = right;
	}
	if (array[root] >= array[max])
	{
		return;
	}
	Swap(array + root, array + max);
	AdjustDown(array, size, max);
}
void CreateHeap(int array[], int size)
{
	//从最后一个非叶子结点到0
	//不断的进行向下调整
	for (int i = size / 2 - 1; i >= 0; i--)
	{
		AdjustDown(array, size, i);
	}
}
void HeapSort(int array[], int size)
{
	CreateHeap(array, size);
	for (int i = 0; i < size; i++)
	{
		Swap(array, array + (size - i - 1));
		AdjustDown(array,size-i-1,0);
	}
}
void BubbleSort(int array[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		int flag = 1;
		for (int j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				Swap(array + j, array + j + 1);
				flag = 0;
			}
		}
		if (flag == 1)
		{
			break;
		}
	}
}
int Partition_01(int array[], int left, int right)
{
	int begin = left;
	int end = right;
	while (begin < end)
	{
		while (begin < end&&array[begin] <= array[right])
		{
			begin++;
		}
		while (begin < end&&array[end] >= array[right])
		{
			end--;
		}
		Swap(array + begin, array + end);
	}
	Swap(array + begin, array + right);
	return begin;
}
int Partition_02(int array[], int left, int right)
{
	int begin = left;
	int end = right;
	int priot = array[right];
	while (begin < end)
	{
		while (begin < end&&array[begin] <= priot)
		{
			begin++;
		}
		array[end] = array[begin];
		while (begin < end&&array[end] >= priot)
		{
			end--;
		}
		array[begin] = array[end];
	}
	array[begin] = priot;
	return begin;
}

int Partition_03(int array[], int left, int right)
{
	int fast = left;
	int slow = left;
	while (fast<right)
	{
		if (array[fast] < array[right])
		{
			Swap(array + fast, array + slow);
			slow++;
			fast++;
		}
		else {
			fast++;
		}
	}
	Swap(array + right, array + slow);
	return slow;
}
void _QuickSort(int array[],int left,int right)
{
	if (left == right)
	{
		return;
	}
	if (left > right)
	{
		return;
	}
	int div = Partition_03(array, left, right);
	_QuickSort(array, left, div - 1);
	_QuickSort(array, div + 1, right);
}
void QuickSort(int array[], int size)
{
	_QuickSort(array, 0, size - 1);
}
void Merge(int array[], int left,int mid, int right,int a[])
{
	int left_i = left;
	int right_i = mid + 1;
	int k = left;
	while (left_i <= mid && right_i <= right) {
		if (array[left_i] <=array[right_i])
		{
			a[k++] = array[left_i++];
		}
		else {
			a[k++] = array[right_i++];
		}
	}
	while (left_i <= mid)
	{
		a[k++] = array[left_i++];
	}
	while (right_i <= right)
	{
		a[k++] = array[right_i++];
	}
	for (int i = left; i <= right; i++)
	{
		array[i] = a[i];
	}
}
void _MergeSort(int array[], int left, int right,int a[])
{//分组函数
	if (left == right)
	{
		return;//区间长度为1
	}
	if (left > right)
	{
		return ;//区间长度为0
	}
	int mid = left + (right - left) / 2;
	_MergeSort(array, left, mid, a);
	_MergeSort(array, mid + 1, right, a);
	Merge(array, left, mid, right, a);

}

void MergeSortLoop(int array[],int size ) {
	int*extra = (int *)malloc(sizeof(int)*size);//用于存放合并后的数组
	for (int i = 1; i < size; i *= 2)
	{
		for (int j = 0; j < size; j = j + 2 * i)
		{
			int left = j;
			int mid = j + i;
			int right = mid + i;
			if (mid >= size) {
				continue;
			}
			if (right > size) {
				right = size;
			}
			Merge(array, left,mid-1, right-1, extra);
		}
	}
	free(extra);
}

void MergeSort(int array[], int size)
{//接口函数
	int*a = (int *)malloc(sizeof(int)*size);//用于存放合并后的数组
	_MergeSort(array, 0, size - 1, a);
	free(a);
}
void test()
{
	int array[] = { 3,5,1,4,7,2,6,0,9,8,8 };
	int size = sizeof(array) / sizeof(int);
	MergeSortLoop(array, size);
	Print(array,size);
}