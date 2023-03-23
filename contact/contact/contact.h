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
//��̬�汾
//typedef struct people
//{
//	int size;
//	Node node[MAXSIZE];
//}people;

//��̬�汾
typedef struct people
{
	Node* node;
	int size;
	int maxsize;
}people;
//��ʼ���ṹ��
void InitPeople(people* arr);
//��ṹ�����������
void add_people(people* arr);
//չʾ����ͨѶ¼����������Ļ�����Ϣ
void show_people(const people* arr);
//���ͨѶ¼
void clear_people(people* arr);
//ͨ������������ͨѶ¼�о�����Ǹ���
int search_people(const people* arr);
//ɾ��ͨѶ¼�е�һ����
void del_people(people* arr);
//�޸�ͨѶ¼��һ���˵���Ϣ
void modify_people(people* arr);
//����ͨѶ¼������������������
void sort_contact(people* arr);