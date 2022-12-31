#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
void quick_sort(int arr[], int l, int r)
{
	if (l >= r)return;
	int mid = l + r >> 1;
	int i = l - 1;
	int j = r + 1;
	while (i < j)
	{
		do i++; while (arr[i] < arr[mid]);
		do j--; while (arr[j] > arr[mid]);
		if (i < j)
		{
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	quick_sort(arr, l, j);
	quick_sort(arr, j + 1, r);
}
int merge[100];
void merge_sort(int arr[], int l, int r)
{
	if (l >= r)return;
	int mid = l + r >> 1;
	int i = l;
	int j = mid + 1;
	int k = 0;
	merge_sort(arr, l, mid);
	merge_sort(arr, mid + 1, r);
	while (i <= mid && j <= r)
	{
		if (arr[i] < arr[j])merge[k++] = arr[i++];
		else merge[k++] = arr[j++];
	}
	while (i <= mid)merge[k++] = arr[i++];
	while (j <= r)merge[k++] = arr[j++];
	for (int w = l, k = 0; w <= r; w++, k++)
	{
		arr[w] = merge[k];
	}
}
void bubble_sort(int arr[], int len) {
	int  temp;
	int i, j;
	for (i = 0; i < len - 1; i++)
	{
		for (j = 0; j < len - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
void HeapAdjust(int* arr, int start, int end)
{
	int tmp = arr[start];
	for (int i = 2 * start + 1; i <= end; i = i * 2 + 1)
	{
		if (i < end && arr[i] < arr[i + 1])
		{
			i++;
		}
		if (arr[i] > tmp)
		{
			arr[start] = arr[i];
			start = i;
		}
		else
		{
			break;
		}
	}
	arr[start] = tmp;
}
void heap_sort(int* arr, int len)
{
	for (int i = (len - 1 - 1) / 2; i >= 0; i--)
	{
		HeapAdjust(arr, i, len - 1);
	}
	int tmp;
	for (int i = 0; i < len - 1; i++)
	{
		tmp = arr[0];
		arr[0] = arr[len - 1 - i];
		arr[len - 1 - i] = tmp;
		HeapAdjust(arr, 0, len - 1 - i - 1);
	}
}
void select_sort(int arr[], int n) {
	for (int i = 0; i < n - 1; i++) { 
		int min = i; 
		for (int j = i + 1; j < n; j++) { 
			if (arr[j] < arr[min]) { 
				min = j;
			}
		}
		if (min != i) { 
			swap(arr[i], arr[min]);
		}
	}
}
void BinaryInsertSort(int array[], int size)
{
	int high;
	int low;
	int mid;
	int i;
	int j;
	int temp;
	for (i = 1; i < size; i++)
	{
		temp = array[i];
		high = i - 1;
		low = 0;
		while (low <= high)
		{
			mid = (low + high);
			if (array[mid] < temp)
			{
				low = mid + 1;
			}
			else
			{
				high = mid - 1;
			}
		}
		for (j = i; j >= low; j--)
		{
			array[j] = array[j - 1];
		}
		array[low] = temp;
	}
}
int main()
{
	int a[] = { 1,5,2,6,3,4,9,8,7 };
	int sz = sizeof(a) / sizeof(a[0]);
	// ’€∞Î≤Â»Î≈≈–Ú
	cout << "’€∞Î≤Â»Î≈≈–Ú:";
	bubble_sort(a, sz);
	for (int i = 0; i < sz; i++)cout << a[i] << ' ';
	cout << endl;
	// √∞≈›≈≈–Ú
	cout << "√∞≈›≈≈–Ú:";
	bubble_sort(a, sz);
	for (int i = 0; i < sz; i++)cout << a[i] << ' ';
	cout << endl;
	// øÏÀŸ≈≈–Ú
	cout << "øÏÀŸ≈≈–Ú:";
	quick_sort(a, 0, sz - 1);
	for (int i = 0; i < sz; i++)cout << a[i] << ' ';
	cout << endl;
	// ºÚµ•—°‘Ò≈≈–Ú
	cout << "ºÚµ•—°‘Ò≈≈–Ú:";
	select_sort(a, sz);
	for (int i = 0; i < sz; i++)cout << a[i] << ' ';
	cout << endl;
	// πÈ≤¢≈≈–Ú
	cout << "ºÚµ•πÈ≤¢≈≈–Ú:";
	merge_sort(a, 0, sz - 1);
	for (int i = 0; i < sz; i++)cout << a[i] << ' ';
	cout << endl;
	// ∂—≈≈–Ú
	cout << "∂—≈≈–Ú:";
	heap_sort(a, sz);
	for (int i = 0; i < sz; i++)cout << a[i] << ' ';
	cout << endl;
	return 0;
}