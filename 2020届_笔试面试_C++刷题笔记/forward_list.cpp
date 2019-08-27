/*
forward_list（单向链表）是序列容器，允许在序列中的任何地方进行恒定的时间插入和擦除操作。
*/

#include <iostream>
#include <string>
#include <cmath>
#include <forward_list>
using namespace std;


void myForward_listTest()
{
	cout << "----this is class forward_list demo---" << endl;
	forward_list<int> myForward_list = { 1, 3, 7, 5, 5 };
	cout << "the front of myForward_list is : " << myForward_list.front() << endl; //front 数
	myForward_list.push_front(0); // 头插法
	for (auto tmp : myForward_list)
		cout << tmp << ' ';
	cout << endl;


	/*
	lst.insert_after(p, t) //在迭代器 p 之后的位置插入元素 t，返回指向插入元素的迭代器
	lst.insert_after(p, b, e) //在迭代器 p 之后插入范围为[b, e）的元素，返回最后一个插入链表的迭代器
	*/
	myForward_list.insert_after(myForward_list.before_begin(), 9);
	//list 和 forward_list 虽然不支持+,-操作，但是支持++，-- 操作
	cout << "after inserting , myForward_list is : " << endl;
	for (auto iter = myForward_list.begin(); iter != myForward_list.end(); ++iter)
	{
		cout << *iter << ends;
	}
	cout << '\n';
	

	//删除某一特定位置元素
	myForward_list.erase_after(myForward_list.before_begin());
	cout << "after erasing , myForward_list is : " << endl;
	for (auto iter = myForward_list.begin(); iter != myForward_list.end(); ++iter)
	{
		cout << *iter << ends;
	}
	cout << '\n';


	myForward_list.remove(1); //删除某一特定值元素
	//myForward_list.remove_if(is_odd); //按照传入谓词来删除某一元素


	//删除重复的元素
	myForward_list.unique(); 
	cout << "after unique , myForward_list is : " << endl;
	for (auto iter = myForward_list.begin(); iter != myForward_list.end(); ++iter)
	{
		cout << *iter << ends;
	}
	cout << '\n';


	//对链表数据进行排序
	myForward_list.sort(); 
	cout << "after sorting , myForward_list is : " << endl;
	for (auto iter = myForward_list.begin(); iter != myForward_list.end(); ++iter)
	{
		cout << *iter << ends;
	}
	cout << '\n';


	// 对链表数据进行逆序
	myForward_list.reverse();
	cout << "after reverse , myForward_list is : " << endl;
	for (auto iter = myForward_list.begin(); iter != myForward_list.end(); ++iter)
	{
		cout << *iter << ends;
	}
	cout << '\n';
}

int main04111111111111111111111(void)
{
	myForward_listTest();
	
	cout<<"Write By JZQ!"<<endl;
	//自动排版：ctrl+k+F
	system("pause");
	return 0;
}