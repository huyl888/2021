#include <stdio.h>
#include <math.h>
#include <string.h>

int j;
int main()
{
	int extract_n(char str[], int a[], int k);
	char str[50];
	int i, k,s, num, a[10] = { 0 }, b[10] = { 0 };
	printf("请输入一个字符串:");
	gets(str);
	s = 0;
	for (i = 0; str[i] != '\0';)
	{
		if (str[i] > 47 && str[i] < 58)
		{
			i = extract_n(str, a, i);
			num = 0;
			for (k = 0; j > 0; k++, j--)
			{
				num =num + a[k] * (pow(10, (j-1)));
			}
			b[s] = num;
			s++;
		}
		else
		{
			i++;
			continue;
		}
		
	}
	for (i = 0; b[i] != 0; i++)
	{
		printf("%d ", b[i]);
	}

	system("pause");
}

int extract_n(char str[], int a[],int k)
{
	int i, s, *p;
	p = &j;
	for (i = k,s = 0; str[i] != '\0'; i++)
	{
		if (str[i] > 47 && str[i] < 58)
		{
			a[s] = str[i] - 48;
			s++;
		}
		else	//非数字跳出
		{
			i++;
			break;
		}
	}
	*p = s;
	k = i;
	return(k);
}