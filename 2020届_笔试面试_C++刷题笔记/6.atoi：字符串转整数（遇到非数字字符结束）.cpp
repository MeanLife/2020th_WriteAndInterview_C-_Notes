#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

/***************************************
6.atoi：字符串转整数（遇到非数字字符结束）
***************************************/
// 指针法
static int my_atoi(const char * str)
{
	if (str == nullptr)
	{
		return 0;
	}
	int num = 0; //需要返回的值
	int flag = 1; //记录正负号,1为正

	if (*str == '-')
	{
		flag = -1;
		str++;
	}
	else
	{
		flag = 1;
		*str == '+' ? str++ : str; // 若有+号，则前进一步，没有就不前进。
	}

	while (*str >= '0' && *str <= '9')
	{
		num = (num * 10) + (*str++ - '0');
	}
	return num * flag;
}


int main_my_atoi(void)
{
	char str[20] = "+57124";
	cout << my_atoi(str) << endl;
	cout << "Write By JZQ!" << endl;
	//自动排版：ctrl+k+F
	return 0;
}