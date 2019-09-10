//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//#define INT_MAX 2147483647
//
//int main(void)
//{
//	int n = 0;
//	while (cin >> n)
//	{
//		vector<int> arr(n, 0);
//		for (int i = 0; i < n; i++)
//		{
//			cin >> arr[i];
//		}
//
//		vector<vector<int>> sum(n, vector<int>(n, 0)); // i到j的和
//		vector<vector<int>> min_value(n, vector<int>(n, INT_MAX)); // i到j的最小值
//		for (int i = 0; i < n; i++)
//		{
//			for (int j = i; j < n; j++)
//			{
//				for (int k = i; k <= j; k++)
//				{
//					sum[i][j] += arr[k];
//					min_value[i][j] = min(min_value[i][j], arr[k]);
//				}
//			}
//		}
//		
//		int max_value = 0;
//		for (int i = 0; i < n; i++)
//		{
//			for (int j = 0; j < n; j++)
//			{
//				max_value = max(max_value, min_value[i][j] * sum[i][j]);
//			}
//		}
//		cout << max_value << endl;
//	}
//
//	return 0;
//}