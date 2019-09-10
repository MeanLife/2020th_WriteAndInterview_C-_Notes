#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

static int COUNT = 0;
static int win = 0;
static void Function(string str, int num)
{
	if (num >= str.size())
	{
		return;
	}
	else if (num == str.size() - 1)
	{
		COUNT += 1;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == '1' && i % 3 == 1)
			{
				break;
			}
			else if (str[i] == '1' && i % 3 == 0)
			{
				win += 1;
				break;
			}
		}
	}

	for (int i = num; i < str.size(); i++)
	{
		swap(str[i], str[num]);
		Function(str, num + 1);
		swap(str[i], str[num]);
	}
}

int main__爱奇艺第二题(void)
{
	int n, m;
	while (cin >> n >> m)
	{
		if (n == 0 && m == 0)
		{
			cout << "0.00000" << endl;
			return 0;
		}
		string str = "";
		str.insert(0, n, '1');
		str.insert(n, m, '0');
		Function(str, 0);
		printf("%.5f", float(win) / float(COUNT));
	}
	return 0;
}