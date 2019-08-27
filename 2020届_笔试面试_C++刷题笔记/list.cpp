/*
list，双向链表，是序列容器，允许在序列中的任何地方进行常数时间插入和擦除操作，
并且，可以在两个方向上进行迭代。
*/

#include <iostream>
#include <list>
#include <string>
using namespace std;
/*
(1)构造：
(2)通用函数： push_back(), pop_back(), empty(), clear(), swap(), insert(), erase(), reverse()
(3)特有操作： push_front(), pop_front(), merge(), remove(), remove_if()
*/

// 一元谓词
bool is_odd(const int x) //充当一元谓词
{
	return (x % 2 == 1);
}


void myListTest()
{
	cout << "------this is class List demo----" << endl;
	list<int> myList{ 3, 5 };
	myList.push_back(7);
	myList.push_front(1); //双向链表支持在两端的快速插入和删除
	cout << "after push, myList is : " << endl;
	for (auto tmp : myList)
	{
		cout << tmp << ' ';
	}
	cout << '\n';


	//插入操作和其他的一样，在此不再赘述
	auto ret = myList.insert(myList.end(), 9);
	myList.insert(myList.begin(), 2); // 这个插入操作无措
	cout << "after inserting, myList is : " << endl;
	for (auto tmp : myList)
	{
		cout << tmp << ' ';
	}
	cout << '\n';


	// 排序
	myList.sort();
	// 逆序
	// myList.reverse();


	list<int >myList1 = { 2, 4, 6, 8 };
	myList.merge(myList1); //合并两个有序链表，返回合并后的排序链表，若合并之前二者其一无序就会报错。
	cout << "after merging, myList is : " << endl;
	for (auto tmp : myList)
	{
		cout << tmp << ' ';
	}
	cout << '\n';


	// 删除所有值为 8 的元素
	myList.remove(8); 
	cout << "after removing, myList is : " << endl;
	for (auto tmp : myList)
	{
		cout << tmp << ' ';
	}
	cout << '\n';


	//remove_if() //当满足条件时，删除
	myList.remove_if(is_odd);//参数为函数指针
	cout << "after remove_if(is_odd), myList is : " << endl;
	for (auto tmp : myList)
	{
		cout << tmp << ' ';
	}
	cout << '\n';


	//删除重复的元素
	myList.unique();
	cout << "after unique , myList is : " << endl;
	for (auto tmp : myList)
	{
		cout << tmp << ' ';
	}
	cout << '\n';

	
	// 复制链表
	list<int > mylist2;
	mylist2.assign(myList.begin(), myList.end());
	cout << "after assign , mylist2 is : " << endl;
	for (auto tmp : mylist2)
	{
		cout << tmp << ' ';
	}
	cout << '\n';
}

int main0211(void)
{
	myListTest();

	
	cout<<"Write By JZQ!"<<endl;
	//自动排版：ctrl+k+F
	system("pause");
	return 0;
}