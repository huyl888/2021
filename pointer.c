#include "pointer.h"



#if(0)

#endif	//可以用来注释一整段代码为0时不编译.为1时编译

//void main()
//{
//	char *a = "I love chain!";		//用指针变量定义字符串时,是将字符串的偏移地址赋值给指针变量,放在常量区
//	char b[] = "I'm a worker!";		//此处应定义为 char b[] 
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
//	int a[3][4] = { 0,1,2,3,4,5,6,7,8,9,10,11 };	//定义二维数组
//	int i, j;
//	int (*p)[4];	//定义指针指向二维数组(数组有4列)
//	p = a;
//	t: printf("请输入i和j:");
//	scanf("%d%d", &i,&j);
//	if ( i > 2 || j > 3)
//	{
//		printf("输入错误请重新输入!\n");
//		goto t;
//	}
	//for (i = 0; i < 3; i++)
	//{
	//	for (j = 0; j < 4; j++)
	//	{
			//printf("数组元素[%d][%d]=%d\n",i,j ,*(*(p+i)+j));
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
	//printf("原始数据为:");
	//for (i = 0; i < n; i++)
	//{
	//	printf("%3d", a[i]);
	//}
	//printf("\n");
	//search(p, n);
	//printf("max = %d min = %d\n", max, min);
	//reverse(a, n);	//逆序重新排放数组
	//printf("逆序排放后:");
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

//void reverse(int *a, int n)	//形参 a 为指针变量
//{
//	int temp, *i,*j,*p,m;
//	m = (n - 1) / 2;
//	i = a;				//i 指向数组a 的第一个元素
//	j = a + n - 1;	//j指向数组a 的最后一个元素
//	p = a + m;	//p指向数组a 的中间元素
//	for (; i <= p; i++,j--)	//条件中的数据必须类型匹配
//	{
//		temp = *i;
//		*i = *j;
//		*j = temp;
//	}
//}