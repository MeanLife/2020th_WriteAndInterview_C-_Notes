/***************************************
【题目】：
某公司有N名员工，给定所有员工工资的清单，财务人员要按照特定的顺序排列员工的工资。
他按照工资的频次降序排列，即给定清单中所有频次较高的工资在频次较低的工资之前出现。
如果相同数量相同的员工有相同的工资，则将按照给定清单中该工资第一次出现的顺序排列。
写一个算法帮助财务人员排列员工工资的顺序。

输入：
1、num, 一个整数表示员工人数
2、salaries，员工工资列表
输出：
返回一个按照工资频次降序的正整数列表
约束条件
1<=num<=10^5
1<=salaries[i]<=10^9
0=<i<num

用例：10,[20,40,26,25,40,20,40,20,40,25]
输出：40 40 40 40 20 20 20 25 25 26
【思路】：
本题中需要统计工资的频次降序排序，当频次一致时应当根据第一次出现升序排序。
首先通过一个循环，建立出现 顺序–员工工资、员工–出现顺序、出现顺序–出现频次 的关系；
将 出现顺序–出现频次 排序。规则：出现频次不一致时降序排序，否则根据出现顺序升序排序
遍历排序后的出现顺序–出现频次，根据出现顺序获取对应的员工工资，添加到输出列表
***************************************/
#include<iostream>
#include<vector>
#include<map>
#include <algorithm>
using namespace std;

static bool compare(pair<int, int> a, pair<int, int> b)
{
	return a.first > b.first;
}

static void salaryfrequeny(int num, vector<int> &salaries)
{
	if (num <= 0)
	{
		return;
	}
	// 统计出现次数：myMap; // 记录出现的频次。。map_temp; // 记录出现的原次序
	map<int, int> myMap; // 记录出现的频次
	vector<int> map_temp; // 记录出现的原次序
	for (auto it : salaries)
	{
		if (myMap.count(it) == 0) // 第一次出现
		{
			myMap[it] = 1;
			map_temp.push_back(it);
		}
		else
		{
			myMap[it] += 1;
		}
	}
	cout << "myMap" << endl;
	for (auto it : myMap)
	{
		cout << it.first << " : " << it.second << endl;
	}
	cout << "map_temp" << endl;
	for (auto it : map_temp)
	{
		cout << it << endl;
	}
	
	vector<pair<int, int>> result;
	for (auto it : map_temp)
	{
		result.push_back(pair<int, int>(myMap[it], it));
		cout << result.back().first << " : " << result.back().second << endl;
	}
	sort(result.begin(), result.end(), compare);

	for (auto it : result)
	{
		while (it.first--)
		{
			cout << it.second << " ";
		}
	}
	cout << endl;
}

int main_工资排序()
{
	const int num = 10;
	vector<int> salaries = { 20, 30, 26, 25, 40, 20, 40, 20, 40, 25 };

	salaryfrequeny(num, salaries);

	return 0;
}



