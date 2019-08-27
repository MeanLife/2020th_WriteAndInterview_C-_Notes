#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

/***************************************
1.strlen：计算字符串长度（不包含'\0'）
实现想法：遍历字符串，直到'\0'结束
***************************************/
// 指针法
static unsigned int my_strlen(const char *str)
{
	int len = 0;
	while (*(str++)) // *(str++) 与 *str++ 一样
	{
		len++;
	}
	return len;
}


int main_my_strlen(void)
{
	const char *str = "fengcong is fucking too handsome";  //32个
	cout << strlen(str) << endl;
	cout << my_strlen(str) << endl;
	
	cout<<"Write By JZQ!"<<endl;
	//自动排版：ctrl+k+F
	return 0;
}