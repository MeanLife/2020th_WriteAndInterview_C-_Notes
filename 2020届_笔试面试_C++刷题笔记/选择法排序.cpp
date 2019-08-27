#include "选择法排序.h"

/*
选择排序的基本思想是：每一趟在n-i+1（i=1，2，…n-1）
个记录中选取关键字最小的记录作为有序序列中第i个记录。
基于此思想的算法主要有简单选择排序、树型选择排序和堆排序。
*/

//简单选择排序
/*
第1趟，在待排序记录r[1]~r[n]中选出最小的记录，将它与r[1]交换；
第2趟，在待排序记录r[2]~r[n]中选出最小的记录，将它与r[2]交换；
以此类推，第i趟在待排序记录r[i]~r[n]中选出最小的记录，将它与r[i]交换，
使有序序列不断增长直到全部排序完毕。所以只会循环n-1次。

n-1趟，每趟从i+1到末尾找最小元素，将它与第i个元素交换。
*/


template<class T>
void SelectSort(T * array, const int len)
{
	for (int i = 0; i < len - 1; ++i)
	{
		int minIndex = i;
		for (int j = i + 1; j < len; ++j)
		{
			minIndex = array[minIndex] <= array[j] ? minIndex : j;
		}
		if (i != minIndex)// 有更小的，则交换
		{
			array[i] = array[i] ^ array[minIndex];
			array[minIndex] = array[i] ^ array[minIndex];
			array[i] = array[i] ^ array[minIndex];
		}
	}
}



/*
template<class T>
void SelectSort(T * array, const int len)
{
	T temp = 0;
	for (int i = 0; i < len - 1; i++)//循环n-1次。最后剩下的一个元素肯定在末尾，不用排序了。
	{
		int index = i;//每一趟，假设第i个元素最小;
		for (int j = i + 1; j < len; j++)//从第i个元素的后面一个元素开始找剩余的序列中最小的值的下标。
		{//查找最小记录的位置
			if (array[j] < array[index])
			{
				index = j;
			}
		}
		if (index != i)//若无序区第一个元素不是无序区中最小元素，则进行交换
		{
			temp = array[index];
			array[index] = array[i];
			array[i] = temp;
		}
	}
}
*/