#include <stdio.h>
#include <string.h>
int main()
{
	int fun1(char str[], int n);
	char str[20];
	int n = 0;
	printf("������һ���ַ���,����20���ַ�:");
	gets(str);
	n=fun1(str, n);

	printf("������ַ�������%d���ַ�.\n", n);

	system("pause");
	return 0;
}

int fun1(char str[], int n)
{
	int i, *p;
	p = &n;
	for (i = 0; i<20 ; i++)
	{
		if (str[i] != '\0')
			*p = *p + 1;
		else break;
	}
	return(n);
}