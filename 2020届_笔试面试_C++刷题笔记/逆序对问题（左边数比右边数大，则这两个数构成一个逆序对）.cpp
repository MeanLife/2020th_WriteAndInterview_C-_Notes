#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

/*
逆序对问题：在一个数组中，左边数如果比右边数大，则这两个数构成一个逆序对，请打印所有逆序对。

思路：与小和问题类似，使用类似归并排序的算法。

逆序对的求解思路和归并排序很像，尝试写出分治三部曲：
划分问题：将原序列分解成尽可能长度相等的两个子序列
递归过程：统计左子序列和右子序列的逆序对
合并问题：统计左右子序列合并后的逆序对
*/

static int merge(vector<int> &array, int L, int mid, int R)
{
	int *help = new int[R - L + 1];
	int p1 = L;
	int p2 = mid + 1;
	int i = 0;
	int ret = 0;
	while (p1 <= mid && p2 <= R)
	{
		ret += array[p1] > array[p2] ? (mid - p1 + 1) : 0;
		if (array[p1] > array[p2]) // 打印逆序对
		{
			for (int j = p1; j <= mid; ++j)
			{
				cout << "(" << array[j] << "," << array[p2] << ")" << endl;
			}
		}
		help[i++] = array[p1] <= array[p2] ? array[p1++] : array[p2++];
	}
	while (p1 <= mid)
	{
		help[i++] = array[p1++];
	}
	while (p2 <= R)
	{
		help[i++] = array[p2++];
	}

	for (int j = 0; j < i; ++j)
	{
		array[L + j] = help[j];
	}

	delete[]help;
	help = nullptr;
	//cout << "ret : " << ret << endl;
	//cout << endl;
	return ret;
}

static int mergeSort(vector<int> &array, int L, int R)
{
	if (L >= R)
	{
		return 0;
	}
	int mid = L + ((R - L) / 2);
	return (mergeSort(array, L, mid)     //左侧排序过程中的逆序对个数
		+ mergeSort(array, mid + 1, R)	 //右侧排序过程中的逆序对个数
		+ merge(array, L, mid, R));		 //合并过程中的逆序对个数
}
static int reversePair(vector<int> &array)
{
	if (array.size() < 2)
	{
		return 0;
	}
	return mergeSort(array, 0, array.size() - 1);
}


int main2111525231(void)
{
	//vector<int> array = { 3,1,4,5,2 };
	vector<int> array = { -1, 3, 3, 5, 5, 41, 5435, -11, 3423, 4432, -4421, 34432 };

	int sum = reversePair(array);
	cout << "逆序对个数为：sum = " << sum << endl;
	
	cout<<"Write By JZQ!"<<endl;
	//自动排版：ctrl+k+F
	return 0;
}