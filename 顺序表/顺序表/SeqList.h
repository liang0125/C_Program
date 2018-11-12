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
	DataType *data;//������ 
	int sz;//��Ч���� 
	int capacity;//���� 
}SeqList, *pSeqList;

////��̬˳��� 
//typedef int DataType;
//typedef struct SeqList 
//{ 
// DataType data[MAX]; 
// int sz;//��ʾ��ǰ˳�����Ч���ݵĸ��� 
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