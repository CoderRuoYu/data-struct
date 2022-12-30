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