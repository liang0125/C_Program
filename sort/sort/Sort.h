#pragma once
#include<stdio.h>
//≤Â»Î≈≈–Ú
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
void test()
{
	int array[] = { 3,5,1,4,7,2,6,0,9,8,8 };
	int size = sizeof(array) / sizeof(int);
	SelectSort1(array, size);
	Print(array,size);
}