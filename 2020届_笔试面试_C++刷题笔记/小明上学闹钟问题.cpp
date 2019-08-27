#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

/*
问题描述：
牛牛总是睡过头，所以他定了很多闹钟，只有在闹钟响的时候他才会醒过来并且决定起不起床。
从他起床算起他需要X分钟到达教室，上课时间为当天的A时B分，请问他最晚可以什么时间起床
输入描述:
每个输入包含一个测试用例。
每个测试用例的第一行包含一个正整数，表示闹钟的数量N(N<=100)。
接下来的N行每行包含两个整数，表示这个闹钟响起的时间为Hi(0<=A<24)时Mi(0<=B<60)分。
接下来的一行包含一个整数，表示从起床算起他需要X(0<=X<=100)分钟到达教室。
接下来的一行包含两个整数，表示上课时间为A(0<=A<24)时B(0<=B<60)分。
数据保证至少有一个闹钟可以让牛牛及时到达教室。
解题思路
第一步：将小时化为分钟，添加到数组里，
第二步：遍历数组 ， 遍历的同时分为以下几步 ：
1.判断当前时间会不会迟到 也就是 所剩时间 = （到校时间-路程-闹钟）如果小于0肯定迟到了
2.如果大于零，我们找所剩时间最小的(可以等于0) 把 i 的位置赋值给min a[min]就是最迟的闹钟了
3.分钟/60所得的就是小时 分钟%60所得的就是剩下的分钟；

输入：
3 //定了几个闹钟
5 0 //第1个闹钟的小时数和分钟数
6 0 //第2个闹钟的小时数和分钟数
7 0 //第3个闹钟的小时数和分钟数
59 //到学校要多少分钟
6 59 //上课的小时数和分钟数
输出：
6 0 //最晚的起床时间
*/

// 输入二维数组vector<vector<int>> array
static void input_2D_Array(vector<vector<int>> &array, const int n, const int m)
{
	int temp;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> temp;
			array[i].push_back(temp);
		}
	}
}

static void fun(vector<vector<int>> &time, const int n, const int x, int deadLine[])
{
	//3
	//5 0
	//6 0
	//7 0
	//59

	//6 0
	vector<int> sumTime;
	int result = 0;
	for (int i = 0; i < n; ++i)
	{
		sumTime.push_back(time[i][0] * 60 + time[i][1] + x);
	}
	sort(sumTime.begin(), sumTime.end());
	for (auto it : sumTime)
	{
		//cout << "it + " << it << endl;
		if (it <= deadLine[0]*60 + deadLine[1])
		{
			result = it;
		}
	}
	cout << (result - x)/60 << " " << (result - x)%60 << endl;
}

int main1512163112631162416584168(void)
{
	int n;
	cin >> n;
	int x;
	int deadLine[2];
	vector<vector<int>> array(n);
	input_2D_Array(array, n, 2);
	cin >> x;
	cin >> deadLine[0] >> deadLine[1];
	fun(array, n, x, deadLine);
	return 0;
}