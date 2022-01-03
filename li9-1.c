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
int nRFS = sizeof(long int)+sizeof(char)*20+sizeof(char)*35;//����ȫ�ֱ����������ն�ȡ�����ļ��ĳ���

int main()
{
	char * MyReadFile(char * szFilePath, int *nRFS);
	int MyWriteFile(char * szFilePath, char * szStr);
	void input_s(struct Student *s);

	FILE *fp;
	if ((fp = fopen("data.dat", "wb")) == NULL)
	{
		printf("�ļ���ʧ��!");
		exit(0);
	}
	else
	{
		printf("�ļ��򿪳ɹ�!\n");
	}
	//int * RFS = &nRFS;
	//char *p = MyReadFile("data.dat", RFS);
	struct Student s1 = { 0," "," "," " }, s2 = { 0," "," "," " },*p1,*p2;
	p1 = &s1;
	p2 = &s2;
	
	printf("�������һ��ѧ������Ϣ:\n");
	input_s(p1);
	printf("������ڶ���ѧ������Ϣ:\n");
	input_s(p2);
	MyWriteFile("data.dat", p1);
	MyWriteFile("data.dat", p2);
	printf("��һ��ѧ������ϢΪ:\nѧ��:%ld\n����:%s\n�Ա�:%s\n��ַ:%s\n", s1.num, s1.name, s1.sex, s1.addr);
	printf("�ڶ���ѧ������ϢΪ:\nѧ��:%ld\n����:%s\n�Ա�:%s\n��ַ:%s\n", s2.num, s2.name, s2.sex, s2.addr);

	system("pause");
	return 0;

}
void input_s(struct Student *s)
{
	char sn[20],ss[5],sad[30];
	int n;
	printf("������ѧ��:");
	scanf("%d", &n);
	(*s).num = n;
	printf("����������:");
	scanf("%s",sn);
	strcpy((*s).name, sn);
	printf("�������Ա�:");
	scanf("%s",ss);
	strcpy((*s).sex,ss);
	printf("�������ַ:");
	scanf("%s",sad);
	strcpy((*s).addr, sad);
}

char * MyReadFile(char * szFilePath, int *nRFS)
{
	FILE *pFile;
	//r �� w д(ɾ����д) a ׷�� 
	//rb wb ab b���Զ�������ʽ����д
	pFile = fopen(szFilePath, "rb");
	if (pFile == NULL)
	{
		printf("open file failed!\n");
		system("pause");
		fclose(pFile);
		exit(0);
	}
	fseek(pFile, 0, SEEK_END); //�ƶ���굽�ļ�ĩβ
	int nReadFileSize = ftell(pFile); //�õ��ļ��Ĵ�С
	*nRFS = nReadFileSize; //����С���ص�ȫ�ֱ���
	rewind(pFile);	//�ƶ���굽�ļ���ʼλ��(�����ȡ������)
	char * szReadTextBuffer = (char *)malloc((nReadFileSize + 1) * sizeof(char));//�ڴ�����
	if (szReadTextBuffer == NULL)
	{
		printf("malloc mnemory failed!\n");
		system("pause");
		fclose(pFile);
		exit(0);
	}
	memset(szReadTextBuffer, 0, (nReadFileSize + 1) * sizeof(char));//��ʼ�����뵽���ڴ�
	int nReadRet = 0;	//
	nReadRet = fread(szReadTextBuffer, 1, nReadFileSize, pFile);//��ȡ�ļ�
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