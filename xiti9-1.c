#include <stdio.h>
#include <stdlib.h>

struct Yearmd {
	int year;
	int month;
	int day;
};

int main()
{
	struct Yearmd input_s;
	int dnum;
	printf("请输入年月日,用空格间隔\n");
	scanf("%d%d%d", &input_s.year, &input_s.month, &input_s.day);
	int days(struct Yearmd);
	dnum = days(input_s);
	printf("%d 年 %d 月 %d 日为 %d 的第 %d 天.\n", input_s.year, input_s.month, input_s.day, input_s.year, dnum);

	system("pause");
	return 0;
}

int days(struct Yearmd input)
{
	int leap_flag, count;
	if ((input.year % 4 == 0) && (input.year % 100 != 0))
	{
		leap_flag = 1;
	}
	else if ((input.year % 100 == 0) && (input.year % 400 == 0))
	{
		leap_flag = 1;
	}
	else
	{
		leap_flag = 0;
	}
	switch (input.month)
	{
	case 1: count = 0;
		break;
	case 2: count = 31;
		break;
	case 3: count = 59;
		break;
	case 4: count = 90;
		break;
	case 5: count = 120;
		break;
	case 6: count = 151;
		break;
	case 7: count = 181;
		break;
	case 8: count = 212;
		break;
	case 9: count = 243;
		break;
	case 10: count = 273;
		break;
	case 11: count = 304;
		break;
	case 12: count = 334;
		break;
	}
	if (input.month > 2)
	{
		count = count + input.day + leap_flag;
	}
	else
	{
		count = count + input.day;
	}
	return count;
}