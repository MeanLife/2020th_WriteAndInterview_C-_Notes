#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

/*
现在现在有一台机器，这台机器可以接收两种形式任务：
（1）任务列表，任务列表里面有N个任务，对于第i个任务，机器在Ti时间开始执行，并在1个单位时间内做完。
（2）临时任务，机器可以在任意时间接收一个临时任务，但任务列表里面的任务优先级要高于临时任务，
也就是说当机器空闲的时候才会执行临时任务。

现在机器已经接收一个任务列表。接下来会有M个临时任务，题目：我们想知道每个临时任务何时被执行。
为了简化问题我们可以认为这M个临时任务是独立无关即任务是可以同时执行的，互不影响的。

输入
输入数据有多组，每组数据第一行包括两个整数N和M（1<=N, M<=10^5）。
接下来一行有N个不同数字T1,T2,T3.....TN（1<=T1
接下来又M行，每行一个数字Qi（1<=Qi<=10^9），表示第i个临时任务的的接收时间。

输出
对于每个临时任务，输出它被执行的时间。

样例输入
5 6
1 2 3 5 6
3
2
1
4
5
6

样例输出
4
4
4
4
7
7
*/

int main4582634528465864583202543(void)
{
	int N, M;
	while (cin >> N >> M)
	{
		vector<int> times_Ti(N, 0); // 任务列表
		for (int i = 0; i < N; i++)
		{
			int temp = 0;
			cin >> temp;
			times_Ti[i] = temp;
		}
		vector<int> times_Qi(M, 0); // 临时任务
		for (int i = 0; i < M; i++)
		{
			int temp = 0;
			cin >> temp;
			times_Qi[i] = temp;
		}
		//sort(times_Qi.begin(), times_Qi.end());
		vector<int> time(times_Ti.back() + 2, 0); // 下标从1开始，且留末尾1个空闲冗余
		for (int i = 0; i < N; i++)
		{
			time[times_Ti[i]] = 1;
		}

		for (int i = 1; i < time.size(); i++) // 下标从1开始，且留末尾1个空闲冗余
		{
			if (time[i] == 0) // 此时空闲:i
			{
				for (int j = 0; j < times_Qi.size(); )
				{
					if (times_Qi[j] <= i)
					{
						cout << i << endl;
						times_Qi.erase(times_Qi.begin() + j);
					}
					else
					{
						j++;
					}
				}
			}
		}
	}
	
	//cout<<"Write By JZQ!"<<endl;
	//自动排版：ctrl+k+F
	return 0;
}