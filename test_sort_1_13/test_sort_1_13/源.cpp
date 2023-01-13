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

//œ£∂˚≈≈–Ú


//—°‘Ò≈≈–Ú

//√∞≈›≈≈–Ú

//∂—≈≈–Ú

//øÏÀŸ≈≈–Ú

//void mid_sort(int arr[], int sz)
//{
//	for (int i = 1; i < sz; i++)
//	{
//		int l = 0;
//		int r = i - 1;
//		int mid = l + r >> 1;
//		                                                 
//	}
//	
//}
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
	mid_sort(arr, sz);
	print(arr, sz);
	
	return 0;
}