#include <stdio.h>
#include <string.h>
int main()
{
	char str[5][6];
	int i;
	printf("ÇëÊäÈë5¸ö5×Ö·û×Ö·û´®:");
	for (i = 0; i<5; i++)
	{
 		gets(str[i]);
	}
	void fun1(char str1[][6]);
	fun1(str);
	for (i = 0; i<5; i++)
	{
		puts(str[i]);
		printf("\n");
	}

	system("pause");
}

void fun1(char str1[][6])
{
	char(*p1)[6], temp[6];
	p1 = str1;
	int i,j;
	for (i = 0; i<4; i++)
	{
		for (j = i + 1; j<5; j++)
		{
			if (strcmp(*(p1 + i), *(p1 + j))>0)
			{
				strcpy(temp, *(p1 + i));
				strcpy(*(p1 + i), *(p1 + j)); 
				strcpy(*(p1 + j), temp);
			}
		}
	}
}