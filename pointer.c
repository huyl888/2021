#include "pointer.h"



#if(0)

#endif	//��������ע��һ���δ���Ϊ0ʱ������.Ϊ1ʱ����

//void main()
//{
//	char *a = "I love chain!";		//��ָ����������ַ���ʱ,�ǽ��ַ�����ƫ�Ƶ�ַ��ֵ��ָ�����,���ڳ�����
//	char b[] = "I'm a worker!";		//�˴�Ӧ����Ϊ char b[] 
//	printf("String a = %s\n", a);
//	printf("String b = %s\n", b);
//
//	str_copy(a, b);
//
//	printf("Copying....\n");
//	printf("String a = %s\n", a);
//	printf("String b = %s\n", b);
//
//	printf("\n");
//	system("pause");
//}
//
//void str_copy(char *from, char *to)
//{
//	char *p1, *p2;
//	p1 = from;
//	p2 = to;
//
//	while ((*p2++ = *p1++) != '\0')
//	{
//		;
//	}
//}

//void str_copy(char *from, char *to)
//{
//	for (; *from != '\0'; from++, to++)
//	{
//		*to = *from;
//	}
//}

//void main()
//{
//	int a[3][4] = { 0,1,2,3,4,5,6,7,8,9,10,11 };	//�����ά����
//	int i, j;
//	int (*p)[4];	//����ָ��ָ���ά����(������4��)
//	p = a;
//	t: printf("������i��j:");
//	scanf("%d%d", &i,&j);
//	if ( i > 2 || j > 3)
//	{
//		printf("�����������������!\n");
//		goto t;
//	}
	//for (i = 0; i < 3; i++)
	//{
	//	for (j = 0; j < 4; j++)
	//	{
			//printf("����Ԫ��[%d][%d]=%d\n",i,j ,*(*(p+i)+j));
		//}
		//printf("\n");
	//}
	//system("pause");
//}

//int main()
//{
	//int a[11] = {10,15,12,35,44,57,16,72,18,79,17};
	//int *p,i,n;
	//p = a;
	//n = 11;
	//printf("ԭʼ����Ϊ:");
	//for (i = 0; i < n; i++)
	//{
	//	printf("%3d", a[i]);
	//}
	//printf("\n");
	//search(p, n);
	//printf("max = %d min = %d\n", max, min);
	//reverse(a, n);	//���������ŷ�����
	//printf("�����ŷź�:");
	//for (i = 0; i < n; i++)
	//{
	//	printf("%3d", a[i]);
	//}
//	printf("\n");
//
//	system("pause");
//	return 0;
//}

//void search(int a[],int n)
//{
//	int *p,i;
//	p = a;
//	max = *p;
//	min = *p;
//	for (i = 0; i < n; i++,p++)
//	{
//		if (*p > max)
//		{
//			max = *p;
//		}
//		if (*p < min)
//		{
//			min = *p;
//		}
//	}
//}

//void reverse( int a[],int n )
//{
//	int i, temp;
//	for (i = 0; i <= n/2; i++)
//	{
//			temp = a[i];
//			a[i] = a[n - i-1];
//			a[n - i-1] = temp;
//	}
//}

//void reverse(int *a, int n)	//�β� a Ϊָ�����
//{
//	int temp, *i,*j,*p,m;
//	m = (n - 1) / 2;
//	i = a;				//i ָ������a �ĵ�һ��Ԫ��
//	j = a + n - 1;	//jָ������a �����һ��Ԫ��
//	p = a + m;	//pָ������a ���м�Ԫ��
//	for (; i <= p; i++,j--)	//�����е����ݱ�������ƥ��
//	{
//		temp = *i;
//		*i = *j;
//		*j = temp;
//	}
//}