#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

/***************************************
3.strcpy：用于字符串复制（复制包含'\0'）
实现想法：一直复制到'\0'结束
***************************************/
// 指针法
static char * my_strcpy(char * dest, const char * source)
{
	if (dest == nullptr || source == nullptr)
	{
		return nullptr;//如果目的操作或者源为空，那么久直接返回
	}

	while (*source)
	{ 
		*dest++ = *source++;
	}
	*dest = '\0';
	return dest;
}


int main_my_strcpy(void)
{
	const char * str1 = "fengcong is fucking too handsome";
	//char str2[100]; //目的字符数组
	char *str2 = new char[strlen(str1) + 1];
	my_strcpy(str2, str1);
	cout << str2 << endl;

	cout << "Write By JZQ!" << endl;
	//自动排版：ctrl+k+F
	return 0;
}