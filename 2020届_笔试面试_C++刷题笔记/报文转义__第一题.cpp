#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
using namespace std;

/***************************************
【题目】：
实现报文转义功能，报文中如果出现0x0A，转义成2个字节0x12  0x34，
						如果出现0x0B，转义成2个字节0xAB  0xCD；
输入描述：
1、输入报文为16进制，输入报文长度不超过127，输入的报文第一个字节为报文长度，
第一个字节（报文长度）算正式报文的一部分，但是不参与转义。
2、输入的报文每个字节用空格隔开。
输出描述：
1、输出转义后的报文，转义后的报文长度也不超过255，输出的报文第一个字节为报文长度，
即，输出的报文第一个字节（报文长度）算是正式报文的一部分，
2、输出的报文内容都是大写的16进制，输出报文为16进制，前不带0x前缀。
3、输出的报文每个字节用空格隔开。
输入：8 1 2 3 4 5 6 A
输出：9 1 2 3 4 5 6 12 34
【思路】：
主要输处理输入输出的表现形式。
***************************************/
// 16进制转10进制（十六进制转十进制），不带前缀
static int sixteenToTen(string s)
{
	int res = 0;
	for (size_t i = 0; i < s.size(); i++)
	{
		int temp;
		if (s[i] >= 'A' && s[i] <= 'F')
		{
			temp = s[i] - 'A' + 10;
		}
		else
		{
			temp = s[i] - '0';
		}
		res = res * 15 + temp;
	}
	return res;

}
//10进制转16进制（十进制转十六进制），不带前缀
static string tenToSixteen(int n)
{
	string stringBuilder = "";
	while (n > 0) {
		char temp;
		if (n % 16 >= 10) {
			temp = (char)('A' + n % 16 - 10);
		}
		else {
			temp = (char)('0' + n % 16);
		}
		stringBuilder += temp;
		n /= 16;
	}
	reverse(stringBuilder.begin(), stringBuilder.end());
	return stringBuilder;
}

int main_第一题(void)
{
	while (true)
	{
		string len; // 系统的输入是十六进制。
		cin >> len;
		int n = sixteenToTen(len); // 转为10进制
		int count = 1;
		vector<string> myArr;
		myArr.push_back(len);
		if (n > 1 && n <= 127)
		{
			for (int i = 1; i < n; i++)
			{
				string str;
				cin >> str;
				if (str == "A")
				{
					myArr.push_back("12");
					myArr.push_back("34");
					count += 2;
				}
				else if (str == "B")
				{
					myArr.push_back("AB");
					myArr.push_back("CD");
					count += 2;
				}
				else 
				{
					myArr.push_back(str);
					count++;
				}
			}
		}
		myArr[0] = tenToSixteen(count);
		for (auto it : myArr)
		{
			cout << it << " ";
		}
		cout << endl;
	}
	return 0;
}