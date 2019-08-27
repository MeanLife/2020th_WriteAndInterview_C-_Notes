#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

/*
有 n 个字符串，每个字符串都是由 A-J 的大写字符构成。
现在你将每个字符映射为一个 0-9 的数字，不同字符映射为不同的数字。
这样每个字符串就可以看做一个整数，唯一的要求是这些整数必须是正整数且它们的字符串不能有前导零。
现在问你怎样映射字符才能使得这些字符串表示的整数之和最大？

输入描述:
每组测试用例仅包含一组数据，每组数据第一行为一个正整数 n ， 接下来有 n 行，
每行一个长度不超过 12 且仅包含大写字母 A-J 的字符串。 n 不大于 50，且至少存在一个字符不是任何字符串的首字母。

输出描述:
输出一个数，表示最大和是多少。

示例1
输入
2
ABC
BCA
输出
1875

【思路】：
设 table = A B C D E F G H I J
个位权值 为 1
十位权值 为 10
百位权值 为 100
依次类推， 没有出现的字母权值为 0

则 A 的权重为 100 + 1  = 101
B 的权重为    10 + 100 = 110
C 的权重为    1 + 10   = 11
*/

// 两个超长的整数字符串相加
static string calculateAdd(string &a1, string &a2)
{
	//string str1 = "21421";
	//string str2 = "809327";
	string str1 = a1;
	string str2 = a2;
	string result = "";
	cout << "str1的长度为：" << str1.size() << endl;
	cout << "str2的长度为：" << str2.size() << endl;

	int quotient = 0;
	int remainder = 0;
	int sum = 0;
	int strNum1 = str1.size();
	int strNum2 = str2.size();
	int max = strNum1 > strNum2 ? strNum1 : strNum2;
	cout << "max的长度为：" << max << endl;

	reverse(str1.begin(), str1.end());
	reverse(str2.begin(), str2.end());

	for (int i = 0; i < max; ++i)
	{
		int nStr1 = i < strNum1 ? (str1[i] - 48) : 0;
		int nStr2 = i < strNum2 ? (str2[i] - 48) : 0;
		sum = nStr1 + nStr2 + quotient;
		if (sum > 9)
		{
			quotient = sum / 10;
			remainder = sum % 10;
		}
		else
		{
			quotient = 0;
			remainder = sum;
		}
		result = (char)(remainder + 48) + result;
	}
	if (quotient != 0)
	{
		result = (char)(quotient + 48) + result;
	}
	// 21421 + 809327 = 830748.
	return result;
}


static void function(vector<string> &str)
{
	// 第一步，给字符赋权值
	map<char, int> my_map;
	for (int i = 0; i < str.size(); ++i)
	{
		string str_temp = str[i];
		for (int j = str_temp.size() - 1; j >= 0; --j)
		{
			if (my_map.insert(pair<char, int>(str_temp[j], pow(10, str_temp.size() - j - 1))).second)
			{
				// 插入成功，说明该值为新的
				continue;
			}
			else
			{
				// 插入不成功，说明该值不为新的
				my_map[str_temp[j]] += pow(10, str_temp.size() - j - 1);
			}
		}
	}
	multimap<int, char, greater<int>> my_multimap; // 键值从大到小greater<int>,键值从小到大less<Type> 
	for (auto it : my_map)
	{
		cout << it.first << " : " << it.second << endl;
		my_multimap.insert(pair<int, char>(it.second, it.first));
	}

	const int max = 9;
	int index = 0;
	for (auto it : my_multimap)
	{
		cout << it.first << " : " << it.second << endl;
		my_map[it.second] = max - index;
		index++;
	}
	for (auto it : my_map)
	{
		cout << it.first << " : " << it.second << endl;
	}
	for (int i = 0; i < str.size(); ++i)
	{
		for (int j = 0; j < str[i].size(); ++j)
		{
			str[i][j] = my_map[str[i][j]] + '0';
			cout << str[i][j];
		}
		cout << endl;
	}
	cout << calculateAdd(str[0], str[1]) << endl;
}

int main_字符串最大映射(void)
{
	int n = 2;
	vector<string> str = { "ABCC", "BCDA" };

	function(str);
	
	cout<<"Write By JZQ!"<<endl;
	//自动排版：ctrl+k+F
	return 0;
}