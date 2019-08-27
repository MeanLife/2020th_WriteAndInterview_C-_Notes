#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main15201025351203052316356201502316(void)
{
	int N, M;
	while (cin >> N >> M)
	{
		vector<vector<int>> array(2);
		vector<int> result(N, 0);
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < N; j++)
			{
				int temp;
				cin >> temp;
				array[i].push_back(temp);
			}
		}
		vector<vector<int>> vv1;
		vector<vector<int>> vv2;
		while (next_permutation(array[0].begin(), array[0].end()))
		{
			vv1.push_back(array[0]);
		}
		while (next_permutation(array[1].begin(), array[1].end()))
		{
			vv1.push_back(array[1]);
		}
		int temp = 0;
		for (auto vt1 : vv1)
		{
			for (auto vt2 : vv2)
			{
				//¡£¡£¡£¡£¡£Î´×ö³ö£¬£¬£¬
			}

		}
		for (auto it : result)
		{
			cout << it << " ";
		}
	}
	return 0;
}