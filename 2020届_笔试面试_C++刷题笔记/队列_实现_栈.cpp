#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

/*
两个队列来实现 栈：
一个data数据队列、一个help辅助队列。
*/

class TwoQueuesStack 
{
	public: void push(int pushInt) 
	{
		data.push(pushInt);
	}

	public: int top() 
	{
		if (data.empty()) {
			cout << ("The init size is less than 0") << endl;
			return -1;
		}
		while (data.size() > 1) 
		{
			help.push(data.front());
			data.pop();
		}
		int temp = data.front(); // data内只剩下最后进的元素（后进的先出）
		data.pop();
		help.push(temp);
		data.swap(help); // 两个容器内的元素进行交换
		return temp;
	}

	public: void pop() 
	{
		if (data.empty()) 
		{
			cout << ("The init size is less than 0") << endl;
			return;
		}
		while (data.size() > 1) 
		{
			help.push(data.front());
			data.pop();
		}
		data.pop(); // data内只剩下最后进的元素（后进的先出）
		data.swap(help); // 两个容器内的元素进行交换
	}
private: queue<int> data;
private: queue<int> help;
};

int main151000012(void)
{
	TwoQueuesStack stack;
	for (int i = 0; i < 5; i++)
	{
		stack.push(i + 1);
	}

	for (int i = 0; i < 5; i++)
	{
		cout << stack.top() << "  ";
		stack.pop();
	}
	cout << endl;
	
	cout<<"Write By JZQ!"<<endl;
	//自动排版：ctrl+k+F
	return 0;
}