#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#define MVNUM 100
#define Maxlnt 10000
#define ERROR -1
//使用邻接表法创建一个无向图
typedef struct arcs
{
	struct arcs* next;
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
		G.arcs[i].firstarc = NULL;
	}
	cout << "请依次输入顶点，顶点：" << endl;
	for (int w = 0; w < G.arcnum; w++)
	{
		char num1, num2;
		cin >> num1 >> num2;
		int i = Locate2(G, num1);
		int j = Locate2(G, num2);
		arcs* p = new arcs;
		p->locate = j;
		p->next = G.arcs[i].firstarc;
		G.arcs[i].firstarc = p;
		arcs* q = new arcs;
		q->locate = i;
		q->next = G.arcs[j].firstarc;
		G.arcs[j].firstarc = q;
	}
}
int visited[MVNUM];
void DFS(LinkGraph G, int n)
{
	cout << G.arcs[n].ch << ' ';
	visited[n] = 1;
	arcs* p = G.arcs[n].firstarc;
	while (p != NULL)
	{
		if (visited[p->locate] != 1)
			DFS(G, p->locate);
		p = p->next;
	}
}
int visited2[MVNUM];
void BFS(LinkGraph G, int n)
{
	int quene[1000];//数组模拟队列
	int front = 0, rear = 0;
	cout << G.arcs[n].ch << ' ';
	visited2[n] = 1;
	quene[rear++] = n;
	while (front < rear)
	{
		int e = quene[front++];
		arcs* p = G.arcs[e].firstarc;
		while (p != NULL)
		{
			if (visited2[p->locate] != 1)
			{
				cout << G.arcs[p->locate].ch << ' ';
				visited2[p->locate] = 1;
				quene[rear++] = p->locate;
			}
			p = p->next;
		}
	}
}
int main()
{
	LinkGraph G;
	creat_graph02(G);
	cout << "深度优先遍历：";
	DFS(G, 0);
	cout << endl;
	cout << "广度优先搜索：";
	BFS(G, 0);
	cout << endl;
	return 0;
}