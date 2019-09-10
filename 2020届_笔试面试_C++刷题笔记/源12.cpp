//#include <iostream>
//#include <string>
//#include <cmath>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
///***************************************
//<https://blog.csdn.net/z451483807/article/details/19354325>
//5
//5
//10 20 30 40 50
//4 5 6 7 8
//***************************************/
//static void function(vector<int> &an, vector<int> &bn, const int n, const int m)
//{
//	vector<vector<int>> result(n + 1, vector<int>(m + 1, 0));
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = i + 1; j <= n; j++)
//		{
//			if (bn[i] < bn[j])
//			{
//				swap(bn[i], bn[j]);
//				swap(an[i], an[j]);
//			}
//		}
//	}
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= min(m, i); j++)
//		{
//			result[i][j] = max(result[i - 1][j], result[i - 1][j - 1] + an[i] - bn[i] * (j - 1));
//		}
//	}
//	cout << result[n][m] << endl;
//}
//
//int main()
//{
//	int n, m;
//	while (cin >> n >> m)
//	{
//		// 输入
//		vector<int> an(n + 1, 0);
//		vector<int> bn(n + 1, 0);
//		for (int i = 1; i <= n; i++)
//		{
//			cin >> an[i];
//		}
//		for (int i = 1; i <= n; i++)
//		{
//			cin >> bn[i];
//		}
//		// 动态规划
//		function(an, bn, n, m);
//
//	}
//}