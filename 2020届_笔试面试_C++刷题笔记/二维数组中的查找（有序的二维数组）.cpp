#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

/*
在一个二维数组中（每个一维数组的长度相同），
每一行都按照从左到右递增的顺序排序，
每一列都按照从上到下递增的顺序排序。
请完成一个函数，输入这样的一个二维数组和一个整数，
判断数组中是否含有该整数。

【思路】：
因为是有序的，那么按递增或递减方向遍历即可（以四个角随便哪个位置开始都可以）
*/

static void printArray(vector<vector<int>> array)
{
	for (unsigned i = 0; i < array.size(); ++i)
	{
		for (vector<int>::iterator it = array[i].begin(); it != array[i].end(); it++)
		{
			cout << *it << "  ";
		}
		cout << endl;
	}
}

/***************************************
【思路】：
因为是有序的，那么按递增或递减方向遍历即可（以四个角随便哪个位置开始都可以）
***************************************/
static bool function(vector<vector<int>> array, const int key)
{
	int temp = array[0][array[0].size() - 1];
	int row = 0;
	int colum = array[0].size() - 1;
	while (row <= array.size() - 1 && colum >= 0)
	{
		temp = array[row][colum];
		if (temp > key)
		{
			colum--;
		}
		else if (temp < key)
		{
			row++;
		}
		else
		{
			return true;
		}
	}

	return false;
}

int main_01(void)
{
	vector<vector<int>> Input(4);
	Input[0].push_back(1);
	Input[0].push_back(2);
	Input[0].push_back(8);
	Input[0].push_back(9);
	Input[1].push_back(2);
	Input[1].push_back(4);
	Input[1].push_back(9);
	Input[1].push_back(12);
	Input[2].push_back(4);
	Input[2].push_back(7);
	Input[2].push_back(10);
	Input[2].push_back(13);
	Input[3].push_back(6);
	Input[3].push_back(8);
	Input[3].push_back(11);
	Input[3].push_back(15);
	
	int key = 1;

	printArray(Input);

	if (function(Input, key))
	{
		cout << "\n找到:"<< key <<"！\n";
	}

	else
	{
		cout << "\n未找到:" << key << "！\n";
	}
	//自动排版：ctrl+k+F
	return 0;
}