#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

/*
Given:
1->2->3->4 you should return the list as 2->1->4->3

迭代法：时间复杂度O(n)，空间复杂度O(1)
递归法：时间复杂度O(n)，空间复杂度O(n)
*/
static struct Node
{
	int data;
	Node *next;
};

// 打印不带头节点的单链表
static void printList(Node *head)
{
	while (head != nullptr)
	{
		cout << head->data << ' ';
		head = head->next;
	}
	cout << endl;
}

static Node * creatList() // 创建单链表(不带头节点的单链表)，new出来的控件不能用引用返回。会造成内存泄漏
{
	Node *head = nullptr;
	Node *ptr = nullptr;
	for (int i = 1; i < 8; i++)
	{
		if (nullptr == head) // 这里是为了保持head1停留在第一个节点不动，让辅助指针ptr移动。
		{
			head = new Node;
			head->data = i;
			head->next = nullptr;
			ptr = head;
			continue;
		}
		ptr->next = new Node;
		ptr = ptr->next;
		ptr->data = i;
		ptr->next = nullptr;
	}
	return head;
}

//static Node * reversePairList(Node *head)
//{// 该代码只适用于偶数个节点，看下面有通用的方法。
//	if (head == nullptr || head->next == nullptr)
//	{
//		return head;
//	}
//	Node *cur = head;
//	Node *next = cur->next;
//	Node *res = next;
//	Node *nextnext = next->next;
//	while (cur != nullptr && next != nullptr)
//	{ 
//		next = cur->next;
//		nextnext = next->next;
//
//		cur->next = nextnext == nullptr ? nextnext : nextnext->next;
//		next->next = cur;
//
//		cur = nextnext;
//	}
//	return res;
//}

// 单链表的成对反转。
static Node * reversePairList_2(Node *head)
{// 该代码适用于任意数个节点
	Node *dummy = new Node; // 辅助节点
	dummy->data = 0;
	dummy->next = head;
	Node *pre = dummy;
	Node *cur = head;
	Node *next = cur->next;
	while (cur != nullptr && cur->next != nullptr)
	{
		next = cur->next;
		cur->next = next->next;
		next->next = pre->next;
		pre->next = next;
		pre = cur;
		cur = cur->next;
	}
	return dummy->next;
}

int main5455656561546456645456564(void)
{
	Node *Head1 = nullptr;
	Head1 = creatList();
	printList(Head1);

	Head1 = reversePairList_2(Head1);

	cout << "成对反转过后：" << endl;
	printList(Head1);

	cout << "Write By JZQ!" << endl;
	//自动排版：ctrl+k+F
	return 0;
}