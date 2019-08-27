#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

/*
【题目】：
　　给定两个有序链表的头指针 head1 和 head2，打印两个链表的公共部分。
【思路】：
　　类似外排，依次比较
*/
struct Node
{
	int data;
	Node *next;
};

void printCommonPart(Node *head1, Node *head2)
{
	cout << "Common Part: " << endl;
	while (nullptr != head1 && nullptr != head2)
	{
		if (head1->data < head2->data) // 谁小谁先走
			head1 = head1->next;
		else if (head1->data > head2->data)
			head2 = head2->next;
		else // 一样大，就是公共部分
		{
			cout << head1->data << " ";
			head1 = head1->next;
			head2 = head2->next;
		}
	}
	cout << endl;
}


int main0094987418(void)
{
	Node *head1 = nullptr;
	Node *head2 = nullptr;
	Node *ptr = nullptr;

	for (int i = 0; i < 10; i++)
	{
		if (nullptr == head1) // 这里是为了保持head1停留在第一个节点不动，让辅助指针ptr移动。
		{
			head1 = new Node;
			head1->data = i;
			head1->next = nullptr;
			ptr = head1;
			continue;
		}
		ptr->next = new Node;
		ptr = ptr->next;
		ptr->data = i;
		ptr->next = nullptr;
	}
	for (int i = 3; i < 23; i++)
	{
		if (nullptr == head2)
		{
			head2 = new Node;
			head2->data = i;
			head2->next = nullptr;
			ptr = head2;
			continue;
		}
		ptr->next = new Node;
		ptr = ptr->next;
		ptr->data = i;
		ptr->next = nullptr;
	}
	printCommonPart(head1, head2);

	cout<<"Write By JZQ!"<<endl;
	//自动排版：ctrl+k+F
	return 0;
}