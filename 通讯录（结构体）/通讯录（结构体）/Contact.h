#ifndef __CONTACT_H__
#define __CONTACT_H__

#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>
#define NAME_MAX 20
#define SEX_MAX 5
#define TEL_MAX 12
#define ADD_MAX 25
#define DATA_MAX 1000
#define DEFAULT_SZ 3
typedef struct PeoInfo
{
	char name[NAME_MAX];
	int age;
	char sex[SEX_MAX];
	char tel[TEL_MAX];
	char add[ADD_MAX];
}PeoInfo;
typedef struct Contact
{
    PeoInfo *data;//数据存放的位置
	int sz ;//表示当前有sz个有效数据
	int capacity;//容量
}Contact,*pContact;
void InitContact(pContact pc);
void AddContact(pContact pc);
void DelContact(pContact pc);
void SearchContact(pContact pc);
void ModifyContact(pContact pc);
void SortContact(pContact pc);
void ShowContact(pContact pc);
void EmptyContact(pContact pc);
void DestroyContact(pContact pc);

#endif // __CONTACT_H__


