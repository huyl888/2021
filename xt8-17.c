#include <stdio.h>
#include <string.h>
int main()
{
	int strcmp(char * p1, char * p2);
	char s1[6], s2[6];
	printf("请输入第一个字符串(5个字符以内)");
	gets(s1);
	printf("请输入第二个字符串(5个字符以内)");
	gets(s2);
	printf("%d\n",strcmp(s1, s2));

	system("pause");
}

int strcmp(char * p1, char * p2)
{
	int i, k;
	for (i = 0, k = 0; *(p1+i) != '\0' && *(p2 + i) != '\0'; i++)
	{
		if (*(p1 + i) == *(p2 + i))
		{
			continue;
		}
		else
		{
			k = (*(p1 + i) - *(p2 + i));
			break;
		}
	}
	return(k);
}