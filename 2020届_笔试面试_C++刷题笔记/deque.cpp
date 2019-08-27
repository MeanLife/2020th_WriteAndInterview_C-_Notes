#include <iostream>
#include <string>
#include <cmath>
#include <deque>
#include <algorithm>
using namespace std;

void printDeque(deque<int> myDeque)
{
	for (auto tmp : myDeque)
	{
		cout << tmp << ends;
	}
}


/*
//（双端队列）是 double-ended queue，可以在两端（前端或后端）插入或删除。
//特点：支持随机访问，可以在内部进行插入和删除操作，在两端插入删除性能最好，
（ 1）创建：
（ 2）通用操作： push_back(), pop_back(), insert(), erase(),
clear(), swap(), empty(), back(), front(), at(), []
（ 3）特有操作： push_front(), pop_front()
*/
void myDequeTest()
{
	cout << "-----this is class deque demo--" << endl;
	deque<int >myDeque = { 3, 5, 7 ,7 ,7, 7};
	printDeque(myDeque);
	cout << '\n';


	myDeque.push_back(9); //在队列尾部添加元素
	myDeque.push_front(1); //在队列头部添加元素
	cout << "after pushing, myDeque is: \n";
	printDeque(myDeque);
	cout << '\n';


	myDeque.pop_back(); // 删除 deque 容器中的最后一个元素，有效地将容器大小减少一个
	myDeque.pop_front(); // 删除 deque 容器中的第一个元素，有效地减小其大小
	printDeque(myDeque);
	cout << '\n';


	myDeque.emplace_front(10); // 在 deque 的开头插入一个新的元素，就在其当前的第一个元素之前
	myDeque.emplace_back(11); // 在 deque 的末尾插入一个新的元素，紧跟在当前的最后一个元素之后
	printDeque(myDeque);
	cout << '\n';


	/*
	insert()版本：
	（ 1） insert(p, t) //在迭代器 p 之前创建一个值为 t，返回指向新添加的元素的迭代器
	（ 2） insert(p, b, e) //将迭代器[b, e）指定的元素插入到 p 所指位置，返回第一个插入元素的迭代器
	//关于迭代器确定范围都是左闭右开！！！！
	*/
	auto ret = myDeque.insert(myDeque.begin() + 1, 2);
	cout << "after inserting, myDeque is: \n";
	printDeque(myDeque);
	cout << '\n';
	cout << "返回迭代指向的元素为： ";
	cout << *ret << endl;


	//将迭代器[b, e）指定的元素插入到 p 所指位置，返回第一个插入元素的迭代器
	deque<int> myDeque2 = { 7,8,8 };
	auto ret1 = myDeque.insert(myDeque.begin(), myDeque2.begin(), myDeque2.end());
	cout << "after inserting , myDeque is : " << endl;
	printDeque(myDeque);
	cout << '\n';
	cout << "返回的迭代器值为： " << *ret1 << endl;


	// erase:
	auto ret2 = myDeque.erase(myDeque.begin() + 1);
	cout << "after earsing, myDeque is: \n";
	printDeque(myDeque);
	cout << '\n';
	cout << "返回迭代指向的元素为： ";
	cout << *ret2 << endl;


	// 计数
	auto cnt = count(myDeque.begin(), myDeque.end(), 7);
	cout << "cnt = " << cnt << endl;


	// sort 排序
	sort(myDeque.begin(), myDeque.end());
	cout << "after sort, myDeque is: \n";
	printDeque(myDeque);
	cout << endl;


	// 删除重复元素，这里没啥用，没有删除掉
	auto itit = unique(myDeque.begin(), myDeque.end());
	myDeque.erase(itit, myDeque.end());//重排元素，对于重复元素重新排在最大不重复子序列的尾后迭代器，
	// 一般 sort 之后使用该元素将重复元素放在最大不重复子序列的后面，然后可以使用 erase 删除
	printDeque(myDeque);
	cout << endl;
}



int main1231231(void)
{
	myDequeTest();


	cout<<"Write By JZQ!"<<endl;
	//自动排版：ctrl+k+F
	system("pause");
	return 0;
}