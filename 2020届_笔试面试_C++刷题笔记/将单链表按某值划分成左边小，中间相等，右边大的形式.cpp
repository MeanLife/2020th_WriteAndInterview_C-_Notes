#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

/*
普通方法，将链表节点放到数组然后partition，无空间复杂度要求、无稳定性要求
进阶方法，将链表划分成三个子链表，然后合并，空间复杂度O(1)，且稳定。
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
	for (int i = 0; i < 15; i++)
	{
		if (nullptr == head) // 这里是为了保持head1停留在第一个节点不动，让辅助指针ptr移动。
		{
			head = new Node;
			head->data = rand() % 10;
			head->next = nullptr;
			ptr = head;
			continue;
		}
		ptr->next = new Node;
		ptr = ptr->next;
		ptr->data = rand() % 10;
		ptr->next = nullptr;
	}
	return head;
}

// 普通方法，将链表节点放到数组然后partition，无空间复杂度要求、无稳定性要求
static void partitionList_1(Node *head, int piovt)
{
	vector<int> array;
	Node * cur = head;
	while (cur != nullptr)
	{
		array.push_back(cur->data);
		cur = cur->next;
	}
	sort(array.begin(), array.end());
	reverse(array.begin(), array.end());
	cur = head;
	while (cur != nullptr)
	{
		cur->data = array.back();
		array.pop_back();
		cur = cur->next;
	}
}

// 进阶方法，将链表划分成三个子链表，然后合并，空间复杂度O(1)，且稳定。
/*
这个方法是将原来的链表依次划分成三个链表，三个链表分别为:
small代表的是左边小于的部分，equal代表的是中间相等的部分，big代表的是右边的大于部分；
这三个链表都有自己的两个指针Head和Tail分别代表各自的头部和尾部，分成三个子链表之后，
我们只需要遍历链表，然后和给定的值比较，按照条件，向三个链表中添加值就可以了，最后把三个链表连接起来就可以了；
*/
static void partitionList_2(Node *head, int piovt)
{
	if (head == nullptr)return;
	Node *sHead = nullptr, *sTail = nullptr; //小于部分链表的  head 和tail
	Node *eHead = nullptr, *eTail = nullptr; //等于部分链表的　head 和tail
	Node *bHead = nullptr, *bTail = nullptr; //大于部分链表的　head 和tail

	Node *next = nullptr;  //用来保存下一个结点
	Node *cur = head;

	//划分到　三个不同的链表
	while (cur != nullptr) 
	{
		next = cur->next;
		cur->next = nullptr; //这个是为了链表拼接后　最后一个就不用再去赋值其next域为nullptr 了
		if (cur->data < piovt) 
		{  //向　small 部分　分布
			if (sHead == nullptr) 
			{ //small部分的第一个结点
				sHead = cur;
				sTail = cur;
			}
			else 
			{ //small部分的非第一个节点
				sTail->next = cur; //把cur放到small最后一个
				sTail = cur;  //更新small部分的sTail
			}
		}
		else if (cur->data == piovt) 
		{
			if (eHead == nullptr) 
			{
				eHead = cur;
				eTail = cur;
			}
			else 
			{
				eTail->next = cur;
				eTail = cur;
			}
		}
		else 
		{
			if (bHead == nullptr) 
			{
				bHead = cur;
				bTail = cur;
			}
			else 
			{
				bTail->next = cur;
				bTail = cur;
			}
		}
		cur = next;
	}

	//将三个链表合并(注意边界的判断)
	if (nullptr != sTail) 
	{ //合并small和equal部分
		sTail->next = eHead;
		eTail = (eTail == nullptr ? sTail : eTail); // 看中间等于区域是否为空的。
	}
	if (nullptr != eTail) 
	{ //合并equal和big部分
		eTail->next = bHead;
	}
	head = (sHead != nullptr ? sHead : eHead != nullptr ? eHead : bHead); // head等于三者中第一个不为nullptr的值。
}


int main110000051111112222(void)
{
	Node *Head1 = nullptr;
	Head1 = creatList();

	printList(Head1);

	partitionList_1(Head1, 5);

	cout << "partitionList_1划分过后：" << endl;
	printList(Head1);

	Node *Head2 = nullptr;
	Head2 = creatList();

	printList(Head2);
	cout << endl;

	partitionList_2(Head2, 5);

	cout << "partitionList_2划分过后：" << endl;
	printList(Head2);
	
	cout<<"Write By JZQ!"<<endl;
	//自动排版：ctrl+k+F
	return 0;
}