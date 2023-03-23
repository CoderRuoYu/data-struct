#pragma once
//made by gaoruoyu
//2023/2/10
#include <stdio.h>
//#define MAXSIZE 1000
#include <string.h>
#define NAMEMAXSIZE 15
#define SEXMAXSIZE 4
#define TELMAXSIZE 14
#define ADDRESSMAX 10

#define DEFAULT_SZ 3
#define INC_SZ 2

typedef struct Node
{
	int age;
	char name[NAMEMAXSIZE];
	char sex[SEXMAXSIZE];
	char tel[TELMAXSIZE];
	char address[ADDRESSMAX];
}Node;
//静态版本
//typedef struct people
//{
//	int size;
//	Node node[MAXSIZE];
//}people;

//动态版本
typedef struct people
{
	Node* node;
	int size;
	int maxsize;
}people;
//初始化结构体
void InitPeople(people* arr);
//向结构体中添加人数
void add_people(people* arr);
//展示我们通讯录中现有人物的基本信息
void show_people(const people* arr);
//清空通讯录
void clear_people(people* arr);
//通过姓名，查找通讯录中具体的那个人
int search_people(const people* arr);
//删除通讯录中的一个人
void del_people(people* arr);
//修改通讯录中一个人的信息
void modify_people(people* arr);
//按照通讯录中人物的年龄进行排序
void sort_contact(people* arr);