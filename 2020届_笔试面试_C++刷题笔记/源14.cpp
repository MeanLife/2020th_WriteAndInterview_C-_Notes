//#include <iostream>
//#include <string>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
//static string function(string str, int k)
//{
//	for (int start = 0; start < str.size(); start += 2 * k) 
//	{
//		int i = start;
//		int j = min(start + k - 1, (int)str.size() - 1);
//		for (; i < j; i++, j--)
//		{
//			swap(str[i], str[j]);
//		}
//	}
//	return str;
//}
//
//int main(void)
//{
//	string str = "ab";
//	int num = 3;
//
//	cout << function(str, num) << endl;
//
//	return 0;
//}