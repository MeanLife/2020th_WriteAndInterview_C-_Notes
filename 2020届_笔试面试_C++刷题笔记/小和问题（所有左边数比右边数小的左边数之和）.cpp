#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

/*
在一个数组中，每一个数左边比当前数小的数累加起来，叫作这个数组的小和。
例如：1 3 4 2 5。
1左边比1小的数：没有
3左边比3小的数：1
4左边比4小的数：1、3
2左边比2小的数：1
5左边比5小的数：1、3、4、2
小和：1+1+3+1+1+3+4+2 = 16。

笨方法：
每个数遍历其左边并依次比较，O(n的平方)。

优化方法：
类似归并排序的Merge过程，Merge过程中记录小和并返回小和。
每次Merge过程，找到左边数比右边多少个数小，则记录几次。

小和的求解思路和归并排序很像，尝试写出分治三部曲：
划分问题：将原序列分解成尽可能长度相等的两个子序列
递归过程：统计左子序列和右子序列的小和
合并问题：统计左右子序列合并后的小和
*/

static int merge(vector<int> &array, int L, int mid, int R)
{
	vector<int> help(R - L + 1);
	int p1 = L;
	int p2 = mid + 1;
	int i = 0;
	int ret = 0;
	while (p1 <= mid && p2 <= R)
	{
		ret += array[p1] < array[p2] ? (R - p2 + 1) * array[p1] : 0;
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

	cout << "ret : " << ret << endl;
	cout << endl;
	return ret;
}

static int mergeSort(vector<int> &array, int L, int R)
{
	if (L >= R) 
	{
		return 0;
	}
	int mid = L + ((R - L) / 2);
	return (mergeSort(array, L, mid)     //左侧排序过程中的小和
		+ mergeSort(array, mid + 1, R)	 //右侧排序过程中的小和
		+ merge(array, L, mid, R));		 //合并过程中的小和
}
static int smallSum(vector<int> &array)
{
	if (array.size() < 2) 
	{
		return 0;
	}
	return mergeSort(array, 0, array.size() - 1);
}

int main12312312141(void)
{
	vector<int> array = { 1 , 3 , 4 , 2 , 5 };
	int sum = smallSum(array);

	cout << "小和为：sum = " << sum << endl;

	cout<<"Write By JZQ!"<<endl;
	//自动排版：ctrl+k+F
	return 0;
}