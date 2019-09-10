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
// 重建二叉树。
static BTreeNode* reConstructBy_pre_vin(vector<int> &pre, vector<int> &vin)
{
	if (pre.size() == 0 || vin.size() == 0 || pre.size() != vin.size())
	{
		cout << "输入的前序与中序不对，无法重建二叉树！" << endl;
		return nullptr;
	}

	BTreeNode *root = new BTreeNode(pre[0]); // 前序的第一个数定为根
	int len = pre.size();
	// 当只有一个数时，则直接返回根
	if (len == 1)
	{
		return root;
	}
	// 不止一个数时，找到中序中的根的位置
	int rootInorder = 0;
	for (; rootInorder < len; rootInorder++)
	{
		if (vin[rootInorder] == root->value)
		{
			break;// 此时的i值就是根在中序中的位置
		}
	}
	// 递归创建左子树
	if (rootInorder == 0) // 中序中只剩一个元素了，它是根
	{
		root->left = nullptr;
	}
	else
	{
		vector<int> newPre;
		vector<int> newVin;
		for (int i = 0; i < rootInorder; i++)
		{
			newPre.push_back(pre[i + 1]);
			newVin.push_back(vin[i]);
		}
		root->left = reConstructBy_pre_vin(newPre, newVin);
	}
	// 递归创建右子树
	if (rootInorder == len - 1) // 中序中只剩一个元素了，它是根
	{
		root->right = nullptr;
	}
	else
	{
		vector<int> newPre;
		vector<int> newVin;
		for (int i = rootInorder + 1; i < len; i++)
		{
			newPre.push_back(pre[i]);
			newVin.push_back(vin[i]);
		}
		root->right = reConstructBy_pre_vin(newPre, newVin);
	}
	return root;
}
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

	queue<BTreeNode *> my_queue;
	my_queue.push(head);
	while (!my_queue.empty())
	{
		int size = my_queue.size(); // 每一层的节点个数（非空节点）
		for (int i = 0; i < size; i++)
		{// 遍历并删除当前层所有节点，并保存下一层节点
			BTreeNode * cur = my_queue.front();
			my_queue.pop(); // 删除当前层节点
			cout << cur->value << " ";
			if (cur->left != nullptr)
			{
				my_queue.push(cur->left); // 保存下一层左节点
			}
			if (cur->right != nullptr)
			{
				my_queue.push(cur->right); // 保存下一层右节点
			}
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
	res += to_string(head->value) + " "; // 头
	res += serialByPre(head->left); // 左
	res += serialByPre(head->right); // 右
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
	BTreeNode *head = new BTreeNode(stoi(value)); // 头
	head->left = reconPreOrderString(values); // 左
	head->right = reconPreOrderString(values); // 右
	return head;
}
static BTreeNode * reconByPreString(string &preStr) 
{
	vector<string> values;
	SplitString(preStr, values, " "); // 以空格分割字符串
	return reconPreOrderString(values);
}

// 中序方式：序列化，中序无法反序列化
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

// 后序方式：序列化，后序无法反序列化
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

	queue<BTreeNode *> my_queue;
	my_queue.push(head);
	string res = "";
	while (!my_queue.empty())
	{
		int size = my_queue.size();
		for (int i = 0; i < size; i++)
		{
			BTreeNode * cur = my_queue.front();
			my_queue.pop();
			if (cur == nullptr) // 在序列化时，为空的节点，要写成“#”：一个标志
			{
				res += "# ";
			}
			else
			{
				res += to_string(cur->value) + " ";
				my_queue.push(cur->left);
				my_queue.push(cur->right);
			}
		}
	}
	return res;
}
//static string serialByLevel(BTreeNode *head) 
//{
//	if (head == nullptr) 
//	{
//		return "# ";
//	}
//	string res = "";
//	res += to_string(head->value) + " "; // 头
//	queue<BTreeNode *> my_queue;
//	while (head != nullptr)
//	{
//		// res += to_string(head->value) + " "; // 不能在这里加，因为这里的head是队列弹出的，已经加入过一遍了。
//		if (head->left != nullptr)
//		{
//			my_queue.push(head->left);
//		}
//		res += (head->left != nullptr ? to_string(head->left->value) : "#") + " ";
//		if (head->right != nullptr)
//		{
//			my_queue.push(head->right);
//		}
//		res += (head->right != nullptr ? to_string(head->right->value) : "#") + " ";
//
//		if (!my_queue.empty())
//		{
//			head = my_queue.front();
//			my_queue.pop();
//		}
//		else
//		{
//			break;
//		}
//	}
//	return res;
//}
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

int main_序列化与反序列化(void) // main_序列化与反序列化
{
	vector<int> preOrder = { 1, 2, 4, 7, 3, 5, 6, 8 };
	vector<int> inOrder = { 4, 7, 2, 1, 5, 3, 8, 6 };
	BTreeNode *head = reConstructBy_pre_vin(preOrder, inOrder);

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