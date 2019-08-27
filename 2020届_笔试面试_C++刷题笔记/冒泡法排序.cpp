#include "冒泡法排序.h"

// n-1趟，每趟用第i个数和后面的比较，后面的大，则交换

/*
template<class T>
void BubbleSort(T * array, const int len)
{
	for (int i = 0; i < len - 1; ++i)
	{
		for (int j = i + 1; j < len; ++j)
		{
			if (array[i] > array[j])
			{
				array[i] = array[i] ^ array[j];
				array[j] = array[i] ^ array[j];
				array[i] = array[i] ^ array[j];
			}
		}
	}
}
*/


template<class T>
void BubbleSort(T * array, const int len)
{
	for (int i = 0; i < len - 1; ++i)
	{
		int flag = 0;
		for (int j = 0; j < len - i - 1; ++j)
		{
			if (array[j] > array[j + 1])
			{
				array[j] = array[j + 1] ^ array[j];
				array[j + 1] = array[j + 1] ^ array[j];
				array[j] = array[j + 1] ^ array[j];
				flag = 1;
			}
		}
		if (flag == 0)// 优化：若某一趟，没有执行交换，则表明数据已经有序了。
		{
			return;
		}
	}
}