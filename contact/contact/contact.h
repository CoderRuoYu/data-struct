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
void InitPeople(people* arr);
void add(people* arr);
void show(const people* arr);
void clear(people* arr);
int search(const people* arr);
void del(people* arr);