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
	printf("��������Ҫ��ϵ�˵ĵ�ַ:>");
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

//û�������Ҫ�޸�
int find_by_name();
void del(people* arr)
{
	printf("��������Ҫɾ����ϵ�˵�����:>");
	char tem[20];
	scanf("%s", tem);

}
