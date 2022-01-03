#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSNUM 10
struct Student {
	int num;
	char name[20];
	int score[3];
	int average;
};

int main()
{
	struct Student stu[MAXSNUM];
	int nf[3];
	int * p1;
	p1 = nf;
	void print(struct Student stu[], int n, int *nf);
	void input(struct Student stu[], int n, int *nf);
	input(stu, MAXSNUM, p1);
	putchar('\n');
	print(stu, MAXSNUM, p1);

	system("pause");
	return 0;
}

void input(struct Student stu[], int n, int *nf)
{
	int aver0 = 0, aver1 = 0, aver2 = 0, mav0 = 0, mav1 = 0, mav2 = 0;
	int mf0 = 0, mf1 = 0, mf2 = 0;
	for (int i = 0; i < n; i++)
	{
		printf("请输入 No.%d 的信息:\n", i + 1);
		printf("学号:");
		scanf("%d", &stu[i].num);
		printf("姓名:");
		scanf("%s", stu[i].name);
		printf("三门课成绩(用空格间隔开):");
		scanf("%d%d%d", &stu[i].score[0], &stu[i].score[1], &stu[i].score[2]);
		stu[i].average = (stu[i].score[0] + stu[i].score[1] + stu[i].score[2]) / 3;
		aver0 = aver0 + stu[i].score[0];
		aver1 = aver1 + stu[i].score[1];
		aver2 = aver2 + stu[i].score[2];
		if (mav0<stu[i].score[0])
		{
			mav0 = stu[i].score[0];
			mf0 = i;
		}
		if (mav1<stu[i].score[1])
		{
			mav1 = stu[i].score[1];
			mf1 = i;
		}
		if (mav2<stu[i].score[2])
		{
			mav2 = stu[i].score[2];
			mf2 = i;
		}
	}
	*nf = mf0; nf++;
	*nf = mf1; nf++;
	*nf = mf2;
	putchar('\n');
	printf("scoreA 平均分: %d\nscoreB 平均分: %d\nscoreC 平均分: %d\n", aver0 / n, aver1 / n, aver2 / n);
}

void print(struct Student stu[], int n, int *nf)
{
	int i, j , k;
	for (k = 0; k < 3; k++)
	{
		i = *nf;
		printf("No.%d 学号: %-2d 姓名: %s", i + 1, stu[i].num, stu[i].name);
		for (j = 0; j < 3; j++)
		{
			printf(" score_%d: %d", j + 1, stu[i].score[j]);
		}
		nf++;
		putchar('\n');
	}
}