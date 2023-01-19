#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"
//以名字排序所有联系人

void menu()
{
	printf("****************************\n");
	printf("*****1.add*******2.search***\n");
	printf("*****3.del*******4.modify***\n");
	printf("*****5.show******6.clear****\n");
	printf("*****7.sort******0.exit*****\n");
	printf("****************************\n");
}
int main()
{
	int n = 0;
	people arr;
	InitPeople(&arr);
	int ret = 0;
	do
	{
		menu();
		printf("请输入您要执行的操作:>");
		scanf("%d", &n);
		switch (n)
		{
		case 1:
			add(&arr);
			break;
		case 2:
			ret = search(&arr);
			if (ret != -1)
				printf("您要查找的人名的下标为%d\n", ret);
			else
				printf("您的通讯录中没找到这个人\n");
			break;
		case 3:
			del(&arr);
			break;
		case 4:
			modify(&arr);
			break;
		case 5:
			show(&arr);
			break;
		case 6:
			clear(&arr);
			break;
		case 7:
			sort_contact(&arr);
			break;
		case 0:
			printf("您已成功退出。");
			break;
		default:
			printf("\n");
			printf("输入错误，请重新输入。\n");
			
			break;
		}
	} while (n);
	return 0;
}