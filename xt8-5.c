#include <stdio.h>
//#define MAX 1000

int main()
{
	//int a[MAX];
	int *a;
	int n, i, out = 0, num, j = 0;//(n�ǲ�������,i��ѭ������,out�ǳ�Ȧ����.num�Ǳ������ڼ���
	printf("Enter the number of people:");
	scanf("%d", &n);
	a = (int *)malloc(n * sizeof(int));//������̬����
	for (i = 0; i < n; i++)                                    
	{
		a[i] = i + 1;	//��ÿ���˱��(��1��ʼ)
	}
	for (i = 0, num = 1; (n - out) != 1; i = (i + 1) % (n - out), num++)//num���˵����,out�ǳ�Ȧ����,������������i=(i+1)%(n-out);Ŀ������i�Զ�����,n-outΪ��������,
	{
		if (num % 3 == 0)
		{
			for (j = i; j < n - out; j++)                          //�����������ǰ����
				a[j] = a[j + 1];
			out++;
			num++;
		}
	}
	printf("The last one is No.%d.\n", a[0]);                             //���һ����

	system("pause");
	return 0;
}