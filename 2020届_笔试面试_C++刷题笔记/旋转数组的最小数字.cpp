#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <climits>
using namespace std;

/***************************************
题目描述
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。
例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。
NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
【思路】：
本题的一个简单算法就是从左到右遍历，由于是递增的，直到找到一个小的数就可以停止了。
***************************************/
class Solution {
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		if (rotateArray.size() == 0)
		{
			return 0;
		}
		//int min = INT_MAX; // 这种方式要找N次，
		//for (auto it : rotateArray)
		//{
		//	if (min > it)
		//	{
		//		min = it;
		//	}
		//}
		//return min;

		// 由于是递增的，直到找到一个小的数就可以停止了。
		for (int i = 0; i < rotateArray.size() - 1; i++)
		{
			if (rotateArray[i] > rotateArray[i + 1]) // 只要找到一个后面比前面小的，那么这个值就是最小的
			{
				return rotateArray[i + 1];
			}
		}
		return rotateArray[0];  //没有逆序，且不为空，则第一个元素最小
	}
};


int main_旋转数组的最小数字(void)
{


	
	cout<<"Write By JZQ!"<<endl;
	//自动排版：ctrl+k+F
	return 0;
}