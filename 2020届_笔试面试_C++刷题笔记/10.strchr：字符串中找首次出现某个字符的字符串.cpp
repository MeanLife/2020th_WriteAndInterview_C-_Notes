#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

/***************************************
10.strchr：字符串中找首次出现某个字符的字符串
***************************************/
// 指针法
static char * my_strchr(const char * str, const int val)
{
	char *pdest = (char *)str;
	while (*pdest)
	{
		if (*pdest == (char)val)
		{
			return pdest;
		}
		pdest++;
	}
	return nullptr;
}


int my_strchr(void) // my_strchr
{
	char str[30] = "fucking too handsome";
	cout << strchr(str, 'o') << endl;
	cout << "Write By JZQ!" << endl;
	//自动排版：ctrl+k+F
	return 0;
}