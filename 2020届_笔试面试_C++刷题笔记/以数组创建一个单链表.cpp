#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

struct Node
{
	int data;
	Node *next;
	Node(const int data)
	{
		this->data = data;
		next = nullptr;
	}
};

static Node * ConstructLinkList(vector<int> &array)
{
	if (array.empty())
	{
		return nullptr;
	}

	Node * head = new Node(array[0]);
	array.erase(array.begin());
	Node * cur = head;
	while (!array.empty())
	{
		cur->next = new Node(array[0]);
		array.erase(array.begin());
		cur = cur->next;
	}
	return head;
}

int main_以数组创建一个单链表(void)
{
	vector<int> array = { 1,2,3,4,5,6,7,8 };
	Node * head = ConstructLinkList(array);

	Node * cur = head;
	while (cur != nullptr)
	{
		cout << cur->data << "  ";
		cur = cur->next;
	}
	
	cout<<"Write By JZQ!"<<endl;
	//自动排版：ctrl+k+F
	return 0;
}