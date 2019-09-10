#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;

	TreeNode(const int val)
	{
		this->val = val;
		left = nullptr;
		right = nullptr;
	}
};

static void preOrderPrintf(TreeNode *root)
{
	if (root == nullptr)
	{
		return;
	}
	cout << root->val << "  ";
	preOrderPrintf(root->left);
	preOrderPrintf(root->right);
}
static void inOrderPrintf(TreeNode *root)
{
	if (root == nullptr)
	{
		return;
	}
	inOrderPrintf(root->left);
	cout << root->val << "  ";
	inOrderPrintf(root->right);
}
static void posOrderPrintf(TreeNode *root)
{
	if (root == nullptr)
	{
		return;
	}
	posOrderPrintf(root->left);
	posOrderPrintf(root->right);
	cout << root->val << "  ";
}


/***************************************
题目描述
输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，
则重建二叉树并返回。
【思路】：
在前序遍历的序列中，根结点后面的3个数字就是3个左子树结点的值，再后面的所有数字都是右子树结点的值。
这样我们就在前序遍历和中序遍历两个序列中，分别找到了左右子树对应的子序列。
既然我们已经分别找到了左、右子树的前序遍历序列和中序遍历序列，
我们可以用同样的方法分别去构建左右子树。也就是说，接下来的事情可以用递归的方法去完成。
***************************************/
static TreeNode* reConstructBy_pre_vin(vector<int> &pre, vector<int> &vin) 
{
	if (pre.size() == 0 || vin.size() == 0 || pre.size() != vin.size())
	{
		cout << "输入的前序与中序不对，无法重建二叉树！" << endl;
		return nullptr;
	}

	TreeNode *root = new TreeNode(pre[0]); // 前序的第一个数定为根
	int len = pre.size();
	// 当只有一个数时，则直接返回根
	if (len == 1)
	{
		return root;
	}
	// 不止一个数时，找到中序中的根的位置
	int rootInorder = 0;
	for ( ; rootInorder < len; rootInorder++)
	{
		if (vin[rootInorder] == root->val)
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
// 以后序和中序重建
static TreeNode* reConstructBy_pos_vin(vector<int> &pos, vector<int> &vin)
{
	if (pos.size() == 0 || vin.size() == 0 || pos.size() != vin.size())
	{
		cout << "输入的前序与中序不对，无法重建二叉树！" << endl;
		return nullptr;
	}

	int len = pos.size();
	TreeNode *root = new TreeNode(pos[len - 1]); // 后序的最后一个数定为根
	// 当只有一个数时，则直接返回根
	if (len == 1)
	{
		return root;
	}
	// 不止一个数时，找到中序中的根的位置
	int rootInorder = 0;
	for (; rootInorder < len; rootInorder++)
	{
		if (vin[rootInorder] == root->val)
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
		vector<int> newPos;
		vector<int> newVin;
		for (int i = 0; i < rootInorder; i++)
		{
			newPos.push_back(pos[i]);
			newVin.push_back(vin[i]);
		}
		root->left = reConstructBy_pos_vin(newPos, newVin);
	}
	// 递归创建右子树
	if (rootInorder == len - 1) // 中序中只剩一个元素了，它是根
	{
		root->right = nullptr;
	}
	else
	{
		vector<int> newPos;
		vector<int> newVin;
		for (int i = rootInorder + 1; i < len; i++)
		{
			newPos.push_back(pos[i - 1]);
			newVin.push_back(vin[i]);
		}
		root->right = reConstructBy_pos_vin(newPos, newVin);
	}
	return root;
}


int main_重建二叉树（前序中序的值）(void) // main_重建二叉树（前序中序的值）
{
	vector<int> preOrder = { 1, 2, 4, 7, 3, 5, 6, 8 };
	vector<int> inOrder = { 4, 7, 2, 1, 5, 3, 8, 6 };
	vector<int> posOrder = { 7, 4, 2, 5, 8, 6, 3, 1 };

	//TreeNode *root = reConstructBy_pre_vin(preOrder, inOrder);
	TreeNode *root = reConstructBy_pos_vin(posOrder, inOrder);

	cout << "重建后前序：" << endl;
	preOrderPrintf(root);
	cout << endl;

	cout << "重建后中序：" << endl;
	inOrderPrintf(root);
	cout << endl;

	cout << "重建后后序：" << endl;
	posOrderPrintf(root);
	cout << endl;

	cout << "Write By JZQ!" << endl;
	//自动排版：ctrl+k+F
	return 0;
}