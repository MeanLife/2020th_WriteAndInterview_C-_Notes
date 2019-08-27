#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <unordered_map>
using namespace std;

/*
【题目】：
　　一种特殊的链表节点类描述如下：
struct Node
	 {
		 int data;
		 Node *next;
		 Node *rand;
	 };
Node 中的 data 是节点值，next 指针和正常链表中的 next 指针的意义一样，都指向下一个节点，
rand 指针是 Node 类中新增的指针，这个指针可能指向链表中的任意一个节点，也可能指向 NULL。
给定一个由 Node 节点类型组成的无环单链表的头节点 head，请实现一个函数完成这个链表中所有结构的复制，
并返回复制的新链表的头节点。例如：链表1->2->3->NULL。
假设 1 的 rand 指针指向 3，2 的 rand 指针指向NULL，3 的 rand 指针指向 1。复制后的链表应该也是这种结构。
【思路】：
　　普通解法：使用hash_map
　　进阶解法：1->2->3-NULL   ------>    1->1'->2->2'->3->3'->NULL
　　不管是普通算法还是进阶算法找到 rand 所对应的 Node 是关键。
【进阶】：
　　不使用额外的数据结构，只使用有限几个变量，且在时间复杂度为 O(N)内完成原问题要实现的函数。
*/
struct Node
{
	int data;
	Node *next;
	Node *rand;
};

// 打印带随机节点的单链表
void printListWithRand(Node *head)
{
	while (NULL != head)
	{
		if (NULL != head->rand)
			cout << head->data << " rand is: " << head->rand->data << endl;
		else
			cout << head->data << " rand is: NULL " << endl;

		if (NULL != head->next)
			cout << head->data << " next is: " << head->next->data << endl;
		else
			cout << head->data << " next is: NULL " << endl;
		head = head->next;
	}
}

static Node * creatList() // 创建单链表(不带头节点的单链表)，new出来的控件不能用引用返回。会造成内存泄漏
{
	Node *head = nullptr;
	Node *ptr = nullptr;
	for (int i = 1; i < 5; i++)
	{
		if (nullptr == head) // 这里是为了保持head1停留在第一个节点不动，让辅助指针ptr移动。
		{
			head = new Node;
			head->data = i;
			head->next = nullptr;
			head->rand = nullptr;
			ptr = head;
			continue;
		}
		ptr->next = new Node;
		ptr = ptr->next;
		ptr->data = i;
		ptr->next = nullptr;
		ptr->rand = nullptr;
	}
	return head;
}

// 普通解法：使用hash_map
Node* copyListWithRand_1(Node *head)
{
	unordered_map<Node *, Node *> map;
	Node *cur = head;
	while (nullptr != cur) // 先创建出所有的复制节点，这时候指向Null
	{
		Node *ptr = new Node;
		ptr->data = cur->data;
		ptr->next = nullptr; // 下一个复制节点还未new出来，所以先指向null
		ptr->rand = nullptr; // rand也是同理
		map[cur] = ptr;    //一一对应的关系
		cur = cur->next;
	}
	cur = head;
	while (nullptr != cur) // 调整复制节点的指向。
	{
		map[cur]->next = map[cur->next];
		map[cur]->rand = map[cur->rand];
		cur = cur->next;
	}
	return map[head];
}

// 进阶解法：1->2->3 - NULL------ > 1->1'->2->2'->3->3'->NULL
Node* copyListWithRand_2(Node *head)
{
	if (nullptr == head)
	{
		return nullptr;
	}
	// 插入节点1'、2'、3'......
	Node *cur = head;
	Node *next = nullptr; // next代表的是1'、2'、3'......
	while (nullptr != cur)
	{
		next = new Node;
		next->data = cur->data*10;
		next->next = cur->next;
		next->rand = nullptr;
		cur->next = next;
		cur = next->next;
	}
	// 复制rand
	cur = head;
	Node *curCopy = nullptr;
	while (nullptr != cur)
	{
		next = cur->next->next;
		curCopy = cur->next;
		curCopy->rand = cur->rand == nullptr ? nullptr : cur->rand->next;
		cur = next;
	}
	// 拆分原链表和复制链表
	Node *res = head->next;
	cur = head;
	while (nullptr != cur)
	{
		next = cur->next->next;
		curCopy = cur->next;
		cur->next = next;
		curCopy->next = next == nullptr ? nullptr : next->next;
		cur = next;
	}

	// rand和拆分一起做会出问题，因为：前面的已经拆分了，后面的cur->rand->next;指向就变了。
	//cur = head;
	//Node *res = head->next;
	//Node *curCopy = nullptr;
	//while (nullptr != cur)
	//{ // rand和拆分一起做会出问题，因为：前面的已经拆分了，后面的cur->rand->next;指向就变了。
	//	next = cur->next->next;
	//	curCopy = cur->next;
	//	curCopy->rand = cur->rand == nullptr ? nullptr : cur->rand->next;
	//	curCopy->next = next == nullptr ? nullptr : next->next;
	//	cur->next = next;
	//	cur = next;
	//}
	return res;
}


int main0000503025222220202220220(void)
{
	Node *Head = nullptr;
	Head = creatList();
	Head->rand = Head->next->next;
	Head->next->rand = nullptr;
	Head->next->next->rand = Head;
	Head->next->next->next->rand = Head->next;

	printListWithRand(Head);
	cout << endl;

	Node *Head_copy = nullptr;
	Head_copy = copyListWithRand_2(Head);
	printListWithRand(Head_copy);

	cout << "Write By JZQ!" << endl;
	//自动排版：ctrl+k+F
	return 0;
}