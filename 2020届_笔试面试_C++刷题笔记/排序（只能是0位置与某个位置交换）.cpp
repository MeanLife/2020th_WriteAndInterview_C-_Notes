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

static void sort(int* array, int len) {
	for (int i = 0; i < len - 1; i++)
	{
		int index = 0;
		for (int j = 0; j < len - i; j++)
		{
			if (array[j] > array[index])
			{
				index = j;
			}
		}
		swap(array, 0, index); // 只能是0位置与某个位置交换
		swap(array, 0, len - i - 1); // 只能是0位置与某个位置交换
	}
}

int main0124541_1052(void)
{
	int array[] = { 5, 8, 6, 2, 7, 3, 4, 0, 1 };
	int rightArray[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
	int len = sizeof(array) / sizeof(array[0]);

	cout << "排序之前" << endl;
	prinft_array(array, len);
	//排序：
	sort(array, len);//在外部文件#include "选择法排序.h"中
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
	cout<<"Write By JZQ!"<<endl;
	//自动排版：ctrl+k+F
	return 0;
}