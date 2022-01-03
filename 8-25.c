#include <stdio.h>
int main()
{
	float score[][4] = { { 60,70,80,90 },{ 56,89,67,88 },{ 34,78,90,66 } };//定义数组,存放成绩
	float *p;	//定义指针变量
	int i, k;
	float *search(float(*p)[4], int n);//声明函数
	printf("请输入要查询的学生学号:");
	scanf_s("%d", &k);	//输入要查询的学生学号
	p = search(score, k);//调用函数返回值
	printf("第%d个学生的成绩为:", k);
	for (i = 0; i<4; i++)
	{
		printf("%5.2f ", *(p + i));//输出各课成绩
	}
	putchar('\n');

	system("pause");
	return 0;
}

float *search(float(*pointer)[4], int n)//形参pointer是指向一维数组的指针变量
{
	float *pt;
	pt = *(pointer + n-1);	//pt的值是 &score[n][0]
	return(pt);
}