#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

/***************************************
题目描述
大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项（从0开始，第0项为0）。n<=39
【思路】：
解题思路：斐波那契数列：F(0)=0，F(1)=1, F(n)=F(n-1)+F(n-2)（n>=2，n∈N*）
第一种思路：最直观的想法就是利用函数的递归来做。但是时间复杂度和空间复杂度都极大，复杂度是O（2^n）。我也写了相关代码，严重超时。
第二种思路：将第0到第n个斐波那契数列元素都求出来，存在数组中。
第三种思路：第一种思路用到了数组，占用空间较多。因此，可以改进为只用三个变量。
***************************************/
class Solution {
public:
	//// 第一种思路：最直观的想法就是利用函数的递归来做。
	//int Fibonacci(int n) { // 函数调用很费时。
	//	if (n == 0)
	//	{
	//		return 0;
	//	}
	//	if (n == 1)
	//	{
	//		return 1;
	//	}
	//	return Fibonacci(n - 1) + Fibonacci(n - 2);
	//}

	//// 第二种思路：将第0到第n个斐波那契数列元素都求出来，存在数组中。
	//int Fibonacci(int n) {
	//	vector<int> Fibonacci_array(39);
	//	Fibonacci_array[0] = 0;
	//	Fibonacci_array[1] = 1;
	//	for (int i = 2; i <= n; i++)
	//	{
	//		Fibonacci_array[i] = Fibonacci_array[i - 1] + Fibonacci_array[i - 2];
	//	}
	//	return Fibonacci_array[n];
	//}

	// 第三种思路：第一种思路用到了数组，占用空间较多。因此，可以改进为只用三个变量。
	int Fibonacci(int n) {
		int first = 0;
		int second = 1;
		int result = first + second;
		if (n == 0)
		{
			return 0;
		}
		if (n == 1)
		{
			return 1;
		}
		for (int i = 2; i < n; i++) // 下标是从0开始的
		{
			first = second;
			second = result;
			result = first + second;
		}
		return result;
	}
};

int main_斐波那契数列(void)
{
	Solution result;
	cout << "result = " << result.Fibonacci(5) << endl;
	
	cout<<"Write By JZQ!"<<endl;
	//自动排版：ctrl+k+F
	return 0;
}