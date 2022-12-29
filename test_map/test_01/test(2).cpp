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
//使用邻接矩阵法创建一个无向网
void creat_graph01(Graph& G)
{
	//输入顶点数和边数
	cout << "请输入顶点总数：";
	cin >> G.vexnum;
	cout << "请输入边的总数：";
	cin>> G.arcnum;
	cout << "请输入顶点：";
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
	cout << "请依次输入顶点，顶点和权值：" << endl;
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
//使用邻接表法创建一个无向图
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
	//输入顶点数和边数
	cout << "请输入顶点总数：";
	cin >> G.vexnum;
	cout << "请输入边的总数：";
	cin >> G.arcnum;
	cout << "请输入顶点：";
	for (int i = 0; i < G.vexnum; i++)
	{
		cin >> G.arcs[i].ch;
	}
	for (int i = 0; i < G.vexnum; i++)
	{
		G.arcs[i].firstarc = NULL;
	}
	cout << "请依次输入顶点，顶点和权重：" << endl;
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