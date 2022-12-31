#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<malloc.h>
#include<string.h>
#define DateType char
#define MAXSIZE 100   

typedef struct CSNode
{
	DateType data;
	struct CSNode* firdtchild;
	struct CSNode* nextsbling;
}CSNode, * CSTree;
typedef struct SeqQueue
{
	CSTree data[MAXSIZE];
	int front, rear;
}SeqQueue, * PSeqQueue;

PSeqQueue  Init_SeqQueue()
{
	PSeqQueue Q;
	Q = (PSeqQueue)malloc(sizeof(SeqQueue));
	if (Q)
	{
		Q->front = 0;
		Q->rear = 0;
	}
	return Q;
}


int Empty_SeqQueue(PSeqQueue Q)
{
	if (Q && Q->front == Q->rear)
		return (1);
	else
		return (0);
}

int In_SeqQueue(PSeqQueue Q, CSTree  x)
{
	if ((Q->rear + 1) % MAXSIZE == Q->front)
	{
		printf("队满");
		return -1;   
	}
	else
	{
		Q->rear = (Q->rear + 1) % MAXSIZE;
		Q->data[Q->rear] = x;
		return 1;   
	}
}
CSTree Out_SeqQueue(PSeqQueue Q)
{
	CSTree x;
	x = (CSTree)malloc(sizeof(CSNode));
	if (Empty_SeqQueue(Q)) {
		printf("队空");
		return NULL;   
	}
	else
	{
		Q->front = (Q->front + 1) % MAXSIZE;
		x = Q->data[Q->front];
		return x;    
	}
}
CSTree CreateTree()  
{
	CSTree T;
	T = (CSTree)malloc(sizeof(CSNode));
	PSeqQueue Q;
	Q = Init_SeqQueue();
	char buffChild[20] = { '\0' }; 
	printf("请输入根结点:\n");
	scanf("%c", &buffChild[0]);
	if (buffChild[0] != '#')
	{
		T->data = buffChild[0];
		T->nextsbling = NULL;  
		In_SeqQueue(Q, T);  

		while (!Empty_SeqQueue(Q))
		{
			CSTree e;
			e = Out_SeqQueue(Q);
			printf("请按输入结点%c的孩子:\n", e->data);
			scanf("%s", buffChild);
			if (buffChild[0] != '#')
			{
				CSTree q, p;
				q = p = (CSTree)malloc(sizeof(CSNode)); 
				if (!q)
					return 0;
				q->data = buffChild[0];  
				e->firdtchild = q;  
				In_SeqQueue(Q, q); 
				p = q; 
				for (size_t i = 1; i < strlen(buffChild) - 1; ++i) 
				{
					q = (CSTree)malloc(sizeof(CSNode)); 
					if (!q)
						return 0;
					q->data = buffChild[i];
					p->nextsbling = q;
					In_SeqQueue(Q, q);
					p = q;       
				}
				p->nextsbling = NULL;

			}

			else
			{
				e->firdtchild = NULL;
			}

		}
	}
	else
	{
		T = NULL;
	}
	return T;
}
int main()
{
	CSTree T;
	T = CreateTree();
	return 0;
}

