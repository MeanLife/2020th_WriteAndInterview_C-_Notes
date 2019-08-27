#include <iostream>
#include <vector>
#include <set>
using namespace std;

/*
看博客《https://blog.csdn.net/qq_41593380/article/details/81146850》
并查集，顾名思义，一个实现了合并和查询集合方法的数据结构。最常见的方式是用数组来实现。
并查集的最终目的是将输入的节点按照其连接关系，分割成一个或多个子集。
一个简单的应用就是判断无向图的连通分量个数，或者判断无向图中任何两个顶点是否连通。
例如，节点 ① ② ③ ④，已知 ① 与 ② 相连， ② 与 ④ 相连，经过并查集操作，
应该形成两个集合，其中一个集合是 {① ② ④}，另一个是 {③}。

大学的同学来自全国各地，对于远离家乡步入陌生大学校园的大一新生来说，碰到老乡是多么激动的一件事，
于是大家都热衷于问身边的同学是否与自己同乡，来自新疆的小赛尤其热衷。但是大家都不告诉小赛他们来自哪里，
只是说与谁同乡，从所给的信息中，你能告诉小赛有多少人确定是她的同乡吗？

输入
每个测试实例首先包括2个整数，N（1 <= N <= 1000），M(0 <= M <= N*(N-1)/2)，代表现有N个人（用1~N编号）和M组关系；
在接下来的M行里，每行包括3个整数，a，b, c，如果c为1，则代表a跟b是同乡；如果c为0，则代表a跟b不是同乡；
当N = 0，M = 0输入结束；
已知1表示小赛本人。

输入样例：
3 1
2 3 1

5 4
1 2 1
3 4 0
2 5 1
3 2 1
输出样例：
0
3
【思路】：其实就是找含有1的并查集
*/

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

int main112653612456821645824562814658845696458(void)
{
	int N, M;
	while (cin >> N >> M)
	{
		if (N == 0 && M == 0) // 当N = 0，M = 0输入结束；
		{
			break;
		}
		// 初始化 N 个独立子集合，初始化并查集
		vector<int> findSet(N + 1, 0);
		for (int i = 1; i <= N; i++)
		{
			findSet[i] = i; // 从0开始。0位置不使用。
		}
		// 链接x、y两个节点
		int a, b, c;
		while (M--)
		{
			cin >> a >> b >> c;
			if (c == 1) // 本题，要求c = 1时，链接a,b。
			{
				join(findSet, a, b); // 每合并一次，并查集findSet的子集就少一。
			}
		}
		// 找到小赛(1)在并查集中的代表
		int k = find(findSet, 1); 
		// 计数：计算以k为代表的元素个数
		int count = 0;
		for (int i = 1; i <= N; i++)
		{
			if (k == find(findSet, i))
			{
				count++;
			}
		}

		cout << count - 1 << endl; // 找到小赛(1)的老乡个数，要把自己在并查集中的计数减去。


		//set<int> r;
		//// 计算根节点个数，即计算并查集中有多少个子集
		//for (int i = 1; i <= N; i++) 
		//{
		//	r.insert(find(findSet, findSet[i]));
		//}

		//return r.size();
	}

	return 0;
}