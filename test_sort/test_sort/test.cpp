#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
typedef struct LNode
{
	int data;
	struct LNode* next;
}LNode, * LinkList;

void InitList(LinkList& L)
{
	L = new LNode;
	L->next = NULL;
}
void CreateList(LinkList& L, int n)
{
	LinkList q = L;
	for (int i = 0; i < n; i++)
	{
		LinkList p = new LNode;
		cin >> p->data;
		p->next = NULL;
		q->next = p;
		q = p;
	}
}
void SortList(LinkList& L, int n)
{
	for (int i = 0; i < n; i++)
	{
		LinkList p = L->next;
		for (int j = i + 1; j < n; j++)
		{
			if (p->data > p->next->data)
			{
				int temp;
				temp = p->data;
				p->data = p->next->data;
				p->next->data = temp;
			}
			p = p->next;
		}
	}
}
void Output(LinkList L)
{
	LinkList p = L->next;
	while (p->next)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << p->data << endl;
}
int main()
{
	int n;
	while (scanf("%d", &n) == 1)
	{
		LinkList L;
		InitList(L);
		CreateList(L, n);
		SortList(L, n);
		Output(L);
	}
	return 0;
}