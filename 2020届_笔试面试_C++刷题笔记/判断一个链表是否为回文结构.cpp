#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

/*
题目：判断一个链表是否为回文结构。
要求：时间复杂度为 O(n)，空间时间复杂度为O(1)。
若没有上诉要求，直接先将链表节点值以次压入栈中，再以次弹出比对，即可完成。

思路分析：回文链表的特点就是对称，那么要判断是否回文，就可以用两个指针指向对称的节点，
看它们的数据是否一样。由于是单向链表，不能同时用两个指针，从头尾向内部遍历取值比较。
且本题对空间复杂度也有要求，所以可用如下方法实现。

具体步骤如下：
（1）先得到链表的中间节点；
（2）从中间节点的下一个节点开始，反转链表。
（3）从中间节点处，断开原链表。
（4）用两个指针分别向两个端点移动，同时进行比较，数据相同则继续，数据不同则直接返回false。直到遍历完成，最后返回true。
（5）最后将后半部分逆序复原
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
	for (int i = 0; i < 5; i++)
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
	for (int i = 4; i >= 0; --i)
	{
		ptr->next = new Node;
		ptr = ptr->next;
		ptr->data = i;
		ptr->next = nullptr;
	}
	return head;
}

// 快慢指针查找单链表的中间节点(不带头节点的单链表)
static Node *FindMid(Node *head)
{
	Node *slow = head; //初始时快、慢指针都指向第一个节点。
	Node *fast = head;

	while (fast != nullptr && fast->next != nullptr && fast->next->next != nullptr)
	{
		fast = fast->next->next;
		slow = slow->next;
	}

	return slow; // 若链表节点为奇数个，slow为中间，若为偶数个slow为中间两个的前面那个。
}

// 从中间节点反转链表(不带头节点的单链表)
static Node *reverseList(Node *mid)
{
	Node *cur = mid;
	Node *pre = nullptr;
	Node *next = cur->next;
	while (nullptr != cur)
	{
		next = cur->next;
		cur->next = pre;
		pre = cur;
		cur = next;
	}

	return pre; // 返回反转后的头结点(原链表的最后一个节点)
}

// 回文（指顺读和倒读都一样的词语）
static bool isPalindrome(Node *Head , Node *rHead)
{
	Node *start = Head;
	Node *end = rHead;
	while (start != nullptr && end != nullptr)
	{
		if (start->data == end->data) // start、end有一个到中点的null即结束循环，所以不用判断时候是奇数、偶数个节点
		{
			start = start->next;
			end = end->next;
		}
		else
			return false;
	}
	return true;
}

// 复原链表(不带头节点的单链表)
static void recoverList(Node *rHead)
{
	Node *pre = nullptr;
	Node *cur = rHead;
	Node *next = cur->next;
	while (cur != nullptr)
	{
		next = cur->next;
		cur->next = pre;
		pre = cur;
		cur = next;
	}
}

int main151412543452415145(void)
{
	Node *Head = nullptr;
	Head = creatList();

	printList(Head);

	Node *mid = nullptr;
	mid = FindMid(Head);

	Node *rHead = nullptr;
	rHead = reverseList(mid);

	if (isPalindrome(Head, rHead))
	{
		cout << "是回文！" << endl;
	}
	else
	{
		cout << "不是回文！" << endl;
	}

	recoverList(rHead);
	cout << "复原后：" << endl;
	printList(Head);

	cout<<"Write By JZQ!"<<endl;
	//自动排版：ctrl+k+F
	return 0;
}