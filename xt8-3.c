#include <stdio.h>
int main()
{
	void num_in(int a[10]);
	void num_ch(int a[10]);
	void num_out(int a[10]);
	int a[10];
	num_in(a);
	num_ch(a);
	num_out(a);

	system("pause");
}

void num_in(int a[10])
{
	int * p, i;
	p = a;
	printf("请输入 10 个整数:");
	for (i = 0; i<10; i++)
	{
		scanf("%d", p + i);
	}
}

void num_ch(int a[10])
{
	int * p, max, min, i, t, m, n;
	p = a;
	max = *p;
	min = *p;
	m = 0; n = 0;
	for (i = 0; i<10; i++)
	{
		if (max < *p) { max = *p; m = i; }
		if (min > *p) { min = *p; n = i; }
		p++;
	}
	p = a;
	t = *(p+0); 
	*(p+0) = *(p+n); 
	*(p+n) = t;
	t = *(p + 9);
	*(p+9) = *(p+m);
	*(p+m) = t;
}

void num_out(int a[10])
{
	int i;
	for (i = 0; i<10; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}