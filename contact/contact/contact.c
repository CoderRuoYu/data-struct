#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"
void InitPeople(people* arr)
{
	arr->size = 0;
}
void add(people* arr)
{
	if (arr->size >= MAXSIZE - 1)
		printf("通讯录已满，无法添加\n");
	printf("请输入您要添加的姓名:>");
	scanf("%s", arr->node[arr->size].name);
	printf("请输入您要添加人的性别:>");
	scanf("%s", arr->node[arr->size].sex);

	printf("请输入您要添加人的年龄:>");
	scanf("%d", &arr->node[arr->size].age);
	printf("请输入您要添加人的电话号码:>");
	scanf("%s", arr->node[arr->size].tel);
	printf("请输入您要联系人的地址:>");
	scanf("%s", arr->node[arr->size].address);
	arr->size++;
}
void show(const people* a)
{
	if (a->size == 0)
	{
		printf("您的通讯录为空\n");
		return;
	}
	printf("%-15s%-15s%-15s%-15s%-15s\n", "姓名", "性别", "年龄", "电话", "住址");
	for (int i = 0; i < a->size; i++)
	{
		printf("%-15s%-15s%-15d%-15s%-15s\n", a->node[i].name, a->node[i].sex, a->node[i].age, a->node[i].tel, a->node[i].address);
	}
	printf("\n");
}
void clear(people* arr)
{
	arr->size = 0;
	printf("您的通讯录已经清空\n");
}
//找到匹配的人名返回下标，否则返回-1
int search(const people* arr)
{
	char tem[20];
	printf("请输入您要查找的人的名字:>");
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

//没有完成需要修改
int find_by_name();
void del(people* arr)
{
	printf("请输入您要删除联系人的姓名:>");
	char tem[20];
	scanf("%s", tem);

}
