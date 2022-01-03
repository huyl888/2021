#include <stdio.h>
int main()
{
	void tran(int a[][3]);
	int a[3][3] = { { 1,2,3 },{ 4,5,6 },{ 7,8,9 } };
	int i, j;
	for (i = 0; i<3; i++)
	{
		for (j = 0; j<3; j++)
		{
			printf("%2d", a[i][j]);
		}
		printf("\n");
	}
	tran(a);
	printf("\n");
	for (i = 0; i<3; i++)
	{
		for (j = 0; j<3; j++)
		{
			printf("%2d", a[i][j]);
		}
		printf("\n");
	}

	system("pause");
}

void tran(int a[][3])
{
	int(*p)[3], i, j, t;
	i = 0;
	p = a;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < i; j++)
		{
			if (i == j) { continue; }
			t = *(*(p + i) + j);
			*(*(p + i) + j) = *(*(p + j) + i);
			*(*(p + j) + i) = t;
		}
	}
}