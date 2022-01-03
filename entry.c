#include "entry.h"

int main()
{
	int d[3][3] = {
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};
	int(*p)[3];
	p = d;
	printf("%d %d %d %d", **p, *p[2], **p + 1,*p[2]+1);
	system("pause");
}