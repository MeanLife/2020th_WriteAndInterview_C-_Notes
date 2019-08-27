#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int main_14141515454(void)
{
	string str = "ASDdcxaSDAsdasd";
	///转小写
	transform(str.begin(), str.end(), str.begin(), ::tolower);
	cout << "转化为小写后为：" << str << endl;
	transform(str.begin(), str.end(), str.begin(), ::toupper);
	cout << "转化为大写后为：" << str << endl;

	
	cout<<"Write By JZQ!"<<endl;
	//自动排版：ctrl+k+F
	return 0;
}