#include <stdio.h>
#include <stdlib.h>
int main()
{
	FILE * in, * out;
	int a,b;
	a = 2;
	char ch, infile[10], outfile[10];
	printf("��������ļ�������:");
	scanf("%s", infile);
	printf("��������ļ�������:");
	scanf("%s", outfile);
	printf("��ѡ��Ҫ���ļ��ķ�ʽ:\n");
	printf("1 .�����ƶ�ȡ�ļ�.\n");
	printf("2 .�ı�ģʽ��ȡ�ļ�.\n");
	scanf("%d", &a);
	printf("��ѡ��Ҫ����ļ��ķ�ʽ:\n");
	printf("1 .����������ļ�.\n");
	printf("2 .�ı�ģʽ����ļ�.\n");
	scanf("%d", &b);
	switch (a)
	{
	case 1:
		if ((in = fopen(infile, "rb")) == NULL)
		{
			printf("���ļ�ʧ��!\n");
			exit(0);
		}
		break;
	case 2:
		if ((in = fopen(infile, "r")) == NULL)
		{
			printf("���ļ�ʧ��!\n");
			exit(0);
		}
		break;
	default:
		printf("�������!\n");
		exit(0);
	}
	switch (b)
	{
	case 1:
		if ((out = fopen(outfile, "wb")) == NULL)
		{
			printf("���ļ�ʧ��!\n");
			exit(0);
		}
		break;
	case 2:
		if ((out = fopen(outfile, "w")) == NULL)
		{
			printf("���ļ�ʧ��!\n");
			exit(0);
		}
		break;
	default:
		printf("�������!\n");
		exit(0);
	}
	
	while (!feof(in))
	{
		ch = fgetc(in);
		fputc(ch, out);
		putchar(ch);
	}
	putchar(10);
	fclose(in);
	fclose(out);

	system("pause");
	return 0;
}