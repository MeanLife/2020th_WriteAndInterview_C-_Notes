#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

static bool compare(pair<long long, int> a, pair<long long, int> b)
{
	return a.first < b.first;
}

int main__111112315(void)
{
	int N = 0;
	while (cin >> N)
	{
		if (N <= 0)
		{
			cout << "0" << endl;
			return 0;
		}

		vector<pair<long long, int>> Hi(N);
		for (int i = 0; i < N; i++)
		{
			long long temp;
			cin >> temp;
			Hi[i] = pair<long long, int>(temp, i + 1);
		}

		sort(Hi.begin(), Hi.end(), compare);
		//cout << endl;
		//for (auto it : Hi) // 测试
		//{
		//	cout << it.first << ":" << it.second << endl;
		//}

		int count = 1;
		vector<int> result;
		result.push_back(Hi[0].second);
		for (auto it1 : Hi)
		{
			bool flag = true;
			for (auto it2 : result)
			{
				if (abs(it1.second - it2) == 0) // 第一个编号
				{
					flag = false; // 改变了。
					break;
				}
				else if (abs(it1.second - it2) == 1) // 表示编号能连续
				{
					result.push_back(it1.second);
					flag = false; // 改变了。
					break;
				}
			}
			if (flag == true && it1 != Hi.back()) // 未改变，在result里面没有找到连续编号，分组中断
			{
				if (result.size() > 3)
				{
					count += result.size() - 3;
				}
				result.clear();
				result.push_back(it1.second);
				count++;
			}
		}
		//cout << "count = " << count << endl;
		cout << count << endl;
	}
	return 0;
}