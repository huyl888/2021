#include <stdio.h>
int main()
{
	void print_n(int n);
	long int n;
	printf("������Ҫ��ӡ 0 �����ٵ�ż��:");
	scanf("%d", &n);
	print_n(n);

	system("pause");
	return 0;
}

void print_n(int n)
{
	if (n % 2 == 0)
	{
		printf("%d ", n);
	}
	else
	{
		printf("%d ", n - 1);
	}
	n -= 2;
	if (n>0)
	{
		print_n(n);
	}
}