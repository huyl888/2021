#include <stdio.h>
#include <stdlib.h>
int main()
{
	FILE * fp;
	char ch, filename[10];
	printf("���������õ��ļ���:");
	scanf("%s", filename);
	if ((fp = fopen(filename, "w")) == NULL)
	{
		printf("���ļ�ʧ��\n");
		exit(0);
	}
	ch = getchar();
	printf("������һ��׼���洢�����̵��ַ���(�� # ����):");
	ch = getchar();
	while (ch != '#')
	{
		fputc(ch, fp);
		putchar(ch);
		ch = getchar();
	}
	fclose(fp);
	putchar(10);

	system("pause");
	return 0;
}