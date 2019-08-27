#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

/***************************************
2.strcmp：比较字符串大小（一般用于字符串排序）
实现想法：依次从字符串开始一直找到不同的那个字符进行比较，得出大小
***************************************/
// 指针法
static int my_strcmp(const char * str1, const char * str2)
{
	while (*str1 && *str1 == *str2)
	{ // 一直找到两个字符串不同的地方
		str1++;
		str2++;
	}
	if (*str1 > *str2)
	{
		return 1;
	}
	else if (*str1 == *str2)
	{
		return 0;
	}
	else
	{
		return -1;
	}
}


int main_my_strcmp(void)
{
	const char * str1 = "feng1";
	const char * str2 = "feng1";

	cout << my_strcmp(str1, str2) << endl;

	cout << "Write By JZQ!" << endl;
	//自动排版：ctrl+k+F
	return 0;
}