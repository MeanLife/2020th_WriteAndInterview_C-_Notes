#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

/***************************************
【题目】：
判断输入的一个数，转为二进制后，能否形成回文
输入描述：
第一个数n：有n个样例
后面n行：n个样例
输出描述：
是否为回文
输入：
3
2
3
5
输出：
NO
YES
YES
【思路】：
1、转为二进制，判断即可
2、不转，用栈。。。。该方法得去找解析
***************************************/

static string TenToTwo(int n)
{
	string ans = "";
	do
	{
		int t = n % 2;
		ans += t + '0';
		n /= 2;
	} while (n != 0);    //使用do{}while（）以防止输入为0的情况
	reverse(ans.begin(), ans.end());
	return ans;
}

int 网易互娱__第一题(void) // 网易互娱__第一题
{
	int n;
	while (cin >> n)
	{
		if (n <= 0)
		{
			break;
		}
		vector<int> input_(n, 0);
		for (int i = 0; i < n; ++i)
		{
			cin >> input_[i];
		}
		for (int i = 0; i < n; ++i)
		{
			string res = TenToTwo(input_[i]);
			cout << "res = " << res << endl;
			string num2 = res;
			reverse(num2.begin(), num2.end());
			cout << (num2 == res ? "YES" : "NO") << endl;
		}
	}
	return 0;
}