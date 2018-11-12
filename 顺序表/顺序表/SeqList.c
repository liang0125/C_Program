#include"SeqList.h"//��̬˳���
//��ʼ��
void InitSeqList(pSeqList ps)
{
	const int init_capacity = 5;
	assert(ps != NULL);
	ps->sz = 0;
	ps->capacity = init_capacity;
	ps->data = (DataType*)malloc(sizeof(DataType)*init_capacity);
	assert(ps->data != NULL);
}
void DestroySeqList(pSeqList ps)
{
	assert(ps);
	free(ps->data);
	ps->data = NULL;
	ps->sz = 0;
	ps->capacity = 0;
}
void ExpandIfRequired(pSeqList ps)
{
	assert(ps);
	//����Ҫ����
	if (ps->sz < ps->capacity)
	{
		return;
	}
	//������������Ҫ����
	int newcapacity = ps->capacity + Increase;
	DataType *newdata = (DataType*)malloc(sizeof(DataType)*newcapacity);
	assert(newdata);
	printf("���ݳɹ�\n");
	//���������Ƶ�����������
	for (int i = 0; i < ps->sz; i++)
	{
		newdata[i] = ps->data[i];
	}
	//�ͷ�������
	free(ps->data);
	//������ŵ�˳���ṹ��
	ps->data = newdata;
	//����capacity
	ps->capacity = newcapacity;
}
void PushBack(pSeqList ps, DataType d)
{//β��
	assert(ps != NULL);
	//����Ҫ��������
	ExpandIfRequired(ps);
	ps->data[ps->sz++] = d;
}
void PrintSeqList(const pSeqList ps)
{//��ӡ˳���
	int i = 0;
	assert(ps != NULL);
	if (ps->sz == 0)
	{
		printf("˳���Ϊ��\n");
		return;
	}
	else
	{
		for (i = 0; i < ps->sz; i++)
		{
			printf("%d ", ps->data[i]);
		}
		printf("\n");
	}
}
void PushFront(pSeqList ps, DataType d)
{//ͷ��
	int i = 0;
	assert(ps != NULL);
	ExpandIfRequired(ps);

		for (i = ps->sz; i > 0; i--)
		{
			ps->data[i] = ps->data[i-1];
		}
		ps->data[0] = d;
		ps->sz++;

}
void PopBack(pSeqList ps)
{//βɾ
	assert(ps != NULL);
	if (ps->sz == 0)
	{
		printf("˳���Ϊ�գ��޷�ɾ��\n");
		return;
	}
	else
	{
		ps->sz--;
	}
}
void PopFront(pSeqList ps)
{//ͷɾ
	int i = 0;
	assert(ps != NULL);
	if (ps->sz == 0)
	{
		printf("˳���Ϊ�� \n");
		return;
	}
	else
	{
		for (i = 0; i < ps->sz-1; i++)
		{
			ps->data[i] = ps->data[i + 1];
		}
		ps->sz--;
	}
}
void Insert(pSeqList ps, int pos, DataType d)
{//ָ��λ�ò���
	int i = 0;
	assert(ps != NULL);
	ExpandIfRequired(ps);
	assert(pos >= 0 && pos <= ps->sz);
	for (i = ps->sz - 1; i >= pos; i--)
	{
		ps->data[i + 1] = ps->data[i];
	}
	ps->data[pos] = d;
	ps->sz++;
}
void Erase(pSeqList ps, int pos)
{//ɾ��ָ��λ�õ�Ԫ��
	int i = 0;
	assert(ps != NULL);
	assert(pos >= 0 && pos <= ps->sz);
	for (i = pos; i < ps->sz-1; i++)
	{
		ps->data[i] = ps->data[i + 1];
	}
	ps->sz--;

}
int Find(pSeqList ps, DataType d)
{//��ָ��Ԫ��,�ҵ��˷����±꣬û�ҵ�����-1
	int i = 0;
	assert(ps != NULL);
	for (i = 0; i < ps->sz; i++)
	{
		if (ps->data[i] == d)
			return i;
	}
	return -1;
}
void Remove(pSeqList ps, DataType d)
{//ɾ��Ԫ��
	assert(ps != NULL);
	int pos = Find(ps, d);
	if (pos == -1)
	{
		printf("Ҫɾ����Ԫ�ز�����\n");
			return;
	}
	else
	{
		Erase(ps, pos);
	}
}
void Sort(pSeqList ps)
{//ð������
	assert(ps != NULL);
	int i = 0;
	int j = 0;
	int flag = 0;
	DataType tmp = 0;
	for (i = 0; i < ps->sz - 1; i++)
	{
		flag = 0;
		for (j = 0; j < ps->sz - 1 - i; j++)
		{
			if (ps->data[j] > ps->data[j + 1])
			{
				tmp = ps->data[j];
				ps->data[j] = ps->data[j + 1];
				ps->data[j + 1] = tmp;
				flag = 1;
			}
		}
		if (flag == 0)
			return;
	}
}
int BinarySearch(pSeqList ps, DataType d)
{//���ֲ���
	assert(ps != NULL);
	int left = 0;
	int right = ps->sz - 1;
	int mid = left + (right - left) / 2;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (d<ps->data[mid])
		{
			right = mid - 1;
		}
		if (d > ps->data[mid])
		{
			left = mid + 1;
		}
		if(d==ps->data[mid])
			return mid;
	}
	return -1;
}
