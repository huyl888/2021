#include <stdio.h>
#define SIZE 17

char pws[] = "34608";


struct Job_type
{
	char name[10];
char num[8];
int age;
char station[4];
int jobage;
char addr[30];
char phone[11];
}jobd[SIZE];

void save()
{
	FILE * fp;
	int i;
	if ((fp = fopen("job.dat", "wb")) == NULL)
	{
		printf("�ļ���ʧ��!\n");
		system("pause");
		exit(0);
	}
	for (i = 0; i < SIZE; i++)
	{
		if (fwrite(&jobd[i], sizeof(struct Job_type), 1, fp) != 1)
		{
			printf("�ļ�д��ʧ��!\n");
			system("pause");
			exit(0);
		}
	}
	fclose(fp);
}

void print_job()
{
	int i;
	FILE * fp;
	if ((fp = fopen("job.dat", "rb")) == NULL)
	{
		printf("�ļ���ʧ��!\n");
		exit(0);
	}
	printf("%5s %11s %9s %7s %4s %9s %20s\n", "����", "����", "����", "��λ", "����", "�绰", "סַ");
	for (i = 0; i < SIZE; i++)
	{
		fread(&jobd[i], sizeof(struct Job_type), 1, fp);
		printf("%-10s %-10s %4d %7s %4d %13s %15s\n", jobd[i].name, &jobd[i].num, jobd[i].age, jobd[i].station, jobd[i].jobage, jobd[i].phone, jobd[i].addr);
	}
	fclose(fp);

	system("pause");
}

void in_mes()
{
	int i;
	for (i = 0; i < SIZE; i++)
	{
		system("cls");
		printf("������� %d ��Ա������:\n", i + 1);

		printf("����:");
		scanf("%s", jobd[i].name);
		printf("����:");
		scanf("%s", &jobd[i].num);
		printf("����:");
		scanf("%d", &jobd[i].age);
		printf("��λ:");
		scanf("%s", jobd[i].station);
		printf("����:");
		scanf("%d", &jobd[i].jobage);
		printf("�绰:");
		scanf("%s", &jobd[i].phone);
		printf("סַ:");
		scanf("%s", jobd[i].addr);
		
	}

	save();
}


int main()
{
	char job_PWS[6];
	while (1)
	{
		int k;
		system("cls");
		printf("��ѡ��Ĳ���:\n");
		printf("1. ������Ա��Ϣ\n");
		printf("2. ��ʾ��Ա��Ϣ\n");
		printf("3. �˳�\n");
		scanf("%d", &k);
		switch (k)
		{
		case 1: system("cls"); 
			printf("����������:");
			scanf("%s",job_PWS);
			if (strcmp(job_PWS,pws) == 0)
			{
				in_mes();
			}
			else
			{
				printf("�������!\n");
				system("pause");
			}
			break;
		case 2: system("cls"); print_job();
			break;
		case 3: exit(0);
			break;
		default: system("cls"); printf("�������\n"); system("pause");
			break;
		}
	}
	system("pause");
	return 0;
}