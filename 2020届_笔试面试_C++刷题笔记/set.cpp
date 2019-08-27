#include <iostream>
#include <string>
#include <cmath>
#include <set>
using namespace std;

/*
//所有元素都是按照字典序自动排序， set 只有键值，键值就是市值
（ 1）构造：
（ 2）通用操作： empty(), insert(), erase(), size(), swap(), find(), count(),
（ 3）特有操作： equal_range(), lower_bound(), upper_bound()
*/
void mySetTest()
{
	cout << "----this is class set demo-------" << endl;
	set<string >mySet = { "a", "c", "b" };


	/*
	//insert 返回一个 pair<first,second>， first 是一个迭代器指向具有给定关键字的值， second 是一个 bool 量，
	若是 true 则表示插入成功，若为 false 则表示插入失败，说明已经存在，则该语句什么也不做
	m.insert(e); //插入 pair 对象
	m.insert(beg, end); //将范围内的元素插入
	m.insert(iter, e); //unknow
	*/
	bool flag = mySet.empty();
	auto ret = mySet.insert("d"); //插入键值
	cout << "insert : " << *ret.first << endl;
	cout << "after inserting, mySet is : \n";
	if (ret.second)
	{
		for (auto tmp : mySet)
			cout << tmp << ends;  // a  b  c  d  自动排序
	};
	cout << "\n";


	// erase删除元素
	auto ret1 = mySet.erase("d"); //删除元素
	cout << "after erase d, mySet is : \n";
	for (auto tmp : mySet)
		cout << tmp << ends;
	cout << "\n";


	// find查找元素
	auto ret2 = mySet.find("a");
	if (ret2 == mySet.end())
		cout << "dont find it \n";
	else
		cout << "find it:" << *ret2 << endl;

	// 查找元素个数
	unsigned int cnt = mySet.count("a");
	printf("a occurred %d times \n", cnt);


	// 返回一个非递减序列 [first, last)（参数）中的第一个   大于等于   值 val（参数）的位置的迭代器
	set<string>::iterator iter_beg = mySet.lower_bound("b");
	cout << "iter_beg : " << *iter_beg << endl;
	// 返回一个非递减序列 [first, last)（参数）中第一个   大于   val（参数）的位置的迭代器
	set<string>::iterator iter_end = mySet.upper_bound("b");
	cout << "iter_end : " << *iter_end << endl;
	//给定关键字的范围[lower_bound, upper_bound)
}

int main25126226(void)
{
	mySetTest();

	
	cout<<"Write By JZQ!"<<endl;
	//自动排版：ctrl+k+F
	system("pause");
	return 0;
}