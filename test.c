#include "MyString.h"
#include <stdio.h>

int main()
{
	char * str1 = "huyllovehuyllovehuyllovehuyllovehuyllovehuyllove";
	char * str2 = "huyllove";
	char str3[50] = { 0 };
	char str4[10];
	//MyStrCpy(str3, str1,8);
	//printf("%s\n", str3);
	//MyStrCat(str3, str1, 8);
	//printf("%s\n", str3);
	//MyStrCat(str3, str1, 8);
	//printf("%s\n", str3);
	int t = MyStrstr(str3, "love");
	printf("%d\n", t);
	MyStrSlic(str1, str3, 2, 10);
	printf("%s", str3);
	system("pause");
	return 0;
}