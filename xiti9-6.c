#include <stdio.h>

#define MAXNUM 50;
#define LEN sizeof(struct Number)

struct Number {
	int num;
	int k;
	struct Number * Flink;
	struct Number * Blink;
};

int main()
{
	int n = MAXNUM;
	struct Number * person = NULL;
	struct Number * Creat_RingLinkedList(struct Number * per, int n);
	int person_num(struct Number * Head,int n);
	struct Number * Header;
	int h;
	Header = Creat_RingLinkedList(person, n);
	//for (int i = 1; i <= 13; i++)
	//{
	//	printf("%2d Flink:%d Node:%d Blink:%d\n", Header->num, Header->Flink,Header,Header->Blink);
	//	Header = Header->Flink;
	//}
	h = person_num(Header,n);
	printf("\n最后剩下的为原来的第 %d 位\n", h);

	system("pause");
	return 0;
}

struct Number * Creat_RingLinkedList(struct Number * per, int n)
{
	struct Number * Head = NULL;
	struct Number * p1= NULL, *p2 = NULL;
	for (int i = 1; i <= n; i++)
	{
		if (i == 1)
		{
			Head = p1 = p2 = (struct Number *)malloc(LEN);
			p1->num = i;
		}
		else
		{
			p2 = (struct Number *)malloc(LEN);
			p2->num = i;
			p1->Flink = p2;
			p2->Blink = p1;
			p1 = p2;
		}
	}
	p1->Flink = Head;
	Head->Blink = p1;

	return(Head);
}

int person_num(struct Number * Head,int n)
{
	struct Number * p1= NULL, *pdel;
	p1 =  Head;
	int z;
	int en = 0;
	while (n != 1)
	{
		
		for (int i = 1; i<=3; i++)
		{
			p1->k = i;
			//printf("%2d %2d %d\n", p1->num, p1->k, p1->Flink);
			if (p1->k == 3)
			{
				pdel = p1;
				p1->Blink->Flink = p1->Flink;
				p1->Flink->Blink = p1->Blink;
				//printf("%2d Flink:%d Node:%d Blink:%d\n", p1->Blink->num, p1->Blink->Flink, p1->Blink, p1->Blink->Blink);
				//printf("%2d Flink:%d Node:%d Blink:%d\n", p1->num, p1->Flink, p1, p1->Blink);
				//printf("%2d Flink:%d Node:%d Blink:%d\n", p1->Flink->num, p1->Flink->Flink, p1->Flink, p1->Flink->Blink);
				printf("第%2d名出圈  ", p1->num);
				en++;
				if (en % 3 == 0)
				{
					putchar('\n');
				}
				p1 = p1->Flink;
				free(pdel);
				n--;
			}
			else
			{
				p1 = p1->Flink;
				
			}
			//printf("%20d\n", p1->Flink);
			
		}
		
	}
	z = p1->num;
	return(z);
}