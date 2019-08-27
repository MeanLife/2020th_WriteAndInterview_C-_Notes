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
class Solution {
public:
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		TreeNode *root = new TreeNode(pre[0]); // 前序的第一个数定为根
		int len = pre.size();
		// 当只有一个数时，则直接返回根
		if (len == 1)
		{
			return root;
		}
		// 不止一个数时
		// 找到中序中的根的位置
		int i = 0;
		for ( ; i < len; i++)
		{
			if (vin[i] == root->val)
			{
				break; // 此时的i值就是根在中序中的位置
			}
		}
		// 递归创建左子树
		if (i == 0)
		{
			root->left = nullptr; // 递归结束
		}
		else
		{
			vector<int> newpre;
			vector<int> newvin;
			for (int j = 0; j < i; j++)
			{
				newpre.push_back(pre[j + 1]);
				newvin.push_back(vin[j]);
			}
			root->left = reConstructBinaryTree(newpre, newvin);
		}
		// 递归创建右子树
		if (i == len - 1)
		{
			root->right = nullptr;
		}
		else
		{
			vector<int> newpre;
			vector<int> newvin;
			for (int j = i + 1; j < len; j++)
			{
				newpre.push_back(pre[j]);
				newvin.push_back(vin[j]);
			}
			root->right = reConstructBinaryTree(newpre, newvin);
		}
		return root;
	}
};


int main_重建二叉树（前序中序的值）(void)
{
	vector<int> preOrder = { 1, 2, 4, 7, 3, 5, 6, 8 };
	vector<int> inOrder = { 4, 7, 2, 1, 5, 3, 8, 6 };

	Solution result;
	TreeNode *root = result.reConstructBinaryTree(preOrder, inOrder);

	preOrderPrintf(root);

	cout << "Write By JZQ!" << endl;
	//自动排版：ctrl+k+F
	return 0;
}