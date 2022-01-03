#include <stdio.h>
int main()
{
	float average(float a[][5]);
	float T_fail(float a[][5]);
	float reach_9(float a[][5]);
	float score[4][5];
	int i, j;
	printf("请分别输入每个学生的成绩:\n");
	for (i = 0; i<4; i++)
	{
		printf("No.%d:", i + 1);
		for (j = 0; j<5; j++)
		{
			scanf("%f", &score[i][j]);
		}
	}
	average(score);
	T_fail(score);
	reach_9(score);

	system("pause");
	return 0;
}

float average(float a[][5])
{
	float(*p)[5], total;
	int i, k;
	p = a;
	printf("要求那门课的平均分:");
	scanf("%d", &k);
	total = 0;
	for (i = 0; i<4; i++)
	{
		total += *(*(p + i) + k - 1);
	}
	printf("第 %d 门课的平均成绩为%5.2f.\n", k, total / 4);
}

float T_fail(float a[][5])
{
	float(*p)[5];
	int i, j, k;
	p = a;
	for (i = 0; i<4; i++)
	{
		k = 0;
		for (j = 0; j<5; j++)
		{
			if (*(*(p + i) + j)<60)
			{
				k++;
			}
		}
		if (k >= 2)
		{
			printf("第 %d 名有两门课不合格,所有成绩为:", i + 1);
			for (j = 0; j<5; j++)
			{
				printf("%5.2f ", *(*(p + i) + j));
			}
			printf("\n");
		}
	}
}

float reach_9(float a[][5])
{
	float(*p)[5], total, aver;
	p = a;
	int i, j, k;
	for (i = 0; i<4; i++)
	{
		total = aver = 0;
		k = 0;
		for (j = 0; j<5; j++)
		{
			if (*(*(p + i) + j)<85)
			{
				k++;
			}
			total += *(*(p + i) + j);
		}
		aver = total / 5;
		if (k == 0 || aver>90)
		{
			printf("成绩优秀的为第 %d 名,成绩为:\n", i + 1);
			for (j = 0; j<5; j++)
			{
				printf("%5.2f ", *(*(p + i) + j));
			}
			printf("\n");
		}
	}
}