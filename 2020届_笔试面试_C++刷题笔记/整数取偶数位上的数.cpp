#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

// 给定程序中函数fun的功能是：从低位开始取出长整型变量s中偶数位上的数，
// 依次构成一个新数放在t中，高位仍在高位，低位仍是在低位。

static void fun(long s, long *t)
{
	long s1 = 10;
	s /= 10;
	*t = s % 10;
	while (s > 0)
	{
		s = s / 100;
		*t = s % 10 * s1 + *t;
		s1 = s1 * 10;
	}
}


int main_0251646463165(void)
{
	long s, t;
	cout << "\nPlease enter s:  ";
	cin >> s;
	fun(s, &t);
	cout << "\nThe result is: " << t << endl;

	
	cout<<"Write By JZQ!"<<endl;
	//自动排版：ctrl+k+F
	return 0;
}