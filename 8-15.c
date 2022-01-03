#include <stdio.h>
#include "8-15.h"
void main()
{
	float score[3][4] = { { 65,57,70,60 },{ 58,87,90,81 },{ 90,99,100,98 } };
	search(score);

	system("pause");
}

void search(float(*p)[4])
{
	int i, j, k;
	for (i = 0; i<3; i++)
	{
		for (j = 0; j<4; j++)
		{
			if (*(*(p + i) + j)<60)
			{
				printf("No.%dµÄ³É¼¨Îª:", i+1);
				for (k = 0; k<4; k++)
				{
					printf("%5.1f", *(*(p + i) + k));
				}
				printf("\n");
			}
		}
	}
}