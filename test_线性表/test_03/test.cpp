#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
//����һ��˫��ѭ������ÿ������г���prior, data��next�������⣬
//��������һ������Ƶ����freq������������֮ǰ��Ƶ����freq��ֵ����ʼ��Ϊ�㣬
//��ÿ�����������һ��locate(L, x)�Ĳ����󣬱����ʵĽ�㣨��Ԫ��ֵ����x�Ľ�㣩�е�Ƶ����freq��ֵ����1��
//ͬʱ���������н��֮��Ĵ���ʹ�䰴����Ƶ�ȷǵ����Ĵ���˳�����У�
//�Ա�ʼ�ձ��ֱ�Ƶ�����ʵĽ�����ǿ�����ͷ��㡣�Ա�д��������Ҫ���locate�������㷨��

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
	cout << "���������֣�������������";
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
		cout << "������Ϊ��" << endl;
		return;
	}
	LinkNode p = L;
	p = p->next;
	cout << "��������";
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