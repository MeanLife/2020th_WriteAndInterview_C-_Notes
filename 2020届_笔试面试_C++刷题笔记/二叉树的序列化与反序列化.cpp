#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

// 分割字符串
static void SplitString(const string& source, vector<string>& des, const string& key)
{
	string::size_type pos1, pos2;
	pos2 = source.find(key);
	pos1 = 0;
	while (string::npos != pos2)
	{
		des.push_back(source.substr(pos1, pos2 - pos1));
		pos1 = pos2 + key.size();
		pos2 = source.find(key, pos1);
	}
	if (pos1 != source.length())
	{
		des.push_back(source.substr(pos1));
	}
}
// 二叉树的节点
static struct BTreeNode
{
	int value;
	BTreeNode *left;
	BTreeNode *right;

	BTreeNode(int data)
	{
		this->value = data;
		this->left = nullptr;
		this->right = nullptr;
	}
};
// 递归：先序遍历
static void preOrderRecur(BTreeNode *head)
{
	if (head == nullptr) {
		return;
	}
	cout << head->value << " ";
	preOrderRecur(head->left);
	preOrderRecur(head->right);
}
// 递归：中序遍历
static void inOrderRecur(BTreeNode *head)
{
	if (head == nullptr) {
		return;
	}
	inOrderRecur(head->left);
	cout << head->value << " ";
	inOrderRecur(head->right);
}
// 递归：后序遍历
static void posOrderRecur(BTreeNode *head)
{
	if (head == nullptr) {
		return;
	}
	posOrderRecur(head->left);
	posOrderRecur(head->right);
	cout << head->value << " ";
}
// 非递归：层次遍历
static void leverTrace(BTreeNode * head)
{
	if (head == nullptr)
	{
		return;
	}
	queue<BTreeNode *> my_queue; // 利用先入队列先弹出的原理
	while (nullptr != head)
	{
		cout << head->value << " ";
		if (head->left != nullptr)
		{
			my_queue.push(head->left);
		}
		if (head->right != nullptr)
		{
			my_queue.push(head->right);
		}

		if (!my_queue.empty())
		{
			head = my_queue.front();
			my_queue.pop();
		}
		else
		{
			head = nullptr;
		}
	}
}

// 先序方式：序列化
static string serialByPre(BTreeNode *head)
{
	if (head == nullptr) 
	{
		return "# ";
	}
	string res = "";
	res += to_string(head->value) + " ";
	res += serialByPre(head->left);
	res += serialByPre(head->right);
	return res;
}
// 先序方式：反序列化
static BTreeNode *reconPreOrderString(vector<string> &values)
{
	string value = values.front();
	values.erase(values.begin());
	if (value == "#")
	{
		return nullptr;
	}
	BTreeNode *head = new BTreeNode(stoi(value));
	head->left = reconPreOrderString(values);
	head->right = reconPreOrderString(values);
	return head;
}
static BTreeNode * reconByPreString(string &preStr) 
{
	vector<string> values;
	SplitString(preStr, values, " "); // 以空格分割字符串
	return reconPreOrderString(values);
}

// 中序方式：序列化
static string serialByPosOrder(BTreeNode *head)
{
	if (head == nullptr)
	{
		return "# ";
	}
	string res = "";
	res += serialByPosOrder(head->left);
	res += serialByPosOrder(head->right);
	res += to_string(head->value) + " ";
	return res;
}

// 后序方式：序列化
static string serialByInOrder(BTreeNode *head)
{
	if (head == nullptr)
	{
		return "# ";
	}
	string res = "";
	res += serialByInOrder(head->left);
	res += to_string(head->value) + " ";
	res += serialByInOrder(head->right);
	return res;
}

// 层次方式：序列化
static string serialByLevel(BTreeNode *head) 
{
	if (head == nullptr) 
	{
		return "# ";
	}
	string res = "";
	res += to_string(head->value) + " ";
	queue<BTreeNode *> my_queue;
	while (head != nullptr)
	{
		// res += to_string(head->value) + " "; // 不能在这里加，因为这里的head是队列弹出的，已经加入过一遍了。
		if (head->left != nullptr)
		{
			my_queue.push(head->left);
		}
		res += (head->left != nullptr ? to_string(head->left->value) : "#") + " ";
		if (head->right != nullptr)
		{
			my_queue.push(head->right);
		}
		res += (head->right != nullptr ? to_string(head->right->value) : "#") + " ";

		if (!my_queue.empty())
		{
			head = my_queue.front();
			my_queue.pop();
		}
		else
		{
			break;
		}
	}
	return res;
}
// 层次方式：反序列化
static BTreeNode * reconByLevelString(string &leverStr)
{
	vector<string> values;
	SplitString(leverStr, values, " "); // 以空格分割字符串

	string value = values.front();
	values.erase(values.begin());
	if (value == "#")
	{
		return nullptr;
	}
	BTreeNode *head = new BTreeNode(stoi(value)); // 以value建立头结点。
	BTreeNode *cur = head;

	// 入队列和反序列化一起做：
	queue<BTreeNode *> my_queue;
	while (!values.empty())
	{
		if (values.front() != "#") // 左边
		{
			my_queue.push(new BTreeNode(stoi(values.front())));
		}
		cur->left = values.front() != "#" ? my_queue.back() : nullptr;
		values.erase(values.begin());

		if (values.front() != "#") // 右边
		{
			my_queue.push(new BTreeNode(stoi(values.front())));
		}
		cur->right = values.front() != "#" ? my_queue.back() : nullptr;
		values.erase(values.begin());
		
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

int main_序列化与反序列化(void)
{
	BTreeNode *head = new BTreeNode(5);
	head->left = new BTreeNode(3);
	head->right = new BTreeNode(8);
	head->left->left = new BTreeNode(2);
	head->left->right = new BTreeNode(4);
	head->left->left->left = new BTreeNode(1);
	head->right->left = new BTreeNode(7);
	head->right->left->left = new BTreeNode(6);
	head->right->right = new BTreeNode(10);
	head->right->right->left = new BTreeNode(9);
	head->right->right->right = new BTreeNode(11);

	cout << "先序方式：序列化：";
	string preStr = serialByPre(head);
	cout << preStr << endl;

	cout << "先序方式：反序列化后，";
	cout << "递归—先序遍历：";
	BTreeNode * head2 = reconByPreString(preStr);
	preOrderRecur(head2);
	cout << endl;
	cout << endl;
	

	cout << "中序方式：序列化：";
	string inOrderStr = serialByInOrder(head);
	cout << inOrderStr << endl;

	cout << "递归—中序遍历(中序不能反序列化)：";
	inOrderRecur(head);
	cout << endl;
	cout << endl;


	cout << "后序方式：序列化：";
	string posOrderStr = serialByPosOrder(head);
	cout << posOrderStr << endl;

	cout << "递归—中序遍历(后序不能反序列化)：";
	posOrderRecur(head);
	cout << endl;
	cout << endl;


	cout << "层次方式：序列化：";
	string leverStr = serialByLevel(head);
	cout << leverStr << endl;

	cout << "层次方式：反序列化后，";
	cout << "非递归层次遍历：";
	BTreeNode * head4 = reconByLevelString(leverStr);
	leverTrace(head4);
	cout << endl;
	cout << endl;

	cout<<"Write By JZQ!"<<endl;
	//自动排版：ctrl+k+F
	return 0;
}