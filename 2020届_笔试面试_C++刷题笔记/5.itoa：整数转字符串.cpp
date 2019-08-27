#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

/***************************************
5.itoa:整数转字符串
***************************************/
// 指针法
static char * my_itoa(int value, char * str)
{
	char *pstr = str; //str本身不能改变，一会要返回str
	if (value < 0)
	{
		*pstr++ = '-';
		value *= -1; //转变为正数处理
	}
	int wei = 1; //数至少一位
	int value_temp = value; // 用于测试长度
	while ((value_temp /= 10) > 0)
	{
		wei++;
	}
	pstr += wei; // 从后往前转换
	*pstr-- = '\0'; // 最后一位以'\0'结尾，其实不加也可以，因为初始化为0了的
	while (value > 0)
	{
		*pstr-- = value % 10 + '0';
		value /= 10;
	}
	return str;
}


int main_my_itoa(void)
{
	int num = -4564421;
	char str[20] = { 0 };
	cout << my_itoa(num, str) << endl;
	cout << "Write By JZQ!" << endl;
	//自动排版：ctrl+k+F
	return 0;
}