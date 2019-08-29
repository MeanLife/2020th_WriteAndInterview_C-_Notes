#include <iostream>
#include <vector>
#include <set>
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

static int find(vector<int>& findSet, int x)
{
	return findSet[x] == x ? x : find(findSet, findSet[x]);
}

static void join(vector<int>& findSet, int x, int y)
{
	int root1 = find(findSet, x);
	int root2 = find(findSet, y);
	if (root1 != root2)
	{
		findSet[root1] = root2;
	}
}

static void getCount(vector<pair<int, int>> &U_V_map, const int N, const int M, const int K)
{
	vector<int> findSet(N + 1, 0);
	for (int i = 1; i <= N; i++)
	{
		findSet[i] = i; // 从0开始。0位置不使用。
	}

	vector<vector<int>> result_temp(M + 1);
	for (int i = 0; i < U_V_map.size(); i++)
	{
		result_temp[U_V_map[i].second].push_back(U_V_map[i].first);
	}
	cout << endl;
	print_2D_Array(result_temp);
	// 当两个人语言相通，就连接起来
	for (int i = 0; i < result_temp.size(); i++)
	{
		if (result_temp[i].size() > 1)
		{
			for (int j = 0; j < result_temp[i].size() - 1; j++)
			{
				join(findSet, result_temp[i][j], result_temp[i][j + 1]); // 每合并一次，并查集findSet的子集就少一。
			}
		}
	}
	set<int> result;
	// 计算根节点个数，即计算并查集中有多少个子集
	for (int i = 1; i <= N; i++)
	{
		result.insert(find(findSet, findSet[i]));
	}

	cout << result.size() - 1 << endl;
}

int main_2065161581850025(void)
{
	int N, M, K;
	while (cin >> N >> M >> K)
	{
		vector<pair<int, int>> U_V_map;
		for (int i = 0; i < K; i++)
		{
			int u, v;
			cin >> u >> v;
			U_V_map.push_back(pair<int, int>(u, v));
		}

		getCount(U_V_map, N, M, K);
	}
	return 0;
}