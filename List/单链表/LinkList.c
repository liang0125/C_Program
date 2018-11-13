#define _CRT_SECURE_NO_WARNINGS 1
#include"LinkList.h"
Node *list1;
Node *list2;
// 初始化
void InitLinkList(Node **pplist)
{ 
	assert(pplist);
	pplist = NULL;
}
// 销毁 
void DestroyLinkList(Node **pplist)
{
	assert(pplist);
	Node *cur=*pplist;
	Node *next;
	while (cur!= NULL)
	{
		next = cur->next;
		free(cur);
		cur=next;
	}
}
//创建结点
static Node*  CreateNode(DataType data)
{
	Node *newnode = (Node*)malloc(sizeof(Node));
	if (newnode == NULL)
	{
		perror("CreateNode::malloc");
		return NULL;
	}
	newnode->data = data;
	newnode->next = NULL;
	return newnode;
}
void PrintLinkList(Node **pplist)
{
	Node *cur = *pplist;
	while (cur)
	{
		printf("%d-->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}
// 尾部插入 
void ListPushBack(Node **pplist, DataType data)
{
	Node *node = CreateNode(data);//先创建结点
	assert(pplist);
	if (*pplist == NULL)
	{
		*pplist = node;
		return;
	}
		//找到最后一个结点
		Node *cur = *pplist;
		while (cur->next!=	NULL)
		{
			cur = cur->next;
		}
		cur->next = node;
}
//头部插入 
void ListPushFront(Node **pplist, DataType data)
{
	assert(pplist);
	Node *newnode = CreateNode(data);
	newnode->next = *pplist;
	*pplist = newnode;
}
//尾部删除
void ListPopBack(Node **pplist)
{
	assert(pplist);
	if ((*pplist)->next == NULL)
	{
		free(*pplist);
		*pplist = NULL;
		return;
	}
	else //至少有两个结点，才能找倒数第二个结点
		{
		Node *cur = *pplist;
		while (cur->next->next != NULL)
		{
			cur = cur->next;
		}
		free(cur->next);
		cur->next = NULL;
	}
}
// 头部删除 
void ListPopFront(Node **pplist)
{
	assert(pplist);
	assert(*pplist);//链表不是空链表
	Node *cur = *pplist;
	*pplist = cur->next;
	free(cur);
	cur = NULL;
}
// 按值查找，返回第一个找到的结点指针，如果没找到，返回 NULL 
Node *ListFind(Node **pplist, DataType data)
{
	assert(pplist);
	Node *cur = *pplist;
	while (cur->next != NULL)
	{
		if (cur->data == data)
		{
			return cur;
		}
		else
		{
			cur = cur->next;
		}
	}
	return NULL;
}
// 给定结点插入，插入到结点前 
void ListInsert(Node **pplist, Node *pos, DataType data)
{
	assert(pplist);
	if (pos == *pplist)
	{
		ListPushFront(pplist, data);
		return;
	}
	else
	{
		Node *newnode = CreateNode(data);//创建结点
		Node *cur = *pplist;
		while (cur->next != pos)
		{
			cur = cur->next;
		}
		newnode->next = pos;
		cur->next = newnode;
	}
}
// 给定结点删除 
void ListErase(Node **pplist, Node *pos)
{
	assert(pplist);
	if (pos == *pplist)
	{
		ListPopFront(pplist);
		return;
	}
	else
	{
		Node* cur = *pplist;
		while (cur->next != pos)
		{
			cur = cur->next;
		}
		cur->next = pos->next;
		free(pos);
	}
}
// 按值删除，只删遇到的第一个 
void ListRemove(Node **pplist, DataType data)
{
	assert(pplist);
	Node *p = ListFind(pplist,data);
	ListErase(pplist, p);
}
Node *Crossing(Node *list1, Node *list2)
{//求交点
	int length1 = GetLength(list1);
	int length2 = GetLength(list2);
	Node *longlist = list1;
	Node *shortlist = list2;
	int diff = length1 - length2;//两条链表的长度差
	if (length1<length2)
	{
		longlist = list2;
		shortlist = list1;
		diff = length2 - length1;
	}
	//让长链表先走，走到和短链表一样长
	while (diff--)
	{
		longlist = longlist->next;
	}
	//此时两条链表一样长，再让两条链表同时走
	//如果两条链表的结点相等则有交点
	//如果走完还无交点则无交点
	while (1)
	{
		if (longlist == shortlist)
		{
			return longlist;
		}
		longlist = longlist->next;
		shortlist = shortlist->next;
	}
	return NULL;

}
// 按值删除，删除所有的 
void ListRemoveAll(Node **pplist, DataType data)
{
	assert(pplist);
	Node *cur = *pplist;
	Node *pre = *pplist;
	while (cur != NULL)
	{
		if (data == cur->data)
		{
			Node *del = cur;
			cur = cur->next;
			if (del == *pplist)
			{
				ListPopFront(pplist);
			}
			else if (del->next == NULL)
			{
				ListPopBack(pplist);
			}
			else
			{
				pre->next = del->next;
				free(del);
			}
		}
		else
		{
			pre = cur;
			cur = cur->next;
		}
	}
}
Node *IsCircleList(Node *list)
{
	Node *fast = list;
	Node *slow = list;
	if (list == NULL || list->next == NULL)
	{
		return NULL;
	}
	while (fast&&fast->next)
	{
		fast = fast->next->next;//快指针一次走两步
		slow = slow->next;//慢指针一次走一步
	}
	if (fast == slow)
	{
		return fast;//如果相等，返回相遇点
	}
}
int GetCircleLen(Node *list)
{
	Node *p = IsCircleList(list);
	int count = 0;
	if (p != NULL)//带环
	{
		while (p->next != p)
		{
			count++;
			p = p->next;
		}
		count++;//加上最后一个结点
	}
	return count;
}
Node *EnterNode(Node *list)
{
	Node *node = IsCircleList(list);
	Node *first = list;
	if (node != NULL)//带环
	{
		while (node != first)
		{
			node = node->next;
			first = first->next;
		}
	}
	return node;
}
Node *CircleMeetNode(Node *list1, Node *list2)
{
	Node *m1=IsCircleList(list1);//若带环，返回相遇点
	Node *m2 = IsCircleList(list2);
	Node *p1 = EnterNode(list1);//返回环的入口点
	Node *p2 = EnterNode(list2);
	Node *entryNext1 = p1->next;//保存入口点的next，为恢复环做准备
	Node *entryNext2 = p2->next;
	Node *meet = NULL;
	Node *cur = m1->next;


	if (m1 == NULL && m2 == NULL)
	{//两个都不带环，转换为两个链表相交问题
		return Crossing(list1, list2);
	}
	else if (m1&&m2)//两个都带环，分三种情况
	{
		while (cur != m1 && cur != m2)//1.两个不相交
		{
			cur = cur->next;
		}
		if (cur == m1)
		{
			return NULL;
		}
		else
		{
			if (p1 == p2)//2.入口点相等，相交在环外
			{
				p1->next = NULL;//断开环转化成Y型求交点问题
				p2->next = NULL;
				meet=Crossing(list1, list2);
				p1->next = entryNext1;//恢复环
				p2->next = entryNext2;
				return meet;
			}
			else//?
			{//3.入口点不相等
				return p2;
			}

		}
	}
	else//一个带环，一个不带环
	{
		return NULL;
	}
}