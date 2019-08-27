#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static bool compare(pair<long long, int> a, pair<long long, int> b)
{
	return a.first > b.first;
}

// 递归查找x的根节点，findSet是并查集
static int find(vector<int>& findSet, int x)
{
	return findSet[x] == x ? x : find(findSet, findSet[x]);
}

// 两个点连通但根节点却不同，需要进行连接
static void join(vector<int>& findSet, int x, int y)
{
	int root1 = find(findSet, x);
	int root2 = find(findSet, y);
	if (root1 != root2)
	{
		findSet[root1] = root2;
	}
}

int main_2_1(void)
{
	int N, M;
	while (cin >> N >> M)
	{
		if (N <= 0 && M <= 0) // 当N = 0，M = 0输入结束；
		{
			cout << "0" << endl;
			cout << "0" << endl;
			return 0;
		}
		// 初始化 N 个独立子集合，初始化并查集
		const int len = 2 * N;
		vector<int> findSet(len + 1, 0);
		for (int i = 1; i <= len; i++)
		{
			findSet[i] = i; // 从1开始。0位置不使用。
		}
		// 链接x、y两个节点
		int a, b;
		vector<int> myarr;
		while (M--)
		{
			cin >> a >> b;
			myarr.push_back(a);
			myarr.push_back(b);
			join(findSet, a, b); // 每合并一次，并查集findSet的子集就少一。
		}

		int count_root = 0;
		// 计算根节点个数，即计算并查集中有多少个子集
		for (int i = 1; i <= N; i++) 
		{
			if (count(myarr.begin(), myarr.end(), i) == 0)
			{
				continue;
			}
			count_root++;
		}
		cout << count_root << endl;

		vector<pair<int,int>> temp;
		for (int i = 1; i < len + 1; i++)
		{
			if (count(myarr.begin(), myarr.end(), i) == 0)
			{
				continue;
			}
			temp.push_back(pair<int, int>(count(myarr.begin(), myarr.end(), i), i));
		}
		sort(temp.begin(), temp.end(), compare);
		vector<int> result;
		for (int i = 0; i < count_root; i++)
		{
			result.push_back(temp[i].second);
		}
		sort(result.begin(), result.end());
		for (auto it : result)
		{
			cout << it << " ";
		}
		cout << endl;
	}
	return 0;
}