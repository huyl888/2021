#include <stdio.h>
//#define MAX 1000

int main()
{
	//int a[MAX];
	int *a;
	int n, i, out = 0, num, j = 0;//(n是参与人数,i是循环变量,out是出圈人数.num是报数到第几人
	printf("Enter the number of people:");
	scanf("%d", &n);
	a = (int *)malloc(n * sizeof(int));//建立动态数组
	for (i = 0; i < n; i++)                                    
	{
		a[i] = i + 1;	//给每个人编号(从1开始)
	}
	for (i = 0, num = 1; (n - out) != 1; i = (i + 1) % (n - out), num++)//num是人的序号,out是出圈人数,核心内容在于i=(i+1)%(n-out);目的是让i自动归零,n-out为现有人数,
	{
		if (num % 3 == 0)
		{
			for (j = i; j < n - out; j++)                          //将后面的人往前补空
				a[j] = a[j + 1];
			out++;
			num++;
		}
	}
	printf("The last one is No.%d.\n", a[0]);                             //最后一个人

	system("pause");
	return 0;
}