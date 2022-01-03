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
	HANDLE handle_out = GetStdHandle(STD_OUTPUT_HANDLE); //获得标准输出设备句柄
	CONSOLE_SCREEN_BUFFER_INFO csbi; //定义窗口缓冲区信息结构体
	const char * title = "班组人员管理系统-by:凝冰舞";
	GetConsoleScreenBufferInfo(handle_out, &csbi); //获得窗口缓冲区信息
	SetConsoleTitle(title);
#if(0)
	char * str = "班组人员管理系统";
	WORD shadow = BACKGROUND_INTENSITY; //阴影属性
	WORD text = BACKGROUND_GREEN | BACKGROUND_INTENSITY; //文本属性
	SMALL_RECT rc; //定义一个文本框输出区域
	COORD posText; //定义文本框的起始坐标
	COORD posShadow; //定义阴影框的起始坐标
	//COORD size = { 80,25 };
	
	int len = strlen(str);
	//确定区域边界
	rc.Top = 8; //上
	rc.Bottom = rc.Top + 4; //下
	rc.Left = (csbi.dwSize.X - len)/2-2; //左
	rc.Right = rc.Left + len + 4; //右
	//确定文本框起始坐标
	posText.X = rc.Left;
	posText.Y = rc.Top;
	//确定阴影框起始坐标
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
		printf("1. 建立班员信息.\n");
		printf("2. 查看班员信息.\n");
		printf("3. 添加班员信息.\n");
		printf("4. 删除班员信息.\n");
		printf("5. 读取文件.\n");
		printf("6. 写入文件.\n");
		printf("0. 退出.\n");
		printf("请选择要执行的操作.\n");
		scanf("%d", &Case_stu);

		switch (Case_stu)
		{
		case 1:
			system("cls");
			printf("需要建立几人的信息?\n");
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
			printf("请输入要插入信息的序号:");
			scanf("%d", &into_list);
			printf("请输入姓名:");
			memset(temp_name, 0, 20);
			scanf("%s", temp_name);
			printf("请输入学号:");
			scanf("%ld", &temp_num);
			printf("请输入成绩:");
			scanf("%f", &temp_score);
			Insert_stu(Header, into_list,temp_name,temp_num,temp_score);
			system("pause");
			break;
		case 4:
			system("cls");
			stu_n = Count;
			Print_stu(Header, stu_n);
			printf("请输入要删除信息的序号:");
			scanf("%d", &del_list);
			Del_stu(Header, del_list);
			system("pause");
			break;
		case 5:
			system("cls");
			//读取
			myReadFlie("date.dat", Header);
			system("pause");
			break;
		case 6:
			system("cls");
			//写入
			myWriteFile("date.dat", Header);
			system("pause");
			break;
		case 0:
			system("pause");
			exit(0);
			break;
		default:
			system("cls");
			printf("输入错误!\n");
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
		printf("请输入第 %d 名的信息.\n", i + 1);
		if (Count == 0)
		{
			memset(TempName, 0, 20);
			p1 = p2 = malloc(LEN);
			Head = p1;
			p1->Flink = NULL;
			p1->Blink = NULL;
			p1->List = i + 1;
			printf("请输入姓名:");
			scanf("%s", TempName);
			strcpy(p1->Name, TempName);
			printf("请输入学号:");
			scanf("%ld", &p1->Num);
			printf("请输入成绩:");
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
			printf("请输入姓名:");
			scanf("%s", TempName);
			strcpy(p1->Name, TempName);
			printf("请输入学号:");
			scanf("%ld", &p1->Num);
			printf("请输入成绩:");
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
		printf("输出完成!\n");
		return true;
	}
	else
	{
		printf("错误!没有任何信息!\n");
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
			printf("插入信息成功!\n");
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
	printf("输入序号错误!调整序号插入成功!\n");
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
			printf("删除信息成功!\n");
			return true;
		}
		else
		{
			pt = pt->Flink;
		}
	}
	printf("没有相关信息!删除失败!\n");
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
		printf("打开文件失败!\n");
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
			printf("读取文件失败!\n");
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
	printf("读取文件完成!\n");
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
		printf("建立文件失败!\n");
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
			printf("写入信息失败!\n");
		}
		pt = pt->Flink;
	}
	free(ptstu);
	fclose(pFile);
	printf("写入信息完成!\n");
	return true;
}