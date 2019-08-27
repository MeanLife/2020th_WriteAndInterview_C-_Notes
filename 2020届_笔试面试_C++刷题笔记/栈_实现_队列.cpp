#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <stack>
using namespace std;

/*
两个栈来实现队列：
一个push栈、一个pop栈。
先将数据全部装入push栈，每次需要出队列时，判断pop栈是否为空的：
若为空的，则将push栈的数据全部倒入pop栈，并弹出pop栈的栈顶。
若不为空的，则直接弹出pop栈的栈顶。
*/

class TwoStacksQueue 
{
public: 
	void push(int pushInt) 
	{
		stackPush.push(pushInt);
	}

	public: void pop() {
		if (stackPop.empty() && stackPush.empty()) {
			cout << ("The queue is empty") << endl;
			return;
		}
		else if (stackPop.empty()) { // 将push栈的数据全部倒入pop栈，并弹出pop栈的栈顶。
			while (!stackPush.empty()) {
				stackPop.push(stackPush.top());
				stackPush.pop();
			}
		}
		stackPop.pop();
	}

	public: int front() {
		if (stackPop.empty() && stackPush.empty()) {
			cout << ("The queue is empty") << endl;
			return -1;
		}
		else if (stackPop.empty()) { // 将push栈的数据全部倒入pop栈，并弹出pop栈的栈顶。
			while (!stackPush.empty()) {
				stackPop.push(stackPush.top());
				stackPush.pop();
			}
		}
		return stackPop.top();
	}

private: stack<int> stackPush;
private: stack<int> stackPop;
};


int main2122222221111(void)
{
	TwoStacksQueue queue;
	for (int i = 0; i < 5; i++)
	{
		queue.push(i + 1);
	}

	for (int i = 0; i < 5; i++)
	{
		cout << queue.front() << "  ";
		queue.pop();
	}
	cout << endl;

	cout << "Write By JZQ!" << endl;
	//自动排版：ctrl+k+F
	return 0;
}