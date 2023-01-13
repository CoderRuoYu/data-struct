#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
//÷±Ω”≤Â»Î≈≈–Ú
void insert_sort(int arr[], int sz)
{
	for (int i = 1; i < sz; i++)
	{
		int j = 0;
		int tem = arr[i];
		for (j = i - 1; j >= 0; j--)
		{
			if (arr[j] > tem)
			{
				arr[j + 1] = arr[j];
			}
			else
			{
				break;
			}
		}
		arr[j + 1] = tem;
	}
}
//’€∞Î≤Â»Î≈≈–Ú
void mid_insert_sort(int arr[], int sz)
{
	for (int i = 1; i < sz; i++)
	{
		int tem = arr[i];
		int l = 0;
		int r = i - 1;
		
		while (l <= r)
		{
			int mid = l + r >> 1;
			if (arr[mid] < tem)
			{
				l = mid + 1;
			}
			else
			{
				r = mid - 1;
			}
		}
		for (int w = i - 1; w > r; w--)
		{
			arr[w + 1] = arr[w];
		}
		arr[r + 1] = tem;
	}
}
//œ£∂˚≈≈–Ú


//—°‘Ò≈≈–Ú
void select_sort(int arr[], int sz)
{
	for (int i = 0; i < sz; i++)
	{
		int min = i;
		for (int j = i + 1; j < sz; j++)
		{
			if (arr[j] < arr[min])
			{
				min = j;
			}
		}
		int tem = arr[min];
		arr[min] = arr[i];
		arr[i] = tem;
	}
}
//√∞≈›≈≈–Ú
void bubble_sort(int arr[], int sz)
{
	for (int i = 0; i < sz - 1; i++)
	{
		for (int j = 0; j < sz - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int tem = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tem;
			}
		}
	}
}
//∂—≈≈–Ú

//øÏÀŸ≈≈–Ú
void quick_sort(int arr[], int l, int r)
{
	if (l >= r)return;
	int x = arr[l + r >> 1];
	int i = l - 1;
	int j = r + 1;
	while (i < j)
	{
		do i++; while (arr[i] < x);
		do j--; while (arr[j] > x);
		if (i < j)
		{
			int tem = arr[i];
			arr[i] = arr[j];
			arr[j] = tem;
		}
	}
	quick_sort(arr, l, j);
	quick_sort(arr, j + 1, r);
}

void print(int arr[], int sz)
{
	for (int i = 0; i < sz; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;
}
int main()
{
	int arr[10] = { 6,4,8,2,7,1,3,6,9,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	//insert_sort(arr, sz);
	//mid_insert_sort(arr, sz);
	//select_sort(arr, sz);
	//bubble_sort(arr, sz);
	//quick_sort(arr, 0, sz - 1);
	print(arr, sz);
	
	return 0;
}