#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

/***************************************
【题目】：
给定一个单词，你需要判断单词的大写使用是否正确。
我们定义，在以下情况时，单词的大写用法是正确的：
全部字母都是大写，比如"USA"。
单词中所有字母都不是大写，比如"leetcode"。
如果单词不只含有一个字母，只有首字母大写， 比如 "Google"。
否则，我们定义这个单词没有正确使用大写字母。

示例 1:
输入: "USA"
输出: True
示例 2:
输入: "FlaG"
输出: False
【思路】：
isupper()、islower()：用于判断字符是否是大小写。
***************************************/

static bool detectCapitalUse(const string &str)
{
	if (str.size() == 0)
	{
		return false;
	}

	int count = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (isupper(str[i])) // if (word.charAt(i) <= 'Z' && word.charAt(i) >= 'A')
		{
			count++;
		}
	}

	if (count == str.size() || (count == 1 && isupper(str[0])) || count == 0)
	{
		return true;
	}
	return false;
}

int main_LeetCode520_检测大写字母(void)
{
	string input = "AASDAF";
	cin >> input;
	cout << (true == detectCapitalUse(input) ? "true" : "false") << endl;
	
	cout<<"Write By JZQ!"<<endl;
	//自动排版：ctrl+k+F
	return 0;
}