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
物品有指定件，只需用num数组对weight和value进行重新初始化即可。
***************************************/
static int knasSack_kTimes(int n, int c, vector<int> &weight, vector<int> &value, vector<int> &num)
{
	vector<int> weightVec;
	vector<int> valueVec;
	// 物品有指定件，只需用num数组对weight和value进行重新初始化即可。
	for (int i = 0; i < n; i++)
	{
		while (num[i]--)
		{
			weightVec.push_back(weight[i]);
			valueVec.push_back(value[i]);
		}
	}
	// 物品有指定件，只需用num数组对weight和value进行重新初始化即可。

	/*
	这中间代码与经典背包问题代码一致。
	.......
	.......
	.......
	*/
	return 0;
}

int main_多重背包问题(void) // main_多重背包问题
{
	int n = 5; // 物品件数
	int c = 10; // 背包最大容量
	vector<int> weight = { 2,2,6,5,4 };
	vector<int> value = { 6,3,5,4,6 };
	vector<int> num = { 0 };
	int sumValue = 0;
	knasSack_kTimes(n, c, weight, value, num);

	cout << "Write By JZQ!" << endl;
	//自动排版：ctrl+k+F
	return 0;
}