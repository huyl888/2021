#include<stdio.h>
#include "8-16.h"
void main()
{
	char str[] = "I love China!";
	int n;
	printf("%s\n", str);
	printf("������Ҫ��ʾ�ڼ����ַ�:");
	scanf("%d", &n);
	str_out(str, n);

	system("pause");
}

void str_out(char str[], int n)
{
	printf("��%d���ַ�Ϊ\"%c\"\n",n, str[n - 1]);
}