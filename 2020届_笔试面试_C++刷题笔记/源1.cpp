//#include <iostream>
//#include <string>
//#include <list>
//#include <vector>
//using namespace std;
//
//static void function(vector<int> &game, int index)
//{
//	vector<int> temp(index - 1, 0);
//	for (int i = 0; i < index - 1; i++)
//	{
//		temp[i] = game[i];
//	}
//	for (int i = index; i <= game.size(); i++)
//	{
//		game[i - index] = game[i - 1];
//	}
//	for (int i = 0; i < index-1; i++)
//	{
//		game[game.size() - temp.size() + i] = temp[i];
//	}
//}
//
//int main(void)
//{
//	int n, m, k;
//	while (cin >> n >> m >> k)
//	{
//		vector<int> temp_p;
//		int temp_p_sum = 0;
//		for (int i = 0; i < k; i++) // 每一轮替补上场的人数
//		{
//			int temp;
//			cin >> temp;
//			temp_p_sum += temp;
//			temp_p.push_back(temp);
//		}
//
//		vector<int> num_p;
//		vector<int> game;
//		for (int i = 1; i <= n + temp_p_sum; i++) // 初始+替补:编号
//		{
//			i <= n ? game.push_back(i) : num_p.push_back(i);
//		}
//
//		// 游戏开始，共k轮
//		int count = 0;
//		for (int i = 0; i < k; i++)
//		{
//			int index = (game.size() >= m ? m : game.size() % m);
//			cout << game[index - 1] << endl;
//			game.erase(game.begin() + index - 1); // 淘汰
//
//			// 替补
//			for (int j = 0; j < temp_p[i]; j++)
//			{
//				//cout << "num_p[0] = " << num_p[0] << endl;
//				game.insert(game.begin() + index - 1 + j, num_p[0]);
//				num_p.erase(num_p.begin());
//			}
//			
//			// 调整数组
//			function(game, index);
//		}
//	}
//	return 0;
//}