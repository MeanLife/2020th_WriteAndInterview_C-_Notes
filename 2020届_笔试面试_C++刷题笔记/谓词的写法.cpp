#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

// 操作符重载，调用：cmp()
typedef pair<string, int> PAIR;
struct cmp
{
	bool operator()(const pair<string, int> &p1, const pair<string, int> &p2)
	{
		return p1.second > p2.second;
	}
};
// 二元谓词，调用：decreece
bool decreece(const pair<string, int> &p1, const pair<string, int> &p2)
{
	return p1.second > p2.second;
}

int main_谓词练习()
{
	map<string, int>mp;

	for (int i = 0; i < 100; i += 10)
	{
		stringstream ss;
		ss << i;
		string si = "m" + ss.str();
		mp.insert(make_pair(si, i));
	}

	for (map<string, int>::iterator it = mp.begin(); it != mp.end(); it++)
	{
		cout << it->first << "  " << it->second << endl;
	}

	vector<pair<string, int>>vt(mp.begin(), mp.end());
	sort(vt.begin(), vt.end(), decreece); // 以map的value排序。
	cout << endl;

	for (vector<pair<string, int>>::iterator it = vt.begin(); it != vt.end(); it++)
	{
		cout << it->first << "  " << it->second << endl;
	}

	return 0;
}