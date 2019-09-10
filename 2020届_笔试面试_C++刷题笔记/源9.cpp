//#include <iostream>
//#include <vector>
//#include <numeric>
//#include <string>
//#include <limits>
//using namespace std;
//
//struct bitnode
//{
//	char data;
//	bitnode * left;
//	bitnode * right;
//	bitnode(const char data)
//	{
//		this->data = data;
//		left = nullptr;
//		right = nullptr;
//	}
//};
//
//static bitnode * CreateTree(string str)
//{
//	char ch;
//	vector<bitnode *> stack(str.size());
//	bitnode * head = nullptr;
//	bitnode * p = head;
//	int top = -1;
//	int k = 0, j = 0;
//	while ((ch = str[j++]) != '\0')
//	{
//		switch (ch)
//		{
//		case '(':
//			top++;
//			stack[top] = p;
//			k = 1;
//			break;
//		case ',':
//			k = 2;
//			break;
//		case ')':
//			top--;
//			break;
//		default:
//			p = new bitnode(ch);
//			if (head == nullptr)
//			{
//				head = p;
//			}
//			else
//			{
//				switch (k)
//				{
//				case 1:
//					stack[top]->left = p;
//					break;
//				case 2:
//					stack[top]->right = p;
//					break;
//				}
//			}
//		}
//	}
//	return head;
//}
//
//static string inorderPrint(bitnode * head)
//{
//	if (head == nullptr)
//	{
//		return "";
//	}
//	string res = "";
//	res += inorderPrint(head->left);
//	res += head->data;
//	res += inorderPrint(head->right);
//	return res;
//}
//
///*请完成下面这个函数，实现题目要求的功能
//当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^
//******************************开始写代码******************************/
//string solution(string input) {
//	bitnode * head = CreateTree(input);
//	string res = inorderPrint(head);
//	return res;
//}
///******************************结束写代码******************************/
//
//int main() {
//	string res;
//
//	string _input;
//	getline(cin, _input);
//
//	res = solution(_input);
//	cout << res << endl;
//
//	return 0;
//
//}
