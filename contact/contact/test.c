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
enum number
{
	exit,
	add,
	search,
	del,
	modify,
	show,
	clear,
	sort
};


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
		case add:
			add_people(&arr);
			break;
		case search:
			ret = search_people(&arr);
			if (ret != -1)
				printf("您要查找的人名的下标为%d\n", ret);
			else
				printf("您的通讯录中没找到这个人\n");
			break;
		case del:
			del_people(&arr);
			break;
		case modify:
			modify_people(&arr);
			break;
		case show:
			show_people(&arr);
			break;
		case clear:
			clear_people(&arr);
			break;
		case sort:
			sort_contact(&arr);
			break;
		case exit:
			destroy_contact(&arr);
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