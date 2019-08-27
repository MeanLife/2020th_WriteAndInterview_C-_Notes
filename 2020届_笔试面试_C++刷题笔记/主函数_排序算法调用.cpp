#include <iostream>
#include <string>
#include <cmath>
#include "选择法排序.cpp"//因为使用的是模板函数，所以调用cpp文件。
#include "冒泡法排序.cpp"//因为使用的是模板函数，所以调用cpp文件。
#include "插入法排序.cpp"//因为使用的是模板函数，所以调用cpp文件。
#include "希尔排序算法.cpp"//因为使用的是模板函数，所以调用cpp文件。
#include "快速排序算法.cpp"//因为使用的是模板函数，所以调用cpp文件。
#include "归并算法排序.cpp"//因为使用的是模板函数，所以调用cpp文件。
using namespace std;


// 遍历打印
template<class T>
void prinft_array(T &array)
{
	for (int i = 0; i < sizeof(array)/sizeof(array[0]); i++)
	{
		cout << "array[" << i << "]:" << array[i] << endl;
	}
}

// 选择法测试案例
int main01(void)
{
	//int array[] = { 10, 50, 60, 20, 30, 40, 80, 90 };
	char array[] = { 'f', 'a', 'd', 'b', 'c'};
	int len = sizeof(array) / sizeof(array[0]);
	cout << "选择法排序之前：" << endl;
	prinft_array(array);
	//排序：
	SelectSort(array,len);//在外部文件#include "选择法排序.h"中
	cout << "选择法排序之后：" << endl;
	prinft_array(array);
	
	cout << "JZQ!" << endl;
	return 0;
	//自动排版：ctrl+K,ctrl+F
}

//冒泡法测试案例
int main02(void)
{
	int array[] = { 10, 50, 60, 20, 30, 40, 80, 90 };
	//char array[] = { 'f', 'a', 'd', 'b', 'c' };
	int len = sizeof(array) / sizeof(array[0]);
	cout << "排序之前" << endl;
	prinft_array(array);
	//排序：
	BubbleSort(array, len);//在外部文件#include "选择法排序.h"中
	cout << "冒泡法排序之后" << endl;
	prinft_array(array);

	cout << "JZQ!" << endl;
	return 0;
	//自动排版：ctrl+K,ctrl+F
}

//插入法测试案例
int main03(void)
{
	int array[] = { 10, 50, 60, 20, 30, 40, 80, 90 };
	//char array[] = { 'f', 'a', 'd', 'b', 'c' };
	int len = sizeof(array) / sizeof(array[0]);
	cout << "排序之前" << endl;
	prinft_array(array);
	//排序：
	InsertSort(array, len);//在外部文件#include "选择法排序.h"中
	cout << "插入法排序之后" << endl;
	prinft_array(array);

	cout << "JZQ!" << endl;
	return 0;
	//自动排版：ctrl+K,ctrl+F
}

//希尔算法测试案例
int main04(void)
{
	int array1[] = { 10, 50, 60, 20, 12, 52, 62, 22, 14, 54, 64, 24 };
	char array2[] = { 'a', 'd', 'b', 'c'};
	int len = sizeof(array2) / sizeof(array2[0]);
	cout << "排序之前" << endl;
	prinft_array(array2);
	//排序：
	ShellSort(array2, len);//在外部文件#include "选择法排序.h"中
	cout << "希尔算法排序之后" << endl;
	prinft_array(array2);

	cout << "JZQ!" << endl;
	system("pause");
	return 0;
	//自动排版：ctrl+K,ctrl+F
}

//快速排序算法测试案例
int main05(void)
{
	int array[] = { 90, 50, 60, 20, 30, 40, 80, 10 };
	//char array[] = { 'f', 'a', 'd', 'b', 'c' };
	int len = sizeof(array) / sizeof(array[0]);
	int low = 0;//指向开头
	int high = len - 1;//指向末尾
	cout << "排序之前" << endl;
	prinft_array(array);
	//排序：
	Quicksort(array, low, high);
	cout << "快速法排序之后" << endl;
	prinft_array(array);

	cout << "JZQ!" << endl;
	return 0;
	//自动排版：ctrl+K,ctrl+F
}

//归并算法测试案例
int main06(void)
{
	int array[] = { 90, 50, 60, 20, 30, 40, 80, 10 };
	//char array[] = { 'f', 'a', 'd', 'b', 'c' };
	int len = sizeof(array) / sizeof(array[0]);
	cout << "排序之前" << endl;
	prinft_array(array);
	//排序：
	MergeSort(array, len);
	cout << "归并法排序之后" << endl;
	prinft_array(array);

	cout << "JZQ!" << endl;
	return 0;
	//自动排版：ctrl+K,ctrl+F
}