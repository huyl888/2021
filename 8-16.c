#include<stdio.h>
#include "8-16.h"
void main()
{
	char str[] = "I love China!";
	int n;
	printf("%s\n", str);
	printf("请输入要显示第几个字符:");
	scanf("%d", &n);
	str_out(str, n);

	system("pause");
}

void str_out(char str[], int n)
{
	printf("第%d个字符为\"%c\"\n",n, str[n - 1]);
}