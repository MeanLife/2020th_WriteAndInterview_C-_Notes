#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
/*
基本思想：将整数按位数切割成不同的数字，然后按每个位数分别比较。
具体做法：将所有待比较数值统一为同样的数位长度，数位较短的数前面补零。
然后，从最低位开始，依次进行一次排序。这样从最低位排序一直到最高位排序完成以后, 数列就变成一个有序序列。
1. 按照个位数进行排序。
2. 按照十位数进行排序。
3. 按照百位数进行排序。
......
*/

// 打印二维数组vector<vector<int>> array
static void print_2D_Array(vector<vector<int>> array)
{
	for (unsigned i = 0; i < array.size(); ++i)
	{
		for (vector<int>::iterator it = array[i].begin(); it != array[i].end(); it++)
		{
			cout << *it << "  ";
		}
		cout << endl;
	}
	cout << endl;
}


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

// 求数组中所有元素的最大数据的位数,决定排序次数
int maxbits(int *arr, const int len) 
{
	int maxNum = INT_MIN;
	for (int i = 0; i < len; i++) 
	{
		maxNum = max(maxNum, arr[i]);
	}
	int res = 0;
	while (maxNum != 0) 
	{
		res++;
		maxNum /= 10;
	}
	return res;
}
//void radixSort(int *array, int len) //基数排序
//{
//	const int radix = 10;
//	int bitNum = maxbits(array, len);
//	int *bucket = new int[len];
//	int count[radix]; //计数器
//	int i, j, k;
//	int basic = 1;
//	for (i = 1; i <= bitNum; i++) //进行d次排序
//	{
//		for (j = 0; j < radix; j++)
//		{
//			count[j] = 0; //每次分配前清空计数器
//		}
//		for (j = 0; j < len; j++) // 将所有元素的第i位进行桶排序
//		{
//			k = (array[j] / basic) % 10; //统计每个桶中的记录数
//			count[k]++;
//		}
//		for (j = 1; j < radix; j++) 
//		{
//			count[j] = count[j - 1] + count[j]; //将count中的位置依次分配给每个桶
//		}
//		for (j = len - 1; j >= 0; j--) //将所有桶中记录依次收集到tmp中
//		{
//			k = (array[j] / basic) % 10;
//			bucket[count[k] - 1] = array[j];
//			count[k]--;
//		}
//		for (j = 0; j < len; j++) //将临时数组的内容复制到array中
//		{
//			array[j] = bucket[j];
//		}
//		basic = basic * 10;
//	}
//}
void radixSort_2(int *array, int len) //基数排序
{
	const int radix = 10;
	int basic = 1;
	int bitNum = maxbits(array, len);
	vector<vector<int>> bucket(radix);
	int i, j, k;
	for (i = 1; i <= bitNum; ++i)
	{
		for (j = 0; j < bucket.size(); ++j)
		{
			bucket[j].clear();
		}
		for (j = 0; j < len; ++j)
		{
			k = (array[j] / basic) % 10;
			bucket[k].push_back(array[j]);
		}

		int index = 0;
		for (j = 0; j < bucket.size(); ++j)
		{
			for (k = 0; k < bucket[j].size(); ++k)
			{
				array[index++] = bucket[j][k];
			}
		}

		basic *= 10;
	}
}

//void radixSort_2(int *array, int len) //基数排序
//{
//	const int radix = 10;
//	int bitNum = maxbits(array, len);
//	vector<vector<int>> bucket(radix);
//	int i, j, k;
//	int basic = 1;
//	for (i = 1; i <= bitNum; i++) //进行d次排序
//	{
//		for (j = 0; j < radix; j++)
//		{
//			bucket[j].clear(); //每次分配前清空计数器
//		}
//		for (j = 0; j < len; j++) // 将所有元素的第i位进行桶排序
//		{
//			k = (array[j] / basic) % 10; //统计每个桶中的记录数
//			bucket[k].push_back(array[j]);
//		}
//		int index = 0;
//		for (j = 0; j < radix; j++)
//		{
//			for (k = 0; k < bucket[j].size(); k++)
//			{
//				array[index++] = bucket[j][k];
//			}
//		}
//		basic = basic * 10;
//	}
//}


int main122311123(void)
{
	int array[] = { 92, 50, 60, 23, 70, 35, 40, 88, 10 };
	int rightArray[] = { 10, 23, 35, 40, 50, 60, 70, 88, 92 };
	int len = sizeof(array) / sizeof(array[0]);

	cout << "排序之前" << endl;
	prinft_array(array, len);

	//排序：
	radixSort_2(array, len);

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