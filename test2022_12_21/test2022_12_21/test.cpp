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
//初始化二叉树
void initTree(LinkTree& T)
{
	T = NULL;
}
//建立二叉树
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
			cout << "未申请到空间" << endl;
			return;
		}
		T->data = ch;
		creatTree(T->lchild);
		creatTree(T->rchild);
	}
}
//前序递归遍历
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
//中序递归遍历
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
//后序递归遍历
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
//栈的定义
typedef struct Stack
{
	LinkTree a[MAXSIZE];
	int rear;
}Stack;
//初始化栈
void InitStack(Stack& S)
{
	S.rear = 0;
}
//向栈中放入元素
void PushStack(Stack& S,LinkTree T)
{
	if (S.rear >= MAXSIZE)
	{
		cout << "栈已满，无法储存" << endl;
		return;
	}
	S.a[S.rear++] = T;
}
//判断栈是否为空，为空返回1，非空返回0
int is_stack_empty(Stack S)
{
	if (S.rear == 0)
	{
		return 1;
	}
	return 0;
}
//将栈中的元素弹出
LinkTree Pop_stack(Stack& S)
{
	if (is_stack_empty(S))
	{
		cout << "栈空,元素无法出栈" << endl;
		return NULL;
	}
	else
	{
		S.rear--;
		return S.a[S.rear];
	}
}
//中序非递归遍历二叉树
void Mid01OrderTraverse(LinkTree T)
{
	if (T == NULL)
	{
		cout << "该树为空树" << endl;
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
//定义队列
typedef struct Quene
{
	int front;
	int rear;
	LinkTree data[MAXSIZE];
}Quene;
//初始化队列
void Init_Quene(Quene& Q)
{
	Q.front = Q.rear = 0;
}
//入队操作
void Push_Quene(Quene & Q,LinkTree T)
{
	if ((Q.rear + 1) % MAXSIZE == Q.front)
	{
		cout << "队列已满，无法入队" << endl;
		return;
	}
	Q.data[Q.rear] = T;
	Q.rear = (Q.rear + 1) % MAXSIZE;
}
//出队操作
void Pop_Quene(Quene& Q, LinkTree& e)
{
	if (Q.front == Q.rear)
	{
		cout << "队空，无法出队" << endl;
		e = NULL;
		return;
	}
	e = Q.data[Q.front];
	Q.front = (Q.front + 1) % MAXSIZE;
}
//层次遍历二叉树
void InOrderTraverse(LinkTree T)
{
	if (T == NULL)
	{
		cout << "该树为空树" << endl;
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
//复制二叉树
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
//计算节点数
int numNodes(LinkTree T)
{
	if (T == NULL)
	{
		return 0;
	}
	else
		return numNodes(T->lchild) + numNodes(T->rchild) + 1;
}
//计算叶子节点
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

int main()
{
	LinkTree T;
	//创建二叉树
	creatTree(T);
	
	//前序遍历二叉树
	cout << "前序遍历二叉树" << endl;
	PreOrderTraverse(T);
	cout << endl;

	//中序递归遍历
	cout << "中序遍历二叉树" << endl;
	MidOrderTraverse(T);
	cout << endl;

	//中序非递归遍历
	cout << "中序非递归遍历二叉树" << endl;
	Mid01OrderTraverse(T);
	cout << endl;

	//后序递归遍历
	cout << "后序遍历二叉树" << endl;
	PostOrderTraverse(T);
	cout << endl;

	//层次遍历二叉树遍历
	cout << "层次遍历二叉树" << endl;
	InOrderTraverse(T);
	cout << endl;

	//拷贝二叉树
	LinkTree NewT;
	Copy_Tree(T, NewT);
	//计算二叉树的节点
	cout << "该树的节点个数为：" << numNodes(T) << endl;
	//计算二叉树的叶子节点
	cout << "该树的叶子节点个数为：" << numLeaves(T) << endl;
	return 0;
}