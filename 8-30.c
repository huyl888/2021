#include <stdio.h>
#include <stdlib.h>
int main()
{
	void check(int *);	//��������
	int * p1, i;	//p1��int��ָ��
	p1 = (int *)malloc(5 * sizeof(int)); //���ٶ�̬�ڴ���,����ַת����int * ��,Ȼ����� p1 ��
	for (i = 0; i<5; i++)
	{
		scanf_s("%d", p1 + i);	//����5��ѧ���ĳɼ�
	}
	check(p1);

	system("pause");
}

void check(int *p)
{
	int i;
	printf("������ĳɼ�Ϊ:");
	for (i = 0; i<5; i++)
	{
		if (p[i]<60)
			printf("%d ", p[i]);
	}
	printf("\n");
}