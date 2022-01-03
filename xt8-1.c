#include <stdio.h>
int main()
{
	int a[3], i, *p, j, t;
	p = a;
	printf("请输入 3 个整数:");
	for (i = 0; i<3; i++)
	{
		scanf("%d", &a[i]);
	}
	for (i = 0; i<3 - 1; i++)
	{
		for (j = i + 1; j<3; j++)
		{
			if (*(p + i)>*(p + j))
			{
				t = *(p + i);
				*(p + i) = *(p + j);
				*(p + j) = t;
			}
		}
	}
	for (i = 0; i < 3; i++)
	{
		printf("%-2d", a[i]);
	}
	printf("\n");

	system("pause");
}