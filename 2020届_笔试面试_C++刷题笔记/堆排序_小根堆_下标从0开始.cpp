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

// 可以从一个空的大根堆开始建立大根堆,index从0开始。
void minHeap_build_0(int *array, int index)
{
	while (array[index] < array[(index - 1) / 2]) // 插入位置的值比其父节点的值大，则交换两个值，并向上循环。
	{	// (0-1)/2 = 0，所以最后会判断：array[0] > array[0] ?  跳出循环
		swap(array, index, (index - 1) / 2);
		index = (index - 1) / 2;
	}
}
void minheapify_0(int *array, int root, int heapSize)
{
	int child = root * 2 + 1;
	while (child < heapSize) // 左孩子存在
	{
		if (child + 1 < heapSize) // 右孩子存在
		{
			child = array[child + 1] < array[child] ? (child + 1) : child;
		}

		if (array[root] <= array[child])
		{
			break;
		}
		swap(array, child, root);
		root = child;
		child = root * 2 + 1;
	}
}
void minheapSort_0(int *array, const int len)
{
	if (array == nullptr || len < 2)
	{
		return;
	}
	// 建立大根堆，从下标0开始。
	for (int i = 0; i < len; i++)
	{
		minHeap_build_0(array, i);
	}
	// 下面是排序
	int size = len;
	swap(array, 0, --size); // 交换第一个节点和最后一个节点
	while (size > 0)
	{
		minheapify_0(array, 0, size); // size现在是减去了1后的，所以相当于末尾的元素被丢掉了。
		swap(array, 0, --size);
	}
}



int main2342342343(void)
{
	int array[] = { 90, 50, 60, 20, 70, 30, 40, 80, 10 };
	int rightArray[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90 };
	int len = sizeof(array) / sizeof(array[0]);
	cout << "排序之前" << endl;
	prinft_array(array, len);
	//排序：
	minheapSort_0(array, len);
	cout << "排序之后" << endl;
	prinft_array(array, len);
	reverse(array, array + len);
	//sort(array, array + len);
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