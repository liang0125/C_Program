#define _CRT_SECURE_NO_WARNINGS 1
#include"Contact.h"
void InitContact(pContact pc)
{
	assert(pc);
	pc->sz = 0;
	pc->data = (PeoInfo*)malloc(DEFAULT_SZ * sizeof(PeoInfo));
	pc->capacity = DEFAULT_SZ;
}
void DestroyContact(pContact pc)
{
	free(pc->data);
	pc->data = NULL;
	pc->capacity = 0;
	pc->sz = 0;
}
int Check(pContact pc)
{
	if (pc->sz == pc->capacity)
	{
		//增容
		PeoInfo *tmp = realloc(pc->data, (pc->capacity + 2) * sizeof(PeoInfo));
		if (tmp != NULL)
		{
			pc->data = tmp;
			pc->capacity += 2;
			printf("增容成功\n");
			return 1;
		}
		else
		{
			return 0;
		}
	}
	return 1;
}
void AddContact(pContact pc)
{
	assert(pc);
		if (Check(pc) == 0)
		{
			return;
		}
		printf("请输入姓名：\n");
		scanf("%s", pc->data[pc->sz].name);
		printf("请输入年龄：\n");
		scanf("%d", &pc->data[pc->sz].age);
		printf("请输入性别：\n");
		scanf("%s", pc->data[pc->sz].sex);
		printf("请输入电话：\n");
		scanf("%s", pc->data[pc->sz].tel);
		printf("请输入地址：\n");
		scanf("%s", pc->data[pc->sz].add);
		pc->sz++;
		printf("添加成功\n");
}
static int Find(pContact pc,char name[])//static可以有效的保护代码
{
	int i = 0;
	assert(pc);
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(name, pc->data[i].name) == 0)
		{
			return i;//找到了返回下标
		}
	}
	return -1;//没找到
}
void DelContact(pContact pc)
{
	char name[NAME_MAX] = { 0 };
	int j = 0;
	int pos = 0;
	assert(pc);
	if (pc->sz == 0)
	{
		printf("通讯录为空，无法删除\n");
		return;
	}
	printf("请输入要删除的人的姓名：\n");
	scanf("%s", name);
	//1.查找位置
	pos=Find(pc, name);
	if (pos == -1)
		return;
	//2.删除
	for (j = pos; j < pc->sz - 1; j++)
	{
		pc->data[j] = pc->data[j + 1];
	}
	pc->sz--;
	printf("删除成功\n");
}

void SearchContact(pContact pc)
{
	char name[NAME_MAX] = { 0 };
	int pos = 0;
	assert(pc);
	if (pc->sz == 0)
	{
		printf("通讯录为空，无法查找\n");
		return;
	}
	printf("请输入要查找的人的姓名：\n");
	scanf("%s", name);
	//查找位置
	pos = Find(pc, name);
	if (pos == -1)
	{
		printf("要查找的人不存在\n");
		return;
	}
	else
	{
		printf("%10s\t%4s\t%5s\t%12s\t%20s\n", "name", "age", "sex", "tel", "add");
		printf("%10s\t%4d\t%5s\t%12s\t%20s\n", pc->data[pos].name, pc->data[pos].age, pc->data[pos].sex, pc->data[pos].tel, pc->data[pos].add);
	}
}
void ModifyContact(pContact pc)
{
	char name[NAME_MAX] = { 0 };
	int pos = 0;
	assert(pc);
	if (pc->sz == 0)
	{
		printf("通讯录为空，无法修改\n");
		return;
	}
	printf("请输入要修改的人的姓名：\n");
	scanf("%s", name);
	//查找
	pos = Find(pc, name);
	if (pos == -1)
	{
		printf("要修改的人不存在\n");
		return;
	}
	else
	{
		printf("请输入姓名：\n");
		scanf("%s", pc->data[pos].name);
		printf("请输入年龄：\n");
		scanf("%d", &pc->data[pos].age);
		printf("请输入性别：\n");
		scanf("%s", pc->data[pos].sex);
		printf("请输入电话：\n");
		scanf("%s", pc->data[pos].tel);
		printf("请输入地址：\n");
		scanf("%s", pc->data[pos].add);
		printf("修改成功\n");
	}
}

void SortContact(pContact pc)
{
	int i = 0;
	int j = 0;
	char tmp = 0;
	int flag = 0;
	assert(pc);
	for (i = 0; i < pc->sz - 1; i++)
	{
		for (j = 0; j < pc->sz - 1 - i; j++)
		{
			if (strcmp(pc->data[j].name, pc->data[j + 1].name) > 0)
			{
				PeoInfo tmp = pc->data[j];
				pc->data[j] = pc->data[j + 1];
				pc->data[j + 1] = tmp;
				flag = 1;
			}
		}
		if (flag == 0)
			return;
	}
	printf("排序成功！\n");
}

void ShowContact(pContact pc)
{
	int i = 0;
	assert(pc);
	printf("%10s\t%4s\t%5s\t%12s\t%20s\n","name","age","sex","tel","add");
	for (i = 0; i < pc->sz; i++)
	{
		printf("%10s\t%4d\t%5s\t%12s\t%20s\n", pc->data[i].name, pc->data[i].age, pc->data[i].sex, pc->data[i].tel, pc->data[i].add);
	}
}

void EmptyContact(pContact pc)
{
	assert(pc);
	pc->sz = 0;//清空
}