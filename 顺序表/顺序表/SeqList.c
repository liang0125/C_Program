#include"SeqList.h"//动态顺序表
//初始化
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
	//不需要扩容
	if (ps->sz < ps->capacity)
	{
		return;
	}
	//容量不够，需要扩容
	int newcapacity = ps->capacity + Increase;
	DataType *newdata = (DataType*)malloc(sizeof(DataType)*newcapacity);
	assert(newdata);
	printf("扩容成功\n");
	//将老数据移到新数据里面
	for (int i = 0; i < ps->sz; i++)
	{
		newdata[i] = ps->data[i];
	}
	//释放老数组
	free(ps->data);
	//新数组放到顺序表结构里
	ps->data = newdata;
	//更新capacity
	ps->capacity = newcapacity;
}
void PushBack(pSeqList ps, DataType d)
{//尾插
	assert(ps != NULL);
	//这里要考虑扩容
	ExpandIfRequired(ps);
	ps->data[ps->sz++] = d;
}
void PrintSeqList(const pSeqList ps)
{//打印顺序表
	int i = 0;
	assert(ps != NULL);
	if (ps->sz == 0)
	{
		printf("顺序表为空\n");
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
{//头插
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
{//尾删
	assert(ps != NULL);
	if (ps->sz == 0)
	{
		printf("顺序表为空，无法删除\n");
		return;
	}
	else
	{
		ps->sz--;
	}
}
void PopFront(pSeqList ps)
{//头删
	int i = 0;
	assert(ps != NULL);
	if (ps->sz == 0)
	{
		printf("顺序表为空 \n");
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
{//指定位置插入
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
{//删除指定位置的元素
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
{//查指定元素,找到了返回下标，没找到返回-1
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
{//删除元素
	assert(ps != NULL);
	int pos = Find(ps, d);
	if (pos == -1)
	{
		printf("要删除的元素不存在\n");
			return;
	}
	else
	{
		Erase(ps, pos);
	}
}
void Sort(pSeqList ps)
{//冒泡排序
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
{//二分查找
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
