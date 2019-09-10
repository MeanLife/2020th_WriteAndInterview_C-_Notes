#include <iostream>
#include <vector>
using namespace std;

static void findMaxSubstr(vector<int> &nums, const int len)
{
	int maxL = 0;
	vector<int> temp(len, 0);
	for (int i = 0; i < len; i++)
	{
		int L = 0;
		int R = maxL;
		while (L < R)
		{
			int mid = L + (R - L) / 2;
			if (temp[mid] <= nums[i])
			{
				L = mid + 1;
			}
			else
			{
				R = mid;
			}
		}

		temp[L] = nums[i];
		if (L == maxL)
		{
			maxL++;
		}
	}
	cout << maxL << endl;
}

int main____dsad52(void)
{
	int len = 0;
	while (cin >> len)
	{
		vector<int> nums(len, 0);
		for (int i = 0; i < len; i++)
		{
			cin >> nums[i];
		}
		findMaxSubstr(nums, len);
	}
	return 0;
}