#include <stdio.h>
#include <stdlib.h>
int main()
{
	FILE * in, * out;
	int a,b;
	a = 2;
	char ch, infile[10], outfile[10];
	printf("输入读入文件的名字:");
	scanf("%s", infile);
	printf("输入输出文件的名字:");
	scanf("%s", outfile);
	printf("请选择要打开文件的方式:\n");
	printf("1 .二进制读取文件.\n");
	printf("2 .文本模式读取文件.\n");
	scanf("%d", &a);
	printf("请选择要输出文件的方式:\n");
	printf("1 .二进制输出文件.\n");
	printf("2 .文本模式输出文件.\n");
	scanf("%d", &b);
	switch (a)
	{
	case 1:
		if ((in = fopen(infile, "rb")) == NULL)
		{
			printf("打开文件失败!\n");
			exit(0);
		}
		break;
	case 2:
		if ((in = fopen(infile, "r")) == NULL)
		{
			printf("打开文件失败!\n");
			exit(0);
		}
		break;
	default:
		printf("输入错误!\n");
		exit(0);
	}
	switch (b)
	{
	case 1:
		if ((out = fopen(outfile, "wb")) == NULL)
		{
			printf("打开文件失败!\n");
			exit(0);
		}
		break;
	case 2:
		if ((out = fopen(outfile, "w")) == NULL)
		{
			printf("打开文件失败!\n");
			exit(0);
		}
		break;
	default:
		printf("输入错误!\n");
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