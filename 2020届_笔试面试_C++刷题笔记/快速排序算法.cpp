#include "快速排序算法.h"

/*
它的基本思想是：以其中一个元素（一般取头元素或者末尾元素）作为标准Key，
将要排序的数据分割成独立的两部分，左边小于key，右边大于key

然后再按此方法对这两部分数据分别进行快速排序，整个排序过程可以递归进行，
以此达到整个数据变成有序序列。

//https://baike.baidu.com/item/%E5%BF%AB%E9%80%9F%E6%8E%92%E5%BA%8F%E7%AE%97%E6%B3%95/369842?fromtitle=%E5%BF%AB%E9%80%9F%E6%8E%92%E5%BA%8F%E6%B3%95&fromid=612251&fr=aladdin
*/

template<class T>
int *partition(T *array, int L, int R);

template<class T>
void swap(T * array, int x, int y);

template<class T>
void Quicksort(T *array, int L, int R)
{
	int *position = nullptr;
	if (L >= R)
	{
		return;
	}
	position = partition(array, L, R);
	Quicksort(array, L, position[0] - 1);
	Quicksort(array, position[1] + 1, R);
	delete position;
}

template<class T>
int * partition(T * array, int L, int R)
{
	int *help = new int[2];
	int key = array[R];// 记录作为枢轴(区分小的分段和大的分段)
	int lessRange = L - 1;
	int bigRange = R + 1;
	while (L < bigRange)
	{
		if (array[L] < key)
		{
			swap(array, ++lessRange, L++);
		}
		else if (array[L] > key)
		{
			swap(array, --bigRange, L);
		}
		else
		{
			L++;
		}
	}
	help[0] = lessRange + 1;
	help[1] = bigRange - 1;
	return help;
}

template<class T>
void swap(T * array, int x, int y)
{
	int temp = 0;
	temp = array[x];
	array[x] = array[y];
	array[y] = temp;
}


//template<class T>
//void Quicksort(T *array, int low, int high)
//{
//	if (low >= high)
//	{
//		return;//递归结束标志
//	}
//	int first = low;
//	int last = high;
//	int key = array[first];//用字表的第一个记录作为枢轴(区分小的分段和大的分段)
//	while (first < last)
//	{
//		while (first < last && array[last] >= key)
//		{
//			--last;
//		}
//		array[first] = array[last];/*将比key小的移到低端*/
//		while (first<last && array[first] <= key)
//		{
//			++first;
//		}
//		array[last] = array[first];/*将比key大的移到高端*/
//	}
//	array[first] = key;//重新确定枢轴的值，这里的first = last；(一定相等)
//	Quicksort(array, low, first - 1);//对左边的数据段排序
//	Quicksort(array, first + 1, high);//对右边的数据段排序
//}

