#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#define MAXSIZE 100
typedef struct Tree
{
	char data;
	struct Tree* lchild;
	struct Tree* rchild;
}TreeNode, * LinkTree;
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
LinkTree creat_tree(char prestr[], char instr[], int prestart, int preend, int instart, int inend)
{
	//if (prestart >= preend)return NULL;
	LinkTree p;
	p = new TreeNode;
	if (!p)cout << "ERROR" << endl;
	char temp = prestr[prestart];
	p->data = temp;
	p->lchild = NULL;
	p->rchild = NULL;
	int root = -1;
	for (root = instart; root <= inend && instr[root] != temp; root++);
	if (root > inend)return NULL;
	int lenleft = root - instart;
	if (lenleft)p->lchild = creat_tree(prestr, instr, prestart + 1, prestart + lenleft, instart, instart + lenleft - 1);
	int lenright = inend - root;
	if (lenright)p->rchild = creat_tree(prestr, instr, preend - lenright + 1, preend, inend - lenright + 1, inend);
	return p;
}
int main()
{
	//已知一颗二叉树的前序序列和中序序列分别存于两个一维数组中，试编写算法建立该二叉树的二叉链表
	cout << "请输入该树的节点个数" << endl;
	int nodenums = 0;
	cin >> nodenums;
	//前序序列
	char prestr[100];
	//中序序列
	char instr[100];
	cout << "请输入前序序列" << endl;
	for (int i = 1; i <= nodenums; i++)
	{
		cin >> prestr[i];
	}
	cout << "请输入中序序列" << endl;
	for (int i = 1; i <= nodenums; i++)
	{
		cin >> instr[i];
	}
	LinkTree gao = creat_tree(prestr, instr, 1, nodenums, 1, nodenums);
	//前序遍历二叉树
	cout << "前序遍历二叉树" << endl;
	PreOrderTraverse(gao);
	cout << endl;
	return 0;
}