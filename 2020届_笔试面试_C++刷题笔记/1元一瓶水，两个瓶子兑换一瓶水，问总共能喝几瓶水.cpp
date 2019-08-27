#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

/*
用c++编程实现：有40块钱，一瓶水的价格是1元，2个空瓶可以兑换1瓶水，问总共可以喝多少瓶的水？
可以不考虑问老板借瓶子的情况，谢谢！
好吧，我说清楚了哦，是用c++编程求解来实现，况且答案是79瓶
*/

#define P 1 //汽水的单价
#define N 2 //换一瓶汽水所需的空瓶个数

//SodaConvert函数返回用空瓶换来的汽水个数
static int SodaConvert(int x)
{
	if (x < N)
	{
		return 0;
	}
	int ret = x / N;// 空瓶兑换的汽水个数
	cout << "ret = " << ret << endl;
	x = ret + x % N; // 兑换的汽水和剩下的空瓶个数之和 = 现在的空瓶。
	return (ret + SodaConvert(x));

}

int main_sda156(void)
{
	int money = 0;
	int n = 0;
	cout << ("请输入金额：");
	cin >> money;
	n = money / P;
	int bottle = n + SodaConvert(n);//最终喝到的汽水个数 = 买到的 + 空瓶换到的
	cout << bottle << "瓶" << endl;
	
	cout<<"Write By JZQ!"<<endl;
	//自动排版：ctrl+k+F
	return 0;
}