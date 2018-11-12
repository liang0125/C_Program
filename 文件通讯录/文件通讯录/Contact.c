#define _CRT_SECURE_NO_WARNINGS 1
#include"Contact.h"

void LoadContact(pContact pc)
{
	FILE *pf = fopen("contact.dat.txt", "rb");
	PeoInfo tmp = { 0 };
	int i = 0;
	if (pf == NULL)
	{
		perror("open file for read");
		exit(EXIT_FAILURE);
	}
	while(fread(&tmp,sizeof(PeoInfo),1,pf))
	{
		if (Check(pc) == 0)
		{
			exit(EXIT_FAILURE);
		}
		pc->data[pc->sz] = tmp;
		pc->sz++;
	}
	fclose(pf);
	pf = NULL;
}
void InitContact(pContact pc)
{
	assert(pc);
	pc->sz = 0;
	pc->data = (PeoInfo*)malloc(DEFAULT_SZ * sizeof(PeoInfo));
	pc->capacity = DEFAULT_SZ;
	LoadContact(pc);//���ļ�
}
void DestroyContact(pContact pc)
{
	free(pc->data);
	pc->data = NULL;
	pc->capacity = 0;
	pc->sz = 0;
}

void AddContact(pContact pc)
{
	assert(pc);
	if (Check(pc) == 0)
	{
		return;
	}
	printf("������������\n");
	scanf("%s", pc->data[pc->sz].name);
	printf("���������䣺\n");
	scanf("%d", &pc->data[pc->sz].age);
	printf("�������Ա�\n");
	scanf("%s", pc->data[pc->sz].sex);
	printf("������绰��\n");
	scanf("%s", pc->data[pc->sz].tel);
	printf("�������ַ��\n");
	scanf("%s", pc->data[pc->sz].add);
	pc->sz++;
	printf("��ӳɹ�\n");
}
static int Find(pContact pc, char name[])//static������Ч�ı�������
{
	int i = 0;
	assert(pc);
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(name, pc->data[i].name) == 0)
		{
			return i;//�ҵ��˷����±�
		}
	}
	return -1;//û�ҵ�
}
int Check(pContact pc)
{
	if (pc->sz == pc->capacity)
	{
		//����
		PeoInfo *tmp = realloc(pc->data, (pc->capacity + 2) * sizeof(PeoInfo));
		if (tmp != NULL)
		{
			pc->data = tmp;
			pc->capacity += 2;
			printf("���ݳɹ�\n");
			return 1;
		}
		else
		{
			return 0;
		}
	}
	return 1;
}
void DelContact(pContact pc)
{
	char name[NAME_MAX] = { 0 };
	int j = 0;
	int pos = 0;
	assert(pc);
	if (pc->sz == 0)
	{
		printf("ͨѶ¼Ϊ�գ��޷�ɾ��\n");
		return;
	}
	printf("������Ҫɾ�����˵�������\n");
	scanf("%s", name);
	//1.����λ��
	pos = Find(pc, name);
	if (pos == -1)
		return;
	//2.ɾ��
	for (j = pos; j < pc->sz - 1; j++)
	{
		pc->data[j] = pc->data[j + 1];
	}
	pc->sz--;
	printf("ɾ���ɹ�\n");
}

void SearchContact(pContact pc)
{
	char name[NAME_MAX] = { 0 };
	int pos = 0;
	assert(pc);
	if (pc->sz == 0)
	{
		printf("ͨѶ¼Ϊ�գ��޷�����\n");
		return;
	}
	printf("������Ҫ���ҵ��˵�������\n");
	scanf("%s", name);
	//����λ��
	pos = Find(pc, name);
	if (pos == -1)
	{
		printf("Ҫ���ҵ��˲�����\n");
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
		printf("ͨѶ¼Ϊ�գ��޷��޸�\n");
		return;
	}
	printf("������Ҫ�޸ĵ��˵�������\n");
	scanf("%s", name);
	//����
	pos = Find(pc, name);
	if (pos == -1)
	{
		printf("Ҫ�޸ĵ��˲�����\n");
		return;
	}
	else
	{
		printf("������������\n");
		scanf("%s", pc->data[pos].name);
		printf("���������䣺\n");
		scanf("%d", &pc->data[pos].age);
		printf("�������Ա�\n");
		scanf("%s", pc->data[pos].sex);
		printf("������绰��\n");
		scanf("%s", pc->data[pos].tel);
		printf("�������ַ��\n");
		scanf("%s", pc->data[pos].add);
		printf("�޸ĳɹ�\n");
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
	printf("����ɹ���\n");
}

void ShowContact(pContact pc)
{
	int i = 0;
	assert(pc);
	printf("%10s\t%4s\t%5s\t%12s\t%20s\n", "name", "age", "sex", "tel", "add");
	for (i = 0; i < pc->sz; i++)
	{
		printf("%10s\t%4d\t%5s\t%12s\t%20s\n", pc->data[i].name, pc->data[i].age, pc->data[i].sex, pc->data[i].tel, pc->data[i].add);
	}
}

void EmptyContact(pContact pc)
{
	assert(pc);
	pc->sz = 0;//���
}
void SaveContact(pContact pc)
{
	FILE *pf=fopen("contact.dat.txt", "wb");
	int i = 0;
	if (pf == NULL)
	{
		perror("open file for save");
		exit(EXIT_FAILURE);
	}
	for (i = 0; i < pc->sz; i++)
	{
		fwrite(pc->data + i, sizeof(PeoInfo), 1, pf);
	}
	fclose(pf);
	pf = NULL;
}