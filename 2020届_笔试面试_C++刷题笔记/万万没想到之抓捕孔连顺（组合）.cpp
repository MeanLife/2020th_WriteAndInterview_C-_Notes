#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <set>
using namespace std;

/*
请听题：给定N（可选作为埋伏点的建筑物数）、D（相距最远的两名特工间的距离的最大值）以及可选建筑的坐标，计算在这次行动中，大锤的小队有多少种埋伏选择。
注意：
1. 两个特工不能埋伏在同一地点
2. 三个特工是等价的：即同样的位置组合(A, B, C) 只算一种埋伏方法，不能因“特工之间互换位置”而重复使用

输入描述:
第一行包含空格分隔的两个数字 N和D(1 ≤ N ≤ 1000000; 1 ≤ D ≤ 1000000)
第二行包含N个建筑物的的位置，每个位置用一个整数（取值区间为[0, 1000000]）表示，从小到大排列（将字节跳动大街看做一条数轴）

输出描述:
一个数字，表示不同埋伏方案的数量。结果可能溢出，请对 99997867 取模

输入例子1:
4 3
1 2 3 4

输出例子1:
4

例子说明1:
可选方案 (1, 2, 3), (1, 2, 4), (1, 3, 4), (2, 3, 4)

输入例子2:
5 19
1 10 20 30 50

输出例子2:
1

例子说明2:
可选方案 (1, 10, 20)
*/

// 计算组合数C(n,2)的数目
long long Cn2(long long n) {
	return (n - 1) * n / 2;
}

static void function(vector<long long> &v, const long long n, const long long d)
{
	long long count = 0;
	for (int i = 0, j = 0; i < n; i++) 
	{
		//cin >> v[i];
		while (i >= 2 && (v[i] - v[j]) > d) // i是从0开始的，i >= 2，代表需要有0  1  2 共三个组合长度，即m = 3。
		{									// (v[i] - v[j]) > d，是本题所要求的，距离不超过d.
			j++;
		}
		count += Cn2(i - j); // 相当于每次固定开头那个数，从剩下的数里取对应个数的组合数。
	}
	cout << count % 99997867 << endl;
}

int main12165125168431684128643164831516(void)
{
	long long n = 4, d = 3;
	vector<long long> array = { 1, 2, 3, 4 };
	function(array, n, d);

	
	cout<<"Write By JZQ!"<<endl;
	//自动排版：ctrl+k+F
	return 0;
}