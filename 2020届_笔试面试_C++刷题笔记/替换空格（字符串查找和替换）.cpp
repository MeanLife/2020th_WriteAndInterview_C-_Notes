#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

/*
请实现一个函数，将一个字符串中的每个空格替换成“%20”。
例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
*/

/***************************************
【思路】：
一个一个的找出现key2的地方，将其用key1替换掉
***************************************/
//void replaceSpace(char *str, int length)
//{
//	const string key1 = "%20";
//	const string key2 = " ";
//	string temp(str);
//	while (true)
//	{
//		int p = temp.find(key2); // 返回key2第一次出现的位置，下标。
//		if (p == -1)
//		{
//			break;
//		}
//		temp.replace(temp.begin() + p, temp.begin() + p + key2.size(), key1);
//	}
//	*str = temp.substr(0);
//	//strcpy(str, const_cast<char *>(temp.c_str()));
//}
void replaceSpace(string &str, int length)
{
	const string key1 = "%20";
	const string key2 = " ";
	while (true)
	{
		int p = str.find(key2); // 返回key2第一次出现的位置，下标。
		if (p == -1)
		{
			break;
		}
		str.replace(str.begin() + p, str.begin() + p + key2.size(), key1);
	}
}

int main_替换空格（字符串查找和替换）(void)
{
	//char *str = new char[30];
	//string temp = "We Are Happy  12313";
	//strncpy_s(str, 30, const_cast<char *>(temp.c_str()), temp.length());
	//replaceSpace(str, 30); // 在牛客网上，输入必须是char *.
	//cout << "str : " << str << endl;
	
	string str("We Are Happy  12313");
	replaceSpace(str, str.size());
	cout << "str = " << str << endl;

	cout<<"Write By JZQ!"<<endl;
	//自动排版：ctrl+k+F
	return 0;
}