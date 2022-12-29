#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#define MVNUM 100
#define Maxlnt 10000
#define ERROR -1
typedef struct Graph
{
	char vexs[MVNUM];
	int arcs[MVNUM][MVNUM];
	int vexnum, arcnum;
}Graph;
int Locate(Graph G, char x)
{
	for (int i = 0; i < G.vexnum; i++)
	{
		if (G.vexs[i] == x)
		{
			return i;
		}
	}
	return ERROR;
}
//ʹ���ڽӾ��󷨴���һ��������
void creat_graph01(Graph& G)
{
	//���붥�����ͱ���
	cout << "�����붥��������";
	cin >> G.vexnum;
	cout << "������ߵ�������";
	cin>> G.arcnum;
	cout << "�����붥�㣺";
	for (int i = 0; i < G.vexnum; i++)
	{
		cin >> G.vexs[i];
	}
	for (int i = 0; i < G.vexnum; i++)
	{
		for (int j = 0; j < G.vexnum; j++)
		{
			G.arcs[i][j] = Maxlnt;
		}
	}
	cout << "���������붥�㣬�����Ȩֵ��" << endl;
	for (int w = 0; w < G.arcnum; w++)
	{
		char num1, num2;
		int weight;
		cin >> num1 >> num2 >> weight;
		int i = Locate(G, num1);
		int j = Locate(G, num2);
		G.arcs[i][j] = weight;
		G.arcs[j][i] = weight;
	}
}
//ʹ���ڽӱ�����һ������ͼ
typedef struct arcs
{
	struct arcs* next;
	int info;
	int locate;
}arcs;
typedef struct vexs
{
	char ch;
	struct arcs* firstarc;
}vexs;
typedef struct
{
	vexs arcs[MVNUM];
	int arcnum, vexnum;
}LinkGraph;
int Locate2(LinkGraph G, char ch)
{
	for (int i = 0; i < G.vexnum; i++)
	{
		if (G.arcs[i].ch == ch)
			return i;
	}
	return ERROR;
}
void creat_graph02(LinkGraph& G)
{
	//���붥�����ͱ���
	cout << "�����붥��������";
	cin >> G.vexnum;
	cout << "������ߵ�������";
	cin >> G.arcnum;
	cout << "�����붥�㣺";
	for (int i = 0; i < G.vexnum; i++)
	{
		cin >> G.arcs[i].ch;
	}
	for (int i = 0; i < G.vexnum; i++)
	{
		G.arcs[i].firstarc = NULL;
	}
	cout << "���������붥�㣬�����Ȩ�أ�" << endl;
	for (int w = 0; w < G.arcnum; w++)
	{
		char num1, num2;
		int weight;
		cin >> num1 >> num2 >> weight;
		int i = Locate2(G, num1);
		int j = Locate2(G, num2);

		arcs* p = new arcs;
		p->info = weight;
		p->locate = j;
		p->next = G.arcs[i].firstarc;
		G.arcs[i].firstarc = p;

		arcs* q = new arcs;
		q->info = weight;
		q->locate = i;
		q->next = G.arcs[j].firstarc;
		G.arcs[j].firstarc = q;
	}
}
int main()
{
	Graph G;
	creat_graph01(G);
	LinkGraph G1;
	//creat_graph02(G1);
	return 0;
}