#include <stdio.h>
int main()
{
	float score[][4] = { { 60,70,80,90 },{ 56,89,67,88 },{ 34,78,90,66 } };//��������,��ųɼ�
	float *p;	//����ָ�����
	int i, k;
	float *search(float(*p)[4], int n);//��������
	printf("������Ҫ��ѯ��ѧ��ѧ��:");
	scanf_s("%d", &k);	//����Ҫ��ѯ��ѧ��ѧ��
	p = search(score, k);//���ú�������ֵ
	printf("��%d��ѧ���ĳɼ�Ϊ:", k);
	for (i = 0; i<4; i++)
	{
		printf("%5.2f ", *(p + i));//������γɼ�
	}
	putchar('\n');

	system("pause");
	return 0;
}

float *search(float(*pointer)[4], int n)//�β�pointer��ָ��һά�����ָ�����
{
	float *pt;
	pt = *(pointer + n-1);	//pt��ֵ�� &score[n][0]
	return(pt);
}