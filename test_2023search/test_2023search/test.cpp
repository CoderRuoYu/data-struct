#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#define MAXSIZE 100
typedef struct Student
{
	int age;
}Stu;
typedef struct List
{
	Stu arr[MAXSIZE];
}List;
void s_search(List a, int x,int sz)
{
	for (int i = 0; i < sz; i++)
	{
		if (a.arr[i].age == x)
		{
			cout << i << endl;
			return;
		}
	}
	cout << 0;
	return;
}
void merge_search(List a, int x, int sz)
{
	int l = 0, r = sz - 1;
	while (l <= r)
	{
		int mid = l + r >> 1;
		if (a.arr[mid].age == x)
		{
			cout << mid << endl;
			return;
		}
		else
		{
			if (a.arr[mid].age < x)l = mid + 1;
			else r = mid ;
		}
	}
	cout << "Ã»ÕÒµ½" << endl;
}
int main()
{
	List a;
	a.arr[1] = { 0 };
	for (int i = 0; i < 3; i++)
	{
		cin >> a.arr[i].age;
	}
	int sz = sizeof(a.arr) / sizeof(a.arr[0]);
	for (int i = 0; i < 3; i++)
	{
		cout << a.arr[i].age << ' ';
	}
	cout << endl;
	int x = 0;
	cin >> x;
	s_search(a, x, 3);
	merge_search(a, x, 3);
	return 0;
}