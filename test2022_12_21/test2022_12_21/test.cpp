#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#define MAXSIZE 100
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
		MidOrderTraverse(T->lchild);
		cout << T->data << ' ';
		MidOrderTraverse(T->rchild);
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
//ջ�Ķ���
typedef struct Stack
{
	LinkTree a[MAXSIZE];
	int rear;
}Stack;
//��ʼ��ջ
void InitStack(Stack& S)
{
	S.rear = 0;
}
//��ջ�з���Ԫ��
void PushStack(Stack& S,LinkTree T)
{
	if (S.rear >= MAXSIZE)
	{
		cout << "ջ�������޷�����" << endl;
		return;
	}
	S.a[S.rear++] = T;
}
//�ж�ջ�Ƿ�Ϊ�գ�Ϊ�շ���1���ǿշ���0
int is_stack_empty(Stack S)
{
	if (S.rear == 0)
	{
		return 1;
	}
	return 0;
}
//��ջ�е�Ԫ�ص���
LinkTree Pop_stack(Stack& S)
{
	if (is_stack_empty(S))
	{
		cout << "ջ��,Ԫ���޷���ջ" << endl;
		return NULL;
	}
	else
	{
		S.rear--;
		return S.a[S.rear];
	}
}
//����ǵݹ����������
void Mid01OrderTraverse(LinkTree T)
{
	if (T == NULL)
	{
		cout << "����Ϊ����" << endl;
		return;
	}
	Stack S;
	InitStack(S);
	while (T || is_stack_empty(S) != 1)
	{
		if (T)
		{
			PushStack(S, T);
			T = T->lchild;
		}
		else
		{
			LinkTree p = Pop_stack(S);
			cout << p->data << ' ';
			T = p->rchild;
		}

	}
}
//�������
typedef struct Quene
{
	int front;
	int rear;
	int data[MAXSIZE];
}Quene;
//��ʼ������
void Init_Quene(Quene& Q)
{
	Q.front = Q.rear = 0;
}
void Push_Quene()
{

}
//��α���������
void InOrderTraverse(LinkTree T)
{
	Quene Q;
	Init_Quene(Q);


}
//���ƶ�����

//����ڵ���

//����Ҷ�ӽڵ�


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
	//����ǵݹ����
	cout << "����ǵݹ����������" << endl;
	Mid01OrderTraverse(T);
	cout << endl;
	//����ݹ����
	cout << "�������������" << endl;
	PostOrderTraverse(T);
	cout << endl;
	//��α�������������
	cout << "��α���������" << endl;
	InOrderTraverse(T);
	cout << endl;
	return 0;
}