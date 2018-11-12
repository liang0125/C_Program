#include "SeqList.h"
SeqList Seq;
void testPushBack()
{
	PushBack(&Seq, 1);
	PushBack(&Seq, 2);
	PushBack(&Seq, 3);
	PushBack(&Seq, 4);
	PushBack(&Seq, 5);
	PushBack(&Seq, 6);
	PrintSeqList(&Seq);
	//PopBack(&Seq);
	//PrintSeqList(&Seq);
	//PopFront(&Seq);
	//PrintSeqList(&Seq);
	Insert(&Seq, 2, 9);
	PrintSeqList(&Seq);
	//int i=Find(&Seq, 3);
	//printf("%d\n", i);
	//Erase(&Seq, 3);
	//PrintSeqList(&Seq);
	//Remove(&Seq, 2);
	//PrintSeqList(&Seq);
	//Sort(&Seq);
	//PrintSeqList(&Seq);
	/*int j=BinarySearch(&Seq, 4);
	printf("%d\n", j);*/
}
void testPushFront()
{
	PushFront(&Seq, 1);
	PushFront(&Seq, 2);
	PushFront(&Seq, 3);
	PushFront(&Seq, 4);
	PushFront(&Seq, 5);
	PushFront(&Seq, 6);
	PrintSeqList(&Seq);
}
int main()
{
	testPushBack();

	//testPushFront();
	return 0;
}