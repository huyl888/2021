#include <stdio.h>
int main()
{
	void reverse_n(int a[], int n);
	int a[10], i,*p;
	//p = a;
	printf("请输入 10 个整数:");
	for (i = 0; i<10; i++)
	{
		scanf("%d", &a[i]);
	}
	reverse_n(a, 10);
	for (i = 0; i < 10; i++)
	{
		printf("%2d", a[i]);
	}

	system("pause");
}

void reverse_n(int a[], int n)
{
	int i, t,*p;
	p = a;
	for (i = 0; i<n / 2; i++)
	{
		t = *(p+i);
		*(p + i) = *(p +n- i-1);
		*(p + n - i-1) = t;
	}
}