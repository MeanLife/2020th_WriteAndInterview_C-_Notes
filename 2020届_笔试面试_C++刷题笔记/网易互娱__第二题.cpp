#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

/***************************************
【题目】：
一棵树，有n个节点，每个节点由三个域（权值、左、右），若上一层的节点权值之和比下一层的检点权值之和严格小，那么就是一颗递增树。
输入描述：
第一个数N：有N个样例
第二个数n：有n个节点
后面n行：代表节点，第k行代表编号为k的节点，分别代表权值、左孩子的编号、右孩子的编号。
输出描述：
YES或者NO：是否是递增树
输入：
1
8
2 -1 -1
1  5  3
4 -1  6
2 -1 -1
3  0  2
2  4  7
7 -1 -1
2 -1 -1
输出：
YES
【思路】：
1、找到根节点-》序列化-》反序列化(建树)-》统计每一层节点的权值。
***************************************/
// 二叉树的节点
static struct BTreeNode
{
	int num;
	int value;
	BTreeNode *left;
	BTreeNode *right;

	BTreeNode(int num, int value)
	{
		this->num = num;
		this->value = value;
		this->left = nullptr;
		this->right = nullptr;
	}
};
//找到根节点
static int getHeadNum(vector<int> &Left, vector<int> &Right)
{
	for (int i = 0; i < Left.size(); i++)
	{
		if (find(Left.begin(), Left.end(), i) == Left.end() && 
			find(Right.begin(), Right.end(), i) == Right.end())
		{
			return i;
		}
	}
}
//序列化
static vector<string> seriease(int headNum, vector<int> &Value, vector<int> &Left, vector<int> &Right)
{
	vector<string> result;
	queue<int> my_queue;
	while (true)
	{
		if (headNum == -1)
		{
			result.push_back("#");
		}
		else
		{
			result.push_back(to_string(headNum));
			my_queue.push(Left[headNum]);
			my_queue.push(Right[headNum]);
		}

		if (!my_queue.empty())
		{
			headNum = my_queue.front();
			my_queue.pop();
		}
		else
		{
			break;
		}
	}
	return result;
}
//反序列化(建树)
static BTreeNode * reconByLevelString(vector<string> &nums, vector<int> &Value)
{
	string num = nums.front();
	nums.erase(nums.begin());
	if (num == "#")
	{
		return nullptr;
	}
	BTreeNode *head = new BTreeNode(stoi(num), Value[stoi(num)]); // 建立头结点。
	BTreeNode *cur = head;

	// 入队列和反序列化一起做：
	queue<BTreeNode *> my_queue;
	while (!nums.empty())
	{
		if (nums.front() != "#") // 左边
		{
			my_queue.push(new BTreeNode(stoi(nums.front()), Value[stoi(nums.front())]));
		}
		cur->left = nums.front() != "#" ? my_queue.back() : nullptr;
		nums.erase(nums.begin());

		if (nums.front() != "#") // 右边
		{
			my_queue.push(new BTreeNode(stoi(nums.front()), Value[stoi(nums.front())]));
		}
		cur->right = nums.front() != "#" ? my_queue.back() : nullptr;
		nums.erase(nums.begin());

		if (!my_queue.empty())
		{
			cur = my_queue.front();
			my_queue.pop();
		}
		else
		{
			break;
		}
	}
	return head;
}
//统计每一层节点的权值
static vector<int> isIncrease(BTreeNode * head, int n)
{
	vector<int> res;
	queue<BTreeNode *> my_queue;
	my_queue.push(head);
	while (!my_queue.empty())
	{
		int sum = 0;
		int size = my_queue.size();
		for (int i = 0; i < size; i++) // 每次循环保存下一层所有节点。
		{
			BTreeNode * node = my_queue.front();
			my_queue.pop();
			sum += node->value;
			if (node->left != nullptr)
			{
				my_queue.push(node->left);
			}
			if (node->right != nullptr)
			{
				my_queue.push(node->right);
			}
		}
		res.push_back(sum);
	}
	return res;
}

int 网易互娱__第二题(void) // 网易互娱__第二题
{
	int N;
	while (cin >> N)
	{
		vector<bool> result(N, false);
		for (int i = 0; i < N; i++)
		{
			int n;
			cin >> n; // 节点数
			vector<int> Value(n, 0);
			vector<int> Left(n, -1);
			vector<int> Right(n, -1);
			for (int j = 0; j < n; j++)
			{
				cin >> Value[j];
				cin >> Left[j];
				cin >> Right[j];
			}
			//建树
			int headNum = getHeadNum(Left, Right);
			vector<string> res = seriease(headNum, Value, Left, Right);
			BTreeNode * head = reconByLevelString(res, Value);
			//判断
			vector<int> result1 = isIncrease(head, n);
			vector<int> result2(result1);
			sort(result2.begin(), result2.end());
			result[i] = (result1 == result2 ? true : false);
		}
		for (auto it : result)
		{
			cout << (it == true ? "YES" : "NO") << endl;
		}
	}
	return 0;
}