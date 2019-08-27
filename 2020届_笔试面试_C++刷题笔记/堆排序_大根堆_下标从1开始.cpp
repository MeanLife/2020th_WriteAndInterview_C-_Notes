#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;//堆排序的核心是建堆,传入参数为数组，根节点位置，数组长度

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

// 建立大根堆，下标从1开始，下标0位为填充位。
void Heap_build_1(int * array, int heapSize)
{
	for (int root = heapSize / 2; root >= 1; --root)
	{
		int rootElement = array[root];
		int child = 2 * root;
		while (child <= heapSize)
		{
			if (child + 1 <= heapSize) // 右孩子存在
			{
				child = array[child] >= array[child + 1] ? child : (child + 1);
			}
			
			if (rootElement >= array[child])
			{
				break;
			}
			swap(array, child, child / 2);
			child *= 2;
		}
	}
}
void heapify_1(int *array, int root, int heapSize)
{
	int child = root * 2;
	while (child <= heapSize) // 左孩子存在
	{
		if (child + 1 <= heapSize) // 右孩子存在
		{
			child = array[child + 1] > array[child] ? (child + 1) : child;
		}

		if (array[root] >= array[child])
		{
			break;
		}
		swap(array, child, root);
		root = child;
		child = root * 2;
	}
}
void heapSort_1(int *array, const int len)
{
	if (array == nullptr || len < 2)
	{
		return;
	}
	// 建立大根堆，从下标1开始。
	Heap_build_1(array, len - 1);

	cout << "大根堆:" << endl;
	prinft_array(array, len);
	cout << endl;

	// 下面是排序
	int size = len;
	swap(array, 1, --size); // 交换第一个节点和最后一个节点
	while (size > 1)
	{
		heapify_1(array, 1, size - 1); // size现在是减去了1后的，所以相当于末尾的元素被丢掉了。
		swap(array, 1, --size);
	}
}



int main04515605(void)
{
	int array[] = { 0, 90, 50, 60, 20, 70, 30, 40, 80, 10 };
	int rightArray[] = { 0, 10, 20, 30, 40, 50, 60, 70, 80, 90 };
	int len = sizeof(array) / sizeof(array[0]);
	cout << "排序之前" << endl;
	prinft_array(array, len);
	//排序：
	heapSort_1(array, len);
	//Heap_sort(array, len);
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