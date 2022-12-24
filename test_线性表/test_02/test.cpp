#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
typedef struct ListNode
{
	double data;
	struct ListNode* next;
}Node, * LinkNode;
void InitNode(LinkNode& L)
{
	L = new Node;
	if (L == NULL)
	{
		cout << "ÉêÇë¿Õ¼äÊ§°Ü" << endl;
		return;
	}
	L->next = NULL;
}
void Creat_Node(LinkNode& L)
{
	double a = 0;
	while (scanf("%lf", &a) != EOF)
	{
		LinkNode p = new Node;
		p->data = a;
		p->next = L->next;
		L->next = p;
	}
}
void Traverse(LinkNode L)
{
	if (L->next == NULL)
	{
		cout << "Á´±íÎª¿Õ" << endl;
		return;
	}
	L = L->next;
	cout << "±éÀúÁ´±í£º";
	while (L != NULL)
	{
		cout << L->data << ' ';
		L = L->next;
	}
	cout << endl;
}
void freeList(LinkNode& head)
{
	LinkNode freeNode;
	while (NULL != head)
	{
		freeNode = head;
		head = head->next;
		delete freeNode;
	}
}
void Listoppose(LinkNode L)
{
	LinkNode p, q;
	p = L->next;
	L->next = NULL;
	while (p)
	{
		q = p;
		p = p->next;
		q->next = L->next;
		L->next = q;
	}
}
int main()
{
	LinkNode L;
	InitNode(L);
	Creat_Node(L);
	Traverse(L);
	Listoppose(L);
	Traverse(L);
	freeList(L);
	return 0;
}