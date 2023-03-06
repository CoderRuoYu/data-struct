#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"
//����������������ϵ��

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
		printf("��������Ҫִ�еĲ���:>");
		scanf("%d", &n);
		switch (n)
		{
		case add:
			add_people(&arr);
			break;
		case search:
			ret = search_people(&arr);
			if (ret != -1)
				printf("��Ҫ���ҵ��������±�Ϊ%d\n", ret);
			else
				printf("����ͨѶ¼��û�ҵ������\n");
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
			printf("���ѳɹ��˳���");
			break;
		default:
			printf("\n");
			printf("����������������롣\n");
			break;
		}
	} while (n);
	return 0;
}