#include <stdio.h>

int main()
{
	int n;
	float i, j;
	while (1)
	{
		system("cls");
		printf("��ѡ��Ҫִ�еĲ���:\n");
		printf("1. �ӷ�\n");
		printf("2. ����\n");
		printf("3. ����\n");
		printf("4. �˷�\n");
		printf("5. �˳�\n");
		scanf("%d", &n);
		

		switch (n)
		{
		case 1: 
			printf("��������������:\n");
			scanf("%f%f", &i, &j);
			printf("����֮��Ϊ %5.2f\n", i + j); system("pause");
			break;
		case 2:
			printf("��������������:\n");
			scanf("%f%f", &i, &j);
			printf("����֮��Ϊ %5.2f\n", i - j); system("pause");
			break;
		case 3:
			printf("��������������:\n");
			scanf("%f%f", &i, &j);
			printf("����֮��Ϊ %5.2f\n", i / j); system("pause");
			break;
		case 4:
			printf("��������������:\n");
			scanf("%f%f", &i, &j);
			printf("����֮��Ϊ %5.2f\n", i * j); system("pause");
			break;
		case 5:
			system("pause"); exit(0);
			break;
		default:
			printf("�������!\n"); system("pause");
			break;
		}
	}

	system("pause");
	return 0;
}