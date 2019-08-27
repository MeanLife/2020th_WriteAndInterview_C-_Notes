#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;
/*
题目一：
目前市面上的纸币主要有1元，5元，10元，20元，50元、100元六种，如果要买一件商品strTargetNum元，有多少种货币组成方式？
题目二：
现在规定，每种货币的张数最大为strValueSequences = "6 5 4 3 2 1";
*/

// 分割字符串
static void SplitString(const string& s, vector<string>& v, const string& c)
{
	string::size_type pos1, pos2;
	pos2 = s.find(c);
	pos1 = 0;
	while (string::npos != pos2)
	{
		v.push_back(s.substr(pos1, pos2 - pos1));
		pos1 = pos2 + c.size();
		pos2 = s.find(c, pos1);
	}
	if (pos1 != s.length())
	{ 
		v.push_back(s.substr(pos1));
	}	
}

// 字符串数组转为int数组
static void StringToInt(vector<string>& s, vector<int> &v)
{
	for (auto i = 0; !s.empty(); i++)
	{
		v.push_back(std::stoi(s.front()));
		s.erase(s.begin());
	}
}


int process(std::string strTargetNum, std::string strValueSequences) 
{
	//insert your code here:
	int m = std::stoi(strTargetNum);
	vector<string> numstr;
	SplitString(strValueSequences, numstr, " ");
	vector<int> nums;
	StringToInt(numstr, nums);
	int sum = 0; // 符合条件的总价钱
	int count = 0; //符合条件的组合次数
	int money[] = { 1,5,10,20,50,100 };//纸币面额

	for (int i = 0; i <= nums[5]; i++) {
		//100元可能出现的张数，若不限定张数nums，则用：i <= m / money[5]
		for (int j = 0; j <= nums[4]; j++) {
			//50元可能出现的张数
			for (int k = 0; k <= nums[3]; k++) {
				//20元可能出现的张数
				for (int l = 0; l <= nums[2]; l++) {
					//10元可能出现的张数
					for (int n = 0; n <= nums[1]; n++) {
						int o = m - (i * money[5] + j * money[4] + k * money[3] + l * money[2] + n * money[1]); //1元的数量
						int sum = i * money[5] + j * money[4] + k * money[3] + l * money[2] + n * money[1] + o * money[0];
						if (sum == m && o >= 0 && o <= nums[0]) {
							count += (i + j + k + l + n + o);
						}
					}
				}
			}
		}
	}
	return count;
}

int main58978979865416418(void)
{
	std::string strValueSequences = "6 5 4 3 2 1";
	std::string strTargetNum = "11";
	int count = 0;
	count = process(strTargetNum, strValueSequences);
	cout << "count:" << count << endl;
	
	cout<<"Write By JZQ!"<<endl;
	//自动排版：ctrl+k+F
	return 0;
}