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
		case 1:
			add(&arr);
			break;
		case 2:
			ret = search(&arr);
			if (ret != -1)
				printf("��Ҫ���ҵ��������±�Ϊ%d\n", ret);
			else
				printf("����ͨѶ¼��û�ҵ������\n");
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