#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <set>
using namespace std;
/*
我叫王大锤，是一家出版社的编辑。我负责校对投稿来的英文稿件，这份工作非常烦人，因为每天都要去修正无数的拼写错误。但是，优秀的人总能在平凡的工作中发现真理。我发现一个发现拼写错误的捷径：

1. 三个同样的字母连在一起，一定是拼写错误，去掉一个的就好啦：比如 helllo -> hello
2. 两对一样的字母（AABB型）连在一起，一定是拼写错误，去掉第二对的一个字母就好啦：比如 helloo -> hello
3. 上面的规则优先“从左到右”匹配，即如果是AABBCC，虽然AABB和BBCC都是错误拼写，应该优先考虑修复AABB，结果为AABCC

我特喵是个天才！我在蓝翔学过挖掘机和程序设计，按照这个原理写了一个自动校对器，工作效率从此起飞。用不了多久，我就会出任CEO，当上董事长，迎娶白富美，走上人生巅峰，想想都有点小激动呢！
……
万万没想到，我被开除了，临走时老板对我说： “做人做事要兢兢业业、勤勤恳恳、本本分分，人要是行，干一行行一行。一行行行行行；要是不行，干一行不行一行，一行不行行行不行。” 我现在整个人红红火火恍恍惚惚的……


输入描述:
第一行包括一个数字N，表示本次用例包括多少个待校验的字符串。

后面跟随N行，每行为一个待校验的字符串。

输出描述:
N行，每行包括一个被修复后的字符串。

输入例子1:
2
helloo
wooooooow

输出例子1:
hello
woow
*/

// 打印二维数组vector<vector<int>> array
void print_2D_Array(vector<vector<char>> array)
{
	for (unsigned i = 0; i < array.size(); ++i)
	{
		for (vector<char>::iterator it = array[i].begin(); it != array[i].end(); it++)
		{
			cout << *it;
		}
	}
}

static void function(string &str, const int n)
{
	// 先统计需要多少个桶
	int count = 1;
	for (size_t i = 0; i < str.size() - 1; ++i)
	{
		if (str[i] != str[i + 1])
		{
			count++;
		}
	}
	//cout << "count:" << count << endl;
	// 将元素放入桶
	vector<vector<char>> bucket(count);
	int j = 0;
	bucket[j].push_back(str[0]); // 先将第一个元素放入第一个桶
	for (size_t i = 1; i < str.size(); ++i)
	{
		if (str[i - 1] != str[i])
		{
			j++;
			bucket[j].push_back(str[i]);
		}
		else
		{
			bucket[j].push_back(str[i]);
		}
	}
	//print_2D_Array(bucket);
	//cout << endl;
	// 对桶中的元素进行处理
	for (size_t i = 0; i < bucket.size(); ++i)
	{
		if (bucket[i].size() >= 3) // 1. 三个同样的字母连在一起，
		{
			while (bucket[i].size() >= 3)
			{
				bucket[i].pop_back();
			}
		}
	}
	for (size_t i = 0; i < bucket.size() - 1; ++i)
	{
		if ((bucket[i].size() == 2) && (bucket[i + 1].size() == 2)) // 2. 两对一样的字母（AABB型）连在一起
		{
			bucket[i + 1].pop_back();
		}
	}
	print_2D_Array(bucket);
	cout << endl;
}

int main3331255531535135115(void)
{
	//int n = 2;
	//vector<string> str;
	//str.push_back("helloo1122");
	//str.push_back("wooooooow");


	int n = 0;
	cin >> n;
	vector<string> str;
	string in;
	for (int i = 0; i < n; i++)
	{
		cin >> in;
		str.push_back(in);
	}
	for (int i = 0; i < n; i++)
	{
		function(str[i], 2);
	}

	//cout<<"Write By JZQ!"<<endl;
	//自动排版：ctrl+k+F
	return 0;
}