#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

/*
小明同学最近学习了概率论，他了解到数学期望的定义：
设X为一个随机变量，X可以取n种不同的取值x1,x2,x3,…,xn。
取x1的概率为p1,取x2的概率为p2,以此类推。定义随机变量X的数学期望为：E[X]=x1*p1+x2*p2+…+xn*pn。
小明回到家中，他想编程计算数学期望，你能帮助他么？

输入
输入第一行一个数n(1<=n<=100)，接下来有n行，第i行有两个数xi和pi，xi和pi都是整数，
-100<=xi<=100, 0<=pi<=100。表示随机变量X取值为xi的概率是pi/100。输入保证p1+p2+p3+…+pn=100。
输出
输出一个数，随机变量X的数学期望E[x]，小数点后四舍五入保留3位。

样例输入
3
0 50
1 20
2 30

样例输出
0.800
*/

int main5121563564154165614651465(void)
{
	int N;
	double sum = 0;
	while (cin >> N)
	{
		int x, p;
		while (N--)
		{
			cin >> x >> p;
			sum += x * static_cast<double>(p) / 100;
		}
		printf("%.3f\n", sum);
	}

	//cout << "Write By JZQ!" << endl;
	//自动排版：ctrl+k+F
	return 0;
}