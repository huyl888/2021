#include "MyString.h"

int MyStrLen(const char * str)
{
	const char * eos = str;
	while (*eos++);//找到字符串末尾位置('\0'的位置)
	return (eos - str - 1);//末尾位置减开始位置(带'\0',所以要再减1)
}

bool MyStrCmp(char * str1, char * str2)
{
	int nLen1 = MyStrLen(str1);
	int nLen2 = MyStrLen(str2);
	if (nLen1 != nLen2)
	{
		return false;
	}
	for (size_t i = 0; i < nLen1; i++)
	{
		if (*str1 != *str2)
		{
			return false;
		}
		*str1++;
		*str2++;
	}
	return true;
}

bool MyStrCpy(char * str1, char * str2,int Length)
{
	for (size_t i = 0; i < Length; i++)
	{
		str1[i] = str2[i];
	}
	str1[Length] = '\0';
	return true;
}

bool MyStrCat(char * str1, char * str2)
{
	int dLength = MyStrLen(str1);
	int sLength = MyStrLen(str2);
	for (size_t i = 0; i < sLength; i++)
	{
		str1[dLength + i] = str2[i];
	}
	str1[dLength + sLength] = '\0';
	return true;
}

int MyStrstr(char * buffer, char * subbuffer)
{
	int Length = MyStrLen(buffer);
	int subLength = MyStrLen(subbuffer);
	if (subLength > Length)
	{
		return -1;
	}
	for (size_t i = 0; i < Length; i++)
	{
		int nFlag = 0;
		for (size_t k = 0; k < subLength; k++)
		{
			if (buffer[k + i] == subbuffer[k])
			{
				nFlag++;
				if (nFlag == subLength)
				{
					return i;
				}
			}
		}

	}
	return -1;
}

bool MyStrSlic(char * sBuffer, char * dBuffer, int start, int end)
{
	int nLength = MyStrLen(sBuffer);
	if (nLength < start && (end - start) < nLength)
	{
		return false;
	}
	int Size = end - start;
	for (size_t i = 0; i < Size; i++)
	{
		dBuffer[i] = sBuffer[start + i];
	}
	dBuffer[end-start+1] = '\0';
	return true;
}
