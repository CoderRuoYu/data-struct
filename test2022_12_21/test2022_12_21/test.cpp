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
	LinkTree data[MAXSIZE];
}Quene;
//��ʼ������
void Init_Quene(Quene& Q)
{
	Q.front = Q.rear = 0;
}
//��Ӳ���
void Push_Quene(Quene & Q,LinkTree T)
{
	if ((Q.rear + 1) % MAXSIZE == Q.front)
	{
		cout << "�����������޷����" << endl;
		return;
	}
	Q.data[Q.rear] = T;
	Q.rear = (Q.rear + 1) % MAXSIZE;
}
//���Ӳ���
void Pop_Quene(Quene& Q, LinkTree& e)
{
	if (Q.front == Q.rear)
	{
		cout << "�ӿգ��޷�����" << endl;
		e = NULL;
		return;
	}
	e = Q.data[Q.front];
	Q.front = (Q.front + 1) % MAXSIZE;
}
//��α���������
void InOrderTraverse(LinkTree T)
{
	if (T == NULL)
	{
		cout << "����Ϊ����" << endl;
		return;
	}
	Quene Q;
	Init_Quene(Q);
	Push_Quene(Q, T);
	while (Q.front != Q.rear)
	{
		LinkTree e = NULL;
		Pop_Quene(Q, e);
		cout << e->data << ' ';
		if (e->lchild != NULL)
		{
			Push_Quene(Q, e->lchild);
		}
		if (e->rchild != NULL)
		{
			Push_Quene(Q, e->rchild);
		}
	}
}
//���ƶ�����
void Copy_Tree(LinkTree T, LinkTree& NewT)
{
	if (T == NULL)
	{
		NewT = NULL;
		return;
	}
	NewT = new TreeNode;
	NewT->data = T->data;
	Copy_Tree(T->lchild, NewT->lchild);
	Copy_Tree(T->rchild, NewT->rchild);
}
//����ڵ���
int numNodes(LinkTree T)
{
	if (T == NULL)
	{
		return 0;
	}
	else
		return numNodes(T->lchild) + numNodes(T->rchild) + 1;
}
//����Ҷ�ӽڵ�
int numLeaves(LinkTree T)
{
	if (T == NULL)
		return 0;
	if (T->lchild == NULL && T->rchild == NULL)
	{
		return 1;
	}
	else
		return numLeaves(T->lchild) + numLeaves(T->rchild);
}
int Depth_tree(LinkTree T)
{
	if (T == NULL)
		return 0;
	int i = Depth_tree(T->lchild);
	int j = Depth_tree(T->rchild);
	if (i > j)
		return i + 1;
	else
		return j + 1;
}

LinkTree creat_tree(char prestr[], char instr[], int prestart, int preend, int instart, int inend)
{
	//if (prestart >= preend)return NULL;
	LinkTree p;
	p = new TreeNode;
	if (!p)cout << "ERROR" << endl;
	char temp = prestr[prestart];
	p->data = prestr[prestart];
	p->lchild = NULL;
	p->rchild = NULL;
	int root = -1;
	for (int root = instart; root <= inend && instr[root] != temp; root++);
	if (root > inend)return NULL;
	int lenleft = root - instart;
	if (lenleft)p->lchild = creat_tree(prestr, instr, prestart + 1, prestart + lenleft, instart, instart + lenleft - 1);
	int lenright = inend - root;
	if (lenright)p->rchild = creat_tree(prestr, instr, prestart - lenright + 1, preend, inend - lenright + 1, inend);
	return p;
}
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

	//����������
	LinkTree NewT;
	Copy_Tree(T, NewT);
	//����������Ľڵ�
	cout << "�����Ľڵ����Ϊ��" << numNodes(T) << endl;
	//�����������Ҷ�ӽڵ�
	cout << "������Ҷ�ӽڵ����Ϊ��" << numLeaves(T) << endl;
	//���������
	cout << "�������Ϊ��" << Depth_tree(T) << endl;

	//��֪һ�Ŷ�������ǰ�����к��������зֱ��������һά�����У��Ա�д�㷨�����ö������Ķ�������
	cout << "����������Ľڵ����" << endl;
	int nodenums = 0;
	cin >> nodenums;
	//ǰ������
	char prestr[100];
	//��������
	char instr[100];
	cout << "������ǰ������" << endl;
	for (int i = 1; i <= nodenums; i++)
	{
		cin >> prestr[i];
	}
	cout << "��������������" << endl;
	for (int i = 1; i <= nodenums; i++)
	{
		cin >> instr[i];
	}
	LinkTree gao = creat_tree(prestr, instr, 1, nodenums, 1, nodenums);
	//ǰ�����������
	cout << "ǰ�����������" << endl;
	PreOrderTraverse(gao);
	cout << endl;
	return 0;
}