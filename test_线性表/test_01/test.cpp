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
		cout << "申请空间失败" << endl;
		return;
	}
	L->next = NULL;
}
void Creat_Node(LinkNode& L)
{
	double a = 0;
	while (scanf("%lf", &a)!=EOF)
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
		cout << "链表为空" << endl;
		return;
	}
	L = L->next;
	cout << "链表中从小到大存储的数字：";
	while (L != NULL)
	{
		cout << L->data << ' ';
		L = L->next;
	}
	cout << endl;
}
void Delete(double mink, double maxk, LinkNode& L)
{
	LinkNode T = L;
	while (T->next != NULL)
	{
		
		if ((T->next->data) >= mink && (T->next->data) <= maxk)
		{
			LinkNode p = T->next;
			T->next = p->next;
			delete p;
		}
		else
			T = T->next;
	}
	cout << "删除成功" << endl;
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

int main()
{
	double mink, maxk;
	scanf("%lf %lf", &mink, &maxk);
	LinkNode L;
	InitNode(L);
	Creat_Node(L);
	Traverse(L);
	Traverse(L);
	Delete(mink, maxk, L);
	Traverse(L);
	freeList(L);
	return 0;
}