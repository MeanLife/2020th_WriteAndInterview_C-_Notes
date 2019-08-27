#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

// 遍历打印
static void prinft_array(int * array, int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << "array[" << i << "]:" << array[i] << endl;
	}
}

static void swap(int * array, int x, int y)
{
	int temp = 0;
	temp = array[x];
	array[x] = array[y];
	array[y] = temp;
}

//void bucketSort(int * array, const int len)
//{
//	int maxNum = INT_MIN;
//	for (int i = 0; i < len; ++i)
//	{
//		maxNum = max(maxNum, array[i]);
//	}
//
//	vector<int> bucket;
//	for (int i = 0; i < maxNum + 1; ++i)
//	{
//		// bucket[i] = 0; // 下标是修改不是插入
//		bucket.push_back(0);
//	}
//
//	for (int i = 0; i < len; ++i)
//	{
//		bucket[array[i]]++;
//	}
//
//	// 排序，将元素放回array
//	int i = 0;
//	for (unsigned j = 0; j < bucket.size(); ++j)
//	{
//		for ( ;bucket[j] > 0 ; bucket[j]--)
//		{
//			array[i++] = j;
//		}
//	}
//}

void bucketSort(int *array, int len)
{
	if (array == nullptr || len < 2) 
	{
		return;
	}
	// 找出元素的取值范围[0~n],则桶的个数为n+1.
	int maxNum = INT_MIN;
	for (int i = 0; i < len; i++) 
	{
		maxNum = max(maxNum, array[i]);
	}
	// 创建桶，并将数组元素作为下标的桶进行计数
	vector<int> bucket;
	for (int i = 0; i < maxNum + 1; ++i)
	{
		bucket.push_back(0); // 对桶进行初始化
	}
	for (int i = 0; i < len; i++) 
	{
		bucket[array[i]]++;
	}
	// 排序，将元素放回array
	int i = 0;
	for (unsigned j = 0; j < bucket.size(); j++) 
	{
		while (bucket[j]-- > 0) 
		{
			array[i++] = j;
		}
	}
}


int main1112233(void)
{
	int array[] = { 90, 50, 60, 20, 70, 30, 40, 80, 10 };
	int rightArray[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90 };
	int len = sizeof(array) / sizeof(array[0]);

	cout << "排序之前" << endl;
	prinft_array(array, len);

	//排序：
	bucketSort(array, len);

	cout << "排序之后" << endl;
	prinft_array(array, len);

	int flag = 0;
	for (int i = 0; i < len; i++)
	{
		if (array[i] != rightArray[i])
		{
			flag = 1;
		}
	}
	if (flag == 0)
	{
		cout << "\n排序成功！\n" << endl;
	}
	else
	{
		cout << "\n排序失败！\n" << endl;
	}

	cout << "Write By JZQ!" << endl;
	//自动排版：ctrl+k+F
	return 0;
}