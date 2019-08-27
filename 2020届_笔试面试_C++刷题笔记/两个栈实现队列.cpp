#include <iostream>
#include <string>
#include <cmath>
#include <stack>
using namespace std;



// 手写代码：两个栈实现一个队列
class Solution
{
public:
	void push(int node) 
	{
		stack_push.push(node);
	}

	int pop() 
	{
		if (stack_pop.size() != 0) 
		{
			int tmp = stack_pop.top();
			stack_pop.pop();
			return tmp;
		}
		else 
		{
			while (stack_push.size() != 0) // 将stack_push倒入stack_pop的过程
			{
				int tmp = stack_push.top();
				stack_push.pop();
				stack_pop.push(tmp);
			}
			return pop();
		}
	}

private:
	stack<int> stack_push;// 入队列
	stack<int> stack_pop;// 出队列
};


int main1121212131(void)
{
	Solution q;
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);

	for (size_t i = 0; i < 4; i++)
	{
		cout << q.pop() << "  ";

	}
	cout << endl;
	cout<<"Write By JZQ!"<<endl;
	//自动排版：ctrl+k+F
	return 0;
}