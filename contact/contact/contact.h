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
//��ʼ���ṹ��
void InitPeople(people* arr);
//��ṹ�����������
void add(people* arr);
//չʾ����ͨѶ¼����������Ļ�����Ϣ
void show(const people* arr);
//���ͨѶ¼
void clear(people* arr);
//ͨ������������ͨѶ¼�о�����Ǹ���
int search(const people* arr);
//ɾ��ͨѶ¼�е�һ����
void del(people* arr);
//�޸�ͨѶ¼��һ���˵���Ϣ
void modify(people* arr);
//����ͨѶ¼������������������
void sort_contact(people* arr);