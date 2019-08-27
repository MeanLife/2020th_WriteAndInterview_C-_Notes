#include "插入法排序.h"

//时间复杂度: n²
/*
//在排序之前我们需要搞清一个思路，新插入一个数据的时候，排序过后的数组都是
//从小到大排列好的，所以我们需要从后往前查找，直到找到比我们要插入的数字还小的
//值。这个时候我们需要一个变量j作为标识
*/



template<class T>
void InsertSort(T * array, const int len)
{
	for (int i = 1; i < len; ++i)
	{
		for (int j = i - 1; j >= 0; --j)
		{
			if (array[j] > array[j + 1])
			{
				array[j] = array[j] ^ array[j + 1];
				array[j + 1] = array[j] ^ array[j + 1];
				array[j] = array[j] ^ array[j + 1];
			}
		}
	}
}


/*
template<class T>
void InsertSort(T * array, const int len)
{
	T temp = 0;
	for (int i = 1; i < len; i++)//还是n-1趟，只是这里从1开始，即第二个元素开始，前面的是有序的。
	{
		temp = array[i];//取出这个要和前面有序序列比较的元素。
		int j = 0;
		for (j = i - 1;j >= 0;j--)//这个元素的和前面有序序列比较，直到下标0
		{
			if (array[j] > temp)//将大于temp的数向后移动
			{
				array[j + 1] = array[j];
			}
			else
			{
				break;//不再比temp大了，就不移动了
			}
		}
		//移动完，就插入元素
		array[j + 1] = temp;//这里，因为j--，跳出循环时，j多减了一次
	}
}
*/
