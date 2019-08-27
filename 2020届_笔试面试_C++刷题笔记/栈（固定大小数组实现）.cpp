#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

class Array_to_Stack
{
public:
	Array_to_Stack(int initSize) 
	{
		if (initSize < 0) 
		{
			cout << ("The init size is less than 0") << endl;
			return;
		}
		capacity = initSize;
		arr = new int[capacity];
		size = 0;
	}

public:
	int top() 
	{
		if (size == 0) 
		{
			return -1;
		}
		return arr[size - 1];
	}

	void push(int obj) 
	{
		if (size == capacity) 
		{
			cout << ("The queue is full") << endl;
			return;
		}
		arr[size++] = obj;
	}

	void pop() 
	{
		if (size == 0) 
		{
			cout << ("The queue is empty") << endl;
			return;
		}
		--size;
	}

	int getSize()
	{
		return size;
	}
private:
	int *arr = nullptr;
	int index = 0;
	int size = 0;
	int capacity = 0;

};

int main0000000002222222222(void)
{
	Array_to_Stack stack(5);
	for (int i = 0; i < 5; i++)
	{
		stack.push(i + 1);
	}

	for (int i = 0; i < 5; i++)
	{
		cout << stack.top() << "  ";
		stack.pop();
		cout << stack.getSize() << endl;
	}
	cout << endl;
	
	cout<<"Write By JZQ!"<<endl;
	//×Ô¶¯ÅÅ°æ£ºctrl+k+F
	return 0;
}