#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <stack>
using namespace std;

/*
输入一个链表，按链表值从尾到头的顺序返回一个ArrayList。
*/

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(nullptr) 
	{
	}
};

// 借用栈实现
vector<int> printListFromTailToHead1(ListNode* head) 
{
	vector<int> ArrayList;
	stack<int> temp;
	while (head != nullptr)
	{
		temp.push(head->val);
		head = head->next;
	}
	while (!temp.empty())
	{
		ArrayList.push_back(temp.top());
		temp.pop();
	}
	return ArrayList;
}

// 链表反转实现
vector<int> printListFromTailToHead2(ListNode* head)
{
	vector<int> ArrayList;
	
	ListNode *pre = nullptr;
	ListNode *cur = head;
	ListNode *next = cur->next;
	while (nullptr != cur)
	{
		next = cur->next;
		cur->next = pre;
		pre = cur;
		cur = next;
	}
	head = pre; // 此时的pre为头结点
	while (head != nullptr)
	{
		ArrayList.push_back(head->val);
		head = head->next;
	}
	return ArrayList;
}

int main1052505015215135621156615(void)
{
	ListNode * head = new ListNode(1);
	head->next = new struct ListNode(2);
	head->next->next = new struct ListNode(3);

	vector<int> ArrayList = printListFromTailToHead2(head);

	for (vector<int>::iterator it = ArrayList.begin(); it != ArrayList.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;
	
	cout<<"Write By JZQ!"<<endl;
	//自动排版：ctrl+k+F
	return 0;
}