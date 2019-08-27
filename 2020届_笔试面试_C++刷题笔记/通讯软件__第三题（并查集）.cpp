#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <map>
using namespace std;

/***************************************
【题目】：
在通讯软件中，在群里面转发消息可以使得一条消息扩散到很多人那里。假设已知有m个群，
其中一个人把一条消息发送到他自己所在的所有群里面，这些群里面的每个人又把消息在此转发到他所有的群里面，
请问所有群的人都转发过一次后，最后几个人收到该消息（包括发消息的人）？输出收到消息的人数（十进制整数，不需要加换行符）
输入描述：
发第一条消息的人名
群组个数m
群组1成员人名列表
群组2成员人名列表
...
群组m成员人名列表

人名全是英文字符串，包括英文字母和空格，最大长度不超过100字符
群组个数m是十进制数，最大不超过100.
群组成员人名列表包含1至多个人名，两个人名之间以逗号隔开。
输出描述：
以十进制输出最后能收到消息的人数
包括第一个发消息的人，也统计进去，重复接收到消息只统计一次
输入：
Jack
3
Jack,Tom,Anny,Lucy
Tom,Danny
Jack,Lily
输出：
6
【思路】：
并查集，将名字组映射成数字组，就可以做了。
***************************************/

// 打印二维数组vector<vector<int>> array
static void print_2D_Array(vector<vector<string>> array)
{
	for (unsigned i = 0; i < array.size(); ++i)
	{
		for (vector<string>::iterator it = array[i].begin(); it != array[i].end(); it++)
		{
			cout << *it << "  ";
		}
		cout << endl;
	}
	cout << endl;
}

// 分割字符串
static void SplitString(const string& s, vector<string>& v, const string& c)
{
	string::size_type pos1, pos2;
	pos2 = s.find(c);
	pos1 = 0;
	while (string::npos != pos2)
	{
		v.push_back(s.substr(pos1, pos2 - pos1));
		pos1 = pos2 + c.size();
		pos2 = s.find(c, pos1);
	}
	if (pos1 != s.length())
	{
		v.push_back(s.substr(pos1));
	}
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

int main_第三题_通讯软件(void)
{
	//输入：
	//	Jack
	//	3
	//	Jack,Tom,Anny,Lucy
	//	Tom,Danny
	//	Jack,Lily
	string Name = "";
	while (cin >> Name)
	{
		int M = 0;
		cin >> M;
		vector<string> temp(M);
		for (int i = 0; i < M; i++)
		{
			cin >> temp[i];
		}
		vector<vector<string>> names(M);
		for (int i = 0; i < M; i++)
		{
			SplitString(temp[i], names[i], ",");
		}
		print_2D_Array(names);

		map<string, int> mymap;
		int N = 1;
		for (auto it1 : names)
		{
			for (auto it2 : it1)
			{
				if (mymap.insert(pair<string, int>(it2, N)).second)
				{
					N++;
				}
			}
		}

		for (auto it : mymap)
		{
			cout << it.first << " : " << it.second << endl;
		}
		vector<vector<int>> names_map(M);
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < names[i].size(); j++)
			{
				names_map[i].push_back(mymap[names[i][j]]);
				cout << "names_map[" << i << "][" << j << "] = " << names_map[i][j] << endl;
			}
		}

		// 初始化 N 个独立子集合，初始化并查集
		vector<int> findSet(N + 1, 0);
		for (int i = 1; i <= N; i++)
		{
			findSet[i] = i; // 从0开始。0位置不使用。
		}
		// 链接x、y两个节点
		for (int i = 0; i < M; i++)
		{
			for (int j = 1; j < names[i].size(); j++)
			{
				join(findSet, names_map[i][0], names_map[i][j]); // 每合并一次，并查集findSet的子集就少一。
			}
		}
		// 找到小赛(1)在并查集中的代表
		int k = find(findSet, mymap[Name]);
		// 计数：计算以k为代表的元素个数
		int count = 0;
		for (int i = 1; i <= N; i++)
		{
			if (k == find(findSet, i))
			{
				count++;
			}
		}

		cout << count << endl; // 找到与Name有关系的个数，
	}

	return 0;
}