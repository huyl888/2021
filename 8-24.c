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
	printf("enter a and b(�м��Կո����):");
	scanf_s("%lf%lf", &a, &b);
	printf("\n����(1+x)��%4.1f��%4.1f�Ļ�����:", a, b);
	integral(a, b, f1);
	printf("\n����(2*x+3)��%4.1f��%4.1f�Ļ�����:", a, b);
	integral(a, b, f2);
	printf("\n����(e^x+1)��%4.1f��%4.1f�Ļ�����:", a, b);
	integral(a, b, f3);
	printf("\n����((1+x)^2)��%4.1f��%4.1f�Ļ�����:", a, b);
	integral(a, b, f4);
	printf("\n����(x^3)��%4.1f��%4.1f�Ļ�����:", a, b);
	integral(a, b, f5);

	system("pause");
	return 0;
}

double integral(double m, double n, double(*fun)(double))
{
	double sum = 0.0;
	double length = 1e-6;
	double z = m;
	while (z < n)											//�����ǻ��ֺ������±����С���ϱ� 
	{
		sum += ((*fun)(z) + (*fun)(z + length)) * length / 2;   /*��������滻Ϊsum+=((*fun)(z+length))*length; */
		z += length;                                    /*��ȻҲ�����滻Ϊsum+=((*fun)(z))*length; */
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