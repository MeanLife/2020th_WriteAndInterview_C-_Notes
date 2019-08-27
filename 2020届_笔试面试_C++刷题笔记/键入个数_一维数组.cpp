#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

//两种方式，1：手动分配内存。2：使用STL里的vector。
static void printArray(int *array, const int len)
{
	// 遍历输出
	for (int i = 0; i < len; i++)
	{
		cout << array[i] << '\t';
	}
	cout << endl;
}

static void printArray(vector<int> &array)
{
	for (auto it = array.begin(); it != array.end(); ++it)
	{
		cout << *it << '\t';
	}
	cout << endl;
}

int main12_21(void)
{
	int N = 0;
	cin >> N;

	// 一维数组分配内存从这里开始
	int *array = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> array[i];   //需要手动输入元素
	}
	//cin.get();  //可能需要消除缓存中的换行符

	// 遍历输出
	printArray(array, N);
	delete array;

	system("pause");
	return 0;
	//自动排版：ctrl+K,ctrl+F
}

//当我们想定义不固定大小的字符时,可以使用 vector(向量) 标准库。
int main_121331125(void) 
{
	// 创建向量用于存储整型数据
	vector<int> vec;
	int N = 0;
	int num = 0;
	cin >> N;
	// 显示 vec 初始大小
	cout << "vector size = " << vec.size() << endl;

	// 向向量 vec 追加 N 个整数值
	for (int i = 0; i < N; i++) 
	{
		cin >> num;
		vec.push_back(num);
	}

	// 显示追加后 vec 的大小
	cout << "extended vector size = " << vec.size() << endl;
	/////////////////遍历输出//////////////////////////////////
	printArray(vec);
	system("pause");
	return 0;
}