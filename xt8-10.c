#include <stdio.h>
int main()
{
	int a[5][5] = {
		{ 1,2,3,4,5 },
		{ 6,7,8,9,10 },
		{ 11,12,13,14,15 },
		{ 16,17,18,19,20 },
		{ 21,22,23,24,25 }
	};
	int i, j;
	void change_n(int(*p)[5]);
	for (i = 0; i<5; i++)
	{
		for (j = 0; j<5; j++)
		{
			printf("%3d", a[i][j]);
		}
		putchar('\n');
	}
	putchar('\n');
	change_n(a);
	for (i = 0; i<5; i++)
	{
		for (j = 0; j<5; j++)
		{
			printf("%3d", a[i][j]);
		}
		putchar('\n');
	}
	putchar('\n');

	system("pause");
}
void change_n(int(*p)[5])
{
	int i , j , k , max , min , temp ;
	i = j = k = max = min = temp = 0;

	for (i=0; i<5; i++)
	{
		for (j=0; j<5; j++)
		{
			if (*(*(p + i) + j)<*(*p))
			{
				temp = *(*p);
				*(*p) = *(*(p + i) + j);
				*(*(p + i) + j) = temp;
			}
			if (*(*(p + i) + j)>*(*(p + 2) + 2))
			{
				temp = *(*(p + 2) + 2);
				*(*(p + 2) + 2) = *(*(p + i) + j);
				*(*(p + i) + j) = temp;
			}
		}
	}
	for (i=0; i<5; i++)
	{
		for (j=0; j<5; j++)
		{
			if (i == 0 && j == 0)continue;
			if (i == 2 && j == 2)continue;
			else if (*(*(p + i) + j)<*(*p+4))
			{
				temp = *(*p+4);
				*(*p+4) = *(*(p + i) + j);
				*(*(p + i) + j) = temp;
			}
		}
	}
	for (i = 0; i<5; i++)
	{
		for (j = 0; j<5; j++)
		{
			if (i == 0 && j == 0)continue;
			if (i == 0 && j == 4)continue;
			if (i == 2 && j == 2)continue;
			else if (*(*(p + i) + j)<*(*(p + 4)))
			{
				temp = *(*(p + 4));
				*(*(p + 4)) = *(*(p + i) + j);
				*(*(p + i) + j) = temp;
			}
		}
	}	for (i = 0; i<5; i++)
	{
		for (j = 0; j<5; j++)
		{
			if (i == 0 && j == 0)continue;
			if (i == 0 && j == 4)continue;
			if (i == 2 && j == 2)continue;
			if (i == 4 && j == 0)continue;
			else if (*(*(p + i) + j)<*(*(p + 4) + 4))
			{
				temp = *(*(p + 4) + 4);
				*(*(p + 4) + 4) = *(*(p + i) + j);
				*(*(p + i) + j) = temp;
			}
		}
	}
}