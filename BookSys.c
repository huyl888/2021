#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//�鼮�ṹ
typedef struct Node {
	struct Node * Blink;
	struct Node * Flink;
	char BookName[50];
	float BookPrice;
	int BookNumber;
};

int nNodeCount = 0;//ȫ�ֱ���ͳ���ж��ٽڵ�
struct Node * ndHeaderNode = NULL;

//�����鼮�ĺ���
struct Node * AppendNode(struct Node * CurrentNode, char * BookName, float BookPrice, int BookNumber);
//��ѯ�鼮�ĺ���
void QueryNode(struct Node * HeaderNode, char * BookName);
//�޸ĺ���
void ModifyNode(struct Node * HeaderNode, char * BookName, float BookPrice);
//ɾ������
void DeleteNode(struct Node * HeaderNode, char * BookName);
//��ȡ�ļ�
char * MyReadFile(char * szFilePath);
//�洢�ļ�
int MyWriteFile(char *szFilePath, char *szStr);

int main()
{
	while (true)
	{
		int ReadFlag = 0;
		char szBookName[50];
		float fBookPrice = 0;
		float fNewBookPrice = 0;
		int nBookNumber = 0;
		printf("��������Ҫʹ�õĹ���\n");
		printf("1. ����鼮��Ϣ\n");
		printf("2. ��ѯ�鼮��Ϣ\n");
		printf("3. �޸��鼮��Ϣ\n");
		printf("4. ɾ���鼮��Ϣ\n");
		scanf("%d", &ReadFlag);

		switch (ReadFlag)
		{
		case 1:
			system("cls");
			memset(szBookName, 0, 50);
			printf("����������:");
			scanf("%s", szBookName);
			printf("�����붨��:");
			scanf("%f", &fBookPrice);
			printf("���������:");
			scanf("%d", &nBookNumber);
			//Code
			ndHeaderNode = AppendNode(ndHeaderNode, szBookName, fBookPrice, nBookNumber);
			break;
		case 2:
			system("cls");
			memset(szBookName, 0, 50);
			printf("����������:");
			scanf("%s", szBookName);
			//Code
			QueryNode(ndHeaderNode, szBookName);
			break;
		case 3:
			system("cls");
			memset(szBookName, 0, 50);
			printf("����������:");
			scanf("%s", szBookName);
			printf("�������¶���:");
			scanf("%f", &fNewBookPrice);
			//Code
			ModifyNode(ndHeaderNode, szBookName, fBookPrice);
			break;
		case 4:
			system("cls");
			memset(szBookName, 0, 50);
			printf("����������:");
			scanf("%s", szBookName);
			//Code
			DeleteNode(ndHeaderNode, szBookName);
			break;
		default:
			system("cls");
			printf("Error!\a");
			break;
		}
	}

	return 0;
}

struct Node * AppendNode(struct Node * CurrentNode, char * BookName, float BookPrice, int BookNumber)
{
	struct Node * pNewNode = NULL;
	struct Node * pTempNode = NULL;
	struct Node * pHeadNode = CurrentNode;
	pNewNode = (struct Node *)malloc(sizeof(struct Node));
	if (pNewNode == NULL)
	{
		printf("Memory malloc failed!\n");
		return pNewNode;
	}
	if (CurrentNode == NULL)
	{
		CurrentNode = pNewNode;
		CurrentNode->Blink = NULL;
		CurrentNode->Flink = NULL;
	}
	else
	{
		while (pHeadNode->Flink != NULL)
		{
			pTempNode = pHeadNode;
			pHeadNode = pHeadNode->Flink;
		}
		pHeadNode->Flink = pNewNode;
		pHeadNode->Blink = pTempNode;
	}
	strcpy(pNewNode->BookName, BookName);
	pNewNode->BookPrice = BookPrice;
	pNewNode->BookNumber = BookNumber;
	pNewNode = NULL;
	nNodeCount++;
	return CurrentNode;
}

