#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <stack>
using namespace std;

/***************************************
题目描述
用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
【思路】：

***************************************/
class Solution
{
public:
	void push(int node) {
		stack1.push(node);
	}

	int pop() {
		if (stack2.size() != 0) // 先将stack2中的值清空，因为它们肯定是先进队列的。
		{
			int tmp = stack2.top();
			stack2.pop();
			return tmp;
		}
		else // stack2清空了，继续将stack1中的数据倒入stack2
		{
			while (stack1.size() != 0) // 将stack_push倒入stack_pop的过程
			{
				int tmp = stack1.top();
				stack1.pop();
				stack2.push(tmp);
			}
			return pop(); // 并弹出一个stack2的栈顶。
		}
	}

private:
	stack<int> stack1; // push栈，只负责进
	stack<int> stack2; // pop栈，只负责弹
};

int main_两个栈实现队列(void)
{
	Solution myqueue;

	
	cout<<"Write By JZQ!"<<endl;
	//自动排版：ctrl+k+F
	return 0;
}