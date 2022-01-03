#include <stdio.h>
int main()
{
	char a[20], *p;
	int i, k, B_c = 0, S_c = 0, Bl = 0, Nu = 0, Ot = 0;
	printf("请输入一行文字:");
	gets(a);
	p = a;
	for (i = 0; p[i] != '\0'; i++)
	{
		if (p[i] >= 'A' && p[i] <= 'Z')k = 1;
		else if (p[i] >= 'a' && p[i] <= 'z')k = 2;
		else if (p[i] == ' ')k = 3;
		else if (p[i] >= '0' && p[i] <= '9')k = 4;
		else k = 5;
		switch (k)
		{
		case 1:B_c++; continue;
		case 2:S_c++; continue;
		case 3:Bl++; continue;
		case 4:Nu++; continue;
		case 5:Ot++; continue;
		}
	}
	printf("大写%d个,小写%d个,空格%d个,数字%d个,其他%d个.\n", B_c, S_c, Bl, Nu, Ot);
	
	system("pause");
}