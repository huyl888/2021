#undef UNICODE
#undef _UNICODE //ȡ�� Unicode ����ĺ궨��,�ú������붼�� MBCS �������

#include <stdio.h>
#include <stdlib.h>

//����ȫ�ֱ�������������
char show_n[8] = { " " }, query_n[8] = { " " }, name[10][8] = { { " " } }; //�����ַ�Ϊһ�����ְ��ĸ�����һ������,8��Ϊ������
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
	printf("%52s\n", "��ӭʹ�ñ�Ա������ϵͳ\n");
	print_star();
	printf("\n");
	printf("%48s\n", "1. ����Ա����Ϣ\n");
	printf("%48s\n", "2. ��ѯԱ����Ϣ\n");
	printf("%44s\n", "3. �˳�ϵͳ\n");
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
		printf("������No.%d������:\n", i + 1);
		scanf("%s", &show_n);
		strcpy(name[i], show_n);

		printf("������No.%d����:\n", i + 1);
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
	printf("�����빤��:\n");
	scanf("%s", &query_jn);
	int i, n;
	for (i = 0; i < 10; i++)
	{
		if (strcmp(query_jn, job_number[i]) == 0)
		{
			break;
		}
	}
	printf("����:%s ������Ϊ: %s\n", job_number[i], name[i]);
	system("pause");
	show_main();
}

void show_query()
{
	system("cls");
	print_star();
	printf("%52s\n", "��ӭʹ�ñ�Ա������ϵͳ\n");
	print_star();
	printf("%48s\n", "1. ��������ѯ\n");
	printf("%48s\n", "2. �����Ų�ѯ\n");
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
	printf("����������:\n");
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
	printf("%s �Ĺ���Ϊ: %s\n", name[i], job_number[i]);
	system("pause");
	show_main();
}

int main()
{
	show_main();
}