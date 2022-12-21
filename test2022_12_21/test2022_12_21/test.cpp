#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
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
		PreOrderTraverse(T->lchild);
		cout << T->data << ' ';
		PreOrderTraverse(T->rchild);
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
//层次遍历二叉树

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
	//后序递归遍历
	cout << "后序遍历二叉树" << endl;
	PostOrderTraverse(T);
	cout << endl;
	return 0;
}