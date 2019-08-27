#include <iostream>
#include <string>
#include <cmath>
#include <stack>
#include <queue>
using namespace std;

/*
stack
stack 是一种容器适配器，用于 LIFO（后进先出）的操作，其中元素仅从容器的一端插入和提取。
（ 1）构造： atack<int >myStack;
（ 2）通用操作： empty(), size(),
（ 3）特有操作： pop(), push(),top(),
*/
void myStackTest()
{
	cout << "----------this is class stack demo---------------" << endl;
	stack<int >myStack;
	myStack.push(1);
	myStack.push(2);
	myStack.push(3); //元素进栈


	auto top_num = myStack.top(); //栈顶元素
	cout << "the num of myStack is: " << top_num << endl;
	myStack.pop(); //弹出栈顶元素
	int top_num1 = myStack.top();
	cout << "the num of myStack is: " << top_num1 << endl;


	// 遍历
	while (!myStack.empty())
	{
		cout << "the num of myStack is: " << myStack.top() << endl;
		myStack.pop();
	}

	cout << endl;
	cout << endl;
	cout << endl;
}


/*
queue
queue 是一种容器适配器，用于在 FIFO（先入先出）的操作，其中元素插入到容器的一端并从另一端提取。
（ 1）构造： queue<int> myQueue;
（ 2）通用操作： empty(), size(), front(), back(),
（ 3）特有操作： push(), pop(),
*/
void myQueueTest()
{
	cout << "---------------this is class queue demo-----" << endl;
	queue<int > myQueue;
	myQueue.push(1);
	myQueue.push(2);
	myQueue.push(3);
	myQueue.push(4);
	myQueue.push(5); //入队列，队尾进（右边）


	queue<int> myQueue2(myQueue);
	while (!myQueue2.empty())
	{
		cout << myQueue2.front() << "  ";
		myQueue2.pop(); // 队头出（左边）
	}
	cout << endl;


	int front_num = myQueue.front(); //队列头元素
	int back_num = myQueue.back(); //队列尾元素
	printf("the front and back num of the myQueue : %d and %d \n", front_num, back_num);


	myQueue.pop(); //弹出元素不返回元素
	myQueue.pop();


	int front_num1 = myQueue.front();
	int back_num1 = myQueue.back();
	printf("the front and back num of the myQueue : %d and %d \n", front_num1, back_num1);

}


int main112211(void)
{
	myStackTest();
	myQueueTest();

	
	cout<<"Write By JZQ!"<<endl;
	//自动排版：ctrl+k+F
	system("pause");
	return 0;
}