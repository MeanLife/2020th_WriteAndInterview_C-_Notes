#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main__爱奇艺第一题(void)
{
	int n;
	while (cin >> n)
	{
		vector<int> Ai(n - 1, 0);
		vector<char> arr(n, 0);
		for (int i = 0; i < n - 1; i++)
		{
			cin >> Ai[i];
			arr[i] = (i + 1) + '0';
		}
		arr[n - 1] = n + '0';

		int count = 0;
		do
		{
			bool flag = true;
			for (int j = 0; j < arr.size() - 1; j++)
			{
				if ((Ai[j] == 0 && arr[j] >= arr[j + 1]) || (Ai[j] == 1 && arr[j] <= arr[j + 1]))
				{
					flag = false;
					break;
				}
			}
			if (flag == true)
			{
				count++;
			}
		} while (next_permutation(arr.begin(), arr.end()));
		cout << count << endl;
	}
	return 0;
}