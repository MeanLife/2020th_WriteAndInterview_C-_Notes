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

下面程序思路：
有N个瓶子，给所有瓶子编个号（以N=5为例，那么就是1 2 3 4 5），将这5个数，进行组合，即：
先从5个瓶子中取5个，得到组合：
1  2  3  4  5
再从5个瓶子中取4个，得到组合：
1  2  3  4
1  2  3  5
1  2  4  5
1  3  4  5
2  3  4  5
再从5个瓶子中取3个，得到组合：
1  2  3
1  2  4
1  2  5
1  3  4
1  3  5
1  4  5
2  3  4
2  3  5
2  4  5
3  4  5
再从5个瓶子中取2个，得到组合：
1  2
1  3
1  4
1  5
2  3
2  4
2  5
3  4
3  5
4  5
再从5个瓶子中取1个，得到组合：
1
2
3
4
5
每一次得到组合后，遍历所有组合，找到符合条件的最大能量即可。
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

// 求排列组合算法: C(n, m): 从n个数中任选m个数组成一个新的数, 求有多少种组合, 分别是什么 
// 从v[]里任选m个元素组成一个组合, 与顺序无关
static vector<vector<int>> Cnm(vector<int> v, int m)
{
	if (v.size() < m)
	{
		return{};               // 找不到这样的组合
	}

	vector<vector<int>> ret;
	if (v.size() == m)          // v[]中元素全选
	{
		ret.push_back(v);       // 唯一的一个组合
		return ret;
	}
	if (m == 1)                // v[]中任选1个数
	{
		for (auto it : v)
		{
			ret.push_back(vector<int> {it}); // m种选择，每次选一个
		}
		return ret;
	}

	while (v.size() >= m)
	{
		int first = v.front();
		v.begin() = v.erase(v.begin());
		// 在剩下的v[1~]中任选m-1个数
		auto ret_temp = Cnm(v, m - 1);
		for (auto it : ret_temp)
		{
			it.begin() = it.insert(it.begin(), first);
			ret.push_back(it);
		}
	}
	return ret;
}

int find(int reactorCap, int numberOfRadLiquid, int criticalMass, int volumes[], int masses[], int energies[])
{
	int maxEnergies = 0;

	std::vector<int> v = {};//每个瓶子编号
	for (int i = 0; i < numberOfRadLiquid; i++)
		v.push_back(i + 1);

	cout << "每个瓶子编号:";
	for (auto it : v)
	{
		cout << it << "  "; // 1  2  3  4  5
	}
	cout << endl;

	for (int i = numberOfRadLiquid; i >= 1; i--)
	{
		auto res = Cnm(v, i); // C55  C54  C53  C52  C51
		print_2D_Array(res);

		for (auto it : res) // it代表所有组合中的一个组合。
		{
			int sum_volumes = 0;
			int sum_masses = 0;
			int sum_energies = 0;
			for (auto it2 : it)
			{ // 对于每一个组合，求出选这个组合的总和。
				sum_volumes += volumes[it2 - 1];
				sum_masses += masses[it2 - 1];
				sum_energies += energies[it2 - 1];
			}
			// 满足条件，且当前组合得出的sum_energies > maxEnergies，就更新maxEnergies
			if (sum_volumes <= reactorCap && sum_masses <= criticalMass && sum_energies > maxEnergies)
			{
				maxEnergies = sum_energies;
			}
		}
	}
	return maxEnergies;
}

int main_组合()
{
	int reactorCap = 100;//容量50 
	int numberOfRadLiquid = 5;//个数
	int criticalMass = 15;//临界质量

	int volumes[5] = { 50, 40, 30, 20, 10 };//体积
	int masses[5] = { 1, 2, 3, 9, 5 };//质量
	int energies[5] = { 300, 480, 270, 200, 180 };//能量

	int sum_energies = find(reactorCap, numberOfRadLiquid, criticalMass, volumes, masses, energies);

	cout << sum_energies << endl;
	return 0;
}