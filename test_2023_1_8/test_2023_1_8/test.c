#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
void test(int(*p)[3])
{
	printf("%d ", p[1][1]);
}
int main()
{
	int arr[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
	test(arr);
	return 0;
}