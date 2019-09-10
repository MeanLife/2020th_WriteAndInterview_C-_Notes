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
1、从头到尾遍历字符串做替换，时间复杂度为O(n2)，效率低
2、从尾到头遍历字符串做替换，时间复杂度为O(n)，效率高
***************************************/
// 1、
static void replaceSpace1(string &str, int length)
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
/***************************************
【思路】：
// 2、用指针P1指向原始字符串的末尾，指针P2指向替换后字符串的末尾。
向前移动指针P1，如果P1指向的元素不是空格，则将P1指向的元素复制给P2指向的位置；
如果P1指向的元素是空格，则P2依次向前移动并插入%20。当P1==P2时，结束替换。
***************************************/
static void replaceSpace2(string &str, int length)
{
	// 边界检查1：判断字符数组是否为空
	if (str.size() == 0)
	{
		return;
	}

	const string key = "%20";
	// 遍历字符串，统计空格个数、替换前字符个数、替换后字符个数
	int CountOfBlanks = 0; // 空格个数
	int Originallength = 0;// 替换前字符个数
	int newLen = 0;           // 替换后字符个数
	for (int i = 0; str[i] != '\0'; ++i)
	{
		Originallength++;
		if (str[i] == ' ')
		{
			++CountOfBlanks;
		}
	}
	newLen = Originallength + (key.size() - 1) * CountOfBlanks;// 替换后字符个数 = 替换前的个数+需要替换的个数*(替换的字符个数-1)

	// 边界检查2：判断字符数组是否越界
	if (newLen > length)
	{
		return;
	}

	// 替换空格
	int p_Original = Originallength;// 指向原始字符串的末尾(\0)
	int p_New = newLen;// 指向替换后字符串的末尾(\0)
	while (p_Original != p_New)         // 替换结束的条件
	{
		if (str[p_Original] == ' ')
		{
			str[p_Original--] = '0';
			str[p_Original--] = '2';
			str[p_Original--] = '%';
		}
		else
		{
			str[p_New--] = str[p_Original--];
		}
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
	replaceSpace2(str, str.size());
	cout << "str = " << str << endl;

	cout<<"Write By JZQ!"<<endl;
	//自动排版：ctrl+k+F
	return 0;
}