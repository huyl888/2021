#include "xiti9-7.h"

#define LEN sizeof(struct Student)

int Count = 0;

struct Student
{
	int List;
	char Name[20];
	long int Num;
	float Score;
	struct Student * Blink;
	struct Student * Flink;
};

struct Student * Header = NULL;

int main()
{
	HANDLE handle_out = GetStdHandle(STD_OUTPUT_HANDLE); //��ñ�׼����豸���
	CONSOLE_SCREEN_BUFFER_INFO csbi; //���崰�ڻ�������Ϣ�ṹ��
	const char * title = "������Ա����ϵͳ-by:������";
	GetConsoleScreenBufferInfo(handle_out, &csbi); //��ô��ڻ�������Ϣ
	SetConsoleTitle(title);
#if(0)
	char * str = "������Ա����ϵͳ";
	WORD shadow = BACKGROUND_INTENSITY; //��Ӱ����
	WORD text = BACKGROUND_GREEN | BACKGROUND_INTENSITY; //�ı�����
	SMALL_RECT rc; //����һ���ı����������
	COORD posText; //�����ı������ʼ����
	COORD posShadow; //������Ӱ�����ʼ����
	//COORD size = { 80,25 };
	
	int len = strlen(str);
	//ȷ������߽�
	rc.Top = 8; //��
	rc.Bottom = rc.Top + 4; //��
	rc.Left = (csbi.dwSize.X - len)/2-2; //��
	rc.Right = rc.Left + len + 4; //��
	//ȷ���ı�����ʼ����
	posText.X = rc.Left;
	posText.Y = rc.Top;
	//ȷ����Ӱ����ʼ����
	posShadow.X = posText.X + 1;
	posShadow.Y = posText.Y + 1;
	for (int i = 0; i < 5; ++i)
	{
		FillConsoleOutputAttribute(handle_out, shadow, len + 4, posShadow, NULL);
		posShadow.Y++;
	}
	for (int i = 0; i < 5; ++i)
	{
		FillConsoleOutputAttribute(handle_out, text, len + 4, posText, NULL);
		posText.Y++;
	}
	//SetConsoleScreenBufferSize(handle_out, size);
	
#endif

	int Case_stu,stu_n,temp_list,into_list,del_list;
	long int temp_num;
	char temp_name[20];
	float temp_score;
	while (1)
	{
		system("cls");
		printf("1. ������Ա��Ϣ.\n");
		printf("2. �鿴��Ա��Ϣ.\n");
		printf("3. ��Ӱ�Ա��Ϣ.\n");
		printf("4. ɾ����Ա��Ϣ.\n");
		printf("5. ��ȡ�ļ�.\n");
		printf("6. д���ļ�.\n");
		printf("0. �˳�.\n");
		printf("��ѡ��Ҫִ�еĲ���.\n");
		scanf("%d", &Case_stu);

		switch (Case_stu)
		{
		case 1:
			system("cls");
			printf("��Ҫ�������˵���Ϣ?\n");
			scanf("%d", &stu_n);
			Header = Creat_stu(stu_n);
			break;
		case 2:
			system("cls");
			stu_n = Count;
			Print_stu(Header, stu_n);
			system("pause");
			break;
		case 3:
			system("cls");
			stu_n = Count;
			Print_stu(Header, stu_n);
			printf("������Ҫ������Ϣ�����:");
			scanf("%d", &into_list);
			printf("����������:");
			memset(temp_name, 0, 20);
			scanf("%s", temp_name);
			printf("������ѧ��:");
			scanf("%ld", &temp_num);
			printf("������ɼ�:");
			scanf("%f", &temp_score);
			Insert_stu(Header, into_list,temp_name,temp_num,temp_score);
			system("pause");
			break;
		case 4:
			system("cls");
			stu_n = Count;
			Print_stu(Header, stu_n);
			printf("������Ҫɾ����Ϣ�����:");
			scanf("%d", &del_list);
			Del_stu(Header, del_list);
			system("pause");
			break;
		case 5:
			system("cls");
			//��ȡ
			myReadFlie("date.dat", Header);
			system("pause");
			break;
		case 6:
			system("cls");
			//д��
			myWriteFile("date.dat", Header);
			system("pause");
			break;
		case 0:
			system("pause");
			exit(0);
			break;
		default:
			system("cls");
			printf("�������!\n");
			system("pause");
			break;
		}
	}
}

struct Student * Creat_stu(int n)
{
	system("cls");
	struct Student * Head = NULL;
	struct Student * p1, *p2;
	p1 = p2 = NULL;
	char TempName[20];
	for (int i = 0; i < n; i++)
	{
		printf("������� %d ������Ϣ.\n", i + 1);
		if (Count == 0)
		{
			memset(TempName, 0, 20);
			p1 = p2 = malloc(LEN);
			Head = p1;
			p1->Flink = NULL;
			p1->Blink = NULL;
			p1->List = i + 1;
			printf("����������:");
			scanf("%s", TempName);
			strcpy(p1->Name, TempName);
			printf("������ѧ��:");
			scanf("%ld", &p1->Num);
			printf("������ɼ�:");
			scanf("%f", &p1->Score);
			Count++;
		}
		else
		{
			memset(TempName, 0, 20);
			p1 = malloc(LEN);
			p1->Flink = NULL;
			p1->Blink = p2;
			p2->Flink = p1;
			p1->List = i + 1;
			printf("����������:");
			scanf("%s", TempName);
			strcpy(p1->Name, TempName);
			printf("������ѧ��:");
			scanf("%ld", &p1->Num);
			printf("������ɼ�:");
			scanf("%f", &p1->Score);
			p2 = p1;
			Count++;
		}
	}
	return(Head);
}

