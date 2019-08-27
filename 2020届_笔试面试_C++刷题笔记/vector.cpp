#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 输入二维数组vector<vector<int>> array
static void input_2D_Array(vector<vector<int>> &array, const int n, const int m)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			// 不能直接通过：vector[0] = "aa"赋值，下标是修改不是插入
			array[i].push_back((i + 1)*(j + 1));
		}
	}
}

// 打印二维数组vector<vector<int>> array
static void print_2D_Array(vector<vector<int>> array)
{
	for (unsigned i = 0; i < array.size(); ++i)
	{
		for (vector<int>::iterator it = array[i].begin(); it != array[i].end(); it++)
		{
			cout << *it << "  ";
		}
		cout << endl;
	}
	cout << endl;
}

/*
实现 vector 常见的一维操作：
（ 1）构造、赋值:
（ 2）基本操作： size(), empty(), push_back(), pop_back(), insert(), erase(), clear(), swap();
*/
static void myVectorTest_1D()
{
	cout << "-----------this is class vector demo------" << endl;
	vector<int> myVec = { 1, 3, 5, 7, 9 };
	vector<int> myVec1 = { 4, 6, 8 };
	cout << "the size of myVec： " << myVec.size() << endl;
	myVec.reserve(10);// 设置容器至少可容纳的元素数
	cout << "max_size : " << myVec.max_size() << endl; // 返回容器可容纳的最大元素数
	myVec.shrink_to_fit(); // 容器减小其 capacity（容量）以适应其 size（元素数量）


	cout << "myVec.front():" << myVec.front() << endl; // 返回容器中第一个元素的引用
	cout << "myVec.back():" << myVec.back() << endl; // 返回容器中最后一个元素的引用


	//在尾部添加字符
	myVec.push_back(0);
	cout << "after pushing, myVec is: " << endl;
	for (auto tmp : myVec)
	{
		cout << tmp << ' ';
	}
	cout << endl;


	/*
	insert()版本：
	（ 1） insert(p, t) //在迭代器 p 的位置插入一个值为 t，返回指向新添加的元素的迭代器
	（ 2） insert(p, b, e) //将迭代器[b, e）指定的元素插入到 p 所指位置，返回第一个插入元素的迭代器
	（ 3） insert(p, il) //将列表中的元素插入，返回第一个插入元素的迭代器
	//关于迭代器确定范围都是左闭右开！！！！
	*/
	auto ret = myVec.insert(myVec.begin() + 1, 2); //插入单个元素，返回该元素迭代器
	cout << "after inserting , myVec is : " << endl;
	for (auto tmp : myVec)
	{
		cout << tmp << ' ';
	}
	cout << "返回的迭代器值为： " << *ret << endl;


	//将迭代器[b, e）指定的元素插入到 p 所指位置，返回第一个插入元素的迭代器
	auto ret1 = myVec.insert(myVec.begin() + 1, myVec1.begin(), myVec1.end());
	cout << "after inserting , myVec is : " << endl;
	for (auto tmp : myVec)
	{
		cout << tmp << ' ';
	}
	cout << "返回的迭代器值为： " << *ret1 << endl;


	/*
	erase()版本：
	（ 1） erase(p) //删除迭代器 p 所指元素，返回下一个元素的迭代器
	（ 2） erase(b, e) //删除迭代器[b, e) 范围内的元素；
	//关于迭代器确定范围都是左闭右开！！！！
	*/
	//删除单个迭代器指向的元素，
	auto ret2 = myVec.erase(myVec.begin() + 1);
	cout << "after earsing , myVec is : " << endl;
	for (auto tmp : myVec)
	{
		cout << tmp << ' ';
	}
	cout << "返回的迭代器值为： " << *ret2 << endl;


	//删除迭代器[b, e) 范围内的元素；
	auto ret3 = myVec.erase(myVec.begin() + 1, myVec.begin() + 4);
	cout << "after earsing , myVec is : " << endl;
	for (auto tmp : myVec)
	{
		cout << tmp << ' ';
	}
	cout << "返回的迭代器值为： " << *ret3 << endl;


	//交换两个容器的值，其实实质上并不交换
	swap(myVec, myVec1);
	cout << "after swapping , myVec is : " << endl;
	for (auto tmp : myVec)
	{
		cout << tmp << ' ';
	}
	cout << '\n';


	// 8.算法  算法和迭代器 进行无缝的连接 ,求某个元素在向量中的个数
	auto num1 = count(myVec.begin(), myVec.end(), 2);//求‘2’的个数
	cout << "num1 : " << num1 << endl;


	// 从 vector 中删除所有的元素（被销毁），留下 size 为 0 的容器
	myVec1.clear(); 
}


/*
实现 vector 常见的二维操作：
*/
void myVectorTest_2D()
{
	// 9.二维向量的vector，要显示定义第一维（多少行）
	int n = 4;
	int m = 3;
	vector<vector<int>> array(n);
	input_2D_Array(array, n, m);
	print_2D_Array(array);

	// 10.二维向量逆序打印
	for (unsigned i = 0; i < array.size(); i++)
	{
		reverse(array[i].begin(), array[i].end());
	}
	print_2D_Array(array);

}


int main1561651651()
{
	myVectorTest_1D();

	cout << endl;
	cout << endl;

	myVectorTest_2D();
	

	system("pause");
	return 0;
	//自动排版：ctrl+K,ctrl+F
}