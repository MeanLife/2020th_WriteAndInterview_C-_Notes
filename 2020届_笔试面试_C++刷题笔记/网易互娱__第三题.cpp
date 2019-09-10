#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

/***************************************
【题目】：
喝咖啡，一共就30天
如果某一天能喝咖啡，那它距离上一次喝过咖啡的时间>=d，距离下一次必须喝咖啡的时间也>=d
所以我们从１号开始枚举，如果满足上面的条件，我们就让他喝咖啡，更新上一次喝咖啡的时间为今天，
如果到了下一次必须喝咖啡的时间，更新到再下一次必须喝咖啡的时间

第三题，喝咖啡
首先是k++，因为隔k天，相当于下次喝是第k+1天之后，这样方便计算
首先特殊判断一下m=0的情况，实际上就是从第一天开始贪心的喝
然后对于大多数情况，我们这么判断
先判断从第一天到第num[0]天要喝多少天咖啡，因为第num[0]天必须要喝，
然后找上一天能喝的日期以此类推倒着找下去直到回退到第一天之前，即非法状态
接下来一段一段的判断，对于从（num[i],num[i+1]】这个左开右闭的区间来说，
首先也是倒着逆推，第num[i+1]天必须要喝，然后回溯k天，需要注意的是，因为我num[i]也是必须要喝咖啡的，
所以说天数回退到num[i]+k之前就是非法的了
最后是处理num[m-1]到第30天这段，这段也是贪心的判断一下就行了。
【思路】：

***************************************/
static int t, k, m;
static int num[33];
static int ans = 0;
int main_网易互娱__第三题() // 牛客上的代码
{
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d %d", &k, &m);
		k++;
		for (int i = 0; i < m; i++)
		{
			scanf("%d", &num[i]);
		}
		ans = 0;
		if (m == 0)
		{
			int temp = 1;
			while (temp <= 30)
			{
				ans++;
				temp += k;
			}
			printf("%d\n", ans);
			continue;
		}
		int temp = num[0];

		while (temp >= 1)
		{
			ans++;
			temp -= k;
		}
		for (int i = 1; i < m; i++)
		{
			temp = num[i];
			while (temp >= num[i - 1] + k)
			{
				ans++;
				temp -= k;
			}
		}
		temp = num[m - 1] + k;
		while (temp <= 30)
		{
			ans++;
			temp += k;
		}
		printf("%d\n", ans);
	}
	return 0;
}
//int main(void)
//{
//	int n;
//	cin >> n;
//	vector<int> res(n, 0);
//	for (int i = 0; i < n; i++)
//	{
//		int K, M;
//		cin >> K >> M;
//		vector<int> marr(M, 0);
//		for (int j = 0; j < M; j++)
//		{
//			cin >> marr[j];
//		}
//
//		int count = 0;
//		if (marr.size() == 0)
//		{
//			count = 30 / (K + 1);
//		}
//		else
//		{
//			count = M;
//			count += (marr[0] - 1) / (K + 1);
//			if (marr.size() > 1)
//			{
//				for (int j = 1; j < M; j++)
//				{
//					if (marr[j] - marr[j - 1] > (K + 1))
//					{
//						count += (marr[j] - marr[j - 1] - 1) / (K + 1);
//					}
//				}
//				count += (30 - marr[marr.size() - 1]) / (K + 1);
//			}
//		}
//		res[i] = count;
//	}
//	for (auto it : res)
//	{
//		cout << it << endl;
//	}
//	return 0;
//}