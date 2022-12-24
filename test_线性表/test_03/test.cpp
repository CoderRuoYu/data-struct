#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
//设有一个双向循环链表，每个结点中除有prior, data和next三个域外，
//还增设了一个访问频度域freq。在链表被起用之前，频度域freq的值均初始化为零，
//而每当对链表进行一次locate(L, x)的操作后，被访问的结点（即元素值等于x的结点）中的频度域freq的值便增1，
//同时调整链表中结点之间的次序，使其按访问频度非递增的次序顺序排列，
//以便始终保持被频繁访问的结点总是靠近表头结点。试编写符合上述要求的locate操作的算法。

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
int main()
{
	LinkNode L;
	InitNode(L);
	Creat_List(L);
	Traverse(L);
	return 0;
}