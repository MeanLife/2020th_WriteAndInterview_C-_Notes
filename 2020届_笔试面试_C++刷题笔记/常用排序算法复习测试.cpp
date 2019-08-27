#include <iostream>
#include <string>
#include <cmath>
#include <vector>
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

// 选择法
static void Sort(int * array, const int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		int minindex = i;
		// 方法一：
		//for (int j = i + 1; j < len; j++)
		//{
		//	if (array[minindex] >= array[j])
		//	{
		//		minindex = j;
		//	}
		//}
		//if (minindex != i)
		//{
		//	swap(array, minindex, i);
		//}

		// 方法二：
		for (int j = i + 1; j < len; ++j)
		{
			if (array[minindex] >= array[j])
			{
				swap(array, minindex, j);
			}
		}
	}
}


// 冒泡法
//static void Sort(int * array, const int len)
//{
//	for (int i = 0; i < len - 1; ++i)
//	{
//		int flag = 0;
//		for (int j = 0; j < len - 1 - i; ++j)
//		{
//			if (array[j] >= array[j + 1])
//			{
//				flag = 1;
//				swap(array, j, j + 1);
//			}
//		}
//		if (flag == 0)
//		{
//			return;
//		}
//	}
//}

// 插入法1
//static void Sort(int * array, const int len)
//{
//	for (int i = 1; i < len; ++i)
//	{
//		for (int j = i - 1; j >= 0; --j)
//		{
//			if (array[j] > array[j + 1])
//			{
//				swap(array, j, j + 1);
//			}
//		}
//	}
//}

// 插入法2
//void Sort(int * array, const int len)
//{
//	for (int i = 1; i < len; ++i)
//	{
//		int temp = array[i];
//		int j = i - 1;
//		for ( ; j >= 0; --j)
//		{
//			if (array[j] > temp)
//			{
//				array[j + 1] = array[j];
//			}
//			else
//			{
//				break;
//			}
//		}
//		array[j + 1] = temp;
//	}
//}

// 归并法排序
//static void Merge(int * array, int L, int mid, int R)
//{
//	int *help = new int[R - L + 1];
//	int p1 = L;
//	int p2 = mid + 1;
//	int i = 0;
//	while (p1 <= mid && p2 <= R)
//	{
//		help[i++] = array[p1] <= array[p2] ? array[p1++] : array[p2++];
//	}
//	while (p1 <= mid)
//	{
//		help[i++] = array[p1++];
//	}
//	while (p2 <= R)
//	{
//		help[i++] = array[p2++];
//	}
//
//	for (int j = 0; j < i; ++j)
//	{
//		array[L + j] = help[j];
//	}
//
//	delete []help;
//	help = nullptr;
//}
//static void MergeSort(int *array, int L, int R)
//{
//	if (L >= R)
//	{
//		return;
//	}
//	int mid = L + (R - L) / 2;
//	MergeSort(array, L, mid);
//	MergeSort(array, mid + 1, R);
//	Merge(array, L, mid, R);
//}
//static void Sort(int *array, const int len)
//{
//	MergeSort(array, 0, len - 1);
//}

// 快速排序
//int * partition(int *array, int L, int R)
//{
//	int *help = new int[2];
//	int lessRange = L - 1;
//	int bigRange = R + 1;
//	int key = array[R];
//	while (L < bigRange)
//	{
//		if (array[L] < key)
//		{
//			swap(array, L++, ++lessRange);
//		}
//		else if (array[L] > key)
//		{
//			swap(array, L, --bigRange);
//		}
//		else
//		{
//			L++;
//		}
//	}
//	cout << endl;
//	prinft_array(array, 9);
//	cout << endl;
//	help[0] = lessRange;
//	help[1] = bigRange;
//	return help;
//}
//void Quicksort(int * array, int L, int R)
//{
//	if (L >= R)
//	{
//		return;
//	}
//	int * midPoisition = nullptr;
//	midPoisition = partition(array, L, R);
//	Quicksort(array, L, midPoisition[0]);
//	Quicksort(array, midPoisition[1], R);
//	if (midPoisition != nullptr)
//	{
//		delete midPoisition;
//		midPoisition = nullptr;
//	}
//}
//void Sort(int * array, const int len)
//{
//	if (array == nullptr || len < 2)
//	{
//		return;
//	}
//	Quicksort(array, 0, len - 1);
//}

// 希尔排序算法
//void Sort(int * array, const int len)
//{
//	if (array == nullptr || len < 2)
//	{
//		return;
//	}
//
//	int gap = len;
//	do 
//	{
//		gap = gap / 3 + 1; // gap 最后肯定等于1
//		for (int i = gap; i < len; i += gap)
//		{
//			int temp = array[i];
//			int j = i - gap;
//			for ( ; j >= 0; j -= gap)
//			{
//				if (array[j] > temp)
//				{
//					array[j + gap] = array[j];
//				}
//				else
//				{
//					break;
//				}
//			}
//			array[j + gap] = temp;
//		}
//	} while (gap > 1);
//}


int main_常用排序(void)
{
	int array[] = { 90, 50, 60, 20, 70, 30, 40, 80, 10 };
	int rightArray[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90 };
	int len = sizeof(array) / sizeof(array[0]);

	cout << "排序之前" << endl;
	prinft_array(array, len);
	//排序：
	Sort(array, len);//在外部文件#include "选择法排序.h"中
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