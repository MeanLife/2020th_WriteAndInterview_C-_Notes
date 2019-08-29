/*
题目描述：
维克多博士创造了一个裂变反应堆，可取用处于液体状态的放射性物质。反应堆的容量是V加仑。
他有N瓶的放射性液体，每个都有一定的质量和一定的体积。当液体倒入反应堆时，也产生一些单位的能量。
现在，维克多想要将能量输出最大化。但是，有一个限制条件。他研究了原子元素的物理知识和历史，
认识到反应堆内放射性液体的总量不能超过特定的临界质量M，否则反应就会失控，并引发剧烈的爆炸。
写一个算法，帮助他从反应堆获得最大的能量，而不会让他丢掉性命。

输入：
该函数/方法的输入包括六个参数------
reactorCap，一个整数，表示反应堆的容量(V);
numberOfRadLiquid,一个整数，表示现有小瓶的数量(N);
criticalMass，一个整数，表示反应堆的最大临界质量(M);
volumes，一个整数列表，按顺序表示N份放射性液体的体积;
masses，一个整数列表，按顺序表示N份放射性液体的质量;
energies,一个整数列表，按顺序表示N份放射性液体产生的能量。

输出：
返回一个整数，表示可给定的约束条件下从反应堆中产生的最大能量。

示例：
输入：
reactorCap=100
numberOfRadLiquid=5
criticalMass=15
volumes=[50,40,30,20,10]
masses=[1,2,3,9,5]
energies=[300,480,270,200,180]
输出：
960

解释：
通过选择1、2、5号瓶中的液体，产生的能量=300+480+180=960。
这种液体组合产生的总体积=50+40+10=100，不大于reactorCap,
造成反应堆中的总质量=1+2+5=8，不大于criticalMass。

解题思路：这是一个有两个限制条件的0-1背包问题，0-1背包问题可以参考我的另一篇博文：0-1背包问题，
这里只需将一个限制条件的二维动态规划表变成一个三维动态规划表。
博客《https://blog.csdn.net/hongtao_6/article/details/97246319》
*/


#include <iostream>
#include <vector>
#include <algorithm>
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
解题思路：这是一个有两个限制条件的0-1背包问题，
这里只需将一个限制条件的二维动态规划表变成一个三维动态规划表。
***************************************/
static int maxEnergyGenerate(int reactorCap, int numberOfRadLiquid, int criticalMass, int volumes[], int masses[], int energies[])
{
	vector<vector<vector<int>>> maxValue(numberOfRadLiquid + 1, vector<vector<int>>(reactorCap + 1, vector<int>(criticalMass + 1, 0)));
	
	for (int i = 1; i <= numberOfRadLiquid; i++)
	{
		for (int j = 1; j <= reactorCap; j++)
		{
			for (int k = 1; k <= criticalMass; k++)
			{
				if (i == 1)
				{
					maxValue[i][j][k] = (((volumes[i - 1] <= j) && (masses[i - 1] <= k)) == true ? energies[i - 1] : 0);
				}
				else
				{
					int topValue = maxValue[i - 1][j][k];  // 上一个网格的值
					// 当前商品的价值 + 剩余空间的价值
					int thisValue = 0;
					if ((volumes[i - 1] <= j) && (masses[i - 1] <= k))
					{
						thisValue = energies[i - 1] + maxValue[i - 1][j - volumes[i - 1]][k - masses[i - 1]];
					}
					else
					{
						thisValue = topValue;
					}
					maxValue[i][j][k] = (topValue > thisValue ? topValue : thisValue);
				}
			}
		}
	}

	vector<bool> result(numberOfRadLiquid, false);
	for (int i = numberOfRadLiquid, j = reactorCap, k = criticalMass; i > 0; i--)
	{
		if (maxValue[i][j][k] > maxValue[i - 1][j][k])
		{
			result[i - 1] = true;
			j = j - volumes[i - 1];
			k = k - masses[i - 1];
		}
	}
	int sum = 0;
	for (int i = 0; i < result.size(); i++)
	{
		if (result[i])
		{
			sum += energies[i];
		}
	}
	return sum;
}


int main_裂变反应堆_背包() // main_裂变反应堆_背包
{
	int reactorCap = 100;//容量50 
	int numberOfRadLiquid = 5;//个数
	int criticalMass = 15;//临界质量

	int volumes[5] = { 50, 40, 30, 20, 10 };//体积
	int masses[5] = { 1, 2, 3, 9, 5 };//质量
	int energies[5] = { 300, 480, 270, 200, 180 };//能量

	int sum_energies = maxEnergyGenerate(reactorCap, numberOfRadLiquid, criticalMass, volumes, masses, energies);

	cout << sum_energies << endl;
	return 0;
}