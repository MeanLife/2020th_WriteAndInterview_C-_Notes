/*
 *文件名：lists_reverse.cpp
 *作者：
 *摘要：反转单双向链表
 */

#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

struct SingleNode
{
	int value;
	SingleNode *next;
};

struct DoubleNode
{
	int value;
	DoubleNode *pre;
	DoubleNode *next;
};

// 单向链表的反转
SingleNode* reverseList(SingleNode *head)
{
	SingleNode *pre = nullptr;
	SingleNode *next = nullptr;
	//head为当前，pre为之前，next为之后
	while (nullptr != head)
	{
		next = head->next;
		head->next = pre;
		pre = head;
		head = next;
	}
	return pre;
}

// 双向链表的反转：与单向链表的反转一样，只是多了一步前置处理
DoubleNode* reverseList(DoubleNode *head)
{
	DoubleNode *pre = nullptr;
	DoubleNode *next = nullptr;
	//head为当前，pre为之前，next为之后
	while (nullptr != head)
	{
		next = head->next;
		head->next = pre;
		head->pre = next;    //多了一步前置处理
		pre = head;
		head = next;
	}
	return pre;
}

void printList(SingleNode *head)
{
	while (nullptr != head)
	{
		cout << head->value << " ";
		head = head->next;
	}
	cout << endl;
}

void printList(DoubleNode *head)
{
	while (nullptr != head)
	{
		cout << head->value << " ";
		head = head->next;
	}
	cout << endl;
}

int main012201210220102052()
{
	SingleNode *shead = nullptr;
	SingleNode *sptr = nullptr;
	DoubleNode *dhead = nullptr;
	DoubleNode *dptr = nullptr;
	for (int i = 0; i < 10; i++)
	{
		if (nullptr == shead && nullptr == dhead)
		{
			shead = new SingleNode;
			shead->value = i;
			shead->next = nullptr;
			sptr = shead;

			dhead = new DoubleNode;
			dhead->value = i;
			dhead->next = nullptr;
			dhead->pre = nullptr;
			dptr = dhead;
			continue;
		}
		sptr->next = new SingleNode;
		sptr = sptr->next;
		sptr->value = i;
		sptr->next = nullptr;

		dptr->next = new DoubleNode;
		dptr->next->pre = dptr;
		dptr = dptr->next;
		dptr->value = i;
		dptr->next = nullptr;
	}
	cout << "SingleNode before reversed: " << endl;
	printList(shead);
	cout << "SingleNode after reversed: " << endl;
	shead = reverseList(shead);
	printList(shead);

	cout << "DoubleNode before reversed: " << endl;
	printList(dhead);
	cout << "DoubleNode after reversed: " << endl;
	dhead = reverseList(dhead);
	printList(dhead);
	return 0;
}