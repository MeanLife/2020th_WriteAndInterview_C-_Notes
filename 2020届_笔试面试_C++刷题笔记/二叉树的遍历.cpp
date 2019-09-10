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
//static void leverTrace(BTreeNode * head)
//{
//	if (head == nullptr)
//	{
//		return;
//	}
//	queue<BTreeNode *> my_queue; // 利用先入队列先弹出的原理
//	while (nullptr != head)
//	{
//		cout << head->value << " ";
//		if (head->left != nullptr)
//		{
//			my_queue.push(head->left);
//		}
//		if (head->right != nullptr)
//		{
//			my_queue.push(head->right);
//		}
//
//		if (!my_queue.empty())
//		{
//			head = my_queue.front();
//			my_queue.pop();
//		}
//		else
//		{
//			head = nullptr;
//		}
//	}
//}


int main_二叉树的遍历(void) // main_二叉树的遍历
{
	vector<int> preOrder = { 1, 2, 4, 7, 3, 5, 6, 8 };
	vector<int> inOrder = { 4, 7, 2, 1, 5, 3, 8, 6 };
	BTreeNode *head = reConstructBy_pre_vin(preOrder, inOrder);

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