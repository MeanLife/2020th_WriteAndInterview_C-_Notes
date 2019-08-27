#include<iostream>
#include <list>
#include <vector>
using namespace std;

/*
题目：
现在一共有N个任务，每个任务，每个任务需要pi的时间完成执行。同时，任务之间会有依赖关系，比如：
任务1依赖任务2、3，则1必须在2、3执行完之后才能执行。每次只能执行一个任务，现在希望最小化任务
的平均返回时长，一个任务的返回时长定义为任务执行完成时刻减去平台接收任务的时刻。在0时刻，所有
N个任务都已经被接收。
例如：
输入：
5 6				5个任务，6个依赖关系
1 2 1 1 1		第i个任务的处理时间pi
1 2				接下来6行代表6个依赖关系，第1行：2依赖1,即2必须在1执行完后才能执行
1 3
1 4
2 5 
3 5
4 5
输出：
1 3 4 2 5		执行任务的编号，先执行1，再执行3，。。。。4  2  5.
*/

static void printArray(vector<vector<int>> temp)
{
	for (int i = 0; i < temp.size(); ++i)
	{
		cout << i << " : ";
		for (int j = 0; j < temp[i].size(); ++j)
		{
			cout << temp[i][j] << " ";
		}
		cout << endl;
	}
}

int findMinTimeTask(vector<vector<int>> &temp, vector<int> pi)
{
	int minIndex = 0; // 初始化为时间最长的任务
	for (int i = 0; i < pi.size(); i++)
	{
		minIndex = pi[minIndex] > pi[i] ? minIndex : i;
	}
	minIndex += 1;
	for (int i = 0; i < 6; i++)
	{
		if (temp[i].empty())
		{
			minIndex = pi[i - 1] < pi[minIndex - 1] ? i : minIndex;
		}
	}
	return minIndex;
}

void deleteTask(vector<vector<int>> &temp, int minIndex)
{
	for (int i = 0; i < temp.size(); i++)
	{
		for (int j = 0; j < temp[i].size(); j++)
		{
			if (temp[i][j] == minIndex)
			{
				cout << "*(temp[i].begin() + j) : " << *(temp[i].begin() + j) << endl;
				temp[i].erase(temp[i].begin() + j);
			}
		}
	}
}

int main_adasdwerdxczxcdf(void)
{
	int n = 5;
	int m = 6;
	vector<int> pi = { 1,2,1,1,1 };
	int rely[6][2] = { {1,2},{1,3},{1,4},{2,5},{3,5},{4,5} };
	vector<vector<int>> temp(6);
	temp[0].push_back(-1);
	for (int i = 0; i < 6; ++i)
	{
		cout << rely[i][1] << "  " << rely[i][0] << endl;
		temp[rely[i][1]].push_back(rely[i][0]);
	}
	printArray(temp);

	vector<int> output;
	int index = 0;
	int minIndex = 0;
	for (int i = 0; i < n; i++)
	{
		minIndex = findMinTimeTask(temp, pi);
		cout << "minIndex : " << minIndex << endl;

		output.push_back(minIndex);

		temp[minIndex].push_back(-1);

		deleteTask(temp, minIndex);

		printArray(temp);


	}
	for (int i = 0; i < output.size(); i++)
	{
		cout << output[i] << "  ";
	}
	
	cout<<"完成！"<<endl;
	system("pause");
	return 0;
}