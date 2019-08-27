#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

/*
C(n,m)=[n*(n-1)*...*(n-m)]/[m*(m-1)*...*1]
从n个字符中选取m个字符，获得所有的组合

A(n,n)=[n*(n-1)*...*1]
全排列算法

A(n,m)=A(n,m)=C(n,m)*A(m,m)
由公式可以将排列问题转换为组合问题和全排列问题

【思路】：
一、A(n,n)全排列可以使用STL算法:
next_permutation“下一个排列组合”,在使用前需要对欲排列数组按升序排序，否则只能找出该序列之后的全排列数。
prev_permutation“上一个排列组合”,在使用前需要对欲排列数组按降序排序，否则只能找出该序列之后的全排列数。

二、A(n,n)全排列可以使用递归算法:

三、C(n,m)组合，递归法：
将n个字符排列成一条流水线，然后从第一个字符开始选取，并且将已经选取的字符进行保存，
如果已经选取了m个字符，那么就获得了一种组合结果，此时问题还没有解决，
应该将刚刚保存的最后一个字符拿出来，然后选择流水线上的下一个字符，
如果已经访问到了流水线的最后一个字符而选取的字符还没有达到m个，
说明当前保存的字符无法得到一种组合，则将最后保存的字符拿出来，选择下一个字符。
*/

// A(n,n)全排列可以使用STL算法:
static void StlFunction()
{
	cout << "用prev_permutation对3 2 1的全排列" << endl;
	int arr[] = { 3,2,1 };
	do
	{
		cout << arr[0] << ' ' << arr[1] << ' ' << arr[2] << '\n';
	} while (prev_permutation(arr, arr + 3));      ///获取上一个较大字典序排列，如果3改为2，只对前两个数全排列


	cout << "用next_permutation对1 2 3的全排列" << endl;
	int arr1[] = { 1,2,3 };
	do
	{
		cout << arr1[0] << ' ' << arr1[1] << ' ' << arr1[2] << '\n';
	} while (next_permutation(arr1, arr1 + 3));      ///获取下一个较大字典序排列，如果3改为2，只对前两个数全排列
	///注意数组顺序，必要时要对数组先进行排序


	cout << "用next_permutation对1 2 3的全排列_使用容器和迭代器:" << endl;
	vector<int> arr2 = { 1,2,3 };
	do
	{
		cout << arr2[0] << ' ' << arr2[1] << ' ' << arr2[2] << '\n';
	} while (next_permutation(arr2.begin(), arr2.end()));


	// 若只对某一个数字排列，则将其放在首位，并限制排列长度为1。
}

/*
// C(n,m)组合，递归法：
*  str:  源字符串
*  nLen: 组合长度
*  vector<char> ve: 用来记录当前已经访问过的字符
*  vector<string> result: 用来记录组合后的结果，通过size()可以获得最终的组合结果
*/
static void perm(char* str, int nLen, vector<char>& ve, vector<string>& result)
{
	if (nLen == 0)   //已经找到一个全排列的组合,而且这个组合就在ve中
	{
		string st;
		vector<char>::iterator it = ve.begin();
		for (; it != ve.end(); it++)
		{
			st += *it;
		}
		result.push_back(st);    //找到了一种组合，将它保存在动态数组中
		return;
	}
	if (*str == '\0')
		return;

	ve.push_back(*str);
	perm(str + 1, nLen - 1, ve, result);
	//递归从这里出来的条件只有两种，
	//要么str为空了，说明当前已经遍历一遍字符串，
	//要么nLen为0了，说明已经找到了一种组合

	ve.pop_back(); // 此时要将最后一个字符出栈，然后遍历下一个字符
	perm(str + 1, nLen, ve, result);

}
/*
函数Sectet用来检查当前输入参数是否能够形成排列
当传入字符串为空或者n小于m时，返回一个空表
* str:  n个字符组成的字符串
* nLen: 组合长度m
*/
vector<string> Secret(char* str, int nLen)
{
	vector<string> strVect;

	if (str == NULL || nLen > strlen(str))    //返回一个空表
		return strVect;

	vector<char> chVect;
	perm(str, nLen, chVect, strVect);
	return strVect;
}


int main_排列组合(void)
{
	cout << "全排列：" << endl;
	StlFunction();

	cout << "组合：" << endl;
	char s[] = "12345";

	int n = strlen(s);
	int m = 4;

	vector<string> strVect = Secret(s, m);
	int nCount = strVect.size();
	if (nCount == 0)
	{
		cout << "当前输入参数不符合排列规则!" << endl;
	}
	else
	{
		char buff[100];
		sprintf_s(buff, "C(%d,%d)一共有%d种组合", n, m, nCount);
		cout << buff << endl;
		vector<string>::iterator it = strVect.begin();
		for (; it != strVect.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	
	cout<<"Write By JZQ!"<<endl;
	//自动排版：ctrl+k+F
	return 0;
}