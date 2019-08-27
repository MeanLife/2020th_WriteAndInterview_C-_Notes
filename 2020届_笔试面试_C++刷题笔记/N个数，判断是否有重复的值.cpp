#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void swap1(int *array, const int x, const int y)
{
	int temp = array[y];
	array[y] = array[x];
	array[x] = temp;
}

/*
一个长度为N的整形数组，数组中每个元素的取值范围是[0,n-1],
判断该数组否有重复的数，请说一下你的思路并手写代码
*/

//bool IsDuplicateNumber(int *array, int n)
//{
//	if (array == nullptr) return false;
//	int i, temp;
//	for (i = 0; i < n; i++)
//	{
//		while (array[i] != i)
//		{
//			if (array[array[i]] == array[i])// 当前位置的值和该值为下标的位置上值是否相等。
//				return true;
//			temp = array[array[i]];
//			array[array[i]] = array[i];
//			array[i] = temp;
//		}
//	}
//	return false;
//}

static bool IsDuplicateNumber(int *array, int n)
{
	if (array == nullptr) return false;
	int i;
	for (i = 0; i < n; i++)
	{
		if (array[i] != i)
		{
			if (array[array[i]] == array[i])
			{
				return true;
			}
			swap1(array, array[i], i);
		}
		else
		{
			continue;
		}
	}
	return false;
}

int main1525156(void)
{
	int *array = new int[10];
	for (int i = 0; i < 10; ++i)
	{
		array[i] = (i * 2 + 10 / 3) % 10;
		//array[i] = 9-i;
		cout << array[i] << "  ";
	}
	if (IsDuplicateNumber(array, 10))
	{
		cout << "有重复！";
	}
	else
	{
		cout << "无重复！";
	}
	
	cout<<"\nWrite By JZQ!"<<endl;
	//自动排版：ctrl+k+F
	return 0;
}