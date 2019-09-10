//#include <iostream>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
//static bool compare_desc(int a, int b)
//{
//	return a > b;
//}
//static bool compare_inc(int a, int b)
//{
//	return a < b;
//}
//
//int main(void)
//{
//	int n;
//	while (cin >> n)
//	{
//		vector<int> arr_ai(n);
//		vector<int> arr_bi(n);
//		for (int i = 0; i < n; i++)
//		{
//			cin >> arr_ai[i];
//			cin >> arr_bi[i];
//		}
//
//		sort(arr_ai.begin(), arr_ai.end(), compare_desc);
//		sort(arr_bi.begin(), arr_bi.end(), compare_inc);
//
//		int result = 0;
//		for (int i = 0; i < n; i++)
//		{
//			result += arr_ai[i] * i + arr_bi[i] * (n - i - 1);
//		}
//		cout << result << endl;
//	}
//
//	return 0;
//}