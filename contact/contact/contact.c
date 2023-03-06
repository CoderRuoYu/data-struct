#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"
void InitPeople(people* arr)
{
	arr->node = (Node*)malloc(sizeof(Node) * DEFAULT_SZ);
	if (!(arr->node))
	{
		perror("malloc");
		return;
	}
	arr->maxsize = DEFAULT_SZ;
	arr->size = 0;
}
void check_capacity(people* arr)
{
	if (arr->maxsize == arr->size)
	{
		Node* ptr = (Node *)realloc(arr->node, sizeof(Node) * (INC_SZ + arr->size));
		if (!ptr)
		{
			perror("realloc");
			return;
		}
		arr->node = ptr;
		arr->maxsize += INC_SZ;
	}
}
void add_people(people* arr)
{

	check_capacity(arr);
	printf("请输入您要添加的姓名:>");
	scanf("%s", arr->node[arr->size].name);
	printf("请输入您要添加人的性别:>");
	scanf("%s", arr->node[arr->size].sex);
	printf("请输入您要添加人的年龄:>");
	scanf("%d", &(arr->node[arr->size].age));
	printf("请输入您要添加人的电话号码:>");
	scanf("%s", arr->node[arr->size].tel);
	printf("请输入您要添加联系人的地址:>");
	scanf("%s", arr->node[arr->size].address);
	arr->size++;
}
void show_people(const people* a)
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
void clear_people(people* arr)
{
	arr->size = 0;
	printf("您的通讯录已经清空\n");
}
//找到匹配的人名返回下标，否则返回-1
int search_people(const people* arr)
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
void del_people(people* arr)
{
	printf("请输入您要删除联系人的姓名:>");
	char tem[20];
	scanf("%s", tem);
	int ret = find_by_name(arr, tem);
	if (ret == -1)printf("您要删除的联系人不存在");
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
void modify_people(people* arr)
{
	printf("请您输入您要修改哪位联系人的信息:>");
	char tem[20];
	scanf("%s", tem);
	int ret = find_by_name(arr, tem);
	if (ret == -1)
	{
		printf("您输入的联系人不存在于您的通讯录。\n");
	}
	else
	{
		printf("请输入您要修改的姓名:>");
		scanf("%s", arr->node[ret].name);
		printf("请输入您要修改人的性别:>");
		scanf("%s", arr->node[ret].sex);
		printf("请输入您要修改人的年龄:>");
		scanf("%d", &arr->node[ret].age);
		printf("请输入您要修改人的电话号码:>");
		scanf("%s", arr->node[ret].tel);
		printf("请输入您要修改联系人的地址:>");
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
void destroy_contact(people* arr)
{
	free(arr->node);
	arr->node = NULL;
	arr->size = 0;
	arr->maxsize = 0;
	arr = NULL;
}
