#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

class Array_to_Queue // 循环队列
{
public:
	Array_to_Queue(int initSize)
	{
		if (initSize < 0)
		{
			cout << ("The init size is less than 0") << endl;
			return;
		}
		capacity = initSize;
		arr = new int[capacity];
		size = 0;
		first = 0;
		last = 0;
	}

public:
	void push(int value)
	{
		if (size == capacity)
		{
			cout << ("The queue is full") << endl;
			return;
		}
		size++;
		arr[last] = value; // 放到队尾
		last = (last == (capacity - 1)) ? 0 : last + 1; // 看last是否到了数组末端，若为真，则调回开始位置0.
	}

	void pop()
	{
		if (size == 0)
		{
			cout << ("The queue is empty") << endl;
			return;
		}
		size--;
		first = (first == (capacity - 1)) ? 0 : first + 1; // 看first是否到了数组末端，若为真，则调回开始位置0.
	}

	int front()
	{
		if (size == 0)
		{
			cout << ("The queue is empty") << endl;
			return -1;
		}
		return arr[first];
	}

	int getSize()
	{
		return size;
	}
private:
	int *arr = nullptr;
	int first = 0; // 队头
	int last = 0; // 队尾
	int size = 0;
	int capacity = 0;

};

int main21215221515555(void)
{
	Array_to_Queue queue(5);
	for (int i = 0; i < 5; i++)
	{
		queue.push(i + 1);
	}

	for (int i = 0; i < 5; i++)
	{
		cout << queue.front() << "  ";
		queue.pop();
		cout << queue.getSize() << endl;
	}
	cout << endl;

	cout << "Write By JZQ!" << endl;
	//自动排版：ctrl+k+F
	return 0;
}