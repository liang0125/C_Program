#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<stdlib.h>
typedef int Datatype;
typedef struct Seqlist
{
	int *data;
	int size;
	int capacity;
}Seq,*pSeq;
Seq seq;
void Init(pSeq seq)
{
	seq->size = 0;
	seq->capacity = 6;
	seq->data = (int *)malloc(sizeof(int));
}
void Print(pSeq seq)
{
	int i = 0;
	for (i = 0; i < seq->size; i++)
	{
		printf("%d ", seq->data[i]);
	}
	printf("\n");
}
void Expand(pSeq seq)
{
	if(seq->size<seq->capacity)
	{
		return;
	}
	else
	{
		int newcapacity = seq->capacity * 2;
		int *newdata= (int *)malloc(sizeof(int));
		seq->capacity = newcapacity;
		int i = 0;
		for (i = 0; i < seq->size; i++)
		{
			newdata[i] = seq->data[i];
		}
		free(seq->data);

	}
}
void Front(pSeq seq,Datatype data)
{
	Expand(&seq);
	int i = 0;
	for (i = seq->size;i>0;i--)
	{
		seq->data[i] = seq->data[i - 1];
	}
	seq->data[0] = data;
	seq->size++;
}
void test()
{
	Init(&seq);
	Front(&seq, 1);
	Front(&seq, 2);
	Front(&seq, 3);
	Front(&seq, 4);
	Front(&seq, 5);
	Front(&seq, 6);
	Front(&seq, 7);

	Print(&seq);

}