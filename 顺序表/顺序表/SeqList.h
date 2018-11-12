#ifndef __SEQLIST_H__ 
#define __SEQLIST_H__ 

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//#define MAX 1000
#define Increase 10
//
typedef int DataType;
typedef struct SeqList
{
	DataType *data;//数据区 
	int sz;//有效个数 
	int capacity;//容量 
}SeqList, *pSeqList;

////静态顺序表 
//typedef int DataType;
//typedef struct SeqList 
//{ 
// DataType data[MAX]; 
// int sz;//表示当前顺序表有效数据的个数 
//}SeqList, *pSeqList; 

void InitSeqList(pSeqList ps);
void DestroySeqList(pSeqList ps);
void PushBack(pSeqList ps, DataType d);
void PrintSeqList(const pSeqList ps);
void PopBack(pSeqList ps);
void PushFront(pSeqList ps, DataType d);
void PopFront(pSeqList ps);
void Insert(pSeqList ps, int pos, DataType d);
void Erase(pSeqList ps, int pos);
void Sort(pSeqList ps);
int BinarySearch(pSeqList ps, DataType d);
int Find(pSeqList ps, DataType d);
void Remove(pSeqList ps, DataType d);
// RemoveAll(); 
#endif //__SEQLIST_H__ 