#include <iostream>
#include <string>
#include <cmath>
#include <unordered_map>
#include <vector>

/*
给你一个字符串，找出第一个不重复的字符，如“abbbabcd”，则第一个不重复就是c
*/

using namespace std;
int main11313535(void)
{
	string str = "abbcdffdvdcdwejaac";
	unordered_map<char, int> temp;
	vector<char> first;
	
	// 字符计数
	for (int i = 0; str[i] != '\0'; ++i)
	{
		if (!temp.count(str[i]))
		{
			temp[str[i]] = 1;
			first.push_back(str[i]);
		}
		else
		{
			temp[str[i]] += 1;
		}
	}

	// 遍历打印输出
	for (unordered_map<char, int>::iterator it = temp.begin(); it != temp.end(); it++)
	{
		cout << it->first << " : " << it->second << endl;
	}
	cout << endl;
	for (vector<char>::iterator it = first.begin(); it != first.end(); it++)
	{
		cout << *it << " : " <<temp[*it] << endl;
	}

	cout<<"Write By JZQ!"<<endl;
	//自动排版：ctrl+k+F
	return 0;
}