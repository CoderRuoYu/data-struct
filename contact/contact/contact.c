#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"
void InitPeople(people* arr)
{
	arr->size = 0;
}
void add(people* arr)
{
	if (arr->size >= MAXSIZE - 1)
		printf("ͨѶ¼�������޷����\n");
	printf("��������Ҫ��ӵ�����:>");
	scanf("%s", arr->node[arr->size].name);
	printf("��������Ҫ����˵��Ա�:>");
	scanf("%s", arr->node[arr->size].sex);

	printf("��������Ҫ����˵�����:>");
	scanf("%d", &arr->node[arr->size].age);
	printf("��������Ҫ����˵ĵ绰����:>");
	scanf("%s", arr->node[arr->size].tel);
	printf("��������Ҫ�����ϵ�˵ĵ�ַ:>");
	scanf("%s", arr->node[arr->size].address);
	arr->size++;
}
void show(const people* a)
{
	if (a->size == 0)
	{
		printf("����ͨѶ¼Ϊ��\n");
		return;
	}
	printf("%-15s%-15s%-15s%-15s%-15s\n", "����", "�Ա�", "����", "�绰", "סַ");
	for (int i = 0; i < a->size; i++)
	{
		printf("%-15s%-15s%-15d%-15s%-15s\n", a->node[i].name, a->node[i].sex, a->node[i].age, a->node[i].tel, a->node[i].address);
	}
	printf("\n");
}
void clear(people* arr)
{
	arr->size = 0;
	printf("����ͨѶ¼�Ѿ����\n");
}
//�ҵ�ƥ������������±꣬���򷵻�-1
int search(const people* arr)
{
	char tem[20];
	printf("��������Ҫ���ҵ��˵�����:>");
	scanf("%s", tem);
	for (int i = 0; i < arr->size; i++)
	{
		if (strcmp(arr->node[i].name, tem) == 0)
		{
			return i;
		}
	}
	return -1;
}
int find_by_name(people *arr,char tem[])
{
	if (arr->size == 0)return -1;
	for (int i = 0; i < arr->size; i++)
	{
		if (strcmp(arr->node[i].name, tem) == 0)
			return i;
	}
	return -1;
}
void del(people* arr)
{
	printf("��������Ҫɾ����ϵ�˵�����:>");
	char tem[20];
	scanf("%s", tem);
	int ret = find_by_name(arr, tem);
	if (ret == -1)printf("��Ҫɾ������ϵ�˲�����");
	else
	{
		for (int i = ret; i < arr->size - 1; i++)
		{
			strcpy(arr->node[i].name, arr->node[i + 1].name);
			strcpy(arr->node[i].address, arr->node[i + 1].address);
			strcpy(arr->node[i].sex, arr->node[i + 1].sex);
			strcpy(arr->node[i].tel, arr->node[i + 1].tel);
			arr->node[i].age = arr->node[i + 1].age;
		}
		arr->size--;
	}
}
void modify(people* arr)
{
	printf("����������Ҫ�޸���λ��ϵ�˵���Ϣ:>");
	char tem[20];
	scanf("%s", tem);
	int ret = find_by_name(arr, tem);
	if (ret == -1)
	{
		printf("���������ϵ�˲�����������ͨѶ¼��\n");
	}
	else
	{
		printf("��������Ҫ�޸ĵ�����:>");
		scanf("%s", arr->node[ret].name);
		printf("��������Ҫ�޸��˵��Ա�:>");
		scanf("%s", arr->node[ret].sex);
		printf("��������Ҫ�޸��˵�����:>");
		scanf("%d", &arr->node[ret].age);
		printf("��������Ҫ�޸��˵ĵ绰����:>");
		scanf("%s", arr->node[ret].tel);
		printf("��������Ҫ�޸���ϵ�˵ĵ�ַ:>");
		scanf("%s", arr->node[ret].address);
	}
}
//void qsort(void* base, size_t num, size_t size,
//	int (*compar)(const void*, const void*));
int my_compar(const void* s1, const void* s2)
{
	return ((Node*)s1)->age - ((Node*)s2)->age;
}
void sort_contact(people* arr)
{
	qsort(arr->node, arr->size, sizeof(arr->node[0]), my_compar);
}
