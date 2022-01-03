#include<stdio.h>
#include<math.h>

int main()
{
	double f1(double);
	double f2(double);
	double f3(double);
	double f4(double);
	double f5(double);
	double integral(double, double, double(*fun)(double));
	double a, b;
	printf("enter a and b(中间以空格隔开):");
	scanf_s("%lf%lf", &a, &b);
	printf("\n函数(1+x)在%4.1f到%4.1f的积分是:", a, b);
	integral(a, b, f1);
	printf("\n函数(2*x+3)在%4.1f到%4.1f的积分是:", a, b);
	integral(a, b, f2);
	printf("\n函数(e^x+1)在%4.1f到%4.1f的积分是:", a, b);
	integral(a, b, f3);
	printf("\n函数((1+x)^2)在%4.1f到%4.1f的积分是:", a, b);
	integral(a, b, f4);
	printf("\n函数(x^3)在%4.1f到%4.1f的积分是:", a, b);
	integral(a, b, f5);

	system("pause");
	return 0;
}

double integral(double m, double n, double(*fun)(double))
{
	double sum = 0.0;
	double length = 1e-6;
	double z = m;
	while (z < n)											//条件是积分函数的下标必须小于上标 
	{
		sum += ((*fun)(z) + (*fun)(z + length)) * length / 2;   /*这里可以替换为sum+=((*fun)(z+length))*length; */
		z += length;                                    /*当然也可以替换为sum+=((*fun)(z))*length; */
	}
	printf("%6.3f\n", sum);
	return 1;
}

double f1(double x)
{
	return 1 + x;
}

double f2(double x)
{
	return 2 * x + 3;
}

double f3(double x)
{
	return exp(x) + 1;
}

double f4(double x)
{
	return x * x + 2 * x + 1;
}

double f5(double x)
{
	return x * x * x;
}