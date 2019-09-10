/***************************************
【题目】：
在两个字符串中，有些字符会一样，可以形成的子序列也有可能相等，
因此，长度最长的相等子序列便是两者间的最长公共子序列，
【思路】：
其长度可以使用动态规划来求。<https://blog.csdn.net/someone_and_anyone/article/details/81044153>
图中的空白格子需要填上相应的数字（这个数字就是c[i][j]的定义，记录的LCS的长度值）。
填的规则依据递归公式，
简单来说：
如果横竖（i,j）对应的两个元素相等，该格子的值 = c[i-1,j-1] + 1。
如果不等，取c[i-1,j] 和 c[i,j-1]的最大值。最后，c的最右下角的元素就是最长公共子序列的长度
***************************************/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

// 打印二维数组vector<vector<int>> array
static void print_2D_Array(vector<vector<int>> array)
{
	for (unsigned i = 0; i < array.size(); ++i)
	{
		for (vector<int>::iterator it = array[i].begin(); it != array[i].end(); it++)
		{
			cout << *it << "  ";
		}
		cout << endl;
	}
	cout << endl;
}

/***************************************
DP_table：动态规划表
maxLen：最长公共子序列的长度
result：若有多个最长公共子序列，它一次只能求其中一个。
***************************************/
static void LCSofLen(string str1, string str2)
{
	int len1 = str1.size(); // 行
	int len2 = str2.size(); // 列
	vector<vector<int>> DP_table(len1 + 1,vector<int>(len2 + 1, 0)); // 动态规划表
	for (int i = 1; i <= len1; i++)
	{
		for (int j = 1; j <= len2; j++)
		{
			if (str1[i - 1] == str2[j - 1])
				DP_table[i][j] = DP_table[i - 1][j - 1] + 1;
			else
				DP_table[i][j] = max(DP_table[i][j - 1], DP_table[i - 1][j]);
		}
	}
	print_2D_Array(DP_table);
	cout << "maxLen = " << DP_table[len1][len2] << endl;

	vector<char> result; // 求其中一个子序列
	for (int i = len1, j = len2; i > 0 && j > 0; )
	{
		if (str1[i - 1] != str2[j - 1])
		{
			if (DP_table[i][j - 1] > DP_table[i - 1][j])
				j--;
			else if (DP_table[i][j - 1] == DP_table[i - 1][j])
				i--; // 相等时，这两个值随便取一下，所以回退时也可随便选择：选择向上i--，选择向左j--
			else
				i--;
		}
		else
		{
			result.push_back(str1[i - 1]);
			i--;
			j--;
		}
	}
	reverse(result.begin(), result.end());
	for (auto it : result)
	{
		cout << it << "  ";
	}
	cout << endl;
}

int main_最长公共子序列()
{
	string str1 = "13456778";
	string str2 = "357486782";
	LCSofLen(str1, str2);
	return 0;
}

