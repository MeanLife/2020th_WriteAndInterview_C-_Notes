/*
博客：https://blog.csdn.net/hongtao_6/article/details/93924799
博客：https://blog.csdn.net/laoniu_c/article/details/38453083
动态规划解答
*/
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>
using namespace std;

// 打印二维数组vector<vector<int>> array
static void print_2D_Array(vector<vector<int>> array)
{
	for (unsigned i = 0; i < array.size(); ++i)
	{
		for (vector<int>::iterator it = array[i].begin(); it != array[i].end(); it++)
		{
			cout << setw(3) << *it;
		}
		cout << endl;
	}
	cout << endl;
}

/***************************************
n件物品，每件物品重weight，价值value；背包最大容量是c.
物品件数有无穷多，初始化时从右向左初始化即可。加入变量times表示放了几件当前物品。
【注意】
因为每件物品有无穷多件，所以可能会有多种不同的选择，这里只求出一种选择和全部选择的最大的值。可以根据最大的值来求出其他选择。
***************************************/
static vector<int> knasSack_nTimes(int n, int c, vector<int> &weight, vector<int> &value)
{
	// 最大价值表，n+1行（第i行代表第i件物品），每一行是一个一维数组vector<int>(c + 1, 0)，即，c+1列（第i列代表背包重量为i）
	vector<vector <int>> maxValue_table(n + 1, vector<int>(c + 1, 0));
	// 记录物品选或不选，下标从0开始。
	vector<int> result(n, false);
	// 加入变量times表示放了几件当前物品。
	int times = 0;
	// 创建动态规划表。
	for (int i = 1; i <= n; i++) // 第0行不使用，没有0号物品
	{
		for (int j = 1; j <= c; j++) // 第0行背包容量为0（初始化为0即可）
		{
			times = j / weight[i - 1]; // j这个容量，能放下几件i这个物品。
			if (i == 1) // 第1行（第1件物品，下标为0）
			{
				maxValue_table[i][j] = (times > 0 ? value[i - 1] * times : 0);
			}
			else
			{
				// 上一个网格的值，即，不加第i件物品：前面i-1件物品的最大价值
				int frontValue = maxValue_table[i - 1][j];
				// 加第i件物品：当前商品的价值 + 剩余空间的价值
				int thisValue = 0;
				if (times > 0)
				{
					for (int k = 1; k <= times; k++)
					{
						thisValue = value[i - 1] * k + maxValue_table[i - 1][j - weight[i - 1] * k] > thisValue ? value[i - 1] * k + maxValue_table[i - 1][j - weight[i - 1] * k] : thisValue;			
					}
				}
				else
				{
					thisValue = frontValue;
				}
				// 返回 topValue和thisValue中较大的一个
				maxValue_table[i][j] = (frontValue > thisValue ? frontValue : thisValue);
			}
		}
	}
	print_2D_Array(maxValue_table);
	// 动态规划表创建好了，现在根据物品件数和背包容量来选择最大价值的装载。
	for (int i = n, j = c; i > 0; i--) // 从右下角开始。
	{ // 同一列中，如果下面的数比上面的数大，说明当前行选了的。
		if (maxValue_table[i][j] > maxValue_table[i - 1][j])
		{
			int times = j / weight[i - 1];
			result[i - 1] = times;
			//j = j - weight[i - 1];
			j = j - weight[i - 1] * times;
		}
	}
	return result;
}


int main_完全背包问题(void) // main_完全背包问题
{
	int n = 5; // 物品件数
	int c = 10; // 背包最大容量
	vector<int> weight = { 2,2,6,5,4 };
	vector<int> value = { 6,3,2,4,7 };
	int sumValue = 0;
	vector<int> result = knasSack_nTimes(n, c, weight, value);
	for (int i = 0; i < result.size(); i++)
	{
		if (result[i] != 0)
		{
			sumValue += value[i] * result[i];
		}
		// 物品选择情况，下标，从0开始
		cout << "第" << i << "件物品：" << (result[i] != 0 ? "选" : "不选") << result[i] << "件" << endl;
		//cout << "第" << i << "件物品：" << (result[i] == true ? "选" : "不选") << endl;
	}
	cout << sumValue << endl; // 总价值

	cout << "Write By JZQ!" << endl;
	//自动排版：ctrl+k+F
	return 0;
}