#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

/***************************************
9.strcat：字符串连接
思路：直接接在目的字符串的尾部
***************************************/
// 指针法
static char * my_strcat(char * dest, const char * src)
{
	char *pdest = dest;
	while (*pdest)
	{
		pdest++; // 到尾部去
	}
	while (*src)
	{
		*pdest++ = *src++;
	}
	return dest;
}


int main_my_strcat(void) // main_my_strcat
{
	char str[30] = " fucking too handsome";
	char dest[50] = "fengcong is";
	cout << my_strcat(dest, str) << endl;
	cout << "Write By JZQ!" << endl;
	//自动排版：ctrl+k+F
	return 0;
}