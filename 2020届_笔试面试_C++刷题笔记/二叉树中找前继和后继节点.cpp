#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;
/*
题目：在二叉树中找到一个节点的后继节点。
 *  该结构比普通二叉树节点结构多了一个指向父节点的parent指针。
	假设有一棵BTreeNode *类型的节点组成的二叉树，树中每个节点的parent指针
	都正确地指向自己的父节点，头节点的parent指向nullptr。只给一个在
	二叉树中的某个节点 node，请实现返回node的后继节点的函数。

	后继节点：在二叉树的中序遍历的序列中，node的下一个节点叫作node的后继节点。
	前继节点：在二叉树的中序遍历的序列中，node的上一个节点叫作node的前继节点。
思路：
	方法一：利用node结点的parent指针，找到头结点，然后利用中序遍历，找到node结点，然后找到它的下一个结点
	方法二：
找后继结点，分类讨论右孩子:
	1->若节点X有右子树，那它的后继结点就是它的右子树中最左的结点（若它的右子树没有左子树，那就是右子树本身）
	2->因为中序是：左、根、右，所以，X节点没有右子树时，X节点是它所在左子树中的最后一个输出的节点，
		则X的后继节点应在该左子树的根节点。所以：向上循环遍历到该节点所在左子树的根。

找前继节点，分类讨论左孩子:
	1->若节点X有左子树，那它的前继结点就是它的左子树中最右的结点（若它的左子树没有右子树，那就是左子树本身）
	2->因为中序是：左、根、右，所以，X节点没有左子树时，X节点是它所在右子树中的最先一个输出的节点，
		则X的前继节点应在该右子树的根节点。所以：向上循环遍历到该节点所在右子树的根。
*/
static struct BTreeNode
{
	int value;
	BTreeNode *left;
	BTreeNode *right;
	BTreeNode *parent;

	BTreeNode(int data)
	{
		this->value = data;
		this->left = nullptr;
		this->right = nullptr;
		this->parent = nullptr;
	}
};

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

// 右节点不为空，则找右子树最左节点
static BTreeNode * getLeftMost(BTreeNode * node) 
{
	while (node->left != nullptr) 
	{
		node = node->left;
	}
	return node;
}
// 左节点不为空，则找左子树最右节点
static BTreeNode * getRightMost(BTreeNode * node)
{
	while (node->right != nullptr)
	{
		node = node->right;
	}
	return node;
}

// 找后继节点
static BTreeNode * getSuccessorNode(BTreeNode * node) 
{
	if (node == nullptr) 
	{
		return node;
	}
	if (node->right != nullptr) 
	{
		return getLeftMost(node->right);
	}
	else // 右节点为空
	{
		BTreeNode * parent = node->parent;
		while (parent != nullptr && parent->left != node) 
		{ // 向上循环遍历到该节点所在左子树的根。
			node = parent;
			parent = node->parent;
		}
		return parent; // parent是根。
	}
}
// 找前继节点
static BTreeNode * getPreNode(BTreeNode * node)
{
	if (node == nullptr)
	{
		return node;
	}
	if (node->left != nullptr)
	{
		return getRightMost(node->left);
	}
	else // 左节点为空
	{
		BTreeNode * parent = node->parent;
		while (parent != nullptr && parent->right != node)
		{ // 向上循环遍历到该节点所在右子树的根。
			node = parent;
			parent = node->parent;
		}
		return parent; // parent是根。
	}
}


int main_二叉树中找前继和后继节点(void) // main_二叉树中找前继和后继节点
{
	BTreeNode * head = new BTreeNode(6);
	head->parent = nullptr;
	head->left = new BTreeNode(3);
	head->left->parent = head;
	head->left->left = new BTreeNode(1);
	head->left->left->parent = head->left;
	head->left->left->right = new BTreeNode(2);
	head->left->left->right->parent = head->left->left;
	head->left->right = new BTreeNode(4);
	head->left->right->parent = head->left;
	head->left->right->right = new BTreeNode(5);
	head->left->right->right->parent = head->left->right;
	head->right = new BTreeNode(9);
	head->right->parent = head;
	head->right->left = new BTreeNode(8);
	head->right->left->parent = head->right;
	head->right->left->left = new BTreeNode(7);
	head->right->left->left->parent = head->right->left;
	head->right->right = new BTreeNode(10);
	head->right->right->parent = head->right;

	cout << "递归—中序：";
	inOrderRecur(head);
	cout << endl;

	BTreeNode * curNode;
	BTreeNode * laterNode;

	curNode = head->left;
	cout << curNode->value << " 的后继节点：";
	laterNode = getSuccessorNode(curNode);
	cout << (laterNode == nullptr ? -1 : laterNode->value) << endl;
	cout << curNode->value << " 的前继节点：";
	laterNode = getPreNode(curNode);
	 cout << (laterNode == nullptr ? -1 : laterNode->value) << endl;
	
	curNode = head->left->left;
	cout << curNode->value << " 的后继节点：";
	laterNode = getSuccessorNode(curNode);
	 cout << (laterNode == nullptr ? -1 : laterNode->value) << endl;
	cout << curNode->value << " 的前继节点：";
	laterNode = getPreNode(curNode);
	 cout << (laterNode == nullptr ? -1 : laterNode->value) << endl;

	curNode = head->left->left->right;
	cout << curNode->value << " 的后继节点：";
	laterNode = getSuccessorNode(curNode);
	 cout << (laterNode == nullptr ? -1 : laterNode->value) << endl;
	cout << curNode->value << " 的前继节点：";
	laterNode = getPreNode(curNode);
	 cout << (laterNode == nullptr ? -1 : laterNode->value) << endl;

	cout<<"Write By JZQ!"<<endl;
	//自动排版：ctrl+k+F
	return 0;
}