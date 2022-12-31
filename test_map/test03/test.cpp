#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#define MVNUM 100
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
	cin >> G.arcnum;
	cout << "请输入顶点：";
	for (int i = 0; i < G.vexnum; i++)
	{
		cin >> G.vexs[i];
	}
	for (int i = 0; i < G.vexnum; i++)
	{
		for (int j = 0; j < G.vexnum; j++)
		{
			G.arcs[i][j] = 0;
		}
	}
	cout << "请依次输入顶点，顶点：" << endl;
	for (int w = 0; w < G.arcnum; w++)
	{
		char num1, num2;
		cin >> num1 >> num2;
		int i = Locate(G, num1);
		int j = Locate(G, num2);
		G.arcs[i][j] = 1;
	}
}
int visited[MVNUM];
void DFS(Graph G, int n)
{
	cout << G.vexs[n] << ' ';
	visited[n] = 1;
	for (int i = 0; i < G.vexnum; i++) {
		if (!visited[i] && G.arcs[n][i])
			DFS(G, i);
	}
}
int visited2[MVNUM];
void BFS(Graph G, int n)
{
	int quene[1000];//数组模拟队列
	int front = 0, rear = 0;
	cout << G.vexs[n] << ' ';
	visited2[n] = 1;
	quene[rear++] = n;
	while (front < rear)
	{
		int e = quene[front++];
		for (int i = 0; i < G.vexnum; i++) {
			if (G.arcs[n][i] == 1 && !visited[i]) {
				printf("%c ", G.vexs[i]);
				visited[i] = 1;
				rear++;
				quene[rear] = i;					//模拟入队
			}
		}
	}
}
int main()
{
	Graph G;
	creat_graph01(G);
	int i, j;
	scanf("%d %d", &i, &j);
	if (visited[j] == 1)cout << "存在" << endl;
	else
		cout << "不存在" << endl;
	if (visited2[j] == 1)cout << "存在" << endl;
	else
		cout << "不存在";
	return 0;
}