bool Print_stu(struct Student * Head, int n)
{
	struct Student * pt = NULL;
	int i;
	pt = Head;
	char TempName[20];
	if (n>0)
	{
		for (i = 0; i < n; i++)
		{
			memset(TempName, 0, 20);
			strcpy(TempName, pt->Name);
			printf("%d %s %ld %5.2f\n", pt->List, TempName, pt->Num, pt->Score);
			pt = pt->Flink;
		}
		printf("������!\n");
		return true;
	}
	else
	{
		printf("����!û���κ���Ϣ!\n");
		return false;
	}
	
}

bool Insert_stu(struct Student * Head, int into_list, char * into_name, long int into_num, float into_score)
{
	struct Student * pt, *p1, *p2;
	pt = p1 = p2 = NULL;
	int i , j;
	pt = Head;
	for (i = 0; i < Count; i++)
	{
		if(pt->List == into_list)
		{
			p1 = malloc(LEN);
			pt->Blink->Flink = p1;
			p1->Blink = pt->Blink;
			pt->Blink = p1;
			p1->Flink = pt;
			
			strcpy(p1->Name, into_name);
			p1->List = into_list;
			p1->Num = into_num;
			p1->Score = into_score;
			for (j = 0; j <= Count - into_list; j++)
			{
				pt->List++;
				pt = pt->Flink;
			}
			Count++;
			printf("������Ϣ�ɹ�!\n");
			return true;
		}
		else
		{
			p2 = pt;
			pt = pt->Flink;
		}
	}
	p1 = malloc(LEN);
	p2->Flink = p1;
	p1->Blink = p2;
	p1->Flink = NULL;

	strcpy(p1->Name, into_name);
	p1->List = (p2->List + 1);
	p1->Num = into_num;
	p1->Score = into_score;
	Count++;
	printf("������Ŵ���!������Ų���ɹ�!\n");
	return true;
}

bool Del_stu(struct Student * Head, int del_list)
{
	struct Student * pt = NULL,* p1 = NULL;
	pt = Head;
	int i,j;
	for (i = 0; i < Count; i++)
	{
		if (pt->List == del_list)
		{
			if (pt->Blink == NULL)
			{
				Head = pt->Flink;
				pt->Flink->Blink = NULL;
				free(pt);
				Count--;
			}
			else if (pt->Flink != NULL && pt->Blink != NULL)
			{
				p1 = pt->Flink;
				pt->Flink->Blink = pt->Blink;
				pt->Blink->Flink = pt->Flink;
				free(pt);
				for (j = 0; j <= Count - p1->List; j++)
				{
					p1->List--;
					p1 = p1->Flink;
				}
				Count--;
			}
			else
			{
				pt->Blink->Flink = NULL;
				free(pt);
				Count--;
			}
			printf("ɾ����Ϣ�ɹ�!\n");
			return true;
		}
		else
		{
			pt = pt->Flink;
		}
	}
	printf("û�������Ϣ!ɾ��ʧ��!\n");
	return false;
}

bool myReadFlie(char * FilePath,struct Student * Head)
{
	struct Student * p1= NULL, * p2 = NULL;
	struct Stu
	{
		int List;
		char Name[20];
		long int Num;
		float Score;
	};
	struct Stu * pstu;
	FILE * pFile;
	pFile = fopen(FilePath, "rb");
	if (pFile == NULL)
	{
		printf("���ļ�ʧ��!\n");
		system("pause");
		fclose(pFile);
		return false;
	}
	fseek(pFile, 0, SEEK_END);
	int k = ftell(pFile);
	int n = k / sizeof(struct Stu);
	int i;
	pstu = malloc(sizeof(struct Stu));
	fseek(pFile, 0, SEEK_SET);
	for (i = 0; i < n; i++)
	{
		if (fread(pstu, sizeof(struct Stu), 1, pFile) != 1)
		{
			printf("��ȡ�ļ�ʧ��!\n");
		}
		if (i == 0)
		{
			p1 = p2 = malloc(LEN);
			Header = p1;
			//Header = Head;
			p1->Blink = NULL;
			p1->Flink = NULL;
			strcpy(p1->Name, pstu->Name);
			p1->List = i + 1;
			p1->Num = pstu->Num;
			p1->Score = pstu->Score;
			Count++;
		}
		else
		{
			p1 = malloc(LEN);
			p2->Flink = p1;
			p1->Blink = p2;
			p1->Flink = NULL;
			strcpy(p1->Name, pstu->Name);
			p1->List = i + 1;
			p1->Num = pstu->Num;
			p1->Score = pstu->Score;
			p2 = p1;
			Count++;
		}
	}
	printf("��ȡ�ļ����!\n");
	free(pstu);
}

bool myWriteFile(char * FilePath, struct Student * Head)
{
	struct Student *pt = Head;
	struct Stu
	{
		int List;
		char Name[20];
		long int Num;
		float Score;
	};
	FILE * pFile;
	struct Stu * ptstu = NULL;
	int i,k;
	pFile = fopen(FilePath, "wb");
	if (pFile == NULL)
	{
		printf("�����ļ�ʧ��!\n");
		system("pause");
		return false;
	}
	for(i = 0;i < Count;i++)
	{
		k = sizeof(struct Stu);
		ptstu = malloc(sizeof(struct Stu));
		ptstu->List = pt->List;
		strcpy(ptstu->Name, pt->Name);
		ptstu->Num = pt->Num;
		ptstu->Score = pt->Score;
		if (fwrite(ptstu, sizeof(struct Stu), 1, pFile) != 1)
		{
			printf("д����Ϣʧ��!\n");
		}
		pt = pt->Flink;
	}
	free(ptstu);
	fclose(pFile);
	printf("д����Ϣ���!\n");
	return true;
}