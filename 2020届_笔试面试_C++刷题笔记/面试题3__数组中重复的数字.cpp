#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

// This does the trick,正序迭代器转数组下标
inline const int iterator_to_index(vector<int> &a, vector<int>::iterator it)
{
	return it - a.begin();
}
// This does the trick,逆序迭代器转数组下标
inline const int iterator_to_index(vector<int> &a, vector<int>::reverse_iterator it)
{
	return a.rend() - it - 1;
}

/***************************************
【题目】：
在一个长度为n的数组里的所有数字都在0到n-1的范围内。
数组中某些数字是重复的，但不知道有几个数字是重复的。
也不知道每个数字重复几次。请找出数组中任意一个重复的数字。
例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，那么对应的输出是第一个重复的数字2。
输入描述：
{2,3,1,0,2,5,3}
输出描述：
2
【思路】：
1、排序：当前与后一个相等，则重复
2、哈希表：每次插入元素，判断该元素是否存在
3、下标与数字对应：将元素放到对应下标的位置上。
4、前后指针：每个元素从前找、从后找，对比位置。
***************************************/
// 思路3
static bool duplicate(vector<int> &numbers, int length, int &duplication)
{
	if (numbers.size() == 0 || length == 0)
	{
		return false;
	}

	int temp = 0;
	for (int i = 0; i < length; i++)
	{
		if (numbers[i]<0 || numbers[i]>length - 1)//有[0, n-1]范围外的数据
		{
			return false;
		}
	}

	for (int i = 0; i < length; i++)
	{
		while (i != numbers[i]) // numbers[i]的值不等于i，最多两次交换，元素numbers[i]会在i位置。
		{
			if (numbers[i] == numbers[numbers[i]])
			{// 出现重复
				duplication = numbers[i];
				return true;
			}
			else
			{// 不等于则交换
				int temp = numbers[i];
				numbers[i] = numbers[temp];
				numbers[temp] = temp;
			}
		}
	}
	// 找完了都没有找到，则没有重复的。
	return false;
}
// 思路4
static bool duplicate(vector<int> &numbers, int length)
{
	if (numbers.size() == 0 || length == 0)
	{
		return false;
	}

	int temp = 0;
	for (int i = 0; i < length; i++)
	{
		if (numbers[i]<0 || numbers[i]>length - 1)//有[0, n-1]范围外的数据
		{
			return false;
		}
	}

	auto it_front = numbers.begin();
	auto it_back = numbers.rbegin();
	for (int i = 0; i < length; i++)
	{
		it_front = find(numbers.begin(), numbers.end(), numbers[i]); // 顺序找
		it_back = find(numbers.rbegin(), numbers.rend() , numbers[i]); // 逆序找
		int index_front = iterator_to_index(numbers, it_front);
		int index_back = iterator_to_index(numbers, it_back);
		//cout << "index_front:" << index_front << endl;
		//cout << "index_back:" << index_back << endl;
		if (index_front != index_back) // 找第一个重复的；若找不重复的：index_front == index_back
		{
			cout << numbers[index_front] << endl;
			return true;
		}
	}
	// 找完了都没有找到，则没有重复的。
	return false;
}

int main_数组中重复的数字(void)
{
	vector<int> arr = { 2,3,1,0,2,5,3 };
	// 思路3
	//int duplication = 0;
	//if (duplicate(arr, arr.size(), duplication))
	//{
	//	cout << "找到：" << duplication << endl;
	//}
	//else
	//{
	//	cout << "未找到！" << endl;
	//}

	// 思路4
	if (duplicate(arr, arr.size()))
	{
		cout << "找到！" << endl;
	}
	else
	{
		cout << "未找到！" << endl;
	}


	cout << "Write By JZQ!" << endl;
	//自动排版：ctrl+k+F
	return 0;
}
