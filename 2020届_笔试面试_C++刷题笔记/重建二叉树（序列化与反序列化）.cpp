#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

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

// 先序方式：反序列化
static BTreeNode *reconPreOrderString(vector<string> &values)
{ // 字符串类型
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
static BTreeNode *reconPreOrderString(vector<int> &values)
{ // int类型
	int value = values.front();
	values.erase(values.begin());
	if (value == -1)
	{
		return nullptr;
	}
	BTreeNode *head = new BTreeNode(value); // 先建立根节点
	head->left = reconPreOrderString(values); // 再建立左子树
	head->right = reconPreOrderString(values); // 再建立右子树
	return head;
}

int main_以反序列化方式重建二叉树(void)
{
	vector<string> data = { "0", "1", "3", "#", "#", "4", "#", "#", "2", "#", "#" };
	BTreeNode *head = nullptr;
	head = reconPreOrderString(data);
	preOrderRecur(head);

	cout << endl;
	cout << endl;

	vector<int> data1 = { 0, 1, 3, -1, -1, 4, -1, -1, 2, -1, -1 };
	BTreeNode *head1 = nullptr;
	head1 = reconPreOrderString(data1);
	preOrderRecur(head1);

	cout << "Write By JZQ!" << endl;
	//自动排版：ctrl+k+F
	return 0;
}