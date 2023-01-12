#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
typedef struct Tree
{
	int data;
	struct Tree* lchild, * rchild;
}Tree, * LinkTree;
//初始化二叉树
void init_tree(LinkTree& T)
{
	T = NULL;
}
void insert_tree(LinkTree& T, int e)
{
	if (!T)
	{
		LinkTree p = new Tree;
		p->data = e;
		p->lchild = NULL;
		p->rchild = NULL;
		T = p;
	}
	else if (e <= T->data)
	{
		insert_tree(T->lchild, e);
	}
	else
	{
		insert_tree(T->rchild, e);
	}
}
//创建二叉排序树
void creat_tree(LinkTree& T)
{
	int n = 0;
	cout << "请输入您要创建二叉排序树的节点个数:";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int e = 0;
		cin >> e;
		insert_tree(T, e);
	}
}
//中序遍历二叉排序树
void mid_traverse(LinkTree& T)
{
	if (!T)return;
	mid_traverse(T->lchild);
	cout << T->data << ' ';
	mid_traverse(T->rchild);
}
//递归进行查找
LinkTree search_tree(LinkTree T,int key)
{
	if (!T)return T;
	if (T->data == key)return T;
	else if (key > T->data)return search_tree(T->rchild, key);
	else return search_tree(T->lchild, key);
}
//非递归进行查找
LinkTree search_tree1(LinkTree T, int key)
{
	if (!T)return T;
	LinkTree p = T;
	while (p != NULL && p->data != key)
	{
		if (p->data >= key)
		{
			p = p->lchild;
		}
		else
			p = p->rchild;
	}
	return p;
}
//删除二叉排序树
void delete_node(LinkTree T, int key)
{
	if (T == NULL)return;
	LinkTree par;
	LinkTree son = T;
	while (1)
	{
		if (son == NULL)return;
		par = son;
		if (key < son->data)
		{
			son = son->lchild;
		}
		else if (key > son->data)
		{
			son = son->rchild;
		}
		if (son->data == key)
		{
			break;
		}
	}
	if (!son->lchild && !son->rchild)
	{
		if (par->lchild == son)
			par->lchild = NULL;
		else if (par->rchild == son)
			par->rchild = NULL;
		return;
	}
	else if (!son->lchild && son->rchild)
	{
		if (par->lchild == son)
		{
			par->lchild = son->rchild;
			delete son;
		}
		else if (par->rchild == son)
		{
			par->rchild = son->rchild;
			delete son;
		}
		return;
	}
	else if (son->lchild && !son->rchild)
	{
		if (par->lchild == son)
		{
			par->lchild = son->lchild;
			delete son;
		}
		else if (par->rchild == son)
		{
			par->rchild = son->lchild;
			delete son;
		}
		return;
	}
	else
	{
		LinkTree tem = son;

		par = son;
		son = son->rchild;
		while (1)
		{
			if (son->lchild == NULL)
			{
				break;
			}
			par = son;
			son = son->lchild;
		}
		if (par->rchild == son)
		{
			par->rchild = son->rchild;
			delete son;
			return;
		}
		else
		{
			tem->data = son->data;
			par->lchild = NULL;
			delete son;
			return;
		}
	}
}
void test(LinkTree& T)
{
	//创建二叉排序树
	creat_tree(T);
	//中序遍历二叉排序树
	mid_traverse(T);
	cout << endl;
	int key = 0;
	cout << "请输入您要查找的数值:";
	cin >> key;
	LinkTree ret = search_tree1(T, key);
	if (!ret)cout << "在二叉排序树中不存在这个数。" << endl;
	else cout << "找到了这个数，这个数是:" << ret->data << endl;
	cout << endl;
	int e = 0;
	cout << "请输入您要删除的数字:";
	cin >> e;
	delete_node(T, e);
	//中序遍历二叉排序树
	mid_traverse(T);
	cout << endl;
}

int main()
{
	LinkTree T;
	init_tree(T);
	test(T);
	return 0;
}