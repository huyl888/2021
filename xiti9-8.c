#include "xiti9-8.h"

int main()
{
	struct Stu stua[] = { { "����",1003,"��",15,60 },{ "����",1005,"��",15,60 } ,{ "����",1004,"��",15,60 } };	//����A
	struct Stu stub[] = { { "����",1001,"Ů",15,60 },{ "����",1004,"��",15,60 } ,{ "����",1007,"Ů",15,60 } };	//����B
	struct Stu * Header_a = NULL,* pa = NULL, * Header_b = NULL, *pb = NULL, *pt = NULL;
	stua[0].Flink = &stua[1];
	stua[1].Blink = &stua[0];
	stua[1].Flink = &stua[2];
	stua[2].Blink = &stua[1];
	stub[0].Flink = &stub[1];
	stub[1].Blink = &stub[0];
	stub[1].Flink = &stub[2];
	stub[2].Blink = &stub[1];
	Header_b = stub[1].Blink;
	Header_a = stua[1].Blink;	//��ɾ�̬����ṹ
	printf("��� A ������\n");
	print(Header_a, 3);
	printf("��� B ������\n");
	print(Header_b, 3);

	del_mes(Header_a, 3, Header_b, 3);
	printf("��� A ������\n");
	print(Header_a, 3);

	stub[2].Flink = stua[1].Blink;
	stua[0].Blink = stub[1].Flink;	//��A����B���γ�������headB
	printf("��� B ������\n");
	print(Header_b, 6);
	
	long int MinNum = 0;
	for (int i = 0; i < 6; i++)
	{
		pb = Header_b;
		MinNum = pb->StuNum;
		pt = pb;
		if (i == 0)	//�ҳ��������� A ���׽��
		{
			pb = pb->Flink;
			for (int j = 0; j < 6 - i; j++)
			{
				if (MinNum > pb->StuNum)
				{
					MinNum = pb->StuNum;
					pt = pb;
				}
				else
				{
					pb = pb->Flink;
				}
			}
			if (pt->Blink == NULL)
			{
				Header_a = pt;
				Header_b = pt->Flink;
				Header_b->Blink = NULL;
				pt->Flink = NULL;
			}
			else if (pt->Flink == NULL)
			{
				Header_a = pt;
				pb = pt->Blink;
				pb->Flink = NULL;
				pt->Blink = NULL;
			}
			else
			{
				Header_a = pt;
				pb = pt->Blink;
				pb->Flink = pt->Flink;
				pb = pt->Flink;
				pb->Blink = pt->Blink;
				pt->Flink = NULL;
				pt->Blink = NULL;
			}
			pa = Header_a;
		}
		else if (i == 6)
		{
			pa->Flink = pt;
			pt->Blink = pa;
		}
		else
		{
			pb = pb->Flink;
			for (int j = 0; j < 6 - i; j++)
			{
				if (MinNum > pb->StuNum)
				{
					MinNum = pb->StuNum;
					pt = pb;
				}
				else
				{
					pb = pb->Flink;
				}
			}
			if (pt->Blink == NULL)
			{
				Header_b = pt->Flink;
				Header_b->Blink = NULL;
				pt->Flink = NULL;
			}
			else if (pt->Flink == NULL)
			{
				pb = pt->Blink;
				pb->Flink = NULL;
				pt->Blink = NULL;
			}
			else
			{
				pb = pt->Blink;
				pb->Flink = pt->Flink;
				pb = pt->Flink;
				pb->Blink = pt->Blink;
				pt->Flink = NULL;
				pt->Blink = NULL;
			}
			pa->Flink = pt;
			pt->Blink = pa;
			pa = pa->Flink;
		}
	}
	printf("��� A ������\n");
	print(Header_a, 6);

	system("pause");
}

void print(struct Stu * Head, int n)
{
	//char TName[20], TSex[2];

	struct Stu * p = NULL;
	p = Head;
	for (int i = 0; i<n; i++)
	{
		printf("%s %ld %s %d %5.2f\n", p->Name, p->StuNum, p->Sex, p->Age, p->Score);
		p = p->Flink;
	}
}

void del_mes(struct Stu * Head1, int n1, struct Stu * Head2, int n2)
{
	struct Stu * p1, *p2;
	p1 = Head1;
	p2 = Head2;
	int i, j;
	for (i = 0; i < n1; i++)
	{
		for (j = 0; j < n2; j++)
		{
			if (p1->StuNum == p2->StuNum)
			{
				p1->Flink->Blink = p1->Blink;
				p1->Blink->Flink = p1->Flink;
				//free(p1);
			}
			p2 = p2->Flink;
		}
		p1 = p1->Flink;
	}
}