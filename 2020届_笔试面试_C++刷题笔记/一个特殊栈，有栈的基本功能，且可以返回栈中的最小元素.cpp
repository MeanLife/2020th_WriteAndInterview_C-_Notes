#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <stack>
using namespace std;

/*
实现一个特殊栈，有栈的基本功能，且可以返回栈中的最小元素

思路：两个栈同时使用，一个栈正常使用，一个Min栈，只压入当前正常栈中的最小元素。
*/

class MyStack_getMin
{

public:
	void push(int newNum) 
	{
		stackData.push(newNum);
		if (stackMin.empty()) {
			stackMin.push(newNum);
		}
		else 
		{
			stackMin.push(newNum <= getmin() ? newNum : getmin());
		}
	}

public:
	void pop() 
	{
		if (stackData.empty()) {
			cout << ("Your stack is empty.") << endl;
			return;
		}
		stackData.pop();
		stackMin.pop();
	}

public:
	int top()
	{
		if (stackData.empty()) {
			cout << ("Your stack is empty.") << endl;
			return -1;
		}
		return stackData.top();
	}

public:
	int getmin() 
	{
		if (stackMin.empty()) 
		{
			cout << ("Your stack is empty.") << endl;
			return -1;
		}
		return stackMin.top();
	}

public:
	int getSize()
	{
		if (stackData.empty())
		{
			cout << ("Your stack is empty.") << endl;
			return -1;
		}
		return stackData.size();
	}

private:
	stack<int> stackData;
	stack<int> stackMin;
};

int main123123141(void)
{
	MyStack_getMin stack1;
	
	stack1.push(5);
	stack1.push(1);
	stack1.push(3);
	stack1.push(7);
	stack1.push(0);
	stack1.push(2);
	stack1.push(5);

	cout << "目前栈顶元素:\t" << "目前栈内元素个数：\t" << "目前栈内元素最小值：\t" << endl;
	for (int i = 0; i < 7; i++)
	{
		cout << stack1.top() << "  \t\t";
		cout << stack1.getSize() << "  \t\t\t";
		cout << "Min = " << stack1.getmin() << endl;
		stack1.pop();
	}
	cout << endl;

	cout << "Write By JZQ!" << endl;
	//自动排版：ctrl+k+F
	return 0;
}