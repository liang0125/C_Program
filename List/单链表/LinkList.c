#define _CRT_SECURE_NO_WARNINGS 1
#include"LinkList.h"
Node *list1;
Node *list2;
// ��ʼ��
void InitLinkList(Node **pplist)
{ 
	assert(pplist);
	pplist = NULL;
}
// ���� 
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
//�������
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
// β������ 
void ListPushBack(Node **pplist, DataType data)
{
	Node *node = CreateNode(data);//�ȴ������
	assert(pplist);
	if (*pplist == NULL)
	{
		*pplist = node;
		return;
	}
		//�ҵ����һ�����
		Node *cur = *pplist;
		while (cur->next!=	NULL)
		{
			cur = cur->next;
		}
		cur->next = node;
}
//ͷ������ 
void ListPushFront(Node **pplist, DataType data)
{
	assert(pplist);
	Node *newnode = CreateNode(data);
	newnode->next = *pplist;
	*pplist = newnode;
}
//β��ɾ��
void ListPopBack(Node **pplist)
{
	assert(pplist);
	if ((*pplist)->next == NULL)
	{
		free(*pplist);
		*pplist = NULL;
		return;
	}
	else //������������㣬�����ҵ����ڶ������
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
// ͷ��ɾ�� 
void ListPopFront(Node **pplist)
{
	assert(pplist);
	assert(*pplist);//�����ǿ�����
	Node *cur = *pplist;
	*pplist = cur->next;
	free(cur);
	cur = NULL;
}
// ��ֵ���ң����ص�һ���ҵ��Ľ��ָ�룬���û�ҵ������� NULL 
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
// ���������룬���뵽���ǰ 
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
		Node *newnode = CreateNode(data);//�������
		Node *cur = *pplist;
		while (cur->next != pos)
		{
			cur = cur->next;
		}
		newnode->next = pos;
		cur->next = newnode;
	}
}
// �������ɾ�� 
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
// ��ֵɾ����ֻɾ�����ĵ�һ�� 
void ListRemove(Node **pplist, DataType data)
{
	assert(pplist);
	Node *p = ListFind(pplist,data);
	ListErase(pplist, p);
}
Node *Crossing(Node *list1, Node *list2)
{//�󽻵�
	int length1 = GetLength(list1);
	int length2 = GetLength(list2);
	Node *longlist = list1;
	Node *shortlist = list2;
	int diff = length1 - length2;//��������ĳ��Ȳ�
	if (length1<length2)
	{
		longlist = list2;
		shortlist = list1;
		diff = length2 - length1;
	}
	//�ó��������ߣ��ߵ��Ͷ�����һ����
	while (diff--)
	{
		longlist = longlist->next;
	}
	//��ʱ��������һ������������������ͬʱ��
	//�����������Ľ��������н���
	//������껹�޽������޽���
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
// ��ֵɾ����ɾ�����е� 
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
		fast = fast->next->next;//��ָ��һ��������
		slow = slow->next;//��ָ��һ����һ��
	}
	if (fast == slow)
	{
		return fast;//�����ȣ�����������
	}
}
int GetCircleLen(Node *list)
{
	Node *p = IsCircleList(list);
	int count = 0;
	if (p != NULL)//����
	{
		while (p->next != p)
		{
			count++;
			p = p->next;
		}
		count++;//�������һ�����
	}
	return count;
}
Node *EnterNode(Node *list)
{
	Node *node = IsCircleList(list);
	Node *first = list;
	if (node != NULL)//����
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
	Node *m1=IsCircleList(list1);//������������������
	Node *m2 = IsCircleList(list2);
	Node *p1 = EnterNode(list1);//���ػ�����ڵ�
	Node *p2 = EnterNode(list2);
	Node *entryNext1 = p1->next;//������ڵ��next��Ϊ�ָ�����׼��
	Node *entryNext2 = p2->next;
	Node *meet = NULL;
	Node *cur = m1->next;


	if (m1 == NULL && m2 == NULL)
	{//��������������ת��Ϊ���������ཻ����
		return Crossing(list1, list2);
	}
	else if (m1&&m2)//���������������������
	{
		while (cur != m1 && cur != m2)//1.�������ཻ
		{
			cur = cur->next;
		}
		if (cur == m1)
		{
			return NULL;
		}
		else
		{
			if (p1 == p2)//2.��ڵ���ȣ��ཻ�ڻ���
			{
				p1->next = NULL;//�Ͽ���ת����Y���󽻵�����
				p2->next = NULL;
				meet=Crossing(list1, list2);
				p1->next = entryNext1;//�ָ���
				p2->next = entryNext2;
				return meet;
			}
			else//?
			{//3.��ڵ㲻���
				return p2;
			}

		}
	}
	else//һ��������һ��������
	{
		return NULL;
	}
}