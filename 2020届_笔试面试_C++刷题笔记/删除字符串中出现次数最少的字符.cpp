#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

/*
题目描述
实现删除字符串中出现次数最少的字符，若多个字符出现次数一样，则都删除。
输出删除这些单词后的字符串，字符串中其它字符保持原来的顺序。
输入描述:
字符串只包含小写英文字母, 不考虑非法输入，输入的字符串长度小于等于20个字节。

输出描述:
删除字符串中出现次数最少的字符后的字符串。

示例1
输入
复制
abcdd
输出
复制
dd
*/

int main1502_删除字符串中出现次数最少的字符(void)
{
	string str = "";

	while (cin >> str)
	{
		map<char, int> my_map;

		for (int i = 0; i < str.size(); i++) // 元素个数计数。
		{
			auto it = my_map.insert(pair<char, int>(str[i], 0));
			if (it.second)
			{
				my_map[str[i]] = 1;
			}
			else
			{
				my_map[str[i]]++;
			}
		}

		int minVuale = 20;
		for (auto it : my_map)
		{
			//cout << it.first << " : " << it.second << endl;
			if (it.second < minVuale)
			{
				minVuale = it.second;
			}
			//cout << "minVuale : " << minVuale << endl;
		}

		vector<char> my_v;
		for (auto it : my_map)
		{
			if (it.second != minVuale)
			{
				my_v.push_back(it.first);
			}
		}

		//for (auto it : my_v)
		//{
		//	cout << it << endl;
		//}

		for (int i = 0; i < str.size(); i++)
		{
			if (find(my_v.begin(), my_v.end(), str[i]) != my_v.end())
			{
				cout << str[i];
			}
		}
		cout << endl;
	}
	
	//自动排版：ctrl+k+F
	return 0;
}