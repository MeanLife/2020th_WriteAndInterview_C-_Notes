#include <iostream>
#include <string>
#include <cmath>
#include <map>
using namespace std;

/*
map 是关联容器，按照   特定顺序   存储由 key (键值) value (映射值) 组合形成的元素。
（ 1）构造： map<string, int>, pair<string, int>, make_pair(v1, v2)
（ 2）特殊操作： first, second, insert(), erase(), count(), find(), operator[]();
*/
void myMapTest()
{
	cout << "---------this is class map demo---------" << endl;
	map<string, int>myMap;
	auto myPair1 = pair<string, int>("hello", 1);
	auto myPair2 = make_pair("bworld", 3);
	auto myPair3 = make_pair("cqqqqq", 10);

	map<string, int, less<string>>myMap2;// 键值从大到小greater<int>,键值从小到大less<Type> 
	/*
	//insert 返回一个 pair<first,second>; first 是一个迭代器指向具有给定关键字的值， second 是一个 bool 量，若是 true 则表示插入成功，
	//若为 false 则表示插入失败，说明已经存在，则该语句什么也不做，只能手动的++
	m.insert(myPair1); //插入 pair 对象
	m.insert(beg, end); //将范围内的元素插入
	m.insert(iter, e); //unknow
	*/
	// 存储顺序为 ： key关键字  递增的顺序。
	auto ret1 = myMap.insert(myPair1);//insert 返回一个 pair<first,second>;
	if (ret1.second)
		cout << "insert successfully\n"; //插入 pair 类型
	printf("%s---->%d\n", ret1.first->first.c_str(), ret1.first->second);
	auto ret2 = myMap.insert(myPair2);
	if (ret2.second)
		cout << "insert successfully\n";
	printf("%s---->%d\n", ret2.first->first.c_str(), ret2.first->second);
	auto ret3 = myMap.insert(myPair3);
	if (ret3.second)
		cout << "insert successfully\n";
	printf("%s---->%d\n", ret3.first->first.c_str(), ret3.first->second);
	printf("\n");


	// 迭代器遍历打印
	for (auto iter = myMap.begin(); iter != myMap.end(); ++iter)
	{
		printf("%s---->%d\n", iter->first.c_str(), iter->second);
	}
	printf("\n");


	// 下标运算符：修改或插入
	++myMap["aaabbb"]; //使用下标运算符，若不存在，则创建新的键值对(word, 0)，注意与insert的区别
	myMap["world"] += 2;
	cout << "after operator[], myMap is : \n";
	for (auto iter = myMap.begin(); iter != myMap.end(); ++iter)
	{
		printf("%s---->%d\n", iter->first.c_str(), iter->second);
	}
	printf("\n");


	/*
	m.erase(k); //删除关键字为 k 的元素
	m.erase(p); //删除迭代器 p 指向的元素
	m.erase(b, e); //删除范围内的元素
	*/
	myMap.erase("aaabbb");//删除关键字为word的元素
	cout << "after erasing, myMap is : \n";
	//for (auto iter = myMap.begin(); iter != myMap.end(); ++iter)
	//{
	//	printf("%s---->%d\n", iter->first.c_str(), iter->second);
	//}
	for (auto tem : myMap)
	{
		cout << tem.first << "---->" << tem.second << endl;
	}
	printf("\n");


	// 查找元素个数
	unsigned cnt = myMap.count("hello"); //返回关键字的个数
	printf("hello occurred %d times\n", cnt);
	printf("\n");


	// 返回某个关键字的迭代器
	cout << "find keyword hello : \n";
	auto ret4 = myMap.find("hello"); //如果找到则返回迭代器， 否则返回map::end 的迭代器
	if (ret4 != myMap.end()) // 不加这一句，若是没找到，会报错，因为不能从myMap.end()里面取值。
	{
		printf("%s---->%d\n", ret4->first.c_str(), ret4->second);
	}
	printf("\n");


	// map 不能逆序，不能排序


	// 返回一个非递减序列 [first, last)（参数）中的第一个   大于等于   值 val（参数）的位置的迭代器
	auto ret5 = myMap.lower_bound("cqqqqq");// lower_bound(myMap.begin(), myMap.end(), "sss");
	printf("%s---->%d\n", ret5->first.c_str(), ret5->second);
	printf("\n");


	// 返回一个非递减序列 [first, last)（参数）中第一个   大于   val（参数）的位置的迭代器
	auto ret6 = myMap.upper_bound("cqqqqq");// lower_bound(myMap.begin(), myMap.end(), "sss");
	printf("%s---->%d\n", ret6->first.c_str(), ret6->second);
	printf("\n");

}


int main1165161(void)
{
	myMapTest();

	
	cout<<"Write By JZQ!"<<endl;
	//自动排版：ctrl+k+F
	system("pause");
	return 0;
}