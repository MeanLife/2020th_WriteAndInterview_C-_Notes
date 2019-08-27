/*
博客：https://blog.csdn.net/hongtao_6/article/details/93924799
博客：https://blog.csdn.net/laoniu_c/article/details/38453083
动态规划解答
*/
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

// 打印二维数组vector<vector<int>> array
static void print_2D_Array(vector<vector<int>> array)
{
	for (unsigned i = 0; i < array.size(); ++i)
	{
		for (vector<int>::iterator it = array[i].begin(); it != array[i].end(); it++)
		{
			cout << *it << "  ";
		}
		cout << endl;
	}
	cout << endl;
}

/***************************************
n件物品，每件物品重weight，价值value；背包最大容量是c.
***************************************/
static vector<bool> knasSack(int n, int c, vector<int> &weight, vector<int> &value)
{
	// 最大价值表，n+1行（第i行代表第i件物品），每一行是一个一维数组vector<int>(c + 1, 0)，即，c+1列（第i列代表背包重量为i）
	vector<vector <int>> maxValue_table(n + 1, vector<int>(c + 1, 0)); 
	// 记录物品选或不选，下标从0开始。
	vector<bool> result(n, false);
	// 创建动态规划表。
	for (int i = 1; i <= n; i++) // 第0行不使用，没有0号物品
	{
		for (int j = 1; j <= c; j++) // 第0行背包容量为0（初始化为0即可）
		{
			if (i == 1) // 第1行（第1件物品，下标为0），只有一件物品，只要能放下，直接放。
			{
				maxValue_table[i][j] = (weight[i - 1] <= j ? value[i - 1] : 0);
			}
			else
			{
				// 上一个网格的值，即，不加第i件物品：前面i-1件物品的最大价值
				int frontValue = maxValue_table[i - 1][j];
				// 加第i件物品：当前商品的价值 + 剩余空间的价值
				int thisValue = (weight[i - 1] <= j ? value[i - 1] + maxValue_table[i - 1][j - weight[i - 1]] : frontValue);
				// 返回 topValue和thisValue中较大的一个
				maxValue_table[i][j] = (frontValue > thisValue ? frontValue : thisValue);
			}
		}
	}
	print_2D_Array(maxValue_table);

	// 动态规划表创建好了，现在根据物品件数和背包容量来选择最大价值的装载。
	for (int i = n, j = c; i > 0; i--) // 从右下角开始。
	{
		if (maxValue_table[i][j] > maxValue_table[i - 1][j])
		{
			result[i - 1] = true;
			j = j - weight[i - 1];
		}
	}
	return result;
}


int main_背包问题_经典(void)
{
	int n = 5; // 物品件数
	int c = 10; // 背包最大容量
	vector<int> weight = { 2,2,6,5,4 };
	vector<int> value = { 6,3,5,4,6 };
	int sumValue = 0;
	vector<bool> result = knasSack(n, c, weight, value);
	for (int i = 0; i < result.size(); i++)
	{
		if (result[i])
		{
			sumValue += value[i];
		}
		// 物品选择情况，下标，从0开始
		cout << "第" << i << "件物品：" << (result[i] == true ? "选" : "不选") << endl;
	}
	cout << sumValue << endl; // 总价值

	cout << "Write By JZQ!" << endl;
	//自动排版：ctrl+k+F
	return 0;
}