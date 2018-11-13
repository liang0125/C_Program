//逆置/反转单链表
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int Datatype;
typedef struct Node{
	int data;
	struct Node *next;
}Node;
Node *list;
void ListInit(Node **list)
{
	assert(list);
	*list = NULL;
}
Node *CreatNode(Datatype data)
{
	Node *node = (Node *)malloc(sizeof(Node));
	if (node == NULL)
	{
		return NULL;
	}
	node->data = data;
	node->next = NULL;
	return node;
}
void PushBack(Node **list, Datatype data)
{
	Node *newnode = CreatNode(data);
	assert(list);
	Node *cur = *list;
	if (*list == NULL)
	{
		*list = newnode;
		return;
	}
	while (cur->next != NULL)
	{
		cur = cur->next;
	}
	cur->next = newnode;
}
PrintList(Node **list)
{
	Node *cur = *list;
	while (cur != NULL)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}
void Reserve(Node **list)
{
	assert(list);
	Node *cur = *list;
	Node *new = NULL;
	Node *next  = cur->next;
	while (cur != NULL)
	{
		cur->next = new;
		new = cur;
		cur = next;
		if (next != NULL)
		{
			next = next->next;
		}
	}
	PrintList(&new);
}
void test1()
{
	ListInit(&list);
	PushBack(&list, 1);
	PushBack(&list, 2);
	PushBack(&list, 3);
	PushBack(&list, 4);
	PushBack(&list, 5);
	PushBack(&list, 6);
	PrintList(&list);
	Reserve(&list);


}
