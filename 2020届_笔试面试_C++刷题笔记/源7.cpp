//#include <iostream>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
//static void swap(int &a, int &b)
//{
//	int temp = a;
//	a = b;
//	b = temp;
//}
//
//static int function(vector<int> &vec, int k, int s, int e)
//{
//	int roll = vec[s], be = 0, j = s;
//	for (int i = s + 1; i <= e; i++)
//	{
//		if (vec[i] < roll)
//		{
//			j++;
//			swap(vec[i], vec[j]);
//			be++;
//		}
//	}
//
//	swap(vec[s], vec[j]);
//	if (be == k - 1)
//	{
//		return roll;
//	}
//	else if (be < k - 1)
//	{
//		return function(vec, k - be - 1, j + 1, e);
//	}
//	else
//	{
//		return function(vec, k, s, j - 1);
//	}
//}
//
//int main(void)
//{
//	int n = 0;
//	long long k = 0;
//	while (cin >> n >> k)
//	{
//		vector<int> partA(n, 0);
//		vector<int> partB(n, 0);
//		vector<int> keys;
//		for (int i = 0; i < n; i++)
//		{
//			cin >> partA[i];
//		}
//		for (int i = 0; i < n; i++)
//		{
//			cin >> partB[i];
//		}
//		for (int i = 0; i < n; i++)
//		{
//			for (int j = 0; j < n; j++)
//			{
//				if (find(keys.begin(), keys.end(), partA[j] * partB[i]) == keys.end())
//				{
//					keys.push_back(partA[j] * partB[i]);
//				}
//			}
//		}
//
//		cout << function(keys, k, 0, keys.size() - 1);
//	}
//
//	return 0;
//}