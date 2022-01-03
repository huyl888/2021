#include <stdio.h>

int main()
{
	void max_n(int a, int b);
	void min_n(int a, int b);
	void add_n(int a, int b);
	void sub_n(int a, int b);
	void div_n(int a, int b);
	void mul_n(int a, int b);
	void(*p)(int, int);
	int a, b, act;

	printf("Please enter two integer numbers:");
	scanf("%d%d", &a, &b);
	printf("Please select the action you want to perform:\n");
	printf("1. max\n2. min\n3. add\n4. sub\n5. div\n6. mul\n");
	scanf("%d", &act);

	switch (act)
	{
	case 1:p = max_n; p(a, b); break;
	case 2:p = min_n; p(a, b); break;
	case 3:p = add_n; p(a, b); break;
	case 4:p = sub_n; p(a, b); break;
	case 5:p = div_n; p(a, b); break;
	case 6:p = mul_n; p(a, b); break;
	default:printf("Input error!\n\a"); break;
	}

	system("pause");
	return 0;
}

void max_n(int a, int b)
{
	printf("max = %d\n", (a<b) ? b : a);
}

void min_n(int a, int b)
{
	printf("min = %d\n", (a<b) ? a : b);
}

void add_n(int a, int b)
{
	printf("add = %d\n", a + b);
}

void sub_n(int a, int b)
{
	printf("sub = %d\n", a - b);
}

void div_n(int a, int b)
{
	if (b != 0)
	{
		float x, y;
		x = a; y = b;
		printf("div = %5.2f\n", x / y);
	}
	else
	{
		printf("The divisor cannot be 0!\n\a");
	}
}

void mul_n(int a, int b)
{
	printf("mul = %d\n", a*b);
}