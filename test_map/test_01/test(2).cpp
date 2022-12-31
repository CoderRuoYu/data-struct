#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#define MVNUM 100
#define Maxlnt 10000
#define ERROR -1
#define MAX_INT 30000
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
void prim(Graph G, int v0, int& sum) {
	int lowcaost[MVNUM];
	int visited[MVNUM];
	for (int i = 0; i < G.vexnum; i++) {
		visited[i] = 0;
		lowcaost[i] = G.arcs[v0][i];
	}
	visited[v0] = 1;
	int min = MAX_INT, index;
	for (int i = 0; i < G.vexnum - 1; i++) {
		for (int j = 0; j < G.vexnum; j++) {
			if (!visited[j] && lowcaost[j] < min) {
				min = lowcaost[j];
				index = j;
			}
		}
		visited[index] = 1;
		sum += min;
		for (int j = 0; j < G.vexnum; j++) {
			if (!visited[j] && G.arcs[index][j] < lowcaost[j]) {
				lowcaost[j] = G.arcs[index][j];
			}
		}
	}
	return;
}

int main()
{
	Graph G;
	creat_graph01(G);
	int sum = 0;
	prim(G, 0, sum);
	return 0;
}