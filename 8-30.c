#include <stdio.h>
#include <stdlib.h>
int main()
{
	void check(int *);	//函数声明
	int * p1, i;	//p1是int型指针
	p1 = (int *)malloc(5 * sizeof(int)); //开辟动态内存区,将地址转换成int * 型,然后放在 p1 中
	for (i = 0; i<5; i++)
	{
		scanf_s("%d", p1 + i);	//输入5个学生的成绩
	}
	check(p1);

	system("pause");
}

void check(int *p)
{
	int i;
	printf("不及格的成绩为:");
	for (i = 0; i<5; i++)
	{
		if (p[i]<60)
			printf("%d ", p[i]);
	}
	printf("\n");
}