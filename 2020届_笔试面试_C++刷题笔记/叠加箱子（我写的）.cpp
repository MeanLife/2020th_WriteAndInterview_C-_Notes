#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 打印二维数组vector<vector<int>> array
static void print_2D_Array(vector<vector<int>> array)
{
	for (unsigned i = 0; i < array.size(); ++i)
	{
		for (vector<int>::iterator it = array[i].begin(); it != array[i].end(); it++)
		{
			cout << *it << "  ";
		}
		cout << endl;
	}
	cout << endl;
}

int main23152040255214365841658416(void)
{
	int N, M;
	const int data = 6;
	while (cin >> N >> M)
	{
		vector<vector<int>> array(N);
		int sum = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				int temp;
				cin >> temp;
				array[i].push_back(temp);
				sum += temp;
			}
		}
		sum *= 6;
		//cout << "sum = " << sum << endl;
		int num_0 = 0;
		while (num_0 != N * M)
		{
			num_0 = 0;
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < M - 1; j++)
				{
					if (array[i][j] && array[i][j + 1])
					{
						sum -= 2;
					}
					if (array[j][i] && array[j + 1][i])
					{
						sum -= 2;
					}
				}
			}
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < M; j++)
				{
					if (array[i][j] > 0)
					{
						array[i][j]--;
					}
					if (array[i][j] == 0)
					{
						num_0 += 1;
					}
				}
			}
			sum -= (N * M  - num_0) * 2;
			print_2D_Array(array);
			cout << sum << endl;
		}
		cout << sum << endl;
	}
	return 0;
}