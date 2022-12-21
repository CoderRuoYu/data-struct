#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
typedef struct Tree
{
	char data;
	struct Tree* lchild;
	struct Tree* rchild;
}TreeNode,*LinkTree;
//��ʼ��������
void initTree(LinkTree& T)
{
	T = NULL;
}
//����������
void creatTree(LinkTree& T)
{
	char ch;
	scanf("%c", &ch);
	if (ch == '#')
	{
		T = NULL;
		return;
	}
	else
	{
		T = new TreeNode;
		if (!T)
		{
			cout << "δ���뵽�ռ�" << endl;
			return;
		}
		T->data = ch;
		creatTree(T->lchild);
		creatTree(T->rchild);
	}
}
//ǰ��ݹ����
void PreOrderTraverse(LinkTree& T)
{
	if (!T)
	{
		return;
	}
	else
	{
		cout << T->data << ' ';
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);

	}
}
//����ݹ����
void MidOrderTraverse(LinkTree& T)
{
	if(!T)
	{
		return;
	}
	else
	{
		PreOrderTraverse(T->lchild);
		cout << T->data << ' ';
		PreOrderTraverse(T->rchild);
	}
}
//����ݹ����
void PostOrderTraverse(LinkTree& T)
{
	if (!T)
	{
		return;
	}
	else
	{
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
		cout << T->data << ' ';
	}
}
//��α���������

int main()
{
	LinkTree T;
	//����������
	creatTree(T);
	//ǰ�����������
	cout << "ǰ�����������" << endl;
	PreOrderTraverse(T);
	cout << endl;

	//����ݹ����
	cout << "�������������" << endl;
	MidOrderTraverse(T);
	cout << endl;
	//����ݹ����
	cout << "�������������" << endl;
	PostOrderTraverse(T);
	cout << endl;
	return 0;
}