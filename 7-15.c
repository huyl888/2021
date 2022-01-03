#undef UNICODE
#undef _UNICODE //取消 Unicode 编码的宏定义,让后续编码都以 MBCS 编码编译

#include <stdio.h>
#include <stdlib.h>

//定义全局变量及函数声明
char show_n[8] = { " " }, query_n[8] = { " " }, name[10][8] = { { " " } }; //两个字符为一个汉字按四个汉字一个姓名,8个为个人名
char show_jn[13] = { " " }, query_jn[13] = { " " }, job_number[10][13] = { { " " } };
void clear_show();
void input_mes();
void show_query();
void show_main();
void query_name();

void print_star()
{
	int i;
	for (i = 0; i < 80; i++)
	{
		printf("*");
	}
	printf("\n");
}

void show_main()
{
	system("cls");
	print_star();
	printf("\n");
	printf("%52s\n", "欢迎使用本员工管理系统\n");
	print_star();
	printf("\n");
	printf("%48s\n", "1. 输入员工信息\n");
	printf("%48s\n", "2. 查询员工信息\n");
	printf("%44s\n", "3. 退出系统\n");
	print_star();
	int c1;
	scanf("%d", &c1);
	switch (c1)
	{
	case 1:
		clear_show();
		input_mes();
		break;
	case 2:
		clear_show();
		show_query();
		break;
	case 3:
		return 0;
	}
}

void rank()
{
	int i;
	for (i = 0; i<10; i++)
	{
		strcpy(query_jn, job_number[i]);
		strcpy(show_jn, job_number[i+1]);
		strcpy(query_n, name[i]);
		strcpy(show_n, name[i + 1]);
		if (strcmp(query_jn,show_jn)>0)
		{
			strcpy(job_number[i], show_jn);
			strcpy(job_number[i + 1], query_jn);
			strcpy(name[i], show_n);
			strcpy(name[i + 1], query_n);
		}
	}
}

void input_mes()
{
	int i;
	for (i = 0; i < 2; i++)
	{
		printf("请输入No.%d的姓名:\n", i + 1);
		scanf("%s", &show_n);
		strcpy(name[i], show_n);

		printf("请输入No.%d工号:\n", i + 1);
		scanf("%s", &show_jn);
		strcpy(job_number[i], show_jn);
	}
	rank();
	show_main();
}

void clear_show()
{
	system("cls");
}

void query_job()
{
	clear_show();
	printf("请输入工号:\n");
	scanf("%s", &query_jn);
	int i, n;
	for (i = 0; i < 10; i++)
	{
		if (strcmp(query_jn, job_number[i]) == 0)
		{
			break;
		}
	}
	printf("工号:%s 的姓名为: %s\n", job_number[i], name[i]);
	system("pause");
	show_main();
}

void show_query()
{
	system("cls");
	print_star();
	printf("%52s\n", "欢迎使用本员工管理系统\n");
	print_star();
	printf("%48s\n", "1. 按姓名查询\n");
	printf("%48s\n", "2. 按工号查询\n");
	print_star();
	int c1;
	scanf("%d", &c1);
	switch (c1)
	{
	case 1:
		clear_show();
		query_name();
		break;
	case 2:
		clear_show();
		query_job();
	}
}

void query_name()
{
	clear_show();
	printf("请输入姓名:\n");
	scanf("%s", &query_n);
	int i, n;
	for (i = 0; i < 10; i++)
	{
		if (strcmp(query_n, name[i]) == 0)
		{
			break;
		}
	}
	strcpy(show_jn, job_number[1]);
	printf("%s 的工号为: %s\n", name[i], job_number[i]);
	system("pause");
	show_main();
}

int main()
{
	show_main();
}