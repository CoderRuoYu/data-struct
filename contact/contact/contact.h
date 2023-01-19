#pragma once
#include <stdio.h>
#define MAXSIZE 1000
#include <string.h>
typedef struct Node
{
	char name[15];
	char sex[4];
	int age;
	char tel[14];
	char address[10];
}Node;
typedef struct people
{
	int size;
	Node node[MAXSIZE];
}people;
//初始化结构体
void InitPeople(people* arr);
//向结构体中添加人数
void add(people* arr);
//展示我们通讯录中现有人物的基本信息
void show(const people* arr);
//清空通讯录
void clear(people* arr);
//通过姓名，查找通讯录中具体的那个人
int search(const people* arr);
//删除通讯录中的一个人
void del(people* arr);
//修改通讯录中一个人的信息
void modify(people* arr);
//按照通讯录中人物的年龄进行排序
void sort_contact(people* arr);