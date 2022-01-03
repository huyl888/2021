#include <stdio.h>
int main()
{
	void copy_str(char from[], char to[], int m);
	char a[20], b[20];
	int m;
	printf("请输入字符串a:");
	gets(a);
	printf("请输入要从第几个字符开始复制:");
	scanf("%d", &m);
	copy_str(a, b, m);
	printf("a = %s\n", a);
	printf("b = %s\n", b);

	system("pause");
}

#if(1)
void copy_str(char from[], char to[], int m)
{
	int i;
	for (i = 0; from[i] != '\0'; i++)
	{
		to[i] = from[m - 1 + i];
	}
	to[i] = '\0';
}
#endif

#if(0)
void copy_str(char(*f)[], char(*t)[], int m)
{
	int i;
	for (i = 0; (*f)[i] != '\0'; i++)
	{
		(*t)[i] = (*f)[i + m - 1];
	}
}
#endif