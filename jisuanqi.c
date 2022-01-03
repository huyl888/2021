#include <stdio.h>

int main()
{
	int n;
	float i, j;
	while (1)
	{
		system("cls");
		printf("请选择要执行的操作:\n");
		printf("1. 加法\n");
		printf("2. 减法\n");
		printf("3. 除法\n");
		printf("4. 乘法\n");
		printf("5. 退出\n");
		scanf("%d", &n);
		

		switch (n)
		{
		case 1: 
			printf("请输入两个数字:\n");
			scanf("%f%f", &i, &j);
			printf("两数之和为 %5.2f\n", i + j); system("pause");
			break;
		case 2:
			printf("请输入两个数字:\n");
			scanf("%f%f", &i, &j);
			printf("两数之差为 %5.2f\n", i - j); system("pause");
			break;
		case 3:
			printf("请输入两个数字:\n");
			scanf("%f%f", &i, &j);
			printf("两数之商为 %5.2f\n", i / j); system("pause");
			break;
		case 4:
			printf("请输入两个数字:\n");
			scanf("%f%f", &i, &j);
			printf("两数之积为 %5.2f\n", i * j); system("pause");
			break;
		case 5:
			system("pause"); exit(0);
			break;
		default:
			printf("输入错误!\n"); system("pause");
			break;
		}
	}

	system("pause");
	return 0;
}