//#include <iostream>
//#include <vector>
//#include <numeric>
//#include <limits>
//#include <algorithm>
//
//using namespace std;
//
//static bool compare(int a, int b)
//{
//	return a > b;
//}
//
///*请完成下面这个函数，实现题目要求的功能
//当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^
//******************************开始写代码******************************/
//int solution(vector < int > prices, int budget) {
//	sort(prices.begin(), prices.end(), compare);
//	int count = 0;
//	while (budget > 0)
//	{
//		if (budget >= prices[0])
//		{
//			budget -= prices[0];
//			//prices.erase(prices.begin());
//			count++;
//		}
//		else if (!prices.empty())
//		{
//			prices.erase(prices.begin());
//		}
//		else // budget < prices[0] 且 prices.empty()
//		{
//			return -1;
//		}
//	}
//	return count;
//}
///******************************结束写代码******************************/
//
//
//int main() {
//	int res;
//
//	int _prices_size = 0;
//	cin >> _prices_size;
//	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//	vector<int> _prices;
//	int _prices_item;
//	for (int _prices_i = 0; _prices_i < _prices_size; _prices_i++) {
//		cin >> _prices_item;
//		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//		_prices.push_back(_prices_item);
//	}
//
//
//	int _budget;
//	cin >> _budget;
//	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//
//
//
//	res = solution(_prices, _budget);
//	cout << res << endl;
//
//	return 0;
//
//}