void QueryNode(struct Node * HeaderNode, char * BookName)
{
	if (HeaderNode == NULL)
	{
		printf("Error:HeaderNode == NULL!\n");
	}
	for (int i = 0; i < nNodeCount; i++)
	{
		if (strcmp(HeaderNode->BookName, BookName) == 0)
		{
			printf("����: %s\n", HeaderNode->BookName);
			printf("����: %f\n", HeaderNode->BookPrice);
			printf("���: %d\n", HeaderNode->BookNumber);
			return;
		}
		HeaderNode = HeaderNode->Flink;
	}
	//while (HeaderNode->Flink != NULL)
	//{
	//	HeaderNode = HeaderNode->Flink;
	//	if (strcmp(HeaderNode->BookName, BookName) == 0)
	//	{
	//		printf("����: %s\n", HeaderNode->BookName);
	//		printf("����: %f\n",HeaderNode->BookPrice);
	//		printf("���: %d\n", HeaderNode->BookNumber);
	//		return;
	//	}
	//}
	printf("Query Node Failed!\n");
}

void ModifyNode(struct Node * HeaderNode, char * BookName, float BookPrice)
{
	if (HeaderNode == NULL)
	{
		printf("Error:HeaderNode == NULL!\n");
	}
	if (strcmp(HeaderNode->BookName, BookName) == 0)
	{
		HeaderNode->BookPrice = BookPrice;
		printf("ModifyNode Success!");
	}
	while (HeaderNode->Flink != NULL)
	{
		HeaderNode = HeaderNode->Flink;
		if (strcmp(HeaderNode->BookName, BookName) == 0)
		{
			HeaderNode->BookPrice = BookPrice;
			printf("ModifyNode Success!");
		}
	}
	printf("ModifyNode Failed!\n");
	return;
}

void DeleteNode(struct Node * HeaderNode, char * BookName)
{
	struct Node * pNode = NULL;
	pNode = HeaderNode;
	for (int i = 0; i < nNodeCount; i++)
	{
		if (strcmp(pNode->BookName, BookName) == 0)
		{
			if (pNode == HeaderNode)
			{
				pNode = HeaderNode->Flink;
				free(HeaderNode);
				ndHeaderNode = pNode;
				HeaderNode = ndHeaderNode;
				nNodeCount--;
				printf("Delete Success!\n");
				return;
			}
			if (pNode->Flink == NULL)
			{
				pNode->Blink->Flink = NULL;
				free(pNode);
				nNodeCount--;
				printf("Delete Success!\n");
				return;
			}
			pNode->Blink->Flink = pNode->Flink;
			pNode->Flink->Blink = pNode->Blink;
			free(pNode);
			nNodeCount--;
			printf("Delete Success!\n");
			return;
		}
		pNode = pNode->Flink;
	}
}

char * MyReadFile(char * szFilePath)
{
	FILE *pFile;
	pFile = fopen(szFilePath, "rb");
	if (pFile == NULL)
	{
		printf("Open File Failed!\n");
		system("pause");
		fclose(pFile);
		exit(0);
	}
	fseek(pFile, 0, SEEK_END);
	int nReadFileSize = ftell(pFile);
	rewind(pFile);
	char * szReadTextBuffer = (char *)malloc((nReadFileSize + 1) * sizeof(char));
	if (szReadTextBuffer == NULL)
	{
		printf("Malloc memory failed!\n");
		system("pause");
		fclose(pFile);
		exit(0);
	}
	memset(szReadTextBuffer, 0, (nReadFileSize + 1) * sizeof(char));
	int nReadRet = 0;
	nReadRet = fread(szReadTextBuffer, 1, nReadFileSize, pFile);
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
		printf("Open file failed!\n");
		system("pause");
		fclose(pFile);
		exit(0);
	}
	int nRet = fwrite(szStr, sizeof(szStr + 1), 1, pFile);
	fclose(pFile);
	return nRet;
}