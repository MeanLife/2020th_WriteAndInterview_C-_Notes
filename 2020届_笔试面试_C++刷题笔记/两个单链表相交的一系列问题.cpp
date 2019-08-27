#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <unordered_set>
using namespace std;

/*
判断两个单链表是否相交以及相交的情况下求第一个相交节点，两个链表可以有环，也可以无环。因此我们可以从以下几个步骤分析：

1、判断一个单链表是否存在环路，如果无环，返回null，反之，返回入环节点。
	第一种：使用HashSet，
	第二种：使用快慢指针。《https://blog.csdn.net/Yufail/article/details/88236625》
		 * 步骤：
		 * ①准备两个快慢指针，一个一次走一步，一个一次走两步，如果有环，两个指针肯定会相遇，如果快指针走到了null，则代表无环；
		 * ②当两个指针相遇后，将快指针指向头节点，然后两个指针每次都同时走一步，当两个指针相等时，就到了链表的入环节点，返回即可。
2、如果两个单链表均无环，进入相应的子程序，如果无相交，返回null，反之，返回第一个相交节点。
3、如果一个有环，一个无环，不可能相交。
4、如果两个单链表均有环，进入相应的子程序，如果无相交，返回null，反之，返回第一个相交节点。
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
	return head;
}
/***************************************
第一种：使用HashSet，
***************************************/
static Node *getLoopNode_1(Node *head)
{
	unordered_set<Node *> set;
	Node *cur = head;
	while (nullptr != cur)
	{
		auto it = set.insert(cur); //成员函数 insert() 可以插入作为参数传入的单个元素。在这种情况下，它会返回一个 pair 对象，这个 pair 对象包含一个迭代器，以及一个附加的布尔值用来说明插入是否成功。
		if (!it.second)
		{
			return cur;
		}
		cur = cur->next;
	}
	return nullptr;
}
/***************************************
第二种：使用快慢指针。《https://blog.csdn.net/Yufail/article/details/88236625》
	* 步骤：
	* ①准备两个快慢指针，一个一次走一步，一个一次走两步，如果有环，两个指针肯定会相遇，如果快指针走到了null，则代表无环；
	* ②当两个指针相遇后，将快指针指向头节点，然后两个指针每次都同时走一步，当两个指针相等时，就到了链表的入环节点，返回即可。
***************************************/
static Node *getLoopNode_2(Node *head)
{
	if (head == nullptr || head->next == nullptr || head->next->next == nullptr)
	{
		return nullptr;
	}
	Node *slow = head->next;
	Node *fast = head->next->next; // 要保证进入下面的循环，要认为提前走一步。
	while (slow != fast) // 当两个指针相遇后，肯定有环
	{
		if (fast == nullptr || fast->next == nullptr)
		{
			return nullptr;
		}
		slow = slow->next;
		fast = fast->next->next;
	}
	fast = head; // 将快指针指向头节点，
	// 然后两个指针每次都同时走一步，当两个指针相等时，就到了链表的入环节点，返回即可。
	while (slow != fast)
	{
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}
/***************************************
 * 返回两个无环链表的第一个相交节点。（方法一：HashSet；；方法二：如果两个链表相交，end一定相同）
 * 步骤：
 * ①遍历两个链表，分别得到长度和最后一个节点length1,end1;length2,end2；
 * ②如果两个链表相交，end一定相同，否则，不相交，直接返回null。
 * ③确定两个链表长度的差值，让长的链表先走差值这么大的步数，然后两个链表同时走，相遇的时候就是第一个相交节点。
***************************************/
static Node *allNoLoop(Node *head1, Node *head2)
{
	Node *end1 = head1;
	int length1 = 0;
	while (nullptr != end1)
	{
		length1++;
		end1 = end1->next;
	}
	Node *end2 = head2;
	int length2 = 0;
	while (nullptr != end2)
	{
		length2++;
		end2 = end2->next;
	}
	if (end1 != end2)
	{
		return nullptr;
	}
	
	Node * bigHead = nullptr;
	Node * samllHead = nullptr;
	bigHead = length1 >= length2 ? head1 : head2;
	samllHead = bigHead == head1 ? head2 : head1;
	int difference = abs(length1 - length2);
	for (int i = 0; i < difference; ++i)
	{
		bigHead = bigHead->next;
	}
	while (bigHead != samllHead)
	{
		bigHead = bigHead->next;
		samllHead = samllHead->next;
	}
	return samllHead;
}
/***************************************
* 返回两个有环链表的第一个相交节点。
 * 步骤：
 * ①判断两个有环的链表的相交情况，有三种：可能不相交、第一种相交、第二种相交（在相应的图上）；
 * ②如果两个链表的入环节点相等，则为第一种相交情况；
 * ③针对第一种相交情况，其实与无环链表相交理论基本上一致，只不过计算长度的时候无环是到end，有环则是到入环节点；
 * ④如果不相等，则为不相交或者第二种相交情况；
 * ⑤此时把loopNode1一直往下走，如果在回到自己之前，没有遇到loopNode2，则为两个链表不相交，
 * 否则相交，直接返回loopNode1或loopNode2即可，因为这两个都是第一个相交节点，只不过是针对不同链表而言的。
***************************************/
static Node *allLoop(Node *head1, Node *head2, Node *LoopNode1, Node *LoopNode2)
{
	if (LoopNode1 == LoopNode2)
	{
		int length1 = 0;
		int length2 = 0;
		Node *end1 = head1;
		Node *end2 = head2;
		while (LoopNode1 != end1)
		{
			length1++;
			end1 = end1->next;
		}
		while (LoopNode2 != end2)
		{
			length2++;
			end2 = end2->next;
		}
		Node * bigHead = nullptr;
		Node * samllHead = nullptr;
		bigHead = length1 >= length2 ? head1 : head2;
		samllHead = bigHead == head1 ? head2 : head1;
		int difference = abs(length1 - length2);
		for (int i = 0; i < difference; ++i)
		{
			bigHead = bigHead->next;
		}
		while (bigHead != samllHead)
		{
			bigHead = bigHead->next;
			samllHead = samllHead->next;
		}
		return bigHead;
	}
	else if (LoopNode1->next == LoopNode2 || LoopNode2->next == LoopNode1)
	{
		Node *temp = LoopNode1->next;
		while (temp != LoopNode1)
		{
			if (temp == LoopNode2)
			{
				return LoopNode1;
				//or return loopNode2;
			}
			temp = temp->next;
		}
		return nullptr;
	}
	else
	{
		return nullptr;
	}
}


int main00411101011055544545222(void)
{
	Node *Head1 = nullptr;
	Head1 = creatList();
	//printList(Head1);
	Node *cur = Head1;
	while (cur->data != 4) // 找到末尾，形成环
	{
		cur = cur->next;
	}
	cur->next = Head1->next;

	Node *Head2 = nullptr;
	Head2 = creatList();
	Head2->next->next = Head1;
	//printList(Head2);

	// 1、判断是否有环，两种方法
	Node *LoopNode1 = nullptr;
	Node *LoopNode2 = nullptr;
	LoopNode1 = getLoopNode_1(Head1);
	LoopNode2 = getLoopNode_1(Head2);
	//Node *LoopNode3 = nullptr;
	//Node *LoopNode4 = nullptr;
	//LoopNode3 = getLoopNode_2(Head1);
	//LoopNode4 = getLoopNode_2(Head2);

	// 2、分情况判断是否相交
	Node *IntersectionNode = nullptr;
	if (LoopNode1 == nullptr && LoopNode2 == nullptr)
	{
		IntersectionNode = allNoLoop(Head1, Head2);
	}
	else if(LoopNode1 != nullptr && LoopNode2 != nullptr)
	{
		IntersectionNode = allLoop(Head1, Head2, LoopNode1, LoopNode2);
	}
	else
	{
		IntersectionNode = nullptr;
	}

	if (IntersectionNode == nullptr)
	{
		cout << "未相交" << endl;
	}
	else
	{
		cout << "相交于节点: " << IntersectionNode->data << endl;
	}

	cout << "Write By JZQ!" << endl;
	//自动排版：ctrl+k+F
	return 0;
}