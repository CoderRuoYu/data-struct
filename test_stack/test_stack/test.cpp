#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#define MAXSIZE 100
typedef struct Stack
{
	char data[MAXSIZE];
	int rear;
}Stack;
void InitStack(Stack& b)
{
	b.rear = 0;
}
void Push_Stack(Stack& b, char x)
{
	if (b.rear == MAXSIZE)
	{
		cout << "ջ����" << endl;
		return;
	}
	b.data[b.rear] = x;
	b.rear++;
}
int Pop_Stack(Stack& b, char& e)
{
	if (b.rear == 0)
	{
		//cout << "ջ��" << endl;
		return 0;
	}
	b.rear--;
	e = b.data[b.rear];
	return 1;
}
int main()
{
	Stack S;
	InitStack(S);
	char a[100];
	cout << "��������Ҫ�б���ַ���:";
	scanf("%s", a);
	int i = 0;
	while (a[i] != '\0')
	{
		if (a[i] == '[' || a[i] == '(' || a[i] == '{')
		{
			if (a[i] == '[')
				Push_Stack(S, ']');
			else if (a[i] == '(')
				Push_Stack(S, ')');
			else if (a[i] == '{')
				Push_Stack(S, '}');
		}
		else if (a[i] == ']' || a[i] == ')' || a[i] == '}')
		{
			char e;
			if (!Pop_Stack(S, e))
			{
				cout << "�б����" << endl;
				return 0;
			}
			if (e != a[i])
			{
				cout << "�б����" << endl;
				return 0;
			}
		}
		i++;
	}
	cout << "�б�ɹ�" << endl;
	return 0;
}