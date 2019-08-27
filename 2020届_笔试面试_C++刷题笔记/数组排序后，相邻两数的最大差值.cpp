#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

/*
给定一个数组，求数组排序后，相邻两数的最大差值。要求时间复杂度O(n)，且不能用非基于比较的排序。
比如：1 1 3 6 7.   
1与1差值为0；
1与3差值为2；
3与6差值为3；
6与7差值为1；
则最大差值为3.

思路：借用桶排序的概念，但是未进行桶排序
*/

static int bucket(long num, long len, long min, long max) 
{
	return (int)((num - min) * len / (max - min));
}

static int maxGap(int *array, const int len) 
{
	if (array == nullptr || len < 2) {
		return 0;
	}

	int minValue = INT_MAX;
	int maxValue = INT_MIN;
	for (int i = 0; i < len; i++) // 找到数组中的最小值和最大值
	{
		minValue = min(minValue, array[i]);
		maxValue = max(maxValue, array[i]);
	}
	if (minValue == maxValue) // 数组中的元素都是一种数
	{
		return 0;
	}

	vector<bool> hasNum(len + 1, false); // c c(n,t): c 包含 n 个初始化为值 t 的元素
	vector<int> maxs(len + 1, INT_MIN); // 最大的数组初始化为最小值
	vector<int> mins(len + 1, INT_MAX); // 最小的数组初始化为最大值
	int bid = 0;
	for (int i = 0; i < len; i++) 
	{
		bid = bucket(array[i], len, minValue, maxValue); // 划分桶，确定某个数是属于几号桶。bid是桶号。
		mins[bid] = hasNum[bid] ? min(mins[bid], array[i]) : array[i];
		maxs[bid] = hasNum[bid] ? max(maxs[bid], array[i]) : array[i];
		hasNum[bid] = true;
	}

	// 下面就是找：每个当前非空桶的最小值，和前一个非空桶的最大值之间的最大差值，并不断更新。
	int res = 0;
	int lastMax = maxs[0]; // 上一个非空桶的最大值。0号桶因为存放了数组元素的最小值，所以必然不为空桶。
	for (int i = 1; i <= len; i++) // 桶里找，有len+1个桶。
	{
		if (hasNum[i]) // 非空桶
		{
			res = max(res, mins[i] - lastMax);
			lastMax = maxs[i];
		}
	}

	return res;
}

int main0122052151(void)
{
	int array[] = { 1,6,5,15,3,4,2 };
	int len = sizeof(array) / sizeof(array[0]);

	cout << "最大差值：" << maxGap(array, len) << endl;
	
	cout<<"Write By JZQ!"<<endl;
	//自动排版：ctrl+k+F
	return 0;
}