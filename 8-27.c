#include <stdio.h>
#include <string.h>
int main()
{
	void sort(char * name[], int n);	//��������
	void print(char * name[], int n);	//��������
	char *name[5] = { "Follow me","BASIC","Great Wall","FORTAN","Computer design" };    //����ָ������,����Ԫ�طֱ�ָ��5���ַ���
	int n = 5;
	sort(name, n);	//����sort����,���ַ�������
	print(name, n);	//����print����,����ַ���

	system("pause");
	return 0;
}

void sort(char * name[], int n)	//����sort����
{
	char * temp;
	int i, j, k;
	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			k = strcmp(name[i], name[j]);
			if (k > 0)
			{
				temp = name[i];
				name[i] = name[j];
				name[j] = temp;
			}
		}
	}
}

void print(char * name[], int n)	//����print����
{
	int i;
	for (i = 0; i<n; i++)
	{
		printf("%s\n", name[i]);
	}//��ָ������Ԫ�ص�˳�����������ָ����ַ���
}