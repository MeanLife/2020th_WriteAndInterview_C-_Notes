#include <iostream>
#include <string>
#include <cmath>
#include <queue>
#include <stack>
using namespace std;

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
// 递归：先序
static void preOrderRecur(BTreeNode *head)
{
	if (head == nullptr) {
		return;
	}
	cout << head->value << " ";
	preOrderRecur(head->left);
	preOrderRecur(head->right);
}
// 非递归：先序
static void preOrderUnRecur(BTreeNode *head) 
{
	if (head == nullptr)
	{
		return;
	}
	stack<BTreeNode *> my_stack;
	while (nullptr != head)
	{
		cout << head->value << " "; // 先打印根节点
		if (head->right != nullptr)
		{
			my_stack.push(head->right);
		}
		if (head->left != nullptr)
		{
			my_stack.push(head->left);
		}

		if (!my_stack.empty())
		{
			head = my_stack.top();
			my_stack.pop();
		}
		else
		{
			head = nullptr;
		}
	}
}
// 递归：中序
static void inOrderRecur(BTreeNode *head) 
{
	if (head == nullptr) {
		return;
	}
	inOrderRecur(head->left);
	cout << head->value << " ";
	inOrderRecur(head->right);
}
// 非递归：中序
static void inOrderUnRecur(BTreeNode *head)
{
	if (head == nullptr)
	{
		return;
	}
	stack<BTreeNode *> my_stack;
	while (head != nullptr || !my_stack.empty())
	{
		if (head != nullptr) // 当前节点不为空，当前节点入栈，并继续向左走
		{
			my_stack.push(head);
			head = head->left;
		}
		else // 当前节点为空，从栈顶弹出节点为当前节，并向右走
		{
			head = my_stack.top();
			my_stack.pop();
			cout << head->value << " ";
			head = head->right;
		}
	}
}
// 递归：后序
static void posOrderRecur(BTreeNode *head)
{
	if (head == nullptr) {
		return;
	}
	posOrderRecur(head->left);
	posOrderRecur(head->right);
	cout << head->value << " ";
}
// 非递归：后序
static void posOrderUnRecur(BTreeNode *head) 
{
	if (head == nullptr) {
		return;
	}
	stack<BTreeNode *> my_stack;
	stack<BTreeNode *> temp;
	while (nullptr != head) // 其实是先序，只不过左右反着来
	{ // 根右左->左右根。
		temp.push(head);
		if (head->left != nullptr)
		{
			my_stack.push(head->left);
		}
		if (head->right != nullptr)
		{
			my_stack.push(head->right);
		}

		if (!my_stack.empty())
		{
			head = my_stack.top();
			my_stack.pop();
		}
		else
		{
			head = nullptr;
		}
	}
	while (!temp.empty())
	{
		head = temp.top();
		temp.pop();
		cout << head->value << " ";
	}
}
// 非递归：层次
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


int main200545411551154514(void)
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

	cout << "递归—先序：";
	preOrderRecur(head);
	cout << endl;
	cout << "非递归先序：";
	preOrderUnRecur(head);
	cout << endl;
	cout << endl;

	cout << "递归—中序：";
	inOrderRecur(head);
	cout << endl;
	cout << "非递归中序：";
	inOrderUnRecur(head);
	cout << endl;
	cout << endl;

	cout << "递归—后序：";
	posOrderRecur(head);
	cout << endl;
	cout << "非递归后序：";
	posOrderUnRecur(head);
	cout << endl;
	cout << endl;

	cout << "非递归层次：";
	leverTrace(head);
	cout << endl;
	cout << endl;

	cout<<"Write By JZQ!"<<endl;
	//自动排版：ctrl+k+F
	return 0;
}