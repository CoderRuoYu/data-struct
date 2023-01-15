#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
void insert_sort(int arr[], int sz, int gap, int i)
{
	for (int w = i + gap; w < sz; w += gap)
	{
		if (arr[w] < arr[w - gap])
		{
			int tem = arr[w];
			int num = w - gap;
			while (tem < arr[num] && num >= 0)
			{
				arr[num + gap] = arr[num];
				num -= gap;
			}
			arr[num + gap] = tem;
		}
	}
}
void shell_sort(int arr[], int sz)
{
	for (int gap = sz / 2; gap > 0; gap /= 2)
	{
		for (int i = 0; i < gap; i++)
		{
			insert_sort(arr, sz, gap, i);
		}
	}
}
int main()
{
	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	shell_sort(arr, sz);
	for (int i = 0; i < 10; i++)printf("%d ", arr[i]);
	return 0;
}
