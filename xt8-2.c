#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	char str[3][10], (*pointer)[10], *temp[10];
	pointer = str;
	int i, j;
	for (i = 0; i<3; i++)
	{
		printf("ÇëÊäÈë %d ¸ö×Ö·û´®:",i+1);
		getchar(str[i]);
	}
	for (i = 0; i<3 - 1; i++)
	{
		for (j = i + 1; j<3; j++)
		{
			if (strcmp(pointer+i, pointer+j)>0)
			{
				strcpy(temp , pointer+i);
				strcpy(pointer+i , pointer+j);
				strcpy(pointer+j , temp);
			}
		}
	}
	for (i = 0; i < 3; i++)
	{
		printf("%s \n", str[i]);
	}
	system("pause");
}