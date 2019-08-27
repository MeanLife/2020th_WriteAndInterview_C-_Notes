#include <iostream>
#include <vector>
using namespace std;

/***************************************
【题目】：
质数的定义为：在大于1的自然数中，除了1和它本身，不能被其他自然数整除，如2,3,23等。
给定一个取值范围[low,high)，找到该范围内的所有质数，输出这些质数的十位数之和和个位数之和的较小值，
如果该质数小于10，则其十位数为0，注意low在取值范围内，high不在。
输入描述：
第一行输入：low，high，用例保证均不小于0，且low < high，不用考虑输入合法性，如果没有质数，则输出0
输出描述：
输出找到的质数的十位数之和和个位数之和的较小值。
输入：151 160
输出：8
说明：[151,160)之间质数有151和157，十位之和：5+5=10，个位之和：1+7=8；所以输出8.
【思路】：

***************************************/

int main_第二题(void)
{
	int low, high;
	while (cin >> low >> high)
	{
		bool flag = true;
		vector<int> arr;
		for (int value = low; value < high; value++)
		{
			flag = true;
			for (int i = 2; i < value; i++)
			{
				if (0 == value % i)
				{
					flag = false; // 若这之间的数能被value整数，则它不是质数
				}
			}
			if (true == flag)
			{
				arr.push_back(value); // 将所有的质数保存下来。
			}
		}

		int firstNumSum = 0;
		int secondNumSum = 0;
		for (int i = 0; i < arr.size(); i++)
		{
			firstNumSum += arr[i] % 10; // 所有的个位的和
			secondNumSum += arr[i] >= 10 ? (arr[i] / 10 % 10) : 0; // 所有的十位的和
		}
		cout << (firstNumSum < secondNumSum ? firstNumSum : secondNumSum) << endl;
	}
	return 0;
}