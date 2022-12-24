#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
typedef struct List
{
	struct List* pre;
	struct List* next;
	int data;
	int freq;
}Node,*LinkNode;
void InitNode(LinkNode &L)
{
	L = new Node;
	L->next = L;
	L->pre = L;
	L->freq = 0;
}
void Creat_List(LinkNode &L)
{
	int a = 0;
	cout << "请输入数字，用来创建链表：";
	while (scanf("%d", &a) == 1)
	{
		LinkNode p = new Node;
		p->data = a;
		p->freq = 0;
		p->pre = L;
		L->next->pre = p;
		p->next = L->next;
		L->next = p;
	}
}
void Traverse(LinkNode L)
{
	if (L->next == NULL)
	{
		cout << "该链表为空" << endl;
		return;
	}
	LinkNode p = L;
	p = p->next;
	cout << "遍历链表：";
	while (p != L)
	{
		cout << p->data << ' ';
		p = p->next;
	}
	cout << endl;
}
void Locate(LinkNode& L, int x)
{
	if (L->next == NULL)
	{
		cout << "该链表为空" << endl;
		return;
	}
	LinkNode p = L->next;
	do
	{
		if (p->data == x)
		{
			p->freq++;
			LinkNode q = p, s = p->pre;
			while (s->freq < q->freq && s != L)
			{
				LinkNode temp;
				s->pre->next = q;
				s->next = q->next;
				q->pre = s->pre;
				q->next->pre = s;
				s->pre = q;
				q->next = s;

				temp = s;
				s = q;
				q = temp;
				s = s->pre;
				q = q->pre;
			}
		}
		p = p->next;
	} while (p != L);
}
int main()
{
	LinkNode L;
	InitNode(L);
	Creat_List(L);
	Traverse(L);
	int x = 0;
	cout << "请输入你要输入的x的值：";
	while (scanf("%d", &x) == 1)
	{
		
		Locate(L, x);
		cout << "调用Locate函数后：";
		Traverse(L);
		cout << "请输入你要输入的x的值：";
	}
	system("pause");
	return 0;
}