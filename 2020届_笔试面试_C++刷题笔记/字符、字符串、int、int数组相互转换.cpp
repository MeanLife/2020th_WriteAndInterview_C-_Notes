#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

// 分割字符串
static void SplitString(const string& source, vector<string>& des, const string& key)
{
	string::size_type pos1, pos2;
	pos2 = source.find(key);
	pos1 = 0;
	while (string::npos != pos2)
	{
		des.push_back(source.substr(pos1, pos2 - pos1));
		pos1 = pos2 + key.size();
		pos2 = source.find(key, pos1);
	}
	if (pos1 != source.length())
	{
		des.push_back(source.substr(pos1));
	}
}

// 字符串数组转为int数组
static void StringToInt(vector<string>& source, vector<int> &des)
{
	for (auto i = 0; !source.empty(); i++)
	{
		des.push_back(std::stoi(source.front()));
		source.erase(source.begin());
	}
}

int main212653805305220352355(void)
{
	int a = 2;
	vector<string> array1;
	vector<int> array2;

	char b = '5';
	string str1 = "1 2 3 4 5";

	// Int和char互转;
	char c = a + '0'; // 该方法仅限0--9，10之后（包括10）,都不正确
	int d = c - '0';

	// Int和string互转;
	string str2 = to_string(a);
	int e = stoi(str2);
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
	cout << "d = " << d << endl;
	cout << "e = " << e << endl;
	cout << "str1 = " << str1 << endl;
	cout << "str2 = " << str2 << endl;

	// 分割字符串，变成vector<string> array1;字符串数组
	SplitString(str1, array1, " ");
	for (auto it : array1)
	{
		cout << it << "_";
	}
	cout << endl;
	// 将vector<string> array1;字符串数组 变成 int数组
	StringToInt(array1, array2);
	for (auto it : array2)
	{
		cout << it << "_";
	}
	cout << endl;
	
	cout<<"Write By JZQ!"<<endl;
	//自动排版：ctrl+k+F
	return 0;
}

