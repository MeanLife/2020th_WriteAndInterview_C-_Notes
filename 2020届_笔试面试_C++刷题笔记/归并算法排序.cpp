#include "归并算法排序.h"

/*
归并排序法（Merge Sort，以下简称MS）是分治法思想运用的一个典范。其主要算法操作可以分为以下步骤：
Step 1：将n个元素分成两个含n/2元素的子序列
Step 2：用MS将两个子序列递归排序（最后可以将整个原序列分解成n个子序列）
Step 3：合并两个已排序好的序列
*/

template<class T>
void Merge(T * array, int L, int mid, int R);
template<class T>
void MSort(T * array, int L, int R);

template<class T>
void MergeSort(T *array, int len)// O(n*logn)
{
	if (array == nullptr || len < 2)
	{
		return;
	}
	MSort(array, 0, len - 1);
}

//每次分为两路 当只剩下一个元素时，就不需要在划分
template<class T>
void MSort(T * array, int L, int R)
{
	if (L == R)
	{
		return;
	}
	int mid = L + ((R - L) >> 1);
	MSort(array, L, mid);
	MSort(array, mid + 1, R);
	Merge(array, L, mid, R);
}

template<class T>
void Merge(T * array, int L, int mid, int R)
{
	T * help = new T[R - L + 1];
	int i = 0;
	int p1 = L;
	int p2 = mid + 1;
	while (p1 <= mid && p2 <= R) // 这里跳出循环，说明p1或p2有一个越界。
	{
		help[i++] = array[p1] < array[p2] ? array[p1++] : array[p2++];
	}
	while (p1 <= mid)
	{
		help[i++] = array[p1++];
	}
	while (p2 <= R)
	{
		help[i++] = array[p2++];
	}
	for (int j = 0; j < i; j++)// i当计数器，它本身就是要比下标大1
	{
		array[L + j] = help[j];
	}
	delete help;
}

/*
template<class T>
void Merge(T src[], T des[], int low, int mid, int high);
template<class T>
void MSort(T src[], T des[], int low, int high, int max);

template<class T>
void MergeSort(T *array, int len)// O(n*logn)
{
	MSort(array, array, 0, len - 1, len);
}

//每次分为两路 当只剩下一个元素时，就不需要在划分
template<class T>
void MSort(T src[], T des[], int low, int high, int max)
{
	if (low == high) //只有一个元素，不需要归并，结果赋给des[low]
	{
		des[low] = src[low];
	}
	else //如果多个元素，进行两路划分
	{
		int mid = (low + high) / 2;
		T* space = new T[max];

		//递归进行两路，两路的划分 
		//当剩下一个元素的时，递归划分结束，然后开始merge归并操作
		if (space != nullptr)
		{
			MSort(src, space, low, mid, max);
			MSort(src, space, mid + 1, high, max);
			Merge(space, des, low, mid, high); //调用归并函数进行归并
		}
		delete[]space;
	}
}

template<class T>
void Merge(T src[], T des[], int low, int mid, int high)
{
	int i = low;
	int j = mid + 1;
	int k = low;

	while ((i <= mid) && (j <= high)) //将小的放到目的地中
	{
		if (src[i] < src[j])
		{
			des[k++] = src[i++];
		}
		else
		{
			des[k++] = src[j++];
		}
	}

	while (i <= mid)  //若还剩几个尾部元素
	{
		des[k++] = src[i++];
	}

	while (j <= high) //若还剩几个尾部元素
	{
		des[k++] = src[j++];
	}
}

*/