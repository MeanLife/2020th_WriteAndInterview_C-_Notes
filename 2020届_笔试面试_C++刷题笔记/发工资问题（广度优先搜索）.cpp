#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

/*
王大锤要给员工发工资，员工从左到右坐成一排，每个员工知道彼此的资历，
每个员工只知道自己左右员工的工资，如果某员工比左边或右边的人资历老，
那他一定比这个人工资高100元，每个人最低工资100元，求王大锤最低给多少工资。

样例
输入：
4 //几个员工
3 9 2 7 //员工顺序以及对应的资历
输出：
600 //100元，200元，100元，200元

6
1 2 3 4 5 6
2100 //100，200，300，400，500，600

5
1 1 1 1 1
500 //100，100，100，100，100

8
1 2 3 4 3 2 3 4
1800 //100 200 300 400 200 100 200 300

8
3 4 3 4 3 4 3 4
1200 //100 200 100 200 100 200 100 200

4
1 2 3 3
700 //100 200 300 100

思路（100/100分）：
对于给定的一堆资历，从开始往后，第一个初始化为 100，依次向后初始化 i + 100 的 money 值，
当 i 对应的资历比 i+1 的资历小时， i+1 应该拿到更多的钱，所以有 money[i+1]=money[i]+100;
当 i 对应的资历跟 i+1 相等时，反正也看不到，将 money[i+1] 设为 100 ；
当 i 对应的资历比 i+1 大时，money[i+1] 应该是此时较小的，将其设为 100 ，但是可能后面的跟他相同或比他小，
因此要将后面资历递增的那些 money 更新一下，此处采用一个 for 循环，循环从 j=i+1 开始，
当 years[j-1]>years[j] && money[j - 1] <= money[j] 时才 j-- 。满足条件将其值加 100.最后累加
*/

static void fun(vector<int> &years, const int n)
{
	vector<int> money(n, 0);
	int result = 0;

	money[0] = 100;
	for (int i = 0; i < n - 1; ++i)
	{
		if (years[i] < years[i + 1]) // 当 i 对应的资历比 i+1 的资历小时
		{
			money[i + 1] = money[i] + 100;
		}
		else if (years[i] > years[i + 1]) // 当 i 对应的资历比 i+1 大时
		{
			money[i + 1] = 100;
			if (money[i] <= money[i + 1])
			{
				for (int j = i + 1; years[j - 1] > years[j] && money[j - 1] <= money[j]; --j)
				{
					money[j - 1] += 100;
				}
			}
		}
		else // 当 i 对应的资历跟 i+1 相等时
		{
			money[i + 1] = 100;
		}
	}
	
	for (auto it : money)
	{
		cout << it << " ";
		result += it;
	}
	cout << result << endl;
}

int main_发工资(void)
{
	int n = 0;
	vector<int> years;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int temp;
		cin >> temp;
		years.push_back(temp);
	}

	fun(years, n);

	return 0;
}