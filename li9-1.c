#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Student
{
	long int num;
	char name[20];
	char sex[5];
	char addr[30];
};
int nRFS = sizeof(long int)+sizeof(char)*20+sizeof(char)*35;//定义全局变量用来接收读取到的文件的长度

int main()
{
	char * MyReadFile(char * szFilePath, int *nRFS);
	int MyWriteFile(char * szFilePath, char * szStr);
	void input_s(struct Student *s);

	FILE *fp;
	if ((fp = fopen("data.dat", "wb")) == NULL)
	{
		printf("文件打开失败!");
		exit(0);
	}
	else
	{
		printf("文件打开成功!\n");
	}
	//int * RFS = &nRFS;
	//char *p = MyReadFile("data.dat", RFS);
	struct Student s1 = { 0," "," "," " }, s2 = { 0," "," "," " },*p1,*p2;
	p1 = &s1;
	p2 = &s2;
	
	printf("请输入第一个学生的信息:\n");
	input_s(p1);
	printf("请输入第二个学生的信息:\n");
	input_s(p2);
	MyWriteFile("data.dat", p1);
	MyWriteFile("data.dat", p2);
	printf("第一个学生的信息为:\n学号:%ld\n姓名:%s\n性别:%s\n地址:%s\n", s1.num, s1.name, s1.sex, s1.addr);
	printf("第二个学生的信息为:\n学号:%ld\n姓名:%s\n性别:%s\n地址:%s\n", s2.num, s2.name, s2.sex, s2.addr);

	system("pause");
	return 0;

}
void input_s(struct Student *s)
{
	char sn[20],ss[5],sad[30];
	int n;
	printf("请输入学号:");
	scanf("%d", &n);
	(*s).num = n;
	printf("请输入姓名:");
	scanf("%s",sn);
	strcpy((*s).name, sn);
	printf("请输入性别:");
	scanf("%s",ss);
	strcpy((*s).sex,ss);
	printf("请输入地址:");
	scanf("%s",sad);
	strcpy((*s).addr, sad);
}

char * MyReadFile(char * szFilePath, int *nRFS)
{
	FILE *pFile;
	//r 读 w 写(删除后写) a 追加 
	//rb wb ab b是以二进制形式读或写
	pFile = fopen(szFilePath, "rb");
	if (pFile == NULL)
	{
		printf("open file failed!\n");
		system("pause");
		fclose(pFile);
		exit(0);
	}
	fseek(pFile, 0, SEEK_END); //移动光标到文件末尾
	int nReadFileSize = ftell(pFile); //得到文件的大小
	*nRFS = nReadFileSize; //将大小返回到全局变量
	rewind(pFile);	//移动光标到文件初始位置(否则读取出问题)
	char * szReadTextBuffer = (char *)malloc((nReadFileSize + 1) * sizeof(char));//内存申请
	if (szReadTextBuffer == NULL)
	{
		printf("malloc mnemory failed!\n");
		system("pause");
		fclose(pFile);
		exit(0);
	}
	memset(szReadTextBuffer, 0, (nReadFileSize + 1) * sizeof(char));//初始化申请到的内存
	int nReadRet = 0;	//
	nReadRet = fread(szReadTextBuffer, 1, nReadFileSize, pFile);//读取文件
	if (nReadRet != nReadFileSize)
	{
		printf("Read File failed!\n");
		system("pause");
		fclose(pFile);
		exit(0);
	}
	fclose(pFile);
	return szReadTextBuffer;
}

int MyWriteFile(char * szFilePath, char * szStr)
{
	FILE *pFile;
	pFile = fopen(szFilePath, "wb");
	if (pFile == NULL)
	{
		printf("open file failed!\n");
		system("pause");
		fclose(pFile);
		exit(0);
	}
	int nRet = fwrite(szStr, nRFS, 1, pFile);
	fclose(pFile);
	return nRet;
}