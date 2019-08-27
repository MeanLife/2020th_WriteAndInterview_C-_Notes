#include <iostream>
#include <vector>
using namespace std;
//ÀòÀò
int main1456350243151042353(void)
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
			}
		}
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (array[i][j] > 0)
				{
					sum += (6 * array[i][j] - (array[i][j] - 1)* 2);
					if (j < M - 1) // ×óÓÒ
					{
						sum -= array[i][j] >= array[i][j + 1] ? array[i][j + 1] * 2 : array[i][j] * 2;
					}
					if (i < N - 1) // ÉÏÏÂ
					{
						sum -= array[i][j] >= array[i + 1][j] ? array[i + 1][j] * 2 : array[i][j] * 2;
					}
				}
			}
		}

		cout << sum << endl;
	}


	//cout<<"Write By JZQ!"<<endl;
	//×Ô¶¯ÅÅ°æ£ºctrl+k+F
	return 0;
}