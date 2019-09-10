//#include <iostream>
//#include <string>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
//
//// ·Ö¸î×Ö·û´®
//static void SplitString(const string& s, vector<string>& v, const string& c)
//{
//	string::size_type pos1, pos2;
//	pos2 = s.find(c);
//	pos1 = 0;
//	while (string::npos != pos2)
//	{
//		v.push_back(s.substr(pos1, pos2 - pos1));
//		pos1 = pos2 + c.size();
//		pos2 = s.find(c, pos1);
//	}
//	if (pos1 != s.length())
//	{
//		v.push_back(s.substr(pos1));
//	}
//}
//
//int main(void)
//{
//	string input;
//	while (cin >> input)
//	{
//		vector<string> strings;
//		SplitString(input, strings, ";");
//		int n = stoi(strings[1]);
//		vector<string> numstr;
//		SplitString(strings[0], numstr, ",");
//
//		vector<int> even;
//		vector<int> odd;
//		vector<int> nums(numstr.size(), 0);
//		for (int i = 0; i < numstr.size(); i++)
//		{
//			nums[i] = stoi(numstr[i]);
//			nums[i] % 2 == 0 ? even.push_back(nums[i]) : odd.push_back(nums[i]);
//		}
//		sort(even.begin(), even.end());
//		sort(odd.begin(), odd.end());
//
//		vector<int> result(n, 0);
//		int index = 0;
//		int i1 = even.size() - 1;
//		while (n > 0 && i1 >= 0)
//		{
//			result[index++] = even[i1--];
//			n--;
//		}
//		i1 = odd.size() - 1;
//		while (n > 0 && i1 >= 0)
//		{
//			result[index++] = odd[i1--];
//			n--;
//		}
//		for (auto it : result)
//		{
//			cout << it;
//			it != result.back() ? cout << "," : cout << endl;
//		}
//	}
//
//	return 0;
//}