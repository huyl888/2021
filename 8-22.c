#include <stdio.h>
#include <stdlib.h>

int main()
{
	int max_n(int a, int b);
	int(*p)(int, int);
	int a, b,c;
	p = max_n;
	printf("please enter two integer numbers:");
	scanf("%d%d", &a, &b);
	printf("a = %d b = %d\n", a, b);
	c=(*p)(a, b);

	system("pause");
	return 0;
}

int max_n(int a, int b)
{
	if (a<b)
	{
		printf("max = %d\n", b);
	}
	else
	{
		printf("max = %d\n", a);
	}
